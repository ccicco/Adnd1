    // ---- R122: treasure line-diff audit ---------------------------------
    // The R122 line-by-line diff against the printed tables (DMG
    // pp.121-125) found all 383 rows faithful; this audit pins what
    // was diffed so a future edit cannot drift silently: every
    // table's row count, every row's dice-band continuity (1..100,
    // no gaps or overlaps), and the famous rows - the errata
    // corrections (the treasure.h header list), the printed range
    // (Ring of Protection), the no-value rows (Delusion, Poison, the
    // Throne of the Gods), the twin "Hammer +2" rows printed as-is,
    // the bundle quantities (arrows, bolts), and the cursed shield.
    {
        int bad = 0;
        // printed row counts: III.A, III.B (structure: 16 spell
        // bands + 8 protection scrolls + 1 curse row), III.C-H,
        // then 12 = the Special artifact table
        static const int kRows[13] = { 35, 25, 24, 30, 33,
                                       30, 33, 36, 35, 26,
                                       26, 36, 29 };
        for (int c = 0; c <= 12; ++c) {
            if (dm::treasure::magicTablePinCount(c) != kRows[c])
                ++bad;
        }
        // dice-band continuity on every ItemRow table
        for (int c = 0; c <= 12; ++c) {
            if (c == 1) continue;      // III.B: no ItemRow rows
            dm::treasure::TablePin p, prev;
            int n = dm::treasure::magicTablePinCount(c);
            for (int i = 0; i < n; ++i) {
                if (!dm::treasure::magicTablePin(c, i, &p)) {
                    ++bad; break;
                }
                if (p.lo < 1 || p.hi < p.lo || p.hi > 100) ++bad;
                if (i == 0     && p.lo != 1)         ++bad;
                if (i > 0      && p.lo != prev.hi + 1) ++bad;
                if (i == n - 1 && p.hi != 100)       ++bad;
                prev = p;
            }
        }
        dm::treasure::TablePin p;
        // III.A edge rows: 01-03 Animal Control 250/400, the
        // no-xp Delusion (13-15, gp 150) and Poison (82-84, no
        // values at all), 98-00 Water Breathing 400/900
        if (!dm::treasure::magicTablePin(0, 0, &p)) ++bad;
        else if (p.lo != 1 || p.hi != 3 || p.xp != 250 ||
                 p.gp != 400 ||
                 std::string(p.name) != "Potion of Animal Control")
            ++bad;
        if (!dm::treasure::magicTablePin(0, 4, &p)) ++bad;
        else if (p.lo != 13 || p.hi != 15 || p.xp != 0 ||
                 p.gp != 150 ||
                 std::string(p.name) != "Potion of Delusion")
            ++bad;
        if (!dm::treasure::magicTablePin(0, 28, &p)) ++bad;
        else if (p.lo != 82 || p.hi != 84 || p.xp != 0 ||
                 p.gp != 0 ||
                 std::string(p.name) != "Potion of Poison") ++bad;
        if (!dm::treasure::magicTablePin(0, 34, &p)) ++bad;
        else if (p.lo != 98 || p.hi != 100 || p.xp != 400 ||
                 p.gp != 900 ||
                 std::string(p.name) != "Potion of Water Breathing")
            ++bad;
        // III.C: the printed range row (Ring of Protection
        // 45-60, xp 2,000-4,000, gp 10,000-20,000) and the 00 row
        if (!dm::treasure::magicTablePin(2, 11, &p)) ++bad;
        else if (p.lo != 45 || p.hi != 60 ||
                 p.xp != 2000 || p.xpHi != 4000 ||
                 p.gp != 10000 || p.gpHi != 20000 ||
                 std::string(p.name) != "Ring of Protection") ++bad;
        if (!dm::treasure::magicTablePin(2, 23, &p)) ++bad;
        else if (p.lo != 100 || p.hi != 100 || p.xp != 4000 ||
                 std::string(p.name) != "Ring of X-Ray Vision") ++bad;
        // III.E.5: the Robe/Rope errata rows
        if (!dm::treasure::magicTablePin(8, 1, &p)) ++bad;
        else if (p.lo != 2 || p.hi != 8 || p.xp != 3500 ||
                 std::string(p.name) != "Robe of Blending") ++bad;
        if (!dm::treasure::magicTablePin(8, 7, &p)) ++bad;
        else if (p.lo != 26 || p.hi != 27 || p.gp != 1000 ||
                 std::string(p.name) != "Rope of Constriction") ++bad;
        // Special: Heward's (printed Howard's), the valueless
        // Throne, and 00 Wand of Orcus
        if (!dm::treasure::magicTablePin(12, 8, &p)) ++bad;
        else if (p.lo != 26 || p.hi != 26 || p.gp != 25000 ||
                 std::string(p.name) != "Heward's Mystical Organ")
            ++bad;
        if (!dm::treasure::magicTablePin(12, 27, &p)) ++bad;
        else if (p.lo != 99 || p.gp != 0 ||
                 std::string(p.name) != "Throne of the Gods") ++bad;
        if (!dm::treasure::magicTablePin(12, 28, &p)) ++bad;
        else if (p.lo != 100 || p.hi != 100 || p.gp != 10000 ||
                 std::string(p.name) != "Wand of Orcus") ++bad;
        // III.G: the Flame Tongue row (46-49) and the cursed rows
        // with no sale value
        if (!dm::treasure::magicTablePin(10, 5, &p)) ++bad;
        else if (p.lo != 46 || p.hi != 49 || p.xp != 900 ||
                 p.gp != 4500 ||
                 std::string(p.name) != "Sword +1, Flame Tongue")
            ++bad;
        if (!dm::treasure::magicTablePin(10, 25, &p)) ++bad;
        else if (p.lo != 96 || p.hi != 100 || p.gp != 0 ||
                 std::string(p.name) !=
                     "Sword, Cursed Berserking") ++bad;
        // III.H: the twin Hammer +2 rows printed as-is, and the
        // bundle quantities (Arrow +1 2-24, Bolt +2 2-20)
        if (!dm::treasure::magicTablePin(11, 18, &p)) ++bad;
        else if (p.lo != 57 || p.hi != 60 || p.xp != 300 ||
                 p.gp != 2500 ||
                 std::string(p.name) != "Hammer +2") ++bad;
        if (!dm::treasure::magicTablePin(11, 19, &p)) ++bad;
        else if (p.lo != 61 || p.hi != 62 || p.xp != 650 ||
                 p.gp != 6000 ||
                 std::string(p.name) != "Hammer +2") ++bad;
        if (!dm::treasure::magicTablePin(11, 0, &p)) ++bad;
        else if (p.qtyLo != 2 || p.qtyHi != 24 ||
                 std::string(p.name) != "Arrow +1") ++bad;
        if (!dm::treasure::magicTablePin(11, 9, &p)) ++bad;
        else if (p.qtyLo != 2 || p.qtyHi != 20 ||
                 std::string(p.name) != "Bolt +2") ++bad;
        // III.F: the cursed shield (98-00, no xp, gp 750)
        if (!dm::treasure::magicTablePin(9, 25, &p)) ++bad;
        else if (p.lo != 98 || p.hi != 100 || p.xp != 0 ||
                 p.gp != 750 ||
                 std::string(p.name) != "Shield -1, missile attractor")
            ++bad;
        printf("R122 treasure line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }
