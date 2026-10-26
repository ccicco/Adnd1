// =========================================================================================
// Adnd1 - rules/nhg.h
// the Nonhumans' Deities - the D&DG walk round sixteen, print pp. 105-112:
// twenty stat-block rows - the six greater gods (Moradin, Corellon Larethian,
// Maglubiyet, Garl Glittergold, Yondalla, Gruumsh), the twelve lesser
// (Hruggek, Skerrit, Deep Sashelas, Lolth, Rillifane Rallathil, Grolantor,
// Skoraeus Stonebones, Kurtulmak, Blibdoolpoolp, Semuanya, Eadro, Sekolah)
// and the two demigods (Vaprak, Laogzed) - plus the shaman doctrine and the
// NOTE list of the intro.
// census 786 -> 787.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 106-113; the second printing) with
// the tsv x-y geometry as the fold-swap and not-printed-cell arbiter; the
// collation voice: the 1eonline L&L transcription (the R853 parity voice).
// The adjudications: the Moradin-Corellon and Kurtulmak-Blibdoolpoolp fold
// swaps, the Hruggek dex gap, the Yondalla and Kurtulmak fraction sizes, the
// Lolth 1/9 web walk and the -2 drow paren, the Vaprak W 12 and Sashelas D 21
// divergences, and the Nine Hells plane pins against the L&L D64 glosses.
//
namespace rules {

// ---- the shaman doctrine ----

// the nonhumans deities round: the D&DG walk round sixteen
inline int nhgRound()
    { return 864; }

// the section opens on print p. 105
inline int nhgPrintStart()
    { return 105; }

// the section closes on print p. 112 (Laogzed)
inline int nhgPrintEnd()
    { return 112; }

// the shaman bonus hit points per level, low die
inline int nhgShamanHpLow()
    { return 1; }

// the shaman bonus hit points per level, high die
inline int nhgShamanHpHigh()
    { return 4; }

// the levels per one hit dice of fighting improvement
inline int nhgHdBetterLevels()
    { return 2; }

// every two shaman levels fight as one hit dice better
inline bool nhgShamanHdLadder()
    { return true; }

// the tandem witch doctor hit points, low die
inline int nhgWitchHpLow()
    { return 2; }

// the tandem witch doctor hit points, high die
inline int nhgWitchHpHigh()
    { return 5; }

// the witch doctor shaman and magic-user levels are paired, not added
inline bool nhgWitchDoctorPaired()
    { return true; }

// the 2-5 hit point bonus holds only while advancing in tandem
inline bool nhgWitchTandemBonus()
    { return true; }

// the gnoll shaman base hit dice (2d8)
inline int nhgGnollBaseHd()
    { return 2; }

// the gnoll shaman bonus dice (3d4)
inline int nhgGnollBonusDice()
    { return 3; }

// the gnoll shaman fights as a 4 hit dice monster
inline int nhgGnollFightsHd()
    { return 4; }

// the goblin shaman dice (4d4)
inline int nhgGoblinDice()
    { return 4; }

// the goblin shaman bonus hit points, low
inline int nhgGoblinBonusLow()
    { return 1; }

// the goblin shaman bonus hit points, high
inline int nhgGoblinBonusHigh()
    { return 7; }

// the goblin shaman fights as the 3-1 print
inline int nhgGoblinFightsHd()
    { return 3; }

// the goblin shaman 3-1 print carries the (or 2-3+) alternate
inline bool nhgGoblinHdAltPrint()
    { return true; }

// the orc witch doctor base dice (1d8)
inline int nhgOrcDice()
    { return 1; }

// the orc witch doctor bonus dice (2d4)
inline int nhgOrcBonusDice()
    { return 2; }

// the orc witch doctor bonus hit points
inline int nhgOrcBonusHp()
    { return 2; }

// the orc witch doctor fights as a 2 hit dice monster
inline int nhgOrcFightsHd()
    { return 2; }

// the example orc witch doctor is 3/3
inline int nhgOrcWitchLevel()
    { return 3; }

// the NOTE list: thirteen beings treated as lesser gods
inline int nhgNoteLesserGods()
    { return 13; }

// the Monster Manual half of the NOTE list
inline int nhgNoteMMCount()
    { return 10; }

// the Fiend Folio half of the NOTE list
inline int nhgNoteFFCount()
    { return 3; }

// the NOTE list beings are treated as lesser gods
inline bool nhgNoteMMLesserGods()
    { return true; }

// Lolth is the one NOTE being detailed in this volume
inline bool nhgNoteLolthDetailed()
    { return true; }

// the gnoll shamans advance to the 5th level
inline int nhgGnollShamanMax()
    { return 5; }

// the ixitxachitl progress to the 8th level
inline int nhgIxitxachitlClericMax()
    { return 8; }

// the female drow of 18 wisdom reach the 14th level
inline int nhgDrowClericMax()
    { return 14; }

// ---- the shaman level caps ----

// the bugbear shamans rise to the 5th level
inline int nhgBugbearShamanMax()
    { return 5; }

// the centaur shamans advance to the 3rd level
inline int nhgCentaurShamanMax()
    { return 3; }

// the ettin shamans stop at the 3rd level
inline int nhgEttinShamanMax()
    { return 3; }

// the hill giant shamans range to the 7th level
inline int nhgHillGiantShamanMax()
    { return 7; }

// the fire giant shamans rise to the 7th level
inline int nhgFireGiantShamanMax()
    { return 7; }

// the frost giant shamans attain the 7th level
inline int nhgFrostGiantShamanMax()
    { return 7; }

// the stone giant shamans attain the 7th level
inline int nhgStoneGiantShamanMax()
    { return 7; }

// the kobold shamans rise to the 5th level
inline int nhgKoboldShamanMax()
    { return 5; }

// the kuo-toan clerics attain the 12th level
inline int nhgKuoToanClericMax()
    { return 12; }

// the lizard man shamans attain the 7th level
inline int nhgLizardManShamanMax()
    { return 7; }

// the locathah have shamans of up to the 3rd level
inline int nhgLocathahShamanMax()
    { return 3; }

// the merman clerics reach the 5th level
inline int nhgMermanClericMax()
    { return 5; }

// the ogre and troll shamans stop at the 3rd level
inline int nhgOgreTrollShamanMax()
    { return 3; }

// the orcish shamans range to the 5th level
inline int nhgOrcShamanMax()
    { return 5; }

// the sahuagin clerics advance to the 5th level
inline int nhgSahuaginClericMax()
    { return 5; }

// the troglodyte shamans work to the 3rd level
inline int nhgTroglodyteShamanMax()
    { return 3; }

// the goblin and hobgoblin shamans rise to the 7th level
inline int nhgGoblinShamanMax()
    { return 7; }

// the dwarven non-player clerics rise to the 7th level
inline int nhgDwarfClericMax()
    { return 7; }

// the elven non-player clerics attain the 7th level
inline int nhgElfClericMax()
    { return 7; }

// the aquatic elven clerics advance to the 7th level
inline int nhgAquaticElfClericMax()
    { return 7; }

// the gnomish non-player clerics advance to the 7th level
inline int nhgGnomeClericMax()
    { return 7; }

// the halfling non-player clerics rise to the 5th level
inline int nhgHalflingClericMax()
    { return 5; }

// the wood elf clerics of both cults work to the 7th level
inline int nhgWoodElfClericMax()
    { return 7; }

// ---- Hruggek ----

// the ten-foot +3 morningstar
inline int nhgHruggekMorningstarPlus()
    { return 3; }

// the morningstar damage low
inline int nhgHruggekMorningstarLow()
    { return 3; }

// the morningstar damage high
inline int nhgHruggekMorningstarHigh()
    { return 30; }

// the claw damage low
inline int nhgHruggekClawLow()
    { return 2; }

// the claw damage high
inline int nhgHruggekClawHigh()
    { return 16; }

// the +2 or better weapon to hit
inline int nhgHruggekWeaponToHit()
    { return 2; }

// the charisma 23 to bugbears
inline int nhgHruggekChaToBugbears()
    { return 23; }

// the simple bugbear pantheon of six deities
inline int nhgHruggekPantheonSize()
    { return 6; }

// the bugbear shamans offer him the blood of their enemies
inline bool nhgHruggekBloodOfferings()
    { return true; }

// his Pandemonium cave is decorated with severed heads
inline bool nhgHruggekCaveHeads()
    { return true; }

// Hruggek is the most powerful bugbear god but rules none
inline bool nhgHruggekMostPowerful()
    { return true; }

// ---- Skerrit the Forester ----

// the Variable (at least 2) armor class floor
inline int nhgSkerritACFloor()
    { return 2; }

// the centaur-form +3 spear
inline int nhgSkerritSpearPlus()
    { return 3; }

// the spear damage low
inline int nhgSkerritSpearLow()
    { return 2; }

// the spear damage high (plus strength bonus)
inline int nhgSkerritSpearHigh()
    { return 20; }

// the centaur-form armor class 2
inline int nhgSkerritFormAC()
    { return 2; }

// the centaur-form move 21 inches
inline int nhgSkerritFormMove()
    { return 21; }

// the -4 to hit him in the forests
inline int nhgSkerritForestToHit()
    { return -4; }

// Skerrit can appear as any creature of the forest
inline bool nhgSkerritAnyForestForm()
    { return true; }

// his spirit temporarily possesses plants and animals
inline bool nhgSkerritPossessPlants()
    { return true; }

// the branches and leaves block blows in the forests
inline bool nhgSkerritForestDefense()
    { return true; }

// the centaurs worship through dances and mock hunts on full-moon nights
inline bool nhgSkerritFullMoonDances()
    { return true; }

// the satyrs worship Skerrit but have no clerical members
inline bool nhgSkerritSatyrsNoClerics()
    { return true; }

// ---- Moradin the Soul Forger ----

// the +5 glowing hammer
inline int nhgMoradinHammerPlus()
    { return 5; }

// the hammer damage low
inline int nhgMoradinHammerLow()
    { return 4; }

// the hammer damage high
inline int nhgMoradinHammerHigh()
    { return 40; }

// the charisma 25 to dwarves
inline int nhgMoradinChaToDwarves()
    { return 25; }

// Moradin forged the dwarves from iron and mithral
inline bool nhgMoradinForgedDwarves()
    { return true; }

// the hammer disappears from others hands and returns to him
inline bool nhgMoradinHammerReturns()
    { return true; }

// his armor and shield cannot be removed from his body
inline bool nhgMoradinArmorUnremovable()
    { return true; }

// no forged weapon can harm the Soul Forger
inline bool nhgMoradinForgedWeaponsCannotHarm()
    { return true; }

// the shrine center is the ever-burning hearth and forge
inline bool nhgMoradinHearthForge()
    { return true; }

// ---- Corellon Larethian ----

// the longbow damage low
inline int nhgCorellonBowLow()
    { return 2; }

// the longbow damage high
inline int nhgCorellonBowHigh()
    { return 20; }

// the +5 sword made from a star
inline int nhgCorellonSwordPlus()
    { return 5; }

// the sword damage low
inline int nhgCorellonSwordLow()
    { return 3; }

// the sword damage high
inline int nhgCorellonSwordHigh()
    { return 30; }

// the other-wielder burn damage low
inline int nhgCorellonSwordBurnLow()
    { return 10; }

// the other-wielder burn damage high
inline int nhgCorellonSwordBurnHigh()
    { return 100; }

// the arrows fired from his bow never miss
inline bool nhgCorellonBowNeverMisses()
    { return true; }

// the sword detects the most dangerous opponents
inline bool nhgCorellonSwordDetectsDanger()
    { return true; }

// Corellon personally banished Lolth from the sunlit Upperworld
inline bool nhgCorellonBanishedLolth()
    { return true; }

// the elves sprang from the drops of his blood
inline bool nhgCorellonElvesFromBlood()
    { return true; }

// his clerics wear the blue quarter-moon talisman
inline bool nhgCorellonQuarterMoonTalisman()
    { return true; }

// the elves build no shrines, only natural formations
inline bool nhgCorellonNoShrines()
    { return true; }

// ---- Deep Sashelas ----

// the damage low (trident or weapon)
inline int nhgSashelasDmgLow()
    { return 3; }

// the damage high
inline int nhgSashelasDmgHigh()
    { return 30; }

// the twenty strongest dolphins follow him
inline int nhgSashelasDolphins()
    { return 20; }

// the 100 percent magic resistance under water
inline int nhgSashelasWaterMR()
    { return 100; }

// he does double damage under water
inline bool nhgSashelasDoubleDamageUnderwater()
    { return true; }

// the 100 percent magic resistance holds under water
inline bool nhgSashelasFullWaterMR()
    { return true; }

// he is the master of the dolphins
inline bool nhgSashelasDolphinMaster()
    { return true; }

// his clerics conduct ritual shark hunts
inline bool nhgSashelasSharkHunts()
    { return true; }

// the ceremonies time to the high and low tides
inline bool nhgSashelasTideCeremonies()
    { return true; }

// ---- Lolth ----

// the drow-form move 15 inches
inline int nhgLolthDrowMove()
    { return 15; }

// the web strand range in feet
inline int nhgLolthWebRange()
    { return 30; }

// the web poison damage low per round
inline int nhgLolthWebDmgLow()
    { return 1; }

// the web poison damage high per round
inline int nhgLolthWebDmgHigh()
    { return 4; }

// the spider bite damage low
inline int nhgLolthBiteLow()
    { return 4; }

// the spider bite damage high
inline int nhgLolthBiteHigh()
    { return 16; }

// the spider bite save modifier
inline int nhgLolthPoisonSaveMod()
    { return -4; }

// she heals herself up to thrice per day
inline int nhgLolthHealsPerDay()
    { return 3; }

// the poison type I chance
inline int nhgLolthPoisonOnePct()
    { return 45; }

// the poison type II chance
inline int nhgLolthPoisonTwoPct()
    { return 35; }

// the poison type III chance
inline int nhgLolthPoisonThreePct()
    { return 20; }

// the demon gate success chance
inline int nhgLolthGatePct()
    { return 66; }

// the 9-16 large spiders summon chance
inline int nhgLolthSummonLargePct()
    { return 20; }

// the 7-12 huge spiders summon chance
inline int nhgLolthSummonHugePct()
    { return 30; }

// the 2-8 giant spiders summon chance
inline int nhgLolthSummonGiantPct()
    { return 40; }

// the 1-4 phase spiders summon chance
inline int nhgLolthSummonPhasePct()
    { return 10; }

// the holy water splash damage
inline int nhgLolthHolyWaterSplash()
    { return 6; }

// the direct holy water hit low (3d6+3)
inline int nhgLolthHolyWaterLow()
    { return 6; }

// the direct holy water hit high
inline int nhgLolthHolyWaterHigh()
    { return 21; }

// the infrared and ultraviolet sight in inches
inline int nhgLolthSightRange()
    { return 120; }

// the humanoid-form cleric level
inline int nhgLolthDrowClericLevel()
    { return 16; }

// the humanoid-form magic-user level
inline int nhgLolthDrowMagUserLevel()
    { return 14; }

// the psionic disciplines perform at the 16th level
inline int nhgLolthDisciplineLevel()
    { return 16; }

// the charisma 23 of the dark elf form
inline int nhgLolthChaDrow()
    { return 23; }

// the spider and the dark elf forms, the parens give the drow stats
inline bool nhgLolthSpiderAndDrowForms()
    { return true; }

// all spiders understand and obey her unquestioningly
inline bool nhgLolthConverseWithSpiders()
    { return true; }

// the one-per-melee spider power list at will
inline bool nhgLolthSpiderPowersList()
    { return true; }

// the phase door, read magic and shape change twice per day
inline bool nhgLolthTwicePerDayPowers()
    { return true; }

// silver alone does her no harm; weapons must be magical (at least +1) to
// harm her
inline bool nhgLolthSilverImmune()
    { return true; }

// cold, electrical and gas attacks do half damage
inline bool nhgLolthHalfDamageForms()
    { return true; }

// her psionic powers are lost in the spider form
inline bool nhgLolthPsionicLostInSpiderForm()
    { return true; }

// the minor devotion of body equilibrium
inline bool nhgLolthDevBodyEquilibrium()
    { return true; }

// the minor devotion of clairvoyance
inline bool nhgLolthDevClairvoyance()
    { return true; }

// the minor devotion of domination
inline bool nhgLolthDevDomination()
    { return true; }

// the major science of dimension walking
inline bool nhgLolthSciDimensionWalking()
    { return true; }

// the major science of mind bar
inline bool nhgLolthSciMindBar()
    { return true; }

// the major science of molecular rearrangement
inline bool nhgLolthSciMolecularRearrangement()
    { return true; }

// the major science of probability travel
inline bool nhgLolthSciProbabilityTravel()
    { return true; }

// she is especially susceptible to holy water
inline bool nhgLolthHolyWaterSusceptible()
    { return true; }

// ---- Rillifane Rallathil ----

// his bow arrows always slay on a hit, no save
inline bool nhgRillifaneArrowsAlwaysSlay()
    { return true; }

// he appears as a green-skinned elf clad in bark armor
inline bool nhgRillifaneBarkArmor()
    { return true; }

// his oak roots mingle with every other plant in the world
inline bool nhgRillifaneRootsMingle()
    { return true; }

// his clerics are deadly enemies of those who hunt for sport
inline bool nhgRillifaneHuntsSportEnemies()
    { return true; }

// ---- Grolantor ----

// the Dwarfcrusher damage low
inline int nhgGrolantorClubLow()
    { return 4; }

// the Dwarfcrusher damage high
inline int nhgGrolantorClubHigh()
    { return 40; }

// his creed is persecution of all inferior races
inline bool nhgGrolantorPersecutesSmaller()
    { return true; }

// he wears belts of woven dwarfbeards
inline bool nhgGrolantorDwarfbeardBelts()
    { return true; }

// the ettins worship him in a two-headed aspect
inline bool nhgGrolantorEttinWorship()
    { return true; }

// ---- Skoraeus Stonebones ----

// the fist damage low
inline int nhgSkoraeusFistLow()
    { return 6; }

// the fist damage high
inline int nhgSkoraeusFistHigh()
    { return 60; }

// the regeneration 5 points per round on stone
inline int nhgSkoraeusRegen()
    { return 5; }

// the earthquake spell at the 30th level
inline int nhgSkoraeusEarthquakeLevel()
    { return 30; }

// the stone giant summon low
inline int nhgSkoraeusSummonLow()
    { return 2; }

// the stone giant summon high
inline int nhgSkoraeusSummonHigh()
    { return 20; }

// he never ventures above ground and cannot be gated there
inline bool nhgSkoraeusNeverAboveGround()
    { return true; }

// he knows everything touching rock through its vibrations
inline bool nhgSkoraeusListensToRock()
    { return true; }

// he casts one earthquake spell per round
inline bool nhgSkoraeusEarthquakePerRound()
    { return true; }

// ---- Maglubiyet ----

// the damage low
inline int nhgMaglubiyetDmgLow()
    { return 2; }

// the damage high
inline int nhgMaglubiyetDmgHigh()
    { return 20; }

// his goblin spirit armies eternally war with the orcish spirit army
inline bool nhgMaglubiyetSpiritArmies()
    { return true; }

// the sacrifices of creatures with souls fall on new-moon nights
inline bool nhgMaglubiyetNewMoonSacrifices()
    { return true; }

// the shamans claim he always wins; the spirits re-form
inline bool nhgMaglubiyetAlwaysWinsClaim()
    { return true; }

// ---- Garl Glittergold ----

// the intelligent +5 mithral-steel axe Arumdina
inline int nhgGarlAxePlus()
    { return 5; }

// the Arumdina damage low
inline int nhgGarlAxeLow()
    { return 3; }

// the Arumdina damage high
inline int nhgGarlAxeHigh()
    { return 30; }

// Arumdina is an intelligent axe
inline bool nhgGarlArumdinaIntelligent()
    { return true; }

// Arumdina can heal Garl completely once per day
inline bool nhgGarlArumdinaHeals()
    { return true; }

// Garl collapsed the Kobold King cavern
inline bool nhgGarlKoboldCavernCollapse()
    { return true; }

// he is a grim war leader when his people are threatened
inline bool nhgGarlWarLeader()
    { return true; }

// his clerics require gold for the sacrifices
inline bool nhgGarlGoldSacrifices()
    { return true; }

// ---- Yondalla ----

// the staff of withering charges expended
inline int nhgYondallaWitherCharges()
    { return 3; }

// the withering damage low
inline int nhgYondallaWitherLow()
    { return 2; }

// the withering damage high
inline int nhgYondallaWitherHigh()
    { return 5; }

// the withering age in years
inline int nhgYondallaWitherAge()
    { return 10; }

// the Provider aspect of fertility and growing things
inline bool nhgYondallaProviderAspect()
    { return true; }

// the Protector aspect of warding off evil
inline bool nhgYondallaProtectorAspect()
    { return true; }

// the withering wave has no saving throw
inline bool nhgYondallaWitheringNoSave()
    { return true; }

// the halflings set aside one day per week as safeday
inline bool nhgYondallaSafeday()
    { return true; }

// ---- Kurtulmak ----

// he smells gnomes up to a mile away
inline int nhgKurtulmakSmellMiles()
    { return 1; }

// the fear aura radius in feet
inline int nhgKurtulmakFearFeet()
    { return 10; }

// the gnomes save modifier in the fear aura
inline int nhgKurtulmakFearSaveMod()
    { return -4; }

// the +4 spear
inline int nhgKurtulmakSpearPlus()
    { return 4; }

// the spear damage low
inline int nhgKurtulmakSpearLow()
    { return 2; }

// the spear damage high
inline int nhgKurtulmakSpearHigh()
    { return 24; }

// the tail sting damage low
inline int nhgKurtulmakTailLow()
    { return 1; }

// the tail sting damage high
inline int nhgKurtulmakTailHigh()
    { return 6; }

// the gnome scent drives him into a killing frenzy
inline bool nhgKurtulmakSmellsGnomes()
    { return true; }

// the fear aura saves vs spells or flee in panic
inline bool nhgKurtulmakFearAura()
    { return true; }

// the tail sting poison is save or die
inline bool nhgKurtulmakTailPoison()
    { return true; }

// the kobold shamans wear orange robes with the white death-head sigil
inline bool nhgKurtulmakOrangeRobes()
    { return true; }

// ---- Blibdoolpoolp ----

// the claw snap damage low
inline int nhgBlibClawLow()
    { return 4; }

// the claw snap damage high
inline int nhgBlibClawHigh()
    { return 24; }

// the insanity gaze save modifier
inline int nhgBlibGazeSaveMod()
    { return -4; }

// the giant lobster summon low
inline int nhgBlibSummonLobsterLow()
    { return 3; }

// the giant lobster summon high
inline int nhgBlibSummonLobsterHigh()
    { return 30; }

// the water elemental summon low
inline int nhgBlibSummonElementalLow()
    { return 1; }

// the water elemental summon high
inline int nhgBlibSummonElementalHigh()
    { return 10; }

// the summoned water elementals hit dice
inline int nhgBlibElementalHD()
    { return 16; }

// the favor chance percent per gem value
inline int nhgBlibGemFavorPct()
    { return 1; }

// the gems value per favor percent
inline int nhgBlibGemFavorPerGp()
    { return 1000; }

// the pearls value per favor percent
inline int nhgBlibPearlPerGp()
    { return 500; }

// her worshipers regularly sacrifice lobsters to her
inline bool nhgBlibLobsterSacrifices()
    { return true; }

// her close-range gaze causes insanity on a failed save
inline bool nhgBlibGazeInsanity()
    { return true; }

// the clerics sacrifice captured humans by drowning
inline bool nhgBlibDrowningSacrifices()
    { return true; }

// she hates all who drove the kuo-toa into the underworld
inline bool nhgBlibHatesSurfaceRaces()
    { return true; }

// ---- Semuanya ----

// the club damage low
inline int nhgSemuanyaClubLow()
    { return 2; }

// the club damage high (plus strength)
inline int nhgSemuanyaClubHigh()
    { return 20; }

// the minotaur lizard summon low
inline int nhgSemuanyaSummonLow()
    { return 3; }

// the minotaur lizard summon high
inline int nhgSemuanyaSummonHigh()
    { return 18; }

// the regeneration 5 points per round
inline int nhgSemuanyaRegen()
    { return 5; }

// the charisma 25 toward lizard men
inline int nhgSemuanyaChaToLizardMen()
    { return 25; }

// Semuanya can command all lizards
inline bool nhgSemuanyaCommandsLizards()
    { return true; }

// the shamans emulate his taciturnity and counsel avoidance
inline bool nhgSemuanyaTaciturn()
    { return true; }

// the whole creed is survival and propagation
inline bool nhgSemuanyaSurvivalCreed()
    { return true; }

// ---- Eadro ----

// the eight water-whips of the amorphous form
inline int nhgEadroWhipCount()
    { return 8; }

// the water-whip damage low
inline int nhgEadroWhipLow()
    { return 1; }

// the water-whip damage high
inline int nhgEadroWhipHigh()
    { return 10; }

// the water elemental summon low
inline int nhgEadroSummonLow()
    { return 2; }

// the water elemental summon high
inline int nhgEadroSummonHigh()
    { return 8; }

// the summoned water elementals hit dice
inline int nhgEadroElementalHD()
    { return 16; }

// Eadro appears as a being of living water
inline bool nhgEadroLivingWater()
    { return true; }

// in battle he becomes the amorphous blob of water-whips
inline bool nhgEadroAmorphousBlob()
    { return true; }

// between lives the spirits take the form of tiny fish
inline bool nhgEadroSpiritsAsFish()
    { return true; }

// the locathah and mermen compete for the same sea-space
inline bool nhgEadroSeaSpaceRivalry()
    { return true; }

// ---- Vaprak ----

// the claw damage low
inline int nhgVaprakClawLow()
    { return 2; }

// the claw damage high
inline int nhgVaprakClawHigh()
    { return 20; }

// the bite damage low
inline int nhgVaprakBiteLow()
    { return 1; }

// the bite damage high
inline int nhgVaprakBiteHigh()
    { return 12; }

// the regeneration 7 points per melee round
inline int nhgVaprakRegen()
    { return 7; }

// the berserk rage reward chance
inline int nhgVaprakBerserkPct()
    { return 2; }

// the berserk to-hit and damage bonus
inline int nhgVaprakBerserkHit()
    { return 2; }

// the berserk armor class penalty
inline int nhgVaprakBerserkAC()
    { return -2; }

// he prefers to tear his prey apart with his claws
inline bool nhgVaprakTearsPrey()
    { return true; }

// the Destroyer is always hungry
inline bool nhgVaprakAlwaysHungry()
    { return true; }

// he sometimes rewards worshipers with berserk rage
inline bool nhgVaprakBerserkRage()
    { return true; }

// ---- Gruumsh ----

// the great iron +5 spear
inline int nhgGruumshSpearPlus()
    { return 5; }

// the spear damage low
inline int nhgGruumshSpearLow()
    { return 3; }

// the spear damage high
inline int nhgGruumshSpearHigh()
    { return 30; }

// the paralysis save modifier
inline int nhgGruumshParalysisSaveMod()
    { return -4; }

// the charisma 25 to orcs
inline int nhgGruumshChaToOrcs()
    { return 25; }

// he has one large unwinking eye in the center of his forehead
inline bool nhgGruumshOneEye()
    { return true; }

// his clerics use only destructive spells
inline bool nhgGruumshDestructiveSpellsOnly()
    { return true; }

// an orc must pluck out his own left eye to become a shaman
inline bool nhgGruumshPlucksLeftEye()
    { return true; }

// proper worship requires blood in large quantities
inline bool nhgGruumshBloodWorship()
    { return true; }

// his spirit-orcs war continuously in Hell
inline bool nhgGruumshSpiritOrcArmies()
    { return true; }

// ---- Sekolah ----

// the bite damage low
inline int nhgSekolahBiteLow()
    { return 6; }

// the bite damage high
inline int nhgSekolahBiteHigh()
    { return 60; }

// the to-hit roll that swallows man-sized whole
inline int nhgSekolahSwallowRoll()
    { return 16; }

// the holy sharks count low
inline int nhgSekolahHolySharksLow()
    { return 1; }

// the holy sharks count high
inline int nhgSekolahHolySharksHigh()
    { return 3; }

// he swallows man-sized creatures whole
inline bool nhgSekolahSwallowWhole()
    { return true; }

// the sahuagin sacrifice their weak, crippled and aged to him
inline bool nhgSekolahFeedsWeakAged()
    { return true; }

// the 1-3 holy sharks always accompany sahuagin clerics
inline bool nhgSekolahHolySharks()
    { return true; }

// ---- Laogzed ----

// the acid skin damage low
inline int nhgLaogzedAcidLow()
    { return 3; }

// the acid skin damage high
inline int nhgLaogzedAcidHigh()
    { return 18; }

// the acid poison save modifier
inline int nhgLaogzedAcidSaveMod()
    { return -4; }

// the bite damage low
inline int nhgLaogzedBiteLow()
    { return 6; }

// the bite damage high
inline int nhgLaogzedBiteHigh()
    { return 60; }

// his oozing skin is an acidic poison that destroys weapons
inline bool nhgLaogzedAcidSkin()
    { return true; }

// he exhales a stinking cloud at will
inline bool nhgLaogzedStinkingCloud()
    { return true; }

// his clerics use only harmful spells
inline bool nhgLaogzedHarmfulSpellsOnly()
    { return true; }

// the Midwinter ritual of the Shedding of Skins
inline bool nhgLaogzedSheddingOfSkins()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Moradin minus 9 the best with his armor, Lolth minus
// 10 the raw best; Skerrit prints Variable (at least 2) - pinned as the floor
// 2 with the form cells riding consts; Lolth and Eadro the two dual prints,
// the drow paren minus 2 and the amorphous minus 6)
inline int nhgCbtAC(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return -9;
        case 3:
            return -4;
        case 4:
            return -3;
        case 5:
            return -10;
        case 6:
            return -2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return -2;
        case 10:
            return -2;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return -1;
        case 14:
            return -4;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return -1;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The alternate armor class cells (only the two dual prints carry one: Lolth
// the dark elf paren, Eadro the amorphous blob)
inline int nhgCbtACAlt(int b)
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
            return -2;
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
            return -6;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (Moradin 400 the high, Garl and Maglubiyet and Yondalla
// and Gruumsh 350, Lolth 66 the low - her high AC does the protecting)
inline int nhgCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 221;
        case 1:
            return 290;
        case 2:
            return 400;
        case 3:
            return 350;
        case 4:
            return 300;
        case 5:
            return 66;
        case 6:
            return 317;
        case 7:
            return 259;
        case 8:
            return 380;
        case 9:
            return 350;
        case 10:
            return 350;
        case 11:
            return 350;
        case 12:
            return 219;
        case 13:
            return 310;
        case 14:
            return 211;
        case 15:
            return 227;
        case 16:
            return 198;
        case 17:
            return 350;
        case 18:
            return 329;
        case 19:
            return 187;
        default:
            return 0;
        }
    }

// The primary move cells (Skerrit prints Variable - 0; Lolth the 1-inch web
// walk of the spider print; Sekolah the 36-inch swim)
inline int nhgCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 12;
        case 5:
            return 1;
        case 6:
            return 12;
        case 7:
            return 21;
        case 8:
            return 15;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 12;
        case 13:
            return 12;
        case 14:
            return 12;
        case 15:
            return 12;
        case 16:
            return 15;
        case 17:
            return 12;
        case 18:
            return 36;
        case 19:
            return 15;
        default:
            return 0;
        }
    }

