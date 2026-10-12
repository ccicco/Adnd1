# R382b: the UA misc magic prose
# part 2 fix round: the R382
# audit block dropped its
# 'using namespace rules;'
# opening line, so its 107
# uamm2 calls sat at a scope
# without the using-directive
# and the battery build failed
# (undeclared identifiers; the
# empty battery output made
# every census line read 0).
# This fixer restores the line
# in regtest.cpp AND repairs
# the AUDIT template inside
# the committed r382_splice.py,
# so the artifact is
# self-consistent. The census
# stays 309; no new audit
# line. Idempotent; run twice.
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


USING = '        using namespace rules;'
MARK = '    // ---- R382: the UA misc magic'
BRACE = '    {'
BAD0 = '        int bad = 0;'


# ---- (a) regtest.cpp: the
# missing using line ----
RT = 'regtest.cpp'
s = rd(RT)
i = s.find(MARK)
assert i >= 0, 'a mark'
b = s.find(BRACE, i)
assert b >= 0, 'a brace'
after = s[b + len(BRACE) + 1:]
if after.startswith(USING):
    already.append('regtest.cpp: the using line')
else:
    assert after.startswith(BAD0), 'a broken sig'
    s = (s[:b + len(BRACE) + 1] + USING
         + NL + s[b + len(BRACE) + 1:])
    wr(RT, s)
    applied.append('regtest.cpp: the using line')
s = rd(RT)
assert s.count(MARK) == 1, 'a mark kept'
assert s.count(
    'R382 UA misc magic prose part 2 pin audit: bad '
) == 1, 'a audit line kept'
assert s.count('audit: bad ') == 309, 'a census 309'
i = s.find(MARK)
b = s.find(BRACE, i)
assert s[b + len(BRACE) + 1:].startswith(
    USING), 'a fixed block'
assert s.count(
    'R381 UA misc magic prose part 1 pin audit: bad '
) == 1, 'a r381 kept'
assert s.count(
    'R227: the wis mental save'
) == 1, 'a r227 kept'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) tools/r382_splice.py:
# the AUDIT template ----
SP = 'tools/r382_splice.py'
s = rd(SP)
OPEN = NL.join([BRACE, BAD0])
FIXED = NL.join([BRACE, USING, BAD0])
if s.count(OPEN) == 0:
    assert s.count(FIXED) == 1, 'b fixed present'
    already.append('splice: the AUDIT template')
else:
    assert s.count(OPEN) == 1, 'b open'
    assert s.count(FIXED) == 0, 'b no fixed yet'
    s = s.replace(OPEN, FIXED)
    wr(SP, s)
    applied.append('splice: the AUDIT template')
s = rd(SP)
assert s.count(FIXED) == 1, 'b fixed template'
assert s.count(OPEN) == 0, 'b no broken open'
assert s.count('R382') >= 1, 'b round tag kept'
clean(FIXED, 31)
assert len(applied) + len(already) == 2, 'b count'


# ---- the summary ----
print(
    'R382b fix: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R382b note: the R382 audit',
    'block dropped its using',
    'namespace rules opening',
    'line - the 107 uamm2 calls',
    'sat at a scope without the',
    'directive and the battery',
    'build failed; restored in',
    'regtest.cpp and patched in',
    'the committed splice; the',
    'census stays 309'
])
print(NOTE)
print('commit: amend R382 with the')
print('using line restored; census')
print('stays 309')

