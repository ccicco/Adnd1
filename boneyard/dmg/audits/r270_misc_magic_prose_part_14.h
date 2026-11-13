    // ---- R270: the III.E misc magic explanation
    // prose part 14 ----
    // Incense of Obsession through the Fochlucan
    // Bandore, part2 lines 630-684 - the slice
    // pinning the kMisc3 rows 24-26.
    {
        int bad = 0;
        if (rules::mmpObsessionDurationHours() != 24 ||
            rules::mmpObsessionPiecesMin() != 2 ||
            rules::mmpObsessionPiecesMax() != 8 ||
            rules::mmpObsessionBurnHours() != 1) ++bad;
        if (rules::mmpIounSortCount() != 14 ||
            rules::mmpIounOwnerRadiusFeet() != 3 ||
            rules::mmpIounOrbitMinFeet() != 1 ||
            rules::mmpIounOrbitMaxFeet() != 3 ||
            rules::mmpIounFoundMin() != 1 ||
            rules::mmpIounFoundMax() != 10) ++bad;
        if (rules::mmpIounTableRowCount() != 15 ||
            rules::mmpIounDeadRowLo() != 15 ||
            rules::mmpIounDeadRowHi() != 20 ||
            rules::mmpIounStatBonusPoints() != 1 ||
            rules::mmpIounStatCap() != 18 ||
            rules::mmpIounStatBonusRowCount() != 6) ++bad;
        // the orbit tops out at the owner radius, the
        // dead band rides the last table row
        if (rules::mmpIounOrbitMaxFeet() !=
            rules::mmpIounOwnerRadiusFeet() ||
            rules::mmpIounDeadRowLo() !=
            rules::mmpIounRowRollLo(14) ||
            rules::mmpIounDeadRowHi() !=
            rules::mmpIounRowRollHi(14)) ++bad;
        if (rules::mmpIounLevelGainLevels() != 1 ||
            rules::mmpIounRegenHpPerTurn() != 1 ||
            rules::mmpIounPurpleStoreMin() != 2 ||
            rules::mmpIounPurpleStoreMax() != 12 ||
            rules::mmpIounRoseProtectionBonus() != 1) ++bad;
        if (rules::mmpIounGrayPsionicBonus() != 10 ||
            rules::mmpIounGrayPsionicCap() != 50 ||
            rules::mmpIounHpToDestroy() != 10 ||
            rules::mmpIounSaveBonus() != 3 ||
            rules::mmpIounAttackAc() != 4) ++bad;
        // the stone property table against static twins
        static const int kRlo[15] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 13, 14, 15,
        };
        static const int kRhi[15] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 13, 14, 20,
        };
        static const int kStat[15] = {
            1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
        };
        static const int kAbs[15] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            4, 8, 0, 0, 0,
        };
        static const int kBolo[15] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            10, 20, 0, 0, 0,
        };
        static const int kBohi[15] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            40, 80, 0, 0, 0,
        };
        for (int i = 0; i < 15; ++i)
            if (rules::mmpIounRowRollLo(i) != kRlo[i] ||
                rules::mmpIounRowRollHi(i) != kRhi[i] ||
                rules::mmpIounRowAddsStat(i) !=
                kStat[i] ||
                rules::mmpIounRowAbsorbMaxLevel(i) !=
                kAbs[i] ||
                rules::mmpIounRowBurnoutMin(i) !=
                kBolo[i] ||
                rules::mmpIounRowBurnoutMax(i) !=
                kBohi[i]) ++bad;
        // the property dice run 1-20 without gaps
        for (int i = 0; i < 14; ++i)
            if (rules::mmpIounRowRollLo(i + 1) !=
                rules::mmpIounRowRollHi(i) +
                1) ++bad;
        if (rules::mmpIounRowRollLo(0) != 1 ||
            rules::mmpIounRowRollHi(14) != 20) ++bad;
        // the six stat stones are rolls 1-6
        if (rules::mmpIounStatBonusRowCount() !=
            rules::mmpIounRowRollHi(5)) ++bad;
        if (rules::mmpBardInstrumentCount() != 7 ||
            rules::mmpFochlucanLowestFaeriePct() != 50 ||
            rules::mmpFochlucanLowestReversePct() !=
            10) ++bad;
        // the qualified base equals the lowest chance,
        // the reverse fades 1 percent per level
        if (rules::mmpFochlucanFaerieBasePct() !=
            rules::mmpFochlucanLowestFaeriePct() ||
            rules::mmpFochlucanReverseReductionPerLevelPct()
            != 1) ++bad;
        if (rules::mmpFochlucanStringCount() != 3 ||
            rules::mmpFochlucanSongCount() != 4 ||
            rules::mmpFochlucanCharmBonusPct() != 10 ||
            rules::mmpFochlucanEntanglePerDay() != 1 ||
            rules::mmpFochlucanShillelaghPerDay() != 1 ||
            rules::mmpFochlucanSpeakAnimalsPerDay() !=
            1) ++bad;
        if (rules::mmpFochlucanLowestSongWorkPct() != 30 ||
            rules::mmpFochlucanLowestSongFailPct() != 70 ||
            rules::mmpFochlucanLowestFailDamageMin() != 2 ||
            rules::mmpFochlucanLowestFailDamageMax() !=
            8) ++bad;
        // the 1st level attempt splits 30 and 70
        if (rules::mmpFochlucanLowestSongWorkPct() +
            rules::mmpFochlucanLowestSongFailPct() !=
            100) ++bad;
        // the kMisc3 rows this slice pins: 24-26, the
        // (C) mark on row 24, the triple asterisk on
        // row 25, the quadruple asterisk on row 26
        static const int kLo[3] = {
            71, 72, 73,
        };
        static const int kHi[3] = {
            71, 72, 78,
        };
        static const int kCm[3] = {
            1, 0, 0,
        };
        static const int kFm[3] = {
            0, 0, 0,
        };
        static const int kTm[3] = {
            0, 0, 0,
        };
        static const int kSt[3] = {
            0, 3, 4,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::m3RowLo(24 + i) != kLo[i] ||
                rules::m3RowHi(24 + i) != kHi[i] ||
                rules::m3StarCount(24 + i) != kSt[i]) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::m3UsableByCleric(24 + i) != kCm[i] ||
                rules::m3UsableByFighter(24 + i) !=
                kFm[i] ||
                rules::m3UsableByThief(24 + i) != kTm[i] ||
                rules::m3IsPerFacetValued(24 + i)) ++bad;
        // the per-stone and per-level asterisk bases
        if (rules::m3IounPerStoneXp() != 300 ||
            rules::m3IounPerStoneGp() != 5000 ||
            rules::m3InstrumentBaseXp() != 1000 ||
            rules::m3InstrumentBaseGp() != 5000) ++bad;
        printf("R270 misc magic prose part 14 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
