#!/usr/bin/env python3
# splice_engine: the ROUND-AGNOSTIC splice engine (the R428 tooling
# decision). A round is a JSON SPEC (data + comments + examples +
# anchors); this engine turns the spec into the nine-patch splice,
# verifies it against a Python model of the spec, and enforces every
# standing gate. The bug classes of R391/R392/R426/R427 die by
# construction here:
#   - every audit condition is evaluated against the healthy model at
#     RUN time - a condition TRUE on correct data dies before emit
#     (the R391 sense-inversion class);
#   - censuses, inline counts and boundaries are COMPUTED from the
#     spec, never hand-asserted (the R427 39-vs-38 class);
#   - the C++ emitter wraps at whole tokens only - an identifier can
#     never split across lines (the R426 class);
#   - string-literal parity and brace balance gates on every emitted
#     file (the R392 class).
# Usage: python3 splice_engine.py <spec.json>
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

NL = '\n'
WIDTH = 78
OPENER_W = 92


def die(msg):
    print('splice ENGINE ABORT: ' + msg)
    sys.exit(1)


# ---------- the spec ----------

if len(sys.argv) != 2:
    die('usage: splice_engine.py <spec.json>')
with open(sys.argv[1]) as fh:
    S = json.load(fh)

RND = S['round']
PFX = S['prefix']
HDR = S['header_file']
RT = S['regtest']
GR = S['gap_report']
SD = S['seed_file']


def rd(p):
    with open(p) as fh:
        return fh.read()


def wr(p, s):
    with open(p, 'w') as fh:
        fh.write(s)


# ---------- the model: spec -> python callables ----------

from speclib import build_model, audit_bad

# ---------- the C++ emitters ----------

def comment_lines(text, indent='// '):
    words = text.split(' ')
    out = []
    cur = indent
    for w in words:
        cand = cur + ' ' + w if cur != indent else cur + w
        if len(cand) > WIDTH:
            out.append(cur.rstrip())
            cur = indent + w
        else:
            cur = cand
    out.append(cur.rstrip())
    return out


def emit_const(c):
    v = 'true' if c['value'] is True else (
        'false' if c['value'] is False else str(c['value']))
    ty = c.get('type',
               'bool' if isinstance(c['value'], bool)
               else 'int')
    lines = comment_lines(c.get('comment', ''))
    lines += ['inline %s %s()' % (ty, c['name']),
              '    { return %s; }' % v, '']
    return lines


def emit_switch(sw):
    lines = comment_lines(sw.get('comment', ''))
    lines.append('inline int %s(int b)' % sw['name'])
    lines.append('    {')
    lines.append('        switch (b) {')
    for i, v in enumerate(sw['values']):
        lines.append('        case %d:' % i)
        lines.append('            return %d;' % v)
    lines.append('        default:')
    lines.append('            return %d;'
                 % sw.get('default', sw['values'][-1]))
    lines.append('        }')
    lines.append('    }')
    lines.append('')
    return lines


def emit_chain(ch):
    lines = comment_lines(ch.get('comment', ''))
    lines.append('inline int %s(int %s)' % (ch['name'], ch.get('arg', 'x')))
    lines.append('    {')
    for i, lim in enumerate(ch['limits']):
        lines.append('        if (%s <= %d) return %d;'
                     % (ch.get('arg', 'x'), lim, i))
    lines.append('        return %d;' % ch['tail'])
    lines.append('    }')
    lines.append('')
    return lines


