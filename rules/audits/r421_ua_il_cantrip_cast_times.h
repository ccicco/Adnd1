    // ---- R421: the IL cantrip
    // cast-times pin audit ----
    // The PDF read (book pp. 65-66)
    // resolves the whole IL cantrip hole
    // ledger: the eight casting-time
    // cells print clean, unit fractions
    // one segment over the denominator
    // (colored lights, dim, haze and
    // mirage at 1/2; rainbow at 1/3;
    // mask, noise and the two-d-lusion
    // at 1/8 - the census 4/1/3, every
    // denominator inside the 2..10 band
    // the p. 45 header prints); the
    // mirage and two-d-lusion school
    // cells print (Illusion); the areas
    // pin (the mirage 2 sq. inches, the
    // two-d-lusion 4 sq. inches); the
    // mirage somatic tail reads clean
    // (a word or two then a single pass,
    // kept by concentration alone); the
    // colored-lights reflection sentence
    // pins (reflections beyond 1 inch,
    // detection beyond 3 inches); the
    // haze area decode confirms (the 1"
    // cube prints clean); and the clean
    // p. 31 read resolves the R342 IL
    // cantrip column - the eight names,
    // cross-checking the description
    // roster row for row. The IL cantrip
    // descriptions now stand hole-free;
    // census 346 -> 347.
    {
        using namespace rules;
        int bad = 0;
        if (uailcCastTimeDenCount(2) != 4
                || uailcCastTimeDenCount(3) != 1
                || uailcCastTimeDenCount(8) != 3)
            ++bad;
        if (uailcCastTimeDenCount(2)
                + uailcCastTimeDenCount(3)
                + uailcCastTimeDenCount(8)
                != 8) ++bad;
        // the 2..10 norm band
        for (int i = 0; i < 8; ++i)
            if (uailcCastTimeDen(i) < 2
                || uailcCastTimeDen(i) > 10)
                ++bad;
        // the resolved reads
        if (uailcLightsReflectionBeyondInches()
                != 1
                || uailcLightsDetectedBeyondInches()
                != 3
                || !uailcMirageSchoolIsIllusion()
                || uailcMirageAoeSquareInches() != 2
                || !uailcMirageWordOrTwoThenSinglePass()
                || !uailcMirageKeptByConcentrationAlone()
                || !uailcTwodSchoolIsIllusion()
                || uailcTwodAoeSquareInches() != 4)
            ++bad;
        // the R342 IL cantrip column:
        // the eight names cross-check
        // the description roster row for
        // row (each table name is the
        // prefix of its description
        // name, in order)
        if (uas2IlCantripCount() != 8)
            ++bad;
        if (strncmp(uailcLightsName(),
                    uas2IlCantripName(0),
                    strlen(uas2IlCantripName(0)))
                != 0
                || strncmp(uailcDimName(),
                    uas2IlCantripName(1),
                    strlen(uas2IlCantripName(1)))
                != 0
                || strncmp(uailcHazeName(),
                    uas2IlCantripName(2),
                    strlen(uas2IlCantripName(2)))
                != 0
                || strncmp(uailcMaskName(),
                    uas2IlCantripName(3),
                    strlen(uas2IlCantripName(3)))
                != 0
                || strcmp(uailcMirageName(),
                    uas2IlCantripName(4))
                != 0
                || strncmp(uailcNoiseName(),
                    uas2IlCantripName(5),
                    strlen(uas2IlCantripName(5)))
                != 0
                || strncmp(uailcRainbowName(),
                    uas2IlCantripName(6),
                    strlen(uas2IlCantripName(6)))
                != 0
                || strcmp(uailcTwodName(),
                    uas2IlCantripName(7))
                != 0) ++bad;
        // the per-row denominator pins
        // - fail on any wrong cell (the
        // mirror eval)
        if (uailcCastTimeDen(0) != 2
                || uailcCastTimeDen(1) != 2
                || uailcCastTimeDen(2) != 2
                || uailcCastTimeDen(3) != 8
                || uailcCastTimeDen(4) != 2
                || uailcCastTimeDen(5) != 8
                || uailcCastTimeDen(6) != 3
                || uailcCastTimeDen(7) != 8)
            ++bad;
        printf("R421 UA IL cantrip cast-times pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
