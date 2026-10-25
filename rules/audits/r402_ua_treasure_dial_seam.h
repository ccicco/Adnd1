    // ---- R402: the UA treasure
    // dial seam audit ----
    // The R374 decision wires: the
    // dial state (DMG the default,
    // UA, MERGED), the UA-mode
    // determination dispatch (the
    // R375/R395 data rides the
    // engine roller - the category
    // bands, the sub-table splits,
    // the misc seven sub-bands, the
    // row resolution), and the
    // MERGED union read. The DMG
    // audits stay authoritative
    // (the default mode); census
    // 328 -> 329.
    {
        using namespace rules;
        int bad = 0;
        // ---- the dial state ----
        if (uatdMode() != uatdModeDmg()) ++bad;
        if (strcmp(uatdModeName(0),
                   "DMG") != 0) ++bad;
        if (strcmp(uatdModeName(1),
                   "UA") != 0) ++bad;
        if (strcmp(uatdModeName(2),
                   "MERGED") != 0) ++bad;
        if (!uatdModeValid(0)
                || !uatdModeValid(2)) ++bad;
        if (uatdModeValid(3)
                || uatdModeValid(-1)) ++bad;
        uatdSetMode(uatdModeUa());
        if (uatdMode() != uatdModeUa()) ++bad;
        uatdSetMode(99);
        if (uatdMode() != uatdModeDmg()) ++bad;
        if (uatdUaPinRoundsPending()) ++bad;
        if (!uatdDialLanded()) ++bad;
        // ---- the UA row data ----
        // every table covers 01-00
        // contiguously (the band walk)
        for (int t = 0;
             t < uadrowTableCount(); ++t) {
            if (uadrowRowLo(t, 0) != 1) ++bad;
            if (uadrowRowHi(t,
                    uadrowRowCount(t) - 1)
                    != 100) ++bad;
            for (int i = 0;
                 i + 1 < uadrowRowCount(t);
                 ++i)
                if (uadrowRowLo(t, i + 1)
                        != uadrowRowHi(t, i) + 1)
                    ++bad;
        }
        // the spot rows (the R395 pins)
        if (strcmp(uadrowRowName(0, 0),
                   "Animal Control") != 0) ++bad;
        if (strcmp(uadrowRowName(17, 0),
                   "Sword + 1") != 0) ++bad;
        if (strcmp(uadrowRowName(6, 0),
                   "Rod of Absorption") != 0)
            ++bad;
        if (strcmp(uadrowRowName(19, 0),
                   "Arrow + 1, 2-24 in number")
                != 0) ++bad;
        // ---- the UA-mode dispatch ----
        // statistical: every category
        // serves, the misc always the
        // UA sub-tables
        rules::Rng rngUa(402);
        rules::Dice diceUa(rngUa);
        uatdSetMode(uatdModeUa());
        int uaPot = 0, uaMisc = 0;
        for (int i = 0; i < 20000; ++i) {
            dm::treasure::MagicItem m =
                dm::treasure::rollMagicItem(
                    diceUa);
            if (m.name.empty()
                    || m.category < 0
                    || m.category > 11) ++bad;
            if (m.category == 0) ++uaPot;
            if (m.category == 8) ++uaMisc;
        }
        if (uaPot == 0 || uaMisc == 0) ++bad;
        // the potion band is 20 percent,
        // the misc band 15 - loose
        // bounds catch the routing
        if (uaPot < 1000
                || uaPot > 9000) ++bad;
        if (uaMisc < 1000
                || uaMisc > 9000) ++bad;
        // ---- the MERGED union ----
        rules::Rng rngM(403);
        rules::Dice diceM(rngM);
        uatdSetMode(uatdModeMerged());
        for (int i = 0; i < 20000; ++i) {
            dm::treasure::MagicItem m =
                dm::treasure::rollMagicItem(
                    diceM);
            if (m.name.empty()
                    || m.category < 0
                    || m.category > 11) ++bad;
        }
        // ---- the DMG default restores ----
        uatdSetMode(uatdModeDmg());
        if (uatdMode() != uatdModeDmg()) ++bad;
        printf("R402 UA treasure dial seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
