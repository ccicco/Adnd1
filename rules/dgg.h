// =========================================================================================
// Adnd1 - rules/dgg.h
// the Chinese mythos - the D&DG walk round seven, print pp. 37-42: eighteen
// beings from Shang-Ti the head of the Celestial Bureaucracy to Yen-Wang-Yeh
// the judge of the dead, the two Counts of the Wind, Ma Yuan the killer of
// gods, the Spirits of the Air, and the seven devices of the mythos across
// nine planes.
// census 777 -> 778.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 038-043; the second printing); the
// collation voice: the archive.org 1st-print derivative
// (deities-demigods-1st-print, djvu.txt + djvu.xml word geometry at 600dpi).
// The adjudications: the psionic classes by word geometry (Chao Kung Ming and
// Chung Kuel the 27px II words, Chih-Chiang Fyu-Ya the 49px VI, Tou Mu the
// 29px II against the Termux single I, Shang-Ti the single bar I), the size
// decodes (Shang-Ti 5 foot 4 from the printed 514 cell and Chao Kung Ming 6
// foot 2 from the 612 cell - the R853 foot-mark-misread lesson; Kuan Yin 5
// feet and D 12, the IA geometry words against the Termux 72 garble), the Wen
// Chung hit points (the 2nd-print 213 pinned against the IA 1st-print 273 -
// the Gawaine 112 precedent, flagged), the Spirits appearing 1-100 (the
// Termux clean read plus the up-to-100 prose against the IA 17-1700 djvu
// garble), and the Chih Sung-Tzu size (garbled in both voices, the sentinel
// pinned, flagged for the physical-copy eyeball).
//
namespace rules {

// ---- the R855 census ----

// the Chinese mythos round: the D&DG walk round seven, print pp. 37-42
inline int dggRound()
    { return 855; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int dggPrintStart()
    { return 37; }

// the last print page
inline int dggPrintEnd()
    { return 42; }

// the eighteen beings of the mythos (Shang-Ti through Yen-Wang-Yeh, the two
// Counts and the two monster-format listings)
inline int dggBeingCount()
    { return 18; }

// the four grids (combat, class, ability, roster)
inline int dggTableCount()
    { return 4; }

// no chains this round
inline int dggChainCount()
    { return 0; }

// zero registry defs touched - the floor holds at 995
inline int dggRegistryFloor()
    { return 995; }

// the combat grid rows
inline int dggCbtRows()
    { return 18; }

// the class grid rows
inline int dggClsRows()
    { return 18; }

// the ability grid rows
inline int dggAbiRows()
    { return 18; }

// the roster grid rows
inline int dggRosRows()
    { return 18; }

// the nine printed planes: Nirvana, the Elemental Plane of Air, Gehenna, the
// Seven Heavens, Limbo, Acheron, the Abyss, the Nine Hells, Concordant
// Opposition
inline int dggPlaneCount()
    { return 9; }

// the printed psionic class I (Shang-Ti, the single-glyph bar)
inline int dggPsiClassI()
    { return 1; }

// the printed psionic class II (Chao Kung Ming and Chung Kuel the 27px
// two-glyph words, Tou Mu the 29px)
inline int dggPsiClassII()
    { return 2; }

// the printed psionic class V (the two Counts of the Wind)
inline int dggPsiClassV()
    { return 5; }

// the printed psionic class VI (ten of the eighteen read the 49-51px
// two-glyph word)
inline int dggPsiClassVI()
    { return 6; }

// the seven devices of the mythos: the Iron Wand, the Jade Scepter of
// Defending, the Wind Fire Wheels, the Canon of Changes, the Dancing Sword of
// Lightning, the Fire Gems, the Giant Black Pearl
inline int dggArtifactCount()
    { return 7; }

// for every 5 charges expended, one hit point is drawn from the using being
inline int dggWindFireChargePerHP()
    { return 5; }

// ---- the mythos intro ----

// the title caveat: the Chinese mythology is too vast and varied to cover
// adequately, so the most appropriate deities were chosen
inline bool dggVastMythologyCaveat()
    { return true; }

// the Chinese image of the Heavens is that of a great bureaucracy
inline bool dggGreatBureaucracy()
    { return true; }

// many of the deities exist to perform a special task and watch over a
// special area of life
inline bool dggSpecialTaskDeities()
    { return true; }

// each god is supervised by a more important deity, responsible for seeing
// things are done correctly
inline bool dggSupervisionChains()
    { return true; }

// every being is accountable to the Emperor of the Heavens
inline bool dggEmperorAccountability()
    { return true; }

// every year the gods send reports to their supervisors - promotion or
// demotion for the year's work is not uncommon
inline bool dggAnnualReports()
    { return true; }

// the clerics support the existing mortal government and preach the divinity
// of their emperor
inline bool dggClericsSupportGovernment()
    { return true; }

// the emperor is head of state and of the church, gifted with high priest
// powers by the gods
inline bool dggEmperorHeadOfChurch()
    { return true; }

// atonement for all sins: sacrificing items of value commensurate with the
// improper act
inline bool dggAtonementBySacrifice()
    { return true; }

// if the deed was severe enough, the atonement might even be death
inline bool dggAtonementMayBeDeath()
    { return true; }

// clerics must travel about the countryside preaching to rich and poor alike
inline bool dggTravelPreaching()
    { return true; }

// ---- the artifacts ----

// the Iron Wand makes all invisible things appear within a 30" radius
inline int dggIronWandRadiusInches()
    { return 30; }

// the wand grows to a length of 100" upon command and becomes roughened for
// easy climbing
inline int dggIronWandLengthInches()
    { return 100; }

// there are 25 Wind Fire Wheels, handed out by Shang-Ti to the demi-deities
// and their servants
inline int dggWindFireWheelCount()
    { return 25; }

// the Canon of Changes: 72 hours of constant reading to learn the words for
// any one given thing
inline int dggCanonLearnHours()
    { return 72; }

// after uttering them, another 72 hours pass before another creation of even
// the same thing
inline int dggCanonRecreateHours()
    { return 72; }

// the Dancing Sword of Lightning shoots one lightning bolt per melee round
// doing 30 points per strike (saving throw applicable)
inline int dggLightningSwordDamage()
    { return 30; }

// the Fire Gems shoot flame doing 6-60 points of damage per strike
inline int dggFireGemDmgLo()
    { return 6; }

// the fire gem damage ceiling
inline int dggFireGemDmgHi()
    { return 60; }

// the fire gems have a maximum range of 50 yards, firing once per turn
inline int dggFireGemRangeYards()
    { return 50; }

// each gem has 2-12 charges
inline int dggFireGemChargesLo()
    { return 2; }

// the fire gem charge ceiling
inline int dggFireGemChargesHi()
    { return 12; }

// the Giant Black Pearl is a 3 foot sphere
inline int dggPearlSizeFeet()
    { return 3; }

// the pearl negates all wind and earth turbulence in a one mile radius
inline int dggPearlRadiusMiles()
    { return 1; }

// the Iron Wand makes all invisible things appear
inline bool dggIronWandRevealsInvisible()
    { return true; }

// it can make one object disappear as dust of disappearance
inline bool dggIronWandDustDisappearance()
    { return true; }

// it acts as a staff of striking with unlimited charges
inline bool dggIronWandStaffOfStriking()
    { return true; }

// it grows to 100" upon command, roughened for easy climbing
inline bool dggIronWandGrowsToClimb()
    { return true; }

// the Jade Scepter of Defending defends the user from any number of material
// weapons - none may strike its master
inline bool dggJadeScepterBlocksMaterial()
    { return true; }

// while concentrating on defense, no other action may even be contemplated
inline bool dggJadeScepterConcentration()
    { return true; }

// the Wind Fire Wheels shoot fire and/or wind as a staff of the magi, used in
// large battles the gods fear losing
inline bool dggWindFireWheelStaffOfMagi()
    { return true; }

// they are 1 foot circular fans, started by a command word from the holder
inline bool dggWindFireWheelFans()
    { return true; }

// the Canon of Changes allows the reader to create any nonmagical object
// instantly when the command words are spoken
inline bool dggCanonCreatesNonmagical()
    { return true; }

// only immortals have the constitutional stamina to read the passages for the
// length of time required
inline bool dggCanonImmortalsOnly()
    { return true; }

// the Dancing Sword of Lightning behaves as a dancing sword per the DUNGEON
// MASTERS GUIDE
inline bool dggLightningSwordDancingParity()
    { return true; }

// it has unlimited charges
inline bool dggLightningSwordUnlimited()
    { return true; }

// it is the favorite weapon of the demigods of the air, when they can use it
// in their turn
inline bool dggLightningSwordAirDemigods()
    { return true; }

// it performs as a normal sword when held by mortals
inline bool dggLightningSwordMortalNormal()
    { return true; }

// the fire gems fire once per turn when the command words are spoken
inline bool dggFireGemOncePerTurn()
    { return true; }

// the Giant Black Pearl negates turbulence of its own accord and cannot be
// controlled to make it stop
inline bool dggPearlUncontrolled()
    { return true; }

// ---- the Shang-Ti walk ----

// Shang-Ti uses a shaft of light as a weapon doing 3-36 points of damage per
// strike
inline int dggShangTiShaftDmgLo()
    { return 3; }

// the light shaft damage ceiling
inline int dggShangTiShaftDmgHi()
    { return 36; }

// Shang-Ti, supreme god of the heavens, god of the sky and agriculture
inline bool dggShangTiSupremeGod()
    { return true; }

// he sometimes travels among mortals as an aged man with a long white beard,
// dressed in tattered robes
inline bool dggShangTiTravelsAmongMortals()
    { return true; }

// he likes to float in the air ethereally, viewing cities and towns and how
// he is or isn't being worshiped
inline bool dggShangTiFloatsEthereal()
    { return true; }

// all physical weapon attacks sent through the air at the god will turn and
// strike the sender
inline bool dggShangTiWeaponsReturn()
    { return true; }

// the light shaft's range is sight
inline bool dggShangTiShaftRangeSight()
    { return true; }

// as god of the sky and agriculture he has complete control over weather -
// instantly summoning or banishing any type he desires
inline bool dggShangTiWeatherControl()
    { return true; }

// he is the head of the Celestial Bureaucracy; all the other deities
// ultimately report to him
inline bool dggShangTiBureaucracyHead()
    { return true; }

// his word is law among all the gods and goddesses regardless of alignment;
// he is the final arbitrator in any dispute
inline bool dggShangTiWordIsLaw()
    { return true; }

// ---- the Chao Kung Ming walk ----

// Chao Kung Ming strikes with a spear of power for 10-60 points of damage
inline int dggChaoSpearDmgLo()
    { return 10; }

// the spear of power damage ceiling
inline int dggChaoSpearDmgHi()
    { return 60; }

// his giant flying tiger: AC 3, MV 24"/24", HD 11, hp 50, 3 attacks for
// 1-8/1-8/2-16
inline int dggChaoTigerAC()
    { return 3; }

// the flying tiger hit dice
inline int dggChaoTigerHD()
    { return 11; }

// the flying tiger hit points
inline int dggChaoTigerHP()
    { return 50; }

// the flying tiger attacks
inline int dggChaoTigerAtN()
    { return 3; }

// his special +3 scale mail does not interfere with the use of his monk
// abilities
inline int dggChaoScaleMailPlus()
    { return 3; }

// Chao Kung Ming, demigod of war: a very muscular man with bright red skin
inline bool dggChaoWarDemigod()
    { return true; }

// he rides a giant flying tiger into battle
inline bool dggChaoRidesFlyingTiger()
    { return true; }

// this god is able to travel from plane to plane with however many beings he
// wishes
inline bool dggChaoPlaneTravel()
    { return true; }

// ---- the Chih Sung-Tzu walk ----

// the blue war helm gives constant haste and flying at twice his own speed
// (48")
inline int dggChihSungHelmSpeedInches()
    { return 48; }

// he prefers to ride a storm cloud that travels at 24"
inline int dggChihSungCloudSpeedInches()
    { return 24; }

// the storm cloud can support up to 10 beings of any size
inline int dggChihSungCloudBeings()
    { return 10; }

// his +3 mace strikes for 3-30 points per hit
inline int dggChihSungMaceDmgLo()
    { return 3; }

// the mace damage ceiling
inline int dggChihSungMaceDmgHi()
    { return 30; }

// his +3 scale mail appears to be badly rusted
inline int dggChihSungScaleMailPlus()
    { return 3; }

// Chih Sung-Tzu, lord of rain: a very muscular man who always wears a blue
// war helm
inline bool dggChihSungRainLord()
    { return true; }

// like Shang-Ti, he can create weather of any type upon command
inline bool dggChihSungWeatherOnCommand()
    { return true; }

// when any other metal touches his scale mail, that metal completely rusts
// away (no saving throw)
inline bool dggChihSungRustsMetal()
    { return true; }

// ---- the Chih-Chiang Fyu-Ya walk ----

// his arrows inflict 2-20 points of damage when they hit
inline int dggChihChiangArrowDmgLo()
    { return 2; }

// the arrow damage ceiling
inline int dggChihChiangArrowDmgHi()
    { return 20; }

// his sword strikes for 2-24 points in hand-to-hand combat
inline int dggChihChiangSwordDmgLo()
    { return 2; }

// the sword damage ceiling
inline int dggChihChiangSwordDmgHi()
    { return 24; }

// he wears green +4 plate mail in battle
inline int dggChihChiangPlatePlus()
    { return 4; }

// his leathery wings have a span of 40 feet
inline int dggChihChiangWingSpanFeet()
    { return 40; }

// Chih-Chiang Fyu-Ya, god of archers, punisher of the gods: fiery red scaled
// skin, a black demonic head with tusks, elephant ears, cloven hooves
inline bool dggChihChiangArcherGod()
    { return true; }

// with his bow he can hit any target within sight
inline bool dggChihChiangHitsAnyTargetInSight()
    { return true; }

// he is able to reverse any weapon thrown through the air at him and send it
// back at its caster
inline bool dggChihChiangReversesWeapons()
    { return true; }

// his bow is magicked so that use of it by anyone else will cause the arrows
// to fly at the user
inline bool dggChihChiangBowBackfires()
    { return true; }

// the god can shape change at will
inline bool dggChihChiangShapeChange()
    { return true; }

// it is his duty to avenge offenses against the gods, particularly
// desecration of temples
inline bool dggChihChiangAvengeGods()
    { return true; }

// ---- the Chung Kuel walk ----

// Chung Kuel carries a +3 sword of sharpness at all times
inline int dggChungKuelSwordPlus()
    { return 3; }

// Chung Kuel, god of truth and testing, always dressed in costly robes
inline bool dggChungKuelTruthGod()
    { return true; }

// his primary ability: to draw from a well of knowledge so he can meet any
// test with success, given time to visit his well
inline bool dggChungKuelWellOfKnowledge()
    { return true; }

// in any physical contest, if his normal powers will not let him immediately
// win, he will run and secure the materials that allow him to win, doing
// nothing else until he does
inline bool dggChungKuelSecuresWinning()
    { return true; }

// he also carries a rod of cancellation at all times
inline bool dggChungKuelRodOfCancellation()
    { return true; }

// he travels the Prime Material Plane dressed as an old pot-bellied man with
// a long grey beard, asking beings riddles
inline bool dggChungKuelRiddleTravels()
    { return true; }

// correct answers may earn a reward, perhaps even a limited wish - the more
// difficult the riddle, the greater the reward
inline bool dggChungKuelRiddleRewards()
    { return true; }

// ---- the Fei Lien and Feng Po walk ----

// Fei Lien and Feng Po wear +2 plate mail into battle
inline int dggWindCountsPlatePlus()
    { return 2; }

// their swords strike for 2-20
inline int dggWindCountsSwordDmgLo()
    { return 2; }

// the sword damage ceiling
inline int dggWindCountsSwordDmgHi()
    { return 20; }

// their swords do an additional 6 points of electrical damage per blow (no
// saving throw)
inline int dggWindCountsElectricDmg()
    { return 6; }

// their leather sacks blow whirlwinds like those of the djinn, lasting two
// rounds
inline int dggWindCountsWhirlwindRounds()
    { return 2; }

// the whirlwinds can only be conjured up once per day
inline int dggWindCountsWhirlwindPerDay()
    { return 1; }

// their wind-pieces take 10 melee rounds to conjure up
inline int dggWindCountsWindConjureRounds()
    { return 10; }

// Fei Lien and Feng Po, the Counts of the Wind, man-shaped beings
inline bool dggWindCountsOfTheWind()
    { return true; }

// they each ride a piece of the wind, easily negated by any spell affecting
// weather or wind
inline bool dggWindCountsRideTheWind()
    { return true; }

// they each have a large sack of leather that blows djinn-like whirlwinds
// when opened
inline bool dggWindCountsLeatherSacks()
    { return true; }

// they figure prominently in all major battles of the gods and are often used
// as go-betweens for gods and men
inline bool dggWindCountsBattleGoBetweens()
    { return true; }

// their skin is jet black, their eyes blaze fire and they are tusked
inline bool dggWindCountsDemonicLook()
    { return true; }

// ---- the Huan-Ti walk ----

// Huan-Ti wields a +2 halberd doing 3-30 points of damage
inline int dggHuanTiHalberdPlus()
    { return 2; }

// the halberd damage floor
inline int dggHuanTiHalberdDmgLo()
    { return 3; }

// the halberd damage ceiling
inline int dggHuanTiHalberdDmgHi()
    { return 30; }

// his +3 sword also does 3-30 points of damage
inline int dggHuanTiSwordPlus()
    { return 3; }

// he appears as a heavily-muscled man in red +3 plate mail
inline int dggHuanTiPlatePlus()
    { return 3; }

// his black-winged chariot is pulled by 4 Pegasi at 24"/48"
inline int dggHuanTiChariotPegasi()
    { return 4; }

// a mortal dedicates the last ten slain enemies to him
inline int dggHuanTiDedicationCount()
    { return 10; }

// on a 1% chance he may destroy utterly the very next enemy that being faces
inline int dggHuanTiDedicationPct()
    { return 1; }

// Huan-Ti, god of war
inline bool dggHuanTiWarGod()
    { return true; }

// when pressed by more than one enemy he simultaneously uses both his halberd
// and his sword (2 or 4 attacks)
inline bool dggHuanTiDualWield()
    { return true; }

// when flying in his chariot, no magic spell can affect him or the steeds
inline bool dggHuanTiChariotSpellImmune()
    { return true; }

// he watches every battle in which his worshipers take part
inline bool dggHuanTiWatchesBattles()
    { return true; }

// slain enemies dedicated to him must have their heads taken off and burned,
// or the sacrifices will not be received
inline bool dggHuanTiHeadsBurned()
    { return true; }

// clerics of this god must always wear red armor or clothes
inline bool dggHuanTiRedArmorAlways()
    { return true; }

// ---- the Kuan Yin walk ----

// Kuan Yin has the powers of a 20th level magic-user (the printed See below
// class cell)
inline int dggKuanYinMuLevel()
    { return 20; }

// a good act affecting 50 or more worshipers of Kuan Yin, with the goddess
// near
inline int dggKuanYinGoodActWorshipers()
    { return 50; }

// the good act may be granted a wish: a 5% chance
inline int dggKuanYinWishPct()
    { return 5; }

// Kuan Yin, goddess of mercy and child bearing: a slim young woman wearing a
// green satin dress
inline bool dggKuanYinMercyGoddess()
    { return true; }

// her main attribute: the ability to negate any single act of violence
// directed at anyone, once per melee round
inline bool dggKuanYinNegateViolence()
    { return true; }

// she will never use her spells to cause harm
inline bool dggKuanYinNeverHarmfulSpells()
    { return true; }

// no act of violence can be directed towards her by any being in the universe
// - she could walk safely through 500 different types of demons and devils
inline bool dggKuanYinNoViolenceAgainstHer()
    { return true; }

// her main following is with the common folk, and all may work in her cause
// and expect to be rewarded someday
inline bool dggKuanYinCommonFolk()
    { return true; }

// her clerics are the peacemakers of the world and work diligently for the
// end of violence
inline bool dggKuanYinPeacemakers()
    { return true; }

// ---- the Lei Kung walk ----

// in hand-to-hand combat Lei Kung uses his fists for 7-42 points of damage
inline int dggLeiKungFistDmgLo()
    { return 7; }

// the fist damage ceiling
inline int dggLeiKungFistDmgHi()
    { return 42; }

// his +4 hammer strikes for 25 points of electrical damage per hit (no saving
// throw)
inline int dggLeiKungHammerPlus()
    { return 4; }

// the hammer electrical damage
inline int dggLeiKungHammerDmg()
    { return 25; }

// anything touching his +3 plate mail suffers 10 points of electrical damage,
// no saving throw
inline int dggLeiKungMailPlus()
    { return 3; }

// the plate mail electrical damage
inline int dggLeiKungMailDamage()
    { return 10; }

// his red spotted wings have a span of 40 feet
inline int dggLeiKungWingSpanFeet()
    { return 40; }

// Lei Kung, duke of thunder: a man with smoking black skin and eyes with
// pupils like lightning bolts, 2 large tusks and a huge nose
inline bool dggLeiKungThunderDuke()
    { return true; }

// when battling large numbers of opponents he uses a set of green drums that
// act as a horn of blasting and drums of panic combined
inline bool dggLeiKungGreenDrums()
    { return true; }

// he exists to make foul weather of one type or another at the request of the
// other gods, when their worshipers need a lesson
inline bool dggLeiKungFoulWeatherOnRequest()
    { return true; }

// he particularly delights in creating wind storms that destroy fragile
// things of beauty or value
inline bool dggLeiKungDelightsInWindstorms()
    { return true; }

// ---- the Lu Yueh walk ----

// Lu Yueh regenerates at a rate of 25 points per round - all wounds instantly
// close themselves
inline int dggLuYuehRegenPerRound()
    { return 25; }

// those hitting him from less than 10 feet away will suffer the rotting
// sickness (no saving throw)
inline int dggLuYuehRotRangeFeet()
    { return 10; }

// his touch causes the Red Fever that subtracts 3 hit points from those hit
// every melee round until cured
inline int dggLuYuehRedFeverPerMelee()
    { return 3; }

// he can wave his hand and cast a sickness in a cloud 3" x 3" x 3" causing
// the Red Fever to all who breathe it
inline int dggLuYuehCloudSizeInches()
    { return 3; }

// his gifts are decided whenever an evil act affects more than 500 people
inline int dggLuYuehEvilActPeople()
    { return 500; }

// if the god is watching, on a 1% chance
inline int dggLuYuehWatchingPct()
    { return 1; }

// a 5% chance he will give the evil being a disease-causing present with no
// strings attached
inline int dggLuYuehGiftPct()
    { return 5; }

// Lu Yueh, god of epidemics: 3 demon-like heads, 6 arms ending in claws,
// green scaled skin, a look of death and an odor of putrescence
inline bool dggLuYuehEpidemicGod()
    { return true; }

// his main attribute: a rotting sickness spell that kills his enemies who
// fail a saving throw versus poison in 2 melee rounds
inline bool dggLuYuehRottingSicknessSpell()
    { return true; }

// he never wears armor because all wounds instantly close themselves
inline bool dggLuYuehNoArmor()
    { return true; }

// ---- the Ma Yuan walk ----

// Ma Yuan: 3-30 (x4) and 5-40 damage per attack
inline int dggMaYuanDmgLo()
    { return 3; }

// the primary damage ceiling
inline int dggMaYuanDmgHi()
    { return 30; }

// the secondary damage floor
inline int dggMaYuanDmg2Lo()
    { return 5; }

// the secondary damage ceiling
inline int dggMaYuanDmg2Hi()
    { return 40; }

// +3 or better weapon to hit
inline int dggMaYuanWeaponPlusToHit()
    { return 3; }

// the creature is known to have killed at least 10 minor deities
inline int dggMaYuanMinDeitiesKilled()
    { return 10; }

// it attacks as a 16+ hit dice monster
inline int dggMaYuanAttackHD()
    { return 16; }

// the printed X/32,300 experience point value
inline int dggMaYuanXpValue()
    { return 32300; }

// Ma Yuan, killer of the gods: a unique monster with 3 eyes in his
// tyrannosaurus-shaped head and 4 large humanoid arms
inline bool dggMaYuanGodKiller()
    { return true; }

// he has the strength of a storm giant but rarely relies on this in battle
inline bool dggMaYuanStormGiantStrength()
    { return true; }

// he has a powerful magical device shaped as a small triangular piece of
// stone that turns into any weapon the holder wishes, magical or otherwise
inline bool dggMaYuanTriangularStone()
    { return true; }

// his favorite tactic: to make a weapon from his stone that is double the
// power of the one being used against him
inline bool dggMaYuanDoublePowerTactic()
    { return true; }

// the existence of Ma Yuan prevents complacency among the gods
inline bool dggMaYuanPreventsComplacency()
    { return true; }

// ---- the No Cha walk ----

// No Cha often fights with a +3 flaming spear
inline int dggNoChaSpearPlus()
    { return 3; }

// the spear hits for 30 points of damage plus a disintegrate spell (save
// applicable)
inline int dggNoChaSpearDmg()
    { return 30; }

// his small brick of gold throws for 5-50 points of damage up to 100 yards
// away
inline int dggNoChaGoldDmgLo()
    { return 5; }

// the gold brick damage ceiling
inline int dggNoChaGoldDmgHi()
    { return 50; }

// the gold brick range
inline int dggNoChaGoldRangeYards()
    { return 100; }

// his bracelet strangles its target in 5 melee rounds unless they alter their
// form or teleport to another plane
inline int dggNoChaBraceletRounds()
    { return 5; }

// he has the power to throw one 30 point fireball per round
inline int dggNoChaFireballDmg()
    { return 30; }

// No Cha, demigod of thieves: a three-headed, eight-armed man with silvery
// scaled skin and eyes that blaze like fire
inline bool dggNoChaThievesDemigod()
    { return true; }

// he has the ability to grow or shrink in size
inline bool dggNoChaGrowShrink()
    { return true; }

// his panther skin bag blows a whirlwind like that of a djinni
inline bool dggNoChaPantherWhirlwind()
    { return true; }

// his thrown bracelet attaches itself to the neck of its target and strangles
// him or her
inline bool dggNoChaStranglerBracelet()
    { return true; }

// No Cha is the patron of thieves, and there are many tales of his famous
// thieving exploits
inline bool dggNoChaThievesPatron()
    { return true; }

// ---- the Shan Hai Ching walk ----

// Shan Hai Ching's hurricane wind does 5-50 points of damage per melee round
inline int dggShanHaiHurricaneDmgLo()
    { return 5; }

// the hurricane damage ceiling
inline int dggShanHaiHurricaneDmgHi()
    { return 50; }

// Shan Hai Ching, god of wind and sea: a roc's body with the oversized head
// of a man
inline bool dggShanHaiWindSeaGod()
    { return true; }

// the power to raise up a hurricane wind - said to last a full day when great
// wrath is upon the deity
inline bool dggShanHaiHurricaneWind()
    { return true; }

// the power to call forth any creature of the sea (of non-divine nature) to
// do his bidding; the summoning will seem to create beings from the very
// water
inline bool dggShanHaiSeaSummoning()
    { return true; }

// one spell attack against him per round will be turned back upon the caster;
// if multiple spells are cast, the one turned is chosen at random
inline bool dggShanHaiSpellTurning()
    { return true; }

// he and his clerics serve all beings using the sea, and any trip out into
// the oceans requires a sacrifice to this deity for good winds and the like
inline bool dggShanHaiSeaSacrifice()
    { return true; }

// ---- the Spirits of the Air walk ----

// the Spirits of the Air can be summoned by the wind gods in numbers of up to
// 100 every day
inline int dggSpiritsSummonPerDay()
    { return 100; }

// they exist to fight for the gods, attacking as 11 hit dice monsters
inline int dggSpiritsAttackHD()
    { return 11; }

// 50 hit points per spirit (the printed HIT DICE/POINTS line)
inline int dggSpiritsHP()
    { return 50; }

// the printed NO. APPEARING 1-100 (the Termux clean read; the IA 17-1700 is a
// djvu garble of the same cell)
inline int dggSpiritsAppearingLo()
    { return 1; }

// the appearing ceiling
inline int dggSpiritsAppearingHi()
    { return 100; }

// the Spirits of the Air: very rare minions of the wind gods
inline bool dggSpiritsOfTheAir()
    { return true; }

// they have black skin, large bat wings, clawed feet (which they use in
// battle), and a tusked monkey's head
inline bool dggSpiritsLook()
    { return true; }

// ---- the Tou Mu walk ----

// Tou Mu appears on the earth with 16 massive arms, 3 eyes in her barely
// human head, and red scaly skin
inline int dggTouMuArmsCount()
    { return 16; }

// her magical bow never misses anything within 100 yards
inline int dggTouMuBowRangeYards()
    { return 100; }

// her arrows do 1-10 points of damage per strike
inline int dggTouMuArrowDmgLo()
    { return 1; }

// the arrow damage ceiling
inline int dggTouMuArrowDmgHi()
    { return 10; }

// her +3 spear hits for 3-30 points per strike
inline int dggTouMuSpearPlus()
    { return 3; }

// the spear damage floor
inline int dggTouMuSpearDmgLo()
    { return 3; }

// the spear damage ceiling
inline int dggTouMuSpearDmgHi()
    { return 30; }

// her large red flag projects 3 death spells from its folds every melee round
inline int dggTouMuFlagDeathSpells()
    { return 3; }

// her living red dragon's head breathes fire as a normal dragon, with 80 hit
// points
inline int dggTouMuDragonHeadHP()
    { return 80; }

// she has 5 chariots that fly through the air at 24" and move at her command,
// with no visible force to pull them
inline int dggTouMuChariotCount()
    { return 5; }

// the chariot speed
inline int dggTouMuChariotSpeedInches()
    { return 24; }

// the chariot tongues appear to be made of solid diamond and are 32 feet long
inline int dggTouMuChariotTongueFeet()
    { return 32; }

// running beings over in battle inflicts 2-12 points of damage
inline int dggTouMuOverrunDmgLo()
    { return 2; }

// the overrun damage ceiling
inline int dggTouMuOverrunDmgHi()
    { return 12; }

// she may make up to 8 attacks per melee round
inline int dggTouMuAttacksPerMelee()
    { return 8; }

// Tou Mu, goddess of the north star
inline bool dggTouMuNorthStarGoddess()
    { return true; }

// she wields a +3 dancing sword
inline bool dggTouMuDancingSword()
    { return true; }

// a piece of the moon is able to block any single hit directed at her person
// in any given melee round
inline bool dggTouMuMoonPiece()
    { return true; }

// a lotus flower heals all wounds at a touch
inline bool dggTouMuLotusHeals()
    { return true; }

// her free claws do 1-10 points of damage per hit
inline bool dggTouMuFreeClaws()
    { return true; }

// the chariots are all of adamant with gold figures of dragons; the wheels
// are of unbreakable green jade and sparks fly from them whenever they run
// over beings in battle
inline bool dggTouMuAdamantChariots()
    { return true; }

// ---- the Wen Chung walk ----

// Wen Chung's third eye can cast a 20 point lightning bolt
inline int dggWenChungEyeBoltDmg()
    { return 20; }

// the eye bolt range: 180 yards or closer
inline int dggWenChungEyeBoltRangeYards()
    { return 180; }

// the eye bolt: ten times a day
inline int dggWenChungEyeBoltPerDay()
    { return 10; }

// his +3 sword does 3-30 points of damage
inline int dggWenChungSwordPlus()
    { return 3; }

// the sword damage floor
inline int dggWenChungSwordDmgLo()
    { return 3; }

// the sword damage ceiling
inline int dggWenChungSwordDmgHi()
    { return 30; }

// Wen Chung, minister of thunder: 3 eyes in his head and a massive
// dark-skinned body
inline bool dggWenChungThunderMinister()
    { return true; }

// he summons weather for Lei Kung and for his chaotic worshipers
inline bool dggWenChungSummonsWeather()
    { return true; }

// he is totally immune to lightning, cold, or light attacks
inline bool dggWenChungImmunities()
    { return true; }

// ---- the Yen-Wang-Yeh walk ----

// Yen-Wang-Yeh's +3 broad sword does 2-20 points per strike
inline int dggYenWangSwordPlus()
    { return 3; }

// the broad sword damage floor
inline int dggYenWangSwordDmgLo()
    { return 2; }

// the broad sword damage ceiling
inline int dggYenWangSwordDmgHi()
    { return 20; }

// his eyes cast 2 death rays every melee round
inline int dggYenWangDeathRaysPerMelee()
    { return 2; }

// Yen-Wang-Yeh, judge of the dead: a warrior with black skin
inline bool dggYenWangDeadJudge()
    { return true; }

// in battle he likes to shape change into an oriental dragon and use its
// powers for dealing out death
inline bool dggYenWangDragonShape()
    { return true; }

// anyone touching his body with anything will become paralyzed (saving throw
// applicable)
inline bool dggYenWangTouchParalysis()
    { return true; }

// he collects all the souls and spirits of the dead, transports them to the
// proper plane, and makes sure they do not roam the earth at will
inline bool dggYenWangCollectsSouls()
    { return true; }

// he tracks down spirits that do roam and makes them suffer for eternity
inline bool dggYenWangTracksRogues()
    { return true; }

// he has no power over the dead who have risen to a higher plane through
// their good deeds
inline bool dggYenWangNoPowerOverRisen()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Huan-Ti the printed -7, Chih-Chiang the printed +7)
inline int dggCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -4;
        case 2:
            return -2;
        case 3:
            return 7;
        case 4:
            return -2;
        case 5:
            return -4;
        case 6:
            return -4;
        case 7:
            return -7;
        case 8:
            return -3;
        case 9:
            return -4;
        case 10:
            return -2;
        case 11:
            return -4;
        case 12:
            return -2;
        case 13:
            return -2;
        case 14:
            return 4;
        case 15:
            return -3;
        case 16:
            return -2;
        case 17:
            return -5;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all eighteen
// read single this round)
inline int dggCbtACAlt(int b)
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
        default:
            return 0;
        }
    }

