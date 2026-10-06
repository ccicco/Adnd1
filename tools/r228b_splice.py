#!/usr/bin/env python3
# R228b splice: the R129 caster aging audit grew with the R228
# registry. The R228 round appended 77 DR_ rows to kSpells
# (SPELL_COUNT 54 -> 131); the R129 block still pinned the
# pre-R228 census (SPELL_COUNT 54, MU 31 / CL 23) and counted
# the new druid rows as clerics, so the battery printed
# "R129 caster aging audit: bad 2" and returned 1 - halting
# the battery before the R100-R113 blocks (the R112c census
# FAIL wall downstream of the halt, the R179b/R180b pattern).
# The R227b lesson generalized: any consumer that pins the
# registry census must ride the roster round. Five patches,
# all in regtest.cpp; idempotent (marker = the fixed lines).
# Zero backslashes; run AFTER r228_splice.py on 0874ba8.

NL = chr(10)
APPLIED = 0
ALREADY = 0


def patch(path, marker, old, new):
    global APPLIED, ALREADY
    s = open(path).read()
    if old not in s:
        if new in s:
            ALREADY += 1
            print('R228b: %s - already applied' % marker)
            return
        raise SystemExit('R228b FAIL: %s anchor not found in %s'
                         % (marker, path))
    if s.count(old) != 1:
        raise SystemExit('R228b FAIL: %s anchor not unique in %s'
                         % (marker, path))
    open(path, 'w').write(s.replace(old, new))
    APPLIED += 1
    print('R228b: %s - applied' % marker)


# 1. the comment names the grown registry
patch('regtest.cpp',
      'the census comment',
      '        // the registry grew to 54: MU 31, CL 23',
      '        // the registry grew to 131 (R228): MU 31,'
      ' CL 23, DR 77')

# 2. the SpellId census: 54 -> 131 (54 MU+CL + 77 DR)
patch('regtest.cpp',
      'the SpellId census',
      '        if (spells::SPELL_COUNT != 54) ++bad;',
      '        if (spells::SPELL_COUNT != 131) ++bad;')

# 3. the class counters grow a druid slot
patch('regtest.cpp',
      'the class counters',
      '            int mu = 0, cl = 0;',
      '            int mu = 0, cl = 0, dr = 0;')

# 4. the walk counts the druid rows as druids, not clerics
patch('regtest.cpp',
      'the class walk',
      '                if (s.sclass == spells::SPELL_MU) ++mu;'
      + NL + '                else ++cl;',
      '                if (s.sclass == spells::SPELL_MU) ++mu;'
      + NL + '                else if (s.sclass =='
      ' spells::SPELL_DRUID) ++dr;'
      + NL + '                else ++cl;')

# 5. the class census: MU 31, CL 23, DR 77
patch('regtest.cpp',
      'the class census',
      '            if (mu != 31 || cl != 23) ++bad;',
      '            if (mu != 31 || cl != 23 || dr != 77) ++bad;')

if APPLIED == 5 and ALREADY == 0:
    print('R228b splice: ALL OK (applied 5, already 0)')
elif APPLIED == 0 and ALREADY == 5:
    print('R228b splice: ALL OK (applied 0, already 5)')
else:
    raise SystemExit('R228b splice: MIXED STATE (applied %d,'
                     ' already %d) - inspect the tree'
                     % (APPLIED, ALREADY))
print('R228b note: the R129 caster aging audit now counts the'
      ' R228 registry (131 spells: MU 31, CL 23, DR 77);'
      ' the battery runs past R129 again - the R100-R113'
      ' census blocks return.')
print('commit: R228b: the R129 aging audit grows with the R228'
      ' registry (131 spells, the battery halt repaired)')

