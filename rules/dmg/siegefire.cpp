// R-refactor: split from siegefire.h - definitions
#include "rules/dmg/siegefire.h"

int Siegefire::fireDeviceCount() { return 6; }

int Siegefire::siegeFieldOfFireDegrees(int device) {
    // ballista 45, heavy catapult 15, light
    // catapult 30, trebuchet 10; ram and
    // sow have no missile field
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 45, 15, 30, 0, 0, 10 };
    return t[device];
}

int Siegefire::siegeRangeMinQuarterInches(int device) {
    // the minimum range in quarter-inch
    // units (ballista 1/4 inch = 1)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 1, 72, 60, 0, 0, 96 };
    return t[device];
}

int Siegefire::siegeRangeMaxQuarterInches(int device) {
    // the maximum range in quarter-inch
    // units (ballista 32 inches = 128)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 128, 144, 120, 1, 1, 192 };
    return t[device];
}

int Siegefire::siegeDamageSMMin(int device) {
    // the S-M damage low edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 2, 2, 2, 9, 9, 3 };
    return t[device];
}

int Siegefire::siegeDamageSMMax(int device) {
    // the S-M damage high edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 12, 24, 20, 16, 16, 30 };
    return t[device];
}

int Siegefire::siegeDamageLMin(int device) {
    // the L damage low edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 3, 4, 3, 7, 13, 5 };
    return t[device];
}

int Siegefire::siegeDamageLMax(int device) {
    // the L damage high edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 18, 16, 12, 12, 24, 20 };
    return t[device];
}

int Siegefire::siegeRateOfFireMinHundredths(int device) {
    // the rate low edge in hundredths
    // (25 = 1/4 per round)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 25, 25, 25, 50, 50, 25 };
    return t[device];
}

int Siegefire::siegeRateOfFireMaxHundredths(int device) {
    // the rate high edge in hundredths (the
    // ballista 1/2 with maximum crew)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 50, 25, 25, 50, 50, 25 };
    return t[device];
}

int Siegefire::siegeCrewMin(int device) {
    // the minimum crew for normal rate
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 2, 6, 4, 10, 10, 8 };
    return t[device];
}

int Siegefire::siegeCrewMax(int device) {
    // the maximum crew
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 4, 10, 6, 20, 20, 12 };
    return t[device];
}

int Siegefire::siegeBelowMinCrewRatePct() {
    // below the minimum crew the rate drops
    // to at best 50 percent
    return 50;
}

int Siegefire::siegeBallistaMaxCrewRateFactor() {
    // only the ballista doubles its rate at
    // maximum crew
    return 2;
}

int Siegefire::siegeOtherMaxCrewRateFactor() {
    // all other engines gain nothing above
    // the minimum crew
    return 1;
}

int Siegefire::wmHitTargetAc() {
    // all targets are AC 0 regardless of
    // actual armor class
    return 0;
}

int Siegefire::wmBallistaTargetAc() {
    // ballista targets are always AC 10 if
    // exposed to sight
    return 10;
}

int Siegefire::wmModTargetStationary() { return 3; }

int Siegefire::wmModMoveUnder3() { return 0; }

int Siegefire::wmModMove3to12() { return -3; }

int Siegefire::wmModSizeMan() { return -2; }

int Siegefire::wmModSizeHorse() { return 0; }

int Siegefire::wmModSizeGiant() { return 2; }

int Siegefire::wmModSizeMediumBuilding() { return 4; }

int Siegefire::wmModSizeLargeBuilding() { return 6; }

int Siegefire::wmModSubsequentStationary() {
    // subsequent shots after the initial
    // ranging shot, stationary target only
    return 4;
}

int Siegefire::wmWeatherCalm() { return 1; }

int Siegefire::wmWeatherBreeze() { return 0; }

int Siegefire::wmWeatherStrong() { return -2; }

int Siegefire::wmWeatherStorm() { return -4; }

int Siegefire::wmDirectFireBonus() { return 4; }

int Siegefire::wmBallistaInterveningBlocks() {
    // the flat ballista trajectory is
    // interrupted by intervening objects
    return 1;
}

int Siegefire::wmCatapultInterveningBlocks() {
    // the arched trajectory passes over
    // intervening objects
    return 0;
}

int Siegefire::wmBallistaUnseenFirePossible() {
    // ballista fire is not possible at an
    // unseen target
    return 0;
}

int Siegefire::wmUnseenScatterGrenadeRule() {
    // an unseen target is engaged by naming
    // an area and using the grenade-like
    // scatter (the R157 section)
    return 1;
}

int Siegefire::wmGrenadeDiameterSmallCatFeet() {
    // small catapult missiles are 1 foot
    // diameter (the R157 cross-link)
    return 1;
}

int Siegefire::wmGrenadeDiameterTrebuchetFeet() {
    // trebuchet missiles are 2 feet
    return 2;
}

int Siegefire::siegeAttackKindCount() { return 22; }

