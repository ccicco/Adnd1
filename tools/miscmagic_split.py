#!/usr/bin/env python3
"""miscmagic_split.py - un-merge the miscmagic prose pair + relocate.

Undoes the R257-R279 merge: re-splits
rules/dmg/miscmagic_alchemy_jug_to_wings_of_flying.h/.cpp back into
the 23 part pairs and moves them, together with the 5 table*_footnotes
pairs, into rules/dmg/misc_magic/. Instance names stay short (miscmagic).
Includes, preflight build line, and audit decls are rewritten; comment
provenance is preserved verbatim (paths updated in self-identifying
banner lines).

Idempotent: second run reports applied 0. Dies loudly (SPLIT RED:).
Pure stdlib.
"""
import os
import re
import sys

DMG = 'rules/dmg'
DEST = 'rules/dmg/misc_magic'
AUDITS = 'rules/audits'
MERGED_STEM = 'miscmagic_alchemy_jug_to_wings_of_flying'
MERGED_CLS = 'Miscmagic_alchemy_jug_to_wings_of_flying'
INST = 'miscmagic'

applied = []


def die(msg):
    print('SPLIT RED: ' + msg)
    sys.exit(1)


def write(path, text):
    old = open(path).read() if os.path.exists(path) else None
    if old != text:
        open(path, 'w').write(text)
        applied.append(path)


def remove(path):
    if os.path.exists(path):
        os.remove(path)
        applied.append('-' + path)


def segments(text):
    out = []
    i, n, buf = 0, len(text), ''
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
            q, j = c, i + 1
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
    return ''.join(s if k == 'other' else fn(s) for k, s in segments(text))


MARK_H = re.compile(r'^    // ---- part (\d+) \(R(\d+)\): (\w+) ----$')
MARK_C = re.compile(r'^// ---- part (\d+) \(R(\d+)\): (\w+) ----$')
DECL = re.compile(r'^    \w+ \w+\(.*\);$')
AUDIT_NAME = re.compile(r'^r(\d+)_misc_magic_prose_part_(\d+)[_.]?\.h$')


def parse_header(h):
    """Return list of part dicts from the merged header."""
    parts = []
    cur = None
    in_body = False
    for ln in h.split('\n'):
        m = MARK_H.match(ln)
        if m:
            cur = dict(pnum=int(m.group(1)), rnum=int(m.group(2)),
                       stem=m.group(3), banner=[], decls=[])
            parts.append(cur)
            continue
        if cur is None:
            continue
        s = ln.strip()
        if s == '};':
            cur = None
            continue
        if s.startswith('//'):
            if cur['decls']:
                die('comment line after decls in part %d of merged header'
                    % cur['pnum'])
            cur['banner'].append(ln[4:] if ln.startswith('    //') else s)
        elif not s:
            continue
        elif DECL.match(ln):
            cur['decls'].append(ln)
        else:
            die('unparsed line in part %d of merged header: %r'
                % (cur['pnum'], ln))
    if len(parts) != 23:
        die('merged header has %d sections, expected 23' % len(parts))
    if [p['pnum'] for p in parts] != list(range(1, 24)):
        die('merged header sections not parts 1..23')
    if [p['rnum'] for p in parts] != list(range(257, 280)):
        die('merged header sections not R257..R279')
    for p in parts:
        if not p['banner'] or not p['decls']:
            die('empty banner or decls in part %d' % p['pnum'])
        if not p['banner'][0].startswith('// Adnd1 - rules/dmg/%s.h'
                                          % p['stem']):
            die('part %d banner self-path line unexpected: %r'
                % (p['pnum'], p['banner'][0]))
        cls = p['stem'][0].upper() + p['stem'][1:]
        for d in p['decls']:
            if not re.match(r'^    \w+ (\w+)\(.*\);$', d):
                die('bad decl %r in part %d' % (d, p['pnum']))
    return parts


def parse_cpp(c, parts):
    """Split the merged cpp bodies per part; return {stem: body}."""
    by_stem = {}
    cur_stem = None
    buf = []
    for ln in c.split('\n'):
        m = MARK_C.match(ln)
        if m:
            if cur_stem is not None:
                by_stem[cur_stem] = '\n'.join(buf).strip('\n')
            cur_stem = m.group(3)
            buf = []
            if int(m.group(1)) != next(p['pnum'] for p in parts
                                       if p['stem'] == cur_stem):
                die('cpp section part number mismatch for ' + cur_stem)
            continue
        if cur_stem is not None:
            buf.append(ln)
    if cur_stem is not None:
        by_stem[cur_stem] = '\n'.join(buf).strip('\n')
    if sorted(by_stem) != sorted(p['stem'] for p in parts):
        die('cpp sections do not match header sections')
    return by_stem


