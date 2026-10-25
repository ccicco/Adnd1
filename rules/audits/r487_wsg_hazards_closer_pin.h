    // ---- R487 WSG hazards closer pin audit ----
    // The natural hazards closer: the tidal wave death tail - the direct-path
    // victim drowns shortly after being knocked unconscious, the late inland
    // hit survivable by going with the flow for a swimming-proficient
    // character, the non-swimmer doomed even at the very end. Floods: water
    // flows downhill and spreads beyond its container, born of heavy rain or
    // a snowmelt heat wave, worse over frozen ground, usually beside a river
    // or lake; the flash flood is fleeting - minutes, not days - most often
    // in mountainous terrain without a water body, a trickle at 10,000 feet a
    // 30-50 mph torrent at 5,000; avoid a pass or gully within 2-3 hours of
    // rain. Caught: the swimmer avoids drowning but not the battering against
    // rocks and trees, the non-swimmer treads toward refuge, the protrusion
    // grab is a Strength Check with 1d3-to-1d6 batter damage on failure and a
    // re-check every 2 rounds while holding; d6+9 rounds of flood at any
    // point, 3d8 hours of afterflow. Avalanches: snow or ice down a
    // mountainside needing a 12-inch cover, favored by warm sun and bare
    // rock; growing as it falls, worst at the slope base; 2d10-to-3d20 damage
    // halved by curling, a bend bars roll to avoid being swept while
    // standing, a 50 percent hold while huddled; 2d3 feet of burial, 4d3 at
    // the bottom; a Constitution Check for consciousness; 1 foot per round of
    // self-dig with a secret Wisdom Check for direction unless huddled and
    // oriented; the 10 percent find chance plus 1 per intelligence and 25 for
    // a digging victim, checked per searcher per victim; 2 and 3 feet per
    // round of rescue digging, three diggers plus 1 foot each; 1d6+4 rounds
    // of trapped air, then breath-holding and Constitution Checks. Rockfalls:
    // freeze-thaw cracks in valley-walled peaks, crumbling faces every two
    // months, loose rock the tell; the slope attack is 4 per round for 1d4+1
    // rounds at 5 hit dice for 1d4 each, Dex halving but never below 1, more
    // than 20 points sweeping the victim down the slope; the shield overhead
    // intercepts 75 percent given both hands and a round from the back or a
    // half from the belt; the cliff face runs 1-2 rounds at 7 hit dice and
    // 1d6, the count from 1d4-1 if warned or 1d6-3 if not, a Climbing Check
    // on any roll of 3 or more and unconsciousness on two 5-or-6 head hits;
    // the base is 10 hit dice and 1d8 with the same head rule and no chance
    // of falling. Mudslides: thick loose topsoil drenched on a moderate or
    // severe slope, half-water mud on the moderate slope and less on the
    // severe; grab rooted vegetation or ride down unhurt unless the valley
    // collects a sinking depth; the swimmer rides on top at 1 inch per round,
    // the non-swimmer treads for half his afloat time then Strength Checks
    // per round and breath and Constitution Checks below. Quicksand:
    // saturated swamp ground, sandy faster than muddy, no suction - tread and
    // swim to safety, the pole rescue for a non-swimmer, and only a
    // swimming-proficient rescuer may enter.
    {
        using namespace rules;
        int bad = 0;
    if (whz2FlashStartElevFt() != 10000
            || whz2FlashLowerElevFt() != 5000
            || whz2FlashMinMph() != 30
            || whz2FlashMaxMph() != 50
            || whz2PassRainWindowHrs() != 3
            || whz2GrabFailDmgMin() != 3
            || whz2GrabFailDmgMax() != 6
            || whz2FlashRoundsMin() != 10
            || whz2FlashRoundsMax() != 15
            || whz2AfterflowHoursMin() != 3
            || whz2AfterflowHoursMax() != 24
            || whz2AvalancheSnowInches() != 12
            || whz2AvalancheDmgMin() != 2
            || whz2AvalancheDmgMax() != 60
            || whz2HuddledHoldPct() != 50
            || whz2BuriedFtMin() != 2
            || whz2BuriedFtMax() != 6
            || whz2BuriedBottomMin() != 4
            || whz2BuriedBottomMax() != 12
            || whz2DigSelfFtPerRound() != 1
            || whz2FindBasePct() != 10
            || whz2FindPerIntPct() != 1
            || whz2FindVictimDiggingBonusPct() != 25
            || whz2DigHandsFtPerRound() != 2
            || whz2DigToolFtPerRound() != 3
            || whz2MaxDiggers() != 3
            || whz2ExtraDiggerFtPerRound() != 1
            || whz2AirRoundsMin() != 5
            || whz2AirRoundsMax() != 10
            || whz2ProneRockfallMonths() != 2
            || whz2RockAtkPerRound() != 4
            || whz2RockDurationMin() != 2
            || whz2RockDurationMax() != 5
            || whz2RockMonsterHd() != 5
            || whz2RockDmgDie() != 4
            || whz2RockSweepDmgThreshold() != 20
            || whz2ShieldInterceptPct() != 75
            || whz2ShieldUnstrapBackRounds() != 1
            || whz2ShieldUnstrapBeltHalfRounds() != 1
            || whz2CliffRockRoundsMin() != 1
            || whz2CliffRockRoundsMax() != 2
            || whz2CliffRocksMaxPerRound() != 3
            || whz2CliffRockMonsterHd() != 7
            || whz2CliffNoticedDieMax() != 4
            || whz2CliffUnnoticedDieMax() != 6
            || whz2CliffRockDmgDie() != 6
            || whz2ClimbCheckDmgRoll() != 3
            || whz2HeadHitDmgRoll() != 5
            || whz2BaseRockMonsterHd() != 10
            || whz2BaseRockDmgDie() != 8
            || whz2BaseHeadHitDmgRoll() != 5
            || whz2MudSwimMoveInches() != 1
            || !whz2TidalDirectPathDrowns()
            || !whz2TidalLateSurvivable()
            || !whz2TidalNonSwimmerDoomed()
            || !whz2TidalDMJudgment()
            || !whz2WaterFlowsDownhill()
            || !whz2OverflowBeyondContainer()
            || !whz2FloodFromHeavyRain()
            || !whz2FloodFromSnowmelt()
            || !whz2FrozenGroundIntensifies()
            || !whz2FloodNearRiverLake()
            || !whz2FlashFleeting()
            || !whz2FlashMountainous()
            || !whz2TidalLikeFlashFlood()
            || !whz2AvoidByMovingAway()
            || !whz2PassGullyWarning()
            || !whz2SwimmerAvoidsDrowning()
            || !whz2NonSwimmerTreads()
            || !whz2GrabProtrusion()
            || !whz2HoldEvery2Rounds()
            || !whz2AvalancheSnowIce()
            || !whz2RockfallEarthRock()
            || !whz2MudslideEarthWater()
            || !whz2AvalancheWarmDay()
            || !whz2BareRockIncreases()
            || !whz2AvalancheGrowsAsFalls()
            || !whz2BaseWorseThanUpslope()
            || !whz2CurlHalvesDamage()
            || !whz2StandingBendBars()
            || !whz2BuriedConCheck()
            || !whz2HuddledOriented()
            || !whz2OthersWisdomCheck()
            || !whz2FindPerSearcherPerVictim()
            || !whz2SnowNotAirtight()
            || !whz2BreathThenConChecks()
            || !whz2RockfallValleyPeaks()
            || !whz2RockfallCrackFreezeThaw()
            || !whz2CrumblingRockProne()
            || !whz2LooseRockSign()
            || !whz2DexHalvesRockDmg()
            || !whz2ShieldOverHead()
            || !whz2ShieldConditions()
            || !whz2UnconsciousFalls()
            || !whz2MudslideConditions()
            || !whz2MudslideModerateMix()
            || !whz2MudslideGrabVegetation()
            || !whz2MudslideRideSafe()
            || !whz2MudslideValleySink()
            || !whz2MudSwimmerStaysOnTop()
            || !whz2MudNonSwimmerHalfAfloat()
            || !whz2MudStrengthCheckPerRound()
            || !whz2MudBreathThenCon()
            || !whz2QuicksandInWetLowland()
            || !whz2QuicksandCanBeMud()
            || !whz2SandyQuicksandWorse()
            || !whz2QuicksandNoSuction()
            || !whz2QuicksandSelfRescue()
            || !whz2QuicksandSameAsMudslide()
            || !whz2PoleRescue()
            || !whz2RescuerMustSwim()
        )
            ++bad;
        // the flood dice: a flash flood runs d6+9 rounds and leaves 3d8 hours
        // of afterflow, and the battering damage spans 1d3 to 1d6
    if (whz2FlashRoundsMin() + 5 != whz2FlashRoundsMax()
            || whz2AfterflowHoursMin() + 21 != whz2AfterflowHoursMax()
            || whz2GrabFailDmgMin() + 3 != whz2GrabFailDmgMax()
        )
            ++bad;
        // the flash flood speeds 30 to 50 mph downhill from a 10,000-foot
        // trickle to a 5,000-foot torrent
    if (whz2FlashMinMph() + 20 != whz2FlashMaxMph()
            || whz2FlashLowerElevFt() * 2 != whz2FlashStartElevFt()
        )
            ++bad;
        // the avalanche dice: 2d10 to 3d20 damage, 2d3 feet of burial or 4d3
        // at the bottom, 1d6+4 rounds of trapped air
    if (whz2AvalancheDmgMin() + 58 != whz2AvalancheDmgMax()
            || whz2BuriedFtMin() + 4 != whz2BuriedFtMax()
            || whz2BuriedBottomMin() + 8 != whz2BuriedBottomMax()
            || whz2AirRoundsMin() + 5 != whz2AirRoundsMax()
        )
            ++bad;
        // the dig rates: 1 foot per round digging out alone, 2 with hands or
        // 3 with a tool for a comrade, plus 1 per extra digger up to 3
    if (whz2DigHandsFtPerRound() + 1 != whz2DigToolFtPerRound()
            || whz2DigSelfFtPerRound() != 1
            || whz2ExtraDiggerFtPerRound() != 1
            || whz2MaxDiggers() != 3
        )
            ++bad;
        // the find chance builds from the 10 percent base: +1 per
        // intelligence point and +25 if the victim digs, for 35 before
        // intelligence
    if (whz2FindBasePct() + whz2FindVictimDiggingBonusPct() != 35
            || whz2FindPerIntPct() != 1
        )
            ++bad;
        // the rockfall monster hit dice and damage dice strictly ascend by
        // position: 5 HD 1d4 on the slope, 7 HD 1d6 on the cliff face, 10 HD
        // 1d8 at the base
    if (whz2RockMonsterHd() >= whz2CliffRockMonsterHd()
            || whz2CliffRockMonsterHd() >= whz2BaseRockMonsterHd()
            || whz2RockDmgDie() >= whz2CliffRockDmgDie()
            || whz2CliffRockDmgDie() >= whz2BaseRockDmgDie()
        )
            ++bad;
        // the slope rockfall: 4 attacks per round for 1d4+1 rounds
    if (whz2RockAtkPerRound() != 4
            || whz2RockDurationMin() + 3 != whz2RockDurationMax()
        )
            ++bad;
        // the two cliff-face count formulas agree in range - 1d4-1 for the
        // warned climbers and 1d6-3 for the unwarned, both topping out at 3
        // rocks per round
    if (whz2CliffNoticedDieMax() + 2 != whz2CliffUnnoticedDieMax()
            || whz2CliffRocksMaxPerRound() != 3
        )
            ++bad;
        // the cliff-face threshold dice: any roll of 3 or more forces a
        // Climbing Check and a 5 or 6 is a head hit, on both the 1d6 cliff
        // face and the 1d8 base
    if (whz2ClimbCheckDmgRoll() >= whz2HeadHitDmgRoll()
            || whz2BaseHeadHitDmgRoll() != whz2HeadHitDmgRoll()
        )
            ++bad;
        // the shield intercepts 75 percent, the huddled character holds 50
        // percent of the time, and the prone area sheds a significant
        // rockfall every 2 months
    if (whz2ShieldInterceptPct() != 75
            || whz2HuddledHoldPct() != 50
            || whz2ProneRockfallMonths() != 2
        )
            ++bad;
        // the cliff-face rockfall lasts 1-2 rounds, the mud swimmer creeps at
        // the 1-inch rate, and the pass danger window is 3 hours
    if (whz2CliffRockRoundsMin() + 1 != whz2CliffRockRoundsMax()
            || whz2MudSwimMoveInches() != 1
            || whz2PassRainWindowHrs() != 3
        )
            ++bad;
        printf("R487 WSG hazards closer pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
