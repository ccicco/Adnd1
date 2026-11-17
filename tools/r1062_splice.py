#!/usr/bin/env python3
# r1062_splice.py - the R1062 special-artifact family de-wire tool.
#
# Base: 23c67737 (R1061). Target: the 54 retiring static arrays
# of rules/dmg/specart.h (5) and rules/dmg/specart_prose_part2.h
# (49) ride items::MiscItemRegistry from content/tables/specart/
# (2 rowless defs, 54 named tables, one pin per def). The 499
# KEPT zero-arg scalars (specart.h 5, specart_prose_part1.h 20,
# specart_prose_part2.h 474) stay C++ and are probed at the
# edges. The only caller is regtest.cpp (the r280-r29x pin
# fragments keep their value-level pins; they are untouched).
# Census 1135 -> 1143.
#
# Hardening (R1059/R1061 lessons): mixed-splice-state loud die;
# the already-applied path dies if the frag or the regtest
# include is missing, and regenerates a stale/buggy frag from
# the checksum-verified lua values ("frag refreshed"); pristine
# md5 guards on BOTH headers; array values are PARSED from the
# pristine headers and verified against embedded (width, sum)
# checksums; the KEPT scalars are PARSED from the pristine
# headers and verified against the embedded (fn, value) list -
# nothing is retyped.
#
# Idempotent: rerun reports "already 54" and changes nothing.
# No backslashes appear in this source; @N@ tokens become
# backslash-n at emit time.

import os
import re
import sys
import hashlib

PRISTINE_MD5_A = "4acfd91688081423a1a8accd213895dc"   # specart.h
PRISTINE_MD5_B = "d2f050f6e136ce19b2df17f454742525"   # specart_prose_part2.h

MARK = "// R1062 applied"
SEAM_REL = os.path.join("rules", "seams", "specreg.h")
FRAG_REL = os.path.join("rules", "audits", "r1062_specart_registry.h")
LUA_DIR = os.path.join("content", "tables", "specart")
HDR_A = os.path.join("rules", "dmg", "specart.h")
HDR_B = os.path.join("rules", "dmg", "specart_prose_part2.h")
HDR_P1 = os.path.join("rules", "dmg", "specart_prose_part1.h")
REGTEST_REL = "regtest.cpp"

# (fn, dkey, tag, width, sum) - the 54 retiring arrays.
SPECS = [
    ("saRowLo", "specart", "row_lo", 29, 1238),
    ("saRowHi", "specart", "row_hi", 29, 1309),
    ("saSaleGp", "specart", "sale_gp", 29, 1722000),
    ("saSaleGpHi", "specart", "sale_gp_hi", 29, 80000),
    ("saXpValue", "specart", "xp_value", 29, 0),
    ("sapAxePowerCount", "specart_prose", "axe_power_count", 6, 7),
    ("sapHutMoveInches", "specart_prose", "hut_move_inches", 3, 96),
    ("sapHutPowerCount", "specart_prose", "hut_power_count", 6, 10),
    ("sapCodexPowerCount", "specart_prose", "codex_power_count", 6, 16),
    ("sapCrownAlignBandLo", "specart_prose", "crown_align_band_lo", 3, 23),
    ("sapCrownAlignBandHi", "specart_prose", "crown_align_band_hi", 3, 40),
    ("sapCrownWornPowerCount", "specart_prose", "crown_worn_power_count", 3, 4),
    ("sapCrownSet2ndPowerCount", "specart_prose", "crown_set2nd_power_count", 2, 2),
    ("sapCrownSet3rdPowerCount", "specart_prose", "crown_set3rd_power_count", 5, 5),
    ("sapCrystalPowerCount", "specart_prose", "crystal_power_count", 6, 10),
    ("sapCupPowerCount", "specart_prose", "cup_power_count", 3, 5),
    ("sapTalismanPowerCount", "specart_prose", "talisman_power_count", 4, 3),
    ("sapCupTalismanBothPowerCount", "specart_prose", "cup_talisman_both_power_count", 2, 2),
    ("sapCupTalismanPotionBandLo", "specart_prose", "cup_talisman_potion_band_lo", 6, 72),
    ("sapCupTalismanPotionBandHi", "specart_prose", "cup_talisman_potion_band_hi", 6, 86),
    ("sapEyePowerCount", "specart_prose", "eye_power_count", 5, 6),
    ("sapHandPowerCount", "specart_prose", "hand_power_count", 6, 22),
    ("sapOrganPowerCount", "specart_prose", "organ_power_count", 6, 34),
    ("sapHornBlastPowerTable", "specart_prose", "horn_blast_power_table", 3, 8),
    ("sapHornBlastEffectTable", "specart_prose", "horn_blast_effect_table", 3, 13),
    ("sapCoatPowerCount", "specart_prose", "coat_power_count", 6, 10),
    ("sapFlaskPowerCount", "specart_prose", "flask_power_count", 6, 6),
    ("sapJacinthPowerCount", "specart_prose", "jacinth_power_count", 6, 8),
    ("sapMaskPowerCount", "specart_prose", "mask_power_count", 6, 4),
    ("sapQuillPowerCount", "specart_prose", "quill_power_count", 6, 5),
    ("sapMacePowerCount", "specart_prose", "mace_power_count", 6, 6),
    ("sapMachinePowerCount", "specart_prose", "machine_power_count", 6, 70),
    ("sapServantPowerCount", "specart_prose", "servant_power_count", 6, 17),
    ("sapOrbHatchlingPowerCount", "specart_prose", "orb_hatchling_power_count", 6, 3),
    ("sapOrbWyrmkinPowerCount", "specart_prose", "orb_wyrmkin_power_count", 6, 3),
    ("sapOrbDragonettePowerCount", "specart_prose", "orb_dragonette_power_count", 6, 5),
    ("sapOrbDragonPowerCount", "specart_prose", "orb_dragon_power_count", 6, 6),
    ("sapOrbGreatSerpentPowerCount", "specart_prose", "orb_great_serpent_power_count", 6, 7),
    ("sapOrbFiredrakePowerCount", "specart_prose", "orb_firedrake_power_count", 6, 9),
    ("sapOrbElderWyrmPowerCount", "specart_prose", "orb_elder_wyrm_power_count", 6, 12),
    ("sapOrbEternalPowerCount", "specart_prose", "orb_eternal_power_count", 6, 13),
    ("sapOrbMightPowerCount", "specart_prose", "orb_might_power_count", 6, 3),
    ("sapNightingalePowerCount", "specart_prose", "nightingale_power_count", 6, 8),
    ("sapRecorderPowerCount", "specart_prose", "recorder_power_count", 6, 11),
    ("sapGaxxPowerCount", "specart_prose", "gaxx_power_count", 6, 9),
    ("sapRodJointTable", "specart_prose", "rod_joint_table", 6, 17),
    ("sapRodJointUseCount", "specart_prose", "rod_joint_use_count", 6, 6),
    ("sapRodCompleteTableUse", "specart_prose", "rod_complete_table_use", 6, 7),
    ("sapSceptreTableUse", "specart_prose", "sceptre_table_use", 6, 3),
    ("sapKasTableUse", "specart_prose", "kas_table_use", 6, 13),
    ("sapToothTableUse", "specart_prose", "tooth_table_use", 6, 32),
    ("sapToothSetRightUse", "specart_prose", "tooth_set_right_use", 6, 8),
    ("sapThroneTableUse", "specart_prose", "throne_table_use", 6, 14),
    ("sapWandTableUse", "specart_prose", "wand_table_use", 6, 10),
]


