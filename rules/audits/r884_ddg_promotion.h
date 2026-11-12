    // ---- R884 DDG promotion audit ----
    // THE DDG LUA PROMOTION, BATCH FIVE - the fifth promotion round: 33
    // full-field defs (the Melnibonean mythos) generated only from the
    // adjudicated pin headers, the registry floor 1209 -> 1242, the census
    // refresh and the batch-five honest boundaries (the HD-row print garbles
    // cross-checked against the pin, the Kelmain See-below hit dice and
    // Variable xp, the Oonai Variable attacks, the vampire trees 1-10 attack
    // band, the Arioch Variable size, the ranger cells that print on the
    // fighter lines, the Elric Stormbringer alt armor class, the unpinned
    // lair percents, worshipper alignments and symbols stay sentinel).
    {
        using namespace rules;
        int bad = 0;
    if (dpxRound() != 884
            || dpxCensusBefore() != 806
            || dpxCensusAfter() != 807
            || dpxDefs() != 33
            || dpxMythoi() != 1
            || dpxFloorBefore() != 1209
            || dpxFloorAfter() != 1242
            || dpxFullFieldKeys() != 57
            || dpxMonsterRows() != 14
            || dpxHitDiceRows() != 8
            || dpxPinnedDamage() != 26
            || dpxSeeBelowCode() != 99
            || !dpxPromotionBatchFive()
            || !dpxFromHeadersOnly()
            || !dpxNameOrdersLocked()
            || !dpxFullFieldDdg()
            || !dpxSentinelsDistinct()
            || !dpxProseContractSide()
            || !dpxDamagePinnedOnly()
            || !dpxSymbolsUnpinned()
            || !dpxWorshipUnpinned()
            || !dpxNormalizerDdgAware()
        )
            ++bad;
        // the the batch-five mythos grid grid
        int CdpxMyth[1][4] = {
            {0,86,95,33},
            };
        for (int b = 0;
             b < dpxMythoi();
             ++b) {
            int vals[4];
            vals[0] = dpxMythOrd(b);
            vals[1] = dpxMythPageLo(b);
            vals[2] = dpxMythPageHi(b);
            vals[3] = dpxMythDefs(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CdpxMyth[b][c])
                    ++bad;
            }
        }
        // the the DDG key-fill grid grid
        int CdpxKeyFill[57][2] = {
            {0,33},
            {1,33},
            {2,33},
            {3,33},
            {4,33},
            {5,33},
            {6,33},
            {7,33},
            {8,33},
            {9,33},
            {10,33},
            {11,33},
            {12,33},
            {13,33},
            {14,33},
            {15,33},
            {16,33},
            {17,33},
            {18,33},
            {19,33},
            {20,33},
            {21,33},
            {22,33},
            {23,33},
            {24,33},
            {25,33},
            {26,33},
            {27,33},
            {28,33},
            {29,33},
            {30,33},
            {31,33},
            {32,33},
            {33,33},
            {34,33},
            {35,33},
            {36,33},
            {37,33},
            {38,33},
            {39,33},
            {40,33},
            {41,33},
            {42,33},
            {43,33},
            {44,33},
            {45,33},
            {46,33},
            {47,33},
            {48,33},
            {49,33},
            {50,33},
            {51,33},
            {52,33},
            {53,33},
            {54,33},
            {55,33},
            {56,33},
            };
        for (int b = 0;
             b < dpxFullFieldKeys();
             ++b) {
            int vals[2];
            vals[0] = dpxKeyOrd(b);
            vals[1] = dpxKeyDdgCount(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CdpxKeyFill[b][c])
                    ++bad;
            }
        }
        // the round walk (the promotion batch five, the census step)
    if (dpxRound() != 884
            || dpxCensusBefore() != 806
            || dpxCensusAfter() != 807
        )
            ++bad;
        // the floor walk
    if (dpxFloorBefore() != 1209
            || dpxFloorAfter() != 1242
            || dpxDefs() != 33
            || dpxFullFieldKeys() != 57
        )
            ++bad;
        // the mythos grid walk
    if (dpxMythPageLo(0) != 86
            || dpxMythPageHi(0) != 95
            || dpxMythDefs(0) != 33
            || dpxMythOrd(0) != 0
            || dpxMythoi() != 1
        )
            ++bad;
        // the key-fill walk
    if (dpxKeyDdgCount(0) != 33
            || dpxKeyDdgCount(56) != 33
            || dpxKeyOrd(56) != 56
            || dpxKeyOrd(0) != 0
        )
            ++bad;
        // the doctrine walk
    if (dpxFromHeadersOnly() != 1
            || dpxNameOrdersLocked() != 1
            || dpxFullFieldDdg() != 1
            || dpxSentinelsDistinct() != 1
            || dpxProseContractSide() != 1
        )
            ++bad;
        // the boundary walk
    if (dpxDamagePinnedOnly() != 1
            || dpxSymbolsUnpinned() != 1
            || dpxWorshipUnpinned() != 1
            || dpxPinnedDamage() != 26
            || dpxSeeBelowCode() != 99
        )
            ++bad;
        // the shape walk
    if (dpxMonsterRows() != 14
            || dpxHitDiceRows() != 8
            || dpxNormalizerDdgAware() != 1
            || dpxPromotionBatchFive() != 1
        )
            ++bad;
        printf("R884 DDG promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
