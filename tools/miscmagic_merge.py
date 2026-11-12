#!/usr/bin/env python3
"""miscmagic_merge.py - merge the 23 III.E explanation-prose part files.

rules/dmg/miscmagic_* (parts 1-23, R257-R279) become ONE pair:
  miscmagic_alchemy_jug_to_wings_of_flying.h/.cpp
class Miscmagic_alchemy_jug_to_wings_of_flying, instance miscmagic.
The 5 table_footnotes pairs are UNTOUCHED.

Idempotent: second run reports applied 0. Dies loudly on anomalies
(MERGE RED: prefix). Pure stdlib.
"""
import os
import re
import sys

DMG = 'rules/dmg'
AUDITS = 'rules/audits'
MERGED_STEM = 'miscmagic_alchemy_jug_to_wings_of_flying'
MERGED_CLS = 'Miscmagic_alchemy_jug_to_wings_of_flying'
INST = 'miscmagic'
FRAME = re.compile(r'^\s*//\s*=+\s*$')

applied = []


def die(msg):
    print('MERGE RED: ' + msg)
    sys.exit(1)


def write(path, text):
    old = None
    if os.path.exists(path):
        old = open(path).read()
    if old != text:
        open(path, 'w').write(text)
        applied.append(path)
        return True
    return False


def remove(path):
    if os.path.exists(path):
        os.remove(path)
        applied.append('-' + path)


def segments(text):
    """Split into ('code'|'other', str) - other = comment or string."""
    out = []
    i = 0
    n = len(text)
    buf = ''
    while i < n:
        c = text[i]
        if c == '/' and i + 1 < n and text[i + 1] == '/':
            j = text.find('\n', i)
            j = n if j < 0 else j
            if buf:
                out.append(('code', buf))
                buf = ''
            out.append(('other', text[i:j]))
            i = j
        elif c == '/' and i + 1 < n and text[i + 1] == '*':
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            if buf:
                out.append(('code', buf))
                buf = ''
            out.append(('other', text[i:j]))
            i = j
        elif c == '"' or c == "'":
            q = c
            j = i + 1
            while j < n:
                if text[j] == '\\':
                    j += 2
                    continue
                if text[j] == q:
                    j += 1
                    break
                j += 1
            buf += text[i:j]
            i = j
        else:
            buf += c
            i += 1
    if buf:
        out.append(('code', buf))
    return out


def rewrite_code(text, fn):
    return ''.join(t if k == 'other' else fn(t) for k, t in segments(text))


SECTION = re.compile(r'^\s*// ---- part (\d+) \(R(\d+)\): (\w+) ----$', re.M)


def load_parts():
    parts = []
    for f in sorted(os.listdir(DMG)):
        if not f.startswith('miscmagic_') or not f.endswith('.h'):
            continue
        if 'footnotes' in f or f == MERGED_STEM + '.h':
            continue
        h = open(os.path.join(DMG, f)).read()
        pm = re.search(r'R(\d+): the III.E misc magic explanation prose part (\d+)', h)
        if not pm:
            die('no part banner in ' + f)
        parts.append((int(pm.group(2)), int(pm.group(1)), f[:-2], h))
    parts.sort()
    if [p[0] for p in parts] != list(range(1, 24)):
        die('part numbers are not 1..23: %r' % [p[0] for p in parts])
    if [p[1] for p in parts] != list(range(257, 280)):
        die('R numbers are not 257..279')
    return parts


def merged_stems(h):
    """Reconstruct (pnum, rnum, stem) from the merged header sections."""
    out = []
    for m in SECTION.finditer(h):
        out.append((int(m.group(1)), int(m.group(2)), m.group(3)))
    if [p[0] for p in out] != list(range(1, 24)):
        die('merged header sections not parts 1..23')
    if [p[1] for p in out] != list(range(257, 280)):
        die('merged header sections not R257..279')
    return out


