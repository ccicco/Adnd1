    // ---- R497 WSG overview audit ----
    // The overview of the wilderness, printed pp. 7-10 (pdf 8-11): the seven
    // terrain descriptions (the desert with its 10-inch definition and the
    // 70-foot dune cap, the forest with the cactus-stand exception and the
    // 160-foot temperate maximum, the hills with the 2,000/4,000-foot
    // guideline bands, the mountains with the 4,000-foot minimum and the
    // 10,000/12,000-foot Earth lines, the plains, the seacoast with the
    // encounter-table reclass and the swamp), the 1-through-7 hierarchy of
    // terrain with the highest-wins rule and its two exceptions, the bodies
    // of water and the five climate zones.
    {
        using namespace rules;
        int bad = 0;
    if (wovPrintedLo() != 7
            || wovPrintedHi() != 10
            || wovPdfLo() != 8
            || wovPdfHi() != 11
            || wovTerrainTypeCount() != 7
            || wovClimateZoneCount() != 5
            || wovHierarchyRankCount() != 7
            || wovDesertRainMaxIn() != 10
            || wovDesertTypicalRainIn() != 5
            || wovDuneTechnicalMaxFt() != 70
            || wovDuneGiantFt() != 500
            || wovTemperateTreeMaxFt() != 160
            || wovHillsLowBandFt() != 2000
            || wovHillsPeaksMayExceedFt() != 2000
            || wovHillsUpperBandLoFt() != 2000
            || wovHillsUpperBandHiFt() != 4000
            || wovMountainMinFt() != 4000
            || wovEarthTreeLineFt() != 10000
            || wovEarthSnowLineFt() != 12000
            || wovRankSeacoast() != 1
            || wovRankSwamp() != 2
            || wovRankForest() != 3
            || wovRankPlains() != 4
            || wovRankDesert() != 5
            || wovRankHills() != 6
            || wovRankMountains() != 7
            || wovHillsGuidelineCount() != 4
            || !wovPolarWastesAreDesert()
            || !wovDesertGravelCommon()
            || !wovGravelDesertWaterRunsOff()
            || !wovSandSoaksWater()
            || !wovDuneLargerIsDraa()
            || !wovDuneWindwardGradual()
            || !wovDesertBurialRisk()
            || !wovForestAnyClimateButPolar()
            || !wovCactusStandIsDesert()
            || !wovConifersSubarctic()
            || !wovDeciduousTemperate()
            || !wovRainforestTropical()
            || !wovConiferShedsSnow()
            || !wovRainforestLayered()
            || !wovRainforestGreenYearRound()
            || !wovHillsTopographyNotEcology()
            || !wovHillsDenseTreesAreForest()
            || !wovHillsRollingUnder2000NotHills()
            || !wovHillsSharpMoundsAreHills()
            || !wovHillsUpperBandIrregular()
            || !wovMountainDevoidOfTrees()
            || !wovMountainLowerSlopeTreesAreForest()
            || !wovMountainBeginsWhereTreesEnd()
            || !wovLowRockySlopeCanBeMountain()
            || !wovAboveSnowLineSnowIce()
            || !wovExposedRockWarmAir()
            || !wovPlainsFlatVegetated()
            || !wovPlainsTreesNotForest()
            || !wovPlainsFoodWaterEasy()
            || !wovPlainsShelterMaterialScarce()
            || !wovPlainsSeenFromFarAway()
            || !wovSeacoastNearOcean()
            || !wovSeacoastDrivesThreeLookups()
            || !wovSeacoastEncounterReclass()
            || !wovSwampStandingWater()
            || !wovSwampLowElevation()
            || !wovSwampFertileSoil()
            || !wovSwampDepthVariesFast()
            || !wovSwampBadForMounts()
            || !wovHierarchyHighestWins()
            || !wovBeachIsSeacoast()
            || !wovWetTreelandIsSwamp()
            || !wovOceanRockBaseIsMountains()
            || !wovMarshValleyIsHills()
            || !wovHierarchyLastResort()
            || !wovWaterSourceAndChallenge()
            || !wovBoatTravelFasterSafer()
            || !wovSwimCrossSavesTime()
            || !wovPrepareForWater()
            || !wovTemperateGreatestExtremes()
            || !wovTemperateEquidistant()
            || !wovSubarcticColderDrier()
            || !wovArcticFrigid()
            || !wovSubtropicalHotter()
            || !wovSubtropicalPrecipExtremes()
            || !wovTropicalWarmExceptHigh()
            || !wovTropicalHeavyRain()
            || !wovNoBlizzardInTropics()
        )
            ++bad;
        // the chapter spans
    if (wovPrintedLo() != 7
            || wovPrintedHi() != 10
            || wovPdfLo() != 8
            || wovPdfHi() != 11
        )
            ++bad;
        // the counts: seven terrains, five zones, seven ranks
    if (wovTerrainTypeCount() != 7
            || wovClimateZoneCount() != 5
            || wovHierarchyRankCount() != 7
        )
            ++bad;
        // the desert rainfall: half the technical maximum is typical
    if (wovDesertRainMaxIn() != 10
            || wovDesertTypicalRainIn() != 5
            || wovDesertTypicalRainIn() * 2 != wovDesertRainMaxIn()
        )
            ++bad;
        // the dune split: 70-foot technical cap, 500-foot giants
    if (wovDuneTechnicalMaxFt() != 70
            || wovDuneGiantFt() != 500
            || wovDuneGiantFt() <= wovDuneTechnicalMaxFt()
        )
            ++bad;
        // the hills bands are contiguous: the upper band starts at the low
        // band boundary
    if (wovHillsUpperBandLoFt() != wovHillsLowBandFt()
            || wovHillsUpperBandHiFt() != 4000
        )
            ++bad;
        // the mountain minimum sits at the top of the upper hills band
    if (wovMountainMinFt() != wovHillsUpperBandHiFt()
        )
            ++bad;
        // the Earth tree line is below the snow line
    if (wovEarthTreeLineFt() != 10000
            || wovEarthSnowLineFt() != 12000
            || wovEarthSnowLineFt() <= wovEarthTreeLineFt()
        )
            ++bad;
        // the hierarchy ranks run 1 through 7 with seacoast highest and
        // mountains lowest
    if (wovRankSeacoast() != 1
            || wovRankSwamp() != 2
            || wovRankForest() != 3
            || wovRankPlains() != 4
            || wovRankDesert() != 5
            || wovRankHills() != 6
            || wovRankMountains() != 7
        )
            ++bad;
        // the rank ladder sums to 28 and spans six steps
    if (wovRankSeacoast() + wovRankSwamp() + wovRankForest() + wovRankPlains()
        + wovRankDesert() + wovRankHills() + wovRankMountains() != 28
            || wovRankMountains() - wovRankSeacoast() != 6
        )
            ++bad;
        // the temperate maximum tree height
    if (wovTemperateTreeMaxFt() != 160
        )
            ++bad;
        // the four hills guidelines
    if (wovHillsGuidelineCount() != 4
        )
            ++bad;
        // wovPolarWastesAreDesert
    if (wovPolarWastesAreDesert() != 1
        )
            ++bad;
        // wovDesertGravelCommon
    if (wovDesertGravelCommon() != 1
        )
            ++bad;
        // wovGravelDesertWaterRunsOff
    if (wovGravelDesertWaterRunsOff() != 1
        )
            ++bad;
        // wovSandSoaksWater
    if (wovSandSoaksWater() != 1
        )
            ++bad;
        // wovDuneLargerIsDraa
    if (wovDuneLargerIsDraa() != 1
        )
            ++bad;
        // wovDuneWindwardGradual
    if (wovDuneWindwardGradual() != 1
        )
            ++bad;
        // wovDesertBurialRisk
    if (wovDesertBurialRisk() != 1
        )
            ++bad;
        // wovForestAnyClimateButPolar
    if (wovForestAnyClimateButPolar() != 1
        )
            ++bad;
        // wovCactusStandIsDesert
    if (wovCactusStandIsDesert() != 1
        )
            ++bad;
        // wovConifersSubarctic
    if (wovConifersSubarctic() != 1
        )
            ++bad;
        // wovDeciduousTemperate
    if (wovDeciduousTemperate() != 1
        )
            ++bad;
        // wovRainforestTropical
    if (wovRainforestTropical() != 1
        )
            ++bad;
        // wovConiferShedsSnow
    if (wovConiferShedsSnow() != 1
        )
            ++bad;
        // wovRainforestLayered
    if (wovRainforestLayered() != 1
        )
            ++bad;
        // wovRainforestGreenYearRound
    if (wovRainforestGreenYearRound() != 1
        )
            ++bad;
        // wovHillsTopographyNotEcology
    if (wovHillsTopographyNotEcology() != 1
        )
            ++bad;
        // wovHillsDenseTreesAreForest
    if (wovHillsDenseTreesAreForest() != 1
        )
            ++bad;
        // wovHillsRollingUnder2000NotHills
    if (wovHillsRollingUnder2000NotHills() != 1
        )
            ++bad;
        // wovHillsSharpMoundsAreHills
    if (wovHillsSharpMoundsAreHills() != 1
        )
            ++bad;
        // wovHillsUpperBandIrregular
    if (wovHillsUpperBandIrregular() != 1
        )
            ++bad;
        // wovMountainDevoidOfTrees
    if (wovMountainDevoidOfTrees() != 1
        )
            ++bad;
        // wovMountainLowerSlopeTreesAreForest
    if (wovMountainLowerSlopeTreesAreForest() != 1
        )
            ++bad;
        // wovMountainBeginsWhereTreesEnd
    if (wovMountainBeginsWhereTreesEnd() != 1
        )
            ++bad;
        // wovLowRockySlopeCanBeMountain
    if (wovLowRockySlopeCanBeMountain() != 1
        )
            ++bad;
        // wovAboveSnowLineSnowIce
    if (wovAboveSnowLineSnowIce() != 1
        )
            ++bad;
        // wovExposedRockWarmAir
    if (wovExposedRockWarmAir() != 1
        )
            ++bad;
        // wovPlainsFlatVegetated
    if (wovPlainsFlatVegetated() != 1
        )
            ++bad;
        // wovPlainsTreesNotForest
    if (wovPlainsTreesNotForest() != 1
        )
            ++bad;
        // wovPlainsFoodWaterEasy
    if (wovPlainsFoodWaterEasy() != 1
        )
            ++bad;
        // wovPlainsShelterMaterialScarce
    if (wovPlainsShelterMaterialScarce() != 1
        )
            ++bad;
        // wovPlainsSeenFromFarAway
    if (wovPlainsSeenFromFarAway() != 1
        )
            ++bad;
        // wovSeacoastNearOcean
    if (wovSeacoastNearOcean() != 1
        )
            ++bad;
        // wovSeacoastDrivesThreeLookups
    if (wovSeacoastDrivesThreeLookups() != 1
        )
            ++bad;
        // wovSeacoastEncounterReclass
    if (wovSeacoastEncounterReclass() != 1
        )
            ++bad;
        // wovSwampStandingWater
    if (wovSwampStandingWater() != 1
        )
            ++bad;
        // wovSwampLowElevation
    if (wovSwampLowElevation() != 1
        )
            ++bad;
        // wovSwampFertileSoil
    if (wovSwampFertileSoil() != 1
        )
            ++bad;
        // wovSwampDepthVariesFast
    if (wovSwampDepthVariesFast() != 1
        )
            ++bad;
        // wovSwampBadForMounts
    if (wovSwampBadForMounts() != 1
        )
            ++bad;
        // wovHierarchyHighestWins
    if (wovHierarchyHighestWins() != 1
        )
            ++bad;
        // wovBeachIsSeacoast
    if (wovBeachIsSeacoast() != 1
        )
            ++bad;
        // wovWetTreelandIsSwamp
    if (wovWetTreelandIsSwamp() != 1
        )
            ++bad;
        // wovOceanRockBaseIsMountains
    if (wovOceanRockBaseIsMountains() != 1
        )
            ++bad;
        // wovMarshValleyIsHills
    if (wovMarshValleyIsHills() != 1
        )
            ++bad;
        // wovHierarchyLastResort
    if (wovHierarchyLastResort() != 1
        )
            ++bad;
        // wovWaterSourceAndChallenge
    if (wovWaterSourceAndChallenge() != 1
        )
            ++bad;
        // wovBoatTravelFasterSafer
    if (wovBoatTravelFasterSafer() != 1
        )
            ++bad;
        // wovSwimCrossSavesTime
    if (wovSwimCrossSavesTime() != 1
        )
            ++bad;
        // wovPrepareForWater
    if (wovPrepareForWater() != 1
        )
            ++bad;
        // wovTemperateGreatestExtremes
    if (wovTemperateGreatestExtremes() != 1
        )
            ++bad;
        // wovTemperateEquidistant
    if (wovTemperateEquidistant() != 1
        )
            ++bad;
        // wovSubarcticColderDrier
    if (wovSubarcticColderDrier() != 1
        )
            ++bad;
        // wovArcticFrigid
    if (wovArcticFrigid() != 1
        )
            ++bad;
        // wovSubtropicalHotter
    if (wovSubtropicalHotter() != 1
        )
            ++bad;
        // wovSubtropicalPrecipExtremes
    if (wovSubtropicalPrecipExtremes() != 1
        )
            ++bad;
        // wovTropicalWarmExceptHigh
    if (wovTropicalWarmExceptHigh() != 1
        )
            ++bad;
        // wovTropicalHeavyRain
    if (wovTropicalHeavyRain() != 1
        )
            ++bad;
        // wovNoBlizzardInTropics
    if (wovNoBlizzardInTropics() != 1
        )
            ++bad;
        printf("R497 WSG overview audit: bad %d\n", bad);
        if (bad) return 1;
    }
