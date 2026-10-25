    // ---- R731 OA monsters Shirokinukatsukami audit ----
    // OA round one hundred eighteen (capture pp. 283-284): the Chapter 12
    // monster roster - the shirokinukatsukami, the stat block and the Eater
    // of Dreams doctrine riding together, the xp line as consts per the R723
    // pattern, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dksAppear() != 1
            || dksAC() != -2
            || dksMove() != 18
            || dksHD() != 12
            || dksAttackCount() != 3
            || dksMRPct() != 50
            || dksPawDmgMin() != 2
            || dksPawDmgMax() != 5
            || dksTuskDmgMin() != 3
            || dksTuskDmgMax() != 18
            || dksRakeDice() != 2
            || dksRakeDie() != 4
            || dksRegenPerRound() != 2
            || dksWeaponPlus() != 3
            || dksThricePerDay() != 3
            || dksMaxInExistence() != 4
            || dksXPBase() != 1200
            || dksXPPerHP() != 16
            || !dksFrequencyVeryRare()
            || !dksLairNil()
            || !dksTreasureNil()
            || !dksSpecialsSeeBelow()
            || !dksMCA()
            || !dksIntGenius()
            || !dksAlignmentLawfulGood()
            || !dksSizeLarge()
            || !dksPsionicNil()
            || !dksModesNil()
            || !dksEaterOfDreams()
            || !dksCompositeAppearance()
            || !dksMistakenForBaku()
            || !dksFoeOfEvilSpirits()
            || !dksNoPermanentHomeland()
            || !dksAttacksWithPawsAndTusks()
            || !dksRakeOnDoublePawHit()
            || !dksRakeNeedsHitRolls()
            || !dksConstantDetectEvil()
            || !dksConstantDetectShapechanger()
            || !dksConstantDetectCharm()
            || !dksConstantDetectHarmony()
            || !dksConstantESP()
            || !dksAtWillInvisibility()
            || !dksAtWillBecomeAstral()
            || !dksAtWillDreamSight()
            || !dksAtWillDreamVision()
            || !dksAtWillProtectionFromEvil()
            || !dksAtWillTeleportNoError()
            || !dksAtWillSmokeForm()
            || !dksThriceDispelEvil()
            || !dksThriceCloudTrapeze()
            || !dksThricePacify()
            || !dksThriceExorcise()
            || !dksThriceObedience()
            || !dksDailyRestoreAndHeal()
            || !dksImmuneToAirAttacks()
            || !dksHalfOrNoFireDamage()
            || !dksImmuneToPoison()
            || !dksArrivesAtNight()
            || !dksSlipsIntoBedchamber()
            || !dksGuardsAtHeadOfBed()
            || !dksDestroysEvilSpirits()
            || !dksLeavesAtFirstLight()
            || !dksOnlyAppearsAtNight()
            || !dksSentByCelestialEmperor()
        )
            ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dksFrequencyVeryRare() != 1
            || dksAppear() != 1
            || dksAC() != -2
            || dksMove() != 18
            || dksMCA() != 1
            || dksHD() != 12
            || dksLairNil() != 1
            || dksTreasureNil() != 1
            || dksAttackCount() != 3
            || dksSpecialsSeeBelow() != 1
            || dksMRPct() != 50
            || dksIntGenius() != 1
            || dksAlignmentLawfulGood() != 1
            || dksSizeLarge() != 1
            || dksPsionicNil() != 1
            || dksModesNil() != 1
        )
            ++bad;
        // the xp line - the IX/1,200 + 16 per hp, healthy values, each
        // condition false
    if (dksXPBase() != 1200
            || dksXPPerHP() != 16
        )
            ++bad;
        // the Eater of Dreams - the composite look and the cause, healthy
        // values, each condition false
    if (dksEaterOfDreams() != 1
            || dksCompositeAppearance() != 1
            || dksMistakenForBaku() != 1
            || dksFoeOfEvilSpirits() != 1
            || dksNoPermanentHomeland() != 1
            || dksMaxInExistence() != 4
        )
            ++bad;
        // the combat - the paws, the tusks, and the rake, healthy values,
        // each condition false
    if (dksAttacksWithPawsAndTusks() != 1
            || dksPawDmgMin() != 2
            || dksPawDmgMax() != 5
            || dksTuskDmgMin() != 3
            || dksTuskDmgMax() != 18
            || dksRakeOnDoublePawHit() != 1
            || dksRakeDice() != 2
            || dksRakeDie() != 4
            || dksRakeNeedsHitRolls() != 1
        )
            ++bad;
        // the powers - the constant, at-will, thrice-daily, and daily
        // rosters, healthy values, each condition false
    if (dksConstantDetectEvil() != 1
            || dksConstantDetectShapechanger() != 1
            || dksConstantDetectCharm() != 1
            || dksConstantDetectHarmony() != 1
            || dksConstantESP() != 1
            || dksAtWillInvisibility() != 1
            || dksAtWillBecomeAstral() != 1
            || dksAtWillDreamSight() != 1
            || dksAtWillDreamVision() != 1
            || dksAtWillProtectionFromEvil() != 1
            || dksAtWillTeleportNoError() != 1
            || dksAtWillSmokeForm() != 1
            || dksThriceDispelEvil() != 1
            || dksThriceCloudTrapeze() != 1
            || dksThricePacify() != 1
            || dksThriceExorcise() != 1
            || dksThriceObedience() != 1
            || dksThricePerDay() != 3
            || dksDailyRestoreAndHeal() != 1
        )
            ++bad;
        // the immunities - the weapon floor, the regeneration, and the
        // immunities, healthy values, each condition false
    if (dksWeaponPlus() != 3
            || dksRegenPerRound() != 2
            || dksImmuneToAirAttacks() != 1
            || dksHalfOrNoFireDamage() != 1
            || dksImmuneToPoison() != 1
        )
            ++bad;
        // the bedside guardian - the night vigil, healthy values, each
        // condition false
    if (dksArrivesAtNight() != 1
            || dksSlipsIntoBedchamber() != 1
            || dksGuardsAtHeadOfBed() != 1
            || dksDestroysEvilSpirits() != 1
            || dksLeavesAtFirstLight() != 1
            || dksOnlyAppearsAtNight() != 1
            || dksSentByCelestialEmperor() != 1
        )
            ++bad;
        printf("R731 OA monsters Shirokinukatsukami audit: bad %d\n", bad);
        if (bad) return 1;
    }
