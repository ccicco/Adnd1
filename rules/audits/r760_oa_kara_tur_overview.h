    // ---- R760 OA Kara-Tur overview audit ----
    // OA round one hundred forty-seven (capture pp. 301-303): the Chapter 14
    // intro and Geography prose of pp. 301-302 riding as advisory doctrine,
    // and the Population prose of pp. 302-303 - the four empires, the terrain
    // walk from the Land of Snow Demons to the southern jungles, the peoples
    // from the Shou Lung to the snake empire remnant, single-pass pins per
    // the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlvMainEmpireCount() != 4
            || dlvBasinRiverCount() != 3
            || !dlvVastContinentalArea()
            || !dlvShouLungEmpire()
            || !dlvTuLungEmpire()
            || !dlvKozakuraEmpire()
            || !dlvWaEmpire()
            || !dlvSurroundingUnits()
            || !dlvWildernessTracts()
            || !dlvEveryTerrain()
            || !dlvLandOfSnowDemons()
            || !dlvNorthernWoods()
            || !dlvKoryazMountains()
            || !dlvAmaBasin()
            || !dlvCelestialSea()
            || !dlvDesertOfHorses()
            || !dlvNortheastPeninsula()
            || !dlvChukeiPlateau()
            || !dlvThreeRiverBasin()
            || !dlvPeerlessMountains()
            || !dlvSouthernJungles()
            || !dlvPopulationConcentration()
            || !dlvShouLungPopulation()
            || !dlvTuLungPopulation()
            || !dlvAmaNomads()
            || !dlvSnowDemonTribes()
            || !dlvHorseTribesConfederation()
            || !dlvPettyKingdomsTributary()
            || !dlvPrimitiveFishermen()
            || !dlvIslandPeoples()
            || !dlvJungleTribes()
            || !dlvCoastalTributaryStates()
            || !dlvSnakeEmpireRemnant()
        )
            ++bad;
        // the chapter intro - the four empires and the setting, healthy
        // values, each condition false
    if (dlvMainEmpireCount() != 4
            || dlvVastContinentalArea() != 1
            || dlvShouLungEmpire() != 1
            || dlvTuLungEmpire() != 1
            || dlvKozakuraEmpire() != 1
            || dlvWaEmpire() != 1
            || dlvSurroundingUnits() != 1
            || dlvWildernessTracts() != 1
        )
            ++bad;
        // the geography walk - the terrain features, healthy values, each
        // condition false
    if (dlvBasinRiverCount() != 3
            || dlvLandOfSnowDemons() != 1
            || dlvKoryazMountains() != 1
            || dlvAmaBasin() != 1
            || dlvCelestialSea() != 1
            || dlvDesertOfHorses() != 1
            || dlvChukeiPlateau() != 1
            || dlvThreeRiverBasin() != 1
            || dlvPeerlessMountains() != 1
            || dlvSouthernJungles() != 1
        )
            ++bad;
        // the population walk - the peoples, healthy values, each condition
        // false
    if (dlvPopulationConcentration() != 1
            || dlvShouLungPopulation() != 1
            || dlvTuLungPopulation() != 1
            || dlvAmaNomads() != 1
            || dlvSnowDemonTribes() != 1
            || dlvHorseTribesConfederation() != 1
            || dlvPettyKingdomsTributary() != 1
            || dlvIslandPeoples() != 1
            || dlvCoastalTributaryStates() != 1
            || dlvSnakeEmpireRemnant() != 1
        )
            ++bad;
        printf("R760 OA Kara-Tur overview audit: bad %d\n", bad);
        if (bad) return 1;
    }
