#!/usr/bin/env python3
# R270 splice: the III.E misc magic explanation prose
# part 14 pins - Incense of Obsession through the
# Fochlucan Bandore, part2 lines 630-684 (DMG
# p.141-142) - the slice pinning the kMisc3 rows
# 24-26 (the (C) mark rides the Incense of Obsession,
# the triple asterisk the Ioun Stones per stone, the
# quadruple asterisk the Instrument of the Bards per
# level of instrument). ONE page header inside the slice
# (674, the TREASURE page) falls between the bandore
# paragraph and its song list. The ioun stone property
# table: the upload mangles rows 3, 5 and 12 - the
# 15-row table restored from the 1eonline.info
# compilation (the R175 precedent).
# 4 patches, marker-based idempotence, assert after
# every patch. ZERO apostrophes and ZERO literal
# backslashes in the content below (the printf newline
# is built via BS = chr(92)).

import os
import re
import sys

HERE = os.path.abspath(os.path.dirname(sys.argv[0]))
ROOT = os.path.abspath(HERE + '/..')
NL = chr(10)
BS = chr(92)

applied = 0
already = 0

def rd(p):
    f = open(os.path.join(ROOT, p), encoding='utf-8')
    s = f.read()
    f.close()
    return s

def wr(p, s):
    f = open(os.path.join(ROOT, p), 'w', encoding='utf-8')
    f.write(s)
    f.close()

