    // ---- R399: the UA armor
    // swords misc weapons holes
    // pin audit ----
    // The clean read (pp.
    // 104-106) fills every
    // flagged hole the two
    // treasure prose headers
    // carry - all seven flags
    // drop and both part
    // ledgers run clean/0.
    {
        using namespace rules;
        int bad = 0;
            if (uaaspEcmManNormalHeightIn() != 72) ++bad;
            if (uaaspEcmManLargeHeightIn() != 78) ++bad;
            if (!uaaspEcmRow1GnomeHalfling()) ++bad;
            if (!uaaspPltAnyHumanWearsOwn()) ++bad;
            if (!uaaspSubRadianceBrightYellow()) ++bad;
            if (!uaaspSubRadianceEqualsDaylight()) ++bad;
            if (uamwAohFamChancePctX2() != 25) ++bad;
            if (uamwDthShortRangeIn() != 2) ++bad;
            if (uamwDthMediumRangeIn() != 4) ++bad;
            if (uamwHblHornLengthLoIn() != 6) ++bad;
            if (uamwHblHornLengthHiIn() != 15) ++bad;
            if (std::string(
                    uaaspFwbAppellation(0))
                    != "Answerer") ++bad;
            if (std::string(
                    uaaspFwbAppellation(1))
                    != "Back-talker") ++bad;
            if (std::string(
                    uaaspFwbAppellation(2))
                    != "Concluder") ++bad;
            if (std::string(
                    uaaspFwbAppellation(3))
                    != "Last-quip") ++bad;
            if (std::string(
                    uaaspFwbAppellation(4))
                    != "Rebutter") ++bad;
            if (std::string(
                    uaaspFwbAppellation(5))
                    != "Replier") ++bad;
            if (std::string(
                    uaaspFwbAppellation(6))
                    != "Retorter") ++bad;
            if (std::string(
                    uaaspFwbAppellation(7))
                    != "Scather") ++bad;
            if (std::string(
                    uaaspFwbAppellation(8))
                    != "Squelcher") ++bad;
        // ---- the cross-checks
        // ----
            // the large suit stands
            // six inches taller than
            // the normal, and carries
            // fifty more pounds
            if (uaaspEcmManLargeHeightIn()
                    - uaaspEcmManNormalHeightIn()
                    != 6) ++bad;
            if (uaaspEcmManNormalHeightIn()
                    != 12 * 6) ++bad;
            // the thrown-dagger range
            // ladder steps two inches
            // at a time, 2, 4, 6
            if (uamwDthShortRangeIn()
                    + 2 != uamwDthMediumRangeIn())
                ++bad;
            if (uamwDthMediumRangeIn()
                    + 2 != uamwDthHurledRangeIn())
                ++bad;
            // the eight weekly 12
            // 1/2% chances sum to a
            // full 100% expectation
            if (uamwAohFamWeeksFull()
                    * uamwAohFamChancePctX2()
                    != 200) ++bad;
            // the horn band runs a
            // half foot to one and
            // a quarter feet, 6 and
            // 15 inches
            if (5 * uamwHblHornLengthLoIn()
                    != 2 * uamwHblHornLengthHiIn())
                ++bad;
        // ---- the ledger seam ----
            // both part ledgers run
            // clean, no flags
            if (uaaspPartCleanCount()
                    != uaaspPartItemTotal())
                ++bad;
            if (uaaspPartFlaggedCount()
                    != 0) ++bad;
            if (uamwPartCleanCount()
                    != uamwPartItemTotal())
                ++bad;
            if (uamwPartFlaggedCount()
                    != 0) ++bad;
        printf("R399 UA armor weapons holes pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
