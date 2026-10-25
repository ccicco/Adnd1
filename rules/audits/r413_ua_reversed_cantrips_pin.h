    // ---- R413: the UA
    // reversed cantrips pin
    // audit ----
    // The 12 reversed-category
    // descriptions pin: the names
    // cross-check the R341/R401
    // roster live, the schools and
    // areas pin per row (ZERO
    // area holes this round), the
    // school census counts (3/0/7/2),
    // the casting-time family stays
    // the hole family, the mechanics
    // pin with the tarnish/shine and
    // dirty/clean pairs cross-
    // checking each other; census
    // 339 -> 340.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (ucrReversedCount() != 12)
            ++bad;
        if (uastCantripCount(1) != 12)
            ++bad;
        // ---- the school census ----
        if (ucrSchoolCount(UCR_EVO) != 3
                || ucrSchoolCount(UCR_ABJ) != 0
                || ucrSchoolCount(UCR_ALT) != 7
                || ucrSchoolCount(UCR_ENCH) != 2) ++bad;
        // ---- the area census ----
        if (ucrAreaKindCount(UCR_AREA_OBJECT) != 8
                || ucrAreaKindCount(UCR_AREA_SQYDS) != 1
                || ucrAreaKindCount(UCR_AREA_RADIUS) != 1
                || ucrAreaKindCount(UCR_AREA_SPECIAL) != 1
                || ucrAreaKindCount(UCR_AREA_CONTAINER) != 1
                || ucrAreaKindCount(UCR_AREA_HOLE) != 0) ++bad;
        if (strcmp(ucrReversed(0).name,
                   uastCantripName(1, 0)) != 0
                || ucrReversed(0)
                   .school != 3
                || ucrReversed(0)
                   .areaKind != 0
                || ucrReversed(0)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(1).name,
                   uastCantripName(1, 1)) != 0
                || ucrReversed(1)
                   .school != 0
                || ucrReversed(1)
                   .areaKind != 4
                || ucrReversed(1)
                   .areaVal != 4) ++bad;
        if (strcmp(ucrReversed(2).name,
                   uastCantripName(1, 2)) != 0
                || ucrReversed(2)
                   .school != 0
                || ucrReversed(2)
                   .areaKind != 5
                || ucrReversed(2)
                   .areaVal != 10) ++bad;
        if (strcmp(ucrReversed(3).name,
                   uastCantripName(1, 3)) != 0
                || ucrReversed(3)
                   .school != 2
                || ucrReversed(3)
                   .areaKind != 0
                || ucrReversed(3)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(4).name,
                   uastCantripName(1, 4)) != 0
                || ucrReversed(4)
                   .school != 2
                || ucrReversed(4)
                   .areaKind != 0
                || ucrReversed(4)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(5).name,
                   uastCantripName(1, 5)) != 0
                || ucrReversed(5)
                   .school != 2
                || ucrReversed(5)
                   .areaKind != 3
                || ucrReversed(5)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(6).name,
                   uastCantripName(1, 6)) != 0
                || ucrReversed(6)
                   .school != 0
                || ucrReversed(6)
                   .areaKind != 0
                || ucrReversed(6)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(7).name,
                   uastCantripName(1, 7)) != 0
                || ucrReversed(7)
                   .school != 2
                || ucrReversed(7)
                   .areaKind != 6
                || ucrReversed(7)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(8).name,
                   uastCantripName(1, 8)) != 0
                || ucrReversed(8)
                   .school != 2
                || ucrReversed(8)
                   .areaKind != 0
                || ucrReversed(8)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(9).name,
                   uastCantripName(1, 9)) != 0
                || ucrReversed(9)
                   .school != 2
                || ucrReversed(9)
                   .areaKind != 0
                || ucrReversed(9)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(10).name,
                   uastCantripName(1, 10)) != 0
                || ucrReversed(10)
                   .school != 2
                || ucrReversed(10)
                   .areaKind != 0
                || ucrReversed(10)
                   .areaVal != 0) ++bad;
        if (strcmp(ucrReversed(11).name,
                   uastCantripName(1, 11)) != 0
                || ucrReversed(11)
                   .school != 3
                || ucrReversed(11)
                   .areaKind != 0
                || ucrReversed(11)
                   .areaVal != 0) ++bad;
        // ---- the casting times ----
        // (the PDF read resolves the
        // family - R418)

        if (ucrCastTimeDen(0) != 8
                || ucrCastTimeDen(1) != 8
                || ucrCastTimeDen(2) != 8
                || ucrCastTimeDen(3) != 10
                || ucrCastTimeDen(4) != 2
                || ucrCastTimeDen(5) != 10
                || ucrCastTimeDen(6) != 2
                || ucrCastTimeDen(7) != 8) ++bad;

        if (ucrCastTimeDen(8) != 8
                || ucrCastTimeDen(9) != 2
                || ucrCastTimeDen(10) != 3
                || ucrCastTimeDen(11) != 2) ++bad;
        // ---- the mechanics ----
        if (ucrHairyGrowthMinIn() != 2
                || ucrHairyGrowthMaxIn() != 12
                || ucrHairyShortUnderIn() != 1) ++bad;
        if (ucrHairyAbsenceMinDays() != 2
                || ucrHairyAbsenceMaxDays() != 12) ++bad;
        if (ucrKnotUntieMinRounds() != 2
                || ucrKnotUntieMaxRounds() != 8) ++bad;
        if (ucrTangleUntangleMinRounds() != 3
                || ucrTangleUntangleMaxRounds() != 12)
            ++bad;
        if (ucrSourMaxPints() != 1)
            ++bad;
        if (ucrSpillMaxGallons() != 1)
            ++bad;
        // ---- the live pairs ----
        // The tarnish volume is the
        // reverse of the R412 shine
        // volume.
        if (ucrTarnishMaxCubicYds()
                != ucnShineMaxCubicYds()) ++bad;
        // The Dirty 4 sq. yds. is
        // the opposite of the Clean
        // 4 sq. yds. (R412).
        if (ucrReversed(1).areaKind
                != UCR_AREA_SQYDS
                || ucrReversed(1).areaVal
                != ucnUseful(1).areaVal) ++bad;
        printf("R413 UA reversed cantrips pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
