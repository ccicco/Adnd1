// =========================================================================================
// Adnd1 - rules/egp.h
// the Egyptian mythos - the D&DG walk round nine, print pp. 49-56: twenty-one
// beings from Ra the sungod Pharaoh to the Gods to Thoth the teacher of the
// gods, the four monster races (Apep, the Flame Snake, the Phoenix, the
// Minions of Set), the true Ankh, and the 97-word hieroglyph grid, across
// twelve planes.
// census 779 -> 780.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 050-057; the second printing); the
// collation voice: the archive.org 1st-print derivative
// (deities-demigods-1st-print, djvu.xml word geometry at 600dpi, segs 49-56).
// The adjudications: the GEOMETRY SWAP of the Ra and Anhur ability lines (the
// fold reversal caught by the x-coordinates and the +14 lance prose), Bast
// W:10 against the Termux W:70, the psionic classes by word geometry (the
// 46px, 29px and 28px II words against the Termux 11 and // garbles; the
// 9-10px I bars of Isis and Thoth), the foot-mark size decodes (Isis the
// printed 514 cell, Seker the 614, Thoth the 6%4 - the R853 lesson), and the
// odd MR prints (Set 59, Shu and Tefnut 69 - both voices agree). The flagged
// eyeball cells: Horus 6 foot 2 and the 15/15 move, the Nephthys twin size,
// the Minions size, the Flame Snake xp line, and the hieroglyph AT word.
//
namespace rules {

// ---- the R857 census ----

// the Egyptian mythos round: the D&DG walk round nine, print pp. 49-56
inline int egpRound()
    { return 857; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int egpPrintStart()
    { return 49; }

// the last print page
inline int egpPrintEnd()
    { return 56; }

// the twenty-one beings of the mythos (Ra through Thoth: the seventeen
// deities and the four monster races)
inline int egpBeingCount()
    { return 21; }

// the four grids (combat, class, ability, roster)
inline int egpTableCount()
    { return 4; }

// no chains this round
inline int egpChainCount()
    { return 0; }

// the live registry def count floor: zero defs touched this round
inline int egpRegistryFloor()
    { return 995; }

// the combat grid rows (one per being)
inline int egpCbtRows()
    { return 21; }

// the class grid rows
inline int egpClsRows()
    { return 21; }

// the ability grid rows
inline int egpAbiRows()
    { return 21; }

// the roster grid rows
inline int egpRosRows()
    { return 21; }

// the twelve printed planes this round (Prime Material, Astral, Gladsheim,
// Concordant Opposition, Elemental Earth, Nirvana, Olympus, Elysium,
// Ethereal, Nine Hells, Elemental Air, Elemental Water; 0 = the monster rows)
inline int egpPlaneCount()
    { return 12; }

// the R849 psionic class I (Isis, Thoth)
inline int egpPsiClassI()
    { return 1; }

// the R849 psionic class II (Anubis, Bast, Ptah, Set)
inline int egpPsiClassII()
    { return 2; }

// the R849 psionic class V (Osiris)
inline int egpPsiClassV()
    { return 5; }

// the R849 psionic class VI (the eleven VI readers)
inline int egpPsiClassVI()
    { return 6; }

// the two artifact sections: the true Ankh and the hieroglyph system
inline int egpArtifactCount()
    { return 2; }

// the 97 hieroglyph words of the printed pp. 55-56 grid (the data file
// doc/data/ddg_egyptian_hieroglyphs.txt)
inline int egpHieroglyphWordCount()
    { return 97; }

// ---- the mythos intro ----

// the deities aged: Ra starting as ruler and growing senile, Osiris killed by
// Set and brought back to life
inline bool egpDeitiesAged()
    { return true; }

// each city had only one major deity; the others worshiped in an inferior
// position
inline bool egpOneMajorDeityPerCity()
    { return true; }

// the temples: a large rectangle enclosed with high walls, one obvious
// entrance
inline bool egpTempleRectangle()
    { return true; }

// the 2 pylons marked with the symbol of the god of the city
inline bool egpPylonsMarked()
    { return true; }

// the public hall walls covered with hieroglyphics, but no image of the deity
// permitted
inline bool egpPublicHallNoImage()
    { return true; }

// the inner sanctuary presents the image in the best materials the sect can
// afford
inline bool egpInnerSanctuaryBest()
    { return true; }

// the priests and priestesses must bathe every day in the temple garden
inline bool egpGardenBathing()
    { return true; }

// if the holy area is desecrated the entire temple is rendered useless
inline bool egpDesecrationUseless()
    { return true; }

// offerings are objects pleasing to the eye that dress up the altar
inline bool egpOfferingsPleasing()
    { return true; }

// clerics below the 4th level serve the people with knowledge or healing
inline bool egpBelow4thServePeople()
    { return true; }

// clerics of the 4th through 6th level serve the needs of the temple
inline bool egp4thTo6thServeTemple()
    { return true; }

// males of the 11th level or higher take a female cleric consort who often
// rules in their stead
inline bool egpFemaleConsortRule()
    { return true; }

// the female clerics keep all official temple records
inline bool egpFemalesKeepRecords()
    { return true; }

// all clerics wear white; being stripped of white is a great sin requiring a
// redemption quest
inline bool egpWhiteClothingSin()
    { return true; }

// males shave their heads at the 4th or higher level; females wear long hair
// at all times
inline bool egpMalesShaveHeads()
    { return true; }

// Egyptian clerics rise in levels by donating the needed experience points in
// gold to the sect
inline bool egpDonateGoldToRise()
    { return true; }

// ideas conveyed by hieroglyphs, word-pictures meaning a word, phrase or
// concept
inline bool egpHieroglyphWordPictures()
    { return true; }

// a hieroglyph could be altered slightly to negate, emphasize or modify its
// meaning
inline bool egpHieroglyphAlteredForms()
    { return true; }

// the practice confused meanings when artists could not agree on depictions
inline bool egpHieroglyphArtistsDisagree()
    { return true; }

// DMs may use hieroglyphs on maps, scrolls and temple writings to warn of
// danger
inline bool egpHieroglyphOnMapsAndScrolls()
    { return true; }

// consult The Book of the Dead, a translation of hieroglyphs found in
// Egyptian tombs
inline bool egpHieroglyphBookOfTheDead()
    { return true; }

// ---- the temple lore walk ----

// the over-3,000-year culture of the ancient Egyptians
inline int egpLoreCultureYears()
    { return 3000; }

// the 2 large pylons supporting the temple entrance
inline int egpLoreTemplePylons()
    { return 2; }

// female clerics can rise no higher than the 9th level
inline int egpLoreFemaleClericMax()
    { return 9; }

// all males of the 11th level or higher must take a female cleric consort
inline int egpLoreConsortLevel()
    { return 11; }

// ---- the true Ankh walk ----

// the about-one-foot-long cross shape with a loop on top
inline int egpAnkhLengthInches()
    { return 12; }

// only 7 true ankhs in any given plane at any one time
inline int egpAnkhPerPlane()
    { return 7; }

// carried by all of the gods of the Nile at one time or another
inline bool egpAnkhCarriedByNileGods()
    { return true; }

// enables raising any dead creature fully, as the spell, with all body pieces
// present
inline bool egpAnkhRaisesTheDead()
    { return true; }

// it kills by fire any non-divine being that touches it
inline bool egpAnkhKillsNonDivineByFire()
    { return true; }

// the cross shape with a loop on top, usually bright blue in color
inline bool egpAnkhBrightBlue()
    { return true; }

// non-magical ankhs are used as holy symbols by many clerics of Egyptian
// deities
inline bool egpAnkhNonMagicalHolySymbols()
    { return true; }

// ---- the hieroglyphs walk ----

// ---- the Ra walk ----

// the Matet war galley travels at 24 inches
inline int egpRaGalleyMove()
    { return 24; }

// the 40 points of searing damage on contact with the galley flames
inline int egpRaGalleyFlameDamage()
    { return 40; }

// the two heat rays shot at a time
inline int egpRaHeatRayCount()
    { return 2; }

// the 500 yard heat ray range
inline int egpRaHeatRayRangeYards()
    { return 500; }

// the 4-40 heat ray damage
inline int egpRaHeatRayLo()
    { return 4; }

// the heat ray ceiling
inline int egpRaHeatRayHi()
    { return 40; }

// the sungod, Pharaoh to the Gods
inline bool egpRaSunGod()
    { return true; }

// the body of a man and the head of a hawk, surmounted by a solar disk
inline bool egpRaHawkHeaded()
    { return true; }

// he can shape change at will, often into a hawk
inline bool egpRaShapeChange()
    { return true; }

// the permanent anti-magic shell that prevents others spell effects but
// allows his own
inline bool egpRaAntiMagicShell()
    { return true; }

// he can cast the light of day into any area he wishes
inline bool egpRaLightOfDay()
    { return true; }

// the war galley Matet that changes into the barge Semktet at night
inline bool egpRaGalleySunBarge()
    { return true; }

// the galley is never affected by magic
inline bool egpRaGalleyUnaffectedByMagic()
    { return true; }

// he prevents fighting among the pantheon: only the clerics battle unless Ra
// is out of commission
inline bool egpRaPantheonPeacemaker()
    { return true; }

// ---- the Anhur walk ----

// the +5 lance with a tip made of part of the sun
inline int egpAnhurLancePlus()
    { return 5; }

// the 6-60 lance damage
inline int egpAnhurLanceDmgLo()
    { return 6; }

// the lance ceiling
inline int egpAnhurLanceDmgHi()
    { return 60; }

// the plus-14 strength bonus on the lance damage (the S:25(+7,+14) line)
inline int egpAnhurLanceStrBonus()
    { return 14; }

// the lance destroys all undead within 50 yards
inline int egpAnhurLanceUndeadRangeYards()
    { return 50; }

// the +4 scale mail
inline int egpAnhurScaleMailPlus()
    { return 4; }

// the 1 percent chance of a granted experience level after a battle sacrifice
inline int egpAnhurRewardPct()
    { return 1; }

// the god of war
inline bool egpAnhurGodOfWar()
    { return true; }

// unusually tall and always appears as a human
inline bool egpAnhurTallHuman()
    { return true; }

// he shape changes only when attacked by more than one being, sometimes with
// more than two arms
inline bool egpAnhurShapeChangeWhenOutnumbered()
    { return true; }

// in combat he always magically negates his enemy strongest ability, no
// saving throw
inline bool egpAnhurAbilityNegation()
    { return true; }

// a worshiper offers sacrifices in battle in the form of powerful enemies
inline bool egpAnhurBattleSacrifices()
    { return true; }

// the promised foe must be at least twice as powerful as the worshiper
inline bool egpAnhurFoeTwiceAsPowerful()
    { return true; }

// if successful, Anhur may grant sufficient experience to raise one level
inline bool egpAnhurGrantsExperienceLevel()
    { return true; }

// ---- the Anubis walk ----

// the 3-30 bite damage
inline int egpAnubisBiteDmgLo()
    { return 3; }

// the bite ceiling
inline int egpAnubisBiteDmgHi()
    { return 30; }

// the 5 percent chance he comes when a tomb with his image is robbed
inline int egpAnubisTombRobberyPct()
    { return 5; }

// the 10 percent chance for a tomb consecrated especially to Anubis
inline int egpAnubisConsecratedPct()
    { return 10; }

// the 10th level priest the intercession requires
inline int egpAnubisIntercessionLevel()
    { return 10; }

// the 50,000 gp worth of precious gems of the sacrifice
inline int egpAnubisGemCost()
    { return 50000; }

// the 20 percent chance a raising cleric is sent on a cult quest
inline int egpAnubisQuestPct()
    { return 20; }

// the guardian of the dead
inline bool egpAnubisGuardianOfTheDead()
    { return true; }

// appears as a man with the head of a jackal
inline bool egpAnubisJackalHeaded()
    { return true; }

// he can animate any statue of himself
inline bool egpAnubisAnimateStatues()
    { return true; }

// he casts 2 charm monster spells at the same time
inline bool egpAnubisDoubleCharmMonster()
    { return true; }

// short range teleport like a blink dog
inline bool egpAnubisBlinkDogTeleport()
    { return true; }

// the god hates all thieves
inline bool egpAnubisHatesThieves()
    { return true; }

// the collector of souls for transportation to the house of the dead
inline bool egpAnubisSoulCollector()
    { return true; }

// he particularly likes to bite his enemies to death
inline bool egpAnubisBitesToDeath()
    { return true; }

// ---- the Apep walk ----

// the 3-30 poisonous bite damage
inline int egpApepBiteDmgLo()
    { return 3; }

// the bite ceiling
inline int egpApepBiteDmgHi()
    { return 30; }

// the save at -4 or die of the bite
inline int egpApepBiteSaveMod()
    { return -4; }

// the 6-60 flame breath damage
inline int egpApepBreathDmgLo()
    { return 6; }

// the breath ceiling
inline int egpApepBreathDmgHi()
    { return 60; }

// the 4-24 constriction damage
inline int egpApepConstrictLo()
    { return 4; }

// the constriction ceiling
inline int egpApepConstrictHi()
    { return 24; }

// the X/28,350 level/xp value line
inline int egpApepXpValue()
    { return 28350; }

// the 70 percent in lair
inline int egpApepLairPct()
    { return 70; }

// the 5-50 flame snakes attending him
inline int egpApepFlameSnakesLo()
    { return 5; }

// the attendant ceiling
inline int egpApepFlameSnakesHi()
    { return 50; }

// the printed Unique frequency, 1 appearing
inline bool egpApepUnique()
    { return true; }

// the king of serpents
inline bool egpApepKingOfSerpents()
    { return true; }

// this creature of the Abyss (the plane, monster row)
inline bool egpApepOfTheAbyss()
    { return true; }

// the deadly enemy of the gods, particularly Osiris
inline bool egpApepEnemyOfTheGods()
    { return true; }

// the physical embodiment of chaotic evil in the Egyptian mythos
inline bool egpApepEmbodimentOfChaoticEvil()
    { return true; }

// the poisonous bite: save at -4 or die
inline bool egpApepPoisonSaveOrDie()
    { return true; }

// the 6-60 flame breath every other melee round, a 10 by 4 cone
inline bool egpApepBreathEveryOtherRound()
    { return true; }

// he attacks as a 16+ HD monster
inline bool egpApepAttacksAs16HDMonster()
    { return true; }

// the Termux 43-or-better garble: +3 or better weapons required, nonmagical
// weapons shatter
inline bool egpApepWeaponPlusNeeded()
    { return true; }

// ---- the Apshai walk ----

// the 6-60 bite damage
inline int egpApshaiBiteDmgLo()
    { return 6; }

// the bite ceiling
inline int egpApshaiBiteDmgHi()
    { return 60; }

// the god of insects
inline bool egpApshaiGodOfInsects()
    { return true; }

// a great praying mantis
inline bool egpApshaiPrayingMantis()
    { return true; }

// able to shape change at will
inline bool egpApshaiShapeChange()
    { return true; }

// can call an insect plague on a person, town or country
inline bool egpApshaiInsectPlague()
    { return true; }

// he controls any type of non-divine insect
inline bool egpApshaiControlInsects()
    { return true; }

// he never misses his prey
inline bool egpApshaiNeverMisses()
    { return true; }

// ---- the Bast walk ----

// the 5-50 claw damage
inline int egpBastClawDmgLo()
    { return 5; }

// the claw ceiling
inline int egpBastClawDmgHi()
    { return 50; }

// the 100 yard evil sense range
inline int egpBastEvilSenseRangeYards()
    { return 100; }

// the 2 percent chance she sees a being killing one of the cat race
inline int egpBastCatKillSeePct()
    { return 2; }

// the 5 percent choice chance
inline int egpBastChoicePct()
    { return 5; }

// the 75 percent chance weapons shatter on her body
inline int egpBastShatterPct()
    { return 75; }

// the cat goddess
inline bool egpBastCatGoddess()
    { return true; }

// Bast bitter enemies are Set and his minions
inline bool egpBastEnemyOfSet()
    { return true; }

// she teleports about and shape changes to use more claws in battle
inline bool egpBastTeleportsInBattle()
    { return true; }

// she can sense evil within 100 yards
inline bool egpBastSensesEvil()
    { return true; }

// the protector of all cat kind
inline bool egpBastProtectorOfCatKind()
    { return true; }

// seeing a cat killed she may come and kill the slayer, or demand half his
// remaining life
inline bool egpBastKillOrDevote()
    { return true; }

// her priests gain +1 to strike snakes and +1 per damage die; snakes save at
// -2 vs their snake charm
inline bool egpBastPriestSnakeBonuses()
    { return true; }

// the priests may never summon snakes in a spell
inline bool egpBastPriestNeverSummonSnakes()
    { return true; }

// the goddess is never surprised by anything
inline bool egpBastNeverSurprised()
    { return true; }

// ---- the Bes walk ----

// the +2 sword that always hits
inline int egpBesSwordPlus()
    { return 2; }

// the 4-24 sword damage
inline int egpBesSwordDmgLo()
    { return 4; }

// the sword ceiling
inline int egpBesSwordDmgHi()
    { return 24; }

// the 5 percent chance of a luck stone grant
inline int egpBesLuckStonePct()
    { return 5; }

// any weapon striking him needs a natural 17 no matter the pluses
inline int egpBesNaturalWeaponFloor()
    { return 17; }

// the god of luck
inline bool egpBesGodOfLuck()
    { return true; }

// appears as a mountain dwarf as described in the MONSTER MANUAL
inline bool egpBesMountainDwarf()
    { return true; }

// often found shape changing to watch and aid all types of creatures
inline bool egpBesShapeChangeAid()
    { return true; }

// he looks favorably on all gambles; the greater the risk the better he likes
// it
inline bool egpBesFavorsGambles()
    { return true; }

// if really pleased he may give the being a luck stone, no strings attached
inline bool egpBesGrantsLuckStone()
    { return true; }

// his sword always hits
inline bool egpBesSwordAlwaysHits()
    { return true; }

// he always makes his saving throws
inline bool egpBesAlwaysMakesSaves()
    { return true; }

// he often fights while invisible, not appearing for the strike
inline bool egpBesFightsInvisible()
    { return true; }

// ---- the Flame Snake walk ----

// the 3 inch blast flame range (5 times per 24 hours)
inline int egpFlameSnakeBlastRangeInches()
    { return 3; }

// the 15 points of fire damage (save vs breath for half)
inline int egpFlameSnakeBlastDamage()
    { return 15; }

// the 5 blasts per 24 hour period
inline int egpFlameSnakeBlastPerDay()
    { return 5; }

// the 1 hit die
inline int egpFlameSnakeHD()
    { return 1; }

// the 80 percent in lair
inline int egpFlameSnakeLairPct()
    { return 80; }

// the 1-2 bite damage
inline int egpFlameSnakeDmgLo()
    { return 1; }

// the bite ceiling
inline int egpFlameSnakeDmgHi()
    { return 2; }

// the 745 base xp (the level I/xp line, flagged garble)
inline int egpFlameSnakeXpBase()
    { return 745; }

// the 1 xp per hit point
inline int egpFlameSnakeXpPerHp()
    { return 1; }

// the printed Rare frequency
inline bool egpFlameSnakeRare()
    { return true; }

// this creature is an enemy of the gods
inline bool egpFlameSnakeEnemyOfTheGods()
    { return true; }

// related to the great serpent Apep
inline bool egpFlameSnakeRelatedToApep()
    { return true; }

// appears as a small harmless grass snake
inline bool egpFlameSnakeGrassSnakeLook()
    { return true; }

// most often found sitting coiled on the highest pile of treasure in a tomb
inline bool egpFlameSnakeCoiledOnTreasure()
    { return true; }

// the blast flame save vs breath weapon for half damage
inline bool egpFlameSnakeSaveForHalf()
    { return true; }

// the Egyptian hells swarm with flame snakes
inline bool egpFlameSnakeHellsSwarm()
    { return true; }

// ---- the Geb walk ----

// the 6-60 fist damage
inline int egpGebFistDmgLo()
    { return 6; }

// the fist ceiling
inline int egpGebFistDmgHi()
    { return 60; }

// the 2-12 earth elementals called once per day
inline int egpGebElementalsLo()
    { return 2; }

// the elemental ceiling
inline int egpGebElementalsHi()
    { return 12; }

// the 2-8 random monsters of the crown, once a day
inline int egpGebCrownMonstersLo()
    { return 2; }

// the crown ceiling
inline int egpGebCrownMonstersHi()
    { return 8; }

// the 25 hit points regenerated per melee round by the staff
inline int egpGebStaffRegen()
    { return 25; }

// the 5 energy levels drained per staff strike
inline int egpGebStaffDrainLevels()
    { return 5; }

// the god of the earth, also known as Seb or Qeb
inline bool egpGebGodOfTheEarth()
    { return true; }

// appears as a heavily muscled man
inline bool egpGebHeavilyMuscled()
    { return true; }

// not affected by any physical weapon while standing on the ground
inline bool egpGebImmuneOnGround()
    { return true; }

// he can shape change at will
inline bool egpGebShapeChange()
    { return true; }

// he negates any spell having to do with earth, no save
inline bool egpGebNegateEarthSpells()
    { return true; }

// he calls 2-12 earth elementals once per day
inline bool egpGebElementalsOncePerDay()
    { return true; }

// the crown that summons 2-8 random monsters once a day
inline bool egpGebCrownOfMonsters()
    { return true; }

// the staff regenerating 25 per melee and draining 5 levels per strike
inline bool egpGebStaffOfRegeneration()
    { return true; }

// he uses 2 magical devices that he is never without
inline bool egpGebNeverWithoutDevices()
    { return true; }

// ---- the Horus walk ----

// the 30 foot spear
inline int egpHorusSpearFeet()
    { return 30; }

// the 3-36 spear damage (plus 14)
inline int egpHorusSpearDmgLo()
    { return 3; }

// the spear ceiling
inline int egpHorusSpearDmgHi()
    { return 36; }

// the +14 strength bonus on spear and sword
inline int egpHorusSpearBonus()
    { return 14; }

// the +3 sword
inline int egpHorusSwordPlus()
    { return 3; }

// the 3-30 sword damage
inline int egpHorusSwordDmgLo()
    { return 3; }

// the sword ceiling
inline int egpHorusSwordDmgHi()
    { return 30; }

// the 18-dice fireball of his wand of fire
inline int egpHorusWandFireDice()
    { return 18; }

// the 5 percent chance the god aids a righteous avenger
inline int egpHorusAidPct()
    { return 5; }

// all ability scores increased to 19 until the deed is done
inline int egpHorusAidedScores()
    { return 19; }

// the son of Osiris, The Avenger
inline bool egpHorusSonOfOsiris()
    { return true; }

// a muscular man with a hawk head on the earth
inline bool egpHorusHawkHeaded()
    { return true; }

// his main attribute: tripling the power of any weapon or magic item he uses
inline bool egpHorusTriplesWeaponPower()
    { return true; }

// the wand of fire shooting an 18-dice fireball in his hands
inline bool egpHorusWandOfFire()
    { return true; }

// he casts monster summoning VII, shape change and project image at will
inline bool egpHorusMonsterSummoningVII()
    { return true; }

// his sword nullifies all first through fifth level spells used against him
inline bool egpHorusSwordNullifiesSpells()
    { return true; }

// the spear instantly kills any shape changed being, no save
inline bool egpHorusSpearKillsShapeChanged()
    { return true; }

// in other hands: the sword +1 doing 1-10 nullifying 1st-2nd; the lance 1-12
// only paralyzing
inline bool egpHorusOthersWeaponsWeaker()
    { return true; }

// he is not affected by the first blow of any given weapon used against him
inline bool egpHorusUnaffectedByFirstBlow()
    { return true; }

// when a good person seeks righteous revenge he may aid, raising all scores
// to 19
inline bool egpHorusAidsAvengers()
    { return true; }

// ---- the Isis walk ----

// the 20th level spell casting, unlimited
inline int egpIsisSpellLevel()
    { return 20; }

// the 5 percent charm chance upon creation of a new spell or item
inline int egpIsisCharmPct()
    { return 5; }

// the goddess of magic and fertility
inline bool egpIsisGoddessOfMagic()
    { return true; }

// appears as a beautiful well-proportioned female
inline bool egpIsisBeautifulFemale()
    { return true; }

// she can use any spell as a 20th level spell-caster an unlimited number of
// times
inline bool egpIsisUnlimitedSpells()
    { return true; }

// her headdress puts her in contact with any Egyptian god at will
inline bool egpIsisHeaddressContactsGods()
    { return true; }

// she understands the fashioning of magical charms as no other being
inline bool egpIsisCharmsMaker()
    { return true; }

// each charm resists the effects of one spell only
inline bool egpIsisCharmResistsOneSpell()
    { return true; }

// the charms go to favored good or neutral beings by her whims
inline bool egpIsisGivesCharmsByWhim()
    { return true; }

// ---- the Nephthys walk ----

// the save at -6 against the twin death rays
inline int egpNephthysDeathRaySaveMod()
    { return -6; }

// the 12 inch death ray range
inline int egpNephthysDeathRayRangeInches()
    { return 12; }

// the goddess of wealth and protector of the dead
inline bool egpNephthysGoddessOfWealth()
    { return true; }

// the twin sister to Isis, appearing as a beautiful woman
inline bool egpNephthysTwinOfIsis()
    { return true; }

// she protects chaotic good souls of the Egyptian cults after death
inline bool egpNephthysProtectsChaoticSouls()
    { return true; }

// she hates evil of any sort and tries to destroy it
inline bool egpNephthysHatesEvil()
    { return true; }

// the twin death rays projected from her eyes
inline bool egpNephthysTwinDeathRays()
    { return true; }

// the protector of the edge of civilization, where fields meet deserts
inline bool egpNephthysEdgeOfCivilization()
    { return true; }

// her clerics protect worshipers, root out evil, and expect monetary support
inline bool egpNephthysClericCrusades()
    { return true; }

// she was once married to Set and left him when he turned to evil
inline bool egpNephthysWasMarriedToSet()
    { return true; }

// ---- the Osiris walk ----

// the 3-30 damage (plus 12)
inline int egpOsirisDmgLo()
    { return 3; }

// the damage ceiling
inline int egpOsirisDmgHi()
    { return 30; }

// the +12 strength bonus
inline int egpOsirisStrBonus()
    { return 12; }

// the 5 percent wish chance for a great deed
inline int egpOsirisWishPct()
    { return 5; }

// the god of nature and the dead
inline bool egpOsirisGodOfNatureAndDead()
    { return true; }

// appears as a muscular green man
inline bool egpOsirisMuscularGreenMan()
    { return true; }

// the lord and protector of the dead
inline bool egpOsirisLordOfTheDead()
    { return true; }

// vegetation or anything made of vegetation has no effect on him
inline bool egpOsirisVegetationImmune()
    { return true; }

// the power to raise the dead no matter how long dead
inline bool egpOsirisRaisesAnyDead()
    { return true; }

// anyone touching his body in battle instantly dies, save vs death applicable
inline bool egpOsirisTouchKills()
    { return true; }

// he shape changes at will
inline bool egpOsirisShapeChange()
    { return true; }

// he controls all forms of vegetation, making it shrink or grow
inline bool egpOsirisControlsVegetation()
    { return true; }

// he can use any weapon even if magically tied to its owner
inline bool egpOsirisUsesAnyWeapon()
    { return true; }

// the crown sees all invisible objects and illusions, negating 4th or lower
// spells
inline bool egpOsirisCrownSeesInvisible()
    { return true; }

// the scepter acts as a rod of cancellation with unlimited charges
inline bool egpOsirisScepterOfCancellation()
    { return true; }

// second only to Ra in power, ruling in Ra absence
inline bool egpOsirisSecondOnlyToRa()
    { return true; }

// a cleric doing a great deed for the religion may be given a wish
inline bool egpOsirisGrantsWish()
    { return true; }

// ---- the Phoenix walk ----

// the 5 points regenerated per melee round
inline int egpPhoenixRegen()
    { return 5; }

// the 10 yard heat radius
inline int egpPhoenixHeatRangeYards()
    { return 10; }

// the 25 points of fire damage per melee round, no saving throw
inline int egpPhoenixHeatDamage()
    { return 25; }

// the attacks as a 12 hit dice monster
inline int egpPhoenixAttackHd()
    { return 12; }

// the 10-100 explosion damage on a successful save
inline int egpPhoenixExplosionDmgLo()
    { return 10; }

// the explosion ceiling
inline int egpPhoenixExplosionDmgHi()
    { return 100; }

// the 3-18 rounds until reborn whole from its own ashes
inline int egpPhoenixRebirthLo()
    { return 3; }

// the rebirth ceiling
inline int egpPhoenixRebirthHi()
    { return 18; }

// the printed Unique frequency, 1 appearing
inline bool egpPhoenixUnique()
    { return true; }

// said to exist and be watching at the time of the creation of the universe
inline bool egpPhoenixExistedAtCreation()
    { return true; }

// it stands for everlasting life beyond even the power of the gods to attain
inline bool egpPhoenixEverlastingLife()
    { return true; }

// it regenerates 5 points per melee round
inline bool egpPhoenixRegenerates()
    { return true; }

// no magical spell can affect the creature
inline bool egpPhoenixNoMagicAffects()
    { return true; }

// the bird is constantly burning
inline bool egpPhoenixConstantlyBurning()
    { return true; }

// the heat damages even those resistant to fire and heat, no saving throw
inline bool egpPhoenixHeatNoSave()
    { return true; }

// any weapon less than +4 melts when striking the body, doing no damage
inline bool egpPhoenixMeltsWeapons()
    { return true; }

// it attacks with its wings (3-18) and beak (4-24) plus its heat damage
inline bool egpPhoenixWingsBeakDamage()
    { return true; }

// if killed the body explodes; saving creatures take only 10-100 points
inline bool egpPhoenixExplosionSave()
    { return true; }

// the phoenix will be reborn whole from its own ashes
inline bool egpPhoenixRebornFromAshes()
    { return true; }

// there is no way the phoenix can be killed permanently
inline bool egpPhoenixUnkillable()
    { return true; }

// ---- the Ptah walk ----

// the 1-100 scepter damage (plus 9)
inline int egpPtahScepterDmgLo()
    { return 1; }

// the scepter ceiling
inline int egpPtahScepterDmgHi()
    { return 100; }

// the +9 strength bonus
inline int egpPtahScepterStrBonus()
    { return 9; }

// the save vs spells at -6 against the banishing gaze
inline int egpPtahGazeSaveMod()
    { return -6; }

// the 2-12 Thet charges
inline int egpPtahThetChargesLo()
    { return 2; }

// the charge ceiling
inline int egpPtahThetChargesHi()
    { return 12; }

// the 5 percent Thet chance for a highly useful device
inline int egpPtahThetPct()
    { return 5; }

// the chance goes up by 5 percent for a cult worshiper
inline int egpPtahThetWorshiperBonus()
    { return 5; }

// the chance goes up by 10 percent for a cleric
inline int egpPtahThetClericBonus()
    { return 10; }

// the creator of the universe
inline bool egpPtahCreator()
    { return true; }

// a dwarf with eyes that reflect the universe, exuding great power
inline bool egpPtahDwarfReflectingUniverse()
    { return true; }

// according to legend he formed the Prime Material Plane out of the Ethereal
inline bool egpPtahFormedPrimeMaterial()
    { return true; }

// he created the Egyptian pantheon of gods
inline bool egpPtahCreatedPantheon()
    { return true; }

// he is not really a member of their group and makes his own way
inline bool egpPtahNotAMember()
    { return true; }

// a master of planar travel with no limit to his speed through any medium
inline bool egpPtahPlanarMaster()
    { return true; }

// his gaze forces beings out of the Prime Material Plane to a plane of his
// choice
inline bool egpPtahGazeBanishes()
    { return true; }

// he can teleport anywhere in the multiverse with accuracy
inline bool egpPtahTeleportAnywhere()
    { return true; }

// in combat he never uses armor
inline bool egpPtahNoArmor()
    { return true; }

// the Scepter of the Gods: tells strong points, nullifies one spell or device
// per melee
inline bool egpPtahScepterOfTheGods()
    { return true; }

// he enjoys new ideas and devices
inline bool egpPtahLovesNewDevices()
    { return true; }

// the Thet can project an anti-magic shell that does not affect the user
// spells
inline bool egpPtahThetAntiMagicShell()
    { return true; }

// or the Thet enables the wearer to become ethereal once a week
inline bool egpPtahThetEtherealWeekly()
    { return true; }

// ---- the Seker walk ----

// the 3-30 halberd damage (plus 14)
inline int egpSekerHalberdDmgLo()
    { return 3; }

// the halberd ceiling
inline int egpSekerHalberdDmgHi()
    { return 30; }

// the +14 strength bonus
inline int egpSekerHalberdBonus()
    { return 14; }

// the +3 mace of disintegration
inline int egpSekerMacePlus()
    { return 3; }

// the 2-24 mace damage on a successful save
inline int egpSekerMaceDmgLo()
    { return 2; }

// the mace ceiling
inline int egpSekerMaceDmgHi()
    { return 24; }

// the 500 yard range of the light shafts that kill undead
inline int egpSekerShaftRangeYards()
    { return 500; }

// the god of light
inline bool egpSekerGodOfLight()
    { return true; }

// cousin to Shu, appears as a rather ordinary man
inline bool egpSekerCousinToShu()
    { return true; }

// relentless in his efforts to destroy all evil on the earth
inline bool egpSekerDestroysEvil()
    { return true; }

// the +3 mace of disintegration: save vs spells or be disintegrated
inline bool egpSekerMaceOfDisintegration()
    { return true; }

// the light shafts from his hands kill any undead they touch
inline bool egpSekerShaftsKillUndead()
    { return true; }

// he shape changes at will
inline bool egpSekerShapeChange()
    { return true; }

// one of the gods of the afterworld
inline bool egpSekerGodOfAfterworld()
    { return true; }

// he protects neutral good souls of the Egyptian cults after death
inline bool egpSekerProtectsNeutralGoodSouls()
    { return true; }

// ---- the Set walk ----

// the jet black +4 Spear of Darkness
inline int egpSetSpearPlus()
    { return 4; }

// the 7-70 spear damage
inline int egpSetSpearDmgLo()
    { return 7; }

// the spear ceiling
inline int egpSetSpearDmgHi()
    { return 70; }

// the 2-20 Minions of Set lent for an evil act
inline int egpSetMinionsLo()
    { return 2; }

// the minion ceiling
inline int egpSetMinionsHi()
    { return 20; }

// the 12 weeks the lent minions serve
inline int egpSetMinionWeeks()
    { return 12; }

// the 5 percent chance Set is watching a highly evil act
inline int egpSetWatchPct()
    { return 5; }

// the god of evil and the night
inline bool egpSetGodOfEvil()
    { return true; }

// a scaled humanoid with the head of a fierce jackal
inline bool egpSetJackalHeaded()
    { return true; }

// totally dedicated to the spreading of evil
inline bool egpSetSpreadsEvil()
    { return true; }

// his touch changes any neutral or good being to lawful evil, save applicable
inline bool egpSetAlignmentChangeTouch()
    { return true; }

// the changed beings become Minions of Set
inline bool egpSetMinionsCreated()
    { return true; }

// the jet black Spear of Darkness
inline bool egpSetSpearOfDarkness()
    { return true; }

// his skin is deadly poisonous to the touch
inline bool egpSetPoisonSkin()
    { return true; }

// the 5 percent chance he is watching when a worshiper does a highly evil act
inline bool egpSetWatchesEvilActs()
    { return true; }

// the implacable enemy of Osiris and Horus
inline bool egpSetEnemyOfOsirisAndHorus()
    { return true; }

// he attempts to thwart them through others whenever possible
inline bool egpSetThwartsThroughOthers()
    { return true; }

// ---- the Minions of Set walk ----

// the 25 hit points each
inline int egpMinionsHp()
    { return 25; }

// they fight and save as 10th level fighters
inline int egpMinionsFightAsLevel()
    { return 10; }

// the 1-20 appearing
inline int egpMinionsAppearingLo()
    { return 1; }

// the appearing ceiling
inline int egpMinionsAppearingHi()
    { return 20; }

// the 1-12 snake bite damage
inline int egpMinionsBiteLo()
    { return 1; }

// the bite ceiling
inline int egpMinionsBiteHi()
    { return 12; }

// the V level/xp value label
inline int egpMinionsXpLevel()
    { return 5; }

// the 500 base xp
inline int egpMinionsXpBase()
    { return 500; }

// the printed Uncommon frequency
inline bool egpMinionsUncommon()
    { return true; }

// able to polymorph themselves into giant snakes
inline bool egpMinionsPolymorphSnakes()
    { return true; }

// they fight and save as 10th level fighters
inline bool egpMinionsSaveAs10thFighters()
    { return true; }

// they appear in black scaly plate mail and use broadswords
inline bool egpMinionsBlackPlateMail()
    { return true; }

// fully intelligent, acting as go-betweens for Set and mankind
inline bool egpMinionsIntelligentGoBetweens()
    { return true; }

// these beings never need to check morale
inline bool egpMinionsNeverCheckMorale()
    { return true; }

// some can also polymorph into cave bears, giant crocodiles or giant
// scorpions
inline bool egpMinionsOtherForms()
    { return true; }

// ---- the Shu walk ----

// the +5 scale mail made of phoenix feathers
inline int egpShuScaleMailPlus()
    { return 5; }

// the 25 points of contact flame damage, no saving throw
inline int egpShuFlameDamage()
    { return 25; }

// the 1-10 air elementals called once per day
inline int egpShuElementalsLo()
    { return 1; }

// the elemental ceiling
inline int egpShuElementalsHi()
    { return 10; }

// the 75 percent chance Horus also helps avenge Tefnut
inline int egpShuHorusAidPct()
    { return 75; }

// the god of the sky
inline bool egpShuGodOfTheSky()
    { return true; }

// the twin brother to Tefnut, appears as a normal man
inline bool egpShuTwinBrotherOfTefnut()
    { return true; }

// at will he can levitate and shape change
inline bool egpShuLevitate()
    { return true; }

// he creates the light of day as Ra
inline bool egpShuLightOfDay()
    { return true; }

// he is not affected by any form of heat
inline bool egpShuHeatImmune()
    { return true; }

// the +5 scale mail made of phoenix feathers
inline bool egpShuPhoenixFeatherMail()
    { return true; }

// the mail enables a surrounding flame causing 25 points of contact damage
inline bool egpShuFlameAura()
    { return true; }

// he uses a double strength staff of the magi in battle
inline bool egpShuDoubleStrengthStaff()
    { return true; }

// his skin touch withers: metal shatters, flesh rots, vegetable matter dries
// (save vs spells)
inline bool egpShuWitheringTouch()
    { return true; }

// he is very protective of his sister; harm to her suffers his immediate
// vengeance
inline bool egpShuProtectiveOfTefnut()
    { return true; }

// ---- the Tefnut walk ----

// the 2 lightning bolts per melee round
inline int egpTefnutBoltCount()
    { return 2; }

// the 24 points of damage per bolt
inline int egpTefnutBoltDamage()
    { return 24; }

// the 1,000 yard maximum bolt range
inline int egpTefnutBoltRangeYards()
    { return 1000; }

// the goddess of storms and flowing water
inline bool egpTefnutGoddessOfStorms()
    { return true; }

// the power to call up wind storms
inline bool egpTefnutWindStorms()
    { return true; }

// she shape changes at will
inline bool egpTefnutShapeChange()
    { return true; }

// she can speak with the dead
inline bool egpTefnutSpeakWithDead()
    { return true; }

// she summons water monsters within a one mile radius around her
inline bool egpTefnutWaterMonsters()
    { return true; }

// if the lightning bolts do not work she teleports away from the battle
inline bool egpTefnutTeleportsAway()
    { return true; }

// ---- the Thoth walk ----

// the 100 yard radius of the automatic negation of known powers
inline int egpThothNegateRangeYards()
    { return 100; }

// the set of 3 books: all clerical, all magical, all divine knowledge
inline int egpThothBookCount()
    { return 3; }

// the god of knowledge
inline bool egpThothGodOfKnowledge()
    { return true; }

// the teacher of the gods, with full knowledge of everything, particularly
// magic
inline bool egpThothTeacherOfTheGods()
    { return true; }

// his spells always inflict maximum possible damage, saves applicable
inline bool egpThothMaximumDamageSpells()
    { return true; }

// he negates any known magical or physical force automatically within range
inline bool egpThothNegatesKnownPowers()
    { return true; }

// he can negate only one such power per round
inline bool egpThothOnePerRound()
    { return true; }

// never without his scepter which delivers a death spell at a touch
inline bool egpThothScepterDeathSpell()
    { return true; }

// the set of 3 books of all clerical, magical and divine knowledge
inline bool egpThothThreeBooks()
    { return true; }

// the books have been stolen several times, much to the regret of the thieves
inline bool egpThothThievesRegret()
    { return true; }

// as knowledge is discovered on the Prime Material Plane he is instantly
// aware of it
inline bool egpThothInstantlyAware()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Ra -3, Anhur and Ptah -5, Thoth 4, Shu 6, Nephthys
// 2)
inline int egpCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -5;
        case 2:
            return -2;
        case 3:
            return -4;
        case 4:
            return 3;
        case 5:
            return -2;
        case 6:
            return -3;
        case 7:
            return 2;
        case 8:
            return -3;
        case 9:
            return -2;
        case 10:
            return -2;
        case 11:
            return 2;
        case 12:
            return -2;
        case 13:
            return 3;
        case 14:
            return -5;
        case 15:
            return -2;
        case 16:
            return -4;
        case 17:
            return -2;
        case 18:
            return 6;
        case 19:
            return -2;
        case 20:
            return 4;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all twenty-one
// read single this round)
inline int egpCbtACAlt(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (400 the greater gods, down to 25 per Minion; 0 = the
// hit-dice Flame Snake row)
inline int egpCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 345;
        case 2:
            return 300;
        case 3:
            return 250;
        case 4:
            return 289;
        case 5:
            return 300;
        case 6:
            return 210;
        case 7:
            return 0;
        case 8:
            return 339;
        case 9:
            return 359;
        case 10:
            return 300;
        case 11:
            return 200;
        case 12:
            return 400;
        case 13:
            return 50;
        case 14:
            return 390;
        case 15:
            return 300;
        case 16:
            return 378;
        case 17:
            return 25;
        case 18:
            return 346;
        case 19:
            return 223;
        case 20:
            return 389;
        default:
            return 0;
        }
    }

// The primary move cells (-1 = the printed Infinite of Ptah, the R854
// convention; 0 = none this round)
inline int egpCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 15;
        case 2:
            return 12;
        case 3:
            return 18;
        case 4:
            return 21;
        case 5:
            return 24;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 12;
        case 9:
            return 15;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 24;
        case 13:
            return 12;
        case 14:
            return -1;
        case 15:
            return 24;
        case 16:
            return 18;
        case 17:
            return 12;
        case 18:
            return 12;
        case 19:
            return 24;
        case 20:
            return 12;
        default:
            return 0;
        }
    }

