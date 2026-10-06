#!/usr/bin/env python3
# R232b splice: the monk open-hand damage fix.
#
# The R232 helper invented an ai::Actor API: Actor carries
# no encounter dice - the dice live on the Encounter
# (m_dice), in scope at both call sites of resolveMelee.
# The fix drops the static helper and rolls the Monks
# Table II row span on the encounter dice directly:
# dmg = roll(1, dmgHi - dmgLo + 1) + dmgLo - 1 (a span of
# one reads dmgLo == dmgHi - the degenerate row is safe).
#
# Patches (run on the R232-spliced tree, census 148):
#  1. ai/actor.cpp - remove the monkOpenHandDamage helper
#     (the encounterDice call is the syntax-gate error),
#     leaving the giant-class helper and its comment
#  2. the bare-fist call site - roll the span on m_dice
#  3. the armed call site - same roll
#
# commit: R232: the subclass specials hooks - backstab, the monk open hand, the giant-class bonus, lay on hands (census 148)

import sys

AC = 'ai/actor.cpp'

NL = chr(10)
Q = chr(39)
BS = chr(92)

# ---- 1: the helper ----
helper_old = [
    '// R232: the monk open-hand damage - the Monks Table II row',
    'static int monkOpenHandDamage(const Actor& a) {',
    '    const rules::MonkLadderRow& r =',
    '        rules::monkLadderRow(a.level);',
    '    int span = r.dmgHi - r.dmgLo + 1;',
    '    if (span <= 1) return r.dmgHi;',
    '    return (int)a.encounterDice().roll(',
    '               1, (uint32_t)span, 0) + r.dmgLo - 1;',
    '}',
]
helper_new = [
    '// R232: the monk open-hand damage - the Monks Table II',
    '// row span, rolled in resolveMelee on the encounter',
    '// dice. ai::Actor carries no dice member of its own',
    '// (the R232 helper invented one); the dice live on',
    '// the Encounter (the R232b fix).',
]

# ---- 2: the bare-fist call site ----
fist_old = [
    '            if (attacker.subclass == rules::SUB_MONK) {',
    '                dmg = monkOpenHandDamage(attacker);',
    '            } else {',
]
fist_new = [
    '            if (attacker.subclass == rules::SUB_MONK) {',
    '                const rules::MonkLadderRow& mr =',
    '                    rules::monkLadderRow(attacker.level);',
    '                dmg = (int)m_dice.roll(',
    '                    1, (uint32_t)(mr.dmgHi - mr.dmgLo + 1),',
    '                    0) + mr.dmgLo - 1;',
    '            } else {',
]

# ---- 3: the armed call site ----
armed_old = [
    '            // pack (the JUDGMENT)',
    '            dmg = monkOpenHandDamage(attacker);',
]
armed_new = [
    '            // pack (the JUDGMENT). The ladder row span',
    '            // rolls on the encounter dice - the same',
    '            // roll as the bare-fist path (the R232b fix)',
    '            {',
    '                const rules::MonkLadderRow& mr =',
    '                    rules::monkLadderRow(attacker.level);',
    '                dmg = (int)m_dice.roll(',
    '                    1, (uint32_t)(mr.dmgHi - mr.dmgLo + 1),',
    '                    0) + mr.dmgLo - 1;',
    '            }',
]

PATCHES = [
    (AC, 'monkOpenHandDamage(const Actor& a)', helper_old, helper_new),
    (AC, 'if (attacker.subclass == rules::SUB_MONK) {', fist_old, fist_new),
    (AC, '// pack (the JUDGMENT)', armed_old, armed_new),
]

applied = 0
already = 0
for path, marker, old, new in PATCHES:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    count = text.count(old_s)
    if count == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    elif count == 0:
        if text.count(new_s) != 1:
            print('R232b FAIL: marker missing post-patch: ' + marker)
            sys.exit(1)
        already += 1
    else:
        print('R232b FAIL: marker appears ' + str(count) + ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions: the invented API is gone, the roll is in
if applied == len(PATCHES):
    with open(AC) as f:
        t = f.read()
    if 'encounterDice' in t:
        print('R232b FAIL: encounterDice still present')
        sys.exit(1)
    if 'monkOpenHandDamage' in t:
        print('R232b FAIL: the old helper still referenced')
        sys.exit(1)
    if t.count('(uint32_t)(mr.dmgHi - mr.dmgLo + 1)') != 2:
        print('R232b FAIL: the span roll must appear exactly twice')
        sys.exit(1)

print('R232b splice: ALL OK (applied ' + str(applied) + ', already ' + str(already) + ')')
print('R232b note: 3 patches - the monk open-hand damage rolls the')
print('Monks Table II span on the encounter dice; no Actor dice API.')
print('commit: R232: the subclass specials hooks - backstab, the monk open hand, the giant-class bonus, lay on hands (census 148)')