HDR = [
    '// ====================================================================',
    '// Adnd1 - rules/miscprose14.h',
    '// R270: the III.E misc magic explanation prose part 14',
    '// (DMG p.141-142) - Incense of Obsession through the',
    '// Fochlucan Bandore, part2 lines 630-684 (global =',
    '// 11065 + part2 line). ONE page header inside the slice',
    '// (674, the TREASURE page) falls between the bandore',
    '// paragraph and its song list (one seam, restored). The',
    '// ioun stone property table: the upload mangles rows 3,',
    '// 5 and 12 (the shape cells folded into the roll and',
    '// color cells, the missing space in 5pink) and wraps the',
    '// regeneration cell across rows - the 15-row table',
    '// restored from the 1eonline.info compilation (the R175',
    '// precedent).',
    '// 47 accessors: 41 scalars + 6 array walkers (the stone',
    '// property table), no name collisions with miscprose1.h',
    '// through miscprose13.h. The slice pins kMisc3 rows',
    '// 24-26: the (C) mark on the Incense of Obsession (row',
    '// 24), the triple asterisk on the Ioun Stones (row 25,',
    '// per stone), the quadruple asterisk on the Instrument of',
    '// the Bards (rows 73-78, per level of instrument). Pure',
    '// data + helpers, header-only (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpObsessionDurationHours() {',
    '    // the cleric remains obsessed until all spells',
    '    // are cast or 24 hours have elapsed',
    '    return 24;',
    '}',
    '',
    'inline int mmpObsessionPiecesMin() {',
    '    // there are 2-8 pieces of this incense normally',
    '    return 2;',
    '}',
    '',
    'inline int mmpObsessionPiecesMax() {',
    '    // the upper edge of the normal 2-8 pieces',
    '    return 8;',
    '}',
    '',
    'inline int mmpObsessionBurnHours() {',
    '    // each piece burns for 1 hour',
    '    return 1;',
    '}',
    '',
    'inline int mmpIounSortCount() {',
    '    // there are 14 sorts of useful ioun stones',
    '    return 14;',
    '}',
    '',
    'inline int mmpIounOwnerRadiusFeet() {',
    '    // the stones must be within 3 feet of their',
    '    // owner to be efficacious',
    '    return 3;',
    '}',
    '',
    'inline int mmpIounOrbitMinFeet() {',
    '    // the circling orbit starts at a 1 foot radius',
    '    return 1;',
    '}',
    '',
    'inline int mmpIounOrbitMaxFeet() {',
    '    // the circling orbit tops at a 3 foot radius',
    '    return 3;',
    '}',
    '',
    'inline int mmpIounFoundMin() {',
    '    // from 1-10 ioun stones will be found',
    '    return 1;',
    '}',
    '',
    'inline int mmpIounFoundMax() {',
    '    // the upper edge of the 1-10 found',
    '    return 10;',
    '}',
    '',
    'inline int mmpIounTableRowCount() {',
    '    // the property table has 15 rows',
    '    return 15;',
    '}',
    '',
    'inline int mmpIounDeadRowLo() {',
    '    // the dull gray dead band starts at roll 15',
    '    return 15;',
    '}',
    '',
    'inline int mmpIounDeadRowHi() {',
    '    // and ends at roll 20',
    '    return 20;',
    '}',
    '',
    'inline int mmpIounStatBonusPoints() {',
    '    // the six stat stones add 1 point to the score',
    '    return 1;',
    '}',
    '',
    'inline int mmpIounStatCap() {',
    '    // with an 18 maximum',
    '    return 18;',
    '}',
    '',
    'inline int mmpIounStatBonusRowCount() {',
    '    // six stones add to a stat score',
    '    return 6;',
    '}',
    '',
    'inline int mmpIounLevelGainLevels() {',
    '    // the pale green prism adds 1 level of',
    '    // experience',
    '    return 1;',
    '}',
    '',
    'inline int mmpIounRegenHpPerTurn() {',
    '    // the pearly white spindle regenerates 1 hit',
    '    // point of damage per turn',
    '    return 1;',
    '}',
    '',
    'inline int mmpIounPurpleStoreMin() {',
    '    // the vibrant purple prism stores 2-12 levels',
    '    return 2;',
    '}',
    '',
    'inline int mmpIounPurpleStoreMax() {',
    '    // the upper edge of the stored 2-12 levels',
    '    return 12;',
    '}',
    '',
    'inline int mmpIounRoseProtectionBonus() {',
    '    // the dusty rose prism gives +1 protection',
    '    return 1;',
    '}',
    '',
    'inline int mmpIounGrayPsionicBonus() {',
    '    // the dead gray stone adds 10 points to the',
    '    // psionic strength total',
    '    return 10;',
    '}',
    '',
    'inline int mmpIounGrayPsionicCap() {',
    '    // the psionic strength total caps at 50 points',
    '    return 50;',
    '}',
    '',
    'inline int mmpIounHpToDestroy() {',
    '    // the stones take 10 hit points of damage to',
    '    // destroy',
    '    return 10;',
    '}',
    '',
    'inline int mmpIounSaveBonus() {',
    '    // they save as if they were of hard metal, +3',
    '    return 3;',
    '}',
    '',
    'inline int mmpIounAttackAc() {',
    '    // exposed to attack they are treated as armor',
    '    // class -4 (the minus rides the comment)',
    '    return 4;',
    '}',
    '',
    'inline int mmpIounRowRollLo(int i) {',
    '    // the printed roll lower edges, rolls 1-14',
    '    // then the dead band; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 14) i = 14;',
    '    static const int t[15] = {',
    '        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '        11, 12, 13, 14, 15,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpIounRowRollHi(int i) {',
    '    // the printed roll upper edges, the dead band',
    '    // topping at 20; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 14) i = 14;',
    '    static const int t[15] = {',
    '        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '        11, 12, 13, 14, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpIounRowAddsStat(int i) {',
    '    // the rolls 1-6 stones add to a stat score;',
    '    // i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 14) i = 14;',
    '    static const int t[15] = {',
    '        1, 1, 1, 1, 1, 1, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpIounRowAbsorbMaxLevel(int i) {',
    '    // the roll 11 and 12 stones absorb spells up',
    '    // to the 4th and 8th level; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 14) i = 14;',
    '    static const int t[15] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        4, 8, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpIounRowBurnoutMin(int i) {',
    '    // the absorbed spell levels that burn a',
    '    // stone out, the lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 14) i = 14;',
    '    static const int t[15] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        10, 20, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpIounRowBurnoutMax(int i) {',
    '    // the absorbed spell levels that burn a',
    '    // stone out, the upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 14) i = 14;',
    '    static const int t[15] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        40, 80, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpBardInstrumentCount() {',
    '    // there are 7 magical instruments',
    '    return 7;',
    '}',
    '',
    'inline int mmpFochlucanStringCount() {',
    '    // the small, 3-stringed bandore',
    '    return 3;',
    '}',
    '',
    'inline int mmpFochlucanLowestFaeriePct() {',
    '    // a 1st level bard or a non-bard: a 50',
    '    // percent chance per round of playing to',
    '    // cast a faerie fire spell',
    '    return 50;',
    '}',
    '',
    'inline int mmpFochlucanLowestReversePct() {',
    '    // a 10 percent chance the musician is',
    '    // limned by the glow instead',
    '    return 10;',
    '}',
    '',
    'inline int mmpFochlucanFaerieBasePct() {',
    '    // a bard of Fochlucan or higher college',
    '    // casts the faerie fire at base 50 percent',
    '    return 50;',
    '}',
    '',
    'inline int mmpFochlucanReverseReductionPerLevelPct() {',
    '    // the reverse effect reduced by 1 percent',
    '    // per level above 1st',
    '    return 1;',
    '}',
    '',
    'inline int mmpFochlucanSongCount() {',
    '    // the bandore has 4 song properties when',
    '    // properly played',
    '    return 4;',
    '}',
    '',
    'inline int mmpFochlucanCharmBonusPct() {',
    '    // adds 10 percent to the bard charm',
    '    // percentage',
    '    return 10;',
    '}',
    '',
    'inline int mmpFochlucanEntanglePerDay() {',
    '    // casts an entangle spell once per day',
    '    return 1;',
    '}',
    '',
    'inline int mmpFochlucanShillelaghPerDay() {',
    '    // casts a shillelagh spell once per day',
    '    return 1;',
    '}',
    '',
    'inline int mmpFochlucanSpeakAnimalsPerDay() {',
    '    // enables the bard to speak with animals',
    '    // once per day',
    '    return 1;',
    '}',
    '',
    'inline int mmpFochlucanLowestSongWorkPct() {',
    '    // a 1st level bard attempts the powers: a',
    '    // 30 percent chance they work',
    '    return 30;',
    '}',
    '',
    'inline int mmpFochlucanLowestSongFailPct() {',
    '    // a 70 percent chance of the mishap',
    '    return 70;',
    '}',
    '',
    'inline int mmpFochlucanLowestFailDamageMin() {',
    '    // the mishap deals 2-8 hit points of damage',
    '    return 2;',
    '}',
    '',
    'inline int mmpFochlucanLowestFailDamageMax() {',
    '    // the upper edge of the 2-8 damage',
    '    return 8;',
    '}',
    '',
    '}  // namespace rules',
]

AUDIT = [
    '    // ---- R270: the III.E misc magic explanation',
    '    // prose part 14 ----',
    '    // Incense of Obsession through the Fochlucan',
    '    // Bandore, part2 lines 630-684 - the slice',
    '    // pinning the kMisc3 rows 24-26.',
    '    {',
    '        int bad = 0;',
    '        if (rules::mmpObsessionDurationHours() != 24 ||',
    '            rules::mmpObsessionPiecesMin() != 2 ||',
    '            rules::mmpObsessionPiecesMax() != 8 ||',
    '            rules::mmpObsessionBurnHours() != 1) ++bad;',
    '        if (rules::mmpIounSortCount() != 14 ||',
    '            rules::mmpIounOwnerRadiusFeet() != 3 ||',
    '            rules::mmpIounOrbitMinFeet() != 1 ||',
    '            rules::mmpIounOrbitMaxFeet() != 3 ||',
    '            rules::mmpIounFoundMin() != 1 ||',
    '            rules::mmpIounFoundMax() != 10) ++bad;',
    '        if (rules::mmpIounTableRowCount() != 15 ||',
    '            rules::mmpIounDeadRowLo() != 15 ||',
    '            rules::mmpIounDeadRowHi() != 20 ||',
    '            rules::mmpIounStatBonusPoints() != 1 ||',
    '            rules::mmpIounStatCap() != 18 ||',
    '            rules::mmpIounStatBonusRowCount() != 6) ++bad;',
    '        // the orbit tops out at the owner radius, the',
    '        // dead band rides the last table row',
    '        if (rules::mmpIounOrbitMaxFeet() !=',
    '            rules::mmpIounOwnerRadiusFeet() ||',
    '            rules::mmpIounDeadRowLo() !=',
    '            rules::mmpIounRowRollLo(14) ||',
    '            rules::mmpIounDeadRowHi() !=',
    '            rules::mmpIounRowRollHi(14)) ++bad;',
    '        if (rules::mmpIounLevelGainLevels() != 1 ||',
    '            rules::mmpIounRegenHpPerTurn() != 1 ||',
    '            rules::mmpIounPurpleStoreMin() != 2 ||',
    '            rules::mmpIounPurpleStoreMax() != 12 ||',
    '            rules::mmpIounRoseProtectionBonus() != 1) ++bad;',
    '        if (rules::mmpIounGrayPsionicBonus() != 10 ||',
    '            rules::mmpIounGrayPsionicCap() != 50 ||',
    '            rules::mmpIounHpToDestroy() != 10 ||',
    '            rules::mmpIounSaveBonus() != 3 ||',
    '            rules::mmpIounAttackAc() != 4) ++bad;',
    '        // the stone property table against static twins',
    '        static const int kRlo[15] = {',
    '            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '            11, 12, 13, 14, 15,',
    '        };',
    '        static const int kRhi[15] = {',
    '            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '            11, 12, 13, 14, 20,',
    '        };',
    '        static const int kStat[15] = {',
    '            1, 1, 1, 1, 1, 1, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0,',
    '        };',
    '        static const int kAbs[15] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            4, 8, 0, 0, 0,',
    '        };',
    '        static const int kBolo[15] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            10, 20, 0, 0, 0,',
    '        };',
    '        static const int kBohi[15] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            40, 80, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 15; ++i)',
    '            if (rules::mmpIounRowRollLo(i) != kRlo[i] ||',
    '                rules::mmpIounRowRollHi(i) != kRhi[i] ||',
    '                rules::mmpIounRowAddsStat(i) !=',
    '                kStat[i] ||',
    '                rules::mmpIounRowAbsorbMaxLevel(i) !=',
    '                kAbs[i] ||',
    '                rules::mmpIounRowBurnoutMin(i) !=',
    '                kBolo[i] ||',
    '                rules::mmpIounRowBurnoutMax(i) !=',
    '                kBohi[i]) ++bad;',
    '        // the property dice run 1-20 without gaps',
    '        for (int i = 0; i < 14; ++i)',
    '            if (rules::mmpIounRowRollLo(i + 1) !=',
    '                rules::mmpIounRowRollHi(i) +',
    '                1) ++bad;',
    '        if (rules::mmpIounRowRollLo(0) != 1 ||',
    '            rules::mmpIounRowRollHi(14) != 20) ++bad;',
    '        // the six stat stones are rolls 1-6',
    '        if (rules::mmpIounStatBonusRowCount() !=',
    '            rules::mmpIounRowRollHi(5)) ++bad;',
    '        if (rules::mmpBardInstrumentCount() != 7 ||',
    '            rules::mmpFochlucanLowestFaeriePct() != 50 ||',
    '            rules::mmpFochlucanLowestReversePct() !=',
    '            10) ++bad;',
    '        // the qualified base equals the lowest chance,',
    '        // the reverse fades 1 percent per level',
    '        if (rules::mmpFochlucanFaerieBasePct() !=',
    '            rules::mmpFochlucanLowestFaeriePct() ||',
    '            rules::mmpFochlucanReverseReductionPerLevelPct()',
    '            != 1) ++bad;',
    '        if (rules::mmpFochlucanStringCount() != 3 ||',
    '            rules::mmpFochlucanSongCount() != 4 ||',
    '            rules::mmpFochlucanCharmBonusPct() != 10 ||',
    '            rules::mmpFochlucanEntanglePerDay() != 1 ||',
    '            rules::mmpFochlucanShillelaghPerDay() != 1 ||',
    '            rules::mmpFochlucanSpeakAnimalsPerDay() !=',
    '            1) ++bad;',
    '        if (rules::mmpFochlucanLowestSongWorkPct() != 30 ||',
    '            rules::mmpFochlucanLowestSongFailPct() != 70 ||',
    '            rules::mmpFochlucanLowestFailDamageMin() != 2 ||',
    '            rules::mmpFochlucanLowestFailDamageMax() !=',
    '            8) ++bad;',
    '        // the 1st level attempt splits 30 and 70',
    '        if (rules::mmpFochlucanLowestSongWorkPct() +',
    '            rules::mmpFochlucanLowestSongFailPct() !=',
    '            100) ++bad;',
    '        // the kMisc3 rows this slice pins: 24-26, the',
    '        // (C) mark on row 24, the triple asterisk on',
    '        // row 25, the quadruple asterisk on row 26',
    '        static const int kLo[3] = {',
    '            71, 72, 73,',
    '        };',
    '        static const int kHi[3] = {',
    '            71, 72, 78,',
    '        };',
    '        static const int kCm[3] = {',
    '            1, 0, 0,',
    '        };',
    '        static const int kFm[3] = {',
    '            0, 0, 0,',
    '        };',
    '        static const int kTm[3] = {',
    '            0, 0, 0,',
    '        };',
    '        static const int kSt[3] = {',
    '            0, 3, 4,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::m3RowLo(24 + i) != kLo[i] ||',
    '                rules::m3RowHi(24 + i) != kHi[i] ||',
    '                rules::m3StarCount(24 + i) != kSt[i]) ++bad;',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::m3UsableByCleric(24 + i) != kCm[i] ||',
    '                rules::m3UsableByFighter(24 + i) !=',
    '                kFm[i] ||',
    '                rules::m3UsableByThief(24 + i) != kTm[i] ||',
    '                rules::m3IsPerFacetValued(24 + i)) ++bad;',
    '        // the per-stone and per-level asterisk bases',
    '        if (rules::m3IounPerStoneXp() != 300 ||',
    '            rules::m3IounPerStoneGp() != 5000 ||',
    '            rules::m3InstrumentBaseXp() != 1000 ||',
    '            rules::m3InstrumentBaseGp() != 5000) ++bad;',
    '        printf("R270 misc magic prose part 14 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]

GAP = [
    'R270 landed the III.E misc',
    'magic explanation prose part',
    '14 (part2 lines 630-684;',
    'global = 11065 + part2 line),',
    'Incense of Obsession through',
    'the Fochlucan Bandore - pinning',
    'the kMisc3 rows 24-26: the (C)',
    'mark on the Incense of Obsession',
    '(row 24), the triple asterisk on',
    'the Ioun Stones (row 25, per',
    'stone), the quadruple asterisk',
    'on the Instrument of the Bards',
    '(rows 73-78, per level of',
    'instrument). ONE page header',
    'inside the slice (674, the',
    'TREASURE page) falls between the',
    'bandore paragraph and its song',
    'list - restored. The ioun stone',
    'table: the upload mangles rows',
    '3, 5 and 12 (the shape cells',
    'folded into the roll and color',
    'cells, the missing space in',
    '5pink) and wraps the',
    'regeneration cell across rows -',
    'the 15-row table restored from',
    'the 1eonline.info compilation',
    '(the R175 precedent). The',
    'items: Incense of Obsession',
    '(resembles the meditation',
    'incense; the cleric stays',
    'obsessed until all spells are',
    'cast or 24 hours pass; 2-8',
    'pieces, each burning 1 hour),',
    'Ioun Stones (14 sorts; within 3',
    'feet of the owner, orbit 1-3',
    'feet; 1-10 found; the 15-row',
    'property table: six stat stones',
    'at +1 point to an 18 maximum,',
    'the pale green prism +1 level,',
    'the clear and iridescent',
    'spindles sustain without food',
    'and water or air, the pearly',
    'white regenerates 1 hp per',
    'turn, the pale lavender absorbs',
    'to the 4th level and burns out',
    'at 10-40 absorbed levels, the',
    'lavender and green to the 8th',
    'at 20-80, the vibrant purple',
    'stores 2-12 levels, the dusty',
    'rose gives +1 protection, the',
    'dull gray 15-20 band is dead',
    'and adds 10 psionic points to a',
    '50 maximum; attacked as armor',
    'class -4 (the sign rides the',
    'comment), 10 hp to destroy,',
    'saves as hard metal +3),',
    'Instrument of the Bards (7',
    'instruments, bard college',
    'gated), Fochlucan Bandore (3',
    'strings; a 1st level bard or a',
    'non-bard: 50 percent per round',
    'to cast faerie fire, 10 percent',
    'the musician is limned; a',
    'qualified bard at base 50',
    'percent, the reverse reduced 1',
    'percent per level above 1st;',
    '4 songs: +10 percent charm,',
    'entangle, shillelagh and speak',
    'with animals once per day each;',
    'a 1st level bard: 30 percent',
    'works, else 70 percent for 2-8',
    'hp damage). 47 accessors: 41',
    'scalars + 6 walkers (the stone',
    'property table), no name',
    'collisions parts 1-13. New R270',
    'battery audit; census 188.',
    'Next: part 15 - Mac-Fuirmidh',
    'Cittern onward in part2 from',
    'line 686 (global 11751; the',
    'doss lute, canooth and the',
    'remaining instruments follow;',
    'kMisc3 row 26 continues).',
]

# ---- the splice self-asserts ----
HTEXT = NL.join(HDR)
defs = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(]', HTEXT)
assert len(defs) == 47, 'accessor count is not 47'
assert len(set(defs)) == 47, 'accessor names not unique'
scal = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(][)]', HTEXT)
walk = [d for d in defs if d not in scal]
assert len(scal) == 41, 'scalar count is not 41'
assert len(walk) == 6, 'walker count is not 6'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(mmp[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for p in range(1, 14):
    pp = os.path.join(ROOT, 'rules/miscprose%d.h' % p)
    if os.path.exists(pp):
        pt = open(pp, encoding='utf-8').read()
        for n in defs:
            assert n not in pt, 'name collision with part %d' % p
for grp in (HDR, AUDIT, GAP):
    for el in grp:
        if isinstance(el, str):
            assert chr(39) not in el, 'apostrophe in content'
            probe = el.replace(chr(92) + 'n', '')
            assert chr(92) not in probe, 'backslash in content'
            assert NL not in el, 'list element spans lines'
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert HDR[-1] == '}  // namespace rules', 'header does not close'
assert ATEXT.count('R270 misc magic prose part 14 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'

# ---- patch 1: create rules/miscprose14.h ----
p = 'rules/miscprose14.h'
if os.path.exists(os.path.join(ROOT, p)):
    assert rd(p) == HTEXT, 'miscprose14.h exists but differs'
    already += 1
else:
    wr(p, HTEXT)
    applied += 1
assert rd(p) == HTEXT, 'patch 1 failed'

# ---- patch 2: the regtest include ----
p = 'regtest.cpp'
s = rd(p)
inc = '#include "rules/miscprose14.h"  // R270: the III.E misc magic explanation prose part 14 pins'
if inc in s:
    already += 1
else:
    anchor = '#include "rules/miscprose13.h"  // R269: the III.E misc magic explanation prose part 13 pins'
    assert s.count(anchor) == 1, 'include anchor not unique'
    s = s.replace(anchor, anchor + NL + inc, 1)
    wr(p, s)
    applied += 1
assert inc in rd(p), 'patch 2 failed'
assert rd(p).count('#include "rules/miscprose14.h"') == 1, 'patch 2 doubled'

# ---- patch 3: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R270: the III.E misc magic explanation'
if mark in s:
    already += 1
else:
    anchor = '    // ---- R227: the wis mental save wiring audit ----'
    assert s.count(anchor) == 1, 'audit anchor not unique'
    s = s.replace(anchor, ATEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 3 failed'
assert rd(p).count(mark) == 1, 'patch 3 doubled'

# ---- patch 4: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R270 landed the III.E misc'
if mark in s:
    already += 1
else:
    anchor = 'rows 24+).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'rows 24+).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 4 failed'
assert rd(p).count(mark) == 1, 'patch 4 doubled'

print('R270 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R270 note: 4 patches; the III.E misc magic')
print('explanation prose part 14 - Incense of')
print('Obsession through the Fochlucan Bandore,')
print('part2 lines 630-684; census 188.')
print('commit: R270: the III.E misc magic explanation prose part 14 pinned - Incense of Obsession through the Fochlucan Bandore in part2 lines 630-684 (census 188)')

