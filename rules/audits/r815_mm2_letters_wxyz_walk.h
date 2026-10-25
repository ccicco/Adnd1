    // ---- R815 MM2 letters WXYZ walk audit ----
    // THE MM2 LETTERS WXYZ WALK - the weasel p. 125, the webbird and the
    // wemic p. 125, the black willow p. 126, the wolf-in-sheep's-clothing and
    // the wolfwere p. 127, the tenebrous worm and the tunnel worm pp. 127-128
    // (the WORM family head, the two sub-entries), the xag-ya and xeg-yi p.
    // 128, the xaren p. 129, the yeth hound and the yochlol (Handmaiden of
    // Lolth) p. 129, the yuan ti p. 130, the juju zombie p. 130 and the
    // monster zombie p. 131 (the two ZOMBIE heads), the zorbo p. 131 and the
    // zygom pp. 131-132; the WXYZ-FLIP round: the Letter W, X, Y and Z gap
    // boxes flip to closed and the Monsters from A-Z parent box flips to
    // closed - 32 closed 5 open, the A-Z section complete. SEVENTEEN .lua
    // defs ride the R791 data_files extension, registry 792 -> 809; SIXTEEN
    // entry heads carrying SEVENTEEN stat blocks (the WORM family head the
    // one two-def head), no prior-owned heads, no doctrine-only heads. THE
    // SETTLED READS (the capture the sole voice this round - the
    // transcription not consulted): the weasel 1/4 and the webbird 1/2 the
    // half-dice hdNum-0 reads (the atomie precedent, avgHp 2 each); the black
    // willow 7-12 attacks the loader 10 clamp (the land urchin precedent);
    // the yochlol AC -10 the UNQUOTED number read over its -10 or 10 cell
    // (the tarrasque precedent); the xaren xp row 55 + 8/hp with NO level
    // numeral (XpLevel 0); the yuan ti Variable the by_level xp source with
    // explicit unquoted zeros (the walk index-12 exception); the monster
    // zombie the capture-lossy nil block (only the AC 6 and the 4-16 damage
    // evidenced, hitDiceNum 0 the shade precedent, xp 0 the derro sentinel);
    // the juju zombie +7 or better specialDefenses cell verbatim; the yeth
    // hound 100% (daytime only) the bare-numeral lair read; the wolfwere,
    // xag-ya, yeth hound, yochlol, yuan ti and zorbo percent MR cells; every
    // WORM, willow and zygom move cell the first-int read.
    {
        using namespace rules;
        int bad = 0;
    if (mm2wxyzRound() != 815
            || mm2wxyzRegistryBefore() != 792
            || mm2wxyzRegistryAfter() != 809
            || mm2wxyzDefCount() != 17
            || mm2wxyzEntryCount() != 16
            || mm2wxyzStatBlockHeadings() != 17
            || mm2wxyzDoctrineHeads() != 0
            || mm2wxyzLetterWXYZHeadings() != 16
            || mm2wxyzWXYZStatRows() != 17
            || mm2wxyzGapClosed() != 32
            || mm2wxyzGapOpen() != 5
            || mm2wxyzPriorOwnedEntries() != 0
            || mm2wxyzWeaselXpValue() != 4
            || mm2wxyzWeaselXpLevel() != 1
            || mm2wxyzWebbirdXpValue() != 9
            || mm2wxyzWebbirdXpLevel() != 1
            || mm2wxyzWebbirdWebMinFeet() != 7
            || mm2wxyzWebbirdWebMaxFeet() != 12
            || mm2wxyzWebbirdEggsMin() != 2
            || mm2wxyzWebbirdEggsMax() != 8
            || mm2wxyzWebbirdGrubHatchMinTurns() != 3
            || mm2wxyzWebbirdGrubHatchMaxTurns() != 6
            || mm2wxyzWemicXpValue() != 375
            || mm2wxyzWemicXpLevel() != 4
            || mm2wxyzWemicLeapUpFeet() != 10
            || mm2wxyzWemicLeapForwardFeet() != 30
            || mm2wxyzWemicMaleShieldAc() != 5
            || mm2wxyzWemicFemaleAc() != 7
            || mm2wxyzWemicFemaleToHitBonus() != 2
            || mm2wxyzWemicPrideMalesMin() != 4
            || mm2wxyzWemicPrideMalesMax() != 16
            || mm2wxyzWemicPrideFemalesMin() != 2
            || mm2wxyzWemicPrideFemalesMax() != 24
            || mm2wxyzWemicPrideYoungMin() != 1
            || mm2wxyzWemicPrideYoungMax() != 12
            || mm2wxyzWemicChiefAc() != 5
            || mm2wxyzWemicChiefHd() != 6
            || mm2wxyzWemicChiefHdBonus() != 4
            || mm2wxyzWemicKingAc() != 3
            || mm2wxyzWemicKingHd() != 9
            || mm2wxyzWemicWitchDoctorChance() != 70
            || mm2wxyzWemicWitchDoctorCleric() != 7
            || mm2wxyzWemicWitchDoctorMu() != 4
            || mm2wxyzWillowXpValue() != 3240
            || mm2wxyzWillowXpLevel() != 8
            || mm2wxyzWillowDetectFailPct() != 90
            || mm2wxyzWillowDrowsinessRadiusFeet() != 20
            || mm2wxyzWillowCavityDepthFeet() != 8
            || mm2wxyzWillowSapFillRoundsPerFoot() != 10
            || mm2wxyzWillowSapDamageMin() != 1
            || mm2wxyzWillowSapDamageMax() != 4
            || mm2wxyzWillowDigestionFloor() != -12
            || mm2wxyzWillowRegenPerTurn() != 1
            || mm2wxyzWillowConfinedMaxDamage() != 1
            || mm2wxyzWolfIscXpValue() != 1334
            || mm2wxyzWolfIscXpLevel() != 6
            || mm2wxyzWolfIscRootTentacles() != 7
            || mm2wxyzWolfIscRootHpMin() != 19
            || mm2wxyzWolfIscRootHpMax() != 22
            || mm2wxyzWolfIscEyestalkHpMin() != 13
            || mm2wxyzWolfIscEyestalkHpMax() != 16
            || mm2wxyzWolfIscRegenMinWeeks() != 1
            || mm2wxyzWolfIscRegenMaxWeeks() != 4
            || mm2wxyzWolfIscLureRangeFeet() != 12
            || mm2wxyzWolfIscBiteMin() != 7
            || mm2wxyzWolfIscBiteMax() != 12
            || mm2wxyzWolfIscSurprisePct() != 90
            || mm2wxyzWolfIscBreakStrength() != 13
            || mm2wxyzWolfIscBaseBreakPct() != 30
            || mm2wxyzWolfIscBreakPctPerPoint() != 5
            || mm2wxyzWolfwereXpValue() != 658
            || mm2wxyzWolfwereXpLevel() != 6
            || mm2wxyzWolfwerePackChance() != 75
            || mm2wxyzWolfwerePackWorgPct() != 70
            || mm2wxyzWolfwereLethargyMinRounds() != 5
            || mm2wxyzWolfwereLethargyMaxRounds() != 8
            || mm2wxyzWolfwereBiteMin() != 2
            || mm2wxyzWolfwereBiteMax() != 12
            || mm2wxyzTenebrousXpValue() != 3100
            || mm2wxyzTenebrousXpLevel() != 7
            || mm2wxyzTenebrousBiteMin() != 2
            || mm2wxyzTenebrousBiteMax() != 20
            || mm2wxyzTenebrousBristleDamageMax() != 4
            || mm2wxyzTenebrousPoisonSavePenalty() != 3
            || mm2wxyzTenebrousNeutralizeMinRounds() != 1
            || mm2wxyzTenebrousNeutralizeMaxRounds() != 4
            || mm2wxyzTenebrousHeadContactReductionPct() != 20
            || mm2wxyzTenebrousMandibleGpMin() != 1000
            || mm2wxyzTenebrousMandibleGpMax() != 3000
            || mm2wxyzTunnelXpValue() != 1826
            || mm2wxyzTunnelXpLevel() != 7
            || mm2wxyzTunnelLungeBonus() != 2
            || mm2wxyzTunnelBiteMin() != 2
            || mm2wxyzTunnelBiteMax() != 16
            || mm2wxyzTunnelLeatherRounds() != 1
            || mm2wxyzTunnelChainRounds() != 2
            || mm2wxyzTunnelPlateRounds() != 3
            || mm2wxyzTunnelRetreatFireDamage() != 15
            || mm2wxyzTunnelRetreatHpPct() != 60
            || mm2wxyzTunnelBurrowDiameterFeet() != 2
            || mm2wxyzXagYaXpValue() != 1270
            || mm2wxyzXagYaXpLevel() != 8
            || mm2wxyzXagYaBoltRangeFeet() != 10
            || mm2wxyzXagYaDeathBlastDamageMin() != 14
            || mm2wxyzXagYaDeathBlastDamageMax() != 24
            || mm2wxyzXagYaDeathBlastRadiusFeet() != 10
            || mm2wxyzXagYaMeetBlastRadiusFeet() != 30
            || mm2wxyzXagYaMeetBlastMin() != 28
            || mm2wxyzXagYaMeetBlastMax() != 48
            || mm2wxyzXagYaMetalDamageMin() != 1
            || mm2wxyzXagYaMetalDamageMax() != 4
            || mm2wxyzXagYaGuardianRadiusInches() != 3
            || mm2wxyzXarenXpValue() != 231
            || mm2wxyzXarenXpLevel() != 0
            || mm2wxyzXarenClawDamageMin() != 1
            || mm2wxyzXarenClawDamageMax() != 3
            || mm2wxyzXarenBiteDamageMin() != 4
            || mm2wxyzXarenBiteDamageMax() != 16
            || mm2wxyzXarenOreSmellFeet() != 20
            || mm2wxyzXarenMagicSmellFeet() != 40
            || mm2wxyzXarenMagicMetalHpCap() != 45
            || mm2wxyzXarenMealPoundsMin() != 5
            || mm2wxyzXarenMealPoundsMax() != 8
            || mm2wxyzXarenAttackIfMagicWithheldPct() != 80
            || mm2wxyzXarenAttackIfMetalWithheldPct() != 40
            || mm2wxyzXarenWeaponBiteChance() != 40
            || mm2wxyzXarenRockMoveInches() != 9
            || mm2wxyzXarenBurrowInches() != 3
            || mm2wxyzYethXpValue() != 287
            || mm2wxyzYethXpLevel() != 4
            || mm2wxyzYethBayingRangeMiles() != 1
            || mm2wxyzYethPanicRadiusInches() != 9
            || mm2wxyzYethBiteMin() != 2
            || mm2wxyzYethBiteMax() != 8
            || mm2wxyzYethPackMin() != 4
            || mm2wxyzYethPackMax() != 16
            || mm2wxyzYethPlusDamagePerPlus() != 1
            || mm2wxyzYethSilverDamage() != 1
            || mm2wxyzYochlolXpValue() != 1485
            || mm2wxyzYochlolXpLevel() != 7
            || mm2wxyzYochlolGaseousAc() != -10
            || mm2wxyzYochlolMaterializedAc() != 10
            || mm2wxyzYochlolPseudopods() != 8
            || mm2wxyzYochlolPseudopodDamageMin() != 5
            || mm2wxyzYochlolPseudopodDamageMax() != 8
            || mm2wxyzYochlolStinkingHealMin() != 3
            || mm2wxyzYochlolStinkingHealMax() != 12
            || mm2wxyzYochlolGustOfWindDamageMin() != 6
            || mm2wxyzYochlolGustOfWindDamageMax() != 36
            || mm2wxyzYochlolFighterLevel() != 6
            || mm2wxyzYochlolStrength() != 18
            || mm2wxyzYochlolStrengthPercent() != 50
            || mm2wxyzYuanTiXpValue() != 0
            || mm2wxyzYuanTiXpLevel() != 0
            || mm2wxyzYuanTiPurebloodHd() != 6
            || mm2wxyzYuanTiHalfbreedHdMin() != 7
            || mm2wxyzYuanTiHalfbreedHdMax() != 8
            || mm2wxyzYuanTiAbominationHd() != 9
            || mm2wxyzYuanTiPurebloodPassPct() != 80
            || mm2wxyzYuanTiSnakeHeadBiteMin() != 1
            || mm2wxyzYuanTiSnakeHeadBiteMax() != 10
            || mm2wxyzYuanTiSnakeArmBiteMin() != 1
            || mm2wxyzYuanTiSnakeArmBiteMax() != 6
            || mm2wxyzYuanTiTailConstrictMin() != 1
            || mm2wxyzYuanTiTailConstrictMax() != 4
            || mm2wxyzYuanTiHumanMoveInches() != 12
            || mm2wxyzYuanTiSnakeMoveInches() != 9
            || mm2wxyzYuanTiDarknessRadiusFeet() != 15
            || mm2wxyzYuanTiSnakePartAc() != 0
            || mm2wxyzZombieJujuXpValue() != 198
            || mm2wxyzZombieJujuXpLevel() != 3
            || mm2wxyzZombieJujuDamageMin() != 3
            || mm2wxyzZombieJujuDamageMax() != 12
            || mm2wxyzZombieJujuClimbAsThiefLevel() != 6
            || mm2wxyzZombieJujuAttacksAsHd() != 6
            || mm2wxyzZombieMonsterXpValue() != 0
            || mm2wxyzZombieMonsterXpLevel() != 0
            || mm2wxyzZombieMonsterDamageMin() != 4
            || mm2wxyzZombieMonsterDamageMax() != 16
            || mm2wxyzZombieMonsterHolyWaterMin() != 2
            || mm2wxyzZombieMonsterHolyWaterMax() != 8
            || mm2wxyzZorboXpValue() != 360
            || mm2wxyzZorboXpLevel() != 5
            || mm2wxyzZorboEarthAc() != 7
            || mm2wxyzZorboWoodAc() != 5
            || mm2wxyzZorboMetalAc() != 3
            || mm2wxyzZorboStoneAc() != 0
            || mm2wxyzZorboBaseAc() != 10
            || mm2wxyzZorboAbsorbDurationRounds() != 10
            || mm2wxyzZorboClawDamageMin() != 1
            || mm2wxyzZorboClawDamageMax() != 2
            || mm2wxyzZygomXpValue() != 125
            || mm2wxyzZygomXpLevel() != 3
            || mm2wxyzZygomColonyMin() != 12
            || mm2wxyzZygomColonyMax() != 24
            || mm2wxyzZygomGlueChance() != 6
            || mm2wxyzZygomGlueDaysMin() != 2
            || mm2wxyzZygomGlueDaysMax() != 5
            || mm2wxyzZygomInfestationWeeksMin() != 1
            || mm2wxyzZygomInfestationWeeksMax() != 8
            || !mm2wxyzWebbirdShunsFlame()
            || !mm2wxyzWemicSurprisedOnlyOnOne()
            || !mm2wxyzWemicYoungNoncombative()
            || !mm2wxyzWillowNoSaveVsDrowsiness()
            || !mm2wxyzWillowResurrectionImpossible()
            || !mm2wxyzWolfIscExceptionalStrengthOnly()
            || !mm2wxyzWolfwereIronOrMagicToHit()
            || !mm2wxyzWolfwereShunsWolvesbane()
            || !mm2wxyzTenebrousAcidBite()
            || !mm2wxyzTenebrousBristleParalysis()
            || !mm2wxyzTunnelDragsCorpsesToLair()
            || !mm2wxyzXagYaMagicWeaponOnly()
            || !mm2wxyzXagYaShieldRepulses()
            || !mm2wxyzXarenFireAndColdImmune()
            || !mm2wxyzXarenBluntFullDamage()
            || !mm2wxyzYethSilverOrMagicToHit()
            || !mm2wxyzYethFlies()
            || !mm2wxyzYochlolDemonType()
            || !mm2wxyzYochlolWindWalkDestroys()
            || !mm2wxyzYochlolGaseousPlusOneToHit()
            || !mm2wxyzYuanTiDemonWorshippers()
            || !mm2wxyzYuanTiSpeaksWithSnakes()
            || !mm2wxyzZombieJujuPlusOneToHit()
            || !mm2wxyzZombieJujuPiercingHalfDamage()
            || !mm2wxyzZombieJujuMindImmune()
            || !mm2wxyzZombieJujuFireHalfEffect()
            || !mm2wxyzZombieJujuUnderwaterCapable()
            || !mm2wxyzZombieJujuTurnedAsSpectre()
            || !mm2wxyzZombieMonsterBluntHalfDamage()
            || !mm2wxyzZombieMonsterTurnedAsGhast()
            || !mm2wxyzZombieMonsterStrikesLast()
            || !mm2wxyzZorboAbsorbsItemToDust()
            || !mm2wxyzZorboNeverWorseAc()
            || !mm2wxyzZygomMindMagicImmune()
            || !mm2wxyzZygomCureDiseaseRemoves()
        )
            ++bad;
        // THE WXYZ-GRID: the 17-row WXYZStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the seventeen promoted letters WXYZ stat
        // blocks, in print order - the weasel p. 125 through the zygom pp.
        // 131-132)
        int CWXYZStats[17][10] = {
            {6,0,0,2,1,2,1,0,15,0},
            {8,0,0,2,1,7,1,0,3,0},
            {6,5,8,25,2,200,7,50,12,0},
            {2,12,0,42,10,2400,20,100,1,0},
            {3,9,0,31,3,900,14,0,1,0},
            {3,5,1,18,2,550,6,35,15,10},
            {1,10,0,35,1,2400,20,0,1,0},
            {4,9,3,34,1,1350,14,76,6,0},
            {0,5,0,17,1,1100,10,0,6,15},
            {1,5,5,22,4,55,8,70,9,0},
            {0,3,3,13,1,235,4,100,15,10},
            {-10,6,0,21,1,1275,10,0,12,50},
            {4,6,0,21,2,0,0,70,12,20},
            {6,3,12,22,1,110,4,0,9,0},
            {6,0,0,0,1,0,0,0,0,0},
            {10,4,2,16,2,280,5,30,15,20},
            {8,3,0,10,1,85,4,50,1,0},
            };
        for (int b = 0;
             b < mm2wxyzWXYZStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2wxyzWXYZStatAc(b);
            vals[1] = mm2wxyzWXYZStatHd(b);
            vals[2] = mm2wxyzWXYZStatHdBonus(b);
            vals[3] = mm2wxyzWXYZStatAvgHp(b);
            vals[4] = mm2wxyzWXYZStatAttacks(b);
            vals[5] = mm2wxyzWXYZStatXp(b);
            vals[6] = mm2wxyzWXYZStatXpHp(b);
            vals[7] = mm2wxyzWXYZStatLairPct(b);
            vals[8] = mm2wxyzWXYZStatMove(b);
            vals[9] = mm2wxyzWXYZStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CWXYZStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the Letter W, X, Y
        // and Z gap boxes plus the A-Z parent flip (the census walk)
    if (mm2wxyzRegistryAfter() - mm2wxyzRegistryBefore() != mm2wxyzDefCount()
            || mm2wxyzDefCount() != 17
            || mm2wxyzEntryCount() != 16
            || mm2wxyzStatBlockHeadings() != 17
            || mm2wxyzDoctrineHeads() != 0
            || mm2wxyzLetterWXYZHeadings() != 16
            || mm2wxyzWXYZStatRows() != 17
            || mm2wxyzGapClosed() != 32
            || mm2wxyzGapOpen() != 5
            || mm2wxyzPriorOwnedEntries() != 0
        )
            ++bad;
        // the weasel grid row (p. 125 print order)
    if (mm2wxyzWXYZStatAc(0) != 6
            || mm2wxyzWXYZStatHd(0) != 0
            || mm2wxyzWXYZStatHdBonus(0) != 0
            || mm2wxyzWXYZStatAvgHp(0) != 2
            || mm2wxyzWXYZStatAttacks(0) != 1
            || mm2wxyzWXYZStatXp(0) != 2
            || mm2wxyzWXYZStatXpHp(0) != 1
            || mm2wxyzWXYZStatLairPct(0) != 0
            || mm2wxyzWXYZStatMove(0) != 15
            || mm2wxyzWXYZStatMr(0) != 0
            || mm2wxyzWeaselXpValue() != 4
            || mm2wxyzWeaselXpLevel() != 1
        )
            ++bad;
        // the webbird grid row (p. 125 print order)
    if (mm2wxyzWXYZStatAc(1) != 8
            || mm2wxyzWXYZStatHd(1) != 0
            || mm2wxyzWXYZStatHdBonus(1) != 0
            || mm2wxyzWXYZStatAvgHp(1) != 2
            || mm2wxyzWXYZStatAttacks(1) != 1
            || mm2wxyzWXYZStatXp(1) != 7
            || mm2wxyzWXYZStatXpHp(1) != 1
            || mm2wxyzWXYZStatLairPct(1) != 0
            || mm2wxyzWXYZStatMove(1) != 3
            || mm2wxyzWXYZStatMr(1) != 0
            || mm2wxyzWebbirdXpValue() != 9
            || mm2wxyzWebbirdXpLevel() != 1
        )
            ++bad;
        // the wemic grid row (p. 125 print order)
    if (mm2wxyzWXYZStatAc(2) != 6
            || mm2wxyzWXYZStatHd(2) != 5
            || mm2wxyzWXYZStatHdBonus(2) != 8
            || mm2wxyzWXYZStatAvgHp(2) != 25
            || mm2wxyzWXYZStatAttacks(2) != 2
            || mm2wxyzWXYZStatXp(2) != 200
            || mm2wxyzWXYZStatXpHp(2) != 7
            || mm2wxyzWXYZStatLairPct(2) != 50
            || mm2wxyzWXYZStatMove(2) != 12
            || mm2wxyzWXYZStatMr(2) != 0
            || mm2wxyzWemicXpValue() != 375
            || mm2wxyzWemicXpLevel() != 4
        )
            ++bad;
        // the black willow grid row (p. 126 print order)
    if (mm2wxyzWXYZStatAc(3) != 2
            || mm2wxyzWXYZStatHd(3) != 12
            || mm2wxyzWXYZStatHdBonus(3) != 0
            || mm2wxyzWXYZStatAvgHp(3) != 42
            || mm2wxyzWXYZStatAttacks(3) != 10
            || mm2wxyzWXYZStatXp(3) != 2400
            || mm2wxyzWXYZStatXpHp(3) != 20
            || mm2wxyzWXYZStatLairPct(3) != 100
            || mm2wxyzWXYZStatMove(3) != 1
            || mm2wxyzWXYZStatMr(3) != 0
            || mm2wxyzWillowXpValue() != 3240
            || mm2wxyzWillowXpLevel() != 8
        )
            ++bad;
        // the wolf-in-sheep's-clothing grid row (p. 127 print order)
    if (mm2wxyzWXYZStatAc(4) != 3
            || mm2wxyzWXYZStatHd(4) != 9
            || mm2wxyzWXYZStatHdBonus(4) != 0
            || mm2wxyzWXYZStatAvgHp(4) != 31
            || mm2wxyzWXYZStatAttacks(4) != 3
            || mm2wxyzWXYZStatXp(4) != 900
            || mm2wxyzWXYZStatXpHp(4) != 14
            || mm2wxyzWXYZStatLairPct(4) != 0
            || mm2wxyzWXYZStatMove(4) != 1
            || mm2wxyzWXYZStatMr(4) != 0
            || mm2wxyzWolfIscXpValue() != 1334
            || mm2wxyzWolfIscXpLevel() != 6
        )
            ++bad;
        // the wolfwere grid row (p. 127 print order)
    if (mm2wxyzWXYZStatAc(5) != 3
            || mm2wxyzWXYZStatHd(5) != 5
            || mm2wxyzWXYZStatHdBonus(5) != 1
            || mm2wxyzWXYZStatAvgHp(5) != 18
            || mm2wxyzWXYZStatAttacks(5) != 2
            || mm2wxyzWXYZStatXp(5) != 550
            || mm2wxyzWXYZStatXpHp(5) != 6
            || mm2wxyzWXYZStatLairPct(5) != 35
            || mm2wxyzWXYZStatMove(5) != 15
            || mm2wxyzWXYZStatMr(5) != 10
            || mm2wxyzWolfwereXpValue() != 658
            || mm2wxyzWolfwereXpLevel() != 6
        )
            ++bad;
        // the tenebrous worm grid row (p. 127 print order)
    if (mm2wxyzWXYZStatAc(6) != 1
            || mm2wxyzWXYZStatHd(6) != 10
            || mm2wxyzWXYZStatHdBonus(6) != 0
            || mm2wxyzWXYZStatAvgHp(6) != 35
            || mm2wxyzWXYZStatAttacks(6) != 1
            || mm2wxyzWXYZStatXp(6) != 2400
            || mm2wxyzWXYZStatXpHp(6) != 20
            || mm2wxyzWXYZStatLairPct(6) != 0
            || mm2wxyzWXYZStatMove(6) != 1
            || mm2wxyzWXYZStatMr(6) != 0
            || mm2wxyzTenebrousXpValue() != 3100
            || mm2wxyzTenebrousXpLevel() != 7
        )
            ++bad;
        // the tunnel worm grid row (p. 128 print order)
    if (mm2wxyzWXYZStatAc(7) != 4
            || mm2wxyzWXYZStatHd(7) != 9
            || mm2wxyzWXYZStatHdBonus(7) != 3
            || mm2wxyzWXYZStatAvgHp(7) != 34
            || mm2wxyzWXYZStatAttacks(7) != 1
            || mm2wxyzWXYZStatXp(7) != 1350
            || mm2wxyzWXYZStatXpHp(7) != 14
            || mm2wxyzWXYZStatLairPct(7) != 76
            || mm2wxyzWXYZStatMove(7) != 6
            || mm2wxyzWXYZStatMr(7) != 0
            || mm2wxyzTunnelXpValue() != 1826
            || mm2wxyzTunnelXpLevel() != 7
        )
            ++bad;
        // the xag-ya and xeg-yi grid row (p. 128 print order)
    if (mm2wxyzWXYZStatAc(8) != 0
            || mm2wxyzWXYZStatHd(8) != 5
            || mm2wxyzWXYZStatHdBonus(8) != 0
            || mm2wxyzWXYZStatAvgHp(8) != 17
            || mm2wxyzWXYZStatAttacks(8) != 1
            || mm2wxyzWXYZStatXp(8) != 1100
            || mm2wxyzWXYZStatXpHp(8) != 10
            || mm2wxyzWXYZStatLairPct(8) != 0
            || mm2wxyzWXYZStatMove(8) != 6
            || mm2wxyzWXYZStatMr(8) != 15
            || mm2wxyzXagYaXpValue() != 1270
            || mm2wxyzXagYaXpLevel() != 8
        )
            ++bad;
        // the xaren grid row (p. 129 print order)
    if (mm2wxyzWXYZStatAc(9) != 1
            || mm2wxyzWXYZStatHd(9) != 5
            || mm2wxyzWXYZStatHdBonus(9) != 5
            || mm2wxyzWXYZStatAvgHp(9) != 22
            || mm2wxyzWXYZStatAttacks(9) != 4
            || mm2wxyzWXYZStatXp(9) != 55
            || mm2wxyzWXYZStatXpHp(9) != 8
            || mm2wxyzWXYZStatLairPct(9) != 70
            || mm2wxyzWXYZStatMove(9) != 9
            || mm2wxyzWXYZStatMr(9) != 0
            || mm2wxyzXarenXpValue() != 231
            || mm2wxyzXarenXpLevel() != 0
        )
            ++bad;
        // the yeth hound grid row (p. 129 print order)
    if (mm2wxyzWXYZStatAc(10) != 0
            || mm2wxyzWXYZStatHd(10) != 3
            || mm2wxyzWXYZStatHdBonus(10) != 3
            || mm2wxyzWXYZStatAvgHp(10) != 13
            || mm2wxyzWXYZStatAttacks(10) != 1
            || mm2wxyzWXYZStatXp(10) != 235
            || mm2wxyzWXYZStatXpHp(10) != 4
            || mm2wxyzWXYZStatLairPct(10) != 100
            || mm2wxyzWXYZStatMove(10) != 15
            || mm2wxyzWXYZStatMr(10) != 10
            || mm2wxyzYethXpValue() != 287
            || mm2wxyzYethXpLevel() != 4
        )
            ++bad;
        // the yochlol grid row (p. 129 print order)
    if (mm2wxyzWXYZStatAc(11) != -10
            || mm2wxyzWXYZStatHd(11) != 6
            || mm2wxyzWXYZStatHdBonus(11) != 0
            || mm2wxyzWXYZStatAvgHp(11) != 21
            || mm2wxyzWXYZStatAttacks(11) != 1
            || mm2wxyzWXYZStatXp(11) != 1275
            || mm2wxyzWXYZStatXpHp(11) != 10
            || mm2wxyzWXYZStatLairPct(11) != 0
            || mm2wxyzWXYZStatMove(11) != 12
            || mm2wxyzWXYZStatMr(11) != 50
            || mm2wxyzYochlolXpValue() != 1485
            || mm2wxyzYochlolXpLevel() != 7
        )
            ++bad;
        // the yuan ti grid row (p. 130 print order)
    if (mm2wxyzWXYZStatAc(12) != 4
            || mm2wxyzWXYZStatHd(12) != 6
            || mm2wxyzWXYZStatHdBonus(12) != 0
            || mm2wxyzWXYZStatAvgHp(12) != 21
            || mm2wxyzWXYZStatAttacks(12) != 2
            || mm2wxyzWXYZStatXp(12) != 0
            || mm2wxyzWXYZStatXpHp(12) != 0
            || mm2wxyzWXYZStatLairPct(12) != 70
            || mm2wxyzWXYZStatMove(12) != 12
            || mm2wxyzWXYZStatMr(12) != 20
            || mm2wxyzYuanTiXpValue() != 0
            || mm2wxyzYuanTiXpLevel() != 0
        )
            ++bad;
        // the juju zombie grid row (p. 130 print order)
    if (mm2wxyzWXYZStatAc(13) != 6
            || mm2wxyzWXYZStatHd(13) != 3
            || mm2wxyzWXYZStatHdBonus(13) != 12
            || mm2wxyzWXYZStatAvgHp(13) != 22
            || mm2wxyzWXYZStatAttacks(13) != 1
            || mm2wxyzWXYZStatXp(13) != 110
            || mm2wxyzWXYZStatXpHp(13) != 4
            || mm2wxyzWXYZStatLairPct(13) != 0
            || mm2wxyzWXYZStatMove(13) != 9
            || mm2wxyzWXYZStatMr(13) != 0
            || mm2wxyzZombieJujuXpValue() != 198
            || mm2wxyzZombieJujuXpLevel() != 3
        )
            ++bad;
        // the monster zombie grid row (p. 131 print order)
    if (mm2wxyzWXYZStatAc(14) != 6
            || mm2wxyzWXYZStatHd(14) != 0
            || mm2wxyzWXYZStatHdBonus(14) != 0
            || mm2wxyzWXYZStatAvgHp(14) != 0
            || mm2wxyzWXYZStatAttacks(14) != 1
            || mm2wxyzWXYZStatXp(14) != 0
            || mm2wxyzWXYZStatXpHp(14) != 0
            || mm2wxyzWXYZStatLairPct(14) != 0
            || mm2wxyzWXYZStatMove(14) != 0
            || mm2wxyzWXYZStatMr(14) != 0
            || mm2wxyzZombieMonsterXpValue() != 0
            || mm2wxyzZombieMonsterXpLevel() != 0
        )
            ++bad;
        // the zorbo grid row (p. 131 print order)
    if (mm2wxyzWXYZStatAc(15) != 10
            || mm2wxyzWXYZStatHd(15) != 4
            || mm2wxyzWXYZStatHdBonus(15) != 2
            || mm2wxyzWXYZStatAvgHp(15) != 16
            || mm2wxyzWXYZStatAttacks(15) != 2
            || mm2wxyzWXYZStatXp(15) != 280
            || mm2wxyzWXYZStatXpHp(15) != 5
            || mm2wxyzWXYZStatLairPct(15) != 30
            || mm2wxyzWXYZStatMove(15) != 15
            || mm2wxyzWXYZStatMr(15) != 20
            || mm2wxyzZorboXpValue() != 360
            || mm2wxyzZorboXpLevel() != 5
        )
            ++bad;
        // the zygom grid row (p. 131 print order)
    if (mm2wxyzWXYZStatAc(16) != 8
            || mm2wxyzWXYZStatHd(16) != 3
            || mm2wxyzWXYZStatHdBonus(16) != 0
            || mm2wxyzWXYZStatAvgHp(16) != 10
            || mm2wxyzWXYZStatAttacks(16) != 1
            || mm2wxyzWXYZStatXp(16) != 85
            || mm2wxyzWXYZStatXpHp(16) != 4
            || mm2wxyzWXYZStatLairPct(16) != 50
            || mm2wxyzWXYZStatMove(16) != 1
            || mm2wxyzWXYZStatMr(16) != 0
            || mm2wxyzZygomXpValue() != 125
            || mm2wxyzZygomXpLevel() != 3
        )
            ++bad;
        printf("R815 MM2 letters WXYZ walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