def parse_part(pnum, rnum, stem, h):
    m = re.search(r'class (\w+) \{', h)
    if not m:
        die('no class in ' + stem + '.h')
    cls = m.group(1)
    if cls != stem[0].upper() + stem[1:]:
        die('class name mismatch in ' + stem + '.h: ' + cls)
    prefix = h[:m.start()]
    if '#pragma once' not in prefix:
        die('missing pragma in ' + stem + '.h')
    # banner = comment lines before pragma, minus === frames
    banner = []
    for line in prefix.split('\n'):
        if line.strip() == '#pragma once':
            break
        if FRAME.match(line):
            continue
        banner.append(line)
    while banner and not banner[-1].strip():
        banner.pop()
    while banner and not banner[0].strip():
        banner.pop(0)
    # decls = class body after public:
    body = h[m.end():h.rindex('};')]
    lines = body.split('\n')
    while lines and not lines[0].strip():
        lines.pop(0)
    if not lines or lines[0].strip() != 'public:':
        die('expected public: first in ' + stem + '.h')
    lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()
    decls = list(lines)
    names = []
    for ln in decls:
        mm = re.match(r'\s*\w+\s+(\w+)\(.*\);\s*$', ln)
        if not mm:
            die('unparsed decl line in %s.h: %r' % (stem, ln))
        names.append(mm.group(1))
    # cpp body
    cpp_path = os.path.join(DMG, stem + '.cpp')
    if not os.path.exists(cpp_path):
        die('missing ' + cpp_path)
    c = open(cpp_path).read()
    inc = '#include "rules/dmg/%s.h"' % stem
    k = c.find(inc)
    if k < 0:
        die('missing self include in ' + stem + '.cpp')
    k = c.index('\n', k) + 1
    cbody = c[k:]
    if pt_defs(cbody, cls) == 0:
        die('no method definitions found in ' + stem + '.cpp')
    return dict(pnum=pnum, rnum=rnum, stem=stem, cls=cls,
                banner=banner, decls=decls, names=names, cbody=cbody)


def pt_defs(cbody, cls):
    return len(re.findall(r'\b' + cls + r'::', cbody))


def merged_header(parts):
    L = []
    L.append('// ====================================================================')
    L.append('// Adnd1 - rules/dmg/%s.h' % MERGED_STEM)
    L.append('// R257-R279: the III.E misc magic explanation prose parts 1-23')
    L.append('// pins - merged from the 23 explanation-prose part files')
    L.append("// (R257 alchemy jug ... R279 wings of flying). Each part's")
    L.append('// original banner is preserved below as its section comment.')
    L.append('// Upload-seam provenance (parts 1-2): part1 ended mid-sentence')
    L.append('// at line 11065; part2 line 3 completed it; global line =')
    L.append('// part1 line or 11065 + part2 line.')
    L.append('// ====================================================================')
    L.append('#pragma once')
    L.append('')
    L.append('class %s {' % MERGED_CLS)
    L.append('public:')
    for pt in parts:
        L.append('')
        L.append('    // ---- part %d (R%d): %s ----' % (pt['pnum'], pt['rnum'], pt['stem']))
        for b in pt['banner']:
            L.append('    ' + b if b.strip() else '')
        for d in pt['decls']:
            L.append(d)
    L.append('};')
    L.append('')
    return '\n'.join(L)


def merged_cpp(parts):
    L = []
    L.append('// R257-R279: the III.E misc magic explanation prose parts 1-23 -')
    L.append("// merged from the 23 part files; each part's bodies verbatim.")
    L.append('#include "rules/dmg/%s.h"' % MERGED_STEM)
    for pt in parts:
        L.append('')
        L.append('// ---- part %d (R%d): %s ----' % (pt['pnum'], pt['rnum'], pt['stem']))
        body = pt['cbody']
        body = re.sub(r'\b' + pt['cls'] + r'::', MERGED_CLS + '::', body)
        L.append(body.rstrip('\n'))
    L.append('')
    return '\n'.join(L)




