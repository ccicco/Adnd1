// ====================================================================
// Adnd1 - rules/dmg/siegefire.h
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

// R-refactor: namespace rules -> class Siegefire (instance methods)
class Siegefire {
public:
    int fireDeviceCount();
    int siegeFieldOfFireDegrees(int device);
    int siegeRangeMinQuarterInches(int device);
    int siegeRangeMaxQuarterInches(int device);
    int siegeDamageSMMin(int device);
    int siegeDamageSMMax(int device);
    int siegeDamageLMin(int device);
    int siegeDamageLMax(int device);
    int siegeRateOfFireMinHundredths(int device);
    int siegeRateOfFireMaxHundredths(int device);
    int siegeCrewMin(int device);
    int siegeCrewMax(int device);
    int siegeBelowMinCrewRatePct();
    int siegeBallistaMaxCrewRateFactor();
    int siegeOtherMaxCrewRateFactor();


// -----------------------------------------------------------------------
// The hit determination conventions and
// the d20 modifiers.
// -----------------------------------------------------------------------
    int wmHitTargetAc();
    int wmBallistaTargetAc();
    int wmModTargetStationary();
    int wmModMoveUnder3();
    int wmModMove3to12();
    int wmModSizeMan();
    int wmModSizeHorse();
    int wmModSizeGiant();
    int wmModSizeMediumBuilding();
    int wmModSizeLargeBuilding();
    int wmModSubsequentStationary();
    int wmWeatherCalm();
    int wmWeatherBreeze();
    int wmWeatherStrong();
    int wmWeatherStorm();
    int wmDirectFireBonus();
    int wmBallistaInterveningBlocks();
    int wmCatapultInterveningBlocks();
    int wmBallistaUnseenFirePossible();
    int wmUnseenScatterGrenadeRule();
    int wmGrenadeDiameterSmallCatFeet();
    int wmGrenadeDiameterTrebuchetFeet();
    int siegeAttackKindCount();
    int siegeAttackQuarterPoints(int kind, int material);
    int siegeAttackPerRound(int kind);
    int siegeAttackPerCasterLevel(int kind);
    int siegeFireDamageWetReductionPct();
    int siegeAttackQuakeMin(int material);
    int siegeAttackQuakeMax(int material);
    int siegeSowScrewEarthOnly();
    int siegeSoftStoneIncludes();
    int defensiveKindCount();
    int constructionDefensiveMin(int kind);
    int constructionDefensiveMax(int kind);
    int dkBarbicanExcludesGates();
    int dkSupportsFallFirst();
    int dkRampartUnaffectedByMissiles();
    int dkCurtainWallThicknessFeet();
    int dkCurtainWallBreachAreaFeet();


// -----------------------------------------------------------------------
// The device MHP: the 12 devices on the
// R213 SiegeDevice enum.
// -----------------------------------------------------------------------
    int siegeDeviceMhp(int device);


// -----------------------------------------------------------------------
// The additional attack forms.
// -----------------------------------------------------------------------
    int miningBreachCurtainFeet();
    int miningBreachDamagePoints();
    int sappingDamagePerTurn();
};
