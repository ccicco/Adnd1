    // ---- R801 MM2 devil section audit ----
    // THE MM2 LETTER D PART 3 - the devil section of the Monster Manual II
    // arc (the user Go call on the landed deva turn). The pin-time walk from
    // the print finds THIRTEEN entries on pp. 44-49: the abishai five-form
    // table and the Amon, Bael, bearded devil, Belial, Glasya, Hutijin,
    // Mammon, Mephistopheles, Moloch, nupperibo, Titivilus and spined devil
    // blocks. SEVENTEEN defs ride the R791 data_files extension in the MM1
    // registry schema (the abishai splits five ways, the aspis precedent).
    // THE GRIDS: the 17-row DevStats stat grid, the 9x12 Frequency of Devils
    // on Plane grid and the 9x12 Frequency of Others on Plane grid (the
    // letter-code legend 0 absent, 1 VVR, 2 VR, 3 R, 4 U, 5 C). THE SETTLED
    // READS: the Titivilus symbol 99 hit points (the capture 98 misread); the
    // Titivilus MOVE 15/30 MC:D; the Mephistopheles rulership print typo
    // verbatim; the abishai command; the nupperibo Standard magic-resistance
    // word; the single stench kow frequency column. NO GAP FLIPS (the Letter
    // D box flips only when all the D parts land - the R791 no-flip
    // precedent). NO XP-AUDIT PATCH (mm2_print rides the allowed-source list
    // since R797). The live def walk (the one file-patch site block, no
    // census marker) cross-checks all 17 defs against the DevStats grid, the
    // loader attack semantics, the nupperibo Standard word and the registry
    // census floor 566 -> 583.
    {
        using namespace rules;
        int bad = 0;
    if (mm2dfRound() != 801
            || mm2dfEntryCount() != 13
            || mm2dfAbishaiFormCount() != 5
            || mm2dfDefCount() != 17
            || mm2dfFirstPage() != 44
            || mm2dfLastPage() != 49
            || mm2dfRegistryBefore() != 566
            || mm2dfRegistryAfter() != 583
            || mm2dfDevStatRows() != 17
            || mm2dfDevilFreqRows() != 9
            || mm2dfOthersFreqRows() != 9
            || mm2dfDukeRosterRows() != 61
            || mm2dfFreqCodeAbsent() != 0
            || mm2dfFreqCodeVvr() != 1
            || mm2dfFreqCodeVr() != 2
            || mm2dfFreqCodeR() != 3
            || mm2dfFreqCodeU() != 4
            || mm2dfFreqCodeC() != 5
            || mm2dfGreaterDevilLemureDecades() != 9
            || mm2dfDukePlaneBoundYears() != 10
            || mm2dfBlackAbishaiXpValue() != 1135
            || mm2dfBlueAbishaiXpValue() != 658
            || mm2dfGreenAbishaiXpValue() != 676
            || mm2dfRedAbishaiXpValue() != 400
            || mm2dfWhiteAbishaiXpValue() != 842
            || mm2dfAbishaiXpLevel() != 6
            || mm2dfRedAbishaiXpLevel() != 5
            || mm2dfBlackAbishaiStrengthBonus() != 4
            || mm2dfBlueAbishaiStrengthBonus() != 3
            || mm2dfGreenAbishaiStrengthBonus() != 2
            || mm2dfWhiteAbishaiStrengthBonus() != 2
            || mm2dfRedAbishaiStrengthBonus() != 1
            || mm2dfAbishaiGrappleDamageLo() != 1
            || mm2dfAbishaiGrappleDamageHi() != 4
            || mm2dfAbishaiTailDamageHi() != 2
            || mm2dfAbishaiRegenPerRound() != 1
            || mm2dfAbishaiSummonPct() != 20
            || mm2dfAbishaiOtherTypesPct() != 10
            || mm2dfAbishaiQTreasurePct() != 15
            || mm2dfAmonXpValue() != 30000
            || mm2dfAmonXpLevel() != 10
            || mm2dfAmonPsionicAbility() != 229
            || mm2dfAmonBoneDevilCompanies() != 40
            || mm2dfAmonMaceBonus() != 3
            || mm2dfAmonWinterWolfMagicResist() != 25
            || mm2dfAmonWinterWolfBonus() != 3
            || mm2dfAmonSummonBoneDevilsPct() != 60
            || mm2dfAmonRegenPerTurnLo() != 1
            || mm2dfAmonRegenPerTurnHi() != 12
            || mm2dfAmonWolfControlMiles() != 1
            || mm2dfBaelXpValue() != 35000
            || mm2dfBaelXpLevel() != 10
            || mm2dfBaelPsionicAbility() != 206
            || mm2dfBaelBarbedCompanies() != 66
            || mm2dfBaelMorningStarBonus() != 2
            || mm2dfBaelMorningStarLoFeet() != 4
            || mm2dfBaelMorningStarHiFeet() != 8
            || mm2dfBaelSpellLevel() != 20
            || mm2dfBaelSummonBarbedPct() != 65
            || mm2dfBeardedXpValue() != 1395
            || mm2dfBeardedXpLevel() != 7
            || mm2dfBeardedGlaiveHookDamageHi() != 3
            || mm2dfBeardedBeardMaxDamage() != 8
            || mm2dfBeardedRashRounds() != 4
            || mm2dfBeardedRashDexLossPerRound() != 1
            || mm2dfBeardedSummonPct() != 35
            || mm2dfBelialXpValue() != 30000
            || mm2dfBelialXpLevel() != 10
            || mm2dfBelialPsionicAbility() != 279
            || mm2dfBelialForkBonus() != 4
            || mm2dfBelialSymbolOfPainPerDay() != 3
            || mm2dfBelialSummonPct() != 85
            || mm2dfBelialSpellLevel() != 20
            || mm2dfGlasyaXpValue() != 20000
            || mm2dfGlasyaXpLevel() != 10
            || mm2dfGlasyaPsionicAbility() != 206
            || mm2dfGlasyaRegenPerTurn() != 2
            || mm2dfGlasyaSummonLo() != 1
            || mm2dfGlasyaSummonHi() != 2
            || mm2dfGlasyaSummonPct() != 70
            || mm2dfGlasyaSpellLevel() != 20
            || mm2dfHutijinXpValue() != 30000
            || mm2dfHutijinXpLevel() != 10
            || mm2dfHutijinPsionicAbility() != 275
            || mm2dfHutijinPitFiendCompanies() != 2
            || mm2dfHutijinTridentBonus() != 3
            || mm2dfHutijinFearRadiusFeet() != 30
            || mm2dfHutijinSummonPct() != 75
            || mm2dfHutijinSpellLevel() != 20
            || mm2dfMammonXpValue() != 32000
            || mm2dfMammonXpLevel() != 10
            || mm2dfMammonPsionicAbility() != 259
            || mm2dfMammonSpellLevel() != 20
            || mm2dfMammonSummonPct() != 80
            || mm2dfMephistoXpValue() != 49000
            || mm2dfMephistoXpLevel() != 10
            || mm2dfMephistoPsionicAbility() != 309
            || mm2dfMephistoForkBonus() != 3
            || mm2dfMephistoForkDamageHi() != 12
            || mm2dfMephistoForkUsesPerDay() != 3
            || mm2dfMephistoSummonIceDevilsPct() != 90
            || mm2dfMephistoFearRadiusFeet() != 10
            || mm2dfMephistoSpellLevel() != 20
            || mm2dfMolochXpValue() != 42000
            || mm2dfMolochXpLevel() != 10
            || mm2dfMolochPsionicAbility() != 226
            || mm2dfMolochWhipTails() != 6
            || mm2dfMolochWhipChargesPerTurn() != 20
            || mm2dfMolochBurningHandsDamage() != 16
            || mm2dfMolochFearBreathLo() != 1
            || mm2dfMolochFearBreathHi() != 8
            || mm2dfMolochFearBreathRangeFeet() != 30
            || mm2dfMolochSummonHornedPct() != 80
            || mm2dfMolochSpellLevel() != 20
            || mm2dfNupperiboXpValue() != 21
            || mm2dfNupperiboXpLevel() != 1
            || mm2dfNupperiboRegenPerRound() != 1
            || mm2dfNupperiboReformedPct() != 99
            || mm2dfNupperiboLemurePct() != 1
            || mm2dfNupperiboMillenniumYears() != 1000
            || mm2dfTitivilusXpValue() != 29000
            || mm2dfTitivilusXpLevel() != 10
            || mm2dfTitivilusPsionicAbility() != 239
            || mm2dfTitivilusSymbolLevelsOrDice() != 19
            || mm2dfTitivilusSymbolHitPoints() != 99
            || mm2dfTitivilusAwakenChance() != 20
            || mm2dfTitivilusSummonErinyesPct() != 50
            || mm2dfTitivilusRegenPerRound() != 1
            || mm2dfTitivilusSpellLevel() != 20
            || mm2dfSpinedXpValue() != 292
            || mm2dfSpinedXpLevel() != 4
            || mm2dfSpinedForkLengthInches() != 54
            || mm2dfSpinedSpineCap() != 12
            || mm2dfSpinedMeleeSpinesLo() != 1
            || mm2dfSpinedMeleeSpinesHi() != 4
            || mm2dfSpinedSummonBarbedPct() != 5
            || !mm2dfDevilsMostPowerfulLawfulEvil()
            || !mm2dfDevilsChainOfCommand()
            || !mm2dfAsmodeusPlaysOneAgainstOther()
            || !mm2dfDevilsMoveAboutTheHells()
            || !mm2dfDevilCannotEnterOtherPlanesUnaided()
            || !mm2dfGreaterDevilNotSlainOutsideHell()
            || !mm2dfDevilsNeverSubdued()
            || !mm2dfDevilsServeIfCommanded()
            || !mm2dfNonLawfulEvilMayTreat()
            || !mm2dfMagicCirclesRepelDevils()
            || !mm2dfHolyArtifactsRepelDevils()
            || !mm2dfDevilsSplitAttacks()
            || !mm2dfDevilTelepathy()
            || !mm2dfDevilAcidFullDamage()
            || !mm2dfDevilColdHalfDamage()
            || !mm2dfDevilElectricityFullDamage()
            || !mm2dfDevilFireNoneDamage()
            || !mm2dfDevilGasHalfDamage()
            || !mm2dfDevilIronWeaponNone()
            || !mm2dfDevilMagicMissileFullDamage()
            || !mm2dfDevilPoisonFullDamage()
            || !mm2dfDevilsResembleDemons()
            || !mm2dfAbishaiCommonToFirstHell()
            || !mm2dfAbishaiReptilian()
            || !mm2dfAbishaiWeaponsByForm()
            || !mm2dfAmonFearGaze()
            || !mm2dfAmonSymbolOfHopelessnessOncePerDay()
            || !mm2dfAmonWolfHeaded()
            || !mm2dfBaelSymbolOfStunningOncePerDay()
            || !mm2dfBaelFearRadius()
            || !mm2dfBaelRegenerates()
            || !mm2dfBaelBovineFeatures()
            || !mm2dfBeardedThirdHell()
            || !mm2dfBeardedShockTroops()
            || !mm2dfBelialRulesFourthHell()
            || !mm2dfBelialUnholyWordOncePerDay()
            || !mm2dfBelialFearByStare()
            || !mm2dfBelialMostHandsome()
            || !mm2dfGlasyaConsortToMammon()
            || !mm2dfGlasyaDaughterOfAsmodeus()
            || !mm2dfGlasyaFingerOfDeathOncePerDay()
            || !mm2dfGlasyaDaggerOfVenom()
            || !mm2dfHutijinAristocracyOfEighthPlane()
            || !mm2dfHutijinSymbolOfPersuasionOncePerDay()
            || !mm2dfHutijinHealTwicePerDay()
            || !mm2dfHutijinResemblesPitFiend()
            || !mm2dfMammonRulesThirdHell()
            || !mm2dfMammonRidesNightmare()
            || !mm2dfMammonSwordOfWounding()
            || !mm2dfMammonSymbolOfHopelessnessOncePerDay()
            || !mm2dfMammonFearByGaze()
            || !mm2dfMammonRedGold()
            || !mm2dfMephistoRulesEighthHell()
            || !mm2dfMephistoWrestSeventhPlane()
            || !mm2dfMephistoRulershipPrintsVerbatim()
            || !mm2dfMephistoWhisperingWind()
            || !mm2dfMolochRulesSixthHell()
            || !mm2dfMolochWhipElectrical()
            || !mm2dfMolochFlameStrikeOncePerDay()
            || !mm2dfMolochEnmityWithGeryon()
            || !mm2dfMolochSquareBodied()
            || !mm2dfNupperiboMrStandard()
            || !mm2dfNupperiboBlindDeafMute()
            || !mm2dfNupperiboHordesMarch()
            || !mm2dfNupperiboHolyObjectBlocksRegen()
            || !mm2dfNupperiboRemainsOfLawfulEvil()
            || !mm2dfTitivilusMessengerForDispater()
            || !mm2dfTitivilusSilverSwordOfWounding()
            || !mm2dfTitivilusFearByTouch()
            || !mm2dfTitivilusMovePrintsMCd()
            || !mm2dfSpinedServantsCouriers()
            || !mm2dfSpinedHerdLemures()
            || !mm2dfSpinedAllPlanesOfHell()
            || !mm2dfSpinedAttacksAutoHit()
        )
            ++bad;
        // THE DEVIL GRID: the 17-row DevStats stat grid (every armor class,
        // hit-dice, hit, xp, lair, move and magic-resistance cell of the
        // thirteen devil stat blocks with the abishai split five ways)
        int CDevStats[17][10] = {
            {2,8,0,28,1,855,10,20,9,35},
            {3,5,1,18,1,550,6,35,15,20},
            {3,6,0,21,1,550,6,30,12,25},
            {1,4,2,16,2,320,5,40,18,40},
            {3,7,0,24,2,650,8,25,9,30},
            {-2,0,0,126,2,30000,0,60,18,70},
            {-3,0,0,106,2,35000,0,55,12,70},
            {1,6,6,27,3,1125,10,15,15,45},
            {-4,0,0,154,2,30000,0,75,9,80},
            {-2,0,0,69,2,20000,0,80,15,60},
            {-4,0,0,111,2,30000,0,30,9,65},
            {-3,0,0,139,2,32000,0,65,6,75},
            {-6,0,0,188,2,49000,0,70,15,85},
            {-3,0,0,126,3,42000,0,95,12,70},
            {9,1,0,3,2,18,1,0,6,0},
            {-2,0,0,86,2,29000,0,35,15,75},
            {3,3,3,13,3,240,4,10,6,25},
            };
        for (int b = 0;
             b < mm2dfDevStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2dfDevStatAC(b);
            vals[1] = mm2dfDevStatHd(b);
            vals[2] = mm2dfDevStatHdBonus(b);
            vals[3] = mm2dfDevStatAvgHp(b);
            vals[4] = mm2dfDevStatAttacks(b);
            vals[5] = mm2dfDevStatXp(b);
            vals[6] = mm2dfDevStatXpHp(b);
            vals[7] = mm2dfDevStatLairPct(b);
            vals[8] = mm2dfDevStatMove(b);
            vals[9] = mm2dfDevStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CDevStats[b][c])
                    ++bad;
            }
        }
        // THE PLANE GRID: the Frequency of Devils on Plane table (p. 45) -
        // the letter codes pinned as 0 absent, 1 very very rare, 2 very rare,
        // 3 rare, 4 uncommon, 5 common
        int CDevilPlaneFreq[9][12] = {
            {5,1,3,0,0,5,0,0,4,0,5,0},
            {5,1,4,3,0,5,2,0,5,2,5,0},
            {4,1,5,5,4,3,2,0,5,2,5,2},
            {3,1,5,5,5,2,3,0,5,2,5,3},
            {2,1,3,4,4,0,4,0,5,2,5,5},
            {0,1,0,2,3,0,5,0,5,2,4,4},
            {0,1,0,0,2,0,5,2,5,2,4,0},
            {0,1,0,0,0,0,2,5,5,3,4,0},
            {0,1,0,0,0,0,2,3,5,5,4,0},
            };
        for (int b = 0;
             b < mm2dfDevilFreqRows();
             ++b) {
            int vals[12];
            vals[0] = mm2dfFreqDAbishai(b);
            vals[1] = mm2dfFreqDArch(b);
            vals[2] = mm2dfFreqDBarbed(b);
            vals[3] = mm2dfFreqDBearded(b);
            vals[4] = mm2dfFreqDBone(b);
            vals[5] = mm2dfFreqDErinyes(b);
            vals[6] = mm2dfFreqDHorned(b);
            vals[7] = mm2dfFreqDIce(b);
            vals[8] = mm2dfFreqDNupperibo(b);
            vals[9] = mm2dfFreqDPitFiend(b);
            vals[10] = mm2dfFreqDSpined(b);
            vals[11] = mm2dfFreqDStyx(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CDevilPlaneFreq[b][c])
                    ++bad;
            }
        }
        // THE OTHERS GRID: the Frequency of Others on Plane table (p. 45) -
        // the same letter-code legend
        int COthersPlaneFreq[9][12] = {
            {3,2,2,0,2,2,2,3,5,2,2,5},
            {5,2,2,4,4,4,5,3,5,3,5,5},
            {5,2,2,4,4,3,5,4,5,3,5,5},
            {4,2,2,3,5,3,4,4,5,3,4,4},
            {4,2,2,3,5,3,4,5,5,3,4,4},
            {4,2,2,4,3,2,4,5,4,3,3,4},
            {3,2,2,3,2,0,3,5,4,3,0,4},
            {2,3,2,3,0,0,2,5,4,2,2,4},
            {2,3,2,0,4,0,3,5,4,2,2,4},
            };
        for (int b = 0;
             b < mm2dfOthersFreqRows();
             ++b) {
            int vals[12];
            vals[0] = mm2dfFreqOAchaierai(b);
            vals[1] = mm2dfFreqOBarghest(b);
            vals[2] = mm2dfFreqODaemon(b);
            vals[3] = mm2dfFreqOHellCat(b);
            vals[4] = mm2dfFreqOHellHound(b);
            vals[5] = mm2dfFreqOHoardling(b);
            vals[6] = mm2dfFreqOImp(b);
            vals[7] = mm2dfFreqOLemure(b);
            vals[8] = mm2dfFreqOMephit(b);
            vals[9] = mm2dfFreqONightmare(b);
            vals[10] = mm2dfFreqORakshasa(b);
            vals[11] = mm2dfFreqOStenchKow(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != COthersPlaneFreq[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count (the census walk)
    if (mm2dfRegistryAfter() - mm2dfRegistryBefore() != mm2dfDefCount()
            || mm2dfDefCount() != 17
            || mm2dfEntryCount() != 13
            || mm2dfAbishaiFormCount() != 5
        )
            ++bad;
        // each grid xp tile equals its pinned full kill xp (the xpValue
        // formula, pin-vs-pin)
    if (mm2dfDevStatXp(0) + mm2dfDevStatXpHp(0) * mm2dfDevStatAvgHp(0) !=
        mm2dfBlackAbishaiXpValue()
            || mm2dfDevStatXp(1) + mm2dfDevStatXpHp(1) * mm2dfDevStatAvgHp(1)
            != mm2dfBlueAbishaiXpValue()
            || mm2dfDevStatXp(2) + mm2dfDevStatXpHp(2) * mm2dfDevStatAvgHp(2)
            != mm2dfGreenAbishaiXpValue()
            || mm2dfDevStatXp(3) + mm2dfDevStatXpHp(3) * mm2dfDevStatAvgHp(3)
            != mm2dfRedAbishaiXpValue()
            || mm2dfDevStatXp(4) + mm2dfDevStatXpHp(4) * mm2dfDevStatAvgHp(4)
            != mm2dfWhiteAbishaiXpValue()
            || mm2dfDevStatXp(5) + mm2dfDevStatXpHp(5) * mm2dfDevStatAvgHp(5)
            != mm2dfAmonXpValue()
            || mm2dfDevStatXp(6) + mm2dfDevStatXpHp(6) * mm2dfDevStatAvgHp(6)
            != mm2dfBaelXpValue()
            || mm2dfDevStatXp(7) + mm2dfDevStatXpHp(7) * mm2dfDevStatAvgHp(7)
            != mm2dfBeardedXpValue()
            || mm2dfDevStatXp(8) + mm2dfDevStatXpHp(8) * mm2dfDevStatAvgHp(8)
            != mm2dfBelialXpValue()
            || mm2dfDevStatXp(9) + mm2dfDevStatXpHp(9) * mm2dfDevStatAvgHp(9)
            != mm2dfGlasyaXpValue()
            || mm2dfDevStatXp(10) + mm2dfDevStatXpHp(10) *
            mm2dfDevStatAvgHp(10) != mm2dfHutijinXpValue()
            || mm2dfDevStatXp(11) + mm2dfDevStatXpHp(11) *
            mm2dfDevStatAvgHp(11) != mm2dfMammonXpValue()
            || mm2dfDevStatXp(12) + mm2dfDevStatXpHp(12) *
            mm2dfDevStatAvgHp(12) != mm2dfMephistoXpValue()
            || mm2dfDevStatXp(13) + mm2dfDevStatXpHp(13) *
            mm2dfDevStatAvgHp(13) != mm2dfMolochXpValue()
            || mm2dfDevStatXp(14) + mm2dfDevStatXpHp(14) *
            mm2dfDevStatAvgHp(14) != mm2dfNupperiboXpValue()
            || mm2dfDevStatXp(15) + mm2dfDevStatXpHp(15) *
            mm2dfDevStatAvgHp(15) != mm2dfTitivilusXpValue()
            || mm2dfDevStatXp(16) + mm2dfDevStatXpHp(16) *
            mm2dfDevStatAvgHp(16) != mm2dfSpinedXpValue()
        )
            ++bad;
        // the settled LEVEL reads (the abishai VI with the red V, the bearded
        // VII, the nupperibo I, the spined IV)
    if (mm2dfAbishaiXpLevel() != 6
            || mm2dfRedAbishaiXpLevel() != 5
            || mm2dfBeardedXpLevel() != 7
            || mm2dfNupperiboXpLevel() != 1
            || mm2dfSpinedXpLevel() != 4
            || mm2dfAmonXpLevel() != 10
        )
            ++bad;
        // the psionic abilities of the nine unique devils
    if (mm2dfAmonPsionicAbility() != 229
            || mm2dfBaelPsionicAbility() != 206
            || mm2dfBelialPsionicAbility() != 279
            || mm2dfGlasyaPsionicAbility() != 206
            || mm2dfHutijinPsionicAbility() != 275
            || mm2dfMammonPsionicAbility() != 259
            || mm2dfMephistoPsionicAbility() != 309
            || mm2dfMolochPsionicAbility() != 226
            || mm2dfTitivilusPsionicAbility() != 239
        )
            ++bad;
        // the Titivilus symbol settled read (the 99 hit points over the
        // capture 98 misread) and the doctrine roster counts
    if (mm2dfTitivilusSymbolHitPoints() != 99
            || mm2dfTitivilusSymbolLevelsOrDice() != 19
            || mm2dfTitivilusAwakenChance() != 20
            || mm2dfDukeRosterRows() != 61
            || mm2dfGreaterDevilLemureDecades() != 9
            || mm2dfDukePlaneBoundYears() != 10
        )
            ++bad;
        // the frequency-code legend and the plane-grid spot tiles
    if (mm2dfFreqCodeAbsent() != 0
            || mm2dfFreqCodeVvr() != 1
            || mm2dfFreqCodeVr() != 2
            || mm2dfFreqCodeR() != 3
            || mm2dfFreqCodeU() != 4
            || mm2dfFreqCodeC() != 5
            || mm2dfFreqDAbishai(0) != mm2dfFreqCodeC()
            || mm2dfFreqDAbishai(2) != mm2dfFreqCodeU()
            || mm2dfFreqDArch(8) != mm2dfFreqCodeVvr()
            || mm2dfFreqDNupperibo(2) != mm2dfFreqCodeC()
            || mm2dfFreqDStyx(2) != mm2dfFreqCodeVr()
            || mm2dfFreqOLemure(5) != mm2dfFreqCodeC()
            || mm2dfFreqOStenchKow(0) != mm2dfFreqCodeC()
        )
            ++bad;
        // the weapon and strength tiles
    if (mm2dfBlackAbishaiStrengthBonus() != 4
            || mm2dfBlueAbishaiStrengthBonus() != 3
            || mm2dfGreenAbishaiStrengthBonus() != 2
            || mm2dfWhiteAbishaiStrengthBonus() != 2
            || mm2dfRedAbishaiStrengthBonus() != 1
            || mm2dfAbishaiSummonPct() != 20
            || mm2dfAmonMaceBonus() != 3
            || mm2dfBaelMorningStarBonus() != 2
            || mm2dfBelialForkBonus() != 4
            || mm2dfHutijinTridentBonus() != 3
            || mm2dfMephistoForkBonus() != 3
            || mm2dfMolochWhipTails() != 6
            || mm2dfSpinedForkLengthInches() != 54
        )
            ++bad;
        // the summon chance tiles
    if (mm2dfAmonSummonBoneDevilsPct() != 60
            || mm2dfBaelSummonBarbedPct() != 65
            || mm2dfBelialSummonPct() != 85
            || mm2dfGlasyaSummonPct() != 70
            || mm2dfHutijinSummonPct() != 75
            || mm2dfMammonSummonPct() != 80
            || mm2dfMephistoSummonIceDevilsPct() != 90
            || mm2dfMolochSummonHornedPct() != 80
            || mm2dfTitivilusSummonErinyesPct() != 50
            || mm2dfBeardedSummonPct() != 35
            || mm2dfSpinedSummonBarbedPct() != 5
        )
            ++bad;
        printf("R801 MM2 devil section audit: bad %d\n", bad);
        if (bad) return 1;
    }
