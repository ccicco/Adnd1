    // ---- R947 issue-22 sneak preview audit ----
    // THE DRAGON ISSUE-22 OPENER PART TWO - the AD&D sneak preview of the
    // Dungeon Masters Guide, the single-chain table round of the four-round
    // shape. Pinned: the magic items of the six modules (the amulet of the
    // planes and its seventeen plane bands, the hammer of thunderbolts, the
    // helm of underwater action, the Nolzur pigments, the pearl of wisdom,
    // the periapt chart, the two philters, the water breathing potion), the
    // four elemental command rings with their power counts and save
    // penalties, the eight protection scrolls with their reading times and
    // hit-dice caps, the creatures-struck-only-by-magic-weapons grades, the
    // grenade-like missile rules, the attack matrix I.D point one for thieves
    // assassins and monks, the cleric-undead matrix with the T D and dash
    // symbols converted ninety-seven ninety-eight ninety-nine and zero, the
    // psionic IV.B crush percentages IV.C blast saves and IV.D ranges, and
    // the three saving throw matrices - the characters, the monster rules and
    // the items. The print catches pinned as scanned: Freet Giant Jari, con
    // penetrate, jackolwere, wralths, the Ghost row printed twice for the
    // Ghast, Petrifaction, the farce and an die footnote, the missing I.D
    // footnote e, the I.B armor class three eleven and the dropped armor
    // class ten cell, the five I.C bands over four columns with the dangling
    // Opponent, and the overlapping IV.B defender band.
    {
        using namespace rules;
        int bad = 0;
    if (s22GenConYear() != 1979
            || s22GenConNumber() != 12
            || s22PreviewModules() != 6
            || s22AmuletCount() != 17
            || s22AmuletAdd12From() != 4
            || s22AmuletResults() != 24
            || s22AmuletAltEthereal() != 22
            || s22AmuletAltAstral() != 23
            || s22AmuletAltPrime() != 24
            || s22HammerStrengthMin() != 1801
            || s22HammerHeightFeet() != 6
            || s22HammerBasePlus() != 3
            || s22HammerTrueNamePlus() != 5
            || s22HammerStunRadiusInches() != 3
            || s22HammerStunRounds() != 1
            || s22HammerThrowsPerTwoTurns() != 5
            || s22HammerRestTurns() != 1
            || s22HammerThorFactor() != 2
            || s22HelmVisionFactor() != 5
            || s22PigmentCubicFeet() != 1000
            || s22PigmentSurfaceFeet() != 100
            || s22PigmentPotsMin() != 1
            || s22PigmentPotsMax() != 4
            || s22PigmentDepictTurns() != 1
            || s22PearlMonths() != 1
            || s22PearlDays() != 30
            || s22PearlCursedPct() != 5
            || s22PeriaptCount() != 4
            || s22PeriaptNoSavePct() != 10
            || s22PhilterLoveBaseTurns() != 4
            || s22PhilterLoveExtraMin() != 1
            || s22PhilterLoveExtraMax() != 4
            || s22PhilterPersuasionPct() != 25
            || s22PhilterSuggestRangeInches() != 3
            || s22PotionTwoDosePct() != 75
            || s22PotionDosesMin() != 2
            || s22PotionDosesMax() != 4
            || s22PotionHoursPerDose() != 1
            || s22PotionExtraRoundsMin() != 1
            || s22PotionExtraRoundsMax() != 10
            || s22RingTypes() != 4
            || s22RingKeepFeet() != 5
            || s22RingCharmSaveMinus() != 2
            || s22RingFoeHitMinus() != 1
            || s22RingSavePlus() != 2
            || s22RingHitPlus() != 4
            || s22RingDamagePlus() != 6
            || s22RingOperateLevel() != 10
            || s22RingPowerSegments() != 5
            || s22RingElementalSaveMinus() != 2
            || s22RingAirPowers() != 5
            || s22RingEarthPowers() != 6
            || s22RingFirePowers() != 5
            || s22RingWaterPowers() != 8
            || s22ScrollKinds() != 8
            || s22ScrollMagicSegments() != 8
            || s22ScrollMagicRadiusFeet() != 5
            || s22ScrollMagicDrainPct() != 50
            || s22ScrollMagicSaveFloor() != 11
            || s22ScrollMagicRoundsMin() != 5
            || s22ScrollMagicRoundsMax() != 30
            || s22ScrollPetrifactionSegments() != 5
            || s22ScrollPetrifactionRoundsMin() != 5
            || s22ScrollPetrifactionRoundsMax() != 20
            || s22ScrollPossessionRounds() != 1
            || s22ScrollPossessionRoundsMin() != 10
            || s22ScrollPossessionRoundsMax() != 60
            || s22ScrollPossessionTurnsMin() != 10
            || s22ScrollPossessionTurnsMax() != 60
            || s22ScrollPossessionStationaryPct() != 10
            || s22ScrollUndeadSegments() != 4
            || s22ScrollUndeadRadiusFeet() != 5
            || s22ScrollUndeadRoundsMin() != 10
            || s22ScrollUndeadRoundsMax() != 80
            || s22ScrollUndeadHdCap() != 35
            || s22ScrollDemonLordRounds() != 1
            || s22ScrollDemonMidSegments() != 7
            || s22ScrollDemonLesserSegments() != 3
            || s22ScrollDemonPauseSegments() != 1
            || s22ScrollDemonRoundsMin() != 5
            || s22ScrollDemonRoundsMax() != 20
            || s22ScrollDevilArchRounds() != 1
            || s22ScrollDevilGreaterSegments() != 7
            || s22ScrollDevilLesserSegments() != 3
            || s22ScrollElementalSegments() != 6
            || s22ScrollElementalRoundsMin() != 5
            || s22ScrollElementalRoundsMax() != 40
            || s22ScrollElementalSpecificHd() != 24
            || s22ScrollElementalAllHd() != 16
            || s22ScrollLycanSegments() != 4
            || s22ScrollLycanRoundsMin() != 5
            || s22ScrollLycanRoundsMax() != 30
            || s22ScrollLycanHdCap() != 49
            || s22ScrollLycanPlusThreshold() != 2
            || s22ElemScrollCount() != 5
            || s22LycanScrollCount() != 7
            || s22HitOnlyCount() != 4
            || s22UndeadCount() != 13
            || s22UndeadFootnotes() != 6
            || s22TurnAffectedMin() != 1
            || s22TurnAffectedMax() != 12
            || s22TurnStarMin() != 7
            || s22TurnFleeRoundsMin() != 3
            || s22TurnFleeRoundsMax() != 12
            || s22TurnSpecialMin() != 1
            || s22TurnSpecialMax() != 2
            || s22TurnSpecialAc() != -5
            || s22TurnSpecialHd() != 11
            || s22TurnSpecialMrPct() != 66
            || s22BlastCost() != 20
            || s22MindThrustCost() != 4
            || s22EgoWhipCost() != 7
            || s22IdInsinuationCost() != 10
            || s22PsychicCrushCost() != 14
            || s22MindBlankCost() != 1
            || s22ThoughtShieldCost() != 2
            || s22MentalBarrierCost() != 3
            || s22IntellectFortressCost() != 8
            || s22TowerIronWillCost() != 10
            || s22PsiCrushCount() != 6
            || s22PsiConfusedRoundsMin() != 2
            || s22PsiConfusedRoundsMax() != 8
            || s22PsiDazedTurnsMin() != 1
            || s22PsiDazedTurnsMax() != 4
            || s22PsiComaWeeksMin() != 1
            || s22PsiComaWeeksMax() != 4
            || s22PsiRobotWeeksMin() != 2
            || s22PsiRobotWeeksMax() != 8
            || s22PsiWoundedWeeksMin() != 2
            || s22PsiWoundedWeeksMax() != 8
            || s22PsiCatatonicPct() != 99
            || s22PsiMindBarPoints() != 40
            || s22PsiBlastCount() != 11
            || s22PsiFeebleCap() != 5
            || s22PsiRangeCount() != 5
            || s22PsiSeriesBonusPct() != 50
            || s22PsiMediumDamageCutPct() != 20
            || s22PsiLongCategoryCut() != 25
            || s22PsiLongDamageCutPct() != 20
            || s22PsiLongLowBandCutPct() != 50
            || s22SaveMatrices() != 3
            || s22SaveAutoFail() != 1
            || s22SaveCharCount() != 28
            || s22SaveClericBands() != 7
            || s22SaveFighterBands() != 10
            || s22SaveMuBands() != 5
            || s22SaveThiefBands() != 6
            || s22MonsterPlusCap() != 3
            || s22NonIntDivisor() != 2
            || s22ItemRowCount() != 14
            || s22ItemAttackForms() != 11
            || s22ItemMagicBonus() != 2
            || s22ItemPlusBonus() != 1
            || s22ItemOwnModeBonus() != 5
            || s22ItemFallBaseFeet() != 5
            || s22ItemFallSoftBonus() != 1
            || s22ItemFallFleshyBonus() != 5
            || s22ItemFallPenaltyFeet() != 5
            || s22ItemColdSavePenalty() != 10
            || s22ItemPaperRounds() != 1
            || s22ItemClothRounds() != 2
            || s22ItemBoneRounds() != 3
            || s22GrenadeRangeInches() != 3
            || s22GrenadeMediumFrom() != 1
            || s22GrenadeLongFrom() != 2
            || s22GrenadeMediumMinus() != 2
            || s22GrenadeLongMinus() != 5
            || s22GrenadeSplashFeet() != 3
            || s22GiantBoulderFeet() != 1
            || s22SiegeBoulderFeet() != 2
            || s22AcidOunces() != 8
            || s22HolyOunces() != 4
            || s22OilOunces() != 16
            || s22PoisonOunces() != 4
            || s22AcidSplashHp() != 1
            || s22AcidDirectMin() != 2
            || s22AcidDirectMax() != 8
            || s22HolySplashHp() != 2
            || s22HolyDirectMin() != 2
            || s22HolyDirectMax() != 7
            || s22OilDiameterFeet() != 3
            || s22OilBurnSegmentsMin() != 1
            || s22OilBurnSegmentsMax() != 3
            || s22OilDirectFirstMin() != 2
            || s22OilDirectFirstMax() != 12
            || s22OilDirectSecondMin() != 1
            || s22OilDirectSecondMax() != 6
            || s22OilWalkDamageMin() != 1
            || s22OilWalkDamageMax() != 4
            || s22GrenadeMissDistanceDie() != 6
            || s22GrenadeMissDirectionDie() != 8
            || s22LanternAreaFeet() != 2
            || s22ThievesCount() != 21
            || s22MissileLongMinus() != 5
            || s22MissileMediumMinus() != 2
            || s22AcFloor() != 10
            || s22AcProjectionRepeats() != 6
            || s22MonsterMatrixCols() != 12
            || s22BackstabMin() != 2
            || s22BackstabMax() != 5
            || s22AssassinationRows() != 15
            || s22FighterAc3Prints() != 11
            || s22MuHeaderBands() != 5
            || s22MuDataCols() != 4
            || !s22ModuleItemsNotRepeated()
            || !s22NewItemDoctrine()
            || !s22AmuletSafeTravel()
            || !s22HammerGiantSlain()
            || !s22HammerEveryOtherRound()
            || !s22HelmCommandGlobe()
            || !s22PigmentInanimateOnly()
            || !s22PigmentValuablesFalse()
            || !s22PearlRetainOrLose()
            || !s22PeriaptPermanentPlus()
            || !s22PhilterDispelEnds()
            || !s22RingCharmGamble()
            || !s22RingAnyWeaponHits()
            || !s22RingRespectDoctrine()
            || !s22ScrollsCumulative()
            || !s22ScrollMagicDrainCancels()
            || !s22ScrollMagicArtifactsImmune()
            || !s22ScrollPossessionDeadBodies()
            || !s22ScrollLycanShapechangers()
            || !s22HitOnlyCharactersExempt()
            || !s22GrenadeOilAlightOnly()
            || !s22GrenadePoisonSwallowed()
            || !s22HolyWaterNonmaterialImmune()
            || !s22TurnNoRetry()
            || !s22TurnNeutralIgnore()
            || !s22PsiSimultaneous()
            || !s22PsiCrushThoughtShieldOnly()
            || !s22PsiMindBarLetters()
            || !s22PsiIdiocyHealable()
            || !s22PsiRobotSaveVsMagic()
            || !s22SaveMultiClassBest()
            || !s22MonsterPlusBump()
            || !s22NonIntRoundedUp()
            || !s22NonIntPoisonException()
            || !s22ItemInterpolated()
            || !s22ItemOwnModeBoth()
            || !s22SaveSpellExclusions()
            || !s22FreetJariPrintCatch()
            || !s22ConPenetratePrintCatch()
            || !s22JackolwerePrintCatch()
            || !s22WralthsPrintCatch()
            || !s22GhastPrintsGhost()
            || !s22PetrifactionPrint()
            || !s22FarceAnDiePrintCatch()
            || !s22ThievesFootnotePrintCatch()
            || !s22FighterAc3PrintCatch()
            || !s22FighterAc10GapPrintCatch()
            || !s22MuBandsPrintCatch()
            || !s22MuOpponentDangling()
            || !s22PsiBandPrintCatch()
        )
            ++bad;
        // the amulet of the planes grid - seventeen bands one through
        // twenty-four, the d6 add-twelve rule, the plane code pinned by band
        // order
        int CAm[17][3] = {
            {1,2,1},
            {3,3,2},
            {4,4,3},
            {5,5,4},
            {6,7,5},
            {8,8,6},
            {9,9,7},
            {10,10,8},
            {11,12,9},
            {13,13,10},
            {14,14,11},
            {15,15,12},
            {16,17,13},
            {18,18,14},
            {19,19,15},
            {20,20,16},
            {21,24,17},
            };
        for (int b = 0;
             b < s22AmuletCount();
             ++b) {
            int vals[3];
            vals[0] = s22AmuletLo(b);
            vals[1] = s22AmuletHi(b);
            vals[2] = s22AmuletPlane(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CAm[b][c])
                    ++bad;
            }
        }
        // the periapt of proof against poison grid - the four plus bands
        // rolled once when found
        int CPp[4][3] = {
            {1,8,1},
            {9,14,2},
            {15,18,3},
            {19,20,4},
            };
        for (int b = 0;
             b < s22PeriaptCount();
             ++b) {
            int vals[3];
            vals[0] = s22PeriaptLo(b);
            vals[1] = s22PeriaptHi(b);
            vals[2] = s22PeriaptPlus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CPp[b][c])
                    ++bad;
            }
        }
        // the creatures-struck-only-by-magic-weapons grid - the four grades,
        // the weapon alternative and the hit-dice alternative
        int CMw[4][4] = {
            {1,1,4,1},
            {2,2,6,2},
            {3,3,8,3},
            {4,4,10,4},
            };
        for (int b = 0;
             b < s22HitOnlyCount();
             ++b) {
            int vals[4];
            vals[0] = s22HitOnlyPlus(b);
            vals[1] = s22HitOnlyAttacker(b);
            vals[2] = s22HitOnlyHdBase(b);
            vals[3] = s22HitOnlyHdPlus(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CMw[b][c])
                    ++bad;
            }
        }
        // the attack matrix I.D point one for thieves assassins and monks -
        // the twenty-one armor class rows by the six level bands, the
        // backstab multipliers riding the footnote lines
        int CId[21][7] = {
            {-10,26,24,21,20,20,20},
            {-9,25,23,20,20,20,19},
            {-8,24,22,20,20,20,18},
            {-7,23,21,20,20,19,17},
            {-6,22,20,20,20,18,16},
            {-5,21,20,20,19,17,15},
            {-4,20,20,20,18,16,14},
            {-3,20,20,19,17,15,13},
            {-2,20,20,18,16,14,12},
            {-1,20,20,17,15,13,11},
            {0,20,19,16,14,12,10},
            {1,20,18,15,13,11,9},
            {2,19,17,14,12,10,8},
            {3,18,16,13,11,9,7},
            {4,17,15,12,10,8,6},
            {5,16,14,11,9,7,5},
            {6,15,13,10,8,6,4},
            {7,14,12,9,7,5,3},
            {8,13,11,8,6,4,2},
            {9,12,10,7,5,3,1},
            {10,11,9,6,4,2,0},
            };
        for (int b = 0;
             b < s22ThievesCount();
             ++b) {
            int vals[7];
            vals[0] = s22ThievesAc(b);
            vals[1] = s22ThievesL1(b);
            vals[2] = s22ThievesL2(b);
            vals[3] = s22ThievesL3(b);
            vals[4] = s22ThievesL4(b);
            vals[5] = s22ThievesL5(b);
            vals[6] = s22ThievesL6(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CId[b][c])
                    ++bad;
            }
        }
        // the protection from elementals grid - the five varieties,
        // twenty-four hit dice specific and sixteen against all
        int CEs[5][3] = {
            {1,15,1},
            {16,30,2},
            {31,45,3},
            {46,60,4},
            {61,100,5},
            };
        for (int b = 0;
             b < s22ElemScrollCount();
             ++b) {
            int vals[3];
            vals[0] = s22ElemScrollLo(b);
            vals[1] = s22ElemScrollHi(b);
            vals[2] = s22ElemScrollKind(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CEs[b][c])
                    ++bad;
            }
        }
        // the protection from lycanthropes grid - the seven varieties, the
        // forty-nine hit dice and the rounding rule
        int CLy[7][3] = {
            {1,5,1},
            {6,10,2},
            {11,20,3},
            {21,25,4},
            {26,40,5},
            {41,98,6},
            {99,100,7},
            };
        for (int b = 0;
             b < s22LycanScrollCount();
             ++b) {
            int vals[3];
            vals[0] = s22LycanScrollLo(b);
            vals[1] = s22LycanScrollHi(b);
            vals[2] = s22LycanScrollKind(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CLy[b][c])
                    ++bad;
            }
        }
        // the IV.B psychic crush grid - the instant-kill percentages of the
        // defenseless-psionic attack, six strength bands by seven defender
        // bands
        int CPc[6][8] = {
            {1,72,60,50,40,30,20,10},
            {26,75,62,52,42,32,22,12},
            {51,79,65,55,45,35,25,15},
            {76,84,69,59,49,39,29,19},
            {101,90,74,64,54,44,34,24},
            {126,97,80,70,60,50,40,30},
            };
        for (int b = 0;
             b < s22PsiCrushCount();
             ++b) {
            int vals[8];
            vals[0] = s22PsiCrushBand(b);
            vals[1] = s22PsiCrushC1(b);
            vals[2] = s22PsiCrushC2(b);
            vals[3] = s22PsiCrushC3(b);
            vals[4] = s22PsiCrushC4(b);
            vals[5] = s22PsiCrushC5(b);
            vals[6] = s22PsiCrushC6(b);
            vals[7] = s22PsiCrushC7(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CPc[b][c])
                    ++bad;
            }
        }
        // the IV.C psionic blast upon the non-psionic grid - the eleven
        // int-wis bands by the three ranges, the failure results riding the
        // consts
        int CNp[11][4] = {
            {0,20,19,18},
            {6,18,17,16},
            {10,16,15,14},
            {14,14,13,12},
            {18,12,11,10},
            {22,10,9,8},
            {26,8,7,6},
            {30,6,5,4},
            {34,4,3,2},
            {36,2,1,0},
            {38,0,-1,-2},
            };
        for (int b = 0;
             b < s22PsiBlastCount();
             ++b) {
            int vals[4];
            vals[0] = s22PsiBlastIntLo(b);
            vals[1] = s22PsiBlastShort(b);
            vals[2] = s22PsiBlastMedium(b);
            vals[3] = s22PsiBlastLong(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CNp[b][c])
                    ++bad;
            }
        }
        // the IV.D psionic attack range grid - the five modes, the crush
        // dashes pinned zero with the conversion noted
        int CRg[5][3] = {
            {2,4,6},
            {3,6,9},
            {4,8,12},
            {6,12,18},
            {5,0,0},
            };
        for (int b = 0;
             b < s22PsiRangeCount();
             ++b) {
            int vals[3];
            vals[0] = s22PsiRangeShort(b);
            vals[1] = s22PsiRangeMedium(b);
            vals[2] = s22PsiRangeLong(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CRg[b][c])
                    ++bad;
            }
        }
        // the III cleric-undead matrix - thirteen types by ten cleric bands,
        // the T D and dash symbols pinned ninety-seven ninety-eight
        // ninety-nine and zero with the conversion noted, the Ghast row
        // printing Ghost
        int CCu[13][10] = {
            {10,7,4,97,97,98,98,99,99,99},
            {13,10,7,97,97,98,98,98,99,99},
            {16,13,10,4,97,97,98,98,98,99},
            {19,16,13,7,4,97,97,98,98,99},
            {20,19,16,10,7,4,97,97,98,98},
            {0,20,19,13,10,7,4,97,97,98},
            {0,0,20,16,13,10,7,4,97,98},
            {0,0,0,20,16,13,10,7,4,97},
            {0,0,0,0,20,16,13,10,7,97},
            {0,0,0,0,0,20,16,13,10,4},
            {0,0,0,0,0,0,20,16,13,7},
            {0,0,0,0,0,0,0,19,16,10},
            {0,0,0,0,0,0,0,20,19,13},
            };
        for (int b = 0;
             b < s22UndeadCount();
             ++b) {
            int vals[10];
            vals[0] = s22TurnLev1(b);
            vals[1] = s22TurnLev2(b);
            vals[2] = s22TurnLev3(b);
            vals[3] = s22TurnLev4(b);
            vals[4] = s22TurnLev5(b);
            vals[5] = s22TurnLev6(b);
            vals[6] = s22TurnLev7(b);
            vals[7] = s22TurnLev8(b);
            vals[8] = s22TurnLev9(b);
            vals[9] = s22TurnLev14(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CCu[b][c])
                    ++bad;
            }
        }
        // the saving throw matrix I for characters and human types - the four
        // class blocks by the five attack forms, the druid paladin ranger
        // illusionist assassin and monk inclusions riding the footnotes
        int CSv[28][7] = {
            {1,1,10,13,14,16,15},
            {1,4,9,12,13,15,14},
            {1,7,7,10,11,13,12},
            {1,10,6,9,10,12,11},
            {1,13,5,8,9,11,10},
            {1,16,4,7,8,10,9},
            {1,19,2,5,6,8,7},
            {2,0,16,17,18,20,19},
            {2,1,14,15,16,17,17},
            {2,3,13,14,15,16,16},
            {2,5,11,12,13,13,14},
            {2,7,10,11,12,12,13},
            {2,9,8,9,10,9,11},
            {2,11,7,8,9,8,10},
            {2,13,5,6,7,5,8},
            {2,15,4,5,6,4,7},
            {2,17,3,4,5,4,6},
            {3,1,14,13,11,15,12},
            {3,6,13,11,9,13,10},
            {3,11,11,9,7,11,8},
            {3,16,10,7,5,9,6},
            {3,21,8,5,3,7,4},
            {4,1,13,12,14,16,15},
            {4,5,12,11,12,15,13},
            {4,9,11,10,10,14,11},
            {4,13,10,9,8,13,9},
            {4,17,9,8,6,12,7},
            {4,21,8,7,4,11,5},
            };
        for (int b = 0;
             b < s22SaveCharCount();
             ++b) {
            int vals[7];
            vals[0] = s22SaveClass(b);
            vals[1] = s22SaveLevel(b);
            vals[2] = s22SavePoison(b);
            vals[3] = s22SavePetrify(b);
            vals[4] = s22SaveRod(b);
            vals[5] = s22SaveBreath(b);
            vals[6] = s22SaveSpell(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CSv[b][c])
                    ++bad;
            }
        }
        // the saving throw matrix III for magical and non-magical items - the
        // fourteen items by the eleven attack forms, the liquid mirror and
        // jewelry footnotes riding the consts
        int CIs[14][11] = {
            {11,16,10,20,6,17,9,3,2,8,1},
            {4,18,12,19,11,5,3,2,4,2,1},
            {12,6,3,20,2,20,16,13,1,18,1},
            {6,19,14,20,13,10,6,3,7,15,5},
            {5,20,15,20,14,11,7,4,6,17,1},
            {10,4,2,20,1,13,6,4,3,13,1},
            {15,0,0,20,0,15,14,13,12,18,15},
            {7,6,2,17,2,6,2,1,1,11,1},
            {13,14,9,19,4,18,13,5,1,16,1},
            {12,20,15,20,13,14,9,5,6,18,1},
            {16,11,6,20,0,25,21,18,2,20,1},
            {3,17,7,18,4,7,3,2,1,14,2},
            {9,13,6,20,2,15,11,9,1,10,1},
            {8,10,3,19,1,11,7,5,1,12,1},
            };
        for (int b = 0;
             b < s22ItemRowCount();
             ++b) {
            int vals[11];
            vals[0] = s22ItemAcid(b);
            vals[1] = s22ItemCrush(b);
            vals[2] = s22ItemBlow(b);
            vals[3] = s22ItemDisint(b);
            vals[4] = s22ItemFall(b);
            vals[5] = s22ItemFireball(b);
            vals[6] = s22ItemFireMag(b);
            vals[7] = s22ItemFireNorm(b);
            vals[8] = s22ItemFrost(b);
            vals[9] = s22ItemBolt(b);
            vals[10] = s22ItemElec(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CIs[b][c])
                    ++bad;
            }
        }
        // the preview frame - the GenCon XII release and the six modules
        // whose items ride the AD&D DMG sneak preview (print 33-38, 41-43)
    if (s22GenConYear() != 1979
            || s22GenConNumber() != 12
            || s22PreviewModules() != 6
        )
            ++bad;
        // the amulet frame - the twenty-four results, the add-twelve rule and
        // the three alternates the AD&D DMG sneak preview (print 33-38,
        // 41-43)
    if (s22AmuletResults() != 24
            || s22AmuletAdd12From() != 4
            || s22AmuletCount() != 17
            || s22AmuletAltEthereal() != 22
            || s22AmuletAltAstral() != 23
            || s22AmuletAltPrime() != 24
        )
            ++bad;
        // the hammer of thunderbolts - the strength and height gates, the
        // pluses, the stun and the throw economy the AD&D DMG sneak preview
        // (print 33-38, 41-43)
    if (s22HammerStrengthMin() != 1801
            || s22HammerHeightFeet() != 6
            || s22HammerBasePlus() != 3
            || s22HammerTrueNamePlus() != 5
            || s22HammerStunRadiusInches() != 3
            || s22HammerStunRounds() != 1
            || s22HammerThrowsPerTwoTurns() != 5
            || s22HammerRestTurns() != 1
            || s22HammerThorFactor() != 2
        )
            ++bad;
        // the helm the pigments and the pearl - the vision factor, the
        // thousand cubic feet, the pots and the cursed share the AD&D DMG
        // sneak preview (print 33-38, 41-43)
    if (s22HelmVisionFactor() != 5
            || s22PigmentCubicFeet() != 1000
            || s22PigmentSurfaceFeet() != 100
            || s22PigmentPotsMin() != 1
            || s22PigmentPotsMax() != 4
            || s22PigmentDepictTurns() != 1
            || s22PearlMonths() != 1
            || s22PearlDays() != 30
            || s22PearlCursedPct() != 5
        )
            ++bad;
        // the philters and the potion - the charm turns, the reaction bonus
        // and the dose economy the AD&D DMG sneak preview (print 33-38,
        // 41-43)
    if (s22PhilterLoveBaseTurns() != 4
            || s22PhilterLoveExtraMin() != 1
            || s22PhilterLoveExtraMax() != 4
            || s22PhilterPersuasionPct() != 25
            || s22PhilterSuggestRangeInches() != 3
            || s22PotionTwoDosePct() != 75
            || s22PotionDosesMin() != 2
            || s22PotionDosesMax() != 4
            || s22PotionHoursPerDose() != 1
            || s22PotionExtraRoundsMin() != 1
            || s22PotionExtraRoundsMax() != 10
        )
            ++bad;
        // the ring of elemental command - the four types, the protection and
        // charm numbers, the combat pluses and the power counts the AD&D DMG
        // sneak preview (print 33-38, 41-43)
    if (s22RingTypes() != 4
            || s22RingKeepFeet() != 5
            || s22RingCharmSaveMinus() != 2
            || s22RingFoeHitMinus() != 1
            || s22RingSavePlus() != 2
            || s22RingHitPlus() != 4
            || s22RingDamagePlus() != 6
            || s22RingOperateLevel() != 10
            || s22RingPowerSegments() != 5
            || s22RingElementalSaveMinus() != 2
            || s22RingAirPowers() != 5
            || s22RingEarthPowers() != 6
            || s22RingFirePowers() != 5
            || s22RingWaterPowers() != 8
        )
            ++bad;
        // the anti-magic and petrifaction scrolls - the reading times, the
        // globe and the drain save the AD&D DMG sneak preview (print 33-38,
        // 41-43)
    if (s22ScrollMagicSegments() != 8
            || s22ScrollMagicRadiusFeet() != 5
            || s22ScrollMagicDrainPct() != 50
            || s22ScrollMagicSaveFloor() != 11
            || s22ScrollMagicRoundsMin() != 5
            || s22ScrollMagicRoundsMax() != 30
            || s22ScrollPetrifactionSegments() != 5
            || s22ScrollPetrifactionRoundsMin() != 5
            || s22ScrollPetrifactionRoundsMax() != 20
        )
            ++bad;
        // the possession and undead scrolls - the ninety-ten duration split,
        // the five-foot circle and the thirty-five hit dice the AD&D DMG
        // sneak preview (print 33-38, 41-43)
    if (s22ScrollPossessionRounds() != 1
            || s22ScrollPossessionRoundsMin() != 10
            || s22ScrollPossessionRoundsMax() != 60
            || s22ScrollPossessionTurnsMin() != 10
            || s22ScrollPossessionTurnsMax() != 60
            || s22ScrollPossessionStationaryPct() != 10
            || s22ScrollUndeadSegments() != 4
            || s22ScrollUndeadRadiusFeet() != 5
            || s22ScrollUndeadRoundsMin() != 10
            || s22ScrollUndeadRoundsMax() != 80
            || s22ScrollUndeadHdCap() != 35
        )
            ++bad;
        // the demon and devil scrolls - the three reading tiers each, the
        // one-segment pause that destroys the AD&D DMG sneak preview (print
        // 33-38, 41-43)
    if (s22ScrollDemonLordRounds() != 1
            || s22ScrollDemonMidSegments() != 7
            || s22ScrollDemonLesserSegments() != 3
            || s22ScrollDemonPauseSegments() != 1
            || s22ScrollDemonRoundsMin() != 5
            || s22ScrollDemonRoundsMax() != 20
            || s22ScrollDevilArchRounds() != 1
            || s22ScrollDevilGreaterSegments() != 7
            || s22ScrollDevilLesserSegments() != 3
        )
            ++bad;
        // the elemental and lycanthrope scrolls - the hit-dice caps and the
        // rounding threshold, the eight scroll kinds the AD&D DMG sneak
        // preview (print 33-38, 41-43)
    if (s22ScrollElementalSegments() != 6
            || s22ScrollElementalRoundsMin() != 5
            || s22ScrollElementalRoundsMax() != 40
            || s22ScrollElementalSpecificHd() != 24
            || s22ScrollElementalAllHd() != 16
            || s22ScrollLycanSegments() != 4
            || s22ScrollLycanRoundsMin() != 5
            || s22ScrollLycanRoundsMax() != 30
            || s22ScrollLycanHdCap() != 49
            || s22ScrollLycanPlusThreshold() != 2
            || s22ScrollKinds() != 8
        )
            ++bad;
        // the turning procedure - the one-to-twelve count, the starred
        // seven-to-twelve, the flee rounds and the special rule of thumb the
        // AD&D DMG sneak preview (print 33-38, 41-43)
    if (s22TurnAffectedMin() != 1
            || s22TurnAffectedMax() != 12
            || s22TurnStarMin() != 7
            || s22TurnFleeRoundsMin() != 3
            || s22TurnFleeRoundsMax() != 12
            || s22TurnSpecialMin() != 1
            || s22TurnSpecialMax() != 2
            || s22TurnSpecialAc() != -5
            || s22TurnSpecialHd() != 11
            || s22TurnSpecialMrPct() != 66
            || s22UndeadFootnotes() != 6
        )
            ++bad;
        // the psionic costs - the five attack modes and the five defense
        // modes, the points of each the AD&D DMG sneak preview (print 33-38,
        // 41-43)
    if (s22BlastCost() != 20
            || s22MindThrustCost() != 4
            || s22EgoWhipCost() != 7
            || s22IdInsinuationCost() != 10
            || s22PsychicCrushCost() != 14
            || s22MindBlankCost() != 1
            || s22ThoughtShieldCost() != 2
            || s22MentalBarrierCost() != 3
            || s22IntellectFortressCost() != 8
            || s22TowerIronWillCost() != 10
        )
            ++bad;
        // the psionic letter durations - confused dazed comatose robot and
        // wounded, the mind bar rule and the feeble cap the AD&D DMG sneak
        // preview (print 33-38, 41-43)
    if (s22PsiConfusedRoundsMin() != 2
            || s22PsiConfusedRoundsMax() != 8
            || s22PsiDazedTurnsMin() != 1
            || s22PsiDazedTurnsMax() != 4
            || s22PsiComaWeeksMin() != 1
            || s22PsiComaWeeksMax() != 4
            || s22PsiRobotWeeksMin() != 2
            || s22PsiRobotWeeksMax() != 8
            || s22PsiWoundedWeeksMin() != 2
            || s22PsiWoundedWeeksMax() != 8
            || s22PsiCatatonicPct() != 99
            || s22PsiMindBarPoints() != 40
            || s22PsiFeebleCap() != 5
        )
            ++bad;
        // the IV.D adjustments - the series range bonus and the medium and
        // long damage cuts the AD&D DMG sneak preview (print 33-38, 41-43)
    if (s22PsiSeriesBonusPct() != 50
            || s22PsiMediumDamageCutPct() != 20
            || s22PsiLongCategoryCut() != 25
            || s22PsiLongDamageCutPct() != 20
            || s22PsiLongLowBandCutPct() != 50
        )
            ++bad;
        // the saving throw frame - the three matrices, the natural one, the
        // class bands and the monster rules the AD&D DMG sneak preview (print
        // 33-38, 41-43)
    if (s22SaveMatrices() != 3
            || s22SaveAutoFail() != 1
            || s22SaveClericBands() != 7
            || s22SaveFighterBands() != 10
            || s22SaveMuBands() != 5
            || s22SaveThiefBands() != 6
            || s22MonsterPlusCap() != 3
            || s22NonIntDivisor() != 2
        )
            ++bad;
        // the item saves - the magic bonuses, the own-mode five, the fall
        // ladder and the cold-strike ten the AD&D DMG sneak preview (print
        // 33-38, 41-43)
    if (s22ItemMagicBonus() != 2
            || s22ItemPlusBonus() != 1
            || s22ItemOwnModeBonus() != 5
            || s22ItemFallBaseFeet() != 5
            || s22ItemFallSoftBonus() != 1
            || s22ItemFallFleshyBonus() != 5
            || s22ItemFallPenaltyFeet() != 5
            || s22ItemColdSavePenalty() != 10
            || s22ItemPaperRounds() != 1
            || s22ItemClothRounds() != 2
            || s22ItemBoneRounds() != 3
        )
            ++bad;
        // the grenade frame - the three-inch range, the bands and penalties,
        // the splash and the boulders the AD&D DMG sneak preview (print
        // 33-38, 41-43)
    if (s22GrenadeRangeInches() != 3
            || s22GrenadeMediumFrom() != 1
            || s22GrenadeLongFrom() != 2
            || s22GrenadeMediumMinus() != 2
            || s22GrenadeLongMinus() != 5
            || s22GrenadeSplashFeet() != 3
            || s22GiantBoulderFeet() != 1
            || s22SiegeBoulderFeet() != 2
        )
            ++bad;
        // the grenade contents - the four containers, the acid holy water and
        // oil damage ladders, the miss dice and the lantern the AD&D DMG
        // sneak preview (print 33-38, 41-43)
    if (s22AcidOunces() != 8
            || s22HolyOunces() != 4
            || s22OilOunces() != 16
            || s22PoisonOunces() != 4
            || s22AcidSplashHp() != 1
            || s22AcidDirectMin() != 2
            || s22AcidDirectMax() != 8
            || s22HolySplashHp() != 2
            || s22HolyDirectMin() != 2
            || s22HolyDirectMax() != 7
            || s22OilDiameterFeet() != 3
            || s22OilBurnSegmentsMin() != 1
            || s22OilBurnSegmentsMax() != 3
            || s22OilDirectFirstMin() != 2
            || s22OilDirectFirstMax() != 12
            || s22OilDirectSecondMin() != 1
            || s22OilDirectSecondMax() != 6
            || s22OilWalkDamageMin() != 1
            || s22OilWalkDamageMax() != 4
            || s22GrenadeMissDistanceDie() != 6
            || s22GrenadeMissDirectionDie() != 8
            || s22LanternAreaFeet() != 2
        )
            ++bad;
        // the combat envelope - the matrix shapes, the missile penalties, the
        // backstab multipliers and the two print catches the AD&D DMG sneak
        // preview (print 33-38, 41-43)
    if (s22ThievesCount() != 21
            || s22MissileLongMinus() != 5
            || s22MissileMediumMinus() != 2
            || s22AcFloor() != 10
            || s22AcProjectionRepeats() != 6
            || s22MonsterMatrixCols() != 12
            || s22BackstabMin() != 2
            || s22BackstabMax() != 5
            || s22AssassinationRows() != 15
            || s22FighterAc3Prints() != 11
            || s22MuHeaderBands() != 5
            || s22MuDataCols() != 4
        )
            ++bad;
        // the amulet spot check - the Seven Heavens band, the Hades and the
        // Prime ceiling the AD&D DMG sneak preview (print 33-38, 41-43)
    if (s22AmuletLo(0) != 1
            || s22AmuletHi(0) != 2
            || s22AmuletPlane(0) != 1
            || s22AmuletLo(9) != 13
            || s22AmuletHi(16) != 24
            || s22AmuletPlane(16) != 17
        )
            ++bad;
        // the periapt spot check - the plus-one floor band and the plus-four
        // ceiling the AD&D DMG sneak preview (print 33-38, 41-43)
    if (s22PeriaptLo(0) != 1
            || s22PeriaptHi(0) != 8
            || s22PeriaptPlus(0) != 1
            || s22PeriaptPlus(3) != 4
            || s22PeriaptHi(3) != 20
        )
            ++bad;
        // the hit-only spot check - the first grade and the ten-plus-four
        // ceiling the AD&D DMG sneak preview (print 33-38, 41-43)
    if (s22HitOnlyPlus(0) != 1
            || s22HitOnlyHdBase(3) != 10
            || s22HitOnlyHdPlus(2) != 3
            || s22HitOnlyPlus(3) != 4
        )
            ++bad;
        // the thieves matrix spot check - the minus-ten row, the twenty-one
        // band floor and the armor class ten row the AD&D DMG sneak preview
        // (print 33-38, 41-43)
    if (s22ThievesAc(0) != -10
            || s22ThievesL1(0) != 26
            || s22ThievesL6(20) != 0
            || s22ThievesL1(20) != 11
            || s22ThievesL3(10) != 16
        )
            ++bad;
        // the elemental scroll spot check - the air band and the
        // sixty-one-to-one-hundred all band the AD&D DMG sneak preview (print
        // 33-38, 41-43)
    if (s22ElemScrollLo(0) != 1
            || s22ElemScrollHi(0) != 15
            || s22ElemScrollKind(4) != 5
            || s22ElemScrollLo(4) != 61
            || s22ElemScrollHi(4) != 100
        )
            ++bad;
        // the lycanthrope scroll spot check - the werebear band and the
        // shape-changer ceiling the AD&D DMG sneak preview (print 33-38,
        // 41-43)
    if (s22LycanScrollLo(0) != 1
            || s22LycanScrollHi(0) != 5
            || s22LycanScrollKind(5) != 6
            || s22LycanScrollHi(5) != 98
            || s22LycanScrollKind(6) != 7
        )
            ++bad;
        // the psychic crush spot check - the lowest band and the
        // one-hundred-twenty-six-and-up row the AD&D DMG sneak preview (print
        // 33-38, 41-43)
    if (s22PsiCrushBand(0) != 1
            || s22PsiCrushC1(0) != 72
            || s22PsiCrushC7(0) != 10
            || s22PsiCrushBand(5) != 126
            || s22PsiCrushC1(5) != 97
            || s22PsiCrushC7(5) != 30
        )
            ++bad;
        // the psionic blast spot check - the zero-to-five band and the
        // thirty-eight-and-up row the AD&D DMG sneak preview (print 33-38,
        // 41-43)
    if (s22PsiBlastIntLo(0) != 0
            || s22PsiBlastShort(0) != 20
            || s22PsiBlastLong(10) != -2
            || s22PsiBlastIntLo(10) != 38
            || s22PsiBlastMedium(8) != 3
        )
            ++bad;
        // the psionic range spot check - the blast cone and the crush with
        // its dashes pinned zero the AD&D DMG sneak preview (print 33-38,
        // 41-43)
    if (s22PsiRangeShort(0) != 2
            || s22PsiRangeLong(0) != 6
            || s22PsiRangeMedium(3) != 12
            || s22PsiRangeShort(4) != 5
            || s22PsiRangeMedium(4) != 0
            || s22PsiRangeLong(4) != 0
        )
            ++bad;
        // the cleric-undead spot check - the skeleton row, the ghost destroy,
        // the vampire and the special the AD&D DMG sneak preview (print
        // 33-38, 41-43)
    if (s22TurnLev1(0) != 10
            || s22TurnLev8(12) != 20
            || s22TurnLev14(5) != 98
            || s22TurnLev8(10) != 16
            || s22TurnLev9(12) != 19
            || s22TurnLev1(11) != 0
        )
            ++bad;
        // the character save spot check - the first cleric band, the
        // zero-level fighter and the thief ceiling the AD&D DMG sneak preview
        // (print 33-38, 41-43)
    if (s22SaveClass(0) != 1
            || s22SavePoison(0) != 10
            || s22SaveClass(7) != 2
            || s22SaveLevel(7) != 0
            || s22SaveBreath(7) != 20
            || s22SaveSpell(27) != 5
            || s22SaveBreath(27) != 11
        )
            ++bad;
        // the item save spot check - the bone acid, the parchment fall and
        // its twenty-five fireball, the thick wood the AD&D DMG sneak preview
        // (print 33-38, 41-43)
    if (s22ItemAcid(0) != 11
            || s22ItemFall(10) != 0
            || s22ItemFireball(10) != 25
            || s22ItemCrush(5) != 4
            || s22ItemElec(13) != 1
            || s22ItemFrost(10) != 2
        )
            ++bad;
        printf("R947 issue-22 sneak preview audit: bad %d\n", bad);
        if (bad) return 1;
    }