// The secondary move cells (the printed slash ceilings; Horus the 15/15
// decode - flagged)
inline int egpCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 24;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 21;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 48;
        case 9:
            return 15;
        case 10:
            return 24;
        case 11:
            return 12;
        case 12:
            return 48;
        case 13:
            return 24;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 48;
        case 19:
            return 0;
        case 20:
            return 24;
        default:
            return 0;
        }
    }

// The attack count cells (Ra the printed 0 with Nil damage, Apep 2, Osiris
// and Set 2, Phoenix 3)
inline int egpCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 1;
        default:
            return 0;
        }
    }

// The attack alternative cells (the 3/2 slashes of Anubis, Bes, Isis,
// Nephthys, Minions, Shu, Tefnut)
inline int egpCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 2;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (Set the 59 and Shu/Tefnut the 69 - both voices
// agree on the odd print; 0 = the Phoenix printed See below)
inline int egpCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 20;
        case 2:
            return 80;
        case 3:
            return 40;
        case 4:
            return 10;
        case 5:
            return 45;
        case 6:
            return 100;
        case 7:
            return 85;
        case 8:
            return 30;
        case 9:
            return 75;
        case 10:
            return 90;
        case 11:
            return 40;
        case 12:
            return 80;
        case 13:
            return 0;
        case 14:
            return 70;
        case 15:
            return 40;
        case 16:
            return 59;
        case 17:
            return 10;
        case 18:
            return 69;
        case 19:
            return 69;
        case 20:
            return 98;
        default:
            return 0;
        }
    }

