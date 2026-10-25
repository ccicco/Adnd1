    // ---- R147: matrix II.D audit ----
    // DMG p.80 footnote D: non-intelligence saves at
    // half hit dice rounded up - half the II.B-stepped
    // level - except vs. death/poison. Pins: the halving
    // against the stepped level, the category exception,
    // the iron_golem/goblin mapping, and the census
    // (exactly 90 of the 408 print intelligence "non";
    // "animal" keeps II.B - a named judgment call).
    {
        int bad = 0;
        struct { float hd; int lvl; int half; } kPin[] = {
            { 0.5f, 1, 1 }, { 2.0f, 2, 1 },
            { 3.0f, 3, 2 }, { 4.0f, 4, 2 },
            { 4.75f, 5, 3 }, { 6.0f, 6, 3 },
            { 8.5f, 9, 5 }, { 10.0f, 10, 5 },
            { 12.0f, 12, 6 }, { 16.0f, 16, 8 },
            { 20.0f, 20, 10 },
        };
        for (int i = 0; i < 11; ++i) {
            int lvl = rules::monsterSaveLevel(kPin[i].hd);
            if (lvl != kPin[i].lvl) ++bad;
            int h = spelleffects::effectiveSaveLevel(
                lvl, true, rules::SAVE_SPELLS);
            if (h != kPin[i].half) ++bad;
            if (spelleffects::effectiveSaveLevel(
                    lvl, true, rules::SAVE_DEATH_POISON)
                != lvl) ++bad;
        }
        if (spelleffects::effectiveSaveLevel(
                9, false, rules::SAVE_SPELLS) != 9) ++bad;
        {
            rules::Rng rngII(20261004);
            rules::Dice diceII(rngII);
            if (!reg.toActor("iron_golem", diceII)
                    .nonIntelligent) ++bad;
            if (reg.toActor("goblin", diceII)
                    .nonIntelligent) ++bad;
            int non = 0;
            for (const auto& kv : reg.all())
                if (reg.toActor(kv.first, diceII)
                        .nonIntelligent) ++non;
            if (non != 90) ++bad;
        }
        printf("R147 matrix II.D audit: bad %d\n", bad);
        if (bad) return 1;
    }
