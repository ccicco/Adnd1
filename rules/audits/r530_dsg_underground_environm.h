    // ---- R530 DSG underground environment audit ----
    // The DSG underground environment pins the ecosystem justifications (the
    // castle comparison, the burrowers, the mining, the gravity), the
    // features of the game (the DM control, the essential encounter, the
    // monster tactics, the danger, the fears, the frontier), the nature of
    // the environment (the precarious balance, the evil tendency, the
    // philosophy, the resources, the food chain, the oxygen), and the brief
    // history (the five ancient cultures, the Alignment Wars, the retreat,
    // the plane doors).
    {
        using namespace rules;
        int bad = 0;
    if (dnugLimestoneMiles() != 100
            || dnugCorridorFt() != 10
            || dnugWoodFloatMiles() != 1
            || dnugAncientCultures() != 5
            || !dnugDungeonSaferThanCastle()
            || !dnugBurrowersNoArmy()
            || !dnugDepthBlocksExcavation()
            || !dnugNoGarrisonReserve()
            || !dnugDefensibilitySavedDrow()
            || !dnugMiningExcavation()
            || !dnugGravityPopulates()
            || !dnugDmControlNarrow()
            || !dnugEssentialEncounter()
            || !dnugMonsterTacticsPlanned()
            || !dnugBeginnersDecisionEase()
            || !dnugDangerAtmosphere()
            || !dnugCommonFears()
            || !dnugAliennessWonder()
            || !dnugFrontierBelowFeet()
            || !dnugFrontierMissions()
            || !dnugBackToBasics()
            || !dnugPrecariousBalance()
            || !dnugLandMorePrecious()
            || !dnugEvilTendency()
            || !dnugLowerPlaneTheory()
            || !dnugNoHumor()
            || !dnugDisciplinedIndividuals()
            || !dnugFunctionalArt()
            || !dnugWastePunished()
            || !dnugTimelessness()
            || !dnugStubbornConservative()
            || !dnugDepthShapesResources()
            || !dnugFoodSlavesRaided()
            || !dnugDepthShapesAlienness()
            || !dnugSunlessFoodChain()
            || !dnugStoneEatersInedible()
            || !dnugScavengersMinor()
            || !dnugNocturnalRaiders()
            || !dnugOxygenCirculation()
            || !dnugJermalaineTunnels()
            || !dnugMyconidCoexistence()
            || !dnugAbolethDarksea()
            || !dnugCloakersEvict()
            || !dnugIllithidDominion()
            || !dnugAlignmentWarsSides()
            || !dnugEvilHaltedAtSun()
            || !dnugDefeatAndRetreat()
            || !dnugImmigrantNiches()
            || !dnugPlaneOfEarthStrongest()
            || !dnugSvirfneblinGood()
            || !dnugSavageWarsToday()
        )
            ++bad;
        // the round load-bearing numbers: the 100-mile limestone caverns, the
        // 10-ft corridor defense, the mile-floated wood, and the five ancient
        // cultures.
    if (dnugLimestoneMiles() != 100
            || dnugCorridorFt() != 10
            || dnugWoodFloatMiles() != 1
            || dnugAncientCultures() != 5
        )
            ++bad;
        // the why-an-ecosystem justifications: the defense, the burrowers,
        // the drow and duergar survival, the mining, the gravity.
    if (dnugDungeonSaferThanCastle() != 1
            || dnugBurrowersNoArmy() != 1
            || dnugDefensibilitySavedDrow() != 1
            || dnugMiningExcavation() != 1
            || dnugGravityPopulates() != 1
        )
            ++bad;
        // the features of the underground game: the DM control, the essential
        // encounter, the plannable monster tactics, the danger atmosphere,
        // the frontier, the back-to-basics.
    if (dnugDmControlNarrow() != 1
            || dnugEssentialEncounter() != 1
            || dnugMonsterTacticsPlanned() != 1
            || dnugDangerAtmosphere() != 1
            || dnugFrontierBelowFeet() != 1
            || dnugBackToBasics() != 1
        )
            ++bad;
        // the nature of the underground: the precarious balance, the evil
        // tendency, the humorless philosophy, the functional art, the
        // punished waste, the timelessness, the sunless food chain, the
        // oxygen.
    if (dnugPrecariousBalance() != 1
            || dnugEvilTendency() != 1
            || dnugNoHumor() != 1
            || dnugFunctionalArt() != 1
            || dnugWastePunished() != 1
            || dnugTimelessness() != 1
            || dnugSunlessFoodChain() != 1
            || dnugOxygenCirculation() != 1
        )
            ++bad;
        // the brief history: the jermalaine tunnels, the aboleth Darksea, the
        // illithid dominion, the Alignment Wars, the defeat and retreat, the
        // plane doors, the savage wars of today.
    if (dnugJermalaineTunnels() != 1
            || dnugAbolethDarksea() != 1
            || dnugIllithidDominion() != 1
            || dnugAlignmentWarsSides() != 1
            || dnugDefeatAndRetreat() != 1
            || dnugPlaneOfEarthStrongest() != 1
            || dnugSavageWarsToday() != 1
        )
            ++bad;
        printf("R530 DSG underground environment audit: bad %d\n", bad);
        if (bad) return 1;
    }