def emit_part(pt, body):
    stem = pt['stem']
    cls = stem[0].upper() + stem[1:]
    L = []
    L.append('// ====================================================================')
    L.append('// Adnd1 - %s/%s.h' % (DEST, stem))
    L.extend(pt['banner'][1:])
    L.append('// ---- re-split from %s.h (the R257-R279 merge) ----'
             % MERGED_STEM)
    L.append('// ====================================================================')
    L.append('#pragma once')
    L.append('')
    L.append('class %s {' % cls)
    L.append('public:')
    L.extend(pt['decls'])
    L.append('};')
    L.append('')
    write(os.path.join(DEST, stem + '.h'), '\n'.join(L))

    body = re.sub(r'\b' + MERGED_CLS + r'::', cls + '::', body)
    C = []
    C.append('// R-refactor: re-split from %s.cpp - definitions' % MERGED_STEM)
    C.append('#include "%s/%s.h"' % (DEST, stem))
    C.append('')
    C.append(body)
    C.append('')
    write(os.path.join(DEST, stem + '.cpp'), '\n'.join(C))


def move_footnotes():
    for n in range(1, 6):
        stem = 'miscmagic_table%d_footnotes' % n
        old = os.path.join(DMG, stem)
        for ext in ('.h', '.cpp'):
            src = old + ext
            if not os.path.exists(src):
                die('missing footnote file ' + src)
            t = open(src).read()
            t = t.replace('rules/dmg/%s' % stem,
                         '%s/%s' % (DEST, stem))
            write(os.path.join(DEST, stem + ext), t)
            remove(src)


def rewrite_regtest(parts):
    p = 'regtest.cpp'
    t = open(p).read()
    orig = t
    m = re.search(r'^#include "rules/dmg/%s\.h".*\n' % MERGED_STEM, t, re.M)
    if not m:
        die('missing merged include in regtest.cpp')
    lines = ['#include "%s/%s.h"  // R%d: the III.E misc magic explanation'
             ' prose part %d pins\n' % (DEST, pt['stem'], pt['rnum'],
                                        pt['pnum']) for pt in parts]
    t = t[:m.start()] + ''.join(lines) + t[m.end():]
    for n in range(1, 6):
        old_inc = '"rules/dmg/miscmagic_table%d_footnotes.h"' % n
        new_inc = '"%s/miscmagic_table%d_footnotes.h"' % (DEST, n)
        if old_inc not in t:
            die('missing footnote include %d in regtest.cpp' % n)
        t = t.replace(old_inc, new_inc)
    if t != orig:
        write(p, t)


def rewrite_preflight(parts):
    p = 'tools/preflight.sh'
    lines = open(p).read().split('\n')
    idxs = [i for i, ln in enumerate(lines)
            if 'rules/dmg/miscmagic_' in ln]
    if not idxs:
        die('no miscmagic entries in preflight build line')
    if idxs != list(range(idxs[0], idxs[0] + len(idxs))):
        die('preflight miscmagic region not contiguous')
    entries = []
    for ln in [lines[i] for i in idxs]:
        if not ln.rstrip().endswith('\\'):
            die('preflight region line missing backslash: ' + ln)
        toks = ln.split()
        if toks and toks[-1] == '\\':
            toks = toks[:-1]
        entries.extend(toks)
    drop = {'rules/dmg/%s.cpp' % MERGED_STEM}
    for n in range(1, 6):
        drop.add('rules/dmg/miscmagic_table%d_footnotes.cpp' % n)
    keep = [e for e in entries if e not in drop]
    for pt in parts:
        keep.append('%s/%s.cpp' % (DEST, pt['stem']))
    for n in range(1, 6):
        keep.append('%s/miscmagic_table%d_footnotes.cpp' % (DEST, n))
    keep = sorted(set(keep))
    newl = []
    for i in range(0, len(keep), 5):
        newl.append('    ' + ' '.join(keep[i:i + 5]) + ' \\')
    lines[idxs[0]:idxs[-1] + 1] = newl
    write(p, '\n'.join(lines))