// The size cells in inches (the foot-mark decodes: Isis 5 foot 4 from the
// printed 514, Seker and Thoth 6 foot 4 from 614 and 6%4 - the R853 lesson;
// Apep 300 feet long, Geb 70 feet, Phoenix the 60 feet wingspread; Horus the
// flagged 6 foot 2, Nephthys the flagged twin decode, Minions the flagged 6
// foot 4)
inline int egpCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 72;
        case 1:
            return 84;
        case 2:
            return 72;
        case 3:
            return 3600;
        case 4:
            return 180;
        case 5:
            return 72;
        case 6:
            return 48;
        case 7:
            return 12;
        case 8:
            return 840;
        case 9:
            return 74;
        case 10:
            return 64;
        case 11:
            return 64;
        case 12:
            return 84;
        case 13:
            return 720;
        case 14:
            return 48;
        case 15:
            return 76;
        case 16:
            return 84;
        case 17:
            return 76;
        case 18:
            return 72;
        case 19:
            return 72;
        case 20:
            return 76;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (Ra 20th, Anubis 20th, Isis the printed 20th
// cleric/14th druid slash, Ptah 20th, Thoth Nil)
inline int egpClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 15;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 20;
        case 15:
            return 13;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 15;
        case 19:
            return 18;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (Isis the 14, Seker the in-each 13s; all others Nil)
inline int egpClsDruid(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 14;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 13;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The fighter level floor cells (the paladins Anubis 12, Horus via bool,
// Seker via bool, Shu via bool; 0 = the ranger-slot Osiris and the monster
// rows)
inline int egpClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 17;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 8;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 14;
        case 15:
            return 0;
        case 16:
            return 17;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 8;
        case 20:
            return 5;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells (single printed levels read floor =
// ceiling)
inline int egpClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 17;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 8;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 14;
        case 15:
            return 0;
        case 16:
            return 17;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 8;
        case 20:
            return 5;
        default:
            return 0;
        }
    }

// The ranger level cells (Osiris the 16th level ranger)
inline int egpClsRanger(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 16;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells (99 = the printed See below: Isis the unlimited
// 20th level doctrine; Ptah 25th, Set Nil over the 30th illusionist, Thoth
// the in-each 30s)
inline int egpClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 8;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 15;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 16;
        case 10:
            return 99;
        case 11:
            return 17;
        case 12:
            return 20;
        case 13:
            return 0;
        case 14:
            return 25;
        case 15:
            return 12;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 15;
        case 19:
            return 13;
        case 20:
            return 30;
        default:
            return 0;
        }
    }

// The illusionist level cells (Set the 30th level illusionist over a Nil
// magic-user; the in-each pairs of Anhur, Bast, Seker and Thoth)
inline int egpClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 8;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 15;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 12;
        case 16:
            return 30;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 30;
        default:
            return 0;
        }
    }