# (fn, literal) - the 499 KEPT zero-arg scalars, parse-verified.
KEEPS = [
    ("saRowCount", 29),
    ("saNoXpRowCount", 29),
    ("saDualRangeCount", 1),
    ("saNoSaleRowCount", 1),
    ("saPerToothRowCount", 1),
    ("sapOneOfEachExists", 1),
    ("sapListingCrossedWhenPlaced", 1),
    ("sapUnavailableOptionCount", 2),
    ("sapPowersPartiallyDescribed", 1),
    ("sapDmAssignsMajorPowers", 1),
    ("sapLoreFoundByChance", 0),
    ("sapNemesisSometimesNeeded", 1),
    ("sapPowerTableCount", 5),
    ("sapHenchBehaviorCount", 3),
    ("sapBehaviorEvilDestroysOrEscapes", 1),
    ("sapBehaviorNeutralDominates", 1),
    ("sapBehaviorGoodDefectsWithItem", 1),
    ("sapLoyaltyDropMinPct", 10),
    ("sapLoyaltyDropMaxPct", 30),
    ("sapDestroyedBySingleMeans", 1),
    ("sapDefaceSavePenalty", -5),
    ("sapDefaceFailureIsDeath", 1),
    ("sapCorruptionTraitCount", 4),
    ("sapEffectsArePermanent", 1),
    ("sapDeityMayReverseSome", 1),
    ("sapAxeBladeSharpness", 1),
    ("sapAxeHammerBonus", 3),
    ("sapAxeHandleForms", 2),
    ("sapAxeReturnFeet", 30),
    ("sapAxeDwarfAbilityMultiplier", 2),
    ("sapAxeLifespanBonusPct", 50),
    ("sapAxeBearsCurse", 1),
    ("sapAxeInvokedDevastationLost", 1),
    ("sapAxePowerTotal", 7),
    ("sapHutDiameterFeet", 15),
    ("sapHutHeightFeet", 10),
    ("sapHutLegCount", 2),
    ("sapHutLegLengthFeet", 12),
    ("sapHutInfravisionFeet", 120),
    ("sapHutRoomCount", 30),
    ("sapHutFloorCount", 3),
    ("sapHutMoveTerrainCount", 3),
    ("sapHutCommanderCount", 1),
    ("sapHutCallRangeLeagues", 1),
    ("sapHutLegAttacksPerRound", 2),
    ("sapHutLegArmorClass", 2),
    ("sapHutLegHpEach", 48),
    ("sapHutLegRegenPerRound", 1),
    ("sapHutWallGraniteFeet", 5),
    ("sapHutLegsHillGiantBlows", 1),
    ("sapHutPowerTotal", 10),
    ("sapCodexDamnedPages", 99),
    ("sapCodexDoomChancePct", 99),
    ("sapCodexPerilPerPagePct", 1),
    ("sapCodexTouchKillBelowLevel", 11),
    ("sapCodexCommandMinLevel", 11),
    ("sapCodexPerusalActivation", 1),
    ("sapCodexPowerTotal", 16),
    ("sapCrownRegaliaSetCount", 3),
    ("sapCrownItemsPerSet", 3),
    ("sapCrownChampionEthosCount", 3),
    ("sapCrownPossessionBenefits", 1),
    ("sapCrownWrongEthosDamageMin", 5),
    ("sapCrownWrongEthosDamageMax", 30),
    ("sapCrownWrongEthosSaveOrDeath", 1),
    ("sapCrownWearerLevelBonus", 1),
    ("sapCrownWornPowerTotal", 4),
    ("sapCrownOffEthosMalevolentCount", 1),
    ("sapCrownOffEthosMalevolentTable", 4),
    ("sapCrownSet2ndPowerTotal", 2),
    ("sapCrownSet3rdPowerTotal", 5),
    ("sapCrownDetectionRevealsAlignment", 0),
    ("sapCrownGemCount", 3),
    ("sapCrownSaleGpMin", 50000),
    ("sapCrystalOriginUnknown", 1),
    ("sapCrystalDiamondHard", 1),
    ("sapCrystalTouchRaysBlackFlame", 1),
    ("sapCrystalCharmRadiusFeet", 30),
    ("sapCrystalCharmIsFireCharm", 1),
    ("sapCrystalPowersByGazing", 1),
    ("sapCrystalPowerTotal", 10),
    ("sapCupTalismanRelicCount", 2),
    ("sapCupTalismanPaynimGift", 1),
    ("sapCupTalismanInvokedDevastationEra", 1),
    ("sapCupTalismanLostToRaiders", 1),
    ("sapCupTalismanPotionClassCount", 4),
    ("sapCupTalismanPotionPerWeek", 1),
    ("sapCupGemCount", 12),
    ("sapCupJewelryGpMin", 75000),
    ("sapCupRadiatesMagic", 0),
    ("sapCupPowerTotal", 5),
    ("sapTalismanPointCount", 8),
    ("sapTalismanPointGemCount", 8),
    ("sapTalismanBeadSetCount", 8),
    ("sapTalismanBeadsPerSet", 3),
    ("sapTalismanJewelryGpMin", 10000),
    ("sapTalismanRadiatesMagic", 0),
    ("sapTalismanPowerTotal", 3),
    ("sapCupTalismanBothPowerTotal", 2),
    ("sapCupTalismanPotionBandCount", 6),
    ("sapEyeVecnaPhantomRoams", 1),
    ("sapEyeDoomSurvivors", 2),
    ("sapEyeFeralGlow", 1),
    ("sapEyeAppearsAgate", 1),
    ("sapEyeGraftIrrevocable", 1),
    ("sapEyeHostNeutralEvil", 1),
    ("sapEyeGrantsInfravision", 1),
    ("sapEyeGrantsUltravision", 1),
    ("sapEyePowerTotal", 6),
    ("sapEyePrimaryPowerMalevolent", 1),
    ("sapHandVecnaLeftHand", 1),
    ("sapHandMummifiedExtremity", 1),
    ("sapHandGripStrength", 18),
    ("sapHandGripStrengthRating", 0),
    ("sapHandGripHitOrDamageBonus", 0),
    ("sapHandHostTurnsNeutralEvil", 1),
    ("sapHandMajorPowerWakesSpirit", 1),
    ("sapHandPrimaryPowerInstantEvil", 1),
    ("sapHandSeverBaseChancePct", 100),
    ("sapHandSeverMajorPenaltyPct", 1),
    ("sapHandSeverPrimaryPenaltyPct", 10),
    ("sapHandNoRemovalAtLimit", 1),
    ("sapHandFingerCombinations", 1),
    ("sapHandPowerTotal", 22),
    ("sapHandGodsOnlyAlteration", 1),
    ("sapHandRecordCombinations", 1),
    ("sapOrganPipeCount", 77),
    ("sapOrganStopCount", 13),
    ("sapOrganPedalCount", 3),
    ("sapOrganBellowsElemental", 1),
    ("sapOrganStopsVaryVoice", 1),
    ("sapOrganKeysVaryNotes", 1),
    ("sapOrganPedalPurposeUnknown", 1),
    ("sapOrganStillWorksDespiteTime", 1),
    ("sapOrganWrongStopsSummon", 1),
    ("sapOrganWrongKeysBackfire", 1),
    ("sapOrganMisplayAlignment", 1),
    ("sapOrganDmAssignsStopsKeys", 1),
    ("sapOrganPowerTotal", 34),
    ("sapOrganMisplayNegates", 1),
    ("sapHornResemblesCommonHorns", 1),
    ("sapHornSuggestedPowerPct", 75),
    ("sapHornSuggestedEffectPct", 25),
    ("sapHornIgnoresInappropriate", 1),
    ("sapCoatArndOfTdon", 1),
    ("sapCoatChainLinksWeightless", 1),
    ("sapCoatCoveredAreaCount", 3),
    ("sapCoatMinWearerHeightFt", 3),
    ("sapCoatMaxWearerHeightFt", 8),
    ("sapCoatInvulnerableCovered", 1),
    ("sapCoatUncoveredAc", 5),
    ("sapCoatSaveBonus", 5),
    ("sapCoatFireResistance", 1),
    ("sapCoatElementalImmunityCount", 3),
    ("sapCoatPowerTotal", 10),
    ("sapFlaskHeavyUrn", 1),
    ("sapFlaskTurnipPlug", 1),
    ("sapFlaskSigilRunes", 1),
    ("sapFlaskWordCount", 3),
    ("sapFlaskPrisonerCount", 5),
    ("sapFlaskServantEvilOnly", 1),
    ("sapFlaskKillBeforeReturn", 1),
    ("sapFlaskPowerTotal", 6),
    ("sapJacinthGodFashioned", 1),
    ("sapJacinthMountainHeart", 1),
    ("sapJacinthFacetedBeams", 1),
    ("sapJacinthCharmRangeFt", 20),
    ("sapJacinthSultanPossessed", 1),
    ("sapJacinthKeolandTrailLost", 1),
    ("sapJacinthGraspPowers", 1),
    ("sapJacinthPowerTotal", 8),
    ("sapMaskJohydeeTrickedEvil", 1),
    ("sapMaskOverthrewNation", 1),
    ("sapMaskCoversFace", 1),
    ("sapMaskAssumeLikeness", 1),
    ("sapMaskBlocksMindContact", 1),
    ("sapMaskGazeImmunity", 1),
    ("sapMaskGazeCreatureCount", 3),
    ("sapMaskPowerTotal", 4),
    ("sapQuillMasterThiefBest", 1),
    ("sapQuillUnknownAntiquity", 1),
    ("sapQuillBearsKurothName", 1),
    ("sapQuillInfallibleScribe", 1),
    ("sapQuillDepictsSeenSpoken", 1),
    ("sapQuillPotionTreasureFinding", 1),
    ("sapQuillTreasureFindPerMonth", 1),
    ("sapQuillPowerTotal", 5),
    ("sapMaceSaintCuthbertWeapon", 1),
    ("sapMaceFollyOfError", 1),
    ("sapMaceRelicsEncased", 1),
    ("sapMaceHitDamageBonus", 5),
    ("sapMaceDisruptionEffects", 1),
    ("sapMaceClericStrReq", 18),
    ("sapMaceLawfulGoodOnly", 1),
    ("sapMacePowerTotal", 6),
    ("sapMachineGodsForgotten", 1),
    ("sapMachineWorkmanshipUnknown", 1),
    ("sapMachineBaronLumEmpire", 1),
    ("sapMachineLeverCount", 60),
    ("sapMachineDialCount", 40),
    ("sapMachineSwitchCount", 20),
    ("sapMachineControlsTotal", 120),
    ("sapMachineHalfFunction", 60),
    ("sapMachineWeightLb", 5500),
    ("sapMachineJoltDestroyMax", 4),
    ("sapMachineBoothCreatures", 4),
    ("sapMachinePowerTotal", 70),
    ("sapServantLumSameMake", 1),
    ("sapServantAutomatonHeightFt", 9),
    ("sapServantDepthFt", 6),
    ("sapServantWidthFt", 4),
    ("sapServantInsideRiders", 2),
    ("sapServantOutsideSittersMin", 4),
    ("sapServantCommandPhrases", 1),
    ("sapServantUseCount", 3),
    ("sapServantArmorClass", 1),
    ("sapServantHitPoints", 60),
    ("sapServantWeaponDamagePct", 50),
    ("sapServantRegenPerRound", 2),
    ("sapServantMagicResistPct", 100),
    ("sapServantElementImmuneCount", 6),
    ("sapServantElectricalDamagePct", 20),
    ("sapServantSpeedInches", 3),
    ("sapServantOperationHours", 12),
    ("sapServantRestHours", 1),
    ("sapServantPanicRangeInches", 12),
    ("sapServantPanicSaveBonus", 2),
    ("sapServantAttacksPerRound", 1),
    ("sapServantBaseHitPct", 15),
    ("sapServantDexReduceFloor", 14),
    ("sapServantDexReducePct", 2),
    ("sapServantDamageLowHp", 10),
    ("sapServantDamageHighHp", 100),
    ("sapServantObeysSecretLearners", 1),
    ("sapServantPowerTotal", 17),
    ("sapOrbGoodDeitiesOrigin", 1),
    ("sapOrbDemonsCorrupted", 1),
    ("sapOrbGlobeCount", 8),
    ("sapOrbOnePerAge", 1),
    ("sapOrbSmallestInches", 3),
    ("sapOrbLargestInches", 10),
    ("sapOrbBasReliefCovered", 1),
    ("sapOrbDragonEssence", 1),
    ("sapOrbHatchlingIntelligence", 9),
    ("sapOrbHatchlingEgo", 9),
    ("sapOrbHatchlingPowerTotal", 3),
    ("sapOrbWyrmkinIntelligence", 10),
    ("sapOrbWyrmkinEgo", 10),
    ("sapOrbWyrmkinPowerTotal", 3),
    ("sapOrbDragonetteIntelligence", 11),
    ("sapOrbDragonetteEgo", 11),
    ("sapOrbDragonettePowerTotal", 5),
    ("sapOrbDragonIntelligence", 12),
    ("sapOrbDragonEgo", 12),
    ("sapOrbDragonPowerTotal", 6),
    ("sapOrbGreatSerpentIntelligence", 13),
    ("sapOrbGreatSerpentEgo", 13),
    ("sapOrbGreatSerpentPowerTotal", 7),
    ("sapOrbFiredrakeOldDragon", 1),
    ("sapOrbFiredrakeIntelligence", 14),
    ("sapOrbFiredrakeEgo", 14),
    ("sapOrbFiredrakePowerTotal", 9),
    ("sapOrbElderWyrmVeryOldDragon", 1),
    ("sapOrbElderWyrmIntelligence", 16),
    ("sapOrbElderWyrmEgo", 16),
    ("sapOrbElderWyrmPowerTotal", 12),
    ("sapOrbEternalAncientDragon", 1),
    ("sapOrbEternalTiamatBahamutBonus", 8),
    ("sapOrbEternalIntelligence", 18),
    ("sapOrbEternalEgo", 18),
    ("sapOrbEternalPowerTotal", 13),
    ("sapOrbNotesEvilComponent", 1),
    ("sapOrbNotesNeutralGoodResist", 1),
    ("sapOrbNotesCharmRangeInches", 5),
    ("sapOrbNotesCharmRounds", 1),
    ("sapOrbNotesAwakeAndAware", 1),
    ("sapOrbNotesEvilAutoCharmed", 1),
    ("sapOrbNotesNeutralSavePenalty", 4),
    ("sapOrbNotesGoodSavePenalty", 2),
    ("sapOrbNotesCharmedWisdomPercent", 50),
    ("sapOrbNotesFeeblemindIntelligence", 3),
    ("sapOrbNotesInsanePercent", 50),
    ("sapOrbNotesAwakeMindOnly", 1),
    ("sapOrbNotesSacrificeDestruction", 1),
    ("sapOrbMightOrbCount", 3),
    ("sapOrbMightCrownSource", 1),
    ("sapOrbMightEvilDieLo", 1),
    ("sapOrbMightEvilDieHi", 6),
    ("sapOrbMightGoodDieLo", 7),
    ("sapOrbMightGoodDieHi", 14),
    ("sapOrbMightNeutralDieLo", 15),
    ("sapOrbMightNeutralDieHi", 20),
    ("sapOrbMightTouchDeathSave", 1),
    ("sapOrbMightTouchDamageLo", 4),
    ("sapOrbMightTouchDamageHi", 24),
    ("sapOrbMightRegaliaTableFour", 1),
    ("sapOrbMightPlatinumGems", 1),
    ("sapOrbMightValueGp", 100000),
    ("sapOrbMightGemOfBrightness", 1),
    ("sapOrbMightPowerEthosCount", 3),
    ("sapOrbMightPowerTotal", 3),
    ("sapOrbMightRegaliaPowers", 1),
    ("sapNightingaleMadeByXagy", 1),
    ("sapNightingaleJoramyCoMaker", 1),
    ("sapNightingaleMadeCenturiesAgo", 17),
    ("sapNightingaleEhlissaBentAll", 1),
    ("sapNightingaleNeverEscaped", 1),
    ("sapNightingaleGoldenWireCage", 1),
    ("sapNightingaleWingsPerchPerform", 1),
    ("sapNightingaleEyeRays", 1),
    ("sapNightingaleSongWonders", 1),
    ("sapNightingaleRaySongSpells", 1),
    ("sapNightingaleSphereRadiusFeet", 30),
    ("sapNightingaleSphereBlocksScrying", 1),
    ("sapNightingaleNoHungerThirst", 1),
    ("sapNightingalePowerTotal", 8),
    ("sapRecorderNeedsNoMusician", 1),
    ("sapRecorderPlaysOnCommand", 1),
    ("sapRecorderAlarmRadiusFeet", 30),
    ("sapRecorderAlarmIncludesSelf", 1),
    ("sapRecorderClueWordSongs", 1),
    ("sapRecorderRumoredSpells", 1),
    ("sapRecorderPowerTotal", 11),
    ("sapGaxxAlienOrigin", 1),
    ("sapGaxxPlatinumLoopSpinel", 1),
    ("sapGaxxUnknownGemType", 1),
    ("sapGaxxFingerDiscovery", 1),
    ("sapGaxxFacetCount", 9),
    ("sapGaxxFacingToTop", 1),
    ("sapGaxxTurnsItself", 1),
    ("sapGaxxDailyRandomFacet", 1),
    ("sapGaxxFacetOrderKnown", 1),
    ("sapGaxxCannotBeMarked", 1),
    ("sapGaxxPowerTotal", 9),
    ("sapRodWindDukesMadeIt", 1),
    ("sapRodMadeForBattleOfPesh", 1),
    ("sapRodPeshChaosVersusLaw", 1),
    ("sapRodShatteredAtPesh", 1),
    ("sapRodNothingDestroysIt", 1),
    ("sapRodCorrectOrderSurpassingPower", 1),
    ("sapRodPartCount", 7),
    ("sapRodPartsSlightlyDifferent", 1),
    ("sapRodFirstLargestLengthDiameter", 1),
    ("sapRodSeventhSmallest", 1),
    ("sapRodNoAlonePower", 1),
    ("sapRodPartsLookLikeBatons", 1),
    ("sapRodSeventhLooksLikeWand", 1),
    ("sapRodFirstSensesSecond", 1),
    ("sapRodSensingNeedsWholeThought", 1),
    ("sapRodLeadsOnlyUpward", 1),
    ("sapRodOutOfOrderTouchTeleports", 1),
    ("sapRodTeleportMinMiles", 100),
    ("sapRodTeleportMaxMiles", 1000),
    ("sapRodAssembledLengthFeet", 5),
    ("sapRodThreeSectionsGripLock", 1),
    ("sapRodPartPowersCumulative", 1),
    ("sapRodFullPowersNeedAllParts", 1),
    ("sapRodCannotBeDisassembled", 1),
    ("sapRodPrimeRiskDenominator", 20),
    ("sapRodPrimeRiskPercent", 5),
    ("sapRodBreakupTeleportMinMiles", 100),
    ("sapRodBreakupTeleportMaxMiles", 1200),
    ("sapRodOutOfOrderNotCumulative", 1),
    ("sapRodLastPieceJoinedActive", 1),
    ("sapRodInOrderCumulative", 1),
    ("sapRodAssemblyRowCount", 6),
    ("sapRodAssemblyUseTotal", 6),
    ("sapRodCompleteUseTotal", 7),
    ("sapRodCompleteOrderQuirk", 1),
    ("sapRodCompleteLacksTableVI", 1),
    ("sapRodBlankSlotCount", 13),
    ("sapRodBlankSlotUnderscores", 11),
    ("sapSceptreCount", 3),
    ("sapSceptreSourceCrownOfMight", 1),
    ("sapSceptreEvilBandLo", 1),
    ("sapSceptreEvilBandHi", 6),
    ("sapSceptreGoodBandLo", 7),
    ("sapSceptreGoodBandHi", 14),
    ("sapSceptreNeutralBandLo", 15),
    ("sapSceptreNeutralBandHi", 20),
    ("sapSceptreForeignEthosCrownEffects", 1),
    ("sapSceptreBronzeInlaidSilver", 1),
    ("sapSceptreHugeStoneTipping", 1),
    ("sapSceptreLengthFeet", 2),
    ("sapSceptreValueGp", 150000),
    ("sapSceptreRodOfBeguiling", 1),
    ("sapSceptreUseTotal", 3),
    ("sapSceptreCrownOrbComboNote", 1),
    ("sapSceptreBlankSlotCount", 9),
    ("sapKasOfVecnaTheLich", 1),
    ("sapKasBodyguardRightHand", 1),
    ("sapKasFlatchetDullGrayMetal", 1),
    ("sapKasSharpPointKeenEdges", 1),
    ("sapKasServedFaithfully", 1),
    ("sapKasHubrisGrew", 1),
    ("sapKasSwordUrgedHimOn", 1),
    ("sapKasGreaterThanVecna", 1),
    ("sapKasCouldRuleInVecnaStead", 1),
    ("sapKasDestroyedVecna", 1),
    ("sapKasDoomWroughtTogether", 1),
    ("sapKasWorldBrighter", 1),
    ("sapKasPowersOnlyHinted", 1),
    ("sapKasRenownedSwordsman", 1),
    ("sapKasPlusBonus", 6),
    ("sapKasDefender", 1),
    ("sapKasDoubleDamageOffPlane", 1),
    ("sapKasNormalDamageOnOtherPlanes", 1),
    ("sapKasShortSword", 1),
    ("sapKasEvilChaoticAlignment", 1),
    ("sapKasIntelligence", 15),
    ("sapKasEgo", 19),
    ("sapKasTriesToControl", 1),
    ("sapKasUseTotal", 13),
    ("sapKasBlankSlotCount", 13),
    ("sapKasPrintsInOrder", 1),
    ("sapToothHistoriesSilent", 1),
    ("sapToothGodsGavePowers", 1),
    ("sapToothRelicsAreTeeth", 1),
    ("sapToothEachToothHasPower", 1),
    ("sapToothCount", 32),
    ("sapToothBenefitLevels", 3),
    ("sapToothQuarterCount", 8),
    ("sapToothHalfCount", 16),
    ("sapToothGraftsInMouth", 1),
    ("sapToothLikeMissingTooth", 1),
    ("sapToothNeverRemoved", 1),
    ("sapToothRemovalOnlyByDemise", 1),
    ("sapToothPowersCumulative", 1),
    ("sapToothUseTotal", 32),
    ("sapToothTableOneCount", 21),
    ("sapToothTableTwoCount", 4),
    ("sapToothTableThreeCount", 4),
    ("sapToothTableFourCount", 1),
    ("sapToothTableFiveCount", 0),
    ("sapToothTableSixCount", 2),
    ("sapToothLoneFourTooth", 21),
    ("sapToothFirstSixTooth", 7),
    ("sapToothSecondSixTooth", 14),
    ("sapToothUnderscoreRunLen", 14),
    ("sapToothBlankSlotCount", 51),
    ("sapToothXSignCount", 51),
    ("sapToothSetPairRows", 8),
    ("sapToothSetQuarterRows", 4),
    ("sapToothSetHalfRepeatQuarters", 1),
    ("sapToothSetFiveRows", 3),
    ("sapToothSetLeftTwoCount", 8),
    ("sapToothSetLeftFiveCount", 3),
    ("sapToothSetRightThreeCount", 4),
    ("sapToothSetRightFourCount", 2),
    ("sapToothSetRightSixCount", 2),
    ("sapThroneCarvenMountainHeart", 1),
    ("sapThroneMassiveStoneChair", 1),
    ("sapThroneMosaicsIvoryMetals", 1),
    ("sapThroneSetAboutGems", 1),
    ("sapThroneGodsActuallySat", 1),
    ("sapThroneWithinGreatCavern", 1),
    ("sapThroneImmobileImmovable", 1),
    ("sapThroneAffectsAnyoneSeated", 1),
    ("sapThroneCertainMagicItem", 1),
    ("sapThroneMalevolentEffectToo", 1),
    ("sapThroneItemGainOnlyOnce", 1),
    ("sapThroneProperWordsGestures", 1),
    ("sapThroneGraspOptions", 3),
    ("sapThroneUseTotal", 14),
    ("sapThroneTableOneCount", 3),
    ("sapThroneTableTwoCount", 3),
    ("sapThroneTableThreeCount", 2),
    ("sapThroneTableFourCount", 2),
    ("sapThroneTableFiveCount", 2),
    ("sapThroneTableSixCount", 2),
    ("sapThroneBlankSlotCount", 14),
    ("sapThroneXSignCount", 6),
    ("sapThroneBulletLineCount", 0),
    ("sapWandDemonPrinceProperty", 1),
    ("sapWandPassesToPrimeMaterial", 1),
    ("sapWandWreakChaosEvil", 1),
    ("sapWandMonsterManualRef", 1),
    ("sapWandSavingThrowVersusMagic", 1),
    ("sapWandAvoidsDeathAnnihilation", 1),
    ("sapWandImmuneCount", 6),
    ("sapWandUseTotal", 10),
    ("sapWandTableOneCount", 4),
    ("sapWandTableTwoCount", 2),
    ("sapWandTableThreeCount", 2),
    ("sapWandTableFourCount", 1),
    ("sapWandTableFiveCount", 0),
    ("sapWandTableSixCount", 1),
    ("sapWandBlankSlotCount", 10),
    ("sapWandXSignCount", 5),
    ("sapWandBulletLineCount", 5),
    ("sapWandFourOneSpaceSeparator", 1),
    ("sapWandFourOneCommaCount", 2),
    ("sapFinalXSignCount", 11),
    ("sapFinalBlankRunCount", 24),
    ("sapFinalUnderscoreRunLen", 14),
    ("sapFinalCurlyApostropheCount", 2),
    ("sapFinalEmDashCount", 0),
    ("sapFinalPageSeamLine", 1797),
    ("sapFinalSpecialDescriptionCount", 29),
]


