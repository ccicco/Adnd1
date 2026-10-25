    // ---- R814 MM2 letters TUV walk audit ----
    // THE MM2 LETTERS TUV WALK - the tarrasque p. 117 (its treasure and lair
    // cells the See-below read), the tasloi p. 118, the giant harvester
    // termite variant table pp. 118-119 (the worker and soldier columns, plus
    // the king and queen the royal-pair inline stats), the thessalhydra, the
    // thri-kreen, the thunder beast and the time elemental p. 119, the
    // thunderherder p. 120, the transposer p. 120, the tri-flower frond p.
    // 121, the troll marine (scrag) variant table p. 121 (the fresh and salt
    // water columns), the twilight bloom and the land urchin p. 122, the
    // ustilagor p. 122 and the vagabond pp. 122-123, the vargouille p. 123,
    // the vegepygmy, the verme and the vilstrak p. 124, the vulchling and the
    // vulture variant table p. 125 (the giant and ordinary columns); the
    // TUV-FLIP round: the Letter T, U and V gap boxes flip to closed (27
    // closed, 10 open). TWENTY-SIX .lua defs ride the R791 data_files
    // extension, registry 766 -> 792; TWENTY-ONE entry heads carrying
    // TWENTY-TWO stat blocks (the termite royal pair the one extra block), no
    // prior-owned heads, no doctrine-only heads. THE SETTLED READS (capture
    // primary, the 1eonline transcription the cross-check voice): the
    // tarrasque 300 hp the flat-hp path (hdNum 0) and its AC -3 the UNQUOTED
    // number (the phoenix precedent); the transposer xp VI/625 the
    // capture-wins read (the transcription 525); the scrag saltwater 6+12 the
    // capture-wins read (the transcription 5+12); the thessalhydra IX/5800
    // (the capture 5S00, the S an 8 artifact, the transcription the confirm);
    // the ordinary vulture AC 6 the capture-wins read (the transcription 7)
    // and the two vulture xp rows pinned verbatim (the giant I/20 + 2/hp, the
    // ordinary II/35 with no per-hp - the print rows as printed, not a
    // ladder); the vegepygmy HD 1 to 6 the low-end read with its 6-rung xp
    // ladder pinned as consts (53+1, 81+2, 120+3, 175+4, 245+5, 425+6 - the
    // R812 rider precedent) and its treasure O, T, P the capture-wins read
    // (the transcription Q, P); the ustilagor intelligence Unstable the
    // capture-wins read (the transcription Unratable); the land urchin 2-12
    // spines the loader 10 clamp; the vilstrak 1-6 hp the flat-hp high-end
    // read 6 (the scum creeper precedent); the vagabond the nil block (the
    // phantom precedent - the As-form cells, AC the 9 default, xp 0); the
    // print typos pinned where both voices agree (the lejendary tarrasque,
    // the tranposer, Tarterus, the parallel unverse); every Standard,
    // See-below, As-form and Special magic resistance 0; the percent lair
    // cells the bare-numeral read (the R812 repair lesson). REPAIR OF THE
    // FIRST CUT: the vagabond hitDiceNum cell was authored as the string "As
    // form" and the regtest walk came back bad 1 - the loader hitDiceNum
    // default is 1, so a non-numeric cell rides the default instead of
    // reading 0; the cell is now the numeric "0" - the shade precedent; the
    // offline loader sim was taught the default-1 semantics (the new sim gate
    // class) so this cannot recur unseen; no other byte changed.
    {
        using namespace rules;
        int bad = 0;
    if (mm2tuvRound() != 814
            || mm2tuvRegistryBefore() != 766
            || mm2tuvRegistryAfter() != 792
            || mm2tuvDefCount() != 26
            || mm2tuvEntryCount() != 21
            || mm2tuvStatBlockHeadings() != 22
            || mm2tuvDoctrineHeads() != 0
            || mm2tuvLetterTUVHeadings() != 21
            || mm2tuvTUVStatRows() != 26
            || mm2tuvGapClosed() != 27
            || mm2tuvGapOpen() != 10
            || mm2tuvPriorOwnedEntries() != 0
            || mm2tuvTarrasqueXpValue() != 37500
            || mm2tuvTarrasqueXpLevel() != 10
            || mm2tuvTarrasqueHitPoints() != 300
            || mm2tuvTarrasqueRushBonusInches() != 6
            || mm2tuvTarrasqueTailLashMax() != 24
            || mm2tuvTarrasqueBiteMax() != 50
            || mm2tuvTarrasqueHornMax() != 10
            || mm2tuvTarrasqueReflectChance() != 6
            || mm2tuvTarrasqueRegenPerRound() != 1
            || mm2tuvTarrasqueSlayThreshold() != -30
            || mm2tuvTarrasqueDiamondMin() != 10
            || mm2tuvTarrasqueDiamondMax() != 100
            || mm2tuvTarrasqueDiamondBaseGp() != 1000
            || mm2tuvTarrasqueShieldMin() != 1
            || mm2tuvTarrasqueShieldMax() != 4
            || mm2tuvTarrasqueShieldPlus() != 5
            || mm2tuvTarrasqueDormancyMinMonths() != 5
            || mm2tuvTarrasqueDormancyMaxMonths() != 20
            || mm2tuvTarrasqueActiveToDormantRatio() != 30
            || mm2tuvTasloiXpValue() != 13
            || mm2tuvTasloiXpLevel() != 1
            || mm2tuvTasloiSurpriseMax() != 4
            || mm2tuvTasloiHideInShadowsPct() != 75
            || mm2tuvTasloiDaylightPenalty() != 1
            || mm2tuvTasloiChiefBandSize() != 70
            || mm2tuvTasloiChiefHitDice() != 5
            || mm2tuvTasloiShamanChancePct() != 30
            || mm2tuvTasloiShamanMaxLevel() != 5
            || mm2tuvTasloiShieldArmorClass() != 5
            || mm2tuvTasloiLairTreesMin() != 1
            || mm2tuvTasloiLairTreesMax() != 6
            || mm2tuvTasloiPlatformsMin() != 4
            || mm2tuvTasloiPlatformsMax() != 24
            || mm2tuvTasloiPlatformHeightMin() != 50
            || mm2tuvTasloiPlatformHeightMax() != 100
            || mm2tuvTasloiGiantSpiderChancePct() != 60
            || mm2tuvTasloiGiantWaspChancePct() != 20
            || mm2tuvTasloiPidginCommonPct() != 5
            || mm2tuvTermiteWorkerXpValue() != 30
            || mm2tuvTermiteWorkerXpLevel() != 1
            || mm2tuvTermiteNestDiameterFeet() != 100
            || mm2tuvTermiteNestHeightMinFeet() != 200
            || mm2tuvTermiteNestHeightMaxFeet() != 500
            || mm2tuvTermiteOpeningMinFeet() != 5
            || mm2tuvTermiteOpeningMaxFeet() != 8
            || mm2tuvTermiteLairMultiplier() != 10
            || mm2tuvTermiteSoldierEscortMin() != 3
            || mm2tuvTermiteSoldierEscortMax() != 16
            || mm2tuvTermiteChamberGuardBonus() != 1
            || mm2tuvTermiteSoldierXpValue() != 77
            || mm2tuvTermiteSoldierXpLevel() != 2
            || mm2tuvTermiteSoldierBlindMinRounds() != 5
            || mm2tuvTermiteSoldierBlindMaxRounds() != 20
            || mm2tuvTermiteSoldierBurnMin() != 5
            || mm2tuvTermiteSoldierBurnMax() != 16
            || mm2tuvTermiteSoldierSpitRangeInches() != 1
            || mm2tuvTermiteKingXpValue() != 770
            || mm2tuvTermiteKingXpLevel() != 5
            || mm2tuvTermiteKingHpMin() != 30
            || mm2tuvTermiteKingDamageMax() != 18
            || mm2tuvTermiteQueenXpValue() != 1368
            || mm2tuvTermiteQueenXpLevel() != 6
            || mm2tuvTermiteQueenHpMin() != 40
            || mm2tuvTermiteQueenDamageMax() != 30
            || mm2tuvThessalhydraXpValue() != 6472
            || mm2tuvThessalhydraXpLevel() != 9
            || mm2tuvThessalhydraFringeHeadFeet() != 6
            || mm2tuvThessalhydraSeverDamage() != 12
            || mm2tuvThessalhydraFringeRegenDays() != 12
            || mm2tuvThessalhydraSpitRangeInches() != 3
            || mm2tuvThessalhydraSpitDiameterFeet() != 12
            || mm2tuvThessalhydraSpitMin() != 12
            || mm2tuvThessalhydraSpitMax() != 72
            || mm2tuvThessalhydraMouthMax() != 20
            || mm2tuvThessalhydraTailMax() != 12
            || mm2tuvThriKreenXpValue() != 992
            || mm2tuvThriKreenXpLevel() != 6
            || mm2tuvThriKreenLeapUpFeet() != 20
            || mm2tuvThriKreenLeapForwardFeet() != 50
            || mm2tuvThriKreenPolearmMin() != 3
            || mm2tuvThriKreenPolearmMax() != 8
            || mm2tuvThriKreenWedgeMin() != 3
            || mm2tuvThriKreenWedgeMax() != 6
            || mm2tuvThriKreenWedgeRangeInches() != 9
            || mm2tuvThriKreenWedgeCarryMax() != 10
            || mm2tuvThriKreenDodgeRoll() != 9
            || mm2tuvThriKreenBiteMin() != 2
            || mm2tuvThriKreenBiteMax() != 5
            || mm2tuvThriKreenParalysisMinRounds() != 2
            || mm2tuvThriKreenParalysisMaxRounds() != 16
            || mm2tuvThunderBeastXpValue() != 800
            || mm2tuvThunderBeastXpLevel() != 6
            || mm2tuvThunderBeastYoungPerAdults() != 2
            || mm2tuvThunderBeastTrampleRangeInches() != 2
            || mm2tuvThunderBeastTrampleDieMax() != 4
            || mm2tuvThunderBeastBreathRounds() != 3
            || mm2tuvThunderBeastCloudMinRounds() != 1
            || mm2tuvThunderBeastCloudMaxRounds() != 4
            || mm2tuvThunderBeastOdorPenalty() != 2
            || mm2tuvThunderBeastLegs() != 6
            || mm2tuvThunderBeastRareHd() != 9
            || mm2tuvThunderBeastRareHdChance() != 5
            || mm2tuvTimeElementalXpValue() != 3840
            || mm2tuvTimeElementalXpLevel() != 7
            || mm2tuvTimeElementalExtraMin() != 1
            || mm2tuvTimeElementalExtraMax() != 4
            || mm2tuvTimeElementalDampenInches() != 3
            || mm2tuvTimeElementalSpellChance() != 10
            || mm2tuvTimeElementalPursuitPerHd() != 1
            || mm2tuvTimeElementalCommonPursuitMax() != 13
            || mm2tuvTimeElementalNoblePursuitMax() != 17
            || mm2tuvTimeElementalTravelPerHd() != 1
            || mm2tuvTimeElementalNobleAgeMin() != 1
            || mm2tuvTimeElementalNobleAgeMax() != 20
            || mm2tuvTimeElementalMatterAgeMin() != 10
            || mm2tuvTimeElementalMatterAgeMax() != 200
            || mm2tuvTimeElementalMineralAgeMin() != 100
            || mm2tuvTimeElementalMineralAgeMax() != 2000
            || mm2tuvTimeElementalNobleMoveMax() != 4
            || mm2tuvTimeElementalRoyalHdMin() != 24
            || mm2tuvTimeElementalRoyalHdMax() != 28
            || mm2tuvTimeElementalRoyalSummonPct() != 70
            || mm2tuvThunderherderXpValue() != 542
            || mm2tuvThunderherderXpLevel() != 5
            || mm2tuvThunderherderWidthMinFeet() != 3
            || mm2tuvThunderherderWidthMaxFeet() != 5
            || mm2tuvThunderherderLengthMinFeet() != 5
            || mm2tuvThunderherderLengthMaxFeet() != 10
            || mm2tuvTransposerXpValue() != 772
            || mm2tuvTransposerXpLevel() != 6
            || mm2tuvTransposerMaxHp() != 48
            || mm2tuvTransposerSuckerMax() != 6
            || mm2tuvTransposerExampleDamage() != 20
            || mm2tuvTriFlowerXpValue() != 165
            || mm2tuvTriFlowerXpLevel() != 3
            || mm2tuvTriFlowerStalkMinFeet() != 5
            || mm2tuvTriFlowerStalkMaxFeet() != 8
            || mm2tuvTriFlowerTendrilMin() != 2
            || mm2tuvTriFlowerTendrilMax() != 8
            || mm2tuvTriFlowerTendrilFeet() != 3
            || mm2tuvTriFlowerEnzymeMin() != 2
            || mm2tuvTriFlowerEnzymeMax() != 8
            || mm2tuvTriFlowerWaterReduction() != 1
            || mm2tuvTriFlowerRedTendrilFeet() != 1
            || mm2tuvTriFlowerDrainMin() != 1
            || mm2tuvTriFlowerDrainMax() != 6
            || mm2tuvScragFreshwaterXpValue() != 576
            || mm2tuvScragFreshwaterXpLevel() != 5
            || mm2tuvScragFreshClawMax() != 5
            || mm2tuvScragFreshJawMin() != 3
            || mm2tuvScragFreshJawMax() != 12
            || mm2tuvScragFreshOpponents() != 3
            || mm2tuvScragSaltwaterXpValue() != 1296
            || mm2tuvScragSaltwaterXpLevel() != 6
            || mm2tuvScragSaltArmoredPct() != 10
            || mm2tuvScragSaltArmoredAc() != 1
            || mm2tuvScragSaltClawMax() != 4
            || mm2tuvScragSaltMawMin() != 9
            || mm2tuvScragSaltMawMax() != 16
            || mm2tuvTwilightBloomXpValue() != 197
            || mm2tuvTwilightBloomXpLevel() != 3
            || mm2tuvTwilightBloomHeightMinFeet() != 8
            || mm2tuvTwilightBloomHeightMaxFeet() != 13
            || mm2tuvTwilightBloomSapChancePct() != 25
            || mm2tuvUrchinLandXpValue() != 202
            || mm2tuvUrchinLandXpLevel() != 3
            || mm2tuvUrchinSpineMin() != 2
            || mm2tuvUrchinSpineMax() != 12
            || mm2tuvUrchinSpineDamageMax() != 2
            || mm2tuvUrchinParalysisTurns() != 6
            || mm2tuvUrchinSmokeRadiusFeet() != 10
            || mm2tuvUrchinAntennae() != 2
            || mm2tuvUrchinLegs() != 5
            || mm2tuvUrchinPearlMinGp() != 100
            || mm2tuvUrchinPearlMaxGp() != 600
            || mm2tuvUrchinPearlsMax() != 12
            || mm2tuvUstilagorXpValue() != 187
            || mm2tuvUstilagorXpLevel() != 3
            || mm2tuvUstilagorTendrilFeet() != 3
            || mm2tuvUstilagorAlkaliMin() != 2
            || mm2tuvUstilagorAlkaliMax() != 5
            || mm2tuvVagabondXpValue() != 0
            || mm2tuvVagabondXpLevel() != 0
            || mm2tuvVagabondJoinPct() != 90
            || mm2tuvVagabondGemCharges() != 3
            || mm2tuvVargouilleXpValue() != 126
            || mm2tuvVargouilleXpLevel() != 3
            || mm2tuvVargouilleBiteMax() != 4
            || mm2tuvVargouilleWingspreadFeet() != 3
            || mm2tuvVegepygmyXpValue() != 56
            || mm2tuvVegepygmyXpLevel() != 3
            || mm2tuvVegepygmySurprisePct() != 50
            || mm2tuvVegepygmyPiercingDamage() != 1
            || mm2tuvVegepygmyShriekerPct() != 40
            || mm2tuvVegepygmyShriekerMin() != 1
            || mm2tuvVegepygmyShriekerMax() != 3
            || mm2tuvVegepygmyRussetMoldPct() != 70
            || mm2tuvVegepygmySubchiefPer() != 50
            || mm2tuvVegepygmySubchiefHd() != 5
            || mm2tuvVegepygmySubchiefGuardsMin() != 2
            || mm2tuvVegepygmySubchiefGuardsMax() != 5
            || mm2tuvVegepygmySubchiefGuardHd() != 3
            || mm2tuvVegepygmyLeaderHd() != 6
            || mm2tuvVegepygmyLeaderGuardsMin() != 2
            || mm2tuvVegepygmyLeaderGuardsMax() != 8
            || mm2tuvVegepygmyLeaderGuardHd() != 4
            || mm2tuvVegepygmyLadderBase2() != 81
            || mm2tuvVegepygmyLadderPerHp2() != 2
            || mm2tuvVegepygmyLadderXpValue2() != 95
            || mm2tuvVegepygmyLadderLevel2() != 3
            || mm2tuvVegepygmyLadderBase3() != 120
            || mm2tuvVegepygmyLadderPerHp3() != 3
            || mm2tuvVegepygmyLadderXpValue3() != 150
            || mm2tuvVegepygmyLadderLevel3() != 3
            || mm2tuvVegepygmyLadderBase4() != 175
            || mm2tuvVegepygmyLadderPerHp4() != 4
            || mm2tuvVegepygmyLadderXpValue4() != 231
            || mm2tuvVegepygmyLadderLevel4() != 4
            || mm2tuvVegepygmyLadderBase5() != 245
            || mm2tuvVegepygmyLadderPerHp5() != 5
            || mm2tuvVegepygmyLadderXpValue5() != 330
            || mm2tuvVegepygmyLadderLevel5() != 4
            || mm2tuvVegepygmyLadderBase6() != 425
            || mm2tuvVegepygmyLadderPerHp6() != 6
            || mm2tuvVegepygmyLadderXpValue6() != 551
            || mm2tuvVegepygmyLadderLevel6() != 5
            || mm2tuvVermeXpValue() != 10575
            || mm2tuvVermeXpLevel() != 9
            || mm2tuvVermeSwallowHeightFeet() != 12
            || mm2tuvVermeSwallowMax() != 28
            || mm2tuvVermeSwallowRoundMin() != 2
            || mm2tuvVermeSwallowRoundMax() != 16
            || mm2tuvVermeDissolveRounds() != 6
            || mm2tuvVermeEdgedDamage() != 1
            || mm2tuvVilstrakXpValue() != 13
            || mm2tuvVilstrakXpLevel() != 1
            || mm2tuvVilstrakUndetectablePct() != 75
            || mm2tuvVilstrakDetectFeet() != 20
            || mm2tuvVilstrakBadLairPct() != 5
            || mm2tuvVulchlingXpValue() != 13
            || mm2tuvVulchlingXpLevel() != 1
            || mm2tuvVulchlingEggsMin() != 0
            || mm2tuvVulchlingEggsMax() != 9
            || mm2tuvVultureGiantXpValue() != 36
            || mm2tuvVultureGiantXpLevel() != 1
            || mm2tuvVultureArrivalMinRounds() != 7
            || mm2tuvVultureArrivalMaxRounds() != 12
            || mm2tuvVulturePeckingFeet() != 20
            || mm2tuvVulturePeckersMin() != 1
            || mm2tuvVulturePeckersMax() != 6
            || mm2tuvVultureGiantWingspreadFeet() != 12
            || mm2tuvVultureOrdinaryXpValue() != 35
            || mm2tuvVultureOrdinaryXpLevel() != 2
            || mm2tuvVultureOrdinaryWingspreadMinFeet() != 5
            || mm2tuvVultureOrdinaryWingspreadMaxFeet() != 6
            || !mm2tuvTarrasqueFireImmune()
            || !mm2tuvTarrasqueReflectsRays()
            || !mm2tuvTarrasqueMagicWeaponToHit()
            || !mm2tuvTasloiInfravision()
            || !mm2tuvTasloiArboreal()
            || !mm2tuvTermiteNocturnal()
            || !mm2tuvTermiteFormianEnemies()
            || !mm2tuvTermiteSoldierSpitBlinds()
            || !mm2tuvTermiteSoldierSpitFlammable()
            || !mm2tuvTermiteKingDoubleSpit()
            || !mm2tuvTermiteQueenEggCountMatches()
            || !mm2tuvThessalhydraAcidImmune()
            || !mm2tuvThessalhydraFringeIsolated()
            || !mm2tuvThriKreenWedgeReturns()
            || !mm2tuvThriKreenFourClaws()
            || !mm2tuvThunderBeastFogBreath()
            || !mm2tuvThunderBeastYoungHarmless()
            || !mm2tuvTimeElementalTimeStop()
            || !mm2tuvTimeElementalUnsummonable()
            || !mm2tuvThunderherderTremors()
            || !mm2tuvThunderherderNonaggressive()
            || !mm2tuvTransposerHealingHarms()
            || !mm2tuvTransposerSelfIllusion()
            || !mm2tuvTriFlowerImmersionCures()
            || !mm2tuvTriFlowerSlumberPollen()
            || !mm2tuvScragGilled()
            || !mm2tuvScragFreshRegenerates()
            || !mm2tuvScragSaltRegenerates()
            || !mm2tuvTwilightBloomSapDeadly()
            || !mm2tuvTwilightBloomPerfumeLure()
            || !mm2tuvUrchinSpinesParalyze()
            || !mm2tuvUrchinSmokeEscape()
            || !mm2tuvUstilagorMindless()
            || !mm2tuvUstilagorPsionic()
            || !mm2tuvVagabondMindImmune()
            || !mm2tuvVagabondFormFixed()
            || !mm2tuvVargouillePermanentDrain()
            || !mm2tuvVargouilleHatesLight()
            || !mm2tuvVegepygmyElectricImmune()
            || !mm2tuvVegepygmyCharmImmune()
            || !mm2tuvVermeSwallowsWhole()
            || !mm2tuvVermeEdgedUseless()
            || !mm2tuvVermeFireHalf()
            || !mm2tuvVilstrakMergesWithStone()
            || !mm2tuvVilstrakSurpriseOneToFour()
            || !mm2tuvVulchlingConsortsWithHarpies()
            || !mm2tuvVulchlingTalonSwoop()
            || !mm2tuvVultureGiantStruckToDeter()
            || !mm2tuvVultureOrdinaryWaitsForWeakness()
        )
            ++bad;
        // THE TUV-GRID: the 26-row TUVStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the twenty-six promoted letters TUV stat
        // blocks, in print order - the tarrasque p. 117 through the ordinary
        // vulture p. 125)
        int CTUVStats[26][10] = {
            {-3,0,0,300,6,37500,0,0,9,0},
            {6,1,0,3,2,10,1,30,9,0},
            {2,1,2,5,1,20,2,20,9,0},
            {2,2,2,9,1,50,3,20,9,0},
            {5,6,6,27,1,500,10,20,6,0},
            {4,8,8,36,1,900,13,20,3,0},
            {0,12,0,42,10,5800,16,50,12,0},
            {5,6,3,24,5,800,8,5,18,0},
            {4,4,1,15,1,650,10,0,9,0},
            {2,12,0,42,1,3000,20,0,1,0},
            {3,7,0,24,1,350,8,5,20,0},
            {7,6,0,21,2,625,7,0,15,0},
            {9,2,8,15,1,120,3,0,0,0},
            {3,5,5,22,3,400,8,20,3,0},
            {2,6,12,33,3,900,12,15,3,0},
            {8,3,8,18,1,125,4,0,0,0},
            {3,3,3,13,10,150,4,0,12,0},
            {5,3,3,13,1,135,4,90,9,0},
            {9,0,0,0,1,0,0,0,0,0},
            {8,1,1,4,1,118,2,80,12,0},
            {4,1,0,3,1,53,1,40,12,0},
            {3,18,18,81,1,8550,25,0,18,0},
            {2,0,0,6,2,7,1,5,9,0},
            {7,1,0,3,2,10,1,25,6,0},
            {7,2,1,8,1,20,2,0,3,0},
            {6,1,1,4,1,35,0,0,3,0},
            };
        for (int b = 0;
             b < mm2tuvTUVStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2tuvTUVStatAc(b);
            vals[1] = mm2tuvTUVStatHd(b);
            vals[2] = mm2tuvTUVStatHdBonus(b);
            vals[3] = mm2tuvTUVStatAvgHp(b);
            vals[4] = mm2tuvTUVStatAttacks(b);
            vals[5] = mm2tuvTUVStatXp(b);
            vals[6] = mm2tuvTUVStatXpHp(b);
            vals[7] = mm2tuvTUVStatLairPct(b);
            vals[8] = mm2tuvTUVStatMove(b);
            vals[9] = mm2tuvTUVStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CTUVStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the Letter T, U and
        // V gap boxes flip (the census walk)
    if (mm2tuvRegistryAfter() - mm2tuvRegistryBefore() != mm2tuvDefCount()
            || mm2tuvDefCount() != 26
            || mm2tuvEntryCount() != 21
            || mm2tuvStatBlockHeadings() != 22
            || mm2tuvDoctrineHeads() != 0
            || mm2tuvLetterTUVHeadings() != 21
            || mm2tuvTUVStatRows() != 26
            || mm2tuvGapClosed() != 27
            || mm2tuvGapOpen() != 10
            || mm2tuvPriorOwnedEntries() != 0
        )
            ++bad;
        // the tarrasque grid row (p. 117 print order)
    if (mm2tuvTUVStatAc(0) != -3
            || mm2tuvTUVStatHd(0) != 0
            || mm2tuvTUVStatHdBonus(0) != 0
            || mm2tuvTUVStatAvgHp(0) != 300
            || mm2tuvTUVStatAttacks(0) != 6
            || mm2tuvTUVStatXp(0) != 37500
            || mm2tuvTUVStatXpHp(0) != 0
            || mm2tuvTUVStatLairPct(0) != 0
            || mm2tuvTUVStatMove(0) != 9
            || mm2tuvTUVStatMr(0) != 0
            || mm2tuvTarrasqueXpValue() != 37500
            || mm2tuvTarrasqueXpLevel() != 10
        )
            ++bad;
        // the tasloi grid row (p. 118 print order)
    if (mm2tuvTUVStatAc(1) != 6
            || mm2tuvTUVStatHd(1) != 1
            || mm2tuvTUVStatHdBonus(1) != 0
            || mm2tuvTUVStatAvgHp(1) != 3
            || mm2tuvTUVStatAttacks(1) != 2
            || mm2tuvTUVStatXp(1) != 10
            || mm2tuvTUVStatXpHp(1) != 1
            || mm2tuvTUVStatLairPct(1) != 30
            || mm2tuvTUVStatMove(1) != 9
            || mm2tuvTUVStatMr(1) != 0
            || mm2tuvTasloiXpValue() != 13
            || mm2tuvTasloiXpLevel() != 1
        )
            ++bad;
        // the termite, worker grid row (p. 118 print order)
    if (mm2tuvTUVStatAc(2) != 2
            || mm2tuvTUVStatHd(2) != 1
            || mm2tuvTUVStatHdBonus(2) != 2
            || mm2tuvTUVStatAvgHp(2) != 5
            || mm2tuvTUVStatAttacks(2) != 1
            || mm2tuvTUVStatXp(2) != 20
            || mm2tuvTUVStatXpHp(2) != 2
            || mm2tuvTUVStatLairPct(2) != 20
            || mm2tuvTUVStatMove(2) != 9
            || mm2tuvTUVStatMr(2) != 0
            || mm2tuvTermiteWorkerXpValue() != 30
            || mm2tuvTermiteWorkerXpLevel() != 1
        )
            ++bad;
        // the termite, soldier grid row (p. 118 print order)
    if (mm2tuvTUVStatAc(3) != 2
            || mm2tuvTUVStatHd(3) != 2
            || mm2tuvTUVStatHdBonus(3) != 2
            || mm2tuvTUVStatAvgHp(3) != 9
            || mm2tuvTUVStatAttacks(3) != 1
            || mm2tuvTUVStatXp(3) != 50
            || mm2tuvTUVStatXpHp(3) != 3
            || mm2tuvTUVStatLairPct(3) != 20
            || mm2tuvTUVStatMove(3) != 9
            || mm2tuvTUVStatMr(3) != 0
            || mm2tuvTermiteSoldierXpValue() != 77
            || mm2tuvTermiteSoldierXpLevel() != 2
        )
            ++bad;
        // the termite, king grid row (p. 119 print order)
    if (mm2tuvTUVStatAc(4) != 5
            || mm2tuvTUVStatHd(4) != 6
            || mm2tuvTUVStatHdBonus(4) != 6
            || mm2tuvTUVStatAvgHp(4) != 27
            || mm2tuvTUVStatAttacks(4) != 1
            || mm2tuvTUVStatXp(4) != 500
            || mm2tuvTUVStatXpHp(4) != 10
            || mm2tuvTUVStatLairPct(4) != 20
            || mm2tuvTUVStatMove(4) != 6
            || mm2tuvTUVStatMr(4) != 0
            || mm2tuvTermiteKingXpValue() != 770
            || mm2tuvTermiteKingXpLevel() != 5
        )
            ++bad;
        // the termite, queen grid row (p. 119 print order)
    if (mm2tuvTUVStatAc(5) != 4
            || mm2tuvTUVStatHd(5) != 8
            || mm2tuvTUVStatHdBonus(5) != 8
            || mm2tuvTUVStatAvgHp(5) != 36
            || mm2tuvTUVStatAttacks(5) != 1
            || mm2tuvTUVStatXp(5) != 900
            || mm2tuvTUVStatXpHp(5) != 13
            || mm2tuvTUVStatLairPct(5) != 20
            || mm2tuvTUVStatMove(5) != 3
            || mm2tuvTUVStatMr(5) != 0
            || mm2tuvTermiteQueenXpValue() != 1368
            || mm2tuvTermiteQueenXpLevel() != 6
        )
            ++bad;
        // the thessalhydra grid row (p. 119 print order)
    if (mm2tuvTUVStatAc(6) != 0
            || mm2tuvTUVStatHd(6) != 12
            || mm2tuvTUVStatHdBonus(6) != 0
            || mm2tuvTUVStatAvgHp(6) != 42
            || mm2tuvTUVStatAttacks(6) != 10
            || mm2tuvTUVStatXp(6) != 5800
            || mm2tuvTUVStatXpHp(6) != 16
            || mm2tuvTUVStatLairPct(6) != 50
            || mm2tuvTUVStatMove(6) != 12
            || mm2tuvTUVStatMr(6) != 0
            || mm2tuvThessalhydraXpValue() != 6472
            || mm2tuvThessalhydraXpLevel() != 9
        )
            ++bad;
        // the thri-kreen (mantis warrior) grid row (p. 119 print order)
    if (mm2tuvTUVStatAc(7) != 5
            || mm2tuvTUVStatHd(7) != 6
            || mm2tuvTUVStatHdBonus(7) != 3
            || mm2tuvTUVStatAvgHp(7) != 24
            || mm2tuvTUVStatAttacks(7) != 5
            || mm2tuvTUVStatXp(7) != 800
            || mm2tuvTUVStatXpHp(7) != 8
            || mm2tuvTUVStatLairPct(7) != 5
            || mm2tuvTUVStatMove(7) != 18
            || mm2tuvTUVStatMr(7) != 0
            || mm2tuvThriKreenXpValue() != 992
            || mm2tuvThriKreenXpLevel() != 6
        )
            ++bad;
        // the thunder beast grid row (p. 119 print order)
    if (mm2tuvTUVStatAc(8) != 4
            || mm2tuvTUVStatHd(8) != 4
            || mm2tuvTUVStatHdBonus(8) != 1
            || mm2tuvTUVStatAvgHp(8) != 15
            || mm2tuvTUVStatAttacks(8) != 1
            || mm2tuvTUVStatXp(8) != 650
            || mm2tuvTUVStatXpHp(8) != 10
            || mm2tuvTUVStatLairPct(8) != 0
            || mm2tuvTUVStatMove(8) != 9
            || mm2tuvTUVStatMr(8) != 0
            || mm2tuvThunderBeastXpValue() != 800
            || mm2tuvThunderBeastXpLevel() != 6
        )
            ++bad;
        // the time elemental grid row (p. 119 print order)
    if (mm2tuvTUVStatAc(9) != 2
            || mm2tuvTUVStatHd(9) != 12
            || mm2tuvTUVStatHdBonus(9) != 0
            || mm2tuvTUVStatAvgHp(9) != 42
            || mm2tuvTUVStatAttacks(9) != 1
            || mm2tuvTUVStatXp(9) != 3000
            || mm2tuvTUVStatXpHp(9) != 20
            || mm2tuvTUVStatLairPct(9) != 0
            || mm2tuvTUVStatMove(9) != 1
            || mm2tuvTUVStatMr(9) != 0
            || mm2tuvTimeElementalXpValue() != 3840
            || mm2tuvTimeElementalXpLevel() != 7
        )
            ++bad;
        // the thunderherder grid row (p. 120 print order)
    if (mm2tuvTUVStatAc(10) != 3
            || mm2tuvTUVStatHd(10) != 7
            || mm2tuvTUVStatHdBonus(10) != 0
            || mm2tuvTUVStatAvgHp(10) != 24
            || mm2tuvTUVStatAttacks(10) != 1
            || mm2tuvTUVStatXp(10) != 350
            || mm2tuvTUVStatXpHp(10) != 8
            || mm2tuvTUVStatLairPct(10) != 5
            || mm2tuvTUVStatMove(10) != 20
            || mm2tuvTUVStatMr(10) != 0
            || mm2tuvThunderherderXpValue() != 542
            || mm2tuvThunderherderXpLevel() != 5
        )
            ++bad;
        // the transposer grid row (p. 120 print order)
    if (mm2tuvTUVStatAc(11) != 7
            || mm2tuvTUVStatHd(11) != 6
            || mm2tuvTUVStatHdBonus(11) != 0
            || mm2tuvTUVStatAvgHp(11) != 21
            || mm2tuvTUVStatAttacks(11) != 2
            || mm2tuvTUVStatXp(11) != 625
            || mm2tuvTUVStatXpHp(11) != 7
            || mm2tuvTUVStatLairPct(11) != 0
            || mm2tuvTUVStatMove(11) != 15
            || mm2tuvTUVStatMr(11) != 0
            || mm2tuvTransposerXpValue() != 772
            || mm2tuvTransposerXpLevel() != 6
        )
            ++bad;
        // the tri-flower frond grid row (p. 121 print order)
    if (mm2tuvTUVStatAc(12) != 9
            || mm2tuvTUVStatHd(12) != 2
            || mm2tuvTUVStatHdBonus(12) != 8
            || mm2tuvTUVStatAvgHp(12) != 15
            || mm2tuvTUVStatAttacks(12) != 1
            || mm2tuvTUVStatXp(12) != 120
            || mm2tuvTUVStatXpHp(12) != 3
            || mm2tuvTUVStatLairPct(12) != 0
            || mm2tuvTUVStatMove(12) != 0
            || mm2tuvTUVStatMr(12) != 0
            || mm2tuvTriFlowerXpValue() != 165
            || mm2tuvTriFlowerXpLevel() != 3
        )
            ++bad;
        // the scrag, freshwater grid row (p. 121 print order)
    if (mm2tuvTUVStatAc(13) != 3
            || mm2tuvTUVStatHd(13) != 5
            || mm2tuvTUVStatHdBonus(13) != 5
            || mm2tuvTUVStatAvgHp(13) != 22
            || mm2tuvTUVStatAttacks(13) != 3
            || mm2tuvTUVStatXp(13) != 400
            || mm2tuvTUVStatXpHp(13) != 8
            || mm2tuvTUVStatLairPct(13) != 20
            || mm2tuvTUVStatMove(13) != 3
            || mm2tuvTUVStatMr(13) != 0
            || mm2tuvScragFreshwaterXpValue() != 576
            || mm2tuvScragFreshwaterXpLevel() != 5
        )
            ++bad;
        // the scrag, saltwater grid row (p. 121 print order)
    if (mm2tuvTUVStatAc(14) != 2
            || mm2tuvTUVStatHd(14) != 6
            || mm2tuvTUVStatHdBonus(14) != 12
            || mm2tuvTUVStatAvgHp(14) != 33
            || mm2tuvTUVStatAttacks(14) != 3
            || mm2tuvTUVStatXp(14) != 900
            || mm2tuvTUVStatXpHp(14) != 12
            || mm2tuvTUVStatLairPct(14) != 15
            || mm2tuvTUVStatMove(14) != 3
            || mm2tuvTUVStatMr(14) != 0
            || mm2tuvScragSaltwaterXpValue() != 1296
            || mm2tuvScragSaltwaterXpLevel() != 6
        )
            ++bad;
        // the twilight bloom (purple death) grid row (p. 122 print order)
    if (mm2tuvTUVStatAc(15) != 8
            || mm2tuvTUVStatHd(15) != 3
            || mm2tuvTUVStatHdBonus(15) != 8
            || mm2tuvTUVStatAvgHp(15) != 18
            || mm2tuvTUVStatAttacks(15) != 1
            || mm2tuvTUVStatXp(15) != 125
            || mm2tuvTUVStatXpHp(15) != 4
            || mm2tuvTUVStatLairPct(15) != 0
            || mm2tuvTUVStatMove(15) != 0
            || mm2tuvTUVStatMr(15) != 0
            || mm2tuvTwilightBloomXpValue() != 197
            || mm2tuvTwilightBloomXpLevel() != 3
        )
            ++bad;
        // the urchin, land grid row (p. 122 print order)
    if (mm2tuvTUVStatAc(16) != 3
            || mm2tuvTUVStatHd(16) != 3
            || mm2tuvTUVStatHdBonus(16) != 3
            || mm2tuvTUVStatAvgHp(16) != 13
            || mm2tuvTUVStatAttacks(16) != 10
            || mm2tuvTUVStatXp(16) != 150
            || mm2tuvTUVStatXpHp(16) != 4
            || mm2tuvTUVStatLairPct(16) != 0
            || mm2tuvTUVStatMove(16) != 12
            || mm2tuvTUVStatMr(16) != 0
            || mm2tuvUrchinLandXpValue() != 202
            || mm2tuvUrchinLandXpLevel() != 3
        )
            ++bad;
        // the ustilagor grid row (p. 122 print order)
    if (mm2tuvTUVStatAc(17) != 5
            || mm2tuvTUVStatHd(17) != 3
            || mm2tuvTUVStatHdBonus(17) != 3
            || mm2tuvTUVStatAvgHp(17) != 13
            || mm2tuvTUVStatAttacks(17) != 1
            || mm2tuvTUVStatXp(17) != 135
            || mm2tuvTUVStatXpHp(17) != 4
            || mm2tuvTUVStatLairPct(17) != 90
            || mm2tuvTUVStatMove(17) != 9
            || mm2tuvTUVStatMr(17) != 0
            || mm2tuvUstilagorXpValue() != 187
            || mm2tuvUstilagorXpLevel() != 3
        )
            ++bad;
        // the vagabond grid row (p. 122 print order)
    if (mm2tuvTUVStatAc(18) != 9
            || mm2tuvTUVStatHd(18) != 0
            || mm2tuvTUVStatHdBonus(18) != 0
            || mm2tuvTUVStatAvgHp(18) != 0
            || mm2tuvTUVStatAttacks(18) != 1
            || mm2tuvTUVStatXp(18) != 0
            || mm2tuvTUVStatXpHp(18) != 0
            || mm2tuvTUVStatLairPct(18) != 0
            || mm2tuvTUVStatMove(18) != 0
            || mm2tuvTUVStatMr(18) != 0
            || mm2tuvVagabondXpValue() != 0
            || mm2tuvVagabondXpLevel() != 0
        )
            ++bad;
        // the vargouille grid row (p. 123 print order)
    if (mm2tuvTUVStatAc(19) != 8
            || mm2tuvTUVStatHd(19) != 1
            || mm2tuvTUVStatHdBonus(19) != 1
            || mm2tuvTUVStatAvgHp(19) != 4
            || mm2tuvTUVStatAttacks(19) != 1
            || mm2tuvTUVStatXp(19) != 118
            || mm2tuvTUVStatXpHp(19) != 2
            || mm2tuvTUVStatLairPct(19) != 80
            || mm2tuvTUVStatMove(19) != 12
            || mm2tuvTUVStatMr(19) != 0
            || mm2tuvVargouilleXpValue() != 126
            || mm2tuvVargouilleXpLevel() != 3
        )
            ++bad;
        // the vegepygmy grid row (p. 124 print order)
    if (mm2tuvTUVStatAc(20) != 4
            || mm2tuvTUVStatHd(20) != 1
            || mm2tuvTUVStatHdBonus(20) != 0
            || mm2tuvTUVStatAvgHp(20) != 3
            || mm2tuvTUVStatAttacks(20) != 1
            || mm2tuvTUVStatXp(20) != 53
            || mm2tuvTUVStatXpHp(20) != 1
            || mm2tuvTUVStatLairPct(20) != 40
            || mm2tuvTUVStatMove(20) != 12
            || mm2tuvTUVStatMr(20) != 0
            || mm2tuvVegepygmyXpValue() != 56
            || mm2tuvVegepygmyXpLevel() != 3
        )
            ++bad;
        // the verme grid row (p. 124 print order)
    if (mm2tuvTUVStatAc(21) != 3
            || mm2tuvTUVStatHd(21) != 18
            || mm2tuvTUVStatHdBonus(21) != 18
            || mm2tuvTUVStatAvgHp(21) != 81
            || mm2tuvTUVStatAttacks(21) != 1
            || mm2tuvTUVStatXp(21) != 8550
            || mm2tuvTUVStatXpHp(21) != 25
            || mm2tuvTUVStatLairPct(21) != 0
            || mm2tuvTUVStatMove(21) != 18
            || mm2tuvTUVStatMr(21) != 0
            || mm2tuvVermeXpValue() != 10575
            || mm2tuvVermeXpLevel() != 9
        )
            ++bad;
        // the vilstrak (marl mugger, tunnel thug) grid row (p. 124 print
        // order)
    if (mm2tuvTUVStatAc(22) != 2
            || mm2tuvTUVStatHd(22) != 0
            || mm2tuvTUVStatHdBonus(22) != 0
            || mm2tuvTUVStatAvgHp(22) != 6
            || mm2tuvTUVStatAttacks(22) != 2
            || mm2tuvTUVStatXp(22) != 7
            || mm2tuvTUVStatXpHp(22) != 1
            || mm2tuvTUVStatLairPct(22) != 5
            || mm2tuvTUVStatMove(22) != 9
            || mm2tuvTUVStatMr(22) != 0
            || mm2tuvVilstrakXpValue() != 13
            || mm2tuvVilstrakXpLevel() != 1
        )
            ++bad;
        // the vulchling grid row (p. 125 print order)
    if (mm2tuvTUVStatAc(23) != 7
            || mm2tuvTUVStatHd(23) != 1
            || mm2tuvTUVStatHdBonus(23) != 0
            || mm2tuvTUVStatAvgHp(23) != 3
            || mm2tuvTUVStatAttacks(23) != 2
            || mm2tuvTUVStatXp(23) != 10
            || mm2tuvTUVStatXpHp(23) != 1
            || mm2tuvTUVStatLairPct(23) != 25
            || mm2tuvTUVStatMove(23) != 6
            || mm2tuvTUVStatMr(23) != 0
            || mm2tuvVulchlingXpValue() != 13
            || mm2tuvVulchlingXpLevel() != 1
        )
            ++bad;
        // the vulture, giant grid row (p. 125 print order)
    if (mm2tuvTUVStatAc(24) != 7
            || mm2tuvTUVStatHd(24) != 2
            || mm2tuvTUVStatHdBonus(24) != 1
            || mm2tuvTUVStatAvgHp(24) != 8
            || mm2tuvTUVStatAttacks(24) != 1
            || mm2tuvTUVStatXp(24) != 20
            || mm2tuvTUVStatXpHp(24) != 2
            || mm2tuvTUVStatLairPct(24) != 0
            || mm2tuvTUVStatMove(24) != 3
            || mm2tuvTUVStatMr(24) != 0
            || mm2tuvVultureGiantXpValue() != 36
            || mm2tuvVultureGiantXpLevel() != 1
        )
            ++bad;
        // the vulture, ordinary grid row (p. 125 print order)
    if (mm2tuvTUVStatAc(25) != 6
            || mm2tuvTUVStatHd(25) != 1
            || mm2tuvTUVStatHdBonus(25) != 1
            || mm2tuvTUVStatAvgHp(25) != 4
            || mm2tuvTUVStatAttacks(25) != 1
            || mm2tuvTUVStatXp(25) != 35
            || mm2tuvTUVStatXpHp(25) != 0
            || mm2tuvTUVStatLairPct(25) != 0
            || mm2tuvTUVStatMove(25) != 3
            || mm2tuvTUVStatMr(25) != 0
            || mm2tuvVultureOrdinaryXpValue() != 35
            || mm2tuvVultureOrdinaryXpLevel() != 2
        )
            ++bad;
        printf("R814 MM2 letters TUV walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
