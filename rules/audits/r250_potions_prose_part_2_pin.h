    // ---- R250: the III.A potions explanation prose part 2 pins audit ----
    // DMG pp.134-136: Fire Resistance
    // through Invisibility - potions part 2.
    {
        Potions potions;
        Potions_fire_resistance_to_invisibility potions_fire_resistance_to_invisibility;
        int bad = 0;
        // the ten potions are the engine III.A
        // table rows 10-19 - bands 27-54,
        // invulnerability from 55 (the R221
        // pins)
        if (potions.potionRowLo(9) != 27 ||
            potions.potionRowHi(18) != 54 ||
            potions.potionRowLo(19) != 55) ++bad;
        // the engine rows 10-19 checked band
        // by band against the R221 pins
        static const int kRowLo[10] = {
            27, 30, 33, 35, 37, 40, 42, 48, 50, 52,
        };
        static const int kRowHi[10] = {
            29, 32, 34, 36, 39, 41, 47, 49, 51, 54,
        };
        for (int i = 0; i < 10; ++i)
            if (potions.potionRowLo(i + 9) != kRowLo[i] ||
                potions.potionRowHi(i + 9) != kRowHi[i]) ++bad;
        // Fire Resistance - the reduction,
        // the save, and the durations
        if (potions_fire_resistance_to_invisibility.potFireDieReduction() != -2 ||
            potions_fire_resistance_to_invisibility.potFireSaveMod() != 4 ||
            potions_fire_resistance_to_invisibility.potFireHalfDieReduction() != -1 ||
            potions_fire_resistance_to_invisibility.potFireHalfSaveMod() != 2 ||
            potions_fire_resistance_to_invisibility.potFireTurns() != 1 ||
            potions_fire_resistance_to_invisibility.potFireHalfRounds() != 5) ++bad;
        // Flying - the fly spell level
        if (potions_fire_resistance_to_invisibility.potFlySpellLevel() != 3) ++bad;
        // Gaseous Form - the speed and the
        // whirlwind
        if (potions_fire_resistance_to_invisibility.potGasSpeedInches() != 3 ||
            potions_fire_resistance_to_invisibility.potGasWhirlwindMult() != 2) ++bad;
        // Giant Control - the count, the
        // saves, and the rounds
        if (potions_fire_resistance_to_invisibility.potGiantControlLo() != 1 ||
            potions_fire_resistance_to_invisibility.potGiantControlHi() != 2 ||
            potions_fire_resistance_to_invisibility.potGiantOneSaveMod() != -4 ||
            potions_fire_resistance_to_invisibility.potGiantTwoSaveMod() != 2 ||
            potions_fire_resistance_to_invisibility.potGiantRoundLo() != 5 ||
            potions_fire_resistance_to_invisibility.potGiantRoundHi() != 30 ||
            potions_fire_resistance_to_invisibility.potGiantRoundDice() != 5 ||
            potions_fire_resistance_to_invisibility.potGiantRoundFaces() != 6) ++bad;
        // the giant type sub-table: 6 rows on d20
        if (potions_fire_resistance_to_invisibility.potGiantTypeRowCount() != 6 ||
            potions_fire_resistance_to_invisibility.potGiantTypeFaces() != 20) ++bad;
        static const int kGLo[6] = {
            1, 6, 10, 14, 18, 20,
        };
        static const int kGHi[6] = {
            5, 9, 13, 17, 19, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (potions_fire_resistance_to_invisibility.potGiantTypeLo(i) != kGLo[i] ||
                potions_fire_resistance_to_invisibility.potGiantTypeHi(i) != kGHi[i]) ++bad;
        for (int i = 1; i < 6; ++i)
            if (potions_fire_resistance_to_invisibility.potGiantTypeLo(i) !=
                potions_fire_resistance_to_invisibility.potGiantTypeHi(i - 1) + 1) ++bad;
        if (potions_fire_resistance_to_invisibility.potGiantTypeLo(-5) != 1 ||
            potions_fire_resistance_to_invisibility.potGiantTypeHi(99) != 20) ++bad;
        // Giant Strength - the 6-row die table
        if (potions_fire_resistance_to_invisibility.potGStrRowCount() != 6) ++bad;
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
            if (potions_fire_resistance_to_invisibility.potGStrTypeLo(i) != kSLo[i] ||
                potions_fire_resistance_to_invisibility.potGStrTypeHi(i) != kSHi[i] ||
                potions_fire_resistance_to_invisibility.potGStrWeightGp(i) != kSWt[i] ||
                potions_fire_resistance_to_invisibility.potGStrDmgBonus(i) != kSBon[i] ||
                potions_fire_resistance_to_invisibility.potGStrRockRangeInches(i) != kSRng[i] ||
                potions_fire_resistance_to_invisibility.potGStrRockDmgLo(i) != kSRkLo[i] ||
                potions_fire_resistance_to_invisibility.potGStrRockDmgHi(i) != kSRkHi[i] ||
                potions_fire_resistance_to_invisibility.potGStrBendBarsPercent(i) != kSBend[i]) ++bad;
        for (int i = 1; i < 6; ++i)
            if (potions_fire_resistance_to_invisibility.potGStrTypeLo(i) !=
                potions_fire_resistance_to_invisibility.potGStrTypeHi(i - 1) + 1) ++bad;
        if (potions_fire_resistance_to_invisibility.potGStrTypeLo(-5) != 1 ||
            potions_fire_resistance_to_invisibility.potGStrTypeHi(99) != 20) ++bad;
        // Growth - the quarter and the full potion
        if (potions_fire_resistance_to_invisibility.potGrowthQuarterFeet() != 6 ||
            potions_fire_resistance_to_invisibility.potGrowthFullFeet() != 24) ++bad;
        // Healing - the restored hit points
        if (potions_fire_resistance_to_invisibility.potHealLo() != 4 ||
            potions_fire_resistance_to_invisibility.potHealHi() != 10 ||
            potions_fire_resistance_to_invisibility.potHealDice() != 2 ||
            potions_fire_resistance_to_invisibility.potHealFaces() != 4 ||
            potions_fire_resistance_to_invisibility.potHealBonus() != 2) ++bad;
        // Heroism - the level ceiling and the table
        if (potions_fire_resistance_to_invisibility.potHeroMaxLevels() != 10 ||
            potions_fire_resistance_to_invisibility.potHeroRowCount() != 3 ||
            potions_fire_resistance_to_invisibility.potHeroDmgFaces() != 10) ++bad;
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
            if (potions_fire_resistance_to_invisibility.potHeroLevels(i) != kHLvl[i] ||
                potions_fire_resistance_to_invisibility.potHeroDmgDice(i) != kHDice[i] ||
                potions_fire_resistance_to_invisibility.potHeroDmgBonus(i) != kHBon[i]) ++bad;
        // Human Control - the levels, the table,
        // and the duration
        if (potions_fire_resistance_to_invisibility.potHumanLevelsTotal() != 32 ||
            potions_fire_resistance_to_invisibility.potHumanTypeRowCount() != 8 ||
            potions_fire_resistance_to_invisibility.potHumanTypeFaces() != 20 ||
            potions_fire_resistance_to_invisibility.potHumanRoundLo() != 5 ||
            potions_fire_resistance_to_invisibility.potHumanRoundHi() != 30) ++bad;
        static const int kHLo[8] = {
            1, 3, 5, 7, 9, 11, 17, 20,
        };
        static const int kHHi[8] = {
            2, 4, 6, 8, 10, 16, 19, 20,
        };
        for (int i = 0; i < 8; ++i)
            if (potions_fire_resistance_to_invisibility.potHumanTypeLo(i) != kHLo[i] ||
                potions_fire_resistance_to_invisibility.potHumanTypeHi(i) != kHHi[i]) ++bad;
        for (int i = 1; i < 8; ++i)
            if (potions_fire_resistance_to_invisibility.potHumanTypeLo(i) !=
                potions_fire_resistance_to_invisibility.potHumanTypeHi(i - 1) + 1) ++bad;
        if (potions_fire_resistance_to_invisibility.potHumanTypeLo(-5) != 1 ||
            potions_fire_resistance_to_invisibility.potHumanTypeHi(99) != 20) ++bad;
        // Invisibility - the gulp and the turns
        if (potions_fire_resistance_to_invisibility.potInvisGulpFraction() != 8 ||
            potions_fire_resistance_to_invisibility.potInvisTurnsLo() != 3 ||
            potions_fire_resistance_to_invisibility.potInvisTurnsHi() != 6) ++bad;
        printf("R250 potions prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
