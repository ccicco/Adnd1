#!/usr/bin/env python3
# dmg class refactor - namespaces out, instance classes in, .h/.cpp split.
# R-rule: pure stdlib, idempotent, dies loudly on anything unexpected.
import os
import re
import sys

FAIL = "REORG RED:"


def die(msg):
    print(FAIL, msg)
    sys.exit(1)


def repo_root():
    d = os.path.dirname(os.path.abspath(__file__))
    root = os.path.dirname(d)
    if not os.path.isdir(os.path.join(root, "rules", "dmg")):
        die("cannot locate rules/dmg from " + root)
    return root


# ---------------------------------------------------------------- scanning


def segments(text):
    """Split text into code/comment/string segments (start, end, kind)."""
    out = []
    i = 0
    n = len(text)
    while i < n:
        c = text[i]
        if c == "/" and i + 1 < n and text[i + 1] == "/":
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append((i, j, "comment"))
            i = j
        elif c == "/" and i + 1 < n and text[i + 1] == "*":
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append((i, j, "comment"))
            i = j
        elif c == '"' or c == "'":
            q = c
            j = i + 1
            while j < n:
                if text[j] == "\\":
                    j += 2
                    continue
                if text[j] == q:
                    j += 1
                    break
                j += 1
            out.append((i, j, "string"))
            i = j
        else:
            j = i
            while j < n and text[j] not in '/"\'':
                j += 1
            if j == i:  # lone '/' (division): do not stall
                j = i + 1
            out.append((i, j, "code"))
            i = j
    return out


def code_of(text):
    """Text with comments and strings blanked (positions preserved)."""
    buf = list(text)
    for a, b, k in segments(text):
        if k != "code":
            for x in range(a, b):
                buf[x] = " "
    return "".join(buf)


def find_matching_brace(text, open_pos):
    """open_pos indexes a '{' in code; return index of matching '}'."""
    blank = code_of(text)
    depth = 0
    for x in range(open_pos, len(blank)):
        c = blank[x]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return x
    die("unbalanced braces from offset %d" % open_pos)


# ---------------------------------------------------------------- header parse

SIG_RE = re.compile(
    r"^(?P<quals>(?:inline|constexpr|static)\s+)*(?P<ret>.+?)\s*"
    r"(?P<name>[A-Za-z_]\w*)\s*\((?P<params>[^()]*)\)\s*$"
)


def parse_dmg_header(path, text):
    """Return (pre, items, tail, close_pos) for a namespace-rules header."""
    blank = code_of(text)
    m = re.search(r"\bnamespace\s+rules\s*\{", blank)
    if not m:
        return None
    open_pos = blank.index("{", m.start())
    close_pos = find_matching_brace(blank, open_pos)
    pre = text[: m.start()]
    items = []
    tail = ""
    pos = open_pos + 1
    segs = segments(text)
    # walk the namespace body: whitespace/comment runs become item leads
    while True:
        lead_start = pos
        lead_end = pos
        while lead_end < close_pos:
            in_code = False
            for a, b, k in segs:
                if a <= lead_end < b:
                    if k == "code" and not text[lead_end].isspace():
                        in_code = True
                    break
            if in_code:
                break
            lead_end += 1
        if lead_end >= close_pos:
            tail = text[lead_start:close_pos]
            break
        lead = text[lead_start:lead_end]
        pos = lead_end
        # classify item by next code word
        wm = re.match(r"\s*(\w+)", blank[pos:close_pos])
        word = wm.group(1) if wm else ""
        if word in ("enum", "struct"):
            # find the opening brace of the aggregate
            bo = blank.index("{", pos)
            bc = find_matching_brace(blank, bo)
            # require ';' right after (possibly over comments)
            rest = code_of(text[bc + 1: close_pos])
            if not re.match(r"\s*;", rest):
                die("%s: %s not followed by ';'" % (path, word))
            end = close_pos
            semi_rel = re.match(r"\s*;", rest).end()
            # locate actual ';' in original text
            seek = bc + 1
            while True:
                in_code = False
                for a, b, k in segs:
                    if a <= seek < b:
                        in_code = k == "code"
                        break
                if in_code and text[seek] == ";":
                    break
                seek += 1
            end = seek + 1
            body = text[pos:end]
            name_m = re.search(word + r"\s+([A-Za-z_]\w*)", blank[pos:end])
            name = name_m.group(1) if name_m else None
            if name is None:
                die("%s: anonymous %s" % (path, word))
            items.append(("type", word, name, body, lead))
            pos = end
        elif word:
            # function: signature runs to the first code '{' (or ';')
            bo = blank.find("{", pos)
            semi = blank.find(";", pos)
            if 0 <= semi < bo if bo >= 0 else True:
                pass
            if bo < 0 or (0 <= semi < bo):
                # declaration only: runs to ';'
                seek = pos
                while text[seek] != ";":
                    seek += 1
                sig_raw = text[pos:seek]
                sig = " ".join(code_of(sig_raw).split())
                sm = SIG_RE.match(sig)
                if not sm:
                    die("%s: unparseable decl: %r" % (path, sig))
                items.append(
                    ("decl", sm.group("ret"), sm.group("name"),
                     sm.group("params"), lead))
                pos = seek + 1
                continue
            sig_raw = text[pos:bo]
            sig = " ".join(code_of(sig_raw).split())
            sm = SIG_RE.match(sig)
            if not sm:
                die("%s: unparseable signature: %r" % (path, sig))
            bc = find_matching_brace(blank, bo)
            body = text[bo: bc + 1]
            items.append(
                ("fn", sm.group("ret"), sm.group("name"), sm.group("params"),
                 lead, body))
            pos = bc + 1
        else:
            die("%s: unrecognized item at offset %d (word %r)"
                % (path, pos, word))
    return pre, items, tail, close_pos


