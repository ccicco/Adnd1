    // ---- R735 OA Table 74 monetary treasure audit ----
    // OA round one hundred twenty-two (capture p. 286): the Table 74 Monetary
    // Treasure And Magical Items - the twenty-six treasure types by the seven
    // categories, each cell the min, max, and percent triple with the Nil the
    // 0 sentinel, the guaranteed pieces rows the 100, the maps and magic
    // clauses riding as bools, single-pass pins per the Chapter 9 provenance
    // shift
    {
        using namespace rules;
        int bad = 0;
    if (dkwTypeCount() != 26
            || !dkwMapsPlusPotion()
            || !dkwMapsPlusScroll()
            || !dkwMapsExceptSwordsMisc()
            || !dkwMapsExceptPotionsScrolls()
            || !dkwMapsSwordArmorWeapon()
            || !dkwMapsOneMap()
            || !dkwMapsMiscMagicAndPotion()
            || !dkwPiecesGuaranteed()
        )
            ++bad;
        // the dkwFen grid
        int CFen[26][3] = {
            {1,6,25},
            {1,8,50},
            {1,12,20},
            {1,8,10},
            {1,10,5},
            {0,0,0},
            {0,0,0},
            {5,30,25},
            {0,0,0},
            {3,24,100},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,4,25},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,3,20},
            };
        int nFen[3] = {0,0,0};
        int eFen[3] = {17,17,17};
        for (int b = 0;
             b < dkwTypeCount();
             ++b) {
            int vals[3];
            vals[0] = dkwFenMin(b);
            vals[1] = dkwFenMax(b);
            vals[2] = dkwFenPct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CFen[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nFen[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nFen[c] != eFen[c])
                ++bad;
        // the dkwYuan grid
        int CYuan[26][3] = {
            {1,3,30},
            {1,6,25},
            {1,6,30},
            {1,10,15},
            {1,10,25},
            {3,18,10},
            {0,0,0},
            {1,100,40},
            {0,0,0},
            {0,0,0},
            {4,24,100},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,6,20},
            {2,8,30},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {2,8,25},
            };
        int nYuan[3] = {0,0,0};
        int eYuan[3] = {15,15,15};
        for (int b = 0;
             b < dkwTypeCount();
             ++b) {
            int vals[3];
            vals[0] = dkwYuanMin(b);
            vals[1] = dkwYuanMax(b);
            vals[2] = dkwYuanPct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CYuan[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nYuan[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nYuan[c] != eYuan[c])
                ++bad;
        // the dkwTael grid
        int CTael[26][3] = {
            {2,20,35},
            {10,40,25},
            {1,10,10},
            {10,60,35},
            {10,60,25},
            {20,80,30},
            {10,40,50},
            {20,80,45},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {2,12,100},
            {4,24,100},
            {0,0,0},
            {0,0,0},
            {1,10,25},
            {0,0,0},
            {10,40,40},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {10,100,60},
            {0,0,0},
            {10,60,70},
            {20,60,25},
            };
        int nTael[3] = {0,0,0};
        int eTael[3] = {11,11,11};
        for (int b = 0;
             b < dkwTypeCount();
             ++b) {
            int vals[3];
            vals[0] = dkwTaelMin(b);
            vals[1] = dkwTaelMax(b);
            vals[2] = dkwTaelPct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CTael[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nTael[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nTael[c] != eTael[c])
                ++bad;
        // the dkwChien grid
        int CChien[26][3] = {
            {1,3,40},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,8,35},
            {2,16,50},
            {4,40,25},
            {2,12,30},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,6,100},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {10,30,50},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,8,15},
            {0,0,0},
            {0,0,0},
            {1,3,30},
            };
        int nChien[3] = {0,0,0};
        int eChien[3] = {17,17,17};
        for (int b = 0;
             b < dkwTypeCount();
             ++b) {
            int vals[3];
            vals[0] = dkwChienMin(b);
            vals[1] = dkwChienMax(b);
            vals[2] = dkwChienPct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CChien[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nChien[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nChien[c] != eChien[c])
                ++bad;
        // the dkwGems grid
        int CGems[26][3] = {
            {4,40,60},
            {1,8,30},
            {1,6,25},
            {1,6,30},
            {1,8,15},
            {2,20,20},
            {2,12,30},
            {1,100,50},
            {1,10,55},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,4,50},
            {3,24,55},
            {0,0,0},
            {0,0,0},
            {10,40,90},
            {0,0,0},
            {10,40,60},
            {0,0,0},
            {0,0,0},
            {5,30,55},
            };
        int nGems[3] = {0,0,0};
        int eGems[3] = {12,12,12};
        for (int b = 0;
             b < dkwTypeCount();
             ++b) {
            int vals[3];
            vals[0] = dkwGemsMin(b);
            vals[1] = dkwGemsMax(b);
            vals[2] = dkwGemsPct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CGems[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nGems[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nGems[c] != eGems[c])
                ++bad;
        // the dkwArt grid
        int CArt[26][3] = {
            {1,6,50},
            {1,2,20},
            {1,1,20},
            {1,3,25},
            {1,4,10},
            {1,6,10},
            {1,6,25},
            {10,30,50},
            {1,6,50},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {1,8,45},
            {0,0,0},
            {0,0,0},
            {2,20,80},
            {0,0,0},
            {3,30,50},
            {0,0,0},
            {0,0,0},
            {3,18,50},
            };
        int nArt[3] = {0,0,0};
        int eArt[3] = {13,13,13};
        for (int b = 0;
             b < dkwTypeCount();
             ++b) {
            int vals[3];
            vals[0] = dkwArtMin(b);
            vals[1] = dkwArtMax(b);
            vals[2] = dkwArtPct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CArt[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nArt[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nArt[c] != eArt[c])
                ++bad;
        // the dkwMaps grid
        int CMaps[26][3] = {
            {3,3,30},
            {1,1,10},
            {2,2,10},
            {2,2,15},
            {3,3,25},
            {3,3,30},
            {4,4,35},
            {4,4,15},
            {1,1,15},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {2,8,40},
            {1,4,50},
            {1,1,70},
            {2,2,85},
            {1,1,55},
            {1,1,60},
            {0,0,0},
            {3,3,50},
            };
        int nMaps[3] = {0,0,0};
        int eMaps[3] = {10,10,10};
        for (int b = 0;
             b < dkwTypeCount();
             ++b) {
            int vals[3];
            vals[0] = dkwMapsMin(b);
            vals[1] = dkwMapsMax(b);
            vals[2] = dkwMapsPct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMaps[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nMaps[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nMaps[c] != eMaps[c])
                ++bad;
        // the clause bools - the maps and magic specials, healthy values,
        // each condition false
    if (dkwMapsPlusPotion() != 1
            || dkwMapsPlusScroll() != 1
            || dkwMapsExceptSwordsMisc() != 1
            || dkwMapsExceptPotionsScrolls() != 1
            || dkwMapsSwordArmorWeapon() != 1
            || dkwMapsOneMap() != 1
            || dkwMapsMiscMagicAndPotion() != 1
            || dkwPiecesGuaranteed() != 1
        )
            ++bad;
        // the grid - the twenty-six-row Table 74, audited cell by cell by the
        // table audit
    if (dkwTypeCount() != 26
        )
            ++bad;
        // the nil law - the min, max, and percent of a cell nil together, the
        // A row ch'ien and the Q row maps spot checks, healthy values, each
        // condition false
    if (dkwChienMin(1) != 0
            || dkwChienMax(1) != 0
            || dkwChienPct(1) != 0
            || dkwMapsMin(16) != 0
            || dkwMapsMax(16) != 0
            || dkwMapsPct(16) != 0
        )
            ++bad;
        // the extremes - the U row gems percent the 90 high of the rolled
        // cells and the H row yuan the 100 range top, healthy values, each
        // condition false
    if (dkwGemsPct(20) != 90
            || dkwYuanMax(7) != 100
        )
            ++bad;
        printf("R735 OA Table 74 monetary treasure audit: bad %d\n", bad);
        if (bad) return 1;
    }
