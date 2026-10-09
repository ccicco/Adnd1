// ====================================================================
// Adnd1 - rules/miscprose19.h
// R275: the III.E misc magic explanation prose part 19
// (DMG p.152-153) - the Necklace of Prayer Beads, the
// Necklace of Strangulation, the Nets of Entrapment and
// Snaring, Nolzurs Marvelous Pigments, the Pearls of
// Power and Wisdom and the Periapts of Foul Rotting,
// Health, Proof Against Poison and Wound Closure,
// part2 lines 905-969 (global = 11065 + part2 line),
// pinning the kMisc4 rows 19-29 of the 36-row III.E.4
// table. ONE mid-sentence break inside the slice: the
// pearl of power paragraph splits between a pearl of
// power (933) and enables the possessor (935), the
// upload prints no running head at the break - ONE
// seam restored this round; the slice rides the
// pp.152-153 attribution on the R274-established p.152
// base (the TREASURE running head at 903). The upload
// quirks this round: the bead table rows are split
// across multiple table lines (the karma and summons
// beads span three each); the part1 pigments row
// misplaces the apostrophe after the s; the net of
// entrapment prints the one-quarter character (mesh)
// and an en-dash (AC -10) - pinned as plain digits,
// apostrophe-free here. 49 accessors: 41 scalars + 8
// walkers (the bead die bands; the pearl die bands
// and spell levels; the periapt plus ladder), no name
// collisions with miscprose1.h through miscprose18.h.
// Pure data + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpBeadStoneMin() {
    // the necklace consists of 25-30 stones
    return 25;
}

inline int mmpBeadStoneMax() {
    // the upper edge of the 25-30 stones
    return 30;
}

inline int mmpBeadSemiPreciousPct() {
    // 60 percent semi-precious stones
    return 60;
}

inline int mmpBeadFancyPct() {
    // 40 percent fancy stones
    return 40;
}

inline int mmpBeadPetitionBonusPct() {
    // 25 percent more likely to petition the deity
    return 25;
}

inline int mmpBeadSpecialMin() {
    // 3-6 special beads
    return 3;
}

inline int mmpBeadSpecialMax() {
    // the upper edge of the 3-6 special beads
    return 6;
}

inline int mmpBeadGemBaseGp() {
    // precious stones of 1,000 gp base value
    return 1000;
}

inline int mmpBeadUsesPerDay() {
    // each special bead once per day
    return 1;
}

inline int mmpBeadKarmaLevels() {
    // the karma bead casts 4 levels higher
    return 4;
}

inline int mmpBeadSummonsPct() {
    // the summons bead calls the deity at 90 percent
    return 90;
}

inline int mmpBeadRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 6, 11, 16, 18, 19,
    };
    return t[i];
}

inline int mmpBeadRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 10, 15, 17, 18, 20,
    };
    return t[i];
}

inline int mmpStrangleDamagePerRound() {
    // 6 hit points of strangulation damage per round
    return 6;
}

inline int mmpEntrapMinStrength() {
    // defies strength under 20
    return 20;
}

inline int mmpEntrapCutAc() {
    // equal to AC -10 against cutting blows
    return -10;
}

inline int mmpEntrapSizeFeet() {
    // each net is 10 feet square
    return 10;
}

inline int mmpEntrapMeshQuarterFeet() {
    // with a quarter-foot mesh
    return 1;
}

inline int mmpEntrapThrowFeet() {
    // it can be thrown 20 feet
    return 20;
}

inline int mmpEntrapCloseCubeFeet() {
    // stretches to close over a 5 foot cube
    return 5;
}

inline int mmpSnareRangeInches() {
    // shoots forth up to 3 inches underwater
    return 3;
}

inline int mmpPigPotCubicFeet() {
    // one pot creates a 1,000 cubic foot object
    return 1000;
}

inline int mmpPigDepictSquareFeet() {
    // depicted over a 100 square foot surface
    return 100;
}

inline int mmpPigContainersMin() {
    // from 1-4 containers found
    return 1;
}

inline int mmpPigContainersMax() {
    // the upper edge of the 1-4 containers
    return 4;
}

inline int mmpPigInstrumentFeet() {
    // a single instrument about 1 foot long
    return 1;
}

inline int mmpPigDepictTurns() {
    // 1 turn to depict an object
    return 1;
}

inline int mmpPowerRecallPerDay() {
    // once a day the pearl recalls
    return 1;
}

inline int mmpPowerSpellsRecalled() {
    // recalls any 1 spell as desired
    return 1;
}

inline int mmpPowerReverseOneIn() {
    // 1 in 20 of opposite effect
    return 20;
}

inline int mmpPowerDoubleMin() {
    // the 00 row recalls 2 spells
    return 2;
}

inline int mmpPowerDoubleMaxLevel() {
    // of 1st to 6th level
    return 6;
}

inline int mmpPowerDoubleDieSides() {
    // the level picked by d6
    return 6;
}

inline int mmpPowerRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 26, 46, 61, 76, 86, 93, 97, 99, 100,
    };
    return t[i];
}

inline int mmpPowerRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        25, 45, 60, 75, 85, 92, 96, 98, 99, 100,
    };
    return t[i];
}

inline int mmpPowerSpellLevel(int i) {
    // the spell level per die band, the 00 row
    // marked 0 for the double-spell special; clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    };
    return t[i];
}

inline int mmpWisdomGain() {
    // the cleric gains 1 point of wisdom
    return 1;
}

inline int mmpWisdomMonths() {
    // retained for a 1 month period
    return 1;
}

inline int mmpWisdomDays() {
    // the gain at the expiration of 30 days
    return 30;
}

inline int mmpWisdomReverseOneIn() {
    // 1 in 20 cursed to work in reverse
    return 20;
}

inline int mmpRotAbilityLossPerWeek() {
    // 1 point per ability per week
    return 1;
}

inline int mmpRotStartWeek() {
    // beginning 1 week after claiming
    return 1;
}

inline int mmpRotAbilityCount() {
    // dexterity, constitution and charisma
    return 3;
}

inline int mmpRotDeathScore() {
    // dead when any score reaches 0
    return 0;
}

inline int mmpPoisonSavePctPerPlus() {
    // a 10 percent saving throw per plus
    return 10;
}

inline int mmpPoisonRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 9, 15, 19,
    };
    return t[i];
}

inline int mmpPoisonRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        8, 14, 18, 20,
    };
    return t[i];
}

inline int mmpPoisonPlus(int i) {
    // the plus of periapt per die band; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 3, 4,
    };
    return t[i];
}

inline int mmpWoundHealRateMult() {
    // doubles the normal rate of healing
    return 2;
}

}  // namespace rules