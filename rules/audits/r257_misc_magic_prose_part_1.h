    // ---- R257: the III.E misc magic explanation prose part 1 pins audit ----
    // The first two-part-file round: part1 10949-
    // 11065 stitched into part2 line 3 (Bag of
    // Devouring, the seam fact pinned exactly).
    {
        int bad = 0;
        // the nine items are the engine kMisc1 rows
        // 0-6, 8 and 9 (the R225 m1 band pins);
        // row 7 is the Artifact or Relic row
        if (rules::m1RowCount() != 33) ++bad;
        static const int kM1Lo[7] = {
            1, 3, 5, 6, 8, 12, 14,
        };
        static const int kM1Hi[7] = {
            2, 4, 5, 7, 11, 13, 16,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::m1RowLo(i) != kM1Lo[i] ||
                rules::m1RowHi(i) != kM1Hi[i]) ++bad;
        if (rules::m1RowLo(8) != 18 ||
            rules::m1RowHi(8) != 20 ||
            rules::m1RowLo(9) != 21 ||
            rules::m1RowHi(9) != 21) ++bad;
        // the intro
        if (rules::mmpIntroMaxDuplicates() != 3 ||
            rules::mmpIntroBooksExactWishCount() != 2) ++bad;
        // the alchemy jug: 11 liquids
        if (rules::mmpAlchemyJugRowCount() != 11 ||
            rules::mmpAlchemyJugKindsPerDay() != 1 ||
            rules::mmpAlchemyJugPouringsPerDay() != 7 ||
            rules::mmpAlchemyJugGallonsPerRound() != 2 ||
            rules::mmpAlchemyJugRoundsPerLargePouring() != 8) ++bad;
        static const int kJugQty[11] = {
            16, 8, 4, 2, 1, 1, 1, 2, 1, 8, 4,
        };
        static const int kJugUnit[11] = {
            0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4,
        };
        for (int i = 0; i < 11; ++i)
            if (rules::mmpAlchemyJugRowQty(i) != kJugQty[i] ||
                rules::mmpAlchemyJugRowUnit(i) != kJugUnit[i]) ++bad;
        // the amulets
        if (rules::mmpAmuletLocationMultiplier() != 2 ||
            rules::mmpAmuletLifeProtectionDays() != 7 ||
            rules::mmpAmuletProofNoAuraFlag() != 1) ++bad;
        // the amulet of the planes: d6 on d12
        if (rules::mmpAmuletPlanesRowCount() != 17 ||
            rules::mmpAmuletPlanesLowDieFaces() != 6 ||
            rules::mmpAmuletPlanesHighDieFaces() != 12 ||
            rules::mmpAmuletPlanesAddOnHigh() != 12 ||
            rules::mmpAmuletPlanesResultMax() != 24 ||
            rules::mmpAmuletPlanesAltRowCount() != 3) ++bad;
        static const int kPlLo[17] = {
            1, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14,
            15, 16, 18, 19, 20, 21,
        };
        static const int kPlHi[17] = {
            2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14,
            15, 17, 18, 19, 20, 24,
        };
        for (int i = 0; i < 17; ++i)
            if (rules::mmpAmuletPlanesRowLo(i) != kPlLo[i] ||
                rules::mmpAmuletPlanesRowHi(i) != kPlHi[i]) ++bad;
        static const int kPlAlt[3] = {
            22, 23, 24,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::mmpAmuletPlanesAltLo(i) != kPlAlt[i]) ++bad;
        // the apparatus of kwalish
        if (rules::mmpKwalishLeverCount() != 10 ||
            rules::mmpKwalishForwardInches() != 3 ||
            rules::mmpKwalishBackwardInches() != 6 ||
            rules::mmpKwalishPincerReachFeet() != 4 ||
            rules::mmpKwalishPincerDamageLo() != 2 ||
            rules::mmpKwalishPincerDamageHi() != 12 ||
            rules::mmpKwalishPincerHitPct() != 25 ||
            rules::mmpKwalishMaxDepthFeet() != 900 ||
            rules::mmpKwalishOccupants() != 2 ||
            rules::mmpKwalishAirHoursLo() != 2 ||
            rules::mmpKwalishAirHoursHi() != 5 ||
            rules::mmpKwalishArmorClass() != 0 ||
            rules::mmpKwalishLeakHp() != 100 ||
            rules::mmpKwalishStaveHp() != 200) ++bad;
        // the arrow of direction
        if (rules::mmpArrowDirectionUsesPerDay() != 1 ||
            rules::mmpArrowDirectionRepetitions() != 7 ||
            rules::mmpArrowDirectionTurns() != 7 ||
            rules::mmpArrowDirectionRequestKinds() != 5) ++bad;
        // the bag of beans
        if (rules::mmpBeanExplodeDamageLo() != 5 ||
            rules::mmpBeanExplodeDamageHi() != 20 ||
            rules::mmpBeanExplodeRadiusFeet() != 10 ||
            rules::mmpBeanOptimumLo() != 3 ||
            rules::mmpBeanOptimumHi() != 12 ||
            rules::mmpBeanBeneficialMax() != 2 ||
            rules::mmpBeanEffectRowCount() != 7 ||
            rules::mmpBeanBerryCountLo() != 5 ||
            rules::mmpBeanBerryCountHi() != 20 ||
            rules::mmpBeanBerryGemLo() != 100 ||
            rules::mmpBeanBerryGemHi() != 500 ||
            rules::mmpBeanSmokeRadiusFeet() != 50 ||
            rules::mmpBeanSmokeTurns() != 5 ||
            rules::mmpBeanBlindRoundsLo() != 1 ||
            rules::mmpBeanBlindRoundsHi() != 6 ||
            rules::mmpBeanGasRadiusFeet() != 20 ||
            rules::mmpBeanGasTurns() != 1) ++bad;
        // the bag of devouring (the seam item)
        if (rules::mmpDevouringIgnorePct() != 90 ||
            rules::mmpDevouringClosePct() != 60 ||
            rules::mmpDevouringBaseDrawPct() != 75 ||
            rules::mmpDevouringDrawModPerPlus() != 5 ||
            rules::mmpDevouringExampleStr18Pct() != 65 ||
            rules::mmpDevouringExampleStr5Pct() != 80 ||
            rules::mmpDevouringCapacityCubicFeet() != 30 ||
            rules::mmpDevouringSwallowPctPerTurn() != 5 ||
            rules::mmpDevouringConsumeSegments() != 7) ++bad;
        printf("R257 misc magic prose part 1 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
