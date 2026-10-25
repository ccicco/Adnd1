    // ---- R537 DSG Deepearth areas 8-9 audit ----
    // The DSG Deepearth areas 8-9 pin Area 8 (the Fungus Forest with its
    // myconid tenders, spore zombies and glowing levitating boulder) and Area
    // 9 (the Caverns of Doom with its six immense caverns, the irrigation
    // works, the pech diamond mine and the jermalaine honeycomb).
    {
        using namespace rules;
        int bad = 0;
    if (dnafChamberHtLowFt() != 50
            || dnafChamberHtHighFt() != 60
            || dnafCapMaxFt() != 30
            || dnafMyconidCircle() != 20
            || dnafGlowBoulderDiaFt() != 1
            || dnafRouteDice() != 1
            || dnafRouteSides() != 3
            || dnafRouteMultFt() != 10
            || dnafBranchCaverns() != 5
            || dnafCentralCaverns() != 6
            || dnafCavernWidthFt() != 1000
            || dnafCavernLenDice() != 2
            || dnafCavernLenSides() != 6
            || dnafConnectWideFt() != 20
            || dnafConnectHighFt() != 10
            || dnafPipelineDiaFt() != 2
            || dnafWaterCaverns() != 3
            || dnafJermaineDiaLowIn() != 18
            || dnafJermaineDiaHighIn() != 24
            || dnafJermaineExitHeightFt() != 20
            || dnafDuergarCaves() != 3
            || !dnafMazeCircle()
            || !dnafFungiCarpet()
            || !dnafCrushedPaths()
            || !dnafMyconidTenders()
            || !dnafIrrigationRelay()
            || !dnafMyconidKing()
            || !dnafSporeZombies()
            || !dnafAirCistern()
            || !dnafUnlimitedFood()
            || !dnafGlowStone()
            || !dnafKeyHub()
            || !dnafDeadCave()
            || !dnafDoomName()
            || !dnafRacePockets()
            || !dnafCityRaiders()
            || !dnafMonsterMenagerie()
            || !dnafEdibleFungi()
            || !dnafIrrigationWorks()
            || !dnafCavePigs()
            || !dnafPechMining()
            || !dnafPechDiamondMine()
            || !dnafDuergarFort()
            || !dnafJermaineHoneycomb()
        )
            ++bad;
        // the Fungus Forest numbers: the 50/60-ft chamber heights, the 30-ft
        // mushroom caps, the myconid circle of 20, the one-foot glowing
        // boulder.
    if (dnafChamberHtLowFt() != 50
            || dnafChamberHtHighFt() != 60
            || dnafCapMaxFt() != 30
            || dnafMyconidCircle() != 20
            || dnafGlowBoulderDiaFt() != 1
        )
            ++bad;
        // the Caverns of Doom layout: the 1d3x10-ft city route, the five
        // branch caverns, the six linked central caverns.
    if (dnafRouteDice() != 1
            || dnafRouteSides() != 3
            || dnafRouteMultFt() != 10
            || dnafBranchCaverns() != 5
            || dnafCentralCaverns() != 6
        )
            ++bad;
        // the great caverns: widths approaching 1,000 feet, lengths of 2d6
        // miles, connections at least 20 ft wide and 10 ft high.
    if (dnafCavernWidthFt() != 1000
            || dnafCavernLenDice() != 2
            || dnafCavernLenSides() != 6
            || dnafConnectWideFt() != 20
            || dnafConnectHighFt() != 10
        )
            ++bad;
        // the water works: the sub-2-ft pipelines to Area 4, the three
        // receiving caverns, the duergar pool's three blocked approach caves.
    if (dnafPipelineDiaFt() != 2
            || dnafWaterCaverns() != 3
            || dnafDuergarCaves() != 3
        )
            ++bad;
        // the jermalaine warren: the 18-to-24-inch lair passages, the exits
        // dug 20 feet off the cavern floor.
    if (dnafJermaineDiaLowIn() != 18
            || dnafJermaineDiaHighIn() != 24
            || dnafJermaineExitHeightFt() != 20
        )
            ++bad;
        printf("R537 DSG Deepearth areas 8-9 audit: bad %d\n", bad);
        if (bad) return 1;
    }
