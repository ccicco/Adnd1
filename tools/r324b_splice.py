# ============================================================================
# Adnd1 - tools/r324b_splice.py
# The R324b fix: the elf gates
# case list gains SUB_ELF_WILD.
#
# The R324 preflight read RED: the
# R324 audit reported bad 2 and its
# `if (bad) return 1;` bail-out
# suppressed every audit after it
# (the census FAILs were all
# knock-on). The two failing checks
# share one root cause: the
# subraceLevelGates elf case list
# names the dark/gray/high/valley/
# wood elves but omits the wild elf,
# so the wild-elf druid CHA gates
# (fn1/fn2) and the wild-elf
# assassin shared INT/WIS gates
# (fn1-fn6) both read null.
#
# Patch (idempotent; guarded and
# re-runnable):
#   (a) rules/subracelevels.h - the
#       case SUB_ELF_WILD: line
#       joins the shared elf block
#       of subraceLevelGates (the
#       enum order: after VALLEY,
#       before WOOD). The
#       subraceLevelColumn switch
#       already carried the wild
#       elf; only the gates switch
#       omitted it.
#
# The build-time Python model had
# the intent (the wild elf in the
# elf block); the generated C++ did
# not - the cross-check verified
# the audit against the model, not
# against the landed C++ text. The
# R325 lesson: the model must be
# read back out of the generated
# header, not out of the intent.
# ============================================================================

import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
applied, already = [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) the gates case list ----
SL = 'rules/subracelevels.h'
s = rd(SL)
ANCH = (
    '        case SUB_ELF_VALLEY:' + NL
    + '        case SUB_ELF_WOOD:' + NL
    + '            if (c == UACLASS_DRUID) {')
FIX = (
    '        case SUB_ELF_VALLEY:' + NL
    + '        case SUB_ELF_WILD:' + NL
    + '        case SUB_ELF_WOOD:' + NL
    + '            if (c == UACLASS_DRUID) {')
clean(FIX, 78)
if FIX in s:
    already.append('subracelevels.h: the wild-elf gates case')
else:
    assert s.count(ANCH) == 1, 'the gates anchor is not unique'
    assert s.count('case SUB_ELF_WILD:') == 1,\
        'unexpected column case count'
    s = s.replace(ANCH, FIX)
    wr(SL, s)
    applied.append('subracelevels.h: the wild-elf gates case')
s = rd(SL)
assert s.count('SUB_ELF_WILD') == 3, 'the wild-elf tokens'
assert s.count('case SUB_ELF_WILD:') == 2, 'the wild-elf cases'
assert s.count('if (s != SUB_ELF_WILD)') == 1, 'the druid guard kept'
assert s.count('kIicDG1') == 2, 'dg1 kept'
assert s.count('kIicAG3') == 2, 'ag3 kept'
assert len(applied) + len(already) == 1, 'patch count wrong'

if len(applied) + len(already) != 1:
    print('R324b splice: FAIL - expected 1 patch, '
          'counted ' + str(len(applied) + len(already)))
    sys.exit(1)
print('R324b splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R324b note: the fix round - the elf')
print('gates case list gains SUB_ELF_WILD')
print('the wild-elf druid CHA gates and the')
print('shared assassin gates read again')
print('the R324 audit goes bad 2 -> bad 0')
print('census stays 251; amend the round:')
print('git add rules/subracelevels.h')
print('git commit --amend --no-edit')
print('then ./tools/preflight.sh && git push')

