// =========================================================================================
// Adnd1 - rules/nrs.h
// the Norse mythos - the D&DG walk round seventeen, print pp. 113-124:
// thirty-five stat-block rows - the eleven greater gods (Odin, Balder,
// Forseti, Frey, Freya, Frigga, Heimdall, Hel, Loki, Thor, Tyr), the ten
// lesser (Aegir, Bragi, Idun, Magni, Modi, Sif, Surtur, Thrym, Uller, Vidar),
// the four no-rank class-grid rows (Fjalar, Skirnir, the Norns, the
// Valkyries) and the eleven MM-style companion and monster blocks (Hugin and
// Munin, Sleipner, Freke and Gere, the Fenris Wolf, Fossergrim, Blodug-Hofi,
// Gullin-Bursti, Garm, Jormungandr, the Thor goats) - plus the Ragnarok and
// sacrifice doctrine of the intro.
// census 787 -> 788.
//
// primary ink: the extract/ddg tesseract pass (pNNN_full.txt + pNNN_tsv.tsv,
// print = pdf - 1, pages 114-125; the second printing) with the tsv x-y
// geometry as the fold-swap, dropped-glyph and not-printed-cell arbiter; the
// collation voice: the 1eonline L&L transcription (norse.htm and the
// per-being pages, the R853 parity voice). The adjudications: the THOR BARE 4
// armor class (no minus glyph on the tsv line, the L&L reads minus 4, pinned
// as printed with the eyeball flag), the Hel +38 damage garble adjudicated to
// 8 by the strength-bonus arithmetic and the L&L voice, the half-foot size
// cells (Odin, Hel, Tyr 78 and the Valkyries 66 - the half glyph garbles to
// )4 and %), the Hugin 1 over 48 move and the merged V1815 XP glyph (VI/815,
// the MM level VI base), the Frey II pipe at width 15, the Thrym 300 hit
// points from the L&L voice (the print cell occluded by the plate
// illustration), and the divergent Aegir and Freya armor classes pinned by
// the print.
//
namespace rules {

// ---- the Norse doctrine ----

// the section closes on print p. 124 (Vidar, the Valkyries)
inline int nrsPrintEnd()
    { return 124; }

// the section opens on print p. 113 (Odin)
inline int nrsPrintStart()
    { return 113; }

// the Norse mythos round: the D&DG walk round seventeen
inline int nrsRound()
    { return 865; }

// ---- Odin ----

// Odin telepathy has a range of 300 miles
inline int nrsOdinTelepathyMiles()
    { return 300; }

// Odin inspires berserker rages within 30 yards
inline int nrsOdinBerserkYards()
    { return 30; }

// allies within 20 yards gain fighting levels
inline int nrsOdinAllyYards()
    { return 20; }

// the ally gain is 4 levels of fighting ability
inline int nrsOdinAllyLevels()
    { return 4; }

// Odin gaze paralysis save at minus 4, one being per round
inline int nrsOdinGazeSaveMod()
    { return -4; }

// Gungnir the spear is +5
inline int nrsOdinSpearPlus()
    { return 5; }

// Gungnir held aloft strikes fear within 20 yards
inline int nrsOdinFearYards()
    { return 20; }

// each Gungnir prayer touch takes 1 hit point from Odin
inline int nrsOdinTouchHpCost()
    { return 1; }

// same-alignment Gungnir touchers lose 50 percent of original hit points
inline int nrsOdinSameAlignHpPct()
    { return 50; }

// Odin bow is +3 composite recurved
inline int nrsOdinBowPlus()
    { return 3; }

// the bow fires 10 +3 arrows per melee round
inline int nrsOdinBowArrows()
    { return 10; }

// the golden Rune Wand has five powers
inline int nrsOdinWandPowers()
    { return 5; }

// the wand summons 1-4 elementals once per week, low
inline int nrsOdinWandElementalLow()
    { return 1; }

// the wand summons 1-4 elementals once per week, high
inline int nrsOdinWandElementalHigh()
    { return 4; }

// the wand stores 12 spells of Odin choice
inline int nrsOdinWandSpells()
    { return 12; }

// the wand drains 6 energy levels from a grabber
inline int nrsOdinWandDrainLevels()
    { return 6; }

// the wand drains 100 hit points from a grabber
inline int nrsOdinWandDrainHp()
    { return 100; }

// Odin wears +5 corselet of mail and +5 helm
inline int nrsOdinArmorPlus()
    { return 5; }

// Draupnir produces a 30,000 gold piece twin every night
inline int nrsOdinDraupnirGp()
    { return 30000; }

// healing anyone forces a sleep of 1-10 days, low
inline int nrsOdinHealSleepLow()
    { return 1; }

// healing anyone forces a sleep of 1-10 days, high
inline int nrsOdinHealSleepHigh()
    { return 10; }

// Odin cannot raise the dead
inline bool nrsOdinCannotRaiseDead()
    { return true; }

// different-alignment Gungnir touchers are polymorphed into normal ants, no
// save
inline bool nrsOdinAntsPolymorph()
    { return true; }

// the all-seeing throne Hlidskialf is an unlimited crystal ball with
// clairaudience
inline bool nrsOdinHlidskialf()
    { return true; }

// Odin walks among men as an old man on a mangy horse
inline bool nrsOdinOldManGuise()
    { return true; }

// Odin keeps a pair of ravens, a pair of wolves and a magical horse
inline bool nrsOdinCompanionTrio()
    { return true; }

// the fear works only when Odin holds Gungnir aloft, as the fear symbol
inline bool nrsOdinGungnirFear()
    { return true; }

// Odin-allowed Gungnir touchers get a double effect prayer for the battle
inline bool nrsOdinPrayerDouble()
    { return true; }

// the Rune Wand is an artifact, undetectable by magical detection
inline bool nrsOdinRuneWandArtifact()
    { return true; }

// the wand causes instantaneous death to any mortal touching it
inline bool nrsOdinRuneWandDeath()
    { return true; }

// the curing power forces a temporary coma nothing can wake
inline bool nrsOdinHealingComa()
    { return true; }

// ---- Hugin and Munin ----

// two ravens: Hugin and Munin, Thought and Memory
inline int nrsHuginCount()
    { return 2; }

// 30 hit points each
inline int nrsHuginHpEach()
    { return 30; }

// the XP level VI (the print merges the roman into V1815)
inline int nrsHuginXpRoman()
    { return 6; }

// the XP base 815, the MM level VI base value
inline int nrsHuginXpBase()
    { return 815; }

// the ravens attack as 7 hit dice monsters
inline int nrsHuginAttackHd()
    { return 7; }

// the beak strike 1-8, low
inline int nrsHuginDmgLow()
    { return 1; }

// the beak strike 1-8, high
inline int nrsHuginDmgHigh()
    { return 8; }

// the printed 1 over 48 move cell is odd ink - both voices read it, pinned as
// printed
inline bool nrsHuginOddMovePrint()
    { return true; }

// the ravens teleport from plane to plane
inline bool nrsHuginPlaneTeleport()
    { return true; }

// Odin sees and hears through his spies
inline bool nrsHuginSeeHearThrough()
    { return true; }

// the ravens carry verbal messages for Odin
inline bool nrsHuginVerbalMessages()
    { return true; }

// ---- Sleipner ----

// the XP level X
inline int nrsSleipnerXpRoman()
    { return 10; }

// the XP base 20,600
inline int nrsSleipnerXpBase()
    { return 20600; }

// Sleipner fights as a 16+ hit dice monster
inline int nrsSleipnerFightHd()
    { return 16; }

// the fore-hoove kick 2-20, low
inline int nrsSleipnerKickLow()
    { return 2; }

// the fore-hoove kick 2-20, high
inline int nrsSleipnerKickHigh()
    { return 20; }

// the bite 1-10, low
inline int nrsSleipnerBiteLow()
    { return 1; }

// the bite 1-10, high
inline int nrsSleipnerBiteHigh()
    { return 10; }

// only Odin rides Sleipner, save Odin-ordered one-ride mercy trips
inline bool nrsSleipnerOdinOnly()
    { return true; }

// only one being per round can attack Sleipner rider
inline bool nrsSleipnerOneAttacker()
    { return true; }

// Sleipner can be ridden in any medium - air, earth, water and the like
inline bool nrsSleipnerAnyMedium()
    { return true; }

// Sleipner will only obey one master at a time
inline bool nrsSleipnerOneMaster()
    { return true; }

// a Valkyrie may pick up a fine dead hero on Sleipner
inline bool nrsSleipnerValkyrieRide()
    { return true; }

// ---- Freke and Gere ----

// 75 hit points each
inline int nrsFrekeHpEach()
    { return 75; }

// the XP level IX
inline int nrsFrekeXpRoman()
    { return 9; }

// the XP base 8,875
inline int nrsFrekeXpBase()
    { return 8875; }

// the wolves attack as 16+ hit dice monsters
inline int nrsFrekeFightHd()
    { return 16; }

// the bite 2-20, low
inline int nrsFrekeDmgLow()
    { return 2; }

// the bite 2-20, high
inline int nrsFrekeDmgHigh()
    { return 20; }

// the wolves punish humans who aid the giants against the gods
inline bool nrsFrekePunishers()
    { return true; }

// the wolves see any hidden object and sense all things magical
inline bool nrsFrekeSenseMagic()
    { return true; }

// the wolves travel the planes for Odin and report the worlds
inline bool nrsFrekeSeeHidden()
    { return true; }

// ---- Aegir ----

// the maiden-club strike 4-40, low
inline int nrsAegirDmgLow()
    { return 4; }

// the maiden-club strike 4-40, high
inline int nrsAegirDmgHigh()
    { return 40; }

// the printed +11 damage bonus
inline int nrsAegirDmgBonus()
    { return 11; }

// in the sea Aegir is 60 feet tall and fights the Aesir and Vanir trespassers
inline int nrsAegirSeaFormFeet()
    { return 60; }

// Aegir is neither Aesir nor Vanir but related to the giants
inline bool nrsAegirGiantKin()
    { return true; }

// those meeting him in battle under the water are slowed, no saving throw
inline bool nrsAegirSlowNoSave()
    { return true; }

// Aegir overturns ships that have not sacrificed and drags them down
inline bool nrsAegirOverturnsShips()
    { return true; }

// Aegir lives in a great underwater castle with his wife Ran
inline bool nrsAegirCastleWithRan()
    { return true; }

// ---- Balder ----

// the +2 sword strike 3-30, low
inline int nrsBalderDmgLow()
    { return 3; }

// the +2 sword strike 3-30, high
inline int nrsBalderDmgHigh()
    { return 30; }

// the printed +10 damage bonus
inline int nrsBalderDmgBonus()
    { return 10; }

// the Balder sword is +2
inline int nrsBalderSwordPlus()
    { return 2; }

// Balder can grant 2 charisma points once in a being life
inline int nrsBalderCharismaGift()
    { return 2; }

// the 1 percent chance he asks a 15-plus-charisma female to serve him
inline int nrsBalderServePct()
    { return 1; }

// the charisma floor of the serving females
inline int nrsBalderMinCha()
    { return 15; }

// Balder cannot be harmed by any weapon without mistletoe in it
inline bool nrsBalderMistletoeOnly()
    { return true; }

// mortal females looking on him save or become enchanted, then devotion-save
inline bool nrsBalderEnchantGaze()
    { return true; }

// Balder lives in his hall of Breidablik in Gladsheim
inline bool nrsBalderHallBreidablik()
    { return true; }

// ---- Bragi ----

// the strike 2-20, low
inline int nrsBragiDmgLow()
    { return 2; }

// the strike 2-20, high
inline int nrsBragiDmgHigh()
    { return 20; }

// the printed +11 damage bonus
inline int nrsBragiDmgBonus()
    { return 11; }

// violent minds within 30 yards are overcome by the song, no save
inline int nrsBragiSongYards()
    { return 30; }

// the song power works up to 5 hours at a time per creature
inline int nrsBragiSongHours()
    { return 5; }

// the Harp of Calm stops fighting or quarreling for 7 days
inline int nrsBragiHarpDays()
    { return 7; }

// the 5 percent chance a first-performance bard is granted a great legend
inline int nrsBragiLegendPct()
    { return 5; }

// the great-legend grant needs a crowd of more than 50 beings
inline int nrsBragiCrowdMin()
    { return 50; }

// Bragi cannot have violence on his mind while singing
inline bool nrsBragiNoViolence()
    { return true; }

// the harp has all magical bard instrument powers plus uncharm
inline bool nrsBragiHarpUncharm()
    { return true; }

// the harp can stop any creature from attacking for a short time
inline bool nrsBragiHarpStopsAttack()
    { return true; }

// ---- the Fenris Wolf ----

// the bite 9-90, low
inline int nrsFenrisDmgLow()
    { return 9; }

// the bite 9-90, high
inline int nrsFenrisDmgHigh()
    { return 90; }

// the XP level X
inline int nrsFenrisXpRoman()
    { return 10; }

// the XP base 33,200
inline int nrsFenrisXpBase()
    { return 33200; }

// a +4 or better weapon to hit
inline int nrsFenrisWeaponPlus()
    { return 4; }

// a bite totaling more than half the victim hit points swallows him whole
inline bool nrsFenrisSwallowHalf()
    { return true; }

// the dwarves forged the silken golden chain from thoughts and concepts,
// unbreakable until Ragnarok
inline bool nrsFenrisGleipnirChain()
    { return true; }

// the wolf lived in Asgard by the technicality sparing divine offspring
inline bool nrsFenrisAsgardLoophole()
    { return true; }

// ---- Fjalar ----

// the gauntlet punch 2-20, low
inline int nrsFjalarDmgLow()
    { return 2; }

// the gauntlet punch 2-20, high
inline int nrsFjalarDmgHigh()
    { return 20; }

// the magical iron gauntlets give +3 to hit
inline int nrsFjalarGauntletPlus()
    { return 3; }

// Fjalar cannot be hit by +2 or better weapons - he makes them shun his skin
inline bool nrsFjalarShunPlusTwo()
    { return true; }

// Fjalar is the battle leader of the dwarves
inline bool nrsFjalarBattleLeader()
    { return true; }

// Fjalar is a dwarven hero of the Durin race
inline bool nrsFjalarDurinRace()
    { return true; }

// ---- Forseti ----

// the sword strike 1-10, low
inline int nrsForsetiDmgLow()
    { return 1; }

// the sword strike 1-10, high
inline int nrsForsetiDmgHigh()
    { return 10; }

// the printed +12 damage bonus
inline int nrsForsetiDmgBonus()
    { return 12; }

// the sword always hits a being that has lied in the last 7 days or is
// chaotic
inline int nrsForsetiLieDays()
    { return 7; }

// Forseti detects lies and is called on when Odin cannot be impartial
inline bool nrsForsetiDetectLies()
    { return true; }

// evil beings suffer -1 on their chance to hit Forseti
inline bool nrsForsetiEvilMinusOne()
    { return true; }

// Forseti attacks evil beings at +2 both to hit and damage
inline bool nrsForsetiEvilPlusTwo()
    { return true; }

// the son of Balder has never been known to lie; his hall Glitner is gold and
// silver
inline bool nrsForsetiNeverLies()
    { return true; }

// ---- Fossergrim ----

// the printed 5 HD cell (hit dice, not points)
inline int nrsFossergrimHd()
    { return 5; }

// the XP level V
inline int nrsFossergrimXpRoman()
    { return 5; }

// the XP base 320, the MM level V base value
inline int nrsFossergrimXpBase()
    { return 320; }

// the XP 5 per hit point rider
inline int nrsFossergrimXpPerHp()
    { return 5; }

// a fossergrim cannot live more than a mile from its waterfall
inline int nrsFossergrimMileLimit()
    { return 1; }

// regeneration 5 points per melee round in splashing water
inline int nrsFossergrimRegen()
    { return 5; }

// in battle in the water they cannot miss any standing being
inline bool nrsFossergrimCannotMissWater()
    { return true; }

// their offspring by bathing maidens are always male and find their own falls
inline bool nrsFossergrimMaleOffspring()
    { return true; }

// they appear as normal men in chainmail until attacked or forced from the
// fall
inline bool nrsFossergrimWaterfallBound()
    { return true; }

// ---- Frey ----

// the +4 two-handed sword 2-20, low
inline int nrsFreyDmgLow()
    { return 2; }

// the +4 two-handed sword 2-20, high
inline int nrsFreyDmgHigh()
    { return 20; }

// the printed +12 damage bonus
inline int nrsFreyDmgBonus()
    { return 12; }

// the Frey two-handed sword is +4
inline int nrsFreySwordPlus()
    { return 4; }

// the sword does 10-100 to fire giants, low
inline int nrsFreyFireGiantLow()
    { return 10; }

// the sword does 10-100 to fire giants, high
inline int nrsFreyFireGiantHigh()
    { return 100; }

// the sword does 5-50 to all other giants, low
inline int nrsFreyOtherGiantLow()
    { return 5; }

// the sword does 5-50 to all other giants, high
inline int nrsFreyOtherGiantHigh()
    { return 50; }

// Skidbladnir travels at 60 and holds all the gods and their mounts
inline int nrsFreyShipRate()
    { return 60; }

// Freya uses a +3 frost brand
inline int nrsFreyaFrostPlus()
    { return 3; }

// Freya commands all fire spells as a 30th level caster
inline int nrsFreyaFireSpellLevel()
    { return 30; }

// her chariot cats are AC 5
inline int nrsFreyaCatAc()
    { return 5; }

// the cats are 5 hit dice
inline int nrsFreyaCatHd()
    { return 5; }

// the cats have 30 hit points each
inline int nrsFreyaCatHp()
    { return 30; }

// the cat paw 1-8, low
inline int nrsFreyaCatPawLow()
    { return 1; }

// the cat paw 1-8, high
inline int nrsFreyaCatPawHigh()
    { return 8; }

// the cat rear 1-12, low
inline int nrsFreyaCatRearLow()
    { return 1; }

// the cat rear 1-12, high
inline int nrsFreyaCatRearHigh()
    { return 12; }

// the chariot moves at 18
inline int nrsFreyaChariotMove()
    { return 18; }

// Brisingamen is worth 1 million gold pieces
inline int nrsFreyaNecklaceGp()
    { return 1000000; }

// the falcon cloak flies at 48
inline int nrsFreyaCloakRate()
    { return 48; }

// the ship folds to a 1-inch cube for the god pocket
inline bool nrsFreyShipFolds()
    { return true; }

// Frey is a weather deity and controls all manner of storms and calms
inline bool nrsFreyWeatherControl()
    { return true; }

// Frey the Vanir is god of Fairyland and commands all the elves of Alfheim
inline bool nrsFreyElfCommand()
    { return true; }

// Freya can remove any curse with a touch of her hand
inline bool nrsFreyaRemoveCurse()
    { return true; }

// she travels in falcon guise and can shape change into any bird form
inline bool nrsFreyaFalconGuise()
    { return true; }

// Freya is the leader of the Valkyries and accompanies them to choose the
// slain
inline bool nrsFreyaValkyrieLeader()
    { return true; }

// no avian or fire attack can hurt Freya
inline bool nrsFreyaAvianFireImmune()
    { return true; }

// Brisingamen glows when a lie is told in its presence
inline bool nrsFreyaNecklaceLieGlow()
    { return true; }

// Freya is a Vanir, the twin sister of Frey
inline bool nrsFreyaVanirTwin()
    { return true; }

// ---- Blodug-Hofi ----

// the bite 1-6, low
inline int nrsBlodugBiteLow()
    { return 1; }

// the bite 1-6, high
inline int nrsBlodugBiteHigh()
    { return 6; }

// the fore-hoove kick 1-10, low
inline int nrsBlodugKickLow()
    { return 1; }

// the fore-hoove kick 1-10, high
inline int nrsBlodugKickHigh()
    { return 10; }

// +4 on saves vs fire attacks
inline int nrsBlodugFireSavePlus()
    { return 4; }

// the fire-resistant coat subtracts 1 point per die of damage
inline int nrsBlodugFireDieSave()
    { return 1; }

// the daylight glow kills undead with a light beam within 200 yards
inline int nrsBlodugUndeadYards()
    { return 200; }

// the horse fights as an 11 hit dice monster
inline int nrsBlodugFightHd()
    { return 11; }

// the XP level VIII
inline int nrsBlodugXpRoman()
    { return 8; }

// the XP base 4,500
inline int nrsBlodugXpBase()
    { return 4500; }

// Blodug-Hofi glows with the light of day in any battle
inline bool nrsBlodugDaylightGlow()
    { return true; }

// if Frey is down the horse stays near to defend him unto death
inline bool nrsBlodugDefendMaster()
    { return true; }

// the horse teleports at will
inline bool nrsBlodugTeleportWill()
    { return true; }

// ---- Gullin-Bursti ----

// the tusk strike 2-20, low
inline int nrsGullinDmgLow()
    { return 2; }

// the tusk strike 2-20, high
inline int nrsGullinDmgHigh()
    { return 20; }

// the boar normally regenerates 1 hit point per round
inline int nrsGullinRegen()
    { return 1; }

// the XP level X
inline int nrsGullinXpRoman()
    { return 10; }

// the XP base 22,300
inline int nrsGullinXpBase()
    { return 22300; }

// the boar attacks as a 16+ hit dice monster
inline int nrsGullinFightHd()
    { return 16; }

// eaten by day, the boar regenerates at night from bones and skin if none are
// broken
inline bool nrsGullinNightRegen()
    { return true; }

// with a god on it the boar teleports where the god wills
inline bool nrsGullinTeleportWithGod()
    { return true; }

// Frey uses the golden boar to pull his war chariot
inline bool nrsGullinChariotPuller()
    { return true; }

// ---- Skirnir ----

// Skirnir wears +4 chainmail
inline int nrsSkirnirMailPlus()
    { return 4; }

// Skirnir wields a +3 two-handed sword
inline int nrsSkirnirSwordPlus()
    { return 3; }

// a split second before a death blow Skirnir is teleported to Alfheim
inline bool nrsSkirnirAutoTeleport()
    { return true; }

// the shield-man is loyal to Frey and always at his side in battle
inline bool nrsSkirnirLoyalShieldman()
    { return true; }

// ---- Frigga ----

// ten named Frigga handmaidens: Fulla, Vara, Lofn, Vor, Gna, Eira, Hlin, Syn,
// Vjofn, Snotra
inline int nrsFriggaMaidenNames()
    { return 10; }

// Frigga controls all forms of weather
inline bool nrsFriggaWeatherControl()
    { return true; }

// her black opal necklace charms a being to do nothing but flatter her, save
// applicable
inline bool nrsFriggaNecklaceCharm()
    { return true; }

// Frigga can view any area with a breeze blowing through it
inline bool nrsFriggaSeesBreezeAreas()
    { return true; }

// in battle she shape changes into creatures and fights with their powers
inline bool nrsFriggaShapeChange()
    { return true; }

// she starts with dragon forms and goes to avian forms toward the end of a
// battle
inline bool nrsFriggaDragonToAvian()
    { return true; }

// she spins flax into gold for Odin clothes
inline bool nrsFriggaFlaxGold()
    { return true; }

// her handmaidens are Valkyries
inline bool nrsFriggaHandmaidenValkyries()
    { return true; }

// ---- Garm ----

// the bite 6-60, low
inline int nrsGarmDmgLow()
    { return 6; }

// the bite 6-60, high
inline int nrsGarmDmgHigh()
    { return 60; }

// the XP level X
inline int nrsGarmXpRoman()
    { return 10; }

// the XP base 26,200
inline int nrsGarmXpBase()
    { return 26200; }

// Garm attacks as a 16+ hit dice monster
inline int nrsGarmFightHd()
    { return 16; }

// Garm travels with a pack of 20 dire wolves
inline int nrsGarmWolfPack()
    { return 20; }

// beings of the 6th level or less flee in terror automatically
inline int nrsGarmFleeLevel()
    { return 6; }

// higher-level beings save vs fear at minus 4
inline int nrsGarmFearSaveMod()
    { return -4; }

// Garm guards the gateway to the land of the dead
inline bool nrsGarmHelGateGuard()
    { return true; }

// Garm obeys the laws of Hel and travels all planes when Hel is out
// collecting the dead
inline bool nrsGarmTravelsPlanes()
    { return true; }

// its treasure is the goods of those who failed to pass
inline bool nrsGarmTreasureOfTheDead()
    { return true; }

// ---- Heimdall ----

// the Hofud strike 3-30, low
inline int nrsHeimdallDmgLow()
    { return 3; }

// the Hofud strike 3-30, high
inline int nrsHeimdallDmgHigh()
    { return 30; }

// the printed +14 strength bonus
inline int nrsHeimdallDmgBonus()
    { return 14; }

// the +3 white armor acts as a gem of brightness
inline int nrsHeimdallArmorPlus()
    { return 3; }

// Heimdall always attacks with surprise
inline bool nrsHeimdallAlwaysSurprise()
    { return true; }

// Heimdall is never surprised
inline bool nrsHeimdallNeverSurprised()
    { return true; }

// his eyesight is an unlimited range and duration clairvoyance
inline bool nrsHeimdallUnlimitedClairvoyance()
    { return true; }

// Hofud is a vorpal weapon
inline bool nrsHeimdallVorpalHofud()
    { return true; }

// Hofud is also a sword of frost giant slaying
inline bool nrsHeimdallFrostSlaying()
    { return true; }

// his horn Gjaller is the alarm of Asgard, blown for the frost giants and for
// visitors
inline bool nrsHeimdallHornGjaller()
    { return true; }

// Heimdall is the sworn enemy of Loki, who mocks his guardianship
inline bool nrsHeimdallLokiEnmity()
    { return true; }

// ---- Hel ----

// the sword strike 5-50, low
inline int nrsHelDmgLow()
    { return 5; }

// the sword strike 5-50, high
inline int nrsHelDmgHigh()
    { return 50; }

// the +8 bonus - the print shows the +38 garble at conf 28, the ability grid
// arithmetic and the L&L voice agree on 8
inline int nrsHelDmgBonus()
    { return 8; }

// her sword is +3 and also causes disease when it hits
inline int nrsHelSwordPlus()
    { return 3; }

// her withering aura radius is 90 yards
inline int nrsHelWitherYards()
    { return 90; }

// the aura subtracts 20 hit points, magic save applicable
inline int nrsHelWitherHp()
    { return 20; }

// her plagues take away 5 hit points per round until dead or cured
inline int nrsHelPlagueHp()
    { return 5; }

// the +3 sword causes disease whenever it hits
inline bool nrsHelSwordDisease()
    { return true; }

// Hel is totally impervious to all physical weaponry
inline bool nrsHelImperviousWeapons()
    { return true; }

// her body is white on the left, jet black on the right, the left face blank
inline bool nrsHelHalfWhiteHalfBlack()
    { return true; }

// she rides a white spectral three-legged horse
inline bool nrsHelSpectralHorse()
    { return true; }

// she lives in a dismal palace in the Niflheim area of Hades
inline bool nrsHelNiflheimPalace()
    { return true; }

// ---- Jormungandr ----

// the head has 300 hit points - 300 or more in one round kills it
inline int nrsJormHeadHp()
    { return 300; }

// the printed L (25,000 miles long) cell - the size col carries the 0
// sentinel
inline int nrsJormMiles()
    { return 25000; }

// the bite 5-50, low
inline int nrsJormBiteLow()
    { return 5; }

// the bite 5-50, high
inline int nrsJormBiteHigh()
    { return 50; }

// the constriction 10-100, low
inline int nrsJormConstrictionLow()
    { return 10; }

// the constriction 10-100, high
inline int nrsJormConstrictionHigh()
    { return 100; }

// the venom save at minus 5
inline int nrsJormPoisonSaveMod()
    { return -5; }

// an unsaved bite kills within two melee rounds
inline int nrsJormDeathRounds()
    { return 2; }

// at its death the venom spews - save within 50 feet or die
inline int nrsJormVenomCloudFeet()
    { return 50; }

// the XP level X
inline int nrsJormXpRoman()
    { return 10; }

// the XP base 55,000 (the print drops the slash: X 55,000)
inline int nrsJormXpBase()
    { return 55000; }

// it attacks as a 16+ HD monster
inline int nrsJormFightHd()
    { return 16; }

// the body hit points are infinite - only the head is vulnerable
inline bool nrsJormBodyInfinite()
    { return true; }

// the serpent shifts its body and locates its head anywhere in one melee
// round
inline bool nrsJormHeadAnywhere()
    { return true; }

// head and body regenerate all lost hit points the next melee round, even if
// severed
inline bool nrsJormRegenNextRound()
    { return true; }

// it grew until it circled the earth and could bite its own tail
inline bool nrsJormBitesOwnTail()
    { return true; }

// the Norns foretold Thor drowns in its venom at Ragnarok
inline bool nrsJormThorDoom()
    { return true; }

// ---- Idun ----

// an Apple of Youth returns 10 years of youth per bite
inline int nrsIdunAppleYears()
    { return 10; }

// an apple restores up to 50 lost hit points per bite
inline int nrsIdunAppleHp()
    { return 50; }

// the 1-foot wicker chest always appears full but holds any amount
inline bool nrsIdunChestAlwaysFull()
    { return true; }

// Idun is the wife of Bragi
inline bool nrsIdunWifeOfBragi()
    { return true; }

// the gods eat the Apples of Youth to remain immortal
inline bool nrsIdunApplesImmortal()
    { return true; }

// ---- Loki ----

// illusions work on Loki only when cast by beings above the 20th level
inline int nrsLokiIllusionLevel()
    { return 20; }

// Loki is blood brother to Odin and once saved the Asgardians
inline bool nrsLokiBloodBrother()
    { return true; }

// Loki relies on his suggestion power to force beings to his desires
inline bool nrsLokiSuggestionPower()
    { return true; }

// looking at Loki for 3 melee rounds or more negates all saves against the
// suggestion
inline bool nrsLokiThreeRoundNoSave()
    { return true; }

// magic resistance still applies; illusions only above 20th level
inline bool nrsLokiIllusionsAbove()
    { return true; }

// his boots combine water walking, flying, travelling and speed
inline bool nrsLokiBootsOfFour()
    { return true; }

// his colors are red and black, worn even in another guise
inline bool nrsLokiRedBlack()
    { return true; }

// Loki is immune to fire
inline bool nrsLokiFireImmune()
    { return true; }

// Loki cannot be magically controlled
inline bool nrsLokiNoMagicControl()
    { return true; }

// the god shape changes at will
inline bool nrsLokiShapeChange()
    { return true; }

// Loki is the one most likely to betray the gods to the giants
inline bool nrsLokiWouldBetray()
    { return true; }

// ---- Magni ----

// the +3 hammer strike 8-80, low
inline int nrsMagniDmgLow()
    { return 8; }

// the +3 hammer strike 8-80, high
inline int nrsMagniDmgHigh()
    { return 80; }

// the Magni hammer is +3
inline int nrsMagniHammerPlus()
    { return 3; }

// he catches and throws back any object, hitting 90 percent of the time
inline int nrsMagniCatchPct()
    { return 90; }

// he can bend anything he can grip and put his fist through anything
inline bool nrsMagniBendAnything()
    { return true; }

// he can lift nearly anything, even the unliftable, judge option
inline bool nrsMagniLiftAnything()
    { return true; }

// blunt weapons of any type cannot harm him
inline bool nrsMagniBluntImmune()
    { return true; }

// his strength was supposed to be almost limitless
inline bool nrsMagniLimitlessStrength()
    { return true; }

// ---- Modi ----

// the vorpal blade strikes for 25 points per hit - the walk first non-dice
// damage print, low cell
inline int nrsModiVorpalDmg()
    { return 25; }

// the berserk doubles all powers: 4 hits per round for 50 points
inline int nrsModiBerserkDmg()
    { return 50; }

// his courage aura affects all within a 90 yard radius
inline int nrsModiAuraYards()
    { return 90; }

// his inspired followers do an extra 4 points of damage per hit
inline int nrsModiAuraBonus()
    { return 4; }

// Thor son Modi is always in the forefront of any battle
inline bool nrsModiAlwaysForefront()
    { return true; }

// he knows when best to retreat and regroup his forces
inline bool nrsModiRetreatSense()
    { return true; }

// after losing half his hit points he berserks and doubles all combat powers
inline bool nrsModiBerserkDoubles()
    { return true; }

// he is immune to all forms of magical control or illusions
inline bool nrsModiControlImmune()
    { return true; }

// the special attack is the vorpal blade decapitating power
inline bool nrsModiVorpalBlade()
    { return true; }

// ---- the Norns ----

// the three Norns: Urd, Verdandi and Skuld - past, present and future
inline int nrsNornsCount()
    { return 3; }

// the dagger strike 1-10, low
inline int nrsNornsDmgLow()
    { return 1; }

// the dagger strike 1-10, high
inline int nrsNornsDmgHigh()
    { return 10; }

// expensive gold and silver gifts buy a fate telling 1 percent of the time
inline int nrsNornsGiftPct()
    { return 1; }

// they travel the Prime Material Plane as swans dealing out prophecy
inline bool nrsNornsSwanForm()
    { return true; }

// they tend the tree of life Yggdrasil and advise the gods
inline bool nrsNornsYggdrasil()
    { return true; }

// their weapons subtract 1 point from every ability score, no save
inline bool nrsNornsAbilityDrain()
    { return true; }

// they are immune to all nonmagical attacks
inline bool nrsNornsNonmagicalImmune()
    { return true; }

// the Norns are not normal goddesses and have no worshipers
inline bool nrsNornsNoWorshipers()
    { return true; }

// they weave the web of fate impartially
inline bool nrsNornsImpartialFate()
    { return true; }

// ---- Sif ----

// the +3 sword strike 3-30, low
inline int nrsSifDmgLow()
    { return 3; }

// the +3 sword strike 3-30, high
inline int nrsSifDmgHigh()
    { return 30; }

// the printed +11 damage bonus
inline int nrsSifDmgBonus()
    { return 11; }

// the Sif sword is +3
inline int nrsSifSwordPlus()
    { return 3; }

// a 1st level fighter devoted to Sif has a 1 percent chance of a bless spell
// before battle
inline int nrsSifBlessPct()
    { return 1; }

// Sif is the patron of young warriors
inline bool nrsSifPatronYoungWarriors()
    { return true; }

// her golden hair was a gift from the dwarves
inline bool nrsSifGoldenHair()
    { return true; }

// Sif is immune to magical control
inline bool nrsSifControlImmune()
    { return true; }

// ---- Surtur ----

// the flaming sword strike 6-60, low
inline int nrsSurturDmgLow()
    { return 6; }

// the flaming sword strike 6-60, high
inline int nrsSurturDmgHigh()
    { return 60; }

// his hot iron armor does 1-10 to exposed-flesh contacters, low
inline int nrsSurturArmorDmgLow()
    { return 1; }

// his hot iron armor does 1-10 to exposed-flesh contacters, high
inline int nrsSurturArmorDmgHigh()
    { return 10; }

// he wields a 15-foot flaming iron sword
inline int nrsSurturSwordFeet()
    { return 15; }

// Surtur is immune to fire attacks of any kind
inline bool nrsSurturFireImmune()
    { return true; }

// he waits in Jotunheim to lead the fire giants at Ragnarok
inline bool nrsSurturRagnarokLeader()
    { return true; }

// most fire giants regard Surtur as their leader and deity
inline bool nrsSurturFireGiantDeity()
    { return true; }

// ---- Thor ----

// the Mjolnir strike 10-100, low
inline int nrsThorDmgLow()
    { return 10; }

// the Mjolnir strike 10-100, high
inline int nrsThorDmgHigh()
    { return 100; }

// the Special +16 of the ability line
inline int nrsThorDmgBonus()
    { return 16; }

// Mjolnir is +5
inline int nrsThorMjolnirPlus()
    { return 5; }

// Mjolnir can be thrown up to 200 yards
inline int nrsThorThrowYards()
    { return 200; }

// up to 100 dice of lightning bolts per day, of any split
inline int nrsThorLightningDice()
    { return 100; }

// the thunderclap power word stun affects all within 30 feet, save vs magic
// negates
inline int nrsThorStunRadiusFeet()
    { return 30; }

// a lightning spell cast within 200 inches of Thor turns on its caster
inline int nrsThorRedirectInches()
    { return 200; }

// only a 25 strength can lift Mjolnir, more to wield it
inline int nrsThorLiftStrength()
    { return 25; }

// servants and allies within 90 yards gain +2 on all dice throws
inline int nrsThorAllyPlus()
    { return 2; }

// the ally bonus radius
inline int nrsThorAllyYards()
    { return 90; }

// the glove Jarn Grieper gives the third attack per round and handles the
// red-hot hammer
inline bool nrsThorGloveJarngrieper()
    { return true; }

// the girdle Meginjarder gives the strength to wield Mjolnir and break any
// barrier
inline bool nrsThorGirdleMeginjarder()
    { return true; }

// thrown Mjolnir never misses and returns automatically
inline bool nrsThorHammerReturns()
    { return true; }

// a thrown Mjolnir is Thor only attack that round
inline bool nrsThorThrownOnlyAttack()
    { return true; }

// the throw trails a lightning bolt and stuns on the hit clap
inline bool nrsThorPowerWordStun()
    { return true; }

// all Thor clerics rely on hammers for their weapons
inline bool nrsThorClericsUseHammers()
    { return true; }

// his name is enough to make giants check morale
inline bool nrsThorGiantMorale()
    { return true; }

// Thor often alerts his worshipers to incursions of evil
inline bool nrsThorAlertsWorshipers()
    { return true; }

// ---- Thrym ----

// the +3 double-bladed axe strike 4-40, low
inline int nrsThrymDmgLow()
    { return 4; }

// the +3 double-bladed axe strike 4-40, high
inline int nrsThrymDmgHigh()
    { return 40; }

// the printed +14 damage bonus
inline int nrsThrymDmgBonus()
    { return 14; }

// the Thrym axe is +3
inline int nrsThrymAxePlus()
    { return 3; }

// Thrym has ten brothers like normal frost giants
inline int nrsThrymBrothers()
    { return 10; }

// the brothers are AC 4
inline int nrsThrymBrotherAc()
    { return 4; }

// each brother has 100 hit points
inline int nrsThrymBrotherHp()
    { return 100; }

// the brothers move 12
inline int nrsThrymBrotherMove()
    { return 12; }

// the brother damage 4-24, low
inline int nrsThrymBrotherDmgLow()
    { return 4; }

// the brother damage 4-24, high
inline int nrsThrymBrotherDmgHigh()
    { return 24; }

// Thrym is immune to cold attacks
inline bool nrsThrymColdImmune()
    { return true; }

// he wears a coat of white fur over his chainmail
inline bool nrsThrymWhiteFur()
    { return true; }

// he waits to lead the frost giants against the Aesir at Ragnarok
inline bool nrsThrymRagnarokLeader()
    { return true; }

// each brother attacks as a 16+ hit dice monster
inline bool nrsThrymBrothersFight16()
    { return true; }

// Thrym is both leader and deity of the frost giants
inline bool nrsThrymFrostGiantDeity()
    { return true; }

// ---- Tyr ----

// the +3 sword strike 2-20, low
inline int nrsTyrDmgLow()
    { return 2; }

// the +3 sword strike 2-20, high
inline int nrsTyrDmgHigh()
    { return 20; }

// the printed +12 damage bonus
inline int nrsTyrDmgBonus()
    { return 12; }

// the Tyr sword is +3
inline int nrsTyrSwordPlus()
    { return 3; }

// Tyr senses any thief within 100 inches
inline int nrsTyrThiefSenseInches()
    { return 100; }

// Fenris bit off Tyr right hand at the binding
inline bool nrsTyrRightHandLost()
    { return true; }

// by honoring the binding contract Tyr became the god of law and trust
inline bool nrsTyrLawByContract()
    { return true; }

// as war god he watches the Valkyries - only the most valiant reach Valhalla
inline bool nrsTyrValkyrieWatch()
    { return true; }

// he can see invisible objects
inline bool nrsTyrSeeInvisible()
    { return true; }

// he wields his sword in his left hand
inline bool nrsTyrLeftHandSword()
    { return true; }

// ---- Uller ----

// the +4 two-handed sword strike 2-20, low
inline int nrsUllerDmgLow()
    { return 2; }

// the +4 two-handed sword strike 2-20, high
inline int nrsUllerDmgHigh()
    { return 20; }

// the printed +11 damage bonus
inline int nrsUllerDmgBonus()
    { return 11; }

// the Uller longbow is +5
inline int nrsUllerBowPlus()
    { return 5; }

// he never misses targets less than 200 inches away
inline int nrsUllerBowRangeInches()
    { return 200; }

// the Uller two-handed sword is +4
inline int nrsUllerSwordPlus()
    { return 4; }

// he shoots any target he can see with no range penalties
inline bool nrsUllerNoRangePenalty()
    { return true; }

// he cannot be harmed by fire, cold, lightning or elementals
inline bool nrsUllerElementalImmune()
    { return true; }

// he has temporarily ruled in Odin place
inline bool nrsUllerRuledForOdin()
    { return true; }

// as god of winter he sometimes gives aid to those less able to survive it
inline bool nrsUllerWinterAid()
    { return true; }

// his power waned with the ascension of Odin
inline bool nrsUllerWanedPower()
    { return true; }

// Uller is the patron of archers and a mighty bowman
inline bool nrsUllerPatronArchers()
    { return true; }

// ---- Tanngrisner and Tanngjost ----

// two goats: Tanngrisner the white and Tanngjost the black
inline int nrsGoatsCount()
    { return 2; }

// the horn butt 3-24, low
inline int nrsGoatsDmgLow()
    { return 3; }

// the horn butt 3-24, high
inline int nrsGoatsDmgHigh()
    { return 24; }

// they add +6 to damage when they charge
inline int nrsGoatsChargePlus()
    { return 6; }

// the XP level X
inline int nrsGoatsXpRoman()
    { return 10; }

// the XP base 14,100
inline int nrsGoatsXpBase()
    { return 14100; }

// the goats attack as 16+ hit dice monsters
inline int nrsGoatsFightHd()
    { return 16; }

// eaten by Thor and friends, they regenerate from bones and skin in morning
// light
inline bool nrsGoatsEatenReborn()
    { return true; }

// the enchanted goats pull Thor chariot through air and land
inline bool nrsGoatsPullChariot()
    { return true; }

// ---- Vidar ----

// the iron shoe strike 8-80, low
inline int nrsVidarDmgLow()
    { return 8; }

// the iron shoe strike 8-80, high
inline int nrsVidarDmgHigh()
    { return 80; }

// at will Vidar makes a 24 inch radius completely silent
inline int nrsVidarSilenceRadiusInches()
    { return 24; }

// the magical iron shoe on his right foot strikes twice per round
inline bool nrsVidarIronShoe()
    { return true; }

// what he steps on is pinned until he lets go - no fighting or spellcasting
// under the shoe
inline bool nrsVidarPinUnderfoot()
    { return true; }

// he speaks only when he must, in as few words as possible
inline bool nrsVidarStoicSilent()
    { return true; }

// the son of Odin combats evil in his own way
inline bool nrsVidarHatesEvil()
    { return true; }

// the silence cannot be countered by dispel magic, spell turning or anything
// else
inline bool nrsVidarSilenceUncounterable()
    { return true; }

// ---- the Valkyries ----

// the warrior maidens ride pegasi of maximum hit points
inline bool nrsValkyriePegasiMaxHp()
    { return true; }

// they travel ethereally
inline bool nrsValkyrieEthereal()
    { return true; }

// their pearly flickering armor light is said to cause the Aurora Borealis
inline bool nrsValkyrieAuroraLight()
    { return true; }

// they are only visible to warriors in mortal danger
inline bool nrsValkyrieVisibleToDoomed()
    { return true; }

// they bring the souls of the best slain warriors to Valhalla
inline bool nrsValkyrieChooseSlain()
    { return true; }

// their mounts are the offspring of Sleipner
inline bool nrsValkyrieSleipnerOffspring()
    { return true; }

// they act as serving maids in Odin hall and handmaidens to Frigga
inline bool nrsValkyrieServeOdin()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Odin minus 6 the best; THOR PRINTS THE BARE 4 - the
// tsv line shows no minus glyph, the L&L voice reads minus 4, pinned as
// printed with the eyeball flag; Freke the positive 4 and the goats and
// Fossergrim the 0 cells; the L&L divergences Aegir minus 3 and Freya minus 4
// pinned the other way by the print)
inline int nrsCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -6;
        case 1:
            return 2;
        case 2:
            return -1;
        case 3:
            return 4;
        case 4:
            return -5;
        case 5:
            return -4;
        case 6:
            return -4;
        case 7:
            return -4;
        case 8:
            return -3;
        case 9:
            return -4;
        case 10:
            return 0;
        case 11:
            return -5;
        case 12:
            return 3;
        case 13:
            return -4;
        case 14:
            return -3;
        case 15:
            return -3;
        case 16:
            return -4;
        case 17:
            return -1;
        case 18:
            return -5;
        case 19:
            return -5;
        case 20:
            return -3;
        case 21:
            return -3;
        case 22:
            return -4;
        case 23:
            return -4;
        case 24:
            return -4;
        case 25:
            return 0;
        case 26:
            return -4;
        case 27:
            return -2;
        case 28:
            return 4;
        case 29:
            return -2;
        case 30:
            return -5;
        case 31:
            return -3;
        case 32:
            return 0;
        case 33:
            return -3;
        case 34:
            return -2;
        default:
            return 0;
        }
    }

