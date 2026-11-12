// ====================================================================
// Adnd1 - rules/dmg/misc_magic/miscmagic_helm_of_brilliance_to_horn_of_bubbles.h
// R268: the III.E misc magic explanation prose part 12
// (DMG p.137-139) - Helm of Brilliance through the Horn
// of Bubbles, part2 lines 532-579 (global =
// 11065 + part2 line). ONE page header inside the slice
// (541, the TREASURE page) falls between the jewel
// functions table and the Each gem paragraph of the
// Brilliance item. The jewel functions table: the book
// upload flattens the four gem rows into the Diamond
// cell (the Ruby, Fire Opal and Opal cells empty) -
// the four-row table restored from the compilation
// (the R175 precedent): Diamond prismatic spray (7th
// illusionist), Ruby wall of fire (5th druid), Fire
// Opal fireball (3rd magic-user), Opal light (1st
// cleric). 91 accessors: 87 scalars + 4 array walkers
// (the jewel functions table), no name collisions with
// miscprose1.h through miscprose11.h.
// The slice pins kMisc3 rows 10-17, no class marks and
// no asterisks ride these rows. Pure data + helpers,
// header-only (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_helm_of_brilliance_to_horn_of_bubbles {
public:
    int mmpHelmBrilCommandWordOnly();
    int mmpHelmBrilTrueNatureVisible();
    int mmpHelmBrilArmorPlus();
    int mmpHelmBrilDiamondCount();
    int mmpHelmBrilRubyCount();
    int mmpHelmBrilFireOpalCount();
    int mmpHelmBrilOpalCount();
    int mmpHelmBrilScintillatesInBrightLight();
    int mmpHelmBrilJewelUseSegments();
    int mmpHelmBrilJewelUsableOnce();
    int mmpHelmBrilUsesPerRound();
    int mmpHelmBrilSpellLevelDoublingFactor();
    int mmpHelmBrilUndeadGlowRangeFeet();
    int mmpHelmBrilUndeadPainDmgMin();
    int mmpHelmBrilUndeadPainDmgMax();
    int mmpHelmBrilUndeadExemptKinds();
    int mmpHelmBrilFlameSwordEffectRounds();
    int mmpHelmBrilFlameSwordAdditional();
    int mmpHelmBrilProduceFlameDruidLevel();
    int mmpHelmBrilFireResistRingStrength();
    int mmpHelmBrilFireResistAugmentable();
    int mmpHelmBrilPowderOnExpenditure();
    int mmpHelmBrilJewelRemovalDestroys();
    int mmpHelmBrilJewelRemagickable();
    int mmpHelmBrilRetrySaveWithoutMagic();
    int mmpHelmBrilOverloadDetonatesRemaining();
    int mmpHelmBrilOverloadEffectsInMultiple();
    int mmpHelmBrilJewelRowCount();
    int mmpHelmBrilJewelGemCount(int i);
    int mmpHelmBrilJewelSpellLevel(int i);
    int mmpHelmBrilJewelCasterKind(int i);
    int mmpHelmBrilJewelFunctionKind(int i);
    int mmpHelmComprStrangeTonguesPct();
    int mmpHelmComprMagicalWritingsPct();
    int mmpHelmComprAllOrNone();
    int mmpHelmComprImpliesSpellUse();
    int mmpHelmComprHelmetOfAcValue();
    int mmpHelmOppAlignIndeterminateDweomer();
    int mmpHelmOppAlignCurseOnDonning();
    int mmpHelmOppAlignAbsoluteKinds();
    int mmpHelmOppAlignAlterationDesired();
    int mmpHelmOppAlignRestoreSpellKinds();
    int mmpHelmOppAlignSelfRestoreAttempts();
    int mmpHelmOppAlignPaladinQuestAndAtone();
    int mmpHelmOppAlignPowersAfterFunctioning();
    int mmpHelmTelepathyRangeInches();
    int mmpHelmTelepathyStoneBarrierFeet();
    int mmpHelmTelepathyIronBarrierQuarterFeet();
    int mmpHelmTelepathyLeadGoldSheetBlocks();
    int mmpHelmTelepathyDirectional();
    int mmpHelmTelepathyConsciousEffort();
    int mmpHelmTelepathySuggestPctPer2IntAbove();
    int mmpHelmTelepathySuggestPctPer1IntBelow();
    int mmpHelmTelepathySavePenaltyPer2IntBelow();
    int mmpHelmTelepathySaveBonusPer1IntAbove();
    int mmpHelmTelepathyEqualIntSaveAdjustment();
    int mmpHelmTelepathyPsionicAttackBonus();
    int mmpHelmTelepathyPsionicStrengthBonus();
    int mmpHelmTeleportPerDay();
    int mmpHelmTeleportMuRefreshRepeats();
    int mmpHelmTeleportMuStillPersonalAfterRefresh();
    int mmpHelmTeleportMuUncastPersonalCount();
    int mmpHelmTeleportUsageAfterMemoryLost();
    int mmpHelmUnderwaterSeeAndBreathe();
    int mmpHelmUnderwaterLensCompartments();
    int mmpHelmUnderwaterVisionFactor();
    int mmpHelmUnderwaterObstructionsBlock();
    int mmpHelmUnderwaterAirGlobeUntilRepeat();
    int mmpHornBlastingConeLengthInches();
    int mmpHornBlastingConeBaseWidthInches();
    int mmpHornBlastingSaveStunRounds();
    int mmpHornBlastingSaveDeafRounds();
    int mmpHornBlastingFailDmgMin();
    int mmpHornBlastingFailDmgMax();
    int mmpHornBlastingFailStunRounds();
    int mmpHornBlastingFailDeafRounds();
    int mmpHornBlastingPulseWidthFeet();
    int mmpHornBlastingPulseLengthInches();
    int mmpHornBlastingCatapultMultiplier();
    int mmpHornBlastingCatapultHitDamage();
    int mmpHornBlastingStructuralPoints();
    int mmpHornBlastingExplodePctPerExtraUse();
    int mmpHornBlastingExplodeDmgMin();
    int mmpHornBlastingExplodeDmgMax();
    int mmpHornBlastingCharges();
    int mmpHornBlastingShiverPctPerUse();
    int mmpHornBlastingShiverWielderDamage();
    int mmpHornBubblesBlindRoundsMin();
    int mmpHornBubblesBlindRoundsMax();
    int mmpHornBubblesOnlyWhenSlayerSeeks();
    int mmpHornBubblesAppearanceMayDelay();
};
