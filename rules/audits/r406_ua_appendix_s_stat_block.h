    // ---- R406: the UA Appendix S
    // stat blocks pin audit ----
    // The ungated data round rides
    // the R405 seam: the 23 stat
    // blocks pin their scan-clean
    // numerics (tier, AC, HP, MR,
    // rating, size, the attacks in
    // halves, the damage range, the
    // printed alignment and plane),
    // the tier and rating censuses
    // cross-check the R405 seam
    // live, the hole sentinels
    // record the scan garbles, and
    // the 6985 hit-point sum catches
    // any cell drift; the class
    // lines, the MOVE values and the
    // stat lines stay unpinned;
    // census 332 -> 333.
    {
        using namespace rules;
        int bad = 0;
        // ---- the census ----
        if (uasDeityCount() != 23) ++bad;
        if (uasDeityCount()
                != nhdDeityCount()) ++bad;
        // the tier census: 5/16/2
        if (uasTierCount(UAS_TIER_GREATER)
                != 5) ++bad;
        if (uasTierCount(UAS_TIER_LESSER)
                != 16) ++bad;
        if (uasTierCount(UAS_TIER_DEMI)
                != 2) ++bad;
        if (uasTierCount(UAS_TIER_GREATER)
                + uasTierCount(UAS_TIER_LESSER)
                + uasTierCount(UAS_TIER_DEMI)
                != 23) ++bad;
        // the rating census: VI 10,
        // III 5, IV 1, Nil 6,
        // unrecorded 1 - and the four
        // printed codes match the R405
        // seam live
        if (uasRatingCount(UAS_RATING_VI)
                != 10) ++bad;
        if (uasRatingCount(UAS_RATING_III)
                != 5) ++bad;
        if (uasRatingCount(UAS_RATING_IV)
                != 1) ++bad;
        if (uasRatingCount(UAS_RATING_NIL)
                != 6) ++bad;
        if (uasRatingCount(
                UAS_RATING_UNRECORDED) != 1)
            ++bad;
        if (uasRatingCount(UAS_RATING_VI)
                != nhdPsionicRatingCount(0))
            ++bad;
        if (uasRatingCount(UAS_RATING_III)
                != nhdPsionicRatingCount(1))
            ++bad;
        if (uasRatingCount(UAS_RATING_IV)
                != nhdPsionicRatingCount(2))
            ++bad;
        if (uasRatingCount(UAS_RATING_NIL)
                != nhdPsionicRatingCount(3))
            ++bad;
        // the pantheon slices ride the
        // R405 registry live
        if (uasPantheonSize(0)
                != nhdPantheonSize(0)
                || uasPantheonSize(1)
                    != nhdPantheonSize(1)
                || uasPantheonSize(2)
                    != nhdPantheonSize(2)
                || uasPantheonSize(3)
                    != nhdPantheonSize(3)
                || uasPantheonSize(4)
                    != nhdPantheonSize(4))
            ++bad;
        // ---- the drift catch ----
        if (uasTotalHitPoints() != 6985)
            ++bad;
        // ---- the hole sentinels ----
        if (uasAcHoleCount() != 1
                || uasAtkHoleCount() != 1
                || uasDamageUnrecordedCount()
                    != 4)
            ++bad;
        if (uasStat(8).ac != UAS_AC_HOLE)
            ++bad;
        if (uasStat(19).atkHalves
                != UAS_ATK_HOLE) ++bad;
        // ---- the spot checks ----
        // Clanggedin (the first block)
        if (strcmp(uasStat(0).name,
                   "CLANGGEDIN SILVERBEARD") != 0)
            ++bad;
        if (uasStat(0).ac != -4
                || uasStat(0).hp != 375
                || uasStat(0).mr != 50
                || uasStat(0).tier
                    != UAS_TIER_GREATER
                || uasStat(0).rating
                    != UAS_RATING_VI
                || uasStat(0).size
                    != UAS_SIZE_L
                || uasStat(0).atkHalves != 4
                || uasStat(0).dmgMin != 3
                || uasStat(0).dmgMax != 36)
            ++bad;
        if (strcmp(uasStat(0).align,
                   "Lawful neutral") != 0)
            ++bad;
        if (strcmp(uasStat(0).plane,
                   "Arcadia") != 0) ++bad;
        // Berronar, Hanali, Brandobaris
        if (uasStat(4).hp != 370
                || uasStat(4).mr != 80) ++bad;
        if (uasStat(8).hp != 312
                || uasStat(8).mr != 95
                || uasStat(8).dmgMin != 0
                || uasStat(8).dmgMax != 0)
            ++bad;
        if (uasStat(13).hp != 185
                || uasStat(13).tier
                    != UAS_TIER_DEMI
                || uasStat(13).rating
                    != UAS_RATING_UNRECORDED)
            ++bad;
        // Bahgtru, Shargaas, Luthic
        if (uasStat(18).dmgMin != 10
                || uasStat(18).dmgMax != 60)
            ++bad;
        if (uasStat(19).rating
                != UAS_RATING_IV
                || uasStat(19).ac != 2
                || uasStat(19).dmgMin != 3
                || uasStat(19).dmgMax != 30)
            ++bad;
        if (uasStat(22).ac != 3
                || uasStat(22).hp != 287
                || uasStat(22).dmgMin != 5
                || uasStat(22).dmgMax != 20)
            ++bad;
        if (strcmp(uasStat(22).align,
                   "Lawful evil") != 0) ++bad;
        // Urdlen: the evil gnome
        if (strcmp(uasStat(15).plane,
                   "Abyss") != 0) ++bad;
        printf("R406 UA appendix S stat blocks pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
