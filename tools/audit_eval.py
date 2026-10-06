#!/usr/bin/env python3
# audit_eval.py -- the literal audit evaluator.
#
# R207c tool: reads the ACTUAL generated C++ (rules/*.h bodies
# and the regtest.cpp audit blocks) and evaluates every audit
# assertion literally, the way the C++ compiler would. It NEVER
# re-implements a rule from intent: the engine under test is the
# parsed header source itself. Anything it cannot parse is
# reported UNVERIFIED and never silently passed.
#
# Born of two preflight-RED rounds the assistant-side sim blessed:
#   R206b - a missing bang (foodDistractionSucceeds(100,1) is
#           true at 100 percent) and dropped +10 arithmetic;
#   R207b - an inverted ternary (taxEntryFeeCopper's citizen
#           flag read backwards).
# The lesson carved in the knowledge file: a sim that re-implements
# from intent inherits the same mistake it should catch. This tool
# exists so the acid test can no longer make that mistake.
#
# Usage (repo root):
#   python3 tools/audit_eval.py R205 R206 R207   # named blocks
# With no args: every audit block in regtest.cpp (a coverage
# report - the older pre-R205 blocks use structs, classes and
# engine objects outside the evaluable subset and print
# UNVERIFIED; they do not count against a named run).
# Exit code: 0 only when every counted block is literally
# verified bad 0. A block that cannot be parsed is UNVERIFIED
# and fails the run (YELLOW, RED-equivalent): the tool never
# blesses what it cannot read.
#
# HOUSE RULE (R207c, carved): every new seam is written in the
# grenade.h pattern (pure inline helpers in this subset), and
# the acid test runs `python3 tools/audit_eval.py RNNN` and
# demands "verified bad 0" - not UNVERIFIED - BEFORE delivery.
# A sim that re-implements from intent is no longer acceptable.
#
# Supported header body subset (the grenade.h pattern):
#   - return <expr>;  /  if (cond) return <expr>;
#   - if (cond) { ... }  braced blocks, bare return;
#   - if (<cmp>) <var> = / += / -= <expr>;  (clamp chains)
#   - int <var> = <expr>;  local bindings
#   - static const int k[N] = {...};  1D/2D local arrays
#     (dims may be enum constants)
#   - int& reference out-params
# Expressions: int/bool literals, params, enum constants, casts
# ((Type)e and (rules::Type)e), arithmetic (+ - * / %, C
# truncation), comparisons, && || ! ?:, and cross-calls to
# other rules:: functions (including enum-returning ones).
#
# Supported audit statements: `if (<cond>) ++bad;`, bare
# reference calls (rules::f(x, lo, hi);), local int/array
# declarations, and the nested for-walk pattern
# (for (int i = A; i <= B; ++i) ... ) around an if-assert.

import re
import sys
import os


def strip_comments(s):
    out = []
    for line in s.split('\n'):
        i = line.find('//')
        out.append(line if i < 0 else line[:i])
    return '\n'.join(out)


def match_braces(s, start):
    # start points at '{'; returns index of matching '}'
    d = 0
    i = start
    while i < len(s):
        c = s[i]
        if c == '{':
            d += 1
        elif c == '}':
            d -= 1
            if d == 0:
                return i
        i += 1
    raise ValueError('unbalanced braces at %d' % start)


def match_parens(s, start):
    # start points at '('; returns index of matching ')'
    d = 0
    i = start
    while i < len(s):
        c = s[i]
        if c == '(':
            d += 1
        elif c == ')':
            d -= 1
            if d == 0:
                return i
        i += 1
    raise ValueError('unbalanced parens at %d' % start)


# ---------------------------------------------------------------------------
# Tokenizer for expressions / statements
# ---------------------------------------------------------------------------

TOKEN_RE = re.compile(
    r'\s*(?:'
    r'(?P<num>\d+)'
    r'|(?P<id>[A-Za-z_]\w*)'
    r'|(?P<punct>::|&&|\|\||==|!=|<=|>=|[-+*/%(){}\[\],;?:<>=!&|.])'
    r')')


