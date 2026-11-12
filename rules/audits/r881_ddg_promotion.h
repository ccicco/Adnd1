    // ---- R881 DDG promotion audit ----
    // THE DDG LUA PROMOTION, BATCH TWO - the second promotion round: 68
    // full-field defs (Central American 14, Chinese 18, Cthulhu 15, Egyptian
    // 21) generated only from the adjudicated pin headers, the registry floor
    // 1050 -> 1118, the census refresh and the batch-two honest boundaries
    // (the unpinned worshipper alignments, symbols, lair percents and fighter
    // lines stay sentinel).
    {
        using namespace rules;
        int bad = 0;
    if (dptRound() != 881
            || dptCensusBefore() != 803
            || dptCensusAfter() != 804
            || dptDefs() != 68
            || dptMythoi() != 4
            || dptFloorBefore() != 1050
            || dptFloorAfter() != 1118
            || dptFullFieldKeys() != 57
            || dptMonsterRows() != 13
            || dptHitDiceRows() != 8
            || dptPinnedDamage() != 50
            || dptSeeBelowCode() != 99
            || !dptPromotionBatchTwo()
            || !dptFromHeadersOnly()
            || !dptNameOrdersLocked()
            || !dptFullFieldDdg()
            || !dptSentinelsDistinct()
            || !dptProseContractSide()
            || !dptDamagePinnedOnly()
            || !dptSymbolsUnpinned()
            || !dptWorshipUnpinned()
            || !dptNormalizerDdgAware()
        )
            ++bad;
        // the the batch-two mythos grid grid
        int CdptMyth[4][4] = {
            {0,32,36,14},
            {1,37,42,18},
            {2,43,47,15},
            {3,49,55,21},
            };
        for (int b = 0;
             b < dptMythoi();
             ++b) {
            int vals[4];
            vals[0] = dptMythOrd(b);
            vals[1] = dptMythPageLo(b);
            vals[2] = dptMythPageHi(b);
            vals[3] = dptMythDefs(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CdptMyth[b][c])
                    ++bad;
            }
        }
        // the the DDG key-fill grid grid
        int CdptKeyFill[57][2] = {
            {0,68},
            {1,68},
            {2,68},
            {3,68},
            {4,68},
            {5,68},
            {6,68},
            {7,68},
            {8,68},
            {9,68},
            {10,68},
            {11,68},
            {12,68},
            {13,68},
            {14,68},
            {15,68},
            {16,68},
            {17,68},
            {18,68},
            {19,68},
            {20,68},
            {21,68},
            {22,68},
            {23,68},
            {24,68},
            {25,68},
            {26,68},
            {27,68},
            {28,68},
            {29,68},
            {30,68},
            {31,68},
            {32,68},
            {33,68},
            {34,68},
            {35,68},
            {36,68},
            {37,68},
            {38,68},
            {39,68},
            {40,68},
            {41,68},
            {42,68},
            {43,68},
            {44,68},
            {45,68},
            {46,68},
            {47,68},
            {48,68},
            {49,68},
            {50,68},
            {51,68},
            {52,68},
            {53,68},
            {54,68},
            {55,68},
            {56,68},
            };
        for (int b = 0;
             b < dptFullFieldKeys();
             ++b) {
            int vals[2];
            vals[0] = dptKeyOrd(b);
            vals[1] = dptKeyDdgCount(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CdptKeyFill[b][c])
                    ++bad;
            }
        }
        // the round walk (the promotion batch two, the census step)
    if (dptRound() != 881
            || dptCensusBefore() != 803
            || dptCensusAfter() != 804
        )
            ++bad;
        // the registry floor (the second growth batch)
    if (dptFloorBefore() != 1050
            || dptFloorAfter() != 1118
            || dptDefs() != 68
            || dptFullFieldKeys() != 57
        )
            ++bad;
        // the mythos walk (the print pages, the def counts)
    if (dptMythPageLo(0) != 32
            || dptMythPageHi(0) != 36
            || dptMythDefs(0) != 14
            || dptMythDefs(1) != 18
            || dptMythDefs(2) != 15
            || dptMythDefs(3) != 21
            || dptMythPageLo(3) != 49
            || dptMythPageHi(3) != 55
            || dptMythOrd(3) != 3
        )
            ++bad;
        // the key-fill (every DDG def full-field, all 57 keys)
    if (dptKeyDdgCount(0) != 68
            || dptKeyDdgCount(56) != 68
            || dptKeyOrd(56) != 56
            || dptKeyOrd(0) != 0
        )
            ++bad;
        // the doctrine (the headers-only, the sentinel and prose bools)
    if (dptFromHeadersOnly() != 1
            || dptNameOrdersLocked() != 1
            || dptFullFieldDdg() != 1
            || dptSentinelsDistinct() != 1
            || dptProseContractSide() != 1
        )
            ++bad;
        // the honest boundaries (the unpinned worshipper alignments, symbols
        // and figures stay sentinel)
    if (dptDamagePinnedOnly() != 1
            || dptSymbolsUnpinned() != 1
            || dptWorshipUnpinned() != 1
            || dptPinnedDamage() != 50
            || dptSeeBelowCode() != 99
        )
            ++bad;
        // the rows (the monster formats, the hit-dice rows, the DDG-aware
        // normalizer)
    if (dptMonsterRows() != 13
            || dptHitDiceRows() != 8
            || dptNormalizerDdgAware() != 1
            || dptPromotionBatchTwo() != 1
        )
            ++bad;
        printf("R881 DDG promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