// The secondary move cells (the duals: Corellon 15/18, Sashelas and Semuanya
// and Eadro the 12/24s, Lolth the 9-inch web strand rate)
inline int nhgCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 18;
        case 4:
            return 24;
        case 5:
            return 9;
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
            return 48;
        case 14:
            return 24;
        case 15:
            return 24;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (Garl and Yondalla the 3/2 prints; Vaprak 3; Eadro
// the 1 of the 1-or-8)
inline int nhgCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
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
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 1;
        default:
            return 0;
        }
    }

// The alternate-attack cells (Hruggek the 2 of the 1-or-2 claw pair; Garl and
// Yondalla the 3/2 halves; Eadro the 8 water-whips)
inline int nhgCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 2;
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
            return 8;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (Corellon 95 the high, Maglubiyet and Skoraeus
// and Sekolah the 50s, Laogzed 29 the low; Sashelas prints Standard (out of
// water) - 0 with the 100 percent underwater cell riding a const)
inline int nhgCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 35;
        case 2:
            return 60;
        case 3:
            return 95;
        case 4:
            return 0;
        case 5:
            return 70;
        case 6:
            return 75;
        case 7:
            return 45;
        case 8:
            return 50;
        case 9:
            return 50;
        case 10:
            return 25;
        case 11:
            return 75;
        case 12:
            return 55;
        case 13:
            return 55;
        case 14:
            return 78;
        case 15:
            return 72;
        case 16:
            return 50;
        case 17:
            return 75;
        case 18:
            return 47;
        case 19:
            return 29;
        default:
            return 0;
        }
    }

