    // ---- R492 WSG DM section pin audit ----
    // The Dungeon Master section, CLOSING it. The opener: the veteran faded
    // world and the first-timer, the crossroads, no going back without
    // starting over. Realism vs fantasy: no uphill water, the Earthlike
    // assumption, the familiar-features advantage, homo sapiens dominant, the
    // world as inobtrusive backdrop, deviations on a small scale. The ten
    // steps: the 20-to-40-mile-per-hex scale from the DMG page 47 with the
    // 8.5-by-11 sheet covering 1600 by 1250 miles of two million square
    // miles, the 50-or-60-mile larger scale, the pp. 124-126 hex sheets; the
    // coastline outline and sea level; the 10,000-foot and 5,000-foot
    // elevation lines at 5,000-foot increments; the planet placement, the
    // five regions, the prevailing winds; the rivers high-to-sea, the
    // Mississippi-and-Amazon rarity, the subarctic networks, the swamps in
    // low country; the subtropical and downwind deserts; the forests near
    // water below the tree line; the leftover hills and plains. The details:
    // the oases and passes, the river through the desert with its non-desert
    // banks, the fault lines at abrupt elevation and seacoasts and mountain
    // axes, the 20-to-40-mile hot spots where magma lies close, the
    // not-every-line-quakes latitude. The semi-finished product: the cities
    // by water with sea outlets, the resource cities with roads, the
    // isolation independence, the desert divide, the rivers as boundaries,
    // the elven and dwarven enclaves, the country ABCD example. Scaling down:
    // the seven-league-boot caveat, the eight-hex cluster three wide at
    // one-third, the 36-12-4-1-and-a-third-half-mile ladder, the cluster maps
    // on demand. The smaller-scale-more-detail rules with the 20-to-30-foot
    // cliff. Winging it: the think-on-feet law, the oak-and-clearing example,
    // the cannot-uncreate rule, the hex-paper sketching, the between-session
    // updates, the framework closing.
    {
        using namespace rules;
        int bad = 0;
    if (wmdHexLoMph() != 20
            || wmdHexHiMph() != 40
            || wmdDmgPage() != 47
            || wmdPaperLongMi() != 1600
            || wmdPaperShortMi() != 1250
            || wmdPaperSqMi() != 2000000
            || wmdBigHexLoMph() != 50
            || wmdBigHexHiMph() != 60
            || wmdHexSheetFirstPg() != 124
            || wmdHexSheetLastPg() != 126
            || wmdPeakLineFt() != 10000
            || wmdMidLineFt() != 5000
            || wmdIncrFt() != 5000
            || wmdHotSpotLoMph() != 20
            || wmdHotSpotHiMph() != 40
            || wmdClusterHexes() != 8
            || wmdClusterWideHexes() != 3
            || wmdClusterDiv() != 3
            || wmdExampleHexMph() != 36
            || wmdFirstClusterMph() != 12
            || wmdSecondClusterMph() != 4
            || wmdThirdClusterNum() != 4
            || wmdThirdClusterDen() != 3
            || wmdHalfMileNum() != 1
            || wmdHalfMileDen() != 2
            || wmdCliffLoFt() != 20
            || wmdCliffHiFt() != 30
            || !wmdOldWorldFaded()
            || !wmdFirstTimeDM()
            || !wmdCrossroads()
            || !wmdNoGoingBack()
            || !wmdNoUphillWater()
            || !wmdEarthlikeAssumption()
            || !wmdFamiliarAdvantage()
            || !wmdHumanDominant()
            || !wmdBackdropRule()
            || !wmdDeviationSmallScale()
            || !wmdObviousOverlooked()
            || !wmdContinentSize()
            || !wmdHexesRegulateOnly()
            || !wmdStartAtBottom()
            || !wmdLandOffEdge()
            || !wmdSeaLevelLine()
            || !wmdPeakBalance()
            || !wmdPlaceOnPlanet()
            || !wmdFiveRegionsEnough()
            || !wmdPrevailingWinds()
            || !wmdRiversHighToSea()
            || !wmdRareRiverSystems()
            || !wmdSubarcticWater()
            || !wmdDontStreamEveryHex()
            || !wmdSwampPlacement()
            || !wmdDesertSubtropical()
            || !wmdDesertWinds()
            || !wmdDesertDownwind()
            || !wmdDesertObliterateRiver()
            || !wmdForestPlacement()
            || !wmdForestLimits()
            || !wmdHillsOrPlains()
            || !wmdAdjacentToMountainsHills()
            || !wmdLargeScaleDetails()
            || !wmdRiverThroughDesert()
            || !wmdPointsOfInterest()
            || !wmdQuakeFaultLines()
            || !wmdHotSpotDefinition()
            || !wmdNotEveryLineQuakes()
            || !wmdMoreDecisionsBetter()
            || !wmdBringItAlive()
            || !wmdCitiesByWater()
            || !wmdResourceCities()
            || !wmdIsolationIndependent()
            || !wmdDesertDivides()
            || !wmdRiversBoundaries()
            || !wmdEnclavesSuited()
            || !wmdFleshOutWorld()
            || !wmdCountryExample()
            || !wmdAdventurersSurvive()
            || !wmdWorldMapNotDaily()
            || !wmdClusterMethod()
            || !wmdClusterOnDemand()
            || !wmdUnexpectedDirection()
            || !wmdGeneralityMap()
            || !wmdTerrainVaries()
            || !wmdMoreDetailEachStep()
            || !wmdThinkOnFeet()
            || !wmdImproviseWithinReason()
            || !wmdOakExample()
            || !wmdImprovisationPays()
            || !wmdCantUncreate()
            || !wmdRepeatVisits()
            || !wmdFrameworkClosing()
        )
            ++bad;
        // the recommended hex scale range is strictly ordered, 20 up to 40,
        // as is the larger 50-to-60 option
    if (wmdHexLoMph() >= wmdHexHiMph()
            || wmdBigHexLoMph() >= wmdBigHexHiMph()
        )
            ++bad;
        // the standard-sheet coverage arithmetic: 1600 miles by 1250 miles is
        // the two-million-square-mile area, and the larger-scale floor sits
        // above the recommended ceiling
    if (wmdPaperLongMi() * wmdPaperShortMi() != wmdPaperSqMi()
            || wmdBigHexLoMph() <= wmdHexHiMph()
        )
            ++bad;
        // the topography: the 10,000-foot peak line is twice the 5,000-foot
        // mid line, and the contours step at the 5,000-foot increment
    if (wmdPeakLineFt() != 2 * wmdMidLineFt()
            || wmdMidLineFt() != wmdIncrFt()
        )
            ++bad;
        // the hot spot diameter range matches the recommended hex scale range
        // exactly, 20 to 40 miles
    if (wmdHotSpotLoMph() != wmdHexLoMph()
            || wmdHotSpotHiMph() != wmdHexHiMph()
        )
            ++bad;
        // the cluster: eight smaller hexes in a cluster three hexes wide, at
        // one-third scale
    if (wmdClusterHexes() != 8
            || wmdClusterWideHexes() != 3
            || wmdClusterDiv() != wmdClusterWideHexes()
        )
            ++bad;
        // the cluster ladder: 36 miles over the divisor 3 gives the 12-mile
        // first cluster, 12 over 3 gives the 4-mile second, and 4 thirds
        // gives the 1-and-a-third third step
    if (wmdExampleHexMph() != wmdFirstClusterMph() * wmdClusterDiv()
            || wmdFirstClusterMph() != wmdSecondClusterMph() * wmdClusterDiv()
            || wmdThirdClusterNum() * wmdClusterDiv() != wmdSecondClusterMph()
            * wmdThirdClusterDen()
            || wmdThirdClusterNum() * wmdHalfMileDen() <= wmdHalfMileNum() *
            wmdThirdClusterDen()
        )
            ++bad;
        // the half-mile floor of the scale ladder is exactly one over two
    if (wmdHalfMileNum() * 2 != wmdHalfMileDen()
        )
            ++bad;
        // the hex-paper sheets run from page 124 through 126 in order
    if (wmdHexSheetFirstPg() >= wmdHexSheetLastPg()
        )
            ++bad;
        // the small cliff range runs 20 to 30 feet, strictly ordered
    if (wmdCliffLoFt() >= wmdCliffHiFt()
        )
            ++bad;
        // the Dungeon Masters Guide scale recommendation cited from page 47
    if (wmdDmgPage() != 47
        )
            ++bad;
        printf("R492 WSG DM section pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
