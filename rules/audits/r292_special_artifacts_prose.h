    // ---- R292: the III.E Special artifacts
    // explanation prose part 13 ----
    // The Rod of Seven Parts, part2
    // lines 1677-1707. No break absorbed -
    // the round closes on the standard
    // blank at 1707; no page seam claimed
    // (no running heads between lines 1450
    // and 1797).
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the origin, the shattering and the parts
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodWindDukesMadeIt() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodMadeForBattleOfPesh() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodPeshChaosVersusLaw() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodShatteredAtPesh() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodNothingDestroysIt() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCorrectOrderSurpassingPower() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodPartCount() != 7 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodPartsSlightlyDifferent() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodFirstLargestLengthDiameter() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodSeventhSmallest() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodNoAlonePower() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodPartsLookLikeBatons() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodSeventhLooksLikeWand() != 1) ++bad;
        // the senses, the teleports and the length
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodFirstSensesSecond() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodSensingNeedsWholeThought() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodLeadsOnlyUpward() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodOutOfOrderTouchTeleports() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodTeleportMinMiles() != 100 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodTeleportMaxMiles() != 1000 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodAssembledLengthFeet() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodBreakupTeleportMinMiles() != 100 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodBreakupTeleportMaxMiles() != 1200) ++bad;
        // the two teleport minimums agree at 100 miles
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodTeleportMinMiles() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodBreakupTeleportMinMiles()) ++bad;
        // the grip, the cumulation and the breakup risk
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodThreeSectionsGripLock() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodPartPowersCumulative() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodFullPowersNeedAllParts() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCannotBeDisassembled() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodPrimeRiskDenominator() != 20 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodPrimeRiskPercent() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodOutOfOrderNotCumulative() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodLastPieceJoinedActive() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodInOrderCumulative() != 1) ++bad;
        // the assembly powers table
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodAssemblyRowCount() != 6 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodAssemblyUseTotal() != 6) ++bad;
        static const int kT[6] = {
            3, 1, 1, 4, 2, 6,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointTable(i) != kT[i]) ++bad;
        static const int kU[6] = {
            1, 1, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointUseCount(i) != kU[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointUseCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointUseCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointUseCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointUseCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointUseCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodJointUseCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodAssemblyUseTotal()) ++bad;
        // the complete rod powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteUseTotal() != 7 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteOrderQuirk() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteLacksTableVI() != 1) ++bad;
        static const int kC[6] = {
            1, 1, 2, 1, 2, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteTableUse(i) != kC[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteTableUse(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteTableUse(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteTableUse(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteTableUse(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteTableUse(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteTableUse(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteUseTotal()) ++bad;
        // the blank slots: 6 assembly + 7 complete = 13
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodBlankSlotCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodAssemblyRowCount() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRodCompleteUseTotal()) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRodBlankSlotUnderscores() != 11) ++bad;
        // the cross-pin: the R240 sale table row 23
        // (a range row, 69-74, its price fixed)
        if (specart.saRowLo(23) != 69 ||
            specart.saRowHi(23) != 74 ||
            specart.saSaleGp(23) != 25000 ||
            specart.saSaleGpHi(23) != 0) ++bad;
        printf("R292 special artifacts prose part 13 pins audit: bad %d\n", bad);
    }
