    // ---- R110: saving throws audit (DMG p.79-80 matrix I) ----
    {
        int bad = 0;
        // the banded tables, pinned band by band (repo category
        // order: Death, Wands, Petrify, Breath, Spells)
        {
            struct SC { int cls, lvl, cat, want; };
            const SC sc[] = {
                // fighter 1-2 band
                {0, 1, rules::SAVE_DEATH_POISON,  14},
                {0, 1, rules::SAVE_WANDS,         16},
                {0, 1, rules::SAVE_PETRIFY_POLY,  15},
                {0, 1, rules::SAVE_BREATH,        17},
                {0, 1, rules::SAVE_SPELLS,        17},
                {0, 2, rules::SAVE_DEATH_POISON,  14},  // band mate
                {0, 0, rules::SAVE_DEATH_POISON,  16},  // 0-level row
                {0, 3, rules::SAVE_DEATH_POISON,  13},  // 3-4 band
                {0, 9, rules::SAVE_SPELLS,        11},  // 9-10 band
                {0, 9, rules::SAVE_BREATH,         9},  // dips below wands
                {0, 17, rules::SAVE_DEATH_POISON,  3},  // 17+ band
                {0, 25, rules::SAVE_DEATH_POISON,  3},  // beyond: last band
                // cleric - the big fix: L1 death save is 10, not 14
                {2, 1, rules::SAVE_DEATH_POISON,  10},
                {2, 1, rules::SAVE_WANDS,         14},
                {2, 3, rules::SAVE_DEATH_POISON,  10},  // band 1-3
                {2, 4, rules::SAVE_DEATH_POISON,   9},  // band 4-6
                {2, 12, rules::SAVE_SPELLS,        11}, // band 10-12
                {2, 19, rules::SAVE_DEATH_POISON,   2}, // 19+ band
                // magic-user
                {1, 1, rules::SAVE_DEATH_POISON,  14},
                {1, 1, rules::SAVE_WANDS,         11},
                {1, 5, rules::SAVE_SPELLS,        12},  // band 1-5
                {1, 6, rules::SAVE_SPELLS,        10},  // band 6-10
                {1, 21, rules::SAVE_SPELLS,         4}, // 21+ band
                {1, 25, rules::SAVE_SPELLS,         4},
                // thief (1-4 happens to match the old linear row)
                {3, 1, rules::SAVE_DEATH_POISON,  13},
                {3, 1, rules::SAVE_WANDS,         14},
                {3, 4, rules::SAVE_DEATH_POISON,  13},  // band 1-4
                {3, 5, rules::SAVE_DEATH_POISON,  12},  // band 5-8
                {3, 21, rules::SAVE_SPELLS,         5},  // 21+ band
            };
            for (const SC& s : sc) {
                if (rules::saveTarget(s.cls, s.lvl,
                                       (rules::SaveCategory)s.cat)
                    != s.want) ++bad;
            }
        }
        // the tables never worsen with level and stay in bounds
        for (int cls = 0; cls < 4; ++cls) {
            for (int cat = 0; cat < rules::SAVE_COUNT; ++cat) {
                int prev = 99;
                for (int lvl = 1; lvl <= 25; ++lvl) {
                    int v = rules::saveTarget(cls, lvl,
                                              (rules::SaveCategory)cat);
                    if (v < 2 || v > 20) ++bad;
                    if (v > prev) ++bad;
                    prev = v;
                }
            }
        }
        // monster HD -> save level (matrix II.B stepping)
        {
            const float hds[]  = { 0.5f, 1.0f, 1.25f, 1.5f, 1.75f,
                                  2.25f, 2.5f, 4.8f, 16.0f, 40.0f };
            const int   want[] = { 1, 1, 2, 2, 2, 3, 3, 5, 16, 21 };
            for (int i = 0; i < 10; ++i)
                if (rules::monsterSaveLevel(hds[i]) != want[i]) ++bad;
        }
        // a natural 1 is ALWAYS failure, whatever the modifier
        {
            rules::Rng rng(110);
            rules::Dice dice(rng);
            int fails = 0;
            for (int i = 0; i < 20000; ++i) {
                // target 1, modifier +19: only a natural 1 fails
                if (!rules::attemptSave(dice, 1, 19)) ++fails;
            }
            if (fails == 0 || fails == 20000) ++bad;
        }
        printf("R110 saves audit: bad %d\n", bad);
        if (bad) return 1;
    }
