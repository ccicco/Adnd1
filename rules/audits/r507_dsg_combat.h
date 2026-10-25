    // ---- R507 DSG combat audit ----
    // The DSG combat rules for underground play pins the wall fighting (the
    // shield-and-Dex AC bonus loss, the flat -2 attack/damage/save penalty,
    // the +2 higher / -2 lower elevation modifiers, the damage-forced
    // Climbing Check with the -10% half-hit-points modifier, the 3-foot 2d8
    // boulder at AC 10 with the -8 cannot-hurl penalty), the bridge and ledge
    // fighting (the 5-foot drop-off rule, the hit-forced Dex Check at +2 Dex
    // per foot from the drop-off, the +2 back-to-wall / -2 back-to-drop-off
    // push modifiers), the grabbing-an-enemy system (the under-2-foot-weapon
    // bar, the 1d20 grab vs AC 10 with the weapon dropped, the Climbing/Dex
    // Check to avoid joining the fall, the -20% hanging regain and hit
    // checks, the separate-immediately fall, the 80-95/70/0 rating
    // assignments), the water fighting (the none-below-waist /
    // halved-to-chest / full-above-chest ladder, the -4 attack and -4 damage
    // at floor 1, the native and swimming-proficiency exemptions) with the
    // grappling-in-water modification (the UA pp. 106/108 references, the
    // 1/3-height depth bar, the paralysis save for a breath, the p. 12
    // holding-breath rules), the narrow-passage bottleneck (the DMG pp. 69-70
    // frontage), the darkness fighting (the flat -4 attack/save/damage with
    // +4 AC at floor 1, the forfeited sight bonuses, the
    // infravision/magic/light exemptions, the twice-weapon-length wild swing
    // at modified 0-or-less with the count-and-roll discipline, the Dex -2
    // and Climbing -10% drop-off cuts), the spellcasting in darkness (the
    // Table 9 secret roll, the -1 to -3 clue modifier), the mounted combat
    // (the trained-and-appropriate-species rules, the +1 mounted-vs-foot, the
    // exact-hit-strikes-mount, the bow fire with the halved rate of fire and
    // Table 14, the 45-degree firing-round limit, the DMG p. 53 flying
    // penalties) and the dismount tactics (the slain-mount 1d3 fall with the
    // proficiency check, the natural-20 3-foot unseat, the 5-9-foot and
    // 10-foot foot soldiers at 16-20/25%, the dive grapple at 1d6, the -2
    // rider-vs-grappler).
    {
        using namespace rules;
        int bad = 0;
    if (dnqWallAtkDmgSavePenalty() != 2
            || dnqWallHigherAtkBonus() != 2
            || dnqWallLowerAtkPenalty() != 2
            || dnqWallHalfHpCheckPenalty() != 10
            || dnqBoulderDiameterFt() != 3
            || dnqBoulderDamageDice() != 2
            || dnqBoulderDamageSides() != 8
            || dnqBoulderCannotHurlPenalty() != 8
            || dnqBridgeDropoffWithinFt() != 5
            || dnqBridgeDexPerFoot() != 2
            || dnqBridgeBackToWallDex() != 2
            || dnqBridgeBackToDropoffDex() != 2
            || dnqBridgePushMod() != 2
            || dnqGrabWeaponMaxFt() != 2
            || dnqGrabAttackDie() != 20
            || dnqGrabAcBase() != 10
            || dnqHangingRegainCheckPenalty() != 20
            || dnqClingHitCheckPenalty() != 20
            || dnqNaturalClimberRatingLo() != 80
            || dnqNaturalClimberRatingHi() != 95
            || dnqGoatLlamaRating() != 70
            || dnqClumsyRatingFloor() != 0
            || dnqWaterAttackPenalty() != 4
            || dnqWaterDamagePenalty() != 4
            || dnqWaterDamageFloor() != 1
            || dnqWaterGrappleUaPage() != 106
            || dnqWaterGrappleDepthNum() != 1
            || dnqWaterGrappleDepthDen() != 3
            || dnqWaterGrappleHoldPage() != 108
            || dnqWaterGrappleBreathRefPage() != 12
            || dnqNarrowDmgFrontagePage() != 69
            || dnqNarrowDmgFrontagePage2() != 70
            || dnqDarkAttackPenalty() != 4
            || dnqDarkSavePenalty() != 4
            || dnqDarkDamagePenalty() != 4
            || dnqDarkAcPenalty() != 4
            || dnqDarkDamageFloor() != 1
            || dnqDarkWildSwingThreshold() != 0
            || dnqDarkWildSwingRadiusMult() != 2
            || dnqDarkDexCheckPenalty() != 2
            || dnqDarkClimbingCut() != 10
            || dnqDarkSpellCourseTable() != 9
            || dnqDarkSpellClueModLo() != 1
            || dnqDarkSpellClueModHi() != 3
            || dnqMountedVsFootBonus() != 1
            || dnqMountedRofExampleFromNum() != 2
            || dnqMountedRofExampleFromDen() != 1
            || dnqMountedRofExampleToNum() != 1
            || dnqMountedRofExampleToDen() != 1
            || dnqMountedRofSecondFromNum() != 3
            || dnqMountedRofSecondToNum() != 3
            || dnqMountedRofSecondToDen() != 2
            || dnqFireRoundTurnLimitDeg() != 45
            || dnqFlyingDmgRefPage() != 53
            || dnqMountDeathFallDmgDice() != 1
            || dnqMountDeathFallDmgSides() != 3
            || dnqUnseatWeaponMinFt() != 3
            || dnqUnseatNaturalDie() != 20
            || dnqUnseatNoProfExtraDmgSides() != 3
            || dnqFootUnseatShortMinFt() != 5
            || dnqFootUnseatShortMaxFt() != 9
            || dnqFootUnseatLongMinFt() != 10
            || dnqFootUnseatLongPct() != 25
            || dnqFootUnseatLongDieLo() != 16
            || dnqFootUnseatLongDieHi() != 20
            || dnqDiveMissFallDmgSides() != 6
            || dnqDiveBothFallDmgSides() != 6
            || dnqRiderGrapplerAtkPenalty() != 2
            || dnqT14RowCount() != 3
            || !dnqOpenerUnusualTerrain()
            || !dnqOpenerSheerWallExample()
            || !dnqOpenerNarrowBridgeExample()
            || !dnqOpenerSwimmingAttacked()
            || !dnqOpenerDarknessClarification()
            || !dnqOpenerBattlesystemTail()
            || !dnqWallNoShieldDexAcBonus()
            || !dnqWallFaceToSurfaceBackExposed()
            || !dnqWallBackExposedExceptAdjacent()
            || !dnqWallOneSideOrOther()
            || !dnqWallOneHandHoldsOn()
            || !dnqWallNoMultipleWeapons()
            || !dnqWallAboveBelowModifiers()
            || !dnqWallSecurePlaceMayCancel()
            || !dnqWallArcherLedgeExample()
            || !dnqWallBoulderSwordsmanExample()
            || !dnqWallDamageClimbingCheck()
            || !dnqWallCheckFailFalls()
            || !dnqWallHalfHpTrigger()
            || !dnqWallHalfHpRoundedUp()
            || !dnqWallBoulderTactic()
            || !dnqBoulderVictimAcTen()
            || !dnqBoulderKnocksOffClimbers()
            || !dnqBridgeStandWithoutHands()
            || !dnqBridgeHitPenaltiesOnly()
            || !dnqBridgeHitForcesDexCheck()
            || !dnqBridgePushTowardAway()
            || !dnqBridgeMissilePathIndicator()
            || !dnqBridgeArrowExample()
            || !dnqBridgeLedgeExample()
            || !dnqGrabCloseQuartersOnly()
            || !dnqGrabOrGrappling()
            || !dnqGrabOneAttempt()
            || !dnqGrabNoArmorShieldBenefit()
            || !dnqGrabNoWeaponMagicBonus()
            || !dnqGrabWeaponMustDrop()
            || !dnqGrabSuccessGrabsBody()
            || !dnqGrabbedWallClimbingCheck()
            || !dnqGrabbedLedgeDexCheck()
            || !dnqGrabbedCheckFailBothFall()
            || !dnqGrabbedCheckSuccessRetains()
            || !dnqHangingCannotAttack()
            || !dnqHangingRegainSuccess()
            || !dnqHangingFailStaysClinging()
            || !dnqClingOpponentAttacksNormally()
            || !dnqClingCheckFailFalls()
            || !dnqClingOtherCauseBothFall()
            || !dnqFallingGrappledSeparate()
            || !dnqFallingSpellPossible()
            || !dnqAssignRatingToCreatures()
            || !dnqWaterBelowWaistNoPenalty()
            || !dnqWaterWaistToChestHalved()
            || !dnqWaterAboveChestOrSwimFull()
            || !dnqWaterInterferesWithFighting()
            || !dnqWaterNativeExempt()
            || !dnqWaterSwimProfExempt()
            || !dnqWaterGrapplePullUnder()
            || !dnqWaterGrappleDepthRule()
            || !dnqWaterGrappleNoWeaponPenalties()
            || !dnqWaterGrappleBothGoUnder()
            || !dnqWaterGrappleAttackerBreath()
            || !dnqWaterGrappleVictimParalysisSave()
            || !dnqWaterGrappleNoBreathIfFailed()
            || !dnqWaterGrappleUnderUntilHoldBroken()
            || !dnqNarrowBottleneckTactic()
            || !dnqNarrowOneOrTwoHolders()
            || !dnqNarrowLimitsAttackers()
            || !dnqNarrowMonstersNpcsToo()
            || !dnqNarrowDefensiveOrAggressive()
            || !dnqNarrowRoomForAllRequired()
            || !dnqDarkCannotSeeRisks()
            || !dnqDarkForfeitsSightBonuses()
            || !dnqDarkForfeitExamples()
            || !dnqDarkInfravisionExempt()
            || !dnqDarkMagicWeaponExempt()
            || !dnqDarkLightSourceExempt()
            || !dnqDarkWildSwingObjects()
            || !dnqDarkWildSwingCountRoll()
            || !dnqDarkDropoffDexCheck()
            || !dnqDarkClimbingCheckCut()
            || !dnqDarkSpellOffTargetRisk()
            || !dnqDarkSpellPlayerIndicates()
            || !dnqDarkSpellDmSecretRoll()
            || !dnqDarkSpellClueMods()
            || !dnqMountCavalryRareUnderground()
            || !dnqMountUnderdarkStables()
            || !dnqMountTrainedRequired()
            || !dnqMountSpeciesAppropriate()
            || !dnqMuleInappropriate()
            || !dnqMuleLackSpeedManeuverFearless()
            || !dnqHorseTrainableUnderground()
            || !dnqHorseReliesOnSight()
            || !dnqHorseUnusableTotalDark()
            || !dnqUnderdarkSteedList()
            || !dnqHorseIlluminationPermits()
            || !dnqHorseNightRaids()
            || !dnqMountedHeightAdvantage()
            || !dnqExactHitStrikesMount()
            || !dnqExactHitOnlyIfRiderTarget()
            || !dnqChooseMountTarget()
            || !dnqMountedBowFormidable()
            || !dnqMountedBowRideShootRide()
            || !dnqMountedBowStationaryNoPenalty()
            || !dnqMountedBowMovingNeedsHorsemanship()
            || !dnqMountedBowMovingNeedsBowProf()
            || !dnqMountedBowBothHandsKnees()
            || !dnqMountedBowTerrainBar()
            || !dnqShortbowAllowed()
            || !dnqCompositeShortbowAllowed()
            || !dnqLightCrossbowAllowed()
            || !dnqMountedRofLessThanUnmounted()
            || !dnqMountedSpeedPenaltyTable()
            || !dnqT14Cumulative()
            || !dnqFireRoundNoManeuvers()
            || !dnqSlightTurningOnly()
            || !dnqSharperTurnsRequireHold()
            || !dnqMountedRulesAllMounts()
            || !dnqFlyingAdditionalPenalties()
            || !dnqDismountEvensOdds()
            || !dnqDismountRiderStunnedProne()
            || !dnqDismountMethodsHeroicOrGrim()
            || !dnqSlayMountMostDirect()
            || !dnqSlayMountSteedLost()
            || !dnqCaptureSteedBetter()
            || !dnqMountDeathAutoFall()
            || !dnqMountDeathProfCheckLandsFeet()
            || !dnqMountDeathContinueActing()
            || !dnqMountDeathNoFurtherFunctions()
            || !dnqMountDeathNextRoundToFeet()
            || !dnqUnseatKnockChance()
            || !dnqUnseatNoProfAutoFall()
            || !dnqUnseatProfCheckRetains()
            || !dnqUnseatCheckFailFalls()
            || !dnqFootUnseatRidersSameBothWays()
            || !dnqFootUnseatLongCheckAllowed()
            || !dnqDiveByMounted()
            || !dnqDiveSuccessGrapples()
            || !dnqDiveMissAttackerFalls()
            || !dnqDiveVictimProfCheck()
            || !dnqDiveCheckSuccessStays()
            || !dnqDiveCheckFailBothFall()
            || !dnqDiveRepeatSubsequentRounds()
            || !dnqClingNeedsToHit()
            || !dnqClingRiderRechecks()
            || !dnqRiderMayAttackGrappler()
        )
            ++bad;
        // the Table 14 mounted bow fire grid
        int C14[3][2] = {
            {0,-1},
            {1,-3},
            {2,-5},
            };
        int n14[2] = {0,0};
        int e14[2] = {0,0};
        for (int b = 0;
             b < dnqT14RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnqT14Band(b);
            vals[1] = dnqT14Mod(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C14[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++n14[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (n14[c] != e14[c])
                ++bad;
        // the Table 14 slow band: less than 1/2 normal speed, -1 to hit.
    if (dnqT14Band(0) != 0
            || dnqT14Mod(0) != -1
        )
            ++bad;
        // the Table 14 mid band: 1/2 to less than 3/4 normal speed, -3 to
        // hit.
    if (dnqT14Band(1) != 1
            || dnqT14Mod(1) != -3
        )
            ++bad;
        // the Table 14 fast band: 3/4 to maximum speed, -5 to hit.
    if (dnqT14Band(2) != 2
            || dnqT14Mod(2) != -5
        )
            ++bad;
        // the Table 14 bands run contiguously 0-1-2.
    if (dnqT14Band(2) - dnqT14Band(0) != 2
        )
            ++bad;
        // the Table 14 penalty ladder steps by -2 each band: -1, -3, -5.
    if (dnqT14Mod(0) - dnqT14Mod(1) != 2
            || dnqT14Mod(1) - dnqT14Mod(2) != 2
        )
            ++bad;
        // the half-hit-points Climbing Check penalty is -10% (agrees with the
        // WSG wfcBigDamageCheckPenalty).
    if (dnqWallHalfHpCheckPenalty() != 10
        )
            ++bad;
        // the dropped boulder: three feet in diameter, 2d8 damage, -8 if it
        // cannot be hurled.
    if (dnqBoulderDiameterFt() != 3
            || dnqBoulderDamageDice() != 2
            || dnqBoulderDamageSides() != 8
            || dnqBoulderCannotHurlPenalty() != 8
        )
            ++bad;
        // the bridge rule: drop-off within 5 feet, +2 Dex per foot of
        // distance, the push modifier plus-or-minus 2.
    if (dnqBridgeDropoffWithinFt() != 5
            || dnqBridgeDexPerFoot() != 2
            || dnqBridgePushMod() != 2
        )
            ++bad;
        // the bridge per-foot bonus equals the push modifier: both 2.
    if (dnqBridgeDexPerFoot() != dnqBridgePushMod()
        )
            ++bad;
        // the back-to-wall +2 and the back-to-drop-off -2 Dex modifiers.
    if (dnqBridgeBackToWallDex() != 2
            || dnqBridgeBackToDropoffDex() != 2
        )
            ++bad;
        // the grab: under-2-foot weapon bar, the 1d20 attack, AC 10.
    if (dnqGrabWeaponMaxFt() != 2
            || dnqGrabAttackDie() != 20
            || dnqGrabAcBase() != 10
        )
            ++bad;
        // the hanging -20% regain check and the hit-while-clinging -20%
        // check.
    if (dnqHangingRegainCheckPenalty() != 20
            || dnqClingHitCheckPenalty() != 20
        )
            ++bad;
        // the two -20% grab checks are the same number.
    if (dnqHangingRegainCheckPenalty() != dnqClingHitCheckPenalty()
        )
            ++bad;
        // the assigned climbing ratings: natural climbers 80-95%, goats and
        // llamas 70%, clumsy creatures as low as 0.
    if (dnqNaturalClimberRatingLo() != 80
            || dnqNaturalClimberRatingHi() != 95
            || dnqGoatLlamaRating() != 70
            || dnqClumsyRatingFloor() != 0
        )
            ++bad;
        // the water penalties: -4 attack, -4 damage, floor 1 point.
    if (dnqWaterAttackPenalty() != 4
            || dnqWaterDamagePenalty() != 4
            || dnqWaterDamageFloor() != 1
        )
            ++bad;
        // the water attack and damage penalties are the same 4.
    if (dnqWaterAttackPenalty() != dnqWaterDamagePenalty()
        )
            ++bad;
        // the grappling-in-water references: UA pp. 106 and 108, the DSG
        // Holding Breath p. 12.
    if (dnqWaterGrappleUaPage() != 106
            || dnqWaterGrappleHoldPage() != 108
            || dnqWaterGrappleBreathRefPage() != 12
        )
            ++bad;
        // the grappling depth bar: 1/3 of the victim's height.
    if (dnqWaterGrappleDepthNum() != 1
            || dnqWaterGrappleDepthDen() != 3
        )
            ++bad;
        // the narrow-passage frontage reference: DMG pp. 69 and 70.
    if (dnqNarrowDmgFrontagePage() != 69
            || dnqNarrowDmgFrontagePage2() != 70
        )
            ++bad;
        // the darkness penalties: -4 attack, save and damage, +4 AC, floor 1
        // point.
    if (dnqDarkAttackPenalty() != 4
            || dnqDarkSavePenalty() != 4
            || dnqDarkDamagePenalty() != 4
            || dnqDarkAcPenalty() != 4
            || dnqDarkDamageFloor() != 1
        )
            ++bad;
        // all four darkness penalties are the same 4.
    if (dnqDarkAttackPenalty() != dnqDarkSavePenalty()
            || dnqDarkSavePenalty() != dnqDarkDamagePenalty()
            || dnqDarkDamagePenalty() != dnqDarkAcPenalty()
        )
            ++bad;
        // the darkness wild swing: modified 0-or-less within twice weapon
        // length; the drop-off Dex -2 and Climbing -10%.
    if (dnqDarkWildSwingThreshold() != 0
            || dnqDarkWildSwingRadiusMult() != 2
            || dnqDarkDexCheckPenalty() != 2
            || dnqDarkClimbingCut() != 10
        )
            ++bad;
        // the spell-in-darkness roll: Table 9 course changes, the clue
        // modifier -1 to -3.
    if (dnqDarkSpellCourseTable() != 9
            || dnqDarkSpellClueModLo() != 1
            || dnqDarkSpellClueModHi() != 3
        )
            ++bad;
        // the mounted-vs-foot attack bonus: +1.
    if (dnqMountedVsFootBonus() != 1
        )
            ++bad;
        // the mounted rate of fire: 2/1 fires at 1/1, 3/1 becomes 3/2.
    if (dnqMountedRofExampleFromNum() != 2
            || dnqMountedRofExampleFromDen() != 1
            || dnqMountedRofExampleToNum() != 1
            || dnqMountedRofExampleToDen() != 1
            || dnqMountedRofSecondFromNum() != 3
            || dnqMountedRofSecondToNum() != 3
            || dnqMountedRofSecondToDen() != 2
        )
            ++bad;
        // the firing-round turn limit 45 degrees; the flying-steed penalties
        // at DMG p. 53.
    if (dnqFireRoundTurnLimitDeg() != 45
            || dnqFlyingDmgRefPage() != 53
        )
            ++bad;
        // the slain-mount fall 1d3 and the unseat extra 1d3.
    if (dnqMountDeathFallDmgDice() != 1
            || dnqMountDeathFallDmgSides() != 3
            || dnqUnseatNoProfExtraDmgSides() != 3
        )
            ++bad;
        // the slain-mount fall die equals the unseat extra die: both d3.
    if (dnqMountDeathFallDmgSides() != dnqUnseatNoProfExtraDmgSides()
        )
            ++bad;
        // the unseat attempt: 3-foot-or-greater weapon, natural 20.
    if (dnqUnseatWeaponMinFt() != 3
            || dnqUnseatNaturalDie() != 20
        )
            ++bad;
        // the foot-soldier unseat weapons: 5-9 feet at the natural 20, 10
        // feet or more at 25% (16-20).
    if (dnqFootUnseatShortMinFt() != 5
            || dnqFootUnseatShortMaxFt() != 9
            || dnqFootUnseatLongMinFt() != 10
            || dnqFootUnseatLongPct() != 25
            || dnqFootUnseatLongDieLo() != 16
            || dnqFootUnseatLongDieHi() != 20
        )
            ++bad;
        // the dive grapple: 1d6 falls both ways, the rider attacks the
        // grappler at -2.
    if (dnqDiveMissFallDmgSides() != 6
            || dnqDiveBothFallDmgSides() != 6
            || dnqRiderGrapplerAtkPenalty() != 2
        )
            ++bad;
        // the dive miss-fall die equals the both-fall die: both d6.
    if (dnqDiveMissFallDmgSides() != dnqDiveBothFallDmgSides()
        )
            ++bad;
        // the wall-fight modifiers: flat -2 to attack, damage and saves; +2
        // higher / -2 lower.
    if (dnqWallAtkDmgSavePenalty() != 2
            || dnqWallHigherAtkBonus() != 2
            || dnqWallLowerAtkPenalty() != 2
        )
            ++bad;
        // the wall elevation bonus and penalty are the same 2.
    if (dnqWallHigherAtkBonus() != dnqWallLowerAtkPenalty()
        )
            ++bad;
        // the Table 14 carries three speed bands.
    if (dnqT14RowCount() != 3
        )
            ++bad;
        // the Table 14 grid cell-for-cell: bands 0-1-2, modifiers -1/-3/-5.
    if (dnqT14Band(0) != 0
            || dnqT14Mod(0) != -1
            || dnqT14Band(1) != 1
            || dnqT14Mod(1) != -3
            || dnqT14Band(2) != 2
            || dnqT14Mod(2) != -5
        )
            ++bad;
        printf("R507 DSG combat audit: bad %d\n", bad);
        if (bad) return 1;
    }
