    // ---- R249: the III.A potions explanation prose part 1 pins audit ----
    // DMG pp.133-134: the conventions and
    // the first nine potions.
    {
        int bad = 0;
        // the nine potions are the engine III.A
        // table rows 1-9 - bands 01-26, fire
        // resistance from 27 (the R221 pins)
        if (rules::potionRowLo(0) != 1 ||
            rules::potionRowHi(8) != 26 ||
            rules::potionRowLo(9) != 27) ++bad;
        // the general conventions
        if (rules::potDurationTurnsBase() != 4 ||
            rules::potDurationExtraLo() != 1 ||
            rules::potDurationExtraHi() != 4 ||
            rules::potOnsetLo() != 2 ||
            rules::potOnsetHi() != 5) ++bad;
        // Animal Control - the sizes and the save
        if (rules::potAnimalSmallLo() != 5 ||
            rules::potAnimalSmallHi() != 20 ||
            rules::potAnimalManLo() != 3 ||
            rules::potAnimalManHi() != 12 ||
            rules::potAnimalLargeLo() != 1 ||
            rules::potAnimalLargeHi() != 4 ||
            rules::potAnimalSaveInt() != 5) ++bad;
        // the animal type sub-table: 7 rows on d20
        if (rules::potAnimalTypeRowCount() != 7 ||
            rules::potAnimalTypeFaces() != 20) ++bad;
        static const int kALo[7] = {
            1, 5, 9, 13, 16, 18, 20,
        };
        static const int kAHi[7] = {
            4, 8, 12, 15, 17, 19, 20,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::potAnimalTypeLo(i) != kALo[i] ||
                rules::potAnimalTypeHi(i) != kAHi[i]) ++bad;
        for (int i = 1; i < 7; ++i)
            if (rules::potAnimalTypeLo(i) !=
                rules::potAnimalTypeHi(i - 1) + 1) ++bad;
        if (rules::potAnimalTypeLo(-5) != 1 ||
            rules::potAnimalTypeHi(99) != 20) ++bad;
        // Clairaudience / Clairvoyance
        if (rules::potClairaudRangeInches() != 3 ||
            rules::potClairaudTurns() != 2 ||
            rules::potClairvoyRangeInches() != 3 ||
            rules::potClairvoyTurns() != 1) ++bad;
        // Climbing - the slip chance and the armor table
        if (rules::potClimbBasePercent() != 1 ||
            rules::potClimbFallRoll() != 1 ||
            rules::potClimbTurns() != 1 ||
            rules::potClimbExtraRoundsLo() != 5 ||
            rules::potClimbExtraRoundsHi() != 20 ||
            rules::potClimbLoadIncrementGp() != 1000 ||
            rules::potClimbLoadPercent() != 1 ||
            rules::potClimbArmorRowCount() != 7) ++bad;
        static const int kArmor[7] = {
            1, 2, 4, 7, 8, 10, 1,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::potClimbArmorPercent(i) != kArmor[i]) ++bad;
        // Delusion / Diminution
        if (rules::potDeludeAgreePercent() != 90 ||
            rules::potDiminishMinPercent() != 5 ||
            rules::potDiminishHalfPercent() != 50 ||
            rules::potDiminishTurnsBase() != 6 ||
            rules::potDiminishExtraLo() != 2 ||
            rules::potDiminishExtraHi() != 5) ++bad;
        // Dragon Control - the charm and the save
        if (rules::potDragonRangeInches() != 6 ||
            rules::potDragonSaveMod() != -2 ||
            rules::potDragonLo() != 5 ||
            rules::potDragonHi() != 20 ||
            rules::potDragonDice() != 5 ||
            rules::potDragonFaces() != 4) ++bad;
        // the dragon type sub-table: 12 rows on d20
        if (rules::potDragonTypeRowCount() != 12 ||
            rules::potDragonTypeFaces() != 20) ++bad;
        static const int kDLo[12] = {
            1, 3, 5, 8, 10, 11, 13, 15, 16, 17, 18, 20,
        };
        static const int kDHi[12] = {
            2, 4, 7, 9, 10, 12, 14, 15, 16, 17, 19, 20,
        };
        for (int i = 0; i < 12; ++i)
            if (rules::potDragonTypeLo(i) != kDLo[i] ||
                rules::potDragonTypeHi(i) != kDHi[i]) ++bad;
        for (int i = 1; i < 12; ++i)
            if (rules::potDragonTypeLo(i) !=
                rules::potDragonTypeHi(i - 1) + 1) ++bad;
        if (rules::potDragonTypeLo(-5) != 1 ||
            rules::potDragonTypeHi(99) != 20) ++bad;
        // ESP / Extra-Healing
        if (rules::potEspLo() != 5 ||
            rules::potEspHi() != 40 ||
            rules::potEspDice() != 5 ||
            rules::potEspFaces() != 8 ||
            rules::potXHealLo() != 6 ||
            rules::potXHealHi() != 27 ||
            rules::potXHealDice() != 3 ||
            rules::potXHealFaces() != 8 ||
            rules::potXHealBonus() != 3 ||
            rules::potXHealThirdLo() != 1 ||
            rules::potXHealThirdHi() != 8) ++bad;
        printf("R249 potions prose part 1 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
