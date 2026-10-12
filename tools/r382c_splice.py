# R382c: the egg of reason
# example fix. The R382 audit
# asserted the printed example
# value - 'intelligence 17
# gives 100 - (17 x 2) = 68%'
# - but the formula gives
# 100 - 34 = 66; the 68 is the
# book's own arithmetic slip.
# The battery caught it (R382
# bad 1). This fixer asserts
# the formula value (66) in
# regtest.cpp AND repairs the
# AUDIT template inside the
# committed r382_splice.py,
# so the artifact is
# self-consistent; the comment
# documents the printed slip.
# The census stays 309; no
# new audit line. Idempotent;
# run twice.
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


CHECK_OLD = '                    != 68) ++bad;'
CHECK_NEW = '                    != 66) ++bad;'
COMMENT_OLD = NL.join([
    '            // the printed example:',
    '            // intelligence 17 gives',
    '            // 100 - (17 x 2) = 68%;'
])
COMMENT_NEW = NL.join([
    '            // the printed example',
    '            // reads 68%, a book',
    '            // arithmetic slip - the',
    '            // formula gives 100 -',
    '            // (17 x 2) = 66;'
])


def fix(s, label):
    if CHECK_NEW in s:
        already.append(label)
        return s
    assert s.count(CHECK_OLD) == 1, (
        label + ' check anchor')
    assert s.count(COMMENT_OLD) == 1, (
        label + ' comment anchor')
    s = s.replace(CHECK_OLD, CHECK_NEW)
    s = s.replace(COMMENT_OLD, COMMENT_NEW)
    applied.append(label)
    return s


# ---- (a) regtest.cpp ----
RT = 'regtest.cpp'
s = rd(RT)
s = fix(s, 'regtest.cpp: the 66 check')
wr(RT, s)
s = rd(RT)
assert s.count(CHECK_NEW) == 1, 'a fixed check'
assert s.count(CHECK_OLD) == 0, 'a no 68 check'
assert s.count(COMMENT_OLD) == 0, 'a old comment gone'
assert s.count(
    'R382 UA misc magic prose part 2 pin audit: bad '
) == 1, 'a audit line kept'
assert s.count(
    'R381 UA misc magic prose part 1 pin audit: bad '
) == 1, 'a r381 kept'
assert s.count('audit: bad ') == 309, 'a census 309'
assert s.count(
    'using namespace rules;'
) >= 1, 'a using lines kept'
assert s.count(
    'R227: the wis mental save'
) == 1, 'a r227 kept'
clean(COMMENT_NEW, 76)


# ---- (b) tools/r382_splice.py ----
SP = 'tools/r382_splice.py'
s = rd(SP)
s = fix(s, 'splice: the AUDIT template')
wr(SP, s)
s = rd(SP)
assert s.count(CHECK_NEW) == 1, 'b fixed check'
assert s.count(CHECK_OLD) == 0, 'b no 68 check'
assert s.count(COMMENT_OLD) == 0, 'b old comment gone'
assert s.count('R382') >= 1, 'b round tag kept'
assert s.count(
    'using namespace rules;'
) == 1, 'b using line kept'


# ---- the summary ----
print(
    'R382c fix: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R382c note: the R382 audit',
    'asserted the egg of reason',
    "example's printed 68%, but",
    'the formula gives 100 -',
    '(17 x 2) = 66 - the 68 is',
    "the book's own arithmetic",
    'slip; the check now asserts',
    'the formula value and the',
    'comment documents the',
    'printed slip; patched in',
    'regtest.cpp and the',
    'committed splice; the',
    'census stays 309'
])
print(NOTE)
print('commit: amend R382 with the')
print('66 check; census stays 309')

