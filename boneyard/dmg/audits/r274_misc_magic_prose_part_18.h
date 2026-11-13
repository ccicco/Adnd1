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
        int bad = 0;
        // the manual of stealthy pilfering
        if (rules::mmpStealthyPracticeMonths() != 1 ||
            rules::mmpStealthyKnowledgeMonths() != 3 ||
            rules::mmpStealthyAssassinXp() != 5000 ||
            rules::mmpStealthyAssassinWeeks() != 1 ||
            rules::mmpStealthyWrongDamageMin() != 5 ||
            rules::mmpStealthyWrongDamageMax() != 20 ||
            rules::mmpStealthyXpLossMin() != 5000 ||
            rules::mmpStealthyXpLossMax() != 20000 ||
            rules::mmpStealthyAtoneDays() != 1 ||
            rules::mmpStealthyWisdomLoss() != 1) ++bad;
        // the stun rounds are a like number of the
        // printed damage pair
        if (rules::mmpStealthyStunRoundsMin() !=
            rules::mmpStealthyWrongDamageMin() ||
            rules::mmpStealthyStunRoundsMax() !=
            rules::mmpStealthyWrongDamageMax()) ++bad;
        // the mattock of the titans
        if (rules::mmpMattockLengthFeet() != 10 ||
            rules::mmpMattockWeightLb() != 100 ||
            rules::mmpMattockMinStrength() != 20 ||
            rules::mmpMattockEarthCubicFeet() != 100 ||
            rules::mmpMattockRockCubicFeet() != 20 ||
            rules::mmpMattockAreaTurns() != 1 ||
            rules::mmpMattockHitBonus() != 3 ||
            rules::mmpMattockDamageMin() != 5 ||
            rules::mmpMattockDamageMax() != 30) ++bad;
        // the maul of the titans
        if (rules::mmpMaulLengthFeet() != 8 ||
            rules::mmpMaulWeightLb() != 150 ||
            rules::mmpMaulMinStrength() != 21 ||
            rules::mmpMaulPileDiameterFeet() != 2 ||
            rules::mmpMaulPileDepthFeet() != 4 ||
            rules::mmpMaulBlowsPerRound() != 2 ||
            rules::mmpMaulDoorHeightFeet() != 10 ||
            rules::mmpMaulDoorWidthFeet() != 4 ||
            rules::mmpMaulDoorThicknessInches() != 2 ||
            rules::mmpMaulDoorBlows() != 1 ||
            rules::mmpMaulDoorIronBlows() != 2 ||
            rules::mmpMaulHitBonus() != 2 ||
            rules::mmpMaulDamageMin() != 10 ||
            rules::mmpMaulDamageMax() != 40) ++bad;
        // the medallion of esp scalars
        if (rules::mmpEspPathWidthFeet() != 1 ||
            rules::mmpEspBroadenFeet() != 2 ||
            rules::mmpEspBroadenPerFeet() != 10 ||
            rules::mmpEspMaxWidthFeet() != 11 ||
            rules::mmpEspMaxWidthAtFeet() != 50 ||
            rules::mmpEspUseRounds() != 1 ||
            rules::mmpEspStoneBlockFeet() != 3 ||
            rules::mmpEspMetalBlockSixthsFeet() != 1 ||
            rules::mmpEspMalfunctionRoll() != 6 ||
            rules::mmpEspMalfunctionDieSides() != 6) ++bad;
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
            if (rules::mmpEspRowLo(i) != kElo[i] ||
                rules::mmpEspRowHi(i) != kEhi[i] ||
                rules::mmpEspRangeFeet(i) != kErg[i] ||
                rules::mmpEspEmpathy(i) != kEmp[i]) ++bad;
        // the medallion die bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (rules::mmpEspRowLo(i + 1) !=
                rules::mmpEspRowHi(i) + 1) ++bad;
        if (rules::mmpEspRowLo(0) != 1 ||
            rules::mmpEspRowHi(3) != 20) ++bad;
        // the medallion of thought projection
        if (rules::mmpProjectionWorksRoll() != 6) ++bad;
        // both printed medallion rolls are the 6 on d6
        if (rules::mmpProjectionWorksRoll() !=
            rules::mmpEspMalfunctionRoll()) ++bad;
        // the mirror of life trapping
        if (rules::mmpTrapAreaSquareFeet() != 4 ||
            rules::mmpTrapCellMin() != 13 ||
            rules::mmpTrapCellMax() != 18 ||
            rules::mmpTrapTriggerFeet() != 30 ||
            rules::mmpTrapSeePctUnaware() != 100 ||
            rules::mmpTrapSeePctAvoiding() != 50 ||
            rules::mmpTrapSeePctAware() != 20 ||
            rules::mmpTrapOverflowFreed() != 1) ++bad;
        // the 13-18 cell span is the 5 gap
        if (rules::mmpTrapCellMax() -
            rules::mmpTrapCellMin() != 5) ++bad;
        // the mirror of mental prowess
        if (rules::mmpProwessQuestionsPerWeek() != 1 ||
            rules::mmpProwessWidthFeet() != 5 ||
            rules::mmpProwessHeightFeet() != 2) ++bad;
        // the necklace of adaptation
        if (rules::mmpAdaptationAirlessDays() != 7) ++bad;
        // the necklace of missiles
        if (rules::mmpMissileRangeInches() != 7) ++bad;
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
            if (rules::mmpNeckRowLo(i) != kNlo[i] ||
                rules::mmpNeckRowHi(i) != kNhi[i]) ++bad;
        for (int i = 0; i < 10; ++i)
            if (rules::mmpNeckDieOf(i) != kHdc[i]) ++bad;
        for (int i = 0; i < 70; ++i)
            if (rules::mmpNeckCell(i) != kNcl[i]) ++bad;
        // the necklace die bands tile 1-20 without gaps
        for (int i = 0; i < 6; ++i)
            if (rules::mmpNeckRowLo(i + 1) !=
                rules::mmpNeckRowHi(i) + 1) ++bad;
        if (rules::mmpNeckRowLo(0) != 1 ||
            rules::mmpNeckRowHi(6) != 20) ++bad;
        // the hit dice columns descend by one
        for (int i = 0; i < 9; ++i)
            if (rules::mmpNeckDieOf(i + 1) !=
                rules::mmpNeckDieOf(i) - 1) ++bad;
        // the printed 9-12 example: one 7-dice, two
        // 5-dice and four 3-dice - seven missiles
        if (rules::mmpNeckCell(24) != 1 ||
            rules::mmpNeckCell(26) != 2 ||
            rules::mmpNeckCell(28) != 4) ++bad;
        // every row sums to its missile count
        static const int kTot[7] = {
            3, 5, 7, 9, 7, 9, 9,
        };
        for (int r = 0; r <= 6; ++r)
            if (rules::mmpNeckCell(r * 10) +
                rules::mmpNeckCell(r * 10 + 1) +
                rules::mmpNeckCell(r * 10 + 2) +
                rules::mmpNeckCell(r * 10 + 3) +
                rules::mmpNeckCell(r * 10 + 4) +
                rules::mmpNeckCell(r * 10 + 5) +
                rules::mmpNeckCell(r * 10 + 6) +
                rules::mmpNeckCell(r * 10 + 7) +
                rules::mmpNeckCell(r * 10 + 8) +
                rules::mmpNeckCell(r * 10 + 9) !=
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
            if (rules::m4RowLo(9 + i) != kRlo[i] ||
                rules::m4RowHi(9 + i) != kRhi[i]) ++bad;
        if (rules::m4StarCount(18) != 1 ||
            rules::m4IsDualValued(12) != 1 ||
            rules::m4UsableByThief(9) != 1 ||
            rules::m4UsableByFighter(10) != 1 ||
            rules::m4UsableByMagicUser(14) != 1 ||
            rules::m4RowCount() != 36) ++bad;
        for (int i = 9; i < 18; ++i)
            if (rules::m4StarCount(i) != 0 ||
                rules::m4UsableByCleric(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 12 && rules::m4IsDualValued(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 9 && rules::m4UsableByThief(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 10 && rules::m4UsableByFighter(i) != 0) ++bad;
        for (int i = 9; i < 19; ++i)
            if (i != 14 &&
                rules::m4UsableByMagicUser(i) != 0) ++bad;
        // the engine per-hit-die and dual-value pins
        if (rules::m4MissilePerHitDieXp() != 50 ||
            rules::m4MissilePerHitDieGp() != 200 ||
            rules::m4MedallionEspXpLow() != 1000 ||
            rules::m4MedallionEspXpHigh() != 3000 ||
            rules::m4MedallionEspGpLow() != 10000 ||
            rules::m4MedallionEspGpHigh() != 30000 ||
            rules::m4ThiefCount() != 3 ||
            rules::m4FighterCount() != 4 ||
            rules::m4MagicUserCount() != 6) ++bad;
        printf("R274 misc magic prose part 18 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
