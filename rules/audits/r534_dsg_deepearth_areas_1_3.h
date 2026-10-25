    // ---- R534 DSG Deepearth areas 1-3 audit ----
    // The DSG Deepearth areas 1-3 pin Area 1 (the Great Lake with its depths,
    // cliff, denizens and the wall-of-force spur), Area 2 (the surface lands
    // with the city sewers, the four-level bandit dungeon, the
    // half-connecting hill caves and the taboo shaft), and Area 3 (the Upper
    // Caverns with the raiding races, the beholder, the troglodyte
    // amphitheater and the magic infravision pool).
    {
        using namespace rules;
        int bad = 0;
    if (dnarLakeMaxDepthFt() != 1200
            || dnarLakeAvgDepthFt() != 400
            || dnarLakeCliffMaxFt() != 400
            || dnarLakeCliffMinFt() != 100
            || dnarLakeSouthDepthFt() != 50
            || dnarLakeWideMiles() != 50
            || dnarLakeLongMiles() != 120
            || dnarLakeCaveHtFt() != 20
            || dnarBanditDungeonLevels() != 4
            || dnarUpperPoolDeepLowFt() != 6
            || dnarUpperPoolDeepHighFt() != 8
            || dnarUpperExcavatedMaxFt() != 300
            || dnarUpperChamberWidFt() != 20
            || dnarUpperChamberHtFt() != 10
            || dnarUpperChamberLongFt() != 100
            || dnarUpperPinchHtFt() != 3
            || dnarUpperPinchWidFt() != 2
            || dnarAmphitheaterDiaFt() != 80
            || dnarStatueDiamondGp() != 10000
            || dnarPoolWidFt() != 3
            || dnarPoolDeepFt() != 1
            || dnarPoolDripPintsPerYear() != 1
            || dnarPoolInfraRangeFt() != 60
            || dnarPoolInfraWeeksDice() != 2
            || dnarPoolInfraWeeksSides() != 6
            || dnarPoolPints() != 30
            || !dnarLakeNorthRocky()
            || !dnarLakeCarnivores()
            || !dnarLakeSirinesScrags()
            || !dnarLakeMillWheels()
            || !dnarLakeMineShafts()
            || !dnarSurfaceTerrainFrame()
            || !dnarFortifiedCity()
            || !dnarSurfaceRaces()
            || !dnarSurfaceResources()
            || !dnarCityDungeonSewers()
            || !dnarHillCavesHalfConnect()
            || !dnarTabooMineShaft()
            || !dnarUpperMazeLiving()
            || !dnarUpperWallOfForce()
            || !dnarUpperRaiders()
            || !dnarUpperMonstersBeholder()
            || !dnarUpperAirWaterPlants()
            || !dnarTroglodyteStatue()
        )
            ++bad;
        // the Great Lake numbers: the 1,200-ft maximum depth, the 400-ft
        // average, the 400/100-ft cliff, the 50-ft southern depth, the
        // 50-by-120-mile oval, the 20-ft cave.
    if (dnarLakeMaxDepthFt() != 1200
            || dnarLakeAvgDepthFt() != 400
            || dnarLakeCliffMaxFt() != 400
            || dnarLakeCliffMinFt() != 100
            || dnarLakeSouthDepthFt() != 50
            || dnarLakeWideMiles() != 50
            || dnarLakeLongMiles() != 120
            || dnarLakeCaveHtFt() != 20
        )
            ++bad;
        // the surface and upper-cavern excavation numbers: the four-level
        // bandit dungeon, the 300-ft-square excavation cap.
    if (dnarBanditDungeonLevels() != 4
            || dnarUpperExcavatedMaxFt() != 300
        )
            ++bad;
        // the Upper Caverns geography: the 6-to-8-ft pools, the 20x10x100-ft
        // largest chamber, the 3x2-ft pinches.
    if (dnarUpperPoolDeepLowFt() != 6
            || dnarUpperPoolDeepHighFt() != 8
            || dnarUpperChamberWidFt() != 20
            || dnarUpperChamberHtFt() != 10
            || dnarUpperChamberLongFt() != 100
            || dnarUpperPinchHtFt() != 3
            || dnarUpperPinchWidFt() != 2
        )
            ++bad;
        // the troglodyte amphitheater, the statue diamonds, and the magic
        // pool: the 80-ft diameter, the 10,000-gp diamonds, the 3x1-ft pool,
        // the pint-per-year drip, the 60-ft infravision, the 2d6 weeks, the
        // 30 pints.
    if (dnarAmphitheaterDiaFt() != 80
            || dnarStatueDiamondGp() != 10000
            || dnarPoolWidFt() != 3
            || dnarPoolDeepFt() != 1
            || dnarPoolDripPintsPerYear() != 1
            || dnarPoolInfraRangeFt() != 60
            || dnarPoolInfraWeeksDice() != 2
            || dnarPoolInfraWeeksSides() != 6
            || dnarPoolPints() != 30
        )
            ++bad;
        // the Great Lake prose: the carnivores and giant gars, the sirines
        // and scrags, the mill wheels, the mine shafts and the wall of force.
    if (dnarLakeCarnivores() != 1
            || dnarLakeSirinesScrags() != 1
            || dnarLakeMillWheels() != 1
            || dnarLakeMineShafts() != 1
        )
            ++bad;
        // the Surface Lands prose: the terrain frame, the fortified city, the
        // races, the resources, the city dungeon and sewers, the
        // half-connecting hill caves, the taboo mine shaft.
    if (dnarSurfaceTerrainFrame() != 1
            || dnarFortifiedCity() != 1
            || dnarSurfaceRaces() != 1
            || dnarSurfaceResources() != 1
            || dnarCityDungeonSewers() != 1
            || dnarHillCavesHalfConnect() != 1
            || dnarTabooMineShaft() != 1
        )
            ++bad;
        // the Upper Caverns prose: the living maze, the wall of force, the
        // raiding races, the monsters and the beholder, the air-water-plants
        // resources, the troglodyte statue.
    if (dnarUpperMazeLiving() != 1
            || dnarUpperWallOfForce() != 1
            || dnarUpperRaiders() != 1
            || dnarUpperMonstersBeholder() != 1
            || dnarUpperAirWaterPlants() != 1
            || dnarTroglodyteStatue() != 1
        )
            ++bad;
        printf("R534 DSG Deepearth areas 1-3 audit: bad %d\n", bad);
        if (bad) return 1;
    }
