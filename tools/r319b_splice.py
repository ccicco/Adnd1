#!/usr/bin/env python3
# tools/r319b_splice.py - R319b: the
# public cast seam (the r319 RED fix).
#
# The bug the Termux build caught (2 errors,
# the W2/W3 audit calls): resolveCast sat
# in the Encounter PRIVATE block - the
# engine drives casts from the internal
# scheduler, so no public caller existed
# and the audit could not reach the light
# fold. The partyMutable seam comment even
# promised the cast commands reach the
# live company actors; the declaration
# never moved. The census failures were
# cascade (the build died, the battery
# never ran).
#
# The fix (1 patch - the declaration moves
# public; the definition and every engine
# caller unchanged; the R319 audit stays the
# gate):
#   (a) ai/actor.h - the resolveCast
#       declaration rides the public block
#       (beside partyMutable, the seam it
#       belongs to); the private block keeps
#       a pointer comment.
#
# The battery census stays 246.
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows the
# patch (the R142 lesson). ZERO literal
# backslash bytes; no apostrophe, non-ASCII,
# or line past 78.
# Commit (with r319_splice.py): "R319: the
# underwater vision multiples (census 246)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
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

# ---- (a) actor.h: the public cast seam ----
PR_OLD = NL.join([
    '    // R27: resolve a party member' + Q + 's cast through spelleffects and',
    '    // apply the per-target results (hp, statuses, notes) back to',
    '    // the affected actors',
    '    void resolveCast(Actor& caster, spells::SpellId id);',
])
PR_NEW = NL.join([
    '    // R27/R319b: the cast seam moved',
    '    // public (below, beside partyMutable -',
    '    // the audit drives a party cast; the',
    '    // engine callers unchanged)',
])
clean(PR_OLD, 78)
clean(PR_NEW, 78)

PU_OLD = NL.join([
    '    std::vector<Actor>& partyMutable() { return m_party; }',
    '',
    '    // single-round step (interactive combat drives this)',
    '    int stepRound();',
])
PU_NEW = NL.join([
    '    std::vector<Actor>& partyMutable() { return m_party; }',
    '    // R27/R319b: resolve a party member' + Q + 's cast',
    '    // through spelleffects and apply the',
    '    // per-target results (hp, statuses,',
    '    // notes) back to the affected actors -',
    '    // the PUBLIC cast seam (the R319b',
    '    // lesson: the audit drives a party',
    '    // cast, so the declaration rides the',
    '    // public block; the engine callers',
    '    // unchanged)',
    '    void resolveCast(Actor& caster, spells::SpellId id);',
    '',
    '    // single-round step (interactive combat drives this)',
    '    int stepRound();',
])
clean(PU_OLD, 78)
clean(PU_NEW, 78)

p = 'ai/actor.h'
s = rd(p)
if 'the PUBLIC cast seam' in s:
    already.append('actor.h: the public cast seam')
else:
    assert s.count(PR_OLD) == 1, 'private anchor not unique'
    s = s.replace(PR_OLD, PR_NEW, 1)
    assert s.count(PU_OLD) == 1, 'public anchor not unique'
    s = s.replace(PU_OLD, PU_NEW, 1)
    wr(p, s)
    applied.append('actor.h: the public cast seam')

s = rd(p)
assert s.count(
    'void resolveCast(Actor& caster, spells::SpellId id);') == 1, (
    'a decl once')
assert s.count('the PUBLIC cast seam') == 1, 'a seam note'
assert s.count('int stepRound();') == 1, 'a step intact'
assert s.count(
    'partyMutable() { return m_party; }') == 1, 'a mirror intact'
_o, _c, _o2, _c2 = counts(s)
assert _o == _c and _o2 == _c2, 'patch a balance'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- R319b tail ----
if len(applied) + len(already) != 1:
    print('R319b splice: FAIL - expected 1 patch, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R319b splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R319b note: 1 patch; the resolveCast')
print('declaration moves public (the audit')
print('drives a party cast - the private')
print('block kept the W2/W3 calls out); the')
print('battery census stays 246')
print('commit (with r319_splice.py): R319:')
print('the underwater vision multiples')
print('(census 246)')

