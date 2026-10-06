// ====================================================================
// Adnd1 - rules/siegefire.h
// R214: the war machine fire tables, the
// siege attack values, and the construction
// defensive values (DMG pp.108-110, the
// CONSTRUCTION & SIEGE tail).
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice, the scatter rolls and the campaign
// milieu; the tables and modifiers read
// here).
//
// Conventions and judgments, named in
// place:
//   - GROUND TRUTH NOTE: the upload OCR
//     scrambles the crew column and
//     interleaves the fire columns of the
//     WAR MACHINE FIRE table; the live
//     compilation (seadow.htm) is the
//     recovery source (the R209/R210 rule)
//     and matches the upload cell values
//     everywhere else. The SIEGE ATTACK
//     VALUES matrix and the defensive value
//     tables agree in both sources.
//   - The firing devices: ballista, heavy
//     and light catapult, ram, sow,
//     trebuchet (the print order). Field of
//     fire: ballista 45 degrees, heavy
//     catapult 15, light catapult 30,
//     trebuchet 10 - rams and sows have no
//     missile field (0). Ranges are pinned
//     in quarter-inch units x4: ballista
//     1/4 to 32 inches (1 to 128), heavy
//     catapult 18 to 36 (72 to 144), light
//     catapult 15 to 30 (60 to 120), ram
//     and sow 0 to 1/4 (0 to 1), trebuchet
//     24 to 48 (96 to 192). The ram and sow
//     range is only the maximum swing of the
//     boom - the proximity of the housing
//     to the target construction.
//   - Damage: the S-M and L columns are
//     pinned as min/max ints (the dice are
//     the caller choice). Rate of fire in
//     hundredths: ballista 25 to 50 (the
//     max crew doubles the ballista rate),
//     catapults and trebuchet 25, ram and
//     sow 50.
//   - Crew: below the minimum, rate of fire
//     drops to at best 50 percent of
//     normal; only the ballista gains from
//     a maximum crew (x2) - all other
//     engines gain nothing above minimum.
//   - Hit determination: artillerists must
//     operate the engines; the crew chief
//     level selects the attack matrix
//     column (the R111 matrices - not
//     re-pinned here). All targets are
//     AC 0 regardless of actual armor class,
//     except ballista targets which are
//     always AC 10 if exposed to sight. The
//     d20 modifiers: stationary +3, movement
//     under 3 inches 0, movement 3 to 12
//     inches -3; man size or smaller -2,
//     horse and rider / small ship 0, giant
//     size / small building / medium ship
//     +2, medium building / large ship +4,
//     large building / castle wall +6;
//     subsequent shots at a stationary target
//     +4; ship weather calm +1, light to
//     moderate breeze 0, strong breeze to
//     strong gale -2, storm -4; direct fire
//     +4.
//   - Trajectory and cover: ballista flight
//     is flat - intervening objects block it;
//     catapult and trebuchet missiles arch
//     over intervening objects unless near
//     engine or target. A wholly or partly
//     unseen target cannot be hit normally
//     by catapult or trebuchet - a target
//     area is named and the grenade-like
//     scatter is used; ballista fire is not
//     possible at an unseen target. Small
//     catapult missiles are 1 foot diameter,
//     trebuchet 2 (the R157 cross-link; the
//     print repeats the figure here).
//   - The siege attack values: 22 attack
//     forms x 4 materials (wood, earth, soft
//     stone, hard rock), pinned in
//     quarter-point units x4 (1 = 1/4 point,
//     2 = 1/2, 4 = 1 point; 0 = no effect).
//     Per-round forms carry the P flag,
//     fireball and lightning bolt are per
//     caster level (L flag, with the green
//     hides / wet wood 50 percent reduction
//     clause), the sow earth value applies
//     only with a screw device, and the
//     earthquake row is dice, pinned as the
//     quake min/max arrays (5-60 wood and
//     soft stone, 5-30 earth and hard rock).
//   - The construction defensive values: 26
//     rows, the print order, pinned as
//     min/max (most rows single-valued; the
//     ranges are building wood 8-16,
//     drawbridge 10-15, gate 8-12, palisade
//     6-12, tower round 40-80, tower square
//     30-50). The barbican value excludes
//     gates and portcullis; the batter,
//     buttress and pilaster values must be
//     destroyed before the supported
//     construction is affected; the rampart
//     is unaffected by catapult missiles,
//     battering or picking; the curtain wall
//     value is for a 10-foot thick wall in a
//     10 x 10 area.
//   - The device MHP: 12 devices on the R213
//     SiegeDevice enum - the ram catcher
//     carries no value in the print (pinned
//     0 with that note).
//   - Additional attack forms: a successful
//     mine breaches a 10-foot wide curtain
//     section or causes 10 points of damage
//     to other constructions; sapping does
//     sow damage but per turn, not per
//     round.
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The firing devices.
// -----------------------------------------------------------------------
enum FireDevice {
    FD_BALLISTA = 0,
    FD_CATAPULT_HEAVY,
    FD_CATAPULT_LIGHT,
    FD_RAM,
    FD_SOW,
    FD_TREBUCHET,
    FD_COUNT
};