DEFS = [
    ("specart", "DMG special artifact band table"),
    ("specart_prose", "DMG special artifact prose columns"),
]

BS = chr(92)
def emit(text):
    # @N@ -> the two characters backslash + n
    return text.replace("@N@", BS + "n")

def die(msg):
    sys.stderr.write("r1062_splice: FATAL: " + msg + chr(10))
    sys.exit(1)

def parse_array(src, fn):
    try:
        i = src.index("inline int " + fn + "(")
        j = src.index("return t[i];", i)
        k = src.index("static const int t[", i, j)
    except ValueError:
        die("pristine shape mismatch at " + fn)
    seg = src[k:j]
    m = re.search("t" + re.escape("[") + "([0-9]+)" + re.escape("]"), seg)
    w = int(m.group(1))
    body = seg.split("= " + chr(123), 1)[1].split("};", 1)[0]
    vals = [int(x) for x in re.findall("-?[0-9]+", body)]
    if len(vals) != w:
        die(fn + ": parsed " + str(len(vals))
            + " values, header says " + str(w))
    return k, j + len("return t[i];"), vals

def parse_zeroarg(src, label):
    out = {}
    pat = ("inline int ([A-Za-z_0-9]+)" + re.escape("()")
           + " " + chr(123) + chr(10)
           + "(.*?)" + chr(10) + chr(125) + chr(10))
    for fn, body in re.findall(pat, src, re.S):
        m = re.search("return (-?[0-9]+);", body)
        if not m:
            die("zero-arg fn without a literal return: " + fn
                + " (in " + label + ")")
        out[fn] = int(m.group(1))
    return out

