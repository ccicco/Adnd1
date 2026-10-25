    // ---- R183: the illusionist spell layer audit ----
    // Every printed slot cell of the 26x7 table, every
    // roster row, the per-level counts and name spot-
    // checks from the print.
    {
        int bad = 0;
        // the full slots table, cell by cell
        static const int kSlots[26][7] = {
            { 1, 0, 0, 0, 0, 0, 0 },
            { 2, 0, 0, 0, 0, 0, 0 },
            { 2, 1, 0, 0, 0, 0, 0 },
            { 3, 2, 0, 0, 0, 0, 0 },
            { 4, 2, 1, 0, 0, 0, 0 },
            { 4, 3, 1, 0, 0, 0, 0 },
            { 4, 3, 2, 0, 0, 0, 0 },
            { 4, 3, 2, 1, 0, 0, 0 },
            { 5, 3, 3, 2, 0, 0, 0 },
            { 5, 4, 3, 2, 1, 0, 0 },
            { 5, 4, 3, 3, 2, 0, 0 },
            { 5, 5, 4, 3, 2, 1, 0 },
            { 5, 5, 4, 3, 2, 2, 0 },
            { 5, 5, 4, 3, 2, 2, 1 },
            { 5, 5, 4, 4, 2, 2, 2 },
            { 5, 5, 5, 4, 3, 2, 2 },
            { 5, 5, 5, 5, 3, 2, 2 },
            { 5, 5, 5, 5, 3, 3, 2 },
            { 5, 5, 5, 5, 4, 3, 2 },
            { 5, 5, 5, 5, 4, 3, 3 },
            { 5, 5, 5, 5, 5, 4, 3 },
            { 5, 5, 5, 5, 5, 5, 4 },
            { 5, 5, 5, 5, 5, 5, 5 },
            { 6, 6, 6, 6, 5, 5, 5 },
            { 6, 6, 6, 6, 6, 6, 6 },
            { 7, 7, 7, 7, 6, 6, 6 },
        };
        for (int il = 1; il <= 26; ++il)
            for (int sl = 1; sl <= 7; ++sl)
                if (rules::illusionistSpellSlots(il, sl)
                    != kSlots[il-1][sl-1]) ++bad;
        // the clamps: level 0 and 99 read level 1 and 26;
        // spell level 0 and 99 read 1 and 7
        if (rules::illusionistSpellSlots(0, 1) != 1) ++bad;
        if (rules::illusionistSpellSlots(99, 7) != 6) ++bad;
        if (rules::illusionistSpellSlots(26, 8) != 6) ++bad;
        if (rules::illusionistSpellSlots(1, 0) != 1) ++bad;
        // the roster: 61 rows, every level
        if (rules::illusionistSpellTotal() != 61) ++bad;
        int byLevel[8] = { 0, 0, 0, 0,  0, 0, 0, 0 };
        for (int i = 0; i < 61; ++i) {
            const rules::IllusionistSpell& s =
                rules::illusionistSpell(i);
            if (s.level < 1 || s.level > 7) ++bad;
            byLevel[s.level] += 1;
        }
        // the printed per-level counts 8/16/11/5/12/4/5
        if (byLevel[1] != 8 || byLevel[2] != 16
            || byLevel[3] != 11 || byLevel[4] != 5) ++bad;
        if (byLevel[5] != 12 || byLevel[6] != 4
            || byLevel[7] != 5) ++bad;
        for (int sl = 1; sl <= 7; ++sl) {
            int want = (sl == 1) ? 8
                : ((sl == 2) ? 16 : ((sl == 3) ? 11
                : ((sl == 4) ? 5 : ((sl == 5) ? 12
                : ((sl == 6) ? 4 : 5)))));
            if (rules::illusionistSpellCountByLevel(sl)
                != want) ++bad;
        }
        // name spot-checks (the print, the book order)
        if (std::string(rules::illusionistSpell(0).name)
            != "Audible Glamer") ++bad;
        if (std::string(rules::illusionistSpell(7).name)
            != "Wall Of Fog") ++bad;
        if (std::string(rules::illusionistSpell(8).name)
            != "Blindness") ++bad;
        if (std::string(rules::illusionistSpell(23).name)
            != "Ventriloquism") ++bad;
        if (std::string(rules::illusionistSpell(24).name)
            != "Invisibility, 10' Radius") ++bad;
        if (std::string(rules::illusionistSpell(34).name)
            != "Massmorph") ++bad;
        if (std::string(rules::illusionistSpell(39).name)
            != "Shadow Monsters") ++bad;
        if (std::string(rules::illusionistSpell(51).name)
            != "Shades") ++bad;
        if (std::string(rules::illusionistSpell(55).name)
            != "Veil") ++bad;
        if (std::string(rules::illusionistSpell(60).name)
            != "Vision") ++bad;
        // roster index spot-probes: level-1 rows 0-7,
        // level-2 8-23, level-3 24-34, level-4 35-39,
        // level-5 40-51, level-6 52-55, level-7 56-60
        if (rules::illusionistSpell(8).level != 2) ++bad;
        if (rules::illusionistSpell(24).level != 3) ++bad;
        if (rules::illusionistSpell(35).level != 4) ++bad;
        if (rules::illusionistSpell(40).level != 5) ++bad;
        if (rules::illusionistSpell(52).level != 6) ++bad;
        if (rules::illusionistSpell(56).level != 7) ++bad;
        printf("R183 illusionist spell layer audit: bad %d\n", bad);
        if (bad) return 1;
    }
