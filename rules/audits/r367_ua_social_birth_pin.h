    // ---- R367: the UA campaign social
    // class and birth pin audit ----
    // The UA CAMPAIGN section (pp.
    // 82-83): the SOCIAL CLASS AND RANK
    // - the nine-band dice ladder (LLC
    // 01-04 through UUC 00), the
    // occupation rosters per band (the
    // LLC label cell garbles, flagged),
    // the no-effect-on-starting-money
    // note with the cavalier/paladin
    // exception, the non-human
    // placements (the halfling ULC
    // parenthetical divergence flagged),
    // the one-rank-below profession
    // rule; the CIRCUMSTANCES OF BIRTH -
    // the 13-row birth ladder, the
    // marital status split 01-80/81-00
    // with the one-class-below-the-
    // father read, the racial modifiers
    // (the high-elf sign cell lost,
    // the half-orc +10/+75 split). The
    // R336 seam cross-checks the cavalier
    // money stations against the band
    // names. Both items flip CLOSED; the
    // census 293 -> 294.
    {
        using namespace rules;
        int bad = 0;
        // ---- the uasoc pins ----
            if (uasocBandCount() != 9) ++bad;
            if (uasocLlcLabelCellGarbled()) ++bad;
            if (!uasocTableExcludesPoliticalInfo()) ++bad;
            if (!uasocGuidelinesFollowTheTable()) ++bad;
            if (!uasocDmModelsToMilieu()) ++bad;
            if (!uasocPcStartMoneyUnaffected()) ++bad;
            if (!uasocExceptCavaliersAndPaladins()) ++bad;
            if (!uasocCavPaladinSeeMoneyHeading()) ++bad;
            if (!uasocDwarvesMMC()) ++bad;
            if (!uasocDwarvesGoldGemsReputation()) ++bad;
            if (!uasocWoodElfULC()) ++bad;
            if (!uasocGrayElfLUC()) ++bad;
            if (!uasocGnomeULCToLMC()) ++bad;
            if (!uasocHalflingULC()) ++bad;
            if (uasocHalflingParentheticalDivergence()) ++bad;
            if (!uasocHalfElfSlightlyAboveHuman()) ++bad;
            if (!uasocHalfOrcLLC()) ++bad;
            if (!uasocNonHumanPlacementMilieuDependent()) ++bad;
            if (!uasocProfessionOneRankBelowMinimum()) ++bad;
            if (!uasocFighterRequiresMlcMinimum()) ++bad;
            if (!uasocLlcBornOnlyThiefOrAssassin()) ++bad;
        // ---- the uabirth pins ----
            if (uabirthRowCount() != 13) ++bad;
            if (uabirthMarriedLow() != 1) ++bad;
            if (uabirthMarriedHigh() != 80) ++bad;
            if (uabirthUnmarriedLow() != 81) ++bad;
            if (uabirthUnmarriedHigh() != 100) ++bad;
            if (!uabirthUnmarriedOneClassBelowFather()) ++bad;
            if (uabirthDwarfMod() != -15) ++bad;
            if (uabirthElfDrowMod() != -15) ++bad;
            if (uabirthElfGrayMod() != -30) ++bad;
            if (uabirthElfHighModMagnitude() != 20) ++bad;
            if (uabirthElfHighModSignLost()) ++bad;
            if (uabirthElfWoodMod() != -10) ++bad;
            if (uabirthElfOtherMod() != -15) ++bad;
            if (uabirthGnomeMod() != -20) ++bad;
            if (uabirthHalfElfMod() != -10) ++bad;
            if (uabirthHalflingMod() != -10) ++bad;
            if (uabirthHalfOrcBirthMod() != 10) ++bad;
            if (uabirthHalfOrcMaritalMod() != 75) ++bad;
            if (!uabirthHumanNoMods()) ++bad;
            if (uabirthIntroGarbled()) ++bad;
            if (!uabirthDmDecidesToMilieu()) ++bad;
            if (!uabirthTablesAStartingPoint()) ++bad;
        // ---- the band table ----
            static const int bl[9] = {1, 5, 11, 21,
                36, 56, 88, 97, 100};
            static const int bh[9] = {4, 10, 20, 35,
                55, 87, 96, 99, 100};
            for (int i = 0; i < 9; ++i) {
                if (uasocBandLow(i) != bl[i]) ++bad;
                if (uasocBandHigh(i) != bh[i]) ++bad;
                if (i < 8 && bh[i] + 1 != bl[i + 1])
                    ++bad;
            }
            if (uasocBandCount() != 9) ++bad;
            if (strcmp(uasocBandAbbr(0), "LLC") != 0)
                ++bad;
            if (strcmp(uasocBandAbbr(8), "UUC") != 0)
                ++bad;
            if (strcmp(uasocBandFullName(4),
                    "Middle Middle Class") != 0)
                ++bad;
        // ---- the rosters ----
            static const int rc[9] = {8, 10, 7, 8, 8,
                9, 9, 6, 3};
            int rsum = 0;
            for (int i = 0; i < 9; ++i) {
                if (uasocRosterCount(i) != rc[i])
                    ++bad;
                rsum += uasocRosterCount(i);
                for (int j = 0; j < rc[i]; ++j) {
                    if (uasocRosterName(i, j)[0] == 0)
                        ++bad;
                }
            }
            if (rsum != 68) ++bad;
            if (strcmp(uasocRosterName(0, 5),
                "criminals") != 0) ++bad;
            if (strcmp(uasocRosterName(6, 5),
                "cavaliers") != 0) ++bad;
            if (strcmp(uasocRosterName(6, 6),
                "paladins") != 0) ++bad;
            if (strcmp(uasocRosterName(8, 0),
                "great nobles") != 0) ++bad;
        // ---- the R336 seam ----
            if (cavMoneyStationCount() != 6)
                ++bad;
            if (strcmp(cavMoneyStationName(3),
                    uasocBandFullName(6)) != 0)
                ++bad;
            if (strcmp(cavMoneyStationName(4),
                    uasocBandFullName(7)) != 0)
                ++bad;
            if (strcmp(cavMoneyStationName(5),
                    uasocBandFullName(8)) != 0)
                ++bad;
            if (strncmp(cavMoneyStationName(0),
                    uasocBandFullName(3), 18) != 0)
                ++bad;
            if (!cavMoneyPaladinExceptionNoted())
                ++bad;
        // ---- the birth table ----
            static const int wl[13] = {1, 6, 11, 21,
                36, 51, 66, 81, 86, 91, 95, 98, 100};
            static const int wh[13] = {5, 10, 20, 35,
                50, 65, 80, 85, 90, 94, 97, 99, 100};
            for (int i = 0; i < 13; ++i) {
                if (uabirthRowLow(i) != wl[i]) ++bad;
                if (uabirthRowHigh(i) != wh[i]) ++bad;
                if (i < 12 && wh[i] + 1 != wl[i + 1])
                    ++bad;
            }
            if (uabirthRowCount() != 13)
                ++bad;
            if (strcmp(uabirthOrderLabel(0),
                "Only child") != 0) ++bad;
            if (strcmp(uabirthOrderLabel(12),
                "12th child") != 0) ++bad;
        printf("R367 UA social/birth pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
