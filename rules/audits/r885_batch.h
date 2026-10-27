    // ---- R885 DDG promotion audit ----
    // THE DDG LUA PROMOTION, BATCH SIX - the sixth promotion round: 49
    // full-field defs (the Nehwon mythos and the Nonhumans' Deities)
    // generated only from the adjudicated pin headers, the registry floor
    // 1242 -> 1291, the census refresh and the batch-six honest boundaries
    // (the ghoul by-weapon print against the DmgFixed flag and the earth god
    // 5-50 print against its 0 - both pin-internal, both emitting the n/a
    // sentinel; the Votishal hp 344 against the L&L 244; the Hate See-below
    // armor class and the Tyaa bare dash pinned 0; the Gods of Trouble
    // Special magic resistance pinned 0 as Standard; the Skerrit Variable
    // cells with the armor-class 2 floor pin; the Lolth monster-block voice -
    // the -2 drow paren, the 1/9 web walk, the MR 70 against the L&L 75, the
    // See below class pairs and the L (M) size sentinel; the twelve
    // as-16-plus-HD fighter cells reading as F16; the Sashelas Standard (out
    // of water); the Nine Hells plane pins against the L&L D64 glosses; the
    // Behemoth and Lolth collision renames; the Mouser quarter-foot and the
    // Yondalla and Kurtulmak fraction sizes; the unpinned lair percents,
    // worshipper alignments, symbols and areas of control stay sentinel).
    {
        using namespace rules;
        int bad = 0;
    if (dpyRound() != 885
            || dpyCensusBefore() != 807
            || dpyCensusAfter() != 808
            || dpyDefs() != 49
            || dpyMythoi() != 2
            || dpyFloorBefore() != 1242
            || dpyFloorAfter() != 1291
            || dpyFullFieldKeys() != 57
            || dpyMonsterRows() != 10
            || dpyHitDiceRows() != 7
            || dpyPinnedDamage() != 34
            || dpySeeBelowCode() != 99
            || !dpyPromotionBatchSix()
            || !dpyFromHeadersOnly()
            || !dpyNameOrdersLocked()
            || !dpyFullFieldDdg()
            || !dpySentinelsDistinct()
            || !dpyProseContractSide()
            || !dpyDamagePinnedOnly()
            || !dpySymbolsUnpinned()
            || !dpyWorshipUnpinned()
            || !dpyNormalizerDdgAware()
        )
            ++bad;
        // the the batch-six mythos grid grid
        int CdpyMyth[2][4] = {
            {0,96,104,29},
            {1,105,112,20},
            };
        for (int b = 0;
             b < dpyMythoi();
             ++b) {
            int vals[4];
            vals[0] = dpyMythOrd(b);
            vals[1] = dpyMythPageLo(b);
            vals[2] = dpyMythPageHi(b);
            vals[3] = dpyMythDefs(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CdpyMyth[b][c])
                    ++bad;
            }
        }
        // the the DDG key-fill grid grid
        int CdpyKeyFill[57][2] = {
            {0,49},
            {1,49},
            {2,49},
            {3,49},
            {4,49},
            {5,49},
            {6,49},
            {7,49},
            {8,49},
            {9,49},
            {10,49},
            {11,49},
            {12,49},
            {13,49},
            {14,49},
            {15,49},
            {16,49},
            {17,49},
            {18,49},
            {19,49},
            {20,49},
            {21,49},
            {22,49},
            {23,49},
            {24,49},
            {25,49},
            {26,49},
            {27,49},
            {28,49},
            {29,49},
            {30,49},
            {31,49},
            {32,49},
            {33,49},
            {34,49},
            {35,49},
            {36,49},
            {37,49},
            {38,49},
            {39,49},
            {40,49},
            {41,49},
            {42,49},
            {43,49},
            {44,49},
            {45,49},
            {46,49},
            {47,49},
            {48,49},
            {49,49},
            {50,49},
            {51,49},
            {52,49},
            {53,49},
            {54,49},
            {55,49},
            {56,49},
            };
        for (int b = 0;
             b < dpyFullFieldKeys();
             ++b) {
            int vals[2];
            vals[0] = dpyKeyOrd(b);
            vals[1] = dpyKeyDdgCount(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CdpyKeyFill[b][c])
                    ++bad;
            }
        }
        // the round walk (the promotion batch six, the census step)
    if (dpyRound() != 885
            || dpyCensusBefore() != 807
            || dpyCensusAfter() != 808
        )
            ++bad;
        // the floor walk
    if (dpyFloorBefore() != 1242
            || dpyFloorAfter() != 1291
            || dpyDefs() != 49
            || dpyFullFieldKeys() != 57
        )
            ++bad;
        // the mythos grid walk
    if (dpyMythPageLo(0) != 96
            || dpyMythPageHi(0) != 104
            || dpyMythDefs(0) != 29
            || dpyMythOrd(0) != 0
            || dpyMythOrd(1) != 1
            || dpyMythPageLo(1) != 105
            || dpyMythPageHi(1) != 112
            || dpyMythDefs(1) != 20
            || dpyMythoi() != 2
        )
            ++bad;
        // the key-fill walk
    if (dpyKeyDdgCount(0) != 49
            || dpyKeyDdgCount(56) != 49
            || dpyKeyOrd(56) != 56
            || dpyKeyOrd(0) != 0
        )
            ++bad;
        // the doctrine walk
    if (dpyFromHeadersOnly() != 1
            || dpyNameOrdersLocked() != 1
            || dpyFullFieldDdg() != 1
            || dpySentinelsDistinct() != 1
            || dpyProseContractSide() != 1
        )
            ++bad;
        // the boundary walk
    if (dpyDamagePinnedOnly() != 1
            || dpySymbolsUnpinned() != 1
            || dpyWorshipUnpinned() != 1
            || dpyPinnedDamage() != 34
            || dpySeeBelowCode() != 99
        )
            ++bad;
        // the shape walk
    if (dpyMonsterRows() != 10
            || dpyHitDiceRows() != 7
            || dpyNormalizerDdgAware() != 1
            || dpyPromotionBatchSix() != 1
        )
            ++bad;
        printf("R885 DDG promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
