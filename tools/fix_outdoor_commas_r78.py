#!/usr/bin/env python3
"""fix_outdoor_commas_r78.py -- add missing array-element separators in
dm/encounters.cpp outdoor tables (comma was swallowed into trailing
comments in the R63-R67 transcription: '}}   // text,' instead of
'}},   // text'). Idempotent; run from repo root."""
import re
import sys

dry = '--dry' in sys.argv
path = 'dm/encounters.cpp'
for a in sys.argv[1:]:
    if not a.startswith('--'):
        path = a

lines = open(path, encoding='utf-8').read().split('\n')

def code_of(l):
    return re.sub(r'//.*$', '', l)

fixed = 0
out = []
for i, l in enumerate(lines):
    nxt = lines[i + 1] if i + 1 < len(lines) else ''
    c = code_of(l).rstrip()
    n = code_of(nxt).lstrip()
    if re.search(r'\}\}$', c) and not re.search(r',$', c):
        if n.startswith('{"') or n.startswith('{ SUB') or n.startswith('{"SUB'):
            m = re.match(r'^(.*?\}\})(\s*)(//.*)?$', l)
            if m and not m.group(1).rstrip().endswith(','):
                l = m.group(1) + ',' + (m.group(2) or '') + (m.group(3) or '')
                fixed += 1
    out.append(l)

print("commas added:", fixed)
if not dry:
    open(path, 'w', encoding='utf-8').write('\n'.join(out))