def build_header():
    b = S['banner']
    opener = ('// ' + '=' * 89)[:OPENER_W]
    lines = [opener,
             '// Adnd1 - %s' % HDR]
    lines += comment_lines(b['title'])
    lines += comment_lines('census %d -> %d.'
                           % (S['census_before'],
                              S['census_before'] + 1))
    lines.append('//')
    lines += comment_lines(b['provenance'])
    lines.append('//')
    if b.get('sentinel'):
        lines += comment_lines(b['sentinel'])
        lines.append('//')
    lines.append('namespace rules {')
    lines.append('')
    pools = {'const': {c['name']: c for c in S['consts']},
             'bool': {c['name']: c for c in S['bools']},
             'chain': {c['name']: c for c in S['chains']},
             'table': {c['name']: c for c in S['tables']},
             'switch': {c['name']: c
                        for c in S.get('switches', [])}}
    for sec in S['header_sections']:
        lines.append('// ---- %s ----' % sec)
        lines.append('')
        for item in S['header_sections'][sec]:
            pool = pools[item['kind']]
            src = pool[item['name']]
            if item['kind'] in ('const', 'bool'):
                lines += emit_const(src)
            elif item['kind'] == 'switch':
                lines += emit_switch(src)
            elif item['kind'] == 'chain':
                lines += emit_chain(src)
            elif item['kind'] == 'table':
                for c, col in enumerate(src['cols']):
                    lines += emit_switch({
                        'name': col,
                        'values': [row[c]
                                   for row in src['data']],
                        'default': src.get('col_default',
                                          src.get('sentinel')),
                        'comment': src['col_comments'][c]})
    lines.append('}   // namespace rules')
    return NL.join(lines) + NL


def py_expr_to_cpp(expr):
    # spec examples use m['name'](...) - translate to name(...)
    return re.sub(r"m\['(\w+)'\]", r'\1', expr)


def emit_audit():
    lbl = S['audit_label']
    if len('        printf("%s: bad %%d\\n", bad);' % lbl) > WIDTH:
        die('the audit label is too long for one '
            'line (the R389 class): %d cols' % len(lbl))
    head = ['    // ---- %s ----' % lbl]
    head += comment_lines(S['audit_comment'], '    // ')
    head += ['    {',
             '        using namespace rules;',
             '        int bad = 0;']
    body = []
    # consts and bools: one fail-on-wrong if per group
    conds = []
    for c in S.get('consts', []):
        conds.append('%s() != %d' % (c['name'], c['value'])
                     if not isinstance(c['value'], bool)
                     else '!%s()' % c['name'])
    for b in S.get('bools', []):
        conds.append('!%s()' % b['name'] if b['value']
                     else '%s()' % b['name'])
    if conds:
        body += emit_cond(conds, 'if', '')
        body.append('            ++bad;')
    # tables
    for t in S.get('tables', []):
        body += emit_table_audit(t)
    # chain boundaries
    for ch in S.get('chains', []):
        body += comment_lines('the %s band-for '
                              'boundaries' % ch['name'],
                              '        // ')
        conds = []
        f = ch['name']
        lims = ch['limits']
        conds.append('%s(%d) != 0'
                     % (f, lims[0] - 1))
        for i, lim in enumerate(lims):
            conds.append('%s(%d) != %d' % (f, lim, i))
            if i > 0:
                conds.append('%s(%d) != %d'
                             % (f, lims[i - 1] + 1, i))
        conds.append('%s(%d) != %d'
                     % (f, lims[-1] + 1, ch['tail']))
        body += emit_cond(conds, 'if', '')
        body.append('            ++bad;')
    # examples and table checks
    for ex in S.get('examples', []) + S.get('table_checks', []):
        e = py_expr_to_cpp(ex['expr'])
        e = e.replace(' or ', ' || ')
        body += comment_lines(ex.get('note', 'the example'),
                              '        // ')
        body += emit_cond(e.split(' || '), 'if', '')
        body.append('            ++bad;')
    tail = ['        printf("%s: bad %%d\\n", bad);' % lbl,
            '        if (bad) return 1;',
            '    }']
    return head + body + tail


