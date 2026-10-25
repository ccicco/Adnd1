    // ---- R641 OA handheld audit ----
    // OA round twenty-eight (capture p. 80): the Table 50 hand-held weapons
    // grid - the general data and the to-hit adjustments
    {
        using namespace rules;
        int bad = 0;
    if (dhbT50RowCount() != 49
            || dhbT50AcCount() != 11
            || !dhbT50ChijirikiSeeChain()
        )
            ++bad;
        // the Table 50 grid: the speed factor bounds, the AC 0-10 ladder and
        // the footnote bitmask letters
        int CT50Data[49][14] = {
            {7,7,-5,-4,-3,-2,-1,-1,0,0,1,1,2,0},
            {4,4,-5,-4,-3,-2,-2,-1,0,0,1,1,2,0},
            {3,3,-13,-11,-9,-7,-5,-3,-1,0,1,0,3,0},
            {4,4,-7,-6,-5,-4,-3,-2,-1,0,0,-1,0,0},
            {5,5,-8,-8,-7,-7,-5,-5,-2,0,0,1,0,0},
            {6,8,-2,-2,-2,-1,-1,-1,0,0,0,0,0,0},
            {-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,0},
            {2,2,-16,-14,-12,-10,-8,-6,-4,-2,-1,-1,-1,0},
            {4,4,-7,-6,-5,-4,-3,-2,-1,-1,0,0,1,0},
            {2,2,-4,-4,-3,-3,-2,-2,0,0,1,1,3,0},
            {4,4,-5,-4,-3,-2,-1,0,0,0,0,0,0,0},
            {2,2,-14,-12,-10,-8,-6,-4,-3,-2,0,-1,0,0},
            {9,9,0,1,1,1,1,2,2,2,1,1,0,0},
            {2,2,-4,-3,-2,-1,0,0,0,0,0,-2,0,0},
            {2,2,-10,-9,-8,-6,-4,-1,-1,0,1,0,2,0},
            {4,4,-5,-4,-3,-2,-1,0,0,0,1,2,3,0},
            {6,6,3,3,2,2,1,2,1,1,1,1,-1,0},
            {7,7,-8,-8,-8,-6,-6,-4,-4,-2,-1,-2,0,0},
            {3,3,-7,-6,-5,-4,-3,-2,-1,-1,0,0,1,0},
            {4,4,-6,-6,-5,-5,-3,-2,-2,-1,-1,0,1,0},
            {6,6,-3,-2,-1,-1,-1,1,1,1,0,-1,2,0},
            {5,5,-8,-8,-8,-6,-6,-4,-4,-2,-1,-2,1,0},
            {6,6,-3,-3,-3,-2,-2,-1,0,0,1,1,3,0},
            {7,7,-3,-3,-2,-2,-1,0,0,0,0,0,0,0},
            {10,10,0,0,0,0,0,0,0,0,0,0,0,0},
            {7,7,2,2,1,1,0,0,0,0,0,1,-1,128},
            {7,7,0,0,0,0,0,0,0,0,-1,-2,-3,0},
            {6,6,-3,-3,-2,-2,-1,0,0,0,0,0,0,0},
            {7,7,-2,-2,-1,-1,0,0,0,0,0,0,0,0},
            {2,2,-8,-7,-7,-6,-5,-4,-3,-2,-1,0,0,0},
            {3,3,-5,-4,-3,-2,-1,0,0,0,1,0,2,0},
            {3,3,-8,-7,-6,-4,-2,-2,0,0,1,0,3,0},
            {4,4,-5,-5,-4,-4,-3,-1,0,0,0,1,2,0},
            {2,2,-4,-3,-2,-1,0,0,0,0,0,-2,0,0},
            {7,7,-7,-6,-5,-4,-3,-2,-1,0,0,0,1,0},
            {3,3,-8,-7,-6,-5,-4,-3,-2,-1,0,-1,0,0},
            {7,7,-10,-9,-9,-8,-6,-6,-4,-3,0,0,2,0},
            {6,8,-2,-2,-2,-1,-1,-1,0,0,0,0,0,0},
            {5,5,-5,-4,-3,-2,-1,0,0,1,1,1,2,0},
            {5,5,-4,-3,-2,-1,0,0,0,0,0,1,2,0},
            {3,3,-5,-4,-3,-2,-1,0,0,0,1,0,2,0},
            {10,10,2,2,2,2,2,2,3,3,3,1,0,0},
            {4,4,0,0,0,0,0,0,0,0,0,0,0,8},
            {7,7,2,2,1,1,0,0,0,0,0,1,-1,0},
            {7,7,-2,-2,-2,-1,-1,0,0,0,0,1,0,0},
            {6,8,-4,-3,-3,-2,-1,-1,0,0,1,0,1,0},
            {4,4,-8,-8,-6,-6,-4,-2,0,0,0,1,2,0},
            {4,4,-5,-4,-3,-2,-1,0,0,0,1,0,0,0},
            {5,8,-14,-12,-10,-8,-6,-4,-2,-1,1,0,3,0},
            };
        int nT50Data[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int eT50Data[14] = {1,1,1,1,1,1,1,1,1,1,1,1,1,0};
        for (int b = 0;
             b < dhbT50RowCount();
             ++b) {
            int vals[14];
            vals[0] = dhbT50SpeedLo(b);
            vals[1] = dhbT50SpeedHi(b);
            vals[2] = dhbT50Ac0(b);
            vals[3] = dhbT50Ac1(b);
            vals[4] = dhbT50Ac2(b);
            vals[5] = dhbT50Ac3(b);
            vals[6] = dhbT50Ac4(b);
            vals[7] = dhbT50Ac5(b);
            vals[8] = dhbT50Ac6(b);
            vals[9] = dhbT50Ac7(b);
            vals[10] = dhbT50Ac8(b);
            vals[11] = dhbT50Ac9(b);
            vals[12] = dhbT50Ac10(b);
            vals[13] = dhbT50LNote(b);
            for (int c = 0; c < 14;
                 ++c) {
                if (vals[c] != CT50Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT50Data[c];
            }
        }
        for (int c = 0; c < 14; ++c)
            if (nT50Data[c] != eT50Data[c])
                ++bad;
        // the T50 row count pin
    if (dhbT50RowCount() != 49
        )
            ++bad;
        // the T50 AC ladder width pin
    if (dhbT50AcCount() != 11
        )
            ++bad;
        // the ChijirikiSeeChain pin
    if (dhbT50ChijirikiSeeChain() != 1
        )
            ++bad;
        // the katana row - the contested AC-8 cell settles +1 per the print
        // capture (the compressed -1 dips non-monotonically between the AC-7
        // zero and the AC-9 plus-two)
    if (dhbT50Ac8(15) != 1
        )
            ++bad;
        // the sword, short row - the contested AC-8 cell settles +1 per the
        // print capture (the same compressed dip class)
    if (dhbT50Ac8(40) != 1
        )
            ++bad;
        // the tui-fa row - the contested AC-9 cell settles +1 per the print
        // capture (the compressed -1 dips between the AC-8 zero and the AC-10
        // plus-two)
    if (dhbT50Ac9(46) != 1
        )
            ++bad;
        // the jo stick row - the contested AC-5 cell settles -1 per the print
        // capture (both readings ladder-consistent, the settling print read
        // stands over the compressed -2)
    if (dhbT50Ac5(14) != -1
        )
            ++bad;
        // the bo stick row - the steepest ladder, AC 0 at -13 and AC 10 at
        // plus-three (capture p. 80)
    if (dhbT50Ac0(2) != -13
            || dhbT50Ac10(2) != 3
        )
            ++bad;
        // the chopsticks row - the AC-0 floor at -16 (capture p. 80)
    if (dhbT50Ac0(7) != -16
        )
            ++bad;
        // the chijiriki, chain row - the -99 dashes across the grid, the
        // cross-ref bool
    if (dhbT50SpeedLo(6) != -99
            || dhbT50Ac0(6) != -99
            || dhbT50Ac10(6) != -99
        )
            ++bad;
        // the chijiriki, spear row - the 6-8 speed range (capture p. 80)
    if (dhbT50SpeedLo(5) != 6
            || dhbT50SpeedHi(5) != 8
        )
            ++bad;
        // the spear row - the 6-8 speed range, the flat upper ladder (capture
        // p. 80)
    if (dhbT50SpeedLo(37) != 6
            || dhbT50SpeedHi(37) != 8
            || dhbT50Ac5(37) != -1
        )
            ++bad;
        // the whip row - the 5-8 speed range, the AC-0 at -14 (capture p. 80)
    if (dhbT50SpeedLo(48) != 5
            || dhbT50SpeedHi(48) != 8
            || dhbT50Ac0(48) != -14
        )
            ++bad;
        // the mace row - the h footnote letter, bitmask 128 (capture p. 80)
    if (dhbT50LNote(25) != 128
        )
            ++bad;
        // the tetsu-bishi row - the d footnote letter 8, the zero space
        // pinning as data (capture p. 80)
    if (dhbT50LNote(42) != 8
        )
            ++bad;
        // the lasso row - the all-zero ladder with speed 10 (capture p. 80)
    if (dhbT50Ac0(24) != 0
            || dhbT50Ac10(24) != 0
            || dhbT50SpeedLo(24) != 10
        )
            ++bad;
        // the sword, two-handed row - the +2 plateau into the +3 band
        // (capture p. 80)
    if (dhbT50Ac0(41) != 2
            || dhbT50Ac6(41) != 3
        )
            ++bad;
        // the man catcher row - the zero ladder breaking at AC 8 through 10
        // (capture p. 80)
    if (dhbT50Ac8(26) != -1
            || dhbT50Ac10(26) != -3
        )
            ++bad;
        // the kawanga row - the AC-0 at -8, the printed spelling per the R640
        // settle riding the roster
    if (dhbT50Ac0(17) != -8
        )
            ++bad;
        printf("R641 OA handheld audit: bad %d\n", bad);
        if (bad) return 1;
    }
