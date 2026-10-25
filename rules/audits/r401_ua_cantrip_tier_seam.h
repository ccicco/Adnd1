    // ---- R401: the UA cantrip tier
    // seam audit ----
    // The sub-1st registry tier closes the
    // deferred seam: the p. 45 tier traits,
    // the 0-level per-day ladder, the
    // first-level retention, the round
    // rules and the roster; the R341
    // decode amendments cross-check here.
    {
        using namespace rules;
        int bad = 0;
        // the tier traits
        if (cantSpellLevel() != 0) ++bad;
        if (cantRangeInches() != 1) ++bad;
        if (cantCastTimeMinTenths() != 1)
            ++bad;
        if (cantCastTimeMaxTenths() != 5)
            ++bad;
        if (!cantSmallAoe()) ++bad;
        if (!cantSoftSimpleComponents())
            ++bad;
        if (!cantLivingCreatureCantripsAllowSave()) ++bad;
        if (!cantConcentrationBlocksPersonAffecting()) ++bad;
        if (!cantFaintMagicAura()) ++bad;
        if (!cantMemorizedLikeSpells())
            ++bad;
        // the per-day ladder: the band
        // edges
        if (cantPerDayByXp(-2000) != 1)
            ++bad;
        if (cantPerDayByXp(-1001) != 1)
            ++bad;
        if (cantPerDayByXp(-1000) != 2)
            ++bad;
        if (cantPerDayByXp(-501) != 2)
            ++bad;
        if (cantPerDayByXp(-500) != 3)
            ++bad;
        if (cantPerDayByXp(-1) != 3)
            ++bad;
        if (cantPerDayByXp(0) != 0) ++bad;
        if (cantPerDayByXp(500) != 0)
            ++bad;
        if (cantPerDayByXp(-2001) != 1)
            ++bad;
        // the ladder agrees with its bands
        if (cantNeophytePerDay()
                != cantPerDayByXp(
                      cantNeophyteXpHi()))
            ++bad;
        if (cantInitiatePerDay()
                != cantPerDayByXp(                      cantInitiateXpHi()))
            ++bad;
        if (cantApprenticePerDay()
                != cantPerDayByXp(                      cantApprenticeXpHi()))
            ++bad;
        // the bands tile contiguously
        if (cantInitiateXpLo()
                != cantNeophyteXpHi() + 1)
            ++bad;
        if (cantApprenticeXpLo()
                != cantInitiateXpHi() + 1)
            ++bad;
        // the per-day ladder climbs
        if (cantNeophytePerDay() + 1
                != cantInitiatePerDay())
            ++bad;
        if (cantInitiatePerDay() + 1
                != cantApprenticePerDay())
            ++bad;
        // the first-level retention
        if (!cantKnowledgeDiscardedAtFirst()) ++bad;
        if (cantRetainedMaxInPlaceOfFirst()
            != 4) ++bad;
        // the round rules
        if (cantPerRoundMax() != 2) ++bad;
        if (cantSecondCastGapDieSides()
            != 4) ++bad;
        if (!cantNoSpellAndCantripSameRound()) ++bad;
        // the categories
        if (cantCategoryCount() != 7)
            ++bad;
        if (cantMuCategoryCount() != 6)
            ++bad;
        if (cantCategoryCount()
                != cantMuCategoryCount() + 1)
            ++bad;
        if (!cantAnyCasterMayKnowAllCategories()) ++bad;
        // the roster (the R401-amended
        // R341 decode)
        if (cantMuRosterTotal() != 66)
            ++bad;
        if (cantIlRosterTotal() != 8)
            ++bad;
        if (cantRosterTotal()
                != cantMuRosterTotal()
                   + cantIlRosterTotal())
            ++bad;
        {
            int total = 0;
            for (int c = 0; c < 6; ++c)
                total += uastCantripCount(c);
            if (total != cantMuRosterTotal())
                ++bad;
        }
        // the R341 seam agreement: the
        // category counts and the
        // amended name seats
        if (uastCantripCount(1) != 12)
            ++bad;
        if (uastCantripCount(4) != 10)
            ++bad;
        if (strcmp(uastCantripName(1, 8),
            "Tangle") != 0) ++bad;
        if (strcmp(uastCantripName(4, 8),
            "Tweak") != 0) ++bad;
        if (uastCantripName(1, 12)[0] != 0)
            ++bad;
        if (uastCantripName(4, 10)[0] != 0)
            ++bad;
        // the R369/R365 acquisition seams
        if (uacaqCategoryCount()
                != cantMuCategoryCount())
            ++bad;
        if (uacaqMaxDevelopedCantrips()
                != uastMuCantripMaxNewCount())
            ++bad;
        if (uastIlMinorIllusionMin()
                > uastIlMinorIllusionMax())
            ++bad;
        if (uastIlMinorIllusionMax()
                > cantIlRosterTotal()) ++bad;
        // the R366 book seam
        if (!uabkCantripsCountAsFirstLevel())
            ++bad;
        // the R363 minor-illusion roster
        if (strcmp(uailcLightsName(),
            "Colored Lights (Alteration)") != 0)
            ++bad;
        if (strcmp(uailcDimName(),
            "Dim (Alteration)") != 0) ++bad;
        if (strcmp(uailcHazeName(),
            "Haze (Alteration)") != 0) ++bad;
        if (strcmp(uailcMaskName(),
            "Mask (Illusion)") != 0) ++bad;
        if (strcmp(uailcMirageName(),
            "Mirage") != 0) ++bad;
        if (strcmp(uailcNoiseName(),
            "Noise (Illusion)") != 0) ++bad;
        if (strcmp(uailcRainbowName(),
            "Rainbow (Alteration)") != 0)
            ++bad;
        if (strcmp(uailcTwodName(),
            "Two-D'lusion") != 0)
            ++bad;
        printf("R401 UA cantrip tier seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