def tokenize(s):
    toks = []
    i = 0
    while i < len(s):
        m = TOKEN_RE.match(s, i)
        if not m:
            if s[i].isspace():
                i += 1
                continue
            raise ValueError('cannot tokenize at: %r' % s[i:i + 30])
        i = m.end()
        if m.group('num') is not None:
            toks.append(('num', int(m.group('num'))))
        elif m.group('id') is not None:
            toks.append(('id', m.group('id')))
        else:
            toks.append(('p', m.group('punct')))
    toks.append(('eof', None))
    return toks


# ---------------------------------------------------------------------------
# Expression parser / evaluator (C semantics)
# ---------------------------------------------------------------------------

class ExprParser:
    def __init__(self, toks, env, funcs, enums, arrays, depth=0):
        self.t = toks
        self.i = 0
        self.env = env          # variable name -> value
        self.funcs = funcs      # name -> CppFunction
        self.enums = enums      # enum-constant name -> int
        self.arrays = arrays    # array name -> (dims, flat list)
        self.depth = depth

    def peek(self):
        return self.t[self.i]

    def next(self):
        tok = self.t[self.i]
        self.i += 1
        return tok

    def expect(self, val):
        tok = self.next()
        if tok != ('p', val) and tok[1] != val:
            raise ValueError('expected %r got %r' % (val, tok))

    def at_p(self, val):
        tok = self.peek()
        return tok[0] == 'p' and tok[1] == val

    def parse_expr(self):
        return self.parse_ternary()

    def parse_ternary(self):
        c = self.parse_or()
        if self.at_p('?'):
            self.next()
            a = self.parse_ternary()
            self.expect(':')
            b = self.parse_ternary()
            return a if c else b
        return c

    def parse_or(self):
        v = self.parse_and()
        while self.at_p('||'):
            self.next()
            r = self.parse_and()
            v = 1 if (v or r) else 0
        return v

    def parse_and(self):
        v = self.parse_cmp()
        while self.at_p('&&'):
            self.next()
            r = self.parse_cmp()
            v = 1 if (v and r) else 0
        return v

    def parse_cmp(self):
        v = self.parse_add()
        while self.peek()[0] == 'p' and self.peek()[1] in (
                '==', '!=', '<', '<=', '>', '>='):
            op = self.next()[1]
            r = self.parse_add()
            v = 1 if {
                '==': v == r, '!=': v != r, '<': v < r,
                '<=': v <= r, '>': v > r, '>=': v >= r}[op] else 0
        return v

    def parse_add(self):
        v = self.parse_mul()
        while self.peek()[0] == 'p' and self.peek()[1] in ('+', '-'):
            op = self.next()[1]
            r = self.parse_mul()
            v = v + r if op == '+' else v - r
        return v

    def parse_mul(self):
        v = self.parse_unary()
        while self.peek()[0] == 'p' and self.peek()[1] in ('*', '/', '%'):
            op = self.next()[1]
            r = self.parse_unary()
            if op == '*':
                v = v * r
            elif op == '/':
                v = c_div(v, r)
            else:
                v = c_mod(v, r)
        return v

    def parse_unary(self):
        if self.at_p('!'):
            self.next()
            return 0 if self.parse_unary() else 1
        if self.at_p('-'):
            self.next()
            return -self.parse_unary()
        if self.at_p('+'):
            self.next()
            return self.parse_unary()
        if self.at_p('('):
            self.next()
            # a cast: (Type)expr or (rules::Type)expr
            if self.peek()[0] == 'id':
                j = self.i
                if self.t[j + 1] == ('p', ')'):
                    self.i = j + 2
                    return self.parse_unary()
                if self.t[j + 1] == ('p', '::') and \
                        self.t[j + 2][0] == 'id' and \
                        self.t[j + 3] == ('p', ')'):
                    self.i = j + 4
                    return self.parse_unary()
            v = self.parse_ternary()
            self.expect(')')
            return v
        return self.parse_primary()

    def parse_primary(self):
        tok = self.peek()
        if tok[0] == 'num':
            self.next()
            return tok[1]
        if tok[0] == 'id':
            name = self.next()[1]
            if name == 'rules' and self.at_p('::'):
                # namespace-qualified call: rules::fn(...)
                self.next()
                return self.parse_primary()
            if name == 'true':
                return 1
            if name == 'false':
                return 0
            if self.at_p('['):
                dims = []
                while self.at_p('['):
                    self.next()
                    dims.append(self.parse_ternary())
                    self.expect(']')
                if name not in self.arrays:
                    raise ValueError('unknown array %r' % name)
                adims, flat = self.arrays[name]
                if len(dims) != len(adims):
                    raise ValueError('rank mismatch on %r' % name)
                idx = 0
                for d, ad in zip(dims, adims):
                    idx = idx * ad + d
                if not (0 <= idx < len(flat)):
                    raise ValueError('index out of range on %r' % name)
                return flat[idx]
            if self.at_p('('):
                self.next()
                args = []
                if not self.at_p(')'):
                    args.append(self.parse_ternary())
                    while self.at_p(','):
                        self.next()
                        args.append(self.parse_ternary())
                self.expect(')')
                return call_function(name, args, self.funcs,
                                    self.enums, self.arrays, self.depth)
            if name in self.env:
                return self.env[name]
            if name in self.enums:
                return self.enums[name]
            raise ValueError('unknown identifier %r' % name)
        raise ValueError('unexpected token %r' % (tok,))


