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
        Miscmagic_necklace_of_prayer_beads_to_periapts miscmagic_necklace_of_prayer_beads_to_periapts;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the necklace of prayer beads scalars
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadStoneMin() != 25 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadStoneMax() != 30 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadSemiPreciousPct() != 60 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadFancyPct() != 40 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadPetitionBonusPct() != 25 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadSpecialMin() != 3 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadSpecialMax() != 6 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadGemBaseGp() != 1000 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadUsesPerDay() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadKarmaLevels() != 4 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadSummonsPct() != 90) ++bad;
        // the stone split sums to the full necklace
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadSemiPreciousPct() +
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadFancyPct() != 100) ++bad;
        // the bead type table against static twins
        static const int kBlo[6] = {
            1, 6, 11, 16, 18, 19,
        };
        static const int kBhi[6] = {
            5, 10, 15, 17, 18, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadRowLo(i) != kBlo[i] ||
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadRowHi(i) != kBhi[i]) ++bad;
        // the bead die bands tile 1-20 without gaps
        for (int i = 0; i < 5; ++i)
            if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadRowLo(i + 1) !=
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadRowHi(i) + 1) ++bad;
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadRowLo(0) != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpBeadRowHi(5) != 20) ++bad;
        // the necklace of strangulation
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpStrangleDamagePerRound() != 6) ++bad;
        // the net of entrapment
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpEntrapMinStrength() != 20 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpEntrapSizeFeet() != 10 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpEntrapMeshQuarterFeet() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpEntrapThrowFeet() != 20 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpEntrapCloseCubeFeet() != 5) ++bad;
        // AC -10 against cutting blows
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpEntrapCutAc() + 10 != 0) ++bad;
        // the net of snaring
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpSnareRangeInches() != 3) ++bad;
        // the marvelous pigments
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPigPotCubicFeet() != 1000 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPigDepictSquareFeet() != 100 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPigContainersMin() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPigContainersMax() != 4 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPigInstrumentFeet() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPigDepictTurns() != 1) ++bad;
        // the pearl of power scalars
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerRecallPerDay() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerSpellsRecalled() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerReverseOneIn() != 20 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerDoubleMin() != 2 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerDoubleMaxLevel() != 6 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerDoubleDieSides() != 6) ++bad;
        // the 00 row d6 equals the 1st to 6th ladder
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerDoubleDieSides() !=
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerDoubleMaxLevel()) ++bad;
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
            if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerRowLo(i) != kPlo[i] ||
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerRowHi(i) != kPhi[i] ||
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerSpellLevel(i) !=
                kLvl[i]) ++bad;
        // the pearl die bands tile 1-100 without gaps
        for (int i = 0; i < 9; ++i)
            if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerRowLo(i + 1) !=
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerRowHi(i) + 1) ++bad;
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerRowLo(0) != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerRowHi(9) != 100) ++bad;
        // the spell levels ascend first to ninth
        for (int i = 0; i < 8; ++i)
            if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerSpellLevel(i + 1) !=
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerSpellLevel(i) + 1) ++bad;
        // the 00 row carries the double-spell mark
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPowerSpellLevel(9) != 0) ++bad;
        // the pearl of wisdom
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpWisdomGain() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpWisdomMonths() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpWisdomDays() != 30 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpWisdomReverseOneIn() != 20) ++bad;
        // the month expires at the printed 30 days
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpWisdomMonths() * 30 !=
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpWisdomDays()) ++bad;
        // the periapt of foul rotting
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpRotAbilityLossPerWeek() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpRotStartWeek() != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpRotAbilityCount() != 3 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpRotDeathScore() != 0) ++bad;
        // the periapt of proof against poison
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonSavePctPerPlus() != 10) ++bad;
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
            if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonRowLo(i) != kOlo[i] ||
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonRowHi(i) != kOhi[i] ||
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonPlus(i) != kOpl[i]) ++bad;
        // the periapt bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonRowLo(i + 1) !=
                miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonRowHi(i) + 1) ++bad;
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonRowLo(0) != 1 ||
            miscmagic_necklace_of_prayer_beads_to_periapts.mmpPoisonRowHi(3) != 20) ++bad;
        // the periapt of wound closure
        if (miscmagic_necklace_of_prayer_beads_to_periapts.mmpWoundHealRateMult() != 2) ++bad;
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