// The alternative armor class cells (none printed - all 0)
inline int nrsCbtACAlt(int b)
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
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (Odin 400 and Thor 399 the highs, Fjalar and Skirnir
// the 99 lows; Thrym 300 pinned from the L&L voice - the print cell is
// occluded by the plate illustration on the pdf page; the Fossergrim 5 is the
// 5 HD print, hit dice not points)
inline int nrsCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 30;
        case 2:
            return 200;
        case 3:
            return 75;
        case 4:
            return 387;
        case 5:
            return 388;
        case 6:
            return 370;
        case 7:
            return 400;
        case 8:
            return 99;
        case 9:
            return 389;
        case 10:
            return 5;
        case 11:
            return 388;
        case 12:
            return 50;
        case 13:
            return 100;
        case 14:
            return 99;
        case 15:
            return 339;
        case 16:
            return 366;
        case 17:
            return 200;
        case 18:
            return 390;
        case 19:
            return 350;
        case 20:
            return 300;
        case 21:
            return 329;
        case 22:
            return 300;
        case 23:
            return 325;
        case 24:
            return 379;
        case 25:
            return 299;
        case 26:
            return 349;
        case 27:
            return 380;
        case 28:
            return 399;
        case 29:
            return 300;
        case 30:
            return 380;
        case 31:
            return 390;
        case 32:
            return 100;
        case 33:
            return 380;
        case 34:
            return 100;
        default:
            return 0;
        }
    }

