    // ---- R717 OA monsters Goblin Spider audit ----
    // OA round one hundred four (capture pp. 267-268): the Chapter 12 monster
    // roster - the goblin spider, the stat block and the description riding
    // together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkeAppearMin() != 1
            || dkeAppearMax() != 4
            || dkeAC() != 4
            || dkeMove() != 18
            || dkeHDMin() != 6
            || dkeHDMax() != 9
            || dkeLairPct() != 80
            || dkeAttackCount() != 2
            || dkeDmgMin() != 1
            || dkeDmgMax() != 8
            || dkeWeaponPlusRequired() != 1
            || dkeMagicResistPct() != 20
            || dkeSizeMinFeet() != 8
            || dkeSizeMaxFeet() != 10
            || dkeXP6Base() != 575
            || dkeXP6PerHP() != 6
            || dkeXP7Base() != 900
            || dkeXP7PerHP() != 8
            || dkeXP8Base() != 1350
            || dkeXP8PerHP() != 10
            || dkeXP9Base() != 2200
            || dkeXP9PerHP() != 12
            || dkeSurpriseDieMax() != 4
            || dkeHeldToHitPenalty() != 4
            || dkeFreeStrengthPoints() != 20
            || dkeFreeMinCharacters() != 2
            || dkeGuardsPct() != 30
            || dkeGuardsDice() != 2
            || dkeGuardsSides() != 4
            || !dkeFrequencyRare()
            || !dkeTreasureTypeC()
            || !dkeSpecialAttackSurprise()
            || !dkeSpecialAttackGrasp()
            || !dkeIntelligenceLow()
            || !dkeAlignmentNeutralEvil()
            || !dkeSizeLarge()
            || !dkePsionicNil()
            || !dkePsionicModesNil()
            || !dkeXP6LevelVI()
            || !dkeXP7LevelVI()
            || !dkeXP8LevelVII()
            || !dkeXP9LevelVII()
            || !dkeEarthSpiderName()
            || !dkeHugeFurryEvilCast()
            || !dkeDwellFarFromHumans()
            || !dkeWoodedMountains()
            || !dkeFormerDominion()
            || !dkeViewHumansAsInvaders()
            || !dkeHarmTravelersAndSettlers()
            || !dkeNoWebs()
            || !dkeLairInTunnels()
            || !dkeTrapdoorEntrances()
            || !dkeDetectVibrationsOverhead()
            || !dkeDragIntoLair()
            || !dkeBothHitsGrasp()
            || !dkeBendBarsFrees()
            || !dkeHelpersWrenchLoose()
            || !dkeGrippingBlocksAttacks()
            || !dkeExcellentMimic()
            || !dkeUnknownTonguesRepeatOnly()
            || !dkeCleverAndDevious()
            || !dkeMimicryLuresVictims()
            || !dkeSpeaksOwnLanguage()
            || !dkeSpeaksSpiderLanguage()
            || !dkeSpeaksTradeLanguage()
            || !dkeSpeaksLocalHuman()
            || !dkeGiantSpiderGuards()
        )
            ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dkeAppearMin() != 1
            || dkeAppearMax() != 4
            || dkeAC() != 4
            || dkeMove() != 18
            || dkeHDMin() != 6
            || dkeHDMax() != 9
            || dkeLairPct() != 80
            || dkeFrequencyRare() != 1
            || dkeTreasureTypeC() != 1
            || dkeAttackCount() != 2
            || dkeDmgMin() != 1
            || dkeDmgMax() != 8
            || dkeSpecialAttackSurprise() != 1
            || dkeSpecialAttackGrasp() != 1
            || dkeWeaponPlusRequired() != 1
            || dkeMagicResistPct() != 20
            || dkeIntelligenceLow() != 1
            || dkeAlignmentNeutralEvil() != 1
            || dkeSizeLarge() != 1
            || dkeSizeMinFeet() != 8
            || dkeSizeMaxFeet() != 10
            || dkePsionicNil() != 1
            || dkePsionicModesNil() != 1
        )
            ++bad;
        // the xp ladder - the four-step xp ladder, healthy values, each
        // condition false
    if (dkeXP6Base() != 575
            || dkeXP6PerHP() != 6
            || dkeXP6LevelVI() != 1
            || dkeXP7Base() != 900
            || dkeXP7PerHP() != 8
            || dkeXP7LevelVI() != 1
            || dkeXP8Base() != 1350
            || dkeXP8PerHP() != 10
            || dkeXP8LevelVII() != 1
            || dkeXP9Base() != 2200
            || dkeXP9PerHP() != 12
            || dkeXP9LevelVII() != 1
        )
            ++bad;
        // the earth spider - the name and the grudge, healthy values, each
        // condition false
    if (dkeEarthSpiderName() != 1
            || dkeHugeFurryEvilCast() != 1
            || dkeDwellFarFromHumans() != 1
            || dkeWoodedMountains() != 1
            || dkeFormerDominion() != 1
            || dkeViewHumansAsInvaders() != 1
            || dkeHarmTravelersAndSettlers() != 1
        )
            ++bad;
        // the trapdoor ambush - the tunnel lair and the spring, healthy
        // values, each condition false
    if (dkeNoWebs() != 1
            || dkeLairInTunnels() != 1
            || dkeTrapdoorEntrances() != 1
            || dkeDetectVibrationsOverhead() != 1
            || dkeSurpriseDieMax() != 4
            || dkeDragIntoLair() != 1
        )
            ++bad;
        // the grasp - the hold and the rescue, healthy values, each condition
        // false
    if (dkeBothHitsGrasp() != 1
            || dkeHeldToHitPenalty() != 4
            || dkeBendBarsFrees() != 1
            || dkeHelpersWrenchLoose() != 1
            || dkeFreeStrengthPoints() != 20
            || dkeFreeMinCharacters() != 2
            || dkeGrippingBlocksAttacks() != 1
        )
            ++bad;
        // the mimicry and the tongues - the mimic and the four tongues,
        // healthy values, each condition false
    if (dkeExcellentMimic() != 1
            || dkeUnknownTonguesRepeatOnly() != 1
            || dkeCleverAndDevious() != 1
            || dkeMimicryLuresVictims() != 1
            || dkeSpeaksOwnLanguage() != 1
            || dkeSpeaksSpiderLanguage() != 1
            || dkeSpeaksTradeLanguage() != 1
            || dkeSpeaksLocalHuman() != 1
        )
            ++bad;
        // the giant spider guards - the lair retinue, healthy values, each
        // condition false
    if (dkeGuardsPct() != 30
            || dkeGuardsDice() != 2
            || dkeGuardsSides() != 4
            || dkeGiantSpiderGuards() != 1
        )
            ++bad;
        printf("R717 OA monsters Goblin Spider audit: bad %d\n", bad);
        if (bad) return 1;
    }
