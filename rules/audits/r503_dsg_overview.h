    // ---- R503 DSG overview audit ----
    // The DSG OVERVIEW OF THE UNDERDARK, printed pp. 7-11 (pdf 8-12) - the
    // first DSG content round, the R497 pattern applied to the dungeoneering
    // book: the three natural cave types (limestone, sea, lava), the
    // living/dead cave split, the drip formations, the geothermal ladder with
    // the 1,800-degree lava, the unnatural locale taxonomy (dungeons, mines,
    // burrows, realms) and the five hazard families of the underearth. The
    // load-bearing pins: the pdf = printed + 1 offset (proved by the chapter
    // opener on pdf 7 for printed 6); the three-cave taxonomy; the molten
    // lava temperature of approximately 1,800 F that kills non-fire-resistant
    // creatures on contact; the 10-foot dirt-shoring interval; the
    // realms-deeper-than-a-mile rule; and the living/dead cave mechanics
    // (glisten, sturdy, mud pools vs brittle, dust, rubble,
    // standing-but-not-stagnant water). The DM-section boxes of
    // tools/dsg_gap_report.md are re-grained in the same splice from the DM
    // table of contents pulled at pdf 65, and the perspective-maps section
    // (pp. 124-127) the player TOC missed is opened. Provenance: the
    // tesseract reads (d8-d12 full/tsv/png) on the r503-extraction branch;
    // pdf 9 is the cave-formations illustration plate (labels only).
    {
        using namespace rules;
        int bad = 0;
    if (dovPrintedLo() != 7
            || dovPrintedHi() != 11
            || dovPdfLo() != 8
            || dovPdfHi() != 12
            || dovCaveTypeCount() != 3
            || dovLavaTempF() != 1800
            || dovDirtShoringIntervalFt() != 10
            || dovRealmShallowMi() != 1
            || !dovLimestoneMostCommon()
            || !dovLimestoneCarbonateBedrock()
            || !dovLimestoneAcidErosion()
            || !dovWaterTableDrainsCave()
            || !dovLimestoneWaterInletEntrances()
            || !dovSinkholeEntrance()
            || !dovDripFormations()
            || !dovOtherFormations()
            || !dovLivingCaveSeepage()
            || !dovLivingCaveMud()
            || !dovDeadCaveBrittle()
            || !dovDeadCaveRubble()
            || !dovDeadCaveWaterNotStagnant()
            || !dovWaterFilledSmooth()
            || !dovSeaCaveSurfCarved()
            || !dovSeaCaveSmaller()
            || !dovSeaCaveWaterLevels()
            || !dovSeaCaveSmoothNoFeatures()
            || !dovRiverbendLikeSeaCave()
            || !dovLavaCrustOrigin()
            || !dovLavaCaveVolcanic()
            || !dovLavaCaveDry()
            || !dovLavaCaveHiddenExits()
            || !dovQuakeChamberNotTrueCave()
            || !dovFaultCavityEnclosed()
            || !dovGeothermalInDeepCaves()
            || !dovLavaKillsOnContact()
            || !dovLavaCrustBreakRisk()
            || !dovSteamScalds()
            || !dovHotWaterRange()
            || !dovWarmAirFirstWarning()
            || !dovDungeonPurposeBuilt()
            || !dovDungeonShallowish()
            || !dovDungeonSoftRock()
            || !dovRuinsBecomeDungeons()
            || !dovDungeonPurposes()
            || !dovDungeonStrongerThanCastles()
            || !dovMineTunnelNetworks()
            || !dovMineActiveGuarded()
            || !dovBurrowCreatorSized()
            || !dovRealmsDeepMystery()
            || !dovRealmNationScale()
            || !dovRealmWildernessToCities()
            || !dovCaveinTriggers()
            || !dovCaveinProtectionSplit()
            || !dovFloodNoDispersion()
            || !dovFireDoubleThreat()
            || !dovWoodUncommonUnderground()
            || !dovPoisonGasConfined()
            || !dovVolcanoDamage()
        )
            ++bad;
        // the chapter spans printed 7-11 and pdf 8-12
    if (dovPrintedLo() != 7
            || dovPrintedHi() != 11
            || dovPdfLo() != 8
            || dovPdfHi() != 12
        )
            ++bad;
        // the pdf offset is printed + 1 on both ends of the chapter
    if (dovPdfLo() - dovPrintedLo() != 1
            || dovPdfHi() - dovPrintedHi() != 1
        )
            ++bad;
        // three natural cave types
    if (dovCaveTypeCount() != 3
        )
            ++bad;
        // molten lava runs at approximately 1,800 degrees Fahrenheit
    if (dovLavaTempF() != 1800
            || dovLavaTempF() < 1000
        )
            ++bad;
        // dirt dungeons get shored at 10-foot intervals
    if (dovDirtShoringIntervalFt() != 10
            || dovDirtShoringIntervalFt() <= 0
        )
            ++bad;
        // realms live deeper than a mile
    if (dovRealmShallowMi() != 1
        )
            ++bad;
        // dovLimestoneMostCommon
    if (dovLimestoneMostCommon() != 1
        )
            ++bad;
        // dovLimestoneCarbonateBedrock
    if (dovLimestoneCarbonateBedrock() != 1
        )
            ++bad;
        // dovLimestoneAcidErosion
    if (dovLimestoneAcidErosion() != 1
        )
            ++bad;
        // dovWaterTableDrainsCave
    if (dovWaterTableDrainsCave() != 1
        )
            ++bad;
        // dovLimestoneWaterInletEntrances
    if (dovLimestoneWaterInletEntrances() != 1
        )
            ++bad;
        // dovSinkholeEntrance
    if (dovSinkholeEntrance() != 1
        )
            ++bad;
        // dovDripFormations
    if (dovDripFormations() != 1
        )
            ++bad;
        // dovOtherFormations
    if (dovOtherFormations() != 1
        )
            ++bad;
        // dovLivingCaveSeepage
    if (dovLivingCaveSeepage() != 1
        )
            ++bad;
        // dovLivingCaveMud
    if (dovLivingCaveMud() != 1
        )
            ++bad;
        // dovDeadCaveBrittle
    if (dovDeadCaveBrittle() != 1
        )
            ++bad;
        // dovDeadCaveRubble
    if (dovDeadCaveRubble() != 1
        )
            ++bad;
        // dovDeadCaveWaterNotStagnant
    if (dovDeadCaveWaterNotStagnant() != 1
        )
            ++bad;
        // dovWaterFilledSmooth
    if (dovWaterFilledSmooth() != 1
        )
            ++bad;
        // dovSeaCaveSurfCarved
    if (dovSeaCaveSurfCarved() != 1
        )
            ++bad;
        // dovSeaCaveSmaller
    if (dovSeaCaveSmaller() != 1
        )
            ++bad;
        // dovSeaCaveWaterLevels
    if (dovSeaCaveWaterLevels() != 1
        )
            ++bad;
        // dovSeaCaveSmoothNoFeatures
    if (dovSeaCaveSmoothNoFeatures() != 1
        )
            ++bad;
        // dovRiverbendLikeSeaCave
    if (dovRiverbendLikeSeaCave() != 1
        )
            ++bad;
        // dovLavaCrustOrigin
    if (dovLavaCrustOrigin() != 1
        )
            ++bad;
        // dovLavaCaveVolcanic
    if (dovLavaCaveVolcanic() != 1
        )
            ++bad;
        // dovLavaCaveDry
    if (dovLavaCaveDry() != 1
        )
            ++bad;
        // dovLavaCaveHiddenExits
    if (dovLavaCaveHiddenExits() != 1
        )
            ++bad;
        // dovQuakeChamberNotTrueCave
    if (dovQuakeChamberNotTrueCave() != 1
        )
            ++bad;
        // dovFaultCavityEnclosed
    if (dovFaultCavityEnclosed() != 1
        )
            ++bad;
        // dovGeothermalInDeepCaves
    if (dovGeothermalInDeepCaves() != 1
        )
            ++bad;
        // dovLavaKillsOnContact
    if (dovLavaKillsOnContact() != 1
        )
            ++bad;
        // dovLavaCrustBreakRisk
    if (dovLavaCrustBreakRisk() != 1
        )
            ++bad;
        // dovSteamScalds
    if (dovSteamScalds() != 1
        )
            ++bad;
        // dovHotWaterRange
    if (dovHotWaterRange() != 1
        )
            ++bad;
        // dovWarmAirFirstWarning
    if (dovWarmAirFirstWarning() != 1
        )
            ++bad;
        // dovDungeonPurposeBuilt
    if (dovDungeonPurposeBuilt() != 1
        )
            ++bad;
        // dovDungeonShallowish
    if (dovDungeonShallowish() != 1
        )
            ++bad;
        // dovDungeonSoftRock
    if (dovDungeonSoftRock() != 1
        )
            ++bad;
        // dovRuinsBecomeDungeons
    if (dovRuinsBecomeDungeons() != 1
        )
            ++bad;
        // dovDungeonPurposes
    if (dovDungeonPurposes() != 1
        )
            ++bad;
        // dovDungeonStrongerThanCastles
    if (dovDungeonStrongerThanCastles() != 1
        )
            ++bad;
        // dovMineTunnelNetworks
    if (dovMineTunnelNetworks() != 1
        )
            ++bad;
        // dovMineActiveGuarded
    if (dovMineActiveGuarded() != 1
        )
            ++bad;
        // dovBurrowCreatorSized
    if (dovBurrowCreatorSized() != 1
        )
            ++bad;
        // dovRealmsDeepMystery
    if (dovRealmsDeepMystery() != 1
        )
            ++bad;
        // dovRealmNationScale
    if (dovRealmNationScale() != 1
        )
            ++bad;
        // dovRealmWildernessToCities
    if (dovRealmWildernessToCities() != 1
        )
            ++bad;
        // dovCaveinTriggers
    if (dovCaveinTriggers() != 1
        )
            ++bad;
        // dovCaveinProtectionSplit
    if (dovCaveinProtectionSplit() != 1
        )
            ++bad;
        // dovFloodNoDispersion
    if (dovFloodNoDispersion() != 1
        )
            ++bad;
        // dovFireDoubleThreat
    if (dovFireDoubleThreat() != 1
        )
            ++bad;
        // dovWoodUncommonUnderground
    if (dovWoodUncommonUnderground() != 1
        )
            ++bad;
        // dovPoisonGasConfined
    if (dovPoisonGasConfined() != 1
        )
            ++bad;
        // dovVolcanoDamage
    if (dovVolcanoDamage() != 1
        )
            ++bad;
        printf("R503 DSG overview audit: bad %d\n", bad);
        if (bad) return 1;
    }
