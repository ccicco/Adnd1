    // ---- R813 MM2 letter S walk audit ----
    // THE MM2 LETTER S WALK - the sandling p. 106, the scorpion variant table
    // p. 107 (the large and huge columns), the scum creeper and the selkie p.
    // 107, the shade p. 108, the greater shedu head p. 109 (prior-owned - the
    // MM1 print owns it, head pins only, no def), the sirine and the skeleton
    // (animal) p. 109, the skunk, the slime creature and the olive slime p.
    // 110, the snake variant table p. 111 (the constrictor and poisonous
    // columns), the solar pp. 111-112, the solifugid variant table p. 112
    // (the large, huge and giant columns), the spectator pp. 112-113, the
    // spider (giant marine), the spriggan and the squealer pp. 113-114, the
    // squirrel variant table p. 114 (the giant black and ordinary columns),
    // the squirrel (carnivorous flying) p. 114, the stegocentipede pp.
    // 114-115, the stench kow, the stone guardian and the storoper pp.
    // 115-116, the sundew (giant), the swan and the swanmay pp. 116-117, the
    // swordfish and the taer p. 117; the S-FLIP round: the Letter S gap box
    // flips to closed (24 closed, 13 open). THIRTY-THREE .lua defs ride the
    // R791 data_files extension, registry 733 -> 766; TWENTY-NINE entry heads
    // carrying THIRTY-FOUR stat blocks, one prior-owned head (the greater
    // shedu), no doctrine-only heads. THE SETTLED READS (capture primary, the
    // 1eonline transcription the cross-check voice): the scum creeper, skunk,
    // ordinary squirrel, carnivorous flying squirrel and solar the flat-hp
    // path (hdNum 0, the ikiryo/obliviax precedent); the shade the nil block
    // (the phantom precedent - the As-original-creature cells, AC the 9
    // default, xp 0); the solar 177 hp with the X/95000+35 xpValue 101195 and
    // the AC 9 kept per print-wins against the transcription -9 (the capture
    // preserves minus signs elsewhere - the R810 pudding precedent); the
    // scorpion large sting damage 1-16 (the capture 1 the column clip, the
    // transcription the confirm); the solifugid giant V350 the OCR artifact
    // read V/350+8; the sirine 20%-or-more MR 20 and 3-or-less AC 3; the
    // spectator body-4-eyes-7 AC 4 and the 4' diameter size (the capture 4"
    // the prime artifact); the stegocentipede 3/6 AC 3 and the 1-and-1 attack
    // sum 2; the taer 11-30 no-appearing confirmed in both voices; the selkie
    // sealware the sealwere settle and the solar Drawnij the Drawmij settle;
    // the olive slime 0 attacks the loader 1 clamp; every
    // Standard/See-below/Variable magic resistance 0; the percent lair cells
    // the bare-numeral read (the R812 repair lesson). Repair of the first
    // cut: the double commas in the kS/kSMark array lines of the walk patch
    // were collapsed to single commas (builder join bug); no other byte
    // changed.
    {
        using namespace rules;
        int bad = 0;
    if (mm2sRound() != 813
            || mm2sRegistryBefore() != 733
            || mm2sRegistryAfter() != 766
            || mm2sDefCount() != 33
            || mm2sEntryCount() != 29
            || mm2sStatBlockHeadings() != 34
            || mm2sDoctrineHeads() != 0
            || mm2sLetterSHeadings() != 29
            || mm2sSStatRows() != 33
            || mm2sGapClosed() != 24
            || mm2sGapOpen() != 13
            || mm2sPriorOwnedEntries() != 1
            || mm2sSandlingXpValue() != 141
            || mm2sSandlingXpLevel() != 3
            || mm2sScorpionLargeXpValue() != 117
            || mm2sScorpionLargeXpLevel() != 3
            || mm2sScorpionHugeXpValue() != 255
            || mm2sScorpionHugeXpLevel() != 4
            || mm2sScumCreeperXpValue() != 19
            || mm2sScumCreeperXpLevel() != 1
            || mm2sSelkieXpValue() != 127
            || mm2sSelkieXpLevel() != 3
            || mm2sShadeXpValue() != 0
            || mm2sShadeXpLevel() != 0
            || mm2sSirineXpValue() != 490
            || mm2sSirineXpLevel() != 5
            || mm2sSkeletonAnimalXpValue() != 12
            || mm2sSkeletonAnimalXpLevel() != 1
            || mm2sSkunkXpValue() != 6
            || mm2sSkunkXpLevel() != 1
            || mm2sSlimeCreatureXpValue() != 158
            || mm2sSlimeCreatureXpLevel() != 3
            || mm2sSlimeOliveXpValue() != 357
            || mm2sSlimeOliveXpLevel() != 5
            || mm2sSnakeConstrictorXpValue() != 133
            || mm2sSnakeConstrictorXpLevel() != 3
            || mm2sSnakePoisonousXpValue() != 279
            || mm2sSnakePoisonousXpLevel() != 5
            || mm2sSolarXpValue() != 101195
            || mm2sSolarXpLevel() != 10
            || mm2sSolifugidLargeXpValue() != 137
            || mm2sSolifugidLargeXpLevel() != 3
            || mm2sSolifugidHugeXpValue() != 357
            || mm2sSolifugidHugeXpLevel() != 4
            || mm2sSolifugidGiantXpValue() != 566
            || mm2sSolifugidGiantXpLevel() != 5
            || mm2sSpectatorXpValue() != 512
            || mm2sSpectatorXpLevel() != 5
            || mm2sSpiderGiantMarineXpValue() != 1022
            || mm2sSpiderGiantMarineXpLevel() != 6
            || mm2sSprigganXpValue() != 1140
            || mm2sSprigganXpLevel() != 6
            || mm2sSquealerXpValue() != 3672
            || mm2sSquealerXpLevel() != 5
            || mm2sSquirrelGiantBlackXpValue() != 28
            || mm2sSquirrelGiantBlackXpLevel() != 1
            || mm2sSquirrelOrdinaryXpValue() != 0
            || mm2sSquirrelOrdinaryXpLevel() != 1
            || mm2sSquirrelCarnivorousFlyingXpValue() != 14
            || mm2sSquirrelCarnivorousFlyingXpLevel() != 1
            || mm2sStegocentipedeXpValue() != 2072
            || mm2sStegocentipedeXpLevel() != 7
            || mm2sStenchKowXpValue() != 202
            || mm2sStenchKowXpLevel() != 3
            || mm2sStoneGuardianXpValue() != 694
            || mm2sStoneGuardianXpLevel() != 6
            || mm2sStoroperXpValue() != 626
            || mm2sStoroperXpLevel() != 6
            || mm2sSundewGiantXpValue() != 1355
            || mm2sSundewGiantXpLevel() != 7
            || mm2sSwanXpValue() != 0
            || mm2sSwanXpLevel() != 1
            || mm2sSwanmayXpValue() != 0
            || mm2sSwanmayXpLevel() != 0
            || mm2sSwordfishXpValue() != 47
            || mm2sSwordfishXpLevel() != 2
            || mm2sTaerXpValue() != 214
            || mm2sTaerXpLevel() != 3
            || mm2sSandlingWaterGallons() != 10
            || mm2sSandlingWaterDamageMax() != 8
            || mm2sSandlingFullSizeFeet() != 10
            || mm2sSandlingInfantSplitInches() != 2
            || mm2sSandlingHugeReportsMultiplier() != 3
            || mm2sScorpionLargeSaveBonus() != 2
            || mm2sScumFaceAttachChanceIn20() != 20
            || mm2sScumAttachDamagePerRound() != 1
            || mm2sScumSaltDamagePerRound() != 2
            || mm2sScumSaltRoundsMin() != 1
            || mm2sScumSaltRoundsMax() != 4
            || mm2sSelkieUnarmedUnderwaterPct() != 90
            || mm2sSelkieWeatherRestWeeks() != 1
            || mm2sShadeRegenPerTurn() != 1
            || mm2sShadeRegrowLimbsWeeksMin() != 1
            || mm2sShadeRegrowLimbsWeeksMax() != 4
            || mm2sShadeImagesMin() != 2
            || mm2sShadeImagesMax() != 5
            || mm2sShadeImageRangeFeet() != 30
            || mm2sShadeMrCapPct() != 60
            || mm2sShadeHideBonusShadowyPct() != 2
            || mm2sShadeHideBonusNightPct() != 5
            || mm2sShadeBrightSavePenalty() != 4
            || mm2sSirineSongRangeInches() != 3
            || mm2sSirineTouchIdiotInt() != 2
            || mm2sSirineSaveAsLevel() != 11
            || mm2sSirinePoisonSaveBonus() != 2
            || mm2sSkeletonAnimalAnimateNum() != 3
            || mm2sSkeletonAnimalAnimateDen() != 2
            || mm2sSkeletonAnimalTurnDieSides() != 8
            || mm2sSkeletonAnimalTurnDieBonus() != 6
            || mm2sSkeletonAnimalTurnPlus() != 1
            || mm2sSkunkMuskNauseaRoundsMin() != 1
            || mm2sSkunkMuskNauseaRoundsMax() != 4
            || mm2sSkunkBlindRoundsMin() != 1
            || mm2sSkunkBlindRoundsMax() != 4
            || mm2sSlimeCreatureInfectPct() != 10
            || mm2sSlimeCreatureTelepathyInches() != 20
            || mm2sOliveSlimeNoticePct() != 50
            || mm2sOliveSlimeMetamorphDaysMin() != 7
            || mm2sOliveSlimeMetamorphDaysMax() != 12
            || mm2sOliveSlimeWasteHpPctPerDay() != 10
            || mm2sSnakeConstrictorEscapePenalty() != 1
            || mm2sSnakePoisonRows() != 7
            || mm2sSnakePoisonSaveMod1() != 3
            || mm2sSnakePoisonSaveMod2() != 2
            || mm2sSnakePoisonSaveMod3() != 1
            || mm2sSnakePoisonSaveMod4() != 0
            || mm2sSnakePoisonSaveMod5() != -1
            || mm2sSnakePoisonSaveMod6() != -2
            || mm2sSnakePoisonSaveMod7() != -3
            || mm2sSolarRegenPerRound() != 7
            || mm2sSolarFighterLevel() != 17
            || mm2sSolarDexterity() != 24
            || mm2sSolarSpellClassLevel() != 12
            || mm2sSolarBowRangeInches() != 36
            || mm2sSolarSwordPlus() != 5
            || mm2sSolarWeaponPlusMinimum() != 5
            || mm2sSolarSummonMin() != 1
            || mm2sSolarSummonMax() != 2
            || mm2sSolarReformDecades() != 7
            || mm2sSolifugidLegs() != 10
            || mm2sSolifugidBeakBonus() != 3
            || mm2sSolifugidNocturnalPct() != 60
            || mm2sSolifugidDaylightPenalty() != 2
            || mm2sSolifugidSeverMargin() != 3
            || mm2sSpectatorGuardYears() != 101
            || mm2sSpectatorGuardMagicItemPct() != 90
            || mm2sSpectatorTreasureValueGp() != 15000
            || mm2sSpectatorBodyHitPct() != 70
            || mm2sSpectatorEyeHitPct() != 30
            || mm2sSpectatorCentralReflectPerRound() != 1
            || mm2sSpectatorInitiativeDie() != 8
            || mm2sSpectatorSenseRangeFeet() != 240
            || mm2sSpectatorEyeRegenDays() != 1
            || mm2sSprigganThiefLevel() != 8
            || mm2sSprigganDexterity() != 18
            || mm2sSprigganPickPocketsPct() != 75
            || mm2sSprigganOpenLocksPct() != 78
            || mm2sSprigganFindTrapsPct() != 70
            || mm2sSprigganMoveSilentlyPct() != 77
            || mm2sSprigganHideShadowsPct() != 64
            || mm2sSprigganHearNoisePct() != 35
            || mm2sSprigganClimbWallsPct() != 81
            || mm2sSprigganReadLanguagesPct() != 40
            || mm2sSprigganBackstabMultiplier() != 3
            || mm2sSprigganScareSavePenalty() != 2
            || mm2sSquealerCamouflagePct() != 75
            || mm2sSquealerSurprisePct() != 50
            || mm2sSquealerSurpriseBonus() != 2
            || mm2sSquealerCrushDamageMin() != 5
            || mm2sSquealerCrushDamageMax() != 8
            || mm2sSquealerWeightLb() != 400
            || mm2sSquealerYoungHpPerDie() != 2
            || mm2sSquirrelGiantLairHeightFeet() != 20
            || mm2sSquirrelFlyingGlideRatio() != 5
            || mm2sSquirrelFlyingSurpriseChanceIn6() != 4
            || mm2sSquirrelFlyingSurpriseHd() != 2
            || mm2sSquirrelFlyingOddsMin() != 2
            || mm2sStegoPlateAcPct() != 75
            || mm2sStegoTailDamageMin() != 3
            || mm2sStegoTailDamageMax() != 12
            || mm2sStegoSpikeDamageMin() != 1
            || mm2sStegoSpikeDamageMax() != 6
            || mm2sStegoSpikeAttackersMax() != 3
            || mm2sStegoTailReachFeet() != 6
            || mm2sStenchKowBullsPer() != 5
            || mm2sStenchKowBullHpPerDie() != 6
            || mm2sStenchKowBullMinDamage() != 5
            || mm2sStenchKowBullHd() != 6
            || mm2sStenchKowTrampleDamageMin() != 2
            || mm2sStenchKowTrampleDamageMax() != 12
            || mm2sStenchKowChargeDamageMultiplier() != 2
            || mm2sStenchKowStenchCheckRounds() != 3
            || mm2sStenchKowChargeMoveInches() != 1
            || mm2sStenchKowHerdYoungMin() != 5
            || mm2sStenchKowHerdYoungMax() != 30
            || mm2sStoneGuardianDisregardPct() != 20
            || mm2sStoneGuardianRingRadiusFeet() != 10
            || mm2sStoneGuardianEdgedDamageDivisor() != 4
            || mm2sStoneGuardianElementDamageDivisor() != 2
            || mm2sStoroperTentacles() != 6
            || mm2sStoroperVenomUsesPerDay() != 2
            || mm2sStoroperVenomDurationTurns() != 10
            || mm2sStoroperStrengthLossPct() != 50
            || mm2sStoroperDragFeetPerRound() != 10
            || mm2sStoroperSenseRangeFeet() != 200
            || mm2sStoroperAttackRangeFeet() != 50
            || mm2sSundewTendrilsPerVictim() != 6
            || mm2sSundewToHitPenaltyPerTendrils() != 3
            || mm2sSundewToHitPenalty() != 1
            || mm2sSundewSuffocateRoundsMin() != 2
            || mm2sSundewSuffocateRoundsMax() != 4
            || mm2sSundewEnzymeDamage() != 1
            || mm2sSwanBlindPct() != 50
            || mm2sSwanDangerSensePct() != 90
            || mm2sSwanSurpriseChanceIn10() != 10
            || mm2sSwanEggsMin() != 1
            || mm2sSwanEggsMax() != 3
            || mm2sSwanCygnetsMin() != 1
            || mm2sSwanCygnetsMax() != 2
            || mm2sSwanmayLevelDice() != 2
            || mm2sSwanmayLevelMin() != 1
            || mm2sSwanmayLevelMax() != 11
            || mm2sSwanmayWeaponPlusMin() != 1
            || mm2sSwanmayMrPerHitDie() != 2
            || mm2sTaerStenchRadiusFeet() != 10
            || mm2sTaerStenchHoursMin() != 2
            || mm2sTaerStenchHoursMax() != 5
            || mm2sTaerToHitPenalty() != 2
            || mm2sTaerDamagePenalty() != 1
            || mm2sTaerTreasurePct() != 15
            || mm2sTaerMagicItemPct() != 10
            || mm2sTaerSpearPct() != 50
            || mm2sTaerSpearToHitBonus() != 1
            || mm2sTaerSpearDamageBonus() != 3
            || mm2sSheduGreaterHdNum() != 14
            || mm2sSheduGreaterHdBonus() != 14
            || mm2sSheduGreaterAc() != 2
            || mm2sSheduGreaterMrPct() != 50
            || mm2sSheduGreaterMinorDisciplines() != 7
            || mm2sSheduGreaterMajorDisciplines() != 4
            || mm2sSheduGreaterMasteryLevel() != 14
            || mm2sSheduGreaterPsionicMin() != 120
            || mm2sSheduGreaterPsionicMax() != 150
            || mm2sSheduGreaterXpValue() != 6510
            || mm2sSheduGreaterXpLevel() != 9
            || !mm2sSandlingTerritorial()
            || !mm2sScorpionStingerLethal()
            || !mm2sScumWallClimber()
            || !mm2sSelkieLeaderSpellPowers()
            || !mm2sShadeUndying()
            || !mm2sShadeShadowWalk()
            || !mm2sSirineGasImmune()
            || !mm2sSirineSongCharm()
            || !mm2sSkeletonAnimalEdgedHalf()
            || !mm2sSkeletonAnimalImmuneToMindSpells()
            || !mm2sSkunkMuskCloud()
            || !mm2sSlimeCreatureHarmedByAcid()
            || !mm2sSlimeCreatureTrapLayer()
            || !mm2sOliveSlimeCureDiseaseKills()
            || !mm2sOliveSlimeNeutralizesGreenSlime()
            || !mm2sSolarAcidImmune()
            || !mm2sSolarNeverSurprised()
            || !mm2sSolarDeathMagicImmune()
            || !mm2sSolifugidFleeBrightLight()
            || !mm2sSpectatorCentralEyeReflect()
            || !mm2sSpectatorSummons()
            || !mm2sSpiderMarineParalyticBite()
            || !mm2sSquealerSoundImitation()
            || !mm2sSquirrelGiantStealsShiny()
            || !mm2sStegoTailPoison()
            || !mm2sStenchKowColdImmune()
            || !mm2sStenchKowFireImmune()
            || !mm2sStenchKowPoisonGasImmune()
            || !mm2sStoneGuardianMissileImmune()
            || !mm2sStoneGuardianMindless()
            || !mm2sStoneGuardianTransmuteKills()
            || !mm2sStoroperVenomNoSave()
            || !mm2sStoroperMissileImmune()
            || !mm2sSundewHalfDamageFromMissiles()
            || !mm2sSundewVinegarNeutralizes()
            || !mm2sSwanTerritorial()
            || !mm2sSwanmayRanger()
            || !mm2sSwanmayNoFollowers()
            || !mm2sSwordfishTrainedGuards()
            || !mm2sTaerColdImmune()
        )
            ++bad;
        // THE S-GRID: the 33-row SStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the thirty-three promoted letter S stat
        // blocks, in print order - the sandling p. 106 through the taer p.
        // 117)
        int CSStats[33][10] = {
            {3,4,0,14,1,85,4,65,12,0},
            {5,2,2,9,3,90,3,25,9,0},
            {4,4,4,18,3,165,5,25,12,0},
            {8,0,0,5,1,14,1,0,3,0},
            {5,3,3,13,1,75,4,0,12,0},
            {9,0,0,0,1,0,0,0,0,0},
            {3,4,0,14,1,350,10,30,12,20},
            {8,1,-1,2,1,10,1,85,6,0},
            {8,0,0,2,1,4,1,0,12,0},
            {9,3,2,12,1,110,4,0,6,0},
            {9,2,2,9,1,330,3,0,0,0},
            {6,3,2,12,2,85,4,0,9,0},
            {6,2,1,8,1,255,3,0,15,0},
            {9,0,0,177,4,95000,35,0,18,85},
            {6,3,3,13,2,85,4,10,9,0},
            {5,5,5,22,2,225,6,20,9,0},
            {4,6,6,27,2,350,8,25,12,0},
            {4,4,4,18,1,350,9,100,10,5},
            {4,7,7,31,1,650,12,70,15,0},
            {3,4,0,14,2,1000,10,30,9,0},
            {6,12,0,42,3,3000,16,15,12,0},
            {6,1,1,4,1,20,2,0,12,0},
            {8,0,0,1,1,0,0,0,9,0},
            {7,0,0,4,1,10,1,40,9,0},
            {3,9,0,31,2,1700,12,0,15,0},
            {2,3,3,13,1,150,4,0,15,0},
            {2,4,4,18,2,550,8,100,10,0},
            {0,6,0,21,1,500,6,90,1,0},
            {7,8,0,28,1,1075,10,0,1,0},
            {7,1,2,5,3,0,0,0,3,0},
            {7,2,0,7,1,0,0,0,3,2},
            {6,1,1,4,1,35,3,0,24,0},
            {4,3,6,16,3,150,4,40,18,0},
            };
        for (int b = 0;
             b < mm2sSStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2sSStatAc(b);
            vals[1] = mm2sSStatHd(b);
            vals[2] = mm2sSStatHdBonus(b);
            vals[3] = mm2sSStatAvgHp(b);
            vals[4] = mm2sSStatAttacks(b);
            vals[5] = mm2sSStatXp(b);
            vals[6] = mm2sSStatXpHp(b);
            vals[7] = mm2sSStatLairPct(b);
            vals[8] = mm2sSStatMove(b);
            vals[9] = mm2sSStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CSStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the Letter S gap
        // box flips (the census walk)
    if (mm2sRegistryAfter() - mm2sRegistryBefore() != mm2sDefCount()
            || mm2sDefCount() != 33
            || mm2sEntryCount() != 29
            || mm2sStatBlockHeadings() != 34
            || mm2sDoctrineHeads() != 0
            || mm2sLetterSHeadings() != 29
            || mm2sSStatRows() != 33
            || mm2sGapClosed() != 24
            || mm2sGapOpen() != 13
            || mm2sPriorOwnedEntries() != 1
        )
            ++bad;
        // the sandling grid row (p. 106 print order)
    if (mm2sSStatAc(0) != 3
            || mm2sSStatHd(0) != 4
            || mm2sSStatHdBonus(0) != 0
            || mm2sSStatAvgHp(0) != 14
            || mm2sSStatAttacks(0) != 1
            || mm2sSStatXp(0) != 85
            || mm2sSStatXpHp(0) != 4
            || mm2sSStatLairPct(0) != 65
            || mm2sSStatMove(0) != 12
            || mm2sSStatMr(0) != 0
            || mm2sSandlingXpValue() != 141
            || mm2sSandlingXpLevel() != 3
        )
            ++bad;
        // the scorpion, large grid row (p. 107 print order)
    if (mm2sSStatAc(1) != 5
            || mm2sSStatHd(1) != 2
            || mm2sSStatHdBonus(1) != 2
            || mm2sSStatAvgHp(1) != 9
            || mm2sSStatAttacks(1) != 3
            || mm2sSStatXp(1) != 90
            || mm2sSStatXpHp(1) != 3
            || mm2sSStatLairPct(1) != 25
            || mm2sSStatMove(1) != 9
            || mm2sSStatMr(1) != 0
            || mm2sScorpionLargeXpValue() != 117
            || mm2sScorpionLargeXpLevel() != 3
        )
            ++bad;
        // the scorpion, huge grid row (p. 107 print order)
    if (mm2sSStatAc(2) != 4
            || mm2sSStatHd(2) != 4
            || mm2sSStatHdBonus(2) != 4
            || mm2sSStatAvgHp(2) != 18
            || mm2sSStatAttacks(2) != 3
            || mm2sSStatXp(2) != 165
            || mm2sSStatXpHp(2) != 5
            || mm2sSStatLairPct(2) != 25
            || mm2sSStatMove(2) != 12
            || mm2sSStatMr(2) != 0
            || mm2sScorpionHugeXpValue() != 255
            || mm2sScorpionHugeXpLevel() != 4
        )
            ++bad;
        // the scum creeper grid row (p. 107 print order)
    if (mm2sSStatAc(3) != 8
            || mm2sSStatHd(3) != 0
            || mm2sSStatHdBonus(3) != 0
            || mm2sSStatAvgHp(3) != 5
            || mm2sSStatAttacks(3) != 1
            || mm2sSStatXp(3) != 14
            || mm2sSStatXpHp(3) != 1
            || mm2sSStatLairPct(3) != 0
            || mm2sSStatMove(3) != 3
            || mm2sSStatMr(3) != 0
            || mm2sScumCreeperXpValue() != 19
            || mm2sScumCreeperXpLevel() != 1
        )
            ++bad;
        // the selkie grid row (p. 107 print order)
    if (mm2sSStatAc(4) != 5
            || mm2sSStatHd(4) != 3
            || mm2sSStatHdBonus(4) != 3
            || mm2sSStatAvgHp(4) != 13
            || mm2sSStatAttacks(4) != 1
            || mm2sSStatXp(4) != 75
            || mm2sSStatXpHp(4) != 4
            || mm2sSStatLairPct(4) != 0
            || mm2sSStatMove(4) != 12
            || mm2sSStatMr(4) != 0
            || mm2sSelkieXpValue() != 127
            || mm2sSelkieXpLevel() != 3
        )
            ++bad;
        // the shade grid row (p. 108 print order)
    if (mm2sSStatAc(5) != 9
            || mm2sSStatHd(5) != 0
            || mm2sSStatHdBonus(5) != 0
            || mm2sSStatAvgHp(5) != 0
            || mm2sSStatAttacks(5) != 1
            || mm2sSStatXp(5) != 0
            || mm2sSStatXpHp(5) != 0
            || mm2sSStatLairPct(5) != 0
            || mm2sSStatMove(5) != 0
            || mm2sSStatMr(5) != 0
            || mm2sShadeXpValue() != 0
            || mm2sShadeXpLevel() != 0
        )
            ++bad;
        // the sirine grid row (p. 109 print order)
    if (mm2sSStatAc(6) != 3
            || mm2sSStatHd(6) != 4
            || mm2sSStatHdBonus(6) != 0
            || mm2sSStatAvgHp(6) != 14
            || mm2sSStatAttacks(6) != 1
            || mm2sSStatXp(6) != 350
            || mm2sSStatXpHp(6) != 10
            || mm2sSStatLairPct(6) != 30
            || mm2sSStatMove(6) != 12
            || mm2sSStatMr(6) != 20
            || mm2sSirineXpValue() != 490
            || mm2sSirineXpLevel() != 5
        )
            ++bad;
        // the skeleton, animal grid row (p. 109 print order)
    if (mm2sSStatAc(7) != 8
            || mm2sSStatHd(7) != 1
            || mm2sSStatHdBonus(7) != -1
            || mm2sSStatAvgHp(7) != 2
            || mm2sSStatAttacks(7) != 1
            || mm2sSStatXp(7) != 10
            || mm2sSStatXpHp(7) != 1
            || mm2sSStatLairPct(7) != 85
            || mm2sSStatMove(7) != 6
            || mm2sSStatMr(7) != 0
            || mm2sSkeletonAnimalXpValue() != 12
            || mm2sSkeletonAnimalXpLevel() != 1
        )
            ++bad;
        // the skunk grid row (p. 110 print order)
    if (mm2sSStatAc(8) != 8
            || mm2sSStatHd(8) != 0
            || mm2sSStatHdBonus(8) != 0
            || mm2sSStatAvgHp(8) != 2
            || mm2sSStatAttacks(8) != 1
            || mm2sSStatXp(8) != 4
            || mm2sSStatXpHp(8) != 1
            || mm2sSStatLairPct(8) != 0
            || mm2sSStatMove(8) != 12
            || mm2sSStatMr(8) != 0
            || mm2sSkunkXpValue() != 6
            || mm2sSkunkXpLevel() != 1
        )
            ++bad;
        // the slime creature grid row (p. 110 print order)
    if (mm2sSStatAc(9) != 9
            || mm2sSStatHd(9) != 3
            || mm2sSStatHdBonus(9) != 2
            || mm2sSStatAvgHp(9) != 12
            || mm2sSStatAttacks(9) != 1
            || mm2sSStatXp(9) != 110
            || mm2sSStatXpHp(9) != 4
            || mm2sSStatLairPct(9) != 0
            || mm2sSStatMove(9) != 6
            || mm2sSStatMr(9) != 0
            || mm2sSlimeCreatureXpValue() != 158
            || mm2sSlimeCreatureXpLevel() != 3
        )
            ++bad;
        // the slime, olive grid row (p. 110 print order)
    if (mm2sSStatAc(10) != 9
            || mm2sSStatHd(10) != 2
            || mm2sSStatHdBonus(10) != 2
            || mm2sSStatAvgHp(10) != 9
            || mm2sSStatAttacks(10) != 1
            || mm2sSStatXp(10) != 330
            || mm2sSStatXpHp(10) != 3
            || mm2sSStatLairPct(10) != 0
            || mm2sSStatMove(10) != 0
            || mm2sSStatMr(10) != 0
            || mm2sSlimeOliveXpValue() != 357
            || mm2sSlimeOliveXpLevel() != 5
        )
            ++bad;
        // the snake, constrictor grid row (p. 111 print order)
    if (mm2sSStatAc(11) != 6
            || mm2sSStatHd(11) != 3
            || mm2sSStatHdBonus(11) != 2
            || mm2sSStatAvgHp(11) != 12
            || mm2sSStatAttacks(11) != 2
            || mm2sSStatXp(11) != 85
            || mm2sSStatXpHp(11) != 4
            || mm2sSStatLairPct(11) != 0
            || mm2sSStatMove(11) != 9
            || mm2sSStatMr(11) != 0
            || mm2sSnakeConstrictorXpValue() != 133
            || mm2sSnakeConstrictorXpLevel() != 3
        )
            ++bad;
        // the snake, poisonous grid row (p. 111 print order)
    if (mm2sSStatAc(12) != 6
            || mm2sSStatHd(12) != 2
            || mm2sSStatHdBonus(12) != 1
            || mm2sSStatAvgHp(12) != 8
            || mm2sSStatAttacks(12) != 1
            || mm2sSStatXp(12) != 255
            || mm2sSStatXpHp(12) != 3
            || mm2sSStatLairPct(12) != 0
            || mm2sSStatMove(12) != 15
            || mm2sSStatMr(12) != 0
            || mm2sSnakePoisonousXpValue() != 279
            || mm2sSnakePoisonousXpLevel() != 5
        )
            ++bad;
        // the solar grid row (p. 111-112 print order)
    if (mm2sSStatAc(13) != 9
            || mm2sSStatHd(13) != 0
            || mm2sSStatHdBonus(13) != 0
            || mm2sSStatAvgHp(13) != 177
            || mm2sSStatAttacks(13) != 4
            || mm2sSStatXp(13) != 95000
            || mm2sSStatXpHp(13) != 35
            || mm2sSStatLairPct(13) != 0
            || mm2sSStatMove(13) != 18
            || mm2sSStatMr(13) != 85
            || mm2sSolarXpValue() != 101195
            || mm2sSolarXpLevel() != 10
        )
            ++bad;
        // the solifugid, large grid row (p. 112 print order)
    if (mm2sSStatAc(14) != 6
            || mm2sSStatHd(14) != 3
            || mm2sSStatHdBonus(14) != 3
            || mm2sSStatAvgHp(14) != 13
            || mm2sSStatAttacks(14) != 2
            || mm2sSStatXp(14) != 85
            || mm2sSStatXpHp(14) != 4
            || mm2sSStatLairPct(14) != 10
            || mm2sSStatMove(14) != 9
            || mm2sSStatMr(14) != 0
            || mm2sSolifugidLargeXpValue() != 137
            || mm2sSolifugidLargeXpLevel() != 3
        )
            ++bad;
        // the solifugid, huge grid row (p. 112 print order)
    if (mm2sSStatAc(15) != 5
            || mm2sSStatHd(15) != 5
            || mm2sSStatHdBonus(15) != 5
            || mm2sSStatAvgHp(15) != 22
            || mm2sSStatAttacks(15) != 2
            || mm2sSStatXp(15) != 225
            || mm2sSStatXpHp(15) != 6
            || mm2sSStatLairPct(15) != 20
            || mm2sSStatMove(15) != 9
            || mm2sSStatMr(15) != 0
            || mm2sSolifugidHugeXpValue() != 357
            || mm2sSolifugidHugeXpLevel() != 4
        )
            ++bad;
        // the solifugid, giant grid row (p. 112 print order)
    if (mm2sSStatAc(16) != 4
            || mm2sSStatHd(16) != 6
            || mm2sSStatHdBonus(16) != 6
            || mm2sSStatAvgHp(16) != 27
            || mm2sSStatAttacks(16) != 2
            || mm2sSStatXp(16) != 350
            || mm2sSStatXpHp(16) != 8
            || mm2sSStatLairPct(16) != 25
            || mm2sSStatMove(16) != 12
            || mm2sSStatMr(16) != 0
            || mm2sSolifugidGiantXpValue() != 566
            || mm2sSolifugidGiantXpLevel() != 5
        )
            ++bad;
        // the spectator grid row (p. 112-113 print order)
    if (mm2sSStatAc(17) != 4
            || mm2sSStatHd(17) != 4
            || mm2sSStatHdBonus(17) != 4
            || mm2sSStatAvgHp(17) != 18
            || mm2sSStatAttacks(17) != 1
            || mm2sSStatXp(17) != 350
            || mm2sSStatXpHp(17) != 9
            || mm2sSStatLairPct(17) != 100
            || mm2sSStatMove(17) != 10
            || mm2sSStatMr(17) != 5
            || mm2sSpectatorXpValue() != 512
            || mm2sSpectatorXpLevel() != 5
        )
            ++bad;
        // the spider, giant marine grid row (p. 113 print order)
    if (mm2sSStatAc(18) != 4
            || mm2sSStatHd(18) != 7
            || mm2sSStatHdBonus(18) != 7
            || mm2sSStatAvgHp(18) != 31
            || mm2sSStatAttacks(18) != 1
            || mm2sSStatXp(18) != 650
            || mm2sSStatXpHp(18) != 12
            || mm2sSStatLairPct(18) != 70
            || mm2sSStatMove(18) != 15
            || mm2sSStatMr(18) != 0
            || mm2sSpiderGiantMarineXpValue() != 1022
            || mm2sSpiderGiantMarineXpLevel() != 6
        )
            ++bad;
        // the spriggan grid row (p. 113 print order)
    if (mm2sSStatAc(19) != 3
            || mm2sSStatHd(19) != 4
            || mm2sSStatHdBonus(19) != 0
            || mm2sSStatAvgHp(19) != 14
            || mm2sSStatAttacks(19) != 2
            || mm2sSStatXp(19) != 1000
            || mm2sSStatXpHp(19) != 10
            || mm2sSStatLairPct(19) != 30
            || mm2sSStatMove(19) != 9
            || mm2sSStatMr(19) != 0
            || mm2sSprigganXpValue() != 1140
            || mm2sSprigganXpLevel() != 6
        )
            ++bad;
        // the squealer grid row (p. 113-114 print order)
    if (mm2sSStatAc(20) != 6
            || mm2sSStatHd(20) != 12
            || mm2sSStatHdBonus(20) != 0
            || mm2sSStatAvgHp(20) != 42
            || mm2sSStatAttacks(20) != 3
            || mm2sSStatXp(20) != 3000
            || mm2sSStatXpHp(20) != 16
            || mm2sSStatLairPct(20) != 15
            || mm2sSStatMove(20) != 12
            || mm2sSStatMr(20) != 0
            || mm2sSquealerXpValue() != 3672
            || mm2sSquealerXpLevel() != 5
        )
            ++bad;
        // the squirrel, giant black grid row (p. 114 print order)
    if (mm2sSStatAc(21) != 6
            || mm2sSStatHd(21) != 1
            || mm2sSStatHdBonus(21) != 1
            || mm2sSStatAvgHp(21) != 4
            || mm2sSStatAttacks(21) != 1
            || mm2sSStatXp(21) != 20
            || mm2sSStatXpHp(21) != 2
            || mm2sSStatLairPct(21) != 0
            || mm2sSStatMove(21) != 12
            || mm2sSStatMr(21) != 0
            || mm2sSquirrelGiantBlackXpValue() != 28
            || mm2sSquirrelGiantBlackXpLevel() != 1
        )
            ++bad;
        // the squirrel, ordinary grid row (p. 114 print order)
    if (mm2sSStatAc(22) != 8
            || mm2sSStatHd(22) != 0
            || mm2sSStatHdBonus(22) != 0
            || mm2sSStatAvgHp(22) != 1
            || mm2sSStatAttacks(22) != 1
            || mm2sSStatXp(22) != 0
            || mm2sSStatXpHp(22) != 0
            || mm2sSStatLairPct(22) != 0
            || mm2sSStatMove(22) != 9
            || mm2sSStatMr(22) != 0
            || mm2sSquirrelOrdinaryXpValue() != 0
            || mm2sSquirrelOrdinaryXpLevel() != 1
        )
            ++bad;
        // the squirrel, carnivorous flying grid row (p. 114 print order)
    if (mm2sSStatAc(23) != 7
            || mm2sSStatHd(23) != 0
            || mm2sSStatHdBonus(23) != 0
            || mm2sSStatAvgHp(23) != 4
            || mm2sSStatAttacks(23) != 1
            || mm2sSStatXp(23) != 10
            || mm2sSStatXpHp(23) != 1
            || mm2sSStatLairPct(23) != 40
            || mm2sSStatMove(23) != 9
            || mm2sSStatMr(23) != 0
            || mm2sSquirrelCarnivorousFlyingXpValue() != 14
            || mm2sSquirrelCarnivorousFlyingXpLevel() != 1
        )
            ++bad;
        // the stegocentipede grid row (p. 114-115 print order)
    if (mm2sSStatAc(24) != 3
            || mm2sSStatHd(24) != 9
            || mm2sSStatHdBonus(24) != 0
            || mm2sSStatAvgHp(24) != 31
            || mm2sSStatAttacks(24) != 2
            || mm2sSStatXp(24) != 1700
            || mm2sSStatXpHp(24) != 12
            || mm2sSStatLairPct(24) != 0
            || mm2sSStatMove(24) != 15
            || mm2sSStatMr(24) != 0
            || mm2sStegocentipedeXpValue() != 2072
            || mm2sStegocentipedeXpLevel() != 7
        )
            ++bad;
        // the stench kow grid row (p. 115 print order)
    if (mm2sSStatAc(25) != 2
            || mm2sSStatHd(25) != 3
            || mm2sSStatHdBonus(25) != 3
            || mm2sSStatAvgHp(25) != 13
            || mm2sSStatAttacks(25) != 1
            || mm2sSStatXp(25) != 150
            || mm2sSStatXpHp(25) != 4
            || mm2sSStatLairPct(25) != 0
            || mm2sSStatMove(25) != 15
            || mm2sSStatMr(25) != 0
            || mm2sStenchKowXpValue() != 202
            || mm2sStenchKowXpLevel() != 3
        )
            ++bad;
        // the stone guardian grid row (p. 115 print order)
    if (mm2sSStatAc(26) != 2
            || mm2sSStatHd(26) != 4
            || mm2sSStatHdBonus(26) != 4
            || mm2sSStatAvgHp(26) != 18
            || mm2sSStatAttacks(26) != 2
            || mm2sSStatXp(26) != 550
            || mm2sSStatXpHp(26) != 8
            || mm2sSStatLairPct(26) != 100
            || mm2sSStatMove(26) != 10
            || mm2sSStatMr(26) != 0
            || mm2sStoneGuardianXpValue() != 694
            || mm2sStoneGuardianXpLevel() != 6
        )
            ++bad;
        // the storoper grid row (p. 115-116 print order)
    if (mm2sSStatAc(27) != 0
            || mm2sSStatHd(27) != 6
            || mm2sSStatHdBonus(27) != 0
            || mm2sSStatAvgHp(27) != 21
            || mm2sSStatAttacks(27) != 1
            || mm2sSStatXp(27) != 500
            || mm2sSStatXpHp(27) != 6
            || mm2sSStatLairPct(27) != 90
            || mm2sSStatMove(27) != 1
            || mm2sSStatMr(27) != 0
            || mm2sStoroperXpValue() != 626
            || mm2sStoroperXpLevel() != 6
        )
            ++bad;
        // the sundew, giant grid row (p. 116 print order)
    if (mm2sSStatAc(28) != 7
            || mm2sSStatHd(28) != 8
            || mm2sSStatHdBonus(28) != 0
            || mm2sSStatAvgHp(28) != 28
            || mm2sSStatAttacks(28) != 1
            || mm2sSStatXp(28) != 1075
            || mm2sSStatXpHp(28) != 10
            || mm2sSStatLairPct(28) != 0
            || mm2sSStatMove(28) != 1
            || mm2sSStatMr(28) != 0
            || mm2sSundewGiantXpValue() != 1355
            || mm2sSundewGiantXpLevel() != 7
        )
            ++bad;
        // the swan grid row (p. 116 print order)
    if (mm2sSStatAc(29) != 7
            || mm2sSStatHd(29) != 1
            || mm2sSStatHdBonus(29) != 2
            || mm2sSStatAvgHp(29) != 5
            || mm2sSStatAttacks(29) != 3
            || mm2sSStatXp(29) != 0
            || mm2sSStatXpHp(29) != 0
            || mm2sSStatLairPct(29) != 0
            || mm2sSStatMove(29) != 3
            || mm2sSStatMr(29) != 0
            || mm2sSwanXpValue() != 0
            || mm2sSwanXpLevel() != 1
        )
            ++bad;
        // the swanmay grid row (p. 116-117 print order)
    if (mm2sSStatAc(30) != 7
            || mm2sSStatHd(30) != 2
            || mm2sSStatHdBonus(30) != 0
            || mm2sSStatAvgHp(30) != 7
            || mm2sSStatAttacks(30) != 1
            || mm2sSStatXp(30) != 0
            || mm2sSStatXpHp(30) != 0
            || mm2sSStatLairPct(30) != 0
            || mm2sSStatMove(30) != 3
            || mm2sSStatMr(30) != 2
            || mm2sSwanmayXpValue() != 0
            || mm2sSwanmayXpLevel() != 0
        )
            ++bad;
        // the swordfish grid row (p. 117 print order)
    if (mm2sSStatAc(31) != 6
            || mm2sSStatHd(31) != 1
            || mm2sSStatHdBonus(31) != 1
            || mm2sSStatAvgHp(31) != 4
            || mm2sSStatAttacks(31) != 1
            || mm2sSStatXp(31) != 35
            || mm2sSStatXpHp(31) != 3
            || mm2sSStatLairPct(31) != 0
            || mm2sSStatMove(31) != 24
            || mm2sSStatMr(31) != 0
            || mm2sSwordfishXpValue() != 47
            || mm2sSwordfishXpLevel() != 2
        )
            ++bad;
        // the taer grid row (p. 117 print order)
    if (mm2sSStatAc(32) != 4
            || mm2sSStatHd(32) != 3
            || mm2sSStatHdBonus(32) != 6
            || mm2sSStatAvgHp(32) != 16
            || mm2sSStatAttacks(32) != 3
            || mm2sSStatXp(32) != 150
            || mm2sSStatXpHp(32) != 4
            || mm2sSStatLairPct(32) != 40
            || mm2sSStatMove(32) != 18
            || mm2sSStatMr(32) != 0
            || mm2sTaerXpValue() != 214
            || mm2sTaerXpLevel() != 3
        )
            ++bad;
        printf("R813 MM2 letter S walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
