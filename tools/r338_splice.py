#!/usr/bin/env python3
# R338: the UA HURLED WEAPON AND
# MISSILE TYPES table (p. 28) pin
# round - the 24-row roster, the
# range column (the long range in
# tens of feet, PHB-seam verified),
# the AC-adjustment ladders
# minus-loss decoded (the pattern
# seam-proven against the R145
# rows); the rate column, the S/M
# ranges and the tail AC cells are
# OCR holes - the item stays open
# pending the PDF. Also: the R337b
# duplicate-const fix in
# rules/uaweapontable.h. Pin-era
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

# ---- (a) the seed: the R337 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R337 landed 2026-10-11: commit',
    '  924e41d, census 264, the UA',
    '  weight and damage pin round',
    '  (rules/uaweapontable.h): the',
    '  67-row roster, all 50 PHB rows',
    '  cell-verified against the R189',
    '  seam (the hyphen-loss pattern',
    '  proven row by row), the 17',
    '  new-weapon rows pinned where',
    '  printed or pattern-decoded.',
    '  GREEN on the first paste.',
    '  Lesson: the array-template',
    '  generator emitted a duplicate',
    '  const on the char* name row (a',
    '  benign -Wduplicate-decl-specifier',
    '  warning); fixed in R338.',    ])
s = rd(SD)
if 'R337 landed 2026-10-11' in s:
    already.append('seed: the R337 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R337 record')
s = rd(SD)
assert s.count('R337 landed 2026-10-11') == 1, \
    'a entry'
assert s.count('R336 landed 2026-10-11') == 1, \
    'a r336 kept'
assert s.count('R335 landed 2026-10-11') == 1, \
    'a r335 kept'
assert s.count('## Knowledge maintenance') == 1, \
    'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uamissile.h ----
