// =========================================================================================
// Adnd1 - rules/wsgoverview.h
// The WSG OVERVIEW OF THE WILDERNESS, R497: the opening chapter of the book,
// printed pp. 7-10 (pdf 8-11) - the seven terrain types, the hierarchy of
// terrain, the bodies of water and the five climate zones. Prose mechanics:
// no grids, no dice - the load-bearing numbers are the desert rainfall
// definition, the dune cap, the hills guideline bands, the mountain
// thresholds and the hierarchy ranking.
// census 421 -> 422.
//
// WSG printed pp. 7-10, pdf 8-11, extracted at r497-extraction sha 0d5f109
// (tesseract full-text and tsv, x8-x11, 300 dpi, the /tmp-write retry after
// the empty-shell push 2644f42). The extraction also covers the R498
// proficiencies ground: pdf 12-18.
//
// THE SETTLE: the eleven overview boxes flip in the same commit; 182 closed /
// 4 open - only the proficiencies prose (pp. 11-17) remains in the WSG gap
// report; census 421 -> 422.
//
namespace rules {

// ---- the chapter opener ----

// the overview chapter starts at printed p. 7.
inline int wovPrintedLo()
    { return 7; }

// the overview chapter ends at printed p. 10.
inline int wovPrintedHi()
    { return 10; }

// the overview chapter starts at pdf page 8.
inline int wovPdfLo()
    { return 8; }

// the overview chapter ends at pdf page 11.
inline int wovPdfHi()
    { return 11; }

// seven terrain types: desert, forest, hills, mountains, plains, seacoast and
// swamp.
inline int wovTerrainTypeCount()
    { return 7; }

// ---- the desert ----

// the technical definition of a desert: any area receiving less than 10
// inches of rain per year.
inline int wovDesertRainMaxIn()
    { return 10; }

// most deserts receive half the technical maximum or even less.
inline int wovDesertTypicalRainIn()
    { return 5; }

// a dune is a wind-formed sand accumulation no more than 70 feet high.
inline int wovDuneTechnicalMaxFt()
    { return 70; }

// where sand is abundant and the wind very strong, dunes can grow to more
// than 500 feet high.
inline int wovDuneGiantFt()
    { return 500; }

// the icy polar wastes qualify as desert: moisture is abundant as ice but
// precipitation is very little.
inline bool wovPolarWastesAreDesert()
    { return true; }

// most deserts are dry, hard-packed earth beneath a layer of gravel,
// occasionally broken by large boulders.
inline bool wovDesertGravelCommon()
    { return true; }

// in gravel deserts the rainfall tends to run off the surface instead of
// soaking in, making water hard to find.
inline bool wovGravelDesertWaterRunsOff()
    { return true; }

// sand permits water to soak into the terrain, from where it can be recovered
// later.
inline bool wovSandSoaksWater()
    { return true; }

// a wind-formed sand accumulation larger than a dune is properly called a
// sand mountain, or draa.
inline bool wovDuneLargerIsDraa()
    { return true; }

// a dune ascends gradually on the windward side and slopes down sharply on
// the side opposite the wind.
inline bool wovDuneWindwardGradual()
    { return true; }

// an object remaining in one spot in heavy sand cover may end up buried under
// tons of sand.
inline bool wovDesertBurialRisk()
    { return true; }

// ---- the forest ----

// the largest temperate trees (oak, maple and ash) can reach 160 feet tall.
inline int wovTemperateTreeMaxFt()
    { return 160; }

// forests can be found in any climate except the polar regions.
inline bool wovForestAnyClimateButPolar()
    { return true; }

// a large stand of cactus in a desert does not qualify as forest: the area
// stays desert for weather, food and water determination.
inline bool wovCactusStandIsDesert()
    { return true; }

// subarctic forests are evergreens, or conifers.
inline bool wovConifersSubarctic()
    { return true; }

// temperate forests are primarily deciduous, leaf-bearing trees.
inline bool wovDeciduousTemperate()
    { return true; }

// rainforest is the name for forests in subtropical and tropical climates.
inline bool wovRainforestTropical()
    { return true; }

// the conifer cone shape sheds snow easily; conifer branches are a good
// source of impromptu shelter material.
inline bool wovConiferShedsSnow()
    { return true; }

// the distinctive feature of a rainforest is its layered composition: several
// tree heights coexisting with low shrubs and ferns.
inline bool wovRainforestLayered()
    { return true; }

// rainforest trees are green all year round: new leaves appear before the old
// ones drop.
inline bool wovRainforestGreenYearRound()
    { return true; }

// ---- the hills ----

// the low hills band: elevation under 2,000 feet with sharply sloping mounds.
inline int wovHillsLowBandFt()
    { return 2000; }

// low-band hill peaks may rise above 2,000 feet.
inline int wovHillsPeaksMayExceedFt()
    { return 2000; }

// the upper hills band starts at 2,000 feet.
inline int wovHillsUpperBandLoFt()
    { return 2000; }

// the upper hills band runs through 4,000 feet.
inline int wovHillsUpperBandHiFt()
    { return 4000; }

// four classification guidelines govern hilly terrain.
inline int wovHillsGuidelineCount()
    { return 4; }

// hills are about topography, not ecology: a forest or a desert can also be
// hilly.
inline bool wovHillsTopographyNotEcology()
    { return true; }

// any irregular terrain with dense or moderate tree cover is forest.
inline bool wovHillsDenseTreesAreForest()
    { return true; }

// gently rolling terrain under 2,000 feet with few or no trees is NOT hills:
// use desert, plains, swamp or seacoast as appropriate.
inline bool wovHillsRollingUnder2000NotHills()
    { return true; }

// terrain under 2,000 feet with few or no trees and sharply sloping mounds
// (peaks possibly above 2,000 feet) is hills.
inline bool wovHillsSharpMoundsAreHills()
    { return true; }

// terrain between 2,000 and 4,000 feet with irregular ground and few or no
// trees is hills.
inline bool wovHillsUpperBandIrregular()
    { return true; }

// ---- the mountains ----

// mountainous terrain usually occurs at 4,000 feet or above.
inline int wovMountainMinFt()
    { return 4000; }

// on Earth the tree line sits at about 10,000 feet above sea level.
inline int wovEarthTreeLineFt()
    { return 10000; }

// beyond the snow line at 12,000 feet trees cannot prosper.
inline int wovEarthSnowLineFt()
    { return 12000; }

// mountainous terrain is devoid of large vegetation.
inline bool wovMountainDevoidOfTrees()
    { return true; }

// a heavily wooded area on the lower slopes of a mountain is forest, even
// above 4,000 feet.
inline bool wovMountainLowerSlopeTreesAreForest()
    { return true; }

// a mountainous region for movement, encounters and food availability begins
// where the trees end.
inline bool wovMountainBeginsWhereTreesEnd()
    { return true; }

// a barren, rocky slope rising high above the surrounding area can be
// mountainous even from a base under 4,000 feet.
inline bool wovLowRockySlopeCanBeMountain()
    { return true; }

// above the snow line some of the rocky surface is covered with snow or ice,
// making travel more hazardous.
inline bool wovAboveSnowLineSnowIce()
    { return true; }

// exposed rock surfaces at high altitude can become much warmer than the air
// temperature because they absorb the sun heat all day.
inline bool wovExposedRockWarmAir()
    { return true; }

// ---- the plains ----

// plains are mostly flat, with moderately dense low vegetation except in an
// arctic climate.
inline bool wovPlainsFlatVegetated()
    { return true; }

// an occasional tree or small grove on a plain is not enough to qualify as
// forest.
inline bool wovPlainsTreesNotForest()
    { return true; }

// food and water are generally easy to find on a plain.
inline bool wovPlainsFoodWaterEasy()
    { return true; }

// the materials for an impromptu shelter are not easily come by on a plain.
inline bool wovPlainsShelterMaterialScarce()
    { return true; }

// on flat, featureless terrain, characters who can see for a long distance
// can in turn be seen from far away.
inline bool wovPlainsSeenFromFarAway()
    { return true; }

// ---- the seacoast ----

// practically any place a short distance from an ocean is seacoast terrain.
inline bool wovSeacoastNearOcean()
    { return true; }

// the seacoast distinction matters for weather conditions, animal
// availability for food and plant availability for food and medicine.
inline bool wovSeacoastDrivesThreeLookups()
    { return true; }

// for DMG or Monster Manual II encounter tables, a seacoast area should be
// treated as the other terrain type that conforms to the table
// classifications.
inline bool wovSeacoastEncounterReclass()
    { return true; }

// ---- the swamp ----

// a swamp is any place where a character feet hit standing water shortly
// before hitting the ground.
inline bool wovSwampStandingWater()
    { return true; }

// swamps are always located at low elevation or on flat or slightly depressed
// land at the edge of a river or lake.
inline bool wovSwampLowElevation()
    { return true; }

// swamp soil is extremely fertile because it contains a great quantity of
// decomposed vegetable matter.
inline bool wovSwampFertileSoil()
    { return true; }

// swamp water depth varies from practically zero to several feet, and can go
// from shallow to deep in a few steps.
inline bool wovSwampDepthVariesFast()
    { return true; }

// a swamp is not a good place to take mounts or pack animals.
inline bool wovSwampBadForMounts()
    { return true; }

// ---- the hierarchy of terrain ----

// the terrain hierarchy has seven ranks, 1 the highest and 7 the lowest.
inline int wovHierarchyRankCount()
    { return 7; }

// the hierarchy rank of seacoast.
inline int wovRankSeacoast()
    { return 1; }

// the hierarchy rank of swamp.
inline int wovRankSwamp()
    { return 2; }

// the hierarchy rank of forest.
inline int wovRankForest()
    { return 3; }

// the hierarchy rank of plains.
inline int wovRankPlains()
    { return 4; }

// the hierarchy rank of desert.
inline int wovRankDesert()
    { return 5; }

// the hierarchy rank of hills.
inline int wovRankHills()
    { return 6; }

// the hierarchy rank of mountains.
inline int wovRankMountains()
    { return 7; }

// an area with properties of two or more categories counts as the
// highest-ranking terrain category.
inline bool wovHierarchyHighestWins()
    { return true; }

// a sandy beach bordering the ocean is seacoast, not desert.
inline bool wovBeachIsSeacoast()
    { return true; }

// a low-lying area with standing water and a lot of large trees is swamp, not
// forest.
inline bool wovWetTreelandIsSwamp()
    { return true; }

// where ocean waves crash against the base of a jagged rocky slope, the area
// is mountains, not seacoast.
inline bool wovOceanRockBaseIsMountains()
    { return true; }

// a marshy area in a deep valley between two hills is hills, not swamp.
inline bool wovMarshValleyIsHills()
    { return true; }

// the ranking is used only when common sense and reasonability do not settle
// the classification.
inline bool wovHierarchyLastResort()
    { return true; }

// ---- the bodies of water ----

// rivers and lakes provide a ready source of water and require a party to be
// more versatile: a body of water is both an opportunity and a challenge.
inline bool wovWaterSourceAndChallenge()
    { return true; }

// travel on a lake or river surface is often faster, easier and safer than
// the surrounding terrain on foot - but only with a craft and someone skilled
// to handle it.
inline bool wovBoatTravelFasterSafer()
    { return true; }

// swimming across a deep wide river instead of fording can save hours or even
// days - but only for characters who can swim.
inline bool wovSwimCrossSavesTime()
    { return true; }

// a party fully prepared for the wilderness carries equipment and skills for
// coping with bodies of water as well as for moving on land.
inline bool wovPrepareForWater()
    { return true; }

// ---- the climate ----

// five climate zones: arctic, subarctic, temperate, subtropical and tropical.
inline int wovClimateZoneCount()
    { return 5; }

// the greatest extremes of weather from one season to another are found in
// the temperate zones.
inline bool wovTemperateGreatestExtremes()
    { return true; }

// the temperate zones lie roughly equidistant from the poles and the equator.
inline bool wovTemperateEquidistant()
    { return true; }

// the weather in subarctic regions is usually colder and drier than
// temperate.
inline bool wovSubarcticColderDrier()
    { return true; }

// the weather in the arctic zones around each pole is almost always frigid.
inline bool wovArcticFrigid()
    { return true; }

// the subtropical regions have a higher average temperature than the
// temperate zones.
inline bool wovSubtropicalHotter()
    { return true; }

// subtropical regions show great extremes of precipitation in certain areas
// from one time of year to the other.
inline bool wovSubtropicalPrecipExtremes()
    { return true; }

// in the tropical zone on either side of the equator the temperature is
// almost always warm, except at high elevation.
inline bool wovTropicalWarmExceptHigh()
    { return true; }

// in the tropical zone, precipitation can be extremely heavy in the areas
// where rain does fall.
inline bool wovTropicalHeavyRain()
    { return true; }

// characters will not contend with a raging blizzard in the tropics or a
// blistering heat wave in the far north, but the weather within a region
// still travels a wide range.
inline bool wovNoBlizzardInTropics()
    { return true; }

}   // namespace rules
