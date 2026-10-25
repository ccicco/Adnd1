    // ---- R757 OA weapon explanation audit ----
    // OA round one hundred forty-four (capture pp. 294-296): the Explanation
    // of Weapon Properties - the weapons of quality by class, the plus and
    // damage and to-hit grades, the versus smaller and larger, the -1 cursed
    // weapons, and the special properties of pp. 295-296 with the d8
    // detection subtable and the 24-creature slaying list, single-pass pins
    // per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlsSwordQualityValueDie() != 6
            || dlsBowQualityValueDie() != 4
            || dlsMissileQualityPriceMin() != 2
            || dlsMissileQualityPriceMax() != 5
            || dlsMartialArtsPriceMin() != 2
            || dlsMartialArtsPriceMax() != 5
            || dlsNinjaAssembleRounds() != 1
            || dlsCursedReturnRoll() != 1
            || dlsBalanceTightropePct() != 10
            || dlsDancingFightMin() != 2
            || dlsDancingFightMax() != 5
            || dlsDancingStayFt() != 5
            || dlsDetectRowCount() != 8
            || dlsFlameExtraDie() != 4
            || dlsFlameIgnitePct() != 40
            || dlsFlameLightFt() != 15
            || dlsIntelligenceDie() != 6
            || dlsIntelligenceMin() != 12
            || dlsIntelligenceMax() != 17
            || dlsSilenceMovePct() != 15
            || dlsSilenceHidePct() != 20
            || dlsUnbreakableBreakPct() != 75
            || dlsSlayingCreatureCount() != 24
            || !dlsSwordMeleeQuality()
            || !dlsBowQuality()
            || !dlsMissileQuality()
            || !dlsMartialArtsQuality()
            || !dlsNinjaQuality()
            || !dlsPlusGrades()
            || !dlsDamageBonusGrades()
            || !dlsToHitBonusGrades()
            || !dlsVsSmaller()
            || !dlsVsLarger()
            || !dlsCursedUndetectable()
            || !dlsCursedBowsReturn()
            || !dlsCursedMeleePreference()
            || !dlsAccuracyAllShort()
            || !dlsBalanceSaveRegain()
            || !dlsDancingWeapon()
            || !dlsDetectionWeapon()
            || !dlsDisruptionPerDMG()
            || !dlsDistanceDoubleRange()
            || !dlsFlameWeapon()
            || !dlsIntelligenceWeapon()
            || !dlsSilenceWeapon()
            || !dlsSlayingWeapon()
            || !dlsSpeedWeapon()
            || !dlsUnbreakableWeapon()
            || !dlsVenomPerDMG()
            || !dlsRollTwice()
        )
            ++bad;
        // the dlsDetects grid
        int CDetects[8][2] = {
            {1,10},
            {2,10},
            {3,0},
            {4,10},
            {5,1},
            {6,10},
            {7,5},
            {8,10},
            };
        int nDetects[2] = {0,0};
        int eDetects[2] = {0,1};
        for (int b = 0;
             b < dlsDetectRowCount();
             ++b) {
            int vals[2];
            vals[0] = dlsDetectType(b);
            vals[1] = dlsDetectRangeFt(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CDetects[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nDetects[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nDetects[c] != eDetects[c])
                ++bad;
        // the dlsSlayingCreatures grid
        int CSlayingCreatures[24][1] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
            {7},
            {8},
            {9},
            {10},
            {11},
            {12},
            {13},
            {14},
            {15},
            {16},
            {17},
            {18},
            {19},
            {20},
            {21},
            {22},
            {23},
            {24},
            };
        int nSlayingCreatures[1] = {0};
        int eSlayingCreatures[1] = {0};
        for (int b = 0;
             b < dlsSlayingCreatureCount();
             ++b) {
            int vals[1];
            vals[0] = dlsSlayCreatureCode(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CSlayingCreatures[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nSlayingCreatures[c];
            }
        }
        for (int c = 0; c < 1; ++c)
            if (nSlayingCreatures[c] != eSlayingCreatures[c])
                ++bad;
        // the quality and the plus grades, healthy values, each condition
        // false
    if (dlsSwordQualityValueDie() != 6
            || dlsBowQualityValueDie() != 4
            || dlsMissileQualityPriceMin() != 2
            || dlsMissileQualityPriceMax() != 5
            || dlsSwordMeleeQuality() != 1
            || dlsBowQuality() != 1
            || dlsPlusGrades() != 1
            || dlsVsSmaller() != 1
            || dlsVsLarger() != 1
            || dlsCursedReturnRoll() != 1
        )
            ++bad;
        // the specials - the dancing, flame, intelligence, silence, and speed
        // mechanics, healthy values, each condition false
    if (dlsDancingFightMin() != 2
            || dlsDancingFightMax() != 5
            || dlsDancingStayFt() != 5
            || dlsFlameExtraDie() != 4
            || dlsFlameIgnitePct() != 40
            || dlsFlameLightFt() != 15
            || dlsIntelligenceMin() != 12
            || dlsIntelligenceMax() != 17
            || dlsSilenceMovePct() != 15
            || dlsSilenceHidePct() != 20
        )
            ++bad;
        // the subtables - the d8 detection grid and the slaying creature
        // list, audited cell by cell by the table audit
    if (dlsDetectRowCount() != 8
            || dlsDetectType(0) != 1
            || dlsDetectRangeFt(2) != 0
            || dlsDetectRangeFt(6) != 5
            || dlsSlayingCreatureCount() != 24
            || dlsSlayCreatureCode(0) != 1
            || dlsSlayCreatureCode(23) != 24
        )
            ++bad;
        printf("R757 OA weapon explanation audit: bad %d\n", bad);
        if (bad) return 1;
    }
