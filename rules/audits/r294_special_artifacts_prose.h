    // ---- R294: the III.E Special artifacts
    // explanation prose part 15 ----
    // The Teeth of Dahlver-Nar, part2
    // lines 1744-1781. No break absorbed
    // - the round closes on the standard
    // blank at 1781; no page seam claimed
    // (no running heads between lines 1450
    // and 1797).
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the legend and emplacement scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothHistoriesSilent() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothGodsGavePowers() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothRelicsAreTeeth() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothEachToothHasPower() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothCount() != 32 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothBenefitLevels() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothQuarterCount() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothHalfCount() != 16 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothGraftsInMouth() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothLikeMissingTooth() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothNeverRemoved() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothRemovalOnlyByDemise() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothPowersCumulative() != 1) ++bad;
        // the tooth table counts and blanks
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothUseTotal() != 32 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableOneCount() != 21 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableTwoCount() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableThreeCount() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableFourCount() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableFiveCount() != 0 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableSixCount() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothLoneFourTooth() != 21 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothFirstSixTooth() != 7 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSecondSixTooth() != 14 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothUnderscoreRunLen() != 14 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothBlankSlotCount() != 51 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothXSignCount() != 51) ++bad;
        static const int kT[6] = {
            21, 4, 4, 1, 0, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(i) != kT[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothUseTotal()) ++bad;
        // the set table counts
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetPairRows() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetQuarterRows() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetHalfRepeatQuarters() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetFiveRows() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetLeftTwoCount() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetLeftFiveCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightThreeCount() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightFourCount() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightSixCount() != 2) ++bad;
        static const int kS[6] = {
            0, 0, 4, 2, 0, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightUse(i) != kS[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightUse(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightUse(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightUse(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightUse(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightUse(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightUse(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetPairRows()) ++bad;
        // the identities the tables carry
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapToothXSignCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothBlankSlotCount() ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothBlankSlotCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothUseTotal() +
            2 * specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetPairRows() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetFiveRows() ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetLeftTwoCount() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetLeftFiveCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetPairRows() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetFiveRows() ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightThreeCount() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightFourCount() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetRightSixCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothSetPairRows() ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(0) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableOneCount() ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(3) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableFourCount() ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableUse(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothTableSixCount() ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapToothLoneFourTooth() != 21) ++bad;
        // the cross-pin: the R240 sale row 26
        // (a per-tooth price, a 93-98 range row)
        if (specart.saRowLo(26) != 93 ||
            specart.saRowHi(26) != 98 ||
            specart.saSaleGp(26) != 5000 ||
            specart.saSaleGpHi(26) != 0) ++bad;
        printf("R294 special artifacts prose part 15 pins audit: bad %d\n", bad);
    }
