    // ---- R535 DSG Deepearth areas 4-5 audit ----
    // The DSG Deepearth areas 4-5 pin Area 4 (the Cathedral Caverns with its
    // drow lair, piercer ceiling, sinkhole hydra, diamond vein and gold-dust
    // mud pool) and Area 5 (the Enclosed Caverns with the water-choked river
    // entry, the mad castaways, the kuo-toa outpost guarding the chute and
    // the nereid's spring pool).
    {
        using namespace rules;
        int bad = 0;
    if (dnacCavernCount() != 4
            || dnacCavernLenDice() != 1
            || dnacCavernLenSides() != 6
            || dnacCeilingMaxFt() != 100
            || dnacWideLowFt() != 80
            || dnacWideHighFt() != 90
            || dnacSinkholeDepthFt() != 400
            || dnacStreamWidthFt() != 5
            || dnacStreamDepthFt() != 1
            || dnacDrowFighters() != 25
            || dnacHydraHD() != 12
            || dnacTunnelLenFt() != 500
            || dnacTunnelMaxWidthFt() != 10
            || dnacTunnelClimbFt() != 100
            || dnacTrapDice() != 6
            || dnacTrapSides() != 6
            || dnacMudPoolWidthFt() != 20
            || dnacMudPoolDepthFt() != 5
            || dnacMudGoldPerCharGp() != 20
            || dnacMudGoldTotalGp() != 10000
            || dnacRiverFlowLow() != 3
            || dnacRiverFlowHigh() != 4
            || dnacRapidsMiles() != 1
            || dnacSweepChancePct() != 80
            || dnacCascadeRounds() != 2
            || dnacCaveCount() != 8
            || dnacCaveMaxMiles() != 1
            || dnacTunnelDiaFt() != 2
            || dnacWaterFilledFt() != 50
            || dnacLowClearanceMiles() != 6
            || dnacCastawaysCount() != 20
            || dnacKuoDice() != 6
            || dnacKuoSides() != 6
            || dnacFindChancePct() != 1
            || dnacOutpostLevels() != 3
            || !dnacCavernFormations()
            || !dnacSurfaceLinks()
            || !dnacSinkholeBandits()
            || !dnacBatsOnly()
            || !dnacDrowLair()
            || !dnacPiercersTrail()
            || !dnacScavengerMix()
            || !dnacDiamondVein()
            || !dnacFoodScarce()
            || !dnacDrowTrapTunnel()
            || !dnacMudPoolGold()
            || !dnacAirWaterChoked()
            || !dnacBeachApproach()
            || !dnacEightCaves()
            || !dnacCastaways()
            || !dnacGlowFungi()
            || !dnacKuoToaOutpost()
            || !dnacMonthlySweeps()
            || !dnacRiverFauna()
            || !dnacNereidPool()
            || !dnacFoamResources()
            || !dnacRiverFinds()
            || !dnacKuoNet()
        )
            ++bad;
        // the Cathedral Caverns geography: the four 1d6-mile caverns, the
        // 100-ft ceilings, the 80-to-90-ft widths, the 400-ft sinkhole, the
        // 5-ft-wide, 1-ft-deep streams.
    if (dnacCavernCount() != 4
            || dnacCavernLenDice() != 1
            || dnacCavernLenSides() != 6
            || dnacCeilingMaxFt() != 100
            || dnacWideLowFt() != 80
            || dnacWideHighFt() != 90
            || dnacSinkholeDepthFt() != 400
            || dnacStreamWidthFt() != 5
            || dnacStreamDepthFt() != 1
        )
            ++bad;
        // the drow lair numbers: the 25 fighters, the 12-HD hydra, the 500-ft
        // approach tunnel under 10 ft wide with its 6d6 falling blocks and
        // the 100-ft oil-pot climb.
    if (dnacDrowFighters() != 25
            || dnacHydraHD() != 12
            || dnacTunnelLenFt() != 500
            || dnacTunnelMaxWidthFt() != 10
            || dnacTrapDice() != 6
            || dnacTrapSides() != 6
            || dnacTunnelClimbFt() != 100
        )
            ++bad;
        // the geothermal mud pool: 20 ft wide, 5 ft deep, 20 gp per coated
        // character, more than 10,000 gp of gold in all.
    if (dnacMudPoolWidthFt() != 20
            || dnacMudPoolDepthFt() != 5
            || dnacMudGoldPerCharGp() != 20
            || dnacMudGoldTotalGp() != 10000
        )
            ++bad;
        // the Enclosed Caverns river: the 3-to-4 flow rate, the rapids a mile
        // before the area, the 80% sweep chance at the cascade, the two
        // rounds to the quiet pool.
    if (dnacRiverFlowLow() != 3
            || dnacRiverFlowHigh() != 4
            || dnacRapidsMiles() != 1
            || dnacSweepChancePct() != 80
            || dnacCascadeRounds() != 2
        )
            ++bad;
        // the cave chain and the chute: eight caves under a mile, the
        // 2-ft-diameter connections, the 50-ft water-filled plunge, the six
        // low-clearance miles to the Area 14 waterfall.
    if (dnacCaveCount() != 8
            || dnacCaveMaxMiles() != 1
            || dnacTunnelDiaFt() != 2
            || dnacWaterFilledFt() != 50
            || dnacLowClearanceMiles() != 6
        )
            ++bad;
        // the denizens' numbers: the 20 castaways, the 6d6 kuo-toa, the
        // 1%-per-hour river-bottom finds, the outpost's three vertical
        // levels.
    if (dnacCastawaysCount() != 20
            || dnacKuoDice() != 6
            || dnacKuoSides() != 6
            || dnacFindChancePct() != 1
            || dnacOutpostLevels() != 3
        )
            ++bad;
        printf("R535 DSG Deepearth areas 4-5 audit: bad %d\n", bad);
        if (bad) return 1;
    }
