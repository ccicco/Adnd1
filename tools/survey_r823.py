#!/usr/bin/env python3
# tools/survey_r823.py - the audit-region survey for the regtest
# decomposition migration (the R822 wiring's first cousin).
# READS regtest.cpp at the working tree; NEVER writes regtest.cpp.
# Writes tools/audit_migration_survey.md and prints it whole.
# No network, no git. The migration rounds are authored FROM this
# digest; nothing in it changes the tree.
import io
import os
import re
import sys

RT = 'regtest.cpp'
OUT = 'tools/audit_migration_survey.md'
MAXDUMP = 300   # cap lines per dumped segment

s = io.open(RT, 'r', encoding='utf-8', errors='replace').read()
lines = s.split('\n')
N = len(lines)
out = []


def emit(x):
    out.append(x)


# ---- 1. file facts ----
census = s.count('audit: bad')
census_sp = s.count('audit: bad ')
md5 = None
try:
    import hashlib
    md5 = hashlib.md5(s.encode('utf-8')).hexdigest()
except Exception:
    pass
emit('# The audit-region survey (R823 prep)')
emit('')
emit('## File facts')
emit('')
emit('- regtest.cpp md5: %s' % md5)
emit('- regtest.cpp bytes: %d, lines: %d' % (len(s.encode("utf-8")), N))
emit("- 'audit: bad' occurrences: %d (the census)" % census)
emit("- 'audit: bad ' (trailing space) occurrences: %d" % census_sp)
emit('- include lines: %d' % sum(
    1 for l in lines if l.startswith('#include "')))
inc_last = max(
    (i for i, l in enumerate(lines)
     if l.startswith('#include "')), default=-1)
emit('- last include line: %d: %s'
     % (inc_last + 1, lines[inc_last] if inc_last >= 0 else 'NONE'))

# ---- 2. the anchors ----
anchor = None
for i, l in enumerate(lines):
    if 'R227: the wis mental save' in l:
        anchor = i
        break
emit('- R227 anchor line: %d: %s'
     % (anchor + 1 if anchor is not None else 0,
        lines[anchor] if anchor is not None else 'MISSING'))
emit('')

# ---- 3. segmentation by head comments ----
# A head: a comment line like '    // ---- RNNN: ...' (any indent).
head_re = re.compile(r'^\s*//\s*-+\s*R\d+')
heads = [i for i, l in enumerate(lines) if head_re.match(l)]
printfs = [i for i, l in enumerate(lines) if 'audit: bad' in l]
emit('## Segmentation')
emit('')
emit('- head-comment lines matching "// ---- RNNN": %d' % len(heads))
emit('- printf lines carrying "audit: bad": %d' % len(printfs))
emit('')

# segment = [head_i, next head or anchor or first 'return 0;' or EOF)
def seg_end(h):
    nxt = [j for j in heads if j > h]
    bounds = nxt[:1]
    if anchor is not None and anchor > h:
        bounds.append(anchor)
    for j in range(h + 1, N):
        if lines[j] == '    return 0;':
            bounds.append(j)
            break
    bounds.append(N)
    return min(bounds)

segs = []
for h in heads:
    e = seg_end(h)
    pfs = [p for p in printfs if h < p < e]
    body = lines[h:e]
    # trim trailing blank lines from the segment body for delta stats
    while body and body[-1].strip() == '':
        body.pop()
    opens = sum(l.count('{') for l in body)
    closes = sum(l.count('}') for l in body)
    # a self-contained audit scope: brace delta 0, at least one {}
    segs.append(dict(head=h, end=e, pfs=pfs, body=body,
                     d=opens - closes,
                     has_ret0=any(
                         l.strip() == 'return 0;' for l in body[1:])))

head_with_pf = [g for g in segs if g['pfs']]
head_no_pf = [g for g in segs if not g['pfs']]
pf_no_head = [p for p in printfs
              if not any(g['head'] < p < g['end'] for g in segs)]
emit('## The audit blocks (head + printf), in file order')
emit('')
emit('- blocks (head + audit printf): %d' % len(head_with_pf))
emit('- heads WITHOUT an audit printf in segment: %d'
     % len(head_no_pf))
emit('- audit printfs NOT under any head: %d' % len(pf_no_head))
emit('- blocks with nonzero brace delta: %d'
     % sum(1 for g in head_with_pf if g['d'] != 0))
emit('- blocks containing a bare "return 0;": %d'
     % sum(1 for g in head_with_pf if g['has_ret0']))
emit('')

# ---- 4. the digest: one line per audit block ----
emit('## The digest (one line per audit block)')
emit('')
emit('idx | headln | endln | d | ret0 | label | head text')
aud = head_with_pf
for k, g in enumerate(aud):
    p = g['pfs'][0]
    l = lines[p]
    m = re.search(r'"([^"]*)"', l)
    lab = m.group(1) if m else l.strip()
    # keep the label short: up to ': bad'
    cut = lab.find(': bad')
    if cut > 0:
        lab = lab[:cut]
    emit('%d | %d | %d | %d | %s | %s | %s'
         % (k, g['head'] + 1, g['end'], g['d'],
            'Y' if g['has_ret0'] else '-',
            lab, lines[g['head']].strip()))
emit('')

# ---- 5. full text of sample blocks ----
emit('## Full text: the first 12 audit blocks, mid samples, last 3')
emit('')
pick = list(range(min(12, len(aud))))
for probe in (200, 350, 500, 650):
    if probe < len(aud):
        pick.append(probe)
pick += list(range(max(0, len(aud) - 3), len(aud)))
pick = sorted(set(pick))
for k in pick:
    g = aud[k]
    body = lines[g['head']:g['end']]
    # trim trailing blanks
    while body and body[-1].strip() == '':
        body.pop()
    emit('### block %d (head line %d, %d lines, delta %d)'
         % (k, g['head'] + 1, len(body), g['d']))
    emit('')
    if len(body) > MAXDUMP:
        emit(''.join(l + '\n' for l in body[:MAXDUMP]))
        emit('... (%d more lines, capped)' % (len(body) - MAXDUMP))
    else:
        emit(''.join(l + '\n' for l in body))
    emit('')

# ---- 6. the printfs with no head, if any ----
if pf_no_head:
    emit('## Printfs with no head above them')
    emit('')
    for p in pf_no_head:
        emit('line %d: %s' % (p + 1, lines[p].strip()))
        for j in range(max(0, p - 6), min(N, p + 3)):
            emit('  %6d| %s' % (j + 1, lines[j]))
        emit('')

# ---- 7. the tail of the file ----
emit('## The file tail (last 30 lines)')
emit('')
emit(''.join('%6d| %s\n' % (N - 30 + j + 1, lines[N - 30 + j])
            for j in range(30)))

# ---- write + print ----
txt = '\n'.join(out) + '\n'
io.open(OUT, 'w', encoding='utf-8').write(txt)
print(txt)
print('SURVEY OK: %d audit blocks, %d heads, %d printfs, '
      'census %d; wrote %s (%d bytes)'
      % (len(aud), len(heads), len(printfs), census, OUT,
         len(txt.encode('utf-8'))))