// The size inch cells (Sekolah the 35-foot shark 420, Skoraeus 360,
// Blibdoolpoolp 240, Moradin 240, Vaprak 180, Grolantor 300; the two fraction
// cells Yondalla 4 1/2 foot 54 and Kurtulmak 5 1/2 foot 66; Lolth prints L
// (M) and Rillifane See below - both 0 sentinels)
inline int nhgCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 144;
        case 1:
            return 0;
        case 2:
            return 240;
        case 3:
            return 84;
        case 4:
            return 84;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 300;
        case 8:
            return 360;
        case 9:
            return 132;
        case 10:
            return 48;
        case 11:
            return 54;
        case 12:
            return 66;
        case 13:
            return 240;
        case 14:
            return 144;
        case 15:
            return 84;
        case 16:
            return 180;
        case 17:
            return 120;
        case 18:
            return 420;
        case 19:
            return 120;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric levels (Eadro 20 the high, Sashelas 19; Lolth prints See below -
// the 99 pair with the drow 16th riding a const; Gruumsh and Laogzed the
// destructive-only and harmful-only prints ride bools)
inline int nhgClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 13;
        case 4:
            return 19;
        case 5:
            return 99;
        case 6:
            return 14;
        case 7:
            return 10;
        case 8:
            return 15;
        case 9:
            return 10;
        case 10:
            return 15;
        case 11:
            return 12;
        case 12:
            return 10;
        case 13:
            return 15;
        case 14:
            return 13;
        case 15:
            return 20;
        case 16:
            return 10;
        case 17:
            return 15;
        case 18:
            return 15;
        case 19:
            return 15;
        default:
            return 0;
        }
    }

