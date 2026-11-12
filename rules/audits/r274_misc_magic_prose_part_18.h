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
        Miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles miscmagic;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the manual of stealthy pilfering
        if (miscmagic.mmpStealthyPracticeMonths() != 1 ||
            miscmagic.mmpStealthyKnowledgeMonths() != 3 ||
            miscmagic.mmpStealthyAssassinXp() != 5000 ||
            miscmagic.mmpStealthyAssassinWeeks() != 1 ||
            miscmagic.mmpStealthyWrongDamageMin() != 5 ||
            miscmagic.mmpStealthyWrongDamageMax() != 20 ||
            miscmagic.mmpStealthyXpLossMin() != 5000 ||
            miscmagic.mmpStealthyXpLossMax() != 20000 ||
            miscmagic.mmpStealthyAtoneDays() != 1 ||
            miscmagic.mmpStealthyWisdomLoss() != 1) ++bad;
        // the stun rounds are a like number of the
        // printed damage pair
        if (miscmagic.mmpStealthyStunRoundsMin() !=
            miscmagic.mmpStealthyWrongDamageMin() ||
            miscmagic.mmpStealthyStunRoundsMax() !=
            miscmagic.mmpStealthyWrongDamageMax()) ++bad;
        // the mattock of the titans
        if (miscmagic.mmpMattockLengthFeet() != 10 ||
            miscmagic.mmpMattockWeightLb() != 100 ||
            miscmagic.mmpMattockMinStrength() != 20 ||
            miscmagic.mmpMattockEarthCubicFeet() != 100 ||
            miscmagic.mmpMattockRockCubicFeet() != 20 ||
            miscmagic.mmpMattockAreaTurns() != 1 ||
            miscmagic.mmpMattockHitBonus() != 3 ||
            miscmagic.mmpMattockDamageMin() != 5 ||
            miscmagic.mmpMattockDamageMax() != 30) ++bad;
        // the maul of the titans
        if (miscmagic.mmpMaulLengthFeet() != 8 ||
            miscmagic.mmpMaulWeightLb() != 150 ||
            miscmagic.mmpMaulMinStrength() != 21 ||
            miscmagic.mmpMaulPileDiameterFeet() != 2 ||
            miscmagic.mmpMaulPileDepthFeet() != 4 ||
            miscmagic.mmpMaulBlowsPerRound() != 2 ||
            miscmagic.mmpMaulDoorHeightFeet() != 10 ||
            miscmagic.mmpMaulDoorWidthFeet() != 4 ||
            miscmagic.mmpMaulDoorThicknessInches() != 2 ||
            miscmagic.mmpMaulDoorBlows() != 1 ||
            miscmagic.mmpMaulDoorIronBlows() != 2 ||
            miscmagic.mmpMaulHitBonus() != 2 ||
            miscmagic.mmpMaulDamageMin() != 10 ||
            miscmagic.mmpMaulDamageMax() != 40) ++bad;
        // the medallion of esp scalars
        if (miscmagic.mmpEspPathWidthFeet() != 1 ||
            miscmagic.mmpEspBroadenFeet() != 2 ||
            miscmagic.mmpEspBroadenPerFeet() != 10 ||
            miscmagic.mmpEspMaxWidthFeet() != 11 ||
            miscmagic.mmpEspMaxWidthAtFeet() != 50 ||
            miscmagic.mmpEspUseRounds() != 1 ||
            miscmagic.mmpEspStoneBlockFeet() != 3 ||
            miscmagic.mmpEspMetalBlockSixthsFeet() != 1 ||
            miscmagic.mmpEspMalfunctionRoll() != 6 ||
            miscmagic.mmpEspMalfunctionDieSides() != 6) ++bad;
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
            if (miscmagic.mmpEspRowLo(i) != kElo[i] ||
                miscmagic.mmpEspRowHi(i) != kEhi[i] ||
                miscmagic.mmpEspRangeFeet(i) != kErg[i] ||
                miscmagic.mmpEspEmpathy(i) != kEmp[i]) ++bad;
        // the medallion die bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpEspRowLo(i + 1) !=
                miscmagic.mmpEspRowHi(i) + 1) ++bad;
        if (miscmagic.mmpEspRowLo(0) != 1 ||
            miscmagic.mmpEspRowHi(3) != 20) ++bad;
        // the medallion of thought projection
        if (miscmagic.mmpProjectionWorksRoll() != 6) ++bad;
        // both printed medallion rolls are the 6 on d6
        if (miscmagic.mmpProjectionWorksRoll() !=
            miscmagic.mmpEspMalfunctionRoll()) ++bad;
        // the mirror of life trapping
        if (miscmagic.mmpTrapAreaSquareFeet() != 4 ||
            miscmagic.mmpTrapCellMin() != 13 ||
            miscmagic.mmpTrapCellMax() != 18 ||
            miscmagic.mmpTrapTriggerFeet() != 30 ||
            miscmagic.mmpTrapSeePctUnaware() != 100 ||
            miscmagic.mmpTrapSeePctAvoiding() != 50 ||
            miscmagic.mmpTrapSeePctAware() != 20 ||
            miscmagic.mmpTrapOverflowFreed() != 1) ++bad;
        // the 13-18 cell span is the 5 gap
        if (miscmagic.mmpTrapCellMax() -
            miscmagic.mmpTrapCellMin() != 5) ++bad;
        // the mirror of mental prowess
        if (miscmagic.mmpProwessQuestionsPerWeek() != 1 ||
            miscmagic.mmpProwessWidthFeet() != 5 ||
            miscmagic.mmpProwessHeightFeet() != 2) ++bad;
        // the necklace of adaptation
        if (miscmagic.mmpAdaptationAirlessDays() != 7) ++bad;
        // the necklace of missiles
        if (miscmagic.mmpMissileRangeInches() != 7) ++bad;
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
            if (miscmagic.mmpNeckRowLo(i) != kNlo[i] ||
                miscmagic.mmpNeckRowHi(i) != kNhi[i]) ++bad;
        for (int i = 0; i < 10; ++i)
            if (miscmagic.mmpNeckDieOf(i) != kHdc[i]) ++bad;
        for (int i = 0; i < 70; ++i)
            if (miscmagic.mmpNeckCell(i) != kNcl[i]) ++bad;
        // the necklace die bands tile 1-20 without gaps
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpNeckRowLo(i + 1) !=
                miscmagic.mmpNeckRowHi(i) + 1) ++bad;
        if (miscmagic.mmpNeckRowLo(0) != 1 ||
            miscmagic.mmpNeckRowHi(6) != 20) ++bad;
        // the hit dice columns descend by one
        for (int i = 0; i < 9; ++i)
            if (miscmagic.mmpNeckDieOf(i + 1) !=
                miscmagic.mmpNeckDieOf(i) - 1) ++bad;
        // the printed 9-12 example: one 7-dice, two
        // 5-dice and four 3-dice - seven missiles
        if (miscmagic.mmpNeckCell(24) != 1 ||
            miscmagic.mmpNeckCell(26) != 2 ||
            miscmagic.mmpNeckCell(28) != 4) ++bad;
        // every row sums to its missile count
        static const int kTot[7] = {
            3, 5, 7, 9, 7, 9, 9,
        };
        for (int r = 0; r <= 6; ++r)
            if (miscmagic.mmpNeckCell(r * 10) +
                miscmagic.mmpNeckCell(r * 10 + 1) +
                miscmagic.mmpNeckCell(r * 10 + 2) +
                miscmagic.mmpNeckCell(r * 10 + 3) +
                miscmagic.mmpNeckCell(r * 10 + 4) +
                miscmagic.mmpNeckCell(r * 10 + 5) +
                miscmagic.mmpNeckCell(r * 10 + 6) +
                miscmagic.mmpNeckCell(r * 10 + 7) +
                miscmagic.mmpNeckCell(r * 10 + 8) +
                miscmagic.mmpNeckCell(r * 10 + 9) !=
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