// The move cells (Aegir 42 the high; Hel the Infinite print minus 1 sentinel
// - the R863 Death precedent; Jormungandr See below 0; Frigga move 15 with
// her as-per-shape attacks in the AtN col)
inline int nrsCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 1;
        case 2:
            return 24;
        case 3:
            return 24;
        case 4:
            return 42;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 24;
        case 8:
            return 12;
        case 9:
            return 18;
        case 10:
            return 9;
        case 11:
            return 18;
        case 12:
            return 24;
        case 13:
            return 18;
        case 14:
            return 12;
        case 15:
            return 18;
        case 16:
            return 15;
        case 17:
            return 18;
        case 18:
            return 15;
        case 19:
            return -1;
        case 20:
            return 0;
        case 21:
            return 12;
        case 22:
            return 12;
        case 23:
            return 18;
        case 24:
            return 21;
        case 25:
            return 12;
        case 26:
            return 18;
        case 27:
            return 15;
        case 28:
            return 18;
        case 29:
            return 15;
        case 30:
            return 18;
        case 31:
            return 24;
        case 32:
            return 24;
        case 33:
            return 21;
        case 34:
            return 15;
        default:
            return 0;
        }
    }

// The alternative move cells (Hugin 48, Fossergrim 36, Gullin-Bursti 32,
// Blodug-Hofi 18, Freya 48, Idun 18, the Norns 21; Loki 12 and the goats 24
// the two dual-same prints; the Fenris Wolf 12)
inline int nrsCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 48;
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
            return 12;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 36;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return 32;
        case 14:
            return 0;
        case 15:
            return 48;
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
        case 21:
            return 18;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 21;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 24;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The attacks-per-round numerators (Frigga the As per shape print 0 sentinel;
// Modi the 2 of his 2-or-4 berserk; Odin 2 and Tyr 3)
inline int nrsCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 3;
        case 20:
            return 1;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 1;
        case 26:
            return 2;
        case 27:
            return 2;
        case 28:
            return 2;
        case 29:
            return 2;
        case 30:
            return 3;
        case 31:
            return 2;
        case 32:
            return 3;
        case 33:
            return 2;
        case 34:
            return 2;
        default:
            return 0;
        }
    }