// The hit point cells (400 for Shang-Ti down to 50 per Spirit)
inline int dggCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 199;
        case 2:
            return 388;
        case 3:
            return 287;
        case 4:
            return 319;
        case 5:
            return 150;
        case 6:
            return 150;
        case 7:
            return 380;
        case 8:
            return 376;
        case 9:
            return 354;
        case 10:
            return 367;
        case 11:
            return 300;
        case 12:
            return 239;
        case 13:
            return 366;
        case 14:
            return 50;
        case 15:
            return 300;
        case 16:
            return 213;
        case 17:
            return 349;
        default:
            return 0;
        }
    }

// The primary move cells (the printed moves; Huan-Ti 18, Shan Hai Ching 6)
inline int dggCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 15;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 18;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 24;
        case 12:
            return 15;
        case 13:
            return 6;
        case 14:
            return 12;
        case 15:
            return 24;
        case 16:
            return 12;
        case 17:
            return 12;
        default:
            return 0;
        }
    }

// The secondary move cells (the printed slash ceilings; Wen Chung the printed
// 12/21, both voices agreeing)
inline int dggCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 0;
        case 2:
            return 24;
        case 3:
            return 30;
        case 4:
            return 12;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 24;
        case 10:
            return 12;
        case 11:
            return 24;
        case 12:
            return 48;
        case 13:
            return 48;
        case 14:
            return 24;
        case 15:
            return 24;
        case 16:
            return 21;
        case 17:
            return 12;
        default:
            return 0;
        }
    }

