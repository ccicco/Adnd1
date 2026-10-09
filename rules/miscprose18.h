// ====================================================================
// Adnd1 - rules/miscprose18.h
// R274: the III.E misc magic explanation prose part 18
// (DMG p.150-151) - the Manual of Stealthy Pilfering, the
// Mattock and Maul of the Titans, the Medallions of ESP
// and Thought Projection, the Mirrors of Life Trapping,
// Mental Prowess and Opposition and the Necklaces of
// Adaptation and Missiles, part2 lines 843-900 (global
// = 11065 + part2 line), pinning the kMisc4 rows 9-18 of
// the 36-row III.E.4 table. ONE mid-sentence break inside
// the slice: the mirror of life trapping paragraph splits
// between not a (863) and factor (865), the upload
// prints no running head at the break - ONE
// seam restored this round; the slice rides the
// pp.150-151 attribution on the R273-established p.150
// base. The upload quirks this round: the necklace of
// missiles table is badly mangled (pipes misplaced,
// fragments pushed into the wrong cells) - the
// dash-separated count ladders reconstruct it exactly
// and cross-check against the printed example:
// one 7-dice, two 5-dice, four 3-dice (the 9-12 row);
// the stray apostrophe artifact after the word manual
// recurs in the pilfering paragraph (a like manual)
// beside a printed magic- users with a space (both
// pinned as the upload prints them,
// apostrophe-free here); the medallion table prints
// clean. 67
// accessors: 59 scalars + 8 walkers (the medallion die
// bands, ranges and empathy marks; the necklace die
// bands, hit dice columns and the flattened 70-cell
// count table), no name collisions with miscprose1.h
// through miscprose17.h. Pure data + helpers,
// header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpStealthyPracticeMonths() {
    // the thief practices 1 month thereafter
    return 1;
}

inline int mmpStealthyKnowledgeMonths() {
    // the knowledge is retained for 3 months
    return 3;
}

inline int mmpStealthyAssassinXp() {
    // an assassin gains but 5,000 additional xp
    return 5000;
}

inline int mmpStealthyAssassinWeeks() {
    // the contents pondered for 1 week
    return 1;
}

inline int mmpStealthyWrongDamageMin() {
    // a wrong-class reader takes 5-20 damage
    return 5;
}

inline int mmpStealthyWrongDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

inline int mmpStealthyStunRoundsMin() {
    // stunned a like number of rounds
    return 5;
}

inline int mmpStealthyStunRoundsMax() {
    // the upper edge of the like-number rounds
    return 20;
}

inline int mmpStealthyXpLossMin() {
    // a failed save loses 5,000-20,000 xp
    return 5000;
}

inline int mmpStealthyXpLossMax() {
    // the upper edge of the 5,000-20,000 xp loss
    return 20000;
}

inline int mmpStealthyAtoneDays() {
    // must atone within 1 day
    return 1;
}

inline int mmpStealthyWisdomLoss() {
    // or lose 1 point of wisdom
    return 1;
}

inline int mmpMattockLengthFeet() {
    // the huge digging tool is 10 feet long
    return 10;
}

inline int mmpMattockWeightLb() {
    // and weighs over 100 pounds
    return 100;
}

inline int mmpMattockMinStrength() {
    // a giant-sized user of strength 20 or more
    return 20;
}

inline int mmpMattockEarthCubicFeet() {
    // loosens earth in a 100 cubic foot area
    return 100;
}

inline int mmpMattockRockCubicFeet() {
    // smashes rock in a 20 cubic feet area
    return 20;
}

inline int mmpMattockAreaTurns() {
    // either area in 1 turn of work
    return 1;
}

inline int mmpMattockHitBonus() {
    // +3 to hit as a weapon
    return 3;
}

inline int mmpMattockDamageMin() {
    // does 5-30 damage, strength bonuses aside
    return 5;
}

inline int mmpMattockDamageMax() {
    // the upper edge of the 5-30 damage
    return 30;
}

inline int mmpMaulLengthFeet() {
    // the huge mallet is 8 feet long
    return 8;
}

inline int mmpMaulWeightLb() {
    // and weighs over 150 pounds
    return 150;
}

inline int mmpMaulMinStrength() {
    // a giant-sized user of strength 21 or greater
    return 21;
}

inline int mmpMaulPileDiameterFeet() {
    // drives piles of up to 2 feet diameter
    return 2;
}

inline int mmpMaulPileDepthFeet() {
    // into normal earth at 4 feet per blow
    return 4;
}

inline int mmpMaulBlowsPerRound() {
    // 2 blows per round
    return 2;
}

inline int mmpMaulDoorHeightFeet() {
    // an oaken door of up to 10 feet height
    return 10;
}

inline int mmpMaulDoorWidthFeet() {
    // by 4 feet width
    return 4;
}

inline int mmpMaulDoorThicknessInches() {
    // by 2 inch thickness
    return 2;
}

