    // ---- R488 WSG wilderness combat opener pin audit ----
    // The wilderness combat opener: the chapter introduction - characters
    // fight in far-from-best positions outdoors, the DSG pp. 30-34
    // summarized, nonstandard outdoor situations detailed. Climbing: no
    // dexterity armor class bonus on a severe slope or cliff face (the
    // low-dexterity penalty stays), one hand on the surface so no two weapons
    // or weapon-and-shield, rear attacks tell except from an adjacent
    // climber, a strapped shield buys one step for a buckler or small shield
    // and two for a larger; -2 on the cliff face and -1 on the severe slope
    // for attacks and dodge saves; the half-height elevation split gives
    // +2/-2 on the cliff and +1/-1 on the slope, cumulative; combat damage
    // forces a Climbing Check, +10 percent on the severe slope, and a single
    // hit of half total hit points forces one at -10 on both faces; moderate
    // slopes usually safe with optional elevation or tumble rulings and the
    // voluntary-tumble escape. Balanced: no hand needed and no need to face
    // the surface - ledges, rock or tree bridges, boats and barges, knee-deep
    // water mud or loose soil and snow, and slippery ground; a melee miss
    // forces a Dexterity Check to stay up, -4 knee-deep in mud, -2 on a wide
    // ledge, nothing on a slippery surface; unconsciousness or a hit of 10
    // percent of total hit points at height forces a Dexterity Check, -2 per
    // foot from the edge and none needed 10 feet back, the nine-foot -18 with
    // 19 and 20 failing anyway and the far-faller staggering first; the
    // lowland counterpart knocks down and the sleep-spelled knee-deep victim
    // and the face-down loose-soil victim both face Constitution Checks; the
    // knockdown check regains feet in five segments or a full round, +4 on a
    // slippery surface. Water: no dexterity bonus knee-deep, -1 to the waist,
    // -2 to the chest, -4 over, damage never below 1, the attacker shares the
    // penalty, aquatic natives exempt and the swimming-proficient halve the
    // deep penalties. Poor visibility: -1 moonlight, -3 natural darkness, -4
    // total darkness on attacks and dodge saves, vision bonuses cut by a
    // quarter and a half and negated; the total-darkness wild swing at 0 or
    // less modified hits an unintended target within twice weapon length - 50
    // percent in natural darkness - objects saving versus crushing blow; the
    // climbing cut 5 and 10 percent and the precarious modifier +1 and +2,
    // moonlight-level light and infravision and ultravision exempt. Weather
    // cumulative with all else. Melee from a mount: +1 same size, nothing
    // larger, -1 smaller, the footman -1 with the exact-number hit striking
    // the mount; the airborne +1 over ground and +2 at the swoop,
    // both-airborne skipping elevation, the braced 3-foot weapon +4 at the
    // cost of the dexterity bonus with the pull-up standoff, and hovering
    // needed for multiple attacks given the poor maneuverability. Missile
    // from a mount: riding proficiency and both hands, no longbow or heavy
    // crossbow, one rate-of-fire step down the 6/1-to-1/1 scale never below
    // 1/1 - the javelin 5/2 to 2/1 - with -1, -3 and -5 by mount speed, the
    // 45-degree and complex-maneuver bars, the DMG p. 53 short-as- medium and
    // medium-as-long unless hovering. Dismount: the land mount death drops
    // the rider - the proficient check lands him on his feet or the 1d3
    // tumble and a two-round recovery; the flying mount below half hit points
    // checked every round; the natural 20 with a 3-foot weapon unseats unless
    // the proficiency check holds, the ground 5-to-9-foot weapon at 20 and
    // the 10-foot at 16-20, the pull-down grapple at -4 unmounted with both
    // falling 1d6 on the failed check, the cling needing to-hits each round
    // and the rider attacking the grappler at -2 (the flying-mount-death tail
    // rides to R489).
    {
        using namespace rules;
        int bad = 0;
    if (wfcDsgRefStartPage() != 30
            || wfcDsgRefEndPage() != 34
            || wfcShieldBackSmallSteps() != 1
            || wfcShieldBackLargeSteps() != 2
            || wfcCliffAtkPenalty() != 2
            || wfcCliffSavePenalty() != 2
            || wfcSevereSlopeAtkPenalty() != 1
            || wfcElevHighBonusCliff() != 2
            || wfcElevLowPenaltyCliff() != 2
            || wfcElevHighBonusSevere() != 1
            || wfcElevLowPenaltySevere() != 1
            || wfcDamageCheckSevereBonus() != 10
            || wfcBigDamageCheckPenalty() != 10
            || wfcDexModMud() != 4
            || wfcDexModWideLedge() != 2
            || wfcBigHitHpPct() != 10
            || wfcEdgePerFootMod() != 2
            || wfcNotPrecariousFt() != 10
            || wfcNineFtEdgeMod() != 18
            || wfcAutoFailRollLow() != 19
            || wfcAutoFailRollHigh() != 20
            || wfcLooseSoilDexMod() != 2
            || wfcRegainFeetSegments() != 5
            || wfcSlipperyDexMod() != 4
            || wfcWaterKneePenalty() != 1
            || wfcWaterChestPenalty() != 2
            || wfcWaterOverChestPenalty() != 4
            || wfcWaterDmgMin() != 1
            || wfcMoonlightPenalty() != 1
            || wfcNaturalDarkPenalty() != 3
            || wfcTotalDarkPenalty() != 4
            || wfcMoonlightBonusCutNum() != 4
            || wfcNaturalDarkBonusCutNum() != 2
            || wfcWildSwingRadiusMult() != 2
            || wfcNaturalDarkWildPct() != 50
            || wfcDarkClimbCut() != 5
            || wfcDarkPrecariousDexMod() != 1
            || wfcTotalDarkClimbCut() != 10
            || wfcTotalDarkPrecariousDexMod() != 2
            || wfcMountSameSizeBonus() != 1
            || wfcMountSmallerPenalty() != 1
            || wfcFootVsMountedPenalty() != 1
            || wfcAirborneVsGroundBonus() != 1
            || wfcSwoopChargeBonus() != 2
            || wfcBraceWeaponMinFt() != 3
            || wfcBraceBonus() != 4
            || wfcRofBestPerRound() != 6
            || wfcRofFloorNum() != 1
            || wfcRofFloorDen() != 1
            || wfcJavelinNormalNum() != 5
            || wfcJavelinNormalDen() != 2
            || wfcJavelinMountedNum() != 2
            || wfcJavelinMountedDen() != 1
            || wfcMountSlowPenalty() != 1
            || wfcMountMidPenalty() != 3
            || wfcMountFastPenalty() != 5
            || wfcTurnLimitDeg() != 45
            || wfcDmgMountRefPage() != 53
            || wfcTumbleDmgDie() != 3
            || wfcUnseatNaturalDie() != 20
            || wfcUnseatWeaponMinFt() != 3
            || wfcGroundUnseatShortMinFt() != 5
            || wfcGroundUnseatShortMaxFt() != 9
            || wfcGroundUnseatLongMinFt() != 10
            || wfcGroundUnseatLongMinDie() != 16
            || wfcGroundUnseatLongMaxDie() != 20
            || wfcGrappleUnmountedPenalty() != 4
            || wfcGrappleFallDmgDie() != 6
            || !wfcWildernessPositions()
            || !wfcOutdoorNonstandardDetail()
            || !wfcClimberNoDexBonus()
            || !wfcClimberLowDexPenaltyStays()
            || !wfcOneHandToClimb()
            || !wfcRearAttackVulnerable()
            || !wfcElevNeedsHalfHeight()
            || !wfcElevAdjustmentsCumulative()
            || !wfcDamageClimbingCheck()
            || !wfcBigDamageHalfHpCheck()
            || !wfcModerateSlopeNoDisadvantage()
            || !wfcModerateElevOption()
            || !wfcModerateDamageTumbleOption()
            || !wfcVoluntaryTumbleEscape()
            || !wfcBalancedDefinition()
            || !wfcBalancedExamples()
            || !wfcMissDexCheck()
            || !wfcSlipperyNoDexMod()
            || !wfcBigHitDexCheck()
            || !wfcStaggerBeforeFall()
            || !wfcLowPrecariousKnockdown()
            || !wfcWaterSleepSuffocation()
            || !wfcLooseSoilFaceDownCheck()
            || !wfcKnockdownDexCheck()
            || !wfcKnockdownFullRoundFail()
            || !wfcRegainHalfRoundAction()
            || !wfcWaterKneeNoDexBonus()
            || !wfcAttackerSamePenalty()
            || !wfcAquaticNativeExempt()
            || !wfcSwimProficiencyRelief()
            || !wfcTotalDarkBonusNegated()
            || !wfcBonusCutExamples()
            || !wfcTotalDarkWildSwing()
            || !wfcWildSwingRandomTarget()
            || !wfcWildSwingObjectSave()
            || !wfcNaturalDarkWildElseMiss()
            || !wfcMoonlightIlluminationExempt()
            || !wfcSpecialVisionExempt()
            || !wfcIlluminationRangeExempt()
            || !wfcWeatherCumulative()
            || !wfcMountLargerNoBonus()
            || !wfcExactHitStrikesMount()
            || !wfcChooseStrikeMount()
            || !wfcFlyingMountLowEngagement()
            || !wfcAirborneNoElevationAdjustment()
            || !wfcBracedDefense()
            || !wfcBraceForfeitsDexBonus()
            || !wfcPullUpBreaksOff()
            || !wfcHoverNeededForMulti()
            || !wfcVeerPreventsFollowups()
            || !wfcFlyingMountPoorManeuver()
            || !wfcMissileNeedsRidingProf()
            || !wfcMissileNeedsBothHands()
            || !wfcMissileLongbowExcluded()
            || !wfcMissileHeavyCrossbowExcluded()
            || !wfcRofOneStepReduction()
            || !wfcSpeedPenaltiesCumulative()
            || !wfcComplexManeuversBlock()
            || !wfcTerrainMayBlock()
            || !wfcFlyingShortAsMedium()
            || !wfcFlyingMediumAsLong()
            || !wfcHoverNoExtraToHit()
            || !wfcDismountBothDirections()
            || !wfcLandMountDeathFall()
            || !wfcRidingCheckLandsOnFeet()
            || !wfcTumbleRecoveryTwoRounds()
            || !wfcFlyingMountHalfHpChecks()
            || !wfcClericCanKeepMountFlying()
            || !wfcFlyingMountDeathPlummet()
            || !wfcLeapFromMount()
            || !wfcUnseatProfCheckRetains()
            || !wfcPullDownGrapple()
            || !wfcGrappleVictimProfCheck()
            || !wfcGrappleFailAttackerFalls()
            || !wfcClingToHitEachRound()
            || !wfcRiderCheckOrBothFall()
            || !wfcRiderMayAttackGrappler()
        )
            ++bad;
        // the climbing penalties: the cliff face costs -2 while the severe
        // slope costs -1, with the elevation adjustments +2/-2 on the cliff
        // and +1/-1 on the slope
    if (wfcCliffAtkPenalty() != wfcCliffSavePenalty()
            || wfcSevereSlopeAtkPenalty() >= wfcCliffAtkPenalty()
            || wfcElevHighBonusCliff() != wfcElevLowPenaltyCliff()
            || wfcElevHighBonusSevere() != wfcElevLowPenaltySevere()
            || wfcElevHighBonusSevere() >= wfcElevHighBonusCliff()
        )
            ++bad;
        // the shield strapped to the back gives one step for a buckler or
        // small shield and two for a larger shield, and the moderate-slope
        // elevation option uses the severe +1/-1 pair
    if (wfcShieldBackSmallSteps() + 1 != wfcShieldBackLargeSteps()
            || wfcElevHighBonusSevere() != 1
        )
            ++bad;
        // the damage checks: the severe-slope damage check gains +10 percent
        // while the big-damage check loses 10 percent, both from the Climbing
        // Rating
    if (wfcDamageCheckSevereBonus() != wfcBigDamageCheckPenalty()
            || wfcBigDamageCheckPenalty() != 10
        )
            ++bad;
        // the balance modifiers: mud -4, wide ledge -2, the nine-foot edge
        // -18 built from -2 per foot, with 19 and 20 the auto-fail rolls
    if (wfcDexModMud() != 2 * wfcDexModWideLedge()
            || wfcNineFtEdgeMod() != 9 * wfcEdgePerFootMod()
            || wfcAutoFailRollLow() + 1 != wfcAutoFailRollHigh()
            || wfcNotPrecariousFt() != 10
        )
            ++bad;
        // the knockdown rules: five segments to regain feet on a success, the
        // loose-soil check at -2 and the slippery check at +4
    if (wfcRegainFeetSegments() != 5
            || wfcSlipperyDexMod() != 4
            || wfcLooseSoilDexMod() != 2
        )
            ++bad;
        // the water penalties ascend 1, 2 and 4 by depth with the damage
        // floor at 1 point
    if (wfcWaterKneePenalty() >= wfcWaterChestPenalty()
            || wfcWaterChestPenalty() >= wfcWaterOverChestPenalty()
            || wfcWaterDmgMin() != 1
        )
            ++bad;
        // the visibility penalties ascend 1, 3 and 4 from moonlight to total
        // darkness, with the bonus cut one-quarter in moonlight and one-half
        // in natural darkness
    if (wfcMoonlightPenalty() >= wfcNaturalDarkPenalty()
            || wfcNaturalDarkPenalty() >= wfcTotalDarkPenalty()
            || wfcNaturalDarkBonusCutNum() * 2 != wfcMoonlightBonusCutNum()
        )
            ++bad;
        // the darkness adjustments double from natural to total: the climbing
        // cut 5 to 10 percent and the precarious modifier +1 to +2, with the
        // wild-swing radius at twice weapon length and the natural-dark wild
        // swing at 50 percent
    if (wfcDarkClimbCut() * 2 != wfcTotalDarkClimbCut()
            || wfcDarkPrecariousDexMod() * 2 != wfcTotalDarkPrecariousDexMod()
            || wfcWildSwingRadiusMult() != 2
            || wfcNaturalDarkWildPct() != 50
        )
            ++bad;
        // the mount melee numbers: +1 same size, -1 smaller, -1 on foot,
        // airborne +1 and swooping +2, the brace +4 with a 3-foot weapon
    if (wfcMountSameSizeBonus() != wfcMountSmallerPenalty()
            || wfcFootVsMountedPenalty() != 1
            || wfcSwoopChargeBonus() != 2 * wfcAirborneVsGroundBonus()
            || wfcBraceBonus() != 4
            || wfcBraceWeaponMinFt() != 3
        )
            ++bad;
        // the rate-of-fire scale runs from 6/1 down to the 1/1 floor, and the
        // javelin specialist drops one step from 5/2 to 2/1
    if (wfcRofBestPerRound() != 6
            || wfcRofFloorNum() != 1
            || wfcRofFloorDen() != 1
            || wfcJavelinNormalNum() != 5
            || wfcJavelinNormalDen() != 2
            || wfcJavelinMountedNum() != 2
            || wfcJavelinMountedDen() != 1
        )
            ++bad;
        // the mount-speed missile penalties ascend 1, 3 and 5 with the
        // 45-degree turn limit
    if (wfcMountSlowPenalty() >= wfcMountMidPenalty()
            || wfcMountMidPenalty() >= wfcMountFastPenalty()
            || wfcTurnLimitDeg() != 45
        )
            ++bad;
        // the dismount numbers: the natural 20 with a 3-foot weapon, the
        // ground short range 5-9 feet and the long range 10 feet at 16-20,
        // the tumble 1d3 and the grapple falls 1d6
    if (wfcUnseatNaturalDie() != 20
            || wfcGroundUnseatShortMinFt() != 5
            || wfcGroundUnseatShortMaxFt() != 9
            || wfcGroundUnseatLongMinFt() != 10
            || wfcGroundUnseatLongMinDie() != 16
            || wfcGroundUnseatLongMaxDie() != 20
            || wfcTumbleDmgDie() != 3
            || wfcGrappleFallDmgDie() != 6
        )
            ++bad;
        // the grapple penalties: the unmounted attacker at -4 with the rider
        // attacking the grappler at -2, and the big-hit threshold at 10
        // percent of total hit points
    if (wfcGrappleUnmountedPenalty() != 4
            || wfcBigHitHpPct() != 10
        )
            ++bad;
        // the cross-references: the DSG summary pages 30-34 and the DMG
        // flying-mount page 53
    if (wfcDsgRefStartPage() != 30
            || wfcDsgRefEndPage() != 34
            || wfcDmgMountRefPage() != 53
        )
            ++bad;
        printf("R488 WSG wilderness combat opener pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
