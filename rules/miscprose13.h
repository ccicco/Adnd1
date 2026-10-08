// ====================================================================
// Adnd1 - rules/miscprose13.h
// R269: the III.E misc magic explanation prose part 13
// (DMG p.139-140) - Horn of Collapsing through the
// Incense of Meditation, part2 lines 581-626 (global =
// 11065 + part2 line). ONE page header inside the slice
// (592, the TREASURE page) cuts the Collapsing proper
// use paragraph mid-sentence (one seam, restored). ONE
// OCR artifact restored from the compilation (the R175
// precedent): the meditation survival clause reads
// (rounded down), the upload prints grounded down).
// 73 accessors: 60 scalars + 13 array walkers (the
// triton summon and the Valhalla variety tables), no
// name collisions with miscprose1.h through
// miscprose12.h. The slice pins kMisc3 rows 18-23: the
// (C, F) mark on the Horn of the Tritons (row 19), the
// (C) mark on the Incense of Meditation (row 23), the
// Valhalla double asterisk (row 20). Pure data +
// helpers, header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpHornCollapseMisfirePct() {
    // sounded without the proper rune, or 10
    // percent of the time in any event
    return 10;
}

inline int mmpHornCollapseOutRocksMin() {
    // outside: a rain of fist-sized rocks
    return 2;
}

inline int mmpHornCollapseOutRocksMax() {
    // from 2-12 in number
    return 12;
}

inline int mmpHornCollapseOutRockDmgMin() {
    // each rock causes 1-6 hit points of damage
    return 1;
}

inline int mmpHornCollapseOutRockDmgMax() {
    // the 1-6 upper edge
    return 6;
}

inline int mmpHornCollapseIndoorDmgMin() {
    // indoors: the ceiling collapses on the character
    return 3;
}

inline int mmpHornCollapseIndoorDmgMax() {
    // 3-36 hit points of damage
    return 36;
}

inline int mmpHornCollapseUnderDmgMin() {
    // underground: the material above falls
    return 5;
}

inline int mmpHornCollapseUnderDmgMax() {
    // 5-20 hit points base damage
    return 20;
}

inline int mmpHornCollapseUnderHeightFactorFeet() {
    // the base damage is multiplied by 1 factor for
    // each 10 feet of drop height (twice at 20 feet,
    // three times at 30 feet, etc.)
    return 10;
}

inline int mmpHornCollapseAimRangeMinFeet() {
    // proper use: point at the roof overhead from
    return 30;
}

inline int mmpHornCollapseAimRangeMaxFeet() {
    // 30 to 60 feet beyond the user
    return 60;
}

inline int mmpHornCollapseRoofWidthFeet() {
    // collapses a roof section up to 20 feet wide
    return 20;
}

inline int mmpHornCollapseRoofLengthFeet() {
    // and 20 feet long
    return 20;
}

inline int mmpHornCollapseRoofRadiusFeet() {
    // a 10 feet radius from the central aiming point
    return 10;
}

inline int mmpHornCollapseIndoorsOrUndergroundOnly() {
    // the aimed collapse inflicts damage only if
    // indoors or underground
    return 1;
}

inline int mmpHornTritonPerDay() {
    // a conch shell horn blown but once per day
    return 1;
}

inline int mmpHornTritonTritonPerDay() {
    // except by a triton who can sound it 3 times
    return 3;
}

inline int mmpHornTritonFunctionCount() {
    // any 1 of the following functions
    return 3;
}

inline int mmpHornTritonCalmRadiusMiles() {
    // calm rough waters in a 1 mile radius
    return 1;
}

inline int mmpHornTritonCalmDispelKinds() {
    // dispels a water elemental or water weird
    return 2;
}

inline int mmpHornTritonSummonKindCount() {
    // hippocampi, giant sea horses, sea lions
    return 3;
}

inline int mmpHornTritonSummonDieLo(int i) {
    // the selection die band lower edges: 1-2 the
    // hippocampi, 3-5 the sea horses, 6 the lions;
    // i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 3, 6,
    };
    return t[i];
}

inline int mmpHornTritonSummonDieHi(int i) {
    // the selection die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        2, 5, 6,
    };
    return t[i];
}

inline int mmpHornTritonSummonCountMin(int i) {
    // the creatures summoned lower edges: 5-20
    // hippocampi, 5-30 sea horses, 1-10 sea lions;
    // i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        5, 5, 1,
    };
    return t[i];
}

inline int mmpHornTritonSummonCountMax(int i) {
    // the summon upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        20, 30, 10,
    };
    return t[i];
}

inline int mmpHornTritonPanicAnimalOrLower() {
    // panics marine creatures with animal, or
    // lower, intelligence
    return 1;
}

inline int mmpHornTritonPanicToHitPenalty() {
    // those who save take a minus 5 on to hit dice
    return 5;
}

inline int mmpHornTritonPanicTurnsMin() {
    // the penalty lasts 3-18 turns
    return 3;
}

inline int mmpHornTritonPanicTurnsMax() {
    // the turns upper edge
    return 18;
}

inline int mmpHornTritonPanicRoundsPerTurn() {
    // 3-18 turns is 30-180 rounds: 10 rounds per
    // turn
    return 10;
}

inline int mmpHornTritonPanicRoundsMin() {
    // the 30 rounds lower edge
    return 30;
}

inline int mmpHornTritonPanicRoundsMax() {
    // the 180 rounds upper edge
    return 180;
}