def fmt_vals(vals, per, indent):
    p = " " * indent
    out = []
    for s in range(0, len(vals), per):
        out.append(p + ", ".join(str(v) for v in vals[s:s + per]) + ",")
    return out

def lua_file(key, name, tables):
    L = []
    L.append("-- misc magic item def: " + key)
    L.append("-- The R1062 special-artifact family de-wire: the")
    L.append("-- retired static arrays of rules/dmg/specart.h and")
    L.append("-- rules/dmg/specart_prose_part2.h ride this def")
    L.append("-- (rowless: flat int columns only, no rows). The")
    L.append("-- accessors keep their clamps and comments; the")
    L.append("-- r280-r29x pin fragments and the headers are the")
    L.append("-- print-fidelity record. DO NOT hand-edit this")
    L.append("-- file; tools/r1062_splice.py is the only writer.")
    L.append("return {")
    L.append("  key = " + chr(34) + key + chr(34) + ",")
    L.append("  name = " + chr(34) + name + chr(34) + ",")
    L.append("  sources = {")
    L.append("    { part = 0, round = 1062 },")
    L.append("  },")
    L.append("  pins = {")
    L.append("    { name = " + chr(34) + key + "TableCount" + chr(34) + ",")
    L.append("      value = " + str(len(tables)) + ",")
    L.append("      comment = " + chr(34) + "the family columns" + chr(34) + " },")
    L.append("  },")
    L.append("  tables = {")
    for tag, fn, vals in tables:
        L.append("    { name = " + chr(34) + tag + chr(34) + ",")
        L.append("      values = {")
        for line in fmt_vals(vals, 6, 8):
            L.append(line)
        L.append("      },")
        L.append("      comment = " + chr(34) + "from " + fn + chr(34) + " },")
    L.append("  },")
    L.append("}")
    return chr(10).join(L) + chr(10)

