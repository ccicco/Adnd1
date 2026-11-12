    // ---- R262: the III.E misc magic explanation
    // prose part 6 ----
    // Crystal Ball and Crystal Hypnosis Ball,
    // part2 lines 222-283 - the prose pins,
    // completing the kMisc2 rows 11-12. The R226
    // double-asterisk pin verified correct
    // (row 11, 56-60), no off-by-one.
    {
        Miscmagic_crystal_balls miscmagic_crystal_balls;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic_crystal_balls.mmpCrystalBallDiameterInches() != 6 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingRowCount() != 8 ||
            miscmagic_crystal_balls.mmpCrystalBallViewingRowCount() != 6 ||
            miscmagic_crystal_balls.mmpCrystalBallFeatureRowCount() != 4 ||
            miscmagic_crystal_balls.mmpCrystalBallDetectClassCount() != 7 ||
            miscmagic_crystal_balls.mmpCrystalBallIntFactorCount() != 6) ++bad;
        if (miscmagic_crystal_balls.mmpCrystalBallLocatingWellKnownPct() != 100 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingKnownSlightlyPct() != 85 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingPicturedPct() != 50 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingPartPct() != 50 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingGarmentPct() != 25 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingWellInformedPct() != 25 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingSlightlyInformedPct() != 20 ||
            miscmagic_crystal_balls.mmpCrystalBallLocatingOtherPlanePct() != -25) ++bad;
        if (miscmagic_crystal_balls.mmpCrystalBallOverrunIntLoss() != 1 ||
            miscmagic_crystal_balls.mmpCrystalBallOverrunInsaneUntilHealed() != 1 ||
            miscmagic_crystal_balls.mmpCrystalBallImprovingSpellCount() != 4 ||
            miscmagic_crystal_balls.mmpCrystalBallCastThroughSpellCount() != 2 ||
            miscmagic_crystal_balls.mmpCrystalBallCastThroughChancePerLevelPct() != 5 ||
            miscmagic_crystal_balls.mmpCrystalBallSpellFunctionLevel() != 10) ++bad;
        if (miscmagic_crystal_balls.mmpCrystalBallNoticeMinInt() != 12 ||
            miscmagic_crystal_balls.mmpCrystalBallDetectPerLevelPct() != 1 ||
            miscmagic_crystal_balls.mmpCrystalBallDetectionTablePage() != 60 ||
            miscmagic_crystal_balls.mmpCrystalBallDispelDownDays() != 1 ||
            miscmagic_crystal_balls.mmpCrystalBallCheckPerRound() != 1 ||
            miscmagic_crystal_balls.mmpCrystalBallSpellUserClassCount() != 4 ||
            miscmagic_crystal_balls.mmpCrystalBallClericDevicesAllowed() != 1 ||
            miscmagic_crystal_balls.mmpCrystalBallKnowledgeNotDistance() != 1 ||
            miscmagic_crystal_balls.mmpCrystalBallTelepathyCommunicationOnly() != 1) ++bad;
        if (miscmagic_crystal_balls.mmpHypnosisBallCursed() != 1 ||
            miscmagic_crystal_balls.mmpHypnosisBallRadiatesEvil() != 0 ||
            miscmagic_crystal_balls.mmpHypnosisBallSuggestionImplanted() != 1 ||
            miscmagic_crystal_balls.mmpHypnosisBallIndistinguishable() != 1 ||
            miscmagic_crystal_balls.mmpHypnosisBallInfluencerKindCount() != 3 ||
            miscmagic_crystal_balls.mmpHypnosisBallFateCount() != 3 ||
            miscmagic_crystal_balls.mmpHypnosisBallRefereePace() != 1) ++bad;
        static const int kLocPct[8] = {
            100, 85, 50, 50, 25, 25, 20, -25,
        };
        static const int kViewMin[6] = {
            60, 30, 30, 30, 15, 10,
        };
        static const int kViewFreq[6] = {
            3, 3, 2, 1, 1, 1,
        };
        static const int kViewHi[6] = {
            100, 99, 89, 74, 49, 24,
        };
        static const int kFeatLo[4] = {
            1, 51, 76, 91,
        };
        static const int kFeatHi[4] = {
            50, 75, 90, 100,
        };
        static const int kFeatCount[4] = {
            0, 1, 2, 3,
        };
        static const int kDetPct[7] = {
            2, 6, 6, 5, 4, 1, 3,
        };
        static const int kIntPct[6] = {
            1, 3, 6, 10, 15, 21,
        };
        for (int i = 0; i < 8; ++i)
            if (miscmagic_crystal_balls.mmpCrystalBallLocatingPct(i) !=
                kLocPct[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic_crystal_balls.mmpCrystalBallViewingMinutes(i) !=
                kViewMin[i] ||
                miscmagic_crystal_balls.mmpCrystalBallViewingTimesPerDay(i) !=
                kViewFreq[i] ||
                miscmagic_crystal_balls.mmpCrystalBallViewingBandHiPct(i) !=
                kViewHi[i]) ++bad;
        for (int i = 0; i < 4; ++i)
            if (miscmagic_crystal_balls.mmpCrystalBallFeatureBandLo(i) !=
                kFeatLo[i] ||
                miscmagic_crystal_balls.mmpCrystalBallFeatureBandHi(i) !=
                kFeatHi[i] ||
                miscmagic_crystal_balls.mmpCrystalBallFeatureCountAt(i) !=
                kFeatCount[i]) ++bad;
        for (int i = 0; i < 7; ++i)
            if (miscmagic_crystal_balls.mmpCrystalBallDetectBasePct(i) !=
                kDetPct[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic_crystal_balls.mmpCrystalBallIntFactorPct(i) !=
                kIntPct[i]) ++bad;
        // the kMisc2 rows this slice completes:
        // row 11 Crystal Ball 56-60, row 12 the
        // Crystal Hypnosis Ball 61-61
        static const int kM2Lo2[2] = {
            56, 61,
        };
        static const int kM2Hi2[2] = {
            60, 61,
        };
        for (int i = 0; i < 2; ++i)
            if (miscmagic_table2_footnotes.m2RowLo(11 + i) != kM2Lo2[i] ||
                miscmagic_table2_footnotes.m2RowHi(11 + i) != kM2Hi2[i]) ++bad;
        // the class marks: both rows are (M); the
        // Cloak row 10 and the row 13 are negative
        // controls
        if (!miscmagic_table2_footnotes.m2UsableByMagicUser(11) ||
            !miscmagic_table2_footnotes.m2UsableByMagicUser(12) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(10) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(13)) ++bad;
        // the double asterisk: row 11 only, the R226
        // pin verified correct
        if (!miscmagic_table2_footnotes.m2HasFeatureAsterisk(11) ||
            miscmagic_table2_footnotes.m2HasFeatureAsterisk(10) ||
            miscmagic_table2_footnotes.m2HasFeatureAsterisk(12)) ++bad;
        // the printed ball values: 1000 xp / 5000 gp
        // base, +100 percent per additional feature -
        // clairaudience 2000/10000, ESP 3000/15000,
        // telepathy 4000/20000, cross-pinned against
        // the prose feature table
        if (miscmagic_table2_footnotes.m2CrystalBallBaseXp() != 1000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseGp() != 5000 ||
            miscmagic_table2_footnotes.m2CrystalBallFeatureBonusPct() != 100) ++bad;
        if (miscmagic_table2_footnotes.m2CrystalBallBaseXp() *
                (1 + miscmagic_crystal_balls.mmpCrystalBallFeatureCountAt(1)) !=
            2000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseGp() *
                (1 + miscmagic_crystal_balls.mmpCrystalBallFeatureCountAt(1)) !=
            10000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseXp() *
                (1 + miscmagic_crystal_balls.mmpCrystalBallFeatureCountAt(3)) !=
            4000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseGp() *
                (1 + miscmagic_crystal_balls.mmpCrystalBallFeatureCountAt(3)) !=
            20000) ++bad;
        printf("R262 misc magic prose part 6 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
