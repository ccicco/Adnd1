// ====================================================================
// Adnd1 - rules/wandsprose2.h
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

namespace rules {

inline int wdIllumFunctionCount() {
    // Wand of Illumination: 4 separate
    // functions
    return 4;
}

inline int wdIllumSpellLikeCount() {
    // 3 approximate magic-user spells,
    // and 1 is singular
    return 3;
}

inline int wdIllumDanceSegments() {
    // dancing lights: in 1 segment the
    // wand will produce the effect
    return 1;
}

inline int wdIllumDanceCharges() {
    // at a cost of 1 charge
    return 1;
}

inline int wdIllumLightSegments() {
    // light: sent forth in 2 segments
    // time
    return 2;
}

inline int wdIllumLightCharges() {
    // at an expenditure of 1 charge
    return 1;
}

inline int wdIllumContinualSegments() {
    // continual light: only 2 segments
    // to perform
    return 2;
}

inline int wdIllumContinualCharges() {
    // but the cost is 2 charges
    return 2;
}

inline int wdIllumSunburstRangeInches() {
    // sunburst: the range is 12"
    // maximum
    return 12;
}

inline int wdIllumSunburstDurationTenths() {
    // its duration is but 1/10 of a
    // second - pinned as tenths
    return 1;
}

inline int wdIllumSunburstGlobeInches() {
    // a globe of 4" diameter
    return 4;
}

inline int wdIllumSunburstUndeadLo() {
    // any undead within the globe take
    // 6-36 hit points of damage, with
    // no saving throw
    return 6;
}

inline int wdIllumSunburstUndeadHi() {
    return 36;
}

inline int wdIllumSunburstBlindLo() {
    // all others within the globe are
    // blinded for 2-12 segments
    return 2;
}

inline int wdIllumSunburstBlindHi() {
    return 12;
}

inline int wdIllumSunburstSegments() {
    // the function requires 3 segments
    return 3;
}

inline int wdIllumSunburstCharges() {
    // and expends 3 charges
    return 3;
}

inline int wdIllumRechargeable() {
    // the wand can be recharged
    return 1;
}

inline int wdIllusionRangeInches() {
    // Wand of Illusion: a 14" maximum
    // range
    return 14;
}

inline int wdIllusionSegments() {
    // the effect takes 3 segments to
    // commence
    return 3;
}

inline int wdIllusionChargesPerPortion() {
    // it costs 1 charge to effect
    return 1;
}

inline int wdIllusionChargesPerRound() {
    // and 1 per round to continue
    return 1;
}

inline int wdIllusionRechargeable() {
    // the wand may be recharged
    return 1;
}

inline int wdLightningFunctionCount() {
    // Wand of Lightning: 2 functions
    // which closely resemble
    // magic-user spells
    return 2;
}

inline int wdLightningShockLo() {
    // the shock: 1-10 hit points of
    // damage, with no saving throw
    return 1;
}

inline int wdLightningShockHi() {
    return 10;
}

inline int wdLightningShockAc() {
    // metallic armor and shield are
    // discounted, giving opponents
    // armor class 10
    return 10;
}

inline int wdLightningShockCharges() {
    // the shock uses 1 charge
    return 1;
}

inline int wdLightningBoltLo() {
    // the lightning bolt: damage is
    // 12-36 hit points
    return 12;
}

inline int wdLightningBoltHi() {
    return 36;
}

inline int wdLightningBoltDice() {
    // 6d6, treating 1s as 2s
    return 6;
}

inline int wdLightningBoltCharges() {
    // this function uses 2 charges
    return 2;
}

inline int wdLightningBoltSegments() {
    // it requires 2 segments to
    // discharge
    return 2;
}

inline int wdLightningFunctionsPerRound() {
    // it can perform but 1 function
    // per round
    return 1;
}

inline int wdLightningRechargeable() {
    // the wand may be recharged
    return 1;
}

inline int wdMDetectRadiusInches() {
    // Wand of Magic Detection: within
    // a 3" radius the wand will pulse
    return 3;
}

inline int wdMDetectRounds() {
    // operation requires 1 round
    return 1;
}

inline int wdMDetectChargesPerTurn() {
    // 1 charge is expended per turn
    // (or fraction thereof) of use
    return 1;
}

inline int wdMDetectMalfunctionPercent() {
    // there is a 2% cumulative chance
    // per round of a malfunction
    return 2;
}

inline int wdMDetectRechargeable() {
    // the wand may be recharged
    return 1;
}

inline int wdMetalRadiusInches() {
    // Wand of Metal and Mineral
    // Detection: also a 3" radius
    // range
    return 3;
}

inline int wdMetalRounds() {
    // each operation requires 1 round
    return 1;
}

inline int wdMetalChargesPerTurn() {
    // each charge powers the wand for
    // 1 full turn
    return 1;
}

inline int wdMetalRechargeable() {
    // the wand may be recharged
    return 1;
}

inline int wdMissileDamageLo() {
    // Wand of Magic Missiles: each
    // missile causes 2-5 hit points
    // of damage
    return 2;
}

inline int wdMissileDamageHi() {
    return 5;
}

inline int wdMissileSegments() {
    // each missile takes 3 segments to
    // discharge
    return 3;
}

inline int wdMissileCharges() {
    // and costs 1 charge
    return 1;
}

inline int wdMissileMaxPerRound() {
    // a maximum of 2 may be expended
    // in 1 round
    return 2;
}

inline int wdMissileRechargeable() {
    // the wand may be recharged
    return 1;
}

inline int wdNegateWandPercent() {
    // Wand of Negation: this will
    // totally negate any wand function
    return 100;
}

inline int wdNegateDevicePercent() {
    // any other device is 75% likely
    // to be negated
    return 75;
}

inline int wdNegateSegments() {
    // operation requires but 1 segment
    // of a round
    return 1;
}

inline int wdNegateUsesPerRound() {
    // it can function but once per
    // round
    return 1;
}

inline int wdNegateCharges() {
    // each negation drains 1 charge
    return 1;
}

inline int wdNegateRechargeable() {
    // the wand cannot be recharged -
    // the only one of the ten
    return 0;
}

inline int wdParalyzeRangeInches() {
    // Wand of Paralyzation: a thin
    // ray of bluish color to a
    // maximum range of 6"
    return 6;
}

inline int wdParalyzeDurationLo() {
    // struck creatures are rigidly
    // immobile for from 5-20 rounds
    return 5;
}

inline int wdParalyzeDurationHi() {
    return 20;
}

inline int wdParalyzeSegments() {
    // each operation takes 3 segments
    return 3;
}

inline int wdParalyzeCharges() {
    // and costs 1 charge
    return 1;
}

inline int wdParalyzeUsesPerRound() {
    // the wand may operate once per
    // round
    return 1;
}

inline int wdParalyzeRechargeable() {
    // it may be recharged
    return 1;
}

inline int wdPolyRangeInches() {
    // Wand of Polymorphing: a thin ray
    // which darts forth to a maximum
    // distance of 6"
    return 6;
}

inline int wdPolySegments() {
    // either function requires 3
    // segments
    return 3;
}

inline int wdPolyCharges() {
    // each draws 1 charge
    return 1;
}

inline int wdPolyFunctionsPerRound() {
    // only 1 function per round is
    // possible
    return 1;
}

inline int wdPolyRechargeable() {
    // the wand may be recharged
    return 1;
}

inline int wdSecretDoorRadiusHalfInches() {
    // Wand of Secret Door and Trap
    // Location: an effective radius of
    // 1.5 inch for secret door location
    // - pinned as 3 half-inches, the
    // first half-inch pin since the
    // 2.25 inch quarter-inch of R246
    return 3;
}

inline int wdTrapRadiusInches() {
    // 3" for trap location
    return 3;
}

inline int wdSecretRounds() {
    // it requires 1 round to function
    return 1;
}

inline int wdSecretCharges() {
    // and draws 1 charge
    return 1;
}

inline int wdSecretRechargeable() {
    // the wand may be recharged
    return 1;
}

}  // namespace rules

