    // ---- R417: the UA
    // haunting-sound cantrips
    // pin audit ----
    // The 8 haunting-sound
    // descriptions pin - the LAST
    // of the six description
    // rounds: the names cross-
    // check the R341/R401 roster
    // live, the schools pin per
    // row (NO new codes - the
    // Evocation 3 / Illusion 5
    // census), the areas pin per
    // row (ZERO area holes - the
    // Special seven and the Tap
    // one square foot, a NEW area
    // kind), the censuses count,
    // the mechanics pin with the
    // band derivations cross-
    // checking themselves (the
    // whistle loud == faint*3);
    // census 343 -> 344.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (uchHauntingSoundCount() != 8)
            ++bad;
        if (uastCantripCount(5) != 8)
            ++bad;
        // ---- the school census ----
        if (uchSchoolCount(UCH_EVO) != 3
                || uchSchoolCount(UCH_ILL) != 5
                || uchSchoolCount(1) != 0
                || uchSchoolCount(2) != 0
                || uchSchoolCount(3) != 0
                || uchSchoolCount(5) != 0
                || uchSchoolCount(6) != 0
                || uchSchoolCount(7) != 0) ++bad;
        // ---- the area census ----
        if (uchAreaKindCount(UCH_AREA_SPECIAL) != 7
                || uchAreaKindCount(UCH_AREA_SQFT) != 1
                || uchAreaKindCount(UCH_AREA_HOLE) != 0) ++bad;
        if (strcmp(uchHauntingSound(0).name,
                   uastCantripName(5, 0)) != 0
                || uchHauntingSound(0)
                   .school != 0
                || uchHauntingSound(0)
                   .areaKind != 3
                || uchHauntingSound(0)
                   .areaVal != 0) ++bad;
        if (strcmp(uchHauntingSound(1).name,
                   uastCantripName(5, 1)) != 0
                || uchHauntingSound(1)
                   .school != 4
                || uchHauntingSound(1)
                   .areaKind != 3
                || uchHauntingSound(1)
                   .areaVal != 0) ++bad;
        if (strcmp(uchHauntingSound(2).name,
                   uastCantripName(5, 2)) != 0
                || uchHauntingSound(2)
                   .school != 4
                || uchHauntingSound(2)
                   .areaKind != 3
                || uchHauntingSound(2)
                   .areaVal != 0) ++bad;
        if (strcmp(uchHauntingSound(3).name,
                   uastCantripName(5, 3)) != 0
                || uchHauntingSound(3)
                   .school != 4
                || uchHauntingSound(3)
                   .areaKind != 3
                || uchHauntingSound(3)
                   .areaVal != 0) ++bad;
        if (strcmp(uchHauntingSound(4).name,
                   uastCantripName(5, 4)) != 0
                || uchHauntingSound(4)
                   .school != 4
                || uchHauntingSound(4)
                   .areaKind != 3
                || uchHauntingSound(4)
                   .areaVal != 0) ++bad;
        if (strcmp(uchHauntingSound(5).name,
                   uastCantripName(5, 5)) != 0
                || uchHauntingSound(5)
                   .school != 0
                || uchHauntingSound(5)
                   .areaKind != 13
                || uchHauntingSound(5)
                   .areaVal != 1) ++bad;
        if (strcmp(uchHauntingSound(6).name,
                   uastCantripName(5, 6)) != 0
                || uchHauntingSound(6)
                   .school != 4
                || uchHauntingSound(6)
                   .areaKind != 3
                || uchHauntingSound(6)
                   .areaVal != 0) ++bad;
        if (strcmp(uchHauntingSound(7).name,
                   uastCantripName(5, 7)) != 0
                || uchHauntingSound(7)
                   .school != 0
                || uchHauntingSound(7)
                   .areaKind != 3
                || uchHauntingSound(7)
                   .areaVal != 0) ++bad;
        // ---- the casting times ----
        // (the PDF read resolves the
        // family - R419)

        if (uchCastTimeDen(0) != 6
                || uchCastTimeDen(1) != 6
                || uchCastTimeDen(2) != 6
                || uchCastTimeDen(3) != 10
                || uchCastTimeDen(4) != 10
                || uchCastTimeDen(5) != 6
                || uchCastTimeDen(6) != 10
                || uchCastTimeDen(7) != 6) ++bad;

        // ---- the resolved reads (the PDF read - R419)
        if (!uchRangeUnitIsInch()
                || uchCreakFormerDen()
                != 3
                || uchCreakTraverseFeet()
                != 10) ++bad;
        // ---- the mechanics ----
        if (uchRangeNearVal() != 1
                || uchFootfallFarVal() != 2
                || uchMoanFlavors() != 2
                || uchRattleSeconds() != 2) ++bad;
        if (uchCreakLatterHalfSegs() != 1
                || uchTapCountMin() != 1
                || uchTapCountMax() != 3) ++bad;
        if (uchWhistleFaintFeet() != 10
                || uchWhistleLoudFeet() != 30) ++bad;
        // The band derivations: the
        // tap once/twice/thrice opens
        // below its close and the
        // whistle loud radius rides
        // three times the faint one
        // - both cross-check by
        // derivation (quiet on the
        // healthy values - the R391
        // lesson).
        if (uchTapCountMin()
                >= uchTapCountMax()
                || uchWhistleLoudFeet()
                   != uchWhistleFaintFeet() * 3) ++bad;
        printf("R417 UA haunting-sound cantrips pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
