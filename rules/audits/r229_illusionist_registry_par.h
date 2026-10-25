    // ---- R229: the illusionist registry parameters audit ----
    // The evaluable seam walk: the rules/illusionspells.h
    // R229 parameter tables vs the book-pin arrays (the
    // PHB illusionist spell description headers; the
    // OCR-scattered blocks pinned as JUDGMENTs). The
    // registry rows themselves are walked by the extended
    // R80 battery block - spells.cpp structs are outside
    // the audit_eval subset.
    {
        int bad = 0;
        static const int kLv[61] = {
            1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 4, 4, 4, 4, 4,
            5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
            5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
            7,
        };
        static const int kCt[61] = {
            5, 1, 1, 1, 1, 1, 1, 1, 2, 2,
            2, 2, 2, 2, 2, 2, 3, 2, 4, 2,
            50, 2, 0, 2, 3, 3, 3, 3, 3, 3,
            3, 3, 4, 3, 4, 4, 4, 60, 4, 4,
            5, 5, 60, 5, 5, 6, 2, 6, 5, 6,
            5, 6, 9, 10, 5, 3, 0, 180, 7, 7,
            7,
        };
        static const int kRg[61] = {
            6, 1, 0, 0, 3, 6, 6, 3, 3, 0,
            6, 0, 1, 0, 6, 0, 1, 0, 0, 0,
            2, 3, 0, 1, 0, 6, 6, 0, 1, 1,
            0, 6, 0, 3, 1, 8, 0, 0, 0, 3,
            0, 3, 1, 0, 0, 3, 1, 1, 5, 1,
            1, 3, 3, 0, 6, 1, 0, 0, 0, 1,
            0,
        };
        static const int kDu[61] = {
            3, 5, 2, 1, 1, 10, 0, 2, 0, 3,
            0, 2, 4, 0, 0, 0, 0, 0, 0, 3,
            0, 1, 0, 4, 0, 0, 0, 10, 0, 0,
            20, 0, 4, 40, 0, 1, 30, 60, 1, 1,
            1, 1, 60, 0, 1, 40, 40, 0, 0, 0,
            1, 1, 1, 1, 0, 10, 0, 0, 0, 10,
            0,
        };
        static const int kAo[61] = {
            0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 3, 6, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0,
        };
        static const int kSv[61] = {
            -1, -1, -1, -1, 4, -1, -1, -1, 4, -1,
            4, -1, -1, 4, -1, -1, -1, -1, 4, -1,
            -1, 4, -1, -1, -1, -1, -1, -1, 4, 4,
            -1, -1, -1, 4, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, 4, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1,
        };
        static const int kTg[61] = {
            4, 2, 0, 4, 3, 2, 2, 4, 1, 0,
            1, 2, 2, 2, 2, 1, 4, 4, 2, 0,
            2, 4, 1, 4, 2, 2, 2, 0, 2, 2,
            4, 2, 1, 1, 2, 2, 3, 4, 1, 2,
            2, 2, 4, 1, 4, 3, 4, 2, 4, 2,
            2, 2, 4, 1, 4, 2, 0, 4, 2, 4,
            0,
        };
        for (int i = 0; i < 61; ++i)
            if (rules::illusionistSpellLevel(i) != kLv[i] ||
                rules::illusionistSpellCt(i) != kCt[i] ||
                rules::illusionistSpellRangeTens(i) != kRg[i] ||
                rules::illusionistSpellDur(i) != kDu[i] ||
                rules::illusionistSpellAoeTens(i) != kAo[i] ||
                rules::illusionistSpellSaveCat(i) != kSv[i] ||
                rules::illusionistSpellTarget(i) != kTg[i]) ++bad;
        // the clamps: -5 and 99 read rows 0 and 60
        if (rules::illusionistSpellLevel(-5) != kLv[0] ||
            rules::illusionistSpellLevel(99) != kLv[60] ||
            rules::illusionistSpellCt(99) != kCt[60]) ++bad;
        // the level histogram ladder: the seam pins the
        // printed roster counts (8/16/11/5/12/4/5 - R183);
        // every seam level sits in 1..7
        static const int kHist[7] = { 8, 16, 11, 5, 12, 4, 5 };
        for (int l = 1; l <= 7; ++l)
            if (rules::illusionistSpellCountByLevel(l) != kHist[l - 1]) ++bad;
        for (int i = 0; i < 61; ++i)
            if (rules::illusionistSpellLevel(i) < 1 ||
                rules::illusionistSpellLevel(i) > 7) ++bad;
        // the R183 slot table cross-checks (past 26 the
        // table clamps to the 26th row; a spell-level 8
        // query clamps to the 7th)
        if (rules::illusionistSpellSlots(1, 1) != 1 ||
            rules::illusionistSpellSlots(5, 2) != 2 ||
            rules::illusionistSpellSlots(12, 4) != 3 ||
            rules::illusionistSpellSlots(26, 7) != 6 ||
            rules::illusionistSpellSlots(30, 8) != 6) ++bad;
        printf("R229 illusionist registry parameters audit: bad %d\n", bad);
        if (bad) return 1;
    }
