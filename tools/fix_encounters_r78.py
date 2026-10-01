#!/usr/bin/env python3
"""fix_encounters_r78.py -- one-shot repair for the R78b encounters.cpp
gate failures (14 clang errors). Three fix classes:
 (1) 40 table rows whose element comma was swallowed into the trailing
     comment ('{...}   // text,' -> code part has no comma);
 (2) PsychicWindEffect/PsychicWindResult/EtherCycloneEffect/
     EtherCycloneResult defined in BOTH encounters.h (canonical) and
     encounters.cpp (redefinition) -> delete the cpp copies;
 (3) PROF_MAGIC_USER -> PROF_MU (enum member is PROF_MU).
Idempotent; run from repo root; --dry reports without writing."""
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

# ---- (3) PROF rename ----
renamed = 0
for i, l in enumerate(lines):
    if 'PROF_MAGIC_USER' in l:
        lines[i] = l.replace('PROF_MAGIC_USER', 'PROF_MU')
        renamed += 1

# ---- (2) delete duplicate type definitions (cpp copies) ----
DUP_TYPES = ['enum class PsychicWindEffect', 'struct PsychicWindResult',
             'enum class EtherCycloneEffect', 'struct EtherCycloneResult']
removed_blocks = 0
for marker in DUP_TYPES:
    for i, l in enumerate(lines):
        if l.strip().startswith(marker):
            j = i
            while j < len(lines) and lines[j].strip() != '};':
                j += 1
            if j < len(lines):
                end = j + 1
                if end < len(lines) and lines[end].strip() == '' \
                        and (end+1 < len(lines) and lines[end+1].strip() == ''):
                    end += 1
                del lines[i:end]
                removed_blocks += 1
            break

# ---- (1) missing table commas ----
commas = 0
for i in range(len(lines)):
    m = re.match(r'^(.*?)\s*(//.*)?$', lines[i])
    c = (m.group(1) or '').rstrip()
    if not c or c.endswith(',') or not re.search(r'\}+$', c):
        continue
    j = i + 1
    while j < len(lines) and not code_of(lines[j]).strip():
        j += 1
    nxt = code_of(lines[j]).lstrip() if j < len(lines) else ''
    if nxt.startswith('{'):
        lines[i] = c + ',' + ((' ' + m.group(2)) if m.group(2) else '')
        commas += 1

print(f"commas added: {commas}, duplicate type blocks removed: {removed_blocks}, PROF renames: {renamed}")
if not dry:
    open(path, 'w', encoding='utf-8').write('\n'.join(lines))
