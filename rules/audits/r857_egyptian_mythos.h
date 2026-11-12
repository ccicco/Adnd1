    // ---- R857 Egyptian mythos audit ----
    // THE EGYPTIAN MYTHOS - the D&DG walk round nine, print pp. 49-56:
    // twenty-one beings (Ra the sungod, Anhur, Anubis, Apep, Apshai, Bast,
    // Bes, the Flame Snake, Geb, Horus, Isis, Nephthys, Osiris, the Phoenix,
    // Ptah, Seker, Set, the Minions of Set, Shu, Tefnut, Thoth), the temple
    // and cleric-ladder doctrine, the true Ankh, and the 97-word hieroglyph
    // grid riding as a data file. Zero registry defs touched; the floor holds
    // at 995. The adjudications: the GEOMETRY SWAP of the Ra and Anhur
    // ability lines (the Termux psm-4 fold had them reversed; the IA
    // x-coordinates plus the +14 lance prose settled Ra as the S:20 line and
    // Anhur as the S:25(+7,+14)), Bast W:10 (the geometry word against the
    // Termux W:70), the psionic classes (the II words of Anubis, Bast, Ptah
    // and Set; the class I bars of Isis and Thoth; Osiris V; the eleven VI
    // readers), the foot-mark size decodes (Isis 5 foot 4, Seker and Thoth 6
    // foot 4), the MR 59 of Set and the MR 69 of Shu and Tefnut (both voices
    // agree on the odd print), and the flagged cells: the Horus 6 foot 2 size
    // and 15/15 move, the Nephthys twin size decode, the Minions size, the
    // Flame Snake xp line, and the hieroglyph AT word.
    {
        using namespace rules;
        int bad = 0;
    if (egpRound() != 857
            || egpPrintStart() != 49
            || egpPrintEnd() != 56
            || egpBeingCount() != 21
            || egpTableCount() != 4
            || egpChainCount() != 0
            || egpRegistryFloor() != 995
            || egpCbtRows() != 21
            || egpClsRows() != 21
            || egpAbiRows() != 21
            || egpRosRows() != 21
            || egpPlaneCount() != 12
            || egpPsiClassI() != 1
            || egpPsiClassII() != 2
            || egpPsiClassV() != 5
            || egpPsiClassVI() != 6
            || egpArtifactCount() != 2
            || egpLoreCultureYears() != 3000
            || egpLoreTemplePylons() != 2
            || egpLoreFemaleClericMax() != 9
            || egpLoreConsortLevel() != 11
            || egpAnkhLengthInches() != 12
            || egpAnkhPerPlane() != 7
            || egpHieroglyphWordCount() != 97
            || egpRaGalleyMove() != 24
            || egpRaGalleyFlameDamage() != 40
            || egpRaHeatRayCount() != 2
            || egpRaHeatRayRangeYards() != 500
            || egpRaHeatRayLo() != 4
            || egpRaHeatRayHi() != 40
            || egpAnhurLancePlus() != 5
            || egpAnhurLanceDmgLo() != 6
            || egpAnhurLanceDmgHi() != 60
            || egpAnhurLanceStrBonus() != 14
            || egpAnhurLanceUndeadRangeYards() != 50
            || egpAnhurScaleMailPlus() != 4
            || egpAnhurRewardPct() != 1
            || egpAnubisBiteDmgLo() != 3
            || egpAnubisBiteDmgHi() != 30
            || egpAnubisTombRobberyPct() != 5
            || egpAnubisConsecratedPct() != 10
            || egpAnubisIntercessionLevel() != 10
            || egpAnubisGemCost() != 50000
            || egpAnubisQuestPct() != 20
            || egpApepBiteDmgLo() != 3
            || egpApepBiteDmgHi() != 30
            || egpApepBiteSaveMod() != -4
            || egpApepBreathDmgLo() != 6
            || egpApepBreathDmgHi() != 60
            || egpApepConstrictLo() != 4
            || egpApepConstrictHi() != 24
            || egpApepXpValue() != 28350
            || egpApepLairPct() != 70
            || egpApepFlameSnakesLo() != 5
            || egpApepFlameSnakesHi() != 50
            || egpApshaiBiteDmgLo() != 6
            || egpApshaiBiteDmgHi() != 60
            || egpBastClawDmgLo() != 5
            || egpBastClawDmgHi() != 50
            || egpBastEvilSenseRangeYards() != 100
            || egpBastCatKillSeePct() != 2
            || egpBastChoicePct() != 5
            || egpBastShatterPct() != 75
            || egpBesSwordPlus() != 2
            || egpBesSwordDmgLo() != 4
            || egpBesSwordDmgHi() != 24
            || egpBesLuckStonePct() != 5
            || egpBesNaturalWeaponFloor() != 17
            || egpFlameSnakeBlastRangeInches() != 3
            || egpFlameSnakeBlastDamage() != 15
            || egpFlameSnakeBlastPerDay() != 5
            || egpFlameSnakeHD() != 1
            || egpFlameSnakeLairPct() != 80
            || egpFlameSnakeDmgLo() != 1
            || egpFlameSnakeDmgHi() != 2
            || egpFlameSnakeXpBase() != 745
            || egpFlameSnakeXpPerHp() != 1
            || egpGebFistDmgLo() != 6
            || egpGebFistDmgHi() != 60
            || egpGebElementalsLo() != 2
            || egpGebElementalsHi() != 12
            || egpGebCrownMonstersLo() != 2
            || egpGebCrownMonstersHi() != 8
            || egpGebStaffRegen() != 25
            || egpGebStaffDrainLevels() != 5
            || egpHorusSpearFeet() != 30
            || egpHorusSpearDmgLo() != 3
            || egpHorusSpearDmgHi() != 36
            || egpHorusSpearBonus() != 14
            || egpHorusSwordPlus() != 3
            || egpHorusSwordDmgLo() != 3
            || egpHorusSwordDmgHi() != 30
            || egpHorusWandFireDice() != 18
            || egpHorusAidPct() != 5
            || egpHorusAidedScores() != 19
            || egpIsisSpellLevel() != 20
            || egpIsisCharmPct() != 5
            || egpNephthysDeathRaySaveMod() != -6
            || egpNephthysDeathRayRangeInches() != 12
            || egpOsirisDmgLo() != 3
            || egpOsirisDmgHi() != 30
            || egpOsirisStrBonus() != 12
            || egpOsirisWishPct() != 5
            || egpPhoenixRegen() != 5
            || egpPhoenixHeatRangeYards() != 10
            || egpPhoenixHeatDamage() != 25
            || egpPhoenixAttackHd() != 12
            || egpPhoenixExplosionDmgLo() != 10
            || egpPhoenixExplosionDmgHi() != 100
            || egpPhoenixRebirthLo() != 3
            || egpPhoenixRebirthHi() != 18
            || egpPtahScepterDmgLo() != 1
            || egpPtahScepterDmgHi() != 100
            || egpPtahScepterStrBonus() != 9
            || egpPtahGazeSaveMod() != -6
            || egpPtahThetChargesLo() != 2
            || egpPtahThetChargesHi() != 12
            || egpPtahThetPct() != 5
            || egpPtahThetWorshiperBonus() != 5
            || egpPtahThetClericBonus() != 10
            || egpSekerHalberdDmgLo() != 3
            || egpSekerHalberdDmgHi() != 30
            || egpSekerHalberdBonus() != 14
            || egpSekerMacePlus() != 3
            || egpSekerMaceDmgLo() != 2
            || egpSekerMaceDmgHi() != 24
            || egpSekerShaftRangeYards() != 500
            || egpSetSpearPlus() != 4
            || egpSetSpearDmgLo() != 7
            || egpSetSpearDmgHi() != 70
            || egpSetMinionsLo() != 2
            || egpSetMinionsHi() != 20
            || egpSetMinionWeeks() != 12
            || egpSetWatchPct() != 5
            || egpMinionsHp() != 25
            || egpMinionsFightAsLevel() != 10
            || egpMinionsAppearingLo() != 1
            || egpMinionsAppearingHi() != 20
            || egpMinionsBiteLo() != 1
            || egpMinionsBiteHi() != 12
            || egpMinionsXpLevel() != 5
            || egpMinionsXpBase() != 500
            || egpShuScaleMailPlus() != 5
            || egpShuFlameDamage() != 25
            || egpShuElementalsLo() != 1
            || egpShuElementalsHi() != 10
            || egpShuHorusAidPct() != 75
            || egpTefnutBoltCount() != 2
            || egpTefnutBoltDamage() != 24
            || egpTefnutBoltRangeYards() != 1000
            || egpThothNegateRangeYards() != 100
            || egpThothBookCount() != 3
            || !egpDeitiesAged()
            || !egpOneMajorDeityPerCity()
            || !egpTempleRectangle()
            || !egpPylonsMarked()
            || !egpPublicHallNoImage()
            || !egpInnerSanctuaryBest()
            || !egpGardenBathing()
            || !egpDesecrationUseless()
            || !egpOfferingsPleasing()
            || !egpBelow4thServePeople()
            || !egp4thTo6thServeTemple()
            || !egpFemaleConsortRule()
            || !egpFemalesKeepRecords()
            || !egpWhiteClothingSin()
            || !egpMalesShaveHeads()
            || !egpDonateGoldToRise()
            || !egpAnkhCarriedByNileGods()
            || !egpAnkhRaisesTheDead()
            || !egpAnkhKillsNonDivineByFire()
            || !egpAnkhBrightBlue()
            || !egpAnkhNonMagicalHolySymbols()
            || !egpHieroglyphWordPictures()
            || !egpHieroglyphAlteredForms()
            || !egpHieroglyphArtistsDisagree()
            || !egpHieroglyphOnMapsAndScrolls()
            || !egpHieroglyphBookOfTheDead()
            || !egpRaSunGod()
            || !egpRaHawkHeaded()
            || !egpRaShapeChange()
            || !egpRaAntiMagicShell()
            || !egpRaLightOfDay()
            || !egpRaGalleySunBarge()
            || !egpRaGalleyUnaffectedByMagic()
            || !egpRaPantheonPeacemaker()
            || !egpAnhurGodOfWar()
            || !egpAnhurTallHuman()
            || !egpAnhurShapeChangeWhenOutnumbered()
            || !egpAnhurAbilityNegation()
            || !egpAnhurBattleSacrifices()
            || !egpAnhurFoeTwiceAsPowerful()
            || !egpAnhurGrantsExperienceLevel()
            || !egpAnubisGuardianOfTheDead()
            || !egpAnubisJackalHeaded()
            || !egpAnubisAnimateStatues()
            || !egpAnubisDoubleCharmMonster()
            || !egpAnubisBlinkDogTeleport()
            || !egpAnubisHatesThieves()
            || !egpAnubisSoulCollector()
            || !egpAnubisBitesToDeath()
            || !egpApepUnique()
            || !egpApepKingOfSerpents()
            || !egpApepOfTheAbyss()
            || !egpApepEnemyOfTheGods()
            || !egpApepEmbodimentOfChaoticEvil()
            || !egpApepPoisonSaveOrDie()
            || !egpApepBreathEveryOtherRound()
            || !egpApepAttacksAs16HDMonster()
            || !egpApepWeaponPlusNeeded()
            || !egpApshaiGodOfInsects()
            || !egpApshaiPrayingMantis()
            || !egpApshaiShapeChange()
            || !egpApshaiInsectPlague()
            || !egpApshaiControlInsects()
            || !egpApshaiNeverMisses()
            || !egpBastCatGoddess()
            || !egpBastEnemyOfSet()
            || !egpBastTeleportsInBattle()
            || !egpBastSensesEvil()
            || !egpBastProtectorOfCatKind()
            || !egpBastKillOrDevote()
            || !egpBastPriestSnakeBonuses()
            || !egpBastPriestNeverSummonSnakes()
            || !egpBastNeverSurprised()
            || !egpBesGodOfLuck()
            || !egpBesMountainDwarf()
            || !egpBesShapeChangeAid()
            || !egpBesFavorsGambles()
            || !egpBesGrantsLuckStone()
            || !egpBesSwordAlwaysHits()
            || !egpBesAlwaysMakesSaves()
            || !egpBesFightsInvisible()
            || !egpFlameSnakeRare()
            || !egpFlameSnakeEnemyOfTheGods()
            || !egpFlameSnakeRelatedToApep()
            || !egpFlameSnakeGrassSnakeLook()
            || !egpFlameSnakeCoiledOnTreasure()
            || !egpFlameSnakeSaveForHalf()
            || !egpFlameSnakeHellsSwarm()
            || !egpGebGodOfTheEarth()
            || !egpGebHeavilyMuscled()
            || !egpGebImmuneOnGround()
            || !egpGebShapeChange()
            || !egpGebNegateEarthSpells()
            || !egpGebElementalsOncePerDay()
            || !egpGebCrownOfMonsters()
            || !egpGebStaffOfRegeneration()
            || !egpGebNeverWithoutDevices()
            || !egpHorusSonOfOsiris()
            || !egpHorusHawkHeaded()
            || !egpHorusTriplesWeaponPower()
            || !egpHorusWandOfFire()
            || !egpHorusMonsterSummoningVII()
            || !egpHorusSwordNullifiesSpells()
            || !egpHorusSpearKillsShapeChanged()
            || !egpHorusOthersWeaponsWeaker()
            || !egpHorusUnaffectedByFirstBlow()
            || !egpHorusAidsAvengers()
            || !egpIsisGoddessOfMagic()
            || !egpIsisBeautifulFemale()
            || !egpIsisUnlimitedSpells()
            || !egpIsisHeaddressContactsGods()
            || !egpIsisCharmsMaker()
            || !egpIsisCharmResistsOneSpell()
            || !egpIsisGivesCharmsByWhim()
            || !egpNephthysGoddessOfWealth()
            || !egpNephthysTwinOfIsis()
            || !egpNephthysProtectsChaoticSouls()
            || !egpNephthysHatesEvil()
            || !egpNephthysTwinDeathRays()
            || !egpNephthysEdgeOfCivilization()
            || !egpNephthysClericCrusades()
            || !egpNephthysWasMarriedToSet()
            || !egpOsirisGodOfNatureAndDead()
            || !egpOsirisMuscularGreenMan()
            || !egpOsirisLordOfTheDead()
            || !egpOsirisVegetationImmune()
            || !egpOsirisRaisesAnyDead()
            || !egpOsirisTouchKills()
            || !egpOsirisShapeChange()
            || !egpOsirisControlsVegetation()
            || !egpOsirisUsesAnyWeapon()
            || !egpOsirisCrownSeesInvisible()
            || !egpOsirisScepterOfCancellation()
            || !egpOsirisSecondOnlyToRa()
            || !egpOsirisGrantsWish()
            || !egpPhoenixUnique()
            || !egpPhoenixExistedAtCreation()
            || !egpPhoenixEverlastingLife()
            || !egpPhoenixRegenerates()
            || !egpPhoenixNoMagicAffects()
            || !egpPhoenixConstantlyBurning()
            || !egpPhoenixHeatNoSave()
            || !egpPhoenixMeltsWeapons()
            || !egpPhoenixWingsBeakDamage()
            || !egpPhoenixExplosionSave()
            || !egpPhoenixRebornFromAshes()
            || !egpPhoenixUnkillable()
            || !egpPtahCreator()
            || !egpPtahDwarfReflectingUniverse()
            || !egpPtahFormedPrimeMaterial()
            || !egpPtahCreatedPantheon()
            || !egpPtahNotAMember()
            || !egpPtahPlanarMaster()
            || !egpPtahGazeBanishes()
            || !egpPtahTeleportAnywhere()
            || !egpPtahNoArmor()
            || !egpPtahScepterOfTheGods()
            || !egpPtahLovesNewDevices()
            || !egpPtahThetAntiMagicShell()
            || !egpPtahThetEtherealWeekly()
            || !egpSekerGodOfLight()
            || !egpSekerCousinToShu()
            || !egpSekerDestroysEvil()
            || !egpSekerMaceOfDisintegration()
            || !egpSekerShaftsKillUndead()
            || !egpSekerShapeChange()
            || !egpSekerGodOfAfterworld()
            || !egpSekerProtectsNeutralGoodSouls()
            || !egpSetGodOfEvil()
            || !egpSetJackalHeaded()
            || !egpSetSpreadsEvil()
            || !egpSetAlignmentChangeTouch()
            || !egpSetMinionsCreated()
            || !egpSetSpearOfDarkness()
            || !egpSetPoisonSkin()
            || !egpSetWatchesEvilActs()
            || !egpSetEnemyOfOsirisAndHorus()
            || !egpSetThwartsThroughOthers()
            || !egpMinionsUncommon()
            || !egpMinionsPolymorphSnakes()
            || !egpMinionsSaveAs10thFighters()
            || !egpMinionsBlackPlateMail()
            || !egpMinionsIntelligentGoBetweens()
            || !egpMinionsNeverCheckMorale()
            || !egpMinionsOtherForms()
            || !egpShuGodOfTheSky()
            || !egpShuTwinBrotherOfTefnut()
            || !egpShuLevitate()
            || !egpShuLightOfDay()
            || !egpShuHeatImmune()
            || !egpShuPhoenixFeatherMail()
            || !egpShuFlameAura()
            || !egpShuDoubleStrengthStaff()
            || !egpShuWitheringTouch()
            || !egpShuProtectiveOfTefnut()
            || !egpTefnutGoddessOfStorms()
            || !egpTefnutWindStorms()
            || !egpTefnutShapeChange()
            || !egpTefnutSpeakWithDead()
            || !egpTefnutWaterMonsters()
            || !egpTefnutTeleportsAway()
            || !egpThothGodOfKnowledge()
            || !egpThothTeacherOfTheGods()
            || !egpThothMaximumDamageSpells()
            || !egpThothNegatesKnownPowers()
            || !egpThothOnePerRound()
            || !egpThothScepterDeathSpell()
            || !egpThothThreeBooks()
            || !egpThothThievesRegret()
            || !egpThothInstantlyAware()
        )
            ++bad;
        // the the combat grid grid
        int CegpCbt[21][9] = {
            {-3,0,400,24,24,0,0,80,72},
            {-5,0,345,15,24,2,0,20,84},
            {-2,0,300,12,0,3,2,80,72},
            {-4,0,250,18,0,2,0,40,3600},
            {3,0,289,21,21,1,0,10,180},
            {-2,0,300,24,0,2,0,45,72},
            {-3,0,210,6,24,3,2,100,48},
            {2,0,0,3,0,1,0,85,12},
            {-3,0,339,12,48,2,0,30,840},
            {-2,0,359,15,15,2,0,75,74},
            {-2,0,300,12,24,3,2,90,64},
            {2,0,200,12,12,3,2,40,64},
            {-2,0,400,24,48,2,0,80,84},
            {3,0,50,12,24,3,0,0,720},
            {-5,0,390,-1,0,2,0,70,48},
            {-2,0,300,24,0,2,0,40,76},
            {-4,0,378,18,0,2,0,59,84},
            {-2,0,25,12,0,3,2,10,76},
            {6,0,346,12,48,3,2,69,72},
            {-2,0,223,24,0,3,2,69,72},
            {4,0,389,12,24,1,0,98,76},
            };
        for (int b = 0;
             b < egpCbtRows();
             ++b) {
            int vals[9];
            vals[0] = egpCbtAC(b);
            vals[1] = egpCbtACAlt(b);
            vals[2] = egpCbtHP(b);
            vals[3] = egpCbtMove(b);
            vals[4] = egpCbtMoveAlt(b);
            vals[5] = egpCbtAtN(b);
            vals[6] = egpCbtAtD(b);
            vals[7] = egpCbtMR(b);
            vals[8] = egpCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CegpCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CegpCls[21][11] = {
            {20,0,16,16,0,19,0,0,0,0,0},
            {0,0,0,0,0,8,8,0,10,7,0},
            {20,0,12,12,0,20,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,15,15,0,0,0,0,0,0,0},
            {15,0,10,10,0,15,15,0,0,0,0},
            {0,0,10,10,0,15,15,15,0,0,8},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,17,17,0,15,0,0,0,0,0},
            {0,0,0,0,0,16,0,0,0,0,0},
            {20,14,10,10,0,99,0,0,0,0,0},
            {15,0,8,8,0,17,0,0,0,0,0},
            {0,0,0,0,16,20,0,0,0,0,15},
            {0,0,0,0,0,0,0,0,0,0,0},
            {20,0,14,14,0,25,0,0,0,0,0},
            {13,13,0,0,0,12,12,0,0,0,0},
            {15,0,17,17,0,0,30,0,15,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {15,0,0,0,0,15,0,0,0,0,0},
            {18,0,8,8,0,13,0,0,0,0,0},
            {0,0,5,5,0,30,30,0,0,0,0},
            };
        for (int b = 0;
             b < egpClsRows();
             ++b) {
            int vals[11];
            vals[0] = egpClsCleric(b);
            vals[1] = egpClsDruid(b);
            vals[2] = egpClsFighterLo(b);
            vals[3] = egpClsFighterHi(b);
            vals[4] = egpClsRanger(b);
            vals[5] = egpClsMagUser(b);
            vals[6] = egpClsIllus(b);
            vals[7] = egpClsThief(b);
            vals[8] = egpClsAssassin(b);
            vals[9] = egpClsMonk(b);
            vals[10] = egpClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CegpCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CegpAbi[21][9] = {
            {20,0,0,25,25,20,25,25,0},
            {25,7,14,19,12,25,25,12,0},
            {24,6,12,24,24,19,22,19,0},
            {0,0,0,0,0,0,0,0,0},
            {20,3,8,17,25,18,19,-3,0},
            {25,7,14,24,10,23,20,22,0},
            {24,6,12,25,10,24,25,15,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,22,20,23,25,22,0},
            {25,7,14,25,21,25,23,24,0},
            {10,0,0,25,25,20,19,25,0},
            {17,1,1,21,18,23,20,22,0},
            {24,6,12,25,25,19,25,24,0},
            {0,0,0,0,0,0,0,0,0},
            {21,4,9,25,25,18,23,20,0},
            {25,7,14,18,18,25,24,24,0},
            {14,0,0,25,23,20,25,-2,0},
            {0,0,0,0,0,0,0,0,0},
            {16,0,1,20,23,20,23,19,0},
            {16,0,1,20,23,20,23,18,0},
            {20,3,8,25,25,20,24,18,0},
            };
        for (int b = 0;
             b < egpAbiRows();
             ++b) {
            int vals[9];
            vals[0] = egpAbiStr(b);
            vals[1] = egpAbiStrHit(b);
            vals[2] = egpAbiStrDmg(b);
            vals[3] = egpAbiInt(b);
            vals[4] = egpAbiWis(b);
            vals[5] = egpAbiDex(b);
            vals[6] = egpAbiCon(b);
            vals[7] = egpAbiCha(b);
            vals[8] = egpAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CegpAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CegpRos[21][9] = {
            {0,49,1,1,6,1,0,0,0},
            {1,49,2,0,6,1,1,1,0},
            {2,50,0,0,2,2,1,0,0},
            {3,50,8,3,0,0,1,0,0},
            {4,50,4,2,6,1,1,0,0},
            {5,50,2,0,2,3,1,1,1},
            {6,51,4,0,6,4,1,1,0},
            {7,51,8,3,0,0,1,0,0},
            {8,51,4,1,6,5,1,0,0},
            {9,51,3,0,6,6,1,0,1},
            {10,52,1,1,1,1,1,0,0},
            {11,52,2,0,6,7,0,0,1},
            {12,52,0,1,5,8,1,0,1},
            {13,52,4,3,0,0,1,0,0},
            {14,53,3,1,2,9,1,0,0},
            {15,53,1,0,6,8,1,1,0},
            {16,53,6,1,2,10,1,0,0},
            {17,54,6,3,0,0,0,0,0},
            {18,54,0,0,6,11,0,0,0},
            {19,54,0,0,6,12,0,0,0},
            {20,55,4,1,1,4,0,1,0},
            };
        for (int b = 0;
             b < egpRosRows();
             ++b) {
            int vals[9];
            vals[0] = egpRosOrd(b);
            vals[1] = egpRosPage(b);
            vals[2] = egpRosAlign(b);
            vals[3] = egpRosRank(b);
            vals[4] = egpRosPsiClass(b);
            vals[5] = egpRosPlane(b);
            vals[6] = egpRosDmgFixed(b);
            vals[7] = egpRosInEach(b);
            vals[8] = egpRosSetEnmity(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CegpRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the twenty-one beings, the twelve
        // planes, the 97 hieroglyph words)
    if (egpTableCount() != 4
            || egpBeingCount() != 21
            || egpCbtRows() != 21
            || egpClsRows() != 21
            || egpAbiRows() != 21
            || egpRosRows() != 21
            || egpPlaneCount() != 12
            || egpArtifactCount() != 2
            || egpChainCount() != 0
            || egpRound() != 857
            || egpPrintStart() != 49
            || egpPrintEnd() != 56
            || egpRegistryFloor() != 995
            || egpHieroglyphWordCount() != 97
        )
            ++bad;
        // the print walk spans pp. 49-56 and the roster ordinals run 0-20 in
        // print order
    if (egpRosPage(0) != 49
            || egpRosPage(2) != 50
            || egpRosPage(6) != 51
            || egpRosPage(10) != 52
            || egpRosPage(14) != 53
            || egpRosPage(17) != 54
            || egpRosPage(20) != 55
            || egpRosOrd(0) != 0
            || egpRosOrd(1) != 1
            || egpRosOrd(2) != 2
            || egpRosOrd(3) != 3
            || egpRosOrd(4) != 4
            || egpRosOrd(5) != 5
            || egpRosOrd(6) != 6
            || egpRosOrd(7) != 7
            || egpRosOrd(8) != 8
            || egpRosOrd(9) != 9
            || egpRosOrd(10) != 10
            || egpRosOrd(11) != 11
            || egpRosOrd(12) != 12
            || egpRosOrd(13) != 13
            || egpRosOrd(14) != 14
            || egpRosOrd(15) != 15
            || egpRosOrd(16) != 16
            || egpRosOrd(17) != 17
            || egpRosOrd(18) != 18
            || egpRosOrd(19) != 19
            || egpRosOrd(20) != 20
        )
            ++bad;
        // the combat grid walk: the armor classes and hit points of the
        // twenty-one
    if (egpCbtAC(0) != -3
            || egpCbtAC(1) != -5
            || egpCbtAC(14) != -5
            || egpCbtAC(18) != 6
            || egpCbtHP(0) != 400
            || egpCbtHP(12) != 400
            || egpCbtHP(3) != 250
            || egpCbtHP(13) != 50
            || egpCbtHP(17) != 25
        )
            ++bad;
        // the class grid walk: the level cells
    if (egpClsCleric(0) != 20
            || egpClsCleric(10) != 20
            || egpClsDruid(10) != 14
            || egpClsMagUser(14) != 25
            || egpClsIllus(16) != 30
            || egpClsMagUser(16) != 0
            || egpClsRanger(12) != 16
            || egpClsBard(12) != 15
            || egpClsBard(6) != 8
            || egpClsThief(6) != 15
            || egpClsAssassin(1) != 10
            || egpClsAssassin(16) != 15
            || egpClsMonk(1) != 7
            || egpClsMagUser(10) != 99
        )
            ++bad;
        // the GEOMETRY SWAP walk: Ra the S:20 line, Anhur the S:25(+7,+14)
        // the +14 lance prose confirms
    if (egpAbiStr(0) != 20
            || egpAbiStrHit(0) != 0
            || egpAbiStr(1) != 25
            || egpAbiStrHit(1) != 7
            || egpAbiStrDmg(1) != 14
            || egpAbiCha(1) != 12
            || egpAbiWis(1) != 12
            || egpAbiInt(1) != 19
        )
            ++bad;
        // the ability grid walk: the rest of the lines
    if (egpAbiInt(12) != 25
            || egpAbiWis(5) != 10
            || egpAbiStr(10) != 10
            || egpAbiCha(4) != -3
            || egpAbiCha(16) != -2
            || egpAbiStr(18) != 16
            || egpAbiStrDmg(18) != 1
            || egpAbiStr(19) != 16
            || egpAbiPsi(3) != 0
        )
            ++bad;
        // the roster walk: the ranks, classes, planes and Set-enmity flags
    if (egpRosRank(4) != 2
            || egpRosRank(3) != 3
            || egpRosPsiClass(2) != 2
            || egpRosPsiClass(5) != 2
            || egpRosPsiClass(14) != 2
            || egpRosPsiClass(16) != 2
            || egpRosPsiClass(12) != 5
            || egpRosPsiClass(10) != 1
            || egpRosPsiClass(20) != 1
            || egpRosPlane(5) != 3
            || egpRosPlane(8) != 5
            || egpRosPlane(9) != 6
            || egpRosPlane(11) != 7
            || egpRosPlane(14) != 9
            || egpRosPlane(16) != 10
            || egpRosPlane(19) != 12
            || egpRosSetEnmity(5) != 1
            || egpRosSetEnmity(9) != 1
            || egpRosSetEnmity(11) != 1
            || egpRosSetEnmity(12) != 1
            || egpRosSetEnmity(0) != 0
            || egpRosInEach(15) != 1
            || egpRosInEach(20) != 1
        )
            ++bad;
        // the lore walk: the 3,000 year culture, the temple pylons, the
        // female cleric ladder
    if (egpLoreCultureYears() != 3000
            || egpLoreTemplePylons() != 2
            || egpLoreFemaleClericMax() != 9
            || egpLoreConsortLevel() != 11
        )
            ++bad;
        // the true Ankh walk: the one-foot length, the 7 per plane
    if (egpAnkhLengthInches() != 12
            || egpAnkhPerPlane() != 7
        )
            ++bad;
        // the Ra walk: the Nil damage and 0 attacks, the Matet galley, the
        // 4-40 heat rays at 500 yards
    if (egpCbtAtN(0) != 0
            || egpRosDmgFixed(0) != 0
            || egpRaGalleyMove() != 24
            || egpRaGalleyFlameDamage() != 40
            || egpRaHeatRayCount() != 2
            || egpRaHeatRayRangeYards() != 500
            || egpRaHeatRayLo() != 4
            || egpRaHeatRayHi() != 40
            || egpCbtMR(0) != 80
        )
            ++bad;
        // the Anhur walk: the +5 sun lance 6-60 plus 14, the undead
        // destruction at 50 yards, the 1 percent reward
    if (egpAnhurLancePlus() != 5
            || egpAnhurLanceDmgLo() != 6
            || egpAnhurLanceDmgHi() != 60
            || egpAnhurLanceStrBonus() != 14
            || egpAnhurLanceUndeadRangeYards() != 50
            || egpAnhurScaleMailPlus() != 4
            || egpAnhurRewardPct() != 1
            || egpCbtHP(1) != 345
        )
            ++bad;
        // the Anubis walk: the 3-30 bite, the 5/10 percent tomb chances, the
        // 50,000 gp gems, the 20 percent quest
    if (egpAnubisBiteDmgLo() != 3
            || egpAnubisBiteDmgHi() != 30
            || egpAnubisTombRobberyPct() != 5
            || egpAnubisConsecratedPct() != 10
            || egpAnubisIntercessionLevel() != 10
            || egpAnubisGemCost() != 50000
            || egpAnubisQuestPct() != 20
        )
            ++bad;
        // the Apep walk: the 3-30 bite at -4, the 6-60 breath, the 4-24
        // constriction, X/28,350, the 5-50 flame snakes
    if (egpApepBiteDmgLo() != 3
            || egpApepBiteDmgHi() != 30
            || egpApepBiteSaveMod() != -4
            || egpApepBreathDmgLo() != 6
            || egpApepBreathDmgHi() != 60
            || egpApepConstrictLo() != 4
            || egpApepConstrictHi() != 24
            || egpApepXpValue() != 28350
            || egpApepLairPct() != 70
            || egpApepFlameSnakesLo() != 5
            || egpApepFlameSnakesHi() != 50
            || egpCbtSizeIn(3) != 3600
        )
            ++bad;
        // the Apshai walk: the 6-60 bite, the never-miss
    if (egpApshaiBiteDmgLo() != 6
            || egpApshaiBiteDmgHi() != 60
            || egpCbtHP(4) != 289
        )
            ++bad;
        // the Bast walk: the 5-50 claws, the W:10 geometry win, the 100-yard
        // evil sense, the 2/5/75 percents
    if (egpBastClawDmgLo() != 5
            || egpBastClawDmgHi() != 50
            || egpBastEvilSenseRangeYards() != 100
            || egpBastCatKillSeePct() != 2
            || egpBastChoicePct() != 5
            || egpBastShatterPct() != 75
            || egpCbtMR(5) != 45
        )
            ++bad;
        // the Bes walk: the +2 always-hit sword 4-24, the natural 17 floor,
        // the 5 percent luck stone, MR 100
    if (egpBesSwordPlus() != 2
            || egpBesSwordDmgLo() != 4
            || egpBesSwordDmgHi() != 24
            || egpBesLuckStonePct() != 5
            || egpBesNaturalWeaponFloor() != 17
            || egpCbtMR(6) != 100
            || egpCbtSizeIn(6) != 48
        )
            ++bad;
        // the Flame Snake walk: 1 hit die, the 1-2 bite, the 15-point blast
        // at 3 inches 5 times a day
    if (egpFlameSnakeHD() != 1
            || egpFlameSnakeDmgLo() != 1
            || egpFlameSnakeDmgHi() != 2
            || egpFlameSnakeBlastDamage() != 15
            || egpFlameSnakeBlastRangeInches() != 3
            || egpFlameSnakeBlastPerDay() != 5
            || egpFlameSnakeLairPct() != 80
            || egpFlameSnakeXpBase() != 745
            || egpFlameSnakeXpPerHp() != 1
            || egpCbtMR(7) != 85
        )
            ++bad;
        // the Geb walk: the 6-60 fists, the 2-12 elementals, the 2-8 crown
        // monsters, the 25-regen staff
    if (egpGebFistDmgLo() != 6
            || egpGebFistDmgHi() != 60
            || egpGebElementalsLo() != 2
            || egpGebElementalsHi() != 12
            || egpGebCrownMonstersLo() != 2
            || egpGebCrownMonstersHi() != 8
            || egpGebStaffRegen() != 25
            || egpGebStaffDrainLevels() != 5
            || egpCbtMove(8) != 12
            || egpCbtMoveAlt(8) != 48
        )
            ++bad;
        // the Horus walk: the 30 foot spear 3-36 plus 14, the +3 sword 3-30,
        // the 18-dice fireball, the flagged 15/15 move
    if (egpHorusSpearFeet() != 30
            || egpHorusSpearDmgLo() != 3
            || egpHorusSpearDmgHi() != 36
            || egpHorusSpearBonus() != 14
            || egpHorusSwordPlus() != 3
            || egpHorusSwordDmgLo() != 3
            || egpHorusSwordDmgHi() != 30
            || egpHorusWandFireDice() != 18
            || egpHorusAidPct() != 5
            || egpHorusAidedScores() != 19
            || egpCbtMove(9) != 15
            || egpCbtMoveAlt(9) != 15
        )
            ++bad;
        // the Isis walk: the printed S:10, the 20th cleric/14th druid slash,
        // the MU See below, the 5 percent charms
    if (egpIsisSpellLevel() != 20
            || egpIsisCharmPct() != 5
            || egpAbiStr(10) != 10
            || egpClsCleric(10) != 20
            || egpClsDruid(10) != 14
            || egpClsMagUser(10) != 99
            || egpRosPsiClass(10) != 1
        )
            ++bad;
        // the Nephthys walk: the twin death rays at -6 to 12 inches, the By
        // weapon damage cell
    if (egpNephthysDeathRaySaveMod() != -6
            || egpNephthysDeathRayRangeInches() != 12
            || egpRosDmgFixed(11) != 0
            || egpRosSetEnmity(11) != 1
        )
            ++bad;
        // the Osiris walk: the 3-30 plus 12, the 5 percent wish, the ranger
        // slot, the class V
    if (egpOsirisDmgLo() != 3
            || egpOsirisDmgHi() != 30
            || egpOsirisStrBonus() != 12
            || egpOsirisWishPct() != 5
            || egpRosPsiClass(12) != 5
            || egpCbtSizeIn(12) != 84
        )
            ++bad;
        // the Phoenix walk: the 25-point heat at 10 yards, the 12 HD attack,
        // the 10-100 explosion save, the 3-18 rebirth
    if (egpPhoenixHeatRangeYards() != 10
            || egpPhoenixHeatDamage() != 25
            || egpPhoenixAttackHd() != 12
            || egpPhoenixExplosionDmgLo() != 10
            || egpPhoenixExplosionDmgHi() != 100
            || egpPhoenixRebirthLo() != 3
            || egpPhoenixRebirthHi() != 18
            || egpCbtMR(13) != 0
        )
            ++bad;
        // the Ptah walk: the printed Infinite move, the 1-100 plus 9 scepter,
        // the Thet charges and chances
    if (egpCbtMove(14) != -1
            || egpPtahScepterDmgLo() != 1
            || egpPtahScepterDmgHi() != 100
            || egpPtahScepterStrBonus() != 9
            || egpPtahGazeSaveMod() != -6
            || egpPtahThetChargesLo() != 2
            || egpPtahThetChargesHi() != 12
            || egpPtahThetPct() != 5
            || egpPtahThetWorshiperBonus() != 5
            || egpPtahThetClericBonus() != 10
            || egpRosPsiClass(14) != 2
        )
            ++bad;
        // the Seker walk: the 3-30 plus 14 halberd, the +3 disintegration
        // mace 2-24, the 500-yard light shafts
    if (egpSekerHalberdDmgLo() != 3
            || egpSekerHalberdDmgHi() != 30
            || egpSekerHalberdBonus() != 14
            || egpSekerMacePlus() != 3
            || egpSekerMaceDmgLo() != 2
            || egpSekerMaceDmgHi() != 24
            || egpSekerShaftRangeYards() != 500
        )
            ++bad;
        // the Set walk: the +4 Spear of Darkness 7-70, the 2-20 minions for
        // 12 weeks, the MR 59 print
    if (egpSetSpearPlus() != 4
            || egpSetSpearDmgLo() != 7
            || egpSetSpearDmgHi() != 70
            || egpSetMinionsLo() != 2
            || egpSetMinionsHi() != 20
            || egpSetMinionWeeks() != 12
            || egpSetWatchPct() != 5
            || egpCbtMR(16) != 59
            || egpRosPsiClass(16) != 2
        )
            ++bad;
        // the Minions walk: the 25 hit points, the fight-as-10th, the 1-12
        // snake bite, V/500
    if (egpMinionsHp() != 25
            || egpMinionsFightAsLevel() != 10
            || egpMinionsAppearingLo() != 1
            || egpMinionsAppearingHi() != 20
            || egpMinionsBiteLo() != 1
            || egpMinionsBiteHi() != 12
            || egpMinionsXpLevel() != 5
            || egpMinionsXpBase() != 500
            || egpCbtMR(17) != 10
        )
            ++bad;
        // the Shu and Tefnut walks: the phoenix-feather +5 mail, the 24-point
        // bolts at 1,000 yards, the MR 69 print
    if (egpShuScaleMailPlus() != 5
            || egpShuFlameDamage() != 25
            || egpShuElementalsLo() != 1
            || egpShuElementalsHi() != 10
            || egpShuHorusAidPct() != 75
            || egpTefnutBoltCount() != 2
            || egpTefnutBoltDamage() != 24
            || egpTefnutBoltRangeYards() != 1000
            || egpCbtMR(18) != 69
            || egpCbtMR(19) != 69
        )
            ++bad;
        // the Thoth walk: the 100-yard negation, the 3 books, the class I,
        // the 98 percent MR
    if (egpThothNegateRangeYards() != 100
            || egpThothBookCount() != 3
            || egpRosPsiClass(20) != 1
            || egpCbtMR(20) != 98
            || egpClsMagUser(20) != 30
            || egpClsIllus(20) != 30
        )
            ++bad;
        // the paladin cells (the printed Nth level paladin lines of Anubis,
        // Horus, Seker and Shu ride the fighter cols)
    if (egpClsFighterLo(2) != 12
            || egpClsFighterHi(2) != 12
            || egpAbiCha(2) != 19
            || egpAbiWis(2) != 24
            || egpAbiInt(2) != 24
        )
            ++bad;
        // the hieroglyph data file rides the count const (the words
        // themselves in doc/data/ddg_egyptian_hieroglyphs.txt)
    if (egpHieroglyphWordCount() != 97
        )
            ++bad;
        printf("R857 Egyptian mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
