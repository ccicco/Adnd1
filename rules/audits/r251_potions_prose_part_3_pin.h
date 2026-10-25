    // ---- R251: the III.A potions explanation prose part 3 pins audit ----
    // DMG pp.136-137: Invulnerability
    // through Water Breathing - the potions
    // arc closes.
    {
        int bad = 0;
        // the sixteen potions are the engine III.A
        // table rows 20-35 - bands 55-100, the
        // table closing at 100 (the R221 pins)
        if (rules::potionRowCount() != 35 ||
            rules::potionRowLo(19) != 55 ||
            rules::potionRowHi(34) != 100) ++bad;
        // the engine rows 20-35 checked band
        // by band against the R221 pins
        static const int kRowLo[16] = {
            55, 58, 61, 64, 67, 70, 73, 76, 79, 82,
            85, 88, 91, 94, 97, 98,
        };
        static const int kRowHi[16] = {
            57, 60, 63, 66, 69, 72, 75, 78, 81, 84,
            87, 90, 93, 96, 97, 100,
        };
        for (int i = 0; i < 16; ++i)
            if (rules::potionRowLo(i + 19) != kRowLo[i] ||
                rules::potionRowHi(i + 19) != kRowHi[i]) ++bad;
        // Invulnerability - the hit dice, the
        // armor class, the save, and the rounds
        if (rules::potInvulnMinHitDice() != 4 ||
            rules::potInvulnAcClasses() != 2 ||
            rules::potInvulnSaveMod() != 2 ||
            rules::potInvulnRoundLo() != 5 ||
            rules::potInvulnRoundHi() != 20) ++bad;
        // Levitation - the spell level and the
        // maximum weight
        if (rules::potLevitSpellLevel() != 2 ||
            rules::potLevitMaxWeightGp() != 6000) ++bad;
        // Longevity - the years and the reversal
        if (rules::potLongYearsLo() != 1 ||
            rules::potLongYearsHi() != 12 ||
            rules::potLongReversePercent() != 1) ++bad;
        // Oil of Etherealness - the onset and
        // the duration
        if (rules::potEtherRoundsToEffect() != 3 ||
            rules::potEtherTurnsBase() != 4 ||
            rules::potEtherExtraLo() != 1 ||
            rules::potEtherExtraHi() != 4) ++bad;
        // Oil of Slipperiness - the slip chance
        // and the hours
        if (rules::potSlipFallPercent() != 95 ||
            rules::potSlipHours() != 8) ++bad;
        // Philter of Love - the charm duration
        if (rules::potLoveTurnsBase() != 4 ||
            rules::potLoveExtraLo() != 1 ||
            rules::potLoveExtraHi() != 4) ++bad;
        // Philter of Persuasiveness - the
        // reaction bonus and the suggest
        if (rules::potPersuadeReactPercent() != 25 ||
            rules::potPersuadePerTurn() != 1 ||
            rules::potPersuadeRangeInches() != 3) ++bad;
        // Plant Control - the square, the range,
        // and the duration
        if (rules::potPlantSaveInt() != 5 ||
            rules::potPlantSquareInches() != 2 ||
            rules::potPlantRangeInches() != 9 ||
            rules::potPlantRoundLo() != 5 ||
            rules::potPlantRoundHi() != 20) ++bad;
        // Poison - the save modifiers and the
        // neutralize percent
        if (rules::potPoisonWeakLo() != 1 ||
            rules::potPoisonWeakHi() != 4 ||
            rules::potPoisonDeadlyLo() != -4 ||
            rules::potPoisonDeadlyHi() != -1 ||
            rules::potPoisonNeutralizePercent() != 40) ++bad;
        // Polymorph self - the spell level
        if (rules::potPolySpellLevel() != 4) ++bad;
        // Speed - the boost, the movement, the
        // aging, and the rounds
        if (rules::potSpeedBoostPercent() != 100 ||
            rules::potSpeedMoveBaseInches() != 9 ||
            rules::potSpeedMoveBoostedInches() != 18 ||
            rules::potSpeedAgeYears() != 1 ||
            rules::potSpeedRoundLo() != 5 ||
            rules::potSpeedRoundHi() != 20) ++bad;
        // Super-Heroism - the ceiling, the table,
        // and the rounds
        if (rules::potSHeroMaxLevels() != 13 ||
            rules::potSHeroRowCount() != 4 ||
            rules::potSHeroDmgFaces() != 10 ||
            rules::potSHeroRoundLo() != 5 ||
            rules::potSHeroRoundHi() != 30) ++bad;
        static const int kSLvl[4] = {
            5, 4, 3, 2,
        };
        static const int kSDice[4] = {
            4, 3, 2, 1,
        };
        static const int kSBon[4] = {
            1, 2, 3, 4,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::potSHeroLevels(i) != kSLvl[i] ||
                rules::potSHeroDmgDice(i) != kSDice[i] ||
                rules::potSHeroDmgBonus(i) != kSBon[i]) ++bad;
        // Sweet Water - the volumes and the
        // initial period
        if (rules::potSweetWaterCubicFeet() != 100000 ||
            rules::potSweetAcidCubicFeet() != 1000 ||
            rules::potSweetRoundLo() != 5 ||
            rules::potSweetRoundHi() != 20) ++bad;
        // Treasure Finding - the range, the
        // mass, and the rounds
        if (rules::potTreasureRangeInches() != 24 ||
            rules::potTreasureMinCopper() != 10000 ||
            rules::potTreasureMinGems() != 100 ||
            rules::potTreasureRoundLo() != 5 ||
            rules::potTreasureRoundHi() != 20) ++bad;
        // Undead Control - the hit dice, the
        // save, the rounds, and the type table
        if (rules::potUndeadMaxHitDice() != 16 ||
            rules::potUndeadSaveMod() != -2 ||
            rules::potUndeadRoundLo() != 5 ||
            rules::potUndeadRoundHi() != 20 ||
            rules::potUndeadTypeRowCount() != 10 ||
            rules::potUndeadTypeFaces() != 10) ++bad;
        static const int kULo[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        };
        static const int kUHi[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        };
        for (int i = 0; i < 10; ++i)
            if (rules::potUndeadTypeLo(i) != kULo[i] ||
                rules::potUndeadTypeHi(i) != kUHi[i]) ++bad;
        for (int i = 1; i < 10; ++i)
            if (rules::potUndeadTypeLo(i) !=
                rules::potUndeadTypeHi(i - 1) + 1) ++bad;
        if (rules::potUndeadTypeLo(-5) != 1 ||
            rules::potUndeadTypeHi(99) != 10) ++bad;
        // Water Breathing - the doses and the
        // duration
        if (rules::potWaterTwoDosePercent() != 75 ||
            rules::potWaterFourDosePercent() != 25 ||
            rules::potWaterHourPerDose() != 1 ||
            rules::potWaterExtraLo() != 1 ||
            rules::potWaterExtraHi() != 10) ++bad;
        printf("R251 potions prose part 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
