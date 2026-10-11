#!/usr/bin/env python3
# R337: the UA WEIGHT AND DAMAGE
# BY WEAPON TYPE table (p. 26) pin
# round - the 67-row roster, all 50
# PHB rows cell-verified against the
# R189 seam (the hyphen-loss pattern
# proven row by row), the 17
# new-weapon rows pinned where
# printed or pattern-decoded; the
# atlatl/harpoon/falchion weights,
# the lasso damage and the garbled
# quarrel row are OCR holes - the
# item stays open pending the PDF.
# Pin-era pattern (R322). Idempotent;
# run twice.
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

# ---- (a) the seed: the R336 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R336 landed 2026-10-11: commit',
    '  74ebf6a, census 263, the UA',
    '  cavalier money pin round',
    '  (rules/cavmoney.h): the six',
    '  stations in social-ladder',
    '  order, the gold ranges, the',
    '  printed formulas verified',
    '  times-ten against the printed',
    '  ranges and the R190 seam, the',
    '  equipment lists item-by-item',
    '  as printed, the tack and',
    '  esquire prose; the paladin',
    '  exception noted, not',
    '  detailed. GREEN on the first',
    '  paste. No new lessons.',    ])
s = rd(SD)
if 'R336 landed 2026-10-11' in s:
    already.append('seed: the R336 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R336 record')
s = rd(SD)
assert s.count('R336 landed 2026-10-11') == 1, \
    'a entry'
assert s.count('R335 landed 2026-10-11') == 1, \
    'a r335 kept'
assert s.count('R334 landed 2026-10-11') == 1, \
    'a r334 kept'
assert s.count('## Knowledge maintenance') == 1, \
    'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uaweapontable.h ----
