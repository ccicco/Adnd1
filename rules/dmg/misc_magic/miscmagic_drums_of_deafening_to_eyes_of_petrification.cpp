// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_drums_of_deafening_to_eyes_of_petrification.h"

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumDeafDeafRangeInches() {
    // both drums: permanent deafness radius
    return 7;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumDeafStunRangeInches() {
    // the stun zone radius
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumDeafStunMinRounds() {
    // stunned for from 2-8 rounds
    return 2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumDeafStunMaxRounds() {
    // stunned for from 2-8 rounds
    return 8;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumDeafHemisphereHalfFeet() {
    // each drum: 1.5 feet diameter hemisphere
    return 3;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumPanicRangeInches() {
    // both drums: the panic radius
    return 12;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumPanicSafeZoneInches() {
    // the safe zone radius from the drums
    return 2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumPanicFleeTurns() {
    // move directly away for 1 full turn
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumPanicRestRoundsPerTurn() {
    // 3 rounds of rest per 1 turn of flight
    return 3;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumPanicInt2SaveMod() {
    // intelligence of 2 saves at -2
    return -2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumPanicInt1SaveMod() {
    // intelligence of 1 or less saves at -4
    return -4;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDrumPanicHemisphereHalfFeet() {
    // each drum: 1.5 feet diameter hemisphere
    return 3;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearDurationMinTurns() {
    // appearance lasts for 2-20 turns
    return 2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearDurationMaxTurns() {
    // appearance lasts for 2-20 turns
    return 20;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearPacketRadiusFeet() {
    // a packet covers a 10 feet radius
    return 10;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearTubeStartFeet() {
    // the cone: 1 feet wide at the start
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearTubeEndFeet() {
    // the cone: 15 feet wide at the end
    return 15;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearTubeLengthFeet() {
    // the cone: 20 feet long
    return 20;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearContainerMin() {
    // from 5 to 50 containers in one place
    return 5;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustAppearContainerMax() {
    // from 5 to 50 containers in one place
    return 50;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustGoneDurationMinTurns() {
    // invisibility lasts 2 to 20 turns
    return 2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustGoneDurationMaxTurns() {
    // invisibility lasts 2 to 20 turns
    return 20;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustGoneSprinkleMinTurns() {
    // carefully sprinkled: 11-20 turns
    return 11;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustGoneSprinkleMaxTurns() {
    // carefully sprinkled: 11-20 turns
    return 20;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustGoneAcBonusPlaces() {
    // armor class 4 places better
    return 4;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustChokeRadiusFeet() {
    // the sneezing fits radius
    return 20;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustChokeDisabledMinRounds() {
    // survivors disabled 5-20 rounds
    return 5;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpDustChokeDisabledMaxRounds() {
    // survivors disabled 5-20 rounds
    return 20;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEfreetiInsanePct() {
    // 10 percent insane, attacks at once
    return 10;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEfreetiWishesPct() {
    // 10 percent grants 3 wishes only
    return 10;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEfreetiServePct() {
    // the other 80 percent serves normally
    return 80;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEfreetiWishCount() {
    // the wishes-only bottle grants 3
    return 3;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEfreetiReleaseSegments() {
    // issues from the bottle in but 1 segment
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEversmokeFirstRoundCubicFeet() {
    // obscures a 50000 cubic foot area
    return 50000;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEversmokePerRoundCubicFeet() {
    // 10000 cubic feet more each round
    return 10000;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEversmokeMaxCubicFeet() {
    // until 120000 cubic feet are fogged
    return 120000;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesCharmTargetsPerRound() {
    // one person per round can be looked at
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesCharmBothSaveMod() {
    // both lenses: saves at -2
    return -2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesCharmOneSaveMod() {
    // only 1 of a pair: saves at +2
    return 2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesEagleVisionFactor() {
    // vision 100 times greater than normal
    return 100;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesEagleMinDistanceFeet() {
    // at distances of 1 feet or more
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesEagleSeeAtFeet() {
    // sees at 2000 feet
    return 2000;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesEagleNormalSeeFeet() {
    // what normal sight does at 20 feet
    return 20;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesEagleSingleStunRounds() {
    // one cusp: dizzy, stunned, for 1 round
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesMinuteVisionFactor() {
    // see 100 times better at 1 feet or less
    return 100;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesMinuteMaxDistanceFeet() {
    // only within 1 feet
    return 1;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesPetrifyBasiliskGazePct() {
    // 25 percent work as basilisk gaze
    return 25;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesMixInsanityMinTurns() {
    // mixing eye types: insanity 2-8 turns
    return 2;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesMixInsanityMaxTurns() {
    // mixing eye types: insanity 2-8 turns
    return 8;
}

int Miscmagic_drums_of_deafening_to_eyes_of_petrification::mmpEyesMixInsanityDice() {
    // the insanity lasts 2-8 (2d4) turns
    return 2;
}
