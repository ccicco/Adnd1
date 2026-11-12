    // ---- R262: the III.E misc magic explanation
    // prose part 6 ----
    // Crystal Ball and Crystal Hypnosis Ball,
    // part2 lines 222-283 - the prose pins,
    // completing the kMisc2 rows 11-12. The R226
    // double-asterisk pin verified correct
    // (row 11, 56-60), no off-by-one.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic.mmpCrystalBallDiameterInches() != 6 ||
            miscmagic.mmpCrystalBallLocatingRowCount() != 8 ||
            miscmagic.mmpCrystalBallViewingRowCount() != 6 ||
            miscmagic.mmpCrystalBallFeatureRowCount() != 4 ||
            miscmagic.mmpCrystalBallDetectClassCount() != 7 ||
            miscmagic.mmpCrystalBallIntFactorCount() != 6) ++bad;
        if (miscmagic.mmpCrystalBallLocatingWellKnownPct() != 100 ||
            miscmagic.mmpCrystalBallLocatingKnownSlightlyPct() != 85 ||
            miscmagic.mmpCrystalBallLocatingPicturedPct() != 50 ||
            miscmagic.mmpCrystalBallLocatingPartPct() != 50 ||
            miscmagic.mmpCrystalBallLocatingGarmentPct() != 25 ||
            miscmagic.mmpCrystalBallLocatingWellInformedPct() != 25 ||
            miscmagic.mmpCrystalBallLocatingSlightlyInformedPct() != 20 ||
            miscmagic.mmpCrystalBallLocatingOtherPlanePct() != -25) ++bad;
        if (miscmagic.mmpCrystalBallOverrunIntLoss() != 1 ||
            miscmagic.mmpCrystalBallOverrunInsaneUntilHealed() != 1 ||
            miscmagic.mmpCrystalBallImprovingSpellCount() != 4 ||
            miscmagic.mmpCrystalBallCastThroughSpellCount() != 2 ||
            miscmagic.mmpCrystalBallCastThroughChancePerLevelPct() != 5 ||
            miscmagic.mmpCrystalBallSpellFunctionLevel() != 10) ++bad;
        if (miscmagic.mmpCrystalBallNoticeMinInt() != 12 ||
            miscmagic.mmpCrystalBallDetectPerLevelPct() != 1 ||
            miscmagic.mmpCrystalBallDetectionTablePage() != 60 ||
            miscmagic.mmpCrystalBallDispelDownDays() != 1 ||
            miscmagic.mmpCrystalBallCheckPerRound() != 1 ||
            miscmagic.mmpCrystalBallSpellUserClassCount() != 4 ||
            miscmagic.mmpCrystalBallClericDevicesAllowed() != 1 ||
            miscmagic.mmpCrystalBallKnowledgeNotDistance() != 1 ||
            miscmagic.mmpCrystalBallTelepathyCommunicationOnly() != 1) ++bad;
        if (miscmagic.mmpHypnosisBallCursed() != 1 ||
            miscmagic.mmpHypnosisBallRadiatesEvil() != 0 ||
            miscmagic.mmpHypnosisBallSuggestionImplanted() != 1 ||
            miscmagic.mmpHypnosisBallIndistinguishable() != 1 ||
            miscmagic.mmpHypnosisBallInfluencerKindCount() != 3 ||
            miscmagic.mmpHypnosisBallFateCount() != 3 ||
            miscmagic.mmpHypnosisBallRefereePace() != 1) ++bad;
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
            if (miscmagic.mmpCrystalBallLocatingPct(i) !=
                kLocPct[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpCrystalBallViewingMinutes(i) !=
                kViewMin[i] ||
                miscmagic.mmpCrystalBallViewingTimesPerDay(i) !=
                kViewFreq[i] ||
                miscmagic.mmpCrystalBallViewingBandHiPct(i) !=
                kViewHi[i]) ++bad;
        for (int i = 0; i < 4; ++i)
            if (miscmagic.mmpCrystalBallFeatureBandLo(i) !=
                kFeatLo[i] ||
                miscmagic.mmpCrystalBallFeatureBandHi(i) !=
                kFeatHi[i] ||
                miscmagic.mmpCrystalBallFeatureCountAt(i) !=
                kFeatCount[i]) ++bad;
        for (int i = 0; i < 7; ++i)
            if (miscmagic.mmpCrystalBallDetectBasePct(i) !=
                kDetPct[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpCrystalBallIntFactorPct(i) !=
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
                (1 + miscmagic.mmpCrystalBallFeatureCountAt(1)) !=
            2000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseGp() *
                (1 + miscmagic.mmpCrystalBallFeatureCountAt(1)) !=
            10000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseXp() *
                (1 + miscmagic.mmpCrystalBallFeatureCountAt(3)) !=
            4000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseGp() *
                (1 + miscmagic.mmpCrystalBallFeatureCountAt(3)) !=
            20000) ++bad;
        printf("R262 misc magic prose part 6 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
