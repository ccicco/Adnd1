    // ---- R278: the III.E misc magic explanation
    // prose part 22 ----
    // The Rope of Climbing, the Rope of Constriction, the
    // Rope of Entanglement, the rope note, the Rug of
    // Smothering, the Rug of Welcome, the Saw of Mighty
    // Cutting, the Scarab of Death, the Scarab of Enraging
    // Enemies, the Scarab of Insanity, the Scarab of
    // Protection and the Spade of Colossal Excavation,
    // part2 lines 1054-1081 - the slice pinning the kMisc5
    // rows 6-16 of the 35-row III.E.5 table.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table5_footnotes miscmagic_table5_footnotes;
        int bad = 0;
        // the rope of climbing scalars
        if (miscmagic.mmpClimbLengthFeet() != 60 ||
            miscmagic.mmpClimbWeightPounds() != 3 ||
            miscmagic.mmpClimbSupportPounds() != 3000 ||
            miscmagic.mmpClimbSpeedFeetPerRound() != 10 ||
            miscmagic.mmpClimbKnotIntervalFeet() != 1 ||
            miscmagic.mmpClimbKnottedLengthFeet() != 50) ++bad;
        // the knotted rope is shorter than the full rope
        if (miscmagic.mmpClimbKnottedLengthFeet() >=
            miscmagic.mmpClimbLengthFeet()) ++bad;
        // the rope of constriction scalars
        if (miscmagic.mmpConstrictExtraVictimsMin() != 1 ||
            miscmagic.mmpConstrictExtraVictimsMax() != 4 ||
            miscmagic.mmpConstrictVictimRangeFeet() != 10 ||
            miscmagic.mmpConstrictDmgMin() != 2 ||
            miscmagic.mmpConstrictDmgMax() != 12 ||
            miscmagic.mmpConstrictAcClass() != -2 ||
            miscmagic.mmpConstrictCutHitPoints() != 22) ++bad;
        // the victim band and damage band are ordered
        if (miscmagic.mmpConstrictExtraVictimsMin() >
            miscmagic.mmpConstrictExtraVictimsMax() ||
            miscmagic.mmpConstrictDmgMin() >
            miscmagic.mmpConstrictDmgMax()) ++bad;
        // the rope of entanglement scalars
        if (miscmagic.mmpEntangleLashFeet() != 20 ||
            miscmagic.mmpEntangleUpwardFeet() != 10 ||
            miscmagic.mmpEntangleManSizedMax() != 8 ||
            miscmagic.mmpEntangleStrikeSegments() != 1 ||
            miscmagic.mmpEntangleEntwineSegments() != 1 ||
            miscmagic.mmpEntangleCommandSegments() != 1 ||
            miscmagic.mmpEntangleWholeSegments() != 3 ||
            miscmagic.mmpEntangleAcClass() != -2 ||
            miscmagic.mmpEntangleCutHitPoints() != 22 ||
            miscmagic.mmpEntangleRepairTurns() != 6) ++bad;
        // the three segment costs sum to the whole
        if (miscmagic.mmpEntangleStrikeSegments() +
            miscmagic.mmpEntangleEntwineSegments() +
            miscmagic.mmpEntangleCommandSegments() !=
            miscmagic.mmpEntangleWholeSegments()) ++bad;
        // the man-sized equivalence chain against a twin
        static const int kMu[9] = {
            1, 2, 3, 4, 6,
            8, 10, 12, 16,
        };
        for (int i = 0; i < 9; ++i)
            if (miscmagic.mmpEntangleManUnits(i) != kMu[i]) ++bad;
        // the chain rises strictly and the men equal the max
        if (miscmagic.mmpEntangleManUnits(0) != 1 ||
            miscmagic.mmpEntangleManUnits(8) != 16) ++bad;
        for (int i = 0; i < 8; ++i)
            if (miscmagic.mmpEntangleManUnits(i) >=
                miscmagic.mmpEntangleManUnits(i + 1)) ++bad;
        if (miscmagic.mmpEntangleManUnits(5) !=
            miscmagic.mmpEntangleManSizedMax()) ++bad;
        // the rug of smothering scalars
        if (miscmagic.mmpSmotherRoundsMin() != 3 ||
            miscmagic.mmpSmotherRoundsMax() != 6 ||
            miscmagic.mmpSmotherBlockingSpells() != 4) ++bad;
        // the rug of welcome scalars
        if (miscmagic.mmpWelcomeFlyWidthFeet() != 6 ||
            miscmagic.mmpWelcomeFlyLengthFeet() != 9 ||
            miscmagic.mmpWelcomeBridgeFeet() != 27 ||
            miscmagic.mmpWelcomeBridgeWidthFeet() != 2 ||
            miscmagic.mmpWelcomeAcClass() != 0 ||
            miscmagic.mmpWelcomeDestroyHitPoints() != 100 ||
            miscmagic.mmpWelcomeShrinkDivisor() != 12) ++bad;
        // the bridge is longer than it is wide
        if (miscmagic.mmpWelcomeBridgeWidthFeet() >=
            miscmagic.mmpWelcomeBridgeFeet()) ++bad;
        // the saw of mighty cutting scalars
        if (miscmagic.mmpSawLengthFeet() != 12 ||
            miscmagic.mmpSawWidthFeet() != 1 ||
            miscmagic.mmpSawSoloStrength() != 18 ||
            miscmagic.mmpSawTandemStrength() != 17 ||
            miscmagic.mmpSawTandemPersons() != 2 ||
            miscmagic.mmpSawHardwoodFeet() != 2 ||
            miscmagic.mmpSawHardwoodTurns() != 1 ||
            miscmagic.mmpSawTrunkFeet() != 4 ||
            miscmagic.mmpSawTrunkTurns() != 3 ||
            miscmagic.mmpSawSmallDiameterFeet() != 1 ||
            miscmagic.mmpSawSmallRounds() != 3 ||
            miscmagic.mmpSawWorkTurns() != 6 ||
            miscmagic.mmpSawRestTurns() != 6) ++bad;
        // the work and rest turns match
        if (miscmagic.mmpSawWorkTurns() !=
            miscmagic.mmpSawRestTurns()) ++bad;
        // the scarab of death scalars
        if (miscmagic.mmpDeathHoldRounds() != 1 ||
            miscmagic.mmpDeathContainerFeet() != 1 ||
            miscmagic.mmpDeathContainerTurns() != 1 ||
            miscmagic.mmpDeathHeartRounds() != 1) ++bad;
        // the scarab of enraging enemies scalars
        if (miscmagic.mmpEnrageRadiusInches() != 4 ||
            miscmagic.mmpEnrageToHitBonus() != 1 ||
            miscmagic.mmpEnrageDamageBonus() != 2 ||
            miscmagic.mmpEnrageAcPenalty() != 3 ||
            miscmagic.mmpEnrageRageMin() != 7 ||
            miscmagic.mmpEnrageRageMax() != 12 ||
            miscmagic.mmpEnrageChargesMin() != 19 ||
            miscmagic.mmpEnrageChargesMax() != 24) ++bad;
        // the rage and charge bands are ordered
        if (miscmagic.mmpEnrageRageMin() >
            miscmagic.mmpEnrageRageMax() ||
            miscmagic.mmpEnrageChargesMin() >
            miscmagic.mmpEnrageChargesMax()) ++bad;
        // the scarab of insanity scalars
        if (miscmagic.mmpInsanityRadiusInches() != 2 ||
            miscmagic.mmpInsanitySavePenalty() != 2 ||
            miscmagic.mmpInsanityMagicResistPenaltyPct() != 10 ||
            miscmagic.mmpInsanityRoundsMin() != 9 ||
            miscmagic.mmpInsanityRoundsMax() != 12 ||
            miscmagic.mmpInsanityChargesMin() != 9 ||
            miscmagic.mmpInsanityChargesMax() != 16) ++bad;
        if (miscmagic.mmpInsanityRoundsMin() >
            miscmagic.mmpInsanityRoundsMax() ||
            miscmagic.mmpInsanityChargesMin() >
            miscmagic.mmpInsanityChargesMax()) ++bad;
        // the scarab of protection scalars
        if (miscmagic.mmpProtectSaveBonus() != 1 ||
            miscmagic.mmpProtectNoSaveBase() != 20 ||
            miscmagic.mmpProtectAbsorbCount() != 12 ||
            miscmagic.mmpProtectReversedOneIn() != 20 ||
            miscmagic.mmpProtectReversedPenalty() != 2 ||
            miscmagic.mmpProtectFixedOneIn() != 5 ||
            miscmagic.mmpProtectFixedBonus() != 2 ||
            miscmagic.mmpProtectRemoveClericLevel() != 16 ||
            miscmagic.mmpProtectRemovedAbsorbCount() != 24) ++bad;
        // the fixed scarab absorbs double
        if (2 * miscmagic.mmpProtectAbsorbCount() !=
            miscmagic.mmpProtectRemovedAbsorbCount()) ++bad;
        // the fix rate is rarer than the curse rate
        if (miscmagic.mmpProtectFixedOneIn() >
            miscmagic.mmpProtectReversedOneIn()) ++bad;
        // the spade of colossal excavation scalars
        if (miscmagic.mmpSpadeLengthFeet() != 8 ||
            miscmagic.mmpSpadeBladeWidthFeet() != 2 ||
            miscmagic.mmpSpadeBladeLengthFeet() != 3 ||
            miscmagic.mmpSpadeUserStrength() != 18 ||
            miscmagic.mmpSpadeDigYardsPerRound() != 1 ||
            miscmagic.mmpSpadeWorkRounds() != 10 ||
            miscmagic.mmpSpadeRestRounds() != 5 ||
            miscmagic.mmpSpadeHardPanFactor() != 2 ||
            miscmagic.mmpSpadeGravelFactor() != 2 ||
            miscmagic.mmpSpadeLooseSoilDivisor() != 2) ++bad;
        // the work-to-rest ratio is 2 to 1
        if (2 * miscmagic.mmpSpadeRestRounds() !=
            miscmagic.mmpSpadeWorkRounds()) ++bad;
        // the kMisc5 table rows 6-16 against static twins
        static const int kRlo[11] = {
            20, 26, 28, 32, 33, 34,
            35, 36, 39, 41, 47,
        };
        static const int kRhi[11] = {
            25, 27, 31, 32, 33, 34,
            35, 38, 40, 46, 47,
        };
        for (int i = 0; i < 11; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(6 + i) != kRlo[i] ||
                miscmagic_table5_footnotes.m5RowHi(6 + i) != kRhi[i]) ++bad;
        // the slice bands run 20 through 47 with no gaps
        if (miscmagic_table5_footnotes.m5RowLo(6) != 20 ||
            miscmagic_table5_footnotes.m5RowHi(16) != 47) ++bad;
        for (int i = 6; i < 16; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(i + 1) !=
                miscmagic_table5_footnotes.m5RowHi(i) + 1) ++bad;
        for (int i = 6; i < 17; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(i) >
                miscmagic_table5_footnotes.m5RowHi(i)) ++bad;
        // no cleric or thief marks on the slice rows
        for (int i = 6; i < 17; ++i)
            if (miscmagic_table5_footnotes.m5UsableByCleric(i) != 0) ++bad;
        for (int i = 6; i < 17; ++i)
            if (miscmagic_table5_footnotes.m5UsableByThief(i) != 0) ++bad;
        // the fighter marks: the Saw and the Spade only
        for (int i = 6; i < 17; ++i)
            if (i != 11 && i != 16 &&
                miscmagic_table5_footnotes.m5UsableByFighter(i) != 0) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByFighter(11) != 1 ||
            miscmagic_table5_footnotes.m5UsableByFighter(16) != 1) ++bad;
        // the magic-user marks: the Rug of Welcome only
        for (int i = 6; i < 17; ++i)
            if (i != 10 &&
                miscmagic_table5_footnotes.m5UsableByMagicUser(i) != 0) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByMagicUser(10) != 1) ++bad;
        // the whole-table counts and row census
        if (miscmagic_table5_footnotes.m5ClericCount() != 5 ||
            miscmagic_table5_footnotes.m5FighterCount() != 5 ||
            miscmagic_table5_footnotes.m5MagicUserCount() != 8 ||
            miscmagic_table5_footnotes.m5ThiefCount() != 2 ||
            miscmagic_table5_footnotes.m5RowCount() != 35) ++bad;
        printf("R278 misc magic prose part 22 pins audit: bad %d\n", bad);
    }
