    // ---- R398: the UA misc magic
    // flagged holes pin audit ----
    // The clean read (pp.
    // 98-104) fills every
    // flagged hole the six
    // misc prose parts carry -
    // all 33 flags drop and
    // every part ledger runs
    // clean/0.
    {
        using namespace rules;
        int bad = 0;
            if (uammAnyLongTermHours() != 24) ++bad;
            if (!uammBocSaveAsLeatherOrBook()) ++bad;
            if (!uammBocRarelyFoundInscribed()) ++bad;
            if (!uammBocKeptByOwners()) ++bad;
            if (!uammBvtRowOneBasilisk()) ++bad;
            if (!uammBvtRowSixteenWyvern()) ++bad;
            if (uamm2DekRankRows() != 8) ++bad;
            if (uamm2DekCardsPerRank() != 4) ++bad;
            if (!uamm2DekAceIsRedDragon()) ++bad;
            if (!uamm2DekLowRowIsTwo()) ++bad;
            if (!uamm2DicBrightSilverMithral()) ++bad;
            if (!uamm2DicDarkIronAdamantite()) ++bad;
            if (uamm2DicBaseLegs() != 8) ++bad;
            if (!uamm2DdrSaveOrDestroyed()) ++bad;
            if (!uamm2DilResemblesChalkGraphite()) ++bad;
            if (!uamm2DilChangesUnderScrutiny()) ++bad;
            if (!uamm2EgdRemovalAlsoDispelMagic()) ++bad;
            if (!uamm2EgdLowIntUnderSeven()) ++bad;
            if (!uamm2EgdLowIntCovets()) ++bad;
            if (!uamm2EgrHighScoreTenthPoint()) ++bad;
            if (uamm2EgrEggsPerPointAbove18() != 10) ++bad;
            if (uamm3GemYearsBetweenFunctions() != 50) ++bad;
            if (uamm3GdkConBonus() != 1) ++bad;
            if (!uamm3GdkSavesByCon()) ++bad;
            if (uamm3GdkInfravisionIn() != 6) ++bad;
            if (!uamm3GdkDepthDetection()) ++bad;
            if (uamm3GthOpenLocksLevel() != 7) ++bad;
            if (uamm3GthPickPocketsLevel() != 5) ++bad;
            if (uamm3HdfLossRadiusMiles() != 1) ++bad;
            if (uamm3HdfLossHours() != 24) ++bad;
            if (!uamm3HdfLostIfStolen()) ++bad;
            if (!uamm3HavAppearsQuart()) ++bad;
            if (uamm3HfgDriftMinutesLo() != 2) ++bad;
            if (uamm3HfgDriftMinutesHi() != 8) ++bad;
            if (!uamm3HgdNamedGoodnessEvil()) ++bad;
            if (uamm4LulDiameterTenthsIn() != 15) ++bad;
            if (!uamm4MslSustainsAllDiets()) ++bad;
            if (uamm4PstIronLbsLo() != 50) ++bad;
            if (uamm4PstIronLbsHi() != 500) ++bad;
            if (uamm4PstLeadLbsLo() != 10) ++bad;
            if (uamm4PstLeadLbsHi() != 100) ++bad;
            if (!uamm4PzaPermanentAntiMagic()) ++bad;
            if (!uamm4PzaNonDetection()) ++bad;
            if (!uamm4PzaAttunesToOwner()) ++bad;
            if (uamm4PzaShrinksToHeightIn() != 3) ++bad;
            if (!uamm5QehNamesVariants()) ++bad;
            if (!uamm5SsmOneSideLargerPattern()) ++bad;
            if (!uamm5SstAlsoTableThreeA()) ++bad;
            if (!uamm6UsoAsDisintegrate()) ++bad;
        // ---- the cross-checks
        // ----
            // the deck is eight
            // rank rows of four
            // plus the jokers
            if (uamm2DekRankRows()
                    * uamm2DekCardsPerRank()
                    + uamm2DekJokers()
                    != uamm2DekCardCount())
                ++bad;
            // ten eggs of reason
            // raise an 18+ score
            // one point
            if (10 * uamm2EgrEggsPerPointAbove18()
                    != 100) ++bad;
            // the thievery locks
            // outrank the pockets
            if (uamm3GthOpenLocksLevel()
                    <= uamm3GthPickPocketsLevel())
                ++bad;
            // the fog drift band
            // runs 2-8 minutes
            if (uamm3HfgDriftMinutesLo()
                    >= uamm3HfgDriftMinutesHi())
                ++bad;
            // the anything tail is
            // one day - 24 hours
            if (uammAnyLongTermHours()
                    != uammAnyLongTermUseLimit() * 8) ++bad;
            // the lens diameter is
            // one and a half inches
            if (uamm4LulDiameterTenthsIn()
                    / 10 != 1) ++bad;
            if (uamm4LulDiameterTenthsIn()
                    % 10 != 5) ++bad;
            // the lead band is the
            // iron band divided by
            // five at both ends
            if (uamm4PstIronLbsLo()
                    / 5 != uamm4PstLeadLbsLo())
                ++bad;
            if (uamm4PstIronLbsHi()
                    / 5 != uamm4PstLeadLbsHi())
                ++bad;
            // the prison shrink is
            // a quarter foot
            if (4 * uamm4PzaShrinksToHeightIn()
                    != 12) ++bad;
        // ---- the ledger seam ----
            // all six part ledgers
            // run clean, no flags
            if (uammPartCleanCount()
                    != uammPartItemTotal())
                ++bad;
            if (uammPartFlaggedCount()
                    != 0) ++bad;
            if (uamm2PartCleanCount()
                    != uamm2PartItemTotal())
                ++bad;
            if (uamm2PartFlaggedCount()
                    != 0) ++bad;
            if (uamm3PartCleanCount()
                    != uamm3PartItemTotal())
                ++bad;
            if (uamm3PartFlaggedCount()
                    != 0) ++bad;
            if (uamm4PartCleanCount()
                    != uamm4PartItemTotal())
                ++bad;
            if (uamm4PartFlaggedCount()
                    != 0) ++bad;
            if (uamm5PartCleanCount()
                    != uamm5PartItemTotal())
                ++bad;
            if (uamm5PartFlaggedCount()
                    != 0) ++bad;
            if (uamm6PartCleanCount()
                    != uamm6PartItemTotal())
                ++bad;
            if (uamm6PartFlaggedCount()
                    != 0) ++bad;
        printf("R398 UA misc magic holes pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
