    // ---- R426: the WSG
    // dressing pin audit ----
    // The first WSG pin round
    // after the arc opener
    // closes the
    // dressing-for-the-weather
    // chapter whole
    // (rules/wsgdress.h,
    // prefix wsd): the four
    // clothing categories (the
    // ranges, the
    // encumbrance equivalents,
    // the outfit costs), the
    // Table 3 grid (the 15
    // attire rows x the 4
    // temperature columns,
    // cumulative) verified
    // cell for cell with the
    // row/column censuses,
    // the
    // protected/unprotected
    // truth table, the three
    // exertion regimes with
    // the book own chain mail
    // example and the
    // clothing-as-armor
    // option; census
    // 351 -> 352.
    {
        using namespace rules;
        int bad = 0;
        if (wsdClothingCount() != 4
                || wsdAttireCount()
                != 15
                || wsdColCount() != 4
                || !wsdDegreesAreFahrenheit()
                || !wsdTempAdjCumulative()
                || !wsdStuddedLeatherNotMetal()
                || !wsdExertDropFloored()
                || !wsdMiscastIsOptional())
            ++bad;
        if (wsdCategoryLo(0)
                != -99
                || wsdCategoryLo(1)
                != 0
                || wsdCategoryLo(2)
                != 31
                || wsdCategoryLo(3)
                != 76
                || wsdCategoryHi(0)
                != -1
                || wsdCategoryHi(1)
                != 30
                || wsdCategoryHi(2)
                != 75
                || wsdCategoryHi(3)
                != 99)
            ++bad;
        if (wsdCategoryCostGp(0)
                != 15
                || wsdCategoryCostGp(1)
                != 7
                || wsdCategoryCostGp(2)
                != 3
                || wsdCategoryCostGp(3)
                != 0
                || wsdHotClothingCostSp() != 6
                || !wsdVcEncEqPlateMail()
                || wsdVcEncWeightGp()
                != 450
                || !wsdColdEncEqRingMail()
                || wsdColdEncWeightGp() != 250
                || !wsdModEncEqLeather()
                || wsdModEncWeightGp() != 150
                || !wsdHotEncumbranceNone()
                || wsdVcEqColdLayers() != 2
                || wsdVcEqModLayers() != 4)
            ++bad;
        // the thresholds
        if (wsdVcUnprotectedAbove() != 30
                || wsdColdUnprotBelow() != 0
                || wsdColdUnprotAbove() != 50
                || wsdModUnprotBelow() != 30
                || wsdModUnprotAbove() != 80
                || wsdHotUnprotBelow() != 50
                || wsdMetalHighTemp()
                != 80)
            ++bad;
        // the Table 3 grid,
        // cell for cell, with
        // the row/column
        // censuses and the
        // zero count
        int C[15][4] = {
            {30,40,50,60},
            {20,30,40,50},
            {10,20,20,30},
            {0,0,0,0},
            {10,20,30,40},
            {10,20,30,40},
            {10,20,30,30},
            {5,10,15,20},
            {5,10,15,20},
            {0,5,10,20},
            {0,5,10,20},
            {0,5,10,15},
            {5,0,15,30},
            {20,30,40,50},
            {10,5,10,20}};
        int rs[15] = {180,140,80,0,
            100,100,90,50,50,35,
            35,30,50,140,45};
        int cs[4] = {135,220,325,445};
        int zeros = 0;
        for (int a = 0;
             a < wsdAttireCount();
             ++a) {
            int rsum = 0;
            for (int k = 0;
                 k < wsdColCount();
                 ++k) {
                int v =
                    wsdTempAdj(a, k);
                if (v != C[a][k])
                    ++bad;
                if (v == 0) ++zeros;
                rsum += v;
            }
            if (rsum != rs[a]) ++bad;
        }
        for (int k = 0;
             k < wsdColCount();
             ++k) {
            int csum = 0;
            for (int a = 0;
                 a < wsdAttireCount();
                 ++a)
                csum +=
                    wsdTempAdj(a, k);
            if (csum != cs[k]) ++bad;
        }
        if (zeros != 8) ++bad;
        // the column mapping
        if (wsdColForTemp(-5) != 0
                || wsdColForTemp(-1)
                != 0
                || wsdColForTemp(0)
                != 1
                || wsdColForTemp(30)
                != 1
                || wsdColForTemp(31)
                != 2
                || wsdColForTemp(75)
                != 2
                || wsdColForTemp(76)
                != 3
                || wsdColForTemp(110)
                != 3)
            ++bad;
        // the book own
        // cumulative example:
        // subzero, plate mail +
        // very cold clothing
        // = +40
        if (wsdTempAdj(0,
                       wsdColForTemp(-5))
                + wsdTempAdj(6,
                             wsdColForTemp(-5))
                != 40)
            ++bad;
        // the protected truth
        // table (the
        // boundaries, both
        // clauses)
        if (!wsdClothingUnprotected(0, 31)
                || wsdClothingUnprotected(0, 30)
                || !wsdClothingUnprotected(1, -1)
                || wsdClothingUnprotected(1, 0)
                || !wsdClothingUnprotected(1, 51)
                || wsdClothingUnprotected(1, 50)
                || !wsdClothingUnprotected(2, 29)
                || wsdClothingUnprotected(2, 30)
                || !wsdClothingUnprotected(2, 81)
                || wsdClothingUnprotected(2, 80)
                || !wsdClothingUnprotected(3, 49)
                || wsdClothingUnprotected(3, 50)
                || !wsdMetalUnprotected(true, 81)
                || wsdMetalUnprotected(true, 80)
                || wsdMetalUnprotected(false, 100)
                || !wsdUnprotected(2, true, 81)
                || wsdUnprotected(2, true, 31)
                || wsdUnprotected(2, false, 31)
                || wsdUnprotected(3, false, 60)
                || !wsdUnprotected(3, false, 40))
            ++bad;
        // the exertion pins
        if (wsdExertGainBelow0() != 5
                || wsdExertTurnsBelow0() != 4
                || wsdExertRestHoldBelow0() != 1
                || wsdExertMaxBelow0() != 20
                || wsdExertGainWarm() != 5
                || wsdExertTurnsWarm() != 6
                || wsdExertMaxWarm() != 10
                || wsdExertTurnsWarmMax() != 12
                || wsdExertRestLoseWarm() != 2
                || wsdExertGainHot() != 5
                || wsdExertTurnsHot() != 3
                || wsdExertMaxHot() != 25
                || wsdExertRestDropHot() != 5
                || wsdExertRestDropHotRelieved() != 10)
            ++bad;
        // the book own chain
        // mail example: 90
        // degrees, chain mail
        // (+20), a 15-turn hike
        // (+25) = 135 personal
        if (wsdTempAdj(9, 3) != 20
                || 90 + wsdTempAdj(9, 3)
                != 110
                || 90 + wsdTempAdj(9, 3)
                + wsdExertMaxHot()
                != 135
                || wsdExertRestDropHot() * 3 != 15
                || wsdExertRestDropHotRelieved() * 2
                + wsdExertRestDropHot() != 25)
            ++bad;
        // clothing as armor
        if (wsdVcArmorClass() != 8
                || wsdColdArmorClass() != 9
                || wsdClothingMiscastChance() != 10)
            ++bad;
        printf("R426 WSG dressing pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
