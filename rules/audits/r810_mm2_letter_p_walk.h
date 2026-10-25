    // ---- R810 MM2 letter P walk audit ----
    // THE MM2 LETTER P WALK - the para-elemental family (the ice, smoke,
    // magma and ooze forms) on pp. 98-99, the pech p. 99, the pedipalp
    // variant table (the large schizomida, the huge amblypygus and the giant
    // uropygus), the phantom, the phoenix and the phycomid pp. 100-101, the
    // planetar pp. 101-102, the pseudo-undead and the deadly pudding variant
    // table (the brown, the dun and the white) p. 102, the pyrolisk p. 103;
    // the P-FLIP round: the Letter P gap box flips to closed (21 closed, 16
    // open). SEVENTEEN .lua defs ride the R791 data_files extension, registry
    // 706 -> 723. The PStats 17x10 grid cross-checks every armor class, hit
    // dice, bonus, avgHp, attack, xp, xp/hp, lair, move and magic-resistance
    // cell; the per-def doctrine pins carry the settled reads (the
    // para-elemental 8, 12, or 16 first-number read, the summoning doctrine
    // riding as consts - the R808 lycanthrope family-head precedent, the
    // pyrolisk 4+3 the capture 43 OCR artifact settle, the magma druidic heat
    // metal the capture drastic settle, the planetar flat-hp 144 read, the
    // phantom Nil block, the pudding brown VIII the transcription VII
    // variance kept verbatim per print, the ooze +7 or better weapons to hit
    // kept verbatim per print against the +1 transcription variance, the
    // loader max/floor attack semantics)
    {
        using namespace rules;
        int bad = 0;
    if (mm2pRound() != 810
            || mm2pRegistryBefore() != 706
            || mm2pRegistryAfter() != 723
            || mm2pDefCount() != 17
            || mm2pEntryCount() != 10
            || mm2pStatBlockHeadings() != 17
            || mm2pDoctrineHeads() != 1
            || mm2pLetterPHeadings() != 10
            || mm2pPStatRows() != 17
            || mm2pGapClosed() != 21
            || mm2pGapOpen() != 16
            || mm2pPriorOwnedEntries() != 0
            || mm2pParaIceXpValue() != 3270
            || mm2pParaIceXpLevel() != 7
            || mm2pParaSmokeXpValue() != 3270
            || mm2pParaSmokeXpLevel() != 7
            || mm2pParaMagmaXpValue() != 3270
            || mm2pParaMagmaXpLevel() != 7
            || mm2pParaOozeXpValue() != 3270
            || mm2pParaOozeXpLevel() != 7
            || mm2pPechXpValue() != 296
            || mm2pPechXpLevel() != 4
            || mm2pPedipalpLargeXpValue() != 28
            || mm2pPedipalpLargeXpLevel() != 1
            || mm2pPedipalpHugeXpValue() != 77
            || mm2pPedipalpHugeXpLevel() != 2
            || mm2pPedipalpGiantXpValue() != 260
            || mm2pPedipalpGiantXpLevel() != 4
            || mm2pPhantomXpValue() != 0
            || mm2pPhantomXpLevel() != 0
            || mm2pPhoenixXpValue() != 10700
            || mm2pPhoenixXpLevel() != 9
            || mm2pPhycomidXpValue() != 350
            || mm2pPhycomidXpLevel() != 5
            || mm2pPlanetarXpValue() != 65040
            || mm2pPlanetarXpLevel() != 10
            || mm2pPseudoundeadXpValue() != 0
            || mm2pPseudoundeadXpLevel() != 0
            || mm2pPuddingBrownXpValue() != 2208
            || mm2pPuddingBrownXpLevel() != 8
            || mm2pPuddingDunXpValue() != 1348
            || mm2pPuddingDunXpLevel() != 8
            || mm2pPuddingWhiteXpValue() != 1572
            || mm2pPuddingWhiteXpLevel() != 8
            || mm2pPyroliskXpValue() != 325
            || mm2pPyroliskXpLevel() != 4
            || mm2pParaElementalPlaneCount() != 4
            || mm2pParaElementalHdCategories() != 3
            || mm2pParaElementalSpellHd() != 16
            || mm2pParaElementalDeviceHd() != 12
            || mm2pParaElementalStaffHd() != 8
            || mm2pParaElementalEscapePctBase() != 100
            || mm2pParaElementalEscapePctPerLevel() != 5
            || mm2pParaElementalWeaponFloor() != 1
            || mm2pParaElementalHdlessFloor() != 4
            || mm2pParaIceColdAuraFeet() != 10
            || mm2pParaIceColdAuraDamageMin() != 1
            || mm2pParaIceColdAuraDamageMax() != 4
            || mm2pParaIceFreezeAreaSqFt() != 100
            || mm2pParaIceFreezeDepthInches() != 6
            || mm2pParaIceHealPerRoundMin() != 1
            || mm2pParaIceHealPerRoundMax() != 8
            || mm2pParaSmokeEngageRadiusFeet() != 10
            || mm2pParaSmokeBlindHitPenalty() != 2
            || mm2pParaMagmaHeatRadiusFeet() != 20
            || mm2pParaMagmaHotMetalRound2DamageMax() != 4
            || mm2pParaMagmaMetalRound3DamageMin() != 2
            || mm2pParaMagmaMetalRound3DamageMax() != 8
            || mm2pParaMagmaNonmetalRound3DamageMax() != 4
            || mm2pParaOozeConstrictDamageMin() != 2
            || mm2pParaOozeConstrictDamageMax() != 16
            || mm2pPechStoneShapePerDay() != 4
            || mm2pPechStoneTellPerDay() != 4
            || mm2pPechWallOfStoneGroupCount() != 4
            || mm2pPechWallOfStoneCasterLevel() != 16
            || mm2pPechStoneToFleshGroupCount() != 8
            || mm2pPechGroupSpellsPerDay() != 1
            || mm2pPechLairGemsMin() != 50
            || mm2pPechLairGemsMax() != 100
            || mm2pPechLairJewelryMin() != 5
            || mm2pPechLairJewelryMax() != 30
            || mm2pPechJewelryAvgWeightGp() != 150
            || mm2pPechYoungPctMin() != 20
            || mm2pPechYoungPctMax() != 50
            || mm2pPedipalpHugeCrushDamageMin() != 2
            || mm2pPedipalpHugeCrushDamageMax() != 12
            || mm2pPedipalpGiantAutoBiteDamageMax() != 8
            || mm2pPedipalpGiantCrushDamageMin() != 2
            || mm2pPedipalpGiantCrushDamageMax() != 16
            || mm2pPedipalpGiantGasRadiusFeet() != 20
            || mm2pPedipalpGiantGasToHitPenalty() != 3
            || mm2pPedipalpGiantGasDurationRoundsMin() != 1
            || mm2pPedipalpGiantGasDurationRoundsMax() != 6
            || mm2pPedipalpGiantGasUsesPerDay() != 3
            || mm2pPedipalpGiantSeverRollAbove() != 3
            || mm2pPhantomGazeSavePenalty() != 2
            || mm2pPhoenixWhistleRadiusFeet() != 30
            || mm2pPhoenixWhistleInitiativeBonus() != 3
            || mm2pPhoenixSpellLevel() != 20
            || mm2pPhoenixDispelMagicLevel() != 40
            || mm2pPhoenixExorciseLevel() != 40
            || mm2pPhoenixWingTouchesPerDay() != 2
            || mm2pPhoenixWeaponFloor() != 3
            || mm2pPhoenixInfravisionFeet() != 120
            || mm2pPhoenixEggHatchDays() != 20
            || mm2pPhoenixBloodSeedPerDamage() != 5
            || mm2pPhoenixFeatherGp() != 50
            || mm2pPhoenixBeakValueMultiplier() != 100
            || mm2pPhoenixProtectionRadiusFeet() != 10
            || mm2pPhycomidGlobRangeMinFeet() != 7
            || mm2pPhycomidGlobRangeMaxFeet() != 12
            || mm2pPhycomidInfectionOnsetRoundsMin() != 5
            || mm2pPhycomidInfectionOnsetRoundsMax() != 8
            || mm2pPhycomidInfectionDamageMin() != 5
            || mm2pPhycomidInfectionDamageMax() != 8
            || mm2pPhycomidHostDeathTurnsMin() != 5
            || mm2pPhycomidHostDeathTurnsMax() != 8
            || mm2pPhycomidFireSaveBonus() != 4
            || mm2pPlanetarSpiritGroupMin() != 100
            || mm2pPlanetarBastardSwordPlus() != 4
            || mm2pPlanetarDexterity() != 21
            || mm2pPlanetarFighterLevel() != 17
            || mm2pPlanetarWisdom() != 21
            || mm2pPlanetarClericLevel() != 7
            || mm2pPlanetarDruidLevel() != 7
            || mm2pPlanetarPsionic() != 288
            || mm2pPlanetarWeaponFloor() != 4
            || mm2pPlanetarRegenerationPerRound() != 4
            || mm2pPlanetarReformDecades() != 4
            || mm2pPlanetarGateUsesPerDay() != 1
            || mm2pPlanetarCharisma() != 21
            || mm2pPlanetarInfravisionInches() != 12
            || mm2pPlanetarProtectionRadiusFeet() != 40
            || mm2pPseudoundeadInfravisionInches() != 6
            || mm2pPseudoundeadLairPct() != 50
            || mm2pPuddingDunChainmailRounds() != 2
            || mm2pPuddingDunPlateRounds() != 4
            || mm2pPuddingWhiteSnowMistakePct() != 50
            || mm2pPyroliskGazeDamageMin() != 2
            || mm2pPyroliskGazeDamageMax() != 13
            || mm2pPyroliskFireworksRangeFeet() != 30
            || mm2pPyroliskFireworksAreaMultiplier() != 10
            || !mm2pParaElementalTurnsOnSummoner()
            || !mm2pParaIceFireDoubleDamage()
            || !mm2pParaIceColdUsersDamageDiceMinus1()
            || !mm2pParaSmokeFogDoubleDamage()
            || !mm2pParaSmokeAirAttacksDamageDiceMinus1()
            || !mm2pParaMagmaFlammablesIgnite()
            || !mm2pParaOozeConstrictsUntilReleased()
            || !mm2pParaOozeMutableForm()
            || !mm2pPechImmuneToPetrification()
            || !mm2pPechFullAttackVsLithicMonsters()
            || !mm2pPechHateBrightLight()
            || !mm2pPechFemalesEqualMales()
            || !mm2pPechInfraAndUltravision()
            || !mm2pPedipalpLargeCannotHoldLargerPrey()
            || !mm2pPedipalpHugeGripBreaksAsDoors()
            || !mm2pPedipalpGiantGripBreaksOnlyByKillOrSever()
            || !mm2pPhantomCannotBeHarmed()
            || !mm2pPhantomNotTurnedAsUndead()
            || !mm2pPhantomExorcismDispels()
            || !mm2pPhantomNeitherAliveNorUndead()
            || !mm2pPhoenixNeverSurprised()
            || !mm2pPhoenixEtherealAndAstralTravel()
            || !mm2pPhoenixDetectsCharmsEvilMagic()
            || !mm2pPhoenixCannotAttackOrBeAttackedPsionically()
            || !mm2pPhoenixCombActsAsStaffOfCuring()
            || !mm2pPhoenixSpeaksWithAllAvians()
            || !mm2pPhycomidImmuneToMentalAttacks()
            || !mm2pPhycomidFireHalfOrNone()
            || !mm2pPhycomidCureDiseaseStopsSpread()
            || !mm2pPlanetarNeverSurprised()
            || !mm2pPlanetarImmuneToLevelLoss()
            || !mm2pPlanetarImmuneToDeathSpells()
            || !mm2pPlanetarSoulsCannotBeTrapped()
            || !mm2pPlanetarCuresByTouch()
            || !mm2pPseudoundeadNotTurnedByCleric()
            || !mm2pPseudoundeadAvoidSunlightNotHarmed()
            || !mm2pPseudoundeadNeverNearTrueUndead()
            || !mm2pPseudoundeadGhastStench()
            || !mm2pPseudowraithWalksNotFlies()
            || !mm2pPseudovampireRedEyes()
            || !mm2pPuddingWeaponsDivideIt()
            || !mm2pPuddingAcidColdPoisonImmune()
            || !mm2pPuddingFireAndMagicMissileNormalDamage()
            || !mm2pPuddingBrownDoesNotDissolveMetal()
            || !mm2pPuddingWhiteDoesNotAffectMetal()
            || !mm2pPyroliskImmuneToFire()
            || !mm2pPyroliskMortalEnemyPhoenix()
            || !mm2pPyroliskSaveGrantsImmunity()
            || !mm2pPyroliskFireResistantImmuneToGaze()
        )
            ++bad;
        // THE P-GRID: the 17-row PStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the seventeen letter P stat blocks, in
        // print order - the para-elemental ice through the pyrolisk)
        int CPStats[17][10] = {
            {3,8,0,28,1,2850,15,0,6,0},
            {3,8,0,28,1,2850,15,0,6,0},
            {3,8,0,28,1,2850,15,0,6,0},
            {3,8,0,28,1,2850,15,0,36,0},
            {3,4,0,14,1,240,4,5,9,25},
            {7,1,1,4,1,20,2,5,12,0},
            {4,2,2,9,3,50,3,10,9,0},
            {2,4,4,18,3,170,5,20,6,0},
            {9,0,0,0,1,0,0,0,9,0},
            {-3,20,0,70,2,8600,30,0,6,50},
            {5,4,0,14,2,280,5,80,3,0},
            {-7,0,0,144,3,60000,35,0,15,75},
            {9,0,0,0,1,0,0,50,0,0},
            {5,11,0,38,1,1600,16,0,6,0},
            {7,8,1,29,1,1000,12,0,12,0},
            {8,9,0,31,1,1200,12,0,9,0},
            {6,4,3,17,1,240,5,30,6,0},
            };
        for (int b = 0;
             b < mm2pPStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2pPStatAc(b);
            vals[1] = mm2pPStatHd(b);
            vals[2] = mm2pPStatHdBonus(b);
            vals[3] = mm2pPStatAvgHp(b);
            vals[4] = mm2pPStatAttacks(b);
            vals[5] = mm2pPStatXp(b);
            vals[6] = mm2pPStatXpHp(b);
            vals[7] = mm2pPStatLairPct(b);
            vals[8] = mm2pPStatMove(b);
            vals[9] = mm2pPStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CPStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the Letter P gap
        // box flips (the census walk)
    if (mm2pRegistryAfter() - mm2pRegistryBefore() != mm2pDefCount()
            || mm2pDefCount() != 17
            || mm2pEntryCount() != 10
            || mm2pStatBlockHeadings() != 17
            || mm2pDoctrineHeads() != 1
            || mm2pLetterPHeadings() != 10
            || mm2pPStatRows() != 17
            || mm2pGapClosed() != 21
            || mm2pGapOpen() != 16
            || mm2pPriorOwnedEntries() != 0
        )
            ++bad;
        // the para-elemental ice grid row (pp. 98-103 print order)
    if (mm2pPStatAc(0) != 3
            || mm2pPStatHd(0) != 8
            || mm2pPStatHdBonus(0) != 0
            || mm2pPStatAvgHp(0) != 28
            || mm2pPStatAttacks(0) != 1
            || mm2pPStatXp(0) != 2850
            || mm2pPStatXpHp(0) != 15
            || mm2pPStatLairPct(0) != 0
            || mm2pPStatMove(0) != 6
            || mm2pPStatMr(0) != 0
            || mm2pParaIceXpValue() != 3270
            || mm2pParaIceXpLevel() != 7
        )
            ++bad;
        // the para-elemental smoke grid row (pp. 98-103 print order)
    if (mm2pPStatAc(1) != 3
            || mm2pPStatHd(1) != 8
            || mm2pPStatHdBonus(1) != 0
            || mm2pPStatAvgHp(1) != 28
            || mm2pPStatAttacks(1) != 1
            || mm2pPStatXp(1) != 2850
            || mm2pPStatXpHp(1) != 15
            || mm2pPStatLairPct(1) != 0
            || mm2pPStatMove(1) != 6
            || mm2pPStatMr(1) != 0
            || mm2pParaSmokeXpValue() != 3270
            || mm2pParaSmokeXpLevel() != 7
        )
            ++bad;
        // the para-elemental magma grid row (pp. 98-103 print order)
    if (mm2pPStatAc(2) != 3
            || mm2pPStatHd(2) != 8
            || mm2pPStatHdBonus(2) != 0
            || mm2pPStatAvgHp(2) != 28
            || mm2pPStatAttacks(2) != 1
            || mm2pPStatXp(2) != 2850
            || mm2pPStatXpHp(2) != 15
            || mm2pPStatLairPct(2) != 0
            || mm2pPStatMove(2) != 6
            || mm2pPStatMr(2) != 0
            || mm2pParaMagmaXpValue() != 3270
            || mm2pParaMagmaXpLevel() != 7
        )
            ++bad;
        // the para-elemental ooze grid row (pp. 98-103 print order)
    if (mm2pPStatAc(3) != 3
            || mm2pPStatHd(3) != 8
            || mm2pPStatHdBonus(3) != 0
            || mm2pPStatAvgHp(3) != 28
            || mm2pPStatAttacks(3) != 1
            || mm2pPStatXp(3) != 2850
            || mm2pPStatXpHp(3) != 15
            || mm2pPStatLairPct(3) != 0
            || mm2pPStatMove(3) != 36
            || mm2pPStatMr(3) != 0
            || mm2pParaOozeXpValue() != 3270
            || mm2pParaOozeXpLevel() != 7
        )
            ++bad;
        // the pech grid row (pp. 98-103 print order)
    if (mm2pPStatAc(4) != 3
            || mm2pPStatHd(4) != 4
            || mm2pPStatHdBonus(4) != 0
            || mm2pPStatAvgHp(4) != 14
            || mm2pPStatAttacks(4) != 1
            || mm2pPStatXp(4) != 240
            || mm2pPStatXpHp(4) != 4
            || mm2pPStatLairPct(4) != 5
            || mm2pPStatMove(4) != 9
            || mm2pPStatMr(4) != 25
            || mm2pPechXpValue() != 296
            || mm2pPechXpLevel() != 4
        )
            ++bad;
        // the large pedipalp grid row (pp. 98-103 print order)
    if (mm2pPStatAc(5) != 7
            || mm2pPStatHd(5) != 1
            || mm2pPStatHdBonus(5) != 1
            || mm2pPStatAvgHp(5) != 4
            || mm2pPStatAttacks(5) != 1
            || mm2pPStatXp(5) != 20
            || mm2pPStatXpHp(5) != 2
            || mm2pPStatLairPct(5) != 5
            || mm2pPStatMove(5) != 12
            || mm2pPStatMr(5) != 0
            || mm2pPedipalpLargeXpValue() != 28
            || mm2pPedipalpLargeXpLevel() != 1
        )
            ++bad;
        // the huge pedipalp grid row (pp. 98-103 print order)
    if (mm2pPStatAc(6) != 4
            || mm2pPStatHd(6) != 2
            || mm2pPStatHdBonus(6) != 2
            || mm2pPStatAvgHp(6) != 9
            || mm2pPStatAttacks(6) != 3
            || mm2pPStatXp(6) != 50
            || mm2pPStatXpHp(6) != 3
            || mm2pPStatLairPct(6) != 10
            || mm2pPStatMove(6) != 9
            || mm2pPStatMr(6) != 0
            || mm2pPedipalpHugeXpValue() != 77
            || mm2pPedipalpHugeXpLevel() != 2
        )
            ++bad;
        // the giant pedipalp grid row (pp. 98-103 print order)
    if (mm2pPStatAc(7) != 2
            || mm2pPStatHd(7) != 4
            || mm2pPStatHdBonus(7) != 4
            || mm2pPStatAvgHp(7) != 18
            || mm2pPStatAttacks(7) != 3
            || mm2pPStatXp(7) != 170
            || mm2pPStatXpHp(7) != 5
            || mm2pPStatLairPct(7) != 20
            || mm2pPStatMove(7) != 6
            || mm2pPStatMr(7) != 0
            || mm2pPedipalpGiantXpValue() != 260
            || mm2pPedipalpGiantXpLevel() != 4
        )
            ++bad;
        // the phantom grid row (pp. 98-103 print order)
    if (mm2pPStatAc(8) != 9
            || mm2pPStatHd(8) != 0
            || mm2pPStatHdBonus(8) != 0
            || mm2pPStatAvgHp(8) != 0
            || mm2pPStatAttacks(8) != 1
            || mm2pPStatXp(8) != 0
            || mm2pPStatXpHp(8) != 0
            || mm2pPStatLairPct(8) != 0
            || mm2pPStatMove(8) != 9
            || mm2pPStatMr(8) != 0
            || mm2pPhantomXpValue() != 0
            || mm2pPhantomXpLevel() != 0
        )
            ++bad;
        // the phoenix grid row (pp. 98-103 print order)
    if (mm2pPStatAc(9) != -3
            || mm2pPStatHd(9) != 20
            || mm2pPStatHdBonus(9) != 0
            || mm2pPStatAvgHp(9) != 70
            || mm2pPStatAttacks(9) != 2
            || mm2pPStatXp(9) != 8600
            || mm2pPStatXpHp(9) != 30
            || mm2pPStatLairPct(9) != 0
            || mm2pPStatMove(9) != 6
            || mm2pPStatMr(9) != 50
            || mm2pPhoenixXpValue() != 10700
            || mm2pPhoenixXpLevel() != 9
        )
            ++bad;
        // the phycomid grid row (pp. 98-103 print order)
    if (mm2pPStatAc(10) != 5
            || mm2pPStatHd(10) != 4
            || mm2pPStatHdBonus(10) != 0
            || mm2pPStatAvgHp(10) != 14
            || mm2pPStatAttacks(10) != 2
            || mm2pPStatXp(10) != 280
            || mm2pPStatXpHp(10) != 5
            || mm2pPStatLairPct(10) != 80
            || mm2pPStatMove(10) != 3
            || mm2pPStatMr(10) != 0
            || mm2pPhycomidXpValue() != 350
            || mm2pPhycomidXpLevel() != 5
        )
            ++bad;
        // the planetar grid row (pp. 98-103 print order)
    if (mm2pPStatAc(11) != -7
            || mm2pPStatHd(11) != 0
            || mm2pPStatHdBonus(11) != 0
            || mm2pPStatAvgHp(11) != 144
            || mm2pPStatAttacks(11) != 3
            || mm2pPStatXp(11) != 60000
            || mm2pPStatXpHp(11) != 35
            || mm2pPStatLairPct(11) != 0
            || mm2pPStatMove(11) != 15
            || mm2pPStatMr(11) != 75
            || mm2pPlanetarXpValue() != 65040
            || mm2pPlanetarXpLevel() != 10
        )
            ++bad;
        // the pseudo-undead grid row (pp. 98-103 print order)
    if (mm2pPStatAc(12) != 9
            || mm2pPStatHd(12) != 0
            || mm2pPStatHdBonus(12) != 0
            || mm2pPStatAvgHp(12) != 0
            || mm2pPStatAttacks(12) != 1
            || mm2pPStatXp(12) != 0
            || mm2pPStatXpHp(12) != 0
            || mm2pPStatLairPct(12) != 50
            || mm2pPStatMove(12) != 0
            || mm2pPStatMr(12) != 0
            || mm2pPseudoundeadXpValue() != 0
            || mm2pPseudoundeadXpLevel() != 0
        )
            ++bad;
        // the brown pudding grid row (pp. 98-103 print order)
    if (mm2pPStatAc(13) != 5
            || mm2pPStatHd(13) != 11
            || mm2pPStatHdBonus(13) != 0
            || mm2pPStatAvgHp(13) != 38
            || mm2pPStatAttacks(13) != 1
            || mm2pPStatXp(13) != 1600
            || mm2pPStatXpHp(13) != 16
            || mm2pPStatLairPct(13) != 0
            || mm2pPStatMove(13) != 6
            || mm2pPStatMr(13) != 0
            || mm2pPuddingBrownXpValue() != 2208
            || mm2pPuddingBrownXpLevel() != 8
        )
            ++bad;
        // the dun pudding grid row (pp. 98-103 print order)
    if (mm2pPStatAc(14) != 7
            || mm2pPStatHd(14) != 8
            || mm2pPStatHdBonus(14) != 1
            || mm2pPStatAvgHp(14) != 29
            || mm2pPStatAttacks(14) != 1
            || mm2pPStatXp(14) != 1000
            || mm2pPStatXpHp(14) != 12
            || mm2pPStatLairPct(14) != 0
            || mm2pPStatMove(14) != 12
            || mm2pPStatMr(14) != 0
            || mm2pPuddingDunXpValue() != 1348
            || mm2pPuddingDunXpLevel() != 8
        )
            ++bad;
        // the white pudding grid row (pp. 98-103 print order)
    if (mm2pPStatAc(15) != 8
            || mm2pPStatHd(15) != 9
            || mm2pPStatHdBonus(15) != 0
            || mm2pPStatAvgHp(15) != 31
            || mm2pPStatAttacks(15) != 1
            || mm2pPStatXp(15) != 1200
            || mm2pPStatXpHp(15) != 12
            || mm2pPStatLairPct(15) != 0
            || mm2pPStatMove(15) != 9
            || mm2pPStatMr(15) != 0
            || mm2pPuddingWhiteXpValue() != 1572
            || mm2pPuddingWhiteXpLevel() != 8
        )
            ++bad;
        // the pyrolisk grid row (pp. 98-103 print order)
    if (mm2pPStatAc(16) != 6
            || mm2pPStatHd(16) != 4
            || mm2pPStatHdBonus(16) != 3
            || mm2pPStatAvgHp(16) != 17
            || mm2pPStatAttacks(16) != 1
            || mm2pPStatXp(16) != 240
            || mm2pPStatXpHp(16) != 5
            || mm2pPStatLairPct(16) != 30
            || mm2pPStatMove(16) != 6
            || mm2pPStatMr(16) != 0
            || mm2pPyroliskXpValue() != 325
            || mm2pPyroliskXpLevel() != 4
        )
            ++bad;
        // the xpValue formula (the base plus the per-hp times avgHp, every
        // def)
    if (mm2pParaIceXpValue() != mm2pPStatXp(0) + mm2pPStatAvgHp(0) *
        mm2pPStatXpHp(0)
            || mm2pParaSmokeXpValue() != mm2pPStatXp(1) + mm2pPStatAvgHp(1) *
            mm2pPStatXpHp(1)
            || mm2pParaMagmaXpValue() != mm2pPStatXp(2) + mm2pPStatAvgHp(2) *
            mm2pPStatXpHp(2)
            || mm2pParaOozeXpValue() != mm2pPStatXp(3) + mm2pPStatAvgHp(3) *
            mm2pPStatXpHp(3)
            || mm2pPechXpValue() != mm2pPStatXp(4) + mm2pPStatAvgHp(4) *
            mm2pPStatXpHp(4)
            || mm2pPedipalpLargeXpValue() != mm2pPStatXp(5) +
            mm2pPStatAvgHp(5) * mm2pPStatXpHp(5)
            || mm2pPedipalpHugeXpValue() != mm2pPStatXp(6) + mm2pPStatAvgHp(6)
            * mm2pPStatXpHp(6)
            || mm2pPedipalpGiantXpValue() != mm2pPStatXp(7) +
            mm2pPStatAvgHp(7) * mm2pPStatXpHp(7)
            || mm2pPhantomXpValue() != mm2pPStatXp(8) + mm2pPStatAvgHp(8) *
            mm2pPStatXpHp(8)
            || mm2pPhoenixXpValue() != mm2pPStatXp(9) + mm2pPStatAvgHp(9) *
            mm2pPStatXpHp(9)
            || mm2pPhycomidXpValue() != mm2pPStatXp(10) + mm2pPStatAvgHp(10) *
            mm2pPStatXpHp(10)
            || mm2pPlanetarXpValue() != mm2pPStatXp(11) + mm2pPStatAvgHp(11) *
            mm2pPStatXpHp(11)
            || mm2pPseudoundeadXpValue() != mm2pPStatXp(12) +
            mm2pPStatAvgHp(12) * mm2pPStatXpHp(12)
            || mm2pPuddingBrownXpValue() != mm2pPStatXp(13) +
            mm2pPStatAvgHp(13) * mm2pPStatXpHp(13)
            || mm2pPuddingDunXpValue() != mm2pPStatXp(14) + mm2pPStatAvgHp(14)
            * mm2pPStatXpHp(14)
            || mm2pPuddingWhiteXpValue() != mm2pPStatXp(15) +
            mm2pPStatAvgHp(15) * mm2pPStatXpHp(15)
            || mm2pPyroliskXpValue() != mm2pPStatXp(16) + mm2pPStatAvgHp(16) *
            mm2pPStatXpHp(16)
        )
            ++bad;
        // the avgHp formula (the floor of 3.5 x hit dice plus bonus, the
        // flat-hp phantom, planetar and pseudo-undead excluded - the doubling
        // form so the expr compiles as C++)
    if (mm2pPStatAvgHp(0) * 2 + mm2pPStatHd(0) % 2 != mm2pPStatHd(0) * 7 +
        mm2pPStatHdBonus(0) * 2
            || mm2pPStatAvgHp(1) * 2 + mm2pPStatHd(1) % 2 != mm2pPStatHd(1) *
            7 + mm2pPStatHdBonus(1) * 2
            || mm2pPStatAvgHp(2) * 2 + mm2pPStatHd(2) % 2 != mm2pPStatHd(2) *
            7 + mm2pPStatHdBonus(2) * 2
            || mm2pPStatAvgHp(3) * 2 + mm2pPStatHd(3) % 2 != mm2pPStatHd(3) *
            7 + mm2pPStatHdBonus(3) * 2
            || mm2pPStatAvgHp(4) * 2 + mm2pPStatHd(4) % 2 != mm2pPStatHd(4) *
            7 + mm2pPStatHdBonus(4) * 2
            || mm2pPStatAvgHp(5) * 2 + mm2pPStatHd(5) % 2 != mm2pPStatHd(5) *
            7 + mm2pPStatHdBonus(5) * 2
            || mm2pPStatAvgHp(6) * 2 + mm2pPStatHd(6) % 2 != mm2pPStatHd(6) *
            7 + mm2pPStatHdBonus(6) * 2
            || mm2pPStatAvgHp(7) * 2 + mm2pPStatHd(7) % 2 != mm2pPStatHd(7) *
            7 + mm2pPStatHdBonus(7) * 2
            || mm2pPStatAvgHp(9) * 2 + mm2pPStatHd(9) % 2 != mm2pPStatHd(9) *
            7 + mm2pPStatHdBonus(9) * 2
            || mm2pPStatAvgHp(10) * 2 + mm2pPStatHd(10) % 2 != mm2pPStatHd(10)
            * 7 + mm2pPStatHdBonus(10) * 2
            || mm2pPStatAvgHp(13) * 2 + mm2pPStatHd(13) % 2 != mm2pPStatHd(13)
            * 7 + mm2pPStatHdBonus(13) * 2
            || mm2pPStatAvgHp(14) * 2 + mm2pPStatHd(14) % 2 != mm2pPStatHd(14)
            * 7 + mm2pPStatHdBonus(14) * 2
            || mm2pPStatAvgHp(15) * 2 + mm2pPStatHd(15) % 2 != mm2pPStatHd(15)
            * 7 + mm2pPStatHdBonus(15) * 2
            || mm2pPStatAvgHp(16) * 2 + mm2pPStatHd(16) % 2 != mm2pPStatHd(16)
            * 7 + mm2pPStatHdBonus(16) * 2
        )
            ++bad;
        // the loader attack semantics (the Special and Nil floors, the 1
        // constrict read, the 1 or 2 max)
    if (mm2pPStatAttacks(1) != 1
            || mm2pPStatAttacks(3) != 1
            || mm2pPStatAttacks(8) != 1
            || mm2pPStatAttacks(9) != 2
            || mm2pPStatAttacks(12) != 1
        )
            ++bad;
        printf("R810 MM2 letter P walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
