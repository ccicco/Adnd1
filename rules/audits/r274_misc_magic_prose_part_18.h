    // ---- R274: the III.E misc magic explanation
    // prose part 18 ----
    // The Manual of Stealthy Pilfering, the Mattock
    // and Maul of the Titans, the Medallions of ESP
    // and Thought Projection, the Mirrors of Life
    // Trapping, Mental Prowess and Opposition and
    // the Necklaces of Adaptation and Missiles,
    // part2 lines 843-900 - the slice pinning the
    // kMisc4 rows 9-18 of the 36-row III.E.4 table.
    {
        Miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the manual of stealthy pilfering
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyPracticeMonths() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyKnowledgeMonths() != 3 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyAssassinXp() != 5000 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyAssassinWeeks() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyWrongDamageMin() != 5 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyWrongDamageMax() != 20 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyXpLossMin() != 5000 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyXpLossMax() != 20000 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyAtoneDays() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyWisdomLoss() != 1) ++bad;
        // the stun rounds are a like number of the
        // printed damage pair
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyStunRoundsMin() !=
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyWrongDamageMin() ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyStunRoundsMax() !=
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpStealthyWrongDamageMax()) ++bad;
        // the mattock of the titans
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockLengthFeet() != 10 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockWeightLb() != 100 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockMinStrength() != 20 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockEarthCubicFeet() != 100 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockRockCubicFeet() != 20 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockAreaTurns() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockHitBonus() != 3 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockDamageMin() != 5 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMattockDamageMax() != 30) ++bad;
        // the maul of the titans
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulLengthFeet() != 8 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulWeightLb() != 150 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulMinStrength() != 21 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulPileDiameterFeet() != 2 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulPileDepthFeet() != 4 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulBlowsPerRound() != 2 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulDoorHeightFeet() != 10 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulDoorWidthFeet() != 4 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulDoorThicknessInches() != 2 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulDoorBlows() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulDoorIronBlows() != 2 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulHitBonus() != 2 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulDamageMin() != 10 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMaulDamageMax() != 40) ++bad;
        // the medallion of esp scalars
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspPathWidthFeet() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspBroadenFeet() != 2 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspBroadenPerFeet() != 10 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspMaxWidthFeet() != 11 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspMaxWidthAtFeet() != 50 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspUseRounds() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspStoneBlockFeet() != 3 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspMetalBlockSixthsFeet() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspMalfunctionRoll() != 6 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspMalfunctionDieSides() != 6) ++bad;
        // the medallion type table against static twins
        static const int kElo[4] = {
            1, 16, 19, 20,
        };
        static const int kEhi[4] = {
            15, 18, 19, 20,
        };
        static const int kErg[4] = {
            30, 30, 60, 90,
        };
        static const int kEmp[4] = {
            0, 1, 0, 0,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspRowLo(i) != kElo[i] ||
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspRowHi(i) != kEhi[i] ||
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspRangeFeet(i) != kErg[i] ||
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspEmpathy(i) != kEmp[i]) ++bad;
        // the medallion die bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspRowLo(i + 1) !=
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspRowHi(i) + 1) ++bad;
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspRowLo(0) != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspRowHi(3) != 20) ++bad;
        // the medallion of thought projection
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpProjectionWorksRoll() != 6) ++bad;
        // both printed medallion rolls are the 6 on d6
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpProjectionWorksRoll() !=
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpEspMalfunctionRoll()) ++bad;
        // the mirror of life trapping
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapAreaSquareFeet() != 4 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapCellMin() != 13 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapCellMax() != 18 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapTriggerFeet() != 30 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapSeePctUnaware() != 100 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapSeePctAvoiding() != 50 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapSeePctAware() != 20 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapOverflowFreed() != 1) ++bad;
        // the 13-18 cell span is the 5 gap
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapCellMax() -
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpTrapCellMin() != 5) ++bad;
        // the mirror of mental prowess
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpProwessQuestionsPerWeek() != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpProwessWidthFeet() != 5 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpProwessHeightFeet() != 2) ++bad;
        // the necklace of adaptation
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpAdaptationAirlessDays() != 7) ++bad;
        // the necklace of missiles
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpMissileRangeInches() != 7) ++bad;
        static const int kNlo[7] = {
            1, 5, 9, 13, 17, 19, 20,
        };
        static const int kNhi[7] = {
            4, 8, 12, 16, 18, 19, 20,
        };
        static const int kHdc[10] = {
            11, 10, 9, 8, 7, 6, 5, 4, 3, 2,
        };
        static const int kNcl[70] = {
            0, 0, 0, 0, 0, 0, 1, 0, 2, 0,
            0, 0, 0, 0, 0, 1, 0, 2, 0, 2,
            0, 0, 0, 0, 1, 0, 2, 0, 4, 0,
            0, 0, 0, 1, 0, 2, 0, 2, 0, 4,
            0, 0, 1, 0, 2, 0, 2, 0, 2, 0,
            0, 1, 0, 2, 0, 2, 0, 4, 0, 0,
            1, 0, 2, 0, 2, 0, 2, 0, 2, 0,
        };
        for (int i = 0; i < 7; ++i)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckRowLo(i) != kNlo[i] ||
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckRowHi(i) != kNhi[i]) ++bad;
        for (int i = 0; i < 10; ++i)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckDieOf(i) != kHdc[i]) ++bad;
        for (int i = 0; i < 70; ++i)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(i) != kNcl[i]) ++bad;
        // the necklace die bands tile 1-20 without gaps
        for (int i = 0; i < 6; ++i)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckRowLo(i + 1) !=
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckRowHi(i) + 1) ++bad;
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckRowLo(0) != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckRowHi(6) != 20) ++bad;
        // the hit dice columns descend by one
        for (int i = 0; i < 9; ++i)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckDieOf(i + 1) !=
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckDieOf(i) - 1) ++bad;
        // the printed 9-12 example: one 7-dice, two
        // 5-dice and four 3-dice - seven missiles
        if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(24) != 1 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(26) != 2 ||
            miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(28) != 4) ++bad;
        // every row sums to its missile count
        static const int kTot[7] = {
            3, 5, 7, 9, 7, 9, 9,
        };
        for (int r = 0; r <= 6; ++r)
            if (miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 1) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 2) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 3) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 4) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 5) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 6) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 7) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 8) +
                miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles.mmpNeckCell(r * 10 + 9) !=
                kTot[r]) ++bad;
        // the engine kMisc4 rows 9-18: the die band
        // edges, the (T), (F) and (M) marks, the single
        // star on the necklace of missiles and the one
        // dual row on the medallion of esp
        static const int kRlo[10] = {
            10, 11, 12, 13, 16, 18, 19, 20, 21, 24,
        };
        static const int kRhi[10] = {
            10, 11, 12, 15, 17, 18, 19, 20, 23, 27,
        };
        for (int i = 0; i < 10; ++i)
            if (miscmagic_table4_footnotes.m4RowLo(9 + i) != kRlo[i] ||
                miscmagic_table4_footnotes.m4RowHi(9 + i) != kRhi[i]) ++bad;
        if (miscmagic_table4_footnotes.m4StarCount(18) != 1 ||
            miscmagic_table4_footnotes.m4IsDualValued(12) != 1 ||
            miscmagic_table4_footnotes.m4UsableByThief(9) != 1 ||
            miscmagic_table4_footnotes.m4UsableByFighter(10) != 1 ||
            miscmagic_table4_footnotes.m4UsableByMagicUser(14) != 1 ||
            miscmagic_table4_footnotes.m4RowCount() != 36) ++bad;
        for (int i = 9; i < 18; ++i)
            if (miscmagic_table4_footnotes.m4StarCount(i) != 0 ||
                miscmagic_table4_footnotes.m4UsableByCleric(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 12 && miscmagic_table4_footnotes.m4IsDualValued(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 9 && miscmagic_table4_footnotes.m4UsableByThief(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 10 && miscmagic_table4_footnotes.m4UsableByFighter(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 14 &&
                miscmagic_table4_footnotes.m4UsableByMagicUser(i) != 0) ++bad;
        // the engine per-hit-die and dual-value pins
        if (miscmagic_table4_footnotes.m4MissilePerHitDieXp() != 50 ||
            miscmagic_table4_footnotes.m4MissilePerHitDieGp() != 200 ||
            miscmagic_table4_footnotes.m4MedallionEspXpLow() != 1000 ||
            miscmagic_table4_footnotes.m4MedallionEspXpHigh() != 3000 ||
            miscmagic_table4_footnotes.m4MedallionEspGpLow() != 10000 ||
            miscmagic_table4_footnotes.m4MedallionEspGpHigh() != 30000 ||
            miscmagic_table4_footnotes.m4ThiefCount() != 3 ||
            miscmagic_table4_footnotes.m4FighterCount() != 4 ||
            miscmagic_table4_footnotes.m4MagicUserCount() != 6) ++bad;
        printf("R274 misc magic prose part 18 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
