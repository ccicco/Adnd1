#!/usr/bin/env python3
# tools/r318b_splice.py - R318b: the hooks
# re-assert (the r318 bug fix - the RED
# preflight lesson).
#
# The bug the Termux preflight caught (bad 1,
# the N3 hold check): the R318 design read
# the tickStatus comment and took a zero
# round to mean permanent. The engine truth
# is the opposite - tickStatus sets kind
# STATUS_NONE on a zero-round mark and
# Actor::tickStatuses erases it, and every
# actor ticks at the round END (actor.cpp)
# - so the entrap evaporated at the first
# round-end tick and the STR 10 victim was
# free one round later. The MM print says
# the hooks hold until torn; the engine
# needs the fold to say it.
#
# The fix (4 patches, no new audit - the
# existing R318 audit caught the bug and
# stays the gate):
#   (a) ai/actor.cpp - the resolveMissile
#       comment tells the truth (the fold
#       re-asserts, not a zero-round myth).
#   (b) ai/actor.cpp - the entrap sets
#       roundsRemaining 2 (a mid-round volley
#       survives the first round-end tick).
#   (c) ai/actor.cpp - the round-start fold
#       re-asserts the mark on every victim
#       that does not tear (STR below 16):
#       the hooks hold; only the tear frees.
#   (d) regtest.cpp - the N3 hold check runs
#       a SECOND round (the regression
#       teeth: the hold must survive two
#       round-end ticks).
#
# The battery census stays 245 (no new
# audit; the letter-suffix rule - the fix
# amends the round, the initial splice is
# never rewritten and both land together).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file; no CONTENT
# string embeds an apostrophe, non-ASCII,
# or a line past its bound (78 the header
# and the C++ patches, 76 regtest).
# Commit (with r318_splice.py, the R316b
# precedent): "R318: the net entrap layer
# (census 245)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
BS = chr(92)
applied, already = [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def counts(s):
    return (s.count('{'), s.count('}'),
            s.count('('), s.count(')'))

# ---- (a) actor.cpp: the comment truth ----
CM_OLD = NL.join([
    '    // hooks hold until torn (the zero-round',
    '    // permanence, the stepRound tear fold)',
])
CM_NEW = NL.join([
    '    // hooks hold until torn (the round-start',
    '    // fold re-asserts the mark every round;',
    '    // a zero-round status dies at the',
    '    // round-end tick - the R318b lesson)',
])
clean(CM_OLD, 78)
clean(CM_NEW, 78)
assert Q not in CM_NEW, 'a apostrophe'

p = 'ai/actor.cpp'
s = rd(p)
if 'fold re-asserts the mark' in s:
    already.append('actor.cpp: the comment truth')
else:
    assert s.count(CM_OLD) == 1, 'comment anchor not unique'
    s = s.replace(CM_OLD, CM_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the comment truth')

s = rd(p)
assert s.count('fold re-asserts the mark') == 1, 'a comment'
assert s.count('the zero-round') == 0, 'a myth gone'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch a balance'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) actor.cpp: the entrap value ----
RV_OLD = NL.join([
    '        st.roundsRemaining = 0;   // until torn',
])
RV_NEW = NL.join([
    '        st.roundsRemaining = 2;   // until torn',
])
clean(RV_OLD, 78)
clean(RV_NEW, 78)

p = 'ai/actor.cpp'
s = rd(p)
if s.count(RV_NEW) == 1:
    already.append('actor.cpp: the entrap value')
else:
    assert s.count(RV_OLD) == 1, 'value anchor not unique'
    s = s.replace(RV_OLD, RV_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the entrap value')

s = rd(p)
assert s.count(RV_NEW) == 1, 'b value set'
assert s.count(RV_OLD) == 0, 'b zero gone'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch b balance'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) actor.cpp: the fold re-assert ----
FR_OLD = NL.join([
    '                logLine(a.name +',
    '                        ' + DQ +
    ' tears free of the net!' + DQ + ');',
    '            }',
])
FR_NEW = NL.join([
    '                logLine(a.name +',
    '                        ' + DQ +
    ' tears free of the net!' + DQ + ');',
    '            } else {',
    '                // R318b: the hooks re-assert -',
    '                // a held victim stays held; the',
    '                // round-end tick would strip a',
    '                // spent mark, the fold restores',
    '                // it (only the tear frees)',
    '                for (auto& st : a.statuses)',
    '                    if (st.kind ==',
    '                        spelleffects::',
    '                        STATUS_ENTANGLED)',
    '                        st.roundsRemaining = 2;',
    '            }',
])
for _t in (FR_OLD, FR_NEW):
    clean(_t, 78)
assert Q not in FR_NEW, 'c apostrophe'

p = 'ai/actor.cpp'
s = rd(p)
if 'the hooks re-assert' in s:
    already.append('actor.cpp: the fold re-assert')
else:
    assert s.count(FR_OLD) == 1, 'fold anchor not unique'
    s = s.replace(FR_OLD, FR_NEW, 1)
    wr(p, s)
    applied.append('actor.cpp: the fold re-assert')

s = rd(p)
assert s.count('the hooks re-assert') == 1, 'c fold'
assert s.count('roundsRemaining = 2;') == 2, 'c marks'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch c balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) regtest.cpp: the N3 second round ----
N3_ANCH = NL.join([
    '            if (enc.party().empty() ||',
    '                !enc.party()[0].hasStatus(',
    '                    spelleffects::STATUS_ENTANGLED))',
    '                ++bad;',
    '        }',
    '        // N4: the pins (the MM data)',
])
N3_ADD = NL.join([
    '            if (enc.party().empty() ||',
    '                !enc.party()[0].hasStatus(',
    '                    spelleffects::STATUS_ENTANGLED))',
    '                ++bad;',
    '            // R318b: the hooks re-assert - the',
    '            // hold must survive a second',
    '            // round-end tick',
    '            enc.stepRound();',
    '            for (const auto& ln : enc.log())',
    '                if (ln.text.find(' + DQ +
    'tears free of the net' + DQ + ')',
    '                    != std::string::npos)',
    '                    ++bad;',
    '            if (enc.party().empty() ||',
    '                !enc.party()[0].hasStatus(',
    '                    spelleffects::STATUS_ENTANGLED))',
    '                ++bad;',
    '        }',
    '        // N4: the pins (the MM data)',
])
for _t in (N3_ANCH, N3_ADD):
    clean(_t, 76)
assert Q not in N3_ADD, 'd apostrophe'

p = 'regtest.cpp'
s = rd(p)
if 'survive a second' in s:
    already.append('regtest.cpp: the N3 second round')
else:
    assert s.count(N3_ANCH) == 1, 'N3 anchor not unique'
    s = s.replace(N3_ANCH, N3_ADD, 1)
    wr(p, s)
    applied.append('regtest.cpp: the N3 second round')

s = rd(p)
assert s.count('survive a second') == 1, 'd note'
assert s.count(
    '!enc.party()[0].hasStatus(') == 2, 'd holds'
assert s.count('audit: bad') == 245, 'd census intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch d balance'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- R318b tail ----
if len(applied) + len(already) != 4:
    print('R318b splice: FAIL - expected 4 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R318b splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R318b note: 4 patches; the hooks')
print('re-assert (a zero-round mark died at')
print('the round-end tick - the N3 lesson);')
print('the battery census stays 245')
print('commit (with r318_splice.py): R318:')
print('the net entrap layer (census 245)')

