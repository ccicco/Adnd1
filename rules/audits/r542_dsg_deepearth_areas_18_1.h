    // ---- R542 DSG Deepearth areas 18-19 audit ----
    // The DSG Deepearth areas 18-19 pin Area 18 (the Steam-Heated Caverns
    // with their hot-stream chute, the six caves, the superheated north
    // tunnel, the fire giant clan and the geysers) and Area 19 (the Chambers
    // of Fire with their fissure eruptions, the mephits, fire bats and
    // magmen, and the remote cavern of toil).
    {
        using namespace rules;
        int bad = 0;
    if (dnakRiverMeetMiles() != 5
            || dnakCaveCount() != 6
            || dnakBlastPctBase() != 2
            || dnakBlastPctStep() != 2
            || dnakBlastDmgDice() != 4
            || dnakBlastDmgSides() != 6
            || dnakStreamDmgDice() != 4
            || dnakStreamDmgSides() != 6
            || dnakGiantClanOver() != 50
            || dnakFatigueDiv() != 2
            || dnakGeyserPoolPct() != 20
            || dnakGeyserDmgDice() != 6
            || dnakGeyserDmgSides() != 6
            || dnakTunnelDmgDice() != 1
            || dnakTunnelDmgSides() != 6
            || dnakEruptTypePct() != 25
            || dnakEruptRoundsDice() != 1
            || dnakEruptRoundsSides() != 6
            || dnakCaveDmgDice() != 1
            || dnakCaveDmgSides() != 6
            || dnakEruptDmgDice() != 6
            || dnakEruptDmgSides() != 6
            || dnakSmokeTurnsDice() != 1
            || dnakSmokeTurnsSides() != 4
            || dnakArchPct() != 50
            || dnakFissureWideDice() != 3
            || dnakFissureWideSides() != 6
            || dnakMephitForms() != 4
            || dnakMephitFollowPct() != 50
            || dnakToilMephitDice() != 1
            || dnakToilMephitSides() != 20
            || dnakToilMephitBase() != 20
            || dnakFissureWideFt() != 20
            || !dnakVolcanicFissures()
            || !dnakHotStreamJoin()
            || !dnakRiverDescends()
            || !dnakSandLanding()
            || !dnakChuteTunnel()
            || !dnakNarrowPassages()
            || !dnakSteamyAir()
            || !dnakPoolRange()
            || !dnakMildewSlip()
            || !dnakBlastSaveHalf()
            || !dnakStreamPartial()
            || !dnakFireHaven()
            || !dnakPlaneSpillover()
            || !dnakPlaneRefugees()
            || !dnakLesserLairs()
            || !dnakFireGiantSway()
            || !dnakSteamFatigue()
            || !dnakNoMinerals()
            || !dnakGeysers()
            || !dnakGeyserSaveHalf()
            || !dnakFireBaked()
            || !dnakDryTunnel()
            || !dnakDouseAvoids()
            || !dnakCircularCaves()
            || !dnakFloorFissures()
            || !dnakFissureBelch()
            || !dnakDouseHalves()
            || !dnakEruptNoAid()
            || !dnakEruptSaveHalf()
            || !dnakPoisonDeath()
            || !dnakSmokeEffects()
            || !dnakUnearthlyOnly()
            || !dnakLavaGasLink()
            || !dnakMephitPurpose()
            || !dnakFireBatsCommon()
            || !dnakMagmenDive()
            || !dnakBadAir()
            || !dnakMildewOnly()
            || !dnakMephitOfferings()
            || !dnakFireproofTools()
        )
            ++bad;
        // the junction and the main caves: five miles south, the six large
        // caves.
    if (dnakRiverMeetMiles() != 5
            || dnakCaveCount() != 6
        )
            ++bad;
        // the north tunnel: 2% per round cumulative in 2% steps, the 4d6
        // blast.
    if (dnakBlastPctBase() != 2
            || dnakBlastPctStep() != 2
            || dnakBlastDmgDice() != 4
            || dnakBlastDmgSides() != 6
        )
            ++bad;
        // the east stream: 4d6 damage per round.
    if (dnakStreamDmgDice() != 4
            || dnakStreamDmgSides() != 6
        )
            ++bad;
        // the fire giant clan over 50; the half-usual fatigue time.
    if (dnakGiantClanOver() != 50
            || dnakFatigueDiv() != 2
        )
            ++bad;
        // the geysers: a 20% pool susceptibility, the 6d6 eruption.
    if (dnakGeyserPoolPct() != 20
            || dnakGeyserDmgDice() != 6
            || dnakGeyserDmgSides() != 6
        )
            ++bad;
        // the Chambers heat: 1d6 per turn in the tunnel, 1d6 per round in the
        // caves.
    if (dnakTunnelDmgDice() != 1
            || dnakTunnelDmgSides() != 6
            || dnakCaveDmgDice() != 1
            || dnakCaveDmgSides() != 6
        )
            ++bad;
        // the fissure eruptions: 25% per type, 1d6 rounds, the 6d6
        // steam-and-fire, the 1d4-turn smoke.
    if (dnakEruptTypePct() != 25
            || dnakEruptRoundsDice() != 1
            || dnakEruptRoundsSides() != 6
            || dnakEruptDmgDice() != 6
            || dnakEruptDmgSides() != 6
            || dnakSmokeTurnsDice() != 1
            || dnakSmokeTurnsSides() != 4
        )
            ++bad;
        // the arch bridges: 50% over the 3d6-foot fissures.
    if (dnakArchPct() != 50
            || dnakFissureWideDice() != 3
            || dnakFissureWideSides() != 6
        )
            ++bad;
        // the mephits: four forms, 50% after the appropriate eruption.
    if (dnakMephitForms() != 4
            || dnakMephitFollowPct() != 50
        )
            ++bad;
        // the toiling mephits: 21-40 (1d20+20) widening the fissure from its
        // current 20 feet.
    if (dnakToilMephitDice() != 1
            || dnakToilMephitSides() != 20
            || dnakToilMephitBase() != 20
            || dnakFissureWideFt() != 20
        )
            ++bad;
        printf("R542 DSG Deepearth areas 18-19 audit: bad %d\n", bad);
        if (bad) return 1;
    }
