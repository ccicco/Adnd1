    // ---- R607 DMO true-dweomers audit ----
    // CHAPTER 6 of the DMO (printed pp. 118-141), the 10th-level spell system
    // closing in one round: the requirement gates (the 20th level, the
    // ability 18, the four-per-day cap, the unrecordable rule), the
    // difficulty calculus (the level and specialist and practiced
    // adjustments, the component and condition reductions, the save and
    // resistance trades), the eight grids (the Table 28 type ladder with its
    // duel-type mirror, the Table 29 areas, the Table 30 animated objects,
    // the Table 31 ranges, the Table 32 durations, the Table 33 prep-and-cast
    // bands), the school effects from dispel and ward through slay and tap
    // with their doubling and tripling ladders, the preparation and
    // final-check rules, the Pharjis worked creation at 110 through 10, the
    // in-play and dueling and quest-spell doctrines with the duel PR 19, and
    // the thirteen known dweomers with their difficulty pairs.
    {
        using namespace rules;
        int bad = 0;
    if (devMinCasterLevel() != 20
            || devMinAbilityScore() != 18
            || devMaxPerDay() != 4
            || devCasterLevelStep() != -1
            || devSpecialistBonus() != -5
            || devPrevCastBonus() != -10
            || devRareComponentAdjust() != -10
            || devRareComponentMax() != 3
            || devRareComponentLimit() != -30
            || devExoticComponentAdjust() != -20
            || devRareConditionAdjust() != -10
            || devExoticConditionAdjust() != -20
            || devSaveModPerFive() != 5
            || devNoSaveDifficulty() != 100
            || devMrModPerPoint() != 1
            || devDispelBasePct() != 50
            || devDispelSuccessRollMin() != 11
            || devDispelLowMagicPct() != 100
            || devDispelItemSuppressRounds() != 4
            || devDispelItemDieSize() != 4
            || devDispelAugmentPerFive() != 5
            || devWardSaveBonus() != 4
            || devWardDamagePerTwo() != 2
            || devWardPctResistDifficulty() != 105
            || devWardFullResistDifficulty() != 210
            || devWardHedgeTypeDifficulty() != 70
            || devWardHedgeClassDifficulty() != 105
            || devReflectSingleDifficulty() != 25
            || devReflectLimitedDifficulty() != 50
            || devReflectGeneralDifficulty() != 75
            || devAnimateObjWeight() != 50
            || devAnimateObjSpeed() != 12
            || devDestroyRemakeDie() != 6
            || devDestroyRemakePctMult() != 10
            || devDestroyDisintegrateDifficulty() != 90
            || devFortifyBasePct() != 10
            || devFortifyDoubleDifficulty() != 60
            || devFortifyTripleDifficulty() != 90
            || devFortifyQuadDifficulty() != 120
            || devFortifyAbilityLowBonus() != 1
            || devFortifyAbilityHighBonus() != 1
            || devTransformMaxTons() != 50
            || devTransformCreatureDifficulty() != 70
            || devTransformObjectDifficulty() != 105
            || devTransportBaseBonusMv() != 12
            || devTransportBurrowMv() != 3
            || devTransportDifficultMv() != 6
            || devTransportDoubleDifficulty() != 70
            || devTransportTeleportDifficulty() != 105
            || devAfflictBaseDifficulty() != 40
            || devAfflictHarmlessDifficulty() != 20
            || devAfflictDoubleDifficulty() != 80
            || devAfflictTripleDifficulty() != 120
            || devAfflictQuadDifficulty() != 160
            || devBindBaseDifficulty() != 35
            || devConjureBaseDifficulty() != 40
            || devConjureDoubleDifficulty() != 80
            || devConjureTripleDifficulty() != 120
            || devSummonBaseDifficulty() != 50
            || devSummonDoubleDifficulty() != 100
            || devSummonTripleDifficulty() != 150
            || devCharmBaseDifficulty() != 20
            || devCharmUndeadDifficulty() != 60
            || devCompelBaseDifficulty() != 30
            || devImbueBaseDifficulty() != 45
            || devImbueDoubleDifficulty() != 90
            || devImbueReachFt() != 30
            || devImbueLeadCopperDifficulty() != 150
            || devImbueLeadSilverDifficulty() != 90
            || devImbueLeadGoldDifficulty() != 135
            || devImbueWoodGoldDifficulty() != 285
            || devForeseeBaseDifficulty() != 25
            || devForeseeKingDifficulty() != 125
            || devForeseeUnspecifiedCost() != 100
            || devForeseeSenseDifficulty() != 75
            || devRevealBaseDifficulty() != 20
            || devRevealDoubleDifficulty() != 40
            || devRevealTripleDifficulty() != 60
            || devRevealTrueSeeingDifficulty() != 100
            || devRevealPastDivisor() != 10
            || devRevealPastTenYears() != 70
            || devConcealBaseDifficulty() != 20
            || devConcealMagicalDifficulty() != 40
            || devDeludeBaseDifficulty() != 30
            || devDeludeEspDifficulty() != 60
            || devDeludeGiantExampleDifficulty() != 150
            || devPhantomBaseDifficulty() != 40
            || devPhantomMentalCost() != 40
            || devShadowDisbelievedAc() != 4
            || devShadowDisbelievedPct() != 80
            || devShadowSpecialPersistPct() != 50
            || devEnergyWallDifficulty() != 25
            || devEnergyWallDmgDice() != 2
            || devEnergyWallDmgSize() != 8
            || devEnergyWallNearbyDmg() != 8
            || devEnergyWallNearbyFt() != 10
            || devSoftWallDifficulty() != 50
            || devHardWallDifficulty() != 75
            || devForceWallDifficulty() != 100
            || devFallingWallDmgDice() != 3
            || devFallingWallDmgSize() != 10
            || devMatterBlockDifficulty() != 35
            || devMatterSoftDifficulty() != 70
            || devMatterMetalDifficulty() != 105
            || devStrikeBaseDifficulty() != 25
            || devStrikeDmgDice() != 2
            || devStrikeMaxDice() != 30
            || devStrikeStepPerFive() != 5
            || devMobileSpellAc() != 0
            || devCrushingSpellAc() != -2
            || devCrushingSpellHpMult() != 2
            || devAnimateDeadBaseDifficulty() != 25
            || devAnimateDeadDoubleDifficulty() != 50
            || devAnimateDeadTripleDifficulty() != 75
            || devAnimateScatteredAdj() != 25
            || devAnimateScatteredAncientAdj() != 75
            || devSlayBaseDifficulty() != 50
            || devSlayHdPerFive() != 1
            || devSlaySaveHdMin() != 9
            || devTapBaseDifficulty() != 40
            || devTapDmgDie() != 8
            || devTapMaxDice() != 30
            || devTapTransferDifficulty() != 80
            || devTapAbilityTransferDifficulty() != 160
            || devTapLevelDifficulty() != 120
            || devTapLevelTransferDifficulty() != 240
            || devPrepHoursPerDay() != 8
            || devPharjisLevel() != 25
            || devPharjisDiff15PrepWeeks() != 1
            || devPharjisExplosionLostDays() != 2
            || devPharjisDiff55PrepMonths() != 2
            || devFinalCheckDie() != 100
            || devPharjisDiff55Final() != 28
            || devPharjisDiff15Shortened() != 30
            || devPharjisDiff160Final() != 80
            || devHoldTimeCap() != 1
            || devExRevealBase() != 20
            || devExRegionAdj() != 80
            || devExHalfDayAdj() != 10
            || devExCombinedDifficulty() != 110
            || devExAdjustedDifficulty() != 70
            || devExExoticHalved() != 35
            || devExRareReduced() != 5
            || devExDoubledFinal() != 10
            || devExFailRoll() != 2
            || devExSuccessRoll() != 81
            || devExWatchHours() != 12
            || devDispelMagicSuppressRounds() != 4
            || devDisjunctionPctPerLevel() != 1
            || devLimitedWishHours() != 8
            || devDuelPR() != 19
            || devQuestWardSaveFloor() != 18
            || devKnownDweomerCount() != 13
            || devHurdSavePenalty() != -8
            || devKolinUndeadHd() != 200
            || devKrebDragonFailPct() != 20
            || devNazzerBaseDiff() != 55
            || devNazzerCloakDiff() != 90
            || devNazzerCloakFinal() != 13
            || devNazzerItemLevel() != 12
            || devNazzerCloakRounds() != 10
            || devNejaPleaHours() != 12
            || devNejaPleaSaveBonus() != -3
            || devRatecliffeHd() != 40
            || devRatecliffeAreaFt() != 50
            || devTenserDmgDice() != 20
            || devTenserDmgBonus() != 20
            || devWulfRectAreaDia() != 50
            || devWulfRectMrPenalty() != -20
            || devYunniWeightLbs() != 50
            || devT28RowCount() != 29
            || devT29RowCount() != 10
            || devT30RowCount() != 6
            || devT31RowCount() != 10
            || devT32RowCount() != 11
            || devT33RowCount() != 10
            || devT35RowCount() != 29
            || devProvinceMiles() != 20
            || devRegionMiles() != 100
            || devAreaAllCreaturesMult() != 10
            || !devNoScrollOrDevice()
            || !devNeverSameTwice()
            || !devDmApprovalRequired()
            || !devWizardsAnySchool()
            || !devCommonComponentRequired()
            || !devPriestHolySymbolNeeded()
            || !devWizardsNeedNoSpellbook()
            || !devComponentsSymbolic()
            || !devExoticEitherNotBoth()
            || !devWardHalfEvenOnFail()
            || !devWardTwoResistRolls()
            || !devTransformSimplePermanentFree()
            || !devAfflictHarmlessPermanentFree()
            || !devBindYearlySave()
            || !devBindNoSuicide()
            || !devSummonNoControlOvernamed()
            || !devGolemsNeverCharmed()
            || !devRevealNoSaveUnlessUnwilling()
            || !devConcealBrokenByAttack()
            || !devTrueSeeingDefeatsConceal()
            || !devPhantomNoRealDamage()
            || !devMatterPermanentFree()
            || !devForceImmuneToOwnEnergy()
            || !devOnlyPriestsHealWithTap()
            || !devTapDamageInstantOnly()
            || !devPrepDayRestart()
            || !devPrepWeekBacktrack()
            || !devPrepExtensionHalves()
            || !devCastDailyNoBreaks()
            || !devCastBrokenRuinsSpell()
            || !devPlayCasterLevelSaves()
            || !devIounStonesIneffective()
            || !devDispelMagicAreaCapped()
            || !devWishAutoDispels()
            || !devDispelDestroysBarriers()
            || !devSphericalBarriersHold()
            || !devDuelCountersUseless()
            || !devQuestSpellsUncounterable()
            || !devQuestWardMrHalved()
            || !devNazzerAutoFailOne()
            || !devNejaToadstoolSystemShock()
            || !devRatecliffeWishOnlyRevival()
        )
            ++bad;
        // the devT28Grid grid
        int CT42[29][3] = {
            {30,0,1},
            {30,0,0},
            {25,1,0},
            {35,1,0},
            {25,1,2},
            {45,0,2},
            {30,1,1},
            {35,1,1},
            {35,2,1},
            {40,1,3},
            {35,1,4},
            {40,1,2},
            {50,2,4},
            {20,1,4},
            {30,1,4},
            {30,1,1},
            {45,1,1},
            {25,1,0},
            {20,1,0},
            {20,1,3},
            {30,1,3},
            {-99,-99,-99},
            {40,1,0},
            {35,2,0},
            {45,1,1},
            {25,0,0},
            {25,0,0},
            {50,0,4},
            {40,0,4},
            };
        int nT42[3] = {0,0,0};
        int eT42[3] = {1,1,1};
        for (int b = 0;
             b < devT28RowCount();
             ++b) {
            int vals[3];
            vals[0] = devT28BaseDiff(b);
            vals[1] = devT28BaseDuration(b);
            vals[2] = devT28EffectCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT42[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT42[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT42[c] != eT42[c])
                ++bad;
        // the devT29Grid grid
        int CT43[10][4] = {
            {1,5,200,0},
            {3,50,500,5},
            {6,500,1000,10},
            {9,5000,2000,15},
            {12,10000,10000,20},
            {15,25000,20000,25},
            {18,50000,100000,30},
            {21,-99,200000,40},
            {24,-99,400000,80},
            {27,-99,1000000,160},
            };
        int nT43[4] = {0,0,0,0};
        int eT43[4] = {0,3,0,0};
        for (int b = 0;
             b < devT29RowCount();
             ++b) {
            int vals[4];
            vals[0] = devT29Creatures(b);
            vals[1] = devT29AreaFt(b);
            vals[2] = devT29ObjectLbs(b);
            vals[3] = devT29Difficulty(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CT43[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT43[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nT43[c] != eT43[c])
                ++bad;
        // the devT30Grid grid
        int CT44[6][2] = {
            {50,2},
            {100,5},
            {200,10},
            {500,15},
            {1000,20},
            {2000,25},
            };
        for (int b = 0;
             b < devT30RowCount();
             ++b) {
            int vals[2];
            vals[0] = devT30WeightLbs(b);
            vals[1] = devT30Damage(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT44[b][c])
                    ++bad;
            }
        }
        // the devT31Grid grid
        int CT45[10][1] = {
            {0},
            {5},
            {10},
            {15},
            {20},
            {25},
            {30},
            {40},
            {60},
            {100},
            };
        for (int b = 0;
             b < devT31RowCount();
             ++b) {
            int vals[1];
            vals[0] = devT31Difficulty(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT45[b][c])
                    ++bad;
            }
        }
        // the devT32Grid grid
        int CT46[11][1] = {
            {0},
            {1},
            {3},
            {5},
            {7},
            {10},
            {15},
            {30},
            {50},
            {70},
            {100},
            };
        for (int b = 0;
             b < devT32RowCount();
             ++b) {
            int vals[1];
            vals[0] = devT32Difficulty(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT46[b][c])
                    ++bad;
            }
        }
        // the devT33Grid grid
        int CT47[10][2] = {
            {0,0},
            {1,0},
            {2,0},
            {3,1},
            {4,1},
            {5,2},
            {6,2},
            {7,3},
            {8,3},
            {9,4},
            };
        for (int b = 0;
             b < devT33RowCount();
             ++b) {
            int vals[2];
            vals[0] = devT33PrepCode(b);
            vals[1] = devT33CastCode(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT47[b][c])
                    ++bad;
            }
        }
        // the devT35Grid grid
        int CT48[29][1] = {
            {0},
            {2},
            {1},
            {1},
            {2},
            {3},
            {3},
            {0},
            {3},
            {0},
            {0},
            {3},
            {2},
            {0},
            {0},
            {3},
            {3},
            {3},
            {3},
            {3},
            {3},
            {5},
            {6},
            {2},
            {3},
            {4},
            {2},
            {0},
            {0},
            };
        for (int b = 0;
             b < devT35RowCount();
             ++b) {
            int vals[1];
            vals[0] = devT35DuelType(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT48[b][c])
                    ++bad;
            }
        }
        // the devKnownDweomers grid
        int CT49[13][2] = {
            {180,45},
            {325,45},
            {65,5},
            {120,5},
            {55,-5},
            {60,0},
            {120,3},
            {220,3},
            {190,0},
            {160,-7},
            {85,8},
            {155,2},
            {140,-2},
            };
        for (int b = 0;
             b < devKnownDweomerCount();
             ++b) {
            int vals[2];
            vals[0] = devKnownDifficulty(b);
            vals[1] = devKnownFinal(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT49[b][c])
                    ++bad;
            }
        }
        // the devMinCasterLevel pin
    if (devMinCasterLevel() != 20
        )
            ++bad;
        // the devMinAbilityScore pin
    if (devMinAbilityScore() != 18
        )
            ++bad;
        // the devMaxPerDay pin
    if (devMaxPerDay() != 4
        )
            ++bad;
        // the devCasterLevelStep pin
    if (devCasterLevelStep() != -1
        )
            ++bad;
        // the devSpecialistBonus pin
    if (devSpecialistBonus() != -5
        )
            ++bad;
        // the devPrevCastBonus pin
    if (devPrevCastBonus() != -10
        )
            ++bad;
        // the devRareComponentAdjust pin
    if (devRareComponentAdjust() != -10
        )
            ++bad;
        // the devRareComponentMax pin
    if (devRareComponentMax() != 3
        )
            ++bad;
        // the devRareComponentLimit pin
    if (devRareComponentLimit() != -30
        )
            ++bad;
        // the devExoticComponentAdjust pin
    if (devExoticComponentAdjust() != -20
        )
            ++bad;
        // the devRareConditionAdjust pin
    if (devRareConditionAdjust() != -10
        )
            ++bad;
        // the devExoticConditionAdjust pin
    if (devExoticConditionAdjust() != -20
        )
            ++bad;
        // the devSaveModPerFive pin
    if (devSaveModPerFive() != 5
        )
            ++bad;
        // the devNoSaveDifficulty pin
    if (devNoSaveDifficulty() != 100
        )
            ++bad;
        // the devMrModPerPoint pin
    if (devMrModPerPoint() != 1
        )
            ++bad;
        // the devDispelBasePct pin
    if (devDispelBasePct() != 50
        )
            ++bad;
        // the devDispelSuccessRollMin pin
    if (devDispelSuccessRollMin() != 11
        )
            ++bad;
        // the devDispelLowMagicPct pin
    if (devDispelLowMagicPct() != 100
        )
            ++bad;
        // the devDispelItemSuppressRounds pin
    if (devDispelItemSuppressRounds() != 4
        )
            ++bad;
        // the devDispelItemDieSize pin
    if (devDispelItemDieSize() != 4
        )
            ++bad;
        // the devDispelAugmentPerFive pin
    if (devDispelAugmentPerFive() != 5
        )
            ++bad;
        // the devWardSaveBonus pin
    if (devWardSaveBonus() != 4
        )
            ++bad;
        // the devWardDamagePerTwo pin
    if (devWardDamagePerTwo() != 2
        )
            ++bad;
        // the devWardPctResistDifficulty pin
    if (devWardPctResistDifficulty() != 105
        )
            ++bad;
        // the devWardFullResistDifficulty pin
    if (devWardFullResistDifficulty() != 210
        )
            ++bad;
        // the devWardHedgeTypeDifficulty pin
    if (devWardHedgeTypeDifficulty() != 70
        )
            ++bad;
        // the devWardHedgeClassDifficulty pin
    if (devWardHedgeClassDifficulty() != 105
        )
            ++bad;
        // the devReflectSingleDifficulty pin
    if (devReflectSingleDifficulty() != 25
        )
            ++bad;
        // the devReflectLimitedDifficulty pin
    if (devReflectLimitedDifficulty() != 50
        )
            ++bad;
        // the devReflectGeneralDifficulty pin
    if (devReflectGeneralDifficulty() != 75
        )
            ++bad;
        // the devAnimateObjWeight pin
    if (devAnimateObjWeight() != 50
        )
            ++bad;
        // the devAnimateObjSpeed pin
    if (devAnimateObjSpeed() != 12
        )
            ++bad;
        // the devDestroyRemakeDie pin
    if (devDestroyRemakeDie() != 6
        )
            ++bad;
        // the devDestroyRemakePctMult pin
    if (devDestroyRemakePctMult() != 10
        )
            ++bad;
        // the devDestroyDisintegrateDifficulty pin
    if (devDestroyDisintegrateDifficulty() != 90
        )
            ++bad;
        // the devFortifyBasePct pin
    if (devFortifyBasePct() != 10
        )
            ++bad;
        // the devFortifyDoubleDifficulty pin
    if (devFortifyDoubleDifficulty() != 60
        )
            ++bad;
        // the devFortifyTripleDifficulty pin
    if (devFortifyTripleDifficulty() != 90
        )
            ++bad;
        // the devFortifyQuadDifficulty pin
    if (devFortifyQuadDifficulty() != 120
        )
            ++bad;
        // the devFortifyAbilityLowBonus pin
    if (devFortifyAbilityLowBonus() != 1
        )
            ++bad;
        // the devFortifyAbilityHighBonus pin
    if (devFortifyAbilityHighBonus() != 1
        )
            ++bad;
        // the devTransformMaxTons pin
    if (devTransformMaxTons() != 50
        )
            ++bad;
        // the devTransformCreatureDifficulty pin
    if (devTransformCreatureDifficulty() != 70
        )
            ++bad;
        // the devTransformObjectDifficulty pin
    if (devTransformObjectDifficulty() != 105
        )
            ++bad;
        // the devTransportBaseBonusMv pin
    if (devTransportBaseBonusMv() != 12
        )
            ++bad;
        // the devTransportBurrowMv pin
    if (devTransportBurrowMv() != 3
        )
            ++bad;
        // the devTransportDifficultMv pin
    if (devTransportDifficultMv() != 6
        )
            ++bad;
        // the devTransportDoubleDifficulty pin
    if (devTransportDoubleDifficulty() != 70
        )
            ++bad;
        // the devTransportTeleportDifficulty pin
    if (devTransportTeleportDifficulty() != 105
        )
            ++bad;
        // the devAfflictBaseDifficulty pin
    if (devAfflictBaseDifficulty() != 40
        )
            ++bad;
        // the devAfflictHarmlessDifficulty pin
    if (devAfflictHarmlessDifficulty() != 20
        )
            ++bad;
        // the devAfflictDoubleDifficulty pin
    if (devAfflictDoubleDifficulty() != 80
        )
            ++bad;
        // the devAfflictTripleDifficulty pin
    if (devAfflictTripleDifficulty() != 120
        )
            ++bad;
        // the devAfflictQuadDifficulty pin
    if (devAfflictQuadDifficulty() != 160
        )
            ++bad;
        // the devBindBaseDifficulty pin
    if (devBindBaseDifficulty() != 35
        )
            ++bad;
        // the devConjureBaseDifficulty pin
    if (devConjureBaseDifficulty() != 40
        )
            ++bad;
        // the devConjureDoubleDifficulty pin
    if (devConjureDoubleDifficulty() != 80
        )
            ++bad;
        // the devConjureTripleDifficulty pin
    if (devConjureTripleDifficulty() != 120
        )
            ++bad;
        // the devSummonBaseDifficulty pin
    if (devSummonBaseDifficulty() != 50
        )
            ++bad;
        // the devSummonDoubleDifficulty pin
    if (devSummonDoubleDifficulty() != 100
        )
            ++bad;
        // the devSummonTripleDifficulty pin
    if (devSummonTripleDifficulty() != 150
        )
            ++bad;
        // the devCharmBaseDifficulty pin
    if (devCharmBaseDifficulty() != 20
        )
            ++bad;
        // the devCharmUndeadDifficulty pin
    if (devCharmUndeadDifficulty() != 60
        )
            ++bad;
        // the devCompelBaseDifficulty pin
    if (devCompelBaseDifficulty() != 30
        )
            ++bad;
        // the devImbueBaseDifficulty pin
    if (devImbueBaseDifficulty() != 45
        )
            ++bad;
        // the devImbueDoubleDifficulty pin
    if (devImbueDoubleDifficulty() != 90
        )
            ++bad;
        // the devImbueReachFt pin
    if (devImbueReachFt() != 30
        )
            ++bad;
        // the devImbueLeadCopperDifficulty pin
    if (devImbueLeadCopperDifficulty() != 150
        )
            ++bad;
        // the devImbueLeadSilverDifficulty pin
    if (devImbueLeadSilverDifficulty() != 90
        )
            ++bad;
        // the devImbueLeadGoldDifficulty pin
    if (devImbueLeadGoldDifficulty() != 135
        )
            ++bad;
        // the devImbueWoodGoldDifficulty pin
    if (devImbueWoodGoldDifficulty() != 285
        )
            ++bad;
        // the devForeseeBaseDifficulty pin
    if (devForeseeBaseDifficulty() != 25
        )
            ++bad;
        // the devForeseeKingDifficulty pin
    if (devForeseeKingDifficulty() != 125
        )
            ++bad;
        // the devForeseeUnspecifiedCost pin
    if (devForeseeUnspecifiedCost() != 100
        )
            ++bad;
        // the devForeseeSenseDifficulty pin
    if (devForeseeSenseDifficulty() != 75
        )
            ++bad;
        // the devRevealBaseDifficulty pin
    if (devRevealBaseDifficulty() != 20
        )
            ++bad;
        // the devRevealDoubleDifficulty pin
    if (devRevealDoubleDifficulty() != 40
        )
            ++bad;
        // the devRevealTripleDifficulty pin
    if (devRevealTripleDifficulty() != 60
        )
            ++bad;
        // the devRevealTrueSeeingDifficulty pin
    if (devRevealTrueSeeingDifficulty() != 100
        )
            ++bad;
        // the devRevealPastDivisor pin
    if (devRevealPastDivisor() != 10
        )
            ++bad;
        // the devRevealPastTenYears pin
    if (devRevealPastTenYears() != 70
        )
            ++bad;
        // the devConcealBaseDifficulty pin
    if (devConcealBaseDifficulty() != 20
        )
            ++bad;
        // the devConcealMagicalDifficulty pin
    if (devConcealMagicalDifficulty() != 40
        )
            ++bad;
        // the devDeludeBaseDifficulty pin
    if (devDeludeBaseDifficulty() != 30
        )
            ++bad;
        // the devDeludeEspDifficulty pin
    if (devDeludeEspDifficulty() != 60
        )
            ++bad;
        // the devDeludeGiantExampleDifficulty pin
    if (devDeludeGiantExampleDifficulty() != 150
        )
            ++bad;
        // the devPhantomBaseDifficulty pin
    if (devPhantomBaseDifficulty() != 40
        )
            ++bad;
        // the devPhantomMentalCost pin
    if (devPhantomMentalCost() != 40
        )
            ++bad;
        // the devShadowDisbelievedAc pin
    if (devShadowDisbelievedAc() != 4
        )
            ++bad;
        // the devShadowDisbelievedPct pin
    if (devShadowDisbelievedPct() != 80
        )
            ++bad;
        // the devShadowSpecialPersistPct pin
    if (devShadowSpecialPersistPct() != 50
        )
            ++bad;
        // the devEnergyWallDifficulty pin
    if (devEnergyWallDifficulty() != 25
        )
            ++bad;
        // the devEnergyWallDmgDice pin
    if (devEnergyWallDmgDice() != 2
        )
            ++bad;
        // the devEnergyWallDmgSize pin
    if (devEnergyWallDmgSize() != 8
        )
            ++bad;
        // the devEnergyWallNearbyDmg pin
    if (devEnergyWallNearbyDmg() != 8
        )
            ++bad;
        // the devEnergyWallNearbyFt pin
    if (devEnergyWallNearbyFt() != 10
        )
            ++bad;
        // the devSoftWallDifficulty pin
    if (devSoftWallDifficulty() != 50
        )
            ++bad;
        // the devHardWallDifficulty pin
    if (devHardWallDifficulty() != 75
        )
            ++bad;
        // the devForceWallDifficulty pin
    if (devForceWallDifficulty() != 100
        )
            ++bad;
        // the devFallingWallDmgDice pin
    if (devFallingWallDmgDice() != 3
        )
            ++bad;
        // the devFallingWallDmgSize pin
    if (devFallingWallDmgSize() != 10
        )
            ++bad;
        // the devMatterBlockDifficulty pin
    if (devMatterBlockDifficulty() != 35
        )
            ++bad;
        // the devMatterSoftDifficulty pin
    if (devMatterSoftDifficulty() != 70
        )
            ++bad;
        // the devMatterMetalDifficulty pin
    if (devMatterMetalDifficulty() != 105
        )
            ++bad;
        // the devStrikeBaseDifficulty pin
    if (devStrikeBaseDifficulty() != 25
        )
            ++bad;
        // the devStrikeDmgDice pin
    if (devStrikeDmgDice() != 2
        )
            ++bad;
        // the devStrikeMaxDice pin
    if (devStrikeMaxDice() != 30
        )
            ++bad;
        // the devStrikeStepPerFive pin
    if (devStrikeStepPerFive() != 5
        )
            ++bad;
        // the devMobileSpellAc pin
    if (devMobileSpellAc() != 0
        )
            ++bad;
        // the devCrushingSpellAc pin
    if (devCrushingSpellAc() != -2
        )
            ++bad;
        // the devCrushingSpellHpMult pin
    if (devCrushingSpellHpMult() != 2
        )
            ++bad;
        // the devAnimateDeadBaseDifficulty pin
    if (devAnimateDeadBaseDifficulty() != 25
        )
            ++bad;
        // the devAnimateDeadDoubleDifficulty pin
    if (devAnimateDeadDoubleDifficulty() != 50
        )
            ++bad;
        // the devAnimateDeadTripleDifficulty pin
    if (devAnimateDeadTripleDifficulty() != 75
        )
            ++bad;
        // the devAnimateScatteredAdj pin
    if (devAnimateScatteredAdj() != 25
        )
            ++bad;
        // the devAnimateScatteredAncientAdj pin
    if (devAnimateScatteredAncientAdj() != 75
        )
            ++bad;
        // the devSlayBaseDifficulty pin
    if (devSlayBaseDifficulty() != 50
        )
            ++bad;
        // the devSlayHdPerFive pin
    if (devSlayHdPerFive() != 1
        )
            ++bad;
        // the devSlaySaveHdMin pin
    if (devSlaySaveHdMin() != 9
        )
            ++bad;
        // the devTapBaseDifficulty pin
    if (devTapBaseDifficulty() != 40
        )
            ++bad;
        // the devTapDmgDie pin
    if (devTapDmgDie() != 8
        )
            ++bad;
        // the devTapMaxDice pin
    if (devTapMaxDice() != 30
        )
            ++bad;
        // the devTapTransferDifficulty pin
    if (devTapTransferDifficulty() != 80
        )
            ++bad;
        // the devTapAbilityTransferDifficulty pin
    if (devTapAbilityTransferDifficulty() != 160
        )
            ++bad;
        // the devTapLevelDifficulty pin
    if (devTapLevelDifficulty() != 120
        )
            ++bad;
        // the devTapLevelTransferDifficulty pin
    if (devTapLevelTransferDifficulty() != 240
        )
            ++bad;
        // the devPrepHoursPerDay pin
    if (devPrepHoursPerDay() != 8
        )
            ++bad;
        // the devPharjisLevel pin
    if (devPharjisLevel() != 25
        )
            ++bad;
        // the devPharjisDiff15PrepWeeks pin
    if (devPharjisDiff15PrepWeeks() != 1
        )
            ++bad;
        // the devPharjisExplosionLostDays pin
    if (devPharjisExplosionLostDays() != 2
        )
            ++bad;
        // the devPharjisDiff55PrepMonths pin
    if (devPharjisDiff55PrepMonths() != 2
        )
            ++bad;
        // the devFinalCheckDie pin
    if (devFinalCheckDie() != 100
        )
            ++bad;
        // the devPharjisDiff55Final pin
    if (devPharjisDiff55Final() != 28
        )
            ++bad;
        // the devPharjisDiff15Shortened pin
    if (devPharjisDiff15Shortened() != 30
        )
            ++bad;
        // the devPharjisDiff160Final pin
    if (devPharjisDiff160Final() != 80
        )
            ++bad;
        // the devHoldTimeCap pin
    if (devHoldTimeCap() != 1
        )
            ++bad;
        // the devExRevealBase pin
    if (devExRevealBase() != 20
        )
            ++bad;
        // the devExRegionAdj pin
    if (devExRegionAdj() != 80
        )
            ++bad;
        // the devExHalfDayAdj pin
    if (devExHalfDayAdj() != 10
        )
            ++bad;
        // the devExCombinedDifficulty pin
    if (devExCombinedDifficulty() != 110
        )
            ++bad;
        // the devExAdjustedDifficulty pin
    if (devExAdjustedDifficulty() != 70
        )
            ++bad;
        // the devExExoticHalved pin
    if (devExExoticHalved() != 35
        )
            ++bad;
        // the devExRareReduced pin
    if (devExRareReduced() != 5
        )
            ++bad;
        // the devExDoubledFinal pin
    if (devExDoubledFinal() != 10
        )
            ++bad;
        // the devExFailRoll pin
    if (devExFailRoll() != 2
        )
            ++bad;
        // the devExSuccessRoll pin
    if (devExSuccessRoll() != 81
        )
            ++bad;
        // the devExWatchHours pin
    if (devExWatchHours() != 12
        )
            ++bad;
        // the devDispelMagicSuppressRounds pin
    if (devDispelMagicSuppressRounds() != 4
        )
            ++bad;
        // the devDisjunctionPctPerLevel pin
    if (devDisjunctionPctPerLevel() != 1
        )
            ++bad;
        // the devLimitedWishHours pin
    if (devLimitedWishHours() != 8
        )
            ++bad;
        // the devDuelPR pin
    if (devDuelPR() != 19
        )
            ++bad;
        // the devQuestWardSaveFloor pin
    if (devQuestWardSaveFloor() != 18
        )
            ++bad;
        // the devKnownDweomerCount pin
    if (devKnownDweomerCount() != 13
        )
            ++bad;
        // the devHurdSavePenalty pin
    if (devHurdSavePenalty() != -8
        )
            ++bad;
        // the devKolinUndeadHd pin
    if (devKolinUndeadHd() != 200
        )
            ++bad;
        // the devKrebDragonFailPct pin
    if (devKrebDragonFailPct() != 20
        )
            ++bad;
        // the devNazzerBaseDiff pin
    if (devNazzerBaseDiff() != 55
        )
            ++bad;
        // the devNazzerCloakDiff pin
    if (devNazzerCloakDiff() != 90
        )
            ++bad;
        // the devNazzerCloakFinal pin
    if (devNazzerCloakFinal() != 13
        )
            ++bad;
        // the devNazzerItemLevel pin
    if (devNazzerItemLevel() != 12
        )
            ++bad;
        // the devNazzerCloakRounds pin
    if (devNazzerCloakRounds() != 10
        )
            ++bad;
        // the devNejaPleaHours pin
    if (devNejaPleaHours() != 12
        )
            ++bad;
        // the devNejaPleaSaveBonus pin
    if (devNejaPleaSaveBonus() != -3
        )
            ++bad;
        // the devRatecliffeHd pin
    if (devRatecliffeHd() != 40
        )
            ++bad;
        // the devRatecliffeAreaFt pin
    if (devRatecliffeAreaFt() != 50
        )
            ++bad;
        // the devTenserDmgDice pin
    if (devTenserDmgDice() != 20
        )
            ++bad;
        // the devTenserDmgBonus pin
    if (devTenserDmgBonus() != 20
        )
            ++bad;
        // the devWulfRectAreaDia pin
    if (devWulfRectAreaDia() != 50
        )
            ++bad;
        // the devWulfRectMrPenalty pin
    if (devWulfRectMrPenalty() != -20
        )
            ++bad;
        // the devYunniWeightLbs pin
    if (devYunniWeightLbs() != 50
        )
            ++bad;
        // the devT28RowCount pin
    if (devT28RowCount() != 29
        )
            ++bad;
        // the devT29RowCount pin
    if (devT29RowCount() != 10
        )
            ++bad;
        // the devT30RowCount pin
    if (devT30RowCount() != 6
        )
            ++bad;
        // the devT31RowCount pin
    if (devT31RowCount() != 10
        )
            ++bad;
        // the devT32RowCount pin
    if (devT32RowCount() != 11
        )
            ++bad;
        // the devT33RowCount pin
    if (devT33RowCount() != 10
        )
            ++bad;
        // the devT35RowCount pin
    if (devT35RowCount() != 29
        )
            ++bad;
        // the devProvinceMiles pin
    if (devProvinceMiles() != 20
        )
            ++bad;
        // the devRegionMiles pin
    if (devRegionMiles() != 100
        )
            ++bad;
        // the devAreaAllCreaturesMult pin
    if (devAreaAllCreaturesMult() != 10
        )
            ++bad;
        // the devNoScrollOrDevice pin
    if (devNoScrollOrDevice() != 1
        )
            ++bad;
        // the devNeverSameTwice pin
    if (devNeverSameTwice() != 1
        )
            ++bad;
        // the devDmApprovalRequired pin
    if (devDmApprovalRequired() != 1
        )
            ++bad;
        // the devWizardsAnySchool pin
    if (devWizardsAnySchool() != 1
        )
            ++bad;
        // the devCommonComponentRequired pin
    if (devCommonComponentRequired() != 1
        )
            ++bad;
        // the devPriestHolySymbolNeeded pin
    if (devPriestHolySymbolNeeded() != 1
        )
            ++bad;
        // the devWizardsNeedNoSpellbook pin
    if (devWizardsNeedNoSpellbook() != 1
        )
            ++bad;
        // the devComponentsSymbolic pin
    if (devComponentsSymbolic() != 1
        )
            ++bad;
        // the devExoticEitherNotBoth pin
    if (devExoticEitherNotBoth() != 1
        )
            ++bad;
        // the devWardHalfEvenOnFail pin
    if (devWardHalfEvenOnFail() != 1
        )
            ++bad;
        // the devWardTwoResistRolls pin
    if (devWardTwoResistRolls() != 1
        )
            ++bad;
        // the devTransformSimplePermanentFree pin
    if (devTransformSimplePermanentFree() != 1
        )
            ++bad;
        // the devAfflictHarmlessPermanentFree pin
    if (devAfflictHarmlessPermanentFree() != 1
        )
            ++bad;
        // the devBindYearlySave pin
    if (devBindYearlySave() != 1
        )
            ++bad;
        // the devBindNoSuicide pin
    if (devBindNoSuicide() != 1
        )
            ++bad;
        // the devSummonNoControlOvernamed pin
    if (devSummonNoControlOvernamed() != 1
        )
            ++bad;
        // the devGolemsNeverCharmed pin
    if (devGolemsNeverCharmed() != 1
        )
            ++bad;
        // the devRevealNoSaveUnlessUnwilling pin
    if (devRevealNoSaveUnlessUnwilling() != 1
        )
            ++bad;
        // the devConcealBrokenByAttack pin
    if (devConcealBrokenByAttack() != 1
        )
            ++bad;
        // the devTrueSeeingDefeatsConceal pin
    if (devTrueSeeingDefeatsConceal() != 1
        )
            ++bad;
        // the devPhantomNoRealDamage pin
    if (devPhantomNoRealDamage() != 1
        )
            ++bad;
        // the devMatterPermanentFree pin
    if (devMatterPermanentFree() != 1
        )
            ++bad;
        // the devForceImmuneToOwnEnergy pin
    if (devForceImmuneToOwnEnergy() != 1
        )
            ++bad;
        // the devOnlyPriestsHealWithTap pin
    if (devOnlyPriestsHealWithTap() != 1
        )
            ++bad;
        // the devTapDamageInstantOnly pin
    if (devTapDamageInstantOnly() != 1
        )
            ++bad;
        // the devPrepDayRestart pin
    if (devPrepDayRestart() != 1
        )
            ++bad;
        // the devPrepWeekBacktrack pin
    if (devPrepWeekBacktrack() != 1
        )
            ++bad;
        // the devPrepExtensionHalves pin
    if (devPrepExtensionHalves() != 1
        )
            ++bad;
        // the devCastDailyNoBreaks pin
    if (devCastDailyNoBreaks() != 1
        )
            ++bad;
        // the devCastBrokenRuinsSpell pin
    if (devCastBrokenRuinsSpell() != 1
        )
            ++bad;
        // the devPlayCasterLevelSaves pin
    if (devPlayCasterLevelSaves() != 1
        )
            ++bad;
        // the devIounStonesIneffective pin
    if (devIounStonesIneffective() != 1
        )
            ++bad;
        // the devDispelMagicAreaCapped pin
    if (devDispelMagicAreaCapped() != 1
        )
            ++bad;
        // the devWishAutoDispels pin
    if (devWishAutoDispels() != 1
        )
            ++bad;
        // the devDispelDestroysBarriers pin
    if (devDispelDestroysBarriers() != 1
        )
            ++bad;
        // the devSphericalBarriersHold pin
    if (devSphericalBarriersHold() != 1
        )
            ++bad;
        // the devDuelCountersUseless pin
    if (devDuelCountersUseless() != 1
        )
            ++bad;
        // the devQuestSpellsUncounterable pin
    if (devQuestSpellsUncounterable() != 1
        )
            ++bad;
        // the devQuestWardMrHalved pin
    if (devQuestWardMrHalved() != 1
        )
            ++bad;
        // the devNazzerAutoFailOne pin
    if (devNazzerAutoFailOne() != 1
        )
            ++bad;
        // the devNejaToadstoolSystemShock pin
    if (devNejaToadstoolSystemShock() != 1
        )
            ++bad;
        // the devRatecliffeWishOnlyRevival pin
    if (devRatecliffeWishOnlyRevival() != 1
        )
            ++bad;
        // the Pharjis computation: 20 + 80 + 10 = 110 (printed p. 134)
    if (devExRevealBase() + devExRegionAdj() + devExHalfDayAdj() != 110
            || devExCombinedDifficulty() != 110
        )
            ++bad;
        // the Pharjis adjustment: 110 - 25 - 5 - 10 = 70 (printed p. 134)
    if (devExCombinedDifficulty() + devCasterLevelStep() * devPharjisLevel() +
        devSpecialistBonus() + devPrevCastBonus() != 70
            || devExAdjustedDifficulty() != 70
        )
            ++bad;
        // the Pharjis exotic read: half of 70 is 35 (printed p. 134)
    if (devExAdjustedDifficulty() / 2 != 35
            || devExExoticHalved() != 35
        )
            ++bad;
        // the Pharjis rare read: 35 - 30 = 5 (printed p. 134)
    if (devExExoticHalved() + devRareComponentLimit() != 5
            || devExRareReduced() != 5
        )
            ++bad;
        // the Pharjis final: doubling 5 to shorten preparation gives 10
        // (printed p. 134)
    if (devExRareReduced() * 2 != 10
            || devExDoubledFinal() != 10
        )
            ++bad;
        // the Pharjis roll: 02 fails, 81 succeeds against 10 (printed p. 134)
    if (devExFailRoll() >= 10
            || devExSuccessRoll() < 10
        )
            ++bad;
        // the Pharjis time trade: difficulty 55 halved and rounded up is 28
        // (printed p. 133)
    if ((55 + 1) / 2 != 28
            || devPharjisDiff55Final() != 28
        )
            ++bad;
        // the Pharjis 160 read: halved by the two-year preparation is 80
        // (printed p. 134)
    if (devPharjisDiff160Final() != 80
        )
            ++bad;
        // the Table 28 read: slay is the hardest base at 50, charm and
        // conceal and reveal the easiest at 20 (printed p. 120)
    if (devT28BaseDiff(27) != 50
            || devT28BaseDiff(13) != 20
            || devT28BaseDiff(18) != 20
            || devT28BaseDiff(19) != 20
        )
            ++bad;
        // the Table 28 read: the ward base 35, the reflect 25 (printed p.
        // 120)
    if (devT28BaseDiff(3) != 35
            || devT28BaseDiff(2) != 25
        )
            ++bad;
        // the Table 28 shadow shape row: variable throughout (printed p. 120)
    if (devT28BaseDiff(21) != -99
            || devT28BaseDuration(21) != -99
            || devT28EffectCode(21) != -99
        )
            ++bad;
        // the Table 29 read: the plane row costs 160 with a million-pound
        // object cap (printed p. 130)
    if (devT29Difficulty(9) != 160
            || devT29ObjectLbs(9) != 1000000
            || devT29AreaFt(9) != -99
        )
            ++bad;
        // the Table 29 read: the base row is one creature, five feet, zero
        // difficulty (printed p. 130)
    if (devT29Creatures(0) != 1
            || devT29AreaFt(0) != 5
            || devT29Difficulty(0) != 0
        )
            ++bad;
        // the Table 30 read: a man-sized object weighs 200 pounds and
        // averages 10 damage (printed p. 130)
    if (devT30WeightLbs(2) != 200
            || devT30Damage(2) != 10
        )
            ++bad;
        // the Table 31 read: touch is free, trans-planar costs 100 (printed
        // p. 131)
    if (devT31Difficulty(0) != 0
            || devT31Difficulty(9) != 100
        )
            ++bad;
        // the Table 32 read: one round costs 1, one year 70, permanent 100
        // (printed p. 131)
    if (devT32Difficulty(1) != 1
            || devT32Difficulty(9) != 70
            || devT32Difficulty(10) != 100
        )
            ++bad;
        // the Table 33 read: difficulty 15 sits in the week band; 55 in the
        // two-month band (printed pp. 132-133)
    if (devT33PrepCode(4) != 4
            || devT33CastCode(4) != 1
            || devT33PrepCode(7) != 7
            || devT33CastCode(7) != 3
        )
            ++bad;
        // the Table 33 read: the top band prepares a year and casts a week
        // (printed p. 132)
    if (devT33PrepCode(9) != 9
            || devT33CastCode(9) != 4
        )
            ++bad;
        // the Table 35 read: dispel is attack/defense, strike a missile,
        // phantom any (printed p. 135)
    if (devT35DuelType(1) != 2
            || devT35DuelType(25) != 4
            || devT35DuelType(21) != 5
            || devT35DuelType(22) != 6
        )
            ++bad;
        // the known list: Kolin's Legion is the hardest at 325; Neja's Plea
        // the easiest at 60 (printed pp. 136-139)
    if (devKnownDifficulty(1) != 325
            || devKnownDifficulty(5) != 60
        )
            ++bad;
        // the known list: Tenser's final runs negative at -7, Yunni's at -2
        // (printed pp. 140-141)
    if (devKnownFinal(9) != -7
            || devKnownFinal(12) != -2
        )
            ++bad;
        // the ward resistance ladder: 105 for 50 percent, 210 for 100
        // (printed p. 122)
    if (devWardPctResistDifficulty() * 2 != 210
            || devWardFullResistDifficulty() != 210
        )
            ++bad;
        // the reflect ladder: 25 doubled 50 tripled 75 (printed p. 122)
    if (devReflectSingleDifficulty() * 2 != 50
            || devReflectSingleDifficulty() * 3 != 75
        )
            ++bad;
        // the fortify ladder: 30, 60, 90, 120 in even multiples (printed p.
        // 124)
    if (devT28BaseDiff(6) * 2 != 60
            || devFortifyDoubleDifficulty() != 60
            || devT28BaseDiff(6) * 4 != 120
            || devFortifyQuadDifficulty() != 120
        )
            ++bad;
        // the dispel read: 11-or-higher on d20 is the 50-percent base
        // (printed p. 122)
    if (devDispelSuccessRollMin() != 11
            || devDispelBasePct() != 50
        )
            ++bad;
        // the strike read: 2d8 base, +1d8 per five, capped at 30d8 (printed
        // p. 129)
    if (devStrikeDmgDice() != 2
            || devStrikeMaxDice() != 30
            || devStrikeStepPerFive() != 5
        )
            ++bad;
        // the animate dead ladder: 25, 50, 75 (printed p. 129)
    if (devAnimateDeadBaseDifficulty() * 2 != 50
            || devAnimateDeadTripleDifficulty() != 75
        )
            ++bad;
        // the tap transfer ladder: 80, 160, 120, 240 (printed p. 130)
    if (devTapTransferDifficulty() * 2 != 160
            || devTapLevelDifficulty() * 2 != 240
        )
            ++bad;
        // the area multiplier: all-creatures spells cost ten times the
        // modifier (printed p. 130)
    if (devAreaAllCreaturesMult() != 10
        )
            ++bad;
        // the duration past read: Table 32 divided by ten makes ten years
        // cost 70 (printed p. 127)
    if (devT32Difficulty(9) / devRevealPastDivisor() != 7
            || devRevealPastTenYears() != 70
        )
            ++bad;
        // the requisites: 20th level, ability 18, four per day (printed p.
        // 119)
    if (devMinCasterLevel() != 20
            || devMinAbilityScore() != 18
            || devMaxPerDay() != 4
        )
            ++bad;
        printf("R607 DMO true-dweomers audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r608_dmo_auto_save_failure.h"  // R831: migrated