def _wrap_cond(cond, first_prefix, cont_prefix):
    # greedy wrap on whole tokens. In an infix token
    # stream two adjacent operand tokens never occur, so
    # every break lands next to an operator or a paren -
    # no identifier ever splits; the no-split gate
    # verifies this anyway.
    # R431: only the FIRST line of a wrapped
    # condition carries the prefix ('if (' or '|| ');
    # continuations are plain-indented. Re-prefixing
    # every wrapped chunk with 'if (' emitted invalid
    # C++ (each chunk opened a fresh paren and read as
    # a new condition) - the cond syntax gate below
    # now kills this class at emit time.
    toks = cond.split(' ')
    lines = []
    cur = []
    pre = first_prefix
    for tk in toks:
        cand = ' '.join(cur + [tk])
        if len(pre) + len(cand) > WIDTH and cur:
            lines.append(pre + ' '.join(cur))
            cur = [tk]
            pre = cont_prefix
        else:
            cur.append(tk)
    lines.append(pre + ' '.join(cur))
    return lines


def emit_cond(conds, kw, pad):
    # emit 'if (c1\n            || c2\n        )'; every
    # condition wrapped at operator boundaries, whole
    # tokens only. A wrapped chunk is NOT a new
    # condition, so a continuation line never repeats
    # the 'if (' or '|| ' prefix (the R431 fix)
    out = []
    out += _wrap_cond(conds[0], '    %s (' % kw,
                      '        ')
    for c in conds[1:]:
        out += _wrap_cond(c, '            || ',
                          '            ')
    out.append('        )')
    return out


def emit_table_audit(t):
    tag = t['tag']
    rows = len(t['data'])
    ncol = len(t['cols'])
    sent = t.get('sentinel')
    body = []
    body += comment_lines(t.get('audit_comment',
                                 'the %s grid' % t['name']),
                          '        // ')
    body.append('        int C%s[%d][%d] = {'
                % (tag, rows, ncol))
    for row in t['data']:
        body.append('            {%s},'
                    % ','.join(str(v) for v in row))
    body.append('            };')
    if t.get('sentinel_census'):
        zero = ','.join('0' for _ in t['cols'])
        want = ','.join(str(v)
                        for v in t['sentinel_census'])
        body.append('        int n%s[%d] = {%s};'
                    % (tag, ncol, zero))
        body.append('        int e%s[%d] = {%s};'
                    % (tag, ncol, want))
    body.append('        for (int b = 0;')
    body.append('             b < %s();' % t['count'])
    body.append('             ++b) {')
    body.append('            int vals[%d];' % ncol)
    for c, col in enumerate(t['cols']):
        body.append('            vals[%d] = %s(b);'
                    % (c, col))
    body.append('            for (int c = 0; c < %d;'
                % ncol)
    body.append('                 ++c) {')
    body.append('                if (vals[c] != '
                'C%s[b][c])' % tag)
    body.append('                    ++bad;')
    if t.get('sentinel_census'):
        body.append('                if (vals[c] == %d)'
                    % sent)
        body.append('                    ++n%s[c];' % tag)
    body.append('            }')
    pr = t.get('pair')
    if pr:
        body += ['            if ((%s(b) == %d)'
                 % (pr['num'], sent),
                 '                    != (%s(b) == %d))'
                 % (pr['den'], sent),
                 '                || (%s(b) != %d'
                 % (pr['num'], sent),
                 '                    && %s(b)'
                 % pr['den'],
                 '                    != %s(b) + 1))'
                 % pr['num'],
                 '                ++bad;']
    body.append('        }')
    if t.get('sentinel_census'):
        body.append('        for (int c = 0; '
                    'c < %d; ++c)' % ncol)
        body.append('            if (n%s[c] != e%s[c])'
                    % (tag, tag))
        body.append('                ++bad;')
    return body


# ---------- build the emitted artifacts ----------

HDR_TXT = build_header()
AUD_BLOCK = NL.join(emit_audit()) + NL

# ---------- the static gates (the R392/R426 lessons) ----------