UM = 'rules/uamissile.h'
if os.path.exists(UM) and 'R338' in rd(UM):
    already.append('uamissile.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/uamissile.h',
    '// The UA HURLED WEAPON AND MISSILE TYPES, GENERAL DATA, AND',
    '// "TO HIT" ADJUSTMENTS table (p. 28) pins (R338).',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists.',
    '//',
    '// JUDGMENTs:',
    '//   - the range column: the extract prints one number per row',
    '//     (two leading cells OCR-lost). The number reads as the',
    '//     LONG range in tens of feet - PHB-seam-verified: the short',
    '//     bow 15 (150\'), the long bow 21 (210\'), the light crossbow',
    '//     18 (180\'), the sling stone 16 (160\'), the javelin 6 (60\'),',
    '//     the hand crossbow 6 (60\'), the dagger and hand axe 3 (30\').',
    '//     The composite long bow prints 21 - the long bow\'s value;',
    '//     the PHB composite prints 24 - pinned as printed, the',
    '//     doubt noted pending the PDF.',
    '//   - the minus-loss decode: unsigned magnitude tokens between',
    '//     signed neighbors of a monotone ladder read as negative',
    '//     (the aklys -8,7,-6... reads -8,-7,-6...). The pattern is',
    '//     seam-proven on the R145 engine rows: the bow short prints',
    '//     <7,6,5,-4,-1,0,0 and the PHB row reads -7,-6,-5,-4,-1,0,0;',
    '//     the bow long prints 2,-1,-1,0 (PHB -2,-1,-1,0); the light',
    '//     crossbow -3,2,-2,-1,0,0 (PHB -3,-2,-2,-1,0,0); the sling',
    '//     bullet -3,-3,2 (PHB -3,-3,-2).',
    '//   - attributions: the garbled "Bow," row attributes to the',
    '//     long bow (range 21, the AC cells match the PHB row); the',
    '//     composite rows differ from it, so the match is unique.',
    '//     The lasso\'s "#7" reads as +7 - the only sign consistent',
    '//     with the printed descending +9,+8 ladder. The dart\'s',
    '//     "=7" and trailing \'"1\' read as -7 and -1 (the row\'s',
    '//     ladder matches the dagger\'s exactly). The bow short\'s',
    '//     "<7" seam-closes to -7. The staff sling rows read their',
    '//     merged leading cells as the rate garbage and the range 9',
    '//     (both rows print 9).',
    '//   - the AC columns are AC 0 through 6, the adjustment applied',
    '//     at SHORT range (the printed note); medium range adjusts',
    '//     -2, long -5 - the R116 convention, seam-cross-checked.',
    '//   - the dagger and dart rows read -7 through -1 - the UA',
    '//     hurled rows, NOT the PHB p.38 melee rows (the R145',
    '//     dagger row is the melee chart; the hurled chart carries',
    '//     its own row).',
    '//',
    '// OCR holes (the item stays open pending the PDF read): the',
    '// ENTIRE rate-of-fire column (every row prints empty or',
    '// garbage - "ODN", "||"), the two leading range cells of every',
    '// row (the S/M ranges), the aklys and dart range cells, and',
    '// the tail AC cells of the short rows (the hole sentinel is',
    '// 100): the club AC2, the hammer AC0/AC5, the atlatl AC5/AC6',
    '// (the merged "0 4"), the hand crossbow AC6 (the "0 i Wf"),',
    '// the heavy crossbow AC1 (the printed dash), the light',
    '// crossbow AC6 (the PHB row reads +1 - noted, not pinned),',
    '// the sling stone AC0 (the "=r") and the bow long AC4-AC6.',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The row count (24 = the 16 standard weapons plus 8 new).',
    'inline int uamtRowCount()',
    '    { return 24; }',
    '',
    'inline int uamtNewWeaponCount()',
    '    { return 8; }',
    '',
    'inline int uamtStandardWeaponCount()',
    '    { return 16; }',
    '',
    '// The row name (printed, or the attribution judgment -',
    '// the "AKlys" caps slip normalized, the garbled "Bow,"',
    '// row attributed to the long bow).',
    'inline const char* uamtName(int i) {',
    '    static const char* const k[24] = {',
    '        "Aklys (hurled)", "Atlatl (javelin)", "Axe, Hand",',
    '        "Blowgun Needle", "Bow, Composite, Long",',
    '        "Bow, Composite, Short", "Bow, Long", "Bow, Short",',
    '        "Club", "Crossbow, Hand", "Crossbow, Heavy",',
    '        "Crossbow, Light", "Dagger", "Dart", "Hammer", "Harpoon",',
    '        "Javelin", "Knife", "Lasso", "Sling (bullet)",',
    '        "Sling (stone)", "Spear", "Staff Sling (bullet)",',
    '        "Staff Sling (stone)",',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    return k[i];',
    '}',
    '',
    '// True when the row is a UA-new weapon (the',
    '// aklys, atlatl, blowgun, harpoon, knife,',
    '// lasso and the two staff sling rows).',
    'inline bool uamtIsNewWeapon(int i) {',
    '    static const bool k[24] = {',
    '        1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1,',
    '        0, 0, 0, 1, 1,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    return k[i];',
    '}',
    '',
    '// The printed range number - the long range in',
    '// tens of feet (the JUDGMENT above); -1 = the',
    '// cell is OCR-lost (the aklys, the dart).',
    'inline int uamtRangePrinted(int i) {',
    '    static const int k[24] = {',
    '        -1, 9, 3, 3, 21, 18, 21, 15, 3, 6, 24, 18, 3, -1, 3, 3, 6,',
    '        3, 3, 20, 16, 3, 9, 9,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    return k[i];',
    '}',
    '',
    '// The AC adjustment by AC 0..6, applied at',
    '// short range; 100 = the cell is OCR-lost.',
    'inline int uamtAcAdjustment(int i, int ac) {',
    '    static const int k[24][7] = {',
    '        { -8, -7, -6, -5, -4, -3, -2 },',
    '        { -6, -5, -4, -3, -2, 100, 100 },',
    '        { -6, -5, -4, -3, -2, -1, -1 },',
    '        { -14, -12, -10, -8, -6, -4, -2 },',
    '        { -4, -3, -2, -1, 0, 0, 1 },',
    '        { -4, -4, -3, -3, -1, 0, 1 },',
    '        { -2, -1, -1, 0, 100, 100, 100 },',
    '        { -7, -6, -5, -4, -1, 0, 0 },',
    '        { -9, -8, 100, -5, -3, -2, -1 },',
    '        { -6, -4, -2, -1, 0, 0, 100 },',
    '        { -2, 100, -1, 0, 1, 2, 3 },',
    '        { -3, -2, -2, -1, 0, 0, 100 },',
    '        { -7, -6, -5, -4, -3, -2, -1 },',
    '        { -7, -6, -5, -4, -3, -2, -1 },',
    '        { 100, -3, -2, -1, 0, 100, 0 },',
    '        { -6, -5, -4, 100, 100, 100, 100 },',
    '        { -7, -6, -5, 100, 100, 100, 100 },',
    '        { -8, -7, -6, 100, 100, 100, 100 },',
    '        { 9, 8, 7, 100, 100, 100, 100 },',
    '        { -3, -3, -2, 100, 100, 100, 100 },',
    '        { 100, -6, -5, 100, 100, 100, 100 },',
    '        { -4, -4, -3, 100, 100, 100, 100 },',
    '        { -5, -4, -3, 100, 100, 100, 100 },',
    '        { -6, -5, -4, 100, 100, 100, 100 },',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    if (ac < 0) ac = 0;',
    '    if (ac > 6) ac = 6;',
    '    return k[i][ac];',
    '}',
    '',
    '// ---- the printed notes (p. 28) ----',
    '// Rate of fire is based on the turn (for table-top',
    '// miniatures) or the melee round. The AC adjustment',
    '// applies at short range; the range labels are S =',
    '// Short, M = Medium, L = Long.',
    'inline bool uamtRateOfFireTurnOrRound()',
    '    { return true; }',
    '',
    'inline bool uamtAcAdjustmentAtShortRange()',
    '    { return true; }',
    '',
    '// The medium-range adjustment: -2 (the R116 seam).',
    'inline int uamtMediumRangeAdjustment()',
    '    { return -2; }',
    '',
    '// The long-range adjustment: -5 (the R116 seam).',
    'inline int uamtLongRangeAdjustment()',
    '    { return -5; }',
    '',
    '}   // namespace rules',    ])
    clean(HDR, 78)
    wr(UM, HDR)
    applied.append('uamissile.h: the pins')
