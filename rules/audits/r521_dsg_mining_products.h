    // ---- R521 DSG mining products audit ----
    // The DSG mining products pins the 1d100 products roll (the Table 30 nine
    // bands from copper 01-30 through mithril 99 and gemstones 00, the 00
    // band pinned as 100), the mithril possibility (the elven-chain-mail
    // material, a mine only deep under the earth in the most solid of
    // bedrock, the 1d10 Table 31 check with the Table 30 reroll otherwise,
    // silver/gold/platinum at highest quality on 1-5/6-8/9 and mithril on
    // 10), and the gemstone determination (the Table 32 eighteen bands -
    // bloodstone 01-08 from the physical book read, onyx through emerald,
    // 97-99 twice, 00 three times, the 97+ immediate recursion without limit,
    // the Jade-x2 duplicate doubling, and one quality level per stone type).
    {
        using namespace rules;
        int bad = 0;
    if (dnprT30RowCount() != 9
            || dnprT30Dice() != 1
            || dnprT30Sides() != 100
            || dnprMithrilCheckDice() != 1
            || dnprMithrilCheckSides() != 10
            || dnprT31RowCount() != 4
            || dnprT32RowCount() != 18
            || dnprT32ExtraRollThreshold() != 97
            || !dnprRollT30OnLocatingMinerals()
            || !dnprMithrilForElvenChainMail()
            || !dnprMithrilOnlyDeepSolidBedrock()
            || !dnprMithrilElseRerollT30()
            || !dnprT31MetalsHighestQuality()
            || !dnprT32ExtraRollsImmediate()
            || !dnprT32ExtraRollsNoLimit()
            || !dnprT32DuplicateDoublesYield()
            || !dnprT32OneQualityPerType()
        )
            ++bad;
        // the Table 30 mining products grid, the 1d100 products roll
        int C30[9][2] = {
            {1,30},
            {31,40},
            {41,66},
            {67,84},
            {85,92},
            {93,97},
            {98,98},
            {99,99},
            {100,100},
            };
        for (int b = 0;
             b < dnprT30RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnprT30Lo(b);
            vals[1] = dnprT30Hi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C30[b][c])
                    ++bad;
            }
        }
        // the Table 31 mithril check grid, the 1d10 deep-bedrock locale check
        int C31[4][2] = {
            {1,5},
            {6,8},
            {9,9},
            {10,10},
            };
        for (int b = 0;
             b < dnprT31RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnprT31Lo(b);
            vals[1] = dnprT31Hi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C31[b][c])
                    ++bad;
            }
        }
        // the Table 32 gemstones grid, the products-roll gemstone lookup
        int C32[18][2] = {
            {1,8},
            {9,18},
            {19,24},
            {25,30},
            {31,36},
            {37,42},
            {43,48},
            {49,54},
            {55,60},
            {61,66},
            {67,72},
            {73,77},
            {78,82},
            {83,87},
            {88,92},
            {93,96},
            {97,99},
            {100,100},
            };
        for (int b = 0;
             b < dnprT32RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnprT32Lo(b);
            vals[1] = dnprT32Hi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C32[b][c])
                    ++bad;
            }
        }
        // the products rolls: 1d100 on Table 30 when minerals are located,
        // the 1d10 mithril check, and the 97-or-greater gemstone threshold.
    if (dnprT30Dice() != 1
            || dnprT30Sides() != 100
            || dnprMithrilCheckDice() != 1
            || dnprMithrilCheckSides() != 10
            || dnprT32ExtraRollThreshold() != 97
        )
            ++bad;
        // the grid row counts: nine product bands, four mithril-check bands,
        // eighteen gemstone bands.
    if (dnprT30RowCount() != 9
            || dnprT31RowCount() != 4
            || dnprT32RowCount() != 18
        )
            ++bad;
        // the products prose: the roll-on-locate rule, the deep-solid-bedrock
        // mithril locale with the Table 30 reroll, the unlimited 97+
        // recursion, and the Jade-x2 duplicate doubling.
    if (dnprRollT30OnLocatingMinerals() != 1
            || dnprMithrilOnlyDeepSolidBedrock() != 1
            || dnprMithrilElseRerollT30() != 1
            || dnprT32ExtraRollsNoLimit() != 1
            || dnprT32DuplicateDoublesYield() != 1
        )
            ++bad;
        // Table 30 anchor rows: the 01-30 copper, the 93-97 gold, and the 00
        // gemstones band pinned as 100.
    if (dnprT30Lo(0) != 1
            || dnprT30Hi(0) != 30
            || dnprT30Lo(5) != 93
            || dnprT30Hi(5) != 97
            || dnprT30Lo(8) != 100
            || dnprT30Hi(8) != 100
        )
            ++bad;
        // Table 31 anchor rows: the 1-5 silver (highest quality) and the 10
        // mithril.
    if (dnprT31Lo(0) != 1
            || dnprT31Hi(0) != 5
            || dnprT31Lo(3) != 10
            || dnprT31Hi(3) != 10
        )
            ++bad;
        // Table 32 anchor rows: the 01-08 bloodstone (the physical-book
        // read), the 93-96 emerald, and the 97-99/00 extra-roll bands.
    if (dnprT32Lo(0) != 1
            || dnprT32Hi(0) != 8
            || dnprT32Lo(15) != 93
            || dnprT32Hi(15) != 96
            || dnprT32Lo(16) != 97
            || dnprT32Hi(16) != 99
            || dnprT32Lo(17) != 100
            || dnprT32Hi(17) != 100
        )
            ++bad;
        printf("R521 DSG mining products audit: bad %d\n", bad);
        if (bad) return 1;
    }
