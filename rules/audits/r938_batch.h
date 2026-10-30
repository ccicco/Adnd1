    // ---- R938 issue-19 opener part two audit ----
    // THE DRAGON ISSUE-19 OPENER PART TWO - the three table-and-doctrine
    // chains of the issue. CHAIN ONE, the Origins 78 tournament synopsis by
    // Bryan and Kathy Bullinger with the Blake competitive D&D scoring (print
    // 3-4 + 6, PDF 5-6 + 8): the Battle for Snurre Hall walk - the triangular
    // alcove, Obmi the treacherous rescued dwarf, the blade barrier and wall
    // of fire blocks, the haste turning point, the king only pretending and
    // the head in the bag of holding; the Blake victory-point doctrine - the
    // G, R, C terms times the survivor S, the room-plus-clue-equals-giant
    // weighting, the subjectivity-objectivity-combination ladder, the GenCon
    // X and GenCon XI stories and the DM consistency doctrine. CHAIN TWO,
    // Planning Creative Treasures by Dave Schroeder (print 13, PDF 15) and
    // the Charts for Determining the Location of Treasure by Ronald Guritzky
    // (print 25, PDF 27): the sdmLoc, sdmTrap and sdmGas grids - the d20
    // location chart with the unassigned 14-15 bands, the thirteen-kind
    // percentile trap chart, the sixteen-outcome d6-by-d4 gas chart; the kit
    // and theme doctrine. CHAIN THREE, Spell Determination for Hostile Magic
    // Users by Steve Miller (print 24-25, PDF 26-27): the die-for-level
    // method - the worked 10-spell enchanter with the d20, the conjurer d4,
    // the magician d8 - and the nine contiguous percentile grids sdmDet1
    // through sdmDet9, 75 rows from Hold Portal through Monster Summoning VII
    // with the reroll doctrine.
    {
        using namespace rules;
        int bad = 0;
    if (sdmOriginsPlayers() != 275
            || sdmTeamSize() != 9
            || sdmTourneyRounds() != 3
            || sdmDmCountGenconX() != 15
            || sdmDmCountOrigins78() != 16
            || sdmDmCountGenconXI() != 20
            || sdmBriefingHours() != 4
            || sdmRoundOneMinutesFloor() != 120
            || sdmRoundOneMinutesCeil() != 150
            || sdmWallFeet() != 20
            || sdmHallWidthFeet() != 30
            || sdmG1PriceCents() != 449
            || sdmG2PriceCents() != 449
            || sdmG3PriceCents() != 498
            || sdmFormulaTerms() != 3
            || sdmGenconXRoundTeams() != 2
            || sdmTrapChanceDenominator() != 4
            || sdmDaggerCountMin() != 1
            || sdmDaggerCountMax() != 8
            || sdmTrapPoisonDenominator() != 6
            || sdmArrowCountMax() != 6
            || sdmSpearCountMax() != 3
            || sdmExplodingDiceMin() != 2
            || sdmExplodingDiceMax() != 7
            || sdmGasDieCount() != 2
            || sdmGasBlindHoursMax() != 100
            || sdmGasFearFightsMin() != 2
            || sdmGasFearFightsMax() != 9
            || sdmGasSleepMin() != 6
            || sdmGasSleepMax() != 36
            || sdmGasAbilityMin() != 1
            || sdmGasAbilityMax() != 4
            || sdmGasAbilityHours() != 8
            || sdmGasAbilityPermanentDenominator() != 10
            || sdmSickComaDenominator() != 6
            || sdmGasAmnesiaMinDays() != 1
            || sdmGasAmnesiaMaxDays() != 20
            || sdmGasAmnesiaPermanentDenominator() != 6
            || sdmIntelligentChestMinLevel() != 2
            || sdmIntelligentChestMaxLevel() != 7
            || sdmBouncerFeet() != 12
            || sdmLocKinds() != 8
            || sdmTrapKinds() != 13
            || sdmGasKinds() != 16
            || sdmSpellLevels() != 9
            || sdmDetSpellsTotal() != 75
            || sdmL1Spells() != 7
            || sdmL2Spells() != 9
            || sdmL3Spells() != 11
            || sdmL4Spells() != 8
            || sdmL5Spells() != 9
            || sdmL6Spells() != 11
            || sdmL7Spells() != 7
            || sdmL8Spells() != 5
            || sdmL9Spells() != 8
            || sdmEnchanterSpells() != 10
            || sdmEnchanterL1() != 4
            || sdmEnchanterL2() != 3
            || sdmMethodDieSides() != 20
            || sdmConjurerDieSides() != 4
            || sdmMagicianDieSides() != 8
            || !sdmSurvivorMultiplied()
            || !sdmRoomClueEqualGiant()
            || !sdmDoOrDieDesirable()
            || !sdmSubjectivityLeastDesirable()
            || !sdmObjectivityBetterAloneInadequate()
            || !sdmCombinationBest()
            || !sdmSuperiorMethodGreaterReward()
            || !sdmGenconXDoOrDie()
            || !sdmSkullPiecesFudged()
            || !sdmGenconXISurvivorMultiplier()
            || !sdmGenconXIDemonWipe()
            || !sdmGenconXIBye()
            || !sdmSubjectiveNeverAgain()
            || !sdmBriefingSessionsMust()
            || !sdmStandardRulesSheet()
            || !sdmBattleOfTriangular()
            || !sdmObmiBetrayal()
            || !sdmHasteTurningPoint()
            || !sdmKingOnlyPretending()
            || !sdmHeadInBagHolding()
            || !sdmSmurreContTypo()
            || !sdmGenconXIShrinePassage()
            || !sdmKuoSpellingCrossed()
            || !sdmChooseThemeFirst()
            || !sdmItemConnections()
            || !sdmFirstAidKitDoctrine()
            || !sdmThiefToolkitDoctrine()
            || !sdmDisguiseKitDoctrine()
            || !sdmAssassinDaggerPlusTwo()
            || !sdmYouthPotionBishop()
            || !sdmDetectionGemNecklace()
            || !sdmMonsterSizeAttention()
            || !sdmTrapRollTwice()
            || !sdmLocBandsGap()
            || !sdmGasD64Method()
            || !sdmRerollAllowed()
            || !sdmAsteriskDungeonRerull()
            || !sdmInappropriateReroll()
            || !sdmChartsModifiable()
            || !sdmHasteInvisLevitateOpening()
            || !sdmProtectionThenSleep()
            || !sdmLowerLevelPreferred()
            || !sdmL2LeadingDash()
            || !sdmEnchanterEllipsis()
            || !sdmLightningBoltOpening()
            || !sdmMagicMissileCleric()
        )
            ++bad;
        // the treasure location grid - eight kinds down, the d20 band across,
        // chest 1-6, urn 7-9, bag 10-12, pot 13, loose 16-17, carried 18,
        // hidden 19, referee choice 20; the bands 14-15 never assigned,
        // pinned as scanned (print 25, PDF 27)
        int CLc[8][2] = {
            {1,6},
            {7,9},
            {10,12},
            {13,13},
            {16,17},
            {18,18},
            {19,19},
            {20,20},
            };
        for (int b = 0;
             b < sdmLocKinds();
             ++b) {
            int vals[2];
            vals[0] = sdmLocLow(b);
            vals[1] = sdmLocHigh(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CLc[b][c])
                    ++bad;
            }
        }
        // the trap grid - thirteen kinds down, the percentile band across,
        // the dagger 01-20, arrow 21-36, spear 37-46, gas 47-62, poison lock
        // 63-78, monster 79-88, exploding chest 89-92, chest spell 93-95,
        // mirror of life trapping 96, intelligent chest 97, level loss 98,
        // item loss 99 and roll twice 100 (print 25, PDF 27)
        int CTr[13][2] = {
            {1,20},
            {21,36},
            {37,46},
            {47,62},
            {63,78},
            {79,88},
            {89,92},
            {93,95},
            {96,96},
            {97,97},
            {98,98},
            {99,99},
            {100,100},
            };
        for (int b = 0;
             b < sdmTrapKinds();
             ++b) {
            int vals[2];
            vals[0] = sdmTrapLow(b);
            vals[1] = sdmTrapHigh(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CTr[b][c])
                    ++bad;
            }
        }
        // the gas grid - sixteen outcomes down, the d6-by-d4 band across,
        // obscured vision 11-12, blind 13-14, fear 21-22, sleep 23-24,
        // ability drain 31, sick 32-33, paralysis 34, stone 41, death 42,
        // polymorph 43, amnesia 44, alignment change 51-52, slow 53-54, haste
        // 61-62, cloud kill 63 and berserk 64 (print 25, PDF 27)
        int CGs[16][2] = {
            {11,12},
            {13,14},
            {21,22},
            {23,24},
            {31,31},
            {32,33},
            {34,34},
            {41,41},
            {42,42},
            {43,43},
            {44,44},
            {51,52},
            {53,54},
            {61,62},
            {63,63},
            {64,64},
            };
        for (int b = 0;
             b < sdmGasKinds();
             ++b) {
            int vals[2];
            vals[0] = sdmGasLow(b);
            vals[1] = sdmGasHigh(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CGs[b][c])
                    ++bad;
            }
        }
        // the level-1 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 24, PDF 26-27)
        int CS1[7][2] = {
            {1,5},
            {6,10},
            {11,30},
            {31,55},
            {56,75},
            {76,95},
            {96,100},
            };
        for (int b = 0;
             b < sdmL1Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL1Low(b);
            vals[1] = sdmL1High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS1[b][c])
                    ++bad;
            }
        }
        // the level-2 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 24, PDF 26-27)
        int CS2[9][2] = {
            {1,5},
            {6,10},
            {11,30},
            {31,40},
            {41,50},
            {51,65},
            {66,70},
            {71,90},
            {91,100},
            };
        for (int b = 0;
             b < sdmL2Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL2Low(b);
            vals[1] = sdmL2High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS2[b][c])
                    ++bad;
            }
        }
        // the level-3 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 24, PDF 26-27)
        int CS3[11][2] = {
            {1,5},
            {6,15},
            {16,20},
            {21,40},
            {41,50},
            {51,55},
            {56,60},
            {61,75},
            {76,80},
            {81,90},
            {91,100},
            };
        for (int b = 0;
             b < sdmL3Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL3Low(b);
            vals[1] = sdmL3High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS3[b][c])
                    ++bad;
            }
        }
        // the level-4 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 24, PDF 26-27)
        int CS4[8][2] = {
            {1,10},
            {11,20},
            {21,25},
            {26,30},
            {31,40},
            {41,50},
            {51,70},
            {71,100},
            };
        for (int b = 0;
             b < sdmL4Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL4Low(b);
            vals[1] = sdmL4High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS4[b][c])
                    ++bad;
            }
        }
        // the level-5 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 24, PDF 26-27)
        int CS5[9][2] = {
            {1,5},
            {6,25},
            {26,35},
            {36,45},
            {46,55},
            {56,60},
            {61,85},
            {86,95},
            {96,100},
            };
        for (int b = 0;
             b < sdmL5Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL5Low(b);
            vals[1] = sdmL5High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS5[b][c])
                    ++bad;
            }
        }
        // the level-6 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 25, PDF 26-27)
        int CS6[11][2] = {
            {1,5},
            {6,25},
            {26,35},
            {36,40},
            {41,60},
            {61,65},
            {66,75},
            {76,80},
            {81,85},
            {86,95},
            {96,100},
            };
        for (int b = 0;
             b < sdmL6Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL6Low(b);
            vals[1] = sdmL6High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS6[b][c])
                    ++bad;
            }
        }
        // the level-7 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 25, PDF 26-27)
        int CS7[7][2] = {
            {1,10},
            {11,30},
            {31,55},
            {56,75},
            {76,80},
            {81,90},
            {91,100},
            };
        for (int b = 0;
             b < sdmL7Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL7Low(b);
            vals[1] = sdmL7High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS7[b][c])
                    ++bad;
            }
        }
        // the level-8 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 25, PDF 26-27)
        int CS8[5][2] = {
            {1,35},
            {36,55},
            {56,60},
            {61,90},
            {91,100},
            };
        for (int b = 0;
             b < sdmL8Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL8Low(b);
            vals[1] = sdmL8High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS8[b][c])
                    ++bad;
            }
        }
        // the level-9 determination grid - the percentile bands contiguous
        // from 01 to 100 (print 25, PDF 26-27)
        int CS9[8][2] = {
            {1,30},
            {31,45},
            {46,50},
            {51,70},
            {71,75},
            {76,85},
            {86,95},
            {96,100},
            };
        for (int b = 0;
             b < sdmL9Spells();
             ++b) {
            int vals[2];
            vals[0] = sdmL9Low(b);
            vals[1] = sdmL9High(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CS9[b][c])
                    ++bad;
            }
        }
        // the tourney census - 275 players and judges, teams of nine, three
        // rounds, the DM counts 15, 16 and 20, the four-hour briefing, the
        // two-team GenCon X town round (print 3 + 6, PDF 5 + 8)
    if (sdmOriginsPlayers() != 275
            || sdmTeamSize() != 9
            || sdmTourneyRounds() != 3
            || sdmDmCountGenconX() != 15
            || sdmDmCountOrigins78() != 16
            || sdmDmCountGenconXI() != 20
            || sdmBriefingHours() != 4
            || sdmGenconXRoundTeams() != 2
        )
            ++bad;
        // the Snurre Hall numbers - the two-to-two-and-a-half-hour first
        // portion, the 20-foot block marks, the 30-foot hall, the module
        // prices 449, 449 and 498 cents (print 4, PDF 6)
    if (sdmRoundOneMinutesFloor() != 120
            || sdmRoundOneMinutesCeil() != 150
            || sdmWallFeet() != 20
            || sdmHallWidthFeet() != 30
            || sdmG1PriceCents() != 449
            || sdmG2PriceCents() != 449
            || sdmG3PriceCents() != 498
        )
            ++bad;
        // the scoring doctrine - the three-term survivor-multiplied formula,
        // the room-plus-clue-equals-giant weighting, the desirability ladder
        // from do-or-dont through subjectivity and objectivity to the
        // combination (print 6, PDF 8)
    if (sdmSurvivorMultiplied() != 1
            || sdmFormulaTerms() != 3
            || sdmRoomClueEqualGiant() != 1
            || sdmDoOrDieDesirable() != 1
            || sdmSubjectivityLeastDesirable() != 1
            || sdmObjectivityBetterAloneInadequate() != 1
            || sdmCombinationBest() != 1
            || sdmSuperiorMethodGreaterReward() != 1
        )
            ++bad;
        // the trap doctrine - the one-in-four chance, 1-8 daggers and 1-6
        // arrows and 1-3 spears at 1 in 6 poison, the 2-7-dice exploding
        // chest, the 2nd-7th-level intelligent chest (print 25, PDF 27)
    if (sdmTrapChanceDenominator() != 4
            || sdmDaggerCountMin() != 1
            || sdmDaggerCountMax() != 8
            || sdmTrapPoisonDenominator() != 6
            || sdmArrowCountMax() != 6
            || sdmSpearCountMax() != 3
            || sdmExplodingDiceMin() != 2
            || sdmExplodingDiceMax() != 7
            || sdmIntelligentChestMinLevel() != 2
            || sdmIntelligentChestMaxLevel() != 7
        )
            ++bad;
        // the gas doctrine - the d6-and-d4 roll, the 01-100-hour blindness,
        // the 2-9-fight fear, the 6-36-round sleep, the 1-4-point eight-hour
        // ability drain at 1 in 10 permanent (print 25, PDF 27)
    if (sdmGasDieCount() != 2
            || sdmGasBlindHoursMax() != 100
            || sdmGasFearFightsMin() != 2
            || sdmGasFearFightsMax() != 9
            || sdmGasSleepMin() != 6
            || sdmGasSleepMax() != 36
            || sdmGasAbilityMin() != 1
            || sdmGasAbilityMax() != 4
            || sdmGasAbilityHours() != 8
            || sdmGasAbilityPermanentDenominator() != 10
        )
            ++bad;
        // the gas tail and print catches - the 1-20-day amnesia at 1 in 6
        // permanent, the sick 1-in-6 coma, the d6-d4 method, the roll-twice
        // 00, the unassigned 14-15 location bands (print 25, PDF 27)
    if (sdmGasAmnesiaMinDays() != 1
            || sdmGasAmnesiaMaxDays() != 20
            || sdmGasAmnesiaPermanentDenominator() != 6
            || sdmSickComaDenominator() != 6
            || sdmGasD64Method() != 1
            || sdmTrapRollTwice() != 1
            || sdmLocBandsGap() != 1
        )
            ++bad;
        // the determination census - nine tables, 75 rows, the per-level
        // counts 7, 9, 11, 8, 9, 11, 7, 5 and 8 (print 24-25, PDF 26-27)
    if (sdmSpellLevels() != 9
            || sdmDetSpellsTotal() != 75
            || sdmL1Spells() != 7
            || sdmL2Spells() != 9
            || sdmL3Spells() != 11
            || sdmL4Spells() != 8
            || sdmL5Spells() != 9
            || sdmL6Spells() != 11
            || sdmL7Spells() != 7
            || sdmL8Spells() != 5
            || sdmL9Spells() != 8
        )
            ++bad;
        // the method - the 10-spell enchanter, the 4/3 printed counts with
        // the trailing ellipsis, the d20 level die, the conjurer d4 and
        // magician d8, the -01-05 leading dash (print 24, PDF 26)
    if (sdmEnchanterSpells() != 10
            || sdmEnchanterL1() != 4
            || sdmEnchanterL2() != 3
            || sdmMethodDieSides() != 20
            || sdmConjurerDieSides() != 4
            || sdmMagicianDieSides() != 8
            || sdmEnchanterEllipsis() != 1
            || sdmL2LeadingDash() != 1
        )
            ++bad;
        // the determination doctrine - the reroll family with the
        // feeblemind-on-a-fighter example, the modifiable charts, the
        // haste-invisibility-levitate opening, the lightning bolt and magic
        // missile redo (print 24, PDF 26)
    if (sdmRerollAllowed() != 1
            || sdmAsteriskDungeonRerull() != 1
            || sdmInappropriateReroll() != 1
            || sdmChartsModifiable() != 1
            || sdmHasteInvisLevitateOpening() != 1
            || sdmProtectionThenSleep() != 1
            || sdmLowerLevelPreferred() != 1
            || sdmLightningBoltOpening() != 1
            || sdmMagicMissileCleric() != 1
        )
            ++bad;
        // the creative-treasure doctrine - the theme first, the connections,
        // the three kits, the doubled-plus print catch, the youth-potion
        // bishop, the detection necklace and the 12-foot bouncers (print 13,
        // PDF 15)
    if (sdmChooseThemeFirst() != 1
            || sdmItemConnections() != 1
            || sdmFirstAidKitDoctrine() != 1
            || sdmThiefToolkitDoctrine() != 1
            || sdmDisguiseKitDoctrine() != 1
            || sdmAssassinDaggerPlusTwo() != 1
            || sdmYouthPotionBishop() != 1
            || sdmDetectionGemNecklace() != 1
            || sdmBouncerFeet() != 12
        )
            ++bad;
        // the location and trap corners - the chest 1-6, the lone pot 13 with
        // the 16-17 loose jump, the referee 20, the dagger 01-20, the mirror
        // singleton 96, the roll-twice 100 (print 25, PDF 27)
    if (sdmLocLow(0) != 1
            || sdmLocHigh(0) != 6
            || sdmLocLow(3) != 13
            || sdmLocHigh(3) != 13
            || sdmLocLow(4) != 16
            || sdmLocHigh(7) != 20
            || sdmTrapLow(0) != 1
            || sdmTrapHigh(0) != 20
            || sdmTrapHigh(12) != 100
            || sdmTrapLow(8) != 96
            || sdmTrapHigh(8) != 96
        )
            ++bad;
        // the gas corners - the obscured vision 11-12, the singleton ability
        // drain 31, the stone 41, the death 42, the slow 53-54, the haste
        // 61-62, the berserk 64 (print 25, PDF 27)
    if (sdmGasLow(0) != 11
            || sdmGasHigh(0) != 12
            || sdmGasLow(4) != 31
            || sdmGasHigh(4) != 31
            || sdmGasLow(7) != 41
            || sdmGasLow(8) != 42
            || sdmGasHigh(15) != 64
            || sdmGasLow(12) != 53
            || sdmGasHigh(13) != 62
        )
            ++bad;
        // the low-table corners - the asterisked Hold Portal 01-05, the Charm
        // Person 11-30 and Ventriloquism 96-100, the Web 71-90 and Mirror
        // Image 91-100, the Fire Ball 21-40, the Ice Storm 51-70 and Fear
        // 71-100 (print 24, PDF 26)
    if (sdmL1Low(0) != 1
            || sdmL1High(0) != 5
            || sdmL1High(2) != 30
            || sdmL1Low(6) != 96
            || sdmL1High(6) != 100
            || sdmL2High(7) != 90
            || sdmL2Low(8) != 91
            || sdmL3Low(3) != 21
            || sdmL3High(3) != 40
            || sdmL4High(7) != 100
            || sdmL4Low(6) != 51
            || sdmL4High(6) != 70
        )
            ++bad;
        // the high-table corners - the Conjure Elemental 06-25, the
        // Feeblemind 86-95, the Death Spell 41-60, the Monster Summoning IV
        // 96-100, the Reverse Gravity 11-30, the Mass Charm 01-35, the
        // asterisked Time Stop-adjacent Wish 71-75, the Prismatic Wall 76-85
        // (print 24-25, PDF 26-27)
    if (sdmL5Low(1) != 6
            || sdmL5High(1) != 25
            || sdmL5High(7) != 95
            || sdmL6High(4) != 60
            || sdmL6Low(10) != 96
            || sdmL7Low(1) != 11
            || sdmL7High(1) != 30
            || sdmL8Low(0) != 1
            || sdmL8High(0) != 35
            || sdmL9High(4) != 75
            || sdmL9Low(5) != 76
        )
            ++bad;
        // the contiguity spot checks - Protection Evil 06-10, Hold Person
        // 06-15, Dispel Magic 16-20, Telekinesis 26-35, Invisible Stalker
        // 06-25, Delayed Blast 01-10, Shape Change 31-45 - every band butts
        // its neighbor (print 24-25, PDF 26-27)
    if (sdmL1Low(1) != 6
            || sdmL1High(1) != 10
            || sdmL3Low(1) != 6
            || sdmL3High(2) != 20
            || sdmL5Low(2) != 26
            || sdmL6High(1) != 25
            || sdmL7High(0) != 10
            || sdmL9High(1) != 45
        )
            ++bad;
        printf("R938 issue-19 opener part two audit: bad %d\n", bad);
        if (bad) return 1;
    }
