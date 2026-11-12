// ====================================================================
// Adnd1 - rules/dmg/misc_magic/horn_of_collapsing_to_incense_of_meditation.h
// R269: the III.E misc magic explanation prose part 13
// (DMG p.139-140) - Horn of Collapsing through the
// Incense of Meditation, part2 lines 581-626 (global =
// 11065 + part2 line). ONE page header inside the slice
// (592, the TREASURE page) cuts the Collapsing proper
// use paragraph mid-sentence (one seam, restored). ONE
// OCR artifact restored from the compilation (the R175
// precedent): the meditation survival clause reads
// (rounded down), the upload prints grounded down).
// 73 accessors: 60 scalars + 13 array walkers (the
// triton summon and the Valhalla variety tables), no
// name collisions with miscprose1.h through
// miscprose12.h. The slice pins kMisc3 rows 18-23: the
// (C, F) mark on the Horn of the Tritons (row 19), the
// (C) mark on the Incense of Meditation (row 23), the
// Valhalla double asterisk (row 20). Pure data +
// helpers, header-only (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_horn_of_collapsing_to_incense_of_meditation {
public:
    int mmpHornCollapseMisfirePct();
    int mmpHornCollapseOutRocksMin();
    int mmpHornCollapseOutRocksMax();
    int mmpHornCollapseOutRockDmgMin();
    int mmpHornCollapseOutRockDmgMax();
    int mmpHornCollapseIndoorDmgMin();
    int mmpHornCollapseIndoorDmgMax();
    int mmpHornCollapseUnderDmgMin();
    int mmpHornCollapseUnderDmgMax();
    int mmpHornCollapseUnderHeightFactorFeet();
    int mmpHornCollapseAimRangeMinFeet();
    int mmpHornCollapseAimRangeMaxFeet();
    int mmpHornCollapseRoofWidthFeet();
    int mmpHornCollapseRoofLengthFeet();
    int mmpHornCollapseRoofRadiusFeet();
    int mmpHornCollapseIndoorsOrUndergroundOnly();
    int mmpHornTritonPerDay();
    int mmpHornTritonTritonPerDay();
    int mmpHornTritonFunctionCount();
    int mmpHornTritonCalmRadiusMiles();
    int mmpHornTritonCalmDispelKinds();
    int mmpHornTritonSummonKindCount();
    int mmpHornTritonSummonDieLo(int i);
    int mmpHornTritonSummonDieHi(int i);
    int mmpHornTritonSummonCountMin(int i);
    int mmpHornTritonSummonCountMax(int i);
    int mmpHornTritonPanicAnimalOrLower();
    int mmpHornTritonPanicToHitPenalty();
    int mmpHornTritonPanicTurnsMin();
    int mmpHornTritonPanicTurnsMax();
    int mmpHornTritonPanicRoundsPerTurn();
    int mmpHornTritonPanicRoundsMin();
    int mmpHornTritonPanicRoundsMax();
    int mmpHornTritonHearRadiusLeagues();
    int mmpHornValhallaVarietyCount();
    int mmpHornValhallaBlowIntervalDays();
    int mmpHornValhallaSummonedAc();
    int mmpHornValhallaSummonedHpPerDie();
    int mmpHornValhallaSwordSpearPct();
    int mmpHornValhallaAxeSpearPct();
    int mmpHornValhallaServiceTurns();
    int mmpHornValhallaAlignedPct();
    int mmpHornValhallaBronzeXpMultiplier();
    int mmpHornValhallaIronXpMultiplier();
    int mmpHornValhallaDiceLo(int i);
    int mmpHornValhallaDiceHi(int i);
    int mmpHornValhallaCountMin(int i);
    int mmpHornValhallaCountMax(int i);
    int mmpHornValhallaLevel(int i);
    int mmpHornValhallaUsableAny(int i);
    int mmpHornValhallaUsableCleric(int i);
    int mmpHornValhallaUsableFighter(int i);
    int mmpHornValhallaUsableThief(int i);
    int mmpHorseshoesSpeedShoeCount();
    int mmpHorseshoesSpeedFullPct();
    int mmpHorseshoesSpeedDropPct();
    int mmpHorseshoesSpeedDropLeagues();
    int mmpHorseshoesSpeedOneLostPct();
    int mmpHorseshoesSpeedTwoLostPct();
    int mmpHorseshoesZephyrGroundless();
    int mmpHorseshoesZephyrNoTracks();
    int mmpHorseshoesZephyrNoTireHours();
    int mmpHorseshoesZephyrPerDay();
    int mmpIncenseMedRecognizeClericLevel();
    int mmpIncenseMedPrayHours();
    int mmpIncenseMedCureAlwaysMax();
    int mmpIncenseMedBroadestArea();
    int mmpIncenseMedSavePenalty();
    int mmpIncenseMedNotSurvivingDivisor();
    int mmpIncenseMedPieceCountMin();
    int mmpIncenseMedPieceCountMax();
    int mmpIncenseMedBurnHours();
    int mmpIncenseMedEffectHours();
};
