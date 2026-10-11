#!/usr/bin/env python3
# R336: the UA cavalier money
# (p. 25) pin round - the six
# stations, the gold ranges, the
# printed formulas (times-ten
# verified against the printed
# ranges and the R190 seam), the
# equipment lists item-by-item,
# the tack and esquire prose; the
# paladin exception noted but not
# detailed - a hole pending the
# PDF. The item closes. Pin-era
# pattern (R322). Idempotent; run
# twice.
import io
import os

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

# ---- (a) the seed: the R335 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R335 landed 2026-10-11: commit',
    '  ef84109, census 262, the UA',
    '  thief-acrobat pin round',
    '  (rules/acrobat.h): the split class',
    '  at 6th, Table I, the Function',
    '  Table columns (the tumbling',
    '  attack and evasion ladders',
    '  cell-by-cell, the falling column',
    '  where OCR survives), the',
    '  tightrope walk, the vault and',
    '  jump bands, the footnotes, the',
    '  Table III dex bonuses. GREEN on',
    '  the first paste. No new lessons.',    ])
s = rd(SD)
if 'R335 landed 2026-10-11' in s:
    already.append('seed: the R335 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R335 record')
s = rd(SD)
assert s.count('R335 landed 2026-10-11') == 1, \
    'a entry'
assert s.count('R334 landed 2026-10-11') == 1, \
    'a r334 kept'
assert s.count('R333 landed 2026-10-11') == 1, \
    'a r333 kept'
assert s.count('## Knowledge maintenance') == 1, \
    'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/cavmoney.h ----
