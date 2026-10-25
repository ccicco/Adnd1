    // ---- R547 DSG Deepearth areas 28-29 audit ----
    // The DSG Deepearth areas 28-29 pin Area 28 (the Realm of the Drow with
    // its mile-wide 1,000-ft-domed council chamber, the levitation-only
    // shaft, the built cities, the 12,000 drow and their mines) and Area 29
    // (the Dark Realms with their mud reservoir, the cloaker, illithid and
    // derro territories, the Plane of Earth cluster and the mud-whirlpool
    // vortex).
    {
        using namespace rules;
        int bad = 0;
    if (dnapDomeHtFt() != 1000
            || dnapRefugeLvl() != 4
            || dnapDrowPop() != 12000
            || dnapMouthPassages() != 12
            || dnapMudDeepFt() != 300
            || dnapEarthDenizens() != 100
            || !dnapExcavatedRealm()
            || !dnapCouncilChamber()
            || !dnapMileDiameter()
            || !dnapFlightOnlyShaft()
            || !dnapBuiltCities()
            || !dnapWaterways()
            || !dnapSculptedPassages()
            || !dnapMiniRefuges()
            || !dnapMastery()
            || !dnapRothePigs()
            || !dnapWindpipeAir()
            || !dnapCleanWater()
            || !dnapFungusFarms()
            || !dnapDrowMines()
            || !dnapCityArchitecture()
            || !dnapStoneOrnament()
            || !dnapSpiderwebCaves()
            || !dnapMudNotWater()
            || !dnapMudReservoir()
            || !dnapMudMileAcross()
            || !dnapCloakerRemnant()
            || !dnapIllithidThird()
            || !dnapDerroRedoubts()
            || !dnapDarkDomains()
            || !dnapEarthRoster()
            || !dnapStaleAir()
            || !dnapUnminedWealth()
            || !dnapMudWhirlpool()
            || !dnapEarthJourney()
        )
            ++bad;
        // the chamber and the refuges: the 1,000-ft dome, the 4th-level
        // levitation gate.
    if (dnapDomeHtFt() != 1000
            || dnapRefugeLvl() != 4
        )
            ++bad;
        // the realm: more than 12,000 drow.
    if (dnapDrowPop() != 12000
        )
            ++bad;
        // the mud chamber: 12 mouth passages, the 300-ft-deep reservoir.
    if (dnapMouthPassages() != 12
            || dnapMudDeepFt() != 300
        )
            ++bad;
        // the earth cluster: a hundred or more denizens near the vortex.
    if (dnapEarthDenizens() != 100
        )
            ++bad;
        printf("R547 DSG Deepearth areas 28-29 audit: bad %d\n", bad);
        if (bad) return 1;
    }