// The thief level cells (Bes the 15th level thief)
inline int egpClsThief(int b)
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
            return 0;
        case 6:
            return 15;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The assassin level cells (Anhur the 10th, Set the 15th level assassin)
inline int egpClsAssassin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (Anhur the 7th level monk)
inline int egpClsMonk(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 7;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The bard level cells (Bes the 8th, Osiris the 15th level bard)
inline int egpClsBard(int b)
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
            return 0;
        case 6:
            return 8;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the GEOMETRY SWAP: Ra the printed S:20 line and Anhur
// the S:25(+7,+14) - the Termux psm-4 fold had them reversed, the IA
// x-coordinates and the +14 lance prose settled it; Isis the printed S:10,
// Set 14, Shu and Tefnut the 16(0,+1))
inline int egpAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 24;
        case 3:
            return 0;
        case 4:
            return 20;
        case 5:
            return 25;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 25;
        case 9:
            return 25;
        case 10:
            return 10;
        case 11:
            return 17;
        case 12:
            return 24;
        case 13:
            return 0;
        case 14:
            return 21;
        case 15:
            return 25;
        case 16:
            return 14;
        case 17:
            return 0;
        case 18:
            return 16;
        case 19:
            return 16;
        case 20:
            return 20;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = no printed bracket)
inline int egpAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 7;
        case 2:
            return 6;
        case 3:
            return 0;
        case 4:
            return 3;
        case 5:
            return 7;
        case 6:
            return 6;
        case 7:
            return 0;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 6;
        case 13:
            return 0;
        case 14:
            return 4;
        case 15:
            return 7;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 3;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells (the +14s, the +12 of Osiris,
// the +9 of Ptah, the +1 of Shu and Tefnut)
inline int egpAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 14;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 8;
        case 5:
            return 14;
        case 6:
            return 12;
        case 7:
            return 0;
        case 8:
            return 14;
        case 9:
            return 14;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 12;
        case 13:
            return 0;
        case 14:
            return 9;
        case 15:
            return 14;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 8;
        default:
            return 0;
        }
    }

