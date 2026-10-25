    // ---- R602 DMO world-ratings audit ----
    // THE WORLD RATING TABLES of DMO Chapter 2 (printed pp. 46-54): Table 2
    // the chronological ratings (the 17-row local-time grid, the fast
    // 9-or-less and slow 13-or-more thresholds, the locality doctrine), Table
    // 3 the magical ratings (the 17-row ladder of max spell level, casting
    // multiplier, and modified schools; the spellbook-free and study-free
    // tiers; the demihuman and fantastic deprivation bands; the item-decay
    // and priest-planar doctrines), Table 4 the technological ratings (the
    // eight era thresholds from steel to FTL, the device-decay doctrine, the
    // advanced-tech margin), Table 5 the ecological ratings (the 3x3
    // condition grid, the hazard and paradise bands, the native intolerance),
    // and the quirks doctrine.
    {
        using namespace rules;
        int bad = 0;
    if (delChronoCount() != 17
            || delMagicCount() != 17
            || delEcologyCount() != 3
            || delChronoFastMax() != 9
            || delChronoSlowMin() != 13
            || delMagicNoNinthMax() != 8
            || delMagicSpellbookFreeMin() != 19
            || delMagicStudyFreeMin() != 20
            || delDemihumanDeathSaveMax() != 5
            || delDemihumanMaxPenalty() != 4
            || delFantasticPenaltyStartMax() != 6
            || delFantasticMaxPenalty() != 5
            || delItemPlusLossPerPlane() != 1
            || delMaxPlaneDistance() != 4
            || delPspUnaffectedMin() != 13
            || delPriestLossPerPlane() != 1
            || delPriestCelestiaAbyssLoss() != 7
            || delMajorRaceMinorMin() != 7
            || delMajorRaceMajorMin() != 8
            || delMajorRaceExtraordinaryMin() != 9
            || delNaturalMinorMax() != 3
            || delNaturalMajorMax() != 7
            || delNaturalExtraordinaryMax() != 11
            || delTechSteelMin() != 10
            || delTechFirearmMin() != 14
            || delTechSteamMin() != 15
            || delTechCombustionMin() != 16
            || delTechNuclearMin() != 17
            || delTechFusionMin() != 18
            || delTechRobotMin() != 19
            || delTechFtlMin() != 20
            || delAdvancedTechMagicMargin() != 5
            || delEcologyHazardMax() != 6
            || delEcologyParadiseMin() != 18
            || delEcologyNativeIntoleranceMin() != 16
            || delNativeSevereGap() != 5
            || delNativeHostileGap() != 6
            || delNativeDeadlyGap() != 7
            || !delChronoLocalityDoctrine()
            || !delMagicCastingTimeDoctrine()
            || !delMagicModificationDoctrine()
            || !delPriestPlanarDoctrine()
            || !delPspDoctrine()
            || !delItemDecayDoctrine()
            || !delMagicItemFunctionDoctrine()
            || !delNaturalSpellcastingDoctrine()
            || !delMajorRaceDoctrine()
            || !delTechNotesDoctrine()
            || !delEcologyDoctrine()
            || !delQuirkDoctrine()
        )
            ++bad;
        // the delChronoBaseMag grid
        int CT2[17][3] = {
            {1,1,2},
            {15,1,3},
            {1,2,4},
            {10,2,5},
            {30,2,6},
            {1,3,7},
            {6,3,8},
            {1,4,9},
            {1,5,10},
            {1,6,13},
            {3,6,14},
            {6,6,15},
            {1,7,16},
            {5,7,17},
            {10,7,18},
            {30,7,19},
            {100,7,20},
            };
        for (int b = 0;
             b < delChronoCount();
             ++b) {
            int vals[3];
            vals[0] = delChronoBaseMag(b);
            vals[1] = delChronoBaseUnit(b);
            vals[2] = delChronoRating(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT2[b][c])
                    ++bad;
            }
        }
        // the delMagicRating grid
        int CT3[17][5] = {
            {2,0,0,0,0},
            {3,3,5,6,9},
            {4,4,5,4,9},
            {5,5,5,3,9},
            {6,6,4,3,9},
            {7,7,3,2,7},
            {8,8,2,2,5},
            {9,9,1,1,4},
            {10,10,1,0,0},
            {13,10,1,0,0},
            {14,10,1,1,4},
            {15,10,1,2,5},
            {16,10,1,2,7},
            {17,10,1,3,9},
            {18,10,1,3,9},
            {19,10,1,3,9},
            {20,10,1,3,9},
            };
        for (int b = 0;
             b < delMagicCount();
             ++b) {
            int vals[5];
            vals[0] = delMagicRating(b);
            vals[1] = delMagicMaxLevel(b);
            vals[2] = delMagicCastMult(b);
            vals[3] = delMagicSchoolsMin(b);
            vals[4] = delMagicSchoolsMax(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT3[b][c])
                    ++bad;
            }
        }
        // the delEcologyRollCount grid
        int CT5[3][5] = {
            {1,6,1,2,3},
            {2,4,1,2,3},
            {1,0,1,2,3},
            };
        for (int b = 0;
             b < delEcologyCount();
             ++b) {
            int vals[5];
            vals[0] = delEcologyRollCount(b);
            vals[1] = delEcologyDieSize(b);
            vals[2] = delEcologySeverePeriod(b);
            vals[3] = delEcologyHostilePeriod(b);
            vals[4] = delEcologyDeadlyPeriod(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT5[b][c])
                    ++bad;
            }
        }
        // the delChronoCount pin
    if (delChronoCount() != 17
        )
            ++bad;
        // the delMagicCount pin
    if (delMagicCount() != 17
        )
            ++bad;
        // the delEcologyCount pin
    if (delEcologyCount() != 3
        )
            ++bad;
        // the delChronoFastMax pin
    if (delChronoFastMax() != 9
        )
            ++bad;
        // the delChronoSlowMin pin
    if (delChronoSlowMin() != 13
        )
            ++bad;
        // the delMagicNoNinthMax pin
    if (delMagicNoNinthMax() != 8
        )
            ++bad;
        // the delMagicSpellbookFreeMin pin
    if (delMagicSpellbookFreeMin() != 19
        )
            ++bad;
        // the delMagicStudyFreeMin pin
    if (delMagicStudyFreeMin() != 20
        )
            ++bad;
        // the delDemihumanDeathSaveMax pin
    if (delDemihumanDeathSaveMax() != 5
        )
            ++bad;
        // the delDemihumanMaxPenalty pin
    if (delDemihumanMaxPenalty() != 4
        )
            ++bad;
        // the delFantasticPenaltyStartMax pin
    if (delFantasticPenaltyStartMax() != 6
        )
            ++bad;
        // the delFantasticMaxPenalty pin
    if (delFantasticMaxPenalty() != 5
        )
            ++bad;
        // the delItemPlusLossPerPlane pin
    if (delItemPlusLossPerPlane() != 1
        )
            ++bad;
        // the delMaxPlaneDistance pin
    if (delMaxPlaneDistance() != 4
        )
            ++bad;
        // the delPspUnaffectedMin pin
    if (delPspUnaffectedMin() != 13
        )
            ++bad;
        // the delPriestLossPerPlane pin
    if (delPriestLossPerPlane() != 1
        )
            ++bad;
        // the delPriestCelestiaAbyssLoss pin
    if (delPriestCelestiaAbyssLoss() != 7
        )
            ++bad;
        // the delMajorRaceMinorMin pin
    if (delMajorRaceMinorMin() != 7
        )
            ++bad;
        // the delMajorRaceMajorMin pin
    if (delMajorRaceMajorMin() != 8
        )
            ++bad;
        // the delMajorRaceExtraordinaryMin pin
    if (delMajorRaceExtraordinaryMin() != 9
        )
            ++bad;
        // the delNaturalMinorMax pin
    if (delNaturalMinorMax() != 3
        )
            ++bad;
        // the delNaturalMajorMax pin
    if (delNaturalMajorMax() != 7
        )
            ++bad;
        // the delNaturalExtraordinaryMax pin
    if (delNaturalExtraordinaryMax() != 11
        )
            ++bad;
        // the delTechSteelMin pin
    if (delTechSteelMin() != 10
        )
            ++bad;
        // the delTechFirearmMin pin
    if (delTechFirearmMin() != 14
        )
            ++bad;
        // the delTechSteamMin pin
    if (delTechSteamMin() != 15
        )
            ++bad;
        // the delTechCombustionMin pin
    if (delTechCombustionMin() != 16
        )
            ++bad;
        // the delTechNuclearMin pin
    if (delTechNuclearMin() != 17
        )
            ++bad;
        // the delTechFusionMin pin
    if (delTechFusionMin() != 18
        )
            ++bad;
        // the delTechRobotMin pin
    if (delTechRobotMin() != 19
        )
            ++bad;
        // the delTechFtlMin pin
    if (delTechFtlMin() != 20
        )
            ++bad;
        // the delAdvancedTechMagicMargin pin
    if (delAdvancedTechMagicMargin() != 5
        )
            ++bad;
        // the delEcologyHazardMax pin
    if (delEcologyHazardMax() != 6
        )
            ++bad;
        // the delEcologyParadiseMin pin
    if (delEcologyParadiseMin() != 18
        )
            ++bad;
        // the delEcologyNativeIntoleranceMin pin
    if (delEcologyNativeIntoleranceMin() != 16
        )
            ++bad;
        // the delNativeSevereGap pin
    if (delNativeSevereGap() != 5
        )
            ++bad;
        // the delNativeHostileGap pin
    if (delNativeHostileGap() != 6
        )
            ++bad;
        // the delNativeDeadlyGap pin
    if (delNativeDeadlyGap() != 7
        )
            ++bad;
        // the delChronoLocalityDoctrine pin
    if (delChronoLocalityDoctrine() != 1
        )
            ++bad;
        // the delMagicCastingTimeDoctrine pin
    if (delMagicCastingTimeDoctrine() != 1
        )
            ++bad;
        // the delMagicModificationDoctrine pin
    if (delMagicModificationDoctrine() != 1
        )
            ++bad;
        // the delPriestPlanarDoctrine pin
    if (delPriestPlanarDoctrine() != 1
        )
            ++bad;
        // the delPspDoctrine pin
    if (delPspDoctrine() != 1
        )
            ++bad;
        // the delItemDecayDoctrine pin
    if (delItemDecayDoctrine() != 1
        )
            ++bad;
        // the delMagicItemFunctionDoctrine pin
    if (delMagicItemFunctionDoctrine() != 1
        )
            ++bad;
        // the delNaturalSpellcastingDoctrine pin
    if (delNaturalSpellcastingDoctrine() != 1
        )
            ++bad;
        // the delMajorRaceDoctrine pin
    if (delMajorRaceDoctrine() != 1
        )
            ++bad;
        // the delTechNotesDoctrine pin
    if (delTechNotesDoctrine() != 1
        )
            ++bad;
        // the delEcologyDoctrine pin
    if (delEcologyDoctrine() != 1
        )
            ++bad;
        // the delQuirkDoctrine pin
    if (delQuirkDoctrine() != 1
        )
            ++bad;
        // the C2 world ages a visitor a year while under a minute passes at
        // home (the fast end of the Table 2 grid)
    if (delChronoBaseMag(0) != 1
            || delChronoBaseUnit(0) != 1
            || delChronoRating(0) != 2
        )
            ++bad;
        // the C20 world: one local week equals a hundred base years (the slow
        // end of the grid)
    if (delChronoBaseMag(16) != 100
            || delChronoBaseUnit(16) != 7
            || delChronoRating(16) != 20
        )
            ++bad;
        // the M8 world bars the 9th level and doubles casting times
    if (delMagicMaxLevel(6) != 8
            || delMagicCastMult(6) != 2
        )
            ++bad;
        // the dead-magic M2 world: nothing functions
    if (delMagicMaxLevel(0) != 0
            || delMagicCastMult(0) != 0
        )
            ++bad;
        // the typical M10-12 band: everything works, no school modifications
    if (delMagicMaxLevel(8) != 10
            || delMagicSchoolsMin(8) != 0
            || delMagicSchoolsMax(8) != 0
        )
            ++bad;
        // the deadly ecology: the constitution drain runs per round
    if (delEcologyRollCount(0) != 1
            || delEcologyDieSize(0) != 6
            || delEcologyDeadlyPeriod(0) != 3
        )
            ++bad;
        // the poison save row rolls no dice, one save per period
    if (delEcologyRollCount(2) != 1
            || delEcologyDieSize(2) != 0
            || delEcologySeverePeriod(2) != 1
        )
            ++bad;
        printf("R602 DMO world-ratings audit: bad %d\n", bad);
        if (bad) return 1;
    }