def seam_text():
    return chr(10).join([
        "// ===========================================================================",
        "// Adnd1 - rules/seams/specreg.h",
        "// The R1062 special-artifact-family registry seam.",
        "//",
        "// content/tables/specart/ (R1062) via",
        "// items::MiscItemRegistry: the R1061",
        "// siegefirereg idiom, rowless (the",
        "// special-artifact family is flat int",
        "// columns only, no rows readers).",
        "// Header-only singleton (the R1040",
        "// appendixp.h idiom). Every accessor in",
        "// rules/dmg/specart.h and",
        "// rules/dmg/specart_prose_part2.h keeps",
        "// its signature, clamp and comment;",
        "// only the array read moves behind the",
        "// registry. The R1058 weaponsreg /",
        "// R1059 miscreg precedent. DO NOT",
        "// hand-edit: tools/r1062_splice.py is",
        "// the only writer.",
        "// ===========================================================================",
        "",
        "#pragma once",
        "",
        '#include "items/MiscItemRegistry.h"',
        "",
        "namespace rules {",
        "",
        "// ---- the special-artifact family registry seam ----",
        "",
        "inline items::MiscItemRegistry&",
        "saReg() {",
        "    static items::MiscItemRegistry",
        "        reg;",
        "    static bool loaded = false;",
        "    if (!loaded) {",
        "        loaded = true;",
        "        reg.loadDirectory(",
        '            "content/tables/"',
        '            "specart");',
        "    }",
        "    return reg;",
        "}",
        "",
        "// one named int table of one def",
        "// (null when absent or empty -",
        "// the R1058 long long note rides",
        "// here unchanged)",
        "inline const std::vector<",
        "    long long>* saTable(",
        "        const char* key,",
        "        const char* tag) {",
        "    static std::map<std::string,",
        "        std::vector<long long>>",
        "        cache;",
        "    std::string ck =",
        "        std::string(key)",
        "        + " + chr(34) + "/" + chr(34) + " + tag;",
        "    auto it = cache.find(ck);",
        "    if (it == cache.end()) {",
        "        const items::",
        "            MiscItemDef* d =",
        "            saReg().find(key);",
        "        const std::vector<",
        "            long long>* v = nullptr;",
        "        if (d) {",
        "            for (const auto& t :",
        "                 d->tables)",
        '                if (t.name == tag) {',
        "                    v = &t.values;",
        "                    break;",
        "                }",
        "        }",
        "        it = cache.emplace(",
        "            ck, v ? *v",
        "                  : std::vector<",
        "                        long long>()",
        "            ).first;",
        "    }",
        "    return it->second.empty()",
        "        ? nullptr",
        "        : &it->second;",
        "}",
        "",
        "}   // namespace rules",
        ""]) + chr(10)

