    // ---- R864 nonhumans' deities audit ----
    // THE NONHUMANS' DEITIES - the D&DG walk round sixteen, print pp.
    // 105-112: twenty stat-block rows - the six greater gods (Moradin the
    // Soul Forger, Corellon Larethian, Maglubiyet, Garl Glittergold,
    // Yondalla, Gruumsh), the twelve lesser (Hruggek, Skerrit the Forester,
    // Deep Sashelas, Lolth, Rillifane Rallathil, Grolantor, Skoraeus
    // Stonebones, Kurtulmak, Blibdoolpoolp, Semuanya, Eadro, Sekolah) and the
    // two demigods (Vaprak, Laogzed) - plus the shaman and witch doctor
    // doctrine of the intro (the 1-4 hit point ladder, the 2-5 tandem bonus,
    // the per-two-levels hit dice improvement, the gnoll/goblin/orc examples,
    // the thirteen-being NOTE list of MM and FF lesser gods) and the
    // section-wide shaman level caps (3rd to 14th) riding as consts, with the
    // cross-reference roster as the round's data file. THE HEADLINE
    // ADJUDICATIONS: the MORADIN-CORELLON FOLD SWAP - the psm-4 extract
    // interleave gave Moradin the S:21(+4,+9) I:25 W:25 D:25 C:21 CH:25 line
    // and Corellon the S:25(+7,+14) I:23 W:20 D:21 C:25 CH:19(25 to dwarves)
    // line; the tsv x-coordinates settle both (the x=1306 right-column line
    // is Corellon, the x=398 left-column line is Moradin) and the damage
    // riders corroborate (Moradin 4-40 (+14), Corellon 3-30 (+9)) - the R857
    // Ra/Anhur geometry-swap precedent. The KURTULMAK-BLIBDOOLPOOLP TAIL
    // SWAP: the same fold swapped the thief/psionic/ability tails; geometry
    // gives Kurtulmak the 12th assassin, the VI pipe and S:22(+4,+10) I:19
    // W:9 D:19 C:19 CH:19, and Blibdoolpoolp the 15th assassin, the III print
    // and S:21(+4,+9) I:20 W:10 D:21 C:23 CH:11 - the L&L transcription
    // agrees on every cell. THE NOT-PRINTED DEX: Hruggek ability line has no
    // dex cell - the tsv geometry shows only the bare 36px inter-cell gap
    // between W:8 and C:24, and the L&L marks the same gap; pinned 0. THE
    // FRACTION SIZES (the R859 fingerprint): Yondalla prints the 4 1/2 foot
    // cell (the tesseract 42 inches, the L&L 4.5 feet) pinned 54; Kurtulmak
    // the 5 1/2 foot (the tesseract 5 percent glyph) pinned 66. THE DIVERGENT
    // CELLS pinned by the 2nd print with the L&L noted: Sashelas D:21 (L&L
    // 18), Vaprak W:12 (L&L 18 - eyeball flag, the tesseract conf 90), Lolth
    // MR 70 (L&L 75), Lolth psionic See below with the discipline prose (the
    // L&L block prints 266 with all modes - a later-print or transcription
    // gloss), Blibdoolpoolp MU 20th magic-user (L&L illusionist), Laogzed
    // harmful spells (L&L destructive), and the Nine Hells planes of
    // Maglubiyet, Kurtulmak, Gruumsh and Sekolah (the L&L Gehenna and Acheron
    // and Stygia glosses are the transcriber D64 annotations, not print ink).
    // THE LOLTH SPIDER PRINT: the AC -10 with the drow-form paren (the
    // tesseract +2 misread at conf 53, the L&L -2, the game-sense tiebreak -
    // the paren is an armor class and a plus-signed cell is not legal
    // notation - eyeball flag), the MOVE 1 inch / 9 inch web walk of the MM
    // giant spider convention (the tesseract 17 misread) with the drow-form
    // 15 riding a const, the 66 hit points, and the See below 99 pairs on
    // both class lines (the egp Isis precedent) with the 16th cleric / 14th
    // magic-user drow form riding consts. The psionic pipes: I Corellon,
    // Rillifane, Sekolah; II Semuanya, Eadro (the tsv I/ and Il misreads,
    // both corroborated by the L&L); III Sashelas, Blibdoolpoolp; V Skerrit,
    // Gruumsh; VI Moradin, Grolantor, Skoraeus, Maglubiyet, Kurtulmak,
    // Vaprak. The As 16+ HD monster fighter cells (twelve) pin 16 with the
    // as-monster-HD reading noted in the col comment. ZERO registry defs
    // touched - the floor holds at 995.
    {
        using namespace rules;
        int bad = 0;
    if (nhgRound() != 864
            || nhgPrintStart() != 105
            || nhgPrintEnd() != 112
            || nhgBeingCount() != 20
            || nhgTableCount() != 4
            || nhgChainCount() != 0
            || nhgRegistryFloor() != 995
            || nhgCbtRows() != 20
            || nhgClsRows() != 20
            || nhgAbiRows() != 20
            || nhgRosRows() != 20
            || nhgGreaterCount() != 6
            || nhgLesserCount() != 12
            || nhgDemigodCount() != 2
            || nhgPlaneCount() != 11
            || nhgNineHellsCount() != 4
            || nhgOlympusCount() != 3
            || nhgAbyssCount() != 3
            || nhgSevenHeavensCount() != 2
            || nhgConcordantCount() != 2
            || nhgAsMonsterHDCount() != 12
            || nhgPsionicRowCount() != 15
            || nhgPsiNilCount() != 5
            || nhgInEachCount() != 6
            || nhgFractionSizeCount() != 2
            || nhgDualACCount() != 2
            || nhgDualMoveCount() != 5
            || nhgDmgFixedCount() != 17
            || nhgSeeBelowCount() != 7
            || nhgShamanHpLow() != 1
            || nhgShamanHpHigh() != 4
            || nhgWitchHpLow() != 2
            || nhgWitchHpHigh() != 5
            || nhgHdBetterLevels() != 2
            || nhgGnollBaseHd() != 2
            || nhgGnollBonusDice() != 3
            || nhgGnollFightsHd() != 4
            || nhgGoblinDice() != 4
            || nhgGoblinBonusLow() != 1
            || nhgGoblinBonusHigh() != 7
            || nhgGoblinFightsHd() != 3
            || nhgOrcDice() != 1
            || nhgOrcBonusDice() != 2
            || nhgOrcBonusHp() != 2
            || nhgOrcFightsHd() != 2
            || nhgOrcWitchLevel() != 3
            || nhgNoteLesserGods() != 13
            || nhgNoteMMCount() != 10
            || nhgNoteFFCount() != 3
            || nhgGnollShamanMax() != 5
            || nhgBugbearShamanMax() != 5
            || nhgCentaurShamanMax() != 3
            || nhgEttinShamanMax() != 3
            || nhgHillGiantShamanMax() != 7
            || nhgFireGiantShamanMax() != 7
            || nhgFrostGiantShamanMax() != 7
            || nhgStoneGiantShamanMax() != 7
            || nhgIxitxachitlClericMax() != 8
            || nhgKoboldShamanMax() != 5
            || nhgKuoToanClericMax() != 12
            || nhgLizardManShamanMax() != 7
            || nhgLocathahShamanMax() != 3
            || nhgMermanClericMax() != 5
            || nhgOgreTrollShamanMax() != 3
            || nhgOrcShamanMax() != 5
            || nhgSahuaginClericMax() != 5
            || nhgTroglodyteShamanMax() != 3
            || nhgGoblinShamanMax() != 7
            || nhgDwarfClericMax() != 7
            || nhgElfClericMax() != 7
            || nhgAquaticElfClericMax() != 7
            || nhgGnomeClericMax() != 7
            || nhgHalflingClericMax() != 5
            || nhgWoodElfClericMax() != 7
            || nhgDrowClericMax() != 14
            || nhgHruggekMorningstarPlus() != 3
            || nhgHruggekMorningstarLow() != 3
            || nhgHruggekMorningstarHigh() != 30
            || nhgHruggekClawLow() != 2
            || nhgHruggekClawHigh() != 16
            || nhgHruggekWeaponToHit() != 2
            || nhgHruggekChaToBugbears() != 23
            || nhgHruggekPantheonSize() != 6
            || nhgSkerritACFloor() != 2
            || nhgSkerritSpearPlus() != 3
            || nhgSkerritSpearLow() != 2
            || nhgSkerritSpearHigh() != 20
            || nhgSkerritFormAC() != 2
            || nhgSkerritFormMove() != 21
            || nhgSkerritForestToHit() != -4
            || nhgMoradinHammerPlus() != 5
            || nhgMoradinHammerLow() != 4
            || nhgMoradinHammerHigh() != 40
            || nhgMoradinChaToDwarves() != 25
            || nhgCorellonBowLow() != 2
            || nhgCorellonBowHigh() != 20
            || nhgCorellonSwordPlus() != 5
            || nhgCorellonSwordLow() != 3
            || nhgCorellonSwordHigh() != 30
            || nhgCorellonSwordBurnLow() != 10
            || nhgCorellonSwordBurnHigh() != 100
            || nhgSashelasDmgLow() != 3
            || nhgSashelasDmgHigh() != 30
            || nhgSashelasDolphins() != 20
            || nhgSashelasWaterMR() != 100
            || nhgLolthDrowMove() != 15
            || nhgLolthWebRange() != 30
            || nhgLolthWebDmgLow() != 1
            || nhgLolthWebDmgHigh() != 4
            || nhgLolthBiteLow() != 4
            || nhgLolthBiteHigh() != 16
            || nhgLolthPoisonSaveMod() != -4
            || nhgLolthHealsPerDay() != 3
            || nhgLolthPoisonOnePct() != 45
            || nhgLolthPoisonTwoPct() != 35
            || nhgLolthPoisonThreePct() != 20
            || nhgLolthGatePct() != 66
            || nhgLolthSummonLargePct() != 20
            || nhgLolthSummonHugePct() != 30
            || nhgLolthSummonGiantPct() != 40
            || nhgLolthSummonPhasePct() != 10
            || nhgLolthHolyWaterSplash() != 6
            || nhgLolthHolyWaterLow() != 6
            || nhgLolthHolyWaterHigh() != 21
            || nhgLolthSightRange() != 120
            || nhgLolthDrowClericLevel() != 16
            || nhgLolthDrowMagUserLevel() != 14
            || nhgLolthDisciplineLevel() != 16
            || nhgLolthChaDrow() != 23
            || nhgGrolantorClubLow() != 4
            || nhgGrolantorClubHigh() != 40
            || nhgSkoraeusFistLow() != 6
            || nhgSkoraeusFistHigh() != 60
            || nhgSkoraeusRegen() != 5
            || nhgSkoraeusEarthquakeLevel() != 30
            || nhgSkoraeusSummonLow() != 2
            || nhgSkoraeusSummonHigh() != 20
            || nhgMaglubiyetDmgLow() != 2
            || nhgMaglubiyetDmgHigh() != 20
            || nhgGarlAxePlus() != 5
            || nhgGarlAxeLow() != 3
            || nhgGarlAxeHigh() != 30
            || nhgYondallaWitherCharges() != 3
            || nhgYondallaWitherLow() != 2
            || nhgYondallaWitherHigh() != 5
            || nhgYondallaWitherAge() != 10
            || nhgKurtulmakSmellMiles() != 1
            || nhgKurtulmakFearFeet() != 10
            || nhgKurtulmakFearSaveMod() != -4
            || nhgKurtulmakSpearPlus() != 4
            || nhgKurtulmakSpearLow() != 2
            || nhgKurtulmakSpearHigh() != 24
            || nhgKurtulmakTailLow() != 1
            || nhgKurtulmakTailHigh() != 6
            || nhgBlibClawLow() != 4
            || nhgBlibClawHigh() != 24
            || nhgBlibGazeSaveMod() != -4
            || nhgBlibSummonLobsterLow() != 3
            || nhgBlibSummonLobsterHigh() != 30
            || nhgBlibSummonElementalLow() != 1
            || nhgBlibSummonElementalHigh() != 10
            || nhgBlibElementalHD() != 16
            || nhgBlibGemFavorPct() != 1
            || nhgBlibGemFavorPerGp() != 1000
            || nhgBlibPearlPerGp() != 500
            || nhgSemuanyaClubLow() != 2
            || nhgSemuanyaClubHigh() != 20
            || nhgSemuanyaSummonLow() != 3
            || nhgSemuanyaSummonHigh() != 18
            || nhgSemuanyaRegen() != 5
            || nhgSemuanyaChaToLizardMen() != 25
            || nhgEadroWhipCount() != 8
            || nhgEadroWhipLow() != 1
            || nhgEadroWhipHigh() != 10
            || nhgEadroSummonLow() != 2
            || nhgEadroSummonHigh() != 8
            || nhgEadroElementalHD() != 16
            || nhgVaprakClawLow() != 2
            || nhgVaprakClawHigh() != 20
            || nhgVaprakBiteLow() != 1
            || nhgVaprakBiteHigh() != 12
            || nhgVaprakRegen() != 7
            || nhgVaprakBerserkPct() != 2
            || nhgVaprakBerserkHit() != 2
            || nhgVaprakBerserkAC() != -2
            || nhgGruumshSpearPlus() != 5
            || nhgGruumshSpearLow() != 3
            || nhgGruumshSpearHigh() != 30
            || nhgGruumshParalysisSaveMod() != -4
            || nhgGruumshChaToOrcs() != 25
            || nhgSekolahBiteLow() != 6
            || nhgSekolahBiteHigh() != 60
            || nhgSekolahSwallowRoll() != 16
            || nhgSekolahHolySharksLow() != 1
            || nhgSekolahHolySharksHigh() != 3
            || nhgLaogzedAcidLow() != 3
            || nhgLaogzedAcidHigh() != 18
            || nhgLaogzedAcidSaveMod() != -4
            || nhgLaogzedBiteLow() != 6
            || nhgLaogzedBiteHigh() != 60
            || !nhgShamanHdLadder()
            || !nhgWitchDoctorPaired()
            || !nhgWitchTandemBonus()
            || !nhgGoblinHdAltPrint()
            || !nhgNoteMMLesserGods()
            || !nhgNoteLolthDetailed()
            || !nhgHruggekBloodOfferings()
            || !nhgHruggekCaveHeads()
            || !nhgHruggekMostPowerful()
            || !nhgSkerritAnyForestForm()
            || !nhgSkerritPossessPlants()
            || !nhgSkerritForestDefense()
            || !nhgSkerritFullMoonDances()
            || !nhgSkerritSatyrsNoClerics()
            || !nhgMoradinForgedDwarves()
            || !nhgMoradinHammerReturns()
            || !nhgMoradinArmorUnremovable()
            || !nhgMoradinForgedWeaponsCannotHarm()
            || !nhgMoradinHearthForge()
            || !nhgCorellonBowNeverMisses()
            || !nhgCorellonSwordDetectsDanger()
            || !nhgCorellonBanishedLolth()
            || !nhgCorellonElvesFromBlood()
            || !nhgCorellonQuarterMoonTalisman()
            || !nhgCorellonNoShrines()
            || !nhgSashelasDoubleDamageUnderwater()
            || !nhgSashelasFullWaterMR()
            || !nhgSashelasDolphinMaster()
            || !nhgSashelasSharkHunts()
            || !nhgSashelasTideCeremonies()
            || !nhgLolthSpiderAndDrowForms()
            || !nhgLolthConverseWithSpiders()
            || !nhgLolthSpiderPowersList()
            || !nhgLolthTwicePerDayPowers()
            || !nhgLolthSilverImmune()
            || !nhgLolthHalfDamageForms()
            || !nhgLolthPsionicLostInSpiderForm()
            || !nhgLolthDevBodyEquilibrium()
            || !nhgLolthDevClairvoyance()
            || !nhgLolthDevDomination()
            || !nhgLolthSciDimensionWalking()
            || !nhgLolthSciMindBar()
            || !nhgLolthSciMolecularRearrangement()
            || !nhgLolthSciProbabilityTravel()
            || !nhgLolthHolyWaterSusceptible()
            || !nhgRillifaneArrowsAlwaysSlay()
            || !nhgRillifaneBarkArmor()
            || !nhgRillifaneRootsMingle()
            || !nhgRillifaneHuntsSportEnemies()
            || !nhgGrolantorPersecutesSmaller()
            || !nhgGrolantorDwarfbeardBelts()
            || !nhgGrolantorEttinWorship()
            || !nhgSkoraeusNeverAboveGround()
            || !nhgSkoraeusListensToRock()
            || !nhgSkoraeusEarthquakePerRound()
            || !nhgMaglubiyetSpiritArmies()
            || !nhgMaglubiyetNewMoonSacrifices()
            || !nhgMaglubiyetAlwaysWinsClaim()
            || !nhgGarlArumdinaIntelligent()
            || !nhgGarlArumdinaHeals()
            || !nhgGarlKoboldCavernCollapse()
            || !nhgGarlWarLeader()
            || !nhgGarlGoldSacrifices()
            || !nhgYondallaProviderAspect()
            || !nhgYondallaProtectorAspect()
            || !nhgYondallaWitheringNoSave()
            || !nhgYondallaSafeday()
            || !nhgKurtulmakSmellsGnomes()
            || !nhgKurtulmakFearAura()
            || !nhgKurtulmakTailPoison()
            || !nhgKurtulmakOrangeRobes()
            || !nhgBlibLobsterSacrifices()
            || !nhgBlibGazeInsanity()
            || !nhgBlibDrowningSacrifices()
            || !nhgBlibHatesSurfaceRaces()
            || !nhgSemuanyaCommandsLizards()
            || !nhgSemuanyaTaciturn()
            || !nhgSemuanyaSurvivalCreed()
            || !nhgEadroLivingWater()
            || !nhgEadroAmorphousBlob()
            || !nhgEadroSpiritsAsFish()
            || !nhgEadroSeaSpaceRivalry()
            || !nhgVaprakTearsPrey()
            || !nhgVaprakAlwaysHungry()
            || !nhgVaprakBerserkRage()
            || !nhgGruumshOneEye()
            || !nhgGruumshDestructiveSpellsOnly()
            || !nhgGruumshPlucksLeftEye()
            || !nhgGruumshBloodWorship()
            || !nhgGruumshSpiritOrcArmies()
            || !nhgSekolahSwallowWhole()
            || !nhgSekolahFeedsWeakAged()
            || !nhgSekolahHolySharks()
            || !nhgLaogzedAcidSkin()
            || !nhgLaogzedStinkingCloud()
            || !nhgLaogzedHarmfulSpellsOnly()
            || !nhgLaogzedSheddingOfSkins()
        )
            ++bad;
        // the the combat grid grid
        int CnhgCbt[20][9] = {
            {0,0,221,12,0,1,2,25,144},
            {2,0,290,0,0,0,0,35,0},
            {-9,0,400,12,0,2,0,60,240},
            {-4,0,350,15,18,2,0,95,84},
            {-3,0,300,12,24,1,0,0,84},
            {-10,-2,66,1,9,1,1,70,0},
            {-2,0,317,12,0,2,0,75,0},
            {0,0,259,21,0,2,0,45,300},
            {0,0,380,15,0,2,0,50,360},
            {-2,0,350,12,0,2,0,50,132},
            {-2,0,350,12,0,3,2,25,48},
            {2,0,350,12,0,3,2,75,54},
            {0,0,219,12,0,2,0,55,66},
            {-1,0,310,12,48,2,0,55,240},
            {-4,0,211,12,24,1,0,78,144},
            {0,-6,227,12,24,1,8,72,84},
            {0,0,198,15,0,3,0,50,180},
            {-1,0,350,12,0,1,0,75,120},
            {0,0,329,36,0,2,0,47,420},
            {0,0,187,15,0,1,0,29,120},
            };
        for (int b = 0;
             b < nhgCbtRows();
             ++b) {
            int vals[9];
            vals[0] = nhgCbtAC(b);
            vals[1] = nhgCbtACAlt(b);
            vals[2] = nhgCbtHP(b);
            vals[3] = nhgCbtMove(b);
            vals[4] = nhgCbtMoveAlt(b);
            vals[5] = nhgCbtAtN(b);
            vals[6] = nhgCbtAtD(b);
            vals[7] = nhgCbtMR(b);
            vals[8] = nhgCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CnhgCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CnhgCls[20][11] = {
            {15,0,16,0,0,0,0,0,0,0,0},
            {14,14,16,0,0,0,10,0,0,0,9},
            {15,14,20,0,0,19,0,0,0,0,0},
            {13,13,0,0,20,20,20,0,0,0,15},
            {19,0,15,0,0,12,12,0,0,0,10},
            {99,99,16,0,0,99,99,0,0,0,0},
            {14,14,0,0,15,12,12,0,0,10,10},
            {10,0,16,0,0,0,0,0,0,0,0},
            {15,0,16,0,0,12,0,0,0,0,0},
            {10,0,16,0,0,0,6,0,10,0,0},
            {15,0,10,0,0,0,16,20,0,0,8},
            {12,12,10,0,0,0,25,15,0,0,0},
            {10,0,16,0,0,0,0,0,12,0,0},
            {15,0,15,0,0,20,0,0,15,0,0},
            {13,13,16,0,0,15,0,0,0,0,0},
            {20,0,15,0,0,0,0,0,0,0,0},
            {10,0,16,0,0,0,0,0,0,0,0},
            {15,0,16,0,0,6,0,0,8,0,0},
            {15,0,16,0,0,0,0,0,0,0,0},
            {15,0,16,0,0,0,0,0,0,0,0},
            };
        for (int b = 0;
             b < nhgClsRows();
             ++b) {
            int vals[11];
            vals[0] = nhgClsCleric(b);
            vals[1] = nhgClsDruid(b);
            vals[2] = nhgClsFighterLo(b);
            vals[3] = nhgClsFighterHi(b);
            vals[4] = nhgClsRanger(b);
            vals[5] = nhgClsMagUser(b);
            vals[6] = nhgClsIllus(b);
            vals[7] = nhgClsThief(b);
            vals[8] = nhgClsAssassin(b);
            vals[9] = nhgClsMonk(b);
            vals[10] = nhgClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CnhgCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CnhgAbi[20][9] = {
            {23,5,11,17,8,0,24,7,0},
            {25,7,14,19,17,23,24,21,0},
            {25,7,14,23,20,21,25,19,0},
            {21,4,9,25,25,25,21,25,0},
            {25,7,14,20,18,21,21,23,0},
            {21,4,9,21,16,21,21,3,0},
            {19,3,7,23,19,25,21,24,0},
            {25,7,14,14,10,19,20,16,0},
            {25,7,14,19,20,19,25,17,0},
            {20,3,8,19,17,20,22,-2,0},
            {20,3,8,23,22,24,22,24,0},
            {19,3,7,25,25,25,23,22,0},
            {22,4,10,19,9,19,19,19,0},
            {21,4,9,20,10,21,23,11,0},
            {23,5,11,20,19,20,22,7,0},
            {21,4,9,22,18,22,21,19,0},
            {25,7,14,18,12,17,19,-1,0},
            {22,4,10,19,18,23,24,8,0},
            {25,0,0,18,18,19,25,16,0},
            {21,4,9,18,17,19,19,-2,0},
            };
        for (int b = 0;
             b < nhgAbiRows();
             ++b) {
            int vals[9];
            vals[0] = nhgAbiStr(b);
            vals[1] = nhgAbiStrHit(b);
            vals[2] = nhgAbiStrDmg(b);
            vals[3] = nhgAbiInt(b);
            vals[4] = nhgAbiWis(b);
            vals[5] = nhgAbiDex(b);
            vals[6] = nhgAbiCon(b);
            vals[7] = nhgAbiCha(b);
            vals[8] = nhgAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CnhgAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CnhgRos[20][8] = {
            {0,105,8,0,0,1,1,0},
            {1,105,4,0,5,2,0,1},
            {2,106,0,1,6,3,1,0},
            {3,106,2,1,1,4,1,1},
            {4,107,2,0,3,4,1,1},
            {5,107,8,0,0,5,1,0},
            {6,108,2,0,1,4,0,1},
            {7,108,8,0,6,6,1,0},
            {8,108,4,0,6,9,1,0},
            {9,109,6,1,6,7,1,0},
            {10,109,0,1,0,8,1,0},
            {11,109,0,1,0,3,0,1},
            {12,110,6,0,6,7,1,0},
            {13,110,7,0,3,11,1,0},
            {14,111,4,0,2,10,1,1},
            {15,111,4,0,2,10,1,0},
            {16,111,8,3,6,5,1,0},
            {17,112,6,1,5,7,1,0},
            {18,112,6,0,1,7,1,0},
            {19,112,8,3,0,5,1,0},
            };
        for (int b = 0;
             b < nhgRosRows();
             ++b) {
            int vals[8];
            vals[0] = nhgRosOrd(b);
            vals[1] = nhgRosPage(b);
            vals[2] = nhgRosAlign(b);
            vals[3] = nhgRosRank(b);
            vals[4] = nhgRosPsiClass(b);
            vals[5] = nhgRosPlane(b);
            vals[6] = nhgRosDmgFixed(b);
            vals[7] = nhgRosInEach(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CnhgRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the twenty beings, the rank and
        // plane counts)
    if (nhgTableCount() != 4
            || nhgBeingCount() != 20
            || nhgCbtRows() != 20
            || nhgClsRows() != 20
            || nhgAbiRows() != 20
            || nhgRosRows() != 20
            || nhgGreaterCount() != 6
            || nhgLesserCount() != 12
            || nhgDemigodCount() != 2
            || nhgPlaneCount() != 11
            || nhgNineHellsCount() != 4
            || nhgOlympusCount() != 3
            || nhgAbyssCount() != 3
            || nhgSevenHeavensCount() != 2
            || nhgConcordantCount() != 2
            || nhgAsMonsterHDCount() != 12
            || nhgRegistryFloor() != 995
            || nhgChainCount() != 0
        )
            ++bad;
        // the print walk spans pp. 105-112 and the roster ordinals run 0-19
        // in print order
    if (nhgPrintStart() != 105
            || nhgPrintEnd() != 112
            || nhgRosOrd(0) != 0
            || nhgRosOrd(19) != 19
            || nhgRosPage(0) != 105
            || nhgRosPage(19) != 112
            || nhgRosPage(2) != 106
            || nhgRosPage(4) != 107
            || nhgRosPage(7) != 108
            || nhgRosPage(9) != 109
            || nhgRosPage(12) != 110
            || nhgRosPage(14) != 111
            || nhgRosRank(2) != 1
            || nhgRosRank(16) != 3
            || nhgRosRank(0) != 0
        )
            ++bad;
        // the MORADIN-CORELLON FOLD SWAP resolved by tsv geometry: Moradin S
        // 25 (+7,+14) and Corellon S 21 (+4,+9)
    if (nhgAbiStr(2) != 25
            || nhgAbiStrHit(2) != 7
            || nhgAbiStrDmg(2) != 14
            || nhgAbiInt(2) != 23
            || nhgAbiWis(2) != 20
            || nhgAbiDex(2) != 21
            || nhgAbiCon(2) != 25
            || nhgAbiCha(2) != 19
            || nhgMoradinChaToDwarves() != 25
            || nhgAbiStr(3) != 21
            || nhgAbiStrHit(3) != 4
            || nhgAbiStrDmg(3) != 9
            || nhgAbiInt(3) != 25
            || nhgAbiWis(3) != 25
            || nhgAbiDex(3) != 25
            || nhgAbiCon(3) != 21
            || nhgAbiCha(3) != 25
        )
            ++bad;
        // Moradin the Soul Forger: the minus 9 armor class, the 400 hit
        // points, the +5 hammer, the psionic VI
    if (nhgCbtAC(2) != -9
            || nhgCbtHP(2) != 400
            || nhgCbtAtN(2) != 2
            || nhgCbtMR(2) != 60
            || nhgCbtSizeIn(2) != 240
            || nhgClsCleric(2) != 15
            || nhgClsDruid(2) != 14
            || nhgClsFighterLo(2) != 20
            || nhgClsMagUser(2) != 19
            || nhgRosPsiClass(2) != 6
            || nhgRosPlane(2) != 3
            || nhgMoradinHammerPlus() != 5
            || nhgMoradinHammerHigh() != 40
        )
            ++bad;
        // Corellon Larethian the Ranger Lord: the 15/18 dual move, the 95
        // percent resistance, the in-each triple
    if (nhgCbtAC(3) != -4
            || nhgCbtMove(3) != 15
            || nhgCbtMoveAlt(3) != 18
            || nhgCbtHP(3) != 350
            || nhgCbtMR(3) != 95
            || nhgCbtSizeIn(3) != 84
            || nhgClsCleric(3) != 13
            || nhgClsRanger(3) != 20
            || nhgClsMagUser(3) != 20
            || nhgClsIllus(3) != 20
            || nhgClsBard(3) != 15
            || nhgRosInEach(3) != 1
            || nhgCorellonSwordPlus() != 5
            || nhgCorellonBowHigh() != 20
        )
            ++bad;
        // Lolth the demon queen: the -10 (-2) print, the 1/9 web walk, the 66
        // hit points, the See below 99 pairs
    if (nhgCbtAC(5) != -10
            || nhgCbtACAlt(5) != -2
            || nhgCbtHP(5) != 66
            || nhgCbtMove(5) != 1
            || nhgCbtMoveAlt(5) != 9
            || nhgCbtAtN(5) != 1
            || nhgCbtAtD(5) != 1
            || nhgCbtMR(5) != 70
            || nhgCbtSizeIn(5) != 0
            || nhgClsCleric(5) != 99
            || nhgClsDruid(5) != 99
            || nhgClsMagUser(5) != 99
            || nhgClsIllus(5) != 99
            || nhgAbiCha(5) != 3
            || nhgLolthDrowMove() != 15
            || nhgLolthDrowClericLevel() != 16
            || nhgLolthDrowMagUserLevel() != 14
            || nhgLolthChaDrow() != 23
            || nhgLolthHolyWaterHigh() != 21
            || nhgLolthGatePct() != 66
            || nhgLolthBiteHigh() != 16
        )
            ++bad;
        // the Lolth discipline walk: the three devotions and four sciences at
        // the 16th level
    if (nhgLolthDisciplineLevel() != 16
            || nhgLolthPoisonSaveMod() != -4
            || nhgLolthHealsPerDay() != 3
            || nhgLolthPoisonOnePct() != 45
            || nhgLolthPoisonTwoPct() != 35
            || nhgLolthPoisonThreePct() != 20
            || nhgLolthSummonLargePct() != 20
            || nhgLolthSummonHugePct() != 30
            || nhgLolthSummonGiantPct() != 40
            || nhgLolthSummonPhasePct() != 10
            || nhgLolthHolyWaterSplash() != 6
            || nhgLolthSightRange() != 120
            || nhgLolthWebRange() != 30
            || nhgLolthWebDmgHigh() != 4
        )
            ++bad;
        // Skerrit the Variable god: the at-least-2 floor, the zero sentinels,
        // the centaur-form consts
    if (nhgCbtAC(1) != 2
            || nhgCbtMove(1) != 0
            || nhgCbtAtN(1) != 0
            || nhgCbtSizeIn(1) != 0
            || nhgCbtHP(1) != 290
            || nhgCbtMR(1) != 35
            || nhgClsCleric(1) != 14
            || nhgClsDruid(1) != 14
            || nhgClsIllus(1) != 10
            || nhgClsBard(1) != 9
            || nhgRosPsiClass(1) != 5
            || nhgRosPlane(1) != 2
            || nhgSkerritACFloor() != 2
            || nhgSkerritFormAC() != 2
            || nhgSkerritFormMove() != 21
            || nhgSkerritForestToHit() != -4
            || nhgSkerritSpearPlus() != 3
            || nhgSkerritSpearHigh() != 20
        )
            ++bad;
        // Deep Sashelas: the Standard-out-of-water resistance pinned 0 with
        // the 100 percent underwater const
    if (nhgCbtAC(4) != -3
            || nhgCbtMove(4) != 12
            || nhgCbtMoveAlt(4) != 24
            || nhgCbtHP(4) != 300
            || nhgCbtMR(4) != 0
            || nhgCbtSizeIn(4) != 84
            || nhgClsCleric(4) != 19
            || nhgClsFighterLo(4) != 15
            || nhgClsMagUser(4) != 12
            || nhgClsIllus(4) != 12
            || nhgClsBard(4) != 10
            || nhgRosPsiClass(4) != 3
            || nhgSashelasWaterMR() != 100
            || nhgSashelasDolphins() != 20
            || nhgAbiDex(4) != 21
            || nhgAbiCha(4) != 23
        )
            ++bad;
        // the fraction size cells: Yondalla 4 1/2 foot = 54 and Kurtulmak 5
        // 1/2 foot = 66
    if (nhgCbtSizeIn(11) != 54
            || nhgCbtSizeIn(12) != 66
            || nhgFractionSizeCount() != 2
            || nhgCbtAtN(11) != 3
            || nhgCbtAtD(11) != 2
            || nhgCbtAC(11) != 2
            || nhgCbtMR(11) != 75
            || nhgClsIllus(11) != 25
            || nhgClsThief(11) != 15
            || nhgClsDruid(11) != 12
            || nhgCbtAC(12) != 0
            || nhgCbtHP(12) != 219
            || nhgCbtMR(12) != 55
            || nhgClsAssassin(12) != 12
            || nhgRosPsiClass(12) != 6
        )
            ++bad;
        // the KURTULMAK-BLIBDOOLPOOLP TAIL SWAP resolved by geometry: the
        // assassin, psionic and ability lines
    if (nhgAbiStr(12) != 22
            || nhgAbiStrHit(12) != 4
            || nhgAbiStrDmg(12) != 10
            || nhgAbiInt(12) != 19
            || nhgAbiWis(12) != 9
            || nhgAbiDex(12) != 19
            || nhgAbiCon(12) != 19
            || nhgAbiCha(12) != 19
            || nhgKurtulmakSpearPlus() != 4
            || nhgKurtulmakSpearHigh() != 24
            || nhgKurtulmakTailHigh() != 6
            || nhgKurtulmakFearFeet() != 10
            || nhgAbiStr(13) != 21
            || nhgAbiInt(13) != 20
            || nhgAbiWis(13) != 10
            || nhgAbiDex(13) != 21
            || nhgAbiCon(13) != 23
            || nhgAbiCha(13) != 11
            || nhgClsAssassin(13) != 15
            || nhgClsMagUser(13) != 20
            || nhgRosPsiClass(13) != 3
            || nhgRosPlane(13) != 11
        )
            ++bad;
        // Blibdoolpoolp the Sea Mother: the gaze insanity, the summons and
        // the gem-favor calculus
    if (nhgCbtAC(13) != -1
            || nhgCbtMoveAlt(13) != 48
            || nhgCbtHP(13) != 310
            || nhgCbtSizeIn(13) != 240
            || nhgBlibClawHigh() != 24
            || nhgBlibGazeSaveMod() != -4
            || nhgBlibSummonLobsterLow() != 3
            || nhgBlibSummonLobsterHigh() != 30
            || nhgBlibSummonElementalHigh() != 10
            || nhgBlibElementalHD() != 16
            || nhgBlibGemFavorPerGp() != 1000
            || nhgBlibPearlPerGp() != 500
            || nhgKuoToanClericMax() != 12
        )
            ++bad;
        // Hruggek and the not-printed dex cell: the geometry catch of the
        // bare inter-cell gap
    if (nhgCbtAC(0) != 0
            || nhgCbtHP(0) != 221
            || nhgCbtAtN(0) != 1
            || nhgCbtAtD(0) != 2
            || nhgCbtMR(0) != 25
            || nhgCbtSizeIn(0) != 144
            || nhgClsCleric(0) != 15
            || nhgClsFighterLo(0) != 16
            || nhgAbiStr(0) != 23
            || nhgAbiStrHit(0) != 5
            || nhgAbiStrDmg(0) != 11
            || nhgAbiInt(0) != 17
            || nhgAbiWis(0) != 8
            || nhgAbiDex(0) != 0
            || nhgAbiCon(0) != 24
            || nhgAbiCha(0) != 7
            || nhgHruggekChaToBugbears() != 23
            || nhgHruggekMorningstarHigh() != 30
            || nhgHruggekClawHigh() != 16
        )
            ++bad;
        // the giant and goblinoid gods: Grolantor, Skoraeus, Maglubiyet and
        // Gruumsh
    if (nhgCbtAC(7) != 0
            || nhgCbtMove(7) != 21
            || nhgCbtHP(7) != 259
            || nhgCbtMR(7) != 45
            || nhgCbtSizeIn(7) != 300
            || nhgRosPlane(7) != 6
            || nhgGrolantorClubHigh() != 40
            || nhgCbtAC(8) != 0
            || nhgCbtHP(8) != 380
            || nhgCbtMR(8) != 50
            || nhgCbtSizeIn(8) != 360
            || nhgRosPlane(8) != 9
            || nhgSkoraeusFistHigh() != 60
            || nhgSkoraeusEarthquakeLevel() != 30
            || nhgCbtAC(9) != -2
            || nhgCbtHP(9) != 350
            || nhgCbtSizeIn(9) != 132
            || nhgAbiCha(9) != -2
            || nhgClsIllus(9) != 6
            || nhgClsAssassin(9) != 10
            || nhgRosPlane(9) != 7
            || nhgCbtAC(17) != -1
            || nhgCbtMR(17) != 75
            || nhgAbiCha(17) != 8
            || nhgGruumshSpearPlus() != 5
            || nhgGruumshChaToOrcs() != 25
            || nhgClsAssassin(17) != 8
        )
            ++bad;
        // Garl Glittergold and Yondalla: the 3/2 attack pairs, the Arumdina
        // axe and the withering wave
    if (nhgCbtAC(10) != -2
            || nhgCbtHP(10) != 350
            || nhgCbtAtN(10) != 3
            || nhgCbtAtD(10) != 2
            || nhgCbtMR(10) != 25
            || nhgCbtSizeIn(10) != 48
            || nhgClsThief(10) != 20
            || nhgClsIllus(10) != 16
            || nhgClsBard(10) != 8
            || nhgRosPlane(10) != 8
            || nhgGarlAxePlus() != 5
            || nhgGarlAxeHigh() != 30
            || nhgYondallaWitherCharges() != 3
            || nhgYondallaWitherLow() != 2
            || nhgYondallaWitherHigh() != 5
            || nhgYondallaWitherAge() != 10
        )
            ++bad;
        // the neutral water gods: Semuanya and Eadro on Concordant Opposition
    if (nhgCbtAC(14) != -4
            || nhgCbtHP(14) != 211
            || nhgCbtMR(14) != 78
            || nhgCbtSizeIn(14) != 144
            || nhgAbiStr(14) != 23
            || nhgAbiCha(14) != 7
            || nhgSemuanyaChaToLizardMen() != 25
            || nhgSemuanyaRegen() != 5
            || nhgSemuanyaSummonHigh() != 18
            || nhgRosPlane(14) != 10
            || nhgCbtAC(15) != 0
            || nhgCbtACAlt(15) != -6
            || nhgCbtAtN(15) != 1
            || nhgCbtAtD(15) != 8
            || nhgCbtMR(15) != 72
            || nhgClsCleric(15) != 20
            || nhgEadroWhipCount() != 8
            || nhgEadroWhipHigh() != 10
            || nhgEadroSummonHigh() != 8
            || nhgEadroElementalHD() != 16
            || nhgRosPlane(15) != 10
        )
            ++bad;
        // Vaprak the Destroyer: the three claws, the regeneration 7 and the
        // berserk calculus
    if (nhgCbtAC(16) != 0
            || nhgCbtHP(16) != 198
            || nhgCbtAtN(16) != 3
            || nhgCbtMR(16) != 50
            || nhgCbtSizeIn(16) != 180
            || nhgAbiStr(16) != 25
            || nhgAbiWis(16) != 12
            || nhgAbiCha(16) != -1
            || nhgRosRank(16) != 3
            || nhgRosPlane(16) != 5
            || nhgVaprakRegen() != 7
            || nhgVaprakBerserkPct() != 2
            || nhgVaprakBerserkHit() != 2
            || nhgVaprakBerserkAC() != -2
            || nhgVaprakClawHigh() != 20
        )
            ++bad;
        // Sekolah and Laogzed: the shark swallow and the troglodyte acid skin
    if (nhgCbtAC(18) != 0
            || nhgCbtMove(18) != 36
            || nhgCbtHP(18) != 329
            || nhgCbtMR(18) != 47
            || nhgCbtSizeIn(18) != 420
            || nhgAbiStr(18) != 25
            || nhgAbiStrHit(18) != 0
            || nhgAbiStrDmg(18) != 0
            || nhgAbiCha(18) != 16
            || nhgRosPsiClass(18) != 1
            || nhgSekolahBiteHigh() != 60
            || nhgSekolahSwallowRoll() != 16
            || nhgSekolahHolySharksHigh() != 3
            || nhgCbtMR(19) != 29
            || nhgCbtHP(19) != 187
            || nhgAbiCha(19) != -2
            || nhgRosRank(19) != 3
            || nhgLaogzedAcidHigh() != 18
            || nhgLaogzedAcidSaveMod() != -4
            || nhgLaogzedBiteHigh() != 60
        )
            ++bad;
        // the shaman doctrine of the intro: the hit dice ladder, the three
        // examples and the NOTE list
    if (nhgShamanHpLow() != 1
            || nhgShamanHpHigh() != 4
            || nhgWitchHpLow() != 2
            || nhgWitchHpHigh() != 5
            || nhgHdBetterLevels() != 2
            || nhgGnollBaseHd() != 2
            || nhgGnollBonusDice() != 3
            || nhgGnollFightsHd() != 4
            || nhgGoblinDice() != 4
            || nhgGoblinBonusHigh() != 7
            || nhgGoblinFightsHd() != 3
            || nhgOrcDice() != 1
            || nhgOrcBonusDice() != 2
            || nhgOrcBonusHp() != 2
            || nhgOrcFightsHd() != 2
            || nhgOrcWitchLevel() != 3
            || nhgNoteLesserGods() != 13
            || nhgNoteMMCount() != 10
            || nhgNoteFFCount() != 3
        )
            ++bad;
        printf("R864 nonhumans' deities audit: bad %d\n", bad);
        if (bad) return 1;
    }
