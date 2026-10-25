    // ---- R314a: the crossbow and the aquatic
    // first strike seam audit ----
    // The R314 pins (rules/uwfight.h, the
    // grenade.h pattern): the deep crossbow
    // (the R311 specially-made crossbow -
    // the missile bar lifts for it alone),
    // the aquatic first-strike floors and
    // the waterborne gate; the R311 net and
    // crossbow data and the R313 regression
    // probes ride the same block - verified
    // by audit_eval.
    {
        int bad = 0;
        // the R314 pins
        if (rules::uwDeepCrossbowAllowed() != 1 ||
            rules::uwWaterborneIsAquatic() != 1 ||
            rules::uwAquaticFirstStrike() != 1 ||
            rules::uwAquaticFirstStrikeSegment()
                != 1 ||
            rules::uwCompanyEarliestSegment()
                != 2) ++bad;
        // the R311 crossbow and net data
        if (rules::uwSpecialCrossbowPriceMultiple()
                != 10 ||
            rules::uwSpecialCrossbowRangeDivisor()
                != 2 ||
            rules::uwNetThrowFtPerStrPoint() != 1 ||
            rules::uwNetThrowUnderwaterRaceFt()
                != 15 ||
            rules::uwNetThrowSahuaginFt() != 20 ||
            rules::uwNetUntrainedPenalty() != 4)
            ++bad;
        // the R313 regression probes
        if (rules::uwStrikeAllowed(0) != 0 ||
            rules::uwStrikeAllowed(1) != 1 ||
            rules::uwStrikeAllowed(2) != 0 ||
            rules::uwMissileBarred() != 1 ||
            rules::uwCrossCapLbs(0) != 20 ||
            rules::uwCrossCapLbs(5000) != 70)
            ++bad;
        printf("R314a crossbow and aquatic seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
