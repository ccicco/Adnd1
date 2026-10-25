    // ---- R545 DSG Deepearth areas 24-25 audit ----
    // The DSG Deepearth areas 24-25 pin Area 24 (the Domain of the Duergar
    // with its hundred caves, dammed reservoirs, slave mines, gold sculptors
    // and fungus breweries) and Area 25 (the Windpipe with its six living
    // caves, the drow outpost, and the alternating-blast shaft to the
    // mountain crevasse).
    {
        using namespace rules;
        int bad = 0;
    if (dnanCaveCount() != 100
            || dnanOutflowWideFt() != 30
            || dnanDuergarPop() != 8000
            || dnanSlaveEscapePct() != 25
            || dnanResGoldDice() != 1
            || dnanResGoldSides() != 6
            || dnanResGoldMult() != 100
            || dnanLargeResMult() != 6
            || dnanPubGoldDice() != 2
            || dnanPubGoldSides() != 6
            || dnanPubGoldMult() != 1000
            || dnanStatueGp() != 20000
            || dnanIntactDice() != 1
            || dnanIntactSides() != 4
            || dnanIntactBase() != 1
            || dnanWindCaves() != 6
            || dnanWindChamberHtFt() != 80
            || dnanDrowFighterLvl() != 4
            || dnanDrowCasterLvl() != 5
            || dnanPoolPollutePct() != 50
            || dnanPureSourcesMin() != 1
            || dnanShaftWideFt() != 20
            || dnanShaftMiles() != 20
            || dnanUpBlastTurns() != 1
            || dnanInactiveTurns() != 4
            || dnanDownBlastTurns() != 1
            || dnanTimingVaryPct() != 50
            || dnanJourneyUpRounds() != 5
            || dnanJourneyDownRounds() != 8
            || dnanWindFallDice() != 6
            || dnanWindFallSides() != 6
            || !dnanGrayDwarfHome()
            || !dnanLivingCaves()
            || !dnanDammedReservoirs()
            || !dnanCentralCaverns()
            || !dnanOutflowWalk()
            || !dnanDerroTenants()
            || !dnanSlaveCaverns()
            || !dnanGiantBats()
            || !dnanRotheHerds()
            || !dnanAirDucts()
            || !dnanSlaveMines()
            || !dnanIronCopperGold()
            || !dnanGoldSculptors()
            || !dnanFungusBrew()
            || !dnanWindRoutes()
            || !dnanMilesLongCham()
            || !dnanDrowOutpost()
            || !dnanWindFauna()
            || !dnanWindShaft()
            || !dnanAlternatingBlasts()
            || !dnanWindSkill()
        )
            ++bad;
        // the domain: nearly 100 caves, the 30-ft outflow, the 8,000 duergar.
    if (dnanCaveCount() != 100
            || dnanOutflowWideFt() != 30
            || dnanDuergarPop() != 8000
        )
            ++bad;
        // the slaves: a 25% chance a group joins an escape.
    if (dnanSlaveEscapePct() != 25
        )
            ++bad;
        // the gold: 1d6x100 gp per residence, six times in the larger,
        // 2d6x1,000 gp in public.
    if (dnanResGoldDice() != 1
            || dnanResGoldSides() != 6
            || dnanResGoldMult() != 100
            || dnanLargeResMult() != 6
            || dnanPubGoldDice() != 2
            || dnanPubGoldSides() != 6
            || dnanPubGoldMult() != 1000
        )
            ++bad;
        // the statues: 20,000 gp of gold each, worth 1d4+1 times intact on
        // the surface.
    if (dnanStatueGp() != 20000
            || dnanIntactDice() != 1
            || dnanIntactSides() != 4
            || dnanIntactBase() != 1
        )
            ++bad;
        // the windpipe caves: six of them, 80-ft chambers, the 20-ft shaft
        // running 20 miles.
    if (dnanWindCaves() != 6
            || dnanWindChamberHtFt() != 80
            || dnanShaftWideFt() != 20
            || dnanShaftMiles() != 20
        )
            ++bad;
        // the drow and the water: 4th+ fighters, 5th+ casters, 50% polluted
        // pools, one or two pure sources per cave.
    if (dnanDrowFighterLvl() != 4
            || dnanDrowCasterLvl() != 5
            || dnanPoolPollutePct() != 50
            || dnanPureSourcesMin() != 1
        )
            ++bad;
        // the cycle: one turn up-blasting, four inactive, one down, varying
        // as much as 50%.
    if (dnanUpBlastTurns() != 1
            || dnanInactiveTurns() != 4
            || dnanDownBlastTurns() != 1
            || dnanTimingVaryPct() != 50
        )
            ++bad;
        // the ride: five rounds up, eight down, the 6d6 failed-halt fall.
    if (dnanJourneyUpRounds() != 5
            || dnanJourneyDownRounds() != 8
            || dnanWindFallDice() != 6
            || dnanWindFallSides() != 6
        )
            ++bad;
        printf("R545 DSG Deepearth areas 24-25 audit: bad %d\n", bad);
        if (bad) return 1;
    }