// The druid levels (the in-each pairs: Skerrit 14, Moradin 14, Rillifane 14,
// Semuanya 13, Yondalla 12)
inline int nhgClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 14;
        case 2:
            return 14;
        case 3:
            return 13;
        case 4:
            return 0;
        case 5:
            return 99;
        case 6:
            return 14;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 13;
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
        default:
            return 0;
        }
    }

// The fighter level cells (Moradin 20 and Corellon the 20th ranger; Garl 10,
// Yondalla 10; the twelve As 16+ HD monster cells pin 16 - the as-monster-HD
// reading, not a fighter level)
inline int nhgClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 16;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return 0;
        case 7:
            return 16;
        case 8:
            return 16;
        case 9:
            return 16;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 16;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 16;
        case 18:
            return 16;
        case 19:
            return 16;
        default:
            return 0;
        }
    }

// The paladin level cells (none printed this section - all 0)
inline int nhgClsFighterHi(int b)
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
        default:
            return 0;
        }
    }

// The ranger levels (Corellon the Ranger Lord 20, Rillifane 15)
inline int nhgClsRanger(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 20;
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
        default:
            return 0;
        }
    }

// The magic-user levels (Moradin 19, Blibdoolpoolp 20, Skoraeus and Semuanya
// 12 and 15, Gruumsh 6; Lolth the 99 pair with the drow 14th riding a const;
// Sashelas prints Standard MR - the MU 12 is clean)
inline int nhgClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 19;
        case 3:
            return 20;
        case 4:
            return 12;
        case 5:
            return 99;
        case 6:
            return 12;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 20;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 6;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The illusionist levels (Garl 16, Yondalla 25 the high, Maglubiyet 6,
// Skerrit 10; the in-each pairs Corellon 20, Sashelas 12, Rillifane 12; Lolth
// the 99 pair)
inline int nhgClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 20;
        case 4:
            return 12;
        case 5:
            return 99;
        case 6:
            return 12;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 6;
        case 10:
            return 16;
        case 11:
            return 25;
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
        default:
            return 0;
        }
    }

