    // ---- R369: the UA cantrip
    // acquisition pin audit ----
    // The UA ACQUISITION OF CANTRIPS,
    // MAGIC-USERS (p. 79): the known-count
    // rules pinned - the useful category
    // one per point of intelligence by free
    // choice (the decode flagged), the five
    // random bands (reversed 2-8, legerdemain
    // 2-5, person-affecting 2-8, personal
    // 2-8, haunting-sound 2-5), the 3
    // developed cap with the DM review, the
    // read-as-spell and recorded-as-spell
    // notes. The R365 seam cross-checks the
    // illusionist bands (the documented
    // divergence); the R366 seam the book
    // counts. The item flips CLOSED; the
    // census 295 -> 296.
    {
        using namespace rules;
        int bad = 0;
        // ---- the pinned cells ----
            if (uacaqUsefulPerIntelligencePoint()
                    != 1) ++bad;
            if (!uacaqUsefulFreeChoice()) ++bad;
            if (!uacaqUsefulReadDecoded()) ++bad;
            if (uacaqCategoryCount() != 6) ++bad;
            if (uacaqReversedKnownMin() != 2)
                ++bad;
            if (uacaqReversedKnownMax() != 8)
                ++bad;
            if (uacaqLegerdemainKnownMin() != 2)
                ++bad;
            if (uacaqLegerdemainKnownMax() != 5)
                ++bad;
            if (uacaqPersonAffectingKnownMin() != 2)
                ++bad;
            if (uacaqPersonAffectingKnownMax() != 8)
                ++bad;
            if (uacaqPersonalKnownMin() != 2)
                ++bad;
            if (uacaqPersonalKnownMax() != 8)
                ++bad;
            if (uacaqHauntingSoundKnownMin() != 2)
                ++bad;
            if (uacaqHauntingSoundKnownMax() != 5)
                ++bad;
            if (uacaqMaxDevelopedCantrips() != 3)
                ++bad;
            if (!uacaqDevelopedRequiresDmReview())
                ++bad;
            if (!uacaqReadAsSpell()) ++bad;
            if (!uacaqRecordedAsSpell()) ++bad;
        // ---- the R365 illusionist seam ----
            // The documented MU-vs-illusionist
            // divergences (the bands differ by
            // design; the illusionist useful cap
            // is intelligence minus 3):
            if (uacaqReversedKnownMax()
                    == uailaReversedKnownMax())
                ++bad;
            if (uacaqLegerdemainKnownMin()
                    == uailaLegerdemainKnownMin())
                ++bad;
            if (uacaqPersonAffectingKnownMax()
                    == uailaPersonAffectingKnownMax())
                ++bad;
            if (uacaqPersonalKnownMax()
                    == uailaPersonalKnownMax())
                ++bad;
            if (uacaqHauntingSoundKnownMax()
                    == uailaHauntingSoundKnownMax())
                ++bad;
            if (uacaqUsefulPerIntelligencePoint()
                    * 18 - uailaUsefulCapAtInt18()
                    != uailaUsefulCapIntMinus())
                ++bad;
            if (!uailaHasAllMuCantrips()) ++bad;
            if (!uailaMuCantripPropertiesOtherwiseApply())
                ++bad;
            // The seven-category read: the six
            // MU categories plus the
            // illusionist-only minor illusion.
            if (uacaqCategoryCount() + 1 != 7)
                ++bad;
        // ---- the R366 spell-book seam ----
            if (!uabkCantripsCountAsFirstLevel())
                ++bad;
            if (uabkStandardCantripsCapacity()
                    != 36) ++bad;
        printf("R369 UA cantrip acquisition pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