// The intelligence cells (the I:25s of Osiris, Ptah and Thoth; Nephthys the
// 1121 decode = I:21)
inline int egpAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 19;
        case 2:
            return 24;
        case 3:
            return 0;
        case 4:
            return 17;
        case 5:
            return 24;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 22;
        case 9:
            return 25;
        case 10:
            return 25;
        case 11:
            return 21;
        case 12:
            return 25;
        case 13:
            return 0;
        case 14:
            return 25;
        case 15:
            return 18;
        case 16:
            return 25;
        case 17:
            return 0;
        case 18:
            return 20;
        case 19:
            return 20;
        case 20:
            return 25;
        default:
            return 0;
        }
    }

// The wisdom cells (Bast the W:10 the IA geometry word against the Termux
// W:70; Anhur W:12)
inline int egpAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 12;
        case 2:
            return 24;
        case 3:
            return 0;
        case 4:
            return 25;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 20;
        case 9:
            return 21;
        case 10:
            return 25;
        case 11:
            return 18;
        case 12:
            return 25;
        case 13:
            return 0;
        case 14:
            return 25;
        case 15:
            return 18;
        case 16:
            return 23;
        case 17:
            return 0;
        case 18:
            return 23;
        case 19:
            return 23;
        case 20:
            return 25;
        default:
            return 0;
        }
    }

