    // ---- R261: the III.E misc magic explanation
    // prose part 5 ----
    // Candle of Invocation through Cloak of
    // Protection, part2 lines 155-220 - the prose
    // pins, completing the kMisc2 rows 0-10. The
    // R226 per-plus asterisk pin verified correct
    // (row 10, 33-55), no off-by-one.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic.mmpCandleAlignments() != 9 ||
            miscmagic.mmpCandleClericLevelBoost() != 2 ||
            miscmagic.mmpCandleBurnHours() != 4 ||
            miscmagic.mmpCandleGateSpell() != 1) ++bad;
        if (miscmagic.mmpCarpetRowCount() != 4 ||
            miscmagic.mmpCenserAirHd() != 12 ||
            miscmagic.mmpCenserAirMedBonusPerDie() != 3 ||
            miscmagic.mmpCenserAirWidthInches() != 6 ||
            miscmagic.mmpCenserAirHeightInches() != 12 ||
            miscmagic.mmpCenserAirTurnsIfExtinguished() != 1) ++bad;
        if (miscmagic.mmpCenserHostileMin() != 1 ||
            miscmagic.mmpCenserHostileMax() != 4 ||
            miscmagic.mmpCenserHostilePerRound() != 1) ++bad;
        if (miscmagic.mmpChimeOpenLengthInches() != 12 ||
            miscmagic.mmpChimeOpenWizardLockLevel() != 15 ||
            miscmagic.mmpChimeOpenRoundPerFunction() != 1 ||
            miscmagic.mmpChimeOpenSoundingsMin() != 4 ||
            miscmagic.mmpChimeOpenSoundingsMax() != 5 ||
            miscmagic.mmpChimeOpenChargesMin() != 20 ||
            miscmagic.mmpChimeOpenChargesMax() != 80 ||
            miscmagic.mmpChimeOpenChargesDieSides() != 6 ||
            miscmagic.mmpChimeOpenChargesDieMult() != 10) ++bad;
        if (miscmagic.mmpChimeHungerRadiusInches() != 6 ||
            miscmagic.mmpChimeHungerMinEatRounds() != 1) ++bad;
        if (miscmagic.mmpDisplacementMinFeet() != 1 ||
            miscmagic.mmpDisplacementMaxFeet() != 2 ||
            miscmagic.mmpDisplacementAcBonus() != 2 ||
            miscmagic.mmpDisplacementSaveBonus() != 2 ||
            miscmagic.mmpDisplacementHumanoidPct() != 75 ||
            miscmagic.mmpDisplacementSmallPct() != 25) ++bad;
        if (miscmagic.mmpElvenkindRowCount() != 9 ||
            miscmagic.mmpElvenkindOutdoorNaturalRows() != 3 ||
            miscmagic.mmpElvenkindOutdoorOtherRows() != 3 ||
            miscmagic.mmpElvenkindUndergroundRows() != 3 ||
            miscmagic.mmpElvenkindHumanoidPct() != 90 ||
            miscmagic.mmpElvenkindSmallPct() != 10) ++bad;
        if (miscmagic.mmpMantaRayLikenessPct() != 90 ||
            miscmagic.mmpMantaRayMoveInches() != 18 ||
            miscmagic.mmpMantaRayAc() != 6 ||
            miscmagic.mmpMantaRayTailDmgMin() != 1 ||
            miscmagic.mmpMantaRayTailDmgMax() != 6 ||
            miscmagic.mmpMantaRayTailStun() != 0 ||
            miscmagic.mmpMantaRaySaltWaterTrigger() != 1) ++bad;
        if (miscmagic.mmpPoisonCloakRevivalPctPenalty() != 10 ||
            miscmagic.mmpPoisonCloakRemoveCurseDestroys() != 1 ||
            miscmagic.mmpPoisonCloakNeutralizeNoEffect() != 1) ++bad;
        if (miscmagic.mmpCloakProtRowCount() != 5 ||
            miscmagic.mmpCloakProtAcPerPlus() != 1 ||
            miscmagic.mmpCloakProtSavePerPlus() != 1 ||
            miscmagic.mmpCloakProtExampleBaseAc() != 10) ++bad;
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
            if (miscmagic.mmpCarpetBandLo(i) != kCarpetLo[i] ||
                miscmagic.mmpCarpetBandHi(i) != kCarpetHi[i] ||
                miscmagic.mmpCarpetWidthFeet(i) != kCarpetWidth[i] ||
                miscmagic.mmpCarpetLengthFeet(i) != kCarpetLength[i] ||
                miscmagic.mmpCarpetPersons(i) != kCarpetPersons[i] ||
                miscmagic.mmpCarpetSpeedInches(i) != kCarpetSpeed[i]) ++bad;
        static const int kElvenkindPct[9] = {
            100, 99, 95, 98, 90, 50, 95, 90, 50,
        };
        for (int i = 0; i < 9; ++i)
            if (miscmagic.mmpElvenkindInvisibilityPct(i) !=
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
            if (miscmagic.mmpCloakProtBandLo(i) != kCloakProtLo[i] ||
                miscmagic.mmpCloakProtBandHi(i) != kCloakProtHi[i] ||
                miscmagic.mmpCloakProtPlus(i) !=
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
        if (miscmagic.mmpCloakProtPlus(1) != 2 ||
            miscmagic_table2_footnotes.m2CloakPerPlusXp() *
                miscmagic.mmpCloakProtPlus(1) != 2000 ||
            miscmagic_table2_footnotes.m2CloakPerPlusGp() *
                miscmagic.mmpCloakProtPlus(1) != 20000) ++bad;
        printf("R261 misc magic prose part 5 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