// The attack count cells (Huan-Ti the printed 2 or 4; Tou Mu and No Cha 8, Lu
// Yueh 6, Ma Yuan 5)
inline int dggCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 6;
        case 11:
            return 5;
        case 12:
            return 8;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 8;
        case 16:
            return 3;
        case 17:
            return 2;
        default:
            return 0;
        }
    }

// The attack alternative cells (the 3/2 slashes and Huan-Ti's or-4 ceiling)
inline int dggCbtAtD(int b)
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
            return 2;
        case 6:
            return 2;
        case 7:
            return 4;
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
            return 2;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (0 = the printed Standard of Chih Sung-Tzu, the
// Counts and Lu Yueh; Kuan Yin the printed 100%)
inline int dggCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 20;
        case 4:
            return 80;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 50;
        case 8:
            return 100;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 65;
        case 12:
            return 10;
        case 13:
            return 35;
        case 14:
            return 0;
        case 15:
            return 25;
        case 16:
            return 15;
        case 17:
            return 75;
        default:
            return 0;
        }
    }

// The size cells in inches (Shang-Ti 5'4" the 514 decode and Chao 6'2" the
// 612 decode - the R853 foot-mark lesson; Chih Sung-Tzu the sentinel, garbled
// in both voices - flagged; the monsters Ma Yuan 70', Spirits 8')
inline int dggCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 64;
        case 1:
            return 74;
        case 2:
            return 0;
        case 3:
            return 96;
        case 4:
            return 72;
        case 5:
            return 72;
        case 6:
            return 72;
        case 7:
            return 84;
        case 8:
            return 60;
        case 9:
            return 72;
        case 10:
            return 120;
        case 11:
            return 840;
        case 12:
            return 720;
        case 13:
            return 720;
        case 14:
            return 96;
        case 15:
            return 240;
        case 16:
            return 96;
        case 17:
            return 72;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (0 = Nil; Kuan Yin the 25th level cleric)
