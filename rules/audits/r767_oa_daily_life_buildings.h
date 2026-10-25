    // ---- R767 OA Daily Life Buildings audit ----
    // OA round one hundred fifty-four (capture pp. 308-309, with the food
    // tail of p. 308 folded in): Buildings - the fish and tea tail of Food,
    // the peasant wood house, the city packing and fire teams, the clay brick
    // and noble houses, the temple compounds, the military castles,
    // single-pass pins per the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dmcBuildingTypesCount() != 3
            || dmcTownMealsCount() != 4
            || !dmcFishMainMeatSource()
            || !dmcTeaMostCommonDrink()
            || !dmcRiceWinesHeated()
            || !dmcSteppeMilkDrinks()
            || !dmcTownMeals()
            || !dmcTravelMeals()
            || !dmcPeasantWoodHouse()
            || !dmcWindowsCoverings()
            || !dmcVerandaHearth()
            || !dmcRaisedPlatforms()
            || !dmcTileRoofStatus()
            || !dmcCityPackedHouses()
            || !dmcShopsInHomes()
            || !dmcOutbuildingsGranaries()
            || !dmcFireTeamsPrimitive()
            || !dmcClayBrickHouses()
            || !dmcNobleHouses()
            || !dmcTempleCompounds()
            || !dmcMilitaryCastles()
        )
            ++bad;
        // the meat example
    if (dmcFishMainMeatSource() != 1
            || dmcTeaMostCommonDrink() != 1
        )
            ++bad;
        // the drinks example
    if (dmcRiceWinesHeated() != 1
            || dmcSteppeMilkDrinks() != 1
        )
            ++bad;
        // the meals example
    if (dmcTownMealsCount() != 4
            || dmcTownMeals() != 1
            || dmcTravelMeals() != 1
        )
            ++bad;
        // the wood house example
    if (dmcBuildingTypesCount() != 3
            || dmcPeasantWoodHouse() != 1
            || dmcWindowsCoverings() != 1
        )
            ++bad;
        // the hearth example
    if (dmcVerandaHearth() != 1
            || dmcRaisedPlatforms() != 1
        )
            ++bad;
        // the tile example
    if (dmcTileRoofStatus() != 1
            || dmcCityPackedHouses() != 1
        )
            ++bad;
        // the street example
    if (dmcShopsInHomes() != 1
            || dmcOutbuildingsGranaries() != 1
        )
            ++bad;
        // the fire example
    if (dmcFireTeamsPrimitive() != 1
        )
            ++bad;
        // the brick example
    if (dmcClayBrickHouses() != 1
            || dmcNobleHouses() != 1
        )
            ++bad;
        // the compound example
    if (dmcTempleCompounds() != 1
            || dmcMilitaryCastles() != 1
        )
            ++bad;
        printf("R767 OA Daily Life Buildings audit: bad %d\n", bad);
        if (bad) return 1;
    }
