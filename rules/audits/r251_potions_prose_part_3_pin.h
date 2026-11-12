    // ---- R251: the III.A potions explanation prose part 3 pins audit ----
    // DMG pp.136-137: Invulnerability
    // through Water Breathing - the potions
    // arc closes.
    {
        Potions potions;
        Potions_invulnerability_to_water_breathing potions_invulnerability_to_water_breathing;
        int bad = 0;
        // the sixteen potions are the engine III.A
        // table rows 20-35 - bands 55-100, the
        // table closing at 100 (the R221 pins)
        if (potions.potionRowCount() != 35 ||
            potions.potionRowLo(19) != 55 ||
            potions.potionRowHi(34) != 100) ++bad;
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
            if (potions.potionRowLo(i + 19) != kRowLo[i] ||
                potions.potionRowHi(i + 19) != kRowHi[i]) ++bad;
        // Invulnerability - the hit dice, the
        // armor class, the save, and the rounds
        if (potions_invulnerability_to_water_breathing.potInvulnMinHitDice() != 4 ||
            potions_invulnerability_to_water_breathing.potInvulnAcClasses() != 2 ||
            potions_invulnerability_to_water_breathing.potInvulnSaveMod() != 2 ||
            potions_invulnerability_to_water_breathing.potInvulnRoundLo() != 5 ||
            potions_invulnerability_to_water_breathing.potInvulnRoundHi() != 20) ++bad;
        // Levitation - the spell level and the
        // maximum weight
        if (potions_invulnerability_to_water_breathing.potLevitSpellLevel() != 2 ||
            potions_invulnerability_to_water_breathing.potLevitMaxWeightGp() != 6000) ++bad;
        // Longevity - the years and the reversal
        if (potions_invulnerability_to_water_breathing.potLongYearsLo() != 1 ||
            potions_invulnerability_to_water_breathing.potLongYearsHi() != 12 ||
            potions_invulnerability_to_water_breathing.potLongReversePercent() != 1) ++bad;
        // Oil of Etherealness - the onset and
        // the duration
        if (potions_invulnerability_to_water_breathing.potEtherRoundsToEffect() != 3 ||
            potions_invulnerability_to_water_breathing.potEtherTurnsBase() != 4 ||
            potions_invulnerability_to_water_breathing.potEtherExtraLo() != 1 ||
            potions_invulnerability_to_water_breathing.potEtherExtraHi() != 4) ++bad;
        // Oil of Slipperiness - the slip chance
        // and the hours
        if (potions_invulnerability_to_water_breathing.potSlipFallPercent() != 95 ||
            potions_invulnerability_to_water_breathing.potSlipHours() != 8) ++bad;
        // Philter of Love - the charm duration
        if (potions_invulnerability_to_water_breathing.potLoveTurnsBase() != 4 ||
            potions_invulnerability_to_water_breathing.potLoveExtraLo() != 1 ||
            potions_invulnerability_to_water_breathing.potLoveExtraHi() != 4) ++bad;
        // Philter of Persuasiveness - the
        // reaction bonus and the suggest
        if (potions_invulnerability_to_water_breathing.potPersuadeReactPercent() != 25 ||
            potions_invulnerability_to_water_breathing.potPersuadePerTurn() != 1 ||
            potions_invulnerability_to_water_breathing.potPersuadeRangeInches() != 3) ++bad;
        // Plant Control - the square, the range,
        // and the duration
        if (potions_invulnerability_to_water_breathing.potPlantSaveInt() != 5 ||
            potions_invulnerability_to_water_breathing.potPlantSquareInches() != 2 ||
            potions_invulnerability_to_water_breathing.potPlantRangeInches() != 9 ||
            potions_invulnerability_to_water_breathing.potPlantRoundLo() != 5 ||
            potions_invulnerability_to_water_breathing.potPlantRoundHi() != 20) ++bad;
        // Poison - the save modifiers and the
        // neutralize percent
        if (potions_invulnerability_to_water_breathing.potPoisonWeakLo() != 1 ||
            potions_invulnerability_to_water_breathing.potPoisonWeakHi() != 4 ||
            potions_invulnerability_to_water_breathing.potPoisonDeadlyLo() != -4 ||
            potions_invulnerability_to_water_breathing.potPoisonDeadlyHi() != -1 ||
            potions_invulnerability_to_water_breathing.potPoisonNeutralizePercent() != 40) ++bad;
        // Polymorph self - the spell level
        if (potions_invulnerability_to_water_breathing.potPolySpellLevel() != 4) ++bad;
        // Speed - the boost, the movement, the
        // aging, and the rounds
        if (potions_invulnerability_to_water_breathing.potSpeedBoostPercent() != 100 ||
            potions_invulnerability_to_water_breathing.potSpeedMoveBaseInches() != 9 ||
            potions_invulnerability_to_water_breathing.potSpeedMoveBoostedInches() != 18 ||
            potions_invulnerability_to_water_breathing.potSpeedAgeYears() != 1 ||
            potions_invulnerability_to_water_breathing.potSpeedRoundLo() != 5 ||
            potions_invulnerability_to_water_breathing.potSpeedRoundHi() != 20) ++bad;
        // Super-Heroism - the ceiling, the table,
        // and the rounds
        if (potions_invulnerability_to_water_breathing.potSHeroMaxLevels() != 13 ||
            potions_invulnerability_to_water_breathing.potSHeroRowCount() != 4 ||
            potions_invulnerability_to_water_breathing.potSHeroDmgFaces() != 10 ||
            potions_invulnerability_to_water_breathing.potSHeroRoundLo() != 5 ||
            potions_invulnerability_to_water_breathing.potSHeroRoundHi() != 30) ++bad;
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
            if (potions_invulnerability_to_water_breathing.potSHeroLevels(i) != kSLvl[i] ||
                potions_invulnerability_to_water_breathing.potSHeroDmgDice(i) != kSDice[i] ||
                potions_invulnerability_to_water_breathing.potSHeroDmgBonus(i) != kSBon[i]) ++bad;
        // Sweet Water - the volumes and the
        // initial period
        if (potions_invulnerability_to_water_breathing.potSweetWaterCubicFeet() != 100000 ||
            potions_invulnerability_to_water_breathing.potSweetAcidCubicFeet() != 1000 ||
            potions_invulnerability_to_water_breathing.potSweetRoundLo() != 5 ||
            potions_invulnerability_to_water_breathing.potSweetRoundHi() != 20) ++bad;
        // Treasure Finding - the range, the
        // mass, and the rounds
        if (potions_invulnerability_to_water_breathing.potTreasureRangeInches() != 24 ||
            potions_invulnerability_to_water_breathing.potTreasureMinCopper() != 10000 ||
            potions_invulnerability_to_water_breathing.potTreasureMinGems() != 100 ||
            potions_invulnerability_to_water_breathing.potTreasureRoundLo() != 5 ||
            potions_invulnerability_to_water_breathing.potTreasureRoundHi() != 20) ++bad;
        // Undead Control - the hit dice, the
        // save, the rounds, and the type table
        if (potions_invulnerability_to_water_breathing.potUndeadMaxHitDice() != 16 ||
            potions_invulnerability_to_water_breathing.potUndeadSaveMod() != -2 ||
            potions_invulnerability_to_water_breathing.potUndeadRoundLo() != 5 ||
            potions_invulnerability_to_water_breathing.potUndeadRoundHi() != 20 ||
            potions_invulnerability_to_water_breathing.potUndeadTypeRowCount() != 10 ||
            potions_invulnerability_to_water_breathing.potUndeadTypeFaces() != 10) ++bad;
        static const int kULo[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        };
        static const int kUHi[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        };
        for (int i = 0; i < 10; ++i)
            if (potions_invulnerability_to_water_breathing.potUndeadTypeLo(i) != kULo[i] ||
                potions_invulnerability_to_water_breathing.potUndeadTypeHi(i) != kUHi[i]) ++bad;
        for (int i = 1; i < 10; ++i)
            if (potions_invulnerability_to_water_breathing.potUndeadTypeLo(i) !=
                potions_invulnerability_to_water_breathing.potUndeadTypeHi(i - 1) + 1) ++bad;
        if (potions_invulnerability_to_water_breathing.potUndeadTypeLo(-5) != 1 ||
            potions_invulnerability_to_water_breathing.potUndeadTypeHi(99) != 10) ++bad;
        // Water Breathing - the doses and the
        // duration
        if (potions_invulnerability_to_water_breathing.potWaterTwoDosePercent() != 75 ||
            potions_invulnerability_to_water_breathing.potWaterFourDosePercent() != 25 ||
            potions_invulnerability_to_water_breathing.potWaterHourPerDose() != 1 ||
            potions_invulnerability_to_water_breathing.potWaterExtraLo() != 1 ||
            potions_invulnerability_to_water_breathing.potWaterExtraHi() != 10) ++bad;
        printf("R251 potions prose part 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