inline int dggClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 20;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 25;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 10;
        case 14:
            return 0;
        case 15:
            return 20;
        case 16:
            return 0;
        case 17:
            return 20;
        default:
            return 0;
        }
    }

// The druid level cells (Lei Kung and No Cha the 10th level druids; the 14s)
inline int dggClsDruid(int b)
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
            return 14;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 14;
        case 9:
            return 10;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 10;
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
        default:
            return 0;
        }
    }

// The fighter level floor cells (0 = the ranger-slot beings, Kuan Yin's Nil,
// and the monster rows)
inline int dggClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 13;
        case 3:
            return 18;
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
            return 14;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 12;
        case 13:
            return 15;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 18;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells (single printed levels read floor =
// ceiling)
inline int dggClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 13;
        case 3:
            return 18;
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
            return 14;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 12;
        case 13:
            return 15;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 18;
        default:
            return 0;
        }
    }

// The ranger level cells (Chao 17, Chung Kuel 20, Huan-Ti 20, the Counts 10,
// Tou Mu 15, Wen Chung 10)
inline int dggClsRanger(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 17;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 20;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 20;
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
            return 15;
        case 16:
            return 10;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells (99 = the printed See below: Kuan Yin the 20th
// level magic-user doctrine)
inline int dggClsMagUser(int b)
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
            return 15;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 99;
        case 9:
            return 14;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 10;
        case 14:
            return 0;
        case 15:
            return 6;
        case 16:
            return 15;
        case 17:
            return 15;
        default:
            return 0;
        }
    }

