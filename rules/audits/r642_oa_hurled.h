    // ---- R642 OA hurled audit ----
    // OA round twenty-nine (capture pp. 80-81): the Table 51 hurled weapons
    // and missiles grid - the fire rates, ranges and the to-hit adjustments
    {
        using namespace rules;
        int bad = 0;
    if (dhcT51RowCount() != 28
            || dhcT51AcCount() != 11
            || dhcT51MediumAdjust() != -2
            || dhcT51LongAdjust() != -5
            || !dhcT51AcAtShortRange()
            || !dhcT51StarFeetNote()
            || !dhcT51DoubleStarSeeDescription()
        )
            ++bad;
        // the Table 51 grid: the AC 0-10 ladder, the footnote bitmask letters
        // and the star set
        int CT51Data[28][13] = {
            {-6,-5,-4,-3,-2,-1,-1,0,0,0,1,0,0},
            {-14,-12,-10,-8,-6,-4,-2,-1,-1,1,2,0,0},
            {-4,-4,-3,-3,-1,0,1,2,2,2,3,0,0},
            {-7,-6,-5,-4,-1,0,0,1,2,2,3,0,0},
            {-4,-3,-3,-2,-1,0,0,1,2,3,3,0,0},
            {-9,-8,-7,-5,-3,-2,-1,-1,-1,0,0,0,0},
            {-2,-1,-1,0,1,2,3,3,4,4,4,0,0},
            {-3,-2,-2,-1,0,0,1,2,3,3,3,0,0},
            {-7,-6,-5,-4,-3,-2,-1,-1,0,0,1,0,0},
            {-1,0,0,0,0,1,2,3,4,4,4,0,0},
            {-7,-6,-5,-4,-3,-2,-1,0,1,0,1,0,0},
            {-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,8,0},
            {-5,-5,-4,-4,-2,-1,0,0,1,2,2,8,0},
            {-7,-6,-5,-4,-3,-2,-1,-1,0,0,1,128,0},
            {9,8,7,6,5,4,3,2,1,0,-1,0,0},
            {-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,-99,8,1},
            {-16,-14,-12,-10,-10,-8,-6,-4,-2,-3,0,0,1},
            {-3,-2,-2,-1,0,0,1,2,3,3,3,0,0},
            {-7,-6,-5,-4,-3,-2,-1,0,1,0,1,0,0},
            {-7,-6,-5,-4,-3,-2,-1,0,1,0,1,0,0},
            {-7,-6,-5,-4,-3,-2,-1,0,1,0,1,0,0},
            {-7,-6,-5,-4,-3,-2,-1,0,1,0,1,0,0},
            {-3,-3,-2,-2,-1,0,0,0,2,1,3,0,0},
            {-7,-6,-5,-4,-2,-1,0,0,2,1,3,0,0},
            {-5,-4,-3,-2,-1,0,0,0,0,0,0,0,0},
            {-4,-4,-3,-3,-2,-2,-1,0,0,0,0,0,0},
            {-4,-4,-3,-3,-2,-2,-1,0,0,0,0,0,0},
            {-7,-6,-5,-4,-3,-2,-1,0,1,0,1,0,0},
            };
        int nT51Data[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int eT51Data[13] = {2,2,2,2,2,2,2,2,2,2,2,0,0};
        for (int b = 0;
             b < dhcT51RowCount();
             ++b) {
            int vals[13];
            vals[0] = dhcT51Ac0(b);
            vals[1] = dhcT51Ac1(b);
            vals[2] = dhcT51Ac2(b);
            vals[3] = dhcT51Ac3(b);
            vals[4] = dhcT51Ac4(b);
            vals[5] = dhcT51Ac5(b);
            vals[6] = dhcT51Ac6(b);
            vals[7] = dhcT51Ac7(b);
            vals[8] = dhcT51Ac8(b);
            vals[9] = dhcT51Ac9(b);
            vals[10] = dhcT51Ac10(b);
            vals[11] = dhcT51LNote(b);
            vals[12] = dhcT51Star(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != CT51Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT51Data[c];
            }
        }
        for (int c = 0; c < 13; ++c)
            if (nT51Data[c] != eT51Data[c])
                ++bad;
        // the T51 row count pin
    if (dhcT51RowCount() != 28
        )
            ++bad;
        // the T51 AC ladder width pin
    if (dhcT51AcCount() != 11
        )
            ++bad;
        // the medium/long range adjust pins
    if (dhcT51MediumAdjust() != -2
            || dhcT51LongAdjust() != -5
        )
            ++bad;
        // the short-range basis note pin
    if (dhcT51AcAtShortRange() != 1
        )
            ++bad;
        // the star feet note pin
    if (dhcT51StarFeetNote() != 1
        )
            ++bad;
        // the double-star see-description note pin
    if (dhcT51DoubleStarSeeDescription() != 1
        )
            ++bad;
        // the bow, short row - the contested AC-10 cell settles +3 per the
        // print capture (both readings ladder-consistent, the settling print
        // read stands over the compressed +2; flagged for the physical-copy
        // check)
    if (dhcT51Ac10(3) != 3
        )
            ++bad;
        // the sling, staff (stone) row - the contested ladder settles per the
        // print capture (the compressed stone-one-worse-than-bullet pattern
        // is design-plausible, but the settling print read stands; flagged
        // for the physical-copy check)
    if (dhcT51Ac0(25) != -4
            || dhcT51Ac1(25) != -4
            || dhcT51Ac5(25) != -2
            || dhcT51Ac6(25) != -1
        )
            ++bad;
        // the blow pipe dart row - the stacked two-line cells decode as -14,
        // -12, -10 (capture p. 80)
    if (dhcT51Ac0(1) != -14
            || dhcT51Ac2(1) != -10
        )
            ++bad;
        // the needle row - the stacked two-line cells decode as -16 through
        // -10, the AC-9 dip at -3, the star marker (capture p. 81)
    if (dhcT51Ac0(16) != -16
            || dhcT51Ac4(16) != -10
            || dhcT51Ac9(16) != -3
            || dhcT51Star(16) != 1
        )
            ++bad;
        // the grenade row - the -99 dashes across the ladder, the d footnote
        // letter 8 (capture p. 81)
    if (dhcT51Ac0(11) != -99
            || dhcT51Ac10(11) != -99
            || dhcT51LNote(11) != 8
        )
            ++bad;
        // the metsubishi row - the -99 dashes, the d footnote letter 8, the
        // star marker (capture p. 81)
    if (dhcT51Ac0(15) != -99
            || dhcT51LNote(15) != 8
            || dhcT51Star(15) != 1
        )
            ++bad;
        // the javelin row - the h footnote letter, bitmask 128 (capture p.
        // 81)
    if (dhcT51LNote(13) != 128
        )
            ++bad;
        // the hankyu row - the d footnote letter 8 (capture p. 81)
    if (dhcT51LNote(12) != 8
        )
            ++bad;
        // the lasso row - the inverted ladder, +9 at AC 0 falling to -1 at AC
        // 10 (capture p. 81)
    if (dhcT51Ac0(14) != 9
            || dhcT51Ac10(14) != -1
        )
            ++bad;
        // the sling (bullet) row - the AC-8 bump at +2 over the AC-9 +1
        // (capture p. 81)
    if (dhcT51Ac8(22) != 2
            || dhcT51Ac9(22) != 1
        )
            ++bad;
        // the heavy crossbow row - the shallowest ladder, -2 at AC 0 to the
        // +4 plateau (capture p. 81)
    if (dhcT51Ac0(6) != -2
            || dhcT51Ac10(6) != 4
        )
            ++bad;
        // the daikyu row - the AC-0 at -1 only, the +4 plateau at the tail
        // (capture p. 81)
    if (dhcT51Ac0(9) != -1
            || dhcT51Ac10(9) != 4
        )
            ++bad;
        // the sling, staff (bullet) row - the flat zero tail from AC 5
        // through AC 10 (capture p. 81)
    if (dhcT51Ac5(24) != 0
            || dhcT51Ac10(24) != 0
        )
            ++bad;
        printf("R642 OA hurled audit: bad %d\n", bad);
        if (bad) return 1;
    }
