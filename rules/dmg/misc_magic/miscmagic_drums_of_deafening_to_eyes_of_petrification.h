// ====================================================================
// Adnd1 - rules/dmg/misc_magic/miscmagic_drums_of_deafening_to_eyes_of_petrification.h
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
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_drums_of_deafening_to_eyes_of_petrification {
public:
    int mmpDrumDeafDeafRangeInches();
    int mmpDrumDeafStunRangeInches();
    int mmpDrumDeafStunMinRounds();
    int mmpDrumDeafStunMaxRounds();
    int mmpDrumDeafHemisphereHalfFeet();
    int mmpDrumPanicRangeInches();
    int mmpDrumPanicSafeZoneInches();
    int mmpDrumPanicFleeTurns();
    int mmpDrumPanicRestRoundsPerTurn();
    int mmpDrumPanicInt2SaveMod();
    int mmpDrumPanicInt1SaveMod();
    int mmpDrumPanicHemisphereHalfFeet();
    int mmpDustAppearDurationMinTurns();
    int mmpDustAppearDurationMaxTurns();
    int mmpDustAppearPacketRadiusFeet();
    int mmpDustAppearTubeStartFeet();
    int mmpDustAppearTubeEndFeet();
    int mmpDustAppearTubeLengthFeet();
    int mmpDustAppearContainerMin();
    int mmpDustAppearContainerMax();
    int mmpDustGoneDurationMinTurns();
    int mmpDustGoneDurationMaxTurns();
    int mmpDustGoneSprinkleMinTurns();
    int mmpDustGoneSprinkleMaxTurns();
    int mmpDustGoneAcBonusPlaces();
    int mmpDustChokeRadiusFeet();
    int mmpDustChokeDisabledMinRounds();
    int mmpDustChokeDisabledMaxRounds();
    int mmpEfreetiInsanePct();
    int mmpEfreetiWishesPct();
    int mmpEfreetiServePct();
    int mmpEfreetiWishCount();
    int mmpEfreetiReleaseSegments();
    int mmpEversmokeFirstRoundCubicFeet();
    int mmpEversmokePerRoundCubicFeet();
    int mmpEversmokeMaxCubicFeet();
    int mmpEyesCharmTargetsPerRound();
    int mmpEyesCharmBothSaveMod();
    int mmpEyesCharmOneSaveMod();
    int mmpEyesEagleVisionFactor();
    int mmpEyesEagleMinDistanceFeet();
    int mmpEyesEagleSeeAtFeet();
    int mmpEyesEagleNormalSeeFeet();
    int mmpEyesEagleSingleStunRounds();
    int mmpEyesMinuteVisionFactor();
    int mmpEyesMinuteMaxDistanceFeet();
    int mmpEyesPetrifyBasiliskGazePct();
    int mmpEyesMixInsanityMinTurns();
    int mmpEyesMixInsanityMaxTurns();
    int mmpEyesMixInsanityDice();
};
