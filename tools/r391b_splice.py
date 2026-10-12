# R391b: the pole-arm nomenclature
# audit fix. The R391 audit block
# shipped one inverted cross-check:
# the family-coverage condition
# `>= uapaPartItemTotal()` fires
# on the CORRECT value (5+3=8
# versus the 7-item ledger), so
# the audit printed bad 1 and the
# early return truncated the
# census run. The fix flips the
# comparison to `<` - the family
# counts must not cover fewer
# items than the ledger total.
# regtest.cpp ONLY; the census
# stays 318 (no new audit line).
# Pin-era pattern (R322).
# Idempotent; run twice.
import io

NL = '\n'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)


# ---- the fix: the R391 cross-check ----
RT = 'regtest.cpp'
s = rd(RT)
if '< uapaPartItemTotal()) ++bad;' in s:
    already.append('regtest.cpp: the fix')
else:
    OLD = NL.join([
        '            if (uapaSpearFamilyCount()',
        '                + uapaAxeFamilyTrueMemberCount()',
        '                >= uapaPartItemTotal()) ++bad;',
    ])
    NEW = NL.join([
        '            if (uapaSpearFamilyCount()',
        '                + uapaAxeFamilyTrueMemberCount()',
        '                < uapaPartItemTotal()) ++bad;',
    ])
    assert s.count(OLD) == 1, 'fix old'
    clean(NEW, 76)
    s = s.replace(OLD, NEW)
    wr(RT, s)
    applied.append('regtest.cpp: the fix')


s = rd(RT)
assert s.count(
    '    + uapaAxeFamilyTrueMemberCount()'
) == 1, 'fix seam line'
assert s.count(
    '< uapaPartItemTotal()) ++bad;'
) == 1, 'fix new'
assert s.count(
    '>= uapaPartItemTotal()) ++bad;'
) == 0, 'fix old gone'
assert s.count(
    'R391 UA pole-arm nomenclature pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R390 UA non-lethal combat pin audit: bad '
) == 1, 'd r390 kept'
assert s.count(
    'R389 UA weaponless combat pin audit: bad '
) == 1, 'd r389 kept'
assert s.count('audit: bad ') == 318, 'd census 318'
assert s.count(
    '#include "rules/uaappendt.h"'
) == 1, 'd include kept'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert len(applied) + len(already) == 1, 'count'


# ---- the summary ----
print(
    'R391b splice: ALL OK (applied %d, '
    'already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R391b note: the pole-arm',
    'nomenclature audit fix - the',
    'inverted family-coverage',
    'cross-check (>= firing on',
    'the correct 5+3 versus 7)',
    'flips to <; the census',
    'stays 318, no new audit',
    'line; preflight RED to',
    'GREEN',
])
print(NOTE)
print('commit: R391b: the pole-arm')
print('nomenclature audit fix')
print('(census 318)')