s = rd(UM)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 11, 'b inline count'
assert s.count('R338') == 1, 'b round tag'
assert s.count('uamtAcAdjustment(int') == 1, \
    'b ac fn'
assert s.count('uamtRangePrinted') == 1, 'b range'
assert 'uawtPhbSeamIndex' not in s, \
    'b no r337 ref'
assert 'cavMoneyStationCount' not in s, \
    'b no r336 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the rate column and
# the S/M ranges are OCR-lost) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R338: the fragment-verified' in s:
    already.append('gap report: the note')
else:
    FIRST_OLD = ('- [ ] **Weapons, hurled and'
                ' missile,')
    TAIL_OLD = '      general data** (p. 28).'
    assert s.count(FIRST_OLD) == 1, 'c first'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R338: the fragment-verified',
    '      cells pinned (rules/uamissile.h)',
    '      - the 24-row roster, the range',
    '      column (the long range in tens',
    '      of feet, PHB-seam verified),',
    '      the AC-adjustment ladders',
    '      minus-loss decoded (the',
    '      pattern seam-proven on the',
    '      bow, crossbow and sling rows',
    '      against the R145 rows); the',
    '      rate column, the S/M range',
    '      cells and the tail AC cells',
    '      of the short rows are',
    '      OCR-lost - stays open',
    '      pending the PDF read.',    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
FLIP = ('- [ ] **Weapons, hurled and'
        ' missile,')
assert s.count('R338: the fragment-verified') \
    == 1, 'c note'
assert s.count(FLIP) == 1, 'c item stays open'
assert s.count('R337: the fragment-verified') \
    == 1, 'c r337 note kept'
assert s.count('CLOSED R336') == 1, 'c r336 kept'
assert s.count('R334: the fragment-verified') \
    == 1, 'c r334 note kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R338 UA missile data pin audit' in s:
    already.append('regtest.cpp: the R338 audit')
