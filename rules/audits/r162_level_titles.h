    // ---- R162: level title ladders audit ---------
    // PHB p.20-31: the printed per-level titles for
    // the four engine classes. The cleric level 5
    // title cell prints blank; JUDGMENT: it carries
    // the level 4 title down (Curate).
    {
        static const char* const kF[9] = {
            "Veteran", "Warrior", "Swordsman", "Hero",
            "Swashbuckler", "Myrmidon", "Champion",
            "Superhero", "Lord"
        };
        static const char* const kM[11] = {
            "Prestidigitator", "Evoker", "Conjurer",
            "Theurgist", "Thaumaturgist", "Magician",
            "Enchanter", "Warlock", "Sorcerer",
            "Necromancer", "Wizard"
        };
        static const char* const kC[9] = {
            "Acolyte", "Adept", "Priest", "Curate",
            "Curate", "Canon", "Lama", "Patriarch",
            "High Priest"
        };
        static const char* const kT[10] = {
            "Rogue (Apprentice)", "Footpad", "Cutpurse",
            "Robber", "Burglar", "Filcher", "Sharper",
            "Magsman", "Thief", "Master Thief"
        };
        int bad = 0;
        for (int i = 0; i < 9; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_FIGHTER, i + 1)) != kF[i])
                ++bad;
        for (int i = 0; i < 11; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_MAGIC_USER, i + 1)) != kM[i])
                ++bad;
        for (int i = 0; i < 9; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_CLERIC, i + 1)) != kC[i])
                ++bad;
        for (int i = 0; i < 10; ++i)
            if (std::string(rules::titleFor(
                    rules::CLASS_THIEF, i + 1)) != kT[i])
                ++bad;
        // the clamp conventions: a level above the
        // cap reads the top title; level 0 or below
        // reads the first title; a bad class reads
        // Unknown
        if (std::string(rules::titleFor(
                rules::CLASS_FIGHTER, 10)) != kF[8] ||
            std::string(rules::titleFor(
                rules::CLASS_FIGHTER, 99)) != kF[8] ||
            std::string(rules::titleFor(
                rules::CLASS_MAGIC_USER, 12)) != kM[10] ||
            std::string(rules::titleFor(
                rules::CLASS_CLERIC, 10)) != kC[8] ||
            std::string(rules::titleFor(
                rules::CLASS_THIEF, 11)) != kT[9]) ++bad;
        if (std::string(rules::titleFor(
                rules::CLASS_FIGHTER, 0)) != kF[0] ||
            std::string(rules::titleFor(
                rules::CLASS_THIEF, -3)) != kT[0]) ++bad;
        if (std::string(rules::titleFor(-1, 1)) != "Unknown" ||
            std::string(rules::titleFor(99, 1)) != "Unknown")
            ++bad;
        printf("R162 level title ladders audit: bad %d\n", bad);
        if (bad) return 1;
    }
