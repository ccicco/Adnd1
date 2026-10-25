    // ---- R715 OA monsters Animal Generals audit ----
    // OA round one hundred two (capture pp. 265-266): the Chapter 12 monster
    // roster - the animal generals, the stat block and the description riding
    // together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkcGeneralTypeCount() != 3
            || dkcGeneralWeaponPlusRequired() != 5
            || dkcGeneralWuJenLevel() != 29
            || dkcGeneralCloudTrapezeCreatures() != 1000
            || dkcGeneralRegenPerRound() != 5
            || dkcGeneralAtWillCount() != 5
            || dkcGeneralAlwaysOnCount() != 5
            || dkcTigerAC() != -6
            || dkcTigerMoveFly() != 36
            || dkcTigerMoveGround() != 24
            || dkcTigerHD() != 30
            || dkcTigerAttacks() != 3
            || dkcTigerClawDmgMin() != 1
            || dkcTigerClawDmgMax() != 10
            || dkcTigerBiteDmgMin() != 2
            || dkcTigerBiteDmgMax() != 20
            || dkcTigerMRPct() != 80
            || dkcTigerPanicRadiusFt() != 24
            || dkcTigerPanicHDLimit() != 3
            || dkcTigerPanicTurnsDice() != 1
            || dkcTigerPanicTurnsSides() != 4
            || dkcTigerSwordDmgDice() != 2
            || dkcTigerSwordDmgSides() != 6
            || dkcTigerSwordDmgBonus() != 12
            || dkcTigerToHitBonus() != 3
            || dkcTigerSwordToHitBonus() != 8
            || dkcTigerHostCount() != 100
            || dkcTigerXPBase() != 27400
            || dkcOxAC() != -8
            || dkcOxMoveWalk() != 18
            || dkcOxMoveCharge() != 21
            || dkcOxHD() != 36
            || dkcOxAttacks() != 2
            || dkcOxGoreDmgMin() != 2
            || dkcOxGoreDmgMax() != 12
            || dkcOxBiteDmgMin() != 2
            || dkcOxBiteDmgMax() != 20
            || dkcOxMaceDmgDice() != 1
            || dkcOxMaceDmgSides() != 10
            || dkcOxMaceDmgBonus() != 9
            || dkcOxToHitBonus() != 4
            || dkcOxMaceToHitBonus() != 9
            || dkcOxHostDice() != 10
            || dkcOxHostSides() != 4
            || dkcOxXPBase() != 24400
            || dkcOxXPPerHP() != 35
            || dkcMonkeyAC() != -4
            || dkcMonkeyMoveFly() != 48
            || dkcMonkeyMoveGround() != 36
            || dkcMonkeyHD() != 24
            || dkcMonkeyAttacks() != 2
            || dkcMonkeyDmgMin() != 2
            || dkcMonkeyDmgMax() != 12
            || dkcMonkeyNinjaLevel() != 20
            || dkcMonkeyToHitBonus() != 4
            || dkcMonkeyDmgBonus() != 5
            || dkcMonkeyHostPct() != 50
            || dkcMonkeyHostDice() != 10
            || dkcMonkeyHostSides() != 6
            || dkcMonkeyHostAC() != 7
            || dkcMonkeyXPBase() != 24800
            || dkcMonkeyXPPerHP() != 35
            || !dkcGeneralGiantHumanoidAnimals()
            || !dkcGeneralAtWillPowers()
            || !dkcGeneralAlwaysOnPowers()
            || !dkcGeneralReplacedWhenSlain()
            || !dkcGeneralFewAtATime()
            || !dkcGeneralLairNil()
            || !dkcGeneralTreasureNil()
            || !dkcGeneralIntGenius()
            || !dkcGeneralLawfulNeutral()
            || !dkcGeneralSizeL()
            || !dkcGeneralPsionicNil()
            || !dkcTigerSuppressesRebellions()
            || !dkcTigerSwordOrClaws()
            || !dkcTigerProudHotBlooded()
            || !dkcOxAidAndAssistDuty()
            || !dkcOxEarthquakeHooves()
            || !dkcOxMeteorSwarmMace()
            || !dkcOxMaceAndGoreSameRound()
            || !dkcOxSlowThinker()
            || !dkcOxLoyalGozuOniHost()
            || !dkcMonkeyCleverStealthMissions()
            || !dkcMonkeyRodOfLordlyMight()
            || !dkcMonkeyTricksAndPranks()
        )
            ++bad;
        // the shared general doctrine
    if (dkcGeneralTypeCount() != 3
            || dkcGeneralWeaponPlusRequired() != 5
            || dkcGeneralWuJenLevel() != 29
            || dkcGeneralCloudTrapezeCreatures() != 1000
            || dkcGeneralRegenPerRound() != 5
            || dkcGeneralAtWillCount() != 5
            || dkcGeneralAlwaysOnCount() != 5
            || dkcGeneralGiantHumanoidAnimals() != 1
            || dkcGeneralAtWillPowers() != 1
            || dkcGeneralAlwaysOnPowers() != 1
            || dkcGeneralReplacedWhenSlain() != 1
            || dkcGeneralFewAtATime() != 1
        )
            ++bad;
        // the shared stat block
    if (dkcGeneralLairNil() != 1
            || dkcGeneralTreasureNil() != 1
            || dkcGeneralIntGenius() != 1
            || dkcGeneralLawfulNeutral() != 1
            || dkcGeneralSizeL() != 1
            || dkcGeneralPsionicNil() != 1
        )
            ++bad;
        // the general tiger
    if (dkcTigerAC() != -6
            || dkcTigerMoveFly() != 36
            || dkcTigerMoveGround() != 24
            || dkcTigerHD() != 30
            || dkcTigerAttacks() != 3
            || dkcTigerClawDmgMin() != 1
            || dkcTigerClawDmgMax() != 10
            || dkcTigerBiteDmgMin() != 2
            || dkcTigerBiteDmgMax() != 20
            || dkcTigerMRPct() != 80
            || dkcTigerPanicRadiusFt() != 24
            || dkcTigerPanicHDLimit() != 3
            || dkcTigerPanicTurnsDice() != 1
            || dkcTigerPanicTurnsSides() != 4
            || dkcTigerSwordDmgDice() != 2
            || dkcTigerSwordDmgSides() != 6
            || dkcTigerSwordDmgBonus() != 12
            || dkcTigerToHitBonus() != 3
            || dkcTigerSwordToHitBonus() != 8
            || dkcTigerHostCount() != 100
            || dkcTigerXPBase() != 27400
            || dkcTigerSuppressesRebellions() != 1
            || dkcTigerSwordOrClaws() != 1
            || dkcTigerProudHotBlooded() != 1
        )
            ++bad;
        // the general ox
    if (dkcOxAC() != -8
            || dkcOxMoveWalk() != 18
            || dkcOxMoveCharge() != 21
            || dkcOxHD() != 36
            || dkcOxAttacks() != 2
            || dkcOxGoreDmgMin() != 2
            || dkcOxGoreDmgMax() != 12
            || dkcOxBiteDmgMin() != 2
            || dkcOxBiteDmgMax() != 20
            || dkcOxMaceDmgDice() != 1
            || dkcOxMaceDmgSides() != 10
            || dkcOxMaceDmgBonus() != 9
            || dkcOxToHitBonus() != 4
            || dkcOxMaceToHitBonus() != 9
            || dkcOxHostDice() != 10
            || dkcOxHostSides() != 4
            || dkcOxXPBase() != 24400
            || dkcOxXPPerHP() != 35
            || dkcOxAidAndAssistDuty() != 1
            || dkcOxEarthquakeHooves() != 1
            || dkcOxMeteorSwarmMace() != 1
            || dkcOxMaceAndGoreSameRound() != 1
            || dkcOxSlowThinker() != 1
            || dkcOxLoyalGozuOniHost() != 1
        )
            ++bad;
        // the general monkey
    if (dkcMonkeyAC() != -4
            || dkcMonkeyMoveFly() != 48
            || dkcMonkeyMoveGround() != 36
            || dkcMonkeyHD() != 24
            || dkcMonkeyAttacks() != 2
            || dkcMonkeyDmgMin() != 2
            || dkcMonkeyDmgMax() != 12
            || dkcMonkeyNinjaLevel() != 20
            || dkcMonkeyToHitBonus() != 4
            || dkcMonkeyDmgBonus() != 5
            || dkcMonkeyHostPct() != 50
            || dkcMonkeyHostDice() != 10
            || dkcMonkeyHostSides() != 6
            || dkcMonkeyHostAC() != 7
            || dkcMonkeyXPBase() != 24800
            || dkcMonkeyXPPerHP() != 35
            || dkcMonkeyCleverStealthMissions() != 1
            || dkcMonkeyRodOfLordlyMight() != 1
            || dkcMonkeyTricksAndPranks() != 1
        )
            ++bad;
        printf("R715 OA monsters Animal Generals audit: bad %d\n", bad);
        if (bad) return 1;
    }