def arr_decl(name, vals, per, indent):
    lines = [" " * indent + "static const int " + name
             + "[" + str(len(vals)) + "] = {"]
    for line in fmt_vals(vals, per, indent + 4):
        lines.append(line)
    lines.append(" " * indent + "};")
    return lines

def k_block(idx, tag, fn, vals, P):
    L = []
    L.append(P + "            // " + fn + " (" + tag + ")")
    per = 6 if len(vals) <= 18 else 10
    for line in arr_decl("k" + fn, vals, per, 12):
        L.append(line)
    L.append(P + "            if (d->tables[" + str(idx) + "].name")
    L.append(P + "                != " + chr(34) + tag + chr(34) + ") ++bad;")
    L.append(P + "            else for (int i = 0; i < "
             + str(len(vals)) + "; ++i)")
    L.append(P + "                if ((int)d->tables[" + str(idx) + "]")
    L.append(P + "                        .values[i] != k" + fn + "[i])")
    L.append(P + "                    ++bad;")
    return L

def frag_text(vals_by_fn):
    P = " " * 4
    L = []
    L.append(P + "// ==== R1062: special-artifact registry =========")
    L.append(P + "// The R1062 de-wire: the 54 retiring static")
    L.append(P + "// arrays of rules/dmg/specart.h (5) and")
    L.append(P + "// rules/dmg/specart_prose_part2.h (49) ride")
    L.append(P + "// items::MiscItemRegistry from")
    L.append(P + "// content/tables/specart/ - 2 rowless defs,")
    L.append(P + "// 54 tables, one pin per def; the 499 KEPT")
    L.append(P + "// zero-arg scalars stay C++, probed at the")
    L.append(P + "// edges here (the r280-r29x pin fragments keep")
    L.append(P + "// their value-level pins untouched). Eight")
    L.append(P + "// sections: load, counts, defs-A/B/C/D, seam,")
    L.append(P + "// edges. Census 1135 -> 1143. DO NOT hand-edit:")
    L.append(P + "// tools/r1062_splice.py is the only writer.")
    L.append(P + "{")
    L.append(P + "    int bad = 0;")

    # -- 1. load --------------------------------------------------
    L.append(P + "    // -- 1. load ------------------------------")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        int n = reg.loadDirectory(")
    L.append(P + "            \"content/tables/specart\");")
    L.append(P + "        if (n != 2) ++bad;")
    L.append(P + "        if (!reg.errors().empty()) ++bad;")
    L.append(P + "        for (const auto& kv : reg.all())")
    L.append(P + "            if ((int)kv.second.sources.size() != 1")
    L.append(P + "                || kv.second.sources[0].first != 0")
    L.append(P + "                || kv.second.sources[0].second != 1062)")
    L.append(P + "                ++bad;")
    for key, _name in DEFS:
        L.append(P + "        if (!reg.find(\"" + key + "\")) ++bad;")
    L.append(P + "    }")
    L.append(P + "    printf(\"R1062 specart registry load audit: bad %d@N@\", bad);")
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 2. counts ------------------------------------------------
    L.append(P + "    // -- 2. counts ----------------------------")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        reg.loadDirectory(")
    L.append(P + "            \"content/tables/specart\");")
    for key, _name in DEFS:
        tags = [p for p in SPECS if p[1] == key]
        L.append(P + "        {")
        L.append(P + "            const items::MiscItemDef* d =")
        L.append(P + "                reg.find(\"" + key + "\");")
        L.append(P + "            if (!d) { ++bad; } else {")
        L.append(P + "                if ((int)d->pins.size() != 1")
        L.append(P + "                    || d->pins[0].name")
        L.append(P + "                        != \"" + key + "TableCount\"")
        L.append(P + "                    || d->pins[0].value != " + str(len(tags)) + ")")
        L.append(P + "                    ++bad;")
        L.append(P + "                if ((int)d->tables.size() != " + str(len(tags)) + ") ++bad;")
        for idx, p in enumerate(tags):
            fn, _d, tag, w, _s = p
            L.append(P + "                if (d->tables[" + str(idx) + "].name")
            L.append(P + "                    != \"" + tag + "\"")
            L.append(P + "                    || (int)d->tables[" + str(idx) + "]")
            L.append(P + "                        .values.size() != " + str(w) + ")")
            L.append(P + "                    ++bad;")
        L.append(P + "            }")
        L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + "    printf(\"R1062 specart registry counts audit: bad %d@N@\", bad);")
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 3. defs-A (specart band columns) -------------------------
    L.append(P + "    // -- 3. defs-A: the band columns ----------")
    L.append(P + "    {")
    L.append(P + "        items::MiscItemRegistry reg;")
    L.append(P + "        reg.loadDirectory(")
    L.append(P + "            \"content/tables/specart\");")
    L.append(P + "        const items::MiscItemDef* d =")
    L.append(P + "            reg.find(\"specart\");")
    L.append(P + "        if (!d) { ++bad; } else {")
    for idx, p in enumerate([q for q in SPECS if q[1] == "specart"]):
        fn, _d, tag, _w, _s = p
        vals = vals_by_fn[fn][0]
        for line in k_block(idx, tag, fn, vals, P):
            L.append(line)
    L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + "    printf(\"R1062 specart registry defs-A audit: bad %d@N@\", bad);")
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 4/5. defs-B/C (the prose columns, split 25/24) ------------
    prose = [q for q in SPECS if q[1] == "specart_prose"]
    for sec, part, label in [(4, prose[:25], "defs-B"),
                             (5, prose[25:], "defs-C")]:
        L.append(P + "    // -- " + str(sec) + ". " + label
                 + ": prose columns " + ("1-25" if sec == 4 else "26-49")
                 + " -")
        L.append(P + "    {")
        L.append(P + "        items::MiscItemRegistry reg;")
        L.append(P + "        reg.loadDirectory(")
        L.append(P + "            \"content/tables/specart\");")
        L.append(P + "        const items::MiscItemDef* d =")
        L.append(P + "            reg.find(\"specart_prose\");")
        L.append(P + "        if (!d) { ++bad; } else {")
        # defs-C probes the def's ABSOLUTE table indices (the
        # R1035 lesson: derive indices from the emitted layout,
        # never the split's local position)
        base = 0 if sec == 4 else 25
        for idx, p in enumerate(part, base):
            fn, _d, tag, _w, _s = p
            vals = vals_by_fn[fn][0]
            for line in k_block(idx, tag, fn, vals, P):
                L.append(line)
        L.append(P + "        }")
        L.append(P + "    }")
        L.append(P + "    printf(\"R1062 specart registry " + label
                 + " audit: bad %d@N@\", bad);")
        L.append(P + "    if (bad) return 1;")
        L.append(P + "    bad = 0;")

    # -- 6. defs-D (accessor parity sweep) --------------------------
    L.append(P + "    // -- 6. defs-D: accessor parity sweep -----")
    L.append(P + "    // every accessor, every index, against the")
    L.append(P + "    // registry seam (the r280-r29x callers stay")
    L.append(P + "    // byte-identical; this label carries the")
    L.append(P + "    // parity they used to carry)")
    L.append(P + "    {")
    for fn, dkey, tag, w, _s in SPECS:
        L.append(P + "        {")
        L.append(P + "            const auto* g = rules::saTable(")
        L.append(P + "                \"" + dkey + "\", \"" + tag + "\");")
        L.append(P + "            if (!g) { ++bad; }")
        L.append(P + "            else for (int i = 0; i < " + str(w) + "; ++i)")
        L.append(P + "                if (rules::" + fn + "(i)")
        L.append(P + "                    != (int)(*g)[i]) ++bad;")
        L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + "    printf(\"R1062 specart registry defs-D audit: bad %d@N@\", bad);")
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 7. seam ----------------------------------------------------
    L.append(P + "    // -- 7. seam -------------------------------")
    L.append(P + "    // all 54 (key, tag) pairs resolve; wrong tag")
    L.append(P + "    // and wrong key read null; two calls share")
    L.append(P + "    // the cached table (stability)")
    L.append(P + "    {")
    for fn, dkey, tag, _w, _s in SPECS:
        L.append(P + "        if (!rules::saTable(\"" + dkey
                 + "\", \"" + tag + "\")) ++bad;")
    L.append(P + "        if (rules::saTable(\"specart\", \"no_such_tag\")) ++bad;")
    L.append(P + "        if (rules::saTable(\"no_such_def\", \"row_lo\")) ++bad;")
    L.append(P + "        {")
    L.append(P + "            const auto* p1 = rules::saTable(\"specart\",")
    L.append(P + "                                 \"row_lo\");")
    L.append(P + "            const auto* p2 = rules::saTable(\"specart\",")
    L.append(P + "                                 \"row_lo\");")
    L.append(P + "            if (p1 != p2) ++bad;")
    L.append(P + "        }")
    L.append(P + "    }")
    L.append(P + "    printf(\"R1062 specart registry seam audit: bad %d@N@\", bad);")
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")

    # -- 8. edges ---------------------------------------------------
    L.append(P + "    // -- 8. edges -------------------------------")
    L.append(P + "    // accessor clamps, then all 499 KEPT")
    L.append(P + "    // zero-arg scalars against their parsed")
    L.append(P + "    // pristine literals")
    L.append(P + "    {")
    for fn, _dkey, _tag, w, _s in SPECS:
        L.append(P + "        if (rules::" + fn + "(-9)")
        L.append(P + "            != rules::" + fn + "(0)) ++bad;")
        L.append(P + "        if (rules::" + fn + "(99)")
        L.append(P + "            != rules::" + fn + "(" + str(w - 1) + ")) ++bad;")
    for fn, val in KEEPS:
        L.append(P + "        if (rules::" + fn + "() != " + str(val)
                 + ") ++bad;")
    L.append(P + "    }")
    L.append(P + "    printf(\"R1062 specart registry edges audit: bad %d@N@\", bad);")
    L.append(P + "    if (bad) return 1;")
    L.append(P + "    bad = 0;")
    L.append(P + "}")
    return chr(10).join(L) + chr(10)

