    // ---- R292: the III.E Special artifacts
    // explanation prose part 13 ----
    // The Rod of Seven Parts, part2
    // lines 1677-1707. No break absorbed -
    // the round closes on the standard
    // blank at 1707; no page seam claimed
    // (no running heads between lines 1450
    // and 1797).
    {
        int bad = 0;
        // the origin, the shattering and the parts
        if (rules::sapRodWindDukesMadeIt() != 1 ||
            rules::sapRodMadeForBattleOfPesh() != 1 ||
            rules::sapRodPeshChaosVersusLaw() != 1 ||
            rules::sapRodShatteredAtPesh() != 1 ||
            rules::sapRodNothingDestroysIt() != 1 ||
            rules::sapRodCorrectOrderSurpassingPower() != 1 ||
            rules::sapRodPartCount() != 7 ||
            rules::sapRodPartsSlightlyDifferent() != 1 ||
            rules::sapRodFirstLargestLengthDiameter() != 1 ||
            rules::sapRodSeventhSmallest() != 1 ||
            rules::sapRodNoAlonePower() != 1 ||
            rules::sapRodPartsLookLikeBatons() != 1 ||
            rules::sapRodSeventhLooksLikeWand() != 1) ++bad;
        // the senses, the teleports and the length
        if (rules::sapRodFirstSensesSecond() != 1 ||
            rules::sapRodSensingNeedsWholeThought() != 1 ||
            rules::sapRodLeadsOnlyUpward() != 1 ||
            rules::sapRodOutOfOrderTouchTeleports() != 1 ||
            rules::sapRodTeleportMinMiles() != 100 ||
            rules::sapRodTeleportMaxMiles() != 1000 ||
            rules::sapRodAssembledLengthFeet() != 5 ||
            rules::sapRodBreakupTeleportMinMiles() != 100 ||
            rules::sapRodBreakupTeleportMaxMiles() != 1200) ++bad;
        // the two teleport minimums agree at 100 miles
        if (rules::sapRodTeleportMinMiles() !=
            rules::sapRodBreakupTeleportMinMiles()) ++bad;
        // the grip, the cumulation and the breakup risk
        if (rules::sapRodThreeSectionsGripLock() != 1 ||
            rules::sapRodPartPowersCumulative() != 1 ||
            rules::sapRodFullPowersNeedAllParts() != 1 ||
            rules::sapRodCannotBeDisassembled() != 1 ||
            rules::sapRodPrimeRiskDenominator() != 20 ||
            rules::sapRodPrimeRiskPercent() != 5 ||
            rules::sapRodOutOfOrderNotCumulative() != 1 ||
            rules::sapRodLastPieceJoinedActive() != 1 ||
            rules::sapRodInOrderCumulative() != 1) ++bad;
        // the assembly powers table
        if (rules::sapRodAssemblyRowCount() != 6 ||
            rules::sapRodAssemblyUseTotal() != 6) ++bad;
        static const int kT[6] = {
            3, 1, 1, 4, 2, 6,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapRodJointTable(i) != kT[i]) ++bad;
        static const int kU[6] = {
            1, 1, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapRodJointUseCount(i) != kU[i]) ++bad;
        if (rules::sapRodJointUseCount(0) +
            rules::sapRodJointUseCount(1) +
            rules::sapRodJointUseCount(2) +
            rules::sapRodJointUseCount(3) +
            rules::sapRodJointUseCount(4) +
            rules::sapRodJointUseCount(5) !=
            rules::sapRodAssemblyUseTotal()) ++bad;
        // the complete rod powers
        if (rules::sapRodCompleteUseTotal() != 7 ||
            rules::sapRodCompleteOrderQuirk() != 1 ||
            rules::sapRodCompleteLacksTableVI() != 1) ++bad;
        static const int kC[6] = {
            1, 1, 2, 1, 2, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapRodCompleteTableUse(i) != kC[i]) ++bad;
        if (rules::sapRodCompleteTableUse(0) +
            rules::sapRodCompleteTableUse(1) +
            rules::sapRodCompleteTableUse(2) +
            rules::sapRodCompleteTableUse(3) +
            rules::sapRodCompleteTableUse(4) +
            rules::sapRodCompleteTableUse(5) !=
            rules::sapRodCompleteUseTotal()) ++bad;
        // the blank slots: 6 assembly + 7 complete = 13
        if (rules::sapRodBlankSlotCount() !=
            rules::sapRodAssemblyRowCount() +
            rules::sapRodCompleteUseTotal()) ++bad;
        if (rules::sapRodBlankSlotUnderscores() != 11) ++bad;
        // the cross-pin: the R240 sale table row 23
        // (a range row, 69-74, its price fixed)
        if (rules::saRowLo(23) != 69 ||
            rules::saRowHi(23) != 74 ||
            rules::saSaleGp(23) != 25000 ||
            rules::saSaleGpHi(23) != 0) ++bad;
        printf("R292 special artifacts prose part 13 pins audit: bad %d\n", bad);
    }