// The illusionist level cells (No Cha the 17th level illusionist over a Nil
// magic-user)
inline int dggClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 14;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 17;
        case 13:
            return 10;
        case 14:
            return 0;
        case 15:
            return 6;
        case 16:
            return 15;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (the Counts 10th, Lu Yueh the 19th level thief, No
// Cha the 20th)
inline int dggClsThief(int b)
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
            return 10;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 20;
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
        default:
            return 0;
        }
    }

// The assassin level cells (the 15s; Chao 10th, Wen Chung-era none)
inline int dggClsAssassin(int b)
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
            return 15;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 15;
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
            return 15;
        default:
            return 0;
        }
    }

// The monk level cells (Chao 7, the Counts 5, Huan-Ti 12, Chih-Chiang 10,
// Chung Kuel 10, Yen-Wang-Yeh 12)
inline int dggClsMonk(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 7;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 12;
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
            return 12;
        default:
            return 0;
        }
    }

// The bard level cells (Shang-Ti 15th, Kuan Yin 15th, Chih-Chiang and Chung
// Kuel 10)
inline int dggClsBard(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 15;
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
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (Kuan Yin the printed S:8, Yen-Wang-Yeh and the Counts
// 14)
inline int dggAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 23;
        case 3:
            return 23;
        case 4:
            return 20;
        case 5:
            return 14;
        case 6:
            return 14;
        case 7:
            return 25;
        case 8:
            return 8;
        case 9:
            return 23;
        case 10:
            return 20;
        case 11:
            return 0;
        case 12:
            return 25;
        case 13:
            return 24;
        case 14:
            return 0;
        case 15:
            return 23;
        case 16:
            return 24;
        case 17:
            return 14;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = no printed bracket)
inline int dggAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 7;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 7;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 7;
        case 13:
            return 6;
        case 14:
            return 0;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells (the +14s of the S:25s)
inline int dggAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 14;
        case 2:
            return 11;
        case 3:
            return 11;
        case 4:
            return 8;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 14;
        case 8:
            return 0;
        case 9:
            return 11;
        case 10:
            return 8;
        case 11:
            return 0;
        case 12:
            return 14;
        case 13:
            return 12;
        case 14:
            return 0;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The intelligence cells (Tou Mu W:3 and No Cha W:7 the low wisdoms ride the
// int col commentary; the printed I line)
inline int dggAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 18;
        case 2:
            return 20;
        case 3:
            return 22;
        case 4:
            return 25;
        case 5:
            return 14;
        case 6:
            return 14;
        case 7:
            return 23;
        case 8:
            return 25;
        case 9:
            return 23;
        case 10:
            return 17;
        case 11:
            return 0;
        case 12:
            return 25;
        case 13:
            return 21;
        case 14:
            return 0;
        case 15:
            return 25;
        case 16:
            return 20;
        case 17:
            return 24;
        default:
            return 0;
        }
    }