int Siegefire::siegeAttackQuarterPoints(int kind, int material) {
    // the quarter-point damage (x4); the
    // earthquake row is the quake arrays
    // below, not this table
    if (kind < 0) kind = 0;
    if (kind > 21) kind = 21;
    if (material < 0) material = 0;
    if (material > 3) material = 3;
    static const int t[88] = {
        4, 0, 2, 1,
        24, 0, 16, 8,
        16, 0, 8, 4,
        0, 40, 0, 0,
        8, 8, 8, 8,
        8, 40, 8, 4,
        0, 0, 0, 0,
        2, 0, 0, 0,
        12, 0, 4, 2,
        8, 0, 4, 2,
        4, 0, 2, 1,
        16, 0, 8, 4,
        24, 0, 16, 8,
        12, 4, 8, 4,
        12, 4, 4, 2,
        72, 24, 32, 16,
        2, 0, 0, 0,
        0, 80, 0, 0,
        4, 0, 1, 0,
        2, 2, 2, 1,
        32, 8, 8, 4,
        32, 0, 20, 12,
    };
    return t[kind * 4 + material];
}

int Siegefire::siegeAttackPerRound(int kind) {
    // 1 when the shown damage is per round
    // of attack by this mode
    if (kind < 0) kind = 0;
    if (kind > 21) kind = 21;
    static const int t[22] = {
        1, 0, 0, 0, 0, 1, 0, 0, 1, 1,
        1, 0, 0, 1, 1, 0, 0, 0, 1, 1,
        1, 0,
    };
    return t[kind];
}

int Siegefire::siegeAttackPerCasterLevel(int kind) {
    // 1 when the damage is per level of the
    // spell caster (fireball, lightning
    // bolt)
    if (kind < 0) kind = 0;
    if (kind > 21) kind = 21;
    static const int t[22] = {
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0,
    };
    return t[kind];
}

int Siegefire::siegeFireDamageWetReductionPct() {
    // the fireball / lightning bolt clause:
    // green hides or wet wood reduce the
    // damage by 50 percent
    return 50;
}

int Siegefire::siegeAttackQuakeMin(int material) {
    // the earthquake dice low edge (5 for
    // every material)
    if (material < 0) material = 0;
    if (material > 3) material = 3;
    static const int t[4] = { 5, 5, 5, 5 };
    return t[material];
}

int Siegefire::siegeAttackQuakeMax(int material) {
    // the earthquake dice high edge: wood
    // and soft stone 5-60, earth and hard
    // rock 5-30
    if (material < 0) material = 0;
    if (material > 3) material = 3;
    static const int t[4] = { 60, 30, 60, 30 };
    return t[material];
}

int Siegefire::siegeSowScrewEarthOnly() {
    // the sow earth damage is inflicted
    // only if equipped with a screw device
    return 1;
}

int Siegefire::siegeSoftStoneIncludes() {
    // soft stone includes fired brick,
    // limestone, sandstone (the footnote
    // convention pinned as a flag)
    return 1;
}

int Siegefire::defensiveKindCount() { return 26; }

int Siegefire::constructionDefensiveMin(int kind) {
    // the defensive point value low edge
    if (kind < 0) kind = 0;
    if (kind > 25) kind = 25;
    static const int t[26] = {
        150, 25, 20, 12, 10, 8, 20, 10,
        1, 3, 10, 8, 120, 2, 10, 6,
        20, 15, 12, 20, 40, 30, 40, 20,
        4, 12,
    };
    return t[kind];
}

int Siegefire::constructionDefensiveMax(int kind) {
    // the defensive point value high edge
    // (equal to the min when single-valued)
    if (kind < 0) kind = 0;
    if (kind > 25) kind = 25;
    static const int t[26] = {
        150, 25, 20, 12, 10, 16, 20, 10,
        1, 3, 15, 12, 120, 2, 10, 12,
        20, 15, 12, 20, 80, 50, 40, 20,
        4, 12,
    };
    return t[kind];
}

int Siegefire::dkBarbicanExcludesGates() {
    // the barbican value excludes any values
    // for gates or portcullis
    return 1;
}

int Siegefire::dkSupportsFallFirst() {
    // the batter, buttress and pilaster
    // points must be destroyed before the
    // supported construction is affected
    return 1;
}

int Siegefire::dkRampartUnaffectedByMissiles() {
    // the rampart is unaffected by catapult
    // missiles, battering or picking
    return 1;
}

int Siegefire::dkCurtainWallThicknessFeet() {
    // the curtain wall value is for a
    // 10-foot thick wall
    return 10;
}

int Siegefire::dkCurtainWallBreachAreaFeet() {
    // the 10 x 10 area basis; a breach, not
    // a hole, needs top-to-bottom
    // destruction
    return 10;
}

int Siegefire::siegeDeviceMhp(int device) {
    // the device hit points; the ram
    // catcher carries no value in the
    // print (0 here with that note)
    if (device < 0) device = 0;
    if (device > 11) device = 11;
    static const int t[12] = {
        2, 6, 4, 2, 10, 4,
        3, 12, 0, 16, 12, 8,
    };
    return t[device];
}

int Siegefire::miningBreachCurtainFeet() {
    // a successful mine breaches a 10-foot
    // wide curtain wall section
    return 10;
}

int Siegefire::miningBreachDamagePoints() {
    // or causes 10 points of damage to
    // other sorts of constructions
    return 10;
}

int Siegefire::sappingDamagePerTurn() {
    // sapping does the sow damage but per
    // turn, rather than per round
    return 1;
}
