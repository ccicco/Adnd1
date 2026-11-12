    // ---- R882 DDG promotion audit ----
    // THE DDG LUA PROMOTION, BATCH THREE - the third promotion round: 60
    // full-field defs (Finnish 20, Greek 40) generated only from the
    // adjudicated pin headers, the registry floor 1118 -> 1178, the census
    // refresh and the batch-three honest boundaries (the Apollo and Poseidon
    // damage cells garbled or worded in both voices, the unpinned lair
    // percents, worshipper alignments, symbols and the klv ranger lines stay
    // sentinel).
    {
        using namespace rules;
        int bad = 0;
    if (dpuRound() != 882
            || dpuCensusBefore() != 804
            || dpuCensusAfter() != 805
            || dpuDefs() != 60
            || dpuMythoi() != 2
            || dpuFloorBefore() != 1118
            || dpuFloorAfter() != 1178
            || dpuFullFieldKeys() != 57
            || dpuMonsterRows() != 7
            || dpuHitDiceRows() != 2
            || dpuPinnedDamage() != 44
            || dpuSeeBelowCode() != 99
            || !dpuPromotionBatchThree()
            || !dpuFromHeadersOnly()
            || !dpuNameOrdersLocked()
            || !dpuFullFieldDdg()
            || !dpuSentinelsDistinct()
            || !dpuProseContractSide()
            || !dpuDamagePinnedOnly()
            || !dpuSymbolsUnpinned()
            || !dpuWorshipUnpinned()
            || !dpuNormalizerDdgAware()
        )
            ++bad;
        // the the batch-three mythos grid grid
        int CdpuMyth[2][4] = {
            {0,57,62,20},
            {1,63,74,40},
            };
        for (int b = 0;
             b < dpuMythoi();
             ++b) {
            int vals[4];
            vals[0] = dpuMythOrd(b);
            vals[1] = dpuMythPageLo(b);
            vals[2] = dpuMythPageHi(b);
            vals[3] = dpuMythDefs(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CdpuMyth[b][c])
                    ++bad;
            }
        }
        // the the DDG key-fill grid grid
        int CdpuKeyFill[57][2] = {
            {0,60},
            {1,60},
            {2,60},
            {3,60},
            {4,60},
            {5,60},
            {6,60},
            {7,60},
            {8,60},
            {9,60},
            {10,60},
            {11,60},
            {12,60},
            {13,60},
            {14,60},
            {15,60},
            {16,60},
            {17,60},
            {18,60},
            {19,60},
            {20,60},
            {21,60},
            {22,60},
            {23,60},
            {24,60},
            {25,60},
            {26,60},
            {27,60},
            {28,60},
            {29,60},
            {30,60},
            {31,60},
            {32,60},
            {33,60},
            {34,60},
            {35,60},
            {36,60},
            {37,60},
            {38,60},
            {39,60},
            {40,60},
            {41,60},
            {42,60},
            {43,60},
            {44,60},
            {45,60},
            {46,60},
            {47,60},
            {48,60},
            {49,60},
            {50,60},
            {51,60},
            {52,60},
            {53,60},
            {54,60},
            {55,60},
            {56,60},
            };
        for (int b = 0;
             b < dpuFullFieldKeys();
             ++b) {
            int vals[2];
            vals[0] = dpuKeyOrd(b);
            vals[1] = dpuKeyDdgCount(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CdpuKeyFill[b][c])
                    ++bad;
            }
        }
        // the round walk (the promotion batch three, the census step)
    if (dpuRound() != 882
            || dpuCensusBefore() != 804
            || dpuCensusAfter() != 805
        )
            ++bad;
        // the floor walk
    if (dpuFloorBefore() != 1118
            || dpuFloorAfter() != 1178
            || dpuDefs() != 60
            || dpuFullFieldKeys() != 57
        )
            ++bad;
        // the mythos grid walk
    if (dpuMythPageLo(0) != 57
            || dpuMythPageHi(0) != 62
            || dpuMythDefs(0) != 20
            || dpuMythDefs(1) != 40
            || dpuMythPageLo(1) != 63
            || dpuMythPageHi(1) != 74
            || dpuMythOrd(1) != 1
        )
            ++bad;
        // the key-fill walk
    if (dpuKeyDdgCount(0) != 60
            || dpuKeyDdgCount(56) != 60
            || dpuKeyOrd(56) != 56
            || dpuKeyOrd(0) != 0
        )
            ++bad;
        // the doctrine walk
    if (dpuFromHeadersOnly() != 1
            || dpuNameOrdersLocked() != 1
            || dpuFullFieldDdg() != 1
            || dpuSentinelsDistinct() != 1
            || dpuProseContractSide() != 1
        )
            ++bad;
        // the boundary walk
    if (dpuDamagePinnedOnly() != 1
            || dpuSymbolsUnpinned() != 1
            || dpuWorshipUnpinned() != 1
            || dpuPinnedDamage() != 44
            || dpuSeeBelowCode() != 99
        )
            ++bad;
        // the shape walk
    if (dpuMonsterRows() != 7
            || dpuHitDiceRows() != 2
            || dpuNormalizerDdgAware() != 1
            || dpuPromotionBatchThree() != 1
        )
            ++bad;
        printf("R882 DDG promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
