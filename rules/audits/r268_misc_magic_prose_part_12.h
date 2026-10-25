    // ---- R268: the III.E misc magic explanation
    // prose part 12 ----
    // Helm of Brilliance through the Horn of
    // Bubbles, part2 lines 532-579 - the slice
    // pinning the kMisc3 rows 10-17.
    {
        int bad = 0;
        if (rules::mmpHelmBrilCommandWordOnly() != 1 ||
            rules::mmpHelmBrilTrueNatureVisible() != 1 ||
            rules::mmpHelmBrilArmorPlus() != 2) ++bad;
        if (rules::mmpHelmBrilDiamondCount() != 10 ||
            rules::mmpHelmBrilRubyCount() != 20 ||
            rules::mmpHelmBrilFireOpalCount() != 30 ||
            rules::mmpHelmBrilOpalCount() != 40 ||
            rules::mmpHelmBrilScintillatesInBrightLight() !=
            1) ++bad;
        if (rules::mmpHelmBrilJewelUseSegments() != 1 ||
            rules::mmpHelmBrilJewelUsableOnce() != 1 ||
            rules::mmpHelmBrilUsesPerRound() != 1 ||
            rules::mmpHelmBrilSpellLevelDoublingFactor() !=
            2) ++bad;
        if (rules::mmpHelmBrilUndeadGlowRangeFeet() != 30 ||
            rules::mmpHelmBrilUndeadPainDmgMin() != 1 ||
            rules::mmpHelmBrilUndeadPainDmgMax() != 6 ||
            rules::mmpHelmBrilUndeadExemptKinds() != 2) ++bad;
        if (rules::mmpHelmBrilFlameSwordEffectRounds() != 1 ||
            rules::mmpHelmBrilFlameSwordAdditional() != 1 ||
            rules::mmpHelmBrilProduceFlameDruidLevel() !=
            5) ++bad;
        if (rules::mmpHelmBrilFireResistRingStrength() != 2 ||
            rules::mmpHelmBrilFireResistAugmentable() != 0 ||
            rules::mmpHelmBrilPowderOnExpenditure() != 1) ++bad;
        if (rules::mmpHelmBrilJewelRemovalDestroys() != 1 ||
            rules::mmpHelmBrilJewelRemagickable() != 0 ||
            rules::mmpHelmBrilRetrySaveWithoutMagic() !=
            1) ++bad;
        if (rules::mmpHelmBrilOverloadDetonatesRemaining() !=
            1 ||
            rules::mmpHelmBrilOverloadEffectsInMultiple() !=
            1 ||
            rules::mmpHelmBrilJewelRowCount() != 4) ++bad;
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
            if (rules::mmpHelmBrilJewelGemCount(i) !=
                kGem[i] ||
                rules::mmpHelmBrilJewelSpellLevel(i) !=
                kLvl[i] ||
                rules::mmpHelmBrilJewelCasterKind(i) !=
                kCst[i] ||
                rules::mmpHelmBrilJewelFunctionKind(i) !=
                kFn[i]) ++bad;
        // the gem ladder climbs by 10, the spell
        // level ladder falls by 2
        for (int i = 0; i < 3; ++i)
            if (rules::mmpHelmBrilJewelGemCount(i + 1) !=
                rules::mmpHelmBrilJewelGemCount(i) + 10 ||
                rules::mmpHelmBrilJewelSpellLevel(i) !=
                rules::mmpHelmBrilJewelSpellLevel(i + 1) +
                2) ++bad;
        // the diamond function is the highest spell
        // level, the opal function the lowest; the
        // diamond row is the sparsest gem row
        if (rules::mmpHelmBrilJewelSpellLevel(0) !=
            rules::mmpHelmBrilJewelSpellLevel(3) + 6 ||
            rules::mmpHelmBrilJewelGemCount(0) + 30 !=
            rules::mmpHelmBrilJewelGemCount(3)) ++bad;
        // the intro counts name the table rows
        if (rules::mmpHelmBrilDiamondCount() !=
            rules::mmpHelmBrilJewelGemCount(0) ||
            rules::mmpHelmBrilRubyCount() !=
            rules::mmpHelmBrilJewelGemCount(1) ||
            rules::mmpHelmBrilFireOpalCount() !=
            rules::mmpHelmBrilJewelGemCount(2) ||
            rules::mmpHelmBrilOpalCount() !=
            rules::mmpHelmBrilJewelGemCount(3)) ++bad;
        // the walker clamps
        if (rules::mmpHelmBrilJewelGemCount(99) != 40 ||
            rules::mmpHelmBrilJewelSpellLevel(99) != 1) ++bad;
        if (rules::mmpHelmComprStrangeTonguesPct() != 90 ||
            rules::mmpHelmComprMagicalWritingsPct() != 80 ||
            rules::mmpHelmComprAllOrNone() != 1 ||
            rules::mmpHelmComprImpliesSpellUse() != 0 ||
            rules::mmpHelmComprHelmetOfAcValue() != 5) ++bad;
        // the comprehend ladder: 90 = 80 + 10
        if (rules::mmpHelmComprStrangeTonguesPct() !=
            rules::mmpHelmComprMagicalWritingsPct() + 10) ++bad;
        if (rules::mmpHelmOppAlignIndeterminateDweomer() !=
            1 ||
            rules::mmpHelmOppAlignCurseOnDonning() != 1 ||
            rules::mmpHelmOppAlignAbsoluteKinds() != 4 ||
            rules::mmpHelmOppAlignAlterationDesired() !=
            1) ++bad;
        if (rules::mmpHelmOppAlignRestoreSpellKinds() != 2 ||
            rules::mmpHelmOppAlignSelfRestoreAttempts() !=
            0 ||
            rules::mmpHelmOppAlignPaladinQuestAndAtone() !=
            1 ||
            rules::mmpHelmOppAlignPowersAfterFunctioning() !=
            0) ++bad;
        if (rules::mmpHelmTelepathyRangeInches() != 6 ||
            rules::mmpHelmTelepathyStoneBarrierFeet() != 3 ||
            rules::mmpHelmTelepathyIronBarrierQuarterFeet() !=
            1 ||
            rules::mmpHelmTelepathyLeadGoldSheetBlocks() !=
            1) ++bad;
        if (rules::mmpHelmTelepathyDirectional() != 1 ||
            rules::mmpHelmTelepathyConsciousEffort() != 1 ||
            rules::mmpHelmTelepathySuggestPctPer2IntAbove() !=
            5 ||
            rules::mmpHelmTelepathySuggestPctPer1IntBelow() !=
            5) ++bad;
        if (rules::mmpHelmTelepathySavePenaltyPer2IntBelow() !=
            1 ||
            rules::mmpHelmTelepathySaveBonusPer1IntAbove() !=
            1 ||
            rules::mmpHelmTelepathyEqualIntSaveAdjustment() !=
            0 ||
            rules::mmpHelmTelepathyPsionicAttackBonus() !=
            4 ||
            rules::mmpHelmTelepathyPsionicStrengthBonus() !=
            40) ++bad;
        if (rules::mmpHelmTeleportPerDay() != 1 ||
            rules::mmpHelmTeleportMuRefreshRepeats() != 3 ||
            rules::mmpHelmTeleportMuStillPersonalAfterRefresh() !=
            1) ++bad;
        if (rules::mmpHelmTeleportMuUncastPersonalCount() !=
            6 ||
            rules::mmpHelmTeleportUsageAfterMemoryLost() !=
            1) ++bad;
        if (rules::mmpHelmUnderwaterSeeAndBreathe() != 1 ||
            rules::mmpHelmUnderwaterLensCompartments() != 2 ||
            rules::mmpHelmUnderwaterVisionFactor() != 5 ||
            rules::mmpHelmUnderwaterObstructionsBlock() !=
            1 ||
            rules::mmpHelmUnderwaterAirGlobeUntilRepeat() !=
            1) ++bad;
        if (rules::mmpHornBlastingConeLengthInches() != 12 ||
            rules::mmpHornBlastingConeBaseWidthInches() != 3 ||
            rules::mmpHornBlastingSaveStunRounds() != 1 ||
            rules::mmpHornBlastingSaveDeafRounds() != 2) ++bad;
        if (rules::mmpHornBlastingFailDmgMin() != 1 ||
            rules::mmpHornBlastingFailDmgMax() != 10 ||
            rules::mmpHornBlastingFailStunRounds() != 2 ||
            rules::mmpHornBlastingFailDeafRounds() != 4) ++bad;
        if (rules::mmpHornBlastingPulseWidthFeet() != 1 ||
            rules::mmpHornBlastingPulseLengthInches() != 10 ||
            rules::mmpHornBlastingCatapultMultiplier() != 3 ||
            rules::mmpHornBlastingCatapultHitDamage() !=
            6) ++bad;
        // the structural ladder: 18 = 6 + 6 + 6
        if (rules::mmpHornBlastingStructuralPoints() !=
            rules::mmpHornBlastingCatapultHitDamage() +
            rules::mmpHornBlastingCatapultHitDamage() +
            rules::mmpHornBlastingCatapultHitDamage()) ++bad;
        if (rules::mmpHornBlastingExplodePctPerExtraUse() !=
            10 ||
            rules::mmpHornBlastingExplodeDmgMin() != 5 ||
            rules::mmpHornBlastingExplodeDmgMax() != 50) ++bad;
        // the explosion is five fold the save
        // damage: 50 = 10 x 5 and 5 = 1 x 5, as
        // sums over the save damage accessor
        if (rules::mmpHornBlastingExplodeDmgMax() !=
            rules::mmpHornBlastingFailDmgMax() +
            rules::mmpHornBlastingFailDmgMax() +
            rules::mmpHornBlastingFailDmgMax() +
            rules::mmpHornBlastingFailDmgMax() +
            rules::mmpHornBlastingFailDmgMax() ||
            rules::mmpHornBlastingExplodeDmgMin() !=
            rules::mmpHornBlastingFailDmgMin() +
            rules::mmpHornBlastingFailDmgMin() +
            rules::mmpHornBlastingFailDmgMin() +
            rules::mmpHornBlastingFailDmgMin() +
            rules::mmpHornBlastingFailDmgMin()) ++bad;
        if (rules::mmpHornBlastingCharges() != 0 ||
            rules::mmpHornBlastingShiverPctPerUse() != 2 ||
            rules::mmpHornBlastingShiverWielderDamage() !=
            0) ++bad;
        if (rules::mmpHornBubblesBlindRoundsMin() != 2 ||
            rules::mmpHornBubblesBlindRoundsMax() != 20 ||
            rules::mmpHornBubblesOnlyWhenSlayerSeeks() !=
            1 ||
            rules::mmpHornBubblesAppearanceMayDelay() !=
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
            if (rules::m3RowLo(10 + i) != kLo[i] ||
                rules::m3RowHi(10 + i) != kHi[i]) ++bad;
        for (int i = 0; i < 8; ++i)
            if (rules::m3UsableByCleric(10 + i) ||
                rules::m3UsableByFighter(10 + i) ||
                rules::m3UsableByThief(10 + i) ||
                rules::m3StarCount(10 + i) ||
                rules::m3IsPerFacetValued(10 + i)) ++bad;
        printf("R268 misc magic prose part 12 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
