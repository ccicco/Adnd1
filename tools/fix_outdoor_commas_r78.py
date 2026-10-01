#!/usr/bin/env python3
"""fix_table_commas_r78.py -- repair missing element separators in
dm/encounters.cpp aggregate tables. Bug class: flat rows whose comma was
transcribed into the trailing comment ('{...}   // text,' instead of
'{...},  // text'). Covers ALL row shapes (flat '}' and nested '}}').
Idempotent. Run from repo root."""
import re, sys

dry = '--dry' in sys.argv
path = 'dm/encounters.cpp'
for a in sys.argv[1:]:
    if not a.startswith('--'):
        path = a

lines = open(path, encoding='utf-8').read().split('\n')

def code_of(l):
    m = re.match(r'^(.*?)\s*(//.*)?$', l)
    return (m.group(1) or '').rstrip()

fixed = 0
for i in range(len(lines)):
    m = re.match(r'^(.*?)\s*(//.*)?$', lines[i])
    c = (m.group(1) or '').rstrip()
    if not c or c.endswith(','):
        continue
    if not re.search(r'\}+$', c):   # element row must end in brace(s)
        continue
    j = i + 1
    while j < len(lines) and not code_of(lines[j]).strip():
        j += 1
    nxt = code_of(lines[j]).lstrip() if j < len(lines) else ''
    if nxt.startswith('{'):
        lines[i] = c + ',' + ((' ' + m.group(2)) if m.group(2) else '')
        fixed += 1

print("commas added:", fixed)
if not dry:
    open(path, 'w', encoding='utf-8').write('\n'.join(lines))
