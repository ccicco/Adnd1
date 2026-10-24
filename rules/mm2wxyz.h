// =========================================================================================
// Adnd1 - rules/mm2wxyz.h
// THE MM2 LETTERS WXYZ WALK - THE WEASEL TO ZYGOM TURNS (pp. 125-132: the
// weasel, webbird and wemic p. 125, the black willow p. 126, the
// wolf-in-sheep's-clothing and wolfwere p. 127, the tenebrous worm and tunnel
// worm pp. 127-128 (the WORM family head), the xag-ya and xeg-yi and xaren
// pp. 128-129, the yeth hound, yochlol and yuan ti pp. 129-130, the juju
// zombie and monster zombie pp. 130-131, the zorbo and zygom pp. 131-132),
// promoted to the live registry; the WXYZ-FLIP round, the Letter W, X, Y and
// Z gap boxes and the Monsters from A-Z parent box flip to closed - the A-Z
// section complete
// census 737 -> 738.
//
// Round twenty of the MM2 arc, the NINTH letter walk (Curtiss Go call on the
// landed letters TUV walk; the letters WXYZ pin-time walk found SIXTEEN entry
// heads carrying SEVENTEEN stat blocks - the WORM family head the one two-def
// head, no prior-owned heads, no doctrine-only heads)
//
// The pin headers stay the print-fidelity record; the seventeen .lua defs
// ride the R791 data_files extension in the MM1 registry schema (the
// defensive coercers load the verbatim print cells, the WXYZStats grid
// carries the loader values)
//
namespace rules {

// ---- the MM2 letters WXYZ walk round pins (the R815 census) ----

// The MM2 letters WXYZ walk round: the weasel to zygom turns, the NINTH
// letter walk (Curtiss Go call on the landed letters TUV walk)
inline int mm2wxyzRound()
    { return 815; }

// The registry census before the R815 promotion (the landed R814 count)
inline int mm2wxyzRegistryBefore()
    { return 792; }

// The registry census after the R815 promotion (17 defs riding the R791
// data_files extension)
inline int mm2wxyzRegistryAfter()
    { return 809; }

// The 17 letters WXYZ defs promoted this round
inline int mm2wxyzDefCount()
    { return 17; }

// The 16 letters WXYZ entry heads (the WORM family head the one two-def head)
inline int mm2wxyzEntryCount()
    { return 16; }

// The 17 letters WXYZ stat blocks (one per def)
inline int mm2wxyzStatBlockHeadings()
    { return 17; }

// The letters WXYZ walk pins no doctrine-only heads
inline int mm2wxyzDoctrineHeads()
    { return 0; }

// The 16 letters WXYZ entry heads (the print walk)
inline int mm2wxyzLetterWXYZHeadings()
    { return 16; }

// The 17-row WXYZStats stat grid (one row per promoted def)
inline int mm2wxyzWXYZStatRows()
    { return 17; }

// The 32 closed boxes after the WXYZ-FLIP (the A-Z parent and the Letter W,
// X, Y, Z boxes)
inline int mm2wxyzGapClosed()
    { return 32; }

// The 5 open boxes after the WXYZ-FLIP
inline int mm2wxyzGapOpen()
    { return 5; }

// The letters WXYZ walk found zero prior-owned heads
inline int mm2wxyzPriorOwnedEntries()
    { return 0; }

// ---- the weasel pins (the R815 MM2 letters WXYZ walk) ----

// The weasel xp value (the I/2 + 1/hp row over 2 avg hp)
inline int mm2wxyzWeaselXpValue()
    { return 4; }

// The weasel xp level (the I/2 + 1/hp row numeral)
inline int mm2wxyzWeaselXpLevel()
    { return 1; }

// ---- the webbird pins (the R815 MM2 letters WXYZ walk) ----

// The webbird xp value (the I/7 + 1/hp row over 2 avg hp)
inline int mm2wxyzWebbirdXpValue()
    { return 9; }

// The webbird xp level (the I/7 + 1/hp row numeral)
inline int mm2wxyzWebbirdXpLevel()
    { return 1; }

// The webbird strand runs 7-12 feet long
inline int mm2wxyzWebbirdWebMinFeet()
    { return 7; }

// The webbird strand runs 7-12 feet long
inline int mm2wxyzWebbirdWebMaxFeet()
    { return 12; }

// The webbird chest appendage injects 2-8 eggs
inline int mm2wxyzWebbirdEggsMin()
    { return 2; }

// The webbird chest appendage injects 2-8 eggs
inline int mm2wxyzWebbirdEggsMax()
    { return 8; }

// The webbird grubs hatch in 3-6 turns
inline int mm2wxyzWebbirdGrubHatchMinTurns()
    { return 3; }

// The webbird grubs hatch in 3-6 turns
inline int mm2wxyzWebbirdGrubHatchMaxTurns()
    { return 6; }

// The webbirds shun flame; a torch-bearer is safe
inline bool mm2wxyzWebbirdShunsFlame()
    { return true; }

// ---- the wemic pins (the R815 MM2 letters WXYZ walk) ----

// The wemic xp value (the IV/200 + 7/hp row over 25 avg hp)
inline int mm2wxyzWemicXpValue()
    { return 375; }

// The wemic xp level (the IV/200 + 7/hp row numeral)
inline int mm2wxyzWemicXpLevel()
    { return 4; }

// The wemic leaps 10 feet upward
inline int mm2wxyzWemicLeapUpFeet()
    { return 10; }

// The wemic leaps 30 feet forward
inline int mm2wxyzWemicLeapForwardFeet()
    { return 30; }

// The wemic males often use tough leather shields (AC 5)
inline int mm2wxyzWemicMaleShieldAc()
    { return 5; }

// The wemic females claw with armor class 7
inline int mm2wxyzWemicFemaleAc()
    { return 7; }

// The wemic females gain +2 to hit if their young are attacked
inline int mm2wxyzWemicFemaleToHitBonus()
    { return 2; }

// The wemic pride carries 4-16 males
inline int mm2wxyzWemicPrideMalesMin()
    { return 4; }

// The wemic pride carries 4-16 males
inline int mm2wxyzWemicPrideMalesMax()
    { return 16; }

// The wemic pride carries 2-24 females
inline int mm2wxyzWemicPrideFemalesMin()
    { return 2; }

// The wemic pride carries 2-24 females
inline int mm2wxyzWemicPrideFemalesMax()
    { return 24; }

// The wemic pride carries 1-12 young
inline int mm2wxyzWemicPrideYoungMin()
    { return 1; }

// The wemic pride carries 1-12 young
inline int mm2wxyzWemicPrideYoungMax()
    { return 12; }

// The wemic tribal chief is AC 5, HD 6+4
inline int mm2wxyzWemicChiefAc()
    { return 5; }

// The wemic tribal chief is AC 5, HD 6+4
inline int mm2wxyzWemicChiefHd()
    { return 6; }

// The wemic tribal chief is AC 5, HD 6+4
inline int mm2wxyzWemicChiefHdBonus()
    { return 4; }

// The wemic clan king is AC 3, HD 9
inline int mm2wxyzWemicKingAc()
    { return 3; }

// The wemic clan king is AC 3, HD 9
inline int mm2wxyzWemicKingHd()
    { return 9; }

// The 70% chance a witch doctor is present with any tribe
inline int mm2wxyzWemicWitchDoctorChance()
    { return 70; }

// The wemic witch doctor maximum 7th level cleric
inline int mm2wxyzWemicWitchDoctorCleric()
    { return 7; }

// The wemic witch doctor maximum 4th level magic-user
inline int mm2wxyzWemicWitchDoctorMu()
    { return 4; }

// The wemics are surprised only on a 1
inline bool mm2wxyzWemicSurprisedOnlyOnOne()
    { return true; }

// The wemic young are noncombative
inline bool mm2wxyzWemicYoungNoncombative()
    { return true; }

// ---- the black willow pins (the R815 MM2 letters WXYZ walk) ----

// The black willow xp value (the VIII/2400 + 20/hp row over 42 avg hp)
inline int mm2wxyzWillowXpValue()
    { return 3240; }

// The black willow xp level (the VIII/2400 + 20/hp row numeral)
inline int mm2wxyzWillowXpLevel()
    { return 8; }

// The 90% chance a creature will not recognize a black willow
inline int mm2wxyzWillowDetectFailPct()
    { return 90; }

// The black willow drowsiness aura within a 20-foot radius
inline int mm2wxyzWillowDrowsinessRadiusFeet()
    { return 20; }

// The black willow trunk cavity is 8 feet deep
inline int mm2wxyzWillowCavityDepthFeet()
    { return 8; }

// The black willow sap fills 1 foot per 10 rounds
inline int mm2wxyzWillowSapFillRoundsPerFoot()
    { return 10; }

// The black willow sap inflicts 1-4 points per round
inline int mm2wxyzWillowSapDamageMin()
    { return 1; }

// The black willow sap inflicts 1-4 points per round
inline int mm2wxyzWillowSapDamageMax()
    { return 4; }

// The black willow digestion is indicated by -12 or more hit points
inline int mm2wxyzWillowDigestionFloor()
    { return -12; }

// The black willow regenerates 1 point per turn
inline int mm2wxyzWillowRegenPerTurn()
    { return 1; }

// Maximum normal damage inside the trunk is 1 point per round
inline int mm2wxyzWillowConfinedMaxDamage()
    { return 1; }

// No saving throw is possible against the drowsiness aura
inline bool mm2wxyzWillowNoSaveVsDrowsiness()
    { return true; }

// A digested victim cannot be resurrected
inline bool mm2wxyzWillowResurrectionImpossible()
    { return true; }

// ---- the wolf-in-sheep's-clothing pins (the R815 WXYZ walk) ----

// The wolfISC xp value (the VI/900 + 14/hp row over 31 avg hp)
inline int mm2wxyzWolfIscXpValue()
    { return 1334; }

// The wolfISC xp level (the VI/900 + 14/hp row numeral)
inline int mm2wxyzWolfIscXpLevel()
    { return 6; }

// The wolfISC has 7 root tentacles
inline int mm2wxyzWolfIscRootTentacles()
    { return 7; }

// The wolfISC root tentacles take 19-22 hit points each
inline int mm2wxyzWolfIscRootHpMin()
    { return 19; }

// The wolfISC root tentacles take 19-22 hit points each
inline int mm2wxyzWolfIscRootHpMax()
    { return 22; }

// The wolfISC eyestalks take 13-16 hit points
inline int mm2wxyzWolfIscEyestalkHpMin()
    { return 13; }

// The wolfISC eyestalks take 13-16 hit points
inline int mm2wxyzWolfIscEyestalkHpMax()
    { return 16; }

// The wolfISC regenerates appendages in 1-4 weeks
inline int mm2wxyzWolfIscRegenMinWeeks()
    { return 1; }

// The wolfISC regenerates appendages in 1-4 weeks
inline int mm2wxyzWolfIscRegenMaxWeeks()
    { return 4; }

// The wolfISC lures prey within 12 feet
inline int mm2wxyzWolfIscLureRangeFeet()
    { return 12; }

// The wolfISC maw bite is 7-12 hit points
inline int mm2wxyzWolfIscBiteMin()
    { return 7; }

// The wolfISC maw bite is 7-12 hit points
inline int mm2wxyzWolfIscBiteMax()
    { return 12; }

// The wolfISC is 90% likely to attack by surprise
inline int mm2wxyzWolfIscSurprisePct()
    { return 90; }

// Breaking a wolfISC root requires 13 or greater strength
inline int mm2wxyzWolfIscBreakStrength()
    { return 13; }

// The 18-strength base 30% break-free chance
inline int mm2wxyzWolfIscBaseBreakPct()
    { return 30; }

// Each strength point above 13 allows a 5% break chance
inline int mm2wxyzWolfIscBreakPctPerPoint()
    { return 5; }

// Only creatures with exceptional strength can break a root tentacle
inline bool mm2wxyzWolfIscExceptionalStrengthOnly()
    { return true; }

// ---- the wolfwere pins (the R815 MM2 letters WXYZ walk) ----

// The wolfwere xp value (the VI/550 + 6/hp row over 18 avg hp)
inline int mm2wxyzWolfwereXpValue()
    { return 658; }

// The wolfwere xp level (the VI/550 + 6/hp row numeral)
inline int mm2wxyzWolfwereXpLevel()
    { return 6; }

// The 75% chance a wolfwere runs with a pack
inline int mm2wxyzWolfwerePackChance()
    { return 75; }

// The wolfwere pack is wolves (30%) or worgs (70%)
inline int mm2wxyzWolfwerePackWorgPct()
    { return 70; }

// The wolfwere lethargy lasts 5-8 rounds
inline int mm2wxyzWolfwereLethargyMinRounds()
    { return 5; }

// The wolfwere lethargy lasts 5-8 rounds
inline int mm2wxyzWolfwereLethargyMaxRounds()
    { return 8; }

// The wolfwere bite is 2-12
inline int mm2wxyzWolfwereBiteMin()
    { return 2; }

// The wolfwere bite is 2-12
inline int mm2wxyzWolfwereBiteMax()
    { return 12; }

// The wolfwere is hit only by cold-wrought iron or +1 or better
inline bool mm2wxyzWolfwereIronOrMagicToHit()
    { return true; }

// The wolfwere are disgusted by wolvesbane and shun it
inline bool mm2wxyzWolfwereShunsWolvesbane()
    { return true; }

// ---- the tenebrous worm pins (the R815 MM2 letters WXYZ walk) ----

// The tenebrous worm xp value (the VII/2400 + 20/hp row over 35 avg hp)
inline int mm2wxyzTenebrousXpValue()
    { return 3100; }

// The tenebrous worm xp level (the VII/2400 + 20/hp row numeral)
inline int mm2wxyzTenebrousXpLevel()
    { return 7; }

// The tenebrous worm bite is 2-20
inline int mm2wxyzTenebrousBiteMin()
    { return 2; }

// The tenebrous worm bite is 2-20
inline int mm2wxyzTenebrousBiteMax()
    { return 20; }

// The tenebrous bristles inflict 1-4 points of damage
inline int mm2wxyzTenebrousBristleDamageMax()
    { return 4; }

// The tenebrous acid bite saves vs poison at -3
inline int mm2wxyzTenebrousPoisonSavePenalty()
    { return 3; }

// A bristle victim needs neutralize or slow poison in 1-4 rounds
inline int mm2wxyzTenebrousNeutralizeMinRounds()
    { return 1; }

// A bristle victim needs neutralize or slow poison in 1-4 rounds
inline int mm2wxyzTenebrousNeutralizeMaxRounds()
    { return 4; }

// The bristle contact chance drops 20% against the head
inline int mm2wxyzTenebrousHeadContactReductionPct()
    { return 20; }

// The tenebrous mandibles are worth 1000-3000 gp per set
inline int mm2wxyzTenebrousMandibleGpMin()
    { return 1000; }

// The tenebrous mandibles are worth 1000-3000 gp per set
inline int mm2wxyzTenebrousMandibleGpMax()
    { return 3000; }

// The tenebrous mandibles drip a highly caustic acid
inline bool mm2wxyzTenebrousAcidBite()
    { return true; }

// A bristle victim must save vs poison or be paralyzed
inline bool mm2wxyzTenebrousBristleParalysis()
    { return true; }

// ---- the tunnel worm pins (the R815 MM2 letters WXYZ walk) ----

// The tunnel worm xp value (the VII/1350 + 14/hp row over 34 avg hp)
inline int mm2wxyzTunnelXpValue()
    { return 1826; }

// The tunnel worm xp level (the VII/1350 + 14/hp row numeral)
inline int mm2wxyzTunnelXpLevel()
    { return 7; }

// The tunnel worm lunges at +2 to hit
inline int mm2wxyzTunnelLungeBonus()
    { return 2; }

// The tunnel worm bite is 2-16 per round
inline int mm2wxyzTunnelBiteMin()
    { return 2; }

// The tunnel worm bite is 2-16 per round
inline int mm2wxyzTunnelBiteMax()
    { return 16; }

// The tunnel worm chews leather in 1 round
inline int mm2wxyzTunnelLeatherRounds()
    { return 1; }

// The tunnel worm chews chain mail in 2 rounds
inline int mm2wxyzTunnelChainRounds()
    { return 2; }

// The tunnel worm chews plate mail in 3 rounds
inline int mm2wxyzTunnelPlateRounds()
    { return 3; }

// The tunnel worm retreats after 15 or more fire damage
inline int mm2wxyzTunnelRetreatFireDamage()
    { return 15; }

// The tunnel worm retreats after losing more than 60% of hp
inline int mm2wxyzTunnelRetreatHpPct()
    { return 60; }

// The tunnel worm burrows are 2 feet in diameter
inline int mm2wxyzTunnelBurrowDiameterFeet()
    { return 2; }

// The tunnel worm drags corpses back to its lair
inline bool mm2wxyzTunnelDragsCorpsesToLair()
    { return true; }

// ---- the xag-ya and xeg-yi pins (the R815 MM2 letters WXYZ walk) ----

// The xag-ya and xeg-yi xp value (the VIII/1100 + 10/hp row over 17 avg hp)
inline int mm2wxyzXagYaXpValue()
    { return 1270; }

// The xag-ya and xeg-yi xp level (the VIII/1100 + 10/hp row numeral)
inline int mm2wxyzXagYaXpLevel()
    { return 8; }

// The xag-ya bolt reaches up to 10 feet
inline int mm2wxyzXagYaBoltRangeFeet()
    { return 10; }

// The death release inflicts double damage (14-24)
inline int mm2wxyzXagYaDeathBlastDamageMin()
    { return 14; }

// The death release inflicts double damage (14-24)
inline int mm2wxyzXagYaDeathBlastDamageMax()
    { return 24; }

// The death release bursts with a 10-foot radius
inline int mm2wxyzXagYaDeathBlastRadiusFeet()
    { return 10; }

// A xag-ya meeting a xeg-yi explodes in a 30-foot radius
inline int mm2wxyzXagYaMeetBlastRadiusFeet()
    { return 30; }

// The meeting blast looses 28-48 points (4d6+24)
inline int mm2wxyzXagYaMeetBlastMin()
    { return 28; }

// The meeting blast looses 28-48 points (4d6+24)
inline int mm2wxyzXagYaMeetBlastMax()
    { return 48; }

// Contact with heated metal inflicts 1-4 points per segment
inline int mm2wxyzXagYaMetalDamageMin()
    { return 1; }

// Contact with heated metal inflicts 1-4 points per segment
inline int mm2wxyzXagYaMetalDamageMax()
    { return 4; }

// A summoned guardian attacks within 3" of the object
inline int mm2wxyzXagYaGuardianRadiusInches()
    { return 3; }

// Only magic weapons will affect these creatures
inline bool mm2wxyzXagYaMagicWeaponOnly()
    { return true; }

// A shield spell prevents the attack of either creature
inline bool mm2wxyzXagYaShieldRepulses()
    { return true; }

// ---- the xaren pins (the R815 MM2 letters WXYZ walk) ----

// The xaren xp value (the 55 + 8/hp row over 22 avg hp - no level numeral)
inline int mm2wxyzXarenXpValue()
    { return 231; }

// The xaren xp level (the print row carries no level numeral)
inline int mm2wxyzXarenXpLevel()
    { return 0; }

// The xaren claw rakes are 1-3 (x3)
inline int mm2wxyzXarenClawDamageMin()
    { return 1; }

// The xaren claw rakes are 1-3 (x3)
inline int mm2wxyzXarenClawDamageMax()
    { return 3; }

// The xaren bite is 4-16
inline int mm2wxyzXarenBiteDamageMin()
    { return 4; }

// The xaren bite is 4-16
inline int mm2wxyzXarenBiteDamageMax()
    { return 16; }

// The xaren smells ore at 20 feet
inline int mm2wxyzXarenOreSmellFeet()
    { return 20; }

// The xaren smells magic metal at 40 feet
inline int mm2wxyzXarenMagicSmellFeet()
    { return 40; }

// Eaten magic metal can never raise xaren hp past 45
inline int mm2wxyzXarenMagicMetalHpCap()
    { return 45; }

// Metal weighing 5-8 pounds satiates a xaren for 1-4 days
inline int mm2wxyzXarenMealPoundsMin()
    { return 5; }

// Metal weighing 5-8 pounds satiates a xaren for 1-4 days
inline int mm2wxyzXarenMealPoundsMax()
    { return 8; }

// The 80% attack chance if smelled magic metal is not offered
inline int mm2wxyzXarenAttackIfMagicWithheldPct()
    { return 80; }

// The 40% attack chance if ordinary metal is not offered
inline int mm2wxyzXarenAttackIfMetalWithheldPct()
    { return 40; }

// A xaren is 40% likely to bite an attacking magic weapon
inline int mm2wxyzXarenWeaponBiteChance()
    { return 40; }

// The xaren moves through solid rock at 9" per round
inline int mm2wxyzXarenRockMoveInches()
    { return 9; }

// The xaren burrows in rock at 3" per round
inline int mm2wxyzXarenBurrowInches()
    { return 3; }

// Xaren are not harmed by fire and cold, even magical varieties
inline bool mm2wxyzXarenFireAndColdImmune()
    { return true; }

// Sharp weapons do half damage to xaren; blunt weapons full
inline bool mm2wxyzXarenBluntFullDamage()
    { return true; }

// ---- the yeth hound pins (the R815 MM2 letters WXYZ walk) ----

// The yeth hound xp value (the IV/235 + 4/hp row over 13 avg hp)
inline int mm2wxyzYethXpValue()
    { return 287; }

// The yeth hound xp level (the IV/235 + 4/hp row numeral)
inline int mm2wxyzYethXpLevel()
    { return 4; }

// The yeth baying carries a mile or more
inline int mm2wxyzYethBayingRangeMiles()
    { return 1; }

// Creatures within 9" must save vs spells or flee in panic
inline int mm2wxyzYethPanicRadiusInches()
    { return 9; }

// The yeth hound bite is 2-8
inline int mm2wxyzYethBiteMin()
    { return 2; }

// The yeth hound bite is 2-8
inline int mm2wxyzYethBiteMax()
    { return 8; }

// Yeth hounds appear 4-16 at a time
inline int mm2wxyzYethPackMin()
    { return 4; }

// Yeth hounds appear 4-16 at a time
inline int mm2wxyzYethPackMax()
    { return 16; }

// Only the magical pluses of a weapon inflict damage, 1 point each
inline int mm2wxyzYethPlusDamagePerPlus()
    { return 1; }

// Silver weapons inflict 1 point because of their metal
inline int mm2wxyzYethSilverDamage()
    { return 1; }

// Yeth hounds can be struck only by silver or magic weapons
inline bool mm2wxyzYethSilverOrMagicToHit()
    { return true; }

// Yeth hounds have the magical ability to fly
inline bool mm2wxyzYethFlies()
    { return true; }

// ---- the yochlol pins (the R815 MM2 letters WXYZ walk) ----

// The yochlol xp value (the VII/1275 + 10/hp row over 21 avg hp)
inline int mm2wxyzYochlolXpValue()
    { return 1485; }

// The yochlol xp level (the VII/1275 + 10/hp row numeral)
inline int mm2wxyzYochlolXpLevel()
    { return 7; }

// The gaseous yochlol effective armor class -10 (unmated)
inline int mm2wxyzYochlolGaseousAc()
    { return -10; }

// The materialized yochlol armor class 10
inline int mm2wxyzYochlolMaterializedAc()
    { return 10; }

// The amorphous yochlol attacks with 8 pseudopods
inline int mm2wxyzYochlolPseudopods()
    { return 8; }

// The yochlol pseudopod blow does 5-8 points
inline int mm2wxyzYochlolPseudopodDamageMin()
    { return 5; }

// The yochlol pseudopod blow does 5-8 points
inline int mm2wxyzYochlolPseudopodDamageMax()
    { return 8; }

// A stinking cloud spell heals a gaseous yochlol 3-12 points
inline int mm2wxyzYochlolStinkingHealMin()
    { return 3; }

// A stinking cloud spell heals a gaseous yochlol 3-12 points
inline int mm2wxyzYochlolStinkingHealMax()
    { return 12; }

// A gust of wind spell causes 6-36 points of damage
inline int mm2wxyzYochlolGustOfWindDamageMin()
    { return 6; }

// A gust of wind spell causes 6-36 points of damage
inline int mm2wxyzYochlolGustOfWindDamageMax()
    { return 36; }

// A humanoid-form yochlol fights as a 6th-level fighter
inline int mm2wxyzYochlolFighterLevel()
    { return 6; }

// The yochlol strength is effectively 18/50
inline int mm2wxyzYochlolStrength()
    { return 18; }

// The yochlol strength is effectively 18/50
inline int mm2wxyzYochlolStrengthPercent()
    { return 50; }

// Yochlol are a type of demon and are affected by such things
inline bool mm2wxyzYochlolDemonType()
    { return true; }

// A wind walk spell destroys one yochlol
inline bool mm2wxyzYochlolWindWalkDestroys()
    { return true; }

// In gaseous form only a +1 or better weapon can hit it
inline bool mm2wxyzYochlolGaseousPlusOneToHit()
    { return true; }

// ---- the yuan ti pins (the R815 MM2 letters WXYZ walk) ----

// The yuan ti xp value (the Variable row - the by_level source)
inline int mm2wxyzYuanTiXpValue()
    { return 0; }

// The yuan ti xp level (the Variable row carries no numeral)
inline int mm2wxyzYuanTiXpLevel()
    { return 0; }

// The yuan ti purebloods have 6 hit dice
inline int mm2wxyzYuanTiPurebloodHd()
    { return 6; }

// The yuan ti halfbreeds have 7-8 hit dice
inline int mm2wxyzYuanTiHalfbreedHdMin()
    { return 7; }

// The yuan ti halfbreeds have 7-8 hit dice
inline int mm2wxyzYuanTiHalfbreedHdMax()
    { return 8; }

// The yuan ti abominations have 9 hit dice
inline int mm2wxyzYuanTiAbominationHd()
    { return 9; }

// The purebloods pass as humans 80% of the time
inline int mm2wxyzYuanTiPurebloodPassPct()
    { return 80; }

// A snake-head halfbreed bites for 1-10 points
inline int mm2wxyzYuanTiSnakeHeadBiteMin()
    { return 1; }

// A snake-head halfbreed bites for 1-10 points
inline int mm2wxyzYuanTiSnakeHeadBiteMax()
    { return 10; }

// A snake-headed-arms halfbreed bites for 1-6 points
inline int mm2wxyzYuanTiSnakeArmBiteMin()
    { return 1; }

// A snake-headed-arms halfbreed bites for 1-6 points
inline int mm2wxyzYuanTiSnakeArmBiteMax()
    { return 6; }

// A tailed halfbreed constricts for 1-4 points
inline int mm2wxyzYuanTiTailConstrictMin()
    { return 1; }

// A tailed halfbreed constricts for 1-4 points
inline int mm2wxyzYuanTiTailConstrictMax()
    { return 4; }

// Yuan ti with human legs move 12" per turn
inline int mm2wxyzYuanTiHumanMoveInches()
    { return 12; }

// Yuan ti with snake bodies move 9" per turn
inline int mm2wxyzYuanTiSnakeMoveInches()
    { return 9; }

// The human-headed yuan ti darkness is a 15-foot radius
inline int mm2wxyzYuanTiDarknessRadiusFeet()
    { return 15; }

// All yuan ti snake parts have an armor class of 0
inline int mm2wxyzYuanTiSnakePartAc()
    { return 0; }

// All yuan ti are devout demon worshippers
inline bool mm2wxyzYuanTiDemonWorshippers()
    { return true; }

// Yuan ti may speak with any snake or snake-like monster
inline bool mm2wxyzYuanTiSpeaksWithSnakes()
    { return true; }

// ---- the juju zombie pins (the R815 MM2 letters WXYZ walk) ----

// The juju zombie xp value (the III/110 + 4/hp row over 22 avg hp)
inline int mm2wxyzZombieJujuXpValue()
    { return 198; }

// The juju zombie xp level (the III/110 + 4/hp row numeral)
inline int mm2wxyzZombieJujuXpLevel()
    { return 3; }

// The juju zombie attack is 3-12
inline int mm2wxyzZombieJujuDamageMin()
    { return 3; }

// The juju zombie attack is 3-12
inline int mm2wxyzZombieJujuDamageMax()
    { return 12; }

// Juju zombies climb like 6th-level thieves
inline int mm2wxyzZombieJujuClimbAsThiefLevel()
    { return 6; }

// Juju zombies attack as if they were 6 hit dice monsters
inline int mm2wxyzZombieJujuAttacksAsHd()
    { return 6; }

// Juju zombies can be hit only by +1 or better magic weapons
inline bool mm2wxyzZombieJujuPlusOneToHit()
    { return true; }

// Piercing or blunt attacks do one-half normal damage
inline bool mm2wxyzZombieJujuPiercingHalfDamage()
    { return true; }

// Juju zombies are unaffected by all dweomers which affect the mind
inline bool mm2wxyzZombieJujuMindImmune()
    { return true; }

// Fire has only one-half normal effect on juju zombies
inline bool mm2wxyzZombieJujuFireHalfEffect()
    { return true; }

// Juju zombies move quickly even under water, for they do not breathe
inline bool mm2wxyzZombieJujuUnderwaterCapable()
    { return true; }

// A juju zombie is turned as if it were a spectre
inline bool mm2wxyzZombieJujuTurnedAsSpectre()
    { return true; }

// ---- the monster zombie pins (the R815 MM2 letters WXYZ walk) ----

// The monster zombie xp value (the capture-lossy nil block - the derro
// sentinel)
inline int mm2wxyzZombieMonsterXpValue()
    { return 0; }

// The monster zombie xp level (the nil block carries no numeral)
inline int mm2wxyzZombieMonsterXpLevel()
    { return 0; }

// The monster zombie attack is 4-16
inline int mm2wxyzZombieMonsterDamageMin()
    { return 4; }

// The monster zombie attack is 4-16
inline int mm2wxyzZombieMonsterDamageMax()
    { return 16; }

// Holy water inflicts 2-8 points per vial on monster zombies
inline int mm2wxyzZombieMonsterHolyWaterMin()
    { return 2; }

// Holy water inflicts 2-8 points per vial on monster zombies
inline int mm2wxyzZombieMonsterHolyWaterMax()
    { return 8; }

// Blunt weapons inflict but one-half damage on monster zombies
inline bool mm2wxyzZombieMonsterBluntHalfDamage()
    { return true; }

// Monster zombies are turned by clerics as if they were ghasts
inline bool mm2wxyzZombieMonsterTurnedAsGhast()
    { return true; }

// Monster zombies strike last in melee, for they are slow-moving
inline bool mm2wxyzZombieMonsterStrikesLast()
    { return true; }

// ---- the zorbo pins (the R815 MM2 letters WXYZ walk) ----

// The zorbo xp value (the V/280 + 5/hp row over 16 avg hp)
inline int mm2wxyzZorboXpValue()
    { return 360; }

// The zorbo xp level (the V/280 + 5/hp row numeral)
inline int mm2wxyzZorboXpLevel()
    { return 5; }

// The zorbo absorbs earth as AC 7
inline int mm2wxyzZorboEarthAc()
    { return 7; }

// The zorbo absorbs wood as AC 5
inline int mm2wxyzZorboWoodAc()
    { return 5; }

// The zorbo absorbs metal as AC 3
inline int mm2wxyzZorboMetalAc()
    { return 3; }

// The zorbo absorbs stone as AC 0
inline int mm2wxyzZorboStoneAc()
    { return 0; }

// The zorbo base armor class 10 before absorption
inline int mm2wxyzZorboBaseAc()
    { return 10; }

// The absorbed armor class lasts 10 rounds
inline int mm2wxyzZorboAbsorbDurationRounds()
    { return 10; }

// The zorbo claws are 1-2 each
inline int mm2wxyzZorboClawDamageMin()
    { return 1; }

// The zorbo claws are 1-2 each
inline int mm2wxyzZorboClawDamageMax()
    { return 2; }

// A zorbo hit turns 1 random protective item to dust (no save)
inline bool mm2wxyzZorboAbsorbsItemToDust()
    { return true; }

// An absorbed item never makes the zorbo armor class worse
inline bool mm2wxyzZorboNeverWorseAc()
    { return true; }

// ---- the zygom pins (the R815 MM2 letters WXYZ walk) ----

// The zygom xp value (the III/85 + 4/hp row over 10 avg hp, plus xp for host)
inline int mm2wxyzZygomXpValue()
    { return 125; }

// The zygom xp level (the III/85 + 4/hp row numeral)
inline int mm2wxyzZygomXpLevel()
    { return 3; }

// One or 2 dozen fungoid growths form one communal zygom
inline int mm2wxyzZygomColonyMin()
    { return 12; }

// One or 2 dozen fungoid growths form one communal zygom
inline int mm2wxyzZygomColonyMax()
    { return 24; }

// The 1 in 6 chance a broken cap sticks fast on contact
inline int mm2wxyzZygomGlueChance()
    { return 6; }

// The zygom glue holds 2-5 days before it drys and crumbles
inline int mm2wxyzZygomGlueDaysMin()
    { return 2; }

// The zygom glue holds 2-5 days before it drys and crumbles
inline int mm2wxyzZygomGlueDaysMax()
    { return 5; }

// Zygom infestation leads to death in 1-8 weeks
inline int mm2wxyzZygomInfestationWeeksMin()
    { return 1; }

// Zygom infestation leads to death in 1-8 weeks
inline int mm2wxyzZygomInfestationWeeksMax()
    { return 8; }

// No magic affecting the mind will affect zygoms
inline bool mm2wxyzZygomMindMagicImmune()
    { return true; }

// Only a cure disease will remove zygom infestation
inline bool mm2wxyzZygomCureDiseaseRemoves()
    { return true; }

// ---- the WXYZStats grid pins (the R815 MM2 letters WXYZ walk) ----

// The armor class cells (the weasel 6, webbird 8, black willow 2, wolfwere 3,
// tenebrous worm 1, tunnel worm 4, xag-ya 0, xaren 1, yeth hound 0, juju and
// monster zombie 6 and zygom 8 the bare-numeral reads; the wemic 6 (5), the
// wolfISC 3/5/7 the root-tentacle read, the zorbo 10 (See below) and the yuan
// ti 4/0 the first-int reads; the yochlol -10 the UNQUOTED number read over
// the -10 or 10 cell - the tarrasque precedent)
inline int mm2wxyzWXYZStatAc(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 6;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return -10;
        case 12:
            return 4;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 10;
        case 16:
            return 8;
        default:
            return 0;
        }
    }