// The dexterity cells (the D:25s; Anubis 19)
inline int egpAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 19;
        case 3:
            return 0;
        case 4:
            return 18;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 23;
        case 9:
            return 25;
        case 10:
            return 20;
        case 11:
            return 23;
        case 12:
            return 19;
        case 13:
            return 0;
        case 14:
            return 18;
        case 15:
            return 25;
        case 16:
            return 20;
        case 17:
            return 0;
        case 18:
            return 20;
        case 19:
            return 20;
        case 20:
            return 20;
        default:
            return 0;
        }
    }

// The constitution cells (the 25s; Minions, Apep, Flame Snake and Phoenix
// read the all-sentinel line)
inline int egpAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 22;
        case 3:
            return 0;
        case 4:
            return 19;
        case 5:
            return 20;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 25;
        case 9:
            return 23;
        case 10:
            return 19;
        case 11:
            return 20;
        case 12:
            return 25;
        case 13:
            return 0;
        case 14:
            return 23;
        case 15:
            return 24;
        case 16:
            return 25;
        case 17:
            return 0;
        case 18:
            return 23;
        case 19:
            return 23;
        case 20:
            return 24;
        default:
            return 0;
        }
    }

// The charisma cells (Apshai the -3, Set the -2; the positive cells as
// printed - Thoth 18, Shu 19, Osiris 24, Horus 24)
inline int egpAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 12;
        case 2:
            return 19;
        case 3:
            return 0;
        case 4:
            return -3;
        case 5:
            return 22;
        case 6:
            return 15;
        case 7:
            return 0;
        case 8:
            return 22;
        case 9:
            return 24;
        case 10:
            return 25;
        case 11:
            return 22;
        case 12:
            return 24;
        case 13:
            return 0;
        case 14:
            return 20;
        case 15:
            return 24;
        case 16:
            return -2;
        case 17:
            return 0;
        case 18:
            return 19;
        case 19:
            return 18;
        case 20:
            return 18;
        default:
            return 0;
        }
    }

