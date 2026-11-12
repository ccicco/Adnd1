    // ---- R880 DDG promotion audit ----
    // THE DDG LUA PROMOTION, BATCH ONE - the first promotion round: 55
    // full-field defs (American Indian 14, Arthurian 15, Babylonian 10,
    // Celtic 16) generated only from the adjudicated pin headers, the
    // registry floor 995 -> 1050, the normalize_registry.py book_of patch and
    // the engine makedirs (the R851 lesson).
    {
        using namespace rules;
        int bad = 0;
    if (dpeRound() != 880
            || dpeCensusBefore() != 802
            || dpeCensusAfter() != 803
            || dpeDefs() != 55
            || dpeMythoi() != 4
            || dpeFloorBefore() != 995
            || dpeFloorAfter() != 1050
            || dpeFullFieldKeys() != 57
            || dpeClassGridCols() != 10
            || dpeAbilityGridCols() != 9
            || dpePinnedDamage() != 8
            || dpeSeeBelowCode() != 99
            || !dpePromotionBatchOne()
            || !dpeFromHeadersOnly()
            || !dpeNameOrdersLocked()
            || !dpeFullFieldDdg()
            || !dpeSentinelsDistinct()
            || !dpeProseContractSide()
            || !dpeDamagePinnedOnly()
            || !dpeSymbolsUnpinned()
            || !dpeNormalizerDdgAware()
            || !dpeEngineMakedirs()
        )
            ++bad;
        // the the batch-one mythos grid grid
        int CdpeMyth[4][4] = {
            {0,12,16,14},
            {1,17,21,15},
            {2,22,25,10},
            {3,26,31,16},
            };
        for (int b = 0;
             b < dpeMythoi();
             ++b) {
            int vals[4];
            vals[0] = dpeMythOrd(b);
            vals[1] = dpeMythPageLo(b);
            vals[2] = dpeMythPageHi(b);
            vals[3] = dpeMythDefs(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CdpeMyth[b][c])
                    ++bad;
            }
        }
        // the the DDG key-fill grid grid
        int CdpeKeyFill[57][2] = {
            {0,55},
            {1,55},
            {2,55},
            {3,55},
            {4,55},
            {5,55},
            {6,55},
            {7,55},
            {8,55},
            {9,55},
            {10,55},
            {11,55},
            {12,55},
            {13,55},
            {14,55},
            {15,55},
            {16,55},
            {17,55},
            {18,55},
            {19,55},
            {20,55},
            {21,55},
            {22,55},
            {23,55},
            {24,55},
            {25,55},
            {26,55},
            {27,55},
            {28,55},
            {29,55},
            {30,55},
            {31,55},
            {32,55},
            {33,55},
            {34,55},
            {35,55},
            {36,55},
            {37,55},
            {38,55},
            {39,55},
            {40,55},
            {41,55},
            {42,55},
            {43,55},
            {44,55},
            {45,55},
            {46,55},
            {47,55},
            {48,55},
            {49,55},
            {50,55},
            {51,55},
            {52,55},
            {53,55},
            {54,55},
            {55,55},
            {56,55},
            };
        for (int b = 0;
             b < dpeFullFieldKeys();
             ++b) {
            int vals[2];
            vals[0] = dpeKeyOrd(b);
            vals[1] = dpeKeyDdgCount(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CdpeKeyFill[b][c])
                    ++bad;
            }
        }
        // the round walk (the promotion batch one, the census step)
    if (dpeRound() != 880
            || dpeCensusBefore() != 802
            || dpeCensusAfter() != 803
        )
            ++bad;
        // the registry floor (the first growth since the 995 floor)
    if (dpeFloorBefore() != 995
            || dpeFloorAfter() != 1050
            || dpeDefs() != 55
            || dpeFullFieldKeys() != 57
        )
            ++bad;
        // the mythos walk (the print pages, the def counts)
    if (dpeMythPageLo(0) != 12
            || dpeMythPageHi(0) != 16
            || dpeMythDefs(0) != 14
            || dpeMythDefs(1) != 15
            || dpeMythDefs(2) != 10
            || dpeMythDefs(3) != 16
            || dpeMythPageHi(3) != 31
            || dpeMythOrd(3) != 3
        )
            ++bad;
        // the key-fill (every DDG def full-field, all 57 keys)
    if (dpeKeyDdgCount(0) != 55
            || dpeKeyDdgCount(56) != 55
            || dpeKeyOrd(56) != 56
            || dpeKeyOrd(0) != 0
        )
            ++bad;
        // the doctrine (the headers-only, the sentinel and prose bools)
    if (dpeFromHeadersOnly() != 1
            || dpeNameOrdersLocked() != 1
            || dpeFullFieldDdg() != 1
            || dpeSentinelsDistinct() != 1
            || dpeProseContractSide() != 1
        )
            ++bad;
        // the honest boundaries (the unpinned figures and symbols stay
        // sentinel)
    if (dpeDamagePinnedOnly() != 1
            || dpeSymbolsUnpinned() != 1
            || dpePinnedDamage() != 8
            || dpeSeeBelowCode() != 99
        )
            ++bad;
        // the tooling (the DDG-aware normalizer, the engine makedirs)
    if (dpeNormalizerDdgAware() != 1
            || dpeEngineMakedirs() != 1
            || dpeClassGridCols() != 10
            || dpeAbilityGridCols() != 9
        )
            ++bad;
        printf("R880 DDG promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
