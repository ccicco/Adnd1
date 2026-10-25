    // ---- R745 OA Table 76 properties audit ----
    // OA round one hundred thirty-two (capture pp. 289-290): the Table 76
    // Magical Armor Properties - the seven d100 bands of the quality and plus
    // properties with the armor-piece +1 clause, the special property reroll
    // on the Table 77, the no-special-property footnote, the caption printing
    // a period, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlgPropRowCount() != 7
            || dlgPiecePlus() != 1
            || !dlgCaptionPeriod()
            || !dlgQualityAsterisk()
            || !dlgSpecialRerollTable77()
            || !dlgFootnoteNoSpecialProperty()
        )
            ++bad;
        // the dlgArmorProps grid
        int CArmorProps[7][3] = {
            {1,40,0},
            {41,65,1},
            {66,80,2},
            {81,85,3},
            {86,88,4},
            {89,90,5},
            {91,100,6},
            };
        int nArmorProps[3] = {0,0,0};
        int eArmorProps[3] = {0,0,1};
        for (int b = 0;
             b < dlgPropRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlgPropRollMin(b);
            vals[1] = dlgPropRollMax(b);
            vals[2] = dlgPropPlus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CArmorProps[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nArmorProps[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nArmorProps[c] != eArmorProps[c])
                ++bad;
        // the grid - the seven-band Table 76, audited cell by cell by the
        // table audit
    if (dlgPropRowCount() != 7
            || dlgPropRollMin(0) != 1
            || dlgPropRollMax(6) != 100
            || dlgPropPlus(0) != 0
            || dlgPropPlus(6) != 6
        )
            ++bad;
        // the caption quirk, the footnote, and the piece plus, healthy
        // values, each condition false
    if (dlgCaptionPeriod() != 1
            || dlgQualityAsterisk() != 1
            || dlgSpecialRerollTable77() != 1
            || dlgFootnoteNoSpecialProperty() != 1
            || dlgPiecePlus() != 1
        )
            ++bad;
        printf("R745 OA Table 76 properties audit: bad %d\n", bad);
        if (bad) return 1;
    }
