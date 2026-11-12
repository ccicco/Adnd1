    // ---- R257: the III.E misc magic explanation prose part 1 pins audit ----
    // The first two-part-file round: part1 10949-
    // 11065 stitched into part2 line 3 (Bag of
    // Devouring, the seam fact pinned exactly).
    {
        Miscmagic_alchemy_jug_to_bag_of_devouring miscmagic_alchemy_jug_to_bag_of_devouring;
        Miscmagic_table1_footnotes miscmagic_table1_footnotes;
        int bad = 0;
        // the nine items are the engine kMisc1 rows
        // 0-6, 8 and 9 (the R225 m1 band pins);
        // row 7 is the Artifact or Relic row
        if (miscmagic_table1_footnotes.m1RowCount() != 33) ++bad;
        static const int kM1Lo[7] = {
            1, 3, 5, 6, 8, 12, 14,
        };
        static const int kM1Hi[7] = {
            2, 4, 5, 7, 11, 13, 16,
        };
        for (int i = 0; i < 7; ++i)
            if (miscmagic_table1_footnotes.m1RowLo(i) != kM1Lo[i] ||
                miscmagic_table1_footnotes.m1RowHi(i) != kM1Hi[i]) ++bad;
        if (miscmagic_table1_footnotes.m1RowLo(8) != 18 ||
            miscmagic_table1_footnotes.m1RowHi(8) != 20 ||
            miscmagic_table1_footnotes.m1RowLo(9) != 21 ||
            miscmagic_table1_footnotes.m1RowHi(9) != 21) ++bad;
        // the intro
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpIntroMaxDuplicates() != 3 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpIntroBooksExactWishCount() != 2) ++bad;
        // the alchemy jug: 11 liquids
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpAlchemyJugRowCount() != 11 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAlchemyJugKindsPerDay() != 1 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAlchemyJugPouringsPerDay() != 7 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAlchemyJugGallonsPerRound() != 2 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAlchemyJugRoundsPerLargePouring() != 8) ++bad;
        static const int kJugQty[11] = {
            16, 8, 4, 2, 1, 1, 1, 2, 1, 8, 4,
        };
        static const int kJugUnit[11] = {
            0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4,
        };
        for (int i = 0; i < 11; ++i)
            if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpAlchemyJugRowQty(i) != kJugQty[i] ||
                miscmagic_alchemy_jug_to_bag_of_devouring.mmpAlchemyJugRowUnit(i) != kJugUnit[i]) ++bad;
        // the amulets
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletLocationMultiplier() != 2 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletLifeProtectionDays() != 7 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletProofNoAuraFlag() != 1) ++bad;
        // the amulet of the planes: d6 on d12
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesRowCount() != 17 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesLowDieFaces() != 6 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesHighDieFaces() != 12 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesAddOnHigh() != 12 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesResultMax() != 24 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesAltRowCount() != 3) ++bad;
        static const int kPlLo[17] = {
            1, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14,
            15, 16, 18, 19, 20, 21,
        };
        static const int kPlHi[17] = {
            2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14,
            15, 17, 18, 19, 20, 24,
        };
        for (int i = 0; i < 17; ++i)
            if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesRowLo(i) != kPlLo[i] ||
                miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesRowHi(i) != kPlHi[i]) ++bad;
        static const int kPlAlt[3] = {
            22, 23, 24,
        };
        for (int i = 0; i < 3; ++i)
            if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpAmuletPlanesAltLo(i) != kPlAlt[i]) ++bad;
        // the apparatus of kwalish
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishLeverCount() != 10 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishForwardInches() != 3 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishBackwardInches() != 6 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishPincerReachFeet() != 4 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishPincerDamageLo() != 2 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishPincerDamageHi() != 12 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishPincerHitPct() != 25 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishMaxDepthFeet() != 900 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishOccupants() != 2 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishAirHoursLo() != 2 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishAirHoursHi() != 5 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishArmorClass() != 0 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishLeakHp() != 100 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpKwalishStaveHp() != 200) ++bad;
        // the arrow of direction
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpArrowDirectionUsesPerDay() != 1 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpArrowDirectionRepetitions() != 7 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpArrowDirectionTurns() != 7 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpArrowDirectionRequestKinds() != 5) ++bad;
        // the bag of beans
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanExplodeDamageLo() != 5 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanExplodeDamageHi() != 20 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanExplodeRadiusFeet() != 10 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanOptimumLo() != 3 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanOptimumHi() != 12 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanBeneficialMax() != 2 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanEffectRowCount() != 7 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanBerryCountLo() != 5 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanBerryCountHi() != 20 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanBerryGemLo() != 100 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanBerryGemHi() != 500 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanSmokeRadiusFeet() != 50 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanSmokeTurns() != 5 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanBlindRoundsLo() != 1 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanBlindRoundsHi() != 6 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanGasRadiusFeet() != 20 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpBeanGasTurns() != 1) ++bad;
        // the bag of devouring (the seam item)
        if (miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringIgnorePct() != 90 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringClosePct() != 60 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringBaseDrawPct() != 75 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringDrawModPerPlus() != 5 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringExampleStr18Pct() != 65 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringExampleStr5Pct() != 80 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringCapacityCubicFeet() != 30 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringSwallowPctPerTurn() != 5 ||
            miscmagic_alchemy_jug_to_bag_of_devouring.mmpDevouringConsumeSegments() != 7) ++bad;
        printf("R257 misc magic prose part 1 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
