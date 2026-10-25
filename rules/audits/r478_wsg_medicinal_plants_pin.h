    // ---- R478 WSG medicinal plants pin audit ----
    // The Table 40 terrain-climate grids (34 rows: Arctic six with no swamp,
    // then subarctic, temperate, subtropical and tropical with all seven
    // terrains apiece), the slash entry semantics (the left number the
    // vegetation chance, the right the locate chance, identify on one-half or
    // less, the upper half a wrong type believed right), plant lore always
    // correct, one search per turn while moving, repeated searches auto-fail,
    // movement slowed, and the worked example (tropical hills winter 90 and
    // 30: roll 15 the right type, 16-30 wrong, 31-up nothing).
    {
        using namespace rules;
        int bad = 0;
    if (wmpClimateCount() != 5
            || wmpTerrainCount() != 7
            || wmpArcticTerrainCount() != 6
            || wmpRowCount() != 34
            || wmpAppendixJFirstPage() != 220
            || wmpAppendixJLastPage() != 221
            || wmpIdentifyNum() != 1
            || wmpIdentifyDen() != 2
            || wmpSearchesPerTurn() != 1
            || wmpExVegPct() != 90
            || wmpExLocatePct() != 30
            || wmpExRoll() != 15
            || wmpExWrongMinRoll() != 16
            || wmpExWrongMaxRoll() != 30
            || wmpExFailMinRoll() != 31
            || !wmpVegChanceIsLeft()
            || !wmpLocateChanceIsRight()
            || !wmpUpperHalfWrongType()
            || !wmpPlantLoreAlwaysRight()
            || !wmpSearchByFunction()
            || !wmpKeepMoving()
            || !wmpRepeatSearchFails()
            || !wmpSearchSlowsMovement()
            || !wmpDmMayAddPenalties()
            || !wmpDmGuardsAbuse()
            || !wmpArcticHasNoSwamp()
        )
            ++bad;
        // the Table 40 vegetation chance grid (34 rows, the left slash
        // number)
        int C40v[34][4] = {
            {0,5,10,0},
            {5,10,10,5},
            {0,0,5,0},
            {5,5,10,5},
            {10,10,15,10},
            {10,10,10,10},
            {0,5,15,5},
            {70,85,100,75},
            {20,30,40,25},
            {10,15,20,15},
            {20,30,50,30},
            {25,35,50,35},
            {15,20,30,20},
            {10,5,5,5},
            {80,90,100,90},
            {65,75,90,80},
            {20,30,40,30},
            {50,60,75,60},
            {50,65,80,65},
            {30,35,40,35},
            {5,5,0,5},
            {90,100,100,100},
            {80,90,100,95},
            {40,55,75,60},
            {80,90,100,100},
            {80,90,100,95},
            {40,50,50,50},
            {5,5,0,5},
            {100,100,100,100},
            {90,100,100,95},
            {85,90,90,90},
            {100,100,100,100},
            {90,95,100,95},
            {50,60,70,60},
            };
        for (int b = 0;
             b < wmpRowCount();
             ++b) {
            int vals[4];
            vals[0] = wmpVegWinter(b);
            vals[1] = wmpVegSpring(b);
            vals[2] = wmpVegSummer(b);
            vals[3] = wmpVegAutumn(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C40v[b][c])
                    ++bad;
            }
        }
        // the Table 40 locate chance grid (34 rows, the right slash number)
        int C40l[34][4] = {
            {0,10,10,0},
            {10,10,10,10},
            {0,0,20,0},
            {20,20,20,20},
            {10,20,20,10},
            {10,20,20,10},
            {0,10,10,10},
            {30,30,20,30},
            {20,20,30,20},
            {20,20,30,20},
            {20,30,30,20},
            {10,20,30,20},
            {10,10,10,20},
            {10,10,10,20},
            {30,30,30,30},
            {20,30,40,20},
            {20,30,30,20},
            {20,30,40,20},
            {20,30,30,20},
            {10,20,20,10},
            {10,10,0,10},
            {40,40,40,40},
            {40,40,50,50},
            {30,40,40,30},
            {40,40,40,40},
            {30,30,30,30},
            {10,20,20,10},
            {10,10,0,10},
            {40,40,30,40},
            {30,30,30,30},
            {40,40,30,40},
            {40,40,40,30},
            {30,40,40,30},
            {10,10,20,10},
            };
        for (int b = 0;
             b < wmpRowCount();
             ++b) {
            int vals[4];
            vals[0] = wmpLocWinter(b);
            vals[1] = wmpLocSpring(b);
            vals[2] = wmpLocSummer(b);
            vals[3] = wmpLocAutumn(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C40l[b][c])
                    ++bad;
            }
        }
        // the row count: arctic lacks Sw, the other four climates carry all
        // seven terrains
    if (wmpRowCount() != wmpArcticTerrainCount() + 4 * wmpTerrainCount()
        )
            ++bad;
        // the worked example cites tropical hills winter: vegetation 90,
        // locate 30
    if (wmpVegWinter(29) != wmpExVegPct()
            || wmpLocWinter(29) != wmpExLocatePct()
        )
            ++bad;
        // the example bands: 15 halves 30 exactly; 16-30 the wrong type;
        // 31-up nothing
    if (2 * wmpExRoll() != wmpExLocatePct()
            || wmpExWrongMaxRoll() != wmpExLocatePct()
            || wmpExFailMinRoll() != wmpExLocatePct() + 1
            || wmpExWrongMinRoll() != wmpExLocatePct() / 2 + 1
        )
            ++bad;
        // the frame: five climates, seven terrains, arctic six, 34 rows;
        // Appendix J spans DMG pages 220-221
    if (wmpClimateCount() != 5
            || wmpTerrainCount() != 7
            || wmpArcticTerrainCount() != 6
            || wmpRowCount() != 34
            || wmpAppendixJLastPage() != wmpAppendixJFirstPage() + 1
        )
            ++bad;
        // the identify cut is one-half; one search per turn
    if (wmpIdentifyNum() * 2 != wmpIdentifyDen()
            || wmpSearchesPerTurn() != 1
        )
            ++bad;
        printf("R478 WSG medicinal plants pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
