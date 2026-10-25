    // ---- R714 OA monsters Gargantua audit ----
    // OA round one hundred one (capture pp. 263-265): the Chapter 12 monster
    // roster - the gargantua kaiju round, the stat block and the description
    // riding together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkbGargantuaTypeCount() != 3
            || dkbGargantuaRegenPerRound() != 4
            || dkbHumanoidNoAppMin() != 1
            || dkbHumanoidNoAppMax() != 2
            || dkbHumanoidAC() != 4
            || dkbHumanoidMove() != 21
            || dkbHumanoidHD() != 35
            || dkbHumanoidAttacks() != 2
            || dkbHumanoidFistDmgMin() != 4
            || dkbHumanoidFistDmgMax() != 40
            || dkbHumanoidTrampleDmgMin() != 10
            || dkbHumanoidTrampleDmgMax() != 100
            || dkbHumanoidSizeMinFt() != 80
            || dkbHumanoidSizeMaxFt() != 100
            || dkbHumanoidHeightMinFt() != 60
            || dkbHumanoidHeightMaxFt() != 100
            || dkbHumanoidComprehendPct() != 25
            || dkbHumanoidXPBase() != 16600
            || dkbHumanoidXPPerHP() != 35
            || dkbInsectoidNoAppMin() != 1
            || dkbInsectoidNoAppMax() != 3
            || dkbInsectoidAC() != 6
            || dkbInsectoidMoveGround() != 6
            || dkbInsectoidMoveFly() != 36
            || dkbInsectoidAttacks() != 1
            || dkbInsectoidDmgMin() != 3
            || dkbInsectoidDmgMax() != 30
            || dkbInsectoidSizeFt() != 60
            || dkbInsectoidLarvaHD() != 20
            || dkbInsectoidGrowthPerWeek() != 1
            || dkbInsectoidPupationHD() != 25
            || dkbInsectoidPupaeWeeksDice() != 2
            || dkbInsectoidPupaeWeeksSides() != 4
            || dkbInsectoidMothHD() != 30
            || dkbInsectoidSilkRangeFt() != 60
            || dkbInsectoidSilkSeverDmg() != 20
            || dkbInsectoidSilkSeverHDMonster() != 10
            || dkbInsectoidWindstormWidthFt() != 6
            || dkbInsectoidWindstormSavePenalty() != 4
            || dkbInsectoidBlowbackMinFt() != 10
            || dkbInsectoidBlowbackMaxFt() != 40
            || dkbInsectoidBlowbackDmgPerFt() != 6
            || dkbInsectoidXP20HDBase() != 11100
            || dkbInsectoidXP20HDPerHP() != 30
            || dkbInsectoidXP21HDBase() != 13600
            || dkbInsectoidXP21HDPerHP() != 35
            || dkbReptilianNoAppMin() != 1
            || dkbReptilianNoAppMax() != 2
            || dkbReptilianAC() != 2
            || dkbReptilianMoveWalk() != 18
            || dkbReptilianMoveSwim() != 12
            || dkbReptilianHD() != 50
            || dkbReptilianAttacks() != 3
            || dkbReptilianClawDmgMin() != 3
            || dkbReptilianClawDmgMax() != 30
            || dkbReptilianBiteDmgMin() != 6
            || dkbReptilianBiteDmgMax() != 60
            || dkbReptilianSizeMinFt() != 100
            || dkbReptilianSizeMaxFt() != 200
            || dkbReptilianTrampleDice() != 10
            || dkbReptilianTrampleSides() != 10
            || dkbReptilianTailSweepFt() != 90
            || dkbReptilianTailDmgDice() != 8
            || dkbReptilianTailDmgSides() != 10
            || dkbReptilianXPBase() != 22600
            || dkbReptilianXPPerHP() != 35
            || !dkbGargantuaMonstrousClass()
            || !dkbGargantuaOriginUnknown()
            || !dkbGargantuaMindlessBrutes()
            || !dkbGargantuaGroundTrembles()
            || !dkbGargantuaEasilySpotted()
            || !dkbGargantuaSquealingRoars()
            || !dkbGargantuaNationalEmergency()
            || !dkbHumanoidVeryRare()
            || !dkbHumanoidLairNil()
            || !dkbHumanoidTreasureNil()
            || !dkbHumanoidTrample()
            || !dkbHumanoidPsionicNil()
            || !dkbHumanoidLeastIntelligent()
            || !dkbHumanoidSometimesFurred()
            || !dkbHumanoidNoOwnLanguage()
            || !dkbHumanoidHumanEmpathy()
            || !dkbHumanoidMountainIslandLair()
            || !dkbInsectoidRare()
            || !dkbInsectoidLairNil()
            || !dkbInsectoidTreasureNil()
            || !dkbInsectoidSpecialDefenseRegeneration()
            || !dkbInsectoidMRStandard()
            || !dkbInsectoidIntLow()
            || !dkbInsectoidChaoticNeutral()
            || !dkbInsectoidPsionicNil()
            || !dkbInsectoidGrowthStages()
            || !dkbInsectoidSilkEntangles()
            || !dkbInsectoidSilkSeverBendBars()
            || !dkbInsectoidMothLosesSilk()
            || !dkbInsectoidWindstormByFlapping()
            || !dkbInsectoidWarmMountains()
            || !dkbReptilianRare()
            || !dkbReptilianLairNil()
            || !dkbReptilianTreasureNil()
            || !dkbReptilianPsionicNil()
            || !dkbReptilianGiganticBipedal()
            || !dkbReptilianUnableToSpeak()
            || !dkbReptilianSimpleEmpathy()
            || !dkbReptilianClawsAndBite()
            || !dkbReptilianTailSweepSaveVsDeath()
            || !dkbReptilianTropicalIslands()
            || !dkbReptilianSwims()
        )
            ++bad;
        // the shared gargantua doctrine
    if (dkbGargantuaTypeCount() != 3
            || dkbGargantuaRegenPerRound() != 4
            || dkbGargantuaMonstrousClass() != 1
            || dkbGargantuaOriginUnknown() != 1
            || dkbGargantuaMindlessBrutes() != 1
            || dkbGargantuaGroundTrembles() != 1
            || dkbGargantuaEasilySpotted() != 1
            || dkbGargantuaSquealingRoars() != 1
            || dkbGargantuaNationalEmergency() != 1
        )
            ++bad;
        // the humanoid gargantua
    if (dkbHumanoidNoAppMin() != 1
            || dkbHumanoidNoAppMax() != 2
            || dkbHumanoidAC() != 4
            || dkbHumanoidMove() != 21
            || dkbHumanoidHD() != 35
            || dkbHumanoidAttacks() != 2
            || dkbHumanoidFistDmgMin() != 4
            || dkbHumanoidFistDmgMax() != 40
            || dkbHumanoidTrampleDmgMin() != 10
            || dkbHumanoidTrampleDmgMax() != 100
            || dkbHumanoidSizeMinFt() != 80
            || dkbHumanoidSizeMaxFt() != 100
            || dkbHumanoidHeightMinFt() != 60
            || dkbHumanoidHeightMaxFt() != 100
            || dkbHumanoidComprehendPct() != 25
            || dkbHumanoidXPBase() != 16600
            || dkbHumanoidXPPerHP() != 35
            || dkbHumanoidVeryRare() != 1
            || dkbHumanoidLairNil() != 1
            || dkbHumanoidTreasureNil() != 1
            || dkbHumanoidTrample() != 1
            || dkbHumanoidPsionicNil() != 1
            || dkbHumanoidLeastIntelligent() != 1
            || dkbHumanoidSometimesFurred() != 1
            || dkbHumanoidNoOwnLanguage() != 1
            || dkbHumanoidHumanEmpathy() != 1
            || dkbHumanoidMountainIslandLair() != 1
        )
            ++bad;
        // the insectoid gargantua
    if (dkbInsectoidNoAppMin() != 1
            || dkbInsectoidNoAppMax() != 3
            || dkbInsectoidAC() != 6
            || dkbInsectoidMoveGround() != 6
            || dkbInsectoidMoveFly() != 36
            || dkbInsectoidAttacks() != 1
            || dkbInsectoidDmgMin() != 3
            || dkbInsectoidDmgMax() != 30
            || dkbInsectoidSizeFt() != 60
            || dkbInsectoidLarvaHD() != 20
            || dkbInsectoidGrowthPerWeek() != 1
            || dkbInsectoidPupationHD() != 25
            || dkbInsectoidPupaeWeeksDice() != 2
            || dkbInsectoidPupaeWeeksSides() != 4
            || dkbInsectoidMothHD() != 30
            || dkbInsectoidSilkRangeFt() != 60
            || dkbInsectoidSilkSeverDmg() != 20
            || dkbInsectoidSilkSeverHDMonster() != 10
            || dkbInsectoidWindstormWidthFt() != 6
            || dkbInsectoidWindstormSavePenalty() != 4
            || dkbInsectoidBlowbackMinFt() != 10
            || dkbInsectoidBlowbackMaxFt() != 40
            || dkbInsectoidBlowbackDmgPerFt() != 6
            || dkbInsectoidXP20HDBase() != 11100
            || dkbInsectoidXP20HDPerHP() != 30
            || dkbInsectoidXP21HDBase() != 13600
            || dkbInsectoidXP21HDPerHP() != 35
            || dkbInsectoidRare() != 1
            || dkbInsectoidLairNil() != 1
            || dkbInsectoidTreasureNil() != 1
            || dkbInsectoidSpecialDefenseRegeneration() != 1
            || dkbInsectoidMRStandard() != 1
            || dkbInsectoidIntLow() != 1
            || dkbInsectoidChaoticNeutral() != 1
            || dkbInsectoidPsionicNil() != 1
            || dkbInsectoidGrowthStages() != 1
            || dkbInsectoidSilkEntangles() != 1
            || dkbInsectoidSilkSeverBendBars() != 1
            || dkbInsectoidMothLosesSilk() != 1
            || dkbInsectoidWindstormByFlapping() != 1
            || dkbInsectoidWarmMountains() != 1
        )
            ++bad;
        // the reptilian gargantua
    if (dkbReptilianNoAppMin() != 1
            || dkbReptilianNoAppMax() != 2
            || dkbReptilianAC() != 2
            || dkbReptilianMoveWalk() != 18
            || dkbReptilianMoveSwim() != 12
            || dkbReptilianHD() != 50
            || dkbReptilianAttacks() != 3
            || dkbReptilianClawDmgMin() != 3
            || dkbReptilianClawDmgMax() != 30
            || dkbReptilianBiteDmgMin() != 6
            || dkbReptilianBiteDmgMax() != 60
            || dkbReptilianSizeMinFt() != 100
            || dkbReptilianSizeMaxFt() != 200
            || dkbReptilianTrampleDice() != 10
            || dkbReptilianTrampleSides() != 10
            || dkbReptilianTailSweepFt() != 90
            || dkbReptilianTailDmgDice() != 8
            || dkbReptilianTailDmgSides() != 10
            || dkbReptilianXPBase() != 22600
            || dkbReptilianXPPerHP() != 35
            || dkbReptilianRare() != 1
            || dkbReptilianLairNil() != 1
            || dkbReptilianTreasureNil() != 1
            || dkbReptilianPsionicNil() != 1
            || dkbReptilianGiganticBipedal() != 1
            || dkbReptilianUnableToSpeak() != 1
            || dkbReptilianSimpleEmpathy() != 1
            || dkbReptilianClawsAndBite() != 1
            || dkbReptilianTailSweepSaveVsDeath() != 1
            || dkbReptilianTropicalIslands() != 1
            || dkbReptilianSwims() != 1
        )
            ++bad;
        printf("R714 OA monsters Gargantua audit: bad %d\n", bad);
        if (bad) return 1;
    }
