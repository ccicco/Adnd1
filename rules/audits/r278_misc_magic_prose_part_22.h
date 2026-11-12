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
        Miscmagic_rope_of_climbing_to_spade_of_colossal_excavation miscmagic_rope_of_climbing_to_spade_of_colossal_excavation;
        Miscmagic_table5_footnotes miscmagic_table5_footnotes;
        int bad = 0;
        // the rope of climbing scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbLengthFeet() != 60 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbWeightPounds() != 3 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbSupportPounds() != 3000 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbSpeedFeetPerRound() != 10 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbKnotIntervalFeet() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbKnottedLengthFeet() != 50) ++bad;
        // the knotted rope is shorter than the full rope
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbKnottedLengthFeet() >=
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpClimbLengthFeet()) ++bad;
        // the rope of constriction scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictExtraVictimsMin() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictExtraVictimsMax() != 4 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictVictimRangeFeet() != 10 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictDmgMin() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictDmgMax() != 12 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictAcClass() != -2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictCutHitPoints() != 22) ++bad;
        // the victim band and damage band are ordered
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictExtraVictimsMin() >
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictExtraVictimsMax() ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictDmgMin() >
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpConstrictDmgMax()) ++bad;
        // the rope of entanglement scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleLashFeet() != 20 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleUpwardFeet() != 10 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManSizedMax() != 8 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleStrikeSegments() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleEntwineSegments() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleCommandSegments() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleWholeSegments() != 3 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleAcClass() != -2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleCutHitPoints() != 22 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleRepairTurns() != 6) ++bad;
        // the three segment costs sum to the whole
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleStrikeSegments() +
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleEntwineSegments() +
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleCommandSegments() !=
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleWholeSegments()) ++bad;
        // the man-sized equivalence chain against a twin
        static const int kMu[9] = {
            1, 2, 3, 4, 6,
            8, 10, 12, 16,
        };
        for (int i = 0; i < 9; ++i)
            if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManUnits(i) != kMu[i]) ++bad;
        // the chain rises strictly and the men equal the max
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManUnits(0) != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManUnits(8) != 16) ++bad;
        for (int i = 0; i < 8; ++i)
            if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManUnits(i) >=
                miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManUnits(i + 1)) ++bad;
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManUnits(5) !=
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEntangleManSizedMax()) ++bad;
        // the rug of smothering scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSmotherRoundsMin() != 3 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSmotherRoundsMax() != 6 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSmotherBlockingSpells() != 4) ++bad;
        // the rug of welcome scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeFlyWidthFeet() != 6 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeFlyLengthFeet() != 9 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeBridgeFeet() != 27 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeBridgeWidthFeet() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeAcClass() != 0 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeDestroyHitPoints() != 100 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeShrinkDivisor() != 12) ++bad;
        // the bridge is longer than it is wide
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeBridgeWidthFeet() >=
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpWelcomeBridgeFeet()) ++bad;
        // the saw of mighty cutting scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawLengthFeet() != 12 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawWidthFeet() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawSoloStrength() != 18 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawTandemStrength() != 17 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawTandemPersons() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawHardwoodFeet() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawHardwoodTurns() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawTrunkFeet() != 4 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawTrunkTurns() != 3 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawSmallDiameterFeet() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawSmallRounds() != 3 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawWorkTurns() != 6 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawRestTurns() != 6) ++bad;
        // the work and rest turns match
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawWorkTurns() !=
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSawRestTurns()) ++bad;
        // the scarab of death scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpDeathHoldRounds() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpDeathContainerFeet() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpDeathContainerTurns() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpDeathHeartRounds() != 1) ++bad;
        // the scarab of enraging enemies scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageRadiusInches() != 4 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageToHitBonus() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageDamageBonus() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageAcPenalty() != 3 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageRageMin() != 7 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageRageMax() != 12 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageChargesMin() != 19 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageChargesMax() != 24) ++bad;
        // the rage and charge bands are ordered
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageRageMin() >
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageRageMax() ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageChargesMin() >
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpEnrageChargesMax()) ++bad;
        // the scarab of insanity scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityRadiusInches() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanitySavePenalty() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityMagicResistPenaltyPct() != 10 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityRoundsMin() != 9 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityRoundsMax() != 12 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityChargesMin() != 9 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityChargesMax() != 16) ++bad;
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityRoundsMin() >
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityRoundsMax() ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityChargesMin() >
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpInsanityChargesMax()) ++bad;
        // the scarab of protection scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectSaveBonus() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectNoSaveBase() != 20 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectAbsorbCount() != 12 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectReversedOneIn() != 20 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectReversedPenalty() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectFixedOneIn() != 5 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectFixedBonus() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectRemoveClericLevel() != 16 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectRemovedAbsorbCount() != 24) ++bad;
        // the fixed scarab absorbs double
        if (2 * miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectAbsorbCount() !=
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectRemovedAbsorbCount()) ++bad;
        // the fix rate is rarer than the curse rate
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectFixedOneIn() >
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpProtectReversedOneIn()) ++bad;
        // the spade of colossal excavation scalars
        if (miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeLengthFeet() != 8 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeBladeWidthFeet() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeBladeLengthFeet() != 3 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeUserStrength() != 18 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeDigYardsPerRound() != 1 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeWorkRounds() != 10 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeRestRounds() != 5 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeHardPanFactor() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeGravelFactor() != 2 ||
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeLooseSoilDivisor() != 2) ++bad;
        // the work-to-rest ratio is 2 to 1
        if (2 * miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeRestRounds() !=
            miscmagic_rope_of_climbing_to_spade_of_colossal_excavation.mmpSpadeWorkRounds()) ++bad;
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
