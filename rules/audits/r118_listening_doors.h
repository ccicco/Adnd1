    // ---- R118: listening at doors audit ----
    {
        int bad = 0;
        // the book's table (DMG p.60): all seven
        // racial entries pinned, in 20
        if (abilities::raceListenIn20(abilities::LISTEN_DWARF)    != 2)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_ELF)      != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_GNOME)   != 4)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALF_ELF) != 2)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALFLING) != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALF_ORC) != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HUMAN)   != 2)
            ++bad;
        // out-of-range race -> the human band
        // (documented default)
        if (abilities::raceListenIn20(abilities::LISTEN_RACE_COUNT) != 2)
            ++bad;
        // the keen-eared bonus (1 or 2 in 20,
        // the caller passes it)
        if (abilities::listenChanceIn20(abilities::LISTEN_HUMAN, 0) != 2)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_HUMAN, 2) != 4)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, 1) != 5)
            ++bad;
        // clamps at both ends
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, -9) != 0)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, 20) != 20)
            ++bad;
        // thieves ride hear-noise (PHB) as in-20
        // bands (pct/5): L1 10% -> 2, L5 20% -> 4,
        // L12 35% -> 7, L13+ repeats the L12 row
        if (abilities::thiefListenIn20(1, 0)  != 2) ++bad;
        if (abilities::thiefListenIn20(5, 0)  != 4) ++bad;
        if (abilities::thiefListenIn20(12, 0) != 7) ++bad;
        if (abilities::thiefListenIn20(13, 0) != 7) ++bad;
        if (abilities::thiefListenIn20(9, 2)  != 8) ++bad;
        // clamps, and the derivation cross-checked
        // against the skill table itself
        if (abilities::thiefListenIn20(1, -9)  != 0)  ++bad;
        if (abilities::thiefListenIn20(12, 20) != 20) ++bad;
        for (int lvl = 1; lvl <= 14; ++lvl) {
            int expected =
                abilities::thiefSkillBase(abilities::SKILL_HEAR_NOISE,
                                         lvl) / 5;
            if (abilities::thiefListenIn20(lvl, 0) != expected)
                ++bad;
        }
        // the roll: d20 <= chance; the edges and a
        // seeded smoke with both ends reachable
        {
            rules::Rng rng8(6180);
            rules::Dice dice8(rng8);
            for (int i = 0; i < 100; ++i) {
                if (abilities::listenAtDoor(dice8, 0))  ++bad;
                if (!abilities::listenAtDoor(dice8, 20)) ++bad;
            }
            int hits = 0, misses = 0;
            for (int i = 0; i < 2000; ++i) {
                if (abilities::listenAtDoor(dice8, 2)) ++hits;
                else ++misses;
            }
            if (hits == 0 || misses == 0) ++bad;
        }
        printf("R118 listening at doors audit: bad %d\n", bad);
        if (bad) return 1;
    }
