    // ---- R375: the UA determination
    // skeleton pin audit ----
    // The MAGIC ITEMS (Revised
    // Table) skeleton (pp. 84-89):
    // the top-level category bands,
    // the sub-table splits, the
    // seven misc-magic sub-bands,
    // the scroll footnotes. The row
    // bodies of the eight tables
    // OCR-scramble - flagged; the
    // item stays open, PDF-gated.
    // The R374 dial seam
    // cross-checks the modes; the
    // census 301 -> 302.
    {
        using namespace rules;
        int bad = 0;
        // ---- the top-level bands ----
            static const int kLo[8] = {
                1, 21, 36, 41, 46, 61, 76, 87};
            static const int kHi[8] = {
                20, 35, 40, 45, 60, 75, 86,
                100};
            if (uadsCategoryCount() != 8) ++bad;
            if (uadsCategoryLo(0) != 1) ++bad;
            if (uadsCategoryHi(7) != 100) ++bad;
            if (strcmp(uadsCategoryName(0),
                    "Potions") != 0) ++bad;
            if (strcmp(uadsCategoryName(3),
                    "Rods, Staves & Wands") != 0)
                ++bad;
            if (strcmp(uadsCategoryName(7),
                    "Miscellaneous Weapons")
                    != 0) ++bad;
            for (int i = 0; i < 8; ++i) {
                if (uadsCategoryLo(i) != kLo[i])
                    ++bad;
                if (uadsCategoryHi(i) != kHi[i])
                    ++bad;
                if (i < 7 && kHi[i] + 1
                        != kLo[i + 1]) ++bad;
            }
            if (!uadsIsTheRevisedTable()) ++bad;
        // ---- the splits ----
            if (uadsPotionSplitLo() != 65) ++bad;
            if (!uadsPotionLowBandIsNewPotions())
                ++bad;
            if (uadsScrollSplitLo() != 85) ++bad;
            if (uadsRingSplitLo() != 67) ++bad;
            if (uadsRodSplitLo() != 40) ++bad;
            if (uadsArmorSplitLo() != 50) ++bad;
            if (uadsSwordSplitLo() != 95) ++bad;
            if (uadsWeaponSplitLo() != 50) ++bad;
            if (!uadsScrollSecondTableIsIIB2())
                ++bad;
            if (!uadsRodSecondTableIsIID2())
                ++bad;
            if (!uadsSwordFirstTableIsIIG()) ++bad;
            if (!uadsSwordSecondTableIsIIG2())
                ++bad;
        // ---- the misc sub-bands ----
            static const int mLo[7] = {
                1, 15, 29, 43, 57, 71, 86};
            static const int mHi[7] = {
                14, 28, 42, 56, 70, 85, 100};
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsMiscSubNamedCount() != 7) ++bad;
            if (uadsMiscSubSeventhNameGarbles())
                ++bad;
            for (int i = 0; i < 7; ++i) {
                if (uadsMiscSubLo(i) != mLo[i])
                    ++bad;
                if (uadsMiscSubHi(i) != mHi[i])
                    ++bad;
                if (i < 6 && mHi[i] + 1
                        != mLo[i + 1]) ++bad;
            }
        // ---- the scroll footnotes ----
            if (uadsScrollClericalPct() != 30)
                ++bad;
            if (uadsScrollClericalDruidPct() != 25)
                ++bad;
            if (uadsScrollMuIllusionistPct()
                    != 10) ++bad;
            if (!uadsScrollFootnoteBandIs71To00())
                ++bad;
            if (uadsScrollCurseDmgPage() != 121)
                ++bad;
        // ---- the extract read ----
            if (uadsRowBodiesGarble()) ++bad;
        // ---- the R374 dial seam ----
            // the skeleton rides the
            // dial's UA mode when the
            // bodies land; DMG stays
            // the default
            if (uatdModeDmg() != 0) ++bad;
            if (uatdModeUa() != 1) ++bad;
            if (uatdModeMerged() != 2) ++bad;
            if (uatdDefaultMode()
                    != uatdModeDmg()) ++bad;
            if (!uatdRunBothDecided()) ++bad;
            // R402: the pin rounds
            // landed - the pending
            // pin flips
            if (uatdUaPinRoundsPending()) ++bad;
        printf("R375 UA determination skeleton pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