else:
    INC_ANCH = ('#include "rules/uaweapontable.h"'
                '  // R337: the UA weight and damage')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/uamissile.h"'
    '  // R338: the UA hurled and missile data',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R338: the UA missile data pin audit ----',
    '    // The UA HURLED WEAPON AND MISSILE TYPES table',
    '    // (p. 28) - the 24-row roster: the range column',
    '    // (the long range in tens of feet, PHB-seam',
    '    // verified), the AC-adjustment ladders minus-loss',
    '    // decoded (the pattern seam-proven on the bow,',
    '    // crossbow and sling rows against the R145',
    '    // engine rows); the rate column and the S/M',
    '    // ranges are OCR-lost - the item stays open',
    '    // pending the PDF. The R116 seam cross-checked.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the counts and the roster',
    '        {',
    '            if (uamtRowCount() != 24) ++bad;',
    '            if (uamtNewWeaponCount() != 8) ++bad;',
    '            if (uamtStandardWeaponCount() != 16)',
    '                ++bad;',
    '            if (strcmp(uamtName(0),',
    '                "Aklys (hurled)") != 0) ++bad;',
    '            if (strcmp(uamtName(1),',
    '                "Atlatl (javelin)") != 0) ++bad;',
    '            if (strcmp(uamtName(6), "Bow, Long")',
    '                != 0) ++bad;',
    '            if (strcmp(uamtName(23),',
    '                "Staff Sling (stone)") != 0) ++bad;',
    '            if (!uamtIsNewWeapon(0)) ++bad;',
    '            if (!uamtIsNewWeapon(18)) ++bad;',
    '            if (uamtIsNewWeapon(2)) ++bad;',
    '            if (uamtIsNewWeapon(11)) ++bad;',
    '            int newc = 0;',
    '            for (int i = 0; i < 24; ++i)',
    '                if (uamtIsNewWeapon(i)) ++newc;',
    '            if (newc != 8) ++bad;',
    '        }',
    '        // U2: the range column (the long range in',
    '        // tens of feet; the PHB seams)',
    '        {',
    '            // short bow 150, long bow 210,',
    '            // light crossbow 180, sling stone 160,',
    '            // javelin 60, hand crossbow 60',
    '            if (uamtRangePrinted(7) != 15) ++bad;',
    '            if (uamtRangePrinted(6) != 21) ++bad;',
    '            if (uamtRangePrinted(11) != 18) ++bad;',
    '            if (uamtRangePrinted(20) != 16) ++bad;',
    '            if (uamtRangePrinted(16) != 6) ++bad;',
    '            if (uamtRangePrinted(9) != 6) ++bad;',
    '            // the composites, the heavy crossbow',
    '            if (uamtRangePrinted(4) != 21) ++bad;',
    '            if (uamtRangePrinted(5) != 18) ++bad;',
    '            if (uamtRangePrinted(10) != 24) ++bad;',
    '            // the hurled threes, the staff slings',
    '            if (uamtRangePrinted(2) != 3) ++bad;',
    '            if (uamtRangePrinted(12) != 3) ++bad;',
    '            if (uamtRangePrinted(22) != 9) ++bad;',
    '            if (uamtRangePrinted(23) != 9) ++bad;',
    '            if (uamtRangePrinted(19) != 20) ++bad;',
    '            // the holes: the aklys, the dart',
    '            if (uamtRangePrinted(0) != -1) ++bad;',
    '            if (uamtRangePrinted(13) != -1) ++bad;',
    '        }',
    '        // U3: the AC ladders, the pinned cells',
    '        {',
    '            // the aklys: -8 through -2',
    '            for (int ac = 0; ac < 7; ++ac)',
    '                if (uamtAcAdjustment(0, ac)',
    '                    != -8 + ac) ++bad;',
    '            // the blowgun: the even ladder -14..-2',
    '            for (int ac = 0; ac < 7; ++ac)',
    '                if (uamtAcAdjustment(3, ac)',
    '                    != -14 + 2 * ac) ++bad;',
    '            // the dagger and the dart: -7..-1',
    '            for (int ac = 0; ac < 7; ++ac) {',
    '                if (uamtAcAdjustment(12, ac)',
    '                    != -7 + ac) ++bad;',
    '                if (uamtAcAdjustment(13, ac)',
    '                    != -7 + ac) ++bad;',
    '            }',
    '            // the composites (the signed rows)',
    '            if (uamtAcAdjustment(5, 0) != -4) ++bad;',
    '            if (uamtAcAdjustment(5, 1) != -4) ++bad;',
    '            if (uamtAcAdjustment(5, 2) != -3) ++bad;',
    '            if (uamtAcAdjustment(5, 3) != -3) ++bad;',
    '            if (uamtAcAdjustment(5, 4) != -1) ++bad;',
    '            if (uamtAcAdjustment(5, 6) != 1) ++bad;',
    '            if (uamtAcAdjustment(4, 2) != -2) ++bad;',
    '            if (uamtAcAdjustment(4, 6) != 1) ++bad;',
    '            // the lasso: +9, +8, +7',
    '            if (uamtAcAdjustment(18, 0) != 9) ++bad;',
    '            if (uamtAcAdjustment(18, 1) != 8) ++bad;',
    '            if (uamtAcAdjustment(18, 2) != 7) ++bad;',
    '            // the heavy crossbow: -2, hole, -1..+3',
    '            if (uamtAcAdjustment(10, 0) != -2)',
    '                ++bad;',
    '            if (uamtAcAdjustment(10, 2) != -1) ++bad;',
    '            if (uamtAcAdjustment(10, 6) != 3) ++bad;',
    '            // the spear, the staff slings',
    '            if (uamtAcAdjustment(21, 0) != -4) ++bad;',
    '            if (uamtAcAdjustment(21, 1) != -4) ++bad;',
    '            if (uamtAcAdjustment(21, 2) != -3) ++bad;',
    '            if (uamtAcAdjustment(22, 0) != -5) ++bad;',
    '            if (uamtAcAdjustment(23, 0) != -6) ++bad;',
    '            // the hand crossbow, the club,',
    '            // the hammer, the atlatl',
    '            if (uamtAcAdjustment(9, 0) != -6) ++bad;',
    '            if (uamtAcAdjustment(9, 2) != -2) ++bad;',
    '            if (uamtAcAdjustment(8, 0) != -9) ++bad;',
    '            if (uamtAcAdjustment(8, 6) != -1) ++bad;',
    '            if (uamtAcAdjustment(14, 1) != -3) ++bad;',
    '            if (uamtAcAdjustment(1, 0) != -6) ++bad;',
    '            if (uamtAcAdjustment(1, 4) != -2) ++bad;',
    '        }',
    '        // U4: the OCR holes (the 100 sentinel)',
    '        {',
    '            if (uamtAcAdjustment(0, 0) == 100) ++bad;',
    '            if (uamtAcAdjustment(8, 2) != 100) ++bad;',
    '            if (uamtAcAdjustment(14, 0) != 100) ++bad;',
    '            if (uamtAcAdjustment(14, 5) != 100) ++bad;',
    '            if (uamtAcAdjustment(1, 5) != 100) ++bad;',
    '            if (uamtAcAdjustment(1, 6) != 100) ++bad;',
    '            if (uamtAcAdjustment(9, 6) != 100) ++bad;',
    '            if (uamtAcAdjustment(10, 1) != 100) ++bad;',
    '            if (uamtAcAdjustment(11, 6) != 100) ++bad;',
    '            if (uamtAcAdjustment(20, 0) != 100) ++bad;',
    '            if (uamtAcAdjustment(6, 4) != 100) ++bad;',
    '            // the hole census: 24 rows x 7 = 168',
    '            // cells; count the non-holes',
    '            int pinned = 0;',
    '            for (int i = 0; i < 24; ++i)',
    '                for (int ac = 0; ac < 7; ++ac)',
    '                    if (uamtAcAdjustment(i, ac)',
    '                        != 100) ++pinned;',
    '            if (pinned != 120) ++bad;',
    '        }',
    '        // U5: the prose notes and the R116 seam',
    '        {',
    '            if (!uamtRateOfFireTurnOrRound()) ++bad;',
    '            if (!uamtAcAdjustmentAtShortRange())',
    '                ++bad;',
    '            if (uamtMediumRangeAdjustment() != -2)',
    '                ++bad;',
    '            if (uamtLongRangeAdjustment() != -5)',
    '                ++bad;',
    '            // the R116 engine seam: -2 at medium,',
    '            // -5 at long (the sling\'s 40\' short)',
    '            if (missileRangeMod(60, 40) != -2) ++bad;',
    '            if (missileRangeMod(100, 40) != -5)',
    '                ++bad;',
    '        }',
    '        // U6: the R145 engine seam - the minus-loss',
    '        // decode proven on the standard rows',
    '        {',
    '            // the bow short: the PHB row, printed',
    '            // <7,6,5,-4,-1,0,0 in the extract',
    '            for (int ac = 0; ac < 7; ++ac)',
    '                if (uamtAcAdjustment(7, ac)',
    '                    != items::weapon(',
    '                        items::WPN_SHORT_BOW)',
    '                        .acAdj[ac]) ++bad;',
    '            // the bow long: the first four cells',
    '            for (int ac = 0; ac < 4; ++ac)',
    '                if (uamtAcAdjustment(6, ac)',
    '                    != items::weapon(',
    '                        items::WPN_LONG_BOW)',
    '                        .acAdj[ac]) ++bad;',
    '            // the light crossbow: six of six',
    '            // printed cells',
    '            for (int ac = 0; ac < 6; ++ac)',
    '                if (uamtAcAdjustment(11, ac)',
    '                    != items::weapon(',
    '                        items::WPN_CROSSBOW_LIGHT)',
    '                        .acAdj[ac]) ++bad;',
    '            // the sling bullet: three of three',
    '            for (int ac = 0; ac < 3; ++ac)',
    '                if (uamtAcAdjustment(19, ac)',
    '                    != items::weapon(',
    '                        items::WPN_SLING)',
    '                        .acAdj[ac]) ++bad;',
    '        }',
    '        // U7: the R337 seam - the new-weapon',
    '        // roster agreement',
    '        {',
    '            if (strcmp(uawtName(0), "Aklys")',
    '                != 0) ++bad;',
    '            if (!uawtIsNewWeapon(0)) ++bad;',
    '            if (strcmp(uawtName(53),',
    '                "Spiked Buckler") != 0) ++bad;',
    '        }',
    '        printf("R338 UA missile data pin audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R338 audit')
