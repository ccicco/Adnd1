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
        Miscmagic_bowl_commanding_water_elementals_to_bucknards_purse miscmagic_bowl_commanding_water_elementals_to_bucknards_purse;
        Miscmagic_table1_footnotes miscmagic_table1_footnotes;
        int bad = 0;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBowlCmdHd() != 12 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBowlCmdWordsRounds() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBowlCmdSaltBonusPerDie() != 2 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBowlCmdSaltMaxHpPerDie() != 8 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBowlCmdDiameterInches() != 12 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBowlCmdDepthInches() != 6) ++bad;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpWateryDeathSaltSavePenalty() != 2 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpWateryDeathDrownMinRounds() != 3 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpWateryDeathDrownMaxRounds() != 8 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpWateryDeathFreeSpellCount() != 3 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpWateryDeathDeathPermanent() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpWateryDeathSweetWaterAnotherSave() != 1) ++bad;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefRowCount() != 7 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefAcMin() != 2 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefAcMax() != 8 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpDefenselessAc() != 10 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpDefenselessNegatesProtections() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpDefenselessRemoveCurseOnly() != 1) ++bad;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBrazierFireHd() != 12 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBrazierFireLightRounds() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBrazierFireSulphurBonusPerDie() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBrazierFireSulphurHpMin() != 2 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBrazierFireSulphurHpMax() != 9 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpSleepSmokeRadiusInches() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpSleepSmokeHd() != 12 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpSleepSmokeAwakenSpellCount() != 2) ++bad;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroochPctWithoutGems() != 90 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroochAbsorbHp() != 101) ++bad;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackDumpMinFeet() != 6 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackDumpMaxFeet() != 9 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackAttacksPerRound() != 2 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackAsHd() != 4 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackStrawBlindRounds() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackHandleDmgMin() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackHandleDmgMax() != 3 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackAc() != 7 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomAttackHpToDestroy() != 18) ++bad;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomFlySpeedInches() != 30 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomFlyCapacityPounds() != 182 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomFlyPoundsPerInch() != 14 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomFlyClimbDiveDegrees() != 30 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBroomFlyFetchSpeedInches() != 30) ++bad;
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseCoinsPerType() != 26 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseTypeRowCount() != 3 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseGemsBaseGp() != 10 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseGemsMaxGp() != 100 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseAbilitiesNeverChange() != 1 ||
            miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseSpiceNote() != 1) ++bad;
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
            if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefBandLo(i) != kBracersDefLo[i] ||
                miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefBandHi(i) != kBracersDefHi[i] ||
                miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefAc(i) != kBracersDefAc[i]) ++bad;
        static const int kPurseLo[3] = {
            1, 51, 91,
        };
        static const int kPurseHi[3] = {
            50, 90, 100,
        };
        for (int i = 0; i < 3; ++i)
            if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseTypeBandLo(i) != kPurseLo[i] ||
                miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpPurseTypeBandHi(i) != kPurseHi[i]) ++bad;
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
        if (miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefAc(2) != 6 ||
            miscmagic_table1_footnotes.m1BracersPerAcXp() *
                (10 - miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefAc(2)) != 2000 ||
            miscmagic_table1_footnotes.m1BracersPerAcGp() *
                (10 - miscmagic_bowl_commanding_water_elementals_to_bucknards_purse.mmpBracersDefAc(2)) != 12000) ++bad;
        printf("R260 misc magic prose part 4 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