CM = 'rules/cavmoney.h'
if os.path.exists(CM) and 'R336' in rd(CM):
    already.append('cavmoney.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/cavmoney.h',
    '// The UA Starting Money and Equipment for Cavaliers (p. 25) pins',
    '// (R336).',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists.',
    '//',
    '// JUDGMENTs:',
    '//   - the six stations pin in social-ladder order: the three',
    '//     Horseman rows (Lower Middle Class or less, Middle Middle,',
    '//     Upper Middle) then the three Cavalier rows (Lower Upper,',
    '//     Middle Upper, Upper Upper). The UMC row prints no shield',
    '//     and no dagger - pinned exactly as printed.',
    '//   - the gold: the two printed formulas, (1d12 + 6) and',
    '//     (1d6 + 12), are plain rolls TIMES 10 - the PHB convention',
    '//     landed as the R190 seam. Verified, not inferred: 7-18 x 10',
    '//     = 70-180 and 13-18 x 10 = 130-180, the printed ranges. The',
    '//     three Horseman rows print only "20-80 gp" with no formula -',
    '//     the range pins, the formula does not (the 2d4 x 10 guess',
    '//     is NOT pinned).',
    '//   - the equipment lists pin item-by-item exactly as printed;',
    '//     the UUC horse prints as one item, "heavy warhorse with',
    '//     leather barding".',
    '//',
    '// OCR holes: none in the section. The paladin is the one hole:',
    '// the DMG note (pp. 88-89) excepts "cavaliers and paladins" from',
    '// the social-class exemption, but the UA section details',
    '// cavaliers only - the paladin money rules are not printed here',
    '// (pinned as the exception\'s existence; the specifics stay a',
    '// hole pending the PDF).',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the stations (p. 25), in social-ladder order ----',
    'inline int cavMoneyStationCount()',
    '    { return 6; }',
    '',
    'inline const char* cavMoneyStationName(int i) {',
    '    static const char* const k[6] = {',
    '        "Lower Middle Class or less",',
    '        "Middle Middle Class",',
    '        "Upper Middle Class",',
    '        "Lower Upper Class",',
    '        "Middle Upper Class",',
    '        "Upper Upper Class"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    '// 0 = Horseman (0-level track), 1 = Cavalier (1st-level Armiger).',
    'inline const char* cavMoneyStationEntry(int i) {',
    '    static const char* const k[6] = {',
    '        "Horseman", "Horseman", "Horseman",',
    '        "Cavalier", "Cavalier", "Cavalier"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    '// ---- the gold ranges (p. 25) ----',
    'inline int cavMoneyGoldLow(int i) {',
    '    static const int k[6] = {20, 20, 20, 70, 70, 130};',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    'inline int cavMoneyGoldHigh(int i) {',
    '    static const int k[6] = {80, 80, 80, 180, 180, 180};',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    '// ---- the printed formulas (p. 25) ----',
    '// Count 0 = no formula printed (the three Horseman',
    '// rows); faces and bonus read 0 with it.',
    'inline int cavMoneyDiceCount(int i) {',
    '    static const int k[6] = {0, 0, 0, 1, 1, 1};',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    'inline int cavMoneyDiceFaces(int i) {',
    '    static const int k[6] = {0, 0, 0, 12, 6, 6};',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    'inline int cavMoneyDiceBonus(int i) {',
    '    static const int k[6] = {0, 0, 0, 6, 6, 12};',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    '// The printed formulas are plain rolls TIMES 10',
    '// gold pieces - the PHB convention (the R190 seam).',
    '// Verified: (1d12+6) x 10 = 70-180 and (1d6+12)',
    '// x 10 = 130-180, the printed ranges.',
    'inline bool cavMoneyGoldRollTimesTen()',
    '    { return true; }',
    '',
    '// ---- the equipment lists (p. 25) ----',
    'inline int cavMoneyItemCount(int i) {',
    '    static const int k[6] = {3, 4, 4, 6, 6, 7};',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return k[i];',
    '}',
    '',
    'inline const char* cavMoneyItemName(',
    '        int station, int j) {',
    '    static const char* const s0[3] = {',
    '        "shield", "sword (any type)",',
    '        "riding horse"',
    '    };',
    '    static const char* const s1[4] = {',
    '        "shield", "dagger",',
    '        "sword (broad or long)", "light warhorse"',
    '    };',
    '    static const char* const s2[4] = {',
    '        "chain mail", "sword (broad or long)",',
    '        "lance", "light warhorse"',
    '    };',
    '    static const char* const s3[6] = {',
    '        "shield", "plate mail", "dagger",',
    '        "sword (long or broad)", "lance",',
    '        "medium warhorse"',
    '    };',
    '    static const char* const s4[6] = {',
    '        "shield", "field plate armor", "dagger",',
    '        "sword (long or broad)", "lance",',
    '        "heavy warhorse"',
    '    };',
    '    static const char* const s5[7] = {',
    '        "shield", "full plate armor", "dagger",',
    '        "sword (long or broad)", "mace", "lance",',
    '        "heavy warhorse with leather barding"',
    '    };',
    '    if (station < 0) station = 0;',
    '    if (station > 5) station = 5;',
    '    if (j < 0) j = 0;',
    '    switch (station) {',
    '        case 0:',
    '            if (j > 2) j = 2;',
    '            return s0[j];',
    '        case 1:',
    '            if (j > 3) j = 3;',
    '            return s1[j];',
    '        case 2:',
    '            if (j > 3) j = 3;',
    '            return s2[j];',
    '        case 3:',
    '            if (j > 5) j = 5;',
    '            return s3[j];',
    '        case 4:',
    '            if (j > 5) j = 5;',
    '            return s4[j];',
    '        default:',
    '            if (j > 6) j = 6;',
    '            return s5[j];',
    '    }',
    '}',
    '',
    '// ---- the prose pins (p. 25) ----',
    'inline bool cavMoneyHorsesCompleteWithTack()',
    '    { return true; }',
    '',
    'inline bool cavMoneyBelowUpperStartHorseman()',
    '    { return true; }',
    '',
    'inline bool cavMoneyBelowUpperEsquired()',
    '    { return true; }',
    '',
    '// The DMG note (pp. 88-89): starting money and',
    '// equipment are exempt from social-class effects',
    '// only for cavaliers AND paladins; the section',
    '// details the cavalier only.',
    'inline bool cavMoneyPaladinExceptionNoted()',
    '    { return true; }',
    '',
    '}   // namespace rules',    ])
    clean(HDR, 78)
    wr(CM, HDR)
    applied.append('cavmoney.h: the pins')
s = rd(CM)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 15, 'b inline count'
assert s.count('R336') == 1, 'b round tag'
assert s.count('cavMoneyItemName') == 1, 'b items'
assert s.count('cavMoneyGoldRollTimesTen') == 1, \
    'b times ten'
assert 'acrobatFallingChanceKnown' not in s, \
    'b no r335 ref'
assert 'thiefArmorModifierKnown' not in s, \
    'b no r334 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R336' in s:
    already.append('gap report: the close')
else:
    FIRST_OLD = ('- [ ] **Money for cavaliers**'
                ' (p. 25) -')
    TAIL_OLD = ('      the starting gear by social'
                ' class.')
    assert s.count(FIRST_OLD) == 1, 'c first'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    CLOSE = NL.join([
    '      - CLOSED R336: the pin round',
    '        (rules/cavmoney.h) - the six',
    '        stations in social-ladder',
    '        order, the gold ranges, the',
    '        printed formulas verified',
    '        times-ten against the printed',
    '        ranges and the R190 seam, the',
    '        equipment lists item-by-item',
    '        as printed, the tack and',
    '        esquire prose. The paladin',
    '        exception noted at DMG',
    '        pp. 88-89 but not detailed -',
    '        a hole pending the PDF read.',    ])
    clean(CLOSE, 57)
    s = s.replace(FIRST_OLD,
        '- [x] **Money for cavaliers** (p. 25) -')
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + CLOSE)
    wr(GP, s)
    applied.append('gap report: the close')