// The hit dice num cells (the weasel 1/4 and the webbird 1/2 the half-dice
// hdNum-0 reads - the atomie precedent; the black willow 12-19, the xag-ya
// 5-8 and the yuan ti 6-9 the low-end reads; the monster zombie the
// capture-lossy nil block 0 - the shade precedent)
inline int mm2wxyzWXYZStatHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 5;
        case 3:
            return 12;
        case 4:
            return 9;
        case 5:
            return 5;
        case 6:
            return 10;
        case 7:
            return 9;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 3;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 3;
        case 14:
            return 0;
        case 15:
            return 4;
        case 16:
            return 3;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the wemic 5+8, the wolfwere 5+1, the tunnel worm
// 9+3, the xaren 5+5, the yeth hound 3+3 and the juju zombie 3+12)
inline int mm2wxyzWXYZStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 8;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 12;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 0;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x hd + bonus) formula; the weasel and
// webbird 2 - the atomie half-dice precedent; the monster zombie the nil
// block 0)
inline int mm2wxyzWXYZStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 25;
        case 3:
            return 42;
        case 4:
            return 31;
        case 5:
            return 18;
        case 6:
            return 35;
        case 7:
            return 34;
        case 8:
            return 17;
        case 9:
            return 22;
        case 10:
            return 13;
        case 11:
            return 21;
        case 12:
            return 21;
        case 13:
            return 22;
        case 14:
            return 0;
        case 15:
            return 16;
        case 16:
            return 10;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the black willow 7-12 the 10 clamp