UW = 'rules/uaweapontable.h'
if os.path.exists(UW) and 'R337' in rd(UW):
    already.append('uaweapontable.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/uaweapontable.h',
    '// The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) pins',
    '// (R337).',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists.',
    '//',
    '// JUDGMENTs:',
    '//   - the roster: 67 rows in the printed order. The OCR merges',
    '//     and garbles several rows; every row is attributed by data,',
    '//     not guesswork: the 50 PHB weapons (the R189 chart,',
    '//     rules/weapontables.h) match cell for cell -',
    '//     uawtPhbSeamIndex maps each row to its chart row. The',
    '//     merged Jo Stick/Javelin, Long/Short Sword and Lance',
    '//     (heavy)/Lasso rows split by seam.',
    '//   - the hyphen-loss pattern: the OCR drops hyphens in many',
    '//     damage cells (1-6 prints 16, 2-12 prints 212), dots or',
    '//     colons in others (2.5 = 2-5, 2:8 = 2-8). The pattern is',
    '//     proven against the R189 seam on every PHB row it touches',
    '//     (the arrow 16, dagger 14, bo stick 13, halberd 212, the',
    '//     heavy quarrel 2.5/2.7). The new-weapon cells decoded by',
    '//     the same pattern pin as pattern-decoded.',
    '//   - attributed rows: the Military Fork and Glaive-Guisarme',
    '//     data rows print nameless (OCR-displaced); each matches',
    '//     exactly one R189 row - attributed by unique seam match.',
    '//     The pick rows print garbled names; the data assigns them.',
    '//     The row between Ranseur and Scimitar (10, 1-2, 1-2)',
    '//     attributes to the Sap - the roster\'s named new weapon',
    '//     otherwise absent, in its alphabetical place.',
    '//   - the Garrot row prints a stray 3 beside the weight column;',
    '//     the weight 1 pins (the weight-column cell). The Lance',
    '//     (heavy)/Lasso merged row prints 150 20 - the 150 is the',
    '//     lance (seam), the 20 pins as the lasso weight.',
    '//   - the horseman flail S/M cell prints empty in the UA',
    '//     extract - it closes via the R189 seam (2-5, the PHB',
    '//     print), the R333 seam-closure convention; the L cell',
    '//     2.5 decodes by the dot pattern to the same value.',
    '//   - flat damage cells pin as printed (the blowgun 1/1, the',
    '//     caltrop 1, the whip L 1).',
    '//',
    '// OCR holes (the item stays open pending the PDF read): the',
    '// atlatl, harpoon and falchion weights, the lasso damage',
    '// cells, the stray 30 beside the aklys row, and the',
    '// unattributable garbled quarrel row (Quarrel (or Bolt),',
    '// hand - 13/12 matches no seam row; not pinned).',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The row count (67 = the 50 PHB rows',
    '// plus 17 new-weapon rows).',
    'inline int uawtRowCount()',
    '    { return 67; }',
    '',
    '// The PHB rows verified cell for cell',
    '// against the R189 chart seam.',
    'inline int uawtSeamVerifiedCount()',
    '    { return 50; }',
    '',
    '// The UA-new weapon rows (not in the',
    '// PHB chart): the aklys, atlatl,',
    '// blowgun, caltrop, garrot, harpoon,',
    '// hook fauchard, knife, lasso, man',
    '// catcher, sap, spiked buckler, staff',
    '// sling (two rows), falchion, khopesh',
    '// and whip.',
    'inline int uawtNewWeaponCount()',
    '    { return 17; }',
    '',
    '// The row name (printed, or the',
    '// attribution judgment).',
    'inline const char* uawtName(int i) {',
    '    static const const char* k[67] = {',
    '        "Aklys", "Atlatl and javelin", "Arrow", "Axe, Battle",',
    '        "Axe, Hand or Throwing", "Bardiche", "Bec de Corbin",',
    '        "Bill-Guisarme", "Blowgun and needle", "Bo Stick",',
    '        "Caltrop", "Club", "Dagger", "Dart", "Fauchard",',
    '        "Fauchard-Fork", "Flail, Footman\'s", "Flail, Horseman\'s",',
    '        "Military Fork", "Garrot", "Glaive", "Glaive-Guisarme",',
    '        "Guisarme", "Guisarme-Voulge", "Halberd", "Harpoon",',
    '        "Hammer, Lucern", "Hammer", "Hook Fauchard", "Javelin",',
    '        "Jo Stick", "Knife", "Lance (light horse)",',
    '        "Lance (medium horse)", "Lance (heavy horse)", "Lasso",',
    '        "Mace, Footman\'s", "Mace, Horseman\'s", "Man Catcher",',
    '        "Morning Star", "Partisan", "Pick, Footman\'s",',
    '        "Pick, Horseman\'s", "Pike, Awl",',
    '        "Quarrel (or Bolt), light", "Quarrel (or Bolt), heavy",',
    '        "Ranseur", "Sap", "Scimitar", "Sling Bullet",',
    '        "Sling Stone", "Spear", "Spetum", "Spiked Buckler",',
    '        "Staff, Quarter", "Staff Sling Bullet",',
    '        "Staff Sling Stone", "Sword, Bastard", "Sword, Broad",',
    '        "Sword, Falchion", "Sword, Khopesh", "Long Sword",',
    '        "Sword, Short", "Sword, Two-handed", "Trident", "Voulge",',
    '        "Whip",',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// True when the row is a UA-new weapon.',
    'inline bool uawtIsNewWeapon(int i) {',
    '    static const bool k[67] = {',
    '        1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,',
    '        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1,',
    '        0, 0, 1, 1, 0, 0, 0, 0, 0, 1,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// The R189 chart row (rules/',
    '// weapontables.h) each PHB row verifies',
    '// against; -1 = a new weapon.',
    'inline int uawtPhbSeamIndex(int i) {',
    '    static const int k[67] = {',
    '        -1, -1, 0, 1, 2, 3, 4, 5, -1, 6, -1, 7, 8, 9, 10, 11, 12,',
    '        13, 14, -1, 15, 16, 17, 18, 19, -1, 20, 21, -1, 22, 23,',
    '        -1, 24, 25, 26, -1, 27, 28, -1, 29, 30, 31, 32, 33, 34,',
    '        35, 36, -1, 37, 38, 39, 40, 41, -1, 42, -1, -1, 43, 44,',
    '        -1, -1, 45, 46, 47, 48, 49, -1,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// The approximate weight in gold pieces;',
    '// -1 = the weight cell is OCR-lost.',
    'inline int uawtWeightMin(int i) {',
    '    static const int k[67] = {',
    '        35, -1, 2, 75, 50, 125, 100, 150, 15, 15, 2, 30, 10, 5,',
    '        60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, -1, 150,',
    '        50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80,',
    '        60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 40, 50, 35, 50, 5, 4,',
    '        100, 75, -1, 75, 60, 35, 250, 50, 125, 25,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// The weight maximum - equal to the',
    '// minimum except the printed ranges',
    '// (caltrop, spear, whip).',
    'inline int uawtWeightMax(int i) {',
    '    static const int k[67] = {',
    '        35, -1, 2, 75, 50, 125, 100, 150, 15, 15, 4, 30, 10, 5,',
    '        60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, -1, 150,',
    '        50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80,',
    '        60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 60, 50, 35, 50, 5, 4,',
    '        100, 75, -1, 75, 60, 35, 250, 50, 125, 35,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// The damage vs. size S or M: the',
    '// minimum; -1 = OCR-lost.',
    'inline int uawtDamageSMMin(int i) {',
    '    static const int k[67] = {',
    '        1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1,',
    '        1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, -1, 2, 1,',
    '        1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1,',
    '        2, 2, 2, 2, 1, 1, 1, 2, 2, 1,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// The damage vs. size S or M: the',
    '// maximum.',
    'inline int uawtDamageSMMax(int i) {',
    '    static const int k[67] = {',
    '        6, 6, 6, 8, 6, 8, 8, 8, 1, 6, 1, 6, 4, 3, 6, 8, 7, 5, 8,',
    '        4, 6, 8, 8, 8, 10, 8, 8, 5, 4, 6, 6, 3, 6, 7, 9, -1, 7, 6,',
    '        2, 8, 6, 7, 5, 6, 4, 5, 8, 2, 8, 5, 4, 6, 7, 4, 6, 8, 8,',
    '        8, 8, 7, 8, 8, 6, 10, 7, 8, 2,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// The damage vs. size L: the minimum;',
    '// -1 = OCR-lost.',
    'inline int uawtDamageLMin(int i) {',
    '    static const int k[67] = {',
    '        1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2,',
    '        1, 1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, -1, 1, 1,',
    '        1, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 3, 2,',
    '        2, 2, 2, 1, 1, 1, 3, 3, 2, 1,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '// The damage vs. size L: the maximum.',
    'inline int uawtDamageLMax(int i) {',
    '    static const int k[67] = {',
    '        3, 6, 6, 8, 4, 12, 6, 10, 1, 3, 2, 3, 3, 2, 8, 10, 8, 5,',
    '        8, 8, 10, 12, 8, 8, 12, 12, 6, 4, 4, 6, 4, 2, 8, 12, 18,',
    '        -1, 6, 4, 2, 7, 7, 8, 4, 12, 4, 7, 8, 2, 8, 7, 4, 8, 12,',
    '        3, 6, 9, 8, 16, 7, 8, 6, 12, 8, 18, 12, 8, 1,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 66) i = 66;',
    '    return k[i];',
    '}',
    '',
    '}   // namespace rules',    ])
    clean(HDR, 78)
    wr(UW, HDR)
    applied.append('uaweapontable.h: the pins')