def check_class_body(h):
    body = h[h.index('public:') + len('public:'):h.rindex('};')]
    for ln in body.split('\n'):
        s = ln.strip()
        if not s or s.startswith('//'):
            continue
        if not re.match(r'\w+\s+\w+\(.*\);$', s):
            die('non-decl line inside class body: %r' % s)



def rewrite_audit(path, parts):
    if not os.path.exists(path):
        die('missing audit ' + path)
    t = open(path).read()
    orig = t
    pt_by_cls = {pt['cls']: pt for pt in parts}
    used = [c for c in pt_by_cls if re.search(r'\b' + c + r'\b', t)]
    if not used:
        return  # untouched audit
    def fn(code):
        for c in used:
            code = re.sub(r'\b' + c + r'\b', MERGED_CLS, code)
            code = re.sub(r'\b' + pt_by_cls[c]['stem'] + r'\b', INST, code)
        return code
    t = rewrite_code(t, fn)
    # bare-name collision guard
    for k, seg in segments(t):
        if k == 'code':
            stripped = re.sub(r'\b' + INST + r'\b', ' ', seg)
            if re.search(r'\bmiscmagic\b', stripped):
                die('bare identifier miscmagic already in use in ' + path)
            break
    # dedupe merged decl lines within the block
    decl_re = re.compile(r'^(\s*)' + MERGED_CLS + r' ' + INST + r';\s*$')
    lines = t.split('\n')
    seen = 0
    outl = []
    for ln in lines:
        if decl_re.match(ln):
            seen += 1
            if seen > 1:
                continue
        outl.append(ln)
    t = '\n'.join(outl)
    if t != orig:
        write(path, t)


def rewrite_regtest(parts):
    p = 'regtest.cpp'
    t = open(p).read()
    orig = t
    first_pos = None
    for pt in parts:
        m = re.search(r'^#include "rules/dmg/%s\.h".*\n' % pt['stem'], t, re.M)
        if not m:
            die('missing include for ' + pt['stem'] + ' in regtest.cpp')
        if first_pos is None:
            first_pos = m.start()
        t = t[:m.start()] + t[m.end():]
    newline = ('#include "rules/dmg/%s.h"  // R257-R279: the III.E misc magic'
               ' explanation prose parts 1-23 pins\n') % MERGED_STEM
    t = t[:first_pos] + newline + t[first_pos:]
    if t != orig:
        write(p, t)


def rewrite_preflight(parts):
    p = 'tools/preflight.sh'
    lines = open(p).read().split('\n')
    idxs = [i for i, ln in enumerate(lines)
            if any('rules/dmg/%s.cpp' % pt['stem'] in ln for pt in parts)]
    if not idxs:
        return  # already patched (idempotent path)
    if idxs != list(range(idxs[0], idxs[0] + len(idxs))):
        die('preflight build-line region not contiguous')
    region = [lines[i] for i in idxs]
    entries = []
    for ln in region:
        if not ln.rstrip().endswith('\\'):
            die('preflight region line does not end with backslash: ' + ln)
        toks = ln.split()
        if toks and toks[-1] == '\\':
            toks = toks[:-1]
        entries.extend(toks)
    drop = {'rules/dmg/%s.cpp' % pt['stem'] for pt in parts}
    keep, insert_at = [], None
    for e in entries:
        if e in drop:
            if insert_at is None:
                insert_at = len(keep)
            continue
        keep.append(e)
    if insert_at is None:
        die('preflight: no part entries found to anchor insertion')
    keep.insert(insert_at, 'rules/dmg/%s.cpp' % MERGED_STEM)
    newl = []
    for i in range(0, len(keep), 5):
        newl.append('    ' + ' '.join(keep[i:i + 5]) + ' \\')
    lines[idxs[0]:idxs[-1] + 1] = newl
    t = '\n'.join(lines)
    if 'rules/dmg/%s.cpp' % MERGED_STEM not in t:
        die('preflight patch failed')
    write(p, t)