// The attacks-per-round denominators (Modi the berserk 4, Thor the glove 3 of
// his 2(3) print; 0 = a bare number print)
inline int nrsCbtAtD(int b)
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
            return 0;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 2;
        case 20:
            return 0;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 0;
        case 24:
            return 4;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 3;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (the Fenris Wolf and Jormungandr 99 the highs;
// Fjalar and Skirnir the Standard prints 0, the Fossergrim 100 percent rides
// only in splashing water)
inline int nrsCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 75;
        case 2:
            return 25;
        case 3:
            return 50;
        case 4:
            return 50;
        case 5:
            return 75;
        case 6:
            return 75;
        case 7:
            return 99;
        case 8:
            return 0;
        case 9:
            return 85;
        case 10:
            return 0;
        case 11:
            return 75;
        case 12:
            return 75;
        case 13:
            return 75;
        case 14:
            return 0;
        case 15:
            return 80;
        case 16:
            return 75;
        case 17:
            return 80;
        case 18:
            return 80;
        case 19:
            return 95;
        case 20:
            return 99;
        case 21:
            return 25;
        case 22:
            return 75;
        case 23:
            return 70;
        case 24:
            return 95;
        case 25:
            return 80;
        case 26:
            return 80;
        case 27:
            return 60;
        case 28:
            return 80;
        case 29:
            return 60;
        case 30:
            return 25;
        case 31:
            return 50;
        case 32:
            return 25;
        case 33:
            return 95;
        case 34:
            return 25;
        default:
            return 0;
        }
    }

