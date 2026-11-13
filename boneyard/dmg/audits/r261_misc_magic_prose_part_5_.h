    // ---- R261: the III.E misc magic explanation
    // prose part 5 ----
    // Candle of Invocation through Cloak of
    // Protection, part2 lines 155-220 - the prose
    // pins, completing the kMisc2 rows 0-10. The
    // R226 per-plus asterisk pin verified correct
    // (row 10, 33-55), no off-by-one.
    {
        int bad = 0;
        if (rules::mmpCandleAlignments() != 9 ||
            rules::mmpCandleClericLevelBoost() != 2 ||
            rules::mmpCandleBurnHours() != 4 ||
            rules::mmpCandleGateSpell() != 1) ++bad;
        if (rules::mmpCarpetRowCount() != 4 ||
            rules::mmpCenserAirHd() != 12 ||
            rules::mmpCenserAirMedBonusPerDie() != 3 ||
            rules::mmpCenserAirWidthInches() != 6 ||
            rules::mmpCenserAirHeightInches() != 12 ||
            rules::mmpCenserAirTurnsIfExtinguished() != 1) ++bad;
        if (rules::mmpCenserHostileMin() != 1 ||
            rules::mmpCenserHostileMax() != 4 ||
            rules::mmpCenserHostilePerRound() != 1) ++bad;
        if (rules::mmpChimeOpenLengthInches() != 12 ||
            rules::mmpChimeOpenWizardLockLevel() != 15 ||
            rules::mmpChimeOpenRoundPerFunction() != 1 ||
            rules::mmpChimeOpenSoundingsMin() != 4 ||
            rules::mmpChimeOpenSoundingsMax() != 5 ||
            rules::mmpChimeOpenChargesMin() != 20 ||
            rules::mmpChimeOpenChargesMax() != 80 ||
            rules::mmpChimeOpenChargesDieSides() != 6 ||
            rules::mmpChimeOpenChargesDieMult() != 10) ++bad;
        if (rules::mmpChimeHungerRadiusInches() != 6 ||
            rules::mmpChimeHungerMinEatRounds() != 1) ++bad;
        if (rules::mmpDisplacementMinFeet() != 1 ||
            rules::mmpDisplacementMaxFeet() != 2 ||
            rules::mmpDisplacementAcBonus() != 2 ||
            rules::mmpDisplacementSaveBonus() != 2 ||
            rules::mmpDisplacementHumanoidPct() != 75 ||
            rules::mmpDisplacementSmallPct() != 25) ++bad;
        if (rules::mmpElvenkindRowCount() != 9 ||
            rules::mmpElvenkindOutdoorNaturalRows() != 3 ||
            rules::mmpElvenkindOutdoorOtherRows() != 3 ||
            rules::mmpElvenkindUndergroundRows() != 3 ||
            rules::mmpElvenkindHumanoidPct() != 90 ||
            rules::mmpElvenkindSmallPct() != 10) ++bad;
        if (rules::mmpMantaRayLikenessPct() != 90 ||
            rules::mmpMantaRayMoveInches() != 18 ||
            rules::mmpMantaRayAc() != 6 ||
            rules::mmpMantaRayTailDmgMin() != 1 ||
            rules::mmpMantaRayTailDmgMax() != 6 ||
            rules::mmpMantaRayTailStun() != 0 ||
            rules::mmpMantaRaySaltWaterTrigger() != 1) ++bad;
        if (rules::mmpPoisonCloakRevivalPctPenalty() != 10 ||
            rules::mmpPoisonCloakRemoveCurseDestroys() != 1 ||
            rules::mmpPoisonCloakNeutralizeNoEffect() != 1) ++bad;
        if (rules::mmpCloakProtRowCount() != 5 ||
            rules::mmpCloakProtAcPerPlus() != 1 ||
            rules::mmpCloakProtSavePerPlus() != 1 ||
            rules::mmpCloakProtExampleBaseAc() != 10) ++bad;
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
            if (rules::mmpCarpetBandLo(i) != kCarpetLo[i] ||
                rules::mmpCarpetBandHi(i) != kCarpetHi[i] ||
                rules::mmpCarpetWidthFeet(i) != kCarpetWidth[i] ||
                rules::mmpCarpetLengthFeet(i) != kCarpetLength[i] ||
                rules::mmpCarpetPersons(i) != kCarpetPersons[i] ||
                rules::mmpCarpetSpeedInches(i) != kCarpetSpeed[i]) ++bad;
        static const int kElvenkindPct[9] = {
            100, 99, 95, 98, 90, 50, 95, 90, 50,
        };
        for (int i = 0; i < 9; ++i)
            if (rules::mmpElvenkindInvisibilityPct(i) !=
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
            if (rules::mmpCloakProtBandLo(i) != kCloakProtLo[i] ||
                rules::mmpCloakProtBandHi(i) != kCloakProtHi[i] ||
                rules::mmpCloakProtPlus(i) !=
                    kCloakProtPlus[i]) ++bad;
        static const int kM2Lo[11] = {
            1, 7, 9, 11, 12, 14, 15, 19, 28, 31, 33,
        };
        static const int kM2Hi[11] = {
            6, 8, 10, 11, 13, 14, 18, 27, 30, 32, 55,
        };
        for (int i = 0; i < 11; ++i)
            if (rules::m2RowLo(i) != kM2Lo[i] ||
                rules::m2RowHi(i) != kM2Hi[i]) ++bad;
        // the class marks: the Candle is (C); the
        // two Censers are (M); the Carpet row 1
        // is the negative control
        if (!rules::m2UsableByCleric(0) ||
            rules::m2UsableByCleric(1)) ++bad;
        if (!rules::m2UsableByMagicUser(2) ||
            !rules::m2UsableByMagicUser(3) ||
            rules::m2UsableByMagicUser(1) ||
            rules::m2UsableByMagicUser(10)) ++bad;
        // the per-plus asterisk: row 10 (33-55),
        // the R226 pin verified correct
        if (!rules::m2IsPerPlusValued(10) ||
            rules::m2IsPerPlusValued(9) ||
            rules::m2IsPerPlusValued(11)) ++bad;
        // the printed +2 cloak: 1000 xp / 10000 gp
        // per plus = 2000 / 20000, cross-pinned
        // against the prose plus table
        if (rules::mmpCloakProtPlus(1) != 2 ||
            rules::m2CloakPerPlusXp() *
                rules::mmpCloakProtPlus(1) != 2000 ||
            rules::m2CloakPerPlusGp() *
                rules::mmpCloakProtPlus(1) != 20000) ++bad;
        printf("R261 misc magic prose part 5 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
