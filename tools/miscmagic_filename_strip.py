#!/usr/bin/env python3
"""miscmagic_filename_strip.py - strip the miscmagic_ filename stutter.

Inside rules/dmg/misc_magic/ the miscmagic_ prefix is redundant:
miscmagic_crystal_balls.h/.cpp -> crystal_balls.h/.cpp, and the 5
table*_footnotes pairs likewise (56 files total). Rewrites the
self-identifying path lines inside each file, the regtest.cpp
includes, and the tools/preflight.sh build entries. Class and
instance names are NOT touched (only filenames).

Idempotent: second run reports applied 0. Dies loudly
(STRIP RED:). Pure stdlib.
"""
import os
import re
import sys

DIR = 'rules/dmg/misc_magic'
OLD_PATH = 'rules/dmg/misc_magic/miscmagic_'
NEW_PATH = 'rules/dmg/misc_magic/'
CLS = re.compile(r'^class (\w+) \{$', re.M)
DECL = re.compile(r'^    \w+ (\w+)\(.*\);$', re.M)

applied = []


def die(msg):
    print('STRIP RED: ' + msg)
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


def check_pair(stem):
    h = open(os.path.join(DIR, stem + '.h')).read()
    c = open(os.path.join(DIR, stem + '.cpp')).read()
    m = CLS.search(h)
    if not m:
        die('no class decl in %s.h' % stem)
    cls = m.group(1)
    decls = DECL.findall(h)
    defs = re.findall(r'\b' + cls + r'::(\w+)\(', c)
    if sorted(decls) != sorted(defs):
        die('decl/def mismatch in %s: %d vs %d'
            % (stem, len(decls), len(defs)))
    for t in (h, c):
        if t.count('{') != t.count('}'):
            die('brace imbalance in ' + stem)


def stale_scan():
    for root, _, fs in os.walk('.'):
        if '.git' in root:
            continue
        for f in fs:
            if not f.endswith(('.h', '.cpp', '.sh')):
                continue
            t = open(os.path.join(root, f)).read()
            if 'misc_magic/miscmagic_' in t:
                die('stale stuttered path in ' + f)


def stripped_names():
    names = {}
    for f in sorted(os.listdir(DIR)):
        if f.startswith('miscmagic_'):
            names[f[len('miscmagic_'):]] = f
    return names


def main():
    names = stripped_names()
    stripped = [n for n in names]

    if not names:
        # candidate idempotent re-run: verify
        files = sorted(os.listdir(DIR))
        if len(files) != 56 or any(f.startswith('miscmagic_') for f in files):
            die('no stuttered files but %d files in %s (expected 56)'
                % (len(files), DIR))
        for f in files:
            if f.endswith('.h'):
                check_pair(f[:-2])
        reg = open('regtest.cpp').read()
        pre = open('tools/preflight.sh').read()
        if 'misc_magic/miscmagic_' in reg or 'misc_magic/miscmagic_' in pre:
            die('stale stuttered path in callers')
        stale_scan()
        print('applied 0, already stripped (56 files in %s)' % DIR)
        return

    if len(names) != 56:
        die('expected 56 stuttered files in %s, found %d' % (DIR, len(names)))

    for new, old in sorted(names.items()):
        src = os.path.join(DIR, old)
        t = open(src).read()
        n_before = t.count(OLD_PATH)
        if n_before == 0 or n_before > 2:
            die('self-path refs in %s: %d (expected 1-2)'
                % (old, n_before))
        t = t.replace(OLD_PATH, NEW_PATH)
        write(os.path.join(DIR, new), t)
        remove(src)

    p = 'regtest.cpp'
    t = open(p).read()
    n = t.count('"' + OLD_PATH)
    t = t.replace('"' + OLD_PATH, '"' + NEW_PATH)
    if n != 28:
        die('expected 28 regtest includes, found %d' % n)
    write(p, t)

    p = 'tools/preflight.sh'
    t = open(p).read()
    n = t.count(OLD_PATH)
    t = t.replace(OLD_PATH, NEW_PATH)
    if n != 28:
        die('expected 28 preflight entries, found %d' % n)
    write(p, t)

    # verify
    for new in sorted(names):
        if new.endswith('.h'):
            check_pair(new[:-2])
    files = sorted(os.listdir(DIR))
    if len(files) != 56 or any(f.startswith('miscmagic_') for f in files):
        die('post-strip directory census wrong: %d files' % len(files))
    stale_scan()

    print('applied %d changes:' % len(applied))
    for a in applied:
        print('  ' + a)
    print('stripped miscmagic_ from 56 filenames in %s' % DIR)


if __name__ == '__main__':
    main()