def rewrite_header(src, rel_specs, vals_by_fn):
    # mark + seam include after #pragma once
    po = src.index("#pragma once")
    eol = src.index(chr(10), po)
    src = (src[:eol + 1] + chr(10) + MARK + chr(10)
           + '#include "rules/seams/specreg.h"' + chr(10) + src[eol + 1:])
    # body rewrites (re-scan per fn: index-shift safe)
    for fn, dkey, tag, w, s in rel_specs:
        k, jend, vals = parse_array(src, fn)
        if len(vals) != w or sum(vals) != s:
            die(fn + " checksum mismatch")
        if vals != vals_by_fn[fn][0]:
            die(fn + " parse disagrees with the verified values")
        tail = ("const auto* g = saTable(" + chr(10)
                + '        "' + dkey + '", "' + tag + '");' + chr(10)
                + "    if (!g) return 0;" + chr(10)
                + "    return (int)(*g)[i];")
        src = src[:k] + tail + src[jend:]
    return src

def load_lua_vals(root):
    # parse values back out of the spliced lua defs (for the
    # already-applied frag refresh path)
    vals_by_fn = {}
    spec_map = dict((p[0], (p[3], p[4])) for p in SPECS)
    for key, _name in DEFS:
        txt = open(os.path.join(root, LUA_DIR, key + ".lua")).read()
        for fn, d, tag, _w, _s in [p for p in SPECS if p[1] == key]:
            pat = ("name = " + chr(34) + re.escape(tag) + chr(34) + ","
                   + "[@" + chr(10) + " ]*values = " + chr(123)
                   + "(.*?)" + chr(125))
            m = re.search(pat, txt, re.S)
            if not m:
                die("lua table " + tag + " unreadable in " + key)
            vals = [int(x) for x in re.findall("-?[0-9]+", m.group(1))]
            spec = spec_map[fn]
            if len(vals) != spec[0] or sum(vals) != spec[1]:
                die("lua checksum drift at " + fn + " (frag refresh path)")
            vals_by_fn[fn] = (vals, spec[0])
    return vals_by_fn

