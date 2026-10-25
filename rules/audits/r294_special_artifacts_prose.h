    // ---- R294: the III.E Special artifacts
    // explanation prose part 15 ----
    // The Teeth of Dahlver-Nar, part2
    // lines 1744-1781. No break absorbed
    // - the round closes on the standard
    // blank at 1781; no page seam claimed
    // (no running heads between lines 1450
    // and 1797).
    {
        int bad = 0;
        // the legend and emplacement scalars
        if (rules::sapToothHistoriesSilent() != 1 ||
            rules::sapToothGodsGavePowers() != 1 ||
            rules::sapToothRelicsAreTeeth() != 1 ||
            rules::sapToothEachToothHasPower() != 1 ||
            rules::sapToothCount() != 32 ||
            rules::sapToothBenefitLevels() != 3 ||
            rules::sapToothQuarterCount() != 8 ||
            rules::sapToothHalfCount() != 16 ||
            rules::sapToothGraftsInMouth() != 1 ||
            rules::sapToothLikeMissingTooth() != 1 ||
            rules::sapToothNeverRemoved() != 1 ||
            rules::sapToothRemovalOnlyByDemise() != 1 ||
            rules::sapToothPowersCumulative() != 1) ++bad;
        // the tooth table counts and blanks
        if (rules::sapToothUseTotal() != 32 ||
            rules::sapToothTableOneCount() != 21 ||
            rules::sapToothTableTwoCount() != 4 ||
            rules::sapToothTableThreeCount() != 4 ||
            rules::sapToothTableFourCount() != 1 ||
            rules::sapToothTableFiveCount() != 0 ||
            rules::sapToothTableSixCount() != 2 ||
            rules::sapToothLoneFourTooth() != 21 ||
            rules::sapToothFirstSixTooth() != 7 ||
            rules::sapToothSecondSixTooth() != 14 ||
            rules::sapToothUnderscoreRunLen() != 14 ||
            rules::sapToothBlankSlotCount() != 51 ||
            rules::sapToothXSignCount() != 51) ++bad;
        static const int kT[6] = {
            21, 4, 4, 1, 0, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapToothTableUse(i) != kT[i]) ++bad;
        if (rules::sapToothTableUse(0) +
            rules::sapToothTableUse(1) +
            rules::sapToothTableUse(2) +
            rules::sapToothTableUse(3) +
            rules::sapToothTableUse(4) +
            rules::sapToothTableUse(5) !=
            rules::sapToothUseTotal()) ++bad;
        // the set table counts
        if (rules::sapToothSetPairRows() != 8 ||
            rules::sapToothSetQuarterRows() != 4 ||
            rules::sapToothSetHalfRepeatQuarters() != 1 ||
            rules::sapToothSetFiveRows() != 3 ||
            rules::sapToothSetLeftTwoCount() != 8 ||
            rules::sapToothSetLeftFiveCount() != 3 ||
            rules::sapToothSetRightThreeCount() != 4 ||
            rules::sapToothSetRightFourCount() != 2 ||
            rules::sapToothSetRightSixCount() != 2) ++bad;
        static const int kS[6] = {
            0, 0, 4, 2, 0, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapToothSetRightUse(i) != kS[i]) ++bad;
        if (rules::sapToothSetRightUse(0) +
            rules::sapToothSetRightUse(1) +
            rules::sapToothSetRightUse(2) +
            rules::sapToothSetRightUse(3) +
            rules::sapToothSetRightUse(4) +
            rules::sapToothSetRightUse(5) !=
            rules::sapToothSetPairRows()) ++bad;
        // the identities the tables carry
        if (rules::sapToothXSignCount() !=
            rules::sapToothBlankSlotCount() ||
            rules::sapToothBlankSlotCount() !=
            rules::sapToothUseTotal() +
            2 * rules::sapToothSetPairRows() +
            rules::sapToothSetFiveRows() ||
            rules::sapToothSetLeftTwoCount() +
            rules::sapToothSetLeftFiveCount() !=
            rules::sapToothSetPairRows() +
            rules::sapToothSetFiveRows() ||
            rules::sapToothSetRightThreeCount() +
            rules::sapToothSetRightFourCount() +
            rules::sapToothSetRightSixCount() !=
            rules::sapToothSetPairRows() ||
            rules::sapToothTableUse(0) !=
            rules::sapToothTableOneCount() ||
            rules::sapToothTableUse(3) !=
            rules::sapToothTableFourCount() ||
            rules::sapToothTableUse(5) !=
            rules::sapToothTableSixCount() ||
            rules::sapToothLoneFourTooth() != 21) ++bad;
        // the cross-pin: the R240 sale row 26
        // (a per-tooth price, a 93-98 range row)
        if (rules::saRowLo(26) != 93 ||
            rules::saRowHi(26) != 98 ||
            rules::saSaleGp(26) != 5000 ||
            rules::saSaleGpHi(26) != 0) ++bad;
        printf("R294 special artifacts prose part 15 pins audit: bad %d\n", bad);
    }