def camel(stem):
    return stem[0].upper() + stem[1:]


def inst_name(cls):
    return cls[0].lower() + cls[1:]


# ---------------------------------------------------------------- generation


def build_inventory(root, files):
    """Parse all dmg headers; return per-file records and symbol maps."""
    fn2owner = {}   # fn name -> stem
    type_names = {}  # enum/struct name -> stem
    enums_by_stem = {}
    recs = {}
    for fname in files:
        stem = fname[:-2]
        path = os.path.join(root, "rules", "dmg", fname)
        text = open(path, encoding="utf-8").read()
        parsed = parse_dmg_header(path, text)
        recs[stem] = parsed
        if parsed is None:
            continue
        pre, items, tail, close_pos = parsed
        for it in items:
            if it[0] in ("fn", "decl"):
                nm = it[2]
                if nm in fn2owner and fn2owner[nm] != stem:
                    die("fn name %s defined in both %s and %s"
                        % (nm, fn2owner[nm], stem))
                fn2owner[nm] = stem
            else:
                nm = it[2]
                if nm in type_names and type_names[nm] != stem:
                    die("type name %s defined in both %s and %s"
                        % (nm, type_names[nm], stem))
                type_names[nm] = stem
    # enumerators -> owner stem
    enumerators = {}
    for stem, parsed in recs.items():
        if parsed is None:
            continue
        for it in parsed[1]:
            if it[0] == "type" and it[1] == "enum":
                body = it[3]
                brace = body.index("{")
                # blank comments/strings FIRST: a comma inside a trailing
                # comment must not split the enumerator list (R-fix)
                inner = code_of(body[brace + 1: body.rindex("}")])
                for part in inner.split(","):
                    ident = re.match(r"\s*([A-Za-z_]\w*)", part)
                    if ident:
                        enumerators.setdefault(ident.group(1), stem)
    return recs, fn2owner, type_names, enumerators


