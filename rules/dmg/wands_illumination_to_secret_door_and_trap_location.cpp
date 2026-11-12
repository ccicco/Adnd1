// R-refactor: split from wands_illumination_to_secret_door_and_trap_location.h - definitions
#include "rules/dmg/wands_illumination_to_secret_door_and_trap_location.h"

int Wands_illumination_to_secret_door_and_trap_location::wdIllumFunctionCount() {
    // Wand of Illumination: 4 separate
    // functions
    return 4;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSpellLikeCount() {
    // 3 approximate magic-user spells,
    // and 1 is singular
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumDanceSegments() {
    // dancing lights: in 1 segment the
    // wand will produce the effect
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumDanceCharges() {
    // at a cost of 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumLightSegments() {
    // light: sent forth in 2 segments
    // time
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumLightCharges() {
    // at an expenditure of 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumContinualSegments() {
    // continual light: only 2 segments
    // to perform
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumContinualCharges() {
    // but the cost is 2 charges
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstRangeInches() {
    // sunburst: the range is 12"
    // maximum
    return 12;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstDurationTenths() {
    // its duration is but 1/10 of a
    // second - pinned as tenths
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstGlobeInches() {
    // a globe of 4" diameter
    return 4;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstUndeadLo() {
    // any undead within the globe take
    // 6-36 hit points of damage, with
    // no saving throw
    return 6;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstUndeadHi() {
    return 36;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstBlindLo() {
    // all others within the globe are
    // blinded for 2-12 segments
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstBlindHi() {
    return 12;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstSegments() {
    // the function requires 3 segments
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumSunburstCharges() {
    // and expends 3 charges
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllumRechargeable() {
    // the wand can be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllusionRangeInches() {
    // Wand of Illusion: a 14" maximum
    // range
    return 14;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllusionSegments() {
    // the effect takes 3 segments to
    // commence
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllusionChargesPerPortion() {
    // it costs 1 charge to effect
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllusionChargesPerRound() {
    // and 1 per round to continue
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdIllusionRechargeable() {
    // the wand may be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningFunctionCount() {
    // Wand of Lightning: 2 functions
    // which closely resemble
    // magic-user spells
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningShockLo() {
    // the shock: 1-10 hit points of
    // damage, with no saving throw
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningShockHi() {
    return 10;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningShockAc() {
    // metallic armor and shield are
    // discounted, giving opponents
    // armor class 10
    return 10;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningShockCharges() {
    // the shock uses 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningBoltLo() {
    // the lightning bolt: damage is
    // 12-36 hit points
    return 12;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningBoltHi() {
    return 36;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningBoltDice() {
    // 6d6, treating 1s as 2s
    return 6;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningBoltCharges() {
    // this function uses 2 charges
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningBoltSegments() {
    // it requires 2 segments to
    // discharge
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningFunctionsPerRound() {
    // it can perform but 1 function
    // per round
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdLightningRechargeable() {
    // the wand may be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMDetectRadiusInches() {
    // Wand of Magic Detection: within
    // a 3" radius the wand will pulse
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMDetectRounds() {
    // operation requires 1 round
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMDetectChargesPerTurn() {
    // 1 charge is expended per turn
    // (or fraction thereof) of use
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMDetectMalfunctionPercent() {
    // there is a 2% cumulative chance
    // per round of a malfunction
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMDetectRechargeable() {
    // the wand may be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMetalRadiusInches() {
    // Wand of Metal and Mineral
    // Detection: also a 3" radius
    // range
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMetalRounds() {
    // each operation requires 1 round
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMetalChargesPerTurn() {
    // each charge powers the wand for
    // 1 full turn
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMetalRechargeable() {
    // the wand may be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMissileDamageLo() {
    // Wand of Magic Missiles: each
    // missile causes 2-5 hit points
    // of damage
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMissileDamageHi() {
    return 5;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMissileSegments() {
    // each missile takes 3 segments to
    // discharge
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMissileCharges() {
    // and costs 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMissileMaxPerRound() {
    // a maximum of 2 may be expended
    // in 1 round
    return 2;
}

int Wands_illumination_to_secret_door_and_trap_location::wdMissileRechargeable() {
    // the wand may be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdNegateWandPercent() {
    // Wand of Negation: this will
    // totally negate any wand function
    return 100;
}

int Wands_illumination_to_secret_door_and_trap_location::wdNegateDevicePercent() {
    // any other device is 75% likely
    // to be negated
    return 75;
}

int Wands_illumination_to_secret_door_and_trap_location::wdNegateSegments() {
    // operation requires but 1 segment
    // of a round
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdNegateUsesPerRound() {
    // it can function but once per
    // round
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdNegateCharges() {
    // each negation drains 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdNegateRechargeable() {
    // the wand cannot be recharged -
    // the only one of the ten
    return 0;
}

int Wands_illumination_to_secret_door_and_trap_location::wdParalyzeRangeInches() {
    // Wand of Paralyzation: a thin
    // ray of bluish color to a
    // maximum range of 6"
    return 6;
}

int Wands_illumination_to_secret_door_and_trap_location::wdParalyzeDurationLo() {
    // struck creatures are rigidly
    // immobile for from 5-20 rounds
    return 5;
}

int Wands_illumination_to_secret_door_and_trap_location::wdParalyzeDurationHi() {
    return 20;
}

int Wands_illumination_to_secret_door_and_trap_location::wdParalyzeSegments() {
    // each operation takes 3 segments
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdParalyzeCharges() {
    // and costs 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdParalyzeUsesPerRound() {
    // the wand may operate once per
    // round
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdParalyzeRechargeable() {
    // it may be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdPolyRangeInches() {
    // Wand of Polymorphing: a thin ray
    // which darts forth to a maximum
    // distance of 6"
    return 6;
}

int Wands_illumination_to_secret_door_and_trap_location::wdPolySegments() {
    // either function requires 3
    // segments
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdPolyCharges() {
    // each draws 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdPolyFunctionsPerRound() {
    // only 1 function per round is
    // possible
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdPolyRechargeable() {
    // the wand may be recharged
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdSecretDoorRadiusHalfInches() {
    // Wand of Secret Door and Trap
    // Location: an effective radius of
    // 1.5 inch for secret door location
    // - pinned as 3 half-inches, the
    // first half-inch pin since the
    // 2.25 inch quarter-inch of R246
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdTrapRadiusInches() {
    // 3" for trap location
    return 3;
}

int Wands_illumination_to_secret_door_and_trap_location::wdSecretRounds() {
    // it requires 1 round to function
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdSecretCharges() {
    // and draws 1 charge
    return 1;
}

int Wands_illumination_to_secret_door_and_trap_location::wdSecretRechargeable() {
    // the wand may be recharged
    return 1;
}