// - the land urchin precedent; the wolfISC 1-3 the 3 max read; the wolfwere 1
// or 2 and the zorbo 2 claws the max reads; the yochlol See below and the
// zygom By host type the 1 floor; the monster zombie the omitted-field 1
// floor)
inline int mm2wxyzWXYZStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 10;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 1;
        default:
            return 0;
        }
    }

// The xp base cells (the xaren 55 + 8/hp the no-level-numeral row; the yuan
// ti Variable and the monster zombie the 0 reads - the yuan ti by the
// by_level source, the monster zombie the derro sentinel)
inline int mm2wxyzWXYZStatXp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 7;
        case 2:
            return 200;
        case 3:
            return 2400;
        case 4:
            return 900;
        case 5:
            return 550;
        case 6:
            return 2400;
        case 7:
            return 1350;
        case 8:
            return 1100;
        case 9:
            return 55;
        case 10:
            return 235;
        case 11:
            return 1275;
        case 12:
            return 0;
        case 13:
            return 110;
        case 14:
            return 0;
        case 15:
            return 280;
        case 16:
            return 85;
        default:
            return 0;
        }
    }

// The xp per hp cells (the weasel and webbird 1/hp; the wemic 7, the black
// willow 20, the wolfISC 14, the wolfwere 6, the tenebrous worm 20, the
// tunnel worm 14, the xag-ya 10, the xaren 8, the yeth hound 4, the yochlol
// 10, the juju zombie 4, the zorbo 5 and the zygom 4 per hp)
inline int mm2wxyzWXYZStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 7;
        case 3:
            return 20;
        case 4:
            return 14;
        case 5:
            return 6;
        case 6:
            return 20;
        case 7:
            return 14;
        case 8:
            return 10;
        case 9:
            return 8;
        case 10:
            return 4;
        case 11:
            return 10;
        case 12:
            return 0;
        case 13:
            return 4;
        case 14:
            return 0;
        case 15:
            return 5;
        case 16:
            return 4;
        default:
            return 0;
        }
    }