def c_div(a, b):
    if b == 0:
        raise ValueError('division by zero')
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b >= 0) else -q


def c_mod(a, b):
    return a - c_div(a, b) * b


def eval_expr(text, env, funcs, enums, arrays, depth=0):
    p = ExprParser(tokenize(text), env, funcs, enums, arrays, depth)
    v = p.parse_expr()
    if p.peek() != ('eof', None):
        raise ValueError('trailing tokens in expr: %r' % text[:60])
    return v


# ---------------------------------------------------------------------------
# Header parsing: the engine under test
# ---------------------------------------------------------------------------

class CppFunction:
    def __init__(self, ret, name, params, body):
        self.ret = ret          # 'int' / 'bool' / 'void' / enum name
        self.name = name
        self.params = params    # list of (name, is_ref, type) or None
        self.body = body        # stripped text


def parse_params(s):
    params = []
    s = s.strip()
    if not s:
        return params
    for part in s.split(','):
        part = part.strip()
        m = re.match(r'(?:const\s+)?(\w+)\s*&\s*(\w+)$', part)
        if m:
            params.append((m.group(2), True, m.group(1)))
            continue
        m = re.match(r'(?:const\s+)?(\w+)\s+(\w+)$', part)
        if m:
            params.append((m.group(2), False, m.group(1)))
            continue
        raise ValueError('cannot parse param %r' % part)
    return params


def load_headers(rules_dir):
    funcs = {}
    enums = {}
    for fn in sorted(os.listdir(rules_dir)):
        if not fn.endswith('.h'):
            continue
        text = strip_comments(
            open(os.path.join(rules_dir, fn)).read())
        for m in re.finditer(r'enum\s+(\w+)\s*\{([^}]*)\}', text):
            val = 0
            for item in m.group(2).split(','):
                item = item.strip()
                if not item:
                    continue
                if '=' in item:
                    nm, v = item.split('=')
                    val = int(v.strip())
                    enums[nm.strip()] = val
                else:
                    enums[item] = val
                val += 1
        # return type may be int, bool, void or an enum name
        # (R205: SpyFailureResult spyFailureResult)
        for m in re.finditer(
                r'inline\s+([A-Za-z_]\w*)\s+(\w+)\s*\(([^)]*)\)\s*\{',
                text):
            ret, name, params = m.group(1), m.group(2), m.group(3)
            b0 = m.end() - 1
            b1 = match_braces(text, b0)
            body = text[b0 + 1:b1]
            if name in funcs:
                raise ValueError('duplicate function %r' % name)
            try:
                pp = parse_params(params)
            except ValueError:
                # unsupported signature (e.g. const char*): keep
                # the name on record; an audit call to it goes
                # UNVERIFIED rather than killing the load
                funcs[name] = CppFunction(ret, name, None, body)
                continue
            funcs[name] = CppFunction(ret, name, pp, body)
    return funcs, enums


def call_function(name, args, funcs, enums, arrays, depth=0):
    if name not in funcs:
        raise ValueError('call to unknown function %r' % name)
    if depth > 16:
        raise ValueError('recursion limit at %r' % name)
    f = funcs[name]
    if f.params is None:
        raise ValueError('unsupported signature: %r' % name)
    if len(args) != len(f.params):
        raise ValueError('arity mismatch calling %r' % name)
    env = {}
    for (pname, is_ref, ptype), a in zip(f.params, args):
        if ptype == 'bool':
            a = 1 if a else 0
        env[pname] = a
    ret = exec_body(f, env, funcs, enums, arrays, depth)
    refs = {}
    for (pname, is_ref, ptype) in f.params:
        if is_ref:
            refs[pname] = env.get(pname, 0)
    return (ret, refs) if refs else ret