s = rd(RT)
assert s.count(
    'R338 UA missile data pin audit: bad ') \
    == 1, 'd audit line'
assert s.count('audit: bad ') == 265, 'd census 265'
assert s.count(
    'R337 UA weight and damage pin audit: bad ') \
    == 1, 'd r337 kept'
assert s.count(
    'R336 cavalier money pin audit: bad ') \
    == 1, 'd r336 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count('#include "rules/uamissile.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- (e) the R337b fix: the duplicate
# const in rules/uaweapontable.h ----
UW = 'rules/uaweapontable.h'
s = rd(UW)
if 'static const char* const k[67]' in s:
    already.append('uaweapontable.h: the fix')
else:
    BAD = 'static const const char* k[67] = {'
    GOOD = ('static const char* const k[67]'
            ' = {')
    assert s.count(BAD) == 1, 'e bad form'
    s = s.replace(BAD, GOOD)
    wr(UW, s)
    applied.append('uaweapontable.h: the fix')
s = rd(UW)
assert s.count('static const const char*') == 0, \
    'e fixed'
assert s.count(
    'static const char* const k[67]') == 1, \
    'e good form'
assert len(applied) + len(already) == 5, 'e count'

# ---- the summary ----
print('R338 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R338 note: the UA hurled and missile')
print('pin round - the 24-row roster, the')
print('range column (the long range in tens')
print('of feet, PHB-seam verified), the')
print('AC-adjustment ladders minus-loss')
print('decoded (the item stays open pending')
print('the PDF); the R337b duplicate-const')
print('fix rides; the census 264 -> 265')
print('commit: R338: the UA missile data')
print('pin round (census 265)')

