#!/usr/bin/env python3
# R339: the UA WEAPON PROFICIENCY
# TABLE (p. 26) pin round - the
# 14-row roster, seven rows
# cell-verified against the R297 PHB
# seam, the UA-new rows (cavalier,
# barbarian, acrobat, bard), the
# attributed fragment rows
# (illusionist, thief, assassin), the
# paladin and ranger deviations
# pinned as printed. The cavalier
# penalty, the paladin and assassin
# initials and the facing-page notes
# are OCR holes - noted pending the
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

# ---- (a) the seed: the R338 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R338 landed 2026-10-11: commit',
    '  1775600, census 265, the UA',
    '  missile data pin round',
    '  (rules/uamissile.h): the 24-row',
    '  roster, the range column decoded',
    '  as the long range in tens of feet',
    '  (PHB-seam verified), the',
    '  AC-adjustment ladders minus-loss',
    '  decoded (the pattern seam-proven',
    '  against the R145 rows); the',
    '  R337b duplicate-const fix rode.',
    '  GREEN on the first paste. No new',
    '  lessons.',
])
s = rd(SD)
if 'R338 landed 2026-10-11' in s:
    already.append('seed: the R338 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R338 record')
s = rd(SD)
assert s.count('R338 landed 2026-10-11') == 1, \
    'a entry'
assert s.count('R337 landed 2026-10-11') == 1, \
    'a r337 kept'
assert s.count('R336 landed 2026-10-11') == 1, \
    'a r336 kept'
assert s.count('## Knowledge maintenance') == 1, \
    'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uaprof.h ----
UP = 'rules/uaprof.h'
if os.path.exists(UP) and 'R339' in rd(UP):
    already.append('uaprof.h: the pins')
