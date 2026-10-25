    // ---- R615 OA ability tables audit ----
    // OA round two (capture pp. 7-13): the eight ability tables - the six
    // grids (Strength Adjustments, Dexterity, Constitution, Intelligence,
    // Wisdom, Charisma) with the Table 8 band chain and grid, the class and
    // race annotations of the General Information columns, the Table 4
    // warrior-bonus footnote and the Table 2 one-attempt riders.
    {
        using namespace rules;
        int bad = 0;
    if (dgbMinStrWuJen() != 3
            || dgbMinStrSpiritFolk() != 6
            || dgbMinStrKorobokuru() != 8
            || dgbMinStrShukenja() != 9
            || dgbMinStrBushi() != 9
            || dgbMinStrHengeyokai() != 12
            || dgbMinStrKensai() != 12
            || dgbMinStrSamurai() != 13
            || dgbMinStrSohei() != 13
            || dgbMinStrBarbarian() != 15
            || dgbMinStrMonk() != 15
            || dgbMaxStrShukenja() != 18
            || dgbMaxStrMonk() != 18
            || dgbMaxStrWuJen() != 18
            || dgbMaxStrYakuza() != 18
            || dgbMaxStrHuman() != 18
            || dgbMaxStrKorobokuru() != 19
            || dgbT2RowCount() != 16
            || dgbMinDexKorobokuru() != 6
            || dgbMinDexBushi() != 8
            || dgbMinDexHengeyokai() != 9
            || dgbMinDexSpiritFolk() != 12
            || dgbMinDexKensai() != 14
            || dgbMinDexBarbarian() != 14
            || dgbMinDexNinja() != 14
            || dgbMinDexMonk() != 15
            || dgbT3RowCount() != 17
            || dgbMinConSpiritFolk() != 6
            || dgbMinConBushi() != 8
            || dgbMinConShukenja() != 9
            || dgbMinConSohei() != 10
            || dgbMinConMonk() != 11
            || dgbMinConKorobokuru() != 12
            || dgbMinConHengeyokai() != 12
            || dgbMinConSamurai() != 13
            || dgbMaxConSpiritFolk() != 14
            || dgbMinConBarbarian() != 15
            || dgbT4RowCount() != 16
            || dgbMinIntKorobokuru() != 3
            || dgbMinIntHengeyokai() != 12
            || dgbMinIntSpiritFolk() != 12
            || dgbMinIntWuJen() != 13
            || dgbMinIntSamurai() != 14
            || dgbMinIntNinja() != 15
            || dgbMaxIntKorobokuru() != 15
            || dgbT5RowCount() != 16
            || dgbMinWisSpiritFolk() != 9
            || dgbMinWisSohei() != 10
            || dgbMinWisKensai() != 12
            || dgbMinWisShukenja() != 12
            || dgbMinWisHengeyokai() != 12
            || dgbMinWisSamurai() != 13
            || dgbMinWisMonk() != 15
            || dgbMaxWisBarbarian() != 16
            || dgbMaxWisKorobokuru() != 17
            || dgbT6RowCount() != 16
            || dgbMinChaHengeyokai() != 12
            || dgbMinChaSpiritFolk() != 14
            || dgbMinChaNinja() != 14
            || dgbMaxChaKorobokuru() != 16
            || dgbMaxChaHengeyokai() != 17
            || dgbT7RowCount() != 16
            || dgbT8RowCount() != 9
            || !dgbT2OpenDoorsRetry()
            || !dgbT2LockedOneAttempt()
            || !dgbT2BendBarsOneAttempt()
            || !dgbT2DmgFloorOne()
            || !dgbT2WeightSlowdown()
            || !dgbT4HitDieFloorOne()
            || !dgbT4WarriorFullCon()
            || !dgbT4BarbarianFullCon()
            || !dgbT4OthersCapTwo()
            || !dgbT6MindAuto()
        )
            ++bad;
        // the Table 2 grid: hit probability, damage adjustment, weight
        // allowance, open-doors max and locked, bend-bars percent across the
        // sixteen Strength rows (capture p. 8)
        int CT2[16][6] = {
            {-3,-1,0,1,0,0},
            {-2,-1,100,1,0,0},
            {-1,0,200,1,0,0},
            {0,0,350,2,0,1},
            {0,0,350,2,0,2},
            {0,0,450,2,0,4},
            {0,0,550,2,0,7},
            {0,1,700,3,0,10},
            {1,1,850,3,0,13},
            {1,2,1100,3,0,16},
            {1,3,1350,3,0,20},
            {2,3,1600,4,0,25},
            {2,4,1850,4,0,30},
            {2,5,2350,4,1,35},
            {3,6,3350,5,2,40},
            {3,7,4850,7,3,50},
            };
        for (int b = 0;
             b < dgbT2RowCount();
             ++b) {
            int vals[6];
            vals[0] = dgbT2HitProb(b);
            vals[1] = dgbT2DmgAdj(b);
            vals[2] = dgbT2Weight(b);
            vals[3] = dgbT2OpenMax(b);
            vals[4] = dgbT2OpenLocked(b);
            vals[5] = dgbT2BendPct(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT2[b][c])
                    ++bad;
            }
        }
        // the Table 3 grid: the reaction adjustment and the defensive
        // adjustment across Dexterity 3-19 (capture p. 9)
        int CT3[17][2] = {
            {-3,4},
            {-2,3},
            {-1,2},
            {0,1},
            {0,0},
            {0,0},
            {0,0},
            {0,0},
            {0,0},
            {0,0},
            {0,0},
            {0,0},
            {0,0},
            {0,-1},
            {1,-2},
            {2,-3},
            {3,-4},
            };
        for (int b = 0;
             b < dgbT3RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgbT3Reaction(b);
            vals[1] = dgbT3Defensive(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT3[b][c])
                    ++bad;
            }
        }
        // the Table 4 grid: the hit-point and warrior hit-point adjustments,
        // the system shock and resurrection survival percents across
        // Constitution 3-18 (capture p. 10)
        int CT4[16][4] = {
            {-2,-2,35,40},
            {-1,-1,40,45},
            {-1,-1,45,50},
            {-1,-1,50,55},
            {0,0,55,60},
            {0,0,60,65},
            {0,0,65,70},
            {0,0,70,75},
            {0,0,75,80},
            {0,0,80,85},
            {0,0,85,90},
            {0,0,88,92},
            {1,1,91,94},
            {2,2,95,96},
            {2,3,97,98},
            {2,4,99,100},
            };
        for (int b = 0;
             b < dgbT4RowCount();
             ++b) {
            int vals[4];
            vals[0] = dgbT4HpAdj(b);
            vals[1] = dgbT4WarriorHpAdj(b);
            vals[2] = dgbT4ShockPct(b);
            vals[3] = dgbT4ResPct(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CT4[b][c])
                    ++bad;
            }
        }
        // the Table 5 grid: the additional languages and the maximum wu jen
        // spell level across Intelligence 3-18 (capture p. 11)
        int CT5[16][2] = {
            {0,4},
            {0,4},
            {0,4},
            {0,4},
            {0,4},
            {1,4},
            {1,4},
            {2,5},
            {2,5},
            {3,6},
            {3,6},
            {4,6},
            {4,7},
            {5,8},
            {6,8},
            {7,9},
            };
        for (int b = 0;
             b < dgbT5RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgbT5Languages(b);
            vals[1] = dgbT5MaxSpellLevel(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT5[b][c])
                    ++bad;
            }
        }
        // the Table 6 grid: the magical attack adjustment across Wisdom 3-18
        // (capture pp. 11-12)
        int CT6[16][1] = {
            {-3},
            {-2},
            {-1},
            {-1},
            {-1},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {1},
            {2},
            {3},
            {4},
            };
        for (int b = 0;
             b < dgbT6RowCount();
             ++b) {
            int vals[1];
            vals[0] = dgbT6MagicAttack(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT6[b][c])
                    ++bad;
            }
        }
        // the Table 7 grid: the henchmen, loyalty base and reaction
        // adjustment columns across Charisma 3-18 (capture p. 12)
        int CT7[16][3] = {
            {1,-30,-25},
            {1,-25,-20},
            {2,-20,-15},
            {2,-15,-10},
            {3,-10,-5},
            {3,-5,0},
            {4,0,0},
            {4,0,0},
            {4,0,0},
            {5,0,0},
            {5,0,5},
            {6,5,10},
            {7,15,15},
            {8,20,25},
            {10,30,30},
            {15,40,35},
            };
        for (int b = 0;
             b < dgbT7RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgbT7Henchmen(b);
            vals[1] = dgbT7Loyalty(b);
            vals[2] = dgbT7Reaction(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT7[b][c])
                    ++bad;
            }
        }
        // the Table 8 grid: the nine Charisma bands and their Comeliness
        // adjustments (capture p. 13)
        int CT8[9][2] = {
            {2,-8},
            {3,-5},
            {5,-3},
            {8,-1},
            {12,0},
            {15,1},
            {17,2},
            {18,3},
            {19,5},
            };
        for (int b = 0;
             b < dgbT8RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgbT8ChaMax(b);
            vals[1] = dgbT8Adj(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT8[b][c])
                    ++bad;
            }
        }
        // the dgbT8Band band-for boundaries
    if (dgbT8Band(1) != 0
            || dgbT8Band(2) != 0
            || dgbT8Band(3) != 1
            || dgbT8Band(3) != 1
            || dgbT8Band(5) != 2
            || dgbT8Band(4) != 2
            || dgbT8Band(8) != 3
            || dgbT8Band(6) != 3
            || dgbT8Band(12) != 4
            || dgbT8Band(9) != 4
            || dgbT8Band(15) != 5
            || dgbT8Band(13) != 5
            || dgbT8Band(17) != 6
            || dgbT8Band(16) != 6
            || dgbT8Band(18) != 7
            || dgbT8Band(18) != 7
            || dgbT8Band(19) != 8
        )
            ++bad;
        // the dgbMinStrWuJen pin
    if (dgbMinStrWuJen() != 3
        )
            ++bad;
        // the dgbMinStrSpiritFolk pin
    if (dgbMinStrSpiritFolk() != 6
        )
            ++bad;
        // the dgbMinStrKorobokuru pin
    if (dgbMinStrKorobokuru() != 8
        )
            ++bad;
        // the dgbMinStrShukenja pin
    if (dgbMinStrShukenja() != 9
        )
            ++bad;
        // the dgbMinStrBushi pin
    if (dgbMinStrBushi() != 9
        )
            ++bad;
        // the dgbMinStrHengeyokai pin
    if (dgbMinStrHengeyokai() != 12
        )
            ++bad;
        // the dgbMinStrKensai pin
    if (dgbMinStrKensai() != 12
        )
            ++bad;
        // the dgbMinStrSamurai pin
    if (dgbMinStrSamurai() != 13
        )
            ++bad;
        // the dgbMinStrSohei pin
    if (dgbMinStrSohei() != 13
        )
            ++bad;
        // the dgbMinStrBarbarian pin
    if (dgbMinStrBarbarian() != 15
        )
            ++bad;
        // the dgbMinStrMonk pin
    if (dgbMinStrMonk() != 15
        )
            ++bad;
        // the dgbMaxStrShukenja pin
    if (dgbMaxStrShukenja() != 18
        )
            ++bad;
        // the dgbMaxStrMonk pin
    if (dgbMaxStrMonk() != 18
        )
            ++bad;
        // the dgbMaxStrWuJen pin
    if (dgbMaxStrWuJen() != 18
        )
            ++bad;
        // the dgbMaxStrYakuza pin
    if (dgbMaxStrYakuza() != 18
        )
            ++bad;
        // the dgbMaxStrHuman pin
    if (dgbMaxStrHuman() != 18
        )
            ++bad;
        // the dgbMaxStrKorobokuru pin
    if (dgbMaxStrKorobokuru() != 19
        )
            ++bad;
        // the dgbT2OpenDoorsRetry pin
    if (dgbT2OpenDoorsRetry() != 1
        )
            ++bad;
        // the dgbT2LockedOneAttempt pin
    if (dgbT2LockedOneAttempt() != 1
        )
            ++bad;
        // the dgbT2BendBarsOneAttempt pin
    if (dgbT2BendBarsOneAttempt() != 1
        )
            ++bad;
        // the dgbT2DmgFloorOne pin
    if (dgbT2DmgFloorOne() != 1
        )
            ++bad;
        // the dgbT2WeightSlowdown pin
    if (dgbT2WeightSlowdown() != 1
        )
            ++bad;
        // the dgbT2RowCount pin
    if (dgbT2RowCount() != 16
        )
            ++bad;
        // the dgbMinDexKorobokuru pin
    if (dgbMinDexKorobokuru() != 6
        )
            ++bad;
        // the dgbMinDexBushi pin
    if (dgbMinDexBushi() != 8
        )
            ++bad;
        // the dgbMinDexHengeyokai pin
    if (dgbMinDexHengeyokai() != 9
        )
            ++bad;
        // the dgbMinDexSpiritFolk pin
    if (dgbMinDexSpiritFolk() != 12
        )
            ++bad;
        // the dgbMinDexKensai pin
    if (dgbMinDexKensai() != 14
        )
            ++bad;
        // the dgbMinDexBarbarian pin
    if (dgbMinDexBarbarian() != 14
        )
            ++bad;
        // the dgbMinDexNinja pin
    if (dgbMinDexNinja() != 14
        )
            ++bad;
        // the dgbMinDexMonk pin
    if (dgbMinDexMonk() != 15
        )
            ++bad;
        // the dgbT3RowCount pin
    if (dgbT3RowCount() != 17
        )
            ++bad;
        // the dgbMinConSpiritFolk pin
    if (dgbMinConSpiritFolk() != 6
        )
            ++bad;
        // the dgbMinConBushi pin
    if (dgbMinConBushi() != 8
        )
            ++bad;
        // the dgbMinConShukenja pin
    if (dgbMinConShukenja() != 9
        )
            ++bad;
        // the dgbMinConSohei pin
    if (dgbMinConSohei() != 10
        )
            ++bad;
        // the dgbMinConMonk pin
    if (dgbMinConMonk() != 11
        )
            ++bad;
        // the dgbMinConKorobokuru pin
    if (dgbMinConKorobokuru() != 12
        )
            ++bad;
        // the dgbMinConHengeyokai pin
    if (dgbMinConHengeyokai() != 12
        )
            ++bad;
        // the dgbMinConSamurai pin
    if (dgbMinConSamurai() != 13
        )
            ++bad;
        // the dgbMaxConSpiritFolk pin
    if (dgbMaxConSpiritFolk() != 14
        )
            ++bad;
        // the dgbMinConBarbarian pin
    if (dgbMinConBarbarian() != 15
        )
            ++bad;
        // the dgbT4RowCount pin
    if (dgbT4RowCount() != 16
        )
            ++bad;
        // the dgbT4HitDieFloorOne pin
    if (dgbT4HitDieFloorOne() != 1
        )
            ++bad;
        // the dgbT4WarriorFullCon pin
    if (dgbT4WarriorFullCon() != 1
        )
            ++bad;
        // the dgbT4BarbarianFullCon pin
    if (dgbT4BarbarianFullCon() != 1
        )
            ++bad;
        // the dgbT4OthersCapTwo pin
    if (dgbT4OthersCapTwo() != 1
        )
            ++bad;
        // the dgbMinIntKorobokuru pin
    if (dgbMinIntKorobokuru() != 3
        )
            ++bad;
        // the dgbMinIntHengeyokai pin
    if (dgbMinIntHengeyokai() != 12
        )
            ++bad;
        // the dgbMinIntSpiritFolk pin
    if (dgbMinIntSpiritFolk() != 12
        )
            ++bad;
        // the dgbMinIntWuJen pin
    if (dgbMinIntWuJen() != 13
        )
            ++bad;
        // the dgbMinIntSamurai pin
    if (dgbMinIntSamurai() != 14
        )
            ++bad;
        // the dgbMinIntNinja pin
    if (dgbMinIntNinja() != 15
        )
            ++bad;
        // the dgbMaxIntKorobokuru pin
    if (dgbMaxIntKorobokuru() != 15
        )
            ++bad;
        // the dgbT5RowCount pin
    if (dgbT5RowCount() != 16
        )
            ++bad;
        // the dgbMinWisSpiritFolk pin
    if (dgbMinWisSpiritFolk() != 9
        )
            ++bad;
        // the dgbMinWisSohei pin
    if (dgbMinWisSohei() != 10
        )
            ++bad;
        // the dgbMinWisKensai pin
    if (dgbMinWisKensai() != 12
        )
            ++bad;
        // the dgbMinWisShukenja pin
    if (dgbMinWisShukenja() != 12
        )
            ++bad;
        // the dgbMinWisHengeyokai pin
    if (dgbMinWisHengeyokai() != 12
        )
            ++bad;
        // the dgbMinWisSamurai pin
    if (dgbMinWisSamurai() != 13
        )
            ++bad;
        // the dgbMinWisMonk pin
    if (dgbMinWisMonk() != 15
        )
            ++bad;
        // the dgbMaxWisBarbarian pin
    if (dgbMaxWisBarbarian() != 16
        )
            ++bad;
        // the dgbMaxWisKorobokuru pin
    if (dgbMaxWisKorobokuru() != 17
        )
            ++bad;
        // the dgbT6RowCount pin
    if (dgbT6RowCount() != 16
        )
            ++bad;
        // the dgbT6MindAuto pin
    if (dgbT6MindAuto() != 1
        )
            ++bad;
        // the dgbMinChaHengeyokai pin
    if (dgbMinChaHengeyokai() != 12
        )
            ++bad;
        // the dgbMinChaSpiritFolk pin
    if (dgbMinChaSpiritFolk() != 14
        )
            ++bad;
        // the dgbMinChaNinja pin
    if (dgbMinChaNinja() != 14
        )
            ++bad;
        // the dgbMaxChaKorobokuru pin
    if (dgbMaxChaKorobokuru() != 16
        )
            ++bad;
        // the dgbMaxChaHengeyokai pin
    if (dgbMaxChaHengeyokai() != 17
        )
            ++bad;
        // the dgbT7RowCount pin
    if (dgbT7RowCount() != 16
        )
            ++bad;
        // the dgbT8RowCount pin
    if (dgbT8RowCount() != 9
        )
            ++bad;
        // the Table 8 band chain: Charisma 3 lands band 1
    if (dgbT8Band(3) != 1
        )
            ++bad;
        // the Table 8 band chain: Charisma 19 lands band 8
    if (dgbT8Band(19) != 8
        )
            ++bad;
        // the Table 2 18/00 row (capture p. 8)
    if (dgbT2HitProb(14) != 3
            || dgbT2DmgAdj(14) != 6
            || dgbT2Weight(14) != 3350
            || dgbT2BendPct(14) != 40
        )
            ++bad;
        // the Table 2 Str 19 row prints 7-in-8 with the locked 3 (capture p.
        // 8)
    if (dgbT2OpenMax(15) != 7
            || dgbT2OpenLocked(15) != 3
        )
            ++bad;
        // the Table 3 Dexterity 18 row (capture p. 9)
    if (dgbT3Reaction(15) != 2
            || dgbT3Defensive(15) != -3
        )
            ++bad;
        // the Table 4 Constitution 18 row: the warrior +4 and the 100 percent
        // resurrection (capture p. 10)
    if (dgbT4WarriorHpAdj(15) != 4
            || dgbT4ResPct(15) != 100
        )
            ++bad;
        // the Table 4 warrior column diverges from the common column only at
        // 17 and 18 (capture p. 10)
    if (dgbT4WarriorHpAdj(13) != dgbT4HpAdj(13)
        )
            ++bad;
        // the Table 5 Intelligence 18 row (capture p. 11)
    if (dgbT5Languages(15) != 7
            || dgbT5MaxSpellLevel(15) != 9
        )
            ++bad;
        // the Table 6 Wisdom 18 row (capture pp. 11-12)
    if (dgbT6MagicAttack(15) != 4
        )
            ++bad;
        // the Table 7 Charisma 18 row (capture p. 12)
    if (dgbT7Henchmen(15) != 15
            || dgbT7Loyalty(15) != 40
            || dgbT7Reaction(15) != 35
        )
            ++bad;
        // the Table 8 chain and grid agree: Charisma 18 adjusts +3 (capture
        // p. 13)
    if (dgbT8Adj(dgbT8Band(18)) != 3
        )
            ++bad;
        // the Table 8 chain and grid agree: Charisma 2 adjusts -8 (capture p.
        // 13)
    if (dgbT8Adj(dgbT8Band(2)) != -8
        )
            ++bad;
        printf("R615 OA ability tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