// The size cells in inches (the Fenris Wolf the 50-foot wolf 600, Thrym 252,
// Surtur and Vidar 240; the four half-foot cells - Odin, Hel and Tyr the 6
// and a half foot 78, the Valkyries the 5 and a half foot 66, the half glyph
// garbling to )4 and % in the tesseract pass while the L&L voice reads 6.5
// and 5.5; Jormungandr the 25,000-miles print 0 sentinel with the const)
inline int nrsCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 78;
        case 1:
            return 36;
        case 2:
            return 144;
        case 3:
            return 120;
        case 4:
            return 84;
        case 5:
            return 72;
        case 6:
            return 72;
        case 7:
            return 600;
        case 8:
            return 48;
        case 9:
            return 72;
        case 10:
            return 72;
        case 11:
            return 72;
        case 12:
            return 108;
        case 13:
            return 120;
        case 14:
            return 72;
        case 15:
            return 72;
        case 16:
            return 72;
        case 17:
            return 144;
        case 18:
            return 84;
        case 19:
            return 78;
        case 20:
            return 0;
        case 21:
            return 72;
        case 22:
            return 72;
        case 23:
            return 84;
        case 24:
            return 84;
        case 25:
            return 60;
        case 26:
            return 72;
        case 27:
            return 240;
        case 28:
            return 84;
        case 29:
            return 252;
        case 30:
            return 78;
        case 31:
            return 84;
        case 32:
            return 108;
        case 33:
            return 240;
        case 34:
            return 66;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric levels (Odin the 30th level Special print, Hel 20, Freya 15,
// Surtur 15; 0 = Nil or an MM block)
inline int nrsClsClr(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 12;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 13;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 15;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 12;
        case 19:
            return 20;
        case 20:
            return 0;
        case 21:
            return 15;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 12;
        case 26:
            return 0;
        case 27:
            return 15;
        case 28:
            return 0;
        case 29:
            return 10;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The druid levels (Tyr 13, Uller 13, Idun 14, Sif 12, Thor 10, Forseti 10,
// Vidar 10)
inline int nrsClsDrd(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 12;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 10;
        case 10:
            return 0;
        case 11:
            return 13;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 10;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 12;
        case 19:
            return 10;
        case 20:
            return 0;
        case 21:
            return 14;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 12;
        case 26:
            return 12;
        case 27:
            return 0;
        case 28:
            return 10;
        case 29:
            return 0;
        case 30:
            return 13;
        case 31:
            return 13;
        case 32:
            return 0;
        case 33:
            return 10;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The fighter levels (Surtur, Thrym and Thor 20; Modi and Magni 15, the
// Valkyries 15, Fjalar 10)
inline int nrsClsFtr(int b)
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
            return 10;
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
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 15;
        case 24:
            return 15;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 20;
        case 28:
            return 20;
        case 29:
            return 20;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 15;
        default:
            return 0;
        }
    }

// The ranger levels (Odin 18, Uller 18, Vidar 18, Heimdall 17, Frey 15, Aegir
// 15, Loki 12, Hel 12, Sif 12)
inline int nrsClsRng(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 15;
        case 5:
            return 10;
        case 6:
            return 7;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 15;
        case 10:
            return 0;
        case 11:
            return 15;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 9;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 0;
        case 18:
            return 17;
        case 19:
            return 12;
        case 20:
            return 0;
        case 21:
            return 7;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 5;
        case 26:
            return 12;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 18;
        case 32:
            return 0;
        case 33:
            return 18;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The paladin levels (Tyr 25 - the walk first paladin cell)
inline int nrsClsPal(int b)
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
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 25;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user levels (Odin 30 the high, Frey 20, Frigga 18, Hel 15, Loki
// 11, Surtur 5)
inline int nrsClsMU(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 10;
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
            return 20;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 15;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 11;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 15;
        case 26:
            return 0;
        case 27:
            return 5;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The illusionist levels (Freya 15, Bragi 15, the Norns 15, Hel 15, Uller 12,
// Tyr 10, Thrym 3)
inline int nrsClsIll(int b)
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
            return 10;
        case 5:
            return 0;
        case 6:
            return 15;
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
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 15;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 15;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 20;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 15;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 3;
        case 30:
            return 10;
        case 31:
            return 12;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The thief levels (Tyr 15, Fjalar 10, the Norns 10; Uller 0 - his 12th rides
// the assassin col)
inline int nrsClsThf(int b)
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
            return 10;
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
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 10;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 15;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The assassin levels (Loki 15, Hel 15, Uller 12)
inline int nrsClsAss(int b)
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
            return 15;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 15;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 12;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The monk levels (Loki 5 and the Norns 8 the in-each M/B pairs, Tyr 10)
inline int nrsClsMnk(int b)
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
        case 21:
            return 0;
        case 22:
            return 5;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 8;
        case 26:
            return 12;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 10;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The bard levels (Bragi 23 the high, Balder 20, Idun 13, Freya 12, Sif 12,
// Uller 12, Odin 15, Frey 15, the Valkyries 8, Thor 3)
inline int nrsClsBrd(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 5;
        case 5:
            return 20;
        case 6:
            return 23;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 15;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 5;
        case 15:
            return 12;
        case 16:
            return 10;
        case 17:
            return 0;
        case 18:
            return 8;
        case 19:
            return 10;
        case 20:
            return 0;
        case 21:
            return 13;
        case 22:
            return 5;
        case 23:
            return 5;
        case 24:
            return 9;
        case 25:
            return 8;
        case 26:
            return 12;
        case 27:
            return 0;
        case 28:
            return 3;
        case 29:
            return 0;
        case 30:
            return 10;
        case 31:
            return 12;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 8;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the 25s: Odin, Heimdall, Surtur, Thrym, Magni, Vidar;
// Magni the bare 25(special) with no bonus pair, Thor the Special +7 +16
// print)
inline int nrsAbiS(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 23;
        case 5:
            return 22;
        case 6:
            return 23;
        case 7:
            return 0;
        case 8:
            return 19;
        case 9:
            return 24;
        case 10:
            return 0;
        case 11:
            return 24;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 17;
        case 15:
            return 24;
        case 16:
            return 20;
        case 17:
            return 0;
        case 18:
            return 25;
        case 19:
            return 20;
        case 20:
            return 0;
        case 21:
            return 20;
        case 22:
            return 24;
        case 23:
            return 25;
        case 24:
            return 24;
        case 25:
            return 23;
        case 26:
            return 23;
        case 27:
            return 25;
        case 28:
            return 25;
        case 29:
            return 25;
        case 30:
            return 24;
        case 31:
            return 23;
        case 32:
            return 0;
        case 33:
            return 25;
        case 34:
            return 19;
        default:
            return 0;
        }
    }

// The strength to-hit bonuses (0 = the MM blocks and the Magni special)
inline int nrsAbiHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 6;
        case 10:
            return 0;
        case 11:
            return 6;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 6;
        case 16:
            return 3;
        case 17:
            return 0;
        case 18:
            return 7;
        case 19:
            return 3;
        case 20:
            return 0;
        case 21:
            return 3;
        case 22:
            return 6;
        case 23:
            return 0;
        case 24:
            return 6;
        case 25:
            return 5;
        case 26:
            return 5;
        case 27:
            return 7;
        case 28:
            return 7;
        case 29:
            return 7;
        case 30:
            return 6;
        case 31:
            return 5;
        case 32:
            return 0;
        case 33:
            return 7;
        case 34:
            return 3;
        default:
            return 0;
        }
    }

// The strength damage bonuses (Thor +16 the high; every god damage cell
// matches his strength bonus - the Hel +38 print garble adjudicated to 8 by
// that arithmetic and the L&L voice)
inline int nrsAbiDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 11;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 0;
        case 8:
            return 7;
        case 9:
            return 12;
        case 10:
            return 0;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 12;
        case 16:
            return 8;
        case 17:
            return 0;
        case 18:
            return 14;
        case 19:
            return 8;
        case 20:
            return 0;
        case 21:
            return 8;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 12;
        case 25:
            return 11;
        case 26:
            return 11;
        case 27:
            return 14;
        case 28:
            return 16;
        case 29:
            return 14;
        case 30:
            return 12;
        case 31:
            return 11;
        case 32:
            return 0;
        case 33:
            return 14;
        case 34:
            return 7;
        default:
            return 0;
        }
    }

// The intelligence cells (Odin 25, Loki 25; the MM blocks 0)
inline int nrsAbiI(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 25;
        case 10:
            return 0;
        case 11:
            return 24;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 14;
        case 15:
            return 24;
        case 16:
            return 23;
        case 17:
            return 0;
        case 18:
            return 23;
        case 19:
            return 24;
        case 20:
            return 0;
        case 21:
            return 22;
        case 22:
            return 25;
        case 23:
            return 20;
        case 24:
            return 23;
        case 25:
            return 22;
        case 26:
            return 24;
        case 27:
            return 19;
        case 28:
            return 20;
        case 29:
            return 16;
        case 30:
            return 20;
        case 31:
            return 24;
        case 32:
            return 0;
        case 33:
            return 20;
        case 34:
            return 17;
        default:
            return 0;
        }
    }

// The wisdom cells (Odin 25, Hel 25, the Norns 25; Surtur 14 the W:i4
// tesseract garble, the L&L voice agrees 14)
inline int nrsAbiW(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 18;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 24;
        case 10:
            return 0;
        case 11:
            return 23;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 18;
        case 15:
            return 24;
        case 16:
            return 20;
        case 17:
            return 0;
        case 18:
            return 24;
        case 19:
            return 25;
        case 20:
            return 0;
        case 21:
            return 23;
        case 22:
            return 19;
        case 23:
            return 20;
        case 24:
            return 22;
        case 25:
            return 25;
        case 26:
            return 22;
        case 27:
            return 14;
        case 28:
            return 20;
        case 29:
            return 12;
        case 30:
            return 20;
        case 31:
            return 24;
        case 32:
            return 0;
        case 33:
            return 19;
        case 34:
            return 17;
        default:
            return 0;
        }
    }

// The dexterity cells (Odin 25, Heimdall 25, Freya 24, Hel 24; Surtur 12)
inline int nrsAbiD(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 18;
        case 9:
            return 22;
        case 10:
            return 0;
        case 11:
            return 24;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 18;
        case 15:
            return 24;
        case 16:
            return 24;
        case 17:
            return 0;
        case 18:
            return 25;
        case 19:
            return 24;
        case 20:
            return 0;
        case 21:
            return 24;
        case 22:
            return 24;
        case 23:
            return 24;
        case 24:
            return 24;
        case 25:
            return 23;
        case 26:
            return 25;
        case 27:
            return 12;
        case 28:
            return 25;
        case 29:
            return 21;
        case 30:
            return 25;
        case 31:
            return 25;
        case 32:
            return 0;
        case 33:
            return 25;
        case 34:
            return 18;
        default:
            return 0;
        }
    }

// The constitution cells (the 25s: Odin, Freya, Heimdall, Hel, Sif, Tyr,
// Uller)
inline int nrsAbiC(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 24;
        case 5:
            return 25;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 18;
        case 9:
            return 25;
        case 10:
            return 0;
        case 11:
            return 25;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 18;
        case 15:
            return 25;
        case 16:
            return 25;
        case 17:
            return 0;
        case 18:
            return 25;
        case 19:
            return 25;
        case 20:
            return 0;
        case 21:
            return 24;
        case 22:
            return 24;
        case 23:
            return 25;
        case 24:
            return 25;
        case 25:
            return 25;
        case 26:
            return 25;
        case 27:
            return 25;
        case 28:
            return 25;
        case 29:
            return 25;
        case 30:
            return 25;
        case 31:
            return 25;
        case 32:
            return 0;
        case 33:
            return 25;
        case 34:
            return 19;
        default:
            return 0;
        }
    }

// The charisma cells (Odin 25, Balder 25; Aegir 9 and the Norns 9 the lows)
inline int nrsAbiCH(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 9;
        case 5:
            return 25;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 23;
        case 10:
            return 0;
        case 11:
            return 23;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 18;
        case 15:
            return 20;
        case 16:
            return 25;
        case 17:
            return 0;
        case 18:
            return 23;
        case 19:
            return 25;
        case 20:
            return 0;
        case 21:
            return 24;
        case 22:
            return 24;
        case 23:
            return 22;
        case 24:
            return 25;
        case 25:
            return 9;
        case 26:
            return 25;
        case 27:
            return 20;
        case 28:
            return 24;
        case 29:
            return 20;
        case 30:
            return 24;
        case 31:
            return 25;
        case 32:
            return 0;
        case 33:
            return 22;
        case 34:
            return 19;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The print page cells (113 through 124, the Norse box of the gap report)
inline int nrsRosPage(int b)
    {
        switch (b) {
        case 0:
            return 113;
        case 1:
            return 114;
        case 2:
            return 114;
        case 3:
            return 114;
        case 4:
            return 115;
        case 5:
            return 115;
        case 6:
            return 115;
        case 7:
            return 115;
        case 8:
            return 116;
        case 9:
            return 116;
        case 10:
            return 116;
        case 11:
            return 116;
        case 12:
            return 117;
        case 13:
            return 117;
        case 14:
            return 117;
        case 15:
            return 117;
        case 16:
            return 118;
        case 17:
            return 118;
        case 18:
            return 118;
        case 19:
            return 119;
        case 20:
            return 119;
        case 21:
            return 119;
        case 22:
            return 119;
        case 23:
            return 120;
        case 24:
            return 120;
        case 25:
            return 120;
        case 26:
            return 121;
        case 27:
            return 121;
        case 28:
            return 121;
        case 29:
            return 122;
        case 30:
            return 122;
        case 31:
            return 122;
        case 32:
            return 122;
        case 33:
            return 123;
        case 34:
            return 123;
        default:
            return 0;
        }
    }

// The plane cells (1 Gladsheim, 2 Elysium, 3 Hades, 4 Pandemonium, 5
// Concordant Opposition, 0 none printed - the MM blocks, Fjalar, Skirnir and
// the Valkyries)
inline int nrsRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
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
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 4;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 5;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The alternative plane cells (Loki the Pandemonium-or-Gladsheim print, his
// home by current status with the gods)
inline int nrsRosPlaneAlt(int b)
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
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG 1 LN 2 CG 3 CN 4 N 5 NG 6 LE 7 NE 8 CE)
inline int nrsRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 8;
        case 8:
            return 4;
        case 9:
            return 0;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 1;
        case 17:
            return 6;
        case 18:
            return 0;
        case 19:
            return 7;
        case 20:
            return 8;
        case 21:
            return 2;
        case 22:
            return 8;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 4;
        case 26:
            return 2;
        case 27:
            return 6;
        case 28:
            return 2;
        case 29:
            return 8;
        case 30:
            return 0;
        case 31:
            return 3;
        case 32:
            return 4;
        case 33:
            return 2;
        case 34:
            return 3;
        default:
            return 0;
        }
    }

