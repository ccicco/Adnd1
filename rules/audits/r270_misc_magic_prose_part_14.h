    // ---- R270: the III.E misc magic explanation
    // prose part 14 ----
    // Incense of Obsession through the Fochlucan
    // Bandore, part2 lines 630-684 - the slice
    // pinning the kMisc3 rows 24-26.
    {
        Miscmagic_incense_of_obsession_to_fochlucan_bandore miscmagic;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic.mmpObsessionDurationHours() != 24 ||
            miscmagic.mmpObsessionPiecesMin() != 2 ||
            miscmagic.mmpObsessionPiecesMax() != 8 ||
            miscmagic.mmpObsessionBurnHours() != 1) ++bad;
        if (miscmagic.mmpIounSortCount() != 14 ||
            miscmagic.mmpIounOwnerRadiusFeet() != 3 ||
            miscmagic.mmpIounOrbitMinFeet() != 1 ||
            miscmagic.mmpIounOrbitMaxFeet() != 3 ||
            miscmagic.mmpIounFoundMin() != 1 ||
            miscmagic.mmpIounFoundMax() != 10) ++bad;
        if (miscmagic.mmpIounTableRowCount() != 15 ||
            miscmagic.mmpIounDeadRowLo() != 15 ||
            miscmagic.mmpIounDeadRowHi() != 20 ||
            miscmagic.mmpIounStatBonusPoints() != 1 ||
            miscmagic.mmpIounStatCap() != 18 ||
            miscmagic.mmpIounStatBonusRowCount() != 6) ++bad;
        // the orbit tops out at the owner radius, the
        // dead band rides the last table row
        if (miscmagic.mmpIounOrbitMaxFeet() !=
            miscmagic.mmpIounOwnerRadiusFeet() ||
            miscmagic.mmpIounDeadRowLo() !=
            miscmagic.mmpIounRowRollLo(14) ||
            miscmagic.mmpIounDeadRowHi() !=
            miscmagic.mmpIounRowRollHi(14)) ++bad;
        if (miscmagic.mmpIounLevelGainLevels() != 1 ||
            miscmagic.mmpIounRegenHpPerTurn() != 1 ||
            miscmagic.mmpIounPurpleStoreMin() != 2 ||
            miscmagic.mmpIounPurpleStoreMax() != 12 ||
            miscmagic.mmpIounRoseProtectionBonus() != 1) ++bad;
        if (miscmagic.mmpIounGrayPsionicBonus() != 10 ||
            miscmagic.mmpIounGrayPsionicCap() != 50 ||
            miscmagic.mmpIounHpToDestroy() != 10 ||
            miscmagic.mmpIounSaveBonus() != 3 ||
            miscmagic.mmpIounAttackAc() != 4) ++bad;
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
            if (miscmagic.mmpIounRowRollLo(i) != kRlo[i] ||
                miscmagic.mmpIounRowRollHi(i) != kRhi[i] ||
                miscmagic.mmpIounRowAddsStat(i) !=
                kStat[i] ||
                miscmagic.mmpIounRowAbsorbMaxLevel(i) !=
                kAbs[i] ||
                miscmagic.mmpIounRowBurnoutMin(i) !=
                kBolo[i] ||
                miscmagic.mmpIounRowBurnoutMax(i) !=
                kBohi[i]) ++bad;
        // the property dice run 1-20 without gaps
        for (int i = 0; i < 14; ++i)
            if (miscmagic.mmpIounRowRollLo(i + 1) !=
                miscmagic.mmpIounRowRollHi(i) +
                1) ++bad;
        if (miscmagic.mmpIounRowRollLo(0) != 1 ||
            miscmagic.mmpIounRowRollHi(14) != 20) ++bad;
        // the six stat stones are rolls 1-6
        if (miscmagic.mmpIounStatBonusRowCount() !=
            miscmagic.mmpIounRowRollHi(5)) ++bad;
        if (miscmagic.mmpBardInstrumentCount() != 7 ||
            miscmagic.mmpFochlucanLowestFaeriePct() != 50 ||
            miscmagic.mmpFochlucanLowestReversePct() !=
            10) ++bad;
        // the qualified base equals the lowest chance,
        // the reverse fades 1 percent per level
        if (miscmagic.mmpFochlucanFaerieBasePct() !=
            miscmagic.mmpFochlucanLowestFaeriePct() ||
            miscmagic.mmpFochlucanReverseReductionPerLevelPct()
            != 1) ++bad;
        if (miscmagic.mmpFochlucanStringCount() != 3 ||
            miscmagic.mmpFochlucanSongCount() != 4 ||
            miscmagic.mmpFochlucanCharmBonusPct() != 10 ||
            miscmagic.mmpFochlucanEntanglePerDay() != 1 ||
            miscmagic.mmpFochlucanShillelaghPerDay() != 1 ||
            miscmagic.mmpFochlucanSpeakAnimalsPerDay() !=
            1) ++bad;
        if (miscmagic.mmpFochlucanLowestSongWorkPct() != 30 ||
            miscmagic.mmpFochlucanLowestSongFailPct() != 70 ||
            miscmagic.mmpFochlucanLowestFailDamageMin() != 2 ||
            miscmagic.mmpFochlucanLowestFailDamageMax() !=
            8) ++bad;
        // the 1st level attempt splits 30 and 70
        if (miscmagic.mmpFochlucanLowestSongWorkPct() +
            miscmagic.mmpFochlucanLowestSongFailPct() !=
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
            if (miscmagic_table3_footnotes.m3RowLo(24 + i) != kLo[i] ||
                miscmagic_table3_footnotes.m3RowHi(24 + i) != kHi[i] ||
                miscmagic_table3_footnotes.m3StarCount(24 + i) != kSt[i]) ++bad;
        for (int i = 0; i < 3; ++i)
            if (miscmagic_table3_footnotes.m3UsableByCleric(24 + i) != kCm[i] ||
                miscmagic_table3_footnotes.m3UsableByFighter(24 + i) !=
                kFm[i] ||
                miscmagic_table3_footnotes.m3UsableByThief(24 + i) != kTm[i] ||
                miscmagic_table3_footnotes.m3IsPerFacetValued(24 + i)) ++bad;
        // the per-stone and per-level asterisk bases
        if (miscmagic_table3_footnotes.m3IounPerStoneXp() != 300 ||
            miscmagic_table3_footnotes.m3IounPerStoneGp() != 5000 ||
            miscmagic_table3_footnotes.m3InstrumentBaseXp() != 1000 ||
            miscmagic_table3_footnotes.m3InstrumentBaseGp() != 5000) ++bad;
        printf("R270 misc magic prose part 14 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