// The thief levels (Garl 20 the master thief, Yondalla 15)
inline int nhgClsThief(int b)
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
            return 20;
        case 11:
            return 15;
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
        default:
            return 0;
        }
    }

// The assassin levels (Blibdoolpoolp 15, Kurtulmak 12, Maglubiyet 10, Gruumsh
// 8)
inline int nhgClsAssassin(int b)
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
            return 10;
        case 10:
            return 0;
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
            return 8;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The monk levels (none printed this section - all 0)
inline int nhgClsMonk(int b)
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
            return 10;
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
        default:
            return 0;
        }
    }

// The bard levels (Corellon 15, Skerrit 9, Sashelas 10, Garl 8; the Rillifane
// M/B 10 in-each pair)
inline int nhgClsBard(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 9;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 8;
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
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (Sekolah the bare 25 with no bracket; the fold-swap pair
// resolved by geometry: Moradin 25(+7,+14) and Corellon 21(+4,+9))
inline int nhgAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 21;
        case 4:
            return 25;
        case 5:
            return 21;
        case 6:
            return 19;
        case 7:
            return 25;
        case 8:
            return 25;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 19;
        case 12:
            return 22;
        case 13:
            return 21;
        case 14:
            return 23;
        case 15:
            return 21;
        case 16:
            return 25;
        case 17:
            return 22;
        case 18:
            return 25;
        case 19:
            return 21;
        default:
            return 0;
        }
    }