inline int fireDeviceCount() { return 6; }

inline int siegeFieldOfFireDegrees(int device) {
    // ballista 45, heavy catapult 15, light
    // catapult 30, trebuchet 10; ram and
    // sow have no missile field
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 45, 15, 30, 0, 0, 10 };
    return t[device];
}

inline int siegeRangeMinQuarterInches(int device) {
    // the minimum range in quarter-inch
    // units (ballista 1/4 inch = 1)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 1, 72, 60, 0, 0, 96 };
    return t[device];
}

inline int siegeRangeMaxQuarterInches(int device) {
    // the maximum range in quarter-inch
    // units (ballista 32 inches = 128)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 128, 144, 120, 1, 1, 192 };
    return t[device];
}

inline int siegeDamageSMMin(int device) {
    // the S-M damage low edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 2, 2, 2, 9, 9, 3 };
    return t[device];
}

inline int siegeDamageSMMax(int device) {
    // the S-M damage high edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 12, 24, 20, 16, 16, 30 };
    return t[device];
}

inline int siegeDamageLMin(int device) {
    // the L damage low edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 3, 4, 3, 7, 13, 5 };
    return t[device];
}

inline int siegeDamageLMax(int device) {
    // the L damage high edge
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 18, 16, 12, 12, 24, 20 };
    return t[device];
}

inline int siegeRateOfFireMinHundredths(int device) {
    // the rate low edge in hundredths
    // (25 = 1/4 per round)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 25, 25, 25, 50, 50, 25 };
    return t[device];
}

inline int siegeRateOfFireMaxHundredths(int device) {
    // the rate high edge in hundredths (the
    // ballista 1/2 with maximum crew)
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 50, 25, 25, 50, 50, 25 };
    return t[device];
}

inline int siegeCrewMin(int device) {
    // the minimum crew for normal rate
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 2, 6, 4, 10, 10, 8 };
    return t[device];
}

inline int siegeCrewMax(int device) {
    // the maximum crew
    if (device < 0) device = 0;
    if (device > 5) device = 5;
    static const int t[6] = { 4, 10, 6, 20, 20, 12 };
    return t[device];
}

inline int siegeBelowMinCrewRatePct() {
    // below the minimum crew the rate drops
    // to at best 50 percent
    return 50;
}

inline int siegeBallistaMaxCrewRateFactor() {
    // only the ballista doubles its rate at
    // maximum crew
    return 2;
}

inline int siegeOtherMaxCrewRateFactor() {
    // all other engines gain nothing above
    // the minimum crew
    return 1;
}

// -----------------------------------------------------------------------
// The hit determination conventions and
// the d20 modifiers.
// -----------------------------------------------------------------------
inline int wmHitTargetAc() {
    // all targets are AC 0 regardless of
    // actual armor class
    return 0;
}

inline int wmBallistaTargetAc() {
    // ballista targets are always AC 10 if
    // exposed to sight
    return 10;
}

inline int wmModTargetStationary() { return 3; }

inline int wmModMoveUnder3() { return 0; }

inline int wmModMove3to12() { return -3; }

inline int wmModSizeMan() { return -2; }

inline int wmModSizeHorse() { return 0; }

inline int wmModSizeGiant() { return 2; }

inline int wmModSizeMediumBuilding() { return 4; }

inline int wmModSizeLargeBuilding() { return 6; }

inline int wmModSubsequentStationary() {
    // subsequent shots after the initial
    // ranging shot, stationary target only
    return 4;
}

inline int wmWeatherCalm() { return 1; }

inline int wmWeatherBreeze() { return 0; }

inline int wmWeatherStrong() { return -2; }

inline int wmWeatherStorm() { return -4; }

inline int wmDirectFireBonus() { return 4; }

inline int wmBallistaInterveningBlocks() {
    // the flat ballista trajectory is
    // interrupted by intervening objects
    return 1;
}

inline int wmCatapultInterveningBlocks() {
    // the arched trajectory passes over
    // intervening objects
    return 0;
}

inline int wmBallistaUnseenFirePossible() {
    // ballista fire is not possible at an
    // unseen target
    return 0;
}

inline int wmUnseenScatterGrenadeRule() {
    // an unseen target is engaged by naming
    // an area and using the grenade-like
    // scatter (the R157 section)
    return 1;
}

inline int wmGrenadeDiameterSmallCatFeet() {
    // small catapult missiles are 1 foot
    // diameter (the R157 cross-link)
    return 1;
}

inline int wmGrenadeDiameterTrebuchetFeet() {
    // trebuchet missiles are 2 feet
    return 2;
}

// -----------------------------------------------------------------------
// The siege attack values: 22 attack forms
// x 4 materials, quarter-point units x4
// (0 = no effect, 1 = 1/4, 2 = 1/2, 4 = 1).
// -----------------------------------------------------------------------
enum SiegeMaterial {
    SM_WOOD = 0,
    SM_EARTH,
    SM_SOFT_STONE,
    SM_HARD_ROCK,
    SM_COUNT
};