// The psionic score cells (0 = every being reads the R849 class table this
// round; no monster point scores printed)
inline int egpAbiPsi(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Ra through Thoth)
inline int egpRosOrd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        case 13:
            return 13;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 19;
        case 20:
            return 20;
        default:
            return 0;
        }
    }

// The print page cells (49-55, the folio offset PRINT = PDF - 1; the
// hieroglyph grid pages 55-56 ride the data file)
inline int egpRosPage(int b)
    {
        switch (b) {
        case 0:
            return 49;
        case 1:
            return 49;
        case 2:
            return 50;
        case 3:
            return 50;
        case 4:
            return 50;
        case 5:
            return 50;
        case 6:
            return 51;
        case 7:
            return 51;
        case 8:
            return 51;
        case 9:
            return 51;
        case 10:
            return 52;
        case 11:
            return 52;
        case 12:
            return 52;
        case 13:
            return 52;
        case 14:
            return 53;
        case 15:
            return 53;
        case 16:
            return 53;
        case 17:
            return 54;
        case 18:
            return 54;
        case 19:
            return 54;
        case 20:
            return 55;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG, 1 NG, 2 CG, 3 LN, 4 N, 6 LE, 8 CE - the R852
// code scheme)
inline int egpRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 8;
        case 4:
            return 4;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 8;
        case 8:
            return 4;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 4;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 4;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 demigod Apshai, 3 monster - Apep,
// the Flame Snake, the Phoenix, the Minions of Set)
inline int egpRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        default:
            return 0;
        }
    }

