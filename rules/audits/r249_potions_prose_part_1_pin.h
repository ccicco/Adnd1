    // ---- R249: the III.A potions explanation prose part 1 pins audit ----
    // DMG pp.133-134: the conventions and
    // the first nine potions.
    {
        Potions potions;
        Potions_conventions_animal_control_to_extra_healing potions_conventions_animal_control_to_extra_healing;
        int bad = 0;
        // the nine potions are the engine III.A
        // table rows 1-9 - bands 01-26, fire
        // resistance from 27 (the R221 pins)
        if (potions.potionRowLo(0) != 1 ||
            potions.potionRowHi(8) != 26 ||
            potions.potionRowLo(9) != 27) ++bad;
        // the general conventions
        if (potions_conventions_animal_control_to_extra_healing.potDurationTurnsBase() != 4 ||
            potions_conventions_animal_control_to_extra_healing.potDurationExtraLo() != 1 ||
            potions_conventions_animal_control_to_extra_healing.potDurationExtraHi() != 4 ||
            potions_conventions_animal_control_to_extra_healing.potOnsetLo() != 2 ||
            potions_conventions_animal_control_to_extra_healing.potOnsetHi() != 5) ++bad;
        // Animal Control - the sizes and the save
        if (potions_conventions_animal_control_to_extra_healing.potAnimalSmallLo() != 5 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalSmallHi() != 20 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalManLo() != 3 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalManHi() != 12 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalLargeLo() != 1 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalLargeHi() != 4 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalSaveInt() != 5) ++bad;
        // the animal type sub-table: 7 rows on d20
        if (potions_conventions_animal_control_to_extra_healing.potAnimalTypeRowCount() != 7 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalTypeFaces() != 20) ++bad;
        static const int kALo[7] = {
            1, 5, 9, 13, 16, 18, 20,
        };
        static const int kAHi[7] = {
            4, 8, 12, 15, 17, 19, 20,
        };
        for (int i = 0; i < 7; ++i)
            if (potions_conventions_animal_control_to_extra_healing.potAnimalTypeLo(i) != kALo[i] ||
                potions_conventions_animal_control_to_extra_healing.potAnimalTypeHi(i) != kAHi[i]) ++bad;
        for (int i = 1; i < 7; ++i)
            if (potions_conventions_animal_control_to_extra_healing.potAnimalTypeLo(i) !=
                potions_conventions_animal_control_to_extra_healing.potAnimalTypeHi(i - 1) + 1) ++bad;
        if (potions_conventions_animal_control_to_extra_healing.potAnimalTypeLo(-5) != 1 ||
            potions_conventions_animal_control_to_extra_healing.potAnimalTypeHi(99) != 20) ++bad;
        // Clairaudience / Clairvoyance
        if (potions_conventions_animal_control_to_extra_healing.potClairaudRangeInches() != 3 ||
            potions_conventions_animal_control_to_extra_healing.potClairaudTurns() != 2 ||
            potions_conventions_animal_control_to_extra_healing.potClairvoyRangeInches() != 3 ||
            potions_conventions_animal_control_to_extra_healing.potClairvoyTurns() != 1) ++bad;
        // Climbing - the slip chance and the armor table
        if (potions_conventions_animal_control_to_extra_healing.potClimbBasePercent() != 1 ||
            potions_conventions_animal_control_to_extra_healing.potClimbFallRoll() != 1 ||
            potions_conventions_animal_control_to_extra_healing.potClimbTurns() != 1 ||
            potions_conventions_animal_control_to_extra_healing.potClimbExtraRoundsLo() != 5 ||
            potions_conventions_animal_control_to_extra_healing.potClimbExtraRoundsHi() != 20 ||
            potions_conventions_animal_control_to_extra_healing.potClimbLoadIncrementGp() != 1000 ||
            potions_conventions_animal_control_to_extra_healing.potClimbLoadPercent() != 1 ||
            potions_conventions_animal_control_to_extra_healing.potClimbArmorRowCount() != 7) ++bad;
        static const int kArmor[7] = {
            1, 2, 4, 7, 8, 10, 1,
        };
        for (int i = 0; i < 7; ++i)
            if (potions_conventions_animal_control_to_extra_healing.potClimbArmorPercent(i) != kArmor[i]) ++bad;
        // Delusion / Diminution
        if (potions_conventions_animal_control_to_extra_healing.potDeludeAgreePercent() != 90 ||
            potions_conventions_animal_control_to_extra_healing.potDiminishMinPercent() != 5 ||
            potions_conventions_animal_control_to_extra_healing.potDiminishHalfPercent() != 50 ||
            potions_conventions_animal_control_to_extra_healing.potDiminishTurnsBase() != 6 ||
            potions_conventions_animal_control_to_extra_healing.potDiminishExtraLo() != 2 ||
            potions_conventions_animal_control_to_extra_healing.potDiminishExtraHi() != 5) ++bad;
        // Dragon Control - the charm and the save
        if (potions_conventions_animal_control_to_extra_healing.potDragonRangeInches() != 6 ||
            potions_conventions_animal_control_to_extra_healing.potDragonSaveMod() != -2 ||
            potions_conventions_animal_control_to_extra_healing.potDragonLo() != 5 ||
            potions_conventions_animal_control_to_extra_healing.potDragonHi() != 20 ||
            potions_conventions_animal_control_to_extra_healing.potDragonDice() != 5 ||
            potions_conventions_animal_control_to_extra_healing.potDragonFaces() != 4) ++bad;
        // the dragon type sub-table: 12 rows on d20
        if (potions_conventions_animal_control_to_extra_healing.potDragonTypeRowCount() != 12 ||
            potions_conventions_animal_control_to_extra_healing.potDragonTypeFaces() != 20) ++bad;
        static const int kDLo[12] = {
            1, 3, 5, 8, 10, 11, 13, 15, 16, 17, 18, 20,
        };
        static const int kDHi[12] = {
            2, 4, 7, 9, 10, 12, 14, 15, 16, 17, 19, 20,
        };
        for (int i = 0; i < 12; ++i)
            if (potions_conventions_animal_control_to_extra_healing.potDragonTypeLo(i) != kDLo[i] ||
                potions_conventions_animal_control_to_extra_healing.potDragonTypeHi(i) != kDHi[i]) ++bad;
        for (int i = 1; i < 12; ++i)
            if (potions_conventions_animal_control_to_extra_healing.potDragonTypeLo(i) !=
                potions_conventions_animal_control_to_extra_healing.potDragonTypeHi(i - 1) + 1) ++bad;
        if (potions_conventions_animal_control_to_extra_healing.potDragonTypeLo(-5) != 1 ||
            potions_conventions_animal_control_to_extra_healing.potDragonTypeHi(99) != 20) ++bad;
        // ESP / Extra-Healing
        if (potions_conventions_animal_control_to_extra_healing.potEspLo() != 5 ||
            potions_conventions_animal_control_to_extra_healing.potEspHi() != 40 ||
            potions_conventions_animal_control_to_extra_healing.potEspDice() != 5 ||
            potions_conventions_animal_control_to_extra_healing.potEspFaces() != 8 ||
            potions_conventions_animal_control_to_extra_healing.potXHealLo() != 6 ||
            potions_conventions_animal_control_to_extra_healing.potXHealHi() != 27 ||
            potions_conventions_animal_control_to_extra_healing.potXHealDice() != 3 ||
            potions_conventions_animal_control_to_extra_healing.potXHealFaces() != 8 ||
            potions_conventions_animal_control_to_extra_healing.potXHealBonus() != 3 ||
            potions_conventions_animal_control_to_extra_healing.potXHealThirdLo() != 1 ||
            potions_conventions_animal_control_to_extra_healing.potXHealThirdHi() != 8) ++bad;
        printf("R249 potions prose part 1 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
