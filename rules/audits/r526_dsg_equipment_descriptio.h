    // ---- R526 DSG equipment descriptions audit ----
    // The DSG equipment descriptions pins the item prose - the air bladder
    // (flotation at 1/3 kick rate and a full turn of rest air), the beacon
    // (the 240-ft cone, 90-ft fan, 10 turns per pint), the waterproof lantern
    // (10-ft underwater radius, the secret d6 burn), the lard (the 80%
    // passage, the 2-hp 1d6 fire damage), the waterproofing oil (2 sq yd per
    // pint, 1d6 x 6 pour, 1d6 immersion), the pickaxe (the -2 attack,
    // 1d10/1d20 damage, the halved rates without it), the chalk (400 sq ft, 8
    // characters, the 10-ft cloud), the reed (1/3 movement, 10% ripple), the
    // whistle (1,000 ft), the pulleys (2x/4x/6x), and the transportation
    // equipment (the 1d3-turn collapsible boat at double wet weight, the 3/2
    // and 9/6 canoe crews, the sealed kayak).
    {
        using namespace rules;
        int bad = 0;
    if (dnetBladderKickDiv() != 3
            || dnetBladderRestTurns() != 10
            || dnetBeaconRangeFt() != 240
            || dnetBeaconSourceWidFt() != 2
            || dnetBeaconEndWidFt() != 90
            || dnetBeaconOilTurns() != 10
            || dnetBirdcageHeightIn() != 18
            || dnetBirdcageDiaIn() != 12
            || dnetBirdcageBirds() != 3
            || dnetBoxWidFt() != 2
            || dnetBoxLenFt() != 2
            || dnetBoxDeepIn() != 18
            || dnetDrillHoleWidthIn() != 1
            || dnetDrillHoleDepthIn() != 9
            || dnetDrillWoodInPerTurn() != 1
            || dnetDrillStoneInPerTurnFrac() != 3
            || dnetDrillNoiseFt() != 120
            || dnetLanternUwRadiusFt() != 10
            || dnetLanternNormRadiusFt() != 30
            || dnetLanternBurnDice() != 1
            || dnetLanternBurnSides() != 6
            || dnetLardPassagePct() != 80
            || dnetLardExtraHp() != 2
            || dnetLardExtraDice() != 1
            || dnetLardExtraSides() != 6
            || dnetOilSqYards() != 2
            || dnetOilPourDice() != 1
            || dnetOilPourSides() != 6
            || dnetOilPourMult() != 6
            || dnetOilImmerseDice() != 1
            || dnetOilImmerseSides() != 6
            || dnetOilWetDice() != 1
            || dnetOilWetSides() != 6
            || dnetPickNoPickaxeRatePct() != 50
            || dnetPickAtkPenalty() != 2
            || dnetPickDmgSidesSm() != 10
            || dnetPickDmgSidesLg() != 20
            || dnetChalkFloorSqft() != 400
            || dnetChalkCreatures() != 8
            || dnetChalkCloudDiaFt() != 10
            || dnetReedMoveDiv() != 3
            || dnetReedRipplePct() != 10
            || dnetNoShovelRatePct() != 50
            || dnetWhistleRangeFt() != 1000
            || dnetPulleyDoubleLiftMult() != 2
            || dnetPulleyQuadLiftMult() != 4
            || dnetPulleyTripleLiftMult() != 6
            || dnetBoatUnfoldDice() != 1
            || dnetBoatUnfoldSides() != 3
            || dnetBoatWetMult() != 2
            || dnetCanoeNormalCrew() != 3
            || dnetCanoeHeavyCrew() != 2
            || dnetCanoeLgNormalCrew() != 9
            || dnetCanoeLgHeavyCrew() != 6
            || !dnetBladderFlotationAndAir()
            || !dnetBladderNoSwimNeeded()
            || !dnetBladderAirSupply()
            || !dnetBasketsLatched()
            || !dnetBeaconMounted()
            || !dnetBeaconShuttered()
            || !dnetBirdcageWicker()
            || !dnetBoxesLightproof()
            || !dnetCramponsIce()
            || !dnetDrillBore()
            || !dnetGrapplingHooks()
            || !dnetLanternShielded()
            || !dnetLanternUwDouseByAir()
            || !dnetLardLubricant()
            || !dnetLardInsulator()
            || !dnetOilSources()
            || !dnetPickMinerKit()
            || !dnetChalkUses()
            || !dnetPulleyLoops()
            || !dnetReedBreathing()
            || !dnetReedHardToHide()
            || !dnetShovelMinerKit()
            || !dnetWhistleSimple()
            || !dnetBoatBackpack()
            || !dnetCanoeLight()
            || !dnetKayakSealed()
        )
            ++bad;
        // the big-range numbers: the beacon 240-ft cone with the 90-ft fan
        // and 10-turn pint of oil, the drill noise at 120 feet, and the
        // whistle at 1,000 feet.
    if (dnetBeaconRangeFt() != 240
            || dnetBeaconEndWidFt() != 90
            || dnetBeaconOilTurns() != 10
            || dnetDrillNoiseFt() != 120
            || dnetWhistleRangeFt() != 1000
        )
            ++bad;
        // the lantern and lard numbers: the 10/30-ft radii with the secret d6
        // burn, the 80% passage squeeze, and the 2-hp-per-round fire damage
        // for 1d6 rounds.
    if (dnetLanternUwRadiusFt() != 10
            || dnetLanternNormRadiusFt() != 30
            || dnetLanternBurnDice() != 1
            || dnetLanternBurnSides() != 6
            || dnetLardPassagePct() != 80
            || dnetLardExtraHp() != 2
            || dnetLardExtraSides() != 6
        )
            ++bad;
        // the oil and chalk numbers: the pour/immerse/wet 1d6s, two square
        // yards per pint, and the 400-sq-ft, eight-character, 10-ft-cloud
        // chalk container.
    if (dnetOilPourSides() != 6
            || dnetOilPourMult() != 6
            || dnetOilImmerseSides() != 6
            || dnetOilWetSides() != 6
            || dnetOilSqYards() != 2
            || dnetChalkFloorSqft() != 400
            || dnetChalkCreatures() != 8
            || dnetChalkCloudDiaFt() != 10
        )
            ++bad;
        // the tool numbers: the pickaxe -2 attack and 1d10/1d20 damage with
        // the 50% rates, and the 2x/4x/6x pulley lifts.
    if (dnetPickAtkPenalty() != 2
            || dnetPickDmgSidesSm() != 10
            || dnetPickDmgSidesLg() != 20
            || dnetPickNoPickaxeRatePct() != 50
            || dnetNoShovelRatePct() != 50
            || dnetPulleyDoubleLiftMult() != 2
            || dnetPulleyQuadLiftMult() != 4
            || dnetPulleyTripleLiftMult() != 6
        )
            ++bad;
        // the transportation and reed numbers: the 1d3-turn unfold with the
        // doubled wet weight, the canoe 3/2 and 9/6 crews, and the reed 1/3
        // movement with the 10% ripple.
    if (dnetBoatUnfoldDice() != 1
            || dnetBoatUnfoldSides() != 3
            || dnetBoatWetMult() != 2
            || dnetCanoeNormalCrew() != 3
            || dnetCanoeHeavyCrew() != 2
            || dnetCanoeLgNormalCrew() != 9
            || dnetCanoeLgHeavyCrew() != 6
            || dnetReedMoveDiv() != 3
            || dnetReedRipplePct() != 10
        )
            ++bad;
        // the bladder, kayak, boxes and chalk prose: the 1/3 kick and
        // full-turn rest air, the sealed kayak, the lightproof boxes, and the
        // chalk discovery uses.
    if (dnetBladderKickDiv() != 3
            || dnetBladderRestTurns() != 10
            || dnetBladderNoSwimNeeded() != 1
            || dnetKayakSealed() != 1
            || dnetBoxesLightproof() != 1
            || dnetChalkUses() != 1
        )
            ++bad;
        printf("R526 DSG equipment descriptions audit: bad %d\n", bad);
        if (bad) return 1;
    }
