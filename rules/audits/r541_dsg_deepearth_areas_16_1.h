    // ---- R541 DSG Deepearth areas 16-17 audit ----
    // The DSG Deepearth areas 16-17 pin Area 16 (the Mid-Level Caverns with
    // their spiral stairway, drapery center, monster caves and the healing
    // mud-pool stream) and Area 17 (the Lower Lake with its aboleth-kuo-toa
    // war, the fresh-water kraken, the drain plunge and the floating aboleth
    // city).
    {
        using namespace rules;
        int bad = 0;
    if (dnajStairDescendFt() != 1000
            || dnajStairWideFt() != 10
            || dnajStairDeepFt() != 1
            || dnajStairDropIn() != 8
            || dnajShaftDiaFt() != 10
            || dnajWestCavernWidFt() != 20
            || dnajCliffDice() != 1
            || dnajCliffSides() != 6
            || dnajCliffMultFt() != 10
            || dnajPinchCount() != 2
            || dnajPinchDiaFt() != 3
            || dnajPoolMaxDiaFt() != 50
            || dnajPoolDeepLowFt() != 20
            || dnajPoolDeepHighFt() != 30
            || dnajLakeLongMiles() != 12
            || dnajLakeWideMiles() != 13
            || dnajChamberHtFt() != 600
            || dnajWaterDepthFt() != 500
            || dnajTunnelMouthFt() != 50
            || dnajRiverWideFt() != 100
            || dnajRiverDepthDice() != 1
            || dnajRiverDepthSides() != 10
            || dnajRiverDepthBaseFt() != 10
            || dnajRiverCeilLowFt() != 20
            || dnajRiverCeilHighFt() != 50
            || dnajUnderCaveCount() != 6
            || dnajUnderCaveMouthFt() != 100
            || dnajAbolethCount() != 300
            || dnajGoldDustGp() != 100000
            || dnajDrainRoundsDice() != 2
            || dnajDrainRoundsSides() != 6
            || dnajFallFt() != 100
            || dnajFallDmgDice() != 6
            || dnajFallDmgSides() != 6
            || dnajFallNativeDmgDice() != 3
            || dnajFallNativeDmgSides() != 6
            || dnajKrakenTunnelDiaFt() != 40
            || dnajKrakenSlaves() != 50
            || dnajCityDiaFt() != 1000
            || dnajCityTowers() != 6
            || dnajSphereSmallLowFt() != 20
            || dnajSphereSmallHighFt() != 30
            || dnajSphereLargeFt() != 100
            || dnajSphereEntranceDiaFt() != 3
            || dnajBuoyDiskFt() != 40
            || !dnajLivingCaves()
            || !dnajDraperies()
            || !dnajWildernessPass()
            || !dnajMonsterCaves()
            || !dnajMidResources()
            || !dnajOreVeins()
            || !dnajMudPool()
            || !dnajSpoutTurbulence()
            || !dnajLakeWar()
            || !dnajKuoSouthCity()
            || !dnajAbolethNorthCity()
            || !dnajKrakenLair()
            || !dnajLakeResources()
            || !dnajSphereInteriors()
            || !dnajClanHalls()
        )
            ++bad;
        // the spiral stairway: the 1,000-ft descent, the 10-ft-wide
        // one-foot-deep stairs dropping eight inches, the 10-ft shaft.
    if (dnajStairDescendFt() != 1000
            || dnajStairWideFt() != 10
            || dnajStairDeepFt() != 1
            || dnajStairDropIn() != 8
            || dnajShaftDiaFt() != 10
        )
            ++bad;
        // the west descent: the 20-ft cavern, its 1d6x10-ft cliffs, the two
        // three-foot pinches.
    if (dnajWestCavernWidFt() != 20
            || dnajCliffDice() != 1
            || dnajCliffSides() != 6
            || dnajCliffMultFt() != 10
            || dnajPinchCount() != 2
            || dnajPinchDiaFt() != 3
        )
            ++bad;
        // the pools: the largest 50 feet across, commonly 20 to 30 feet deep.
    if (dnajPoolMaxDiaFt() != 50
            || dnajPoolDeepLowFt() != 20
            || dnajPoolDeepHighFt() != 30
        )
            ++bad;
        // the Lower Lake cavern: twelve by thirteen miles, 600 feet high, 500
        // feet of water, the mouth 50 feet above the surface.
    if (dnajLakeLongMiles() != 12
            || dnajLakeWideMiles() != 13
            || dnajChamberHtFt() != 600
            || dnajWaterDepthFt() != 500
            || dnajTunnelMouthFt() != 50
        )
            ++bad;
        // the northern river: 100 feet wide, 1d10+10 deep, ceiling 20 to 50
        // feet above.
    if (dnajRiverWideFt() != 100
            || dnajRiverDepthDice() != 1
            || dnajRiverDepthSides() != 10
            || dnajRiverDepthBaseFt() != 10
            || dnajRiverCeilLowFt() != 20
            || dnajRiverCeilHighFt() != 50
        )
            ++bad;
        // the lake depths: six underwater caves below the 100-ft line, the
        // 300 aboleth, the 100,000-gp gold dust.
    if (dnajUnderCaveCount() != 6
            || dnajUnderCaveMouthFt() != 100
            || dnajAbolethCount() != 300
            || dnajGoldDustGp() != 100000
        )
            ++bad;
        // the drain plunge: 2d6 rounds submerged, the 100-ft fall, 6d6 to
        // non-natives, 3d6 to natives.
    if (dnajDrainRoundsDice() != 2
            || dnajDrainRoundsSides() != 6
            || dnajFallFt() != 100
            || dnajFallDmgDice() != 6
            || dnajFallDmgSides() != 6
            || dnajFallNativeDmgDice() != 3
            || dnajFallNativeDmgSides() != 6
        )
            ++bad;
        // the kraken and the aboleth city: the 40-ft tunnel, the 50 slaves,
        // the 1,000-ft disk on its six towers, the 40-ft buoyancy disk.
    if (dnajKrakenTunnelDiaFt() != 40
            || dnajKrakenSlaves() != 50
            || dnajCityDiaFt() != 1000
            || dnajCityTowers() != 6
            || dnajBuoyDiskFt() != 40
        )
            ++bad;
        // the sphere buildings: 20-30-foot lairs with one entrance, 100-foot
        // clan halls with six, all entered by three-foot holes.
    if (dnajSphereSmallLowFt() != 20
            || dnajSphereSmallHighFt() != 30
            || dnajSphereLargeFt() != 100
            || dnajSphereEntranceDiaFt() != 3
        )
            ++bad;
        printf("R541 DSG Deepearth areas 16-17 audit: bad %d\n", bad);
        if (bad) return 1;
    }