_idc = ('_' 'abcdefghijklmnopqrstuvwxyz'
        'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        '0123456789')


def gate_lines(txt, name, opener_ok):
    lines = txt.split(NL)
    for i, ln in enumerate(lines):
        limit = OPENER_W if (opener_ok and i == 0) else WIDTH
        if len(ln) > limit:
            die('a %s line is %d cols '
                '(max %d): %r'
                % (name, len(ln), limit, ln[:40]))
    # no identifier ever split across lines
    prev = ''
    for ln in lines:
        c = ln.strip()
        pt = prev.rstrip()
        if (c and not c.startswith('//')
                and pt and not pt.lstrip().startswith('//')
                and pt[-1] in _idc and c[0] in _idc):
            import os as _os
            if _os.environ.get('SPLICE_DUMP'):
                print(txt)
            die('a split identifier in %s '
                '(%r|%r) - the R426 class'
                % (name, pt[-20:], c[:20]))
        prev = ln
    # string literal parity per code line
    for ln in lines:
        s = ln.strip()
        if s.startswith('//'):
            continue
        n = 0
        i = 0
        while i < len(ln):
            if ln[i] == chr(92):
                i += 2
                continue
            if ln[i] == '"':
                n += 1
            i += 1
        if n % 2:
            die('an unterminated string in %s: %r' % (name, ln))
    # brace balance
    depth = 0
    for ln in lines:
        s = ln.strip()
        if s.startswith('//') or s.startswith('*'):
            continue
        depth += ln.count('{') - ln.count('}')
    if depth != 0:
        die('the %s brace balance is %d' % (name, depth))


gate_lines(HDR_TXT, 'the header', True)
gate_lines(AUD_BLOCK, 'the audit', False)


# ---------- the cond syntax gate (the R431 lesson) ----------
# The audit mirror proves the round's LOGIC in python;
# this gate proves the emitted C++ PARSES: rejoin every
# wrapped 'if (' statement and check the token stream
# is a well-formed infix expression with balanced
# parens. Born of the R430 landing: a condition longer
# than 78 cols wrapped with 'if (' re-prefixing per
# chunk, the regtest would not compile, and with the
# preflight skipped nothing caught it until R431's.

_COND_OPS = ('+', '-', '*', '/', '%', '==', '!=',
             '<=', '>=', '<', '>', '&&', '||')


def gate_cond_syntax(txt, name):
    lines = txt.split(NL)
    i = 0
    while i < len(lines):
        ln = lines[i]
        if not ln.startswith('    if ('):
            i += 1
            continue
        stmt = [ln]
        j = i + 1
        while (j < len(lines)
               and lines[j].strip() != ')'):
            if lines[j].startswith('    if ('):
                die('a repeated if ( prefix in a '
                    '%s condition - the R431 wrap '
                    'class' % name)
            stmt.append(lines[j])
            j += 1
        if j >= len(lines):
            die('an unterminated if ( in %s' % name)
        # the collector stops AT the ')' closer line
        # without appending it, so the joined text is
        # exactly 'if (' + the condition body
        text = ' '.join(x.strip() for x in stmt)
        expr = text[len('if ('):].rstrip()
        if expr.count('(') != expr.count(')'):
            die('unbalanced parens in a %s '
                'condition: %r' % (name, expr[:40]))
        expect_operand = True
        for tk in expr.split(' '):
            if tk in ('(', ')'):
                continue
            if expect_operand:
                # strip prefix negation - but only in
                # operand position; in operator position
                # '!=' must stay whole
                while tk.startswith('!'):
                    tk = tk[1:]
                if (tk.startswith('-')
                        and len(tk) > 1):
                    tk = tk[1:]
                ok = (tk and (tk[0] in _idc
                             or tk[0] == '(')
                      and all(c in _idc or c in '()-'
                              for c in tk))
                if tk in _COND_OPS or not ok:
                    die('an operand expected in a %s '
                        'condition: %r'
                        % (name, tk[:30]))
                expect_operand = False
            else:
                if tk not in _COND_OPS:
                    die('an operator expected in a %s '
                        'condition: %r'
                        % (name, tk[:30]))
                expect_operand = True
        if expect_operand:
            die('a dangling operator in a %s '
                'condition' % name)
        i = j + 1


gate_cond_syntax(AUD_BLOCK, 'audit')

n_inline = HDR_TXT.count('inline ')
if n_inline != S['inline_count']:
    die('the header inline count is %d, '
        'the spec says %d' % (n_inline,
                              S['inline_count']))

# ---------- the prefix collision gate (the R411 lesson) ----------
# keyed on this round's audit being absent, so a re-run over
# a patched tree stays GREEN (idempotency)

RT0 = rd(RT)
if ('"%s: bad ' % S['audit_label']) not in RT0 \
        and re.search(r'\b%s\w*\(' % PFX, RT0):
    die('the %s prefix is not free in '
        'regtest' % PFX)
for path in S.get('caller_files', []):
    if re.search(r'\b%s\w' % PFX, rd(path)):
        die('the %s prefix is not free in '
            '%s' % (PFX, path))

# ---------- the patches ----------

applied = []
already = []


# ALL patches are computed in memory first and written
# at the END - a missing anchor late in the sequence
# leaves the tree untouched (no half-patched states)
writes = []

# (a) the seed: the previous round record goes right before
# the '## Knowledge maintenance' anchor (no blank line between)
seed_key = S['prev_seed_key']
sd = rd(SD)
if seed_key in sd:
    already.append('seed')
else:
    anchor = NL + S['seed_anchor']
    if anchor not in sd:
        die('the seed anchor is missing')
    rec = [S['prev_record']] if isinstance(S['prev_record'], str) \
        else list(S['prev_record'])
    rec = [l.rstrip() for l in rec]
    if max(len(l) for l in rec) > WIDTH:
        die('a seed record line is over '
            '%d cols (the R427 class)' % WIDTH)
    sd = sd.replace(anchor,
                    NL + NL.join(rec) + anchor, 1)
    writes.append((SD, sd))
    applied.append('seed')

# (b) the header
if os.path.exists(HDR):
    already.append('header')
else:
    writes.append((HDR, HDR_TXT))
    applied.append('header')

# (c) the gap flips
gr = rd(GR)
for flip in S['gap_flips']:
    if flip['to'] in gr:
        already.append('gap: %s' % flip['note'])
    else:
        if flip['from'] not in gr:
            die('the gap flip anchor is '
                'missing: %s' % flip['note'])
        gr = gr.replace(flip['from'], flip['to'], 1)
        applied.append('gap: %s' % flip['note'])
if applied and not already:
    writes.append((GR, gr))
gc = S.get('gap_census')
if gc:
    if gr.count('- [x]') != gc['closed']:
        die('the gap closed count is %d, '
            'want %d' % (gr.count('- [x]'),
                         gc['closed']))
    nopen = len([l for l in gr.split(NL)
                 if l.lstrip().startswith('- [ ]')])
    if nopen != gc['open']:
        die('the gap open count is %d, '
            'want %d' % (nopen, gc['open']))

# (d) the include
rt = rd(RT)
inc = '#include "%s"  // R%d: %s' % (HDR, RND, S['include_comment'])
if inc in rt:
    already.append('include')
else:
    after = S['include_after']
    if after not in rt:
        die('the include anchor is missing')
    rt = rt.replace(after, after + NL + inc, 1)
    applied.append('include')

# (e) the audit block
lbl = S['audit_label']
if ('"%s: bad ' % lbl) in rt:
    already.append('audit')
else:
    anchor = S['audit_anchor']
    if anchor not in rt:
        die('the audit anchor is missing')
    rt = rt.replace(anchor, AUD_BLOCK + anchor, 1)
    applied.append('audit')
writes.append((RT, rt))

# (f) the file patches (the R774 tooling
# extension): spec-declared extra-file
# patches with gap-flip semantics - a
# byte-exact 'from' anchor, one replace,
# idempotent by 'to'-presence, and each
# patch counted in the applied/already
# census so the double-run gate covers
# them exactly like a gap flip
for fp in S.get('file_patches', []):
    p = fp['file']
    if not os.path.exists(p):
        die('the file patch target is '
            'missing: %s' % p)
    if p == RT:
        # RT is engine-patched in
        # memory (the include and
        # the audit); the file
        # patch rides that text,
        # never the pristine disk
        # copy (the clobber class:
        # the deferred writes would
        # lose the include and the
        # audit to the stale read)
        txt = rt
    else:
        txt = rd(p)
    if fp['to'] in txt:
        already.append('file: %s'
                       % fp['note'])
    else:
        if fp['from'] not in txt:
            die('the file patch anchor is '
                'missing: %s' % fp['note'])
        txt = txt.replace(fp['from'],
                          fp['to'], 1)
        writes.append((p, txt))
        applied.append('file: %s'
                       % fp['note'])

# ---------- the idempotency gate (the R420 lesson) ----------

if applied and already:
    die('the mixed applied/already state - '
        'restore the tree and re-run '
        '(the R420 lesson)')

# ---------- write everything (all-or-nothing) ----------

for p, t in writes:
    wr(p, t)

# ---------- the verify pass: parse the emitted header ----------
# and audit it with the model (the R368 lesson generalized) ----------

rt_final = rd(RT)
census = rt_final.count('audit: bad')
want = S['census_before'] + 1
if census != want:
    die('the census is %d, want %d'
        % (census, want))
if rt_final.count('"%s: bad ' % lbl) != 1:
    die('the audit label count is not 1')

hdr_final = rd(HDR)
if hdr_final.count('inline ') != S['inline_count']:
    die('the emitted header inline count '
        'drifted')


def parse_header(path):
    src = rd(path).replace(
        'return true;', 'return 1;').replace(
        'return false;', 'return 0;')
    fns = {}
    idxs = [m.start() for m in
            re.finditer(r'inline \w+ ', src)]
    idxs.append(len(src))
    for i in range(len(idxs) - 1):
        chunk = src[idxs[i]:idxs[i + 1]]
        d = re.match(
            r'inline \w+ (\w+)\((.*?)\)\s*\{(.*?)\n?\s*\}',
            chunk, re.S)
        if not d:
            continue
        name, args, body = d.group(1), \
            d.group(2).strip(), d.group(3)
        if re.fullmatch(r'-?\d+', body.strip()):
            fns[name] = ('const', None, int(body))
            continue
        cases = {int(k): int(v) for k, v in
                 re.findall(r'case (\d+):\s*'
                            r'return (-?\d+);', body)}
        chain = [(int(a), int(b)) for a, b in
                 re.findall(r'if \(\w+ <= (-?\d+)\)'
                            r'\s*return (-?\d+);', body)]
        tails = list(re.finditer(
            r'return (-?\d+);', body))
        tv = int(tails[-1].group(1)) if tails else None
        if args == 'int b' and cases:
            fns[name] = ('switch', cases, tv)
        elif chain:
            fns[name] = ('chain', chain, tv)
        else:
            fns[name] = ('const', None, tv)
    return fns


def parsed_model(fns):
    m = {}
    def mk(f):
        if f[0] == 'switch':
            return lambda b: f[1].get(b, f[2])
        if f[0] == 'chain':
            return lambda x: next(
                (r for lim, r in f[1] if x <= lim), f[2])
        return lambda *a: f[2]
    for n, f in fns.items():
        m[n] = mk(f)
    return m


fns = parse_header(HDR)
if len(fns) != S['inline_count']:
    die('the parser found %d functions, '
        'want %d' % (len(fns), S['inline_count']))
pm = parsed_model(fns)
if audit_bad(pm, S) != 0:
    die('the EMITTED header fails its own '
        'audit mirror (%d bad)' % audit_bad(pm, S))

print('R%d splice engine: ALL OK '
      '(applied %d, already %d)'
      % (RND, len(applied), len(already)))
print('NOTE: census %d -> %d; '
      'the audit mirror is clean against '
      'the emitted header'
      % (S['census_before'], want))
print('commit: R%d: %s '
      '(census %d)'
      % (RND, S['title'], want))

