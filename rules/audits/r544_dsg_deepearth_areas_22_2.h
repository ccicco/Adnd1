    // ---- R544 DSG Deepearth areas 22-23 audit ----
    // The DSG Deepearth areas 22-23 pin Area 22 (the Lands of the Deep Gnomes
    // with their three-level caverns, the clan council chambers, the
    // 5,000-svirfneblin population, the rothe herds, the mines, the smelter
    // and the 550-Strength silver vault) and Area 23 (the Lower Grand Canyon
    // with its spectator galleries, the 20-ft bridge and the
    // three-dimensional champion arena).
    {
        using namespace rules;
        int bad = 0;
    if (dnamCavernLevels() != 3
            || dnamCaveWideFt() != 20
            || dnamCaveHighFt() != 10
            || dnamPinchPerMile() != 1
            || dnamPinchDiaLoFt() != 2
            || dnamPinchDiaHiFt() != 3
            || dnamCouncilDiaFt() != 60
            || dnamCouncilHighFt() != 8
            || dnamMeetingDiaFt() != 200
            || dnamMeetingCeilFt() != 10
            || dnamSvirfPop() != 5000
            || dnamRothePerClan() != 100
            || dnamHerdMultLo() != 8
            || dnamHerdMultHi() != 10
            || dnamMineShaftMiles() != 5
            || dnamVaultStr() != 550
            || dnamSilverBarSp() != 500
            || dnamWallsDescendFt() != 1200
            || dnamGalleryCap() != 1000
            || dnamCanyonWideFt() != 1000
            || dnamBridgeWideFt() != 20
            || !dnamNorthSouthCaverns()
            || !dnamNarrowStretches()
            || !dnamStreamsDryFeet()
            || !dnamGnomeStairways()
            || !dnamExcavatedHomes()
            || !dnamClanPerCave()
            || !dnamMeetingChamber()
            || !dnamThirdMobilize()
            || !dnamRotheHerds()
            || !dnamTrickleWater()
            || !dnamCanyonAir()
            || !dnamEdibleFungi()
            || !dnamGnomeMines()
            || !dnamSmelter()
            || !dnamSmithSurplus()
            || !dnamVaultDoor()
            || !dnamLowerCanyon()
            || !dnamBridgedDomains()
            || !dnamCarvedGalleries()
            || !dnamArenaWeb()
            || !dnamArea7Denizens()
            || !dnamChampionDuels()
            || !dnamNonmissileArms()
            || !dnamArenaManeuver()
        )
            ++bad;
        // the gnome caverns: three levels, 20 ft wide, 10 ft high.
    if (dnamCavernLevels() != 3
            || dnamCaveWideFt() != 20
            || dnamCaveHighFt() != 10
        )
            ++bad;
        // the pinches: once per mile, two to three feet across.
    if (dnamPinchPerMile() != 1
            || dnamPinchDiaLoFt() != 2
            || dnamPinchDiaHiFt() != 3
        )
            ++bad;
        // the chambers: the 60-ft/8-ft council rooms, the 200-ft/10-ft
        // meeting hall.
    if (dnamCouncilDiaFt() != 60
            || dnamCouncilHighFt() != 8
            || dnamMeetingDiaFt() != 200
            || dnamMeetingCeilFt() != 10
        )
            ++bad;
        // the population: ~5,000 svirfneblin, 100 rothe per clan, herds eight
        // or 10 times larger.
    if (dnamSvirfPop() != 5000
            || dnamRothePerClan() != 100
            || dnamHerdMultLo() != 8
            || dnamHerdMultHi() != 10
        )
            ++bad;
        // the works: five-mile shafts, the 550-Strength vault door, 500-sp
        // silver bars.
    if (dnamMineShaftMiles() != 5
            || dnamVaultStr() != 550
            || dnamSilverBarSp() != 500
        )
            ++bad;
        // the lower canyon: 1,200-ft walls, thousand-spectator galleries, the
        // 1,000-ft span, the 20-ft bridge.
    if (dnamWallsDescendFt() != 1200
            || dnamGalleryCap() != 1000
            || dnamCanyonWideFt() != 1000
            || dnamBridgeWideFt() != 20
        )
            ++bad;
        printf("R544 DSG Deepearth areas 22-23 audit: bad %d\n", bad);
        if (bad) return 1;
    }
