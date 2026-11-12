    // ---- R314a: the crossbow and the aquatic
    // first strike seam audit ----
    // The R314 pins (rules/dmg/uwfight.h, the
    // grenade.h pattern): the deep crossbow
    // (the R311 specially-made crossbow -
    // the missile bar lifts for it alone),
    // the aquatic first-strike floors and
    // the waterborne gate; the R311 net and
    // crossbow data and the R313 regression
    // probes ride the same block - verified
    // by audit_eval.
    {
        Uwfight uwfight;
        int bad = 0;
        // the R314 pins
        if (uwfight.uwDeepCrossbowAllowed() != 1 ||
            uwfight.uwWaterborneIsAquatic() != 1 ||
            rules::uwAquaticFirstStrike() != 1 ||
            uwfight.uwAquaticFirstStrikeSegment()
                != 1 ||
            uwfight.uwCompanyEarliestSegment()
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
        if (uwfight.uwStrikeAllowed(0) != 0 ||
            uwfight.uwStrikeAllowed(1) != 1 ||
            uwfight.uwStrikeAllowed(2) != 0 ||
            uwfight.uwMissileBarred() != 1 ||
            uwfight.uwCrossCapLbs(0) != 20 ||
            uwfight.uwCrossCapLbs(5000) != 70)
            ++bad;
        printf("R314a crossbow and aquatic seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
