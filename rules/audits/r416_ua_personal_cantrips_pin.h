    // ---- R416: the UA personal
    // cantrips pin audit ----
    // The 10 personal
    // descriptions pin: the names
    // cross-check the R341/R401
    // roster live (the scan's
    // "Flrefinger" resolves as
    // Firefinger via the roster -
    // the independent
    // confirmation), the schools
    // pin per row (Summoning and
    // Conjuration AS PRINTED, NEW
    // codes), the areas pin per
    // row (EIGHT clean - the one
    // summoned animal four, the
    // Gnats cubic foot, the
    // Smokepuff cloud, the Tweak
    // creature, the Unlock lock;
    // the Bluelight sphere and the
    // Firefinger line record as
    // area holes), the censuses
    // count, the mechanics pin
    // with the band derivations
    // cross-checking themselves;
    // census 342 -> 343.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (ucoPersonalCount() != 10)
            ++bad;
        if (uastCantripCount(4) != 10)
            ++bad;
        // ---- the school census ----
        if (ucoSchoolCount(UCO_EVO) != 1
                || ucoSchoolCount(UCO_ABJ) != 0
                || ucoSchoolCount(UCO_ALT) != 1
                || ucoSchoolCount(UCO_ENCH) != 0
                || ucoSchoolCount(UCO_ILL) != 0
                || ucoSchoolCount(UCO_CHARM) != 0
                || ucoSchoolCount(UCO_SUMM) != 5
                || ucoSchoolCount(UCO_CONJ) != 3) ++bad;
        // ---- the area census ----
        if (ucoAreaKindCount(UCO_AREA_BEAST) != 4
                || ucoAreaKindCount(UCO_AREA_CUBEFoot) != 1
                || ucoAreaKindCount(UCO_AREA_CLOUD) != 1
                || ucoAreaKindCount(UCO_AREA_CREATURE) != 1
                || ucoAreaKindCount(UCO_AREA_LOCK) != 1
                || ucoAreaKindCount(UCO_AREA_SPHERE)
                != 1
                || ucoAreaKindCount(UCO_AREA_LINE)
                != 1
                || ucoAreaKindCount(UCO_AREA_HOLE)
                != 0) ++bad;
        if (strcmp(ucoPersonal(0).name,
                   uastCantripName(4, 0)) != 0
                || ucoPersonal(0)
                   .school != 6
                || ucoPersonal(0)
                   .areaKind != 10
                || ucoPersonal(0)
                   .areaVal != 0) ++bad;
        if (strcmp(ucoPersonal(1).name,
                   uastCantripName(4, 1)) != 0
                || ucoPersonal(1)
                   .school != 7
                || ucoPersonal(1)
                   .areaKind
                   != UCO_AREA_SPHERE
                || ucoPersonal(1)
                   .areaVal != 3) ++bad;
        if (strcmp(ucoPersonal(2).name,
                   uastCantripName(4, 2)) != 0
                || ucoPersonal(2)
                   .school != 6
                || ucoPersonal(2)
                   .areaKind != 10
                || ucoPersonal(2)
                   .areaVal != 0) ++bad;
        if (strcmp(ucoPersonal(3).name,
                   uastCantripName(4, 3)) != 0
                || ucoPersonal(3)
                   .school != 2
                || ucoPersonal(3)
                   .areaKind
                   != UCO_AREA_LINE
                || ucoPersonal(3)
                   .areaVal != 6) ++bad;
        if (strcmp(ucoPersonal(4).name,
                   uastCantripName(4, 4)) != 0
                || ucoPersonal(4)
                   .school != 6
                || ucoPersonal(4)
                   .areaKind != 1
                || ucoPersonal(4)
                   .areaVal != 1) ++bad;
        if (strcmp(ucoPersonal(5).name,
                   uastCantripName(4, 5)) != 0
                || ucoPersonal(5)
                   .school != 6
                || ucoPersonal(5)
                   .areaKind != 10
                || ucoPersonal(5)
                   .areaVal != 0) ++bad;
        if (strcmp(ucoPersonal(6).name,
                   uastCantripName(4, 6)) != 0
                || ucoPersonal(6)
                   .school != 0
                || ucoPersonal(6)
                   .areaKind != 11
                || ucoPersonal(6)
                   .areaVal != 1) ++bad;
        if (strcmp(ucoPersonal(7).name,
                   uastCantripName(4, 7)) != 0
                || ucoPersonal(7)
                   .school != 6
                || ucoPersonal(7)
                   .areaKind != 10
                || ucoPersonal(7)
                   .areaVal != 0) ++bad;
        if (strcmp(ucoPersonal(8).name,
                   uastCantripName(4, 8)) != 0
                || ucoPersonal(8)
                   .school != 7
                || ucoPersonal(8)
                   .areaKind != 9
                || ucoPersonal(8)
                   .areaVal != 0) ++bad;
        if (strcmp(ucoPersonal(9).name,
                   uastCantripName(4, 9)) != 0
                || ucoPersonal(9)
                   .school != 7
                || ucoPersonal(9)
                   .areaKind != 12
                || ucoPersonal(9)
                   .areaVal != 0) ++bad;
        // ---- the casting times ----
        // (the PDF read resolves the
        // family - R419)

        if (ucoCastTimeDen(0) != 2
                || ucoCastTimeDen(1) != 2
                || ucoCastTimeDen(2) != 2
                || ucoCastTimeDen(3) != 3
                || ucoCastTimeDen(4) != 2
                || ucoCastTimeDen(5) != 2
                || ucoCastTimeDen(6) != 3
                || ucoCastTimeDen(7) != 2) ++bad;

        if (ucoCastTimeDen(8) != 3
                || ucoCastTimeDen(9) != 2) ++bad;

        // ---- the resolved reads (the PDF read - R419)
        if (!ucoRangeUnitIsInch()
                || ucoSlowPoisonDeferDays()
                != 1) ++bad;
        // ---- the mechanics ----
        if (ucoRangeVal() != 1
                || ucoBeeStingPct() != 90
                || ucoSmokepuffColors() != 6) ++bad;
        if (ucoBluelightSphereInches() != 3
                || ucoBluelightRadiusFeet() != 5) ++bad;
        if (ucoFirefingerJetInches() != 6
                || ucoFirefingerSegments() != 1) ++bad;
        if (ucoGnatsDistractMinSegments() != 1
                || ucoGnatsDistractMaxSegments() != 4) ++bad;
        if (ucoSpiderPoisonPct() != 5
                || ucoSpiderSizeMaxInches() != 2
                || ucoSpiderBiteDistractSegments() != 1
                || ucoSpiderPoisonSaveBonus() != 4) ++bad;
        if (ucoSpiderHitLight() != 1
                || ucoSpiderHitHeavy() != 2
                || ucoSpiderSickMinDays() != 1
                || ucoSpiderSickMaxDays() != 4) ++bad;
        if (ucoTweakPortions() != 7
                || ucoTweakDistractSegments() != 1
                || ucoTweakIntThreshold() != 7
                || ucoTweakDice() != 3) ++bad;
        // The band derivations: the
        // gnats distraction opens
        // below its close, the
        // firefinger jet is the
        // one-half foot (twelve
        // halves), the bluelight
        // sphere fits its
        // illumination radius, and
        // the spider damage/sickness
        // bands order themselves.
        if (ucoGnatsDistractMinSegments()
                >= ucoGnatsDistractMaxSegments()
                || ucoFirefingerJetInches() * 2 != 12
                || ucoBluelightSphereInches()
                   >= ucoBluelightRadiusFeet() * 12
                || ucoSpiderHitLight() >= ucoSpiderHitHeavy()
                || ucoSpiderSickMinDays()
                   >= ucoSpiderSickMaxDays()) ++bad;
        printf("R416 UA personal cantrips pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
