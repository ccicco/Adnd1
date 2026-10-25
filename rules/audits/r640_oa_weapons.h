    // ---- R640 OA weapons audit ----
    // OA round twenty-seven (capture pp. 79-80): the weapons opener, the
    // weapon equivalents and the Table 49 weight-damage grid
    {
        using namespace rules;
        int bad = 0;
    if (dhaT48RowCount() != 16
            || dhaT49RowCount() != 69
            || !dhaWeaponsEnglishNames()
            || !dhaWeaponsManyNames()
            || !dhaWeaponsAppearanceDiff()
            || !dhaWeaponsFunctionSame()
            || !dhaT49BoldfaceTwoHands()
            || !dhaT49StarSetNote()
            || !dhaT49NoteA()
            || !dhaT49NoteB()
            || !dhaT49NoteC()
            || !dhaT49NoteD()
            || !dhaT49NoteE()
            || !dhaT49NoteF()
            || !dhaT49NoteG()
            || !dhaT49NoteH()
        )
            ++bad;
        // the Table 48 grid: the equivalent-name counts (capture p. 79)
        int CT48Equiv[16][1] = {
            {11},
            {2},
            {2},
            {2},
            {4},
            {4},
            {1},
            {2},
            {2},
            {1},
            {2},
            {1},
            {1},
            {1},
            {1},
            {2},
            };
        int nT48Equiv[1] = {0};
        int eT48Equiv[1] = {0};
        for (int b = 0;
             b < dhaT48RowCount();
             ++b) {
            int vals[1];
            vals[0] = dhaT48EquivCount(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT48Equiv[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT48Equiv[c];
            }
        }
        for (int c = 0; c < 1; ++c)
            if (nT48Equiv[c] != eT48Equiv[c])
                ++bad;
        // the Table 49 grid: weights, damage bounds, footnote bitmasks, stars
        // (capture p. 79)
        int CT49Data[69][9] = {
            {2,2,2,5,1,4,0,0,0},
            {2,2,1,6,1,3,0,0,0},
            {2,2,1,2,1,2,0,0,0},
            {2,2,1,8,1,6,0,0,0},
            {2,2,1,6,1,6,0,0,0},
            {75,75,1,8,1,8,0,128,0},
            {50,50,1,6,1,4,0,128,0},
            {40,40,1,6,1,4,0,32,0},
            {30,30,1,4,1,2,0,0,0},
            {30,30,2,5,1,4,0,224,0},
            {60,60,1,6,1,8,0,64,0},
            {1,1,1,3,1,2,0,0,0},
            {30,30,1,6,1,3,0,0,0},
            {10,10,1,4,1,3,0,0,0},
            {1,1,1,2,1,1,0,0,0},
            {5,5,1,3,1,2,0,0,0},
            {30,30,1,6,1,4,0,16,0},
            {10,10,1,3,1,2,0,32,0},
            {175,175,1,10,1,12,0,128,0},
            {20,20,1,6,1,6,0,0,1},
            {15,15,1,4,1,2,0,16,0},
            {15,15,1,6,1,3,0,32,0},
            {20,20,1,6,1,4,0,0,0},
            {60,60,1,10,1,12,0,0,0},
            {40,40,1,8,1,6,0,16,0},
            {10,10,1,3,1,2,0,72,0},
            {5,5,1,4,1,2,0,32,0},
            {15,15,1,4,1,3,0,8,0},
            {30,30,1,6,1,4,0,72,0},
            {10,10,1,4,1,4,0,72,0},
            {60,60,1,10,1,10,0,32,0},
            {50,50,1,6,1,8,0,1,0},
            {20,20,-99,-99,-99,-99,0,0,0},
            {100,100,2,7,1,6,0,0,0},
            {80,80,1,2,1,2,0,0,0},
            {60,60,1,6,1,8,0,2,0},
            {100,100,1,8,1,10,0,2,1},
            {1,1,1,1,-99,-99,8,0,0},
            {5,5,1,4,1,3,0,8,0},
            {50,50,1,8,1,6,0,8,0},
            {30,30,1,6,1,6,0,16,0},
            {50,50,1,8,1,8,0,0,0},
            {2,2,2,5,2,7,0,0,0},
            {1,1,1,4,1,4,0,0,0},
            {20,20,1,4,1,2,0,16,0},
            {100,100,1,8,1,6,0,16,0},
            {5,5,1,4,1,4,0,8,0},
            {1,1,1,4,1,3,0,8,0},
            {2,2,1,6,1,4,0,8,0},
            {1,1,1,4,1,4,0,8,0},
            {5,5,2,5,1,4,0,16,0},
            {2,2,2,5,2,7,0,0,0},
            {1,1,1,4,1,4,0,0,0},
            {5,5,2,8,3,9,0,0,0},
            {4,4,1,8,2,8,0,0,0},
            {50,50,1,4,1,3,0,64,0},
            {40,60,1,6,1,8,0,34,1},
            {75,75,2,8,2,7,0,128,0},
            {60,60,1,8,1,12,0,128,0},
            {35,35,1,6,1,8,0,132,0},
            {150,250,1,10,3,18,0,128,0},
            {3,3,1,4,1,4,0,8,0},
            {75,75,1,8,1,8,0,32,0},
            {50,50,1,6,1,4,0,16,0},
            {50,50,2,7,3,12,0,128,0},
            {15,15,1,6,1,4,0,16,0},
            {5,5,1,4,1,4,0,0,0},
            {30,30,1,8,1,8,0,0,0},
            {25,35,1,2,1,1,0,64,0},
            };
        int nT49Data[9] = {0,0,0,0,0,0,0,0,0};
        int eT49Data[9] = {0,0,1,1,2,2,0,0,0};
        for (int b = 0;
             b < dhaT49RowCount();
             ++b) {
            int vals[9];
            vals[0] = dhaT49WeightLo(b);
            vals[1] = dhaT49WeightHi(b);
            vals[2] = dhaT49SmLo(b);
            vals[3] = dhaT49SmHi(b);
            vals[4] = dhaT49LLo(b);
            vals[5] = dhaT49LHi(b);
            vals[6] = dhaT49SmNote(b);
            vals[7] = dhaT49LNote(b);
            vals[8] = dhaT49Star(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CT49Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT49Data[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nT49Data[c] != eT49Data[c])
                ++bad;
        // the T48 row count pin
    if (dhaT48RowCount() != 16
        )
            ++bad;
        // the T49 row count pin
    if (dhaT49RowCount() != 69
        )
            ++bad;
        // the WeaponsEnglishNames pin
    if (dhaWeaponsEnglishNames() != 1
        )
            ++bad;
        // the WeaponsManyNames pin
    if (dhaWeaponsManyNames() != 1
        )
            ++bad;
        // the WeaponsAppearanceDiff pin
    if (dhaWeaponsAppearanceDiff() != 1
        )
            ++bad;
        // the WeaponsFunctionSame pin
    if (dhaWeaponsFunctionSame() != 1
        )
            ++bad;
        // the T49BoldfaceTwoHands pin
    if (dhaT49BoldfaceTwoHands() != 1
        )
            ++bad;
        // the T49StarSetNote pin
    if (dhaT49StarSetNote() != 1
        )
            ++bad;
        // the T49NoteA pin
    if (dhaT49NoteA() != 1
        )
            ++bad;
        // the T49NoteB pin
    if (dhaT49NoteB() != 1
        )
            ++bad;
        // the T49NoteC pin
    if (dhaT49NoteC() != 1
        )
            ++bad;
        // the T49NoteD pin
    if (dhaT49NoteD() != 1
        )
            ++bad;
        // the T49NoteE pin
    if (dhaT49NoteE() != 1
        )
            ++bad;
        // the T49NoteF pin
    if (dhaT49NoteF() != 1
        )
            ++bad;
        // the T49NoteG pin
    if (dhaT49NoteG() != 1
        )
            ++bad;
        // the T49NoteH pin
    if (dhaT49NoteH() != 1
        )
            ++bad;
        // the T48 axe battle row - the eleven equivalents (capture p. 79)
    if (dhaT48EquivCount(0) != 11
        )
            ++bad;
        // the T48 dagger and halberd rows - four equivalents apiece; the lone
        // spear yari (capture p. 79)
    if (dhaT48EquivCount(4) != 4
            || dhaT48EquivCount(5) != 4
            || dhaT48EquivCount(11) != 1
        )
            ++bad;
        // the T49 katana row - weight 60, 1-10 vs S-M, 1-12 vs L (capture p.
        // 79)
    if (dhaT49WeightLo(23) != 60
            || dhaT49SmLo(23) != 1
            || dhaT49SmHi(23) != 10
            || dhaT49LLo(23) != 1
            || dhaT49LHi(23) != 12
        )
            ++bad;
        // the T49 halberd row - weight 175, 1-10 vs S-M, 1-12 vs L with the h
        // letter (capture p. 79)
    if (dhaT49WeightLo(18) != 175
            || dhaT49SmHi(18) != 10
            || dhaT49LHi(18) != 12
            || dhaT49LNote(18) != 128
        )
            ++bad;
        // the T49 chain row - the f, g, h letters bitmask 224 (capture p. 79)
    if (dhaT49LNote(9) != 224
            || dhaT49WeightLo(9) != 30
        )
            ++bad;
        // the T49 spear row - the 40-60 weight range, the b and f letters 34,
        // the star (capture p. 79)
    if (dhaT49WeightLo(56) != 40
            || dhaT49WeightHi(56) != 60
            || dhaT49LNote(56) != 34
            || dhaT49Star(56) != 1
        )
            ++bad;
        // the T49 two-handed sword row - the 150-250 weight range, 1-10 vs
        // S-M, 3-18 vs L (capture p. 79)
    if (dhaT49WeightLo(60) != 150
            || dhaT49WeightHi(60) != 250
            || dhaT49LLo(60) != 3
            || dhaT49LHi(60) != 18
        )
            ++bad;
        // the T49 lasso row - no damage, the -99 dashes (capture p. 79)
    if (dhaT49SmLo(32) != -99
            || dhaT49SmHi(32) != -99
            || dhaT49LLo(32) != -99
            || dhaT49LHi(32) != -99
            || dhaT49WeightLo(32) != 20
        )
            ++bad;
        // the T49 needle row - 1 per needle with the d letter, the blank vs-L
        // cell (capture p. 79)
    if (dhaT49SmLo(37) != 1
            || dhaT49SmHi(37) != 1
            || dhaT49SmNote(37) != 8
            || dhaT49LLo(37) != -99
        )
            ++bad;
        // the T49 whip row - the 25-35 weight range, 1-2 vs S-M, 1 vs L with
        // the g letter (capture p. 79)
    if (dhaT49WeightLo(68) != 25
            || dhaT49WeightHi(68) != 35
            || dhaT49LHi(68) != 1
            || dhaT49LNote(68) != 64
        )
            ++bad;
        // the T49 sword short row - the c and h letters bitmask 132 (capture
        // p. 79)
    if (dhaT49LNote(59) != 132
            || dhaT49WeightLo(59) != 35
        )
            ++bad;
        // the T49 stars - the javelin, naginata and spear; the unstarred
        // katana (capture p. 79)
    if (dhaT49Star(19) != 1
            || dhaT49Star(36) != 1
            || dhaT49Star(23) != 0
        )
            ++bad;
        printf("R640 OA weapons audit: bad %d\n", bad);
        if (bad) return 1;
    }