class ReturnValue(Exception):
    def __init__(self, v):
        self.v = v


def exec_body(f, env, funcs, enums, arrays, depth):
    body = f.body.strip()
    all_arrays = dict(arrays)
    try:
        exec_stmts(f, split_statements(body), env, funcs, enums,
                   all_arrays, depth)
    except ReturnValue as rv:
        v = rv.v
        return 1 if (f.ret == 'bool' and v) else v
    return 0


def exec_stmts(f, stmts, env, funcs, enums, arrays, depth):
    for st in stmts:
        st = st.strip()
        while st:
            done = exec_one(f, st, env, funcs, enums, arrays, depth)
            if done is None:
                break
            st = done


def exec_one(f, st, env, funcs, enums, arrays, depth):
    # returns the unconsumed tail, or None when fully consumed
    st = st.strip()
    if not st:
        return None
    # if (cond) { ... }  -- braced conditional block
    if re.match(r'if\s*\(', st):
        p0 = st.index('(')
        p1 = match_parens(st, p0)
        tail = st[p1 + 1:]
        if re.match(r'\s*\{', tail):
            cond = st[p0 + 1:p1]
            b0 = st.index('{', p1)
            b1 = match_braces(st, b0)
            if eval_expr(cond, env, funcs, enums, arrays, depth):
                exec_stmts(f, split_statements(
                    st[b0 + 1:b1]), env, funcs, enums, arrays,
                    depth)
            return st[b1 + 1:]
    # bare return;
    if re.match(r'return\s*;\s*$', st, re.S):
        raise ReturnValue(0)
    # local static array (dims may be enum constants)
    m = re.match(
        r'static\s+const\s+int\s+(\w+)\s*((?:\[[^\]]+\])+)'
        r'\s*=\s*\{', st)
    if m:
        name, dims = m.group(1), m.group(2)
        b0 = st.index('{')
        b1 = match_braces(st, b0)
        flat = [int(x) for x in
                re.findall(r'-?\d+', st[b0 + 1:b1])]
        ds = []
        for d in re.findall(r'\[([^\]]+)\]', dims):
            if d.strip() in enums:
                ds.append(enums[d.strip()])
            else:
                ds.append(int(d.strip()))
        arrays[name] = (ds, flat)
        return None
    # local variable declaration with initializer
    m = re.match(r'int\s+(\w+)\s*=\s*([^;]+);$', st, re.S)
    if m:
        env[m.group(1)] = eval_expr(
            m.group(2), env, funcs, enums, arrays, depth)
        return None
    # if (cond) var op= expr;  -- clamp chains
    m = re.match(
        r'if\s*\((.*)\)\s*(?!return\b)(\w+)\s*'
        r'(\+=|-=|=)\s*([^;]+);$', st, re.S)
    if m:
        if eval_expr(m.group(1), env, funcs, enums, arrays, depth):
            rhs = eval_expr(
                m.group(4), env, funcs, enums, arrays, depth)
            op = m.group(3)
            if op == '=':
                env[m.group(2)] = rhs
            elif op == '+=':
                env[m.group(2)] = env[m.group(2)] + rhs
            else:
                env[m.group(2)] = env[m.group(2)] - rhs
        return None
    # plain assignment: var op= expr;
    m = re.match(r'(\w+)\s*(\+=|-=|=)\s*([^;]+);$', st, re.S)
    if m and m.group(1) not in ('if', 'return', 'for', 'while'):
        rhs = eval_expr(
            m.group(3), env, funcs, enums, arrays, depth)
        op = m.group(2)
        if op == '=':
            env[m.group(1)] = rhs
        elif op == '+=':
            env[m.group(1)] = env[m.group(1)] + rhs
        else:
            env[m.group(1)] = env[m.group(1)] - rhs
        return None
    # if (cond) return expr;  -- braceless conditional return
    m = re.match(
        r'if\s*\((.*)\)\s*return\s+([^;]+);$', st, re.S)
    if m:
        if eval_expr(m.group(1), env, funcs, enums, arrays,
                     depth):
            raise ReturnValue(eval_expr(
                m.group(2), env, funcs, enums, arrays, depth))
        return None
    m = re.match(r'return\s+([^;]+);$', st, re.S)
    if m:
        raise ReturnValue(eval_expr(
            m.group(1), env, funcs, enums, arrays, depth))
    raise ValueError('unsupported statement in %s: %r'
                     % (f.name, st[:70]))