// The strength hit bonuses (Moradin 25 (+7,+14); Corellon 21 (+4,+9))
inline int nhgAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 4;
        case 4:
            return 7;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 7;
        case 8:
            return 7;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 4;
        case 16:
            return 7;
        case 17:
            return 4;
        case 18:
            return 0;
        case 19:
            return 4;
        default:
            return 0;
        }
    }

// The strength damage bonuses (Hruggek 23 (+5,+11); Vaprak 25 (+7,+14);
// Sekolah 0 - the bare S: 25 print)
inline int nhgAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 14;
        case 2:
            return 14;
        case 3:
            return 9;
        case 4:
            return 14;
        case 5:
            return 9;
        case 6:
            return 7;
        case 7:
            return 14;
        case 8:
            return 14;
        case 9:
            return 8;
        case 10:
            return 8;
        case 11:
            return 7;
        case 12:
            return 10;
        case 13:
            return 9;
        case 14:
            return 11;
        case 15:
            return 9;
        case 16:
            return 14;
        case 17:
            return 10;
        case 18:
            return 0;
        case 19:
            return 9;
        default:
            return 0;
        }
    }

// The intelligence cells (Corellon 25, Yondalla 25, Garl 23; Kurtulmak 19)
inline int nhgAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 19;
        case 2:
            return 23;
        case 3:
            return 25;
        case 4:
            return 20;
        case 5:
            return 21;
        case 6:
            return 23;
        case 7:
            return 14;
        case 8:
            return 19;
        case 9:
            return 19;
        case 10:
            return 23;
        case 11:
            return 25;
        case 12:
            return 19;
        case 13:
            return 20;
        case 14:
            return 20;
        case 15:
            return 22;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 18;
        case 19:
            return 18;
        default:
            return 0;
        }
    }

