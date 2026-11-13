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
        int bad = 0;
        // the rope of climbing scalars
        if (rules::mmpClimbLengthFeet() != 60 ||
            rules::mmpClimbWeightPounds() != 3 ||
            rules::mmpClimbSupportPounds() != 3000 ||
            rules::mmpClimbSpeedFeetPerRound() != 10 ||
            rules::mmpClimbKnotIntervalFeet() != 1 ||
            rules::mmpClimbKnottedLengthFeet() != 50) ++bad;
        // the knotted rope is shorter than the full rope
        if (rules::mmpClimbKnottedLengthFeet() >=
            rules::mmpClimbLengthFeet()) ++bad;
        // the rope of constriction scalars
        if (rules::mmpConstrictExtraVictimsMin() != 1 ||
            rules::mmpConstrictExtraVictimsMax() != 4 ||
            rules::mmpConstrictVictimRangeFeet() != 10 ||
            rules::mmpConstrictDmgMin() != 2 ||
            rules::mmpConstrictDmgMax() != 12 ||
            rules::mmpConstrictAcClass() != -2 ||
            rules::mmpConstrictCutHitPoints() != 22) ++bad;
        // the victim band and damage band are ordered
        if (rules::mmpConstrictExtraVictimsMin() >
            rules::mmpConstrictExtraVictimsMax() ||
            rules::mmpConstrictDmgMin() >
            rules::mmpConstrictDmgMax()) ++bad;
        // the rope of entanglement scalars
        if (rules::mmpEntangleLashFeet() != 20 ||
            rules::mmpEntangleUpwardFeet() != 10 ||
            rules::mmpEntangleManSizedMax() != 8 ||
            rules::mmpEntangleStrikeSegments() != 1 ||
            rules::mmpEntangleEntwineSegments() != 1 ||
            rules::mmpEntangleCommandSegments() != 1 ||
            rules::mmpEntangleWholeSegments() != 3 ||
            rules::mmpEntangleAcClass() != -2 ||
            rules::mmpEntangleCutHitPoints() != 22 ||
            rules::mmpEntangleRepairTurns() != 6) ++bad;
        // the three segment costs sum to the whole
        if (rules::mmpEntangleStrikeSegments() +
            rules::mmpEntangleEntwineSegments() +
            rules::mmpEntangleCommandSegments() !=
            rules::mmpEntangleWholeSegments()) ++bad;
        // the man-sized equivalence chain against a twin
        static const int kMu[9] = {
            1, 2, 3, 4, 6,
            8, 10, 12, 16,
        };
        for (int i = 0; i < 9; ++i)
            if (rules::mmpEntangleManUnits(i) != kMu[i]) ++bad;
        // the chain rises strictly and the men equal the max
        if (rules::mmpEntangleManUnits(0) != 1 ||
            rules::mmpEntangleManUnits(8) != 16) ++bad;
        for (int i = 0; i < 8; ++i)
            if (rules::mmpEntangleManUnits(i) >=
                rules::mmpEntangleManUnits(i + 1)) ++bad;
        if (rules::mmpEntangleManUnits(5) !=
            rules::mmpEntangleManSizedMax()) ++bad;
        // the rug of smothering scalars
        if (rules::mmpSmotherRoundsMin() != 3 ||
            rules::mmpSmotherRoundsMax() != 6 ||
            rules::mmpSmotherBlockingSpells() != 4) ++bad;
        // the rug of welcome scalars
        if (rules::mmpWelcomeFlyWidthFeet() != 6 ||
            rules::mmpWelcomeFlyLengthFeet() != 9 ||
            rules::mmpWelcomeBridgeFeet() != 27 ||
            rules::mmpWelcomeBridgeWidthFeet() != 2 ||
            rules::mmpWelcomeAcClass() != 0 ||
            rules::mmpWelcomeDestroyHitPoints() != 100 ||
            rules::mmpWelcomeShrinkDivisor() != 12) ++bad;
        // the bridge is longer than it is wide
        if (rules::mmpWelcomeBridgeWidthFeet() >=
            rules::mmpWelcomeBridgeFeet()) ++bad;
        // the saw of mighty cutting scalars
        if (rules::mmpSawLengthFeet() != 12 ||
            rules::mmpSawWidthFeet() != 1 ||
            rules::mmpSawSoloStrength() != 18 ||
            rules::mmpSawTandemStrength() != 17 ||
            rules::mmpSawTandemPersons() != 2 ||
            rules::mmpSawHardwoodFeet() != 2 ||
            rules::mmpSawHardwoodTurns() != 1 ||
            rules::mmpSawTrunkFeet() != 4 ||
            rules::mmpSawTrunkTurns() != 3 ||
            rules::mmpSawSmallDiameterFeet() != 1 ||
            rules::mmpSawSmallRounds() != 3 ||
            rules::mmpSawWorkTurns() != 6 ||
            rules::mmpSawRestTurns() != 6) ++bad;
        // the work and rest turns match
        if (rules::mmpSawWorkTurns() !=
            rules::mmpSawRestTurns()) ++bad;
        // the scarab of death scalars
        if (rules::mmpDeathHoldRounds() != 1 ||
            rules::mmpDeathContainerFeet() != 1 ||
            rules::mmpDeathContainerTurns() != 1 ||
            rules::mmpDeathHeartRounds() != 1) ++bad;
        // the scarab of enraging enemies scalars
        if (rules::mmpEnrageRadiusInches() != 4 ||
            rules::mmpEnrageToHitBonus() != 1 ||
            rules::mmpEnrageDamageBonus() != 2 ||
            rules::mmpEnrageAcPenalty() != 3 ||
            rules::mmpEnrageRageMin() != 7 ||
            rules::mmpEnrageRageMax() != 12 ||
            rules::mmpEnrageChargesMin() != 19 ||
            rules::mmpEnrageChargesMax() != 24) ++bad;
        // the rage and charge bands are ordered
        if (rules::mmpEnrageRageMin() >
            rules::mmpEnrageRageMax() ||
            rules::mmpEnrageChargesMin() >
            rules::mmpEnrageChargesMax()) ++bad;
        // the scarab of insanity scalars
        if (rules::mmpInsanityRadiusInches() != 2 ||
            rules::mmpInsanitySavePenalty() != 2 ||
            rules::mmpInsanityMagicResistPenaltyPct() != 10 ||
            rules::mmpInsanityRoundsMin() != 9 ||
            rules::mmpInsanityRoundsMax() != 12 ||
            rules::mmpInsanityChargesMin() != 9 ||
            rules::mmpInsanityChargesMax() != 16) ++bad;
        if (rules::mmpInsanityRoundsMin() >
            rules::mmpInsanityRoundsMax() ||
            rules::mmpInsanityChargesMin() >
            rules::mmpInsanityChargesMax()) ++bad;
        // the scarab of protection scalars
        if (rules::mmpProtectSaveBonus() != 1 ||
            rules::mmpProtectNoSaveBase() != 20 ||
            rules::mmpProtectAbsorbCount() != 12 ||
            rules::mmpProtectReversedOneIn() != 20 ||
            rules::mmpProtectReversedPenalty() != 2 ||
            rules::mmpProtectFixedOneIn() != 5 ||
            rules::mmpProtectFixedBonus() != 2 ||
            rules::mmpProtectRemoveClericLevel() != 16 ||
            rules::mmpProtectRemovedAbsorbCount() != 24) ++bad;
        // the fixed scarab absorbs double
        if (2 * rules::mmpProtectAbsorbCount() !=
            rules::mmpProtectRemovedAbsorbCount()) ++bad;
        // the fix rate is rarer than the curse rate
        if (rules::mmpProtectFixedOneIn() >
            rules::mmpProtectReversedOneIn()) ++bad;
        // the spade of colossal excavation scalars
        if (rules::mmpSpadeLengthFeet() != 8 ||
            rules::mmpSpadeBladeWidthFeet() != 2 ||
            rules::mmpSpadeBladeLengthFeet() != 3 ||
            rules::mmpSpadeUserStrength() != 18 ||
            rules::mmpSpadeDigYardsPerRound() != 1 ||
            rules::mmpSpadeWorkRounds() != 10 ||
            rules::mmpSpadeRestRounds() != 5 ||
            rules::mmpSpadeHardPanFactor() != 2 ||
            rules::mmpSpadeGravelFactor() != 2 ||
            rules::mmpSpadeLooseSoilDivisor() != 2) ++bad;
        // the work-to-rest ratio is 2 to 1
        if (2 * rules::mmpSpadeRestRounds() !=
            rules::mmpSpadeWorkRounds()) ++bad;
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
            if (rules::m5RowLo(6 + i) != kRlo[i] ||
                rules::m5RowHi(6 + i) != kRhi[i]) ++bad;
        // the slice bands run 20 through 47 with no gaps
        if (rules::m5RowLo(6) != 20 ||
            rules::m5RowHi(16) != 47) ++bad;
        for (int i = 6; i < 16; ++i)
            if (rules::m5RowLo(i + 1) !=
                rules::m5RowHi(i) + 1) ++bad;
        for (int i = 6; i < 17; ++i)
            if (rules::m5RowLo(i) >
                rules::m5RowHi(i)) ++bad;
        // no cleric or thief marks on the slice rows
        for (int i = 6; i < 17; ++i)
            if (rules::m5UsableByCleric(i) != 0) ++bad;
        for (int i = 6; i < 17; ++i)
            if (rules::m5UsableByThief(i) != 0) ++bad;
        // the fighter marks: the Saw and the Spade only
        for (int i = 6; i < 17; ++i)
            if (i != 11 && i != 16 &&
                rules::m5UsableByFighter(i) != 0) ++bad;
        if (rules::m5UsableByFighter(11) != 1 ||
            rules::m5UsableByFighter(16) != 1) ++bad;
        // the magic-user marks: the Rug of Welcome only
        for (int i = 6; i < 17; ++i)
            if (i != 10 &&
                rules::m5UsableByMagicUser(i) != 0) ++bad;
        if (rules::m5UsableByMagicUser(10) != 1) ++bad;
        // the whole-table counts and row census
        if (rules::m5ClericCount() != 5 ||
            rules::m5FighterCount() != 5 ||
            rules::m5MagicUserCount() != 8 ||
            rules::m5ThiefCount() != 2 ||
            rules::m5RowCount() != 35) ++bad;
        printf("R278 misc magic prose part 22 pins audit: bad %d\n", bad);
    }