def generate(root, stem, parsed, fn2stem, sym2stem, efn, etype, eenum):
    """Write the new .h and .cpp for one dmg file. Returns True if applied."""
    pre, items, tail, close_pos = parsed
    cls = camel(stem)
    hpath = os.path.join(root, "rules", "dmg", stem + ".h")
    cpppath = os.path.join(root, "rules", "dmg", stem + ".cpp")
    # foreign includes needed by this file's declarations/bodies
    foreign = set()
    all_ids = set(re.findall(r"[A-Za-z_]\w*", code_of(
        open(hpath, encoding="utf-8").read())))
    for ident in all_ids:
        owner = fn2stem.get(ident) or sym2stem.get(ident)
        if owner and owner != stem:
            foreign.add(owner)
    engine_uses = sorted(x for x in all_ids & etype)
    h = [pre.rstrip("\n")]
    for f in sorted(foreign):
        h.append('#include "rules/dmg/%s.h"  // R-refactor: cross-file symbol'
                 % f)
    if foreign:
        h.append("")
    for x in engine_uses:
        h.append("using rules::%s;  // R-refactor: engine type, was "
                 "namespace-implicit" % x)
    if engine_uses:
        h.append("")
    h.append("")
    types = [it for it in items if it[0] == "type"]
    for it in types:
        h.append(it[4].rstrip() if it[4].strip() else "")
        h.append(it[3].rstrip())
        h.append("")
    h.append("// R-refactor: namespace rules -> class %s (instance methods)" % cls)
    h.append("class %s {" % cls)
    h.append("public:")
    fns = [it for it in items if it[0] in ("fn", "decl")]
    for it in fns:
        lead = it[4] if it[0] == "fn" else it[-1]
        if lead.strip():
            h.append(lead.rstrip("\n"))
        h.append("    %s %s(%s);" % (it[1].replace("inline ", ""), it[2],
                                     it[3]))
    h.append("};")
    if tail.strip():
        h.append("")
        h.append(tail.rstrip())
    htext = "\n".join(h) + "\n"
    cpp = ["// R-refactor: split from %s.h - definitions" % stem]
    cpp.append('#include "rules/dmg/%s.h"' % stem)
    if foreign:
        cpp.append("")
    for it in fns:
        if it[0] == "decl":
            continue
        body = it[5]
        # cross-file calls inside the body
        used = set()
        for ident in set(re.findall(r"[A-Za-z_]\w*", code_of(body))):
            owner = fn2stem.get(ident)
            if owner and owner != stem:
                used.add(owner)
        b = qualify_engine(body, efn, eenum)
        inserts = []
        for other in sorted(used):
            ocls = camel(other)
            oinst = inst_name(ocls)
            if re.search(r"\b%s\b" % oinst, code_of(b)):
                oinst = "inst_" + oinst
            # rewrite calls to that file's fns
            for ident in fn_names_of.get(other, ()):
                b = re.sub(r"(?<![\w.:>&])(%s)\s*\(" % ident,
                           "%s.\\1(" % oinst, b)
            inserts.append("    %s %s;" % (ocls, oinst))
        if inserts:
            # inject right after the opening brace
            b = b[0] + "\n" + "\n".join(inserts) + b[1:]
        params = it[3]
        if "=" in params:
            params = strip_defaults(params)
        cpp.append("")
        cpp.append("%s %s::%s(%s) %s" % (it[1].replace("inline ", ""),
                                         cls, it[2], params, b))
    cpptext = "\n".join(cpp) + "\n"
    old = open(hpath, encoding="utf-8").read()
    if old == htext and (os.path.exists(cpppath) and
                         open(cpppath, encoding="utf-8").read() == cpptext):
        return False
    open(hpath, "w", encoding="utf-8").write(htext)
    open(cpppath, "w", encoding="utf-8").write(cpptext)
    return True


def strip_defaults(params):
    parts = []
    depth = 0
    cur = ""
    for ch in params:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append(cur)
            cur = ""
            continue
        cur += ch
    parts.append(cur)
    out = []
    for p in parts:
        d = p.find("=")
        out.append(p if d < 0 else p[:d].rstrip())
    return ", ".join(x.strip() for x in out)


# ---------------------------------------------------------------- caller rewrite


def build_engine_inventory(root):
    """Symbols still inside namespace rules (engine + seams): dmg code
    referencing them bare must be qualified or using-declared."""
    efn, etype, eenum = set(), set(), set()
    for sub in sorted(os.listdir(os.path.join(root, "rules"))):
        if sub in ("dmg", "audits"):
            continue
        d = os.path.join(root, "rules", sub)
        if not os.path.isdir(d):
            continue
        for f in os.listdir(d):
            if not f.endswith(".h"):
                continue
            code = code_of(open(os.path.join(d, f),
                                encoding="utf-8").read())
            efn.update(re.findall(
                r"^inline\s[^;(){}]*?\b([A-Za-z_]\w*)\s*\(", code,
                re.M))
            etype.update(re.findall(
                r"\b(?:class|struct|enum)\s+([A-Za-z_]\w*)", code))
            for m in re.finditer(r"\benum\s+[A-Za-z_]\w*\s*\{(.*?)\}",
                                 code, re.S):
                for part in m.group(1).split(","):
                    ident = re.match(r"\s*([A-Za-z_]\w*)", part)
                    if ident:
                        eenum.add(ident.group(1))
    return efn, etype, eenum


