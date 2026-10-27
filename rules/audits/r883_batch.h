    // ---- R883 DDG promotion audit ----
    // THE DDG LUA PROMOTION, BATCH FOUR - the fourth promotion round: 31
    // full-field defs (Indian 18, Japanese 13) generated only from the
    // adjudicated pin headers, the registry floor 1178 -> 1209, the census
    // refresh and the batch-four honest boundaries (the fixed-points damage
    // cells of Ama-Tsu-Mara, Daikoku and Tsukiyomi, the buffalo shoulder
    // size, the Susanowo and Kishijoten move slashes, the unpinned lair
    // percents, worshipper alignments and symbols stay sentinel).
    {
        using namespace rules;
        int bad = 0;
    if (dpwRound() != 883
            || dpwCensusBefore() != 805
            || dpwCensusAfter() != 806
            || dpwDefs() != 31
            || dpwMythoi() != 2
            || dpwFloorBefore() != 1178
            || dpwFloorAfter() != 1209
            || dpwFullFieldKeys() != 57
            || dpwMonsterRows() != 5
            || dpwHitDiceRows() != 0
            || dpwPinnedDamage() != 26
            || dpwSeeBelowCode() != 99
            || !dpwPromotionBatchFour()
            || !dpwFromHeadersOnly()
            || !dpwNameOrdersLocked()
            || !dpwFullFieldDdg()
            || !dpwSentinelsDistinct()
            || !dpwProseContractSide()
            || !dpwDamagePinnedOnly()
            || !dpwSymbolsUnpinned()
            || !dpwWorshipUnpinned()
            || !dpwNormalizerDdgAware()
        )
            ++bad;
        // the the batch-four mythos grid grid
        int CdpwMyth[2][4] = {
            {0,75,80,18},
            {1,81,85,13},
            };
        for (int b = 0;
             b < dpwMythoi();
             ++b) {
            int vals[4];
            vals[0] = dpwMythOrd(b);
            vals[1] = dpwMythPageLo(b);
            vals[2] = dpwMythPageHi(b);
            vals[3] = dpwMythDefs(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CdpwMyth[b][c])
                    ++bad;
            }
        }
        // the the DDG key-fill grid grid
        int CdpwKeyFill[57][2] = {
            {0,31},
            {1,31},
            {2,31},
            {3,31},
            {4,31},
            {5,31},
            {6,31},
            {7,31},
            {8,31},
            {9,31},
            {10,31},
            {11,31},
            {12,31},
            {13,31},
            {14,31},
            {15,31},
            {16,31},
            {17,31},
            {18,31},
            {19,31},
            {20,31},
            {21,31},
            {22,31},
            {23,31},
            {24,31},
            {25,31},
            {26,31},
            {27,31},
            {28,31},
            {29,31},
            {30,31},
            {31,31},
            {32,31},
            {33,31},
            {34,31},
            {35,31},
            {36,31},
            {37,31},
            {38,31},
            {39,31},
            {40,31},
            {41,31},
            {42,31},
            {43,31},
            {44,31},
            {45,31},
            {46,31},
            {47,31},
            {48,31},
            {49,31},
            {50,31},
            {51,31},
            {52,31},
            {53,31},
            {54,31},
            {55,31},
            {56,31},
            };
        for (int b = 0;
             b < dpwFullFieldKeys();
             ++b) {
            int vals[2];
            vals[0] = dpwKeyOrd(b);
            vals[1] = dpwKeyDdgCount(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CdpwKeyFill[b][c])
                    ++bad;
            }
        }
        // the round walk (the promotion batch four, the census step)
    if (dpwRound() != 883
            || dpwCensusBefore() != 805
            || dpwCensusAfter() != 806
        )
            ++bad;
        // the floor walk
    if (dpwFloorBefore() != 1178
            || dpwFloorAfter() != 1209
            || dpwDefs() != 31
            || dpwFullFieldKeys() != 57
        )
            ++bad;
        // the mythos grid walk
    if (dpwMythPageLo(0) != 75
            || dpwMythPageHi(0) != 80
            || dpwMythDefs(0) != 18
            || dpwMythDefs(1) != 13
            || dpwMythPageLo(1) != 81
            || dpwMythPageHi(1) != 85
            || dpwMythOrd(1) != 1
        )
            ++bad;
        // the key-fill walk
    if (dpwKeyDdgCount(0) != 31
            || dpwKeyDdgCount(56) != 31
            || dpwKeyOrd(56) != 56
            || dpwKeyOrd(0) != 0
        )
            ++bad;
        // the doctrine walk
    if (dpwFromHeadersOnly() != 1
            || dpwNameOrdersLocked() != 1
            || dpwFullFieldDdg() != 1
            || dpwSentinelsDistinct() != 1
            || dpwProseContractSide() != 1
        )
            ++bad;
        // the boundary walk
    if (dpwDamagePinnedOnly() != 1
            || dpwSymbolsUnpinned() != 1
            || dpwWorshipUnpinned() != 1
            || dpwPinnedDamage() != 26
            || dpwSeeBelowCode() != 99
        )
            ++bad;
        // the shape walk
    if (dpwMonsterRows() != 5
            || dpwHitDiceRows() != 0
            || dpwNormalizerDdgAware() != 1
            || dpwPromotionBatchFour() != 1
        )
            ++bad;
        printf("R883 DDG promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
