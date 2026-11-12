#!/usr/bin/env python3
# dmg method names - pass 1: strip the redundant class-stem stutter
# (poison.poisonCostPerDose -> poison.costPerDose). Pure stdlib,
# idempotent, dies loudly on anything unexpected.
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


def segments(text):
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
    buf = list(text)
    for a, b, k in segments(text):
        if k != "code":
            for x in range(a, b):
                buf[x] = " "
    return "".join(buf)


def rewrite_code(text, sub):
    """Apply sub(segment_text) to code segments only (comments and
    strings are left untouched)."""
    out = []
    for a, b, k in segments(text):
        if k == "code":
            out.append(sub(text[a:b]))
        else:
            out.append(text[a:b])
    return "".join(out)


def build_strip_map(root):
    """(file, cls, old, new) for every stutter-prefixed method."""
    strips = []
    methods_by_cls = {}
    for fname in sorted(os.listdir(os.path.join(root, "rules", "dmg"))):
        if not fname.endswith(".h"):
            continue
        stem = fname[:-2]
        path = os.path.join(root, "rules", "dmg", fname)
        h = open(path, encoding="utf-8").read()
        m = re.search(r"class (\w+) \{\npublic:\n(.*?)\n\};", h, re.S)
        if not m:
            die("%s: no class decl block found" % fname)
        cls, body = m.group(1), m.group(2)
        decls = re.findall(r"^\s+.*?\b(\w+)\s*\([^()]*\)\s*;$",
                           body, re.M)
        if not decls:
            die("%s: no method declarations parsed" % fname)
        methods_by_cls[cls] = decls
        for n in decls:
            if (n.startswith(stem) and len(n) > len(stem)
                    and (n[len(stem)].isupper() or n[len(stem)].isdigit())):
                rest = n[len(stem):]
                if len(rest) >= 2 and rest[1].islower():
                    rest = rest[0].lower() + rest[1:]
                if not rest[0].isalpha():
                    continue  # e.g. next char a digit: keep as-is
                strips.append((fname, cls, n, rest))
    return strips, methods_by_cls


def check(root, strips, methods_by_cls):
    """Die loudly on any ambiguity before touching anything."""
    by_cls = {}
    for fname, cls, old, new in strips:
        others = methods_by_cls[cls]
        if new in others and new != old:
            die("strip collision in %s: %s would shadow existing "
                "method %s" % (cls, old, new))
        by_cls.setdefault(old, set()).add(cls)
    for old, clss in by_cls.items():
        if len(clss) > 1:
            die("method name %s declared in %s - rewrite would be "
                "ambiguous" % (old, sorted(clss)))
    # engine symbols: a stripped name that equals a rules:: symbol
    # would silently shadow it inside method bodies
    efn, etype, eenum = engine_inventory(root)
    for fname, cls, old, new in strips:
        if new in efn or new in etype or new in eenum:
            die("%s: %s would collide with engine symbol %s"
                % (fname, old, new))
    return True


def engine_inventory(root):
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
                r"^inline\s[^;(){}]*?\b([A-Za-z_]\w*)\s*\(", code, re.M))
            etype.update(re.findall(
                r"\b(?:class|struct|enum)\s+([A-Za-z_]\w*)", code))
            for m in re.finditer(r"\benum\s+[A-Za-z_]\w*\s*\{(.*?)\}",
                                 code, re.S):
                for part in m.group(1).split(","):
                    ident = re.match(r"\s*([A-Za-z_]\w*)", part)
                    if ident:
                        eenum.add(ident.group(1))
    return efn, etype, eenum


def rewrite_all(root, strips):
    old2new = {old: new for _, _, old, new in strips}
    if not old2new:
        return 0
    longest = sorted(old2new, key=len, reverse=True)
    member_re = re.compile(
        r"([.>])(%s)\s*\(" % "|".join(longest))
    any_re = re.compile(r"(?<![\w.:])(%s)\s*\(" % "|".join(longest))
    def_re = re.compile(r"(?<![\w.])(\w+)::(%s)\s*\(" % "|".join(longest))
    changed = 0
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d != ".git"]
        inside_dmg = os.path.join(dirpath, "rules", "dmg") == os.path.join(
            root, "rules", "dmg")
        for fn in filenames:
            if not (fn.endswith(".h") or fn.endswith(".cpp")):
                continue
            path = os.path.join(dirpath, fn)
            text = open(path, encoding="utf-8").read()
            is_dmg = os.path.dirname(path) == os.path.join(
                root, "rules", "dmg")

            def sub(seg):
                if is_dmg:
                    # decls, bare same-file calls, and Cls:: defs
                    seg = def_re.sub(
                        lambda m: "%s::%s(" % (m.group(1),
                                               old2new[m.group(2)]),
                        seg)
                    return any_re.sub(
                        lambda m: old2new[m.group(1)] + "(", seg)
                return member_re.sub(
                    lambda m: m.group(1) + old2new[m.group(2)] + "(",
                    seg)

            new_text = rewrite_code(text, sub)
            if new_text != text:
                open(path, "w", encoding="utf-8").write(new_text)
                changed += 1
    return changed


def add_pragma(root):
    p = os.path.join(root, "rules", "dmg", "set_spear.h")
    if not os.path.isfile(p):
        die("set_spear.h missing")
    text = open(p, encoding="utf-8").read()
    if "#pragma once" in text:
        return False
    m = re.match(r"((?://[^\n]*\n)+)", text)
    if not m:
        die("set_spear.h: no banner comment to anchor #pragma once")
    text = text[:m.end()] + "#pragma once\n" + text[m.end():]
    open(p, "w", encoding="utf-8").write(text)
    return True


def main():
    root = repo_root()
    strips, methods_by_cls = build_strip_map(root)
    if strips:
        check(root, strips, methods_by_cls)
    changed = rewrite_all(root, strips)
    pragma = add_pragma(root)
    print("dmg method names: %d stutter-prefixed methods stripped "
          "(%d files); callers+defs files rewritten %d; set_spear "
          "pragma %s"
          % (len(strips), len(set(s[0] for s in strips)), changed,
             "added" if pragma else "already present"))
    if not strips and not changed and not pragma:
        print("nothing to do - already stripped")


if __name__ == "__main__":
    main()