enum SiegeAttackKind {
    SK_BIGBY_FIST = 0,
    SK_CATAPULT_MISSILE_HEAVY,
    SK_CATAPULT_MISSILE_LIGHT,
    SK_DIG,
    SK_DISINTEGRATE,
    SK_EARTH_ELEMENTAL,
    SK_EARTHQUAKE,
    SK_FIREBALL,
    SK_GIANT_CLOUD_STONE_STORM,
    SK_GIANT_FIRE_FROST,
    SK_GIANT_HILL,
    SK_BOULDER_CLOUD_FIRE_FROST,
    SK_BOULDER_STONE_STORM,
    SK_GOLEM_IRON,
    SK_GOLEM_STONE,
    SK_HORN_OF_BLASTING,
    SK_LIGHTNING_BOLT,
    SK_MOVE_EARTH,
    SK_RAM,
    SK_SOW,
    SK_TREANT,
    SK_TREBUCHET_MISSILE,
    SK_COUNT
};

inline int siegeAttackKindCount() { return 22; }

inline int siegeAttackQuarterPoints(int kind,
                                    int material) {
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

inline int siegeAttackPerRound(int kind) {
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

inline int siegeAttackPerCasterLevel(int kind) {
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

inline int siegeFireDamageWetReductionPct() {
    // the fireball / lightning bolt clause:
    // green hides or wet wood reduce the
    // damage by 50 percent
    return 50;
}

inline int siegeAttackQuakeMin(int material) {
    // the earthquake dice low edge (5 for
    // every material)
    if (material < 0) material = 0;
    if (material > 3) material = 3;
    static const int t[4] = { 5, 5, 5, 5 };
    return t[material];
}

inline int siegeAttackQuakeMax(int material) {
    // the earthquake dice high edge: wood
    // and soft stone 5-60, earth and hard
    // rock 5-30
    if (material < 0) material = 0;
    if (material > 3) material = 3;
    static const int t[4] = { 60, 30, 60, 30 };
    return t[material];
}

inline int siegeSowScrewEarthOnly() {
    // the sow earth damage is inflicted
    // only if equipped with a screw device
    return 1;
}

inline int siegeSoftStoneIncludes() {
    // soft stone includes fired brick,
    // limestone, sandstone (the footnote
    // convention pinned as a flag)
    return 1;
}

// -----------------------------------------------------------------------
// The construction defensive values: 26
// rows, min and max.
// -----------------------------------------------------------------------
enum DefensiveKind {
    DK_BARBICAN = 0,
    DK_BARTIZAN,
    DK_BATTER,
    DK_BATTLEMENT,
    DK_BUILDING_STONE,
    DK_BUILDING_WOOD,
    DK_BUTTRESS,
    DK_DOOR_IRON,
    DK_DOOR_WOODEN,
    DK_DOOR_REINFORCED,
    DK_DRAWBRIDGE,
    DK_GATE,
    DK_GATEHOUSE,
    DK_HOARDING,
    DK_MERLON,
    DK_PALISADE,
    DK_PARAPET,
    DK_PILASTER,
    DK_PORTCULLIS,
    DK_RAMPART,
    DK_TOWER_ROUND,
    DK_TOWER_SQUARE,
    DK_WALL_BASTION,
    DK_WALL_CURTAIN,
    DK_WINDOW_SHUTTERED,
    DK_WINDOW_BARRED,
    DK_COUNT
};

inline int defensiveKindCount() { return 26; }

inline int constructionDefensiveMin(int kind) {
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

inline int constructionDefensiveMax(int kind) {
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

inline int dkBarbicanExcludesGates() {
    // the barbican value excludes any values
    // for gates or portcullis
    return 1;
}

inline int dkSupportsFallFirst() {
    // the batter, buttress and pilaster
    // points must be destroyed before the
    // supported construction is affected
    return 1;
}

inline int dkRampartUnaffectedByMissiles() {
    // the rampart is unaffected by catapult
    // missiles, battering or picking
    return 1;
}

inline int dkCurtainWallThicknessFeet() {
    // the curtain wall value is for a
    // 10-foot thick wall
    return 10;
}

inline int dkCurtainWallBreachAreaFeet() {
    // the 10 x 10 area basis; a breach, not
    // a hole, needs top-to-bottom
    // destruction
    return 10;
}

// -----------------------------------------------------------------------
// The device MHP: the 12 devices on the
// R213 SiegeDevice enum.
// -----------------------------------------------------------------------
inline int siegeDeviceMhp(int device) {
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

// -----------------------------------------------------------------------
// The additional attack forms.
// -----------------------------------------------------------------------
inline int miningBreachCurtainFeet() {
    // a successful mine breaches a 10-foot
    // wide curtain wall section
    return 10;
}

inline int miningBreachDamagePoints() {
    // or causes 10 points of damage to
    // other sorts of constructions
    return 10;
}

inline int sappingDamagePerTurn() {
    // sapping does the sow damage but per
    // turn, rather than per round
    return 1;
}

}  // namespace rules
