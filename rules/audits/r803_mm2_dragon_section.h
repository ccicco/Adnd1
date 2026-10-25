    // ---- R803 MM2 dragon section audit ----
    // THE MM2 LETTER D PART 5 - the dracolisk, the DRAGON family of the
    // Monster Manual II arc and the rest of the letter D close (the user Go
    // call on the landed dinosaur walk). The pin-time walk from the print
    // finds THIRTEEN entries on pp. 55-61: the dracolisk at the foot of p.
    // 55, the DRAGON family head on pp. 55-56 (doctrine only, no stat block -
    // the size roll, the 8 age stages, the infravision and detection, the
    // fear aura, the saving-throw-by-hp/4 rule and the treasure-by-age ladder
    // all pinned), and the 11 remaining stat blocks - the Cloud Dragon, the
    // Faerie Dragon, the Mist Dragon, the Shadow Dragon, the Giant Dragonfly,
    // the Dragon Horse, the Dragonnel, the Drelb, the Drider, the Duergar and
    // the Dustdigger. TWELVE defs ride the R791 data_files extension in the
    // MM1 registry schema, registry 603 -> 615. THE GRIDS: the 12-row DgStats
    // stat grid (armor class, hit dice, bonus, avgHp, attacks, xp, xp/hp,
    // lair, move, magic resistance) plus the 8-row faerie color grid (magic
    // resistance, magic-user level, druid level by color) and the 8-row
    // faerie age grid (level, hit point floor, hit point ceiling). THE
    // D-FLIP: the Letter D gap box flips to closed - the letter D walk is
    // complete, 9 closed 28 open. THE SETTLED READS (capture primary, the
    // 1eonline transcription and the archive.org djvu the cross-check
    // voices): the giant dragonfly hit dice "7 (8+1-8)" is the print line
    // pinned verbatim (the capture and djvu agree; the grid reads the 7); the
    // cloud xp rider "6100 + 10/hp + 100/hp over 48" and the mist rider "3450
    // + 5/hp + 50/hp over 36" stay pinned as riders (the defs carry the base
    // and per-hp cells); the faerie "See below" hit dice read as the 4 hit
    // dice the prose prints (the faerie attacks as 4 hit dice monsters); the
    // faerie "See below" magic resistance reads 0 in the grid (the color grid
    // carries the per-color percents); the dragonfly "Save as 16th-level
    // magic-user" reads 0 (the R155 save-as read); the cloud and mist or-form
    // armor classes and magic resistances read the gaseous best (AC -3 and
    // -2, MR 50 and 30); the cloud, mist and shadow ranged hit dice read the
    // low end (the kuei precedent); the duergar "Variable/variable" xp rides
    // the by_level carry (the dervish and dwarf precedent, no fixed xp
    // fields); the duergar treasure "Individuals M, Q; Lair B (magic only),
    // F" (the capture "M.O" the OCR misread); the dragonnel size L (24'+
    // long) (the capture inches the misread); the duergar "have been know to
    // dwell" and the dragon ancient "(40+ years)" print typos pinned
    // verbatim; the duergar armor-list leading "+" marks are the capture
    // column artifact. LOADER SEMANTICS: the duergar "1 (or more)" attacks
    // read the max 1; every Nil lair reads 0. ONE REGTEST PATCH: the R803
    // live def walk at the R227 anchor (the R782 site-block pattern, no
    // census marker), its registry census a FLOOR 603 -> at least 615.
    {
        using namespace rules;
        int bad = 0;
    if (mm2dgRound() != 803
            || mm2dgRegistryBefore() != 603
            || mm2dgRegistryAfter() != 615
            || mm2dgDefCount() != 12
            || mm2dgEntryCount() != 13
            || mm2dgDgStatRows() != 12
            || mm2dgFaerieColorRows() != 8
            || mm2dgFaerieAgeRows() != 8
            || mm2dgGapClosed() != 9
            || mm2dgGapOpen() != 28
            || mm2dgDragonSizeDie() != 8
            || mm2dgDragonSizeSmallMin() != 1
            || mm2dgDragonSizeSmallMax() != 2
            || mm2dgDragonSizeAvgMin() != 3
            || mm2dgDragonSizeAvgMax() != 7
            || mm2dgDragonSizeHuge() != 8
            || mm2dgDragonAgeStages() != 8
            || mm2dgDragonHatchlingHpPerDie() != 1
            || mm2dgDragonAncientHpPerDie() != 8
            || mm2dgDragonInfravisionFeet() != 60
            || mm2dgDragonDetectInchesPerAgeLevel() != 1
            || mm2dgDragonFearAuraFromAge() != 5
            || mm2dgDragonFearRoutTurnsMin() != 4
            || mm2dgDragonFearRoutTurnsMax() != 24
            || mm2dgDragonFearSplitPct() != 50
            || mm2dgDragonFearToHitPenalty() != -1
            || mm2dgDragonFearImmuneHitDice() != 6
            || mm2dgDragonAuraAdultSaveBonus() != 5
            || mm2dgDragonAuraOldSaveBonus() != 3
            || mm2dgDragonAuraVeryOldSaveBonus() != 1
            || mm2dgDragonSaveHpPerDieThreshold() != 5
            || mm2dgDragonSaveDivisor() != 4
            || mm2dgDragonVeryYoungTreasureChancePct() != 10
            || mm2dgDragonVeryYoungTreasurePct() != 25
            || mm2dgDragonYoungTreasureChancePct() != 25
            || mm2dgDragonSubadultTreasureChancePct() != 50
            || mm2dgDragonSubadultTreasurePct() != 50
            || mm2dgDragonVeryOldTreasureChancePct() != 50
            || mm2dgDragonVeryOldTreasurePct() != 150
            || mm2dgDragonAncientTreasureChancePct() != 75
            || mm2dgDragonAncientTreasurePct() != 200
            || mm2dgDracoliskXpValue() != 2524
            || mm2dgDracoliskXpLevel() != 7
            || mm2dgDracoliskAcidRangeInches() != 3
            || mm2dgDracoliskAcidDamageMin() != 4
            || mm2dgDracoliskAcidDamageMax() != 24
            || mm2dgDracoliskAcidPerDay() != 3
            || mm2dgDracoliskGazePetrifyFeet() != 20
            || mm2dgDracoliskGazeImperviousPct() != 90
            || mm2dgDracoliskGazeAvoidMeleePenalty() != -4
            || mm2dgDracoliskGazeCompletelySurprised() != 9
            || mm2dgDracoliskGazeSurprised() != 7
            || mm2dgDracoliskGazeViewing() != 5
            || mm2dgDracoliskGazeAttacking() != 3
            || mm2dgDracoliskGazeAvoiding() != 1
            || mm2dgDracoliskGazeManSizedBonus() != 1
            || mm2dgDracoliskGazeSmallBonus() != 2
            || mm2dgCloudXpValue() != 6520
            || mm2dgCloudXpLevel() != 10
            || mm2dgCloudLonerPct() != 95
            || mm2dgCloudCloudIslandPct() != 75
            || mm2dgCloudGaseousArmorClass() != -3
            || mm2dgCloudSolidArmorClass() != 0
            || mm2dgCloudAirblastPerDay() != 3
            || mm2dgCloudAirblastWidthInches() != 3
            || mm2dgCloudAirblastDepthInches() != 3
            || mm2dgCloudAirblastLengthMinInches() != 12
            || mm2dgCloudAirblastLengthMaxInches() != 14
            || mm2dgCloudAirblastWeightPoundsPerHp() != 10
            || mm2dgCloudAirblastDamagePerHp() != 1
            || mm2dgCloudTumbleFeetPerDieMin() != 1
            || mm2dgCloudTumbleFeetPerDieMax() != 6
            || mm2dgCloudXpBonusHpThreshold() != 48
            || mm2dgCloudXpBonusPerHpOver() != 100
            || mm2dgCloudSpellsPerDayEach() != 2
            || mm2dgCloudTopSpellAge() != 8
            || mm2dgFaerieXpValue() != 336
            || mm2dgFaerieXpLevel() != 5
            || mm2dgFaerieInvisibleArmorClass() != 1
            || mm2dgFaerieHitDiceNum() != 4
            || mm2dgFaerieBiteDamageMax() != 2
            || mm2dgFaerieEuphoriaRoundsMin() != 3
            || mm2dgFaerieEuphoriaRoundsMax() != 12
            || mm2dgFaerieEuphoriaAcPenaltyPct() != 10
            || mm2dgFaerieSpeakingPct() != 90
            || mm2dgFaerieMagicUsePct() != 100
            || mm2dgFaerieSleepingPct() != 40
            || mm2dgFaerieMagicUserPct() != 65
            || mm2dgFaerieDruidPct() != 35
            || mm2dgFaerieTelepathyMiles() != 2
            || mm2dgMistXpValue() != 3605
            || mm2dgMistXpLevel() != 8
            || mm2dgMistSleepingPct() != 20
            || mm2dgMistMatedPairPct() != 10
            || mm2dgMistMistFormArmorClass() != -2
            || mm2dgMistMistFormMrPct() != 30
            || mm2dgMistSolidArmorClass() != 1
            || mm2dgMistBreathPerDay() != 3
            || mm2dgMistCloudWidthInches() != 3
            || mm2dgMistCloudLengthInches() != 9
            || mm2dgMistCloudDepthInches() != 3
            || mm2dgMistBlindRoundsMin() != 1
            || mm2dgMistBlindRoundsMax() != 4
            || mm2dgMistDrownDamageMin() != 3
            || mm2dgMistDrownDamageMax() != 12
            || mm2dgMistDrownSaveDamageMax() != 4
            || mm2dgMistPersistsRoundsMin() != 5
            || mm2dgMistPersistsRoundsMax() != 8
            || mm2dgMistXpBonusHpThreshold() != 36
            || mm2dgMistXpBonusPerHpOver() != 50
            || mm2dgMistSpellsPerDayEach() != 2
            || mm2dgMistTopSpellAge() != 8
            || mm2dgShadowXpValue() != 320
            || mm2dgShadowXpLevel() != 4
            || mm2dgShadowEggsMin() != 5
            || mm2dgShadowEggsMax() != 8
            || mm2dgShadowSmallPct() != 25
            || mm2dgShadowAveragePct() != 50
            || mm2dgShadowLargePct() != 25
            || mm2dgShadowHpPerDieBonus() != 1
            || mm2dgShadowHatchlingPipsPerDie() != 2
            || mm2dgShadowAncientPipsPerDie() != 9
            || mm2dgShadowInfravisionFeet() != 180
            || mm2dgShadowIllusionistMinIntelligence() != 17
            || mm2dgShadowIllusionistMaxIntelligence() != 18
            || mm2dgShadowIllusionistTopSpellLevel() != 4
            || mm2dgShadowIllusionistSpellsPerLevel() != 2
            || mm2dgShadowIllusionistFromAge() != 5
            || mm2dgShadowBreathLengthFeet() != 40
            || mm2dgShadowBreathWidthFeet() != 30
            || mm2dgShadowBreathHeightFeet() != 20
            || mm2dgShadowVitalityLeftPct() != 25
            || mm2dgShadowVitalitySavePct() != 50
            || mm2dgShadowHideAsThiefLevel() != 10
            || mm2dgShadowHoardGemsMin() != 10
            || mm2dgShadowHoardGemsMax() != 80
            || mm2dgDragonflyXpValue() != 717
            || mm2dgDragonflyXpLevel() != 6
            || mm2dgDragonflyInitiativeBonus() != 2
            || mm2dgDragonflyMissilePenaltyWithInitiative() != -4
            || mm2dgDragonflyMissilePenaltyWithoutInitiative() != -2
            || mm2dgDragonflySkinGpPerSquareFoot() != 600
            || mm2dgDragonflySkinSquareFeet() != 6
            || mm2dgDragonflySaveAsLevel() != 16
            || mm2dgDragonHorseXpValue() != 1555
            || mm2dgDragonHorseXpLevel() != 7
            || mm2dgDragonHorseElsewherePct() != 5
            || mm2dgDragonHorseBreathPerTurn() != 1
            || mm2dgDragonHorseConeBaseInches() != 1
            || mm2dgDragonHorseConeLengthInches() != 2
            || mm2dgDragonHorseConeDamageMin() != 4
            || mm2dgDragonHorseConeDamageMax() != 32
            || mm2dgDragonHorseRearingDamageMin() != 3
            || mm2dgDragonHorseRearingDamageMax() != 10
            || mm2dgDragonHorseSensesMultiple() != 3
            || mm2dgDragonHorseMaturationYears() != 20
            || mm2dgDragonnelXpValue() != 984
            || mm2dgDragonnelXpLevel() != 6
            || mm2dgDrelbXpValue() != 920
            || mm2dgDrelbXpLevel() != 6
            || mm2dgDrelbChillRounds() != 1
            || mm2dgDrelbIllusionTrickPct() != 90
            || mm2dgDrelbPsionicReflectFeet() != 30
            || mm2dgDriderXpValue() != 1091
            || mm2dgDriderXpLevel() != 6
            || mm2dgDriderFightAsHitDice() != 7
            || mm2dgDriderFemalePct() != 60
            || mm2dgDriderFemaleClericMinLevel() != 6
            || mm2dgDriderFemaleClericMaxLevel() != 7
            || mm2dgDriderMaleMagicUserMinLevel() != 6
            || mm2dgDriderMaleMagicUserMaxLevel() != 8
            || mm2dgDriderBiteDamageMax() != 4
            || mm2dgDriderPoisonSavePenalty() != -2
            || mm2dgDriderParalysisTurnsMin() != 1
            || mm2dgDriderParalysisTurnsMax() != 2
            || mm2dgDriderSpiderCompanionsMin() != 2
            || mm2dgDriderSpiderCompanionsMax() != 12
            || mm2dgDriderSpiderChancePct() != 10
            || mm2dgDriderTestFromLevel() != 6
            || mm2dgDuergarHitDiceNum() != 1
            || mm2dgDuergarHitDiceBonus() != 2
            || mm2dgDuergarAvgHp() != 5
            || mm2dgDuergarDoubleLevelChance() != 4
            || mm2dgDuergarLeaderAtCount() != 9
            || mm2dgDuergarLeaderMinLevel() != 3
            || mm2dgDuergarLeaderMaxLevel() != 4
            || mm2dgDuergarSurpriseOnD6() != 3
            || mm2dgDuergarSurprisedOnD10() != 1
            || mm2dgDuergarSaveBonus() != 4
            || mm2dgDuergarPsionicMinPct() != 71
            || mm2dgDuergarPsionicMaxPct() != 90
            || mm2dgDuergarPsionicDisciplines() != 4
            || mm2dgDuergarInfravisionInches() != 12
            || mm2dgDuergarYoungPct() != 10
            || mm2dgDuergarGuardianChancePct() != 25
            || mm2dgDuergarSlaveChancePct() != 75
            || mm2dgDuergarSlaveMin() != 10
            || mm2dgDuergarSlaveMax() != 40
            || mm2dgDustdiggerXpValue() != 221
            || mm2dgDustdiggerXpLevel() != 4
            || mm2dgDustdiggerFrontArmorClass() != 7
            || mm2dgDustdiggerArms() != 5
            || mm2dgDustdiggerIllusionTalentPct() != 20
            || !mm2dgDragonSizeByDieRoll()
            || !mm2dgDragonAgeHpPerDieByDieRoll()
            || !mm2dgDragonAuraPanicsUnderOneHitDie()
            || !mm2dgDragonAuraParalysisOrPanic()
            || !mm2dgDragonAuraPenalizesThreeHitDice()
            || !mm2dgDragonAuraIgnoredAtSixHitDice()
            || !mm2dgDragonToughnessRaisesSave()
            || !mm2dgDragonYoungKeepsFullHitDiceForSaves()
            || !mm2dgDracoliskCannotUseSpells()
            || !mm2dgDracoliskSpeaksLimitedBlackDragonTongue()
            || !mm2dgDracoliskSurprisedOnlyWhenSleeping()
            || !mm2dgDracoliskNeverSubdued()
            || !mm2dgDracoliskGazeReachesAstralEthereal()
            || !mm2dgCloudGaseousFormSpellAttacksOnly()
            || !mm2dgCloudSolidFormNegatesInnateMr()
            || !mm2dgCloudSpeaksDraconianDialect()
            || !mm2dgCloudSpeaksCommonHaltingly()
            || !mm2dgFaerieAttacksOnlyWhenCorneredOrLair()
            || !mm2dgFaerieHoverManeuverabilityA()
            || !mm2dgFaerieNeverAimsDamage()
            || !mm2dgFaerieInvisibleAtWill()
            || !mm2dgMistSpellsOnlyInMistForm()
            || !mm2dgMistImmuneToOwnCloud()
            || !mm2dgMistResemblesGoldDragons()
            || !mm2dgShadowNocturnal()
            || !mm2dgShadowFirstHatchlingDevoursRest()
            || !mm2dgShadowHarmedOnlyByMagicWeapons()
            || !mm2dgShadowImmuneToLifeLevelLoss()
            || !mm2dgShadowCannotBeSubduedAndSold()
            || !mm2dgShadowBreathCostsSpellsUntilRelearned()
            || !mm2dgDragonflyInitiativeImmuneToHandWeapons()
            || !mm2dgDragonflyHuntsHumans()
            || !mm2dgDragonHorseNeverSurprised()
            || !mm2dgDragonHorseDetectsAlignmentAura()
            || !mm2dgDragonHorseTravelsAstralEthereal()
            || !mm2dgDragonHorseWillingCompanionOnly()
            || !mm2dgDragonnelHasNoBreathWeapon()
            || !mm2dgDragonnelTamedAsSteedsInPomarj()
            || !mm2dgDrelbNotUndeadCannotBeTurned()
            || !mm2dgDrelbMagicWeaponsToHarm()
            || !mm2dgDrelbMagickedSilverDoubleDamage()
            || !mm2dgDrelbDrawnSunsetToSunrise()
            || !mm2dgDriderDrowFailedLolthTest()
            || !mm2dgDriderOutcastFromDrow()
            || !mm2dgDriderDrowSpellsOncePerDay()
            || !mm2dgDuergarXpByLevel()
            || !mm2dgDuergarImmuneParalysisPoison()
            || !mm2dgDuergarIllusionPhantasmDoNotAffect()
            || !mm2dgDuergarSubterraneanLair()
            || !mm2dgDustdiggerSinkholeAmbush()
            || !mm2dgDustdiggerNightTravelOnly()
            || !mm2dgDustdiggerCaughtPreyCannotAttack()
        )
            ++bad;
        // THE D-GRID: the 12-row DgStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the 12 letter-D-part-5 stat blocks, in
        // print order)
        int CDgStats[12][10] = {
            {3,7,3,27,3,2200,12,35,9,0},
            {-3,12,0,42,4,6100,10,25,6,50},
            {5,4,0,14,1,280,4,25,6,0},
            {-2,9,0,31,4,3450,5,35,6,30},
            {-2,4,1,15,3,245,5,40,18,20},
            {3,7,0,24,1,525,8,0,1,0},
            {0,8,0,28,2,1275,10,0,24,25},
            {3,8,4,32,3,600,12,10,12,0},
            {2,5,3,20,1,800,6,100,6,0},
            {3,6,6,27,1,875,8,0,12,15},
            {4,1,2,5,1,0,0,5,6,0},
            {4,4,0,14,1,165,4,0,3,0},
            };
        for (int b = 0;
             b < mm2dgDgStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2dgDgStatAC(b);
            vals[1] = mm2dgDgStatHd(b);
            vals[2] = mm2dgDgStatHdBonus(b);
            vals[3] = mm2dgDgStatAvgHp(b);
            vals[4] = mm2dgDgStatAttacks(b);
            vals[5] = mm2dgDgStatXp(b);
            vals[6] = mm2dgDgStatXpHp(b);
            vals[7] = mm2dgDgStatLairPct(b);
            vals[8] = mm2dgDgStatMove(b);
            vals[9] = mm2dgDgStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CDgStats[b][c])
                    ++bad;
            }
        }
        // THE FAERIE COLOR GRID: the 8-row age-color chart (the magic
        // resistance, magic-user level and druid level per color, red through
        // purple)
        int CFaerieColor[8][3] = {
            {12,2,3},
            {24,4,4},
            {35,6,5},
            {48,8,6},
            {60,10,8},
            {72,12,10},
            {84,14,12},
            {96,16,14},
            };
        for (int b = 0;
             b < mm2dgFaerieColorRows();
             ++b) {
            int vals[3];
            vals[0] = mm2dgFaerieColorMr(b);
            vals[1] = mm2dgFaerieColorMuLevel(b);
            vals[2] = mm2dgFaerieColorDruidLevel(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CFaerieColor[b][c])
                    ++bad;
            }
        }
        // THE FAERIE AGE GRID: the 8-row growth-stage table (the level, the
        // hit point range and the age, very young through ancient)
        int CFaerieAge[8][3] = {
            {1,1,2},
            {2,3,4},
            {3,5,6},
            {4,7,8},
            {5,9,10},
            {6,11,12},
            {7,13,14},
            {8,15,16},
            };
        for (int b = 0;
             b < mm2dgFaerieAgeRows();
             ++b) {
            int vals[3];
            vals[0] = mm2dgFaerieAgeLevel(b);
            vals[1] = mm2dgFaerieAgeHpMin(b);
            vals[2] = mm2dgFaerieAgeHpMax(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CFaerieAge[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the gap box flips
        // (the census walk)
    if (mm2dgRegistryAfter() - mm2dgRegistryBefore() != mm2dgDefCount()
            || mm2dgDefCount() != 12
            || mm2dgEntryCount() != 13
            || mm2dgDgStatRows() != 12
            || mm2dgFaerieColorRows() != 8
            || mm2dgFaerieAgeRows() != 8
            || mm2dgGapClosed() != 9
            || mm2dgGapOpen() != 28
        )
            ++bad;
        // each grid xp tile equals its pinned full kill xp (the xpValue
        // formula, pin-vs-pin; the duergar by_level def carries no xp fields)
    if (mm2dgDgStatXp(0) + mm2dgDgStatXpHp(0) * mm2dgDgStatAvgHp(0) !=
        mm2dgDracoliskXpValue()
            || mm2dgDgStatXp(1) + mm2dgDgStatXpHp(1) * mm2dgDgStatAvgHp(1) !=
            mm2dgCloudXpValue()
            || mm2dgDgStatXp(2) + mm2dgDgStatXpHp(2) * mm2dgDgStatAvgHp(2) !=
            mm2dgFaerieXpValue()
            || mm2dgDgStatXp(3) + mm2dgDgStatXpHp(3) * mm2dgDgStatAvgHp(3) !=
            mm2dgMistXpValue()
            || mm2dgDgStatXp(4) + mm2dgDgStatXpHp(4) * mm2dgDgStatAvgHp(4) !=
            mm2dgShadowXpValue()
            || mm2dgDgStatXp(5) + mm2dgDgStatXpHp(5) * mm2dgDgStatAvgHp(5) !=
            mm2dgDragonflyXpValue()
            || mm2dgDgStatXp(6) + mm2dgDgStatXpHp(6) * mm2dgDgStatAvgHp(6) !=
            mm2dgDragonHorseXpValue()
            || mm2dgDgStatXp(7) + mm2dgDgStatXpHp(7) * mm2dgDgStatAvgHp(7) !=
            mm2dgDragonnelXpValue()
            || mm2dgDgStatXp(8) + mm2dgDgStatXpHp(8) * mm2dgDgStatAvgHp(8) !=
            mm2dgDrelbXpValue()
            || mm2dgDgStatXp(9) + mm2dgDgStatXpHp(9) * mm2dgDgStatAvgHp(9) !=
            mm2dgDriderXpValue()
            || mm2dgDgStatXp(11) + mm2dgDgStatXpHp(11) * mm2dgDgStatAvgHp(11)
            != mm2dgDustdiggerXpValue()
        )
            ++bad;
        // the faerie color grid rises red to purple (the printed age-color
        // chart)
    if (mm2dgFaerieColorMr(0) != 12
            || mm2dgFaerieColorMr(7) != 96
            || mm2dgFaerieColorMr(7) - mm2dgFaerieColorMr(0) != 84
            || mm2dgFaerieColorMuLevel(0) != 2
            || mm2dgFaerieColorMuLevel(7) != 16
            || mm2dgFaerieColorDruidLevel(0) != 3
            || mm2dgFaerieColorDruidLevel(7) != 14
        )
            ++bad;
        // the faerie age grid runs level 1-8 with the 1-2 through 15-16 hit
        // point bands
    if (mm2dgFaerieAgeLevel(0) != 1
            || mm2dgFaerieAgeLevel(7) != 8
            || mm2dgFaerieAgeHpMin(0) != 1
            || mm2dgFaerieAgeHpMin(7) != 15
            || mm2dgFaerieAgeHpMax(0) != 2
            || mm2dgFaerieAgeHpMax(7) != 16
            || mm2dgFaerieAgeHpMax(0) - mm2dgFaerieAgeHpMin(0) != 1
        )
            ++bad;
        // the dragon family head size roll covers 1-2, 3-7 and 8 on the
        // 8-sided die
    if (mm2dgDragonSizeDie() != 8
            || mm2dgDragonSizeHuge() != 8
            || mm2dgDragonSizeSmallMin() + mm2dgDragonSizeSmallMax() != 3
            || mm2dgDragonSizeAvgMin() + mm2dgDragonSizeAvgMax() != 10
            || mm2dgDragonSizeSmallMax() + 1 != mm2dgDragonSizeAvgMin()
            || mm2dgDragonSizeAvgMax() + 1 != mm2dgDragonSizeHuge()
            || mm2dgDragonAgeStages() != 8
            || mm2dgDragonAncientHpPerDie() - mm2dgDragonHatchlingHpPerDie()
            != 7
        )
            ++bad;
        // the dracolisk gaze table sums to the printed 25 in 10 across its
        // five rows
    if (mm2dgDracoliskGazeCompletelySurprised() +
        mm2dgDracoliskGazeSurprised() + mm2dgDracoliskGazeViewing() +
        mm2dgDracoliskGazeAttacking() + mm2dgDracoliskGazeAvoiding() != 25
        )
            ++bad;
        // the dragon treasure ladder climbs 25/50/150/200 percent by age
    if (mm2dgDragonVeryYoungTreasurePct() != 25
            || mm2dgDragonSubadultTreasurePct() != 50
            || mm2dgDragonVeryOldTreasurePct() != 150
            || mm2dgDragonAncientTreasurePct() != 200
            || mm2dgDragonVeryOldTreasureChancePct() !=
            mm2dgDragonSubadultTreasureChancePct()
            || mm2dgDragonAncientTreasureChancePct() != 75
        )
            ++bad;
        // the print xp riders stay pinned (the cloud and mist over-threshold
        // bonuses)
    if (mm2dgCloudXpBonusHpThreshold() != 48
            || mm2dgCloudXpBonusPerHpOver() != 100
            || mm2dgMistXpBonusHpThreshold() != 36
            || mm2dgMistXpBonusPerHpOver() != 50
        )
            ++bad;
        printf("R803 MM2 dragon section audit: bad %d\n", bad);
        if (bad) return 1;
    }
