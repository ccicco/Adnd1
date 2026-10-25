    // ---- R262: the III.E misc magic explanation
    // prose part 6 ----
    // Crystal Ball and Crystal Hypnosis Ball,
    // part2 lines 222-283 - the prose pins,
    // completing the kMisc2 rows 11-12. The R226
    // double-asterisk pin verified correct
    // (row 11, 56-60), no off-by-one.
    {
        int bad = 0;
        if (rules::mmpCrystalBallDiameterInches() != 6 ||
            rules::mmpCrystalBallLocatingRowCount() != 8 ||
            rules::mmpCrystalBallViewingRowCount() != 6 ||
            rules::mmpCrystalBallFeatureRowCount() != 4 ||
            rules::mmpCrystalBallDetectClassCount() != 7 ||
            rules::mmpCrystalBallIntFactorCount() != 6) ++bad;
        if (rules::mmpCrystalBallLocatingWellKnownPct() != 100 ||
            rules::mmpCrystalBallLocatingKnownSlightlyPct() != 85 ||
            rules::mmpCrystalBallLocatingPicturedPct() != 50 ||
            rules::mmpCrystalBallLocatingPartPct() != 50 ||
            rules::mmpCrystalBallLocatingGarmentPct() != 25 ||
            rules::mmpCrystalBallLocatingWellInformedPct() != 25 ||
            rules::mmpCrystalBallLocatingSlightlyInformedPct() != 20 ||
            rules::mmpCrystalBallLocatingOtherPlanePct() != -25) ++bad;
        if (rules::mmpCrystalBallOverrunIntLoss() != 1 ||
            rules::mmpCrystalBallOverrunInsaneUntilHealed() != 1 ||
            rules::mmpCrystalBallImprovingSpellCount() != 4 ||
            rules::mmpCrystalBallCastThroughSpellCount() != 2 ||
            rules::mmpCrystalBallCastThroughChancePerLevelPct() != 5 ||
            rules::mmpCrystalBallSpellFunctionLevel() != 10) ++bad;
        if (rules::mmpCrystalBallNoticeMinInt() != 12 ||
            rules::mmpCrystalBallDetectPerLevelPct() != 1 ||
            rules::mmpCrystalBallDetectionTablePage() != 60 ||
            rules::mmpCrystalBallDispelDownDays() != 1 ||
            rules::mmpCrystalBallCheckPerRound() != 1 ||
            rules::mmpCrystalBallSpellUserClassCount() != 4 ||
            rules::mmpCrystalBallClericDevicesAllowed() != 1 ||
            rules::mmpCrystalBallKnowledgeNotDistance() != 1 ||
            rules::mmpCrystalBallTelepathyCommunicationOnly() != 1) ++bad;
        if (rules::mmpHypnosisBallCursed() != 1 ||
            rules::mmpHypnosisBallRadiatesEvil() != 0 ||
            rules::mmpHypnosisBallSuggestionImplanted() != 1 ||
            rules::mmpHypnosisBallIndistinguishable() != 1 ||
            rules::mmpHypnosisBallInfluencerKindCount() != 3 ||
            rules::mmpHypnosisBallFateCount() != 3 ||
            rules::mmpHypnosisBallRefereePace() != 1) ++bad;
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
            if (rules::mmpCrystalBallLocatingPct(i) !=
                kLocPct[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::mmpCrystalBallViewingMinutes(i) !=
                kViewMin[i] ||
                rules::mmpCrystalBallViewingTimesPerDay(i) !=
                kViewFreq[i] ||
                rules::mmpCrystalBallViewingBandHiPct(i) !=
                kViewHi[i]) ++bad;
        for (int i = 0; i < 4; ++i)
            if (rules::mmpCrystalBallFeatureBandLo(i) !=
                kFeatLo[i] ||
                rules::mmpCrystalBallFeatureBandHi(i) !=
                kFeatHi[i] ||
                rules::mmpCrystalBallFeatureCountAt(i) !=
                kFeatCount[i]) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::mmpCrystalBallDetectBasePct(i) !=
                kDetPct[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::mmpCrystalBallIntFactorPct(i) !=
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
            if (rules::m2RowLo(11 + i) != kM2Lo2[i] ||
                rules::m2RowHi(11 + i) != kM2Hi2[i]) ++bad;
        // the class marks: both rows are (M); the
        // Cloak row 10 and the row 13 are negative
        // controls
        if (!rules::m2UsableByMagicUser(11) ||
            !rules::m2UsableByMagicUser(12) ||
            rules::m2UsableByMagicUser(10) ||
            rules::m2UsableByMagicUser(13)) ++bad;
        // the double asterisk: row 11 only, the R226
        // pin verified correct
        if (!rules::m2HasFeatureAsterisk(11) ||
            rules::m2HasFeatureAsterisk(10) ||
            rules::m2HasFeatureAsterisk(12)) ++bad;
        // the printed ball values: 1000 xp / 5000 gp
        // base, +100 percent per additional feature -
        // clairaudience 2000/10000, ESP 3000/15000,
        // telepathy 4000/20000, cross-pinned against
        // the prose feature table
        if (rules::m2CrystalBallBaseXp() != 1000 ||
            rules::m2CrystalBallBaseGp() != 5000 ||
            rules::m2CrystalBallFeatureBonusPct() != 100) ++bad;
        if (rules::m2CrystalBallBaseXp() *
                (1 + rules::mmpCrystalBallFeatureCountAt(1)) !=
            2000 ||
            rules::m2CrystalBallBaseGp() *
                (1 + rules::mmpCrystalBallFeatureCountAt(1)) !=
            10000 ||
            rules::m2CrystalBallBaseXp() *
                (1 + rules::mmpCrystalBallFeatureCountAt(3)) !=
            4000 ||
            rules::m2CrystalBallBaseGp() *
                (1 + rules::mmpCrystalBallFeatureCountAt(3)) !=
            20000) ++bad;
        printf("R262 misc magic prose part 6 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
