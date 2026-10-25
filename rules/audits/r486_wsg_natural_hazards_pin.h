    // ---- R486 WSG natural hazards pin audit ----
    // The natural hazards opener: three types of volcanic eruption, each
    // volcano locked to one type - lava, ash, or explosive. Lava: magma
    // inside, lava expelled; fluid magma sprays less violently, side fissures
    // dissipate but never eliminate the crater flow; lava incinerates
    // combustibles even barely flowing, and after it stops retains
    // serious-burn heat for 2d3 weeks; a mobile character almost certainly
    // avoids the 250-yards-per-hour flow, but the pyroclastic bombs and
    // blocks are the greater danger. The 1d4 lava bands: 1-2 fluid magma for
    // 2d6 days, 1d6 damage per turn within 500 yards, a 50-degree rise one
    // quarter mile out tapering 10 degrees per quarter mile to nothing at 1.5
    // miles; 3 thick magma for 2d4 days, 1d4 per turn within 500 yards, a
    // 30-degree rise dying at 1 mile; 4 thick magma plus pyroclastics - 1
    // percent per hour within 1000 yards, 2d6 from a hit, plus 5 percent and
    // 1d6 per 100 yards closer. Ash: overshadowed lava, seldom violent past
    // the initial blast; the 2000-3000 foot opaque cloud, lighter ash carried
    // dozens of miles settling 3-4 inches; ash kills green plants yet is a
    // supreme fertilizer; St. Helens 1980-1981, six incidents over 10 months,
    // superheated-gas snowmelt mudslides over 100,000 acres, the May 18 1980
    // blast equal to 10 megatons flattening trees 4 miles out, the peak
    // dropping from 9,677 to 8,364 feet. The 1d6 ash bands: 1-3 light to
    // moderate, at least 12 hours daily for 1d4+2 weeks, 2 inches at 1d10+15
    // miles downwind, 6 inches within 1d6+4 miles, 1d3 burn per turn within
    // 2000 yards unless sheltered, save versus breath weapon each turn
    // against a choking fit (-4 to hit, +4 to be hit), two straight failures
    // meaning 1d4 per round and death inside one turn without aid; 4-5 heavy,
    // 1d6+5 hours daily for 1d3 weeks, significant ash at 1d6+9 miles, 9
    // inches within 1d6+2 miles, the danger zone widening to 4000 yards; 6
    // heavy plus pyroclastics for the first 3-8 days. Explosive: the opening
    // salvo blows the top off, the peak collapsing into the magma chamber;
    // sight range is mortal danger - the ash cloud and the 3-5-mile glowing
    // avalanche exude double-strength cloudkill, half a round of breath
    // slaying below 8+1 hit dice, 8+1 through 10+1 saving at -4, above saving
    // normally; 1d3 days of ash puffs, lava leaks and tremors warn first.
    // Earthquakes: fault-line pressure, shock waves outdamaging the shift,
    // quakes triggering quakes, aftershocks for days, wilderness scope only.
    // Light: seconds of shiver, no direct harm, but spells ruined, the
    // jostled trap-working thief failing 50 percent of the time, the
    // tightrope walker halved and falling without a Dexterity Check.
    // Moderate: 10-15 seconds (d6+9), 20 percent shorter, 30 percent longer
    // to 30; dislodges from precarious perches, the straddled limb needing
    // both Dexterity and Strength, Climbing at -50 percent, the specialist
    // missile at -2 save point blank, the non-specialist at -3, -5 and -7,
    // melee at -3 with the slip-and-fall on a miss, rockfall or mudslide at
    // the cliff base, the 1-in-8 uprooted tree, the fissure with falling,
    // abrasion and crush. Severe: everything doubled, Climbing -100 percent,
    // melee -6, the rockfall chance twice as great, 40-90 seconds, hit the
    // ground. Tidal waves: born of undersea cataclysm, the ocean absorbing
    // and passing on the shock for thousands of miles; sighted half a mile
    // out, at least 150 mph, less than 30 seconds of warning, at least 75
    // feet by 500 feet, almost 30 million gallons; rushing inland several
    // miles at 20 mph, the 5,000-foot cliff sparing those hundreds of yards
    // back while the 20-mile lowland fears as much as the coast; the
    // direct-path victim dies. The section cuts mid-sentence at the page
    // bottom - the death-rule continuation rides with R487.
    {
        using namespace rules;
        int bad = 0;
    if (whzVolcanoEruptionTypes() != 3
            || whzLavaHeatWeeksMin() != 2
            || whzLavaHeatWeeksMax() != 6
            || whzLavaFlowYardsPerHour() != 250
            || whzFluidLavaDaysMin() != 2
            || whzFluidLavaDaysMax() != 12
            || whzFluidLavaHeatDmgDie() != 6
            || whzFluidTempRiseDeg() != 50
            || whzLavaHeatRangeYards() != 500
            || whzLavaTempTaperDeg() != 10
            || whzFluidNoHeatQmi() != 6
            || whzThickLavaDaysMin() != 2
            || whzThickLavaDaysMax() != 8
            || whzThickLavaHeatDmgDie() != 4
            || whzThickTempRiseDeg() != 30
            || whzThickNoHeatQmi() != 4
            || whzPyroclasticRangeYards() != 1000
            || whzPyroclasticHitChancePct() != 1
            || whzPyroclasticDmgMin() != 2
            || whzPyroclasticDmgMax() != 12
            || whzPyroclasticStepYards() != 100
            || whzPyroclasticChanceStepPct() != 5
            || whzPyroclasticDmgStepDie() != 6
            || whzAshCloudHeightMinFt() != 2000
            || whzAshCloudHeightMaxFt() != 3000
            || whzAshFarAccumInchesMin() != 3
            || whzAshFarAccumInchesMax() != 4
            || whzStHelensYear() != 1980
            || whzStHelensIncidents() != 6
            || whzStHelensMonths() != 10
            || whzStHelensMudslideAcres() != 100000
            || whzStHelensBlastMegatons() != 10
            || whzStHelensTreesMiles() != 4
            || whzStHelensBeforeFt() != 9677
            || whzStHelensAfterFt() != 8364
            || whzAshLightDailyHours() != 12
            || whzAshLightWeeksMin() != 3
            || whzAshLightWeeksMax() != 6
            || whzAshLightFarAccumInches() != 2
            || whzAshLightFarMilesMin() != 16
            || whzAshLightFarMilesMax() != 25
            || whzAshLightNearAccumInches() != 6
            || whzAshLightNearMilesMin() != 5
            || whzAshLightNearMilesMax() != 10
            || whzAshLightDangerYards() != 2000
            || whzAshBurnDmgDie() != 3
            || whzChokeAtkPenalty() != 4
            || whzChokeBeHitBonus() != 4
            || whzAsphyxDmgDie() != 4
            || whzAshHeavyHoursMin() != 6
            || whzAshHeavyHoursMax() != 11
            || whzAshHeavyWeeksMin() != 1
            || whzAshHeavyWeeksMax() != 3
            || whzAshHeavyFarMilesMin() != 10
            || whzAshHeavyFarMilesMax() != 15
            || whzAshHeavyNearAccumInches() != 9
            || whzAshHeavyNearMilesMin() != 3
            || whzAshHeavyNearMilesMax() != 8
            || whzAshHeavyDangerYards() != 4000
            || whzAshSixPyrDaysMin() != 3
            || whzAshSixPyrDaysMax() != 8
            || whzGlowingAvalancheMilesMin() != 3
            || whzGlowingAvalancheMilesMax() != 5
            || whzCloudkillStrength() != 2
            || whzCloudkillSlaysBelowHd() != 9
            || whzCloudkillMidSavePenalty() != 4
            || whzCloudkillMidMaxHd() != 11
            || whzExplosiveWarningDaysMax() != 3
            || whzQuakeClasses() != 3
            || whzLightQuakeThiefFailPct() != 50
            || whzModQuakeSecMin() != 10
            || whzModQuakeSecMax() != 15
            || whzModQuakeLessPct() != 20
            || whzModQuakeMorePct() != 30
            || whzModQuakeMoreSecMax() != 30
            || whzModQuakeClimbPenaltyPct() != 50
            || whzModQuakeSpecMissilePenalty() != 2
            || whzModQuakeNonSpecShort() != 3
            || whzModQuakeNonSpecMed() != 5
            || whzModQuakeNonSpecLong() != 7
            || whzModQuakeMeleePenalty() != 3
            || whzModQuakeTreeFallChance() != 8
            || whzSevQuakeClimbPenaltyPct() != 100
            || whzSevQuakeMeleePenalty() != 6
            || whzSevQuakeSecMin() != 40
            || whzSevQuakeSecMax() != 90
            || whzTidalSightHalfMiles() != 1
            || whzTidalMinMph() != 150
            || whzTidalMaxWarnSec() != 30
            || whzTidalMinHeightFt() != 75
            || whzTidalLengthFt() != 500
            || whzTidalVolumeMillionGal() != 30
            || whzTidalInlandMph() != 20
            || whzTidalCliffFt() != 5000
            || whzTidalLowlandMiles() != 20
            || !whzOneTypePerVolcano()
            || !whzDormantAwakensFast()
            || !whzPerpetuallyActive()
            || !whzMagmaInsideLavaOut()
            || !whzLavaSpraysWhenThick()
            || !whzFluidMagmaLessViolent()
            || !whzLavaSideFissures()
            || !whzLavaTopAndSides()
            || !whzLavaIncinerates()
            || !whzLavaAvoidable()
            || !whzPyroclasticBombsBlocks()
            || !whzAshEruptionsExpelLava()
            || !whzAshSeldomViolent()
            || !whzAshCloudOpaque()
            || !whzAshLighterCarriedFar()
            || !whzAshKillsPlants()
            || !whzAshFertilizer()
            || !whzStHelensWasAshEruption()
            || !whzStHelensSnowmeltMudslides()
            || !whzStHelensPeakPulverized()
            || !whzAshShelterProtects()
            || !whzChokeSaveBreathWeapon()
            || !whzChokeTwoFailsAsphyxiate()
            || !whzAsphyxAidWithinTurn()
            || !whzAshHeavyUnprotectedEffects()
            || !whzExplosiveBlowsTop()
            || !whzExplosivePeakCollapses()
            || !whzExplosiveSightRangeDanger()
            || !whzExplosiveCloudkillBreath()
            || !whzExplosiveWarnsFirst()
            || !whzQuakeOnlyAvoidedByAir()
            || !whzQuakeMostlyHarmless()
            || !whzQuakeWildernessScope()
            || !whzQuakeFaultLines()
            || !whzQuakeShockWavesDoMoreDamage()
            || !whzQuakeTriggersQuake()
            || !whzQuakeAftershocksDays()
            || !whzLightQuakeFewSeconds()
            || !whzLightQuakeRuinsSpell()
            || !whzLightQuakeThiefJostled()
            || !whzLightQuakeTightropeHalved()
            || !whzModQuakeHasLightEffects()
            || !whzModQuakeDislodges()
            || !whzModQuakeToppleNeedsDexStr()
            || !whzModQuakeSpecPointBlankOk()
            || !whzModQuakeNonSpecRangeStacks()
            || !whzModQuakeMissSlipFall()
            || !whzModQuakeRockfallMudslide()
            || !whzModQuakeClimberAlsoAtRisk()
            || !whzModQuakeFissureOpens()
            || !whzModQuakeFissureFallingDmg()
            || !whzModQuakeFissureCrush()
            || !whzSevQuakeDoublesAll()
            || !whzSevQuakeRockfallDoubled()
            || !whzSevQuakeHitTheGround()
            || !whzTidalCreatedOnOceanFloor()
            || !whzTidalShockAbsorbed()
            || !whzTidalTravelsFar()
            || !whzTidalPrecautionWindow()
            || !whzTidalRushesInland()
            || !whzTidalInlandDiminishes()
            || !whzTidalTerrainGoverns()
            || !whzTidalCliffSpares()
            || !whzTidalLowlandFears()
            || !whzTidalPathKills()
        )
            ++bad;
        // the lava dice spans: 2d6 days fluid, 2d4 days thick, 2d3 weeks of
        // heat retention, 2d6 points of pyroclastic hit damage
    if (whzFluidLavaDaysMin() + 10 != whzFluidLavaDaysMax()
            || whzThickLavaDaysMin() + 6 != whzThickLavaDaysMax()
            || whzLavaHeatWeeksMin() + 4 != whzLavaHeatWeeksMax()
            || whzPyroclasticDmgMin() + 10 != whzPyroclasticDmgMax()
        )
            ++bad;
        // the 50-degree fluid and 30-degree thick temperature rises are exact
        // multiples of the 10-degree-per-quarter-mile taper
    if (whzFluidTempRiseDeg() != whzLavaTempTaperDeg() * 5
            || whzThickTempRiseDeg() != whzLavaTempTaperDeg() * 3
        )
            ++bad;
        // the fluid band's 1.5-mile no-heat distance is the thick band's 1
        // mile plus two more quarter-mile tapers
    if (whzFluidNoHeatQmi() != whzThickNoHeatQmi() + 2
        )
            ++bad;
        // the danger radii strictly ascend with intensity: 500 yards of lava
        // heat, 2,000 light ash, 4,000 heavy ash
    if (whzAshHeavyDangerYards() <= whzAshLightDangerYards()
            || whzAshLightDangerYards() <= whzLavaHeatRangeYards()
        )
            ++bad;
        // the light-band dice: 1d4+2 weeks, 1d10+15 downwind miles, 1d6+4
        // near miles, and the 3-8-day pyroclastic spell of band 6
    if (whzAshLightWeeksMin() + 3 != whzAshLightWeeksMax()
            || whzAshLightFarMilesMin() + 9 != whzAshLightFarMilesMax()
            || whzAshLightNearMilesMin() + 5 != whzAshLightNearMilesMax()
            || whzAshSixPyrDaysMin() + 5 != whzAshSixPyrDaysMax()
        )
            ++bad;
        // the heavy-band dice: 1d6+5 daily hours, 1d3 weeks, 1d6+9 downwind
        // miles, 1d6+2 near miles
    if (whzAshHeavyHoursMin() + 5 != whzAshHeavyHoursMax()
            || whzAshHeavyWeeksMin() + 2 != whzAshHeavyWeeksMax()
            || whzAshHeavyFarMilesMin() + 5 != whzAshHeavyFarMilesMax()
            || whzAshHeavyNearMilesMin() + 5 != whzAshHeavyNearMilesMax()
        )
            ++bad;
        // the ash accumulations strictly ascend with proximity and intensity:
        // 2 inches downwind, 6 near, 9 under a heavy band
    if (whzAshLightFarAccumInches() >= whzAshLightNearAccumInches()
            || whzAshLightNearAccumInches() >= whzAshHeavyNearAccumInches()
        )
            ++bad;
        // the cloudkill hit-die bands abut: fewer than 8+1 slain, 8+1 through
        // 10+1 saving at -4, 11 and above saving normally
    if (whzCloudkillMidMaxHd() != whzCloudkillSlaysBelowHd() + 2
        )
            ++bad;
        // the quake durations: d6+9 gives 10-15 seconds, and 1d6+3 tens gives
        // the severe 40-90 seconds
    if (whzModQuakeSecMin() + 5 != whzModQuakeSecMax()
            || whzSevQuakeSecMin() + 50 != whzSevQuakeSecMax()
        )
            ++bad;
        // the severe quake exactly doubles the moderate penalties: 50 to 100
        // percent climbing, 3 to 6 melee
    if (whzSevQuakeClimbPenaltyPct() != whzModQuakeClimbPenaltyPct() * 2
            || whzSevQuakeMeleePenalty() != whzModQuakeMeleePenalty() * 2
        )
            ++bad;
        // the non-specialist missile penalties escalate -3 -5 -7 and the
        // specialist takes a flat -2
    if (whzModQuakeNonSpecShort() + 2 != whzModQuakeNonSpecMed()
            || whzModQuakeNonSpecMed() + 2 != whzModQuakeNonSpecLong()
            || whzModQuakeSpecMissilePenalty() != 2
        )
            ++bad;
        // the smallest wave is 75 by 500 feet, the 20-mph inland speed is
        // well under the 150-mph open-water minimum, and the warning window
        // is bounded by 30 seconds
    if (whzTidalMinHeightFt() * whzTidalLengthFt() != 37500
            || whzTidalInlandMph() >= whzTidalMinMph()
            || whzTidalMaxWarnSec() != 30
        )
            ++bad;
        // the pulverized peak lost height - 9,677 feet before, 8,364 after -
        // and the six incidents fit inside the 10-month period
    if (whzStHelensBeforeFt() <= whzStHelensAfterFt()
            || whzStHelensIncidents() > whzStHelensMonths()
        )
            ++bad;
        // the chapter's two triads: three volcano eruption types, three quake
        // classes
    if (whzVolcanoEruptionTypes() != 3
            || whzQuakeClasses() != 3
        )
            ++bad;
        printf("R486 WSG natural hazards pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