def rewrite_audits(parts):
    by_part = {pt['pnum']: pt for pt in parts}
    for f in sorted(os.listdir(AUDITS)):
        m = AUDIT_NAME.match(f)
        if not m:
            continue
        pt = by_part.get(int(m.group(2)))
        if pt is None or pt['rnum'] != int(m.group(1)):
            die('audit %s does not map to a known part' % f)
        cls = pt['stem'][0].upper() + pt['stem'][1:]
        path = os.path.join(AUDITS, f)
        t = open(path).read()
        orig = t

        def fn(code):
            code = re.sub(r'\b' + MERGED_CLS + r'\b', cls, code)
            return code
        t = rewrite_code(t, fn)
        if t != orig:
            write(path, t)


def stale_scan():
    for root, _, fs in os.walk('.'):
        if '.git' in root:
            continue
        for f in fs:
            if not f.endswith(('.h', '.cpp', '.sh')):
                continue
            t = open(os.path.join(root, f)).read()
            if re.search(r'\b' + MERGED_CLS + r'\b', t):
                die('stale merged class ref in ' + f)
            if 'rules/dmg/miscmagic_' in t and 'rules/dmg/misc_magic/' not in t:
                die('stale old-path ref in ' + f)


def verify(parts):
    stale_scan()
    for pt in parts:
        cls = pt['stem'][0].upper() + pt['stem'][1:]
        h = open(os.path.join(DEST, pt['stem'] + '.h')).read()
        c = open(os.path.join(DEST, pt['stem'] + '.cpp')).read()
        decls = re.findall(r'^    \w+ (\w+)\(.*\);$', h, re.M)
        defs = re.findall(r'\b' + cls + r'::(\w+)\(', c)
        if sorted(decls) != sorted(defs):
            die('part %d decl/def mismatch: %d vs %d'
                % (pt['pnum'], len(decls), len(defs)))
        for t in (h, c):
            if t.count('{') != t.count('}'):
                die('brace imbalance in part %d' % pt['pnum'])


def main():
    merged_h = os.path.join(DMG, MERGED_STEM + '.h')
    merged_c = os.path.join(DMG, MERGED_STEM + '.cpp')
    part1_new = os.path.join(DEST, 'miscmagic_alchemy_jug_to_bag_of_devouring.h')

    if os.path.exists(part1_new) and not os.path.exists(merged_h):
        # idempotent re-run: verify clean state
        h = open(part1_new).read()
        MARK = re.compile(r'^// R(\d+): the III.E misc magic explanation'
                          r' prose part (\d+)$', re.M)
        found = MARK.findall(h)
        if not found:
            die('idempotent run: part1 header banner unreadable')
        for f in sorted(os.listdir(DEST)):
            if not f.endswith('.h'):
                continue
            t = open(os.path.join(DEST, f)).read()
            m = re.search(r'// R(\d+): the III.E misc magic explanation'
                          r' prose part (\d+)', t)
            if m:
                pt = dict(pnum=int(m.group(2)), rnum=int(m.group(1)),
                          stem=f[:-2], banner=[], decls=[])
                cls = pt['stem'][0].upper() + pt['stem'][1:]
                c = open(os.path.join(DEST, pt['stem'] + '.cpp')).read()
                decls = re.findall(r'^    \w+ (\w+)\(.*\);$', t, re.M)
                defs = re.findall(r'\b' + cls + r'::(\w+)\(', c)
                if sorted(decls) != sorted(defs):
                    die('idempotent run: decl/def mismatch in ' + f)
        reg = open('regtest.cpp').read()
        pre = open('tools/preflight.sh').read()
        if ('rules/dmg/%s.h' % MERGED_STEM) in reg:
            die('idempotent run: merged include still in regtest')
        if ('rules/dmg/%s.cpp' % MERGED_STEM) in pre:
            die('idempotent run: merged entry still in preflight')
        stale_scan()
        print('applied 0, already split (23 parts + 5 footnotes in %s)' % DEST)
        return

    if not os.path.exists(merged_h) or not os.path.exists(merged_c):
        die('merged pair not found at %s (and %s not populated)'
            % (merged_h, DEST))
    h = open(merged_h).read()
    c = open(merged_c).read()
    parts = parse_header(h)
    bodies = parse_cpp(c, parts)
    if not os.path.isdir(DEST):
        os.makedirs(DEST)
        applied.append('+' + DEST)

    for pt in parts:
        emit_part(pt, bodies[pt['stem']])
    remove(merged_h)
    remove(merged_c)
    move_footnotes()
    rewrite_regtest(parts)
    rewrite_preflight(parts)
    rewrite_audits(parts)
    verify(parts)

    print('applied %d changes:' % len(applied))
    for a in applied:
        print('  ' + a)
    print('re-split 23 parts, relocated 5 footnote pairs into %s' % DEST)


if __name__ == '__main__':
    main()
