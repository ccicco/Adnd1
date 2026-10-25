    // ---- R491 WSG magic in the wilderness pin audit ----
    // The magic in the wilderness chapter, CLOSING it. The opener: the
    // starting-point rule, the exclusion points and the alphabetical
    // arrangement. The spells: affect normal fires quick campfire; air walk
    // safe perch; airy water swimming rate; alarm out of the sentry sight;
    // animal summoning animal lore advance knowledge; animate object and
    // rock; armor 10 degrees toward tolerable; augury edibility; barkskin
    // half abrasion; bee Climbing Check; bind 100 feet of half-inch rope;
    // bluelight twice safe speed; bug +10 percent; call lightning always hits
    // at least half damage, indistinguishable, multiple-strike suspicion,
    // natural coexistence; call woodland beings no lore boost; commune one
    // fact per level without concentration; cone of cold six constitution
    // points, one per turn for one hour; control temperature gradual warming;
    // control weather 30 to 40 degrees, the druidic two steps, the extremes
    // one-direction rule and the resumption; control winds negation, fog and
    // sandstorm, no resumption, no large scale; cough and giggle no
    // concentration break; create food and water; create water container and
    // drop; cure blindness sandstorm; cure disease not trauma; darkness half
    // safe rate; detect snares and pits moving area; dig; dispel exhaustion
    // no fatigue help; dry kindling and second application; earthquake 1
    // mile, 50 percent, 1d6 turns; fear obstacle avoidance; feign death half
    // exposure; find familiar desolate and plausible; find traps magical or
    // mechanical only; firewater one pint; flame strike 10-foot diameter;
    // forcecage 5 percent per level, 20-foot fall; fumble minus 20 percent or
    // plus 4, motionless, unaware, deliberate motion; gather needs lore;
    // haste minus 10 percent and plus 2; heal constitution restoration; heat
    // metal chill seven rounds as one hour; hold person no mid-air, grip,
    // willing; insect plague 40 degrees, one-tenth duration, three-quarters
    // area, the 9-inch 1.5-inch cleric and 8-inch 1-inch druid clouds;
    // irritation grip; item portable fire; jump 50 percent on smooth; knot
    // 1d4 minimum 1; locate animals and plants; lower water toward, ford,
    // spill; massmorph hazards, weapon only, no nourishment; mending one
    // rope; misdirection reversal; protection from normal missiles hail and
    // sandstorm, limited visibility, tornado carry, abrasion not impact, no
    // lightning, lava not radiant heat; rainbow the cleric chain and the
    // once, half, 6-inch and 6th-level reductions; resist cold and fire
    // further harm only; run the 1-turn exhaustion, mental activity,
    // endurance exception, runners exempt; shield two-thirds; sink 4 segments
    // and 4 turns; snare 100 and 50 percent; stone tell mountains; stoneskin
    // no abrasion, tumble dispels, hail one sequence; summon insects 40
    // degrees half duration; symbol every turn, hopelessness and pain;
    // transmute rock to mud; trip normal gait; water walk two man-sized,
    // terrain grades, current; weather summoning season and resumption; web
    // the anchors, the 5-per-10 thickness ladder, the 10-20-40-60 distances,
    // the 2x 4x 8x multipliers, the 60-foot maximum, abrasion not impact;
    // wraithform no fall damage, weight, no mid-air cast. The potions:
    // gaseous form 3-30 and hurricane death; invulnerability 40 and 80
    // halved; vitality seven days. The protection scrolls: cold 40 degrees
    // whichever higher; fire mirror; gas the 1-inch no-wind radius. The
    // rings: fire resistance scroll; free action encumbrance limits;
    // protection plus per die; sustenance minus 5, six turns, the 20; warmth
    // scroll. The rods and staves: lordly might 20 feet out of charges;
    // swarming insects 30 plus 5 versus 60 plus 10. The miscellaneous:
    // Kwalish surfaces; arrow of direction; cloak; cube face five; Daern
    // fortress windproof not climate-controlled; the gauntlets plus and minus
    // 10; the mantle comfort, precipitation and limits; the periapt abrasion
    // only; the rope of climbing 100 and 50; the Fharlanghn shoes 100 and 80;
    // the stone of good luck plus 5 percent and minus 1.
    {
        using namespace rules;
        int bad = 0;
    if (wmgArmorTempDeg() != 10
            || wmgBindRopeMinFt() != 100
            || wmgBluelightSpeedMult() != 2
            || wmgBugClimbBonusPct() != 10
            || wmgCommuneFactsPerLevel() != 1
            || wmgConeConMax() != 6
            || wmgConeConPerTurn() != 1
            || wmgConeHour() != 1
            || wmgCtrlWeatherLoDeg() != 30
            || wmgCtrlWeatherHiDeg() != 40
            || wmgDruidicSteps() != 2
            || wmgDarknessRateDen() != 2
            || wmgQuakeFaultMiles() != 1
            || wmgQuakeChancePct() != 50
            || wmgQuakeDelayDie() != 6
            || wmgFeignExposureDen() != 2
            || wmgFirewaterPints() != 1
            || wmgFlameStrikeDiamFt() != 10
            || wmgForcecagePctPerLevel() != 5
            || wmgForcecageFallDmgFt() != 20
            || wmgFumbleClimbPct() != 20
            || wmgFumbleDexMod() != 4
            || wmgHasteClimbPct() != 10
            || wmgHasteDexMod() != 2
            || wmgChillRounds() != 7
            || wmgChillAsHour() != 1
            || wmgPlagueColdDeg() != 40
            || wmgPlagueDurationPct() != 10
            || wmgPlagueRoundsPerLevel() != 1
            || wmgPlagueAreaPct() != 75
            || wmgPlagueClericDiamIn() != 9
            || wmgPlagueClericHighHalfIn() != 3
            || wmgPlagueDruidDiamIn() != 8
            || wmgPlagueDruidHighHalfIn() != 2
            || wmgJumpSmoothPct() != 50
            || wmgKnotDie() != 4
            || wmgKnotMin() != 1
            || wmgRainbowBowPerRound() != 1
            || wmgRainbowBowNormal() != 2
            || wmgRainbowBridgePct() != 50
            || wmgRainbowElevatorIn() != 6
            || wmgRainbowElevatorNormal() != 12
            || wmgRainbowLevel() != 6
            || wmgRainbowLevelNormal() != 12
            || wmgRunExhaustTurns() != 1
            || wmgShieldAbrasionNum() != 2
            || wmgShieldAbrasionDen() != 3
            || wmgSinkSegments() != 4
            || wmgSinkTurns() != 4
            || wmgSnareNonmagicPct() != 100
            || wmgSnareMagicPct() != 50
            || wmgInsectsColdDeg() != 40
            || wmgInsectsDurDen() != 2
            || wmgSymbolEveryTurn() != 1
            || wmgWaterWalkEncumberedCount() != 2
            || wmgWebPerThickFt() != 5
            || wmgWebBand0FallFt() != 10
            || wmgWebBand1FallFt() != 20
            || wmgWebBand2FallFt() != 40
            || wmgWebMaxFallFt() != 60
            || wmgWebSevereMult() != 2
            || wmgWebModerateMult() != 4
            || wmgWebGentleMult() != 8
            || wmgWebSevereExThickFt() != 10
            || wmgWebSevereExTumbleFt() != 40
            || wmgWebModerateExThickFt() != 20
            || wmgWebModerateExTumbleFt() != 160
            || wmgGaseousGaleLo() != 3
            || wmgGaseousGaleHi() != 30
            || wmgInvulnFallFt() != 40
            || wmgInvulnTumbleFt() != 80
            || wmgVitalityDays() != 7
            || wmgScrollColdDeg() != 40
            || wmgScrollGasRadiusIn() != 1
            || wmgRingSustMod() != 5
            || wmgRingSustEveryTurns() != 6
            || wmgRingSustAutoFail() != 20
            || wmgLordlyPoleFt() != 20
            || wmgSwarmColdDeg() != 40
            || wmgSwarmBase() != 30
            || wmgSwarmPerLevel() != 5
            || wmgSwarmNormalBase() != 60
            || wmgSwarmNormalPerLevel() != 10
            || wmgCubeFaceFive() != 5
            || wmgGauntDexBonusPct() != 10
            || wmgGauntFumblePct() != 10
            || wmgFharlanghnGentlePct() != 100
            || wmgFharlanghnSeverePct() != 80
            || wmgLuckyStoneClimbPct() != 5
            || wmgLuckyStoneDie() != 1
            || !wmgMagicIntro()
            || !wmgGeneralPoints()
            || !wmgArrangement()
            || !wmgAffectFiresCampfire()
            || !wmgAirWalkAerialUse()
            || !wmgAiryWaterMoveRate()
            || !wmgAlarmOutOfSight()
            || !wmgAlarmNotCampsite()
            || !wmgAnimalSummonLore()
            || !wmgAnimateObjectRocks()
            || !wmgAnimateRockIdea()
            || !wmgAuguryEdible()
            || !wmgBarkskinHalfAbrasion()
            || !wmgBeeClimbingCheck()
            || !wmgBindTentTeardown()
            || !wmgBindReachProtrusion()
            || !wmgCallLtnAlwaysHit()
            || !wmgCallLtnHalfDmgMin()
            || !wmgCallLtnIndistinguishable()
            || !wmgCallLtnMultipleSuspect()
            || !wmgCallLtnNaturalCoexists()
            || !wmgCallWoodNoLore()
            || !wmgCommuneNoConcentration()
            || !wmgCommuneExpiresOn()
            || !wmgConeHeatstrokeUse()
            || !wmgCtrlTempRecoveryUse()
            || !wmgCtrlTempGradual()
            || !wmgCtrlTempDM()
            || !wmgCtrlWeatherExtreme()
            || !wmgCtrlWeatherResumes()
            || !wmgCtrlWindsNegates()
            || !wmgCtrlWindsAffects()
            || !wmgCtrlWindsNoResume()
            || !wmgCtrlWindsNoLargeScale()
            || !wmgCoughNoBreak()
            || !wmgCreateFoodWater()
            || !wmgCreateWaterLifesaver()
            || !wmgCreateWaterContainer()
            || !wmgCreateWaterDrop()
            || !wmgCureBlindSandstorm()
            || !wmgCureDiseaseNotTrauma()
            || !wmgDarknessBlacker()
            || !wmgDetectSnaresMoves()
            || !wmgDetectSnaresActivity()
            || !wmgDigDesertWater()
            || !wmgDispelExhaustionNoHelp()
            || !wmgDistractSeeCough()
            || !wmgDryKindling()
            || !wmgDrySecondApp()
            || !wmgQuakeMagical()
            || !wmgFearSmartFleeing()
            || !wmgFeignProtect()
            || !wmgFamiliarDesolate()
            || !wmgFamiliarPlausible()
            || !wmgFindTrapsMove()
            || !wmgFindTrapsOnlyMagMech()
            || !wmgFirewaterSpread()
            || !wmgFlameStrikeFireRisk()
            || !wmgForcecageNeedNotAnchor()
            || !wmgForcecageRescue()
            || !wmgFumbleMotionless()
            || !wmgFumbleUnaware()
            || !wmgFumbleDeliberate()
            || !wmgGatherNeedsLore()
            || !wmgGiggleSeeCough()
            || !wmgHealConRestore()
            || !wmgHoldNotMidair()
            || !wmgHoldGrip()
            || !wmgHoldWilling()
            || !wmgIrritationGrip()
            || !wmgItemPortableFire()
            || !wmgJumpAscentOnly()
            || !wmgJumpDexCheck()
            || !wmgJumpGrappling()
            || !wmgKnotDexBonus()
            || !wmgLocateAnimalsRef()
            || !wmgLocatePlantsRef()
            || !wmgLowerWaterToward()
            || !wmgLowerWaterFord()
            || !wmgLowerWaterSpill()
            || !wmgMassmorphHazards()
            || !wmgMassmorphWeaponOnly()
            || !wmgMassmorphNoNourish()
            || !wmgMendOneRope()
            || !wmgMisdirectReversal()
            || !wmgPfnmMissiles()
            || !wmgPfnmLimitedVis()
            || !wmgPfnmWindNotNegated()
            || !wmgPfnmAbrasionNotImpact()
            || !wmgPfnmNoLightning()
            || !wmgPfnmLava()
            || !wmgRainbowClericChain()
            || !wmgResistColdFurther()
            || !wmgResistFireSame()
            || !wmgRunMustRest()
            || !wmgRunMentalOk()
            || !wmgRunEnduranceException()
            || !wmgRunRunnersExempt()
            || !wmgSinkWilling()
            || !wmgStoneTellMountains()
            || !wmgStoneskinNoAbrasion()
            || !wmgStoneskinTumbleDispels()
            || !wmgStoneskinHail()
            || !wmgInsectsHalfDur()
            || !wmgSymbolHopeless()
            || !wmgSymbolPainCon()
            || !wmgTransmuteDrinkable()
            || !wmgTripNormalGait()
            || !wmgWaterWalkLandRate()
            || !wmgWaterWalkTerrain()
            || !wmgWaterWalkCurrent()
            || !wmgWeatherSummonNature()
            || !wmgWeatherSummonSeason()
            || !wmgWeatherSummonResumes()
            || !wmgWebNetAnchors()
            || !wmgWebOverMax()
            || !wmgWebAbrasionNotImpact()
            || !wmgWraithformNoFallDmg()
            || !wmgWraithformWeight()
            || !wmgWraithformNoMidairCast()
            || !wmgGaseousHurricaneDeath()
            || !wmgInvulnHalved()
            || !wmgVitalityRunAndFatigue()
            || !wmgScrollColdRule()
            || !wmgScrollFireMirror()
            || !wmgScrollGasNoWind()
            || !wmgScrollGasSandstorm()
            || !wmgScrollGasTemp()
            || !wmgRingFireResScroll()
            || !wmgRingFreeActionEncumbrance()
            || !wmgRingFreeActionLimits()
            || !wmgRingProtPlusPerDie()
            || !wmgRingSustFatigue()
            || !wmgRingWarmthScroll()
            || !wmgLordlyOutOfCharges()
            || !wmgLordlyEncumbered()
            || !wmgSwarmHalved()
            || !wmgKwalishSurfaces()
            || !wmgArrowOutdoor()
            || !wmgCloakSeeRing()
            || !wmgCubeFaceFiveImmune()
            || !wmgDaernWindproof()
            || !wmgMantleComfort()
            || !wmgMantlePrecipitation()
            || !wmgMantleLimits()
            || !wmgPeriaptAbrasionOnly()
            || !wmgRopeGrappling()
            || !wmgFharlanghnTerrain()
            || !wmgFharlanghnAlignment()
            || !wmgLuckyStoneDexChecks()
        )
            ++bad;
        // the wmgWebThickBand band-for boundaries
    if (wmgWebThickBand(4) != 0
            || wmgWebThickBand(5) != 0
            || wmgWebThickBand(10) != 1
            || wmgWebThickBand(6) != 1
            || wmgWebThickBand(20) != 2
            || wmgWebThickBand(11) != 2
            || wmgWebThickBand(21) != 3
        )
            ++bad;
        // the web thickness ladder: each 5-foot step of thickness doubles the
        // fall distance, and the 30-plus tail equals the 60-foot maximum
    if (wmgWebBand0FallFt() != 2 * wmgWebPerThickFt()
            || wmgWebBand1FallFt() != 2 * wmgWebBand0FallFt()
            || wmgWebBand2FallFt() != 2 * wmgWebBand1FallFt()
            || wmgWebMaxFallFt() != wmgWebBand2FallFt() + wmgWebBand1FallFt()
        )
            ++bad;
        // the web band chain: up to 5 feet is band 0, up to 10 is band 1, up
        // to 20 is band 2, and the 20-foot example web sits in band 2 while
        // the 10-foot one sits in band 1
    if (wmgWebThickBand(4) != 0
            || wmgWebThickBand(5) != 0
            || wmgWebThickBand(10) != 1
            || wmgWebThickBand(20) != 2
            || wmgWebThickBand(21) != 3
        )
            ++bad;
        // the web slope multipliers double from severe to moderate and from
        // moderate to gentle, and the printed examples follow the rule: 10
        // feet thick doubled for severe gives the 40-foot tumble, 20 feet
        // thick quadrupled for moderate gives the 160-foot tumble
    if (wmgWebModerateMult() != 2 * wmgWebSevereMult()
            || wmgWebGentleMult() != 2 * wmgWebModerateMult()
            || wmgWebBand1FallFt() * wmgWebSevereMult() !=
            wmgWebSevereExTumbleFt()
            || wmgWebBand2FallFt() * wmgWebModerateMult() !=
            wmgWebModerateExTumbleFt()
        )
            ++bad;
        // the cold-weather thresholds agree at 40 degrees across insect
        // plague, summon insects and the staff of swarming insects
    if (wmgPlagueColdDeg() != wmgInsectsColdDeg()
            || wmgInsectsColdDeg() != wmgSwarmColdDeg()
        )
            ++bad;
        // the insect plague area cut is three-quarters and the duration cut
        // one-tenth, and the 9-inch cleric cloud is three-quarters of a
        // 12-inch cloud while the 1.5-inch height is three-quarters of a
        // 2-inch height
    if (wmgPlagueAreaPct() * wmgPlagueDurationPct() != 750
            || 4 * wmgPlagueClericDiamIn() != 3 * 12
            || 4 * wmgPlagueClericHighHalfIn() != 3 * 4
            || wmgPlagueClericHighHalfIn() != 3 * wmgPlagueDruidHighHalfIn() -
            3
        )
            ++bad;
        // the rainbow chain halves everything: the bow fires once per round
        // instead of twice, the bridge weight is half, the elevator moves 6
        // instead of 12 inches and the draughts act at 6th instead of 12th
        // level
    if (wmgRainbowBowPerRound() * 2 != wmgRainbowBowNormal()
            || wmgRainbowBridgePct() * 2 != 100
            || wmgRainbowElevatorIn() * 2 != wmgRainbowElevatorNormal()
            || wmgRainbowLevel() * 2 != wmgRainbowLevelNormal()
        )
            ++bad;
        // the staff of swarming insects halves both the base and the
        // per-level insect counts under the cold threshold
    if (wmgSwarmBase() * 2 != wmgSwarmNormalBase()
            || wmgSwarmPerLevel() * 2 != wmgSwarmNormalPerLevel()
        )
            ++bad;
        // the reduced-rate denominators agree: magical darkness halves the
        // safe rate, feign death halves the exposure rate and summon insects
        // halves the duration
    if (wmgDarknessRateDen() != wmgFeignExposureDen()
            || wmgFeignExposureDen() != wmgInsectsDurDen()
        )
            ++bad;
        // the shield spell takes two-thirds damage: 2 over 3
    if (wmgShieldAbrasionNum() * 3 != wmgShieldAbrasionDen() * 2
        )
            ++bad;
        // the control weather recommended range is 30 to 40 degrees, strictly
        // ordered
    if (wmgCtrlWeatherLoDeg() >= wmgCtrlWeatherHiDeg()
        )
            ++bad;
        // the snare spell is 100 percent undetectable without magic and only
        // 50 percent noticeable even with magical detection
    if (wmgSnareNonmagicPct() != 2 * wmgSnareMagicPct()
        )
            ++bad;
        // the sink spell chants 4 segments and grants 4 turns of grace
    if (wmgSinkSegments() != wmgSinkTurns()
        )
            ++bad;
        // the potion of invulnerability tumble impact limit is twice the fall
        // limit
    if (wmgInvulnTumbleFt() != 2 * wmgInvulnFallFt()
        )
            ++bad;
        // the gaseous form gale damage is the 3-30 die range
    if (wmgGaseousGaleLo() != 3
            || wmgGaseousGaleHi() != 30
        )
            ++bad;
        // the fumble spell penalizes Climbing Ratings by 20 percent while the
        // haste spell penalizes by 10 and the bug cantrip and the gauntlets
        // of dexterity bonus by 10 percent, mirrored by the gauntlets of
        // fumbling penalty
    if (wmgFumbleClimbPct() != 2 * wmgHasteClimbPct()
            || wmgBugClimbBonusPct() != wmgHasteClimbPct()
            || wmgGauntDexBonusPct() != wmgGauntFumblePct()
        )
            ++bad;
        // the Fharlanghn shoes rate the gentle-or-moderate ground no worse
        // than the severe ground
    if (wmgFharlanghnGentlePct() <= wmgFharlanghnSeverePct()
        )
            ++bad;
        // the heat metal reverse: the seven rounds of chill metal duration
        // benefit equal one full hour of normal heatstroke treatment
    if (wmgChillRounds() != 7
            || wmgChillAsHour() != 1
        )
            ++bad;
        printf("R491 WSG magic in the wilderness pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
