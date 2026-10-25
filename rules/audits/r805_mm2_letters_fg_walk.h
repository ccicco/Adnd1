    // ---- R805 MM2 letters FG walk audit ----
    // THE MM2 LETTERS FG WALK - the falcon and hawk table, the firefriend,
    // the giant fly table, the foo creatures, the forester bane, the formian
    // table and the froghemoth pp. 64-67, the galeb duhr, the GIANT family
    // head (doctrine only), the fomorian, the firbolg, the verbeeg, the
    // gibbering mouther, the gloomwing, the goat, the gorgimera, the
    // greenhag, the grippli, the grig, the grim, the GRUE family head
    // (doctrine only), the chaggrin, the harginn, the ildriss and the varrdig
    // pp. 68-74, promoted to the live registry; the contested cells settled:
    // the firbolg bat-away roll reads a 6 or better (the capture "8 or
    // better" the OCR misread, the 75% arithmetic the settle); the firbolg
    // chaotic good alignment (the capture "cheotic"); the froghemoth damage
    // cell "5d10 or 5-8 (=4)" stays capture verbatim (the djvu "+4" the
    // misread); the harginn parenthetical treasure reads the letter I (the
    // varrdig "1/2 x F" pattern); the verbeeg treasure reads the K,L,M
    // letters; the grig hit dice read the 2-5 print hp range midpoint (the
    // atomie precedent); the ildriss ground move reads the 3 inch rolling-fog
    // rate
    {
        using namespace rules;
        int bad = 0;
    if (mm2fgRound() != 805
            || mm2fgRegistryBefore() != 622
            || mm2fgRegistryAfter() != 650
            || mm2fgDefCount() != 28
            || mm2fgEntryCount() != 25
            || mm2fgStatBlockHeadings() != 23
            || mm2fgDoctrineHeads() != 2
            || mm2fgLetterFHeadings() != 7
            || mm2fgLetterGHeadings() != 18
            || mm2fgFgStatRows() != 28
            || mm2fgGapClosed() != 12
            || mm2fgGapOpen() != 25
            || mm2fgPriorOwnedEntries() != 3
            || mm2fgFaerieDragonOwningRound() != 803
            || mm2fgGiantDragonflyOwningRound() != 803
            || mm2fgGrayOnesOwningRound() != 803
            || mm2fgGiantHeadSubEntryCount() != 3
            || mm2fgGrueHeadSubEntryCount() != 4
            || mm2fgFalconSmallXpValue() != 17
            || mm2fgFalconSmallXpLevel() != 1
            || mm2fgFalconLargeXpValue() != 28
            || mm2fgFalconLargeXpLevel() != 1
            || mm2fgFirefriendXpValue() != 50
            || mm2fgFirefriendXpLevel() != 2
            || mm2fgFlyBluebottleXpValue() != 65
            || mm2fgFlyBluebottleXpLevel() != 2
            || mm2fgFlyHorseflyXpValue() != 276
            || mm2fgFlyHorseflyXpLevel() != 4
            || mm2fgFooDogXpValue() != 1572
            || mm2fgFooDogXpLevel() != 7
            || mm2fgFooLionXpValue() != 3634
            || mm2fgFooLionXpLevel() != 7
            || mm2fgForestersBaneXpValue() != 250
            || mm2fgForestersBaneXpLevel() != 4
            || mm2fgFormianMyrmarchXpValue() != 616
            || mm2fgFormianMyrmarchXpLevel() != 5
            || mm2fgFormianWarriorXpValue() != 202
            || mm2fgFormianWarriorXpLevel() != 3
            || mm2fgFormianWorkerXpValue() != 28
            || mm2fgFormianWorkerXpLevel() != 2
            || mm2fgFroghemothXpValue() != 9220
            || mm2fgFroghemothXpLevel() != 9
            || mm2fgGalebDuhXpValue() != 2336
            || mm2fgGalebDuhXpLevel() != 7
            || mm2fgFomorianXpValue() != 3578
            || mm2fgFomorianXpLevel() != 7
            || mm2fgFirbolgXpValue() != 4496
            || mm2fgFirbolgXpLevel() != 8
            || mm2fgVerbeegXpValue() != 407
            || mm2fgVerbeegXpLevel() != 5
            || mm2fgGibberingMoutherXpValue() != 295
            || mm2fgGibberingMoutherXpLevel() != 4
            || mm2fgGloomwingXpValue() != 633
            || mm2fgGloomwingXpLevel() != 6
            || mm2fgGoatXpValue() != 34
            || mm2fgGoatXpLevel() != 2
            || mm2fgGorgimeraXpValue() != 3047
            || mm2fgGorgimeraXpLevel() != 7
            || mm2fgGreenhagXpValue() != 1972
            || mm2fgGreenhagXpLevel() != 7
            || mm2fgGrippliXpValue() != 53
            || mm2fgGrippliXpLevel() != 2
            || mm2fgGrigXpValue() != 53
            || mm2fgGrigXpLevel() != 2
            || mm2fgGrimXpValue() != 365
            || mm2fgGrimXpLevel() != 5
            || mm2fgChaggrinXpValue() != 557
            || mm2fgChaggrinXpLevel() != 5
            || mm2fgHarginnXpValue() != 335
            || mm2fgHarginnXpLevel() != 4
            || mm2fgIldrissXpValue() != 315
            || mm2fgIldrissXpLevel() != 4
            || mm2fgVarrdigXpValue() != 866
            || mm2fgVarrdigXpLevel() != 6
            || mm2fgFalconNestShinyPct() != 5
            || mm2fgFalconDiveHeightFeet() != 100
            || mm2fgFalconDiveToHitBonus() != 2
            || mm2fgFalconBeakBlindPct() != 25
            || mm2fgFirefriendBeamInches() != 3
            || mm2fgFirefriendBeamFeet() != 14
            || mm2fgFirefriendBeamDmgMin() != 5
            || mm2fgFirefriendBeamDmgMax() != 20
            || mm2fgFirefriendLifespanYears() != 10
            || mm2fgFlyJumpInches() != 3
            || mm2fgFlyJumpHeightInches() != 1
            || mm2fgFlyJumpSegments() != 1
            || mm2fgFlyBluebottleDiseasePct() != 10
            || mm2fgFooDogAsHd() != 10
            || mm2fgFooLionAsHd() != 15
            || mm2fgFooLawfulEvilBonus() != 1
            || mm2fgFooRoarSummonPct() != 20
            || mm2fgFooRoarRounds() != 7
            || mm2fgFooNewcomerRoundsMin() != 1
            || mm2fgFooNewcomerRoundsMax() != 10
            || mm2fgFooEvilAttackPenalty() != 1
            || mm2fgFooDogHdNum() != 7
            || mm2fgFooLionHdNum() != 11
            || mm2fgForestersBaneLeafFeetMin() != 5
            || mm2fgForestersBaneLeafFeetMax() != 7
            || mm2fgForestersBaneStalksMin() != 3
            || mm2fgForestersBaneStalksMax() != 6
            || mm2fgForestersBaneEscapePctPerStr() != 5
            || mm2fgForestersBaneLeafHpMin() != 9
            || mm2fgForestersBaneLeafHpMax() != 16
            || mm2fgForestersBaneStalkHpMin() != 17
            || mm2fgForestersBaneStalkHpMax() != 24
            || mm2fgForestersBaneRegrowWeeksMin() != 2
            || mm2fgForestersBaneRegrowWeeksMax() != 8
            || mm2fgFormianUndergroundMultiple() != 3
            || mm2fgFormianWorkerEncounterPct() != 90
            || mm2fgFormianWarriorEncounterPct() != 10
            || mm2fgFormianWorkerGuardedPct() != 10
            || mm2fgFormianRaidWorkersMin() != 10
            || mm2fgFormianRaidWorkersMax() != 40
            || mm2fgFormianMyrmarchGuards() != 2
            || mm2fgFormianMyrmarchWorkers() != 8
            || mm2fgFormianGymarchHdNum() != 7
            || mm2fgFormianGymarchHdBonus() != 7
            || mm2fgFormianWorkerStrength() != 22
            || mm2fgFormianWarriorStrength() != 23
            || mm2fgFormianMyrmarchStrength() != 24
            || mm2fgFormianMyrmarchCommonPct() != 75
            || mm2fgFroghemothEggsMin() != 10
            || mm2fgFroghemothEggsMax() != 100
            || mm2fgFroghemothTadpoleEatenPct() != 90
            || mm2fgFroghemothSurvivalPctMax() != 4
            || mm2fgFroghemothTentacleSeverMin() != 19
            || mm2fgFroghemothTentacleSeverMax() != 22
            || mm2fgFroghemothTongueSeverMin() != 12
            || mm2fgFroghemothTongueSeverMax() != 16
            || mm2fgFroghemothTongueFeet() != 10
            || mm2fgFroghemothSwallowDmgMin() != 4
            || mm2fgFroghemothSwallowDmgMax() != 16
            || mm2fgFroghemothUnconsciousRounds() != 2
            || mm2fgFroghemothDigestedHp() != -10
            || mm2fgFroghemothSeveredRoundsMin() != 2
            || mm2fgFroghemothSeveredRoundsMax() != 5
            || mm2fgFroghemothTadpoleSwimInches() != 16
            || mm2fgGalebDuhrSpellLevel() != 20
            || mm2fgGalebDuhrSpellCount() != 5
            || mm2fgGalebDuhrBouldersMin() != 1
            || mm2fgGalebDuhrBouldersMax() != 2
            || mm2fgGalebDuhrBoulderRangeInches() != 6
            || mm2fgGalebDuhrBoulderAc() != 0
            || mm2fgGalebDuhrBoulderHd() != 9
            || mm2fgGalebDuhrColdSaveMod() != -4
            || mm2fgGalebDuhrFireSaveMod() != 4
            || mm2fgGalebDuhrHdMin() != 8
            || mm2fgGalebDuhrHdMax() != 10
            || mm2fgFomorianSurpriseBonusMin() != 1
            || mm2fgFomorianSurpriseBonusMax() != 3
            || mm2fgFomorianFemalePct() != 25
            || mm2fgFomorianFemalesPerMaleMin() != 1
            || mm2fgFomorianFemalesPerMaleMax() != 2
            || mm2fgFomorianYoungPerFemaleMin() != 1
            || mm2fgFomorianYoungPerFemaleMax() != 3
            || mm2fgFirbolgSmallGroupPct() != 90
            || mm2fgFirbolgBatAttemptsPerRound() != 2
            || mm2fgFirbolgBatRollMin() != 6
            || mm2fgFirbolgBatPct() != 75
            || mm2fgFirbolgPowerCount() != 5
            || mm2fgFirbolgShamanPct() != 5
            || mm2fgFirbolgShamanLevel() != 7
            || mm2fgFirbolgSeventhLevelFirstSpells() != 10
            || mm2fgFirbolgSeventhLevelSecondSpells() != 4
            || mm2fgVerbeegWithGiantsPct() != 30
            || mm2fgVerbeegHillGiantSharePct() != 40
            || mm2fgVerbeegOgreSharePct() != 60
            || mm2fgVerbeegWanderingPct() != 50
            || mm2fgVerbeegLairEncPct() != 30
            || mm2fgVerbeegLairMin() != 5
            || mm2fgVerbeegLairMax() != 30
            || mm2fgVerbeegOthersPct() != 20
            || mm2fgVerbeegSpearCount() != 3
            || mm2fgVerbeegSpearRangeBonusMin() != 3
            || mm2fgVerbeegSpearRangeBonusMax() != 6
            || mm2fgVerbeegOoThrowRangeInches() != 9
            || mm2fgVerbeegOoThrowDmgMin() != 7
            || mm2fgVerbeegOoThrowDmgMax() != 12
            || mm2fgVerbeegLeaderHpMin() != 40
            || mm2fgVerbeegShamanPctPerGiant() != 2
            || mm2fgVerbeegShamanLevel() != 7
            || mm2fgVerbeegNoMagicPct() != 90
            || mm2fgVerbeegWolvesMin() != 2
            || mm2fgVerbeegWolvesMax() != 8
            || mm2fgVerbeegWolvesPct() != 75
            || mm2fgVerbeegYoungPct() != 50
            || mm2fgMoutherMouthsPerRound() != 6
            || mm2fgMoutherDrainPerRound() != 1
            || mm2fgMoutherSlipMouthsMin() != 3
            || mm2fgMoutherSlipRollMax() != 4
            || mm2fgMoutherFallenMouths() != 12
            || mm2fgMoutherGibberRadiusInches() != 6
            || mm2fgMoutherGroundRadiusFeet() != 5
            || mm2fgMoutherEarthSegments() != 5
            || mm2fgMoutherStoneRounds() != 1
            || mm2fgGloomwingSurpriseMin() != 1
            || mm2fgGloomwingSurpriseMax() != 3
            || mm2fgGloomwingPheromoneRound() != 2
            || mm2fgGloomwingStrLossPerRound() != 1
            || mm2fgGloomwingRestoreTurnsMin() != 1
            || mm2fgGloomwingRestoreTurnsMax() != 4
            || mm2fgGloomwingAttractPct() != 20
            || mm2fgGloomwingAttractMin() != 1
            || mm2fgGloomwingAttractMax() != 4
            || mm2fgGloomwingHatchDays() != 12
            || mm2fgGloomwingWormsMin() != 4
            || mm2fgGloomwingWormsMax() != 10
            || mm2fgGloomwingMandibleValueGp() != 25
            || mm2fgGoatChargeToHitBonus() != 2
            || mm2fgGoatChargeDmgMin() != 1
            || mm2fgGoatChargeDmgMax() != 2
            || mm2fgGoatBucksMin() != 1
            || mm2fgGoatBucksMax() != 2
            || mm2fgGoatDoesMax() != 12
            || mm2fgGorgimeraLionAc() != 5
            || mm2fgGorgimeraPetrifyPerDay() != 2
            || mm2fgGorgimeraFirePerDay() != 2
            || mm2fgGorgimeraPetrifyLengthInches() != 3
            || mm2fgGorgimeraPetrifyWidthInches() != 1
            || mm2fgGorgimeraFireLengthInches() != 5
            || mm2fgGorgimeraFireWidthInches() != 2
            || mm2fgGorgimeraBreathDmgMin() != 3
            || mm2fgGorgimeraBreathDmgMax() != 24
            || mm2fgGorgimeraRangeFeet() != 10
            || mm2fgGreenhagStrBonus() != 6
            || mm2fgGreenhagPowerCount() != 8
            || mm2fgGreenhagPowerLevel() != 9
            || mm2fgGreenhagSilentHidePct() != 90
            || mm2fgGreenhagSurpriseMin() != 5
            || mm2fgGreenhagSurpriseMax() != 6
            || mm2fgGreenhagInvisibleSurpriseMin() != 19
            || mm2fgGreenhagInvisibleSurpriseMax() != 20
            || mm2fgGreenhagSurprisedMax() != 1
            || mm2fgGreenhagSurprisedDie() != 20
            || mm2fgGrippliLifespanYears() != 700
            || mm2fgGrippliUltravisionInches() != 10
            || mm2fgGrippliPsionicMinPct() != 1
            || mm2fgGrippliPsionicMaxPct() != 2
            || mm2fgGrippliLairMalesMin() != 5
            || mm2fgGrippliLairMalesMax() != 30
            || mm2fgGrippliOffspringMin() != 1
            || mm2fgGrippliOffspringMax() != 6
            || mm2fgGrippliMotherAc() != 7
            || mm2fgGrippliMotherHd() != 3
            || mm2fgGrippliMatesAc() != 8
            || mm2fgGrippliMatesHd() != 2
            || mm2fgGrigMissileToHitBonus() != 2
            || mm2fgGrigDartCount() != 6
            || mm2fgGrigPowerCount() != 6
            || mm2fgGrigPowerLevel() != 6
            || mm2fgGrigFiddlerPct() != 25
            || mm2fgGrigFiddleRadiusFeet() != 30
            || mm2fgGrigSurprisePct() != 90
            || mm2fgGrigSurprisedPct() != 10
            || mm2fgGrigInfravisionFeet() != 180
            || mm2fgGrigGlenPct() != 30
            || mm2fgGrimFormCount() != 3
            || mm2fgGrimTurnUndeadLevel() != 8
            || mm2fgGrimTurnDieBonus() != 2
            || mm2fgGrimWeaponPlusMin() != 1
            || mm2fgGrimProtectionRadiusFeet() != 10
            || mm2fgGrimDetectEvilInches() != 7
            || mm2fgGrimSurpriseMin() != 1
            || mm2fgGrimSurpriseDie() != 10
            || mm2fgChaggrinWeightMin() != 140
            || mm2fgChaggrinWeightMax() != 210
            || mm2fgChaggrinClingDmgMin() != 7
            || mm2fgChaggrinClingDmgMax() != 12
            || mm2fgChaggrinQuillDmgMin() != 1
            || mm2fgChaggrinQuillDmgMax() != 4
            || mm2fgChaggrinDispelFeet() != 40
            || mm2fgChaggrinSurpriseMin() != 1
            || mm2fgChaggrinSurpriseMax() != 5
            || mm2fgHarginnColumnFeet() != 8
            || mm2fgHarginnGoutWidthFeet() != 3
            || mm2fgHarginnGoutLengthFeet() != 6
            || mm2fgHarginnDispelFeet() != 20
            || mm2fgIldrissEyeCount() != 3
            || mm2fgIldrissSurpriseMin() != 4
            || mm2fgIldrissSurpriseMax() != 6
            || mm2fgIldrissWeaponPlusMin() != 2
            || mm2fgIldrissDispelFeet() != 50
            || mm2fgVarrdigJetRangeFeet() != 6
            || mm2fgVarrdigBlindChanceMax() != 6
            || mm2fgVarrdigBlindRoundsMin() != 1
            || mm2fgVarrdigBlindRoundsMax() != 4
            || mm2fgVarrdigDispelFeet() != 30
            || mm2fgVarrdigSnowmanTubesMin() != 3
            || mm2fgVarrdigSnowmanTubesMax() != 6
            || mm2fgVarrdigTubeRangeFeet() != 10
            || mm2fgVarrdigTubeDmgMin() != 1
            || mm2fgVarrdigTubeDmgMax() != 6
            || !mm2fgGiantHeadIsDoctrineOnlyHeading()
            || !mm2fgGrueHeadIsDoctrineOnlyHeading()
            || !mm2fgFalconTableTwoColumns()
            || !mm2fgFlyTableTwoColumns()
            || !mm2fgFooTableTwoColumns()
            || !mm2fgFormianTableThreeColumns()
            || !mm2fgFirbolgBatAwayReadsSix()
            || !mm2fgFirbolgAlignmentChaoticGood()
            || !mm2fgFroghemothDamageKeepsCaptureForm()
            || !mm2fgHarginnTreasureReadsLetterI()
            || !mm2fgVerbeegTreasureReadsKLM()
            || !mm2fgGrigHitDicePrintHpRange()
            || !mm2fgGorgimeraArmorClassComposite()
            || !mm2fgGalebDuhrHdReadsLowEnd()
            || !mm2fgIldrissMoveReadsFogForm()
        )
            ++bad;
        // THE FG-GRID: the 28-row FgStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the 28 letter-F and letter-G stat blocks,
        // in print order)
        int CFgStats[28][10] = {
            {5,1,-1,2,3,15,1,30,1,0},
            {6,1,0,3,3,25,1,30,1,0},
            {4,1,4,7,1,36,2,0,3,0},
            {6,3,0,10,1,35,3,0,9,0},
            {5,6,0,21,1,150,6,0,6,0},
            {0,7,7,31,3,1200,12,0,27,45},
            {-1,11,11,49,3,2850,16,0,21,55},
            {4,5,0,17,6,165,5,0,0,0},
            {1,6,6,27,2,400,8,100,15,0},
            {2,3,3,13,4,150,4,50,15,0},
            {3,1,1,4,1,20,2,20,18,0},
            {2,16,0,56,4,8100,20,40,2,0},
            {-2,8,0,28,2,2000,12,15,6,20},
            {3,13,1,46,1,2750,18,45,9,0},
            {2,13,2,47,1,3650,18,45,15,15},
            {4,5,5,22,2,275,6,30,18,0},
            {1,4,3,17,6,210,5,95,3,0},
            {1,5,1,18,3,525,6,0,12,0},
            {7,1,2,5,1,24,2,0,15,0},
            {5,10,0,35,5,2557,14,25,12,0},
            {-2,9,0,31,2,1600,12,40,12,35},
            {9,1,1,4,1,45,2,30,9,0},
            {2,0,1,3,3,50,1,10,6,30},
            {0,4,2,16,1,285,5,0,18,25},
            {4,5,5,22,2,425,6,0,12,0},
            {3,4,4,18,1,245,5,0,15,0},
            {2,4,0,14,1,245,5,0,3,0},
            {5,6,6,27,2,650,8,0,6,0},
            };
        for (int b = 0;
             b < mm2fgFgStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2fgFgStatAC(b);
            vals[1] = mm2fgFgStatHd(b);
            vals[2] = mm2fgFgStatHdBonus(b);
            vals[3] = mm2fgFgStatAvgHp(b);
            vals[4] = mm2fgFgStatAttacks(b);
            vals[5] = mm2fgFgStatXp(b);
            vals[6] = mm2fgFgStatXpHp(b);
            vals[7] = mm2fgFgStatLairPct(b);
            vals[8] = mm2fgFgStatMove(b);
            vals[9] = mm2fgFgStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CFgStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the two gap boxes
        // flip (the census walk)
    if (mm2fgRegistryAfter() - mm2fgRegistryBefore() != mm2fgDefCount()
            || mm2fgDefCount() != 28
            || mm2fgEntryCount() != 25
            || mm2fgFgStatRows() != 28
            || mm2fgGapClosed() != 12
            || mm2fgGapOpen() != 25
            || mm2fgPriorOwnedEntries() != 3
        )
            ++bad;
        // the pin-time entry census composition (23 stat-block headings, 2
        // doctrine-only family heads, 19 single-column defs and 9
        // multi-column defs)
    if (mm2fgEntryCount() != mm2fgStatBlockHeadings() + mm2fgDoctrineHeads()
            || mm2fgDefCount() != 19 + 9
            || mm2fgLetterFHeadings() != 7
            || mm2fgLetterGHeadings() != 18
            || mm2fgGiantHeadSubEntryCount() + mm2fgGrueHeadSubEntryCount() !=
            7
        )
            ++bad;
        // the full-kill xp formula on four bookend defs (the xpValue walk)
    if (mm2fgFalconSmallXpValue() != 15 + 1 * 2
            || mm2fgFooLionXpValue() != 2850 + 16 * 49
            || mm2fgFroghemothXpValue() != 8100 + 20 * 56
            || mm2fgVarrdigXpValue() != 650 + 8 * 27
        )
            ++bad;
        // the prior-owned letter-F and letter-G index entries (all three
        // landed with the R803 dragon walk)
    if (mm2fgFaerieDragonOwningRound() != 803
            || mm2fgGiantDragonflyOwningRound() != 803
            || mm2fgGrayOnesOwningRound() != 803
            || mm2fgRound() - mm2fgFaerieDragonOwningRound() != 2
        )
            ++bad;
        // the foo creature effective hit-dice ladder vs. evil opponents (the
        // lions 15, the dogs 10)
    if (mm2fgFooLionAsHd() - mm2fgFooDogAsHd() != 5
            || mm2fgFooDogAsHd() != mm2fgFooDogHdNum() + 3
            || mm2fgFooLionAsHd() != mm2fgFooLionHdNum() + 4
        )
            ++bad;
        // the ranged hit-dice cells read the low end (the kuei precedent) and
        // the grig reads the print hp range
    if (mm2fgGalebDuhrHdMin() != 8
            || mm2fgFomorianSurpriseBonusMin() != 1
            || mm2fgGrigXpValue() != 50 + 1 * 3
            || mm2fgFalconSmallXpValue() != 15 + 1 * 2
        )
            ++bad;
        // the grue dispel radii walk (the earth 40, the fire 20, the air 50,
        // the water 30)
    if (mm2fgChaggrinDispelFeet() != 40
            || mm2fgHarginnDispelFeet() != 20
            || mm2fgIldrissDispelFeet() != 50
            || mm2fgVarrdigDispelFeet() != 30
        )
            ++bad;
        printf("R805 MM2 letters FG walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