// The wisdom cells (Vaprak the 12-vs-18 divergence: the 2nd print 12 pinned,
// the L&L 18 noted; Kurtulmak 9 the low, Blibdoolpoolp 10, Grolantor 10)
inline int nhgAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 17;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 18;
        case 5:
            return 16;
        case 6:
            return 19;
        case 7:
            return 10;
        case 8:
            return 20;
        case 9:
            return 17;
        case 10:
            return 22;
        case 11:
            return 25;
        case 12:
            return 9;
        case 13:
            return 10;
        case 14:
            return 19;
        case 15:
            return 18;
        case 16:
            return 12;
        case 17:
            return 18;
        case 18:
            return 18;
        case 19:
            return 17;
        default:
            return 0;
        }
    }

// The dexterity cells (Hruggek dex not printed - the tsv geometry shows the
// bare 36px inter-cell gap between W and C; Rillifane 25, Corellon 25,
// Yondalla 25)
inline int nhgAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 23;
        case 2:
            return 21;
        case 3:
            return 25;
        case 4:
            return 21;
        case 5:
            return 21;
        case 6:
            return 25;
        case 7:
            return 19;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 24;
        case 11:
            return 25;
        case 12:
            return 19;
        case 13:
            return 21;
        case 14:
            return 20;
        case 15:
            return 22;
        case 16:
            return 17;
        case 17:
            return 23;
        case 18:
            return 19;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The constitution cells (Moradin 25, Sekolah 25; Lolth 21)
inline int nhgAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 24;
        case 2:
            return 25;
        case 3:
            return 21;
        case 4:
            return 21;
        case 5:
            return 21;
        case 6:
            return 21;
        case 7:
            return 20;
        case 8:
            return 25;
        case 9:
            return 22;
        case 10:
            return 22;
        case 11:
            return 23;
        case 12:
            return 19;
        case 13:
            return 23;
        case 14:
            return 22;
        case 15:
            return 21;
        case 16:
            return 19;
        case 17:
            return 24;
        case 18:
            return 25;
        case 19:
            return 19;
        default:
            return 0;
        }
    }

// The charisma cells (the negatives: Maglubiyet -2, Laogzed -2, Vaprak -1;
// Lolth 3 with the drow-form 23 riding a const; Gruumsh 8, Laogzed and
// Maglubiyet the worshiper parens ride consts)
inline int nhgAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 21;
        case 2:
            return 19;
        case 3:
            return 25;
        case 4:
            return 23;
        case 5:
            return 3;
        case 6:
            return 24;
        case 7:
            return 16;
        case 8:
            return 17;
        case 9:
            return -2;
        case 10:
            return 24;
        case 11:
            return 22;
        case 12:
            return 19;
        case 13:
            return 11;
        case 14:
            return 7;
        case 15:
            return 19;
        case 16:
            return -1;
        case 17:
            return 8;
        case 18:
            return 16;
        case 19:
            return -2;
        default:
            return 0;
        }
    }