def main():
    merged_h = os.path.join(DMG, MERGED_STEM + '.h')
    merged_c = os.path.join(DMG, MERGED_STEM + '.cpp')
    mexists = os.path.exists(merged_h)

    if mexists and not os.path.exists(os.path.join(
            DMG, 'miscmagic_alchemy_jug_to_bag_of_devouring.h')):
        # idempotent re-run: verify clean state
        h = open(merged_h).read()
        stems = merged_stems(h)
        decls = re.findall(r'^\s*\w+\s+(\w+)\(.*\);\s*$', h, re.M)
        c = open(merged_c).read() if os.path.exists(merged_c) else ''
        defs = re.findall(r'\b' + MERGED_CLS + r'::(\w+)\(', c)
        if sorted(decls) != sorted(defs):
            die('merged decl/def mismatch on idempotent run')
        if len(decls) == 0:
            die('idempotent run found no decls in merged header')
        check_class_body(h)
        reg = open('regtest.cpp').read()
        pre = open('tools/preflight.sh').read()
        for _, _, stem in stems:
            if ('#include "rules/dmg/%s.h"' % stem) in reg:
                die('stale include remains: ' + stem)
            if ('rules/dmg/%s.cpp' % stem) in pre:
                die('stale preflight entry remains: ' + stem)
        print('applied 0, already merged (23 parts -> %s)' % MERGED_STEM)
        return

    parts = load_parts()
    old_h = [os.path.join(DMG, pt[2] + '.h') for pt in parts]
    oexists = sum(1 for f in old_h if os.path.exists(f))
    if oexists != 23:
        die('expected 23 part headers, found %d (merged exists: %s)'
            % (oexists, mexists))
    if mexists:
        die('merged header exists alongside part headers - inconsistent state')

    pts = [parse_part(*pt) for pt in parts]
    # collision checks
    allnames = {}
    for pt in pts:
        for nm in pt['names']:
            if nm in allnames:
                die('method name collision %s: %s vs %s'
                    % (nm, allnames[nm], pt['stem']))
            allnames[nm] = pt['stem']

    # snapshot footnote files (must stay untouched)
    snaps = {}
    for f in sorted(os.listdir(DMG)):
        if 'footnotes' in f:
            snaps[os.path.join(DMG, f)] = open(os.path.join(DMG, f)).read()

    write(merged_h, merged_header(pts))
    write(merged_c, merged_cpp(pts))

    for pt in pts:
        remove(os.path.join(DMG, pt['stem'] + '.h'))
        remove(os.path.join(DMG, pt['stem'] + '.cpp'))

    for f in sorted(os.listdir(AUDITS)):
        rewrite_audit(os.path.join(AUDITS, f), pts)
    rewrite_regtest(pts)
    rewrite_preflight(pts)

    # verify
    h = open(merged_h).read()
    c = open(merged_c).read()
    decls = re.findall(r'^\s*\w+\s+(\w+)\(.*\);\s*$', h, re.M)
    defs = re.findall(r'\b' + MERGED_CLS + r'::(\w+)\(', c)
    if sorted(decls) != sorted(defs):
        die('decl/def mismatch: %d decls vs %d defs' % (len(decls), len(defs)))
    if h.count('{') != h.count('}'):
        die('header brace imbalance')
    check_class_body(h)
    if c.count('{') != c.count('}'):
        die('cpp brace imbalance')
    for f, snap in snaps.items():
        if open(f).read() != snap:
            die('footnote file modified: ' + f)
    # no stale class refs anywhere in code
    for root, _, fs in os.walk('.'):
        if '.git' in root or root.startswith('./tools'):
            continue
        for f in fs:
            if not f.endswith(('.h', '.cpp')):
                continue
            t = open(os.path.join(root, f)).read()
            for pt in pts:
                if re.search(r'\b' + pt['cls'] + r'\b', t):
                    die('stale class ref %s in %s' % (pt['cls'], f))
    print('applied %d changes:' % len(applied))
    for a in applied:
        print('  ' + a)
    print('merged %d parts, %d methods' % (len(pts), len(decls)))


if __name__ == '__main__':
    main()
