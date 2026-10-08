// ====================================================================
// Adnd1 - rules/miscprose9.h
// R265: the III.E misc magic explanation prose part 9
// (DMG p.134-135) - Drums of Deafening through Eyes
// of Petrification plus the eye-mix note, part2
// lines 402-429 (global = 11065 + part2 line). ONE
// page header strips (417, the TREASURE page) cutting
// the Eversmoking Bottle paragraph mid-sentence (one
// seam, restored). The R264 pointer said four dusts;
// the print shows three. 50 scalar accessors, no
// name collisions with miscprose1.h through
// miscprose8.h. The slice pins kMisc2 rows 19-29 -
// completing the 30-row table (Candle of Invocation
// through Eyes of Petrification). Pure data +
// helpers, header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpDrumDeafDeafRangeInches() {
    // both drums: permanent deafness radius
    return 7;
}

inline int mmpDrumDeafStunRangeInches() {
    // the stun zone radius
    return 1;
}

inline int mmpDrumDeafStunMinRounds() {
    // stunned for from 2-8 rounds
    return 2;
}

inline int mmpDrumDeafStunMaxRounds() {
    // stunned for from 2-8 rounds
    return 8;
}

inline int mmpDrumDeafHemisphereHalfFeet() {
    // each drum: 1.5 feet diameter hemisphere
    return 3;
}

inline int mmpDrumPanicRangeInches() {
    // both drums: the panic radius
    return 12;
}

inline int mmpDrumPanicSafeZoneInches() {
    // the safe zone radius from the drums
    return 2;
}

inline int mmpDrumPanicFleeTurns() {
    // move directly away for 1 full turn
    return 1;
}

inline int mmpDrumPanicRestRoundsPerTurn() {
    // 3 rounds of rest per 1 turn of flight
    return 3;
}

inline int mmpDrumPanicInt2SaveMod() {
    // intelligence of 2 saves at -2
    return -2;
}

inline int mmpDrumPanicInt1SaveMod() {
    // intelligence of 1 or less saves at -4
    return -4;
}

inline int mmpDrumPanicHemisphereHalfFeet() {
    // each drum: 1.5 feet diameter hemisphere
    return 3;
}

inline int mmpDustAppearDurationMinTurns() {
    // appearance lasts for 2-20 turns
    return 2;
}

inline int mmpDustAppearDurationMaxTurns() {
    // appearance lasts for 2-20 turns
    return 20;
}

inline int mmpDustAppearPacketRadiusFeet() {
    // a packet covers a 10 feet radius
    return 10;
}

inline int mmpDustAppearTubeStartFeet() {
    // the cone: 1 feet wide at the start
    return 1;
}

inline int mmpDustAppearTubeEndFeet() {
    // the cone: 15 feet wide at the end
    return 15;
}

inline int mmpDustAppearTubeLengthFeet() {
    // the cone: 20 feet long
    return 20;
}

inline int mmpDustAppearContainerMin() {
    // from 5 to 50 containers in one place
    return 5;
}

inline int mmpDustAppearContainerMax() {
    // from 5 to 50 containers in one place
    return 50;
}

inline int mmpDustGoneDurationMinTurns() {
    // invisibility lasts 2 to 20 turns
    return 2;
}

inline int mmpDustGoneDurationMaxTurns() {
    // invisibility lasts 2 to 20 turns
    return 20;
}

inline int mmpDustGoneSprinkleMinTurns() {
    // carefully sprinkled: 11-20 turns
    return 11;
}

inline int mmpDustGoneSprinkleMaxTurns() {
    // carefully sprinkled: 11-20 turns
    return 20;
}

inline int mmpDustGoneAcBonusPlaces() {
    // armor class 4 places better
    return 4;
}

inline int mmpDustChokeRadiusFeet() {
    // the sneezing fits radius
    return 20;
}

inline int mmpDustChokeDisabledMinRounds() {
    // survivors disabled 5-20 rounds
    return 5;
}

inline int mmpDustChokeDisabledMaxRounds() {
    // survivors disabled 5-20 rounds
    return 20;
}

inline int mmpEfreetiInsanePct() {
    // 10 percent insane, attacks at once
    return 10;
}

inline int mmpEfreetiWishesPct() {
    // 10 percent grants 3 wishes only
    return 10;
}

inline int mmpEfreetiServePct() {
    // the other 80 percent serves normally
    return 80;
}

inline int mmpEfreetiWishCount() {
    // the wishes-only bottle grants 3
    return 3;
}

inline int mmpEfreetiReleaseSegments() {
    // issues from the bottle in but 1 segment
    return 1;
}

inline int mmpEversmokeFirstRoundCubicFeet() {
    // obscures a 50000 cubic foot area
    return 50000;
}

inline int mmpEversmokePerRoundCubicFeet() {
    // 10000 cubic feet more each round
    return 10000;
}

inline int mmpEversmokeMaxCubicFeet() {
    // until 120000 cubic feet are fogged
    return 120000;
}

inline int mmpEyesCharmTargetsPerRound() {
    // one person per round can be looked at
    return 1;
}

inline int mmpEyesCharmBothSaveMod() {
    // both lenses: saves at -2
    return -2;
}

inline int mmpEyesCharmOneSaveMod() {
    // only 1 of a pair: saves at +2
    return 2;
}

inline int mmpEyesEagleVisionFactor() {
    // vision 100 times greater than normal
    return 100;
}

inline int mmpEyesEagleMinDistanceFeet() {
    // at distances of 1 feet or more
    return 1;
}

inline int mmpEyesEagleSeeAtFeet() {
    // sees at 2000 feet
    return 2000;
}

inline int mmpEyesEagleNormalSeeFeet() {
    // what normal sight does at 20 feet
    return 20;
}

inline int mmpEyesEagleSingleStunRounds() {
    // one cusp: dizzy, stunned, for 1 round
    return 1;
}

inline int mmpEyesMinuteVisionFactor() {
    // see 100 times better at 1 feet or less
    return 100;
}

inline int mmpEyesMinuteMaxDistanceFeet() {
    // only within 1 feet
    return 1;
}

inline int mmpEyesPetrifyBasiliskGazePct() {
    // 25 percent work as basilisk gaze
    return 25;
}

inline int mmpEyesMixInsanityMinTurns() {
    // mixing eye types: insanity 2-8 turns
    return 2;
}

inline int mmpEyesMixInsanityMaxTurns() {
    // mixing eye types: insanity 2-8 turns
    return 8;
}

inline int mmpEyesMixInsanityDice() {
    // the insanity lasts 2-8 (2d4) turns
    return 2;
}

}  // namespace rules