else:
    HDR = NL.join([
        '// ===========================================================================',
        '// Adnd1 - rules/uaprof.h',
        '// The UA WEAPON PROFICIENCY TABLE (p. 26) pins (R339).',
        '//',
        '// Pin-era pattern (R322): pinned data only - no engine site exists.',
        '// The R297 PHB pin (rules/weaponprof.h) is the decode seam.',
        '//',
        '// JUDGMENTs:',
        '//   - the roster: 14 rows in the printed order. Seven rows match',
        '//     the PHB rows cell for cell (cleric, druid, fighter,',
        '//     magic-user, illusionist, thief, monk) - every readable cell',
        '//     seam-verifies against R297, proving the OCR patterns row by',
        '//     row. The UA-new rows: cavalier, barbarian, acrobat, bard',
        '//     (no PHB row).',
        '//   - the minus-loss decode: unsigned penalty magnitudes print',
        '//     where the PHB prints -2/-3 (the fighter 2, the monk 3) -',
        '//     the R297 magnitude convention, sign carried by the',
        '//     convention not the print. The barbarian prints -1 signed.',
        '//   - the cadence cells print "1/4 levels" style; the cavalier',
        '//     and paladin rows print "112 levels" - the slash-loss',
        '//     decode to 1/2 levels (the barbarian and monk rows print',
        '//     "1/2 levels" clean, proving the cadence in this table).',
        '//   - the cavalier initial prints "3°" - the degree sign is an',
        '//     OCR artifact on the digit; 3 pins.',
        '//   - attributed rows: the post-MAGIC-USER nameless row (1, -5,',
        '//     1/6) attributes to the Illusionist - the only roster',
        '//     class otherwise absent in its printed place, cells matching',
        '//     the R297 illusionist row. The "EF" row (2, -3, 1/4)',
        '//     attributes to the Thief - the garbled name fragment, cells',
        '//     matching the R297 thief row. The post-Acrobat fragment',
        '//     row attributes to the Assassin - the only roster class',
        "//     otherwise absent, sitting exactly at the PHB table's",
        '//     assassin position. The fragment splits to FIVE cells',
        '//     (one misaligned extra empty); the added column anchors',
        '//     right (1/4 levels), and the 2 reads as the PENALTY cell -',
        '//     the PHB-consistent read (an initial-cell read would',
        '//     deviate from every other PHB-matching row in this table);',
        '//     the initial prints lost, a hole.',
        '//   - deviations from the PHB (pinned as printed, noted): the',
        '//     ranger initial prints 8 where the PHB row reads 3 (the',
        '//     R297 seam) - pinned as printed, the echo-of-the-barbarian',
        '//     row doubt noted pending the PDF. The paladin penalty',
        '//     prints 3 where the PHB reads 2, and the paladin cadence',
        '//     prints 1/2 where the PHB reads 1/3 - the UA paladin rides',
        "//     the cavalier group's values, pinned as printed.",
        '//',
        '// OCR holes (the item closes; these stay on the PDF ledger): the',
        '// cavalier penalty cell (prints empty), the paladin initial cell',
        '// (prints empty - the stacked-group reading would share the',
        "// cavalier's 3, not pinned), the assassin initial cell (prints",
        '// empty), and the ENTIRE facing-page notes (the print points at',
        '// them: "(Notes to this table on facing page)" - the notes',
        '// themselves are OCR-lost).',
        '// ===========================================================================',
        '',
        '#pragma once',
        '',
        'namespace rules {',
        '',
        '// The row count (14 = the 10 PHB classes plus the cavalier,',
        '// barbarian, acrobat and bard).',
        'inline int uapfRowCount()',
        '    { return 14; }',
        '',
        '// The row name (printed; the three attributed rows carry the',
        '// attribution JUDGMENT - uapfNameIsAttributed flags them).',
        'inline const char* uapfName(int i) {',
        '    static const char* const k[14] = {',
        '        "Cavalier", "Paladin", "Cleric", "Druid",',
        '        "Fighter", "Barbarian", "Ranger", "Magic-User",',
        '        "Illusionist", "Thief", "Acrobat", "Assassin",',
        '        "Monk", "Bard"',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 13) i = 13;',
        '    return k[i];',
        '}',
        '',
        '// The R297 ProfRow each row seam-verifies against; -1 = a',
        '// UA-new row (no PHB row). The acrobat seam-closes to the',
        "// thief row's values by print (not by PHB membership).",
        'inline int uapfPhbSeamRow(int i) {',
        '    // cavalier, paladin, cleric, druid, fighter,',
        '    // barbarian, ranger, magic-user, illusionist,',
        '    // thief, acrobat, assassin, monk, bard',
        '    static const int k[14] = {',
        '        -1, 3, 0, 1, 2, -1, 4, 5, 6, 7, 7, 8, 9, -1',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 13) i = 13;',
        '    return k[i];',
        '}',
        '',
        '// True when the row name is an attribution (the printed name',
        '// is OCR-lost or garbled; the data assigns the row).',
        'inline bool uapfNameIsAttributed(int i) {',
        '    // illusionist, thief, assassin',
        '    static const bool k[14] = {',
        '        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 13) i = 13;',
        '    return k[i];',
        '}',
        '',
        '// The initial number of weapons; -1 = the cell prints empty',
        '// (a hole): the paladin and the assassin.',
        'inline int uapfInitialSlots(int i) {',
        '    static const int k[14] = {',
        '        3, -1, 2, 2, 4, 8, 8, 1, 1, 2, 2, -1, 1, 5',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 13) i = 13;',
        '    return k[i];',
        '}',
        '',
        '// The non-proficiency to-hit penalty MAGNITUDE (the R297',
        '// convention; the adjustment is negative). The cavalier cell',
        '// prints empty - a hole, -1.',
        'inline int uapfNonProfPenalty(int i) {',
        '    static const int k[14] = {',
        '        -1, 3, 3, 4, 2, 1, 2, 5, 5, 3, 3, 2, 3, 2',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 13) i = 13;',
        '    return k[i];',
        '}',
        '',
        '// The added-proficiency levels-per-slot (one new proficiency',
        '// per N levels above the 1st, the R297 note).',
        'inline int uapfAddedCadence(int i) {',
        '    static const int k[14] = {',
        '        2, 2, 4, 5, 3, 2, 3, 6, 6, 4, 4, 4, 2, 4',
        '    };',
        '    if (i < 0) i = 0;',
        '    if (i > 13) i = 13;',
        '    return k[i];',
        '}',
        '',
        "// The facing-page notes are wholly OCR-lost (the table's own",
        '// caption points at them); their existence pins, their',
        '// content does not.',
        'inline bool uapfFacingPageNotesLost()',
        '    { return true; }',
        '',
        '}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(UP, HDR)
    applied.append('uaprof.h: the pins')
