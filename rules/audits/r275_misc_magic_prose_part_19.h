    // ---- R275: the III.E misc magic explanation
    // prose part 19 ----
    // The Necklace of Prayer Beads, the Necklace of
    // Strangulation, the Nets of Entrapment and
    // Snaring, Nolzurs Marvelous Pigments, the Pearls
    // of Power and Wisdom and the Periapts of Foul
    // Rotting, Health, Proof Against Poison and Wound
    // Closure, part2 lines 905-969 - the slice pinning
    // the kMisc4 rows 19-29 of the 36-row III.E.4
    // table.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the necklace of prayer beads scalars
        if (miscmagic.mmpBeadStoneMin() != 25 ||
            miscmagic.mmpBeadStoneMax() != 30 ||
            miscmagic.mmpBeadSemiPreciousPct() != 60 ||
            miscmagic.mmpBeadFancyPct() != 40 ||
            miscmagic.mmpBeadPetitionBonusPct() != 25 ||
            miscmagic.mmpBeadSpecialMin() != 3 ||
            miscmagic.mmpBeadSpecialMax() != 6 ||
            miscmagic.mmpBeadGemBaseGp() != 1000 ||
            miscmagic.mmpBeadUsesPerDay() != 1 ||
            miscmagic.mmpBeadKarmaLevels() != 4 ||
            miscmagic.mmpBeadSummonsPct() != 90) ++bad;
        // the stone split sums to the full necklace
        if (miscmagic.mmpBeadSemiPreciousPct() +
            miscmagic.mmpBeadFancyPct() != 100) ++bad;
        // the bead type table against static twins
        static const int kBlo[6] = {
            1, 6, 11, 16, 18, 19,
        };
        static const int kBhi[6] = {
            5, 10, 15, 17, 18, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpBeadRowLo(i) != kBlo[i] ||
                miscmagic.mmpBeadRowHi(i) != kBhi[i]) ++bad;
        // the bead die bands tile 1-20 without gaps
        for (int i = 0; i < 5; ++i)
            if (miscmagic.mmpBeadRowLo(i + 1) !=
                miscmagic.mmpBeadRowHi(i) + 1) ++bad;
        if (miscmagic.mmpBeadRowLo(0) != 1 ||
            miscmagic.mmpBeadRowHi(5) != 20) ++bad;
        // the necklace of strangulation
        if (miscmagic.mmpStrangleDamagePerRound() != 6) ++bad;
        // the net of entrapment
        if (miscmagic.mmpEntrapMinStrength() != 20 ||
            miscmagic.mmpEntrapSizeFeet() != 10 ||
            miscmagic.mmpEntrapMeshQuarterFeet() != 1 ||
            miscmagic.mmpEntrapThrowFeet() != 20 ||
            miscmagic.mmpEntrapCloseCubeFeet() != 5) ++bad;
        // AC -10 against cutting blows
        if (miscmagic.mmpEntrapCutAc() + 10 != 0) ++bad;
        // the net of snaring
        if (miscmagic.mmpSnareRangeInches() != 3) ++bad;
        // the marvelous pigments
        if (miscmagic.mmpPigPotCubicFeet() != 1000 ||
            miscmagic.mmpPigDepictSquareFeet() != 100 ||
            miscmagic.mmpPigContainersMin() != 1 ||
            miscmagic.mmpPigContainersMax() != 4 ||
            miscmagic.mmpPigInstrumentFeet() != 1 ||
            miscmagic.mmpPigDepictTurns() != 1) ++bad;
        // the pearl of power scalars
        if (miscmagic.mmpPowerRecallPerDay() != 1 ||
            miscmagic.mmpPowerSpellsRecalled() != 1 ||
            miscmagic.mmpPowerReverseOneIn() != 20 ||
            miscmagic.mmpPowerDoubleMin() != 2 ||
            miscmagic.mmpPowerDoubleMaxLevel() != 6 ||
            miscmagic.mmpPowerDoubleDieSides() != 6) ++bad;
        // the 00 row d6 equals the 1st to 6th ladder
        if (miscmagic.mmpPowerDoubleDieSides() !=
            miscmagic.mmpPowerDoubleMaxLevel()) ++bad;
        // the pearl power table against static twins
        static const int kPlo[10] = {
            1, 26, 46, 61, 76, 86, 93, 97, 99, 100,
        };
        static const int kPhi[10] = {
            25, 45, 60, 75, 85, 92, 96, 98, 99, 100,
        };
        static const int kLvl[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
        };
        for (int i = 0; i < 10; ++i)
            if (miscmagic.mmpPowerRowLo(i) != kPlo[i] ||
                miscmagic.mmpPowerRowHi(i) != kPhi[i] ||
                miscmagic.mmpPowerSpellLevel(i) !=
                kLvl[i]) ++bad;
        // the pearl die bands tile 1-100 without gaps
        for (int i = 0; i < 9; ++i)
            if (miscmagic.mmpPowerRowLo(i + 1) !=
                miscmagic.mmpPowerRowHi(i) + 1) ++bad;
        if (miscmagic.mmpPowerRowLo(0) != 1 ||
            miscmagic.mmpPowerRowHi(9) != 100) ++bad;
        // the spell levels ascend first to ninth
        for (int i = 0; i < 8; ++i)
            if (miscmagic.mmpPowerSpellLevel(i + 1) !=
                miscmagic.mmpPowerSpellLevel(i) + 1) ++bad;
        // the 00 row carries the double-spell mark
        if (miscmagic.mmpPowerSpellLevel(9) != 0) ++bad;
        // the pearl of wisdom
        if (miscmagic.mmpWisdomGain() != 1 ||
            miscmagic.mmpWisdomMonths() != 1 ||
            miscmagic.mmpWisdomDays() != 30 ||
            miscmagic.mmpWisdomReverseOneIn() != 20) ++bad;
        // the month expires at the printed 30 days
        if (miscmagic.mmpWisdomMonths() * 30 !=
            miscmagic.mmpWisdomDays()) ++bad;
        // the periapt of foul rotting
        if (miscmagic.mmpRotAbilityLossPerWeek() != 1 ||
            miscmagic.mmpRotStartWeek() != 1 ||
            miscmagic.mmpRotAbilityCount() != 3 ||
            miscmagic.mmpRotDeathScore() != 0) ++bad;
        // the periapt of proof against poison
        if (miscmagic.mmpPoisonSavePctPerPlus() != 10) ++bad;
        static const int kOlo[4] = {
            1, 9, 15, 19,
        };
        static const int kOhi[4] = {
            8, 14, 18, 20,
        };
        static const int kOpl[4] = {
            1, 2, 3, 4,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic.mmpPoisonRowLo(i) != kOlo[i] ||
                miscmagic.mmpPoisonRowHi(i) != kOhi[i] ||
                miscmagic.mmpPoisonPlus(i) != kOpl[i]) ++bad;
        // the periapt bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpPoisonRowLo(i + 1) !=
                miscmagic.mmpPoisonRowHi(i) + 1) ++bad;
        if (miscmagic.mmpPoisonRowLo(0) != 1 ||
            miscmagic.mmpPoisonRowHi(3) != 20) ++bad;
        // the periapt of wound closure
        if (miscmagic.mmpWoundHealRateMult() != 2) ++bad;
        // the engine kMisc4 rows 19-29: the die band
        // edges, the double star on the beads, the
        // triple on the pigments, the quadruple on the
        // pearl of power, the (C), (F), (T) and (M)
        // marks, no dual rows
        static const int kRlo[11] = {
            28, 34, 36, 39, 43, 45, 47, 49, 51, 54, 61,
        };
        static const int kRhi[11] = {
            33, 35, 38, 42, 44, 46, 48, 50, 53, 60, 64,
        };
        for (int i = 0; i < 11; ++i)
            if (miscmagic_table4_footnotes.m4RowLo(19 + i) != kRlo[i] ||
                miscmagic_table4_footnotes.m4RowHi(19 + i) != kRhi[i]) ++bad;
        if (miscmagic_table4_footnotes.m4StarCount(19) != 2 ||
            miscmagic_table4_footnotes.m4StarCount(23) != 3 ||
            miscmagic_table4_footnotes.m4StarCount(24) != 4 ||
            miscmagic_table4_footnotes.m4RowCount() != 36) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 19 && i != 23 && i != 24 &&
                miscmagic_table4_footnotes.m4StarCount(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (miscmagic_table4_footnotes.m4IsDualValued(i) != 0) ++bad;
        if (miscmagic_table4_footnotes.m4UsableByCleric(19) != 1 ||
            miscmagic_table4_footnotes.m4UsableByCleric(21) != 1 ||
            miscmagic_table4_footnotes.m4UsableByCleric(22) != 1 ||
            miscmagic_table4_footnotes.m4UsableByCleric(25) != 1 ||
            miscmagic_table4_footnotes.m4UsableByFighter(21) != 1 ||
            miscmagic_table4_footnotes.m4UsableByFighter(22) != 1 ||
            miscmagic_table4_footnotes.m4UsableByThief(21) != 1 ||
            miscmagic_table4_footnotes.m4UsableByThief(22) != 1 ||
            miscmagic_table4_footnotes.m4UsableByMagicUser(24) != 1) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 19 && i != 21 && i != 22 &&
                i != 25 &&
                miscmagic_table4_footnotes.m4UsableByCleric(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 21 && i != 22 &&
                miscmagic_table4_footnotes.m4UsableByFighter(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 24 &&
                miscmagic_table4_footnotes.m4UsableByMagicUser(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 21 && i != 22 &&
                miscmagic_table4_footnotes.m4UsableByThief(i) != 0) ++bad;
        // the engine footnote helpers
        if (miscmagic_table4_footnotes.m4BeadPerSpecialXp() != 500 ||
            miscmagic_table4_footnotes.m4BeadPerSpecialGp() != 3000 ||
            miscmagic_table4_footnotes.m4PigmentsPerPotXp() != 500 ||
            miscmagic_table4_footnotes.m4PigmentsPerPotGp() != 3000 ||
            miscmagic_table4_footnotes.m4PearlPerSpellLevelXp() != 200 ||
            miscmagic_table4_footnotes.m4PearlPerSpellLevelGp() != 2000 ||
            miscmagic_table4_footnotes.m4ClericCount() != 8 ||
            miscmagic_table4_footnotes.m4FighterCount() != 4 ||
            miscmagic_table4_footnotes.m4MagicUserCount() != 6 ||
            miscmagic_table4_footnotes.m4ThiefCount() != 3) ++bad;
        printf("R275 misc magic prose part 19 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
