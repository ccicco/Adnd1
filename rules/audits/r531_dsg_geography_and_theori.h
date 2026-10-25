    // ---- R531 DSG geography and theories audit ----
    // The DSG underground geography and theories pin the geography factors
    // (the large-nation area, the surface terrain, the temperature, the
    // humidity, the size, the origin, the access and egress) and the four
    // theories on the nature of the underground (the hollow earth and its
    // variants, the Swiss cheese, the isolated pockets, the partial
    // connection with its fire and water blocks).
    {
        using namespace rules;
        int bad = 0;
    if (dngrRegionDiaMiles() != 1000
            || dngrHalflingTunnelFt() != 3
            || dngrBigCavernMileWide() != 1
            || !dngrLargeNationArea()
            || !dngrCampaignByCampaign()
            || !dngrSeaWaterFilled()
            || !dngrTrappedAirStale()
            || !dngrWaterTable()
            || !dngrMountainDomainsHigher()
            || !dngrGraniteLimestone()
            || !dngrGeothermalPlants()
            || !dngrWarmLairHeatRaces()
            || !dngrConvectionVentilation()
            || !dngrDryCaveBrittle()
            || !dngrSteamyScavengerRock()
            || !dngrLowHumidityDusty()
            || !dngrErosionHazards()
            || !dngrSizeLimitsCreatures()
            || !dngrHugeCavernsAvoided()
            || !dngrSupportColumnsSpells()
            || !dngrSmallTunnelDefense()
            || !dngrNaturalIrregular()
            || !dngrDuergarSmoothCities()
            || !dngrStraightMileTunnels()
            || !dngrDrowConquerLairs()
            || !dngrAirShaftsNoAccess()
            || !dngrEasyAccessRaiders()
            || !dngrDmDecidesTheory()
            || !dngrSageKnowledge()
            || !dngrHollowEarthTheory()
            || !dngrHollowInnerWorld()
            || !dngrHollowLavaRain()
            || !dngrHollowShellVariant()
            || !dngrHollowAirCenter()
            || !dngrSwissCheeseTheory()
            || !dngrGoblinUbiquity()
            || !dngrFailedExpeditions()
            || !dngrUnexploitedConnections()
            || !dngrIsolatedPocketsTheory()
            || !dngrForcedMigration()
            || !dngrPartialConnectionTheory()
            || !dngrFireWaterBlocks()
        )
            ++bad;
        // the geography load-bearing numbers: the 1,000-mile sample region,
        // the three-foot halfling tunnels, and the mile-wide largest caverns.
    if (dngrRegionDiaMiles() != 1000
            || dngrHalflingTunnelFt() != 3
            || dngrBigCavernMileWide() != 1
        )
            ++bad;
        // the geography frame and surface terrain: the large-nation area, the
        // water-filled sea tunnels, the water table, the
        // granite-versus-limestone, the higher mountain domains.
    if (dngrLargeNationArea() != 1
            || dngrSeaWaterFilled() != 1
            || dngrWaterTable() != 1
            || dngrGraniteLimestone() != 1
            || dngrMountainDomainsHigher() != 1
        )
            ++bad;
        // the temperature and humidity: the geothermal plants, the convection
        // ventilation, the brittle dry caves, the steamy scavenger rock, the
        // erosion hazards.
    if (dngrGeothermalPlants() != 1
            || dngrConvectionVentilation() != 1
            || dngrDryCaveBrittle() != 1
            || dngrSteamyScavengerRock() != 1
            || dngrErosionHazards() != 1
        )
            ++bad;
        // the size and origin: the avoided huge caverns, the support columns,
        // the duergar domed cities, the drow conquering lairs, the
        // small-tunnel defense.
    if (dngrHugeCavernsAvoided() != 1
            || dngrSupportColumnsSpells() != 1
            || dngrDuergarSmoothCities() != 1
            || dngrDrowConquerLairs() != 1
            || dngrSmallTunnelDefense() != 1
        )
            ++bad;
        // the access and egress and the theory frame: the no-access air
        // shafts, the easy-access raiders, the DM-decides rule, the sage
        // knowledge.
    if (dngrAirShaftsNoAccess() != 1
            || dngrEasyAccessRaiders() != 1
            || dngrDmDecidesTheory() != 1
            || dngrSageKnowledge() != 1
        )
            ++bad;
        // the hollow earth theory and its variants: the crust, the inner
        // world, the lava rain, the shell, the Plane of Air center.
    if (dngrHollowEarthTheory() != 1
            || dngrHollowInnerWorld() != 1
            || dngrHollowLavaRain() != 1
            || dngrHollowShellVariant() != 1
            || dngrHollowAirCenter() != 1
        )
            ++bad;
        // the remaining theories: the Swiss cheese, the goblin ubiquity, the
        // failed expeditions, the unexploited connections, the isolated
        // pockets, the forced migration, the partial connection, the fire and
        // water blocks.
    if (dngrSwissCheeseTheory() != 1
            || dngrGoblinUbiquity() != 1
            || dngrFailedExpeditions() != 1
            || dngrUnexploitedConnections() != 1
            || dngrIsolatedPocketsTheory() != 1
            || dngrForcedMigration() != 1
            || dngrPartialConnectionTheory() != 1
            || dngrFireWaterBlocks() != 1
        )
            ++bad;
        printf("R531 DSG geography and theories audit: bad %d\n", bad);
        if (bad) return 1;
    }