s = rd(UP)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 8, 'b inline count'
assert s.count('R339') == 1, 'b round tag'
assert s.count('uapfInitialSlots(int') == 1, \
    'b initial fn'
assert s.count('uapfNonProfPenalty(int') == 1, \
    'b penalty fn'
assert 'uamtAcAdjustment' not in s, \
    'b no r338 ref'
assert 'cavMoneyStationCount' not in s, \
    'b no r336 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the item
# CLOSES - the holes noted pending the
# PDF ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R339' in s:
    already.append('gap report: the close')
else:
    FIRST_OLD = ('- [ ] **The Weapon'
                ' Proficiency Table**')
    FIRST_NEW = ('- [x] **The Weapon'
                ' Proficiency Table**')
    TAIL_OLD = '      layer.'
    assert s.count(FIRST_OLD) == 1, 'c first'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - CLOSED R339: the pin round',
        '        (rules/uaprof.h) - the 14-row',
        '        roster, seven rows cell-verified',
        '        against the R297 PHB seam, the',
        '        UA-new rows (cavalier, barbarian,',
        '        acrobat, bard), the attributed',
        '        fragment rows (illusionist, thief,',
        '        assassin), the paladin and ranger',
        '        deviations pinned as printed. The',
        '        cavalier penalty, the paladin and',
        '        assassin initials and the',
        '        facing-page notes are OCR-lost -',
        '        noted pending the PDF read.',
    ])
    clean(NOTE, 57)
    s = s.replace(FIRST_OLD, FIRST_NEW)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the close')
s = rd(GP)
FLIP = ('- [x] **The Weapon'
        ' Proficiency Table**')
OPEN = ('- [ ] **The Weapon'
        ' Proficiency Table**')
assert s.count('CLOSED R339') == 1, 'c closed'
assert s.count(FLIP) == 1, 'c flipped'
assert s.count(OPEN) == 0, 'c no open copy'
assert s.count('R338: the fragment-verified') \
    == 1, 'c r338 note kept'
assert s.count('R337: the fragment-verified') \
    == 1, 'c r337 note kept'
assert s.count('CLOSED R336') == 1, 'c r336 kept'
assert s.count('CLOSED R335') == 1, 'c r335 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R339 UA proficiency pin audit' in s:
    already.append('regtest.cpp: the R339 audit')