def split_statements(body):
    # split on ';' at depth 0, ignoring for-loop header semicolons
    parts = []
    cur = []
    d = 0
    p = 0
    for ch in body:
        if ch == '{':
            d += 1
        elif ch == '}':
            d -= 1
        elif ch == '(':
            p += 1
        elif ch == ')':
            p -= 1
        cur.append(ch)
        if ch == ';' and d == 0 and p == 0:
            parts.append(''.join(cur))
            cur = []
    if ''.join(cur).strip():
        parts.append(''.join(cur))
    return parts


# ---------------------------------------------------------------------------
# Audit block parsing and evaluation
# ---------------------------------------------------------------------------

def find_blocks(text):
    blocks = []
    for m in re.finditer(r'printf\("(\w[^"\\]*) audit: bad %d', text):
        label = m.group(1)
        b = text.rfind('int bad = 0;', 0, m.start())
        if b < 0:
            blocks.append((label, None))
            continue
        b0 = text.rfind('{', 0, b)
        b1 = match_braces(text, b0)
        blocks.append((label, text[b0 + 1:b1]))
    return blocks


def eval_block(label, body, funcs, enums):
    if body is None:
        return (None, 0, 'no int bad = 0; found')
    text = strip_comments(body)
    env = {}
    arrays = {}
    bad = 0
    n = 0
    stmts = split_statements(text)
    i = 0
    while i < len(stmts):
        st = stmts[i].strip()
        i += 1
        if not st:
            continue
        # for-walks (possibly nested): for (int v = A; v <= B; ++v)
        loopvars = []
        while True:
            m = re.match(
                r'for\s*\(\s*int\s+(\w+)\s*=\s*([^;]+);\s*'
                r'\w+\s*(<=|<)\s*([^;]+);\s*\+\+\w+\s*\)\s*(.*)$',
                st, re.S)
            if not m:
                break
            loopvars.append((m.group(1), m.group(2), m.group(4),
                             m.group(3)))
            st = m.group(5).strip()
        if loopvars:
            bad, n, err = run_loops(
                loopvars, st, env, arrays, funcs, enums, bad, n)
            if err:
                return (None, n, err)
            continue
        # printf / bare return: no-ops for the walk
        if re.match(r'(printf|puts|fprintf|fflush|return)\b', st):
            continue
        # if (bad) return 1;  -- the halt gate, not an assert
        if re.match(r'if\s*\(\s*bad\s*\)\s*return', st):
            continue
        # int a, b;   /   int bad = 0;   /   int x = expr;
        m = re.match(r'int\s+((?:\w+\s*,\s*)*\w+)\s*;$', st)
        if m:
            for v in re.findall(r'\w+', m.group(1)):
                env[v] = 0
            continue
        m = re.match(r'int\s+(\w+)\s*=\s*([^;]+);$', st, re.S)
        if m:
            env[m.group(1)] = eval_expr(
                m.group(2), env, funcs, enums, arrays)
            continue
        # local ground-truth array
        m = re.match(
            r'static\s+const\s+int\s+(\w+)\s*((?:\[[^\]]+\])+)'
            r'\s*=\s*\{', st)
        if m:
            b0 = st.index('{')
            b1 = match_braces(st, b0)
            flat = [int(x) for x in re.findall(r'-?\d+',
                                               st[b0 + 1:b1])]
            ds = []
            for d in re.findall(r'\[([^\]]+)\]', m.group(2)):
                if d.strip() in enums:
                    ds.append(enums[d.strip()])
                else:
                    ds.append(int(d.strip()))
            arrays[m.group(1)] = (ds, flat)
            continue
        # if (cond) ++bad;  -- the assertions themselves
        m = re.match(r'if\s*\((.*)\)\s*(?:\+\+bad\s*;?)\s*$',
                     st, re.S)
        if m:
            n += 1
            if eval_expr('(' + m.group(1) + ')', env, funcs, enums,
                         arrays):
                bad += 1
            continue
        # bare rules call (reference out-params): rules::f(args);
        m = re.match(r'rules::(\w+)\s*\((.*)\)\s*;?$', st, re.S)
        if m:
            name = m.group(1)
            if name not in funcs:
                raise ValueError('call to unknown function %r'
                                 % name)
            f = funcs[name]
            if f.params is None:
                raise ValueError('unsupported signature: %r' % name)
            p = ExprParser(tokenize(m.group(2)),
                           env, funcs, enums, arrays)
            args = []
            refs = []       # (caller var, callee param name)
            k = 0
            while p.peek() != ('eof', None):
                tok = p.peek()
                pname, is_ref, ptype = f.params[k]
                if is_ref and tok[0] == 'id' and tok[1] in env:
                    # reference argument passed as a local var
                    nm = p.next()[1]
                    refs.append((nm, pname))
                    args.append(0)   # placeholder for the slot
                    if p.at_p(','):
                        p.next()
                    k += 1
                    continue
                args.append(p.parse_ternary())
                if p.at_p(','):
                    p.next()
                k += 1
            if k != len(f.params):
                raise ValueError('arity mismatch in call %r'
                                 % st[:60])
            out = call_function(name, args, funcs, enums, arrays)
            if refs:
                if not isinstance(out, tuple):
                    raise ValueError(
                        'ref vars on non-ref call %r' % name)
                _, refmap = out
                for r, pn in refs:
                    if pn not in refmap:
                        raise ValueError(
                            'ref var %r not a param of %r'
                            % (r, name))
                    env[r] = refmap[pn]
            continue
        return (None, n, 'unsupported statement: %r' % st[:70])
    return (bad, n, None)


