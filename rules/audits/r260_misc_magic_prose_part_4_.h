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
        Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse miscmagic;
        Miscmagic_table1_footnotes miscmagic_table1_footnotes;
        int bad = 0;
        if (miscmagic.mmpBowlCmdHd() != 12 ||
            miscmagic.mmpBowlCmdWordsRounds() != 1 ||
            miscmagic.mmpBowlCmdSaltBonusPerDie() != 2 ||
            miscmagic.mmpBowlCmdSaltMaxHpPerDie() != 8 ||
            miscmagic.mmpBowlCmdDiameterInches() != 12 ||
            miscmagic.mmpBowlCmdDepthInches() != 6) ++bad;
        if (miscmagic.mmpWateryDeathSaltSavePenalty() != 2 ||
            miscmagic.mmpWateryDeathDrownMinRounds() != 3 ||
            miscmagic.mmpWateryDeathDrownMaxRounds() != 8 ||
            miscmagic.mmpWateryDeathFreeSpellCount() != 3 ||
            miscmagic.mmpWateryDeathDeathPermanent() != 1 ||
            miscmagic.mmpWateryDeathSweetWaterAnotherSave() != 1) ++bad;
        if (miscmagic.mmpBracersDefRowCount() != 7 ||
            miscmagic.mmpBracersDefAcMin() != 2 ||
            miscmagic.mmpBracersDefAcMax() != 8 ||
            miscmagic.mmpDefenselessAc() != 10 ||
            miscmagic.mmpDefenselessNegatesProtections() != 1 ||
            miscmagic.mmpDefenselessRemoveCurseOnly() != 1) ++bad;
        if (miscmagic.mmpBrazierFireHd() != 12 ||
            miscmagic.mmpBrazierFireLightRounds() != 1 ||
            miscmagic.mmpBrazierFireSulphurBonusPerDie() != 1 ||
            miscmagic.mmpBrazierFireSulphurHpMin() != 2 ||
            miscmagic.mmpBrazierFireSulphurHpMax() != 9 ||
            miscmagic.mmpSleepSmokeRadiusInches() != 1 ||
            miscmagic.mmpSleepSmokeHd() != 12 ||
            miscmagic.mmpSleepSmokeAwakenSpellCount() != 2) ++bad;
        if (miscmagic.mmpBroochPctWithoutGems() != 90 ||
            miscmagic.mmpBroochAbsorbHp() != 101) ++bad;
        if (miscmagic.mmpBroomAttackDumpMinFeet() != 6 ||
            miscmagic.mmpBroomAttackDumpMaxFeet() != 9 ||
            miscmagic.mmpBroomAttackAttacksPerRound() != 2 ||
            miscmagic.mmpBroomAttackAsHd() != 4 ||
            miscmagic.mmpBroomAttackStrawBlindRounds() != 1 ||
            miscmagic.mmpBroomAttackHandleDmgMin() != 1 ||
            miscmagic.mmpBroomAttackHandleDmgMax() != 3 ||
            miscmagic.mmpBroomAttackAc() != 7 ||
            miscmagic.mmpBroomAttackHpToDestroy() != 18) ++bad;
        if (miscmagic.mmpBroomFlySpeedInches() != 30 ||
            miscmagic.mmpBroomFlyCapacityPounds() != 182 ||
            miscmagic.mmpBroomFlyPoundsPerInch() != 14 ||
            miscmagic.mmpBroomFlyClimbDiveDegrees() != 30 ||
            miscmagic.mmpBroomFlyFetchSpeedInches() != 30) ++bad;
        if (miscmagic.mmpPurseCoinsPerType() != 26 ||
            miscmagic.mmpPurseTypeRowCount() != 3 ||
            miscmagic.mmpPurseGemsBaseGp() != 10 ||
            miscmagic.mmpPurseGemsMaxGp() != 100 ||
            miscmagic.mmpPurseAbilitiesNeverChange() != 1 ||
            miscmagic.mmpPurseSpiceNote() != 1) ++bad;
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
            if (miscmagic.mmpBracersDefBandLo(i) != kBracersDefLo[i] ||
                miscmagic.mmpBracersDefBandHi(i) != kBracersDefHi[i] ||
                miscmagic.mmpBracersDefAc(i) != kBracersDefAc[i]) ++bad;
        static const int kPurseLo[3] = {
            1, 51, 91,
        };
        static const int kPurseHi[3] = {
            50, 90, 100,
        };
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpPurseTypeBandLo(i) != kPurseLo[i] ||
                miscmagic.mmpPurseTypeBandHi(i) != kPurseHi[i]) ++bad;
        static const int kM1Lo[10] = {
            56, 59, 60, 80, 82, 85, 86, 93, 94, 99,
        };
        static const int kM1Hi[10] = {
            58, 59, 79, 81, 84, 85, 92, 93, 98, 100,
        };
        for (int i = 0; i < 10; ++i)
            if (miscmagic_table1_footnotes.m1RowLo(i + 23) != kM1Lo[i] ||
                miscmagic_table1_footnotes.m1RowHi(i + 23) != kM1Hi[i]) ++bad;
        // the (M) marks: the two Bowls and the two
        // Braziers; Bracers of Defense row 25 is
        // the negative control
        if (!miscmagic_table1_footnotes.m1UsableByMagicUser(23) ||
            !miscmagic_table1_footnotes.m1UsableByMagicUser(24) ||
            !miscmagic_table1_footnotes.m1UsableByMagicUser(27) ||
            !miscmagic_table1_footnotes.m1UsableByMagicUser(28) ||
            miscmagic_table1_footnotes.m1UsableByMagicUser(25)) ++bad;
        // the R225 per-AC asterisk fix: the flag
        // belongs on row 25 (60-79), the printed
        // asterisk row, not row 26
        if (!miscmagic_table1_footnotes.m1IsPerAcPointValued(25) ||
            miscmagic_table1_footnotes.m1IsPerAcPointValued(26) ||
            miscmagic_table1_footnotes.m1IsPerAcPointValued(24)) ++bad;
        if (!miscmagic_table1_footnotes.m1IsTieredPurseRow(32) ||
            miscmagic_table1_footnotes.m1IsTieredPurseRow(31)) ++bad;
        // the printed example: AC 6 (band row 2)
        // is 4 points above 10 = 2,000 xp /
        // 12,000 gp
        if (miscmagic.mmpBracersDefAc(2) != 6 ||
            miscmagic_table1_footnotes.m1BracersPerAcXp() *
                (10 - miscmagic.mmpBracersDefAc(2)) != 2000 ||
            miscmagic_table1_footnotes.m1BracersPerAcGp() *
                (10 - miscmagic.mmpBracersDefAc(2)) != 12000) ++bad;
        printf("R260 misc magic prose part 4 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