else:
    INC_ANCH = ('#include "rules/uamissile.h"'
                '  // R338: the UA hurled and'
                ' missile data')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/uaprof.h"'
    '  // R339: the UA weapon proficiency',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
        '    // ---- R339: the UA proficiency pin audit ----',
        '    // The UA WEAPON PROFICIENCY TABLE (p. 26) - the 14-row',
        '    // roster: seven rows match the PHB rows cell for cell',
        '    // (the R297 seam, verified live), the UA-new rows',
        '    // (cavalier, barbarian, acrobat, bard), the attributed',
        '    // fragment rows (illusionist, thief, assassin -',
        '    // documented JUDGMENTs), the paladin/ranger deviations',
        '    // from the PHB pinned as printed; the holes (cavalier',
        '    // penalty, paladin and assassin initials, the',
        '    // facing-page notes) documented. The item closes.',
        '    {',
        '        using namespace rules;',
        '        int bad = 0;',
        '        // U1: the counts and the roster',
        '        {',
        '            if (uapfRowCount() != 14) ++bad;',
        '            if (strcmp(uapfName(0), "Cavalier") != 0)',
        '                ++bad;',
        '            if (strcmp(uapfName(5), "Barbarian")',
        '                != 0) ++bad;',
        '            if (strcmp(uapfName(10), "Acrobat")',
        '                != 0) ++bad;',
        '            if (strcmp(uapfName(13), "Bard") != 0)',
        '                ++bad;',
        '            if (!uapfNameIsAttributed(8)) ++bad;',
        '            if (!uapfNameIsAttributed(9)) ++bad;',
        '            if (!uapfNameIsAttributed(11)) ++bad;',
        '            if (uapfNameIsAttributed(10)) ++bad;',
        '            int attr = 0;',
        '            for (int i = 0; i < 14; ++i)',
        '                if (uapfNameIsAttributed(i)) ++attr;',
        '            if (attr != 3) ++bad;',
        '        }',
        '        // U2: the initial slots',
        '        {',
        '            static const int k[14] = {',
        '                3, -1, 2, 2, 4, 8, 8, 1,',
        '                1, 2, 2, -1, 1, 5',
        '            };',
        '            for (int i = 0; i < 14; ++i)',
        '                if (uapfInitialSlots(i) != k[i])',
        '                    ++bad;',
        '            // the holes: the paladin, the assassin',
        '            if (uapfInitialSlots(1) != -1) ++bad;',
        '            if (uapfInitialSlots(11) != -1) ++bad;',
        '        }',
        '        // U3: the penalties (magnitudes)',
        '        {',
        '            static const int k[14] = {',
        '                -1, 3, 3, 4, 2, 1, 2, 5,',
        '                5, 3, 3, 2, 3, 2',
        '            };',
        '            for (int i = 0; i < 14; ++i)',
        '                if (uapfNonProfPenalty(i) != k[i])',
        '                    ++bad;',
        '            // the hole: the cavalier',
        '            if (uapfNonProfPenalty(0) != -1) ++bad;',
        '            // the deviations from the PHB (pinned',
        '            // as printed): the paladin 3',
        '            if (uapfNonProfPenalty(1) != 3) ++bad;',
        '        }',
        '        // U4: the cadences',
        '        {',
        '            static const int k[14] = {',
        '                2, 2, 4, 5, 3, 2, 3, 6,',
        '                6, 4, 4, 4, 2, 4',
        '            };',
        '            for (int i = 0; i < 14; ++i)',
        '                if (uapfAddedCadence(i) != k[i])',
        '                    ++bad;',
        '            // the slash-loss prints: the cavalier',
        '            // and paladin 112 = 1/2 levels',
        '            if (uapfAddedCadence(0) != 2) ++bad;',
        '            if (uapfAddedCadence(1) != 2) ++bad;',
        '        }',
        '        // U5: the R297 seam - the seven rows that',
        '        // match the PHB cell for cell',
        '        {',
        '            static const int rows[7] = {',
        '                2, 3, 4, 7, 8, 9, 12',
        '            };',
        '            for (int r = 0; r < 7; ++r) {',
        '                int i = rows[r];',
        '                int j = uapfPhbSeamRow(i);',
        '                if (j < 0) { ++bad; continue; }',
        '                if (uapfInitialSlots(i)',
        '                    != wpfInitialSlots(j)) ++bad;',
        '                if (uapfNonProfPenalty(i)',
        '                    != wpfNonProfPenalty(j)) ++bad;',
        '                if (uapfAddedCadence(i)',
        '                    != wpfAddedCadence(j)) ++bad;',
        '            }',
        '            // the seam map itself',
        '            if (uapfPhbSeamRow(0) != -1) ++bad;',
        '            if (uapfPhbSeamRow(1) != PROF_PALADIN)',
        '                ++bad;',
        '            if (uapfPhbSeamRow(6) != PROF_RANGER)',
        '                ++bad;',
        '            if (uapfPhbSeamRow(11) != PROF_ASSASSIN)',
        '                ++bad;',
        '            if (uapfPhbSeamRow(13) != -1) ++bad;',
        '        }',
        '        // U6: the deviations pinned as printed',
        '        {',
        '            // the ranger initial 8 where the PHB',
        '            // (R297) reads 3 - the echo doubt noted',
        '            if (uapfInitialSlots(6) != 8) ++bad;',
        '            if (wpfInitialSlots(PROF_RANGER) != 3)',
        '                ++bad;',
        '            // the paladin: UA penalty 3, cadence',
        "            // 1/2 - the cavalier group's values",
        '            if (uapfNonProfPenalty(1)',
        '                != wpfNonProfPenalty(',
        '                    PROF_PALADIN) + 1) ++bad;',
        '            if (uapfAddedCadence(1)',
        '                != wpfAddedCadence(',
        '                    PROF_PALADIN) - 1) ++bad;',
        '            // the assassin seam cells: penalty',
        '            // and cadence match the PHB row',
        '            if (uapfNonProfPenalty(11)',
        '                != wpfNonProfPenalty(',
        '                    PROF_ASSASSIN)) ++bad;',
        '            if (uapfAddedCadence(11)',
        '                != wpfAddedCadence(',
        '                    PROF_ASSASSIN)) ++bad;',
        '        }',
        '        // U7: the slots arithmetic rides the R297',
        '        // convention (one per cadence above 1st)',
        '        {',
        '            // the UA cavalier: 3 at 1st, 4 at 3rd,',
        '            // 5 at 5th (cadence 2)',
        '            if (uapfInitialSlots(0)',
        '                    + (1 - 1) / uapfAddedCadence(0)',
        '                != 3) ++bad;',
        '            if (uapfInitialSlots(0)',
        '                    + (3 - 1) / uapfAddedCadence(0)',
        '                != 4) ++bad;',
        '            // the UA barbarian: 8 at 1st, 9 at 3rd',
        '            if (uapfInitialSlots(5)',
        '                    + (3 - 1) / uapfAddedCadence(5)',
        '                != 9) ++bad;',
        '        }',
        '        // U8: the hole ledger',
        '        {',
        '            if (!uapfFacingPageNotesLost()) ++bad;',
        '        }',
        '        printf("R339 UA proficiency pin audit: bad %d\\n", bad);',
        '        if (bad) return 1;',
        '    }',
    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R339 audit')
s = rd(RT)
assert s.count(
    'R339 UA proficiency pin audit: bad ') \
    == 1, 'd audit line'
assert s.count('audit: bad ') == 266, 'd census 266'
assert s.count(
    'R338 UA missile data pin audit: bad ') \
    == 1, 'd r338 kept'
assert s.count(
    'R337 UA weight and damage pin audit: bad ') \
    == 1, 'd r337 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count('#include "rules/uaprof.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R339 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R339 note: the UA weapon proficiency')
print('pin round - the 14-row roster, seven')
print('rows cell-verified against the R297')
print('PHB seam, the UA-new rows (cavalier,')
print('barbarian, acrobat, bard), the attributed')
print('fragment rows (illusionist, thief,')
print('assassin), the paladin and ranger')
print('deviations pinned as printed; the')
print('cavalier penalty, the paladin and')
print('assassin initials and the facing-page')
print('notes are OCR holes - noted pending')
print('the PDF; the item closes; the census')
print('265 -> 266')
print('commit: R339: the UA proficiency pin')
print('round (census 266)')

