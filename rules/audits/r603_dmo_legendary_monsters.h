    // ---- R603 DMO legendary-monsters audit ----
    // THE MONSTER TAIL of DMO Chapter 2 (printed pp. 57-66): the
    // altering-monsters doctrine (the +/-1/2/3 modifier applied throughout,
    // the hit-point and damage floors, the THACO and save deltas with the 20
    // ceiling and the 3 floor, the XP floor at 1-1, the unchanged
    // characteristics, the size-shift option), the six ability-score grids of
    // Tables 6-11 (13 roll bands by the size and intelligence columns, the
    // exceptional-strength encoding, the rust monster reads), and the eleven
    // legendary-rank tables 12-22 (the AC and hit-die ladder with the area
    // multiplier, the breath averages and sizes, the disease onset and
    // fatality dice, the fear radius and saves, the crush dice, the wounding
    // bleed, the melee bonuses, the movement percentages, the gaze saves, the
    // magic resistance, the regeneration rates with the lesser-scion delay).
    {
        using namespace rules;
        int bad = 0;
    if (denAbilityRowCount() != 13
            || denRankCount() != 5
            || denAlterMax() != 3
            || denHpFloor() != 1
            || denDamageFloor() != 1
            || denSaveCeiling() != 20
            || denSaveFloor() != 3
            || denXpHdFloor() != 1
            || denSizeShiftModifier() != 3
            || denAbilityRollDie() != 6
            || denAbilityRollCount() != 3
            || denWeightAllowLarge() != 35
            || denWeightAllowHuge() != 70
            || denWeightAllowGargantuan() != 105
            || denBendBarsLargePct() != 5
            || denBendBarsHugePct() != 10
            || denBendBarsGargantuanPct() != 20
            || denLanguageGap() != 3
            || denLesserScionPowersMin() != 2
            || denLesserScionPowersMax() != 3
            || denLesserScionRollDie() != 4
            || denLesserScionRollCount() != 3
            || denLesserScionRollBonus() != 4
            || denScionPowersMin() != 3
            || denScionPowersMax() != 4
            || denScionRollDie() != 6
            || denScionRollCount() != 2
            || denScionRollBonus() != 6
            || denElderPowersMin() != 3
            || denElderPowersMax() != 5
            || denElderRollDie() != 10
            || denElderRollCount() != 1
            || denElderRollBonus() != 8
            || denGreatElderPowersMin() != 4
            || denGreatElderPowersMax() != 6
            || denGreatElderRollDie() != 10
            || denGreatElderRollCount() != 1
            || denGreatElderRollBonus() != 8
            || denParagonPowersMin() != 5
            || denParagonPowersMax() != 7
            || denParagonRollDie() != 8
            || denParagonRollCount() != 1
            || denParagonRollBonus() != 10
            || denFixedHpPerExtraDie() != 5
            || denBreathPerDayMin() != 3
            || denBreathPerDayMax() != 5
            || denBreathWaitRoundsMin() != 1
            || denBreathWaitRoundsMax() != 2
            || denParagonBreathHalfPerHd() != 45
            || denAvgD4Half() != 25
            || denAvgD6Half() != 35
            || denAvgD8Half() != 45
            || denAvgD10Half() != 55
            || denAvgD12Half() != 65
            || denAvgD20Half() != 105
            || denCloudWidthFt() != 50
            || denCloudHeightFt() != 40
            || denConeMouthFt() != 5
            || denConeApexFt() != 30
            || denLineWidthFt() != 5
            || denLineHeightFt() != 5
            || denDiseaseCheckDie() != 100
            || denChillsRoundsDie() != 4
            || denChillsRoundsCount() != 2
            || denChillsPenalty() != 4
            || denDeliriumSnapRoll() != 9
            || denFeverConsciousRoll() != 9
            || denCauseFearHdMax() != 4
            || denCauseFearLevelMax() != 4
            || denCauseFearFleeDie() != 4
            || denCauseFearFleeCount() != 2
            || denCrushHeightMin() != 30
            || denCrushTwoSizePenalty() != 4
            || denCrushThreeSizePenalty() != 8
            || denExistingGazeParagonPenalty() != 8
            || !denSameModifierThroughout()
            || !denUnchangedCharacteristics()
            || !denAbilityWarriorBonuses()
            || !denDamageTotalNotPerDie()
            || !denDexMovesBonus()
            || !denNonhumanoidDoctrine()
            || !denRankPotencyDoctrine()
            || !denExistingBreathNextRank()
            || !denGazeEffortless()
            || !denCrushFullMovement()
            || !denCrushOverrunNoAoo()
            || !denWoundNoRegen()
            || !denLesserRegenBar()
            || !denEnhancedMovementRoundsUp()
        )
            ++bad;
        // the denStrScore grid
        int CT6[13][6] = {
            {2,4,6,13,15,18},
            {3,5,7,14,17,1801},
            {4,6,8,15,18,1851},
            {5,7,9,16,1801,1876},
            {6,8,10,17,1851,1891},
            {7,9,11,18,1876,1800},
            {8,10,12,1801,1891,19},
            {10,11,13,1851,1800,20},
            {11,12,14,1876,19,21},
            {12,13,15,1891,20,22},
            {13,14,16,1800,21,23},
            {14,15,17,19,22,24},
            {15,16,18,20,23,25},
            };
        for (int b = 0;
             b < denAbilityRowCount();
             ++b) {
            int vals[6];
            vals[0] = denStrT(b);
            vals[1] = denStrS(b);
            vals[2] = denStrM(b);
            vals[3] = denStrL(b);
            vals[4] = denStrH(b);
            vals[5] = denStrG(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT6[b][c])
                    ++bad;
            }
        }
        // the denDexScore grid
        int CT7[13][6] = {
            {13,11,9,7,5,3},
            {14,12,10,8,6,4},
            {15,13,11,9,7,5},
            {16,14,12,10,8,6},
            {17,15,13,11,9,7},
            {18,16,14,12,10,8},
            {19,17,15,13,11,9},
            {20,18,16,14,12,10},
            {21,19,17,15,13,11},
            {22,20,18,16,14,12},
            {23,21,19,17,15,13},
            {24,22,20,18,16,14},
            {25,23,21,19,17,15},
            };
        for (int b = 0;
             b < denAbilityRowCount();
             ++b) {
            int vals[6];
            vals[0] = denDexT(b);
            vals[1] = denDexS(b);
            vals[2] = denDexM(b);
            vals[3] = denDexL(b);
            vals[4] = denDexH(b);
            vals[5] = denDexG(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT7[b][c])
                    ++bad;
            }
        }
        // the denConScore grid
        int CT8[13][6] = {
            {3,5,7,9,11,13},
            {4,6,8,10,12,14},
            {5,7,9,11,13,15},
            {6,8,10,12,14,16},
            {7,9,11,13,15,17},
            {8,10,12,14,16,18},
            {9,11,13,15,17,19},
            {10,12,14,16,18,20},
            {11,13,15,17,19,21},
            {12,14,16,18,20,22},
            {13,15,17,19,21,23},
            {14,16,18,20,22,24},
            {15,17,19,21,23,25},
            };
        for (int b = 0;
             b < denAbilityRowCount();
             ++b) {
            int vals[6];
            vals[0] = denConT(b);
            vals[1] = denConS(b);
            vals[2] = denConM(b);
            vals[3] = denConL(b);
            vals[4] = denConH(b);
            vals[5] = denConG(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT8[b][c])
                    ++bad;
            }
        }
        // the denIntScore grid
        int CT9[13][10] = {
            {1,1,3,6,7,9,10,13,15,17},
            {1,1,3,7,7,10,11,14,16,18},
            {1,1,4,7,8,11,13,15,17,19},
            {1,1,4,8,8,11,13,16,17,19},
            {1,2,5,8,9,12,14,16,18,20},
            {1,2,5,9,9,12,14,17,18,20},
            {1,3,6,9,11,13,15,17,19,21},
            {1,3,6,10,11,13,15,18,19,21},
            {2,4,7,10,12,14,16,19,20,22},
            {2,4,7,11,12,15,17,20,21,22},
            {3,5,8,11,13,16,18,21,22,23},
            {3,5,8,12,14,17,19,22,23,24},
            {4,6,9,13,15,19,20,23,24,25},
            };
        for (int b = 0;
             b < denAbilityRowCount();
             ++b) {
            int vals[10];
            vals[0] = denIntA(b);
            vals[1] = denIntS(b);
            vals[2] = denIntL(b);
            vals[3] = denIntAv(b);
            vals[4] = denIntV(b);
            vals[5] = denIntH(b);
            vals[6] = denIntE(b);
            vals[7] = denIntG(b);
            vals[8] = denIntSg(b);
            vals[9] = denIntGo(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CT9[b][c])
                    ++bad;
            }
        }
        // the denWisScore grid
        int CT10[13][10] = {
            {1,2,3,6,8,10,12,14,16,18},
            {1,2,3,6,8,10,12,14,16,18},
            {1,2,4,7,9,11,13,15,17,19},
            {2,3,4,7,9,11,13,15,17,19},
            {2,3,5,8,10,12,14,16,18,20},
            {2,3,5,8,10,12,14,16,18,20},
            {3,4,6,9,11,13,15,17,19,21},
            {3,4,6,9,11,13,15,17,19,21},
            {3,4,7,10,12,14,16,18,20,22},
            {4,5,7,10,12,14,16,18,20,22},
            {4,5,8,11,13,15,17,19,21,23},
            {4,5,8,11,13,16,18,20,22,24},
            {5,6,9,12,14,17,19,21,23,25},
            };
        for (int b = 0;
             b < denAbilityRowCount();
             ++b) {
            int vals[10];
            vals[0] = denWisA(b);
            vals[1] = denWisS(b);
            vals[2] = denWisL(b);
            vals[3] = denWisAv(b);
            vals[4] = denWisV(b);
            vals[5] = denWisH(b);
            vals[6] = denWisE(b);
            vals[7] = denWisG(b);
            vals[8] = denWisSg(b);
            vals[9] = denWisGo(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CT10[b][c])
                    ++bad;
            }
        }
        // the denChaScore grid
        int CT11[13][10] = {
            {1,1,3,6,8,11,13,15,17,19},
            {1,1,3,6,8,11,13,15,17,19},
            {1,1,4,7,9,12,14,16,18,20},
            {1,1,4,7,9,12,14,16,18,20},
            {1,2,5,8,10,13,15,17,19,21},
            {1,2,5,8,10,13,15,17,19,21},
            {1,3,6,9,11,14,16,18,20,22},
            {1,3,6,9,11,14,16,18,20,22},
            {1,4,7,10,12,15,17,19,21,23},
            {2,4,7,10,12,15,17,19,21,23},
            {2,5,8,11,13,16,18,20,22,24},
            {3,5,8,11,13,16,18,20,22,24},
            {3,6,9,12,14,17,19,21,23,25},
            };
        for (int b = 0;
             b < denAbilityRowCount();
             ++b) {
            int vals[10];
            vals[0] = denChaA(b);
            vals[1] = denChaS(b);
            vals[2] = denChaL(b);
            vals[3] = denChaAv(b);
            vals[4] = denChaV(b);
            vals[5] = denChaH(b);
            vals[6] = denChaE(b);
            vals[7] = denChaG(b);
            vals[8] = denChaSg(b);
            vals[9] = denChaGo(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CT11[b][c])
                    ++bad;
            }
        }
        // the denLegendBase grid
        int CT12[5][3] = {
            {-4,5,15},
            {-6,10,20},
            {-8,15,25},
            {-10,20,30},
            {-12,25,35},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[3];
            vals[0] = denLegendAcMod(b);
            vals[1] = denLegendHdBonus(b);
            vals[2] = denLegendMult(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT12[b][c])
                    ++bad;
            }
        }
        // the denBreath grid
        int CT13[5][6] = {
            {26,35,-2,30,40,60},
            {36,45,-3,40,55,80},
            {46,55,-4,50,70,100},
            {56,65,-5,60,85,120},
            {66,75,-6,70,100,140},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[6];
            vals[0] = denBreathDmgLow(b);
            vals[1] = denBreathDmgHigh(b);
            vals[2] = denBreathSave(b);
            vals[3] = denBreathCloudFt(b);
            vals[4] = denBreathConeFt(b);
            vals[5] = denBreathLineFt(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT13[b][c])
                    ++bad;
            }
        }
        // the denDisease grid
        int CT14[5][6] = {
            {1,4,5,2,4,6},
            {1,4,4,2,6,5},
            {1,4,3,2,6,4},
            {1,4,2,2,4,3},
            {1,4,1,1,4,2},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[6];
            vals[0] = denDiseaseOnsetCount(b);
            vals[1] = denDiseaseOnsetDie(b);
            vals[2] = denDiseaseOnsetUnit(b);
            vals[3] = denDiseaseFatalCount(b);
            vals[4] = denDiseaseFatalDie(b);
            vals[5] = denDiseaseFatalUnit(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT14[b][c])
                    ++bad;
            }
        }
        // the denFear grid
        int CT15[5][2] = {
            {30,0},
            {35,-1},
            {40,-2},
            {45,-3},
            {50,-4},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[2];
            vals[0] = denFearRadiusFt(b);
            vals[1] = denFearSave(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT15[b][c])
                    ++bad;
            }
        }
        // the denCrush grid
        int CT16[5][3] = {
            {10,3,8},
            {15,4,8},
            {20,5,8},
            {25,6,8},
            {30,7,8},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[3];
            vals[0] = denCrushRadiusFt(b);
            vals[1] = denCrushDice(b);
            vals[2] = denCrushDieSize(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT16[b][c])
                    ++bad;
            }
        }
        // the denWound grid
        int CT17[5][2] = {
            {0,0},
            {1,0},
            {1,4},
            {1,8},
            {2,6},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[2];
            vals[0] = denWoundCount(b);
            vals[1] = denWoundDie(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT17[b][c])
                    ++bad;
            }
        }
        // the denMelee grid
        int CT18[5][3] = {
            {1,0,0},
            {2,0,20},
            {3,0,30},
            {3,1,40},
            {3,2,50},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[3];
            vals[0] = denMeleeBonusPerDie(b);
            vals[1] = denMeleeExtraDice(b);
            vals[2] = denMeleeSizePct(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT18[b][c])
                    ++bad;
            }
        }
        // the denMove grid
        int CT19[5][1] = {
            {20},
            {30},
            {40},
            {50},
            {60},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[1];
            vals[0] = denMovePct(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT19[b][c])
                    ++bad;
            }
        }
        // the denGaze grid
        int CT20[5][1] = {
            {-2},
            {-3},
            {-4},
            {-5},
            {-6},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[1];
            vals[0] = denGazeSave(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT20[b][c])
                    ++bad;
            }
        }
        // the denResist grid
        int CT21[5][1] = {
            {60},
            {70},
            {80},
            {90},
            {100},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[1];
            vals[0] = denResistPct(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT21[b][c])
                    ++bad;
            }
        }
        // the denRegen grid
        int CT22[5][2] = {
            {1,3},
            {1,0},
            {2,0},
            {3,0},
            {4,0},
            };
        for (int b = 0;
             b < denRankCount();
             ++b) {
            int vals[2];
            vals[0] = denRegenPerRound(b);
            vals[1] = denRegenDelayRounds(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT22[b][c])
                    ++bad;
            }
        }
        // the denAbilityRowCount pin
    if (denAbilityRowCount() != 13
        )
            ++bad;
        // the denRankCount pin
    if (denRankCount() != 5
        )
            ++bad;
        // the denAlterMax pin
    if (denAlterMax() != 3
        )
            ++bad;
        // the denHpFloor pin
    if (denHpFloor() != 1
        )
            ++bad;
        // the denDamageFloor pin
    if (denDamageFloor() != 1
        )
            ++bad;
        // the denSaveCeiling pin
    if (denSaveCeiling() != 20
        )
            ++bad;
        // the denSaveFloor pin
    if (denSaveFloor() != 3
        )
            ++bad;
        // the denXpHdFloor pin
    if (denXpHdFloor() != 1
        )
            ++bad;
        // the denSizeShiftModifier pin
    if (denSizeShiftModifier() != 3
        )
            ++bad;
        // the denAbilityRollDie pin
    if (denAbilityRollDie() != 6
        )
            ++bad;
        // the denAbilityRollCount pin
    if (denAbilityRollCount() != 3
        )
            ++bad;
        // the denWeightAllowLarge pin
    if (denWeightAllowLarge() != 35
        )
            ++bad;
        // the denWeightAllowHuge pin
    if (denWeightAllowHuge() != 70
        )
            ++bad;
        // the denWeightAllowGargantuan pin
    if (denWeightAllowGargantuan() != 105
        )
            ++bad;
        // the denBendBarsLargePct pin
    if (denBendBarsLargePct() != 5
        )
            ++bad;
        // the denBendBarsHugePct pin
    if (denBendBarsHugePct() != 10
        )
            ++bad;
        // the denBendBarsGargantuanPct pin
    if (denBendBarsGargantuanPct() != 20
        )
            ++bad;
        // the denLanguageGap pin
    if (denLanguageGap() != 3
        )
            ++bad;
        // the denLesserScionPowersMin pin
    if (denLesserScionPowersMin() != 2
        )
            ++bad;
        // the denLesserScionPowersMax pin
    if (denLesserScionPowersMax() != 3
        )
            ++bad;
        // the denLesserScionRollDie pin
    if (denLesserScionRollDie() != 4
        )
            ++bad;
        // the denLesserScionRollCount pin
    if (denLesserScionRollCount() != 3
        )
            ++bad;
        // the denLesserScionRollBonus pin
    if (denLesserScionRollBonus() != 4
        )
            ++bad;
        // the denScionPowersMin pin
    if (denScionPowersMin() != 3
        )
            ++bad;
        // the denScionPowersMax pin
    if (denScionPowersMax() != 4
        )
            ++bad;
        // the denScionRollDie pin
    if (denScionRollDie() != 6
        )
            ++bad;
        // the denScionRollCount pin
    if (denScionRollCount() != 2
        )
            ++bad;
        // the denScionRollBonus pin
    if (denScionRollBonus() != 6
        )
            ++bad;
        // the denElderPowersMin pin
    if (denElderPowersMin() != 3
        )
            ++bad;
        // the denElderPowersMax pin
    if (denElderPowersMax() != 5
        )
            ++bad;
        // the denElderRollDie pin
    if (denElderRollDie() != 10
        )
            ++bad;
        // the denElderRollCount pin
    if (denElderRollCount() != 1
        )
            ++bad;
        // the denElderRollBonus pin
    if (denElderRollBonus() != 8
        )
            ++bad;
        // the denGreatElderPowersMin pin
    if (denGreatElderPowersMin() != 4
        )
            ++bad;
        // the denGreatElderPowersMax pin
    if (denGreatElderPowersMax() != 6
        )
            ++bad;
        // the denGreatElderRollDie pin
    if (denGreatElderRollDie() != 10
        )
            ++bad;
        // the denGreatElderRollCount pin
    if (denGreatElderRollCount() != 1
        )
            ++bad;
        // the denGreatElderRollBonus pin
    if (denGreatElderRollBonus() != 8
        )
            ++bad;
        // the denParagonPowersMin pin
    if (denParagonPowersMin() != 5
        )
            ++bad;
        // the denParagonPowersMax pin
    if (denParagonPowersMax() != 7
        )
            ++bad;
        // the denParagonRollDie pin
    if (denParagonRollDie() != 8
        )
            ++bad;
        // the denParagonRollCount pin
    if (denParagonRollCount() != 1
        )
            ++bad;
        // the denParagonRollBonus pin
    if (denParagonRollBonus() != 10
        )
            ++bad;
        // the denFixedHpPerExtraDie pin
    if (denFixedHpPerExtraDie() != 5
        )
            ++bad;
        // the denBreathPerDayMin pin
    if (denBreathPerDayMin() != 3
        )
            ++bad;
        // the denBreathPerDayMax pin
    if (denBreathPerDayMax() != 5
        )
            ++bad;
        // the denBreathWaitRoundsMin pin
    if (denBreathWaitRoundsMin() != 1
        )
            ++bad;
        // the denBreathWaitRoundsMax pin
    if (denBreathWaitRoundsMax() != 2
        )
            ++bad;
        // the denParagonBreathHalfPerHd pin
    if (denParagonBreathHalfPerHd() != 45
        )
            ++bad;
        // the denAvgD4Half pin
    if (denAvgD4Half() != 25
        )
            ++bad;
        // the denAvgD6Half pin
    if (denAvgD6Half() != 35
        )
            ++bad;
        // the denAvgD8Half pin
    if (denAvgD8Half() != 45
        )
            ++bad;
        // the denAvgD10Half pin
    if (denAvgD10Half() != 55
        )
            ++bad;
        // the denAvgD12Half pin
    if (denAvgD12Half() != 65
        )
            ++bad;
        // the denAvgD20Half pin
    if (denAvgD20Half() != 105
        )
            ++bad;
        // the denCloudWidthFt pin
    if (denCloudWidthFt() != 50
        )
            ++bad;
        // the denCloudHeightFt pin
    if (denCloudHeightFt() != 40
        )
            ++bad;
        // the denConeMouthFt pin
    if (denConeMouthFt() != 5
        )
            ++bad;
        // the denConeApexFt pin
    if (denConeApexFt() != 30
        )
            ++bad;
        // the denLineWidthFt pin
    if (denLineWidthFt() != 5
        )
            ++bad;
        // the denLineHeightFt pin
    if (denLineHeightFt() != 5
        )
            ++bad;
        // the denDiseaseCheckDie pin
    if (denDiseaseCheckDie() != 100
        )
            ++bad;
        // the denChillsRoundsDie pin
    if (denChillsRoundsDie() != 4
        )
            ++bad;
        // the denChillsRoundsCount pin
    if (denChillsRoundsCount() != 2
        )
            ++bad;
        // the denChillsPenalty pin
    if (denChillsPenalty() != 4
        )
            ++bad;
        // the denDeliriumSnapRoll pin
    if (denDeliriumSnapRoll() != 9
        )
            ++bad;
        // the denFeverConsciousRoll pin
    if (denFeverConsciousRoll() != 9
        )
            ++bad;
        // the denCauseFearHdMax pin
    if (denCauseFearHdMax() != 4
        )
            ++bad;
        // the denCauseFearLevelMax pin
    if (denCauseFearLevelMax() != 4
        )
            ++bad;
        // the denCauseFearFleeDie pin
    if (denCauseFearFleeDie() != 4
        )
            ++bad;
        // the denCauseFearFleeCount pin
    if (denCauseFearFleeCount() != 2
        )
            ++bad;
        // the denCrushHeightMin pin
    if (denCrushHeightMin() != 30
        )
            ++bad;
        // the denCrushTwoSizePenalty pin
    if (denCrushTwoSizePenalty() != 4
        )
            ++bad;
        // the denCrushThreeSizePenalty pin
    if (denCrushThreeSizePenalty() != 8
        )
            ++bad;
        // the denExistingGazeParagonPenalty pin
    if (denExistingGazeParagonPenalty() != 8
        )
            ++bad;
        // the denSameModifierThroughout pin
    if (denSameModifierThroughout() != 1
        )
            ++bad;
        // the denUnchangedCharacteristics pin
    if (denUnchangedCharacteristics() != 1
        )
            ++bad;
        // the denAbilityWarriorBonuses pin
    if (denAbilityWarriorBonuses() != 1
        )
            ++bad;
        // the denDamageTotalNotPerDie pin
    if (denDamageTotalNotPerDie() != 1
        )
            ++bad;
        // the denDexMovesBonus pin
    if (denDexMovesBonus() != 1
        )
            ++bad;
        // the denNonhumanoidDoctrine pin
    if (denNonhumanoidDoctrine() != 1
        )
            ++bad;
        // the denRankPotencyDoctrine pin
    if (denRankPotencyDoctrine() != 1
        )
            ++bad;
        // the denExistingBreathNextRank pin
    if (denExistingBreathNextRank() != 1
        )
            ++bad;
        // the denGazeEffortless pin
    if (denGazeEffortless() != 1
        )
            ++bad;
        // the denCrushFullMovement pin
    if (denCrushFullMovement() != 1
        )
            ++bad;
        // the denCrushOverrunNoAoo pin
    if (denCrushOverrunNoAoo() != 1
        )
            ++bad;
        // the denWoundNoRegen pin
    if (denWoundNoRegen() != 1
        )
            ++bad;
        // the denLesserRegenBar pin
    if (denLesserRegenBar() != 1
        )
            ++bad;
        // the denEnhancedMovementRoundsUp pin
    if (denEnhancedMovementRoundsUp() != 1
        )
            ++bad;
        // the rust monster strength read: a man-sized creature, a roll of 10
        // lands in the 9-12 band, the M column gives Strength 12 (printed p.
        // 58)
    if (denStrM(6) != 12
        )
            ++bad;
        // the rust monster intelligence read: a roll of 18 in the A column
        // gives Intelligence 4 - an Einstein among rust monsters (printed p.
        // 58)
    if (denIntA(12) != 4
        )
            ++bad;
        // the scrag chief: a +3 specimen adds three per hit die - HD 5+20
        // from 5+5, the +3 riding every die and the damage dice floored
        // (printed p. 57)
    if (denAlterMax() != 3
            || denDamageFloor() != 1
        )
            ++bad;
        // the elder hydra head: 8 hp a head x the elder 2.5 multiplier = 20
        // (printed p. 61)
    if (denLegendMult(2) != 25
            || denLegendHdBonus(2) != 15
        )
            ++bad;
        // the paragon dragon turtle: 39 hit dice x 4.5 = 175.5, the printed
        // average 175 in half-points (printed p. 62)
    if (denParagonBreathHalfPerHd() != 45
        )
            ++bad;
        // the disease example: two hits for 17 and 21 points - the victim
        // contracts on 38 or less, the damage summed before the 1d100 check
        // (printed p. 62)
    if (denDiseaseCheckDie() != 100
        )
            ++bad;
        // the great elder chimera: +3 per die and one extra die - the 2d3+6
        // claws and the 4d4+12 tail (printed p. 65)
    if (denMeleeBonusPerDie(3) != 3
            || denMeleeExtraDice(3) != 1
            || denMeleeSizePct(3) != 40
        )
            ++bad;
        // the scion displacer beast: 15 base movement + 30 percent rounds to
        // 20 (printed p. 66)
    if (denMovePct(1) != 30
        )
            ++bad;
        // the lesser scion breath: 26-35 average damage at a -2 save, the
        // gorgon-class petrifying breath (printed pp. 62-63)
    if (denBreathDmgLow(0) != 26
            || denBreathDmgHigh(0) != 35
            || denBreathSave(0) != -2
        )
            ++bad;
        // the lesser scion regeneration delay: no hit points until three
        // rounds after the first wound - the troll rule riding the legendary
        // ladder; the paragon regenerates 4 a round with no delay (printed p.
        // 66)
    if (denRegenDelayRounds(0) != 3
            || denRegenPerRound(4) != 4
        )
            ++bad;
        // the weight allowance ladder: 35, 70 and 105 pounds by size (printed
        // p. 58)
    if (denWeightAllowLarge() != 35
            || denWeightAllowHuge() != 70
            || denWeightAllowGargantuan() != 105
        )
            ++bad;
        // the bend bars ladder: +5, +10 and +20 percent by size, sturdy
        // objects negating the bonus (printed p. 59)
    if (denBendBarsLargePct() != 5
            || denBendBarsHugePct() != 10
            || denBendBarsGargantuanPct() != 20
        )
            ++bad;
        printf("R603 DMO legendary-monsters audit: bad %d\n", bad);
        if (bad) return 1;
    }
