    // ---- R182: the druid spell layer audit ----
    // Every printed slot cell of the 14x7 table, every
    // roster row, the per-level counts, the reversible
    // flags and name spot-checks from the print.
    {
        int bad = 0;
        // the full slots table, cell by cell
        static const int kSlots[14][7] = {
            { 2, 0, 0, 0, 0, 0, 0 },
            { 2, 1, 0, 0, 0, 0, 0 },
            { 3, 2, 1, 0, 0, 0, 0 },
            { 4, 2, 2, 0, 0, 0, 0 },
            { 4, 3, 2, 0, 0, 0, 0 },
            { 4, 3, 2, 1, 0, 0, 0 },
            { 4, 4, 3, 1, 0, 0, 0 },
            { 4, 4, 3, 2, 0, 0, 0 },
            { 5, 4, 3, 2, 1, 0, 0 },
            { 5, 4, 3, 3, 2, 0, 0 },
            { 5, 5, 3, 3, 2, 1, 0 },
            { 5, 5, 4, 4, 3, 2, 1 },
            { 6, 5, 5, 5, 4, 3, 2 },
            { 6, 6, 6, 6, 5, 4, 3 },
        };
        for (int dl = 1; dl <= 14; ++dl)
            for (int sl = 1; sl <= 7; ++sl)
                if (rules::druidSpellSlots(dl, sl)
                    != kSlots[dl-1][sl-1]) ++bad;
        // the clamps: level 0 and 99 read level 1 and 14;
        // spell level 0 and 99 read 1 and 7
        if (rules::druidSpellSlots(0, 1) != 2) ++bad;
        if (rules::druidSpellSlots(99, 7) != 3) ++bad;
        if (rules::druidSpellSlots(14, 8) != 3) ++bad;
        if (rules::druidSpellSlots(1, 0) != 2) ++bad;
        // the roster: 77 rows, every level and flag
        if (rules::druidSpellTotal() != 77) ++bad;
        int byLevel[8] = { 0, 0, 0, 0,  0, 0, 0, 0 };
        int revCount = 0;
        for (int i = 0; i < 77; ++i) {
            const rules::DruidSpell& s =
                rules::druidSpell(i);
            if (s.level < 1 || s.level > 7) ++bad;
            if (s.reversible != 0 && s.reversible != 1) ++bad;
            byLevel[s.level] += 1;
            revCount += s.reversible;
        }
        // the printed per-level counts 12/12/12/12/8/12/9
        if (byLevel[1] != 12 || byLevel[2] != 12
            || byLevel[3] != 12 || byLevel[4] != 12) ++bad;
        if (byLevel[5] != 8 || byLevel[6] != 12
            || byLevel[7] != 9) ++bad;
        // 16 printed reversible spells
        if (revCount != 16) ++bad;
        for (int sl = 1; sl <= 7; ++sl) {
            int want = (sl == 5) ? 8
                : ((sl == 7) ? 9 : 12);
            if (rules::druidSpellCountByLevel(sl)
                != want) ++bad;
        }
        // name and flag spot-checks (the print)
        if (std::string(rules::druidSpell(0).name)
            != "Animal Friendship") ++bad;
        if (std::string(rules::druidSpell(9).name)
            != "Purify Water") ++bad;
        if (rules::druidSpell(9).reversible != 1) ++bad;
        if (std::string(rules::druidSpell(38).name)
            != "Control Temperature, 10' Radius") ++bad;
        if (std::string(rules::druidSpell(34).name)
            != "Tree") ++bad;
        if (std::string(rules::druidSpell(71).name)
            != "Chariot Of Sustarre") ++bad;
        if (std::string(rules::druidSpell(76).name)
            != "Transmute Metal To Wood") ++bad;
        if (rules::druidSpell(76).level != 7) ++bad;
        if (rules::druidSpell(69).reversible != 1) ++bad;
        // roster index spot-probes: level-1 rows 0-11,
        // level-2 rows 12-23, level-3 24-35, level-4
        // 36-47, level-5 48-55, level-6 56-67, level-7 68-76
        if (rules::druidSpell(12).level != 2) ++bad;
        if (rules::druidSpell(36).level != 4) ++bad;
        if (rules::druidSpell(48).level != 5) ++bad;
        if (rules::druidSpell(56).level != 6) ++bad;
        if (rules::druidSpell(68).level != 7) ++bad;
        printf("R182 druid spell layer audit: bad %d\n", bad);
        if (bad) return 1;
    }