def qualify_engine(body, efn, eenum):
    """Comment/string-aware: bare engine fn calls and enumerators in a
    dmg body get rules:: qualified (they lost the namespace context)."""
    out = []

    def one_seg(seg):
        def sfn(m):
            return "rules::" + m.group(0) if m.group(1) in efn \
                else m.group(0)
        def sen(m):
            return "rules::" + m.group(1) if m.group(1) in eenum \
                else m.group(0)
        seg = re.sub(r"(?<![\w.:])([A-Za-z_]\w*)\s*\(", sfn, seg)
        seg = re.sub(r"(?<![\w.:])([A-Za-z_]\w*)\b", sen, seg)
        return seg

    for a, b, k in segments(body):
        if k != "code":
            out.append(body[a:b])
        else:
            out.append(one_seg(body[a:b]))
    return "".join(out)


def alternation(names):
    return "|".join(sorted(names, key=len, reverse=True))


def rewrite_callers(root, fn2cls, syms):
    """Rewrite all non-dmg call sites; returns (files_changed, edits)."""
    changed = 0
    edits_total = 0
    qual_fn_re = re.compile(r"rules::\b(%s)\s*\(" % alternation(fn2cls))
    qual_sym_re = re.compile(r"rules::\b(%s)\b" % alternation(syms))
    bare_fn_re = re.compile(r"(?<![\w.:>&])(%s)\s*\(" % alternation(fn2cls))
    all_names = set(fn2cls) | set(syms)
    ident_re = re.compile(r"[A-Za-z_]\w*")
    dmg_dir = os.path.join(root, "rules", "dmg")
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames
                       if d != ".git"
                       and os.path.join(dirpath, d) != dmg_dir]
        for fn in filenames:
            if not (fn.endswith(".h") or fn.endswith(".cpp")):
                continue
            path = os.path.join(dirpath, fn)
            text = open(path, encoding="utf-8").read()
            if not (set(ident_re.findall(code_of(text))) & all_names):
                continue
            new_text, edits = rewrite_one(
                path, text, qual_fn_re, qual_sym_re, bare_fn_re, fn2cls)
            if edits:
                open(path, "w", encoding="utf-8").write(new_text)
                changed += 1
                edits_total += edits
    return changed, edits_total


def rewrite_one(path, text, qual_fn_re, qual_sym_re, bare_fn_re, fn2cls):
    blank = code_of(text)
    inst = {}
    stripped = qual_fn_re.sub("", blank)
    stripped = bare_fn_re.sub("", stripped)
    stripped = qual_sym_re.sub("", stripped)

    def rw(seg):
        def qfn(m):
            nm = get_inst(inst, fn2cls[m.group(1)], stripped)
            return "%s.%s(" % (nm, m.group(1))
        new = qual_fn_re.sub(qfn, seg)
        new = qual_sym_re.sub(r"\1", new)
        new = bare_fn_re.sub(qfn, new)
        return new

    # pass 1: locate fn-call uses (positions in the original text)
    uses = []
    for seg_a, seg_b, kind in segments(text):
        if kind != "code":
            continue
        for m in qual_fn_re.finditer(text, seg_a, seg_b):
            uses.append((m.start(), fn2cls[m.group(1)]))
        for m in bare_fn_re.finditer(text, seg_a, seg_b):
            uses.append((m.start(), fn2cls[m.group(1)]))

    injections = {}
    if uses:
        # block analysis on the ORIGINAL blank text
        blocks = {}   # open brace pos -> set(cls)
        pairs = []
        stack = []
        ui = 0
        uses_sorted = sorted(uses)
        for x in range(len(blank)):
            while ui < len(uses_sorted) and uses_sorted[ui][0] < x:
                pos, cls = uses_sorted[ui]
                if not stack:
                    die("%s: dmg call at offset %d (line %d) is not inside "
                        "any block" % (path, pos,
                                       blank.count("\n", 0, pos) + 1))
                blocks.setdefault(stack[-1], set()).add(cls)
                ui += 1
            c = blank[x]
            if c == "{":
                stack.append(x)
            elif c == "}":
                pairs.append((stack.pop(), x))
        while ui < len(uses_sorted):
            pos, cls = uses_sorted[ui]
            if not stack:
                die("%s: dmg call at line %d not inside any block"
                    % (path, blank.count("\n", 0, pos) + 1))
            blocks.setdefault(stack[-1], set()).add(cls)
            ui += 1
        close_of = dict(pairs)
        for open_pos, clss in sorted(blocks.items()):
            close = close_of.get(open_pos)
            region = blank[open_pos: close if close else len(blank)]
            nl = blank.find("\n", open_pos)
            indent = ""
            if nl >= 0:
                indent = re.match(r"[ \t]*", blank[nl + 1:]).group(0)
            ins_lines = []
            for cls in sorted(clss):
                if re.search(r"\b%s\b\s+[A-Za-z_]\w*\s*;" % cls,
                             region):
                    continue  # already injected on a previous run
                ins_lines.append("%s %s;" % (cls, get_inst(inst, cls,
                                                           stripped)))
            if ins_lines:
                injections[open_pos + 1] = ("\n" + indent +
                                            ("\n" + indent).join(ins_lines))
    # pass 2: rebuild, splitting code segments at injection points
    out = []
    for seg_a, seg_b, kind in segments(text):
        if kind != "code":
            out.append(text[seg_a:seg_b])
            continue
        pts = sorted(p for p in injections if seg_a < p <= seg_b)
        prev = seg_a
        for p in pts:
            out.append(rw(text[prev:p]))
            out.append(injections[p])
            prev = p
        out.append(rw(text[prev:seg_b]))
    new_text = "".join(out)
    return new_text, 1 if new_text != text else 0

def get_inst(inst, cls, stripped):
    if cls in inst:
        return inst[cls]
    nm = inst_name(cls)
    if re.search(r"\b%s\b" % nm, stripped):
        nm = "inst_" + nm
    inst[cls] = nm
    return nm


# ---------------------------------------------------------------- preflight


def patch_preflight(root, cpp_files):
    p = os.path.join(root, "tools", "preflight.sh")
    if not os.path.isfile(p):
        die("preflight.sh missing")
    text = open(p, encoding="utf-8").read()
    if cpp_files[0] in text:
        return False
    m = re.search(r"( *)spelleffects/spelleffects\.cpp regtest\.cpp \\\n",
                  text)
    if not m:
        die("battery build line not found in preflight.sh")
    indent = m.group(1)
    lines = []
    chunk = 5
    for i in range(0, len(cpp_files), chunk):
        lines.append(indent + "  " +
                     " ".join(cpp_files[i:i + chunk]) + " \\")
    repl = (indent + "spelleffects/spelleffects.cpp \\\n" +
            "\n".join(lines) + "\n" +
            indent + "regtest.cpp \\\n")
    text = text[: m.start()] + repl + text[m.end():]
    open(p, "w", encoding="utf-8").write(text)
    return True


# ---------------------------------------------------------------- main


def main():
    root = repo_root()
    dmg_dir = os.path.join(root, "rules", "dmg")
    headers = sorted(f for f in os.listdir(dmg_dir) if f.endswith(".h"))
    if not headers:
        die("no headers in rules/dmg")
    recs, fn2owner, type_names, enumerators = build_inventory(root, headers)
    efn, etype, eenum = build_engine_inventory(root)
    fn2cls = {fn: camel(stem) for fn, stem in fn2owner.items()}
    sym2stem = dict(type_names)
    sym2stem.update(enumerators)
    syms = set(type_names) | set(enumerators)

    global fn_names_of
    fn_names_of = {}
    for fn, stem in fn2owner.items():
        fn_names_of.setdefault(stem, []).append(fn)
    for stem in fn_names_of:
        fn_names_of[stem] = sorted(fn_names_of[stem])

    applied = 0
    already = 0
    for fname in headers:
        stem = fname[:-2]
        parsed = recs[stem]
        if parsed is None:
            already += 1
            continue
        if generate(root, stem, parsed, fn2owner, sym2stem,
                     efn, etype, eenum):
            applied += 1
    callers, edits = rewrite_callers(root, fn2cls, syms)
    cpp_files = ["rules/dmg/%s.cpp" % f[:-2] for f in headers]
    pre = patch_preflight(root, cpp_files)
    print("dmg class refactor: headers applied %d, already %d; "
          "caller files rewritten %d; preflight %s"
          % (applied, already, callers,
             "patched" if pre else "already patched"))
    if applied == 0 and callers == 0 and not pre:
        print("nothing to do - already converted")


if __name__ == "__main__":
    main()