// The wisdom cells (No Cha the printed W:7, Tou Mu the printed W:3)
inline int dggAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 14;
        case 2:
            return 24;
        case 3:
            return 22;
        case 4:
            return 25;
        case 5:
            return 14;
        case 6:
            return 14;
        case 7:
            return 18;
        case 8:
            return 25;
        case 9:
            return 17;
        case 10:
            return 5;
        case 11:
            return 0;
        case 12:
            return 7;
        case 13:
            return 23;
        case 14:
            return 0;
        case 15:
            return 3;
        case 16:
            return 22;
        case 17:
            return 20;
        default:
            return 0;
        }
    }

// The dexterity cells (Kuan Yin the printed D:12 - the IA geometry word
// against the Termux 72 garble)
inline int dggAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        case 2:
            return 19;
        case 3:
            return 25;
        case 4:
            return 20;
        case 5:
            return 19;
        case 6:
            return 19;
        case 7:
            return 25;
        case 8:
            return 12;
        case 9:
            return 20;
        case 10:
            return 17;
        case 11:
            return 0;
        case 12:
            return 25;
        case 13:
            return 17;
        case 14:
            return 0;
        case 15:
            return 25;
        case 16:
            return 21;
        case 17:
            return 25;
        default:
            return 0;
        }
    }

