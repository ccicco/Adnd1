#!/usr/bin/env python3
# R392b: the players tables repair - the follow-up
# fix splice for the RED R392 commit (6cfd9c2).
#
# The R392 body shipped four C defects the Python
# audit simulation pass could not see (it models the
# accessors' return VALUES, not the emitted C text):
#
# 1. rules/uaequip26.h lost the leading slash of its
#    "// ===" opener (a [1:-1] strip on a literal
#    with no leading newline) - the file started
#    "/ ===", a syntax error at line 1.
# 2. rules/uahandheld.h shipped the dagger length
#    c. 15" (fifteen INCHES, double-prime, per the
#    clean print) unescaped - the cell read
#    "c. 15"" and left an unbalanced quote.
# 3. rules/uaweapontable.h: the uawtName replacement
#    flipped the return type (const char* -> int) -
#    every strcmp(uawtName(...)) call in the audit
#    failed to compile.
# 4. rules/uaweapontable.h: the uawtIsNewWeapon
#    replacement flipped bool -> int - this one
#    compiles silently; only a signature-vs-array
#    check caught it.
#
# This splice amends the four sites in place,
# idempotently. The census stays 319 (no new audit:
# the R392 audit block itself only compiles when the
# types are right - the build is the test). No seed
# record (a repair, not a round; R393 writes the R392
# record, which will name the R392b fix - the R391 /
# R391b precedent).
import io

NL = '\n'

HDRS = ('rules/uaequip26.h', 'rules/uahandheld.h',
        'rules/uaweapontable.h', 'rules/uamissile.h',
        'rules/uaprof.h')

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def abort(label, detail):
    print('R392b ABORT: %s' % label)
    print('  %r' % (detail[:80],))
    raise SystemExit(1)


# ---- fix 1: the uaequip26.h opener slash ----
P = 'rules/uaequip26.h'
src = rd(P)
if src.startswith('// '):
    already.append('uaequip26.h: the opener slash')
elif src.startswith('/ ='):
    wr(P, '/' + src)
    applied.append('uaequip26.h: the opener slash')
else:
    abort('%s opener not recognised' % P, src[:60])

# ---- fix 2: the dagger inches escape ----
P = 'rules/uahandheld.h'
src = rd(P)
BAD = '"c. 15"", "8\' +",'
GOOD = '"c. 15\\"", "8\' +",'
if BAD in src:
    if src.count(BAD) != 1:
        abort('uahandheld.h dagger cells', BAD)
    wr(P, src.replace(BAD, GOOD))
    applied.append('uahandheld.h: the dagger inches')
elif GOOD in src:
    already.append('uahandheld.h: the dagger inches')
else:
    abort('the dagger length cell not found in %s' % P,
          'no c. 15 cell')

# ---- fixes 3+4: the flipped return types ----
P = 'rules/uaweapontable.h'
src = rd(P)
PAIRS = [
    ('inline int uawtName(int i) {',
     'inline const char* uawtName(int i) {',
     'uawtName: the return type'),
    ('inline int uawtIsNewWeapon(int i) {',
     'inline bool uawtIsNewWeapon(int i) {',
     'uawtIsNewWeapon: the return type'),
]
touched = False
for bad, good, label in PAIRS:
    if bad in src:
        if src.count(bad) != 1:
            abort('uaweapontable.h %s' % label, bad)
        src = src.replace(bad, good)
        applied.append('uaweapontable.h: %s' % label)
        touched = True
    elif good in src:
        already.append('uaweapontable.h: %s' % label)
    else:
        abort('the %s signature not found' % label,
              'neither form present')
if touched:
    wr(P, src)

# ---- the verify gate (fail on any anomaly) ----
import re

for h in HDRS:
    code = re.sub(r'//[^\n]*', '', rd(h))
    if code.count('{') != code.count('}'):
        abort('brace imbalance in %s' % h, '')
    for n, ln in enumerate(code.split(NL), 1):
        q = len(re.findall(r'(?<!\\)"', ln))
        if q % 2:
            abort('unbalanced quote %s:%d' % (h, n), ln)
    for m in re.finditer(
            r'inline ([\w ]+?[* ]?) (\w+)\([^)]*\) \{(.*?)\n\}',
            code, re.S):
        ret = m.group(1).strip()
        body = m.group(3)
        arr = re.search(
            r'static const ([\w ]+?[* ]?) k\[\d+\] = \{', body)
        if arr:
            atype = arr.group(1).strip()
            if ('char' in atype) != ('char' in ret):
                abort('%s %s returns %r, array %r'
                      % (h, m.group(2), ret, atype), '')
            if ('char' not in atype
                    and atype != ret):
                abort('%s %s returns %r, array %r'
                      % (h, m.group(2), ret, atype), '')

if rd('regtest.cpp').count('audit: bad ') != 319:
    abort('the census is not 319', 'run the R392 splice first')

if not rd('rules/uaequip26.h').startswith('// '):
    abort('the opener fix did not hold', '')

print('R392b splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R392b note: the players')
print('tables repair - the four C')
print('defects of the RED 6cfd9c2')
print('amend in place (the opener')
print('slash, the dagger inches')
print('escape, the two flipped')
print('return types); the census')
print('stays 319; the build is')
print('the test')
print('commit: R392b: the players')
print('tables repair (census 319)')

