// R-refactor: split from miscmagic_horn_of_collapsing_to_incense_of_meditation.h - definitions
#include "rules/dmg/miscmagic_horn_of_collapsing_to_incense_of_meditation.h"

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseMisfirePct() {
    // sounded without the proper rune, or 10
    // percent of the time in any event
    return 10;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseOutRocksMin() {
    // outside: a rain of fist-sized rocks
    return 2;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseOutRocksMax() {
    // from 2-12 in number
    return 12;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseOutRockDmgMin() {
    // each rock causes 1-6 hit points of damage
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseOutRockDmgMax() {
    // the 1-6 upper edge
    return 6;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseIndoorDmgMin() {
    // indoors: the ceiling collapses on the character
    return 3;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseIndoorDmgMax() {
    // 3-36 hit points of damage
    return 36;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseUnderDmgMin() {
    // underground: the material above falls
    return 5;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseUnderDmgMax() {
    // 5-20 hit points base damage
    return 20;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseUnderHeightFactorFeet() {
    // the base damage is multiplied by 1 factor for
    // each 10 feet of drop height (twice at 20 feet,
    // three times at 30 feet, etc.)
    return 10;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseAimRangeMinFeet() {
    // proper use: point at the roof overhead from
    return 30;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseAimRangeMaxFeet() {
    // 30 to 60 feet beyond the user
    return 60;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseRoofWidthFeet() {
    // collapses a roof section up to 20 feet wide
    return 20;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseRoofLengthFeet() {
    // and 20 feet long
    return 20;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseRoofRadiusFeet() {
    // a 10 feet radius from the central aiming point
    return 10;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornCollapseIndoorsOrUndergroundOnly() {
    // the aimed collapse inflicts damage only if
    // indoors or underground
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPerDay() {
    // a conch shell horn blown but once per day
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonTritonPerDay() {
    // except by a triton who can sound it 3 times
    return 3;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonFunctionCount() {
    // any 1 of the following functions
    return 3;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonCalmRadiusMiles() {
    // calm rough waters in a 1 mile radius
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonCalmDispelKinds() {
    // dispels a water elemental or water weird
    return 2;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonSummonKindCount() {
    // hippocampi, giant sea horses, sea lions
    return 3;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonSummonDieLo(int i) {
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

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonSummonDieHi(int i) {
    // the selection die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        2, 5, 6,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonSummonCountMin(int i) {
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

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonSummonCountMax(int i) {
    // the summon upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        20, 30, 10,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPanicAnimalOrLower() {
    // panics marine creatures with animal, or
    // lower, intelligence
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPanicToHitPenalty() {
    // those who save take a minus 5 on to hit dice
    return 5;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPanicTurnsMin() {
    // the penalty lasts 3-18 turns
    return 3;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPanicTurnsMax() {
    // the turns upper edge
    return 18;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPanicRoundsPerTurn() {
    // 3-18 turns is 30-180 rounds: 10 rounds per
    // turn
    return 10;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPanicRoundsMin() {
    // the 30 rounds lower edge
    return 30;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonPanicRoundsMax() {
    // the 180 rounds upper edge
    return 180;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornTritonHearRadiusLeagues() {
    // any sounding is heard by all tritons within
    // a 1 league radius
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaVarietyCount() {
    // there are 4 varieties of this magical device
    return 4;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaBlowIntervalDays() {
    // each variety can be blown but once every 7
    // days
    return 7;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaSummonedAc() {
    // the fighters summoned are armor class 4
    return 4;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaSummonedHpPerDie() {
    // they have 6 hit points per die
    return 6;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaSwordSpearPct() {
    // armed with sword and spear 50 percent
    return 50;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaAxeSpearPct() {
    // or battle axe and spear 50 percent
    return 50;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaServiceTurns() {
    // they fight until slain or 6 turns have
    // elapsed, whichever occurs first
    return 6;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaAlignedPct() {
    // fully 50 percent of these horns are aligned
    // and summon only same-alignment fighters
    return 50;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaBronzeXpMultiplier() {
    // the base 1,000 xp is doubled for a bronze
    // horn - the row 20 double asterisk
    return 2;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaIronXpMultiplier() {
    // and tripled for an iron horn
    return 3;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaDiceLo(int i) {
    // the variety dice band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 9, 16, 19,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaDiceHi(int i) {
    // silver 1-8, brass 9-15, bronze 16-18, iron
    // 19-20; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        8, 15, 18, 20,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaCountMin(int i) {
    // berserk fighters summoned lower edges;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        4, 3, 2, 2,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaCountMax(int i) {
    // the 4-10, 3-9, 2-8, 2-5 upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        10, 9, 8, 5,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaLevel(int i) {
    // the summoned fighter levels: 2nd, 3rd, 4th,
    // 5th; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        2, 3, 4, 5,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaUsableAny(int i) {
    // the silver horn is usable by any class; i
    // clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaUsableCleric(int i) {
    // the (C) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 1, 0,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaUsableFighter(int i) {
    // the (F) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 1, 1,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHornValhallaUsableThief(int i) {
    // the (T) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 0, 0,
    };
    return t[i];
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesSpeedShoeCount() {
    // 4 normal-appearing iron horse shoes
    return 4;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesSpeedFullPct() {
    // affixed, they double the animal speed (the
    // 200 percent full rate)
    return 200;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesSpeedDropPct() {
    // a 1 percent chance per 7 leagues travelled
    // that 1 shoe drops off
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesSpeedDropLeagues() {
    // the drop interval in leagues
    return 7;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesSpeedOneLostPct() {
    // one lost and unnoticed: 150 percent of the
    // normal rate
    return 150;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesSpeedTwoLostPct() {
    // 2 lost: the speed is normal
    return 100;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesZephyrGroundless() {
    // the horse travels without touching the
    // ground
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesZephyrNoTracks() {
    // water can be passed over and no tracks are
    // made on any sort of ground
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesZephyrNoTireHours() {
    // the horse will not tire for 12 hours of
    // continuous riding
    return 12;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpHorseshoesZephyrPerDay() {
    // per day of continuous riding
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedRecognizeClericLevel() {
    // the smoke is recognizable by any cleric of
    // 5th or higher level
    return 5;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedPrayHours() {
    // the cleric spends 8 hours praying and
    // meditating nearby
    return 8;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedCureAlwaysMax() {
    // cure wounds spells are always maximum
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedBroadestArea() {
    // spell effects are of the broadest area
    // possible
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedSavePenalty() {
    // saving throws against the effects are at
    // minus 1
    return 1;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedNotSurvivingDivisor() {
    // the revived dead reduce their chance of not
    // surviving by one-half (rounded down)
    return 2;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedPieceCountMin() {
    // discovered with from 2-8 pieces of incense
    return 2;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedPieceCountMax() {
    // the piece count upper edge
    return 8;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedBurnHours() {
    // one piece burns for 8 hours
    return 8;
}

int Miscmagic_horn_of_collapsing_to_incense_of_meditation::mmpIncenseMedEffectHours() {
    // the effects remain for 24 hours
    return 24;
}
