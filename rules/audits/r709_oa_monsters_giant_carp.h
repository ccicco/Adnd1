    // ---- R709 OA monsters Giant Carp audit ----
    // OA round ninety-six (capture pp. 257-258): the Chapter 12 monster
    // roster - the giant carp, the stat block and the description riding
    // together, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djwCarpNoAppearingMin() != 1
            || djwCarpNoAppearingMax() != 4
            || djwCarpAC() != 6
            || djwCarpMove() != 18
            || djwCarpHDMin() != 8
            || djwCarpHDMax() != 12
            || djwCarpAttacks() != 1
            || djwCarpDmgMin() != 2
            || djwCarpDmgMax() != 20
            || djwCarpSwallowDmgThreshold() != 12
            || djwCarpSizeMinFt() != 20
            || djwCarpSizeMaxFt() != 30
            || djwCarpXPTableRows() != 4
            || djwCarpXP8HDBase() != 650
            || djwCarpXP8HDPerHP() != 10
            || djwCarpXP9HDBase() != 1000
            || djwCarpXP9HDPerHP() != 12
            || djwCarpXP10HDBase() != 1500
            || djwCarpXP10HDPerHP() != 14
            || djwCarpXP11HDLevel() != 7
            || djwCarpXP11HDBase() != 2150
            || djwCarpXP11HDPerHP() != 16
            || djwCarpSwallowTiers() != 5
            || djwCarpDigestDmgPerRound() != 1
            || djwCarpSuffocateChancePct() != 5
            || djwCarpFreeAtHPPct() != 50
            || djwCarpOutsideToHitPenalty() != 2
            || djwCarpThrustHitSwallowedPct() != 20
            || !djwCarpUncommon()
            || !djwCarpLairNil()
            || !djwCarpTreasureNil()
            || !djwCarpSwallowWhole()
            || !djwCarpMRStandard()
            || !djwCarpIntAnimal()
            || !djwCarpNeutral()
            || !djwCarpSizeL()
            || !djwCarpPsionicNil()
            || !djwCarpOvergrownCousin()
            || !djwCarpFreshwaterDepth()
            || !djwCarpTemperateToTropical()
            || !djwCarpScavenger()
            || !djwCarpSurfacesToAttack()
            || !djwCarpTakesBait()
            || !djwCarpRescueOutsideOrCutFree()
            || !djwCarpInsideNoPenalty()
            || !djwCarpVillageSupply()
            || !djwCarpFishingExpeditions()
        )
            ++bad;
        // the stat block - the uncommon, the 1-4, the AC 6, the move 18, the
        // 8-12, the Nil lair, the Nil treasure, the 1 attack of 2-20, the
        // swallow whole, the standard MR, the animal, the neutral, the L of
        // 20-30 feet, the Nil psionics, the four-row XP table (the 8 HD
        // VI/650 + 10, the 9 HD VI/1,000 + 12, the 10 HD VII/1,500 + 14, the
        // 11 and 12 HD VII/2,150 + 16)
    if (djwCarpNoAppearingMin() != 1
            || djwCarpNoAppearingMax() != 4
            || djwCarpAC() != 6
            || djwCarpMove() != 18
            || djwCarpHDMin() != 8
            || djwCarpHDMax() != 12
            || djwCarpAttacks() != 1
            || djwCarpDmgMin() != 2
            || djwCarpDmgMax() != 20
            || djwCarpSwallowDmgThreshold() != 12
            || djwCarpSizeMinFt() != 20
            || djwCarpSizeMaxFt() != 30
            || djwCarpXPTableRows() != 4
            || djwCarpXP8HDBase() != 650
            || djwCarpXP8HDPerHP() != 10
            || djwCarpXP9HDBase() != 1000
            || djwCarpXP9HDPerHP() != 12
            || djwCarpXP10HDBase() != 1500
            || djwCarpXP10HDPerHP() != 14
            || djwCarpXP11HDLevel() != 7
            || djwCarpXP11HDBase() != 2150
            || djwCarpXP11HDPerHP() != 16
            || djwCarpUncommon() != 1
            || djwCarpLairNil() != 1
            || djwCarpTreasureNil() != 1
            || djwCarpSwallowWhole() != 1
            || djwCarpMRStandard() != 1
            || djwCarpIntAnimal() != 1
            || djwCarpNeutral() != 1
            || djwCarpSizeL() != 1
            || djwCarpPsionicNil() != 1
        )
            ++bad;
        // the nature - the overgrown cousin of the food-fish, the freshwater
        // lakes and rivers of substantial depth, the temperate-to-tropical
        // range, the scavenger digging the ooze, the surfacing to attack
        // boats and swimmers, the simple-fishhook bait
    if (djwCarpOvergrownCousin() != 1
            || djwCarpFreshwaterDepth() != 1
            || djwCarpTemperateToTropical() != 1
            || djwCarpScavenger() != 1
            || djwCarpSurfacesToAttack() != 1
            || djwCarpTakesBait() != 1
        )
            ++bad;
        // the swallow rules - the 12-point swallow threshold, the five
        // swallow tiers (the dog, the large dog or colt, the small man, the
        // normal man, the small oni or ogre), the 1 hp per round digestion,
        // the 5% cumulative suffocation, the rescue from outside or cutting
        // free, the 50% hp freedom rule, the inside no-penalty, the outside
        // -2 to hit, the 20% thrust strike chance, the village supply, the
        // dangerous fishing expeditions
    if (djwCarpSwallowTiers() != 5
            || djwCarpDigestDmgPerRound() != 1
            || djwCarpSuffocateChancePct() != 5
            || djwCarpFreeAtHPPct() != 50
            || djwCarpOutsideToHitPenalty() != 2
            || djwCarpThrustHitSwallowedPct() != 20
            || djwCarpRescueOutsideOrCutFree() != 1
            || djwCarpInsideNoPenalty() != 1
            || djwCarpVillageSupply() != 1
            || djwCarpFishingExpeditions() != 1
        )
            ++bad;
        printf("R709 OA monsters Giant Carp audit: bad %d\n", bad);
        if (bad) return 1;
    }
