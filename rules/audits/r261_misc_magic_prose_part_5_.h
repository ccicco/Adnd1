    // ---- R261: the III.E misc magic explanation
    // prose part 5 ----
    // Candle of Invocation through Cloak of
    // Protection, part2 lines 155-220 - the prose
    // pins, completing the kMisc2 rows 0-10. The
    // R226 per-plus asterisk pin verified correct
    // (row 10, 33-55), no off-by-one.
    {
        Miscmagic_candle_of_invocation_to_cloak_of_protection miscmagic_candle_of_invocation_to_cloak_of_protection;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCandleAlignments() != 9 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCandleClericLevelBoost() != 2 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCandleBurnHours() != 4 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCandleGateSpell() != 1) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCarpetRowCount() != 4 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserAirHd() != 12 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserAirMedBonusPerDie() != 3 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserAirWidthInches() != 6 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserAirHeightInches() != 12 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserAirTurnsIfExtinguished() != 1) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserHostileMin() != 1 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserHostileMax() != 4 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCenserHostilePerRound() != 1) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenLengthInches() != 12 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenWizardLockLevel() != 15 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenRoundPerFunction() != 1 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenSoundingsMin() != 4 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenSoundingsMax() != 5 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenChargesMin() != 20 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenChargesMax() != 80 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenChargesDieSides() != 6 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeOpenChargesDieMult() != 10) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeHungerRadiusInches() != 6 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpChimeHungerMinEatRounds() != 1) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpDisplacementMinFeet() != 1 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpDisplacementMaxFeet() != 2 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpDisplacementAcBonus() != 2 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpDisplacementSaveBonus() != 2 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpDisplacementHumanoidPct() != 75 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpDisplacementSmallPct() != 25) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpElvenkindRowCount() != 9 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpElvenkindOutdoorNaturalRows() != 3 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpElvenkindOutdoorOtherRows() != 3 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpElvenkindUndergroundRows() != 3 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpElvenkindHumanoidPct() != 90 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpElvenkindSmallPct() != 10) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpMantaRayLikenessPct() != 90 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpMantaRayMoveInches() != 18 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpMantaRayAc() != 6 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpMantaRayTailDmgMin() != 1 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpMantaRayTailDmgMax() != 6 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpMantaRayTailStun() != 0 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpMantaRaySaltWaterTrigger() != 1) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpPoisonCloakRevivalPctPenalty() != 10 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpPoisonCloakRemoveCurseDestroys() != 1 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpPoisonCloakNeutralizeNoEffect() != 1) ++bad;
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtRowCount() != 5 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtAcPerPlus() != 1 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtSavePerPlus() != 1 ||
            miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtExampleBaseAc() != 10) ++bad;
        static const int kCarpetLo[4] = {
            1, 21, 56, 81,
        };
        static const int kCarpetHi[4] = {
            20, 55, 80, 100,
        };
        static const int kCarpetWidth[4] = {
            3, 4, 5, 6,
        };
        static const int kCarpetLength[4] = {
            5, 6, 7, 9,
        };
        static const int kCarpetPersons[4] = {
            1, 2, 3, 4,
        };
        static const int kCarpetSpeed[4] = {
            42, 36, 30, 24,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCarpetBandLo(i) != kCarpetLo[i] ||
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCarpetBandHi(i) != kCarpetHi[i] ||
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCarpetWidthFeet(i) != kCarpetWidth[i] ||
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCarpetLengthFeet(i) != kCarpetLength[i] ||
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCarpetPersons(i) != kCarpetPersons[i] ||
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCarpetSpeedInches(i) != kCarpetSpeed[i]) ++bad;
        static const int kElvenkindPct[9] = {
            100, 99, 95, 98, 90, 50, 95, 90, 50,
        };
        for (int i = 0; i < 9; ++i)
            if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpElvenkindInvisibilityPct(i) !=
                    kElvenkindPct[i]) ++bad;
        static const int kCloakProtLo[5] = {
            1, 36, 66, 86, 96,
        };
        static const int kCloakProtHi[5] = {
            35, 65, 85, 95, 100,
        };
        static const int kCloakProtPlus[5] = {
            1, 2, 3, 4, 5,
        };
        for (int i = 0; i < 5; ++i)
            if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtBandLo(i) != kCloakProtLo[i] ||
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtBandHi(i) != kCloakProtHi[i] ||
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtPlus(i) !=
                    kCloakProtPlus[i]) ++bad;
        static const int kM2Lo[11] = {
            1, 7, 9, 11, 12, 14, 15, 19, 28, 31, 33,
        };
        static const int kM2Hi[11] = {
            6, 8, 10, 11, 13, 14, 18, 27, 30, 32, 55,
        };
        for (int i = 0; i < 11; ++i)
            if (miscmagic_table2_footnotes.m2RowLo(i) != kM2Lo[i] ||
                miscmagic_table2_footnotes.m2RowHi(i) != kM2Hi[i]) ++bad;
        // the class marks: the Candle is (C); the
        // two Censers are (M); the Carpet row 1
        // is the negative control
        if (!miscmagic_table2_footnotes.m2UsableByCleric(0) ||
            miscmagic_table2_footnotes.m2UsableByCleric(1)) ++bad;
        if (!miscmagic_table2_footnotes.m2UsableByMagicUser(2) ||
            !miscmagic_table2_footnotes.m2UsableByMagicUser(3) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(1) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(10)) ++bad;
        // the per-plus asterisk: row 10 (33-55),
        // the R226 pin verified correct
        if (!miscmagic_table2_footnotes.m2IsPerPlusValued(10) ||
            miscmagic_table2_footnotes.m2IsPerPlusValued(9) ||
            miscmagic_table2_footnotes.m2IsPerPlusValued(11)) ++bad;
        // the printed +2 cloak: 1000 xp / 10000 gp
        // per plus = 2000 / 20000, cross-pinned
        // against the prose plus table
        if (miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtPlus(1) != 2 ||
            miscmagic_table2_footnotes.m2CloakPerPlusXp() *
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtPlus(1) != 2000 ||
            miscmagic_table2_footnotes.m2CloakPerPlusGp() *
                miscmagic_candle_of_invocation_to_cloak_of_protection.mmpCloakProtPlus(1) != 20000) ++bad;
        printf("R261 misc magic prose part 5 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
