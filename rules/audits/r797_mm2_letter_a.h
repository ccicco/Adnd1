    // ---- R797 MM2 letter A audit ----
    // THE MM2 LETTER A - the first A-Z round of the Monster Manual II arc
    // (the user Go call on the landed opener). The pin-time walk from the
    // print finds TEN entries on pp. 8-12: aboleth, afanc, agathion, annis,
    // ant lion, ascomoid, aspis, atomie, aurumvorax, azer - the opener
    // 7-candidate archive.org walk superseded (the R792 lesson: the print
    // walks at pin time). THIRTEEN defs ride the R791 data_files extension in
    // the MM1 registry schema: the ten stat blocks, the aspis split three
    // ways (drone, larva, cow - the oni multi-form precedent), and the
    // Amaimon paragraph as the azer king sub-entry (the marut sentinel
    // precedent for its unprinted xp and armor class; its unprinted combat
    // lines read the azer kind defaults). THE GRIDS: the 12-row stat grid
    // (every armor class, hit-die, hit, xp and lair cell of the stat blocks),
    // the ant lion lair-items d20, the aspis larva xp ladder, the azer
    // strength bracket grid. THE SETTLED READS: the atomie LEVEL/X.P. prints
    // II/40 + 1/hp - the PDF OCR 11/40 is a roman misread, consistent with
    // the 2-HD aspis larva rung and the azer 2+1 bracket; the annis 7+3-12
    // and the azer 2+1 to 5+4 ranges pin their low ends in the defs (the R792
    // range precedent). ONE REGTEST PATCH: the xp audit allowed-source list
    // gains mm2_print. The live def walk (the file-patch site block, no
    // census marker) cross-checks every promoted def against the stat grid,
    // the planes, the xpValue formula and the registry census 478 -> 491.
    {
        using namespace rules;
        int bad = 0;
    if (mm2aRound() != 797
            || mm2aEntryCount() != 10
            || mm2aDefCount() != 13
            || mm2aFirstPage() != 8
            || mm2aLastPage() != 12
            || mm2aRegistryBefore() != 478
            || mm2aRegistryAfter() != 491
            || mm2aStatRows() != 12
            || mm2aAntLionItemRows() != 6
            || mm2aAspisLarvaRows() != 4
            || mm2aAzerBracketRows() != 4
            || mm2aAbolethTentacles() != 4
            || mm2aAbolethEnslavesPerDay() != 3
            || mm2aAbolethEnslaveRangeFt() != 30
            || mm2aAbolethMembraneMin() != 2
            || mm2aAbolethMembraneMax() != 5
            || mm2aAbolethMucusRadiusFt() != 1
            || mm2aAbolethSuffocateMin() != 2
            || mm2aAbolethSuffocateMax() != 12
            || mm2aAbolethSlaveWaterMin() != 1
            || mm2aAbolethSlaveWaterMax() != 3
            || mm2aAbolethPsionicScore() != 250
            || mm2aAfancCircleStartFt() != 100
            || mm2aAfancCircleCloseFt() != 20
            || mm2aAfancCircleInnerFt() != 40
            || mm2aAfancWhirlMinRounds() != 5
            || mm2aAfancWhirlMaxRounds() != 8
            || mm2aAfancMaxShipFt() != 60
            || mm2aAfancDragFtPerRound() != 10
            || mm2aAfancTopSpeed() != 30
            || mm2aAfancSubmergePct() != 10
            || mm2aAfancSmallCraftFt() != 30
            || mm2aAgathionHumanFormPct() != 60
            || mm2aAgathionCreatureFormPct() != 30
            || mm2aAgathionItemFormPct() != 10
            || mm2aAgathionClericLevel() != 7
            || mm2aAgathionWisdom() != 18
            || mm2aAgathionTurnLevel() != 14
            || mm2aAgathionSaveLevel() != 14
            || mm2aAgathionItemTurnLevel() != 6
            || mm2aAgathionSlainMinYears() != 10
            || mm2aAgathionSlainMaxYears() != 60
            || mm2aAgathionTouchMin() != 7
            || mm2aAgathionTouchMax() != 14
            || mm2aAgathionPsionicScore() != 177
            || mm2aAnnisStrength() != 19
            || mm2aAnnisCastLevel() != 8
            || mm2aAnnisUsesPerPowerDay() != 2
            || mm2aAnnisEdgedAdjust() != -1
            || mm2aAnnisBluntAdjust() != 1
            || mm2aAntLionPitFt() != 60
            || mm2aAntLionLairLookPct() != 50
            || mm2aAntLionSlipPct() != 50
            || mm2aAntLionAutoBiteMin() != 5
            || mm2aAntLionAutoBiteMax() != 20
            || mm2aAntLionItemChancePct() != 30
            || mm2aAntLionItemsMin() != 1
            || mm2aAntLionItemsMax() != 4
            || mm2aAntLionMagicPct() != 10
            || mm2aAscomoidSporeRangeFt() != 30
            || mm2aAscomoidCloudMin() != 5
            || mm2aAscomoidCloudMax() != 20
            || mm2aAscomoidDeathMin() != 1
            || mm2aAscomoidDeathMax() != 4
            || mm2aAscomoidRecoverMin() != 1
            || mm2aAscomoidRecoverMax() != 4
            || mm2aAscomoidHelplessHitBonus() != 4
            || mm2aAscomoidMagicSaveBonus() != 4
            || mm2aAscomoidMagicDmgPct() != 50
            || mm2aAscomoidPiercingMinFt() != 6
            || mm2aAspisDroneRearAC() != 2
            || mm2aAspisDroneCommonPct() != 5
            || mm2aAspisCowSlimeMin() != 1
            || mm2aAspisCowSlimeMax() != 8
            || mm2aAspisEggChambersMin() != 1
            || mm2aAspisEggChambersMax() != 3
            || mm2aAspisGranariesMin() != 2
            || mm2aAspisGranariesMax() != 4
            || mm2aAspisHatcheriesMin() != 1
            || mm2aAspisHatcheriesMax() != 6
            || mm2aAspisLarvaePerHatcheryMin() != 1
            || mm2aAspisLarvaePerHatcheryMax() != 10
            || mm2aAspisAntsChancePct() != 10
            || mm2aAspisAntsMin() != 10
            || mm2aAspisAntsMax() != 100
            || mm2aAspisTunnelHeightFt() != 4
            || mm2aAtomieInitiativeBonus() != 1
            || mm2aAtomieFighterLevel() != 3
            || mm2aAtomiePowerLevel() != 5
            || mm2aAtomieSurprisePct() != 90
            || mm2aAtomieSurprisedPct() != 10
            || mm2aAtomieInfravisionFt() != 120
            || mm2aAtomieGrigPct() != 20
            || mm2aAtomieCrossbowPct() != 20
            || mm2aAtomieSpearPct() != 60
            || mm2aAtomieSwordPct() != 40
            || mm2aAtomieCrossbowRangeIn() != 3
            || mm2aAtomieCrossbowDmgMin() != 1
            || mm2aAtomieCrossbowDmgMax() != 3
            || mm2aAtomieSpearDmgMin() != 1
            || mm2aAtomieSpearDmgMax() != 4
            || mm2aAtomieSwordDmgMin() != 1
            || mm2aAtomieSwordDmgMax() != 3
            || mm2aAurumvoraxBiteMin() != 2
            || mm2aAurumvoraxBiteMax() != 8
            || mm2aAurumvoraxHoldBite() != 8
            || mm2aAurumvoraxClawMin() != 2
            || mm2aAurumvoraxClawMax() != 8
            || mm2aAurumvoraxClawDmgMin() != 1
            || mm2aAurumvoraxClawDmgMax() != 6
            || mm2aAurumvoraxSurprisePct() != 50
            || mm2aAurumvoraxWeightLbs() != 500
            || mm2aAzerGraspMin() != 2
            || mm2aAzerGraspMax() != 5
            || mm2aAzerWeaponHeatBonus() != 1
            || mm2aAzerColdMultiplier() != 2
            || mm2aAzerTempFloorF() != 200
            || mm2aAzerSurviveHours() != 1
            || mm2aAmaimonHdNum() != 9
            || mm2aAmaimonHdBonus() != 8
            || mm2aAmaimonAvgHp() != 39
            || mm2aAmaimonHitBonus() != 3
            || mm2aAmaimonDmgBonus() != 6
            || mm2aAmaimonStrPct() != 0
            || mm2aAmaimonMR() != 35
            || mm2aAmaimonNobleHdNum() != 7
            || mm2aAmaimonNobleHdBonus() != 6
            || mm2aAmaimonNobleHitBonus() != 2
            || mm2aAmaimonNobleDmgBonus() != 4
            || mm2aAmaimonNobleStrLo() != 76
            || mm2aAmaimonNobleStrHi() != 90
            || mm2aAmaimonNobleMR() != 25
            || mm2aAmaimonNoblesMin() != 8
            || mm2aAmaimonNoblesMax() != 32
            || mm2aAmaimonHabitationMin() != 20
            || mm2aAmaimonLargestNormals() != 2
            || mm2aAmaimonFemalesMin() != 40
            || mm2aAmaimonFemalesMax() != 70
            || !mm2aLetterWalkFromPrint()
            || !mm2aAspisRidesThreeDefs()
            || !mm2aAmaimonRidesAzerEntry()
            || !mm2aAtomieXpIsRomanII()
            || !mm2aAmaimonStatsRideSentinels()
            || !mm2aMm2PrintRidesXpAudit()
            || !mm2aDefsRideDataFiles()
            || !mm2aPinHeaderStaysPrintRecord()
            || !mm2aAbolethMembraneSaveVsSpells()
            || !mm2aAbolethCureDiseaseStops()
            || !mm2aAbolethCureSeriousReverses()
            || !mm2aAbolethIllusionsAudibleVisual()
            || !mm2aAbolethEnslaveSingleTarget()
            || !mm2aAbolethEnslaveBreaksByRemoveCurse()
            || !mm2aAbolethMucusDissolvedBySoapOrWine()
            || !mm2aAfancAvoidsLargerShips()
            || !mm2aAfancCapsizesSmallCraft()
            || !mm2aAgathionStruckOnlyByPlusOne()
            || !mm2aAgathionImmuneLevelDraining()
            || !mm2aAgathionImmuneDeathSpells()
            || !mm2aAgathionImmuneDisintegration()
            || !mm2aAgathionImmunePositiveEnergy()
            || !mm2aAgathionEtherealAtWill()
            || !mm2aAgathionAstralTravel()
            || !mm2aAgathionWisdomBonusSpells()
            || !mm2aAgathionItemGrantsClericSpells()
            || !mm2aAnnisSeizesOnTripleHit()
            || !mm2aAnnisSeizedFoeAutoHit()
            || !mm2aAnnisTreatedAsPlateMail()
            || !mm2aAnnisFlailMorningstarBlunt()
            || !mm2aAnnisSuperiorHearingSmell()
            || !mm2aAntLionJawsLockOnHit()
            || !mm2aAntLionAutoDamageUntilDeath()
            || !mm2aAntLionLairItemsFromKills()
            || !mm2aAntLionLeavesPitToFeed()
            || !mm2aAscomoidAcceleratingRoll()
            || !mm2aAscomoidKnocksDownSmallerFoes()
            || !mm2aAscomoidPiercingDoublesOverSixFeet()
            || !mm2aAscomoidBluntWeaponsHarmless()
            || !mm2aAscomoidEdgedOnePoint()
            || !mm2aAscomoidColdNormal()
            || !mm2aAscomoidMindSpellsUseless()
            || !mm2aAspisDroneFourLegsTwoShields()
            || !mm2aAspisDroneNoBows()
            || !mm2aAspisDroneImmuneElectricCold()
            || !mm2aAspisDroneHalfFire()
            || !mm2aAspisLarvaBlindDeafByVibration()
            || !mm2aAspisLarvaImmuneAcid()
            || !mm2aAspisCowSlimeEatsMetalWood()
            || !mm2aAspisOneCowPerNest()
            || !mm2aAspisDroneSpeaksByScent()
            || !mm2aAtomiePowersAtWillOnePerRound()
            || !mm2aAtomieHearingDoubleNorm()
            || !mm2aAtomieSpeaksSpriteDialect()
            || !mm2aAtomieWeaponsDoubleInDive()
            || !mm2aAtomieGrigCompany()
            || !mm2aAurumvoraxHoldsAfterBite()
            || !mm2aAurumvoraxDexNegatedWhenHeld()
            || !mm2aAurumvoraxOnlyDeathUnlocks()
            || !mm2aAurumvoraxHalfDamageBlunt()
            || !mm2aAurumvoraxImmuneSmallFires()
            || !mm2aAurumvoraxLargeMagicalFiresHalf()
            || !mm2aAurumvoraxImmunePoisonGas()
            || !mm2aAzerHeatDamagesGrasp()
            || !mm2aAzerWeaponsInflictHeat()
            || !mm2aAzerColdDoubleDamage()
            || !mm2aAzerJavelinEqualsSpear()
            || !mm2aAzerMalletEqualsFootmanMace()
            || !mm2aAzerGemsBuyFavors()
            || !mm2aAzerWordIsBond()
            || !mm2aAmaimonPowersUnknown()
        )
            ++bad;
        // the 12 x 9 stat grid - the stat-block cells of the twelve forms in
        // print order (aboleth, afanc, agathion, annis, ant lion, ascomoid,
        // the aspis drone/larva/cow, atomie, aurumvorax, azer): armor class,
        // hit dice, hit-die bonus, average hit points, attacks, base xp, xp
        // per hit, lair percent and the primary move rate
        int CAStats[12][9] = {
            {4,8,0,28,4,1275,10,20,3},
            {6,15,0,52,2,4000,20,0,15},
            {0,7,7,31,2,1800,10,0,18},
            {0,7,3,27,3,1300,10,20,15},
            {2,8,0,28,1,575,10,95,9},
            {3,6,6,27,1,775,8,40,12},
            {3,6,0,21,2,300,6,30,15},
            {6,2,0,7,1,28,2,90,1},
            {7,10,0,35,1,1350,14,95,3},
            {4,0,0,2,2,40,1,35,12},
            {0,12,0,42,1,2700,16,30,9},
            {2,2,1,8,1,40,3,0,12},
            };
        for (int b = 0;
             b < mm2aStatRows();
             ++b) {
            int vals[9];
            vals[0] = mm2aStatAC(b);
            vals[1] = mm2aStatHd(b);
            vals[2] = mm2aStatHdBonus(b);
            vals[3] = mm2aStatAvgHp(b);
            vals[4] = mm2aStatAttacks(b);
            vals[5] = mm2aStatXp(b);
            vals[6] = mm2aStatXpHp(b);
            vals[7] = mm2aStatLairPct(b);
            vals[8] = mm2aStatMove(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CAStats[b][c])
                    ++bad;
            }
        }
        // the ant lion lair-items d20 - six bands tiling 1-20: the die low,
        // the die high, and the kind (1 gp lot, 2 pp lot, 3 shield, 4 metal
        // weapon, 5 jewelry, 6 miscellaneous item)
        int CAntLionItems[6][3] = {
            {1,6,1},
            {7,10,2},
            {11,13,3},
            {14,17,4},
            {18,19,5},
            {20,20,6},
            };
        for (int b = 0;
             b < mm2aAntLionItemRows();
             ++b) {
            int vals[3];
            vals[0] = mm2aAntLionItemLo(b);
            vals[1] = mm2aAntLionItemHi(b);
            vals[2] = mm2aAntLionItemKind(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CAntLionItems[b][c])
                    ++bad;
            }
        }
        // the aspis larva LEVEL/X.P. ladder - the hit-die rung, the base xp
        // and the xp per hit point at 2 through 5 hit dice (the 2-HD rung
        // rides the larva def)
        int CAspisLarvaXp[4][3] = {
            {2,28,2},
            {3,50,3},
            {4,85,4},
            {5,130,5},
            };
        for (int b = 0;
             b < mm2aAspisLarvaRows();
             ++b) {
            int vals[3];
            vals[0] = mm2aAspisLarvaHd(b);
            vals[1] = mm2aAspisLarvaXp(b);
            vals[2] = mm2aAspisLarvaXpHp(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CAspisLarvaXp[b][c])
                    ++bad;
            }
        }
        // the azer hit-die bracket grid - the four brackets 2+1 through 5+4:
        // hit dice, bonus, the strength base and percentile band, the to-hit
        // and damage bonuses, the encounter percent, the base gem value and
        // the LEVEL/X.P. cells
        int CAzerBrackets[4][11] = {
            {2,1,17,0,0,1,1,90,10,40,3},
            {3,2,18,0,0,1,2,30,50,85,4},
            {4,3,18,1,50,1,3,20,100,130,5},
            {5,4,18,51,75,2,3,10,500,225,6},
            };
        for (int b = 0;
             b < mm2aAzerBracketRows();
             ++b) {
            int vals[11];
            vals[0] = mm2aAzerHd(b);
            vals[1] = mm2aAzerHdBonus(b);
            vals[2] = mm2aAzerStrBase(b);
            vals[3] = mm2aAzerStrLo(b);
            vals[4] = mm2aAzerStrHi(b);
            vals[5] = mm2aAzerToHit(b);
            vals[6] = mm2aAzerToDmg(b);
            vals[7] = mm2aAzerEncounterPct(b);
            vals[8] = mm2aAzerGemValue(b);
            vals[9] = mm2aAzerXp(b);
            vals[10] = mm2aAzerXpHp(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CAzerBrackets[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count (the census walk)
    if (mm2aRegistryAfter() - mm2aRegistryBefore() != mm2aDefCount()
            || mm2aDefCount() != mm2aEntryCount() + 3
        )
            ++bad;
        // the azer stat row rides the first bracket (the low-end range rule)
    if (mm2aAzerHd(0) != mm2aStatHd(11)
            || mm2aAzerHdBonus(0) != mm2aStatHdBonus(11)
            || mm2aAzerXp(0) != mm2aStatXp(11)
            || mm2aAzerXpHp(0) != mm2aStatXpHp(11)
        )
            ++bad;
        // the aspis larva stat row rides the 2-HD rung (the low-end range
        // rule)
    if (mm2aAspisLarvaHd(0) != mm2aStatHd(7)
            || mm2aAspisLarvaXp(0) != mm2aStatXp(7)
            || mm2aAspisLarvaXpHp(0) != mm2aStatXpHp(7)
        )
            ++bad;
        // the ant lion item bands tile the d20 without gaps or overlaps
    if (mm2aAntLionItemLo(0) != 1
            || mm2aAntLionItemHi(5) != 20
            || mm2aAntLionItemLo(1) != mm2aAntLionItemHi(0) + 1
            || mm2aAntLionItemLo(2) != mm2aAntLionItemHi(1) + 1
            || mm2aAntLionItemLo(3) != mm2aAntLionItemHi(2) + 1
            || mm2aAntLionItemLo(4) != mm2aAntLionItemHi(3) + 1
            || mm2aAntLionItemLo(5) != mm2aAntLionItemHi(4) + 1
        )
            ++bad;
        // the azer brackets ladder the hit dice 2+1 through 5+4
    if (mm2aAzerHd(1) != mm2aAzerHd(0) + 1
            || mm2aAzerHd(2) != mm2aAzerHd(1) + 1
            || mm2aAzerHd(3) != mm2aAzerHd(2) + 1
            || mm2aAzerHdBonus(1) != mm2aAzerHdBonus(0) + 1
            || mm2aAzerHdBonus(2) != mm2aAzerHdBonus(1) + 1
            || mm2aAzerHdBonus(3) != mm2aAzerHdBonus(2) + 1
        )
            ++bad;
        // the aspis larva ladder steps the hit dice 2 3 4 5
    if (mm2aAspisLarvaHd(1) != mm2aAspisLarvaHd(0) + 1
            || mm2aAspisLarvaHd(2) != mm2aAspisLarvaHd(1) + 1
            || mm2aAspisLarvaHd(3) != mm2aAspisLarvaHd(2) + 1
        )
            ++bad;
        // Amaimon outranks his nobles by one to-hit point and two of damage
    if (mm2aAmaimonHitBonus() != mm2aAmaimonNobleHitBonus() + 1
            || mm2aAmaimonDmgBonus() != mm2aAmaimonNobleDmgBonus() + 2
        )
            ++bad;
        printf("R797 MM2 letter A audit: bad %d\n", bad);
        if (bad) return 1;
    }