def main():
    root = sys.argv[1] if len(sys.argv) > 1 else "."
    root = os.path.abspath(root)
    hdr_a = os.path.join(root, HDR_A)
    hdr_b = os.path.join(root, HDR_B)

    if not os.path.isfile(hdr_a) or not os.path.isfile(hdr_b):
        die("no specart family headers under " + root)
    src_a = open(hdr_a).read()
    src_b = open(hdr_b).read()

    # canvas.md rides out first if an accidental landing left one
    cm = os.path.join(root, "canvas.md")
    if os.path.isfile(cm):
        os.remove(cm)
        print("r1062_splice: tree-root canvas.md deleted (rides out in R1062)")

    if MARK in src_a:
        # already-applied path: harden (R1059 lesson)
        if MARK not in src_b:
            die("R1062 mark in specart.h but NOT in specart_prose_part2.h"
                + " - mixed splice state; restore both headers from"
                + " 23c67737 and rerun")
        ok = (os.path.isfile(os.path.join(root, FRAG_REL))
              and os.path.isfile(os.path.join(root, SEAM_REL))
              and os.path.isdir(os.path.join(root, LUA_DIR)))
        if not ok:
            die("R1062 mark present but frag/seam/lua dir missing -"
                + " mixed splice state")
        n_lua = len([f for f in os.listdir(os.path.join(root, LUA_DIR))
                     if f.endswith(".lua")])
        if n_lua != 2:
            die("R1062 mark present but " + str(n_lua) + " lua defs (want 2)")
        rt = open(os.path.join(root, REGTEST_REL)).read()
        if "r1062_specart_registry.h" not in rt:
            die("R1062 mark present but regtest include missing -"
                + " mixed splice state")
        vals_by_fn = load_lua_vals(root)
        frag_path = os.path.join(root, FRAG_REL)
        fresh_frag = emit(frag_text(vals_by_fn))
        cur = open(frag_path).read()
        if cur != fresh_frag:
            open(frag_path, "w").write(fresh_frag)
            print("r1062_splice: frag refreshed (tool-generated output updated)")
        else:
            print("r1062_splice: frag current")
        print("r1062_splice: already applied (2 defs, 54 tables, 8 labels)")
        print("r1062_splice: applied 0, already 54; census stays 1143")
        return

    md5a = hashlib.md5(src_a.encode()).hexdigest()
    md5b = hashlib.md5(src_b.encode()).hexdigest()
    if md5a != PRISTINE_MD5_A:
        die("rules/dmg/specart.h md5 is " + md5a + ", want " + PRISTINE_MD5_A
            + " (pristine 23c67737 required)")
    if md5b != PRISTINE_MD5_B:
        die("rules/dmg/specart_prose_part2.h md5 is " + md5b + ", want "
            + PRISTINE_MD5_B + " (pristine 23c67737 required)")

    # parse + verify all 54
    vals_by_fn = {}
    for fn, dkey, tag, w, s in SPECS:
        src = src_a if dkey == "specart" else src_b
        _k, _j, vals = parse_array(src, fn)
        if len(vals) != w or sum(vals) != s:
            die(fn + " checksum mismatch (want w=" + str(w)
                + " sum=" + str(s) + ")")
        vals_by_fn[fn] = (vals, w)
    print("r1062_splice: 54 arrays parsed, checksums verified")

    # parse + verify the 499 KEPT zero-arg scalars
    kept = {}
    for src, label in [(src_a, "specart.h"),
                        (open(os.path.join(root, HDR_P1)).read(),
                         "specart_prose_part1.h"),
                        (src_b, "specart_prose_part2.h")]:
        kept.update(parse_zeroarg(src, label))
    if len(KEEPS) != 499 or dict(KEEPS) != kept:
        die("KEPT scalar ledger mismatch: embedded " + str(len(KEEPS))
            + ", headers carry " + str(len(kept)))
    print("r1062_splice: 499 KEPT zero-arg scalars parsed, ledger verified")

    # lua defs
    os.makedirs(os.path.join(root, LUA_DIR), exist_ok=True)
    for key, name in DEFS:
        tables = [(tag, fn, vals_by_fn[fn][0])
                  for fn, d, tag, _w, _s in SPECS if d == key]
        path = os.path.join(root, LUA_DIR, key + ".lua")
        open(path, "w").write(lua_file(key, name, tables))
    print("r1062_splice: 2 lua defs written (54 tables, 2 pins)")

    # seam
    open(os.path.join(root, SEAM_REL), "w").write(seam_text())
    print("r1062_splice: seam rules/seams/specreg.h written")

    # header rewrites
    open(hdr_a, "w").write(rewrite_header(
        src_a, [p for p in SPECS if p[1] == "specart"], vals_by_fn))
    print("r1062_splice: specart.h rewritten (mark + seam include + 5 bodies)")
    open(hdr_b, "w").write(rewrite_header(
        src_b, [p for p in SPECS if p[1] == "specart_prose"], vals_by_fn))
    print("r1062_splice: specart_prose_part2.h rewritten"
          " (mark + seam include + 49 bodies)")

    # frag
    open(os.path.join(root, FRAG_REL), "w").write(emit(frag_text(vals_by_fn)))
    print("r1062_splice: frag r1062_specart_registry.h written (8 labels)")

    # regtest include after the R1061 line
    rt = open(os.path.join(root, REGTEST_REL)).read()
    anchor = '#include "rules/audits/r1061_siegefire_registry.h"  // R1061'
    if anchor not in rt:
        die("regtest.cpp R1061 anchor missing")
    line = '#include "rules/audits/r1062_specart_registry.h"  // R1062'
    rt = rt.replace(anchor, anchor + chr(10) + line, 1)
    open(os.path.join(root, REGTEST_REL), "w").write(rt)
    print("r1062_splice: regtest.cpp include added after the R1061 line")

    print("r1062_splice: applied 54, already 0; census 1135 -> 1143 (+8)")

if __name__ == "__main__":
    main()
