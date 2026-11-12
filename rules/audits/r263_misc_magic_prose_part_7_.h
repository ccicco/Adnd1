    // ---- R263: the III.E misc magic explanation
    // prose part 7 ----
    // Cube of Force through Decanter of Endless
    // Water, part2 lines 285-322 - the prose pins,
    // completing the kMisc2 rows 13-17. This
    // stretch carries no class marks and no
    // asterisk rows (the negative control slice).
    {
        Miscmagic_cube_of_force_to_decanter_of_endless_water miscmagic_cube_of_force_to_decanter_of_endless_water;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceWallInches() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceCharges() != 36 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceRestoreDays() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceFaceCount() != 6 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceSurchargeFormCount() != 14 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceSpellsInOutBlocked() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceMaterialCount() != 3) ++bad;
        if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostSideInches() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostTempF() != 65 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostColdAttackCount() != 3 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostCollapseHp() != 50 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostTurnRounds() != 10 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostRenewHours() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostDestroyHp() != 100 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostColdPer10BelowF() != 2 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostAt40BelowHp() != 42) ++bad;
        if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubicGateSideCount() != 6 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubicGatePrimeSides() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubicGateChosenSides() != 5 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubicGateNexusChancePct() != 10 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubicGateDrawRadiusFeet() != 5 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubicGateMaxLinks() != 1) ++bad;
        if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernSquareFeet() != 20 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernHeightFeet() != 30 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernGroundDepthFeet() != 10 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernCollapseHp() != 200 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernWishRepairHp() != 10 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernSpringRounds() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernGrowthDamageMin() != 10 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernGrowthDamageMax() != 100 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernDoorOwnerOnly() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernNormalWeaponsAffect() != 0 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDaernDamageCumulative() != 1) ++bad;
        if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterModeCount() != 3 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterStreamGallonsPerRound() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterFountainLengthFeet() != 5 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterFountainGallonsPerRound() != 5 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterGeyserLengthFeet() != 20 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterGeyserGallonsPerRound() != 30 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterWaterTypeCount() != 2 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterGeyserKnockover() != 1 ||
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpDecanterStopsOnCommand() != 1) ++bad;
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
            if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceCostPerTurn(i) !=
                kFaceCost[i] ||
                miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceMoveInches(i) !=
                kFaceMove[i]) ++bad;
        for (int i = 0; i < 14; ++i)
            if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeForceSurchargeAt(i) !=
                kSurcharge[i]) ++bad;
        // the printed frost math: at minus 40 F the
        // device withstands only 42 hp - 50 minus 2
        // hp per 10 degrees below zero
        if (miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostCollapseHp() -
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostColdPer10BelowF() * 4 !=
            miscmagic_cube_of_force_to_decanter_of_endless_water.mmpCubeFrostAt40BelowHp()) ++bad;
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
            if (miscmagic_table2_footnotes.m2RowLo(13 + i) != kM2Lo3[i] ||
                miscmagic_table2_footnotes.m2RowHi(13 + i) != kM2Hi3[i]) ++bad;
        // the negative control stretch: no (C), no
        // (M), no asterisk rows on 13-17; row 12
        // is the (M) positive control
        for (int i = 13; i < 18; ++i)
            if (miscmagic_table2_footnotes.m2UsableByCleric(i) ||
                miscmagic_table2_footnotes.m2UsableByMagicUser(i) ||
                miscmagic_table2_footnotes.m2IsPerPlusValued(i) ||
                miscmagic_table2_footnotes.m2HasFeatureAsterisk(i) ||
                miscmagic_table2_footnotes.m2IsTripleStar(i)) ++bad;
        if (!miscmagic_table2_footnotes.m2UsableByMagicUser(12)) ++bad;
        printf("R263 misc magic prose part 7 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
