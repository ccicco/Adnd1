    // ---- R646 OA barding audit ----
    // OA round thirty-three (capture p. 98): the Table 55 barded warhorse
    // base movement rates - the full/half barding pairs and the too-heavy X
    {
        using namespace rules;
        int bad = 0;
    if (dhgT55RowCount() != 4
            || dhgT55MatCount() != 3
            || !dhgT55FullBeforeSlash()
            || !dhgT55XTooHeavy()
        )
            ++bad;
        // the Table 55 grid: the full/half barding movement pairs and the X
        int CT55Data[4][6] = {
            {21,24,15,21,-99,15},
            {17,18,15,17,12,15},
            {15,15,14,15,13,15},
            {12,12,-99,-99,-99,-99},
            };
        int nT55Data[6] = {0,0,0,0,0,0};
        int eT55Data[6] = {0,0,1,1,2,1};
        for (int b = 0;
             b < dhgT55RowCount();
             ++b) {
            int vals[6];
            vals[0] = dhgT55PaddedFull(b);
            vals[1] = dhgT55PaddedHalf(b);
            vals[2] = dhgT55MetalFull(b);
            vals[3] = dhgT55MetalHalf(b);
            vals[4] = dhgT55ChainFull(b);
            vals[5] = dhgT55ChainHalf(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT55Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT55Data[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (nT55Data[c] != eT55Data[c])
                ++bad;
        // the T55 row count pin
    if (dhgT55RowCount() != 4
        )
            ++bad;
        // the T55 material count pin
    if (dhgT55MatCount() != 3
        )
            ++bad;
        // the full-before-slash note pin
    if (dhgT55FullBeforeSlash() != 1
        )
            ++bad;
        // the X-too-heavy note pin
    if (dhgT55XTooHeavy() != 1
        )
            ++bad;
        // the light row - the padded pair 21/24, half barding faster than
        // full (capture p. 98)
    if (dhgT55PaddedFull(0) != 21
            || dhgT55PaddedHalf(0) != 24
        )
            ++bad;
        // the light row chain cell - the too-heavy X as -99 beside the 15
        // half-barding rate (capture p. 98)
    if (dhgT55ChainFull(0) != -99
            || dhgT55ChainHalf(0) != 15
        )
            ++bad;
        // the light row metal-scale pair - the 15/21 with the print-pass
        // stray-space glyph artifact (capture p. 98)
    if (dhgT55MetalFull(0) != 15
            || dhgT55MetalHalf(0) != 21
        )
            ++bad;
        // the medium row - the 17/18 padded, 15/17 metal and 12/15 chain
        // pairs (capture p. 98)
    if (dhgT55PaddedFull(1) != 17
            || dhgT55MetalFull(1) != 15
            || dhgT55ChainFull(1) != 12
            || dhgT55ChainHalf(1) != 15
        )
            ++bad;
        // the heavy row - the 15/15 padded, 14/15 metal and 13/15 chain pairs
        // (capture p. 98)
    if (dhgT55PaddedFull(2) != 15
            || dhgT55MetalFull(2) != 14
            || dhgT55ChainFull(2) != 13
        )
            ++bad;
        // the elephant row - the lone 12 as the lo=hi convention, the metal
        // and chain cells blank as -99 (capture p. 98)
    if (dhgT55PaddedFull(3) != 12
            || dhgT55PaddedHalf(3) != 12
            || dhgT55MetalFull(3) != -99
            || dhgT55ChainFull(3) != -99
            || dhgT55ChainHalf(3) != -99
        )
            ++bad;
        printf("R646 OA barding audit: bad %d\n", bad);
        if (bad) return 1;
    }
