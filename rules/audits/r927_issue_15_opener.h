    // ---- R927 issue-15 opener audit ----
    // THE DRAGON ISSUE-15 OPENER ROUND - all five engine-relevant chains in
    // one round. CHAIN ONE, Dragon Magic by Michael Benveniste (folio 3,
    // cont. 13; PDF 5-6, 15): the dragon-only spell system, five lists of 11,
    // 12, 13, 13 and 10 spells, the secret-name rule (one service demand, all
    // works dispelled), the polymorph entrapment at 2 and 5 percent per day
    // cumulative with the metallic dragons immune, the Seek spell at 20
    // degrees and 20 percent, the summoning-stone birds (armor class 5, move
    // 4 and 48, 2-12 hit points, talons 1-2, beak 1-6, driven off by strong
    // light, never crossing water, evil dragons only). CHAIN TWO, the
    // Wandering Monster by James Ward (folio 7, PDF 9): the pre-rolled
    // twenty-entry fourth-level list, the appearing bands, hit points, armor
    // classes and dungeon move in feet pinned in the table, the damage lines
    // riding the transcript, the will o wisp armor class minus 8 genuine
    // print. CHAIN THREE, Weather in the Wilderness by David Tillery (folios
    // 14-15, PDF 16-17): the terrain matrix, the weather descriptions with
    // their disease and morale percentages, the six-disease table, the
    // seasonal planner. CHAIN FOUR, the Pits tables by Merferger the 11 and
    // 3/4 Lord of Mecic, alias Richard Morenoff (folio 5, PDF 7): the pit
    // bands, the occupied bands, the animal and insect bands, the specialist
    // bands, the 40 percent poison rule. CHAIN FIVE, the Random Events Table
    // for Settlements by N. Robin Crossby (folio 5, PDF 7): the sixteen
    // events by season. No full-res visual check exists for this issue (the
    // scan is a text-side mistral transcript, no page renders), so the
    // garbled cells pin sentinel, never guessed: the occupied-pit animal
    // lower bound (the shared-35 print), the specialist ranger upper bound
    // (the 91-85 print), the seasonal unusual faces of winter, spring and
    // summer (non-contiguous prints riding the transcript); the disease
    // immunity column prints the percent sign before the digits (the
    // percent-position class, the digits clean and pinned).
    {
        using namespace rules;
        int bad = 0;
    if (drmSpellsLevel1() != 11
            || drmSpellsLevel2() != 12
            || drmSpellsLevel3() != 13
            || drmSpellsLevel4() != 13
            || drmSpellsLevel5() != 10
            || drmSpellsTotal() != 59
            || drmNameServiceDemands() != 1
            || drmPolySelfTrapPercent() != 2
            || drmPolyOtherTrapPercent() != 5
            || drmSeekDirectionErrorDegrees() != 20
            || drmSeekDistanceErrorPercent() != 20
            || drmPointerAdjacentLevelPercent() != 30
            || drmPointerRandomPercent() != 10
            || drmSummonStoneChancePerAge() != 10
            || drmServantsMin() != 4
            || drmServantsMax() != 16
            || drmServantRoundsMin() != 2
            || drmServantRoundsMax() != 12
            || drmServantArmorClass() != 5
            || drmServantMoveGroundInches() != 4
            || drmServantMoveFlyInches() != 48
            || drmServantHpMin() != 2
            || drmServantHpMax() != 12
            || drmServantTalonDamageMin() != 1
            || drmServantTalonDamageMax() != 2
            || drmServantBeakDamageMin() != 1
            || drmServantBeakDamageMax() != 6
            || drmHeatMetalMaxGold() != 1500
            || drmWaterToWineGallonsPerAge() != 20
            || drmWoodToSandCuFtPerAge() != 1
            || drmRockToSandCuFtPerAge() != 1
            || drmCallLightningDice() != 10
            || drmCallLightningDieSides() != 8
            || drmCallLightningMinutesPerBolt() != 10
            || drmAlarmDurationWeeks() != 1
            || drmAlarmTelepathicInches() != 24
            || drmHoldMammalMax() != 4
            || drmHoldMammalRangeInches() != 12
            || drmHoldMammalDurationTurns() != 6
            || drmBindingDurationMinTurns() != 1
            || drmBindingDurationMaxTurns() != 4
            || drmBindingMagicSaves() != 2
            || drmControlWindsSpeedMph() != 15
            || drmControlWindsDirectionDegrees() != 45
            || drmControlWindsDurationTurns() != 6
            || drmControlWindsRadiusInches() != 24
            || drmNegateItemsPerDay() != 1
            || drmNegateDurationMinRounds() != 2
            || drmNegateDurationMaxRounds() != 12
            || drmNegateRangeInches() != 6
            || drmCharmAviansSmallMin() != 2
            || drmCharmAviansSmallMax() != 8
            || drmCharmAviansMediumMin() != 1
            || drmCharmAviansMediumMax() != 3
            || drmCharmAviansManSized() != 1
            || drmCharmAviansRangeInches() != 12
            || drmCharmAviansDurationDays() != 1
            || drmSeeInvisibleRadiusInches() != 6
            || drmSeeOtherPlanesDurationTurns() != 3
            || drmGloomMoralePenalty() != 2
            || drmWallDurationMinTurns() != 3
            || drmWallDurationMaxTurns() != 8
            || drmWeightControlRangeInches() != 12
            || drmWerelightSpreadInches() != 3
            || drmWerelightRangeInches() != 12
            || drmWerelightDurationMinRounds() != 3
            || drmWerelightDurationMaxRounds() != 18
            || drmAnimateDeadHdMin() != 2
            || drmAnimateDeadHdMax() != 16
            || drmAnimateDeadSkeletonHdMax() != 8
            || drmAnimateDeadRangeInches() != 6
            || drmConjureElementalDice() != 16
            || drmCurseBlessLiftHours() != 8
            || drmCurseFullWishesToDispel() != 2
            || drmEvaluateExampleGold() != 30000
            || drmWanderingRows() != 20
            || drmWeatherPatternDieSides() != 6
            || drmWeatherTerrainDieSides() != 8
            || drmDiseaseRows() != 6
            || drmSeasonRows() != 4
            || drmTerrainFaces() != 8
            || drmDenseFogVisibilityFeet() != 30
            || drmLightFogVisibilityFeet() != 180
            || drmLowCloudsVisibilityMiles() != 2
            || drmMediumCloudsVisibilityMiles() != 6
            || drmHighCloudsVisibilityMiles() != 20
            || drmColdHypothermiaPercent() != 15
            || drmColdPneumoniaWeeklyPercent() != 10
            || drmColdFluWeeklyPercent() != 15
            || drmColdColdWeeklyPercent() != 50
            || drmColdWarmPneumoniaPercent() != 2
            || drmColdWarmFluPercent() != 5
            || drmColdWarmColdPercent() != 25
            || drmFrostbiteWeeklyPercent() != 25
            || drmFrostbiteDamageMin() != 1
            || drmFrostbiteDamageMax() != 6
            || drmSnowDiseaseBonusPercent() != 5
            || drmSnowFrostbiteDamageMax() != 12
            || drmThunderLightningDailyPercent() != 2
            || drmThunderUnarmoredDailyPercent() != 1
            || drmLightningDamageMin() != 10
            || drmLightningDamageMax() != 100
            || drmLightningStunDays() != 2
            || drmHeavyRainFluPercent() != 5
            || drmHeavyRainColdPercent() != 15
            || drmHeavyRainMoralePenalty() != 2
            || drmMediumRainColdPercent() != 10
            || drmMediumRainFluPercent() != 1
            || drmMediumRainMoralePenalty() != 1
            || drmLightRainColdPercent() != 5
            || drmHighWindSandstormPercent() != 25
            || drmSandstormSuffocationPercent() != 15
            || drmHotIrritationDailyPercent() != 15
            || drmHotExhaustionDailyPercent() != 15
            || drmHotCombatMaxRounds() != 15
            || drmWarmIrritationPercent() != 10
            || drmCoolColdPercent() != 20
            || drmCoolFluPercent() != 2
            || drmCoolBareWeeklyColdPercent() != 25
            || drmCoolBareWeeklyFluPercent() != 10
            || drmFairMoraleBonus() != 2
            || drmFairCombatBonus() != 1
            || drmColdMoralePenalty() != 1
            || drmColdCombatPenalty() != 1
            || drmHotMoralePenalty() != 2
            || drmHotCombatPenalty() != 2
            || drmHeavyRainMoveDenominator() != 2
            || drmHeavyRainPlateDenominator() != 4
            || drmMediumRainMoveDenominator() != 4
            || drmMediumRainPlateDenominator() != 2
            || drmLightRainPlateDenominator() != 4
            || drmColdSnowExampleHypothermiaPercent() != 35
            || drmColdSnowExampleFluPercent() != 35
            || drmColdSnowExamplePneumoniaPercent() != 25
            || drmColdSnowExampleColdPercent() != 100
            || drmColdSnowExampleFrostbitePercent() != 55
            || drmColdSnowExampleFrostbiteDamageMin() != 2
            || drmColdSnowExampleFrostbiteDamageMax() != 18
            || drmPitBandRows() != 4
            || drmPitOccupantRows() != 5
            || drmPitAnimalRows() != 6
            || drmPitSpecialistRows() != 10
            || drmCitizenCareers() != 12
            || drmPitPoisonPercent() != 40
            || drmSpecialCitizenMax() != 40
            || drmSpecialSpecialistMax() != 80
            || drmFreedMonsterFriendPercent() != 50
            || drmGratitudeDaysMin() != 2
            || drmGratitudeDaysMax() != 20
            || drmFreedLoyalDieMax() != 4
            || drmEventRows() != 16
            || !drmSecretNameDispelsAllWorks()
            || !drmServantEvilOnly()
            || !drmServantDrivenOffByStrongLight()
            || !drmServantsNeverCrossWater()
            || !drmMetallicDragonsPolyImmune()
            || !drmDragonsNeverCharmDragons()
            || !drmAirElementalNeverTurnsOnDragon()
            || !drmPhantasmalForcesAnyFirstLevelSlot()
            || !drmCurseAlwaysComesTrue()
            || !drmCurseNoSavingThrow()
            || !drmAnimateDeadHalfDice()
            || !drmAnimateDeadHalfDamage()
            || !drmReptilesImmobileInCold()
            || !drmReptilesHalfSpeedInCool()
            || !drmReptilesHalfSpeedInHot()
            || !drmFlyingImpossibleDenseFog()
            || !drmWeatherCumulative()
            || !drmMissilesIneffectiveDenseFog()
            || !drmCentipedesAlwaysPoisonous()
            || !drmPitsOpenWideAtBottom()
            || !drmSpecialsStripped()
            || !drmFreedMonsterRemembersFaces()
            || !drmEventsMonthlyPerProvince()
        )
            ++bad;
        // the Ward pre-rolled fourth-level wandering monster list - twenty
        // entries, the uniform columns pinned (appearing band, hit points,
        // armor class, dungeon move in feet) and the damage lines with their
        // special rules riding the transcript, noted never silent; the as-men
        // movement entries pin sentinel rather than a guessed number, and the
        // will o wisp armor class minus 8 is genuine print (folio 7, PDF 9)
        int CWW[20][5] = {
            {1,2,17,5,90},
            {1,4,9,3,120},
            {1,2,12,5,90},
            {1,4,22,5,90},
            {1,6,20,-1,-1},
            {1,4,23,-1,-1},
            {1,4,10,-1,-1},
            {1,4,17,-1,-1},
            {1,4,9,7,90},
            {1,2,15,3,60},
            {1,4,20,3,90},
            {-1,-1,-1,4,-1},
            {1,6,22,4,90},
            {1,4,15,5,120},
            {2,6,22,4,150},
            {4,16,13,5,120},
            {-1,-1,24,5,150},
            {3,12,8,4,30},
            {-1,-1,33,-8,180},
            {-1,-1,19,2,120},
            };
        int nWW[5] = {0,0,0,0,0};
        int eWW[5] = {4,4,1,4,5};
        for (int b = 0;
             b < drmWanderingRows();
             ++b) {
            int vals[5];
            vals[0] = drmWAppearMin(b);
            vals[1] = drmWAppearMax(b);
            vals[2] = drmWHitPoints(b);
            vals[3] = drmWArmorClass(b);
            vals[4] = drmWMoveFeet(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CWW[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nWW[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nWW[c] != eWW[c])
                ++bad;
        // the weather-disease table - pneumonia, heat stroke, hypothermia,
        // irritation, flu and cold, pinned as scanned; the immunity column
        // prints the percent sign before the digits, the digits clean; the
        // heat-stroke and hypothermia fatality footnotes ride the transcript
        // (folio 14, PDF 16)
        int CDI[6][8] = {
            {5,10,100,1,6,10,6,20},
            {-1,1,2,1,1,-1,1,7},
            {5,1,1,0,0,-1,2,15},
            {2,2,20,1,4,-1,1,1},
            {10,2,20,1,8,20,2,15},
            {15,1,10,2,2,25,1,2},
            };
        int nDI[8] = {0,0,0,0,0,0,0,0};
        int eDI[8] = {1,0,0,0,0,3,0,0};
        for (int b = 0;
             b < drmDiseaseRows();
             ++b) {
            int vals[8];
            vals[0] = drmDImmunityPercent(b);
            vals[1] = drmDDurationMinDays(b);
            vals[2] = drmDDurationMaxDays(b);
            vals[3] = drmDIncubationMinDays(b);
            vals[4] = drmDIncubationMaxDays(b);
            vals[5] = drmDCommunicationPercent(b);
            vals[6] = drmDRecoveryWeeks(b);
            vals[7] = drmDFatalityPercent(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CDI[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nDI[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nDI[c] != eDI[c])
                ++bad;
        // the terrain weather matrix - the d8 face by the seven terrains,
        // pinned as the category conversion (1 Clear, 2 Cloudy, 3 Stormy, 4
        // Winds, 5 Unusual), the conversion noted never silent; the companion
        // weather-type table of names rides the transcript (folio 14, PDF 16)
        int CTE[8][7] = {
            {1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1},
            {5,1,1,1,5,1,1},
            {2,2,2,2,2,5,2},
            {2,2,2,5,2,3,3},
            {3,3,3,3,3,4,5},
            {4,3,3,3,3,4,5},
            };
        int nTE[7] = {0,0,0,0,0,0,0};
        int eTE[7] = {0,0,0,0,0,0,0};
        for (int b = 0;
             b < drmTerrainFaces();
             ++b) {
            int vals[7];
            vals[0] = drmTClear(b);
            vals[1] = drmTWoods(b);
            vals[2] = drmTRiver(b);
            vals[3] = drmTSwamp(b);
            vals[4] = drmTMountains(b);
            vals[5] = drmTDesert(b);
            vals[6] = drmTCity(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CTE[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nTE[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nTE[c] != eTE[c])
                ++bad;
        // the seasonal weather planner - the pattern length and the die faces
        // per category for each season; the unusual cells of winter, spring
        // and summer print non-contiguous faces and pin sentinel with the
        // faces riding the transcript, the fall column contiguous 1-10 (folio
        // 15, PDF 17)
        int CSS[4][12] = {
            {1,4,1,4,1,10,1,10,1,10,-1,-1},
            {1,2,2,9,1,10,2,9,1,10,-1,-1},
            {1,6,5,10,1,10,2,9,1,10,-1,-1},
            {1,2,1,10,1,10,1,10,1,10,1,10},
            };
        int nSS[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int eSS[12] = {0,0,0,0,0,0,0,0,0,0,3,3};
        for (int b = 0;
             b < drmSeasonRows();
             ++b) {
            int vals[12];
            vals[0] = drmSWeeksMin(b);
            vals[1] = drmSWeeksMax(b);
            vals[2] = drmSClearMin(b);
            vals[3] = drmSClearMax(b);
            vals[4] = drmSCloudyMin(b);
            vals[5] = drmSCloudyMax(b);
            vals[6] = drmSStormyMin(b);
            vals[7] = drmSStormyMax(b);
            vals[8] = drmSWindsMin(b);
            vals[9] = drmSWindsMax(b);
            vals[10] = drmSUnusualMin(b);
            vals[11] = drmSUnusualMax(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CSS[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nSS[c];
            }
        }
        for (int c = 0; c < 12; ++c)
            if (nSS[c] != eSS[c])
                ++bad;
        // the Crossby random events table for settlements - the sixteen
        // events by season, the 00 faces pinned as 100; the dash cells pin
        // sentinel, never guessed (folio 5, PDF 7)
        int CEV[16][8] = {
            {1,83,1,79,1,79,1,80},
            {84,84,80,81,80,80,-1,-1},
            {-1,-1,-1,-1,81,81,81,85},
            {85,86,82,82,82,82,86,87},
            {87,87,83,83,83,83,88,89},
            {-1,-1,-1,-1,84,85,-1,-1},
            {-1,-1,-1,-1,86,87,-1,-1},
            {88,88,84,84,88,88,90,90},
            {89,89,85,85,89,89,91,91},
            {90,90,86,86,90,90,92,92},
            {91,91,87,87,91,91,93,93},
            {92,94,88,90,92,92,94,94},
            {95,96,91,92,93,93,95,95},
            {97,97,93,95,94,95,96,96},
            {98,99,96,98,96,98,97,98},
            {100,100,99,100,99,100,99,100},
            };
        int nEV[8] = {0,0,0,0,0,0,0,0};
        int eEV[8] = {3,3,3,3,0,0,3,3};
        for (int b = 0;
             b < drmEventRows();
             ++b) {
            int vals[8];
            vals[0] = drmESpringMin(b);
            vals[1] = drmESpringMax(b);
            vals[2] = drmESummerMin(b);
            vals[3] = drmESummerMax(b);
            vals[4] = drmEAutumnMin(b);
            vals[5] = drmEAutumnMax(b);
            vals[6] = drmEWinterMin(b);
            vals[7] = drmEWinterMax(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CEV[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nEV[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nEV[c] != eEV[c])
                ++bad;
        // the main pit table - empty 01-60, occupied 61-95, teleporting
        // 96-98, bottomless 99-00 (folio 5, PDF 7)
        int CPB[4][2] = {
            {1,60},
            {61,95},
            {96,98},
            {99,100},
            };
        int nPB[2] = {0,0};
        int ePB[2] = {0,0};
        for (int b = 0;
             b < drmPitBandRows();
             ++b) {
            int vals[2];
            vals[0] = drmPBandMin(b);
            vals[1] = drmPBandMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CPB[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nPB[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nPB[c] != ePB[c])
                ++bad;
        // the occupied-pit table - spikes, animal or insect, teleporting pit,
        // monster, special; the animal lower bound pins sentinel for the
        // shared-35 print, the 40 percent poison asterisk rule pinned as a
        // const (folio 5, PDF 7)
        int CPO[5][2] = {
            {1,35},
            {-1,65},
            {66,70},
            {71,90},
            {91,100},
            };
        int nPO[2] = {0,0};
        int ePO[2] = {1,0};
        for (int b = 0;
             b < drmPitOccupantRows();
             ++b) {
            int vals[2];
            vals[0] = drmPOccMin(b);
            vals[1] = drmPOccMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CPO[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nPO[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nPO[c] != ePO[c])
                ++bad;
        // the animal and insect subtable of the occupied pit - six bands, the
        // snakes, lizards and serpents carrying the 40 percent poison
        // asterisk, the centipedes always poisonous (folio 5, PDF 7)
        int CPA[6][2] = {
            {1,35},
            {36,45},
            {46,55},
            {56,70},
            {71,85},
            {86,100},
            };
        int nPA[2] = {0,0};
        int ePA[2] = {0,0};
        for (int b = 0;
             b < drmPitAnimalRows();
             ++b) {
            int vals[2];
            vals[0] = drmPAnimalMin(b);
            vals[1] = drmPAnimalMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CPA[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nPA[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nPA[c] != ePA[c])
                ++bad;
        // the specialist subtable of the special pit - magic-user, fighter,
        // cleric, thief, alchemist, druid, monk, assassin, ranger, scribe;
        // the ranger upper bound prints the 91-85 garble and pins sentinel,
        // never guessed (folio 5, PDF 7)
        int CPS[10][2] = {
            {1,15},
            {16,50},
            {51,60},
            {61,70},
            {71,75},
            {76,80},
            {81,85},
            {86,90},
            {91,-1},
            {96,100},
            };
        int nPS[2] = {0,0};
        int ePS[2] = {0,1};
        for (int b = 0;
             b < drmPitSpecialistRows();
             ++b) {
            int vals[2];
            vals[0] = drmPSpecMin(b);
            vals[1] = drmPSpecMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CPS[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nPS[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nPS[c] != ePS[c])
                ++bad;
        // the dragon magic lists - 11, 12, 13, 13 and 10 spells across the
        // five levels, 59 total, the polymorph entrapment 2 and 5 percent,
        // the summoning stone 10 percent per age, the secret name granting
        // one service (folio 3)
    if (drmSpellsLevel1() != 11
            || drmSpellsLevel2() != 12
            || drmSpellsLevel3() != 13
            || drmSpellsLevel4() != 13
            || drmSpellsLevel5() != 10
            || drmSpellsTotal() != 59
            || drmPolySelfTrapPercent() != 2
            || drmPolyOtherTrapPercent() != 5
            || drmSummonStoneChancePerAge() != 10
            || drmNameServiceDemands() != 1
        )
            ++bad;
        // the summoning-stone birds - armor class 5, move 4 over ground and
        // 48 aloft, 2-12 hit points, the beak to 6, only evil dragons
        // summoning, never crossing water, the metallic dragons immune to the
        // polymorph entrapment (folio 3)
    if (drmServantArmorClass() != 5
            || drmServantMoveGroundInches() != 4
            || drmServantMoveFlyInches() != 48
            || drmServantHpMin() != 2
            || drmServantHpMax() != 12
            || drmServantBeakDamageMax() != 6
            || drmServantEvilOnly() != 1
            || drmServantsNeverCrossWater() != 1
            || drmMetallicDragonsPolyImmune() != 1
        )
            ++bad;
        // the weather ink - the fog visibilities 30 and 180 feet, the
        // high-cloud 20 miles, the thunderstorm lightning 2 percent and 1
        // percent unarmored, the 2-day stun, the reptile freeze in cold,
        // everything cumulative (folios 14-15)
    if (drmDenseFogVisibilityFeet() != 30
            || drmLightFogVisibilityFeet() != 180
            || drmHighCloudsVisibilityMiles() != 20
            || drmThunderLightningDailyPercent() != 2
            || drmThunderUnarmoredDailyPercent() != 1
            || drmLightningStunDays() != 2
            || drmReptilesImmobileInCold() != 1
            || drmWeatherCumulative() != 1
        )
            ++bad;
        // the pit ink - the 40 percent poison asterisk, the special bands to
        // 40 and 80, the freed monster 50 percent friendly, the 2-20 day
        // gratitude, the twelve citizen careers (folio 5)
    if (drmPitPoisonPercent() != 40
            || drmSpecialCitizenMax() != 40
            || drmSpecialSpecialistMax() != 80
            || drmFreedMonsterFriendPercent() != 50
            || drmGratitudeDaysMin() != 2
            || drmGratitudeDaysMax() != 20
            || drmCitizenCareers() != 12
        )
            ++bad;
        // the wandering list - the doppleganger 17 hit points, armor class 5,
        // 90 feet; the will o wisp armor class minus 8 genuine print, 33 hit
        // points, 180 feet (folio 7)
    if (drmWHitPoints(0) != 17
            || drmWArmorClass(0) != 5
            || drmWMoveFeet(0) != 90
            || drmWArmorClass(18) != -8
            || drmWHitPoints(18) != 33
            || drmWMoveFeet(18) != 180
        )
            ++bad;
        // the wandering list tail - the blink dogs 4-16 appearing, 13 hit
        // points; the rust monster 19 hit points, armor class 2, 120 feet
        // (folio 7)
    if (drmWAppearMin(15) != 4
            || drmWAppearMax(15) != 16
            || drmWHitPoints(15) != 13
            || drmWArmorClass(19) != 2
            || drmWMoveFeet(19) != 120
            || drmWHitPoints(19) != 19
        )
            ++bad;
        // the pneumonia row - 5 percent immunity (the percent-position print,
        // digits clean), 10-100 days duration, 10 percent communication, 6
        // weeks recovery, 20 percent fatal (folio 14)
    if (drmDImmunityPercent(0) != 5
            || drmDDurationMinDays(0) != 10
            || drmDDurationMaxDays(0) != 100
            || drmDCommunicationPercent(0) != 10
            || drmDRecoveryWeeks(0) != 6
            || drmDFatalityPercent(0) != 20
        )
            ++bad;
        // the fatality ladder - heat stroke 7, hypothermia 15, irritation 1,
        // flu 15, cold 2 percent; the cold 15 percent immunity and 25 percent
        // communication (folio 14)
    if (drmDFatalityPercent(1) != 7
            || drmDFatalityPercent(2) != 15
            || drmDFatalityPercent(3) != 1
            || drmDFatalityPercent(4) != 15
            || drmDFatalityPercent(5) != 2
            || drmDImmunityPercent(5) != 15
            || drmDCommunicationPercent(5) != 25
        )
            ++bad;
        // the terrain matrix - the clear terrain unusual at face 4, the swamp
        // unusual at 6, the desert stormy at 6 and winds at 7-8, the city
        // stormy at 6 and unusual at 7-8 (folio 14)
    if (drmTClear(3) != 5
            || drmTSwamp(5) != 5
            || drmTDesert(5) != 3
            || drmTDesert(7) != 4
            || drmTCity(5) != 3
            || drmTCity(6) != 5
        )
            ++bad;
        // the seasonal planner - the pattern lengths winter 1-4, spring 1-2,
        // summer 1-6 weeks, the summer clear faces 5-10, the spring 2-9, the
        // fall unusual contiguous 1-10 (folio 15)
    if (drmSWeeksMax(0) != 4
            || drmSWeeksMax(1) != 2
            || drmSWeeksMax(2) != 6
            || drmSClearMin(2) != 5
            || drmSClearMax(2) != 10
            || drmSClearMin(1) != 2
            || drmSUnusualMin(3) != 1
            || drmSUnusualMax(3) != 10
        )
            ++bad;
        // the settlements events - the no-event band spring 01-83, summer and
        // autumn 01-79, winter 01-80; the border raids spring 92-94, summer
        // 88-90 (folio 5)
    if (drmESpringMax(0) != 83
            || drmESummerMax(0) != 79
            || drmEAutumnMax(0) != 79
            || drmEWinterMax(0) != 80
            || drmESpringMin(11) != 92
            || drmESpringMax(11) != 94
            || drmESummerMax(11) != 90
        )
            ++bad;
        // the events tail - the more-than-one event at 00 (pinned 100),
        // summer and winter 99; the plague summer 93, winter 96 (folio 5)
    if (drmESpringMin(15) != 100
            || drmEWinterMax(15) != 100
            || drmESummerMin(15) != 99
            || drmEWinterMin(15) != 99
            || drmESummerMin(13) != 93
            || drmEWinterMax(13) != 96
        )
            ++bad;
        // the pit bands - empty to 60, occupied to 95, teleporting to 98,
        // bottomless 99-100; the spikes to 35, the animal band to 65 with its
        // lower bound sentinel (the shared-35 print); the ranger upper bound
        // sentinel (the 91-85 print), the scribe to 100 (folio 5)
    if (drmPBandMax(0) != 60
            || drmPBandMax(1) != 95
            || drmPBandMax(2) != 98
            || drmPBandMax(3) != 100
            || drmPOccMax(0) != 35
            || drmPOccMax(1) != 65
            || drmPOccMin(1) != -1
            || drmPSpecMax(8) != -1
            || drmPSpecMax(9) != 100
        )
            ++bad;
        // the animal and insect bands - snakes to 35, lizards to 45, the
        // giant tick to 55, the giant serpent to 70, the giant weasels to 85,
        // the centipedes to 100, always poisonous (folio 5)
    if (drmPAnimalMax(0) != 35
            || drmPAnimalMax(1) != 45
            || drmPAnimalMax(2) != 55
            || drmPAnimalMax(3) != 70
            || drmPAnimalMax(4) != 85
            || drmPAnimalMax(5) != 100
            || drmCentipedesAlwaysPoisonous() != 1
        )
            ++bad;
        printf("R927 issue-15 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