// The constitution cells (the 25s)
inline int dggAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        case 2:
            return 23;
        case 3:
            return 22;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 25;
        case 8:
            return 22;
        case 9:
            return 23;
        case 10:
            return 25;
        case 11:
            return 0;
        case 12:
            return 20;
        case 13:
            return 24;
        case 14:
            return 0;
        case 15:
            return 19;
        case 16:
            return 19;
        case 17:
            return 23;
        default:
            return 0;
        }
    }

// The charisma cells (Chih-Chiang the printed -2 and Lu Yueh the printed -3;
// Lei Kung 7, the Counts 9)
inline int dggAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 23;
        case 3:
            return -2;
        case 4:
            return 19;
        case 5:
            return 9;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 25;
        case 9:
            return 7;
        case 10:
            return -3;
        case 11:
            return 0;
        case 12:
            return 10;
        case 13:
            return 19;
        case 14:
            return 0;
        case 15:
            return 5;
        case 16:
            return 15;
        case 17:
            return 19;
        default:
            return 0;
        }
    }

// The psionic score cells (0 = no numeric scores; the monster rows read the
// all-sentinel line)
inline int dggAbiPsi(int b)
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
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Shang-Ti through Yen-Wang-Yeh)
inline int dggRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print page cells (37-42, the folio offset PRINT = PDF - 1)
inline int dggRosPage(int b)
    {
        switch (b) {
        case 0:
            return 37;
        case 1:
            return 38;
        case 2:
            return 38;
        case 3:
            return 38;
        case 4:
            return 38;
        case 5:
            return 39;
        case 6:
            return 39;
        case 7:
            return 39;
        case 8:
            return 39;
        case 9:
            return 40;
        case 10:
            return 40;
        case 11:
            return 41;
        case 12:
            return 41;
        case 13:
            return 42;
        case 14:
            return 42;
        case 15:
            return 42;
        case 16:
            return 42;
        case 17:
            return 42;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG, 1 NG, 2 CG, 3 LN, 4 N, 5 CN Wen Chung, 6 LE, 7
// NE No Cha, 8 CE - the R852 code scheme)
inline int dggRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 6;
        case 10:
            return 8;
        case 11:
            return 8;
        case 12:
            return 7;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 8;
        case 16:
            return 5;
        case 17:
            return 4;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 demigod, 3 monster format - Ma Yuan
// and the Spirits)
inline int dggRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 1;
        default:
            return 0;
        }
    }

// The psionic class cells (0 Nil the monsters, 1 Shang-Ti, 2 Chao/Chung
// Kuel/Tou Mu, 5 the Counts, 6 the ten VI readers - the R849 class table)
inline int dggRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 0;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 6;
        case 17:
            return 6;
        default:
            return 0;
        }
    }

// The plane cells (1 Nirvana, 2 Elemental Plane of Air, 3 Gehenna, 4 Seven
// Heavens, 5 Limbo, 6 Acheron, 7 Abyss, 8 Nine Hells, 9 Concordant
// Opposition; 0 = the monster rows)
inline int dggRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 0;
        case 12:
            return 8;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 7;
        case 16:
            return 2;
        case 17:
            return 9;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed DAMAGE/ATTACK cell is numeric
// damage; 0 = Nil, See below, or Variable)
inline int dggRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells: the M-U/I pairs and
// the monk/bard in-eachs)
inline int dggRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The twin-pair flags (Fei Lien and Feng Po, the identical Counts of the Wind
// stat blocks)
inline int dggRosTwinPair(int b)
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
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
