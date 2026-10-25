    // ---- R415: the UA
    // person-affecting cantrips
    // pin audit ----
    // The 10 person-affecting
    // descriptions pin: the names
    // cross-check the R341/R401
    // roster live (the scan's
    // "TVvitch" resolves as
    // Twitch via the roster - the
    // independent confirmation),
    // the schools pin per row
    // (Charm AS PRINTED, a NEW
    // code - Giggle prints Charm
    // while Wink prints
    // Enchantment in the same
    // section), the areas pin per
    // row (ZERO area holes; one
    // person and one creature NEW
    // area kinds), the censuses
    // count, the mechanics pin with
    // the yawn band derivation
    // cross-checking itself; census
    // 341 -> 342.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (ucpPersonAffectingCount() != 10)
            ++bad;
        if (uastCantripCount(3) != 10)
            ++bad;
        // ---- the school census ----
        if (ucpSchoolCount(UCP_EVO) != 8
                || ucpSchoolCount(UCP_ABJ) != 0
                || ucpSchoolCount(UCP_ALT) != 0
                || ucpSchoolCount(UCP_ENCH) != 1
                || ucpSchoolCount(UCP_ILL) != 0
                || ucpSchoolCount(UCP_CHARM) != 1) ++bad;
        // ---- the area census ----
        if (ucpAreaKindCount(UCP_AREA_PERSON) != 6
                || ucpAreaKindCount(UCP_AREA_CREATURE) != 4
                || ucpAreaKindCount(UCP_AREA_HOLE) != 0) ++bad;
        if (strcmp(ucpPersonAffecting(0).name,
                   uastCantripName(3, 0)) != 0
                || ucpPersonAffecting(0)
                   .school != 0
                || ucpPersonAffecting(0)
                   .areaKind != 8
                || ucpPersonAffecting(0)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(1).name,
                   uastCantripName(3, 1)) != 0
                || ucpPersonAffecting(1)
                   .school != 0
                || ucpPersonAffecting(1)
                   .areaKind != 8
                || ucpPersonAffecting(1)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(2).name,
                   uastCantripName(3, 2)) != 0
                || ucpPersonAffecting(2)
                   .school != 0
                || ucpPersonAffecting(2)
                   .areaKind != 8
                || ucpPersonAffecting(2)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(3).name,
                   uastCantripName(3, 3)) != 0
                || ucpPersonAffecting(3)
                   .school != 5
                || ucpPersonAffecting(3)
                   .areaKind != 8
                || ucpPersonAffecting(3)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(4).name,
                   uastCantripName(3, 4)) != 0
                || ucpPersonAffecting(4)
                   .school != 0
                || ucpPersonAffecting(4)
                   .areaKind != 8
                || ucpPersonAffecting(4)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(5).name,
                   uastCantripName(3, 5)) != 0
                || ucpPersonAffecting(5)
                   .school != 0
                || ucpPersonAffecting(5)
                   .areaKind != 9
                || ucpPersonAffecting(5)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(6).name,
                   uastCantripName(3, 6)) != 0
                || ucpPersonAffecting(6)
                   .school != 0
                || ucpPersonAffecting(6)
                   .areaKind != 9
                || ucpPersonAffecting(6)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(7).name,
                   uastCantripName(3, 7)) != 0
                || ucpPersonAffecting(7)
                   .school != 0
                || ucpPersonAffecting(7)
                   .areaKind != 9
                || ucpPersonAffecting(7)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(8).name,
                   uastCantripName(3, 8)) != 0
                || ucpPersonAffecting(8)
                   .school != 3
                || ucpPersonAffecting(8)
                   .areaKind != 8
                || ucpPersonAffecting(8)
                   .areaVal != 0) ++bad;
        if (strcmp(ucpPersonAffecting(9).name,
                   uastCantripName(3, 9)) != 0
                || ucpPersonAffecting(9)
                   .school != 0
                || ucpPersonAffecting(9)
                   .areaKind != 9
                || ucpPersonAffecting(9)
                   .areaVal != 0) ++bad;
        // ---- the casting times ----
        // (the PDF read resolves the
        // family - R419)

        if (ucpCastTimeDen(0) != 10
                || ucpCastTimeDen(1) != 10
                || ucpCastTimeDen(2) != 3
                || ucpCastTimeDen(3) != 3
                || ucpCastTimeDen(4) != 10
                || ucpCastTimeDen(5) != 8
                || ucpCastTimeDen(6) != 2
                || ucpCastTimeDen(7) != 3) ++bad;

        if (ucpCastTimeDen(8) != 10
                || ucpCastTimeDen(9) != 8) ++bad;
        // ---- the mechanics ----
        if (ucpBlinkDurationHalfSecs() != 1
                || ucpScratchSeconds() != 1) ++bad;
        if (ucpCoughMinSeconds() != 1
                || ucpCoughMaxSeconds() != 3) ++bad;
        if (ucpGiggleMinSeconds() != 2
                || ucpGiggleMaxSeconds() != 3) ++bad;
        // The cough/giggle bands
        // are distinct and giggle
        // never exceeds cough max.
        if (ucpGiggleMaxSeconds() > ucpCoughMaxSeconds()
                || ucpGiggleMinSeconds()
                   >= ucpGiggleMaxSeconds()) ++bad;
        // ---- the yawn sleep
        // susceptibility ----
        if (ucpYawnWindowRounds() != 2
                || ucpYawnExtraVulnerable() != 1) ++bad;
        if (ucpYawnSleepHdLow() != 4
                || ucpYawnSleepBandLo() != 41
                || ucpYawnSleepBandHi() != 44
                || ucpYawnSleepHdMax() != 52
                || ucpYawnUnaffectedPct() != 50) ++bad;
        // The band derivation: the
        // re-roll band 41..44 sits
        // in the 4 HD tens, opens
        // at +1, closes at +4, and
        // the 52 reach rides the 5
        // HD tens with +2.
        if (ucpYawnSleepBandLo() / 10
                != ucpYawnSleepBandHi() / 10
                || ucpYawnSleepBandLo() % 10 != 1
                || ucpYawnSleepBandHi() % 10 != 4
                || ucpYawnSleepBandHi() / 10
                   != ucpYawnSleepHdLow()
                || ucpYawnSleepHdMax() / 10
                   != ucpYawnSleepHdLow() + 1
                || ucpYawnSleepHdMax() % 10 != 2)
            ++bad;
        printf("R415 UA person-affecting cantrips pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
