    // ---- R432 WSG encumbrance pin audit ----
    // The encumbrance and movement slice pins Table 11 (the 14 strength rows
    // x the Light/Moderate/Heavy/Severe gp limits), Table 12 (the encumbrance
    // category x the terrain class, the normal and the accelerated rates),
    // the bulk rule-of-thumb, the terrain definitions and the large-scale
    // overland movement rules (rules/wsgencum.h, prefix wem); census 356 ->
    // 357.
    {
        using namespace rules;
        int bad = 0;
    if (wemGpPerPound() != 10
            || wemBulkNonFactor() != 1
            || wemBulkyFactorMin() != 2
            || wemBulkyFactorMax() != 3
            || wemVeryBulkyFactor() != 5
            || wemEncRowCount() != 14
            || wemPctRowBase() != 9
            || wemTerrainClassCount() != 3
            || wemSnowRuggedMinIn() != 5
            || wemSnowRuggedMaxIn() != 10
            || wemSnowVRuggedNormalIn() != 10
            || wemSnowVRuggedRuggedIn() != 5
            || wemRuggedStreamMinHrs() != 3
            || wemRuggedStreamMaxHrs() != 4
            || wemVRuggedStreamHrs() != 2
            || wemMilesPerInchHalfDay() != 1
            || wemHalfDayHours() != 8
            || wemRestHoursMin() != 1
            || wemOver8hNum() != 3
            || wemOver8hDen() != 4
            || wemOver16hNum() != 1
            || wemOver16hDen() != 3
            || wemT12RowCount() != 5
            || wemT12BaseMove() != 12
            || !wemOneSetClothingFree()
            || !wemColdOuterwearCounts()
            || !wemSoleSmallItemFree()
            || !wemSmallComponentsFree()
            || !wemHelmetWithArmorFree()
            || !wemGreatHelmetCounts()
            || !wemBulkMayExceedWeight()
            || !wemEncValueDmRuling()
            || !wemDeviationKeepProportions()
            || !wemBelowLightNotEncumbered()
            || !wemAboveSevereCannotMove()
            || !wemAboveSevereDmDamage()
            || !wemConsistentPathIsNormal()
            || !wemPathInVRuggedIsRugged()
            || !wemLargeScaleAssumesLightRugged()
            || !wemT12ScaleForSlower()
            || !wemAccMoveNeedsRest()
        )
            ++bad;
        // the Table 11 grid: the 14 strength rows x the
        // light/moderate/heavy/severe gp limits, rows ordered 3, 4-5, 6-7,
        // 8-11, 12-13, 14-15, 16, 17, 18, 18/01-50, 18/51-75, 18/76-90,
        // 18/91-99, 18/00
        int C11[14][5] = {
            {40,100,350,700,1150},
            {50,150,450,800,1250},
            {60,200,550,900,1350},
            {90,350,700,1050,1500},
            {120,450,800,1150,1600},
            {140,550,900,1250,1700},
            {160,700,1050,1400,1850},
            {170,850,1200,1550,2000},
            {180,1000,1400,1700,2250},
            {190,1100,1450,1750,2500},
            {200,1200,1500,1800,2750},
            {210,1300,1600,2000,3000},
            {220,1400,1700,2200,3500},
            {250,1500,1900,2400,4500},
            };
        for (int b = 0;
             b < wemEncRowCount();
             ++b) {
            int vals[5];
            vals[0] = wemEncLightMin(b);
            vals[1] = wemEncLightMax(b);
            vals[2] = wemEncModMax(b);
            vals[3] = wemEncHvMax(b);
            vals[4] = wemEncSevMax(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != C11[b][c])
                    ++bad;
            }
        }
        // the Table 12 grid: the encumbrance rows (none, light, moderate,
        // heavy, severe) x the normal and accelerated rates over normal,
        // rugged and very rugged terrain
        int C12[5][6] = {
            {15,18,12,16,8,10},
            {12,16,12,15,6,9},
            {10,12,9,11,4,6},
            {7,10,6,8,3,5},
            {5,7,3,5,2,3},
            };
        for (int b = 0;
             b < wemT12RowCount();
             ++b) {
            int vals[6];
            vals[0] = wemMvNormNorm(b);
            vals[1] = wemMvAccelNorm(b);
            vals[2] = wemMvNormRug(b);
            vals[3] = wemMvAccelRug(b);
            vals[4] = wemMvNormVr(b);
            vals[5] = wemMvAccelVr(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != C12[b][c])
                    ++bad;
            }
        }
        // the wemStrRowFor band-for boundaries
    if (wemStrRowFor(2) != 0
            || wemStrRowFor(3) != 0
            || wemStrRowFor(5) != 1
            || wemStrRowFor(4) != 1
            || wemStrRowFor(7) != 2
            || wemStrRowFor(6) != 2
            || wemStrRowFor(11) != 3
            || wemStrRowFor(8) != 3
            || wemStrRowFor(13) != 4
            || wemStrRowFor(12) != 4
            || wemStrRowFor(15) != 5
            || wemStrRowFor(14) != 5
            || wemStrRowFor(16) != 6
            || wemStrRowFor(16) != 6
            || wemStrRowFor(17) != 7
            || wemStrRowFor(17) != 7
            || wemStrRowFor(18) != 8
        )
            ++bad;
        // the wemPctRowFor band-for boundaries
    if (wemPctRowFor(49) != 0
            || wemPctRowFor(50) != 0
            || wemPctRowFor(75) != 1
            || wemPctRowFor(51) != 1
            || wemPctRowFor(90) != 2
            || wemPctRowFor(76) != 2
            || wemPctRowFor(99) != 3
            || wemPctRowFor(91) != 3
            || wemPctRowFor(100) != 4
        )
            ++bad;
        // the worked example: a 12-inch rate covers 12 miles in the first
        // half-day
    if (wemMilesPerInchHalfDay() * 12 != 12
        )
            ++bad;
        // the 1.5 miles per hour for any span under the half-day (3 miles
        // every 2 hours)
    if (wemHalfDayHours() * 3 / 2 != 12
        )
            ++bad;
        // the second eight hours at 3/4 rate: 9 miles
    if (12 * wemOver8hNum() / wemOver8hDen() != 9
        )
            ++bad;
        // 16 hours of continual movement: 21 miles
    if (wemMilesPerInchHalfDay() * 12 + 12 * wemOver8hNum() / wemOver8hDen()
        != 21
        )
            ++bad;
        // 24 hours without rest: 25 miles
    if (12 + 12 * wemOver8hNum() / wemOver8hDen() + 12 * wemOver16hNum() /
        wemOver16hDen() != 25
        )
            ++bad;
        // the light-encumbered, normal-terrain accelerated rate: 16 miles in
        // the first eight hours
    if (wemMvAccelNorm(1) != 16
        )
            ++bad;
        // strength 8 reads the 8-11 row: the light band begins at 90 gp
    if (wemEncLightMin(wemStrRowFor(8)) != 90
        )
            ++bad;
        // the percentile 00 (read as 100) reads the 18/00 row: severe tops at
        // 4500 gp
    if (wemEncSevMax(wemPctRowFor(100) + wemPctRowBase()) != 4500
        )
            ++bad;
        // every Table 11 row is internally ordered: lightMin <= lightMax <=
        // modMax <= hvMax <= sevMax
    if (wemEncLightMax(0) < wemEncLightMin(0)
            || wemEncModMax(0) < wemEncLightMax(0)
            || wemEncHvMax(0) < wemEncModMax(0)
            || wemEncSevMax(0) < wemEncHvMax(0)
            || wemEncLightMax(1) < wemEncLightMin(1)
            || wemEncModMax(1) < wemEncLightMax(1)
            || wemEncHvMax(1) < wemEncModMax(1)
            || wemEncSevMax(1) < wemEncHvMax(1)
            || wemEncLightMax(2) < wemEncLightMin(2)
            || wemEncModMax(2) < wemEncLightMax(2)
            || wemEncHvMax(2) < wemEncModMax(2)
            || wemEncSevMax(2) < wemEncHvMax(2)
            || wemEncLightMax(3) < wemEncLightMin(3)
            || wemEncModMax(3) < wemEncLightMax(3)
            || wemEncHvMax(3) < wemEncModMax(3)
            || wemEncSevMax(3) < wemEncHvMax(3)
            || wemEncLightMax(4) < wemEncLightMin(4)
            || wemEncModMax(4) < wemEncLightMax(4)
            || wemEncHvMax(4) < wemEncModMax(4)
            || wemEncSevMax(4) < wemEncHvMax(4)
            || wemEncLightMax(5) < wemEncLightMin(5)
            || wemEncModMax(5) < wemEncLightMax(5)
            || wemEncHvMax(5) < wemEncModMax(5)
            || wemEncSevMax(5) < wemEncHvMax(5)
            || wemEncLightMax(6) < wemEncLightMin(6)
            || wemEncModMax(6) < wemEncLightMax(6)
            || wemEncHvMax(6) < wemEncModMax(6)
            || wemEncSevMax(6) < wemEncHvMax(6)
            || wemEncLightMax(7) < wemEncLightMin(7)
            || wemEncModMax(7) < wemEncLightMax(7)
            || wemEncHvMax(7) < wemEncModMax(7)
            || wemEncSevMax(7) < wemEncHvMax(7)
            || wemEncLightMax(8) < wemEncLightMin(8)
            || wemEncModMax(8) < wemEncLightMax(8)
            || wemEncHvMax(8) < wemEncModMax(8)
            || wemEncSevMax(8) < wemEncHvMax(8)
            || wemEncLightMax(9) < wemEncLightMin(9)
            || wemEncModMax(9) < wemEncLightMax(9)
            || wemEncHvMax(9) < wemEncModMax(9)
            || wemEncSevMax(9) < wemEncHvMax(9)
            || wemEncLightMax(10) < wemEncLightMin(10)
            || wemEncModMax(10) < wemEncLightMax(10)
            || wemEncHvMax(10) < wemEncModMax(10)
            || wemEncSevMax(10) < wemEncHvMax(10)
            || wemEncLightMax(11) < wemEncLightMin(11)
            || wemEncModMax(11) < wemEncLightMax(11)
            || wemEncHvMax(11) < wemEncModMax(11)
            || wemEncSevMax(11) < wemEncHvMax(11)
            || wemEncLightMax(12) < wemEncLightMin(12)
            || wemEncModMax(12) < wemEncLightMax(12)
            || wemEncHvMax(12) < wemEncModMax(12)
            || wemEncSevMax(12) < wemEncHvMax(12)
            || wemEncLightMax(13) < wemEncLightMin(13)
            || wemEncModMax(13) < wemEncLightMax(13)
            || wemEncHvMax(13) < wemEncModMax(13)
            || wemEncSevMax(13) < wemEncHvMax(13)
        )
            ++bad;
        // the accelerated rate is never below the normal rate in the same
        // Table 12 cell
    if (wemMvAccelNorm(0) < wemMvNormNorm(0)
            || wemMvAccelRug(0) < wemMvNormRug(0)
            || wemMvAccelVr(0) < wemMvNormVr(0)
            || wemMvAccelNorm(1) < wemMvNormNorm(1)
            || wemMvAccelRug(1) < wemMvNormRug(1)
            || wemMvAccelVr(1) < wemMvNormVr(1)
            || wemMvAccelNorm(2) < wemMvNormNorm(2)
            || wemMvAccelRug(2) < wemMvNormRug(2)
            || wemMvAccelVr(2) < wemMvNormVr(2)
            || wemMvAccelNorm(3) < wemMvNormNorm(3)
            || wemMvAccelRug(3) < wemMvNormRug(3)
            || wemMvAccelVr(3) < wemMvNormVr(3)
            || wemMvAccelNorm(4) < wemMvNormNorm(4)
            || wemMvAccelRug(4) < wemMvNormRug(4)
            || wemMvAccelVr(4) < wemMvNormVr(4)
        )
            ++bad;
        printf("R432 WSG encumbrance pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
