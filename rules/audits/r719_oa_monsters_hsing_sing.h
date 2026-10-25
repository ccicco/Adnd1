    // ---- R719 OA monsters Hsing-Sing audit ----
    // OA round one hundred six (capture p. 269): the Chapter 12 monster
    // roster - the hsing-sing, the stat block and the description riding
    // together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkgAppearMin() != 2
            || dkgAppearMax() != 20
            || dkgAC() != 6
            || dkgMoveWalk() != 6
            || dkgMoveClimb() != 9
            || dkgHD() != 2
            || dkgHDPlus() != 1
            || dkgLairPct() != 25
            || dkgAttackCount() != 1
            || dkgDmgMin() != 1
            || dkgDmgMax() != 6
            || dkgXPBase() != 35
            || dkgXPPerHP() != 3
            || dkgWarSeasonPerYear() != 1
            || dkgRaidMemoryYears() != 2
            || dkgPoisonCount() != 2
            || dkgPoisonOneFailedSaveDeath() != 0
            || dkgPoisonOneSaveDmgDice() != 1
            || dkgPoisonOneSaveDmgSides() != 8
            || dkgPoisonTwoParalysisTurnsDice() != 2
            || dkgPoisonTwoParalysisTurnsSides() != 6
            || dkgPoisonTwoSlowTurnsDice() != 1
            || dkgPoisonTwoSlowTurnsSides() != 6
            || dkgLairFemalePct() != 50
            || dkgFemaleHD() != 1
            || !dkgFrequencyRare()
            || !dkgTreasureTypeB()
            || !dkgDamageByWeaponType()
            || !dkgSpecialAttacksNil()
            || !dkgSpecialDefensesNil()
            || !dkgMagicResistStandard()
            || !dkgIntelligenceAverage()
            || !dkgAlignmentNeutral()
            || !dkgSizeMedium()
            || !dkgPsionicNil()
            || !dkgLevelII()
            || !dkgApeLikeHumanoids()
            || !dkgWhiteFurred()
            || !dkgFacesOfMen()
            || !dkgMountainousSubTropicalForests()
            || !dkgSpeaksOwnAndTrade()
            || !dkgPrefersLeftAlone()
            || !dkgWeaknessForStrongDrink()
            || !dkgTradesRareTreasures()
            || !dkgTakesMetalPotteryWineRice()
            || !dkgPracticesNoCrafts()
            || !dkgHarmonyWithNature()
            || !dkgNotEntirelyPeaceful()
            || !dkgWarSeason()
            || !dkgOrganizesRaidingBands()
            || !dkgImpartialPillage()
            || !dkgNeverSameSettlementTwice()
            || !dkgCarriesSpears()
            || !dkgCarriesParangs()
            || !dkgCarriesBlowguns()
            || !dkgCarriesWickerShields()
            || !dkgAdeptWithPoisons()
            || !dkgPoisonOneDeath()
            || !dkgPoisonOneSaveDamage()
            || !dkgPoisonTwoMuscleRelaxant()
            || !dkgPoisonTwoSaveSlows()
            || !dkgLairInLargeTree()
            || !dkgSleepingPlatforms()
            || !dkgFemalesFightFromBranches()
            || !dkgDespisesTasloi()
        )
            ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dkgAppearMin() != 2
            || dkgAppearMax() != 20
            || dkgAC() != 6
            || dkgMoveWalk() != 6
            || dkgMoveClimb() != 9
            || dkgHD() != 2
            || dkgHDPlus() != 1
            || dkgLairPct() != 25
            || dkgFrequencyRare() != 1
            || dkgTreasureTypeB() != 1
            || dkgAttackCount() != 1
            || dkgDmgMin() != 1
            || dkgDmgMax() != 6
            || dkgDamageByWeaponType() != 1
            || dkgSpecialAttacksNil() != 1
            || dkgSpecialDefensesNil() != 1
            || dkgMagicResistStandard() != 1
            || dkgIntelligenceAverage() != 1
            || dkgAlignmentNeutral() != 1
            || dkgSizeMedium() != 1
            || dkgPsionicNil() != 1
            || dkgLevelII() != 1
            || dkgXPBase() != 35
            || dkgXPPerHP() != 3
        )
            ++bad;
        // the ape-like race - the white-furred race, healthy values, each
        // condition false
    if (dkgApeLikeHumanoids() != 1
            || dkgWhiteFurred() != 1
            || dkgFacesOfMen() != 1
            || dkgMountainousSubTropicalForests() != 1
            || dkgSpeaksOwnAndTrade() != 1
        )
            ++bad;
        // the strong-drink trade - the trade treks, healthy values, each
        // condition false
    if (dkgPrefersLeftAlone() != 1
            || dkgWeaknessForStrongDrink() != 1
            || dkgTradesRareTreasures() != 1
            || dkgTakesMetalPotteryWineRice() != 1
            || dkgPracticesNoCrafts() != 1
            || dkgHarmonyWithNature() != 1
        )
            ++bad;
        // the war season - the annual raids, healthy values, each condition
        // false
    if (dkgNotEntirelyPeaceful() != 1
            || dkgWarSeason() != 1
            || dkgWarSeasonPerYear() != 1
            || dkgOrganizesRaidingBands() != 1
            || dkgImpartialPillage() != 1
            || dkgRaidMemoryYears() != 2
            || dkgNeverSameSettlementTwice() != 1
        )
            ++bad;
        // the war gear and the poisons - the raid kit and the two darts,
        // healthy values, each condition false
    if (dkgCarriesSpears() != 1
            || dkgCarriesParangs() != 1
            || dkgCarriesBlowguns() != 1
            || dkgCarriesWickerShields() != 1
            || dkgAdeptWithPoisons() != 1
            || dkgPoisonCount() != 2
            || dkgPoisonOneDeath() != 1
            || dkgPoisonOneFailedSaveDeath() != 0
            || dkgPoisonOneSaveDamage() != 1
            || dkgPoisonOneSaveDmgDice() != 1
            || dkgPoisonOneSaveDmgSides() != 8
            || dkgPoisonTwoMuscleRelaxant() != 1
            || dkgPoisonTwoParalysisTurnsDice() != 2
            || dkgPoisonTwoParalysisTurnsSides() != 6
            || dkgPoisonTwoSaveSlows() != 1
            || dkgPoisonTwoSlowTurnsDice() != 1
            || dkgPoisonTwoSlowTurnsSides() != 6
        )
            ++bad;
        // the tree lair - the platforms and the defenders, healthy values,
        // each condition false
    if (dkgLairInLargeTree() != 1
            || dkgSleepingPlatforms() != 1
            || dkgLairFemalePct() != 50
            || dkgFemaleHD() != 1
            || dkgFemalesFightFromBranches() != 1
            || dkgDespisesTasloi() != 1
        )
            ++bad;
        printf("R719 OA monsters Hsing-Sing audit: bad %d\n", bad);
        if (bad) return 1;
    }
