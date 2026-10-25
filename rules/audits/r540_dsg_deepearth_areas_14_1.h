    // ---- R540 DSG Deepearth areas 14-15 audit ----
    // The DSG Deepearth areas 14-15 pin Area 14 (the Reclaimed Caverns with
    // their pech dikes, the 300-miner community, the kuo-toan sabotage war
    // and the water-wheel pumping works) and Area 15 (the Upper Lake with its
    // kuo-toan domes, the drain regulation and the aboleth slavers).
    {
        using namespace rules;
        int bad = 0;
    if (dnaiFallsFt() != 500
            || dnaiAirspaceWestFt() != 6
            || dnaiAirspaceEastFt() != 10
            || dnaiCaveCount() != 3
            || dnaiBridgeCavernHtFt() != 8
            || dnaiBridgeCavernWidFt() != 12
            || dnaiPechCount() != 300
            || dnaiKuoPartyLow() != 20
            || dnaiKuoPartyHigh() != 25
            || dnaiVentApertureFt() != 1
            || dnaiStackLow() != 3
            || dnaiStackHigh() != 4
            || dnaiLongboatPct() != 50
            || dnaiLongboatDice() != 1
            || dnaiLongboatSides() != 6
            || dnaiShelfLowFt() != 10
            || dnaiShelfHighFt() != 400
            || dnaiDepthLowFt() != 10
            || dnaiDepthHighFt() != 100
            || dnaiDomeCount() != 6
            || dnaiDomeDiaFt() != 150
            || dnaiDomeHtFt() != 50
            || dnaiDomeAirFt() != 20
            || !dnaiLakeReclaimed()
            || !dnaiEastRiverRoute()
            || !dnaiPechDikes()
            || !dnaiSmoothCaves()
            || !dnaiPechMining()
            || !dnaiMonsterRoster()
            || !dnaiKuoRaids()
            || !dnaiPechHoard()
            || !dnaiPumpingPlant()
            || !dnaiSmeltingForge()
            || !dnaiStoneTown()
            || !dnaiLakeChamber()
            || !dnaiWestShoreline()
            || !dnaiLakeDrain()
            || !dnaiKuoDomestead()
            || !dnaiLakeFauna()
            || !dnaiAboleth()
            || !dnaiLakeResources()
            || !dnaiDrainRegulation()
            || !dnaiDomeCity()
        )
            ++bad;
        // the river routes: the 500-ft waterfall, the six-foot western
        // airspace, the ten-foot eastern minimum.
    if (dnaiFallsFt() != 500
            || dnaiAirspaceWestFt() != 6
            || dnaiAirspaceEastFt() != 10
        )
            ++bad;
        // the reclaimed caverns: three parallel caves, the 8x12-ft bridge
        // cavern, the 300 pech miners.
    if (dnaiCaveCount() != 3
            || dnaiBridgeCavernHtFt() != 8
            || dnaiBridgeCavernWidFt() != 12
            || dnaiPechCount() != 300
        )
            ++bad;
        // the raids and the works: the 20-25-strong war parties, the one-foot
        // vent aperture, the buildings stacked three or four deep.
    if (dnaiKuoPartyLow() != 20
            || dnaiKuoPartyHigh() != 25
            || dnaiVentApertureFt() != 1
            || dnaiStackLow() != 3
            || dnaiStackHigh() != 4
        )
            ++bad;
        // the shoreline moorings: the 50% chance of 1d6 longboats.
    if (dnaiLongboatPct() != 50
            || dnaiLongboatDice() != 1
            || dnaiLongboatSides() != 6
        )
            ++bad;
        // the lake measures: the 10-to-400-ft shelf, the 10-to-100-ft depths.
    if (dnaiShelfLowFt() != 10
            || dnaiShelfHighFt() != 400
            || dnaiDepthLowFt() != 10
            || dnaiDepthHighFt() != 100
        )
            ++bad;
        // the kuo-toan city: six hexagonal domes, 150 feet across, 50 feet
        // high, 20 feet of air.
    if (dnaiDomeCount() != 6
            || dnaiDomeDiaFt() != 150
            || dnaiDomeHtFt() != 50
            || dnaiDomeAirFt() != 20
        )
            ++bad;
        printf("R540 DSG Deepearth areas 14-15 audit: bad %d\n", bad);
        if (bad) return 1;
    }