inline int mmpMaulDoorBlows() {
    // smashed to flinders in 1 blow
    return 1;
}

inline int mmpMaulDoorIronBlows() {
    // 2 blows if heavily bound with iron
    return 2;
}

inline int mmpMaulHitBonus() {
    // +2 to hit as a weapon
    return 2;
}

inline int mmpMaulDamageMin() {
    // inflicts 10-40 damage, strength bonuses aside
    return 10;
}

inline int mmpMaulDamageMax() {
    // the upper edge of the 10-40 damage
    return 40;
}

inline int mmpEspPathWidthFeet() {
    // the path is 1 foot wide at the medallion
    return 1;
}

inline int mmpEspBroadenFeet() {
    // broadening 2 feet every 10 feet of reach
    return 2;
}

inline int mmpEspBroadenPerFeet() {
    // every 10 feet from the device
    return 10;
}

inline int mmpEspMaxWidthFeet() {
    // up to an 11 foot maximum width
    return 11;
}

inline int mmpEspMaxWidthAtFeet() {
    // the maximum reached at 50 feet
    return 50;
}

inline int mmpEspUseRounds() {
    // a full round to use the device
    return 1;
}

inline int mmpEspStoneBlockFeet() {
    // stone of over 3 feet thickness blocks
    return 3;
}

inline int mmpEspMetalBlockSixthsFeet() {
    // metal of over 1/6 foot thickness blocks
    return 1;
}

inline int mmpEspMalfunctionRoll() {
    // malfunctions on a die roll of 6
    return 6;
}

inline int mmpEspMalfunctionDieSides() {
    // the roll is on d6, checked each use
    return 6;
}

inline int mmpEspRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 16, 19, 20,
    };
    return t[i];
}

inline int mmpEspRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        15, 18, 19, 20,
    };
    return t[i];
}

inline int mmpEspRangeFeet(int i) {
    // the medallion range per type; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 30, 60, 90,
    };
    return t[i];
}

inline int mmpEspEmpathy(int i) {
    // the with-empathy mark per type; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 0, 0,
    };
    return t[i];
}

inline int mmpProjectionWorksRoll() {
    // correct without projecting on a roll of 6
    return 6;
}

inline int mmpTrapAreaSquareFeet() {
    // the crystal device about 4 square feet
    return 4;
}

inline int mmpTrapCellMin() {
    // from 13 compartments at the fewest
    return 13;
}

inline int mmpTrapCellMax() {
    // to 18 compartments at the most
    return 18;
}

inline int mmpTrapTriggerFeet() {
    // a looker coming within 30 feet
    return 30;
}

inline int mmpTrapSeePctUnaware() {
    // 100 percent when unaware of the device
    return 100;
}

inline int mmpTrapSeePctAvoiding() {
    // dropping to 50 when actively avoiding
    return 50;
}

inline int mmpTrapSeePctAware() {
    // and 20 when aware it traps life
    return 20;
}

inline int mmpTrapOverflowFreed() {
    // 1 random victim freed on overflow
    return 1;
}

inline int mmpProwessQuestionsPerWeek() {
    // answers one short question per week
    return 1;
}

inline int mmpProwessWidthFeet() {
    // the typical mirror 5 feet by
    return 5;
}

inline int mmpProwessHeightFeet() {
    // 2 feet
    return 2;
}

inline int mmpAdaptationAirlessDays() {
    // exists in airless space for up to 7 days
    return 7;
}

inline int mmpMissileRangeInches() {
    // the globes hurled up to 7 inches distance
    return 7;
}

inline int mmpNeckRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 5, 9, 13, 17, 19, 20,
    };
    return t[i];
}

inline int mmpNeckRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        4, 8, 12, 16, 18, 19, 20,
    };
    return t[i];
}

inline int mmpNeckDieOf(int i) {
    // the hit dice column ladder; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        11, 10, 9, 8, 7, 6, 5, 4, 3, 2,
    };
    return t[i];
}

inline int mmpNeckCell(int i) {
    // the flattened count table, the row-major
    // index i = row * 10 + column, the columns
    // running the 11-dice through 2-dice ladder;
    // the 9-12 row reads the printed example:
    // one 7-dice, two 5-dice, four 3-dice; clamps
    if (i < 0) i = 0;
    if (i > 69) i = 69;
    static const int t[70] = {
        0, 0, 0, 0, 0, 0, 1, 0, 2, 0,
        0, 0, 0, 0, 0, 1, 0, 2, 0, 2,
        0, 0, 0, 0, 1, 0, 2, 0, 4, 0,
        0, 0, 0, 1, 0, 2, 0, 2, 0, 4,
        0, 0, 1, 0, 2, 0, 2, 0, 2, 0,
        0, 1, 0, 2, 0, 2, 0, 4, 0, 0,
        1, 0, 2, 0, 2, 0, 2, 0, 2, 0,
    };
    return t[i];
}

}  // namespace rules