    // ---- R434 WSG vehicles pin audit ----
    // The land-based vehicles slice pins Table 14 (the 21 cart, chariot and
    // wagon rows x the normal and rugged rates and the maximum loads), the
    // miles-per-half-day scale, the no-very-rugged rule and the pathless
    // one-category-worse rule (rules/wsgvehicle.h, prefix wvv); census 358 ->
    // 359.
    {
        using namespace rules;
        int bad = 0;
    if (wvvVehicleCount() != 21
            || wvvCartRowBase() != 0
            || wvvChariotRowBase() != 8
            || wvvWagonRowBase() != 14
            || !wvvRateMilesPerHalfDay()
            || !wvvNoVeryRugged()
            || !wvvAssumesFlatOrPath()
            || !wvvPathlessOneCategoryWorse()
            || !wvvLightForestVehicleRugged()
            || !wvvCartsWagonsHaulGear()
            || !wvvChariotsMainlyCharacters()
            || !wvvMaxLoadIsGp()
        )
            ++bad;
        // the Table 14 grid: the 21 vehicle rows (the small and medium carts,
        // the small and large chariots, the small and large wagons, each by
        // its animal team) x the normal and rugged rates and the maximum
        // loads
        int C14[21][3] = {
            {8,4,3500},
            {10,5,5500},
            {12,5,6000},
            {12,7,6000},
            {6,0,4000},
            {8,3,6500},
            {8,5,7500},
            {10,6,7500},
            {6,3,3000},
            {9,5,4000},
            {10,6,4000},
            {12,7,5500},
            {14,8,5500},
            {16,10,5500},
            {8,3,7500},
            {10,6,8500},
            {12,9,9000},
            {10,6,12000},
            {12,8,13500},
            {14,8,13500},
            {16,10,15000},
            };
        for (int b = 0;
             b < wvvVehicleCount();
             ++b) {
            int vals[3];
            vals[0] = wvvMvNorm(b);
            vals[1] = wvvMvRug(b);
            vals[2] = wvvMaxLoad(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C14[b][c])
                    ++bad;
            }
        }
        // the small cart drawn by a pony: 8 and 4 miles per half-day, a 3500
        // gp maximum load
    if (wvvMvNorm(0) != 8
            || wvvMvRug(0) != 4
            || wvvMaxLoad(0) != 3500
        )
            ++bad;
        // the medium cart drawn by a pony cannot be taken onto rugged terrain
        // (0)
    if (wvvMvNorm(4) != 6
            || wvvMvRug(4) != 0
        )
            ++bad;
        // the large chariot drawn by heavy horses: the fastest vehicle, 16
        // and 10 miles per half-day, a 5500 gp load
    if (wvvMvNorm(13) != 16
            || wvvMvRug(13) != 10
            || wvvMaxLoad(13) != 5500
        )
            ++bad;
        // the large wagon drawn by light horses: 10 and 6, a 12000 gp load
    if (wvvMvNorm(17) != 10
            || wvvMvRug(17) != 6
            || wvvMaxLoad(17) != 12000
        )
            ++bad;
        // the large wagon drawn by heavy horses hauls the most: 15000 gp
    if (wvvMaxLoad(20) != 15000
        )
            ++bad;
        // every Table 14 row: the rugged rate is never above the normal rate
    if (wvvMvRug(0) > wvvMvNorm(0)
            || wvvMvRug(1) > wvvMvNorm(1)
            || wvvMvRug(2) > wvvMvNorm(2)
            || wvvMvRug(3) > wvvMvNorm(3)
            || wvvMvRug(4) > wvvMvNorm(4)
            || wvvMvRug(5) > wvvMvNorm(5)
            || wvvMvRug(6) > wvvMvNorm(6)
            || wvvMvRug(7) > wvvMvNorm(7)
            || wvvMvRug(8) > wvvMvNorm(8)
            || wvvMvRug(9) > wvvMvNorm(9)
            || wvvMvRug(10) > wvvMvNorm(10)
            || wvvMvRug(11) > wvvMvNorm(11)
            || wvvMvRug(12) > wvvMvNorm(12)
            || wvvMvRug(13) > wvvMvNorm(13)
            || wvvMvRug(14) > wvvMvNorm(14)
            || wvvMvRug(15) > wvvMvNorm(15)
            || wvvMvRug(16) > wvvMvNorm(16)
            || wvvMvRug(17) > wvvMvNorm(17)
            || wvvMvRug(18) > wvvMvNorm(18)
            || wvvMvRug(19) > wvvMvNorm(19)
            || wvvMvRug(20) > wvvMvNorm(20)
        )
            ++bad;
        printf("R434 WSG vehicles pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
