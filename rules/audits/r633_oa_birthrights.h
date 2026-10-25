    // ---- R633 OA birthrights audit ----
    // OA round twenty (capture pp. 68-69): the birthrights prose, the effects
    // doctrines and the Table 40 grid
    {
        using namespace rules;
        int bad = 0;
    if (dgtT40RowCount() != 26
            || dgtPropShareMinPct() != 10
            || dgtPropShareMaxPct() != 30
            || dgtCashPerString() != 100
            || dgtMagicWeaponMaxPlus() != 2
            || dgtFirstSonRollPenalty() != 1
            || !dgtBirthrightClanVirtue()
            || !dgtBirthrightMayBeNothing()
            || !dgtSharedClanOwnership()
            || !dgtDeathReturnsToClan()
            || !dgtLostBirthrightLosesHonor()
            || !dgtRollsDeterminedByT38()
            || !dgtBirthRankReducesRolls()
            || !dgtHonorIsPersonal()
            || !dgtPropShareAncestorLandsOnly()
            || !dgtPropShareSingleCap()
            || !dgtPropShareNoPropertyRead()
            || !dgtHorseAnyTypeNoTack()
            || !dgtCashStringDmCoinType()
            || !dgtQualityArmorDmWeaponPlayer()
            || !dgtQualityItemNotTransferable()
            || !dgtMagicWeaponSwordOrMisc()
            || !dgtMagicWeaponNoSpecialAbilities()
            || !dgtMagicWeaponNeverSold()
            || !dgtMagicWeaponLostHonorLoss()
            || !dgtRollAgainNextLargerDie()
        )
            ++bad;
        // the Table 40 grid: the die bands, the personal honor column and the
        // coded birthrights (capture pp. 68-69)
        int CT40[26][4] = {
            {1,3,0,0},
            {4,4,0,1},
            {5,5,0,0},
            {6,6,1,2},
            {7,7,0,1},
            {8,8,1,2},
            {9,16,0,0},
            {17,18,1,2},
            {19,19,0,3},
            {20,20,0,4},
            {21,30,0,0},
            {31,33,2,5},
            {34,40,0,0},
            {41,45,1,2},
            {46,50,0,0},
            {51,55,0,6},
            {56,60,1,2},
            {61,63,2,7},
            {64,70,0,0},
            {71,75,2,5},
            {76,80,1,8},
            {81,90,0,0},
            {91,95,0,9},
            {96,98,2,7},
            {99,99,4,10},
            {100,100,0,11},
            };
        int nT40[4] = {0,0,0,0};
        int eT40[4] = {0,0,0,0};
        for (int b = 0;
             b < dgtT40RowCount();
             ++b) {
            int vals[4];
            vals[0] = dgtT40DieLo(b);
            vals[1] = dgtT40DieHi(b);
            vals[2] = dgtT40Honor(b);
            vals[3] = dgtT40Result(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CT40[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT40[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nT40[c] != eT40[c])
                ++bad;
        // the dgtT40RowCount pin
    if (dgtT40RowCount() != 26
        )
            ++bad;
        // the dgtPropShareMinPct pin
    if (dgtPropShareMinPct() != 10
        )
            ++bad;
        // the dgtPropShareMaxPct pin
    if (dgtPropShareMaxPct() != 30
        )
            ++bad;
        // the dgtCashPerString pin
    if (dgtCashPerString() != 100
        )
            ++bad;
        // the dgtMagicWeaponMaxPlus pin
    if (dgtMagicWeaponMaxPlus() != 2
        )
            ++bad;
        // the dgtFirstSonRollPenalty pin
    if (dgtFirstSonRollPenalty() != 1
        )
            ++bad;
        // the dgtBirthrightClanVirtue pin
    if (dgtBirthrightClanVirtue() != 1
        )
            ++bad;
        // the dgtBirthrightMayBeNothing pin
    if (dgtBirthrightMayBeNothing() != 1
        )
            ++bad;
        // the dgtSharedClanOwnership pin
    if (dgtSharedClanOwnership() != 1
        )
            ++bad;
        // the dgtDeathReturnsToClan pin
    if (dgtDeathReturnsToClan() != 1
        )
            ++bad;
        // the dgtLostBirthrightLosesHonor pin
    if (dgtLostBirthrightLosesHonor() != 1
        )
            ++bad;
        // the dgtRollsDeterminedByT38 pin
    if (dgtRollsDeterminedByT38() != 1
        )
            ++bad;
        // the dgtBirthRankReducesRolls pin
    if (dgtBirthRankReducesRolls() != 1
        )
            ++bad;
        // the dgtHonorIsPersonal pin
    if (dgtHonorIsPersonal() != 1
        )
            ++bad;
        // the dgtPropShareAncestorLandsOnly pin
    if (dgtPropShareAncestorLandsOnly() != 1
        )
            ++bad;
        // the dgtPropShareSingleCap pin
    if (dgtPropShareSingleCap() != 1
        )
            ++bad;
        // the dgtPropShareNoPropertyRead pin
    if (dgtPropShareNoPropertyRead() != 1
        )
            ++bad;
        // the dgtHorseAnyTypeNoTack pin
    if (dgtHorseAnyTypeNoTack() != 1
        )
            ++bad;
        // the dgtCashStringDmCoinType pin
    if (dgtCashStringDmCoinType() != 1
        )
            ++bad;
        // the dgtQualityArmorDmWeaponPlayer pin
    if (dgtQualityArmorDmWeaponPlayer() != 1
        )
            ++bad;
        // the dgtQualityItemNotTransferable pin
    if (dgtQualityItemNotTransferable() != 1
        )
            ++bad;
        // the dgtMagicWeaponSwordOrMisc pin
    if (dgtMagicWeaponSwordOrMisc() != 1
        )
            ++bad;
        // the dgtMagicWeaponNoSpecialAbilities pin
    if (dgtMagicWeaponNoSpecialAbilities() != 1
        )
            ++bad;
        // the dgtMagicWeaponNeverSold pin
    if (dgtMagicWeaponNeverSold() != 1
        )
            ++bad;
        // the dgtMagicWeaponLostHonorLoss pin
    if (dgtMagicWeaponLostHonorLoss() != 1
        )
            ++bad;
        // the dgtRollAgainNextLargerDie pin
    if (dgtRollAgainNextLargerDie() != 1
        )
            ++bad;
        // the T40 first row - the blank 1-3 band (capture pp. 68-69)
    if (dgtT40DieLo(0) != 1
            || dgtT40DieHi(0) != 3
            || dgtT40Honor(0) != 0
            || dgtT40Result(0) != 0
        )
            ++bad;
        // the T40 roll-again rows - 4 and 7 with the next-higher-die read,
        // 100 with the d100 add-10 read (capture pp. 68-69)
    if (dgtT40Result(1) != 1
            || dgtT40Result(4) != 1
            || dgtT40Result(25) != 11
        )
            ++bad;
        // the T40 property-share rows - the +1 honor at 6, 8, 17-18, 41-45
        // and 56-60 (capture pp. 68-69)
    if (dgtT40Honor(3) != 1
            || dgtT40Honor(5) != 1
            || dgtT40Honor(7) != 1
            || dgtT40Honor(13) != 1
            || dgtT40Honor(16) != 1
        )
            ++bad;
        // the T40 horse and cash-string rows - the horse at 19, the 1-6 cash
        // at 20, the 1-8 cash at 51-55, the 1-4 horses at 76-80, the 2-12
        // cash at 91-95 (capture pp. 68-69)
    if (dgtT40Result(8) != 3
            || dgtT40Result(9) != 4
            || dgtT40Result(15) != 6
            || dgtT40Result(20) != 8
            || dgtT40Result(22) != 9
        )
            ++bad;
        // the T40 armor and weapon rows - armor of quality at 31-33 and
        // 71-75, weapon of quality at 61-63 and 96-98 (capture pp. 68-69)
    if (dgtT40Result(11) != 5
            || dgtT40Result(19) != 5
            || dgtT40Result(17) != 7
            || dgtT40Result(23) != 7
        )
            ++bad;
        // the T40 magical weapon capstone - the +4 honor at die 99 (capture
        // pp. 68-69)
    if (dgtT40Honor(24) != 4
            || dgtT40Result(24) != 10
        )
            ++bad;
        // the T40 band contiguity - 3 to 4, 30 to 31, 63 to 64, 98 to 99
        // (capture pp. 68-69)
    if (dgtT40DieLo(1) - dgtT40DieHi(0) != 1
            || dgtT40DieLo(11) - dgtT40DieHi(10) != 1
            || dgtT40DieLo(18) - dgtT40DieHi(17) != 1
            || dgtT40DieLo(24) - dgtT40DieHi(23) != 1
        )
            ++bad;
        // the T40 final band - the d100 roll again at 100, twenty-six rows
        // only (capture pp. 68-69)
    if (dgtT40DieLo(25) != 100
            || dgtT40Honor(25) != 0
            || dgtT40RowCount() != 26
        )
            ++bad;
        // the property-share doctrine - the 10-to-30 percent share of the
        // ancestor-held lands (capture p. 69)
    if (dgtPropShareMinPct() != 10
            || dgtPropShareMaxPct() != 30
            || dgtPropShareAncestorLandsOnly() != 1
        )
            ++bad;
        printf("R633 OA birthrights audit: bad %d\n", bad);
        if (bad) return 1;
    }
