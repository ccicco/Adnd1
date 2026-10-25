    // ---- R260: the III.E misc magic explanation
    // prose part 4 ----
    // Bowl Commanding Water Elementals through
    // Bucknard Everfull Purse, part2 lines
    // 110-153 - the prose pins, plus the R225
    // per-AC asterisk off-by-one fixed: the
    // printed asterisk row is 60-79 Bracers of
    // Defense (engine row 25), not row 26
    // (80-81 Defenselessness).
    {
        int bad = 0;
        if (rules::mmpBowlCmdHd() != 12 ||
            rules::mmpBowlCmdWordsRounds() != 1 ||
            rules::mmpBowlCmdSaltBonusPerDie() != 2 ||
            rules::mmpBowlCmdSaltMaxHpPerDie() != 8 ||
            rules::mmpBowlCmdDiameterInches() != 12 ||
            rules::mmpBowlCmdDepthInches() != 6) ++bad;
        if (rules::mmpWateryDeathSaltSavePenalty() != 2 ||
            rules::mmpWateryDeathDrownMinRounds() != 3 ||
            rules::mmpWateryDeathDrownMaxRounds() != 8 ||
            rules::mmpWateryDeathFreeSpellCount() != 3 ||
            rules::mmpWateryDeathDeathPermanent() != 1 ||
            rules::mmpWateryDeathSweetWaterAnotherSave() != 1) ++bad;
        if (rules::mmpBracersDefRowCount() != 7 ||
            rules::mmpBracersDefAcMin() != 2 ||
            rules::mmpBracersDefAcMax() != 8 ||
            rules::mmpDefenselessAc() != 10 ||
            rules::mmpDefenselessNegatesProtections() != 1 ||
            rules::mmpDefenselessRemoveCurseOnly() != 1) ++bad;
        if (rules::mmpBrazierFireHd() != 12 ||
            rules::mmpBrazierFireLightRounds() != 1 ||
            rules::mmpBrazierFireSulphurBonusPerDie() != 1 ||
            rules::mmpBrazierFireSulphurHpMin() != 2 ||
            rules::mmpBrazierFireSulphurHpMax() != 9 ||
            rules::mmpSleepSmokeRadiusInches() != 1 ||
            rules::mmpSleepSmokeHd() != 12 ||
            rules::mmpSleepSmokeAwakenSpellCount() != 2) ++bad;
        if (rules::mmpBroochPctWithoutGems() != 90 ||
            rules::mmpBroochAbsorbHp() != 101) ++bad;
        if (rules::mmpBroomAttackDumpMinFeet() != 6 ||
            rules::mmpBroomAttackDumpMaxFeet() != 9 ||
            rules::mmpBroomAttackAttacksPerRound() != 2 ||
            rules::mmpBroomAttackAsHd() != 4 ||
            rules::mmpBroomAttackStrawBlindRounds() != 1 ||
            rules::mmpBroomAttackHandleDmgMin() != 1 ||
            rules::mmpBroomAttackHandleDmgMax() != 3 ||
            rules::mmpBroomAttackAc() != 7 ||
            rules::mmpBroomAttackHpToDestroy() != 18) ++bad;
        if (rules::mmpBroomFlySpeedInches() != 30 ||
            rules::mmpBroomFlyCapacityPounds() != 182 ||
            rules::mmpBroomFlyPoundsPerInch() != 14 ||
            rules::mmpBroomFlyClimbDiveDegrees() != 30 ||
            rules::mmpBroomFlyFetchSpeedInches() != 30) ++bad;
        if (rules::mmpPurseCoinsPerType() != 26 ||
            rules::mmpPurseTypeRowCount() != 3 ||
            rules::mmpPurseGemsBaseGp() != 10 ||
            rules::mmpPurseGemsMaxGp() != 100 ||
            rules::mmpPurseAbilitiesNeverChange() != 1 ||
            rules::mmpPurseSpiceNote() != 1) ++bad;
        static const int kBracersDefLo[7] = {
            1, 6, 16, 36, 51, 71, 86,
        };
        static const int kBracersDefHi[7] = {
            5, 15, 35, 50, 70, 85, 100,
        };
        static const int kBracersDefAc[7] = {
            8, 7, 6, 5, 4, 3, 2,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::mmpBracersDefBandLo(i) != kBracersDefLo[i] ||
                rules::mmpBracersDefBandHi(i) != kBracersDefHi[i] ||
                rules::mmpBracersDefAc(i) != kBracersDefAc[i]) ++bad;
        static const int kPurseLo[3] = {
            1, 51, 91,
        };
        static const int kPurseHi[3] = {
            50, 90, 100,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::mmpPurseTypeBandLo(i) != kPurseLo[i] ||
                rules::mmpPurseTypeBandHi(i) != kPurseHi[i]) ++bad;
        static const int kM1Lo[10] = {
            56, 59, 60, 80, 82, 85, 86, 93, 94, 99,
        };
        static const int kM1Hi[10] = {
            58, 59, 79, 81, 84, 85, 92, 93, 98, 100,
        };
        for (int i = 0; i < 10; ++i)
            if (rules::m1RowLo(i + 23) != kM1Lo[i] ||
                rules::m1RowHi(i + 23) != kM1Hi[i]) ++bad;
        // the (M) marks: the two Bowls and the two
        // Braziers; Bracers of Defense row 25 is
        // the negative control
        if (!rules::m1UsableByMagicUser(23) ||
            !rules::m1UsableByMagicUser(24) ||
            !rules::m1UsableByMagicUser(27) ||
            !rules::m1UsableByMagicUser(28) ||
            rules::m1UsableByMagicUser(25)) ++bad;
        // the R225 per-AC asterisk fix: the flag
        // belongs on row 25 (60-79), the printed
        // asterisk row, not row 26
        if (!rules::m1IsPerAcPointValued(25) ||
            rules::m1IsPerAcPointValued(26) ||
            rules::m1IsPerAcPointValued(24)) ++bad;
        if (!rules::m1IsTieredPurseRow(32) ||
            rules::m1IsTieredPurseRow(31)) ++bad;
        // the printed example: AC 6 (band row 2)
        // is 4 points above 10 = 2,000 xp /
        // 12,000 gp
        if (rules::mmpBracersDefAc(2) != 6 ||
            rules::m1BracersPerAcXp() *
                (10 - rules::mmpBracersDefAc(2)) != 2000 ||
            rules::m1BracersPerAcGp() *
                (10 - rules::mmpBracersDefAc(2)) != 12000) ++bad;
        printf("R260 misc magic prose part 4 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
