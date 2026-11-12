    // ---- R268: the III.E misc magic explanation
    // prose part 12 ----
    // Helm of Brilliance through the Horn of
    // Bubbles, part2 lines 532-579 - the slice
    // pinning the kMisc3 rows 10-17.
    {
        Miscmagic_helm_of_brilliance_to_horn_of_bubbles miscmagic_helm_of_brilliance_to_horn_of_bubbles;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilCommandWordOnly() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilTrueNatureVisible() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilArmorPlus() != 2) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilDiamondCount() != 10 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilRubyCount() != 20 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilFireOpalCount() != 30 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilOpalCount() != 40 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilScintillatesInBrightLight() !=
            1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelUseSegments() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelUsableOnce() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilUsesPerRound() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilSpellLevelDoublingFactor() !=
            2) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilUndeadGlowRangeFeet() != 30 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilUndeadPainDmgMin() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilUndeadPainDmgMax() != 6 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilUndeadExemptKinds() != 2) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilFlameSwordEffectRounds() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilFlameSwordAdditional() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilProduceFlameDruidLevel() !=
            5) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilFireResistRingStrength() != 2 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilFireResistAugmentable() != 0 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilPowderOnExpenditure() != 1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelRemovalDestroys() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelRemagickable() != 0 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilRetrySaveWithoutMagic() !=
            1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilOverloadDetonatesRemaining() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilOverloadEffectsInMultiple() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelRowCount() != 4) ++bad;
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
            if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(i) !=
                kGem[i] ||
                miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelSpellLevel(i) !=
                kLvl[i] ||
                miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelCasterKind(i) !=
                kCst[i] ||
                miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelFunctionKind(i) !=
                kFn[i]) ++bad;
        // the gem ladder climbs by 10, the spell
        // level ladder falls by 2
        for (int i = 0; i < 3; ++i)
            if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(i + 1) !=
                miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(i) + 10 ||
                miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelSpellLevel(i) !=
                miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelSpellLevel(i + 1) +
                2) ++bad;
        // the diamond function is the highest spell
        // level, the opal function the lowest; the
        // diamond row is the sparsest gem row
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelSpellLevel(0) !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelSpellLevel(3) + 6 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(0) + 30 !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(3)) ++bad;
        // the intro counts name the table rows
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilDiamondCount() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(0) ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilRubyCount() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(1) ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilFireOpalCount() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(2) ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilOpalCount() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(3)) ++bad;
        // the walker clamps
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelGemCount(99) != 40 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmBrilJewelSpellLevel(99) != 1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmComprStrangeTonguesPct() != 90 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmComprMagicalWritingsPct() != 80 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmComprAllOrNone() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmComprImpliesSpellUse() != 0 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmComprHelmetOfAcValue() != 5) ++bad;
        // the comprehend ladder: 90 = 80 + 10
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmComprStrangeTonguesPct() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmComprMagicalWritingsPct() + 10) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignIndeterminateDweomer() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignCurseOnDonning() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignAbsoluteKinds() != 4 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignAlterationDesired() !=
            1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignRestoreSpellKinds() != 2 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignSelfRestoreAttempts() !=
            0 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignPaladinQuestAndAtone() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmOppAlignPowersAfterFunctioning() !=
            0) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyRangeInches() != 6 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyStoneBarrierFeet() != 3 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyIronBarrierQuarterFeet() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyLeadGoldSheetBlocks() !=
            1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyDirectional() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyConsciousEffort() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathySuggestPctPer2IntAbove() !=
            5 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathySuggestPctPer1IntBelow() !=
            5) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathySavePenaltyPer2IntBelow() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathySaveBonusPer1IntAbove() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyEqualIntSaveAdjustment() !=
            0 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyPsionicAttackBonus() !=
            4 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTelepathyPsionicStrengthBonus() !=
            40) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTeleportPerDay() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTeleportMuRefreshRepeats() != 3 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTeleportMuStillPersonalAfterRefresh() !=
            1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTeleportMuUncastPersonalCount() !=
            6 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmTeleportUsageAfterMemoryLost() !=
            1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmUnderwaterSeeAndBreathe() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmUnderwaterLensCompartments() != 2 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmUnderwaterVisionFactor() != 5 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmUnderwaterObstructionsBlock() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHelmUnderwaterAirGlobeUntilRepeat() !=
            1) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingConeLengthInches() != 12 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingConeBaseWidthInches() != 3 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingSaveStunRounds() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingSaveDeafRounds() != 2) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMin() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMax() != 10 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailStunRounds() != 2 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDeafRounds() != 4) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingPulseWidthFeet() != 1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingPulseLengthInches() != 10 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingCatapultMultiplier() != 3 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingCatapultHitDamage() !=
            6) ++bad;
        // the structural ladder: 18 = 6 + 6 + 6
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingStructuralPoints() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingCatapultHitDamage() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingCatapultHitDamage() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingCatapultHitDamage()) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingExplodePctPerExtraUse() !=
            10 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingExplodeDmgMin() != 5 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingExplodeDmgMax() != 50) ++bad;
        // the explosion is five fold the save
        // damage: 50 = 10 x 5 and 5 = 1 x 5, as
        // sums over the save damage accessor
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingExplodeDmgMax() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMax() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMax() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMax() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMax() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMax() ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingExplodeDmgMin() !=
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMin() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMin() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMin() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMin() +
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingFailDmgMin()) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingCharges() != 0 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingShiverPctPerUse() != 2 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBlastingShiverWielderDamage() !=
            0) ++bad;
        if (miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBubblesBlindRoundsMin() != 2 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBubblesBlindRoundsMax() != 20 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBubblesOnlyWhenSlayerSeeks() !=
            1 ||
            miscmagic_helm_of_brilliance_to_horn_of_bubbles.mmpHornBubblesAppearanceMayDelay() !=
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