s = rd(UW)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 12, 'b inline count'
assert s.count('R337') == 1, 'b round tag'
assert s.count('uawtPhbSeamIndex') == 2, \
    'b seam'
assert s.count('uawtRowCount') == 1, 'b count fn'
assert 'cavMoneyStationCount' not in s, \
    'b no r336 ref'
assert 'acrobatFallingChanceKnown' not in s, \
    'b no r335 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the weights and the
# lasso damage are OCR-lost) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R337: the fragment-verified' in s:
    already.append('gap report: the note')
else:
    FIRST_OLD = ('- [ ] **Weapons, Weight and'
                ' Damage by')
    TAIL_OLD = '      Type** (p. 26).'
    assert s.count(FIRST_OLD) == 1, 'c first'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R337: the fragment-verified',
    '      cells pinned (rules/uaweapontable.h)',
    '      - the 67-row roster, all 50 PHB',
    '      rows cell-verified against the',
    '      R189 seam (the hyphen-loss',
    '      pattern proven row by row),',
    '      the 17 new-weapon rows pinned',
    '      where printed or',
    '      pattern-decoded, the merged',
    '      rows split by seam; the',
    '      atlatl/harpoon/falchion',
    '      weights, the lasso damage',
    '      and the unattributable',
    '      garbled quarrel row are',
    '      OCR-lost - stays open',
    '      pending the PDF read.',    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