// The lair cells (the black willow and the yeth hound the 100 reads - the
// yeth 100% (daytime only) the bare-numeral read; the tunnel worm 76, the
// xaren and yuan ti 70, the wemic and zygom 50, the wolfwere 35, the zorbo
// 30; every Nil cell 0)
inline int mm2wxyzWXYZStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 50;
        case 3:
            return 100;
        case 4:
            return 0;
        case 5:
            return 35;
        case 6:
            return 0;
        case 7:
            return 76;
        case 8:
            return 0;
        case 9:
            return 70;
        case 10:
            return 100;
        case 11:
            return 0;
        case 12:
            return 70;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 30;
        case 16:
            return 50;
        default:
            return 0;
        }
    }

// The move cells (the first-int reads: the black willow 1/4 the 1 read, the
// yeth hound 15 over 15/27, the yuan ti 12 or 9 the 12 read, the zorbo 15/9,
// the webbird 3/18 and the zygom 1 (or host); the monster zombie the
// omitted-field 0)
inline int mm2wxyzWXYZStatMove(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 3;
        case 2:
            return 12;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 15;
        case 6:
            return 1;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 9;
        case 10:
            return 15;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 9;
        case 14:
            return 0;
        case 15:
            return 15;
        case 16:
            return 1;
        default:
            return 0;
        }
    }

// The magic resistance cells (the wolfwere and yeth hound 10%, the xag-ya
// 15%, the yuan ti and zorbo 20% and the yochlol 50% the percent reads; the
// juju zombie and zygom See below and every Standard cell 0)
inline int mm2wxyzWXYZStatMr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 10;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 50;
        case 12:
            return 20;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 20;
        case 16:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
