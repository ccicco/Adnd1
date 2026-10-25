    // ---- R412: the UA useful
    // cantrips pin audit ----
    // The 20 useful-category
    // descriptions pin: the names
    // cross-check the R341/R401
    // roster live, the schools and
    // areas pin per row, the school
    // census counts (7/4/7/2), the
    // six area garbles record as
    // holes pending the PDF read,
    // the casting-time family stays
    // the hole family, the mechanics
    // pin with the chill/warm and
    // freshen/salt pairs cross-
    // checking each other; census
    // 338 -> 339.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (ucnUsefulCount() != 20)
            ++bad;
        if (uastCantripCount(0) != 20)
            ++bad;
        if (cantMuCategoryCount() != 6)
            ++bad;
        // ---- the school census ----
        if (ucnSchoolCount(UCN_EVO) != 7
                || ucnSchoolCount(UCN_ABJ) != 4
                || ucnSchoolCount(UCN_ALT) != 7
                || ucnSchoolCount(UCN_ENCH) != 2) ++bad;
        // ---- the area census ----
        if (ucnAreaKindCount(UCN_AREA_OBJECT) != 8
                || ucnAreaKindCount(UCN_AREA_CUBEFoot) != 2
                || ucnAreaKindCount(UCN_AREA_CUBICyd) != 2
                || ucnAreaKindCount(UCN_AREA_SPECIAL) != 1
                || ucnAreaKindCount(UCN_AREA_SQYDS) != 1
                || ucnAreaKindCount(UCN_AREA_HOLE) != 6) ++bad;
        if (strcmp(ucnUseful(0).name,
                   uastCantripName(0, 0)) != 0
                || ucnUseful(0).school != 0
                || ucnUseful(0).areaKind != 1
                || ucnUseful(0).areaVal != 1) ++bad;
        if (strcmp(ucnUseful(1).name,
                   uastCantripName(0, 1)) != 0
                || ucnUseful(1).school != 1
                || ucnUseful(1).areaKind != 4
                || ucnUseful(1).areaVal != 4) ++bad;
        if (strcmp(ucnUseful(2).name,
                   uastCantripName(0, 2)) != 0
                || ucnUseful(2).school != 0
                || ucnUseful(2).areaKind != 2
                || ucnUseful(2).areaVal != 1) ++bad;
        if (strcmp(ucnUseful(3).name,
                   uastCantripName(0, 3)) != 0
                || ucnUseful(3).school != 0
                || ucnUseful(3).areaKind != -1
                || ucnUseful(3).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(4).name,
                   uastCantripName(0, 4)) != 0
                || ucnUseful(4).school != 1
                || ucnUseful(4).areaKind != -1
                || ucnUseful(4).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(5).name,
                   uastCantripName(0, 5)) != 0
                || ucnUseful(5).school != 1
                || ucnUseful(5).areaKind != -1
                || ucnUseful(5).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(6).name,
                   uastCantripName(0, 6)) != 0
                || ucnUseful(6).school != 1
                || ucnUseful(6).areaKind != -1
                || ucnUseful(6).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(7).name,
                   uastCantripName(0, 7)) != 0
                || ucnUseful(7).school != 3
                || ucnUseful(7).areaKind != 0
                || ucnUseful(7).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(8).name,
                   uastCantripName(0, 8)) != 0
                || ucnUseful(8).school != 3
                || ucnUseful(8).areaKind != 0
                || ucnUseful(8).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(9).name,
                   uastCantripName(0, 9)) != 0
                || ucnUseful(9).school != 2
                || ucnUseful(9).areaKind != -1
                || ucnUseful(9).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(10).name,
                   uastCantripName(0, 10)) != 0
                || ucnUseful(10).school != 2
                || ucnUseful(10).areaKind != 0
                || ucnUseful(10).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(11).name,
                   uastCantripName(0, 11)) != 0
                || ucnUseful(11).school != 0
                || ucnUseful(11).areaKind != 0
                || ucnUseful(11).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(12).name,
                   uastCantripName(0, 12)) != 0
                || ucnUseful(12).school != 2
                || ucnUseful(12).areaKind != 0
                || ucnUseful(12).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(13).name,
                   uastCantripName(0, 13)) != 0
                || ucnUseful(13).school != 0
                || ucnUseful(13).areaKind != 0
                || ucnUseful(13).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(14).name,
                   uastCantripName(0, 14)) != 0
                || ucnUseful(14).school != 2
                || ucnUseful(14).areaKind != -1
                || ucnUseful(14).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(15).name,
                   uastCantripName(0, 15)) != 0
                || ucnUseful(15).school != 2
                || ucnUseful(15).areaKind != 3
                || ucnUseful(15).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(16).name,
                   uastCantripName(0, 16)) != 0
                || ucnUseful(16).school != 0
                || ucnUseful(16).areaKind != 0
                || ucnUseful(16).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(17).name,
                   uastCantripName(0, 17)) != 0
                || ucnUseful(17).school != 2
                || ucnUseful(17).areaKind != 0
                || ucnUseful(17).areaVal != 0) ++bad;
        if (strcmp(ucnUseful(18).name,
                   uastCantripName(0, 18)) != 0
                || ucnUseful(18).school != 0
                || ucnUseful(18).areaKind != 1
                || ucnUseful(18).areaVal != 1) ++bad;
        if (strcmp(ucnUseful(19).name,
                   uastCantripName(0, 19)) != 0
                || ucnUseful(19).school != 2
                || ucnUseful(19).areaKind != 2
                || ucnUseful(19).areaVal != 1) ++bad;
        // ---- the casting times ----
        // (the PDF read resolves the
        // family - R418)

        if (ucnCastTimeDen(0) != 2
                || ucnCastTimeDen(1) != 2
                || ucnCastTimeDen(2) != 2
                || ucnCastTimeDen(3) != 2
                || ucnCastTimeDen(4) != 2
                || ucnCastTimeDen(5) != 2
                || ucnCastTimeDen(6) != 10
                || ucnCastTimeDen(7) != 2) ++bad;

        if (ucnCastTimeDen(8) != 2
                || ucnCastTimeDen(9) != 8
                || ucnCastTimeDen(10) != 2
                || ucnCastTimeDen(11) != 8
                || ucnCastTimeDen(12) != 2
                || ucnCastTimeDen(13) != 2
                || ucnCastTimeDen(14) != 2
                || ucnCastTimeDen(15) != 2) ++bad;

        if (ucnCastTimeDen(16) != 2
                || ucnCastTimeDen(17) != 2
                || ucnCastTimeDen(18) != 2
                || ucnCastTimeDen(19) != 2) ++bad;
        // ---- the mechanics ----
        if (ucnTempDeltaF() != 40)
            ++bad;
        if (ucnFreshenDmgMax() != 4
                || ucnSaltDmgMax() != ucnFreshenDmgMax()) ++bad;
        if (ucnSaltObjectSqYds() != 4
                || ucnSaltGallons() != 30) ++bad;
        if (ucnTieRangeFt() != 1)
            ++bad;
        if (ucnShineMaxCubicYds() != 1
                || ucnShineRevalueDieMod() != -1
                || !ucnShineRevalueOnceOnly()) ++bad;
        if (ucnColorRenewDays() != 30)
            ++bad;
        if (ucnPolishFloorSqFt() != 1000)
            ++bad;
        printf("R412 UA useful cantrips pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
