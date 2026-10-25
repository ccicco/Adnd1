    // ---- R414: the UA
    // legerdemain cantrips pin
    // audit ----
    // The 6 legerdemain
    // descriptions pin: the names
    // cross-check the R341/R401
    // roster live, the schools and
    // areas pin per row (ZERO
    // area holes; Illusion a NEW
    // school code, one small item
    // a NEW area kind), the school
    // census counts (0/0/3/1/2),
    // the casting-time family
    // stays the hole family, the
    // mechanics pin with the hide
    // ladder cross-checking
    // itself by derivation; census
    // 340 -> 341.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (uclLegerdemainCount() != 6)
            ++bad;
        if (uastCantripCount(2) != 6)
            ++bad;
        // ---- the school census ----
        if (uclSchoolCount(UCL_ALT) != 3
                || uclSchoolCount(UCL_ENCH) != 1
                || uclSchoolCount(UCL_ILL) != 2
                || uclSchoolCount(UCL_EVO) != 0
                || uclSchoolCount(UCL_ABJ) != 0) ++bad;
        // ---- the area census ----
        if (uclAreaKindCount(UCL_AREA_OBJECT) != 3
                || uclAreaKindCount(UCL_AREA_SPECIAL) != 1
                || uclAreaKindCount(UCL_AREA_SMALLITEM) != 2
                || uclAreaKindCount(UCL_AREA_HOLE) != 0) ++bad;
        if (strcmp(uclLegerdemain(0).name,
                   uastCantripName(2, 0)) != 0
                || uclLegerdemain(0)
                   .school != 2
                || uclLegerdemain(0)
                   .areaKind != 0
                || uclLegerdemain(0)
                   .areaVal != 0) ++bad;
        if (strcmp(uclLegerdemain(1).name,
                   uastCantripName(2, 1)) != 0
                || uclLegerdemain(1)
                   .school != 3
                || uclLegerdemain(1)
                   .areaKind != 3
                || uclLegerdemain(1)
                   .areaVal != 0) ++bad;
        if (strcmp(uclLegerdemain(2).name,
                   uastCantripName(2, 2)) != 0
                || uclLegerdemain(2)
                   .school != 4
                || uclLegerdemain(2)
                   .areaKind != 0
                || uclLegerdemain(2)
                   .areaVal != 0) ++bad;
        if (strcmp(uclLegerdemain(3).name,
                   uastCantripName(2, 3)) != 0
                || uclLegerdemain(3)
                   .school != 2
                || uclLegerdemain(3)
                   .areaKind != 0
                || uclLegerdemain(3)
                   .areaVal != 0) ++bad;
        if (strcmp(uclLegerdemain(4).name,
                   uastCantripName(2, 4)) != 0
                || uclLegerdemain(4)
                   .school != 4
                || uclLegerdemain(4)
                   .areaKind != 7
                || uclLegerdemain(4)
                   .areaVal != 0) ++bad;
        if (strcmp(uclLegerdemain(5).name,
                   uastCantripName(2, 5)) != 0
                || uclLegerdemain(5)
                   .school != 2
                || uclLegerdemain(5)
                   .areaKind != 7
                || uclLegerdemain(5)
                   .areaVal != 0) ++bad;
        // ---- the casting times ----
        // (the PDF read resolves the
        // family - R418)

        if (uclCastTimeDen(0) != 10
                || uclCastTimeDen(1) != 3
                || uclCastTimeDen(2) != 10
                || uclCastTimeDen(3) != 10
                || uclCastTimeDen(4) != 10
                || uclCastTimeDen(5) != 8) ++bad;
        // ---- the mechanics ----
        if (uclChangeSizePctMax() != 50
                || uclChangeBaseTurns() != 1
                || uclChangeRadicalRounds() != 1
                || uclChangeSlightDays() != 1) ++bad;
        if (uclDistractRangeFt() != 10
                || uclDistractDurationSegments() != 1)
            ++bad;
        // ---- the hide ladder ----
        if (uclHideBaseCubicYds() != 2
                || uclHideBaseTurns() != 1
                || uclHideRoundCubicYds() != 20) ++bad;
        // The derivation: the
        // segment span (38-22)/2 = 8
        // equals 9 - 1, and the
        // span divides the step.
        if (uclHideSegStartCubicYds() != 22
                || uclHideSegStartSegments() != 9
                || uclHideSegStepCubicYds() != 2
                || uclHideMinCubicYds() != 38
                || uclHideMinSegments() != 1) ++bad;
        if ((uclHideMinCubicYds()
                - uclHideSegStartCubicYds())
                / uclHideSegStepCubicYds()
                != uclHideSegStartSegments()
                - uclHideMinSegments()
                || (uclHideMinCubicYds()
                   - uclHideSegStartCubicYds())
                   % uclHideSegStepCubicYds() != 0)
            ++bad;
        if (uclMuteDurationRounds() != 1
                || uclPalmDurationSegments() != 1)
            ++bad;
        if (uclPresentRadiusFt() != 2
                || uclPresentMaxCoins() != 12) ++bad;
        printf("R414 UA legerdemain cantrips pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
