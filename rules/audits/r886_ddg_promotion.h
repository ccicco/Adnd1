    // ---- R886 DDG promotion audit ----
    // THE DDG LUA PROMOTION, BATCH SEVEN - the seventh promotion round: 42
    // full-field defs (the Norse mythos and the Sumerian mythos) generated
    // only from the adjudicated pin headers, the registry floor 1291 -> 1333,
    // the census refresh and the batch-seven honest boundaries (the Thor bare
    // 4 armor class pinned as printed against the L&L minus 4; the Hel +38
    // damage garble adjudicated 8; the Aegir and Freya armor classes pinned
    // by the print against the L&L voices; the Thrym 300 hit points from the
    // L&L voice - the print cell occluded by the plate; the four half-foot
    // size garbles )4 and % reading the 6 1/2 and 5 1/2 foot cells; the Hugin
    // 1/48 move and the merged VI/815 XP glyph; the Frey single-pipe II at
    // width 15; the Fossergrim by-weapon print against its DmgFixed 1 and the
    // Nin-hursag 2-20 dice print against its 0 - both pin-internal, both
    // emitting the n/a sentinel, with the 27-vs-28 DmgFixed count flag; the
    // eleven-vs-ten monster-count flag; the Fossergrim 5 HD print with the
    // hit-dice-not-points CbtHP cell and the 9/ /36 double-slash move pinned
    // as printed; the Modi 2 (or 4) berserk attacks and the 25 or 50 damage -
    // the first non-dice damage cells; the Thor 2(3) glove attacks; the
    // Frigga As-per-shape attacks pinned 0; the Jormungandr See below move 0,
    // the 25,000-mile size print, the 99 magic resistance against the L&L 95
    // and the L&L 1 ~ 7 attacks reading against the pinned 1; the Garm 26,200
    // XP against the L&L 26,000; the goats X/+ merged XP glyph pinned 14,100;
    // the Fjalar and Skirnir 99 hit points and the Fenris Wolf and
    // Jormungandr 99 magic resistances - the literal 99 prints against the
    // See-below code; the four no-rank class-grid rows printing no rank line
    // and emitting the n/a divine rank - the cross-pin rank-code collision
    // with the nhw wizard 4; the paladin grids riding the F token per the
    // Surya convention - the Tyr F25, the Enki F13 and the Ki F10; the Loki
    // Pandemonium-or-Gladsheim plane alt; the Enlil 127/36 inch garble
    // adjudicated 12, the (64) and (5) and (6) size garbles read through the
    // L&L voice, the Utu 32 attacks garble adjudicated 3/2, the Ki 15/36//36
    // triple slash pinned as printed, the Inanna single-pipe I against the
    // L&L II and her warriors-and-lovers worshipper line pinned odd without
    // pinning an alignment, the Enki 10th-level bard against the L&L 13th,
    // the Utu 15th in-each magic-user pair against the L&L illusionist-alone
    // and the Enlil D:23 CH:24 cells against the L&L 25s; the uniform -2
    // Sumerian armor class; the hp-each and head-and-body phrasings riding
    // the pinned numbers; the unpinned lair percents, worshipper alignments,
    // symbols and areas of control stay sentinel).
    {
        using namespace rules;
        int bad = 0;
    if (dpzRound() != 886
            || dpzCensusBefore() != 808
            || dpzCensusAfter() != 809
            || dpzDefs() != 42
            || dpzMythoi() != 2
            || dpzFloorBefore() != 1291
            || dpzFloorAfter() != 1333
            || dpzFullFieldKeys() != 57
            || dpzMonsterRows() != 11
            || dpzHitDiceRows() != 1
            || dpzPinnedDamage() != 32
            || dpzSeeBelowCode() != 99
            || !dpzPromotionBatchSeven()
            || !dpzFromHeadersOnly()
            || !dpzNameOrdersLocked()
            || !dpzFullFieldDdg()
            || !dpzSentinelsDistinct()
            || !dpzProseContractSide()
            || !dpzDamagePinnedOnly()
            || !dpzSymbolsUnpinned()
            || !dpzWorshipUnpinned()
            || !dpzNormalizerDdgAware()
        )
            ++bad;
        // the the batch-seven mythos grid grid
        int CdpzMyth[2][4] = {
            {0,113,124,35},
            {1,125,127,7},
            };
        for (int b = 0;
             b < dpzMythoi();
             ++b) {
            int vals[4];
            vals[0] = dpzMythOrd(b);
            vals[1] = dpzMythPageLo(b);
            vals[2] = dpzMythPageHi(b);
            vals[3] = dpzMythDefs(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CdpzMyth[b][c])
                    ++bad;
            }
        }
        // the the DDG key-fill grid grid
        int CdpzKeyFill[57][2] = {
            {0,42},
            {1,42},
            {2,42},
            {3,42},
            {4,42},
            {5,42},
            {6,42},
            {7,42},
            {8,42},
            {9,42},
            {10,42},
            {11,42},
            {12,42},
            {13,42},
            {14,42},
            {15,42},
            {16,42},
            {17,42},
            {18,42},
            {19,42},
            {20,42},
            {21,42},
            {22,42},
            {23,42},
            {24,42},
            {25,42},
            {26,42},
            {27,42},
            {28,42},
            {29,42},
            {30,42},
            {31,42},
            {32,42},
            {33,42},
            {34,42},
            {35,42},
            {36,42},
            {37,42},
            {38,42},
            {39,42},
            {40,42},
            {41,42},
            {42,42},
            {43,42},
            {44,42},
            {45,42},
            {46,42},
            {47,42},
            {48,42},
            {49,42},
            {50,42},
            {51,42},
            {52,42},
            {53,42},
            {54,42},
            {55,42},
            {56,42},
            };
        for (int b = 0;
             b < dpzFullFieldKeys();
             ++b) {
            int vals[2];
            vals[0] = dpzKeyOrd(b);
            vals[1] = dpzKeyDdgCount(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CdpzKeyFill[b][c])
                    ++bad;
            }
        }
        // the round walk (the promotion batch seven, the census step)
    if (dpzRound() != 886
            || dpzCensusBefore() != 808
            || dpzCensusAfter() != 809
        )
            ++bad;
        // the floor walk
    if (dpzFloorBefore() != 1291
            || dpzFloorAfter() != 1333
            || dpzDefs() != 42
            || dpzFullFieldKeys() != 57
        )
            ++bad;
        // the mythos grid walk
    if (dpzMythPageLo(0) != 113
            || dpzMythPageHi(0) != 124
            || dpzMythDefs(0) != 35
            || dpzMythOrd(0) != 0
            || dpzMythOrd(1) != 1
            || dpzMythPageLo(1) != 125
            || dpzMythPageHi(1) != 127
            || dpzMythDefs(1) != 7
            || dpzMythoi() != 2
        )
            ++bad;
        // the key-fill walk
    if (dpzKeyDdgCount(0) != 42
            || dpzKeyDdgCount(56) != 42
            || dpzKeyOrd(56) != 56
            || dpzKeyOrd(0) != 0
        )
            ++bad;
        // the doctrine walk
    if (dpzFromHeadersOnly() != 1
            || dpzNameOrdersLocked() != 1
            || dpzFullFieldDdg() != 1
            || dpzSentinelsDistinct() != 1
            || dpzProseContractSide() != 1
        )
            ++bad;
        // the boundary walk
    if (dpzDamagePinnedOnly() != 1
            || dpzSymbolsUnpinned() != 1
            || dpzWorshipUnpinned() != 1
            || dpzPinnedDamage() != 32
            || dpzSeeBelowCode() != 99
        )
            ++bad;
        // the shape walk
    if (dpzMonsterRows() != 11
            || dpzHitDiceRows() != 1
            || dpzNormalizerDdgAware() != 1
            || dpzPromotionBatchSeven() != 1
        )
            ++bad;
        printf("R886 DDG promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