FLIP = ('- [ ] **Weapons, Weight and'
        ' Damage by')
assert s.count('R337: the fragment-verified') \
    == 1, 'c note'
assert s.count(FLIP) == 1, 'c item stays open'
assert s.count('CLOSED R336') == 1, 'c r336 kept'
assert s.count('CLOSED R335') == 1, 'c r335 kept'
assert s.count('R334: the fragment-verified') \
    == 1, 'c r334 note kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R337 UA weight and damage pin audit' in s:
    already.append('regtest.cpp: the R337 audit')
else:
    INC_ANCH = ('#include "rules/cavmoney.h"'
                '  // R336: the UA cavalier money')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/uaweapontable.h"'
    '  // R337: the UA weight and damage',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R337: the UA weight and damage pin audit ----',
    '    // The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) -',
    '    // the 67-row roster: all 50 PHB rows verified cell for',
    '    // cell against the R189 chart seam (the hyphen-loss',
    '    // pattern proven row by row), the 17 new-weapon rows',
    '    // pinned where printed or pattern-decoded; the holes',
    '    // (the atlatl/harpoon/falchion weights, the lasso',
    '    // damage) and the attributed rows (military fork,',
    '    // glaive-guisarme, the picks, the sap) are documented',
    '    // in the header. The item stays open pending the PDF.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the counts and the roster anchors',
    '        {',
    '            if (uawtRowCount() != 67) ++bad;',
    '            if (uawtSeamVerifiedCount() != 50) ++bad;',
    '            if (uawtNewWeaponCount() != 17) ++bad;',
    '            if (strcmp(uawtName(0), "Aklys") != 0)',
    '                ++bad;',
    '            if (strcmp(uawtName(66), "Whip") != 0)',
    '                ++bad;',
    '            if (strcmp(uawtName(30), "Jo Stick")',
    '                != 0) ++bad;',
    '            if (strcmp(uawtName(47), "Sap") != 0)',
    '                ++bad;',
    '            if (strcmp(uawtName(53),',
    '                "Spiked Buckler") != 0) ++bad;',
    '        }',
    '        // U2: the full 50-row R189 seam verification',
    '        {',
    '            for (int i = 0; i < uawtRowCount();',
    '                 ++i) {',
    '                int j = uawtPhbSeamIndex(i);',
    '                if (j < 0) continue;',
    '                if (uawtWeightMin(i)',
    '                    != weaponChartWeight(j)) ++bad;',
    '                if (uawtDamageSMMin(i)',
    '                    != weaponChartDamageSMMin(j))',
    '                    ++bad;',
    '                if (uawtDamageSMMax(i)',
    '                    != weaponChartDamageSMMax(j))',
    '                    ++bad;',
    '                if (uawtDamageLMin(i)',
    '                    != weaponChartDamageLMin(j))',
    '                    ++bad;',
    '                if (uawtDamageLMax(i)',
    '                    != weaponChartDamageLMax(j))',
    '                    ++bad;',
    '            }',
    '        }',
    '        // U3: the new-weapon rows, the pinned cells',
    '        {',
    '            // the blowgun: flat 1/1 as printed',
    '            if (strcmp(uawtName(8),',
    '                "Blowgun and needle") != 0) ++bad;',
    '            if (uawtWeightMin(8) != 15) ++bad;',
    '            if (uawtDamageSMMin(8) != 1) ++bad;',
    '            if (uawtDamageSMMax(8) != 1) ++bad;',
    '            if (uawtDamageLMin(8) != 1) ++bad;',
    '            if (uawtDamageLMax(8) != 1) ++bad;',
    '            // the garrot: 1 / 1-4 / 1-8',
    '            if (uawtWeightMin(19) != 1) ++bad;',
    '            if (uawtDamageSMMin(19) != 1) ++bad;',
    '            if (uawtDamageSMMax(19) != 4) ++bad;',
    '            if (uawtDamageLMin(19) != 1) ++bad;',
    '            if (uawtDamageLMax(19) != 8) ++bad;',
    '            // the hook fauchard: 80 / 1-4 / 1-4',
    '            if (uawtWeightMin(28) != 80) ++bad;',
    '            if (uawtDamageSMMin(28) != 1) ++bad;',
    '            if (uawtDamageSMMax(28) != 4) ++bad;',
    '            if (uawtDamageLMin(28) != 1) ++bad;',
    '            if (uawtDamageLMax(28) != 4) ++bad;',
    '            // the knife: 6 / 1-3 / 1-2',
    '            if (uawtWeightMin(31) != 6) ++bad;',
    '            if (uawtDamageSMMax(31) != 3) ++bad;',
    '            if (uawtDamageLMin(31) != 1) ++bad;',
    '            if (uawtDamageLMax(31) != 2) ++bad;',
    '            // the man catcher: 80 / 1-2 / 1-2',
    '            if (uawtWeightMin(38) != 80) ++bad;',
    '            if (uawtDamageSMMax(38) != 2) ++bad;',
    '            if (uawtDamageLMax(38) != 2) ++bad;',
    '            // the sap (attributed): 10 / 1-2 / 1-2',
    '            if (uawtWeightMin(47) != 10) ++bad;',
    '            if (uawtDamageSMMin(47) != 1) ++bad;',
    '            if (uawtDamageSMMax(47) != 2) ++bad;',
    '            if (uawtDamageLMin(47) != 1) ++bad;',
    '            if (uawtDamageLMax(47) != 2) ++bad;',
    '            // the spiked buckler: 35 / 1-4 / 1-3',
    '            if (uawtWeightMin(53) != 35) ++bad;',
    '            if (uawtDamageSMMax(53) != 4) ++bad;',
    '            if (uawtDamageLMin(53) != 1) ++bad;',
    '            if (uawtDamageLMax(53) != 3) ++bad;',
    '            // the staff sling bullet: 5 / 2-8 / 3-9',
    '            if (uawtWeightMin(55) != 5) ++bad;',
    '            if (uawtDamageSMMin(55) != 2) ++bad;',
    '            if (uawtDamageSMMax(55) != 8) ++bad;',
    '            if (uawtDamageLMin(55) != 3) ++bad;',
    '            if (uawtDamageLMax(55) != 9) ++bad;',
    '            // the staff sling stone: 4 / 1-8 / 2-8',
    '            if (uawtWeightMin(56) != 4) ++bad;',
    '            if (uawtDamageSMMin(56) != 1) ++bad;',
    '            if (uawtDamageSMMax(56) != 8) ++bad;',
    '            if (uawtDamageLMin(56) != 2) ++bad;',
    '            if (uawtDamageLMax(56) != 8) ++bad;',
    '            // the khopesh: 75 / 2-8 / 1-6',
    '            if (uawtWeightMin(60) != 75) ++bad;',
    '            if (uawtDamageSMMin(60) != 2) ++bad;',
    '            if (uawtDamageSMMax(60) != 8) ++bad;',
    '            if (uawtDamageLMin(60) != 1) ++bad;',
    '            if (uawtDamageLMax(60) != 6) ++bad;',
    '            // the whip: 25-35 / 1-2 / flat 1',
    '            if (uawtWeightMin(66) != 25) ++bad;',
    '            if (uawtWeightMax(66) != 35) ++bad;',
    '            if (uawtDamageSMMax(66) != 2) ++bad;',
    '            if (uawtDamageLMin(66) != 1) ++bad;',
    '            if (uawtDamageLMax(66) != 1) ++bad;',
    '        }',
    '        // U4: the aklys, the atlatl and the holes',
    '        {',
    '            // the aklys: 35 / 1-6 / 1-3 (the L',
    '            // cell rides the continuation row)',
    '            if (uawtWeightMin(0) != 35) ++bad;',
    '            if (uawtDamageSMMin(0) != 1) ++bad;',
    '            if (uawtDamageSMMax(0) != 6) ++bad;',
    '            if (uawtDamageLMin(0) != 1) ++bad;',
    '            if (uawtDamageLMax(0) != 3) ++bad;',
    '            // the atlatl: weight hole,',
    '            // damage 1-6 / 1-6',
    '            if (uawtWeightMin(1) != -1) ++bad;',
    '            if (uawtDamageSMMin(1) != 1) ++bad;',
    '            if (uawtDamageSMMax(1) != 6) ++bad;',
    '            if (uawtDamageLMin(1) != 1) ++bad;',
    '            if (uawtDamageLMax(1) != 6) ++bad;',
    '            // the harpoon weight and the',
    '            // falchion weight: holes',
    '            if (uawtWeightMin(25) != -1) ++bad;',
    '            if (uawtWeightMin(59) != -1) ++bad;',
    '            // the lasso: weight 20 pinned,',
    '            // the damage cells are holes',
    '            if (uawtWeightMin(35) != 20) ++bad;',
    '            if (uawtDamageSMMin(35) != -1) ++bad;',
    '            if (uawtDamageSMMax(35) != -1) ++bad;',
    '            if (uawtDamageLMin(35) != -1) ++bad;',
    '            if (uawtDamageLMax(35) != -1) ++bad;',
    '        }',
    '        // U5: the weight ranges and the',
    '        // new-weapon flag agreement',
    '        {',
    '            // caltrop 2-4, spear 40-60,',
    '            // whip 25-35; every other row',
    '            // has max == min',
    '            static const int rng[3][3] = {',
    '                {10, 2, 4},',
    '                {51, 40, 60},',
    '                {66, 25, 35}',
    '            };',
    '            for (int r = 0; r < 3; ++r) {',
    '                int i = rng[r][0];',
    '                if (uawtWeightMin(i) != rng[r][1])',
    '                    ++bad;',
    '                if (uawtWeightMax(i) != rng[r][2])',
    '                    ++bad;',
    '            }',
    '            for (int i = 0; i < 67; ++i) {',
    '                if (uawtWeightMin(i) < 0) continue;',
    '                bool ranged = i == 10 || i == 51',
    '                    || i == 66;',
    '                if (uawtWeightMax(i)',
    '                    != uawtWeightMin(i) && !ranged)',
    '                    ++bad;',
    '            }',
    '            int newc = 0;',
    '            for (int i = 0; i < 67; ++i) {',
    '                if (uawtIsNewWeapon(i)) ++newc;',
    '                if (uawtIsNewWeapon(i)',
    '                    != (uawtPhbSeamIndex(i) < 0))',
    '                    ++bad;',
    '            }',
    '            if (newc != 17) ++bad;',
    '        }',
    '        // U6: the R189 seam census',
    '        {',
    '            if (weaponChartRowCount() != 50) ++bad;',
    '        }',
    '        printf("R337 UA weight and damage pin audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R337 audit')
s = rd(RT)
assert s.count(
    'R337 UA weight and damage pin audit: bad ') \
    == 1, 'd audit line'
assert s.count('audit: bad ') == 264, 'd census 264'
assert s.count(
    'R336 cavalier money pin audit: bad ') \
    == 1, 'd r336 kept'
assert s.count(
    'R335 thief-acrobat pin audit: bad ') \
    == 1, 'd r335 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count(
    '#include "rules/uaweapontable.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R337 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R337 note: the UA weight and damage')
print('pin round - the 67-row roster, all')
print('50 PHB rows cell-verified against the')
print('R189 seam, the 17 new-weapon rows')
print('pinned where printed or')
print('pattern-decoded (the item stays open')
print('pending the PDF); the census 263 -> 264')
print('commit: R337: the UA weight and damage')
print('pin round (census 264)')

