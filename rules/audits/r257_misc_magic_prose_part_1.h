    // ---- R257: the III.E misc magic explanation prose part 1 pins audit ----
    // The first two-part-file round: part1 10949-
    // 11065 stitched into part2 line 3 (Bag of
    // Devouring, the seam fact pinned exactly).
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
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
        if (miscmagic.mmpIntroMaxDuplicates() != 3 ||
            miscmagic.mmpIntroBooksExactWishCount() != 2) ++bad;
        // the alchemy jug: 11 liquids
        if (miscmagic.mmpAlchemyJugRowCount() != 11 ||
            miscmagic.mmpAlchemyJugKindsPerDay() != 1 ||
            miscmagic.mmpAlchemyJugPouringsPerDay() != 7 ||
            miscmagic.mmpAlchemyJugGallonsPerRound() != 2 ||
            miscmagic.mmpAlchemyJugRoundsPerLargePouring() != 8) ++bad;
        static const int kJugQty[11] = {
            16, 8, 4, 2, 1, 1, 1, 2, 1, 8, 4,
        };
        static const int kJugUnit[11] = {
            0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4,
        };
        for (int i = 0; i < 11; ++i)
            if (miscmagic.mmpAlchemyJugRowQty(i) != kJugQty[i] ||
                miscmagic.mmpAlchemyJugRowUnit(i) != kJugUnit[i]) ++bad;
        // the amulets
        if (miscmagic.mmpAmuletLocationMultiplier() != 2 ||
            miscmagic.mmpAmuletLifeProtectionDays() != 7 ||
            miscmagic.mmpAmuletProofNoAuraFlag() != 1) ++bad;
        // the amulet of the planes: d6 on d12
        if (miscmagic.mmpAmuletPlanesRowCount() != 17 ||
            miscmagic.mmpAmuletPlanesLowDieFaces() != 6 ||
            miscmagic.mmpAmuletPlanesHighDieFaces() != 12 ||
            miscmagic.mmpAmuletPlanesAddOnHigh() != 12 ||
            miscmagic.mmpAmuletPlanesResultMax() != 24 ||
            miscmagic.mmpAmuletPlanesAltRowCount() != 3) ++bad;
        static const int kPlLo[17] = {
            1, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14,
            15, 16, 18, 19, 20, 21,
        };
        static const int kPlHi[17] = {
            2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14,
            15, 17, 18, 19, 20, 24,
        };
        for (int i = 0; i < 17; ++i)
            if (miscmagic.mmpAmuletPlanesRowLo(i) != kPlLo[i] ||
                miscmagic.mmpAmuletPlanesRowHi(i) != kPlHi[i]) ++bad;
        static const int kPlAlt[3] = {
            22, 23, 24,
        };
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpAmuletPlanesAltLo(i) != kPlAlt[i]) ++bad;
        // the apparatus of kwalish
        if (miscmagic.mmpKwalishLeverCount() != 10 ||
            miscmagic.mmpKwalishForwardInches() != 3 ||
            miscmagic.mmpKwalishBackwardInches() != 6 ||
            miscmagic.mmpKwalishPincerReachFeet() != 4 ||
            miscmagic.mmpKwalishPincerDamageLo() != 2 ||
            miscmagic.mmpKwalishPincerDamageHi() != 12 ||
            miscmagic.mmpKwalishPincerHitPct() != 25 ||
            miscmagic.mmpKwalishMaxDepthFeet() != 900 ||
            miscmagic.mmpKwalishOccupants() != 2 ||
            miscmagic.mmpKwalishAirHoursLo() != 2 ||
            miscmagic.mmpKwalishAirHoursHi() != 5 ||
            miscmagic.mmpKwalishArmorClass() != 0 ||
            miscmagic.mmpKwalishLeakHp() != 100 ||
            miscmagic.mmpKwalishStaveHp() != 200) ++bad;
        // the arrow of direction
        if (miscmagic.mmpArrowDirectionUsesPerDay() != 1 ||
            miscmagic.mmpArrowDirectionRepetitions() != 7 ||
            miscmagic.mmpArrowDirectionTurns() != 7 ||
            miscmagic.mmpArrowDirectionRequestKinds() != 5) ++bad;
        // the bag of beans
        if (miscmagic.mmpBeanExplodeDamageLo() != 5 ||
            miscmagic.mmpBeanExplodeDamageHi() != 20 ||
            miscmagic.mmpBeanExplodeRadiusFeet() != 10 ||
            miscmagic.mmpBeanOptimumLo() != 3 ||
            miscmagic.mmpBeanOptimumHi() != 12 ||
            miscmagic.mmpBeanBeneficialMax() != 2 ||
            miscmagic.mmpBeanEffectRowCount() != 7 ||
            miscmagic.mmpBeanBerryCountLo() != 5 ||
            miscmagic.mmpBeanBerryCountHi() != 20 ||
            miscmagic.mmpBeanBerryGemLo() != 100 ||
            miscmagic.mmpBeanBerryGemHi() != 500 ||
            miscmagic.mmpBeanSmokeRadiusFeet() != 50 ||
            miscmagic.mmpBeanSmokeTurns() != 5 ||
            miscmagic.mmpBeanBlindRoundsLo() != 1 ||
            miscmagic.mmpBeanBlindRoundsHi() != 6 ||
            miscmagic.mmpBeanGasRadiusFeet() != 20 ||
            miscmagic.mmpBeanGasTurns() != 1) ++bad;
        // the bag of devouring (the seam item)
        if (miscmagic.mmpDevouringIgnorePct() != 90 ||
            miscmagic.mmpDevouringClosePct() != 60 ||
            miscmagic.mmpDevouringBaseDrawPct() != 75 ||
            miscmagic.mmpDevouringDrawModPerPlus() != 5 ||
            miscmagic.mmpDevouringExampleStr18Pct() != 65 ||
            miscmagic.mmpDevouringExampleStr5Pct() != 80 ||
            miscmagic.mmpDevouringCapacityCubicFeet() != 30 ||
            miscmagic.mmpDevouringSwallowPctPerTurn() != 5 ||
            miscmagic.mmpDevouringConsumeSegments() != 7) ++bad;
        printf("R257 misc magic prose part 1 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
