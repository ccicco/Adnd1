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
        int bad = 0;
        // the necklace of prayer beads scalars
        if (rules::mmpBeadStoneMin() != 25 ||
            rules::mmpBeadStoneMax() != 30 ||
            rules::mmpBeadSemiPreciousPct() != 60 ||
            rules::mmpBeadFancyPct() != 40 ||
            rules::mmpBeadPetitionBonusPct() != 25 ||
            rules::mmpBeadSpecialMin() != 3 ||
            rules::mmpBeadSpecialMax() != 6 ||
            rules::mmpBeadGemBaseGp() != 1000 ||
            rules::mmpBeadUsesPerDay() != 1 ||
            rules::mmpBeadKarmaLevels() != 4 ||
            rules::mmpBeadSummonsPct() != 90) ++bad;
        // the stone split sums to the full necklace
        if (rules::mmpBeadSemiPreciousPct() +
            rules::mmpBeadFancyPct() != 100) ++bad;
        // the bead type table against static twins
        static const int kBlo[6] = {
            1, 6, 11, 16, 18, 19,
        };
        static const int kBhi[6] = {
            5, 10, 15, 17, 18, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::mmpBeadRowLo(i) != kBlo[i] ||
                rules::mmpBeadRowHi(i) != kBhi[i]) ++bad;
        // the bead die bands tile 1-20 without gaps
        for (int i = 0; i < 5; ++i)
            if (rules::mmpBeadRowLo(i + 1) !=
                rules::mmpBeadRowHi(i) + 1) ++bad;
        if (rules::mmpBeadRowLo(0) != 1 ||
            rules::mmpBeadRowHi(5) != 20) ++bad;
        // the necklace of strangulation
        if (rules::mmpStrangleDamagePerRound() != 6) ++bad;
        // the net of entrapment
        if (rules::mmpEntrapMinStrength() != 20 ||
            rules::mmpEntrapSizeFeet() != 10 ||
            rules::mmpEntrapMeshQuarterFeet() != 1 ||
            rules::mmpEntrapThrowFeet() != 20 ||
            rules::mmpEntrapCloseCubeFeet() != 5) ++bad;
        // AC -10 against cutting blows
        if (rules::mmpEntrapCutAc() + 10 != 0) ++bad;
        // the net of snaring
        if (rules::mmpSnareRangeInches() != 3) ++bad;
        // the marvelous pigments
        if (rules::mmpPigPotCubicFeet() != 1000 ||
            rules::mmpPigDepictSquareFeet() != 100 ||
            rules::mmpPigContainersMin() != 1 ||
            rules::mmpPigContainersMax() != 4 ||
            rules::mmpPigInstrumentFeet() != 1 ||
            rules::mmpPigDepictTurns() != 1) ++bad;
        // the pearl of power scalars
        if (rules::mmpPowerRecallPerDay() != 1 ||
            rules::mmpPowerSpellsRecalled() != 1 ||
            rules::mmpPowerReverseOneIn() != 20 ||
            rules::mmpPowerDoubleMin() != 2 ||
            rules::mmpPowerDoubleMaxLevel() != 6 ||
            rules::mmpPowerDoubleDieSides() != 6) ++bad;
        // the 00 row d6 equals the 1st to 6th ladder
        if (rules::mmpPowerDoubleDieSides() !=
            rules::mmpPowerDoubleMaxLevel()) ++bad;
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
            if (rules::mmpPowerRowLo(i) != kPlo[i] ||
                rules::mmpPowerRowHi(i) != kPhi[i] ||
                rules::mmpPowerSpellLevel(i) !=
                kLvl[i]) ++bad;
        // the pearl die bands tile 1-100 without gaps
        for (int i = 0; i < 9; ++i)
            if (rules::mmpPowerRowLo(i + 1) !=
                rules::mmpPowerRowHi(i) + 1) ++bad;
        if (rules::mmpPowerRowLo(0) != 1 ||
            rules::mmpPowerRowHi(9) != 100) ++bad;
        // the spell levels ascend first to ninth
        for (int i = 0; i < 8; ++i)
            if (rules::mmpPowerSpellLevel(i + 1) !=
                rules::mmpPowerSpellLevel(i) + 1) ++bad;
        // the 00 row carries the double-spell mark
        if (rules::mmpPowerSpellLevel(9) != 0) ++bad;
        // the pearl of wisdom
        if (rules::mmpWisdomGain() != 1 ||
            rules::mmpWisdomMonths() != 1 ||
            rules::mmpWisdomDays() != 30 ||
            rules::mmpWisdomReverseOneIn() != 20) ++bad;
        // the month expires at the printed 30 days
        if (rules::mmpWisdomMonths() * 30 !=
            rules::mmpWisdomDays()) ++bad;
        // the periapt of foul rotting
        if (rules::mmpRotAbilityLossPerWeek() != 1 ||
            rules::mmpRotStartWeek() != 1 ||
            rules::mmpRotAbilityCount() != 3 ||
            rules::mmpRotDeathScore() != 0) ++bad;
        // the periapt of proof against poison
        if (rules::mmpPoisonSavePctPerPlus() != 10) ++bad;
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
            if (rules::mmpPoisonRowLo(i) != kOlo[i] ||
                rules::mmpPoisonRowHi(i) != kOhi[i] ||
                rules::mmpPoisonPlus(i) != kOpl[i]) ++bad;
        // the periapt bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (rules::mmpPoisonRowLo(i + 1) !=
                rules::mmpPoisonRowHi(i) + 1) ++bad;
        if (rules::mmpPoisonRowLo(0) != 1 ||
            rules::mmpPoisonRowHi(3) != 20) ++bad;
        // the periapt of wound closure
        if (rules::mmpWoundHealRateMult() != 2) ++bad;
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
            if (rules::m4RowLo(19 + i) != kRlo[i] ||
                rules::m4RowHi(19 + i) != kRhi[i]) ++bad;
        if (rules::m4StarCount(19) != 2 ||
            rules::m4StarCount(23) != 3 ||
            rules::m4StarCount(24) != 4 ||
            rules::m4RowCount() != 36) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 19 && i != 23 && i != 24 &&
                rules::m4StarCount(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (rules::m4IsDualValued(i) != 0) ++bad;
        if (rules::m4UsableByCleric(19) != 1 ||
            rules::m4UsableByCleric(21) != 1 ||
            rules::m4UsableByCleric(22) != 1 ||
            rules::m4UsableByCleric(25) != 1 ||
            rules::m4UsableByFighter(21) != 1 ||
            rules::m4UsableByFighter(22) != 1 ||
            rules::m4UsableByThief(21) != 1 ||
            rules::m4UsableByThief(22) != 1 ||
            rules::m4UsableByMagicUser(24) != 1) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 19 && i != 21 && i != 22 &&
                i != 25 &&
                rules::m4UsableByCleric(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 21 && i != 22 &&
                rules::m4UsableByFighter(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 24 &&
                rules::m4UsableByMagicUser(i) != 0) ++bad;
        for (int i = 19; i < 30; ++i)
            if (i != 21 && i != 22 &&
                rules::m4UsableByThief(i) != 0) ++bad;
        // the engine footnote helpers
        if (rules::m4BeadPerSpecialXp() != 500 ||
            rules::m4BeadPerSpecialGp() != 3000 ||
            rules::m4PigmentsPerPotXp() != 500 ||
            rules::m4PigmentsPerPotGp() != 3000 ||
            rules::m4PearlPerSpellLevelXp() != 200 ||
            rules::m4PearlPerSpellLevelGp() != 2000 ||
            rules::m4ClericCount() != 8 ||
            rules::m4FighterCount() != 4 ||
            rules::m4MagicUserCount() != 6 ||
            rules::m4ThiefCount() != 3) ++bad;
        printf("R275 misc magic prose part 19 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