// The rank cells (1 greater, 0 lesser, 4 the class-grid rows with no rank
// line - Fjalar, Skirnir, the Norns, the Valkyries, 5 the eleven MM-style
// blocks)
inline int nrsRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 1;
        case 10:
            return 5;
        case 11:
            return 1;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 5;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 5;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 4;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 0;
        case 32:
            return 5;
        case 33:
            return 0;
        case 34:
            return 4;
        default:
            return 0;
        }
    }

// The psionic class cells (I: Odin, Hel, the Norns, Tyr, Uller; II: Forseti,
// Frey, Frigga; III: Heimdall; IV: Loki, Modi; V: Aegir, Bragi, Idun; VI:
// Balder, Freya, Magni, Sif, Skirnir, Thor, Vidar; 0 = Nil)
inline int nrsRosPsi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 6;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 5;
        case 22:
            return 4;
        case 23:
            return 6;
        case 24:
            return 4;
        case 25:
            return 1;
        case 26:
            return 6;
        case 27:
            return 0;
        case 28:
            return 6;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 6;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The printed-damage flags (27 rows; Odin, Fossergrim, Skirnir, Freya,
// Frigga, Idun, Loki and the Valkyries the by-weapon and as-per-shape rows
// carry 0)
inline int nrsRosDmgFixed(int b)
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
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The in-each flags (the eleven rows printing an Nth-level-in-each pair:
// Aegir, Balder, Bragi, Forseti, Frey, Heimdall, Hel, Loki, the Norns, Sif,
// Tyr)
inline int nrsRosInEach(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
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
            return 1;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// The plane parenthetical cells (1 Valhalla - Odin, 2 Jotunheim - Surtur and
// Thrym)
inline int nrsRosParen(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 2;
        case 28:
            return 0;
        case 29:
            return 2;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        default:
            return 0;
        }
    }

// ---- the R865 census ----

// thirty-five stat-block rows
inline int nrsBeingCount()
    { return 35; }

// four grids: combat, class, ability, roster
inline int nrsTableCount()
    { return 4; }

// no chains this round
inline int nrsChainCount()
    { return 0; }

// zero registry defs touched, the floor holds
inline int nrsRegistryFloor()
    { return 995; }

// the battery census after this round lands
inline int nrsCensusAfter()
    { return 788; }

// the combat grid rows
inline int nrsCbtRows()
    { return 35; }

// the class grid rows
inline int nrsClsRows()
    { return 35; }

// the ability grid rows
inline int nrsAbiRows()
    { return 35; }

// the roster grid rows
inline int nrsRosRows()
    { return 35; }

// eleven greater gods: Odin, Balder, Forseti, Frey, Freya, Frigga, Heimdall,
// Hel, Loki, Thor, Tyr
inline int nrsGreaterCount()
    { return 11; }

// ten lesser: Aegir, Bragi, Idun, Magni, Modi, Sif, Surtur, Thrym, Uller,
// Vidar
inline int nrsLesserCount()
    { return 10; }

// four class-grid rows printing no rank line: Fjalar, Skirnir, the Norns, the
// Valkyries
inline int nrsNoRankCount()
    { return 4; }

// eleven MM-style blocks: Hugin, Sleipner, Freke, the Fenris Wolf,
// Fossergrim, Blodug-Hofi, Gullin-Bursti, Garm, Jormungandr, the goats, plus
// the Norns block riding class grids
inline int nrsMonsterCount()
    { return 11; }

// eighteen Gladsheim rows (the Surtur and Thrym parentheticals are Jotunheim
// in Gladsheim)
inline int nrsGladsheimCount()
    { return 18; }

// one Elysium row: Bragi
inline int nrsElysiumCount()
    { return 1; }

// one Hades row: Hel
inline int nrsHadesCount()
    { return 1; }

// one Pandemonium row: Loki (his Gladsheim alt rides the plane alt col)
inline int nrsPandemoniumCount()
    { return 1; }

// one Concordant Opposition row: the Norns
inline int nrsConcordantCount()
    { return 1; }

// thirteen rows printing no PLANE line: the eleven MM blocks minus none, plus
// Fjalar, Skirnir and the Valkyries
inline int nrsNoPlaneCount()
    { return 13; }

// one dual-plane print: Loki the Pandemonium or Gladsheim
inline int nrsDualPlaneCount()
    { return 1; }

// five plane codes in play: Gladsheim, Elysium, Hades, Pandemonium,
// Concordant Opposition
inline int nrsPlaneCodeCount()
    { return 5; }

// twenty-one rows printing a psionic class
inline int nrsPsiRowCount()
    { return 21; }

// fourteen Nil or no-line rows
inline int nrsPsiNilCount()
    { return 14; }

// the class I pipes: Odin, Hel, the Norns, Tyr, Uller
inline int nrsPsiOneCount()
    { return 5; }

// the class II pipes: Forseti, Frey, Frigga
inline int nrsPsiTwoCount()
    { return 3; }

// the class III pipes: Heimdall
inline int nrsPsiThreeCount()
    { return 1; }

// the class IV pipes: Loki, Modi
inline int nrsPsiFourCount()
    { return 2; }

// the class V pipes: Aegir, Bragi, Idun
inline int nrsPsiFiveCount()
    { return 3; }

// the class VI pipes: Balder, Freya, Magni, Sif, Skirnir, Thor, Vidar
inline int nrsPsiSixCount()
    { return 7; }

// twenty-seven printed-damage rows; the by-weapon, as-per-shape and see-below
// rows carry 0
inline int nrsDmgFixedCount()
    { return 27; }

// eleven in-each rows: Aegir, Balder, Bragi, Forseti, Frey, Heimdall, Hel,
// Loki, the Norns, Sif, Tyr
inline int nrsInEachCount()
    { return 11; }

// ten dual-move rows: Hugin, the Fenris Wolf, Fossergrim, Blodug-Hofi,
// Gullin-Bursti, Freya, Idun, Loki, the Norns, the goats
inline int nrsDualMoveCount()
    { return 10; }

// two dual-same prints: Loki 12 over 12 and the goats 24 over 24
inline int nrsDualSameMoveCount()
    { return 2; }

// one Infinite move print: Hel, the minus 1 sentinel (the R863 Death
// precedent)
inline int nrsInfiniteMoveCount()
    { return 1; }

// four half-foot size cells: Odin, Hel and Tyr the 6 and a half foot 78, the
// Valkyries the 5 and a half foot 66
inline int nrsHalfFootCount()
    { return 4; }

// one Valhalla parenthetical: Odin Gladsheim (Valhalla)
inline int nrsValhallaCount()
    { return 1; }

// two Jotunheim parentheticals: Surtur and Thrym
inline int nrsJotunheimCount()
    { return 2; }

// six companion blocks: Hugin and Munin, Sleipner, Freke and Gere,
// Blodug-Hofi, Gullin-Bursti, the goats
inline int nrsCompanionCount()
    { return 6; }

// the Einheriar are always of the 4th level and above
inline int nrsEinheriarMinLevel()
    { return 4; }

// two principal dwarven races: Modsogner and Durin
inline int nrsDwarfRaces()
    { return 2; }

// the Vanir are allies of the Aesir at Ragnarok but separate
inline bool nrsAesirVanirAllies()
    { return true; }

// the Vanir do not deal with the lives of men
inline bool nrsVanirNotMen()
    { return true; }

// at Ragnarok evil triumphs and both hosts are destroyed
inline bool nrsRagnarokEvilWins()
    { return true; }

// the warlike majority cannot cure; only those noted in the text
inline bool nrsCureSpellsRare()
    { return true; }

// a human sacrifice is simultaneously hanged and speared through the heart
inline bool nrsHangedAndSpeared()
    { return true; }

// the sacrifice is burned on a pyre of oak
inline bool nrsOakPyre()
    { return true; }

// the god images are taken out for worship every lunar month
inline bool nrsLunarMonthWorship()
    { return true; }

// sacrifices are gold and silver, useful and pleasing to the eye
inline bool nrsGoldSilverUseful()
    { return true; }

// swearing, broken oaths and defaced images are forgiven by success in the
// next battle
inline bool nrsBlasphemyForgivenByBattle()
    { return true; }

// Bifrost the Rainbow Bridge is kept hidden behind a veil of illusion
inline bool nrsBifrostHidden()
    { return true; }

// Jotunheim is the anomalous blot of evil upon Gladsheim
inline bool nrsJotunheimBlot()
    { return true; }

// the Einheriar are the army of the Norse gods at Ragnarok
inline bool nrsEinheriarRagnarokArmy()
    { return true; }

// the Modsogner dwarves produce magic items of a non-violent nature
inline bool nrsModsognerNonviolent()
    { return true; }

// the Durin dwarves create magical weapons of tremendous power
inline bool nrsDurinWeapons()
    { return true; }

}   // namespace rules