def run_loops(loopvars, body_stmt, env, arrays, funcs, enums, bad, n):
    m = re.match(r'if\s*\((.*)\)\s*(?:\+\+bad\s*;?)\s*$', body_stmt,
                 re.S)
    if not m:
        return (bad, n, 'unsupported loop body: %r'
                % body_stmt[:70])
    cond = m.group(1)

    def rec(k, e):
        nonlocal bad, n
        if k == len(loopvars):
            n += 1
            if eval_expr('(' + cond + ')', e, funcs, enums, arrays):
                bad += 1
            return
        name, start, end, op = loopvars[k]
        lo = eval_expr(start, e, funcs, enums, arrays)
        hi = eval_expr(end, e, funcs, enums, arrays)
        v = lo
        while (v <= hi if op == '<=' else v < hi):
            e2 = dict(e)
            e2[name] = v
            rec(k + 1, e2)
            v += 1

    rec(0, env)
    return (bad, n, None)


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

def main():
    args = sys.argv[1:]
    root = os.path.dirname(os.path.dirname(
        os.path.abspath(__file__)))
    funcs, enums = load_headers(os.path.join(root, 'rules'))
    reg = open(os.path.join(root, 'regtest.cpp')).read()
    blocks = find_blocks(reg)
    total_bad = 0
    n_verified = 0
    n_partial = 0
    for label, body in blocks:
        if args and not any(a in label for a in args):
            continue
        try:
            bad, n, err = eval_block(label, body, funcs, enums)
        except Exception as ex:
            print('%-52s EVAL ERROR: %s' % (label, ex))
            n_partial += 1
            total_bad += 1
            continue
        if err is not None:
            print('%-52s UNVERIFIED (%d asserts seen): %s'
                  % (label, n, err))
            n_partial += 1
            total_bad += 1
            continue
        n_verified += 1
        total_bad += bad or 0
        if bad:
            print('%-52s *** bad %d *** over %d asserts'
                  % (label, bad, n))
        else:
            print('%-52s verified bad 0 (%d asserts)' % (label, n))
    print('-' * 64)
    print('blocks verified %d, unverified/unparseable %d, '
          'total bad %d' % (n_verified, n_partial, total_bad))
    if total_bad:
        print('AUDIT EVAL: RED - the header does not match '
              'the audit')
        sys.exit(1)
    if n_partial:
        print('AUDIT EVAL: YELLOW - RED-equivalent for gating: '
              'unverified blocks present')
        sys.exit(1)
    print('AUDIT EVAL: GREEN - every block literally verified, '
          'all bad 0')
    sys.exit(0)


if __name__ == '__main__':
    main()