inline int mmpHornTritonHearRadiusLeagues() {
    // any sounding is heard by all tritons within
    // a 1 league radius
    return 1;
}

inline int mmpHornValhallaVarietyCount() {
    // there are 4 varieties of this magical device
    return 4;
}

inline int mmpHornValhallaBlowIntervalDays() {
    // each variety can be blown but once every 7
    // days
    return 7;
}

inline int mmpHornValhallaSummonedAc() {
    // the fighters summoned are armor class 4
    return 4;
}

inline int mmpHornValhallaSummonedHpPerDie() {
    // they have 6 hit points per die
    return 6;
}

inline int mmpHornValhallaSwordSpearPct() {
    // armed with sword and spear 50 percent
    return 50;
}

inline int mmpHornValhallaAxeSpearPct() {
    // or battle axe and spear 50 percent
    return 50;
}

inline int mmpHornValhallaServiceTurns() {
    // they fight until slain or 6 turns have
    // elapsed, whichever occurs first
    return 6;
}

inline int mmpHornValhallaAlignedPct() {
    // fully 50 percent of these horns are aligned
    // and summon only same-alignment fighters
    return 50;
}

inline int mmpHornValhallaBronzeXpMultiplier() {
    // the base 1,000 xp is doubled for a bronze
    // horn - the row 20 double asterisk
    return 2;
}

inline int mmpHornValhallaIronXpMultiplier() {
    // and tripled for an iron horn
    return 3;
}

inline int mmpHornValhallaDiceLo(int i) {
    // the variety dice band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 9, 16, 19,
    };
    return t[i];
}

inline int mmpHornValhallaDiceHi(int i) {
    // silver 1-8, brass 9-15, bronze 16-18, iron
    // 19-20; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        8, 15, 18, 20,
    };
    return t[i];
}

inline int mmpHornValhallaCountMin(int i) {
    // berserk fighters summoned lower edges;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        4, 3, 2, 2,
    };
    return t[i];
}

inline int mmpHornValhallaCountMax(int i) {
    // the 4-10, 3-9, 2-8, 2-5 upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        10, 9, 8, 5,
    };
    return t[i];
}

inline int mmpHornValhallaLevel(int i) {
    // the summoned fighter levels: 2nd, 3rd, 4th,
    // 5th; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        2, 3, 4, 5,
    };
    return t[i];
}

inline int mmpHornValhallaUsableAny(int i) {
    // the silver horn is usable by any class; i
    // clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 0, 0, 0,
    };
    return t[i];
}

inline int mmpHornValhallaUsableCleric(int i) {
    // the (C) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 1, 0,
    };
    return t[i];
}

inline int mmpHornValhallaUsableFighter(int i) {
    // the (F) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 1, 1,
    };
    return t[i];
}

inline int mmpHornValhallaUsableThief(int i) {
    // the (T) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 0, 0,
    };
    return t[i];
}

inline int mmpHorseshoesSpeedShoeCount() {
    // 4 normal-appearing iron horse shoes
    return 4;
}

inline int mmpHorseshoesSpeedFullPct() {
    // affixed, they double the animal speed (the
    // 200 percent full rate)
    return 200;
}

inline int mmpHorseshoesSpeedDropPct() {
    // a 1 percent chance per 7 leagues travelled
    // that 1 shoe drops off
    return 1;
}

inline int mmpHorseshoesSpeedDropLeagues() {
    // the drop interval in leagues
    return 7;
}

inline int mmpHorseshoesSpeedOneLostPct() {
    // one lost and unnoticed: 150 percent of the
    // normal rate
    return 150;
}

inline int mmpHorseshoesSpeedTwoLostPct() {
    // 2 lost: the speed is normal
    return 100;
}

inline int mmpHorseshoesZephyrGroundless() {
    // the horse travels without touching the
    // ground
    return 1;
}

inline int mmpHorseshoesZephyrNoTracks() {
    // water can be passed over and no tracks are
    // made on any sort of ground
    return 1;
}

inline int mmpHorseshoesZephyrNoTireHours() {
    // the horse will not tire for 12 hours of
    // continuous riding
    return 12;
}

inline int mmpHorseshoesZephyrPerDay() {
    // per day of continuous riding
    return 1;
}

inline int mmpIncenseMedRecognizeClericLevel() {
    // the smoke is recognizable by any cleric of
    // 5th or higher level
    return 5;
}

inline int mmpIncenseMedPrayHours() {
    // the cleric spends 8 hours praying and
    // meditating nearby
    return 8;
}

inline int mmpIncenseMedCureAlwaysMax() {
    // cure wounds spells are always maximum
    return 1;
}

inline int mmpIncenseMedBroadestArea() {
    // spell effects are of the broadest area
    // possible
    return 1;
}

inline int mmpIncenseMedSavePenalty() {
    // saving throws against the effects are at
    // minus 1
    return 1;
}

inline int mmpIncenseMedNotSurvivingDivisor() {
    // the revived dead reduce their chance of not
    // surviving by one-half (rounded down)
    return 2;
}

inline int mmpIncenseMedPieceCountMin() {
    // discovered with from 2-8 pieces of incense
    return 2;
}

inline int mmpIncenseMedPieceCountMax() {
    // the piece count upper edge
    return 8;
}

inline int mmpIncenseMedBurnHours() {
    // one piece burns for 8 hours
    return 8;
}

inline int mmpIncenseMedEffectHours() {
    // the effects remain for 24 hours
    return 24;
}

}  // namespace rules