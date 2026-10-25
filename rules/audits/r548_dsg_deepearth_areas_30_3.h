    // ---- R548 DSG Deepearth areas 30-31 audit ----
    // The DSG Deepearth areas 30-31 pin Area 30 (the Interplanar Whirlpool
    // with its 2,000-ft plunge down the 100-ft shaft, the switchback stairs,
    // the nereid-guarded Plane of Water vortex) and Area 31 (Darksea with its
    // hundred-mile salty expanse, the 2,000-ft depths, the dozen-plus aboleth
    // cities and the 36-tower capital) - the FINAL round of the Deepearth
    // individual area key.
    {
        using namespace rules;
        int bad = 0;
    if (dnaqFallFt() != 2000
            || dnaqShaftDiaFt() != 100
            || dnaqCeilMinFt() != 20
            || dnaqLakeShallowFt() != 100
            || dnaqLakeDeepFt() != 1000
            || dnaqReinforceTurns() != 3
            || dnaqReachMiles() != 100
            || dnaqCeilHighFt() != 1000
            || dnaqDeepFt() != 2000
            || dnaqCapitalSizeMult() != 3
            || dnaqCapitalTowers() != 36
            || dnaqCityTowersUsual() != 6
            || !dnaqRiverPlunge()
            || !dnaqBreakwaterLanding()
            || !dnaqSwitchbackStairs()
            || !dnaqAdjoiningCaverns()
            || !dnaqTwoOutflows()
            || !dnaqWatcherRaces()
            || !dnaqAquaticCarnivores()
            || !dnaqNymphGuardians()
            || !dnaqNereidWatch()
            || !dnaqWaterRoster()
            || !dnaqCleanWater()
            || !dnaqScantTreasure()
            || !dnaqWaterVortex()
            || !dnaqVastUnknownSea()
            || !dnaqMildlySalty()
            || !dnaqBlockedSections()
            || !dnaqMixedShore()
            || !dnaqAbolethDominion()
            || !dnaqUniqueSeaLife()
            || !dnaqOceanPredators()
            || !dnaqLosingKuoToanWar()
            || !dnaqAquaticFungi()
            || !dnaqFisheries()
            || !dnaqAbolethCapital()
        )
            ++bad;
        // the plunge: 2,000 feet down the 100-ft shaft.
    if (dnaqFallFt() != 2000
            || dnaqShaftDiaFt() != 100
        )
            ++bad;
        // the lake: 20-ft minimum airspace, rarely shallower than 100 feet,
        // bottoms 1,000 feet down.
    if (dnaqCeilMinFt() != 20
            || dnaqLakeShallowFt() != 100
            || dnaqLakeDeepFt() != 1000
        )
            ++bad;
        // the nereid: reinforcements three turns after discovery.
    if (dnaqReinforceTurns() != 3
        )
            ++bad;
        // the Darksea: a hundred miles or more, 1,000-ft airspace, the
        // 2,000-ft depth.
    if (dnaqReachMiles() != 100
            || dnaqCeilHighFt() != 1000
            || dnaqDeepFt() != 2000
        )
            ++bad;
        // the capital: three times the size, 36 towers instead of the usual
        // six.
    if (dnaqCapitalSizeMult() != 3
            || dnaqCapitalTowers() != 36
            || dnaqCityTowersUsual() != 6
        )
            ++bad;
        printf("R548 DSG Deepearth areas 30-31 audit: bad %d\n", bad);
        if (bad) return 1;
    }
