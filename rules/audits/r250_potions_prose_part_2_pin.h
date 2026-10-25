    // ---- R250: the III.A potions explanation prose part 2 pins audit ----
    // DMG pp.134-136: Fire Resistance
    // through Invisibility - potions part 2.
    {
        int bad = 0;
        // the ten potions are the engine III.A
        // table rows 10-19 - bands 27-54,
        // invulnerability from 55 (the R221
        // pins)
        if (rules::potionRowLo(9) != 27 ||
            rules::potionRowHi(18) != 54 ||
            rules::potionRowLo(19) != 55) ++bad;
        // the engine rows 10-19 checked band
        // by band against the R221 pins
        static const int kRowLo[10] = {
            27, 30, 33, 35, 37, 40, 42, 48, 50, 52,
        };
        static const int kRowHi[10] = {
            29, 32, 34, 36, 39, 41, 47, 49, 51, 54,
        };
        for (int i = 0; i < 10; ++i)
            if (rules::potionRowLo(i + 9) != kRowLo[i] ||
                rules::potionRowHi(i + 9) != kRowHi[i]) ++bad;
        // Fire Resistance - the reduction,
        // the save, and the durations
        if (rules::potFireDieReduction() != -2 ||
            rules::potFireSaveMod() != 4 ||
            rules::potFireHalfDieReduction() != -1 ||
            rules::potFireHalfSaveMod() != 2 ||
            rules::potFireTurns() != 1 ||
            rules::potFireHalfRounds() != 5) ++bad;
        // Flying - the fly spell level
        if (rules::potFlySpellLevel() != 3) ++bad;
        // Gaseous Form - the speed and the
        // whirlwind
        if (rules::potGasSpeedInches() != 3 ||
            rules::potGasWhirlwindMult() != 2) ++bad;
        // Giant Control - the count, the
        // saves, and the rounds
        if (rules::potGiantControlLo() != 1 ||
            rules::potGiantControlHi() != 2 ||
            rules::potGiantOneSaveMod() != -4 ||
            rules::potGiantTwoSaveMod() != 2 ||
            rules::potGiantRoundLo() != 5 ||
            rules::potGiantRoundHi() != 30 ||
            rules::potGiantRoundDice() != 5 ||
            rules::potGiantRoundFaces() != 6) ++bad;
        // the giant type sub-table: 6 rows on d20
        if (rules::potGiantTypeRowCount() != 6 ||
            rules::potGiantTypeFaces() != 20) ++bad;
        static const int kGLo[6] = {
            1, 6, 10, 14, 18, 20,
        };
        static const int kGHi[6] = {
            5, 9, 13, 17, 19, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::potGiantTypeLo(i) != kGLo[i] ||
                rules::potGiantTypeHi(i) != kGHi[i]) ++bad;
        for (int i = 1; i < 6; ++i)
            if (rules::potGiantTypeLo(i) !=
                rules::potGiantTypeHi(i - 1) + 1) ++bad;
        if (rules::potGiantTypeLo(-5) != 1 ||
            rules::potGiantTypeHi(99) != 20) ++bad;
        // Giant Strength - the 6-row die table
        if (rules::potGStrRowCount() != 6) ++bad;
        static const int kSLo[6] = {
            1, 7, 11, 15, 18, 20,
        };
        static const int kSHi[6] = {
            6, 10, 14, 17, 19, 20,
        };
        static const int kSWt[6] = {
            4500, 5000, 6000, 7500, 9000, 12000,
        };
        static const int kSBon[6] = {
            7, 8, 9, 10, 11, 12,
        };
        static const int kSRng[6] = {
            8, 16, 10, 12, 14, 16,
        };
        static const int kSRkLo[6] = {
            1, 1, 1, 1, 1, 1,
        };
        static const int kSRkHi[6] = {
            6, 12, 8, 8, 10, 12,
        };
        static const int kSBend[6] = {
            50, 60, 70, 80, 90, 100,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::potGStrTypeLo(i) != kSLo[i] ||
                rules::potGStrTypeHi(i) != kSHi[i] ||
                rules::potGStrWeightGp(i) != kSWt[i] ||
                rules::potGStrDmgBonus(i) != kSBon[i] ||
                rules::potGStrRockRangeInches(i) != kSRng[i] ||
                rules::potGStrRockDmgLo(i) != kSRkLo[i] ||
                rules::potGStrRockDmgHi(i) != kSRkHi[i] ||
                rules::potGStrBendBarsPercent(i) != kSBend[i]) ++bad;
        for (int i = 1; i < 6; ++i)
            if (rules::potGStrTypeLo(i) !=
                rules::potGStrTypeHi(i - 1) + 1) ++bad;
        if (rules::potGStrTypeLo(-5) != 1 ||
            rules::potGStrTypeHi(99) != 20) ++bad;
        // Growth - the quarter and the full potion
        if (rules::potGrowthQuarterFeet() != 6 ||
            rules::potGrowthFullFeet() != 24) ++bad;
        // Healing - the restored hit points
        if (rules::potHealLo() != 4 ||
            rules::potHealHi() != 10 ||
            rules::potHealDice() != 2 ||
            rules::potHealFaces() != 4 ||
            rules::potHealBonus() != 2) ++bad;
        // Heroism - the level ceiling and the table
        if (rules::potHeroMaxLevels() != 10 ||
            rules::potHeroRowCount() != 3 ||
            rules::potHeroDmgFaces() != 10) ++bad;
        static const int kHLvl[3] = {
            3, 2, 1,
        };
        static const int kHDice[3] = {
            3, 2, 1,
        };
        static const int kHBon[3] = {
            1, 2, 3,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::potHeroLevels(i) != kHLvl[i] ||
                rules::potHeroDmgDice(i) != kHDice[i] ||
                rules::potHeroDmgBonus(i) != kHBon[i]) ++bad;
        // Human Control - the levels, the table,
        // and the duration
        if (rules::potHumanLevelsTotal() != 32 ||
            rules::potHumanTypeRowCount() != 8 ||
            rules::potHumanTypeFaces() != 20 ||
            rules::potHumanRoundLo() != 5 ||
            rules::potHumanRoundHi() != 30) ++bad;
        static const int kHLo[8] = {
            1, 3, 5, 7, 9, 11, 17, 20,
        };
        static const int kHHi[8] = {
            2, 4, 6, 8, 10, 16, 19, 20,
        };
        for (int i = 0; i < 8; ++i)
            if (rules::potHumanTypeLo(i) != kHLo[i] ||
                rules::potHumanTypeHi(i) != kHHi[i]) ++bad;
        for (int i = 1; i < 8; ++i)
            if (rules::potHumanTypeLo(i) !=
                rules::potHumanTypeHi(i - 1) + 1) ++bad;
        if (rules::potHumanTypeLo(-5) != 1 ||
            rules::potHumanTypeHi(99) != 20) ++bad;
        // Invisibility - the gulp and the turns
        if (rules::potInvisGulpFraction() != 8 ||
            rules::potInvisTurnsLo() != 3 ||
            rules::potInvisTurnsHi() != 6) ++bad;
        printf("R250 potions prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
