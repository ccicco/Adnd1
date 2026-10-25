    // ---- R693 OA principal methods audit ----
    // OA round eighty (capture pp. 228-232): the Principal Methods prose -
    // the eight method descriptions behind the Table 70 grid, the maneuver
    // mechanics across kick, lock, movement, push, strike, throw, vital area
    // and weapon, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djgCircleKickDmgX() != 2
            || djgFlyingKickDmgX() != 3
            || djgFlyingKickRunFt() != 5
            || djgChokeHoldEscapeMod() != 2
            || djgChokeHoldUnconRounds() != 3
            || djgLockingBlockHitBonus() != 4
            || djgIncapacLimbHours() != 24
            || djgImmobilizingEscapeMod() != 6
            || djgImmobilizingFailMod() != 4
            || djgFeintHitBonus() != 2
            || djgLeapStandUpFt() != 4
            || djgLeapStandFwdFt() != 3
            || djgLeapRunUpFt() != 8
            || djgLeapRunFwdFt() != 10
            || djgLeapPerLevelFt() != 1
            || djgLeapRunSpaceFt() != 10
            || djgSpeedMaxRounds() != 5
            || djgSpeedRestRounds() != 3
            || djgConcPushPerLevelFt() != 1
            || djgConcPushSaveFt() != 3
            || djgConcPushFailBonus() != 2
            || djgStickingTouchHitBonus() != 2
            || djgStickingTouchACBonus() != 2
            || djgOneFingerPerLevelFt() != 1
            || djgIronFistDie() != 10
            || djgCrushWoodPerLvIn() != 6
            || djgCrushStonePerLvIn() != 3
            || djgEagleClawDice() != 3
            || djgEagleClawDie() != 10
            || djgFallDamageDiv() != 2
            || djgHurlDistanceDie() != 4
            || djgGreatThrowChargeFt() != 6
            || djgGreatThrowDmgX() != 3
            || djgPainTouchMod() != 2
            || djgPainTouchRounds() != 3
            || djgStunTouchDie() != 4
            || djgParalyzeTouchDie() != 6
            || djgDistDeathDmgX() != 3
            || djgDistDeathStunSaveMod() != 2
            || djgWeaponCatchHitBonus() != 2
            || djgSteelClothMinFt() != 6
            || djgSteelClothMaxFt() != 10
            || !djgCircleKickFailNextLost()
            || !djgFlyingKickMissFall()
            || !djgBackwardNoFacing()
            || !djgBackwardMissSafe()
            || !djgChokeHoldNextRoundGrip()
            || !djgChokeHoldEscapesPerAttacks()
            || !djgLockingBlockNoDamage()
            || !djgLockingBlockFailWeaponHurt()
            || !djgIncapacDoubleDamage()
            || !djgIncapacSavePara()
            || !djgImmobilOneHand()
            || !djgFeintNoDamage()
            || !djgProneOnlyInstantStand()
            || !djgImmovabilityAutoSave()
            || !djgMissileDeflectNonmagical()
            || !djgMissileDeflectAwareOnly()
            || !djgLeapCostsOneAttack()
            || !djgSpeedDoubleAttacks()
            || !djgSpeedDoubleCombatMove()
            || !djgSpeedOncePerDay()
            || !djgSlowResistAutoImmune()
            || !djgConcPushImmovResist()
            || !djgConcPushFallDamage()
            || !djgStickingTouchNoDamage()
            || !djgOneFingerOnlyAction()
            || !djgIronFistHandsRule()
            || !djgCrushBlowOnlyAction()
            || !djgCrushBlowMissHurtsHand()
            || !djgEagleClawOnlyAction()
            || !djgFallConstant()
            || !djgInstantStandAuto()
            || !djgHurlDoubleDamage()
            || !djgHurlMissCost()
            || !djgGreatThrowMissKnock()
            || !djgVitalHumanoidOnly()
            || !djgPainTouchNoDamage()
            || !djgStunTouchSavePara()
            || !djgParalyzeTouchSavePara()
            || !djgDistDeathPainNoSave()
            || !djgWeaponCatchLock()
            || !djgWeaponCatchBreakOptions()
            || !djgWeaponCatchMissDisarm()
            || !djgWeaponBreakerMeleeOnly()
            || !djgWeaponBreakerSaveCrush()
            || !djgSteelClothSpearLike()
            || !djgSteelClothAutomatic()
        )
            ++bad;
        // the kick damage - Circle Kick double, Flying Kick triple of the
        // five-foot run
    if (djgCircleKickDmgX() != 2
            || djgFlyingKickDmgX() != 3
            || djgFlyingKickRunFt() != 5
        )
            ++bad;
        // the lock modifiers - the choke -2 escape, the +4 feet-only block,
        // the -6 immobilizing escape and its -4 miss
    if (djgChokeHoldEscapeMod() != 2
            || djgLockingBlockHitBonus() != 4
            || djgImmobilizingEscapeMod() != 6
            || djgImmobilizingFailMod() != 4
            || djgIncapacLimbHours() != 24
            || djgChokeHoldUnconRounds() != 3
        )
            ++bad;
        // the movement numbers - the feint +2, the standing leap 4 up 3
        // forward, the running leap 8 up 10 forward
    if (djgFeintHitBonus() != 2
            || djgLeapStandUpFt() != 4
            || djgLeapStandFwdFt() != 3
            || djgLeapRunUpFt() != 8
            || djgLeapRunFwdFt() != 10
            || djgLeapPerLevelFt() != 1
            || djgLeapRunSpaceFt() != 10
        )
            ++bad;
        // the speed and the push - five rounds once a day, the push a foot
        // per level with the three-foot save, the sticking +2 and 2, one
        // finger a foot per level
    if (djgSpeedMaxRounds() != 5
            || djgSpeedRestRounds() != 3
            || djgConcPushPerLevelFt() != 1
            || djgConcPushSaveFt() != 3
            || djgConcPushFailBonus() != 2
            || djgStickingTouchHitBonus() != 2
            || djgStickingTouchACBonus() != 2
            || djgOneFingerPerLevelFt() != 1
        )
            ++bad;
        // the strike - the iron fist 1d10, the six-inch wood and three-inch
        // stone per level, the eagle claw 3d10
    if (djgIronFistDie() != 10
            || djgCrushWoodPerLvIn() != 6
            || djgCrushStonePerLvIn() != 3
            || djgEagleClawDice() != 3
            || djgEagleClawDie() != 10
        )
            ++bad;
        // the throw - the fall halved, the hurl 1d4 feet, the great throw six
        // feet on a charge and triple damage
    if (djgFallDamageDiv() != 2
            || djgHurlDistanceDie() != 4
            || djgGreatThrowChargeFt() != 6
            || djgGreatThrowDmgX() != 3
        )
            ++bad;
        // the vital area - the pain -2/+2 for 1-3 rounds, the stun 1d4, the
        // paralyze 1d6, the distance death triple or the -2 stunning save
    if (djgPainTouchMod() != 2
            || djgPainTouchRounds() != 3
            || djgStunTouchDie() != 4
            || djgParalyzeTouchDie() != 6
            || djgDistDeathDmgX() != 3
            || djgDistDeathStunSaveMod() != 2
        )
            ++bad;
        // the weapon - the catch +2, the cloth 6 to 10 feet
    if (djgWeaponCatchHitBonus() != 2
            || djgSteelClothMinFt() != 6
            || djgSteelClothMaxFt() != 10
        )
            ++bad;
        printf("R693 OA principal methods audit: bad %d\n", bad);
        if (bad) return 1;
    }
