// ====================================================================
// Adnd1 - rules/miscprose14.h
// R270: the III.E misc magic explanation prose part 14
// (DMG p.141-142) - Incense of Obsession through the
// Fochlucan Bandore, part2 lines 630-684 (global =
// 11065 + part2 line). ONE page header inside the slice
// (674, the TREASURE page) falls between the bandore
// paragraph and its song list (one seam, restored). The
// ioun stone property table: the upload mangles rows 3,
// 5 and 12 (the shape cells folded into the roll and
// color cells, the missing space in 5pink) and wraps the
// regeneration cell across rows - the 15-row table
// restored from the 1eonline.info compilation (the R175
// precedent).
// 47 accessors: 41 scalars + 6 array walkers (the stone
// property table), no name collisions with miscprose1.h
// through miscprose13.h. The slice pins kMisc3 rows
// 24-26: the (C) mark on the Incense of Obsession (row
// 24), the triple asterisk on the Ioun Stones (row 25,
// per stone), the quadruple asterisk on the Instrument of
// the Bards (rows 73-78, per level of instrument). Pure
// data + helpers, header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpObsessionDurationHours() {
    // the cleric remains obsessed until all spells
    // are cast or 24 hours have elapsed
    return 24;
}

inline int mmpObsessionPiecesMin() {
    // there are 2-8 pieces of this incense normally
    return 2;
}

inline int mmpObsessionPiecesMax() {
    // the upper edge of the normal 2-8 pieces
    return 8;
}

inline int mmpObsessionBurnHours() {
    // each piece burns for 1 hour
    return 1;
}

inline int mmpIounSortCount() {
    // there are 14 sorts of useful ioun stones
    return 14;
}

inline int mmpIounOwnerRadiusFeet() {
    // the stones must be within 3 feet of their
    // owner to be efficacious
    return 3;
}

inline int mmpIounOrbitMinFeet() {
    // the circling orbit starts at a 1 foot radius
    return 1;
}

inline int mmpIounOrbitMaxFeet() {
    // the circling orbit tops at a 3 foot radius
    return 3;
}

inline int mmpIounFoundMin() {
    // from 1-10 ioun stones will be found
    return 1;
}

inline int mmpIounFoundMax() {
    // the upper edge of the 1-10 found
    return 10;
}

inline int mmpIounTableRowCount() {
    // the property table has 15 rows
    return 15;
}

inline int mmpIounDeadRowLo() {
    // the dull gray dead band starts at roll 15
    return 15;
}

inline int mmpIounDeadRowHi() {
    // and ends at roll 20
    return 20;
}

inline int mmpIounStatBonusPoints() {
    // the six stat stones add 1 point to the score
    return 1;
}

inline int mmpIounStatCap() {
    // with an 18 maximum
    return 18;
}

inline int mmpIounStatBonusRowCount() {
    // six stones add to a stat score
    return 6;
}

inline int mmpIounLevelGainLevels() {
    // the pale green prism adds 1 level of
    // experience
    return 1;
}

inline int mmpIounRegenHpPerTurn() {
    // the pearly white spindle regenerates 1 hit
    // point of damage per turn
    return 1;
}

inline int mmpIounPurpleStoreMin() {
    // the vibrant purple prism stores 2-12 levels
    return 2;
}

inline int mmpIounPurpleStoreMax() {
    // the upper edge of the stored 2-12 levels
    return 12;
}

inline int mmpIounRoseProtectionBonus() {
    // the dusty rose prism gives +1 protection
    return 1;
}

inline int mmpIounGrayPsionicBonus() {
    // the dead gray stone adds 10 points to the
    // psionic strength total
    return 10;
}

inline int mmpIounGrayPsionicCap() {
    // the psionic strength total caps at 50 points
    return 50;
}

inline int mmpIounHpToDestroy() {
    // the stones take 10 hit points of damage to
    // destroy
    return 10;
}

inline int mmpIounSaveBonus() {
    // they save as if they were of hard metal, +3
    return 3;
}

inline int mmpIounAttackAc() {
    // exposed to attack they are treated as armor
    // class -4 (the minus rides the comment)
    return 4;
}

inline int mmpIounRowRollLo(int i) {
    // the printed roll lower edges, rolls 1-14
    // then the dead band; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
    };
    return t[i];
}

inline int mmpIounRowRollHi(int i) {
    // the printed roll upper edges, the dead band
    // topping at 20; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 20,
    };
    return t[i];
}

inline int mmpIounRowAddsStat(int i) {
    // the rolls 1-6 stones add to a stat score;
    // i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int mmpIounRowAbsorbMaxLevel(int i) {
    // the roll 11 and 12 stones absorb spells up
    // to the 4th and 8th level; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        4, 8, 0, 0, 0,
    };
    return t[i];
}

inline int mmpIounRowBurnoutMin(int i) {
    // the absorbed spell levels that burn a
    // stone out, the lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        10, 20, 0, 0, 0,
    };
    return t[i];
}

inline int mmpIounRowBurnoutMax(int i) {
    // the absorbed spell levels that burn a
    // stone out, the upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        40, 80, 0, 0, 0,
    };
    return t[i];
}

inline int mmpBardInstrumentCount() {
    // there are 7 magical instruments
    return 7;
}

inline int mmpFochlucanStringCount() {
    // the small, 3-stringed bandore
    return 3;
}

inline int mmpFochlucanLowestFaeriePct() {
    // a 1st level bard or a non-bard: a 50
    // percent chance per round of playing to
    // cast a faerie fire spell
    return 50;
}

inline int mmpFochlucanLowestReversePct() {
    // a 10 percent chance the musician is
    // limned by the glow instead
    return 10;
}

inline int mmpFochlucanFaerieBasePct() {
    // a bard of Fochlucan or higher college
    // casts the faerie fire at base 50 percent
    return 50;
}

inline int mmpFochlucanReverseReductionPerLevelPct() {
    // the reverse effect reduced by 1 percent
    // per level above 1st
    return 1;
}

inline int mmpFochlucanSongCount() {
    // the bandore has 4 song properties when
    // properly played
    return 4;
}

inline int mmpFochlucanCharmBonusPct() {
    // adds 10 percent to the bard charm
    // percentage
    return 10;
}

inline int mmpFochlucanEntanglePerDay() {
    // casts an entangle spell once per day
    return 1;
}

inline int mmpFochlucanShillelaghPerDay() {
    // casts a shillelagh spell once per day
    return 1;
}

inline int mmpFochlucanSpeakAnimalsPerDay() {
    // enables the bard to speak with animals
    // once per day
    return 1;
}

inline int mmpFochlucanLowestSongWorkPct() {
    // a 1st level bard attempts the powers: a
    // 30 percent chance they work
    return 30;
}

inline int mmpFochlucanLowestSongFailPct() {
    // a 70 percent chance of the mishap
    return 70;
}

inline int mmpFochlucanLowestFailDamageMin() {
    // the mishap deals 2-8 hit points of damage
    return 2;
}

inline int mmpFochlucanLowestFailDamageMax() {
    // the upper edge of the 2-8 damage
    return 8;
}

}  // namespace rules