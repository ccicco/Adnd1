    // ---- R268: the III.E misc magic explanation
    // prose part 12 ----
    // Helm of Brilliance through the Horn of
    // Bubbles, part2 lines 532-579 - the slice
    // pinning the kMisc3 rows 10-17.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic.mmpHelmBrilCommandWordOnly() != 1 ||
            miscmagic.mmpHelmBrilTrueNatureVisible() != 1 ||
            miscmagic.mmpHelmBrilArmorPlus() != 2) ++bad;
        if (miscmagic.mmpHelmBrilDiamondCount() != 10 ||
            miscmagic.mmpHelmBrilRubyCount() != 20 ||
            miscmagic.mmpHelmBrilFireOpalCount() != 30 ||
            miscmagic.mmpHelmBrilOpalCount() != 40 ||
            miscmagic.mmpHelmBrilScintillatesInBrightLight() !=
            1) ++bad;
        if (miscmagic.mmpHelmBrilJewelUseSegments() != 1 ||
            miscmagic.mmpHelmBrilJewelUsableOnce() != 1 ||
            miscmagic.mmpHelmBrilUsesPerRound() != 1 ||
            miscmagic.mmpHelmBrilSpellLevelDoublingFactor() !=
            2) ++bad;
        if (miscmagic.mmpHelmBrilUndeadGlowRangeFeet() != 30 ||
            miscmagic.mmpHelmBrilUndeadPainDmgMin() != 1 ||
            miscmagic.mmpHelmBrilUndeadPainDmgMax() != 6 ||
            miscmagic.mmpHelmBrilUndeadExemptKinds() != 2) ++bad;
        if (miscmagic.mmpHelmBrilFlameSwordEffectRounds() != 1 ||
            miscmagic.mmpHelmBrilFlameSwordAdditional() != 1 ||
            miscmagic.mmpHelmBrilProduceFlameDruidLevel() !=
            5) ++bad;
        if (miscmagic.mmpHelmBrilFireResistRingStrength() != 2 ||
            miscmagic.mmpHelmBrilFireResistAugmentable() != 0 ||
            miscmagic.mmpHelmBrilPowderOnExpenditure() != 1) ++bad;
        if (miscmagic.mmpHelmBrilJewelRemovalDestroys() != 1 ||
            miscmagic.mmpHelmBrilJewelRemagickable() != 0 ||
            miscmagic.mmpHelmBrilRetrySaveWithoutMagic() !=
            1) ++bad;
        if (miscmagic.mmpHelmBrilOverloadDetonatesRemaining() !=
            1 ||
            miscmagic.mmpHelmBrilOverloadEffectsInMultiple() !=
            1 ||
            miscmagic.mmpHelmBrilJewelRowCount() != 4) ++bad;
        // the jewel functions table: the four
        // restored rows against static twins
        static const int kGem[4] = {
            10, 20, 30, 40,
        };
        static const int kLvl[4] = {
            7, 5, 3, 1,
        };
        static const int kCst[4] = {
            0, 1, 2, 3,
        };
        static const int kFn[4] = {
            0, 1, 2, 3,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic.mmpHelmBrilJewelGemCount(i) !=
                kGem[i] ||
                miscmagic.mmpHelmBrilJewelSpellLevel(i) !=
                kLvl[i] ||
                miscmagic.mmpHelmBrilJewelCasterKind(i) !=
                kCst[i] ||
                miscmagic.mmpHelmBrilJewelFunctionKind(i) !=
                kFn[i]) ++bad;
        // the gem ladder climbs by 10, the spell
        // level ladder falls by 2
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpHelmBrilJewelGemCount(i + 1) !=
                miscmagic.mmpHelmBrilJewelGemCount(i) + 10 ||
                miscmagic.mmpHelmBrilJewelSpellLevel(i) !=
                miscmagic.mmpHelmBrilJewelSpellLevel(i + 1) +
                2) ++bad;
        // the diamond function is the highest spell
        // level, the opal function the lowest; the
        // diamond row is the sparsest gem row
        if (miscmagic.mmpHelmBrilJewelSpellLevel(0) !=
            miscmagic.mmpHelmBrilJewelSpellLevel(3) + 6 ||
            miscmagic.mmpHelmBrilJewelGemCount(0) + 30 !=
            miscmagic.mmpHelmBrilJewelGemCount(3)) ++bad;
        // the intro counts name the table rows
        if (miscmagic.mmpHelmBrilDiamondCount() !=
            miscmagic.mmpHelmBrilJewelGemCount(0) ||
            miscmagic.mmpHelmBrilRubyCount() !=
            miscmagic.mmpHelmBrilJewelGemCount(1) ||
            miscmagic.mmpHelmBrilFireOpalCount() !=
            miscmagic.mmpHelmBrilJewelGemCount(2) ||
            miscmagic.mmpHelmBrilOpalCount() !=
            miscmagic.mmpHelmBrilJewelGemCount(3)) ++bad;
        // the walker clamps
        if (miscmagic.mmpHelmBrilJewelGemCount(99) != 40 ||
            miscmagic.mmpHelmBrilJewelSpellLevel(99) != 1) ++bad;
        if (miscmagic.mmpHelmComprStrangeTonguesPct() != 90 ||
            miscmagic.mmpHelmComprMagicalWritingsPct() != 80 ||
            miscmagic.mmpHelmComprAllOrNone() != 1 ||
            miscmagic.mmpHelmComprImpliesSpellUse() != 0 ||
            miscmagic.mmpHelmComprHelmetOfAcValue() != 5) ++bad;
        // the comprehend ladder: 90 = 80 + 10
        if (miscmagic.mmpHelmComprStrangeTonguesPct() !=
            miscmagic.mmpHelmComprMagicalWritingsPct() + 10) ++bad;
        if (miscmagic.mmpHelmOppAlignIndeterminateDweomer() !=
            1 ||
            miscmagic.mmpHelmOppAlignCurseOnDonning() != 1 ||
            miscmagic.mmpHelmOppAlignAbsoluteKinds() != 4 ||
            miscmagic.mmpHelmOppAlignAlterationDesired() !=
            1) ++bad;
        if (miscmagic.mmpHelmOppAlignRestoreSpellKinds() != 2 ||
            miscmagic.mmpHelmOppAlignSelfRestoreAttempts() !=
            0 ||
            miscmagic.mmpHelmOppAlignPaladinQuestAndAtone() !=
            1 ||
            miscmagic.mmpHelmOppAlignPowersAfterFunctioning() !=
            0) ++bad;
        if (miscmagic.mmpHelmTelepathyRangeInches() != 6 ||
            miscmagic.mmpHelmTelepathyStoneBarrierFeet() != 3 ||
            miscmagic.mmpHelmTelepathyIronBarrierQuarterFeet() !=
            1 ||
            miscmagic.mmpHelmTelepathyLeadGoldSheetBlocks() !=
            1) ++bad;
        if (miscmagic.mmpHelmTelepathyDirectional() != 1 ||
            miscmagic.mmpHelmTelepathyConsciousEffort() != 1 ||
            miscmagic.mmpHelmTelepathySuggestPctPer2IntAbove() !=
            5 ||
            miscmagic.mmpHelmTelepathySuggestPctPer1IntBelow() !=
            5) ++bad;
        if (miscmagic.mmpHelmTelepathySavePenaltyPer2IntBelow() !=
            1 ||
            miscmagic.mmpHelmTelepathySaveBonusPer1IntAbove() !=
            1 ||
            miscmagic.mmpHelmTelepathyEqualIntSaveAdjustment() !=
            0 ||
            miscmagic.mmpHelmTelepathyPsionicAttackBonus() !=
            4 ||
            miscmagic.mmpHelmTelepathyPsionicStrengthBonus() !=
            40) ++bad;
        if (miscmagic.mmpHelmTeleportPerDay() != 1 ||
            miscmagic.mmpHelmTeleportMuRefreshRepeats() != 3 ||
            miscmagic.mmpHelmTeleportMuStillPersonalAfterRefresh() !=
            1) ++bad;
        if (miscmagic.mmpHelmTeleportMuUncastPersonalCount() !=
            6 ||
            miscmagic.mmpHelmTeleportUsageAfterMemoryLost() !=
            1) ++bad;
        if (miscmagic.mmpHelmUnderwaterSeeAndBreathe() != 1 ||
            miscmagic.mmpHelmUnderwaterLensCompartments() != 2 ||
            miscmagic.mmpHelmUnderwaterVisionFactor() != 5 ||
            miscmagic.mmpHelmUnderwaterObstructionsBlock() !=
            1 ||
            miscmagic.mmpHelmUnderwaterAirGlobeUntilRepeat() !=
            1) ++bad;
        if (miscmagic.mmpHornBlastingConeLengthInches() != 12 ||
            miscmagic.mmpHornBlastingConeBaseWidthInches() != 3 ||
            miscmagic.mmpHornBlastingSaveStunRounds() != 1 ||
            miscmagic.mmpHornBlastingSaveDeafRounds() != 2) ++bad;
        if (miscmagic.mmpHornBlastingFailDmgMin() != 1 ||
            miscmagic.mmpHornBlastingFailDmgMax() != 10 ||
            miscmagic.mmpHornBlastingFailStunRounds() != 2 ||
            miscmagic.mmpHornBlastingFailDeafRounds() != 4) ++bad;
        if (miscmagic.mmpHornBlastingPulseWidthFeet() != 1 ||
            miscmagic.mmpHornBlastingPulseLengthInches() != 10 ||
            miscmagic.mmpHornBlastingCatapultMultiplier() != 3 ||
            miscmagic.mmpHornBlastingCatapultHitDamage() !=
            6) ++bad;
        // the structural ladder: 18 = 6 + 6 + 6
        if (miscmagic.mmpHornBlastingStructuralPoints() !=
            miscmagic.mmpHornBlastingCatapultHitDamage() +
            miscmagic.mmpHornBlastingCatapultHitDamage() +
            miscmagic.mmpHornBlastingCatapultHitDamage()) ++bad;
        if (miscmagic.mmpHornBlastingExplodePctPerExtraUse() !=
            10 ||
            miscmagic.mmpHornBlastingExplodeDmgMin() != 5 ||
            miscmagic.mmpHornBlastingExplodeDmgMax() != 50) ++bad;
        // the explosion is five fold the save
        // damage: 50 = 10 x 5 and 5 = 1 x 5, as
        // sums over the save damage accessor
        if (miscmagic.mmpHornBlastingExplodeDmgMax() !=
            miscmagic.mmpHornBlastingFailDmgMax() +
            miscmagic.mmpHornBlastingFailDmgMax() +
            miscmagic.mmpHornBlastingFailDmgMax() +
            miscmagic.mmpHornBlastingFailDmgMax() +
            miscmagic.mmpHornBlastingFailDmgMax() ||
            miscmagic.mmpHornBlastingExplodeDmgMin() !=
            miscmagic.mmpHornBlastingFailDmgMin() +
            miscmagic.mmpHornBlastingFailDmgMin() +
            miscmagic.mmpHornBlastingFailDmgMin() +
            miscmagic.mmpHornBlastingFailDmgMin() +
            miscmagic.mmpHornBlastingFailDmgMin()) ++bad;
        if (miscmagic.mmpHornBlastingCharges() != 0 ||
            miscmagic.mmpHornBlastingShiverPctPerUse() != 2 ||
            miscmagic.mmpHornBlastingShiverWielderDamage() !=
            0) ++bad;
        if (miscmagic.mmpHornBubblesBlindRoundsMin() != 2 ||
            miscmagic.mmpHornBubblesBlindRoundsMax() != 20 ||
            miscmagic.mmpHornBubblesOnlyWhenSlayerSeeks() !=
            1 ||
            miscmagic.mmpHornBubblesAppearanceMayDelay() !=
            1) ++bad;
        // the kMisc3 rows this slice pins: 10-17,
        // no class marks and no asterisks
        static const int kLo[8] = {
            30, 31, 36, 38, 40, 41, 46, 47,
        };
        static const int kHi[8] = {
            30, 35, 37, 39, 40, 45, 46, 48,
        };
        for (int i = 0; i < 8; ++i)
            if (miscmagic_table3_footnotes.m3RowLo(10 + i) != kLo[i] ||
                miscmagic_table3_footnotes.m3RowHi(10 + i) != kHi[i]) ++bad;
        for (int i = 0; i < 8; ++i)
            if (miscmagic_table3_footnotes.m3UsableByCleric(10 + i) ||
                miscmagic_table3_footnotes.m3UsableByFighter(10 + i) ||
                miscmagic_table3_footnotes.m3UsableByThief(10 + i) ||
                miscmagic_table3_footnotes.m3StarCount(10 + i) ||
                miscmagic_table3_footnotes.m3IsPerFacetValued(10 + i)) ++bad;
        printf("R268 misc magic prose part 12 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
