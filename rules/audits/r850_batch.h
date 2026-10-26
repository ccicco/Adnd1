    // ---- R850 American Indian mythos audit ----
    // THE AMERICAN INDIAN MYTHOS - the D&DG walk round two, print pp. 12-16:
    // fourteen beings (Raven, Coyote, Hastsezini, Hastseltsi, Heng, Hiawatha,
    // Hotoru, Qagwaaz, Shakak, Snake-Man, Stoneribs, the Thunder Bird,
    // Yanauluha, Tobadzistsini), the pantheon-wide cleric doctrine, and the
    // sacred bundle. Zero registry defs touched; the floor holds at 995. The
    // flagged eyeball cells: Hastsezini CH -1 and Shakak CH 6.
    {
        using namespace rules;
        int bad = 0;
    if (dgbRound() != 850
            || dgbPrintStart() != 12
            || dgbPrintEnd() != 16
            || dgbBeingCount() != 14
            || dgbTableCount() != 4
            || dgbChainCount() != 0
            || dgbRegistryFloor() != 995
            || dgbCbtRows() != 14
            || dgbClsRows() != 14
            || dgbAbiRows() != 14
            || dgbRosRows() != 14
            || dgbPsiClassMax() != 6
            || dgbBundleSaveBonus() != 2
            || dgbBundleSurpriseDen() != 6
            || dgbBundleAC() != 2
            || dgbBundleDmgPerDie() != 1
            || dgbBundleMinItems() != 5
            || dgbBundleMaxItems() != 10
            || dgbRavenDmg1Lo() != 3
            || dgbRavenDmg1Hi() != 18
            || dgbRavenDmg2Lo() != 3
            || dgbRavenDmg2Hi() != 18
            || dgbRavenDmg3Lo() != 3
            || dgbRavenDmg3Hi() != 30
            || dgbRavenPolySaveMod() != 3
            || dgbCoyoteBiteLo() != 3
            || dgbCoyoteBiteHi() != 30
            || dgbHastseAuraLo() != 2
            || dgbHastseAuraHi() != 20
            || dgbHastseAuraRange() != 10
            || dgbHastseFireSense() != 50
            || dgbHastseShieldPlus() != 5
            || dgbHastseBowLo() != 1
            || dgbHastseBowHi() != 10
            || dgbHastseAxeLo() != 2
            || dgbHastseAxeHi() != 20
            || dgbHastseLanceLo() != 3
            || dgbHastseLanceHi() != 30
            || dgbHastsePressCount() != 5
            || dgbHastsePressLevel() != 30
            || dgbHastseltsiHorseAC() != 5
            || dgbHastseltsiHorseHD() != 15
            || dgbHastseltsiHorseHP() != 70
            || dgbHastseltsiHorseAtN() != 3
            || dgbHastseltsiHorseDmg1Lo() != 2
            || dgbHastseltsiHorseDmg1Hi() != 20
            || dgbHastseltsiHorseDmg3Lo() != 1
            || dgbHastseltsiHorseDmg3Hi() != 12
            || dgbHastseltsiAxeLo() != 2
            || dgbHastseltsiAxeHi() != 12
            || dgbHastseltsiAxePlus() != 3
            || dgbHastseltsiKnifeLo() != 1
            || dgbHastseltsiKnifeHi() != 10
            || dgbHastseltsiKnifePlus() != 2
            || dgbHastseltsiDmgMod() != 14
            || dgbHengBowLo() != 6
            || dgbHengBowHi() != 60
            || dgbHengBowRangeMiles() != 30
            || dgbHengLanceLo() != 3
            || dgbHengLanceHi() != 30
            || dgbHengLuckBonus() != 2
            || dgbHengDmgMod() != 12
            || dgbHiawathaHugLo() != 2
            || dgbHiawathaHugHi() != 20
            || dgbHotoruBoltsPerRound() != 3
            || dgbHotoruBoltLo() != 2
            || dgbHotoruBoltHi() != 20
            || dgbHotoruBoltRange() != 900
            || dgbHotoruChiefSaveBonus() != 1
            || dgbShakakAuraDmg() != 20
            || dgbShakakAuraRange() != 30
            || dgbShakakSpearLo() != 3
            || dgbShakakSpearHi() != 30
            || dgbShakakRegenPerRound() != 10
            || dgbShakakDmgMod() != 9
            || dgbSnakemanJewelryGP() != 75000
            || dgbSnakemanSummonLo() != 5
            || dgbSnakemanSummonHi() != 500
            || dgbStoneribsSizeIn() != 66
            || dgbTbirdBoltsPerRound() != 1
            || dgbTbirdBoltDmg() != 30
            || dgbTbirdBoltRangeLo() != 50
            || dgbTbirdBoltRangeHi() != 300
            || dgbTbirdBeakLo() != 1
            || dgbTbirdBeakHi() != 10
            || dgbTbirdWingLo() != 2
            || dgbTbirdWingHi() != 20
            || dgbYanaAppearPct() != 10
            || dgbTobadArrowLo() != 1
            || dgbTobadArrowHi() != 10
            || dgbTobadSpearLo() != 3
            || dgbTobadSpearHi() != 30
            || dgbTobadDmgMod() != 14
            || !dgbGodsPreferCreatureForm()
            || !dgbHumanFormCostly()
            || !dgbControlRequiresPart()
            || !dgbQuestNeedsPart()
            || !dgbNameBlocksCharm()
            || !dgbDemonControlNeedsFire()
            || !dgbSeasonalSacrifice()
            || !dgbClericMeditatesApart()
            || !dgbClericTribeProtector()
            || !dgbRelicsBuriedWithCleric()
            || !dgbRelicsFromVisions()
            || !dgbPatronSymbolReflected()
            || !dgbYoungClericsFight()
            || !dgbOldClericsEnlistGods()
            || !dgbPriestBlessesWarpaint()
            || !dgbLodgeTabooSpirits()
            || !dgbWorshipInTheOpen()
            || !dgbBundleSpiritAdvised()
            || !dgbBundlePriestFinalItem()
            || !dgbRavenTransformer()
            || !dgbRavenFightsAsGiantRaven()
            || !dgbRavenExtraForms()
            || !dgbRavenGreatProvider()
            || !dgbRavenFoodOfferings()
            || !dgbCoyoteTaughtArtsAndFire()
            || !dgbCoyoteBullyingGreedy()
            || !dgbCoyoteBeastCompanions()
            || !dgbCoyoteTricksBackfire()
            || !dgbCoyoteCowardlyThiefRole()
            || !dgbCoyotePolymorphOnceDaily()
            || !dgbCoyoteFleesWhenPossible()
            || !dgbCoyoteFavoriteSpells()
            || !dgbCoyoteThievingAppeals()
            || !dgbHastseBlackUglyFlames()
            || !dgbHastseNoBehindAttack()
            || !dgbHastseBurnsVillages()
            || !dgbHastseNoonOfferings()
            || !dgbHastseBowLineOfSight()
            || !dgbHastseAxeAtStrongest()
            || !dgbHastseLanceNeverThrown()
            || !dgbHastseOffensiveOnly()
            || !dgbHastseltsiRedEquipment()
            || !dgbHastseltsiRacesAnyone()
            || !dgbHastseltsiHidesPower()
            || !dgbHastseltsiHorseEnchanted()
            || !dgbHastseltsiNoProjectileHurt()
            || !dgbHastseltsiSymbolOnLodges()
            || dgbHastseltsiAssassinTrained()
            || !dgbHengPriestsSprinkleWater()
            || !dgbHengThunderCloudForm()
            || !dgbHengFavoredOfTribes()
            || !dgbHiawathaPaladin()
            || !dgbHiawathaManyNames()
            || !dgbHiawathaSelfMovingCanoe()
            || !dgbHiawathaAnimalsWarn()
            || !dgbHiawathaPeacemaker()
            || !dgbHiawathaGreatBear()
            || !dgbHotoruWeatherCrops()
            || !dgbHotoruChiefForm()
            || !dgbHotoruFallenWeapons()
            || !dgbQagwaazPlainsSport()
            || !dgbQagwaazStrengthTests()
            || !dgbQagwaazWoodenClub()
            || !dgbQagwaazExampleForWarriors()
            || !dgbQagwaazFirstInBattle()
            || !dgbShakakColdAtWill()
            || !dgbShakakSacrificeLessensWinter()
            || !dgbShakakNonePrayForFear()
            || !dgbShakakBurnPossessions()
            || !dgbShakakDemonicFace()
            || !dgbShakakColdAuraNoSave()
            || !dgbShakakIceSpear()
            || !dgbShakakRegenBelowFreezing()
            || !dgbSnakemanRainbowSkin()
            || !dgbSnakemanAgesAtWill()
            || !dgbSnakemanControlsReptiles()
            || !dgbSnakemanReptilesNeverAttack()
            || !dgbSnakemanFantasticReptilians()
            || !dgbSnakemanSpellsOnly()
            || !dgbSnakemanSnakesVsImpervious()
            || !dgbStoneribsHalibutCloak()
            || !dgbStoneribsShrinksAtWill()
            || !dgbStoneribsBowOrClub()
            || !dgbStoneribsTribesChampion()
            || !dgbStoneribsYearService()
            || !dgbTbirdUnique()
            || !dgbTbirdIntGenius()
            || !dgbTbirdNeverSurprised()
            || !dgbTbirdThunderWings()
            || !dgbTbirdComesOfOwnWill()
            || !dgbYanaFirstCleric()
            || !dgbYanaSummonsPantheon()
            || !dgbYanaFriendlySpirit()
            || !dgbYanaInvokedForBoons()
            || !dgbYanaNotWorshiped()
            || !dgbYanaOldManForm()
            || !dgbYanaNeutral()
            || !dgbTobadBuiltMaleForm()
            || !dgbTobadShapeChange()
            || !dgbTobadWhimsicalBattles()
            || !dgbTobadBoostsOneSide()
            || !dgbTobadSpearHandToHand()
            || !dgbTobadKillsBurned()
        )
            ++bad;
        // the combat stat blocks of the fourteen beings (print pp. 12-16) -
        // the AC, hit points, move, attacks, magic resistance and size letter
        int CCbt[14][8] = {
            {0,400,24,0,3,0,75,0},
            {2,330,24,0,2,0,75,1},
            {-3,320,21,0,2,0,45,0},
            {3,320,24,48,2,0,50,0},
            {2,250,12,24,3,2,20,1},
            {5,200,15,0,2,0,0,0},
            {-2,200,12,24,3,2,30,1},
            {6,150,15,0,3,2,0,0},
            {-2,390,12,0,2,0,90,1},
            {-2,350,12,18,0,0,75,0},
            {6,150,15,0,3,2,0,0},
            {-2,200,15,24,2,0,32,1},
            {3,200,12,0,3,2,30,0},
            {-2,344,15,0,2,0,30,0},
            };
        int nCbt[8] = {0,0,0,0,0,0,0,0};
        int eCbt[8] = {1,0,0,9,1,9,3,9};
        for (int b = 0;
             b < dgbCbtRows();
             ++b) {
            int vals[8];
            vals[0] = dgbCbtAC(b);
            vals[1] = dgbCbtHP(b);
            vals[2] = dgbCbtMove(b);
            vals[3] = dgbCbtMoveAlt(b);
            vals[4] = dgbCbtAtN(b);
            vals[5] = dgbCbtAtD(b);
            vals[6] = dgbCbtMR(b);
            vals[7] = dgbCbtSize(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CCbt[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nCbt[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nCbt[c] != eCbt[c])
                ++bad;
        // the cleric/druid, fighter, magic-user/illusionist, thief/assassin
        // and monk/bard level lines of the fourteen beings (0 = Nil or none
        // printed)
        int CCls[14][10] = {
            {12,12,0,10,16,16,14,0,0,0},
            {14,14,15,0,14,17,18,0,0,0},
            {12,12,0,12,0,0,0,0,0,0},
            {10,0,0,15,12,12,0,12,0,0},
            {10,0,0,10,12,12,0,0,0,0},
            {0,8,15,10,0,0,0,0,0,0},
            {0,0,10,0,10,10,0,0,0,0},
            {0,0,0,12,0,0,0,0,0,5},
            {0,0,0,12,15,0,0,0,0,0},
            {10,10,0,0,15,15,8,0,0,5},
            {0,0,0,10,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {20,13,0,10,9,9,0,0,0,0},
            {10,10,0,18,10,10,0,10,8,0},
            };
        int nCls[10] = {0,0,0,0,0,0,0,0,0,0};
        int eCls[10] = {6,7,11,4,5,6,11,12,13,12};
        for (int b = 0;
             b < dgbClsRows();
             ++b) {
            int vals[10];
            vals[0] = dgbClsCleric(b);
            vals[1] = dgbClsDruid(b);
            vals[2] = dgbClsFighter(b);
            vals[3] = dgbClsRanger(b);
            vals[4] = dgbClsMagUser(b);
            vals[5] = dgbClsIllus(b);
            vals[6] = dgbClsThief(b);
            vals[7] = dgbClsAssassin(b);
            vals[8] = dgbClsMonk(b);
            vals[9] = dgbClsBard(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CCls[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nCls[c];
            }
        }
        for (int c = 0; c < 10; ++c)
            if (nCls[c] != eCls[c])
                ++bad;
        // the S/I/W/D/C/CH ability lines with the parenthesized strength
        // bonuses and the psionic classes (the Thunder Bird row is all 0 -
        // the monster-format being prints no ability line)
        int CAbi[14][9] = {
            {19,3,7,24,24,25,23,22,6},
            {20,3,8,24,19,24,21,16,3},
            {24,6,12,20,19,23,24,-1,2},
            {25,7,14,19,18,25,24,22,4},
            {24,6,12,23,23,22,24,20,6},
            {21,4,9,18,18,19,19,18,0},
            {23,5,11,23,20,23,23,20,6},
            {19,3,7,18,19,18,18,18,0},
            {21,4,9,19,19,20,24,6,6},
            {24,0,0,24,19,23,24,20,3},
            {19,3,7,15,14,18,19,15,0},
            {0,0,0,0,0,0,0,0,0},
            {14,0,0,20,20,18,19,18,0},
            {25,7,14,20,19,25,25,20,4},
            };
        int nAbi[9] = {0,0,0,0,0,0,0,0,0};
        int eAbi[9] = {1,3,3,1,1,1,1,1,5};
        for (int b = 0;
             b < dgbAbiRows();
             ++b) {
            int vals[9];
            vals[0] = dgbAbiStr(b);
            vals[1] = dgbAbiStrHit(b);
            vals[2] = dgbAbiStrDmg(b);
            vals[3] = dgbAbiInt(b);
            vals[4] = dgbAbiWis(b);
            vals[5] = dgbAbiDex(b);
            vals[6] = dgbAbiCon(b);
            vals[7] = dgbAbiCha(b);
            vals[8] = dgbAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CAbi[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nAbi[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nAbi[c] != eAbi[c])
                ++bad;
        // the roster of the fourteen beings: ordinals, ranks, print pages,
        // planes, alignments, worshiper alignments, the in-lair percent and
        // the experience values
        int CRos[14][9] = {
            {0,0,12,2,0,1,1,0,0},
            {1,1,12,1,0,0,2,0,0},
            {2,1,13,3,1,-1,3,0,0},
            {3,1,13,1,0,0,1,0,0},
            {4,1,13,2,1,1,4,0,0},
            {5,2,14,0,1,1,0,0,0},
            {6,1,14,2,0,1,5,0,0},
            {7,2,15,0,0,1,0,0,0},
            {8,0,15,1,0,-1,3,0,0},
            {9,0,15,1,0,1,5,0,0},
            {10,2,15,0,1,1,0,0,0},
            {11,3,16,0,0,1,0,25,22600},
            {12,4,16,0,0,0,0,0,0},
            {13,1,16,1,1,-1,6,0,0},
            };
        int nRos[9] = {0,0,0,0,0,0,0,0,0};
        int eRos[9] = {1,3,0,5,9,3,5,13,13};
        for (int b = 0;
             b < dgbRosRows();
             ++b) {
            int vals[9];
            vals[0] = dgbRosOrd(b);
            vals[1] = dgbRosRank(b);
            vals[2] = dgbRosPage(b);
            vals[3] = dgbRosPlane(b);
            vals[4] = dgbRosLaw(b);
            vals[5] = dgbRosGood(b);
            vals[6] = dgbRosWorship(b);
            vals[7] = dgbRosLairPct(b);
            vals[8] = dgbRosXP(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CRos[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nRos[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nRos[c] != eRos[c])
                ++bad;
        // the census walk (the four grids, the fourteen beings)
    if (dgbTableCount() != 4
            || dgbBeingCount() != 14
            || dgbCbtRows() != 14
            || dgbClsRows() != 14
            || dgbAbiRows() != 14
            || dgbRosRows() != 14
        )
            ++bad;
        // the print walk spans pp. 12-16 (the folio offset PRINT = PDF - 1)
    if (dgbPrintStart() != 12
            || dgbPrintEnd() != 16
            || dgbRosPage(0) != 12
            || dgbRosPage(11) != 16
            || dgbRosPage(13) != 16
        )
            ++bad;
        // the roster ordinals run 0-13 in print order (Raven first,
        // Tobadzistsini last)
    if (dgbRosOrd(0) != 0
            || dgbRosOrd(1) != 1
            || dgbRosOrd(11) != 11
            || dgbRosOrd(13) != 13
        )
            ++bad;
        // the greater gods are Raven, Shakak and Snake-Man (rank 0)
    if (dgbRosRank(0) != 0
            || dgbRosRank(8) != 0
            || dgbRosRank(9) != 0
        )
            ++bad;
        // the unique Thunder Bird rides rank 3, the first priest rank 4
    if (dgbRosRank(11) != 3
            || dgbRosRank(12) != 4
        )
            ++bad;
        // the printed 3/2 attacks (the adjudicated Heng/Hotoru/Yanauluha
        // cells)
    if (dgbCbtAtN(4) != 3
            || dgbCbtAtD(4) != 2
            || dgbCbtAtN(6) != 3
            || dgbCbtAtD(6) != 2
            || dgbCbtAtN(12) != 3
            || dgbCbtAtD(12) != 2
        )
            ++bad;
        // the 3/2 heroes Qagwaaz and Stoneribs, and the single-figure gods
    if (dgbCbtAtN(7) != 3
            || dgbCbtAtD(7) != 2
            || dgbCbtAtN(10) != 3
            || dgbCbtAtD(10) != 2
            || dgbCbtAtD(0) != 0
            || dgbCbtAtD(9) != 0
        )
            ++bad;
        // the flagged eyeball cell: Hastsezini CH -1 (both voices, the
        // horror-table doctrine)
    if (dgbAbiCha(2) != -1
        )
            ++bad;
        // the flagged eyeball cell: Shakak CH 6 (both voices, four glyphs)
    if (dgbAbiCha(8) != 6
        )
            ++bad;
        // the psionic class adjudications: Coyote III, Hastsezini II (the
        // IA-geometry 47px voice)
    if (dgbAbiPsi(1) != 3
            || dgbAbiPsi(2) != 2
        )
            ++bad;
        // the psionic class VI beings (Raven, Heng, Hotoru, Shakak) against
        // the class ceiling
    if (dgbAbiPsi(0) != 6
            || dgbAbiPsi(4) != 6
            || dgbAbiPsi(6) != 6
            || dgbAbiPsi(8) != 6
            || dgbPsiClassMax() != 6
        )
            ++bad;
        // the Thunder Bird xp line X/22,600 (both voices) and the 25 percent
        // in lair
    if (dgbRosXP(11) != 22600
            || dgbRosLairPct(11) != 25
        )
            ++bad;
        // the Raven damage/attack triple 3-18/3-18/3-30 and the -3 polymorph
        // save
    if (dgbRavenDmg1Lo() != 3
            || dgbRavenDmg1Hi() != 18
            || dgbRavenDmg2Hi() != 18
            || dgbRavenDmg3Hi() != 30
            || dgbRavenPolySaveMod() != 3
        )
            ++bad;
        // the sacred bundle: +2 saves, surprised only on 1 in 6, AC 2, one
        // point off each damage die, 5-10 items
    if (dgbBundleSaveBonus() != 2
            || dgbBundleSurpriseDen() != 6
            || dgbBundleAC() != 2
            || dgbBundleDmgPerDie() != 1
            || dgbBundleMinItems() != 5
            || dgbBundleMaxItems() != 10
        )
            ++bad;
        // the Hastsezini fire-walk: 2-20 aura at 10 yards, the 50-yard fire
        // sense, the +5 shield, the 30th-level pressed casting
    if (dgbHastseAuraLo() != 2
            || dgbHastseAuraHi() != 20
            || dgbHastseAuraRange() != 10
            || dgbHastseFireSense() != 50
            || dgbHastseShieldPlus() != 5
            || dgbHastsePressLevel() != 30
        )
            ++bad;
        // the Hastseltsi horse (AC 5, HD 15, hp 70, 2-20/2-20/1-12) and the
        // +3 axe over the +2 knife
    if (dgbHastseltsiHorseAC() != 5
            || dgbHastseltsiHorseHD() != 15
            || dgbHastseltsiHorseHP() != 70
            || dgbHastseltsiHorseDmg1Hi() != 20
            || dgbHastseltsiHorseDmg3Hi() != 12
            || dgbHastseltsiAxePlus() != 3
            || dgbHastseltsiKnifePlus() != 2
        )
            ++bad;
        // the Heng rain-walk: the 6-60 lightning bow at 30 miles, the 3-30
        // lance, the +2 year luck
    if (dgbHengBowLo() != 6
            || dgbHengBowHi() != 60
            || dgbHengBowRangeMiles() != 30
            || dgbHengLanceHi() != 30
            || dgbHengLuckBonus() != 2
            || dgbHengDmgMod() != 12
        )
            ++bad;
        // the Hotoru storm: three bolts per round, 2-20 each, at 900 yards,
        // the +1 chief saves
    if (dgbHotoruBoltsPerRound() != 3
            || dgbHotoruBoltLo() != 2
            || dgbHotoruBoltHi() != 20
            || dgbHotoruBoltRange() != 900
            || dgbHotoruChiefSaveBonus() != 1
        )
            ++bad;
        // the Shakak winter: 20 points of cold at 30 yards no save, the 3-30
        // ice spear, 10 points of regeneration below freezing
    if (dgbShakakAuraDmg() != 20
            || dgbShakakAuraRange() != 30
            || dgbShakakSpearHi() != 30
            || dgbShakakRegenPerRound() != 10
            || dgbShakakDmgMod() != 9
        )
            ++bad;
        // the Snake-Man: 75,000 gp of jewelry, the 5-500 snake summons, the
        // 90-percent-fire-only note rides the combat grid
    if (dgbSnakemanJewelryGP() != 75000
            || dgbSnakemanSummonLo() != 5
            || dgbSnakemanSummonHi() != 500
            || dgbCbtMR(9) != 75
        )
            ++bad;
        // the Stoneribs size 5 and one half feet (the adjudicated
        // garbled-size cell, 66 inches)
    if (dgbStoneribsSizeIn() != 66
        )
            ++bad;
        // the Thunder Bird: one bolt per round for 30 (save half) at 50-300
        // yards, the 1-10 beak over the 2-20 wings
    if (dgbTbirdBoltsPerRound() != 1
            || dgbTbirdBoltDmg() != 30
            || dgbTbirdBoltRangeLo() != 50
            || dgbTbirdBoltRangeHi() != 300
            || dgbTbirdBeakHi() != 10
            || dgbTbirdWingHi() != 20
        )
            ++bad;
        // the Yanauluha 10 percent appearance chance, and the Tobadzistsini
        // 1-10 arrows over the 3-30 spear (+14)
    if (dgbYanaAppearPct() != 10
            || dgbTobadArrowLo() != 1
            || dgbTobadArrowHi() != 10
            || dgbTobadSpearHi() != 30
            || dgbTobadDmgMod() != 14
        )
            ++bad;
        // the class-grid doctrine: the "in each" pairs (Raven 12/12 and
        // 16/16, Coyote 14/14 and 14/17, Snake-Man 10/10 and 15/15)
    if (dgbClsCleric(0) != 12
            || dgbClsDruid(0) != 12
            || dgbClsMagUser(0) != 16
            || dgbClsIllus(0) != 16
            || dgbClsIllus(1) != 17
            || dgbClsMagUser(9) != 15
            || dgbClsIllus(9) != 15
        )
            ++bad;
        // the Yanauluha split line: 13th level druid over 20th level cleric
    if (dgbClsDruid(12) != 13
            || dgbClsCleric(12) != 20
        )
            ++bad;
        printf("R850 American Indian mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
