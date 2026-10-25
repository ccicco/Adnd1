    // ---- R368: the UA Cavaliers Table I
    // pin audit ----
    // The UA CAVALIERS TABLE I (p. 15): the
    // full table pinned - the two 0-level
    // rows (Horseman 1d4+1 at -1,500 to
    // -501, Lancer 2d4+1 at -500 to -1),
    // the 1st-level footnote (the track
    // 3d4+1 vs the direct 1d10+3), the
    // printed XP bands with the level-11
    // band decoded from its neighbors, the
    // cumulative dice column (the level
    // count at 2nd-10th, 10+3 and 10+6 at
    // 11th and 12th), the level titles (the
    // 11th and 12th cells newly readable -
    // two of the four R328 holes close; the
    // level-5 grid Knight with the prose
    // conflict flagged; the level-6 cell
    // lost, a hole; the 12-sided header cell
    // suspect against the R327 d10), the 3
    // hp per level past 10th, the 300,000
    // xp per level past 12th and Cavalier
    // Commander at 13th+. The R328 seam
    // cross-checks the XP ladder and the
    // known titles. The item flips CLOSED;
    // the census 294 -> 295.
    {
        using namespace rules;
        int bad = 0;
        // ---- the pinned cells ----
            if (uacavtHorsemanXpLow() != -1500) ++bad;
            if (uacavtHorsemanXpHigh() != -501) ++bad;
            if (uacavtHorsemanHpDice() != 1) ++bad;
            if (uacavtHorsemanHpDiceSides() != 4) ++bad;
            if (uacavtHorsemanHpBonus() != 1) ++bad;
            if (uacavtLancerXpLow() != -500) ++bad;
            if (uacavtLancerXpHigh() != -1) ++bad;
            if (uacavtLancerHpDice() != 2) ++bad;
            if (uacavtLancerHpDiceSides() != 4) ++bad;
            if (uacavtLancerHpBonus() != 1) ++bad;
            if (!uacavtFirstLevelTrackFootnote()) ++bad;
            if (uacavtTrackFirstDice() != 3) ++bad;
            if (uacavtTrackFirstSides() != 4) ++bad;
            if (uacavtTrackFirstBonus() != 1) ++bad;
            if (uacavtDirectFirstDice() != 1) ++bad;
            if (uacavtDirectFirstSides() != 10) ++bad;
            if (uacavtDirectFirstBonus() != 3) ++bad;
            if (!uacavtLevel12XpUnbounded()) ++bad;
            if (!uacavtLevel11BandDecoded()) ++bad;
            if (uacavtLevel11FlatHp() != 3) ++bad;
            if (uacavtLevel12FlatHp() != 6) ++bad;
            if (uacavtHpPerLevelPast10() != 3) ++bad;
            if (!uacavtDiceColumnCumulative()) ++bad;
            if (!uacavtTwelveSidedHeaderSuspect()) ++bad;
            if (!uacavtLevel6TitleCellLost()) ++bad;
            if (!uacavtLevel5GridVsProseConflict()) ++bad;
            if (uacavtXpPerLevelPast12() != 300000) ++bad;
            if (uacavtCommanderLevel() != 13) ++bad;
        // ---- the XP band loops ----
            static const int xl[12] = {0,
                2501, 5001, 10001, 18501,
                37001, 85001, 140001,
                220001, 300001, 600001,
                900001};
            static const int xh[12] = {2500,
                5000, 10000, 18500, 37000,
                85000, 140000, 220000,
                300000, 600000, 900000, 0};
            for (int l = 1; l <= 12; ++l) {
                if (uacavtLevelXpLow(l) != xl[l - 1])
                    ++bad;
                if (uacavtLevelXpHigh(l) != xh[l - 1])
                    ++bad;
                if (l < 12 && xh[l - 1] + 1 != xl[l]) ++bad;
                // the R328 seam:
                // attain(l) = high(l-1)
                int att = cavalierXpToAttain(l);
                if (l == 1) {
                    if (att != 0) ++bad;
                } else if (att != xh[l - 2]) {
                    ++bad;
                }
            }
            if (uacavtHorsemanXpLow() != cavalierHorsemanXp())
                ++bad;
            if (uacavtLancerXpLow() != cavalierLancerXp())
                ++bad;
        // ---- the dice column ----
            for (int l = 2; l <= 10; ++l) {
                if (uacavtLevelDiceCount(l) != l)
                    ++bad;
            }
            if (uacavtLevelDiceCount(11) != 10) ++bad;
            if (uacavtLevelDiceCount(12) != 10) ++bad;
            if (uacavtLevel11FlatHp() != uacavtHpPerLevelPast10())
                ++bad;
            if (uacavtLevel12FlatHp() != 2 * uacavtHpPerLevelPast10())
                ++bad;
            if (uacavtHpPerLevelPast10() != cavalierHpPerLevelPast10())
                ++bad;
        // ---- the titles ----
            static const char* const tn[14] = {
                "Horseman", "Lancer", "Armiger",
                "Scutifer", "Esquire", "Knight Errant",
                "Knight", "", "Grand Knight",
                "Banneret", "Chevalier", "Cavalier",
                "Cavalier, 11th", "Cavalier, 12th"};
            for (int i = 0; i < 14; ++i) {
                int l = (i == 0) ? 0 : (i == 1 ? -1 : i - 1);
                if (strcmp(uacavtTitle(l), tn[i]) != 0)
                    ++bad;
            }
            if (strcmp(uacavtTitle(13),
                    "Cavalier Commander") != 0)
                ++bad;
            if (uacavtCommanderLevel() != cavalierCommanderLevel())
                ++bad;
            if (uacavtXpPerLevelPast12() != cavalierXpPerLevelPast12())
                ++bad;
            // the R328 known-title seam
            for (int l = 1; l <= 10; ++l) {
                if (l == 5 || l == 6) continue;
                if (strcmp(uacavtTitle(l),
                        cavalierTitleKnown(l)) != 0)
                    ++bad;
            }
            // the newly readable 11th and
            // 12th cells (the R328 hole
            // record returns the empty
            // string - no seam check)
            if (uacavtTitle(11)[0] == 0)
                ++bad;
            if (uacavtTitle(12)[0] == 0)
                ++bad;
        printf("R368 UA Cavaliers Table I pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
