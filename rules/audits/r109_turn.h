    // ---- R109: turning undead audit (DMG p.75-76 matrix III) ----
    {
        int bad = 0;
        // the printed table, spot-checked cell for cell
        {
            struct Cell { int lvl, kind, result, target, count; };
            const Cell cells[] = {
                { 1,  0, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 },
                { 1,  1, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_12 },
                { 1,  2, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 },
                { 1,  3, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 },
                { 1,  4, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 1,  5, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 },
                { 2,  5, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 3,  6, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 4,  7, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 5,  8, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 6,  9, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 7, 10, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 },
                { 8, 11, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 },
                { 8, 12, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_2  },
                { 4,  0, rules::TURN_ALL,      0, rules::TURN_COUNT_1_12 },
                { 6,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_1_12 },
                { 8,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 },
                { 9, 11, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 },
                {14, 11, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 },
                {14, 12, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_2  },
                {20,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 },
                { 0,  0, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 },
            };
            for (const Cell& c : cells) {
                rules::TurnAttempt t = rules::turnUndead(c.lvl, c.kind);
                if (t.result != c.result || t.target != c.target ||
                    t.countKind != c.count) ++bad;
            }
        }
        // every cell of the table is a legal value
        for (int kind = 0; kind < 13; ++kind) {
            for (int lvl = 1; lvl <= 20; ++lvl) {
                rules::TurnAttempt t = rules::turnUndead(lvl, kind);
                if (t.result == rules::TURN_CHANCE &&
                    (t.target < 4 || t.target > 20)) ++bad;
                if (t.result == rules::TURN_NONE) {
                    // dashes only past skeleton and zombie
                    if (kind == 0 || kind == 1) ++bad;
                }
            }
        }
        // the roll and count mechanics stay in bounds
        {
            rules::Rng rng(109);
            rules::Dice dice(rng);
            int seen1to12 = 0, seen7to12 = 0, seen1to2 = 0;
            int success = 0;
            for (int i = 0; i < 20000; ++i) {
                rules::TurnAttempt t =
                    rules::turnUndead(1, 0);   // skeleton, target 10
                if (rules::rollTurnSuccess(dice, t)) {
                    ++success;
                    int n = rules::rollTurnCount(dice, t);
                    if (n < 1 || n > 12) ++bad;
                    if (n == 12) seen1to12 = 1;
                }
                rules::TurnAttempt s =
                    rules::turnUndead(14, 12); // special, 1-2
                int n = rules::rollTurnCount(dice, s);
                if (n < 1 || n > 2) ++bad;
                if (n == 2) seen1to2 = 1;
                rules::TurnAttempt d =
                    rules::turnUndead(8, 0);   // D* skeleton
                int m = rules::rollTurnCount(dice, d);
                if (m < 7 || m > 12) ++bad;
                if (m == 7) seen7to12 = 1;
            }
            if (seen1to12 == 0 || seen1to2 == 0 ||
                seen7to12 == 0) ++bad;
            if (success == 0 || success == 20000) ++bad;
        }
        printf("R109 turn audit: bad %d\n", bad);
        if (bad) return 1;
    }