// The psionic ability cells (none printed with a score - the Lolth See below
// rides consts and bools)
inline int nhgAbiPsi(int b)
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
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinals 0-19 in print order
inline int nhgRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print pages 105-112
inline int nhgRosPage(int b)
    {
        switch (b) {
        case 0:
            return 105;
        case 1:
            return 105;
        case 2:
            return 106;
        case 3:
            return 106;
        case 4:
            return 107;
        case 5:
            return 107;
        case 6:
            return 108;
        case 7:
            return 108;
        case 8:
            return 108;
        case 9:
            return 109;
        case 10:
            return 109;
        case 11:
            return 109;
        case 12:
            return 110;
        case 13:
            return 110;
        case 14:
            return 111;
        case 15:
            return 111;
        case 16:
            return 111;
        case 17:
            return 112;
        case 18:
            return 112;
        case 19:
            return 112;
        default:
            return 0;
        }
    }

// The alignment codes (0 LG 2 CG 4 N 6 LE 7 NE 8 CE; Skerrit N-tending-CG,
// Blibdoolpoolp NE-chaotic, Semuanya and Eadro the pure neutrals)
inline int nhgRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 4;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 8;
        case 6:
            return 2;
        case 7:
            return 8;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 6;
        case 13:
            return 7;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 8;
        case 17:
            return 6;
        case 18:
            return 6;
        case 19:
            return 8;
        default:
            return 0;
        }
    }

// The rank codes (0 lesser 1 greater 3 demigod; the six greater and the two
// demigods)
inline int nhgRosRank(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
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
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 3;
        default:
            return 0;
        }
    }

// The psionic class cells (I Corellon, Rillifane, Sekolah; II Semuanya,
// Eadro; III Sashelas, Blibdoolpoolp; V Skerrit, Gruumsh; VI Moradin,
// Grolantor, Skoraeus, Maglubiyet, Kurtulmak, Vaprak; 0 = Nil or See below)
inline int nhgRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 6;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 6;
        case 17:
            return 5;
        case 18:
            return 1;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

// The plane codes (1 Pandemonium, 2 Happy Hunting Grounds, 3 Seven Heavens, 4
// Olympus, 5 Abyss, 6 Tarterus, 7 Nine Hells, 8 Twin Paradises, 9 Prime
// Material, 10 Concordant Opposition, 11 Elemental Plane of Water)
inline int nhgRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 9;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 3;
        case 12:
            return 7;
        case 13:
            return 11;
        case 14:
            return 10;
        case 15:
            return 10;
        case 16:
            return 5;
        case 17:
            return 7;
        case 18:
            return 7;
        case 19:
            return 5;
        default:
            return 0;
        }
    }

// The printed-damage flags (seventeen rows; Skerrit and Rillifane and
// Yondalla the Variable and See below and by-weapon rows carry 0)
inline int nhgRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
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
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (the six rows printing an Nth-level-in-each pair:
// Skerrit, Corellon, Sashelas, Rillifane, Yondalla, Semuanya)
inline int nhgRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
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
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
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
        default:
            return 0;
        }
    }

// ---- the R864 census ----

// twenty stat-block rows walk the section
inline int nhgBeingCount()
    { return 20; }

// the four grids (combat, class, ability, roster)
inline int nhgTableCount()
    { return 4; }

// no chains this round
inline int nhgChainCount()
    { return 0; }

// zero registry defs touched - the floor holds
inline int nhgRegistryFloor()
    { return 995; }

// the combat grid rows
inline int nhgCbtRows()
    { return 20; }

// the class grid rows
inline int nhgClsRows()
    { return 20; }

// the ability grid rows
inline int nhgAbiRows()
    { return 20; }

// the roster grid rows
inline int nhgRosRows()
    { return 20; }

// six greater gods: Moradin, Corellon, Maglubiyet, Garl, Yondalla, Gruumsh
inline int nhgGreaterCount()
    { return 6; }

// twelve lesser gods and goddesses
inline int nhgLesserCount()
    { return 12; }

// two demigods: Vaprak and Laogzed
inline int nhgDemigodCount()
    { return 2; }

// eleven distinct planes printed across the roster
inline int nhgPlaneCount()
    { return 11; }

// four Nine Hells rows: Maglubiyet, Kurtulmak, Gruumsh, Sekolah
inline int nhgNineHellsCount()
    { return 4; }

// three Olympus rows: Corellon, Sashelas, Rillifane
inline int nhgOlympusCount()
    { return 3; }

// three Abyss rows: Lolth, Vaprak, Laogzed
inline int nhgAbyssCount()
    { return 3; }

// two Seven Heavens rows: Moradin and Yondalla
inline int nhgSevenHeavensCount()
    { return 2; }

// two Concordant Opposition rows: Semuanya and Eadro
inline int nhgConcordantCount()
    { return 2; }

// twelve As 16+ HD monster fighter cells pin 16
inline int nhgAsMonsterHDCount()
    { return 12; }

// fifteen rows print a psionic class
inline int nhgPsionicRowCount()
    { return 15; }

// five rows print Nil or See below psionics
inline int nhgPsiNilCount()
    { return 5; }

// six rows print an in-each class pair
inline int nhgInEachCount()
    { return 6; }

// two fraction size cells: Yondalla 4 1/2 foot, Kurtulmak 5 1/2 foot
inline int nhgFractionSizeCount()
    { return 2; }

// two dual armor class prints: Lolth and Eadro
inline int nhgDualACCount()
    { return 2; }

// five dual move prints: Corellon, Sashelas, Lolth, Semuanya, Eadro
inline int nhgDualMoveCount()
    { return 5; }

// seventeen printed-damage formula rows
inline int nhgDmgFixedCount()
    { return 17; }

// seven See below cells: Lolth clr/mu/psionic, Skerrit attacks, Rillifane
// dmg/attacks/size
inline int nhgSeeBelowCount()
    { return 7; }

}   // namespace rules
