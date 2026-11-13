    // ---- R263: the III.E misc magic explanation
    // prose part 7 ----
    // Cube of Force through Decanter of Endless
    // Water, part2 lines 285-322 - the prose pins,
    // completing the kMisc2 rows 13-17. This
    // stretch carries no class marks and no
    // asterisk rows (the negative control slice).
    {
        int bad = 0;
        if (rules::mmpCubeForceWallInches() != 1 ||
            rules::mmpCubeForceCharges() != 36 ||
            rules::mmpCubeForceRestoreDays() != 1 ||
            rules::mmpCubeForceFaceCount() != 6 ||
            rules::mmpCubeForceSurchargeFormCount() != 14 ||
            rules::mmpCubeForceSpellsInOutBlocked() != 1 ||
            rules::mmpCubeForceMaterialCount() != 3) ++bad;
        if (rules::mmpCubeFrostSideInches() != 1 ||
            rules::mmpCubeFrostTempF() != 65 ||
            rules::mmpCubeFrostColdAttackCount() != 3 ||
            rules::mmpCubeFrostCollapseHp() != 50 ||
            rules::mmpCubeFrostTurnRounds() != 10 ||
            rules::mmpCubeFrostRenewHours() != 1 ||
            rules::mmpCubeFrostDestroyHp() != 100 ||
            rules::mmpCubeFrostColdPer10BelowF() != 2 ||
            rules::mmpCubeFrostAt40BelowHp() != 42) ++bad;
        if (rules::mmpCubicGateSideCount() != 6 ||
            rules::mmpCubicGatePrimeSides() != 1 ||
            rules::mmpCubicGateChosenSides() != 5 ||
            rules::mmpCubicGateNexusChancePct() != 10 ||
            rules::mmpCubicGateDrawRadiusFeet() != 5 ||
            rules::mmpCubicGateMaxLinks() != 1) ++bad;
        if (rules::mmpDaernSquareFeet() != 20 ||
            rules::mmpDaernHeightFeet() != 30 ||
            rules::mmpDaernGroundDepthFeet() != 10 ||
            rules::mmpDaernCollapseHp() != 200 ||
            rules::mmpDaernWishRepairHp() != 10 ||
            rules::mmpDaernSpringRounds() != 1 ||
            rules::mmpDaernGrowthDamageMin() != 10 ||
            rules::mmpDaernGrowthDamageMax() != 100 ||
            rules::mmpDaernDoorOwnerOnly() != 1 ||
            rules::mmpDaernNormalWeaponsAffect() != 0 ||
            rules::mmpDaernDamageCumulative() != 1) ++bad;
        if (rules::mmpDecanterModeCount() != 3 ||
            rules::mmpDecanterStreamGallonsPerRound() != 1 ||
            rules::mmpDecanterFountainLengthFeet() != 5 ||
            rules::mmpDecanterFountainGallonsPerRound() != 5 ||
            rules::mmpDecanterGeyserLengthFeet() != 20 ||
            rules::mmpDecanterGeyserGallonsPerRound() != 30 ||
            rules::mmpDecanterWaterTypeCount() != 2 ||
            rules::mmpDecanterGeyserKnockover() != 1 ||
            rules::mmpDecanterStopsOnCommand() != 1) ++bad;
        static const int kFaceCost[6] = {
            1, 2, 3, 4, 6, 0,
        };
        static const int kFaceMove[6] = {
            1, 8, 6, 4, 3, 0,
        };
        static const int kSurcharge[14] = {
            1, 3, 2, 4, 6, 8, 3, 3, 6, 5, 3, 7, 3, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::mmpCubeForceCostPerTurn(i) !=
                kFaceCost[i] ||
                rules::mmpCubeForceMoveInches(i) !=
                kFaceMove[i]) ++bad;
        for (int i = 0; i < 14; ++i)
            if (rules::mmpCubeForceSurchargeAt(i) !=
                kSurcharge[i]) ++bad;
        // the printed frost math: at minus 40 F the
        // device withstands only 42 hp - 50 minus 2
        // hp per 10 degrees below zero
        if (rules::mmpCubeFrostCollapseHp() -
            rules::mmpCubeFrostColdPer10BelowF() * 4 !=
            rules::mmpCubeFrostAt40BelowHp()) ++bad;
        // the kMisc2 rows this slice completes:
        // 13 Cube of Force 62-63, 14 Frost 64-65,
        // 15 Cubic Gate 66-67, 16 Daern 68-69,
        // 17 Decanter 70-72
        static const int kM2Lo3[5] = {
            62, 64, 66, 68, 70,
        };
        static const int kM2Hi3[5] = {
            63, 65, 67, 69, 72,
        };
        for (int i = 0; i < 5; ++i)
            if (rules::m2RowLo(13 + i) != kM2Lo3[i] ||
                rules::m2RowHi(13 + i) != kM2Hi3[i]) ++bad;
        // the negative control stretch: no (C), no
        // (M), no asterisk rows on 13-17; row 12
        // is the (M) positive control
        for (int i = 13; i < 18; ++i)
            if (rules::m2UsableByCleric(i) ||
                rules::m2UsableByMagicUser(i) ||
                rules::m2IsPerPlusValued(i) ||
                rules::m2HasFeatureAsterisk(i) ||
                rules::m2IsTripleStar(i)) ++bad;
        if (!rules::m2UsableByMagicUser(12)) ++bad;
        printf("R263 misc magic prose part 7 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
