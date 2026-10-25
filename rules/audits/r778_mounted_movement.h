    // ---- R778 mounted movement audit ----
    // THE MOUNTED MOVEMENT CHARGE (the R778 repair carries the saddle
    // header's classic include guard) - the R123 feeder goes live, warhorse
    // kinds 2-4 only (Curtiss's call). The grid mirrors the p.58-59 mounted
    // rows the R123 audit already pins (dm/outdoormove.h); the site reads the
    // dm rows through the sdd kind mapping (warhorseDmKind), never a
    // hardcoded rate. The honest boundary: the draft is a cart animal and the
    // riding horse and pony walk this round; the grant steeds stay
    // contract-side (no cavalier class). The henchman walks; the fallen are
    // carried
    {
        using namespace rules;
        int bad = 0;
    if (mvmMovementFeederRound() != 123
            || mvmMountedMovementRound() != 778
            || mvmWarhorseKindCount() != 3
            || mvmTerrainClassCount() != 3
            || mvmMountedRateFloor() != 5
            || !mvmWarhorseRidersSetThePace()
            || !mvmCompanyRidesTheSlowestMember()
            || !mvmNonWarhorseKindsWalk()
            || !mvmHenchmanWalksTheMountedRound()
            || !mvmRatesRideThePinnedData()
            || !mvmSaddleLadderFeedsMapping()
            || !mvmSaddleHeaderGuarded()
        )
            ++bad;
        // the warhorse miles/day grid, terrain class by kind - the p.58-59
        // mounted rows the R123 audit already pins in dm/outdoormove.h
        int CR778Warhorse[3][3] = {
            {60,40,30},
            {25,20,15},
            {5,5,5},
            };
        for (int b = 0;
             b < mvmTerrainClassCount();
             ++b) {
            int vals[3];
            vals[0] = mvmLightWarMiles(b);
            vals[1] = mvmMediumWarMiles(b);
            vals[2] = mvmHeavyWarMiles(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CR778Warhorse[b][c])
                    ++bad;
            }
        }
        // the ladder runs light to heavy: the light war horse outpaces the
        // heavy on open and rugged ground
    if (mvmLightWarMiles(0) < mvmHeavyWarMiles(0)
            || mvmLightWarMiles(1) < mvmHeavyWarMiles(1)
        )
            ++bad;
        // the very-rugged floor: every warhorse kind rides 5 in the mountains
        // and the marsh
    if (mvmLightWarMiles(2) != mvmMountedRateFloor()
            || mvmMediumWarMiles(2) != mvmMountedRateFloor()
            || mvmHeavyWarMiles(2) != mvmMountedRateFloor()
        )
            ++bad;
        // the medium war horse outpaces the heavy, and the floor equals them
    if (mvmMediumWarMiles(0) < mvmHeavyWarMiles(0)
            || mvmMediumWarMiles(1) < mvmHeavyWarMiles(1)
            || mvmMediumWarMiles(2) != mvmHeavyWarMiles(2)
        )
            ++bad;
        printf("R778 mounted movement audit: bad %d\n", bad);
        if (bad) return 1;
    }