s = rd(GP)
FLIP = ('- [x] **Money for cavaliers**'
        ' (p. 25) -')
assert s.count('CLOSED R336') == 1, 'c close'
assert s.count(FLIP) == 1, 'c item flipped'
assert s.count(
    '- [ ] **Money for cavaliers** (p. 25) -') \
    == 0, 'c no open item'
assert s.count('R334: the fragment-verified') \
    == 1, 'c r334 note kept'
assert s.count('CLOSED R335') == 1, 'c r335 kept'
assert s.count('CLOSED R333') == 1, 'c r333 kept'
assert s.count('CLOSED R332') == 1, 'c r332 kept'
assert s.count('CLOSED R330') == 1, 'c r330 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R336 cavalier money pin audit' in s:
    already.append('regtest.cpp: the R336 audit')
else:
    INC_ANCH = ('#include "rules/acrobat.h"'
                '  // R335: the UA thief-acrobat')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/cavmoney.h"'
    '  // R336: the UA cavalier money',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R336: the cavalier money pin audit ----',
    '    // The UA Starting Money and Equipment for Cavaliers',
    '    // (p. 25) - the six stations in social-ladder order,',
    '    // the gold ranges, the printed dice formulas (the',
    '    // times-ten convention verified against the printed',
    '    // ranges and the R190 seam), the equipment lists',
    '    // pinned item-by-item as printed (the UMC row prints',
    '    // no shield or dagger), the tack and esquire prose;',
    '    // the paladin exception noted but not detailed - a',
    '    // documented hole pending the PDF. The R328/R190',
    '    // seams cross-checked.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the stations',
    '        {',
    '            if (cavMoneyStationCount() != 6) ++bad;',
    '            if (strcmp(cavMoneyStationName(0),',
    '                "Lower Middle Class or less") != 0)',
    '                ++bad;',
    '            if (strcmp(cavMoneyStationName(2),',
    '                "Upper Middle Class") != 0) ++bad;',
    '            if (strcmp(cavMoneyStationName(5),',
    '                "Upper Upper Class") != 0) ++bad;',
    '            if (strcmp(cavMoneyStationEntry(0),',
    '                "Horseman") != 0) ++bad;',
    '            if (strcmp(cavMoneyStationEntry(2),',
    '                "Horseman") != 0) ++bad;',
    '            if (strcmp(cavMoneyStationEntry(3),',
    '                "Cavalier") != 0) ++bad;',
    '            if (strcmp(cavMoneyStationEntry(5),',
    '                "Cavalier") != 0) ++bad;',
    '        }',
    '        // U2: the gold ranges and the',
    '        // times-ten decode',
    '        {',
    '            static const int lo[6] = {',
    '                20, 20, 20, 70, 70, 130',
    '            };',
    '            static const int hi[6] = {',
    '                80, 80, 80, 180, 180, 180',
    '            };',
    '            for (int i = 0; i < 6; ++i) {',
    '                if (cavMoneyGoldLow(i) != lo[i])',
    '                    ++bad;',
    '                if (cavMoneyGoldHigh(i) != hi[i])',
    '                    ++bad;',
    '            }',
    '            // the printed formulas times ten',
    '            // reproduce the printed ranges',
    '            if (!cavMoneyGoldRollTimesTen())',
    '                ++bad;',
    '            if ((1 + cavMoneyDiceBonus(3)) * 10',
    '                != cavMoneyGoldLow(3)) ++bad;',
    '            if ((12 + cavMoneyDiceBonus(3)) * 10',
    '                != cavMoneyGoldHigh(3)) ++bad;',
    '            if ((1 + cavMoneyDiceBonus(5)) * 10',
    '                != cavMoneyGoldLow(5)) ++bad;',
    '            if ((6 + cavMoneyDiceBonus(5)) * 10',
    '                != cavMoneyGoldHigh(5)) ++bad;',
    '            // the formula rows',
    '            if (cavMoneyDiceCount(3) != 1) ++bad;',
    '            if (cavMoneyDiceFaces(3) != 12) ++bad;',
    '            if (cavMoneyDiceFaces(4) != 6) ++bad;',
    '            if (cavMoneyDiceBonus(4) != 6) ++bad;',
    '            if (cavMoneyDiceBonus(5) != 12) ++bad;',
    '            // the Horseman rows print no',
    '            // formula - all three read 0',
    '            for (int i = 0; i < 3; ++i) {',
    '                if (cavMoneyDiceCount(i) != 0)',
    '                    ++bad;',
    '                if (cavMoneyDiceFaces(i) != 0)',
    '                    ++bad;',
    '                if (cavMoneyDiceBonus(i) != 0)',
    '                    ++bad;',
    '            }',
    '        }',
    '        // U3: the item counts',
    '        {',
    '            static const int k[6] = {3, 4, 4, 6, 6, 7};',
    '            for (int i = 0; i < 6; ++i)',
    '                if (cavMoneyItemCount(i) != k[i])',
    '                    ++bad;',
    '        }',
    '        // U4: the item names (spot reads)',
    '        {',
    '            if (strcmp(cavMoneyItemName(0, 1),',
    '                "sword (any type)") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(0, 2),',
    '                "riding horse") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(1, 2),',
    '                "sword (broad or long)") != 0)',
    '                ++bad;',
    '            if (strcmp(cavMoneyItemName(2, 0),',
    '                "chain mail") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(3, 1),',
    '                "plate mail") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(4, 1),',
    '                "field plate armor") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(5, 1),',
    '                "full plate armor") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(5, 4),',
    '                "mace") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(5, 6),',
    '                "heavy warhorse with leather"',
    '                " barding") != 0) ++bad;',
    '        }',
    '        // U5: the armor ladder and the',
    '        // shieldless UMC row',
    '        {',
    '            // chain mail UMC -> plate mail LUC',
    '            // -> field plate MUC -> full plate UUC',
    '            if (strcmp(cavMoneyItemName(2, 0),',
    '                "chain mail") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(3, 1),',
    '                "plate mail") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(4, 1),',
    '                "field plate armor") != 0)',
    '                ++bad;',
    '            if (strcmp(cavMoneyItemName(5, 1),',
    '                "full plate armor") != 0) ++bad;',
    '            // the UMC row prints no shield',
    '            bool shield = false;',
    '            for (int j = 0; j < cavMoneyItemCount(2);',
    '                 ++j)',
    '                if (strcmp(cavMoneyItemName(2, j),',
    '                    "shield") == 0) shield = true;',
    '            if (shield) ++bad;',
    '        }',
    '        // U6: the horses',
    '        {',
    '            if (strcmp(cavMoneyItemName(0, 2),',
    '                "riding horse") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(1, 3),',
    '                "light warhorse") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(2, 3),',
    '                "light warhorse") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(3, 5),',
    '                "medium warhorse") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(4, 5),',
    '                "heavy warhorse") != 0) ++bad;',
    '            if (strcmp(cavMoneyItemName(5, 6),',
    '                "heavy warhorse with leather"',
    '                " barding") != 0) ++bad;',
    '        }',
    '        // U7: the prose pins',
    '        {',
    '            if (!cavMoneyHorsesCompleteWithTack())',
    '                ++bad;',
    '            if (!cavMoneyBelowUpperStartHorseman())',
    '                ++bad;',
    '            if (!cavMoneyBelowUpperEsquired())',
    '                ++bad;',
    '            if (!cavMoneyPaladinExceptionNoted())',
    '                ++bad;',
    '        }',
    '        // U8: the seams - the R328 horseman',
    '        // track and the R190 times-ten',
    '        // convention',
    '        {',
    '            if (cavalierHorsemanXp() != -1500)',
    '                ++bad;',
    '            if (cavalierLancerXp() != -500) ++bad;',
    '            if (startingMoneyMultiplier(0) != 10)',
    '                ++bad;',
    '        }',
    '        printf("R336 cavalier money pin audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R336 audit')
s = rd(RT)
assert s.count(
    'R336 cavalier money pin audit: bad ') \
    == 1, 'd audit line'
assert s.count('audit: bad ') == 263, 'd census 263'
assert s.count(
    'R335 thief-acrobat pin audit: bad ') \
    == 1, 'd r335 kept'
assert s.count(
    'R334 thief armor and attacks pin audit: bad ') \
    == 1, 'd r334 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count('#include "rules/cavmoney.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R336 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R336 note: the UA cavalier money pin')
print('round - the six stations, the gold')
print('ranges, the printed formulas verified')
print('times-ten, the equipment lists')
print('item-by-item, the tack and esquire')
print('prose; the paladin exception noted')
print('but not detailed (a hole pending the')
print('PDF); the census 262 -> 263')
print('commit: R336: the UA cavalier money')
print('pin round (census 263)')

