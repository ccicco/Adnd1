    // ---- R543 DSG Deepearth areas 20-21 audit ----
    // The DSG Deepearth areas 20-21 pin Area 20 (the Lava Caves with their
    // balcony over the lava sea, the fire giant outpost, the island lairs,
    // the granite lava boats and the king's island castle) and Area 21 (the
    // Elemental Vortex of Fire with its 100-ft hole, the Wisdom-Check stare,
    // the 8d8 passage and the molten whirlpool).
    {
        using namespace rules;
        int bad = 0;
    if (dnalEruptWeekDays() != 7
            || dnalCliffFt() != 400
            || dnalCeilMinFt() != 1000
            || dnalOutpostGiants() != 20
            || dnalOutpostHounds() != 12
            || dnalGuardMin() != 1
            || dnalIslandRacePct() != 50
            || dnalInvasionDecades() != 10
            || dnalBoatLenLoFt() != 80
            || dnalBoatLenHiFt() != 240
            || dnalBoatWidthPct() != 20
            || dnalMastThresholdFt() != 160
            || dnalOarsPerFt() != 40
            || dnalHarborMouthFt() != 120
            || dnalTowerGiants() != 12
            || dnalTorchOutPct() != 50
            || dnalCavernDiaFt() != 1000
            || dnalCavernHtFt() != 300
            || dnalHoleDiaFt() != 100
            || dnalStareRounds() != 1
            || dnalElementalDice() != 1
            || dnalElementalSides() != 6
            || dnalReinforcePct() != 50
            || dnalReinforceDice() != 1
            || dnalReinforceSides() != 6
            || dnalVortexDmgDice() != 8
            || dnalVortexDmgSides() != 8
            || dnalReverseRounds() != 5
            || dnalPassageRounds() != 10
            || dnalEmergePct() != 50
            || dnalWhirlpoolDrawFt() != 500
            || !dnalBalconyCave()
            || !dnalTunnelSameRisk()
            || !dnalHalfFallen()
            || !dnalSeaPanorama()
            || !dnalDailyChunks()
            || !dnalSeaSwells()
            || !dnalOutpostControl()
            || !dnalIslandLairs()
            || !dnalMagmenSea()
            || !dnalFireBatsDwell()
            || !dnalMagmaPara()
            || !dnalConquerorForays()
            || !dnalHeatOnly()
            || !dnalBoats()
            || !dnalKingIsland()
            || !dnalNoWater()
            || !dnalWindForce()
            || !dnalVortexRegion()
            || !dnalRottedFormations()
            || !dnalFlatFloor()
            || !dnalHypnoticJump()
            || !dnalNoOtherExits()
            || !dnalVortexGate()
            || !dnalElementalGuard()
            || !dnalReinforceRoster()
            || !dnalReinforceCadence()
            || !dnalSulphurAir()
            || !dnalFeatherFall()
            || !dnalFlyReverse()
            || !dnalCommitted()
            || !dnalPlaneArrival()
            || !dnalTwoConnections()
        )
            ++bad;
        // the lava caves: weekly eruptions, the 400-ft cliff, the 1,000-ft
        // ceiling.
    if (dnalEruptWeekDays() != 7
            || dnalCliffFt() != 400
            || dnalCeilMinFt() != 1000
        )
            ++bad;
        // the outpost: 20 giants, a dozen hounds, at least one of each
        // guarding at all times.
    if (dnalOutpostGiants() != 20
            || dnalOutpostHounds() != 12
            || dnalGuardMin() != 1
        )
            ++bad;
        // the islands: 50% per race, the once-a-decade invasions.
    if (dnalIslandRacePct() != 50
            || dnalInvasionDecades() != 10
        )
            ++bad;
        // the lava boats: 80-240 feet, 20% width, twin masts over 160 feet,
        // an oar pair per 40 feet.
    if (dnalBoatLenLoFt() != 80
            || dnalBoatLenHiFt() != 240
            || dnalBoatWidthPct() != 20
            || dnalMastThresholdFt() != 160
            || dnalOarsPerFt() != 40
        )
            ++bad;
        // the king's island: the 120-ft harbor mouth, a dozen giants per
        // flank tower.
    if (dnalHarborMouthFt() != 120
            || dnalTowerGiants() != 12
        )
            ++bad;
        // the vortex cavern: the 50% torch wind, 1,000 ft across, 300 ft
        // high, the 100-ft hole.
    if (dnalTorchOutPct() != 50
            || dnalCavernDiaFt() != 1000
            || dnalCavernHtFt() != 300
            || dnalHoleDiaFt() != 100
        )
            ++bad;
        // the hole: a Wisdom Check after one round, the 1d6 elementals, the
        // 50% 1d6 reinforcements.
    if (dnalStareRounds() != 1
            || dnalElementalDice() != 1
            || dnalElementalSides() != 6
            || dnalReinforcePct() != 50
            || dnalReinforceDice() != 1
            || dnalReinforceSides() != 6
        )
            ++bad;
        // the passage: 8d8 per round, the five-round escape window, the
        // ten-round journey.
    if (dnalVortexDmgDice() != 8
            || dnalVortexDmgSides() != 8
            || dnalReverseRounds() != 5
            || dnalPassageRounds() != 10
        )
            ++bad;
        // the two connections: 50% either way, boats drawn within 500 feet of
        // the whirlpool.
    if (dnalEmergePct() != 50
            || dnalWhirlpoolDrawFt() != 500
        )
            ++bad;
        printf("R543 DSG Deepearth areas 20-21 audit: bad %d\n", bad);
        if (bad) return 1;
    }
