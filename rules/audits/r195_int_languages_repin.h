    // ---- R195: the INT languages repin audit ----
    // The printed INTELLIGENCE TABLE I additional-
    // languages column, cell for cell.
    {
        int bad = 0;
        // the printed column (3 through 18):
        // none through 7, then one per two scores
        // up to seven at 18
        static const int kLang[16] = {
            0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3,
            4, 4, 5, 6, 7
        };
        for (int i = 3; i <= 18; ++i) {
            if (rules::intExtraLanguages((uint8_t)i)
                != kLang[i - 3]) ++bad;
        }
        // the clamps read the edge rows
        if (rules::intExtraLanguages(0) != 0) ++bad;
        if (rules::intExtraLanguages(99) != 7) ++bad;
        // the historically divergent cells, the R177 read:
        // the engine convention gave a language at 4-5
        if (rules::intExtraLanguages(4) != 0) ++bad;
        if (rules::intExtraLanguages(6) != 0) ++bad;
        if (rules::intExtraLanguages(9) != 1) ++bad;
        if (rules::intExtraLanguages(17) != 6) ++bad;
        if (rules::intExtraLanguages(18) != 7) ++bad;
        printf("R195 INT languages repin audit: bad %d\n", bad);
        if (bad) return 1;
    }
