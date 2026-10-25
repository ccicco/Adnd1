    // ---- R186: the bard audit ----
    // Every cell of Tables I and II, the gates,
    // the ladders and the wiring.
    {
        int bad = 0;
        // the ability gate: STR WIS DEX CHA 15+,
        // INT 12, CON 10
        if (!rules::bardAbilityGate(15, 15, 15, 15,
                                12, 10)) ++bad;
        if (!rules::bardAbilityGate(18, 16, 15, 17,
                                13, 11)) ++bad;
        if (rules::bardAbilityGate(14, 15, 15, 15,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 14, 15, 15,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 14, 15,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 14,
                               12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 15,
                               11, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 15,
                               12, 9)) ++bad;
        // the race gate: human or half-elf
        if (!rules::bardRaceAllowed(0)) ++bad;
        if (!rules::bardRaceAllowed(4)) ++bad;
        if (rules::bardRaceAllowed(1)) ++bad;
        if (rules::bardRaceAllowed(2)) ++bad;
        if (rules::bardRaceAllowed(3)) ++bad;
        if (rules::bardRaceAllowed(5)) ++bad;
        if (rules::bardRaceAllowed(6)) ++bad;
        // the progression windows
        if (!rules::bardFighterWindow(5)) ++bad;
        if (!rules::bardFighterWindow(6)) ++bad;
        if (!rules::bardFighterWindow(7)) ++bad;
        if (rules::bardFighterWindow(4)) ++bad;
        if (rules::bardFighterWindow(8)) ++bad;
        if (rules::bardFighterWindow(9)) ++bad;
        if (!rules::bardThiefWindow(5)) ++bad;
        if (!rules::bardThiefWindow(9)) ++bad;
        if (rules::bardThiefWindow(4)) ++bad;
        if (rules::bardThiefWindow(10)) ++bad;
        if (!rules::bardNeutralOnly()) ++bad;
        // Bards Table I, cell by cell: the XP
        // thresholds, the titles, the hit dice,
        // the druid slots
        static const int kXp[23] = {
            0,
            2001,
            4001,
            8001,
            16001,
            25001,
            40001,
            60001,
            85001,
            110001,
            150001,
            200001,
            400001,
            600001,
            800001,
            1000001,
            1200001,
            1400001,
            1600001,
            1800001,
            2000001,
            2200001,
            3000001,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardXpForLevel(lv)
                != kXp[lv-1]) ++bad;
        static const char* const kTitles[23] = {
            "Rhymer",
            "Lyrist",
            "Sonnateer",
            "Skald",
            "Racaraide",
            "Joungleur",
            "Troubador",
            "Minstrel",
            "Muse",
            "Lorist",
            "Bard",
            "Master Bard",
            "M. Bard 13th",
            "M. Bard 14th",
            "M. Bard 15th",
            "M. Bard 16th",
            "M. Bard 17th",
            "M. Bard 18th",
            "M. Bard 19th",
            "M. Bard 20th",
            "M. Bard 21st",
            "M. Bard 22nd",
            "M. Bard 23rd",
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (std::string(rules::bardTitle(lv))
                != kTitles[lv-1]) ++bad;
        static const int kSlots[23][5] = {
            { 1, 0, 0, 0, 0 },
            { 2, 0, 0, 0, 0 },
            { 3, 0, 0, 0, 0 },
            { 3, 1, 0, 0, 0 },
            { 3, 2, 0, 0, 0 },
            { 3, 3, 0, 0, 0 },
            { 3, 3, 1, 0, 0 },
            { 3, 3, 2, 0, 0 },
            { 3, 3, 3, 0, 0 },
            { 3, 3, 3, 1, 0 },
            { 3, 3, 3, 2, 0 },
            { 3, 3, 3, 3, 0 },
            { 3, 3, 3, 3, 1 },
            { 3, 3, 3, 3, 2 },
            { 3, 3, 3, 3, 3 },
            { 4, 3, 3, 3, 3 },
            { 4, 4, 3, 3, 3 },
            { 4, 4, 4, 3, 3 },
            { 5, 4, 4, 4, 3 },
            { 5, 4, 4, 4, 4 },
            { 5, 5, 4, 4, 4 },
            { 5, 5, 5, 4, 4 },
            { 5, 5, 5, 5, 5 },
        };
        for (int lv = 1; lv <= 23; ++lv)
            for (int sl = 1; sl <= 5; ++sl)
                if (rules::bardDruidSlots(lv, sl)
                    != kSlots[lv-1][sl-1]) ++bad;
        // the hit dice ladder: 0*, 1-10, then
        // 10+1 through 10+12
        if (rules::bardHitDice(1) != 0) ++bad;
        if (rules::bardHitDice(2) != 1) ++bad;
        if (rules::bardHitDice(11) != 10) ++bad;
        if (rules::bardHitDice(12) != 11) ++bad;
        if (rules::bardHitDice(23) != 22) ++bad;
        if (rules::bardHitDice(0) != 0) ++bad;
        if (rules::bardHitDice(99) != 22) ++bad;
        // the clamps: level and spell level
        if (rules::bardXpForLevel(0) != 0) ++bad;
        if (rules::bardXpForLevel(99) != 3000001) ++bad;
        if (rules::bardDruidSlots(0, 1) != 0) ++bad;
        if (rules::bardDruidSlots(24, 1) != 5) ++bad;
        if (rules::bardDruidSlots(23, 6) != 5) ++bad;
        if (rules::bardDruidSlots(23, 0) != 5) ++bad;
        if (std::string(rules::bardTitle(24))
            != "M. Bard 23rd") ++bad;
        // the druid cast ladder: same level,
        // capped at 12th until the 23rd casts
        // at 13th
        if (rules::bardDruidCastLevel(1) != 1) ++bad;
        if (rules::bardDruidCastLevel(5) != 5) ++bad;
        if (rules::bardDruidCastLevel(12) != 12) ++bad;
        if (rules::bardDruidCastLevel(13) != 12) ++bad;
        if (rules::bardDruidCastLevel(22) != 12) ++bad;
        if (rules::bardDruidCastLevel(23) != 13) ++bad;
        if (rules::bardDruidCastLevel(0) != 0) ++bad;
        // Bards Table II, cell by cell: the
        // colleges, the languages, the percents
        static const char* const kCollege[23] = {
            "Probationer",
            "Fochlucan",
            "Fochlucan",
            "Fochlucan",
            "Mac-Fuirmidh",
            "Mac-Fuirmidh",
            "Mac-Fuirmidh",
            "Doss",
            "Doss",
            "Doss",
            "Canaith",
            "Canaith",
            "Canaith",
            "Cli",
            "Cli",
            "Cli",
            "Anstruth",
            "Anstruth",
            "Anstruth",
            "Ollamh",
            "Ollamh",
            "Ollamh",
            "Magna Alumnae",
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (std::string(rules::bardCollege(lv))
                != kCollege[lv-1]) ++bad;
        static const int kLang[23] = {
            0,
            0,
            0,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            0,
            1,
            1,
            1,
            1,
            1,
            1,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardLanguages(lv)
                != kLang[lv-1]) ++bad;
        static const int kCharm[23] = {
            15,
            20,
            22,
            24,
            30,
            32,
            34,
            40,
            42,
            44,
            50,
            53,
            56,
            60,
            63,
            66,
            70,
            73,
            76,
            80,
            84,
            88,
            95,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardCharmPercent(lv)
                != kCharm[lv-1]) ++bad;
        static const int kLore[23] = {
            0,
            5,
            7,
            10,
            13,
            16,
            20,
            25,
            30,
            35,
            50,
            53,
            56,
            55,
            60,
            65,
            70,
            75,
            80,
            85,
            90,
            95,
            99,
        };
        for (int lv = 1; lv <= 23; ++lv)
            if (rules::bardLegendLorePercent(lv)
                != kLore[lv-1]) ++bad;
        // Table III: the weapon roster
        if (rules::bardWeaponCount() != 9) ++bad;
        if (!rules::bardWeaponAllowed("scimitar")) ++bad;
        if (!rules::bardWeaponAllowed("sword")) ++bad;
        if (!rules::bardWeaponAllowed("club")) ++bad;
        if (!rules::bardWeaponAllowed("staff")) ++bad;
        if (rules::bardWeaponAllowed("long bow")) ++bad;
        if (rules::bardWeaponAllowed("battle axe")) ++bad;
        if (rules::bardWeaponAllowed("")) ++bad;
        if (std::string(rules::bardWeaponName(0))
            != "club") ++bad;
        if (std::string(rules::bardWeaponName(8))
            != "sword") ++bad;
        // Table III: the armor and use pins
        if (!rules::bardOilAllowed()) ++bad;
        if (rules::bardPoisonAllowed(false)) ++bad;
        if (!rules::bardPoisonAllowed(true)) ++bad;
        if (rules::bardShieldAllowed()) ++bad;
        // the poetics layers
        if (rules::BARD_POETIC_ROUNDS != 2) ++bad;
        if (rules::BARD_POETIC_TURN != 1) ++bad;
        if (rules::BARD_MORALE_BONUS != 10) ++bad;
        if (rules::BARD_HIT_BONUS != 1) ++bad;
        // the henchmen ladder: 1 at 5th, 2 at
        // 8th, 3 at 11th, 4 at 14th, 5 at 17th,
        // 6 at 20th, any number at 23rd
        if (rules::bardHenchmen(1) != 0) ++bad;
        if (rules::bardHenchmen(4) != 0) ++bad;
        if (rules::bardHenchmen(5) != 1) ++bad;
        if (rules::bardHenchmen(7) != 1) ++bad;
        if (rules::bardHenchmen(8) != 2) ++bad;
        if (rules::bardHenchmen(11) != 3) ++bad;
        if (rules::bardHenchmen(14) != 4) ++bad;
        if (rules::bardHenchmen(17) != 5) ++bad;
        if (rules::bardHenchmen(20) != 6) ++bad;
        if (rules::bardHenchmen(22) != 6) ++bad;
        if (rules::bardHenchmen(23) != 999) ++bad;
        if (rules::bardHenchmen(0) != 0) ++bad;
        // the musical item bonuses
        if (rules::bardDrumsOfPanicSaveMod() != -1) ++bad;
        if (rules::bardHornOfBlastingDamageFactorPercent()
            != 150) ++bad;
        if (rules::bardLyreOfBuildingFactor() != 2) ++bad;
        if (rules::bardPipesOfSewerRatFactor() != 2) ++bad;
        printf("R186 the bard audit: bad %d\n", bad);
        if (bad) return 1;
    }
