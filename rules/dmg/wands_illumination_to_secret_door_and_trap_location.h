// ====================================================================
// Adnd1 - rules/dmg/wands_illumination_to_secret_door_and_trap_location.h
// R247: the III.D wands explanation prose
// pins, part 2 (DMG pp.144-145) - the
// remaining TEN wands of the RODS, et al.
// explanation prose (upload lines
// ~10828-10865):
//   - Wand of Illumination: 4 separate
//     functions, 3 approximating
//     magic-user spells and 1 singular;
//     dancing lights 1 segment 1 charge;
//     light 2 segments 1 charge;
//     continual light 2 segments
//     2 charges; sunburst 12" maximum
//     range, duration 1/10 of a second
//     - pinned as 1 tenth - a globe of
//     4" diameter, undead within take
//     6-36 hp with no saving throw,
//     others blinded 2-12 segments,
//     3 segments 3 charges.
//   - Wand of Illusion: 14" maximum
//     range, 3 segments to commence,
//     1 charge to effect and 1 per
//     round to continue.
//   - Wand of Lightning: 2 functions
//     resembling magic-user spells;
//     shock 1-10 hp no save, metallic
//     armor and shield discounted
//     giving armor class 10, 1 charge;
//     lightning bolt 12-36 hp (6d6,
//     treating 1s as 2s), 2 charges,
//     2 segments; 1 function per round.
//   - Wand of Magic Detection: 3"
//     radius pulse, 1 round operation,
//     1 charge per turn or fraction
//     thereof, 2% cumulative chance
//     per round of malfunction.
//   - Wand of Metal and Mineral
//     Detection: 3" radius, 1 round
//     per operation, 1 charge per
//     full turn.
//   - Wand of Magic Missiles: 2-5 hp
//     damage per missile, 3 segments,
//     1 charge, maximum 2 per round.
//   - Wand of Negation: totally
//     negates any wand function (100%),
//     75% for other devices, 1 segment,
//     once per round, 1 charge; the
//     one wand that cannot be
//     recharged.
//   - Wand of Paralyzation: a thin
//     ray to 6" maximum range,
//     rigidly immobile 5-20 rounds,
//     3 segments, 1 charge, once per
//     round.
//   - Wand of Polymorphing: a thin
//     ray to 6" maximum distance,
//     3 segments, 1 charge,
//     1 function per round.
//   - Wand of Secret Door and Trap
//     Location: radius 1.5 inch for
//     secret doors - pinned as 3
//     half-inches, the first
//     half-inch pin since the 2.25
//     inch quarter-inch of R246 -
//     and 3" for traps, 1 round,
//     1 charge.
// All ten but Negation are
// rechargeable. The ten wands are
// the engine III.D table wand rows
// 6-15 (dm/treasure.cpp kRods, bands
// 48-94); the wand of wonder rows
// begin at band 95.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Wands_illumination_to_secret_door_and_trap_location (instance methods)
class Wands_illumination_to_secret_door_and_trap_location {
public:
    int wdIllumFunctionCount();
    int wdIllumSpellLikeCount();
    int wdIllumDanceSegments();
    int wdIllumDanceCharges();
    int wdIllumLightSegments();
    int wdIllumLightCharges();
    int wdIllumContinualSegments();
    int wdIllumContinualCharges();
    int wdIllumSunburstRangeInches();
    int wdIllumSunburstDurationTenths();
    int wdIllumSunburstGlobeInches();
    int wdIllumSunburstUndeadLo();
    int wdIllumSunburstUndeadHi();
    int wdIllumSunburstBlindLo();
    int wdIllumSunburstBlindHi();
    int wdIllumSunburstSegments();
    int wdIllumSunburstCharges();
    int wdIllumRechargeable();
    int wdIllusionRangeInches();
    int wdIllusionSegments();
    int wdIllusionChargesPerPortion();
    int wdIllusionChargesPerRound();
    int wdIllusionRechargeable();
    int wdLightningFunctionCount();
    int wdLightningShockLo();
    int wdLightningShockHi();
    int wdLightningShockAc();
    int wdLightningShockCharges();
    int wdLightningBoltLo();
    int wdLightningBoltHi();
    int wdLightningBoltDice();
    int wdLightningBoltCharges();
    int wdLightningBoltSegments();
    int wdLightningFunctionsPerRound();
    int wdLightningRechargeable();
    int wdMDetectRadiusInches();
    int wdMDetectRounds();
    int wdMDetectChargesPerTurn();
    int wdMDetectMalfunctionPercent();
    int wdMDetectRechargeable();
    int wdMetalRadiusInches();
    int wdMetalRounds();
    int wdMetalChargesPerTurn();
    int wdMetalRechargeable();
    int wdMissileDamageLo();
    int wdMissileDamageHi();
    int wdMissileSegments();
    int wdMissileCharges();
    int wdMissileMaxPerRound();
    int wdMissileRechargeable();
    int wdNegateWandPercent();
    int wdNegateDevicePercent();
    int wdNegateSegments();
    int wdNegateUsesPerRound();
    int wdNegateCharges();
    int wdNegateRechargeable();
    int wdParalyzeRangeInches();
    int wdParalyzeDurationLo();
    int wdParalyzeDurationHi();
    int wdParalyzeSegments();
    int wdParalyzeCharges();
    int wdParalyzeUsesPerRound();
    int wdParalyzeRechargeable();
    int wdPolyRangeInches();
    int wdPolySegments();
    int wdPolyCharges();
    int wdPolyFunctionsPerRound();
    int wdPolyRechargeable();
    int wdSecretDoorRadiusHalfInches();
    int wdTrapRadiusInches();
    int wdSecretRounds();
    int wdSecretCharges();
    int wdSecretRechargeable();
};