// The psionic class cells (1 Isis and Thoth, 2 Anubis, Bast, Ptah and Set -
// the 46px, 29px and 28px two-glyph geometry against the Termux 11 and //
// garbles, 5 Osiris, 6 the eleven VI readers - the R849 class table)
inline int egpRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 6;
        case 5:
            return 2;
        case 6:
            return 6;
        case 7:
            return 0;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 1;
        case 11:
            return 6;
        case 12:
            return 5;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 6;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 1;
        default:
            return 0;
        }
    }

// The plane cells (1 Prime Material, 2 Astral, 3 Gladsheim, 4 Concordant
// Opposition, 5 Elemental Earth, 6 Nirvana, 7 Olympus, 8 Elysium, 9 Ethereal,
// 10 Nine Hells, 11 Elemental Air, 12 Elemental Water; 0 = the monster rows,
// Apep the Abyss prose pinned as a bool)
inline int egpRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 1;
        case 11:
            return 7;
        case 12:
            return 8;
        case 13:
            return 0;
        case 14:
            return 9;
        case 15:
            return 8;
        case 16:
            return 10;
        case 17:
            return 0;
        case 18:
            return 11;
        case 19:
            return 12;
        case 20:
            return 4;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed DAMAGE/ATTACK cell is numeric
// damage; 0 = Ra Nil, Nephthys and the Phoenix-adjacent By weapon / See below
// rows of Nephthys, Minions, Shu, Tefnut and Thoth)
inline int egpRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells: Anhur MU/I, Bast
// MU/I, Bes MU/I, Seker C/D and MU/I, Thoth MU/I)
inline int egpRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        default:
            return 0;
        }
    }

// The Set-enmity flags (the printed enemy lines: Bast, Horus, Nephthys the
// abandoned wife, Osiris)
inline int egpRosSetEnmity(int b)
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
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
