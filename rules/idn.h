// =========================================================================================
// Adnd1 - rules/idn.h
// the Indian mythos - the D&DG walk round twelve, print pp. 75-80: eighteen
// beings from Indra the first ruler of the gods and master of the atmosphere
// to Yama the judge of the dead and his water buffalo, the six greater gods
// (Indra, Agni, Rudra, Surya, Varuna, Vishnu), the three lesser gods (Kali,
// Lakshmi, Ushas), the four demigods (Karttikeya, Ratri, Tvashtri, Yama), and
// the five monsters across nine plane codes.
// census 782 -> 783.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 076-081; the second printing) with
// the column-split tsv dumps; the collation voice: the archive.org 1st-print
// derivative (deities-demigods-1st-print) - the chocr char-level word
// geometry at 600dpi plus the djvu.xml word geometry. The adjudications: the
// psionic three-pipe catch (Indra TI! w47 and Kali III I(9)I(10)I(10), both
// class III; single pipe w10 Agni, Tvashtri, Vishnu; V w36 Ratri, Rudra,
// Yama; VI w49 Karttikeya, Lakshmi, Surya, Ushas, Varuna), the fraction
// fingerprint (Ushas 5 1/2 = 66, Varuna 6 1/2 = 78, the small-1 + low-4
// clusters), the Surya AC -3 over the Termux bare dash, the MU/I See below
// 99/99 of Agni and Yama (the egp Isis precedent), the three paladin pairs
// (Surya 16, Varuna 14, Vishnu 17), the Kali in-each double pair (C/D 10 and
// MU/I 15), and the flagged odd prints pinned: Indra AC em-dash minus twelve,
// Kali move 27, Kali wisdom 5 and MR 39, the Marut move 9 apostrophe, the
// Buffalo 12 inch shoulders, Yama MR 25 robes 100.
//
namespace rules {

// ---- the R860 census ----

// the Indian mythos round: the D&DG walk round twelve, print pp. 75-80
inline int idnRound()
    { return 860; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int idnPrintStart()
    { return 75; }

// the last print page of the mythos
inline int idnPrintEnd()
    { return 80; }

// the eighteen beings of the Indian mythos (six greater, three lesser, four
// demigods, five monsters; no heroes, no titans)
inline int idnBeingCount()
    { return 18; }

// the four grids: combat, class, ability, roster
inline int idnTableCount()
    { return 4; }

// no chains this round: no banded thresholds printed in the mythos
inline int idnChainCount()
    { return 0; }

// the registry floor holds: zero registry defs touched this round
inline int idnRegistryFloor()
    { return 995; }

// the combat grid rows (eighteen beings)
inline int idnCbtRows()
    { return 18; }

// the class grid rows
inline int idnClsRows()
    { return 18; }

// the ability grid rows
inline int idnAbiRows()
    { return 18; }

// the roster grid rows
inline int idnRosRows()
    { return 18; }

// the nine plane codes: none, Limbo, Gladsheim, the Abyss, Hades, Nirvana,
// the Seven Heavens, Elysium, Concordant Opposition
inline int idnPlaneCount()
    { return 9; }

// the six greater gods (Indra, Agni, Rudra, Surya, Varuna, Vishnu)
inline int idnGreaterCount()
    { return 6; }

// the three lesser gods (Kali, Lakshmi, Ushas)
inline int idnLesserCount()
    { return 3; }

// the four demigods (Karttikeya, Ratri, Tvashtri, Yama)
inline int idnDemigodCount()
    { return 4; }

// the five monsters (the Elephant, the Peacock, the Marut, Garuda, the Water
// Buffalo)
inline int idnMonsterCount()
    { return 5; }

// the three printed Nth level in each rows (Indra MU/I 20, Kali C/D 10 and
// MU/I 15, Lakshmi MU/I 20)
inline int idnInEachCount()
    { return 3; }

// no printed rivalry lines this round: zero enmity flags
inline int idnEnmityCount()
    { return 0; }

// the three paladins of the FIGHTER lines (Surya 16, Varuna 14, Vishnu 17)
inline int idnPaladinCount()
    { return 3; }

// all four printed psionic classes appear (I Agni, Tvashtri, Vishnu; III
// Indra, Kali; V Ratri, Rudra, Yama; VI Karttikeya, Lakshmi, Surya, Ushas,
// Varuna)
inline int idnPsiClassKinds()
    { return 4; }

// the two pixel-verified X 1/2 foot fraction cells (Ushas 5 1/2, Varuna 6
// 1/2)
inline int idnHalfFootCount()
    { return 2; }

// no artifacts this round
inline int idnArtifactCount()
    { return 0; }

// ---- the Indian pantheon doctrine ----

// the pantheon is a mixture of Vedic and Hindu concepts, usually leaning
// toward the Vedic
inline bool idnVedicHinduMixture()
    { return true; }

// these gods maintain an aloofness greater than normal compared with the
// other pantheons
inline bool idnAloofGreaterThanNormal()
    { return true; }

// a character may be born a cleric, magic-user or fighter under the caste
// system
inline bool idnBornToStation()
    { return true; }

// one does not switch from class to class, which usually prevents two classes
inline bool idnNoClassSwitch()
    { return true; }

// the magic-user caste is deemed superior to all other castes including the
// warriors
inline bool idnMagicUserCasteSupreme()
    { return true; }

// persons of higher status are treated with respect and obeyed or left
// strictly alone
inline bool idnHigherStatusRespect()
    { return true; }

// all prayers are answered if the proper sacrifices are made
inline bool idnProperSacrificeAnswered()
    { return true; }

// an unanswered prayer means impropriety, so the prayers are done again and
// again
inline bool idnImproperSacrificeRepeat()
    { return true; }

// worshipers are identified by marks they wear on their persons
inline bool idnWorshipMarksWorn()
    { return true; }

// the followers of Vishnu wear two parallel white-earth lines joined by a
// perpendicular line
inline bool idnVishnuForeheadMark()
    { return true; }

// an avatar usually has lesser powers and a different appearance than its
// deity
inline bool idnAvatarLesserPowers()
    { return true; }

// avatars are often created to perform one specific function or aspect
inline bool idnAvatarSpecificFunction()
    { return true; }

// a deity may have several avatars simultaneously co-existent, each
// uninvolved with the others
inline bool idnAvatarSeveralSimultaneous()
    { return true; }

// Vishnu in particular has many avatars
inline bool idnVishnuManyAvatars()
    { return true; }

// there are awesomely huge shrines to single gods many stories high
inline bool idnHugeShrines()
    { return true; }

// the same areas hold tiny shrines to all the gods that a single worshiper
// can use
inline bool idnTinyShrines()
    { return true; }

// the deities are often described as having many heads and/or arms
inline bool idnManyHeadsArms()
    { return true; }

// the number of arms matches the number of important abilities, varying by
// account
inline bool idnArmsMatchAbilities()
    { return true; }

// ---- Indra ----

// the rainbow bow shoots two lightning bolts per melee round
inline int idnIndraBoltsPerRound()
    { return 2; }

// each lightning bolt does 3-30 points of damage
inline int idnIndraBoltDamage()
    { return 30; }

// the bow range 1,000 yards, all treated as short range
inline int idnIndraBoltRange()
    { return 1000; }

// the +3 flaming sword
inline int idnIndraSwordPlus()
    { return 3; }

// the +4 plate mail and the +4 shield
inline int idnIndraArmorPlus()
    { return 4; }

// Indra is the first ruler of the gods
inline bool idnIndraFirstRuler()
    { return true; }

// his main attribute is the creation and control of any form of weather at
// will
inline bool idnIndraWeatherControl()
    { return true; }

// he influences humans, animals and plants as a staff of command
inline bool idnIndraStaffOfCommand()
    { return true; }

// he can shape change at will
inline bool idnIndraShapeChange()
    { return true; }

// ---- the Elephant of Indra ----

// the elephant attacks as a 16+ HD monster
inline int idnElephantHitDice()
    { return 16; }

// the xp X/21,450 line
inline int idnElephantXpBase()
    { return 21450; }

// the white beast carries any weight his master wishes
inline bool idnElephantCarryWeight()
    { return true; }

// it carries its master through the air, through the planes, or on the ground
inline bool idnElephantPlaneCarry()
    { return true; }

// ---- Agni ----

// Agni has 3 legs
inline int idnAgniLegs()
    { return 3; }

// Agni has 7 arms
inline int idnAgniArms()
    { return 7; }

// Agni has as many as 3 heads
inline int idnAgniHeads()
    { return 3; }

// the control of fire beings within 1 mile
inline int idnAgniControlMiles()
    { return 1; }

// he casts all fire spells as a 50th level spell-caster
inline int idnAgniFireSpellLevel()
    { return 50; }

// the fire aura does 25 points of flame damage to hand-to-hand attackers
inline int idnAgniAuraDamage()
    { return 25; }

// the aura melts weapons of less than +4 bonus
inline int idnAgniMeltPlus()
    { return 4; }

// the breath weapon is usable 3 times per day
inline int idnAgniBreathUses()
    { return 3; }

// the flame stream reaches 30 yards
inline int idnAgniBreathYards()
    { return 30; }

// the breath does 5-50 points of damage
inline int idnAgniBreathDamage()
    { return 50; }

// the fire chariot ground rate 36 inches
inline int idnAgniChariotGround()
    { return 36; }

// the fire chariot air rate 48 inches
inline int idnAgniChariotAir()
    { return 48; }

// the red horses AC 2
inline int idnAgniHorseAc()
    { return 2; }

// the red horses HD 10
inline int idnAgniHorseHd()
    { return 10; }

// the red horses hp 90
inline int idnAgniHorseHp()
    { return 90; }

// Agni is completely red
inline bool idnAgniCompletelyRed()
    { return true; }

// his main attribute is the control of all forms of fire
inline bool idnAgniFireControl()
    { return true; }

// his axe of flame slays lesser demons and devils on a hit, no saving throw
inline bool idnAgniAxeSlayLesser()
    { return true; }

// the aura destroys any striking weapon of less than +4 bonus
inline bool idnAgniAuraMeltsWeapons()
    { return true; }

// he is able to cure or cause any disease
inline bool idnAgniCureDisease()
    { return true; }

// his voice charms as the charm person or charm monster spell
inline bool idnAgniVoiceCharm()
    { return true; }

// he can shape change at will
inline bool idnAgniShapeChange()
    { return true; }

// his two giant red horses are immune to all forms of heat
inline bool idnAgniHorsesImmuneHeat()
    { return true; }

// ---- Kali ----

// Kali has 3 eyes
inline int idnKaliEyes()
    { return 3; }

// Kali has 4 arms ending in talons
inline int idnKaliArms()
    { return 4; }

// each taloned hand strikes for 4-40 points of damage
inline int idnKaliTalonDamage()
    { return 40; }

// her sword inflicts 2-24 points of damage plus strength bonus
inline int idnKaliSwordDamage()
    { return 24; }

// Kali is the black earth mother, destruction incarnate
inline bool idnKaliBlackEarthMother()
    { return true; }

// her visage causes fear as the spell, save vs. spells negates
inline bool idnKaliVisageFear()
    { return true; }

// she can shape change at will
inline bool idnKaliShapeChange()
    { return true; }

// her worship requires blood sacrifices and even an occasional human
// sacrifice
inline bool idnKaliBloodSacrifice()
    { return true; }

// her cult defenders fight in a berserk suicidal manner until slain
inline bool idnKaliCultBerserk()
    { return true; }

// ---- Karttikeya ----

// Karttikeya has 6 heads
inline int idnKarttikeyaHeads()
    { return 6; }

// Karttikeya has 12 arms
inline int idnKarttikeyaArms()
    { return 12; }

// he carries swords in 10 of his 12 hands
inline int idnKarttikeyaSwords()
    { return 10; }

// each sword strikes for 2-12 points of damage
inline int idnKarttikeyaSwordDamage()
    { return 12; }

// his clerics have a 2 percent chance of requesting aid against devils
inline int idnKarttikeyaAidPct()
    { return 2; }

// the demigod was created to fight devils wherever they are found
inline bool idnKarttikeyaCreatedForDevils()
    { return true; }

// he rides a giant peacock into battle and the bird is his symbol
inline bool idnKarttikeyaRidesPeacock()
    { return true; }

// ---- the Peacock of Karttikeya ----

// the peacock attacks as a 16+ HD monster
inline int idnPeacockHitDice()
    { return 16; }

// the beak strikes for 3-36 points of damage
inline int idnPeacockBeakDamage()
    { return 36; }

// the xp X/12,200 line
inline int idnPeacockXpBase()
    { return 12200; }

// the peacock is said to have feathers made of metal
inline bool idnPeacockMetalFeathers()
    { return true; }

// its beak strikes with the swiftness of lightning at the god enemies
inline bool idnPeacockLightningBeak()
    { return true; }

// it obeys the commands of the god perfectly and can act independently
inline bool idnPeacockIndependent()
    { return true; }

// ---- Lakshmi ----

// the giant floating lotus travels at 75 inches
inline int idnLakshmiLotusSpeed()
    { return 75; }

// Lakshmi appears as a golden-skinned woman
inline bool idnLakshmiGoldenSkin()
    { return true; }

// the giant floating lotus carries only her
inline bool idnLakshmiLotusOnlyHer()
    { return true; }

// Lakshmi always makes her saving throws
inline bool idnLakshmiAlwaysSaves()
    { return true; }

// she is immune to attacks from creatures that are flying
inline bool idnLakshmiImmuneFlying()
    { return true; }

// her right eye grants always-made saves and always-hit for an hour
inline bool idnLakshmiRightEyeLuck()
    { return true; }

// her left eye has the opposite effect, save vs. spells negates either
inline bool idnLakshmiLeftEyeAnti()
    { return true; }

// ---- the Marut ----

// the marut appearing 1-10
inline int idnMarutAppearLo()
    { return 1; }

// the marut appearing 1-10
inline int idnMarutAppearHi()
    { return 10; }

// the marut appearing 10-100 in battles
inline int idnMarutBattleHi()
    { return 100; }

// the marut 25 percent in lair
inline int idnMarutLairPct()
    { return 25; }

// the marut attacks as a 16+ HD monster
inline int idnMarutHitDice()
    { return 16; }

// the xp X/16,700 line
inline int idnMarutXpBase()
    { return 16700; }

// the maruts are humanoids created out of the wind, troops for the gods
inline bool idnMarutWindTroops()
    { return true; }

// they are invisible unless attacking the enemies of the gods
inline bool idnMarutInvisibleUnlessAttacking()
    { return true; }

// they are not subject to the will of any but divine beings, so cannot be
// charmed or enchanted
inline bool idnMarutUncharmable()
    { return true; }

// as wind creatures they naturally have the ability to fly
inline bool idnMarutFly()
    { return true; }

// ---- Ratri ----

// her darkness area is 15 inches radius, no saving throw
inline int idnRatriDarknessRadius()
    { return 15; }

// Ratri appears as a well-proportioned woman
inline bool idnRatriWellProportioned()
    { return true; }

// she permanently blinds any being that crosses her shadow, save vs. spells
inline bool idnRatriShadowBlind()
    { return true; }

// her cloak casts touching objects or persons into the Ethereal Plane, no
// save
inline bool idnRatriCloakEthereal()
    { return true; }

// her physical attack is an angry look from her eyes, once per round
inline bool idnRatriAngryLook()
    { return true; }

// ---- Rudra ----

// the save vs. death at -6 negates his rotting disease
inline int idnRudraSavePenalty()
    { return 6; }

// his black bow shoots arrows of disease like a mummy touch rot
inline bool idnRudraDiseaseArrows()
    { return true; }

// he governs both the spread of disease and its remedies
inline bool idnRudraDiseaseRemedies()
    { return true; }

// he can also create and control storms
inline bool idnRudraStormControl()
    { return true; }

// his treasure hole opens into an area the size of the Grand Canyon
inline bool idnRudraPortableHole()
    { return true; }

// ---- Surya ----

// his sleep ability range 15 inches
inline int idnSuryaSleepRange()
    { return 15; }

// he sleeps any number of 20th level or lesser non-divine beings, no save
inline int idnSuryaSleepLevel()
    { return 20; }

// the +4 shaft of light swordlike weapon
inline int idnSuryaSwordPlus()
    { return 4; }

// the light shaft does 4-40 points of damage per strike
inline int idnSuryaSwordDamage()
    { return 40; }

// it dispels illusions and darkness within 1,000 yards
inline int idnSuryaLightYards()
    { return 1000; }

// his chariot is pulled by 7 magical horses, one per rainbow color
inline int idnSuryaChariotHorses()
    { return 7; }

// against demons the chariot shines for 30 points of heat damage per round
inline int idnSuryaChariotHeat()
    { return 30; }

// the printed 16th level paladin of the FIGHTER line, the R859 paladin
// convention
inline bool idnSuryaPaladin()
    { return true; }

// his sleep ability hits 20th level or lesser non-divine beings with no
// saving throw
inline bool idnSuryaSleepNoSave()
    { return true; }

// he can see anything in the Prime Material Plane the sun shines on
inline bool idnSuryaSeesSunlit()
    { return true; }

// the light shaft acts as a non-negatable continual light spell
inline bool idnSuryaContinualLight()
    { return true; }

// he attacks demons first in any battle where they appear
inline bool idnSuryaDemonsFirst()
    { return true; }

// ---- Tvashtri ----

// the pinwheel nullifies all magic devices in a 200 yard radius
inline int idnTvashtriNullifyYards()
    { return 200; }

// the black beams do 4-40 points of damage and never miss
inline int idnTvashtriBeamDamage()
    { return 40; }

// the black beams reach 30 inches
inline int idnTvashtriBeamRange()
    { return 30; }

// he regenerates 20 lost hit points per melee round from the air
inline int idnTvashtriRegen()
    { return 20; }

// Tvashtri designs objects of great utility and weapons of awesome power
inline bool idnTvashtriArtificerGod()
    { return true; }

// virtually all the gods weapons were his design, so none can hurt him
inline bool idnTvashtriGodWeaponsSafe()
    { return true; }

// his air-grab healing requires all his attention, no attack or defense
inline bool idnTvashtriRegenFullAttention()
    { return true; }

// he is the patron of artisans and inventors, his clerics resourceful and
// original
inline bool idnTvashtriPatronArtisans()
    { return true; }

// ---- Ushas ----

// her brilliant light blinds for 1-4 turns, no save
inline int idnUshasBlindTurns()
    { return 4; }

// she regenerates 30 hit points per round while the sun shines on her
inline int idnUshasRegen()
    { return 30; }

// her gaze does 1-10 points of damage once per round
inline int idnUshasGazeDamage()
    { return 10; }

// she can reincarnate any living thing into any other non-divine living form
inline bool idnUshasReincarnate()
    { return true; }

// she is responsible for the endless reincarnation of the daytime
inline bool idnUshasDawnRespawn()
    { return true; }

// her brilliant light blinds all looking at her, no saving throw
inline bool idnUshasLightBlind()
    { return true; }

// she awakens all dormant good creatures and dispels charm influences
inline bool idnUshasInstantAwakening()
    { return true; }

// ---- Varuna ----

// the 1 percent chance per level that Varuna punishes an oathbreaker
inline int idnVarunaOathPct()
    { return 1; }

// no chaotic non-divine creature approaches within 5 feet of his lawful aura
inline int idnVarunaAuraFeet()
    { return 5; }

// his jet black spear strikes for 5-50 points of damage
inline int idnVarunaSpearDamage()
    { return 50; }

// the printed 14th level paladin of the FIGHTER line
inline bool idnVarunaPaladin()
    { return true; }

// Varuna is the protector of all oaths and the personification of lawfulness
inline bool idnVarunaOathProtector()
    { return true; }

// he can become ethereal at will
inline bool idnVarunaEthereal()
    { return true; }

// his aura of lawfulness bars chaotic non-divine creatures from 5 feet
inline bool idnVarunaLawfulAura()
    { return true; }

// ---- Vishnu ----

// his no-violence aura extends 30 yards, no saving throw
inline int idnVishnuPeaceYards()
    { return 30; }

// the disc weapon fire stream does 5-50 points of damage
inline int idnVishnuDiscDamage()
    { return 50; }

// the disc discharges to a 40 yard maximum range
inline int idnVishnuDiscYards()
    { return 40; }

// the aid chance rises to a 20 percent maximum with worshipers in danger
inline int idnVishnuAidMaxPct()
    { return 20; }

// the lotus flower heals all lost hit points up to three times per day
inline int idnVishnuLotusUses()
    { return 3; }

// a clerical avatar would be 15th level with maximum hit points
inline int idnVishnuAvatarClericLevel()
    { return 15; }

// the clerical avatar carries a wisdom of 25
inline int idnVishnuAvatarWisdom()
    { return 25; }

// the printed 17th level paladin of the FIGHTER line
inline bool idnVishnuPaladin()
    { return true; }

// Vishnu most commonly appears as a normal man with four arms
inline bool idnVishnuFourArms()
    { return true; }

// he can bar any intelligent creature from committing violence within 30
// yards, no save, while he cannot do harm
inline bool idnVishnuNoViolence()
    { return true; }

// he casts double strength prismatic wall spells at will
inline bool idnVishnuPrismaticDouble()
    { return true; }

// undead turn to dust at his glance
inline bool idnVishnuUndeadDust()
    { return true; }

// his mace disintegrates anything it hits, save vs. spells applicable
inline bool idnVishnuMaceDisintegrate()
    { return true; }

// his magical sea shell sends him into the Ethereal Plane when about to be
// killed
inline bool idnVishnuShellEthereal()
    { return true; }

// riding Garuda he is not affected by charm spells of any type
inline bool idnVishnuGarudaCharmImmune()
    { return true; }

// his clerics combat evil with determination but show mercy to redeemable
// defeated opponents
inline bool idnVishnuShowsMercy()
    { return true; }

// ---- Garuda ----

// Garuda carries 5 gods in full battle armor unslowed
inline int idnGarudaCarryGods()
    { return 5; }

// he senses evil within a 1 mile radius
inline int idnGarudaSenseMiles()
    { return 1; }

// each wing batters for 2-24 points of damage
inline int idnGarudaWingDamage()
    { return 24; }

// Garuda fights as a 16+ HD monster
inline int idnGarudaHitDice()
    { return 16; }

// the xp X/17,100 line
inline int idnGarudaXpBase()
    { return 17100; }

// the half-man half-bird hates all things evil with a mad passion
inline bool idnGarudaHatesEvil()
    { return true; }

// he summons 1-10 avian creatures once per day, even over other gods commands
inline bool idnGarudaSummonAvians()
    { return true; }

// he senses any evil creatures or things within a 1 mile radius
inline bool idnGarudaSenseEvil()
    { return true; }

// ---- Yama ----

// the red robes give 100 percent magic resistance
inline int idnYamaRobeMr()
    { return 100; }

// the +5 magical noose
inline int idnYamaNoosePlus()
    { return 5; }

// the noose strangles in 3 melee rounds regardless of hit points
inline int idnYamaNooseRounds()
    { return 3; }

// the +3 mace
inline int idnYamaMacePlus()
    { return 3; }

// the robes flash red 2 melee rounds before any attack, no surprise
inline int idnYamaFlashRounds()
    { return 2; }

// he casts any magic-user spell as if 20th level, if it damages his enemies
inline int idnYamaSpellLevel()
    { return 20; }

// Yama started life as the first mortal and was made immortal for his
// destructiveness
inline bool idnYamaFirstMortal()
    { return true; }

// he is the judge of the dead, deciding the plane of afterlife by the record
// of deeds
inline bool idnYamaJudgeOfDead()
    { return true; }

// the red robes negate all damage from heat, cold and light sources
inline bool idnYamaRobeNegateHeat()
    { return true; }

// the robes let him fly and swim as fast as he moves on land
inline bool idnYamaRobeFly()
    { return true; }

// he enters battle wearing armor of etherealness
inline bool idnYamaEtherealArmor()
    { return true; }

// ---- the Water Buffalo of Yama ----

// the buffalo carries 2 gods in full armor without strain
inline int idnBuffaloCarryGods()
    { return 2; }

// the goring does 4-40 points of damage
inline int idnBuffaloGoreDamage()
    { return 40; }

// it fights as a 16+ HD monster
inline int idnBuffaloHitDice()
    { return 16; }

// the one true-inch size cell: L, 12 inches tall at the shoulders
inline int idnBuffaloShoulderInches()
    { return 12; }

// the xp X/11,500 line
inline int idnBuffaloXpBase()
    { return 11500; }

// it moves over land, air, water or space with ease
inline bool idnBuffaloPlaneTravel()
    { return true; }

// it can pull any weight not attached to the earth
inline bool idnBuffaloPullUnattached()
    { return true; }

// it is slavishly loyal to Yama and will not allow itself to be used by
// others
inline bool idnBuffaloLoyalToYama()
    { return true; }

// it can obey complicated orders from Yama
inline bool idnBuffaloComplexOrders()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Vishnu -5 the best of the gods, Indra the flagged
// em-dash minus twelve odd print, Kali -9; the Buffalo 3 the worst)
inline int idnCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -12;
        case 1:
            return 0;
        case 2:
            return -2;
        case 3:
            return -9;
        case 4:
            return -8;
        case 5:
            return 2;
        case 6:
            return -3;
        case 7:
            return -2;
        case 8:
            return -2;
        case 9:
            return -2;
        case 10:
            return -3;
        case 11:
            return -3;
        case 12:
            return -2;
        case 13:
            return -2;
        case 14:
            return -5;
        case 15:
            return -1;
        case 16:
            return -1;
        case 17:
            return 3;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all eighteen
// read single this round)
inline int idnCbtACAlt(int b)
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

// The hit point cells (Indra 400 the supreme, down to the four 100 hp
// monsters)
inline int idnCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 150;
        case 2:
            return 378;
        case 3:
            return 279;
        case 4:
            return 222;
        case 5:
            return 120;
        case 6:
            return 300;
        case 7:
            return 100;
        case 8:
            return 250;
        case 9:
            return 344;
        case 10:
            return 360;
        case 11:
            return 227;
        case 12:
            return 300;
        case 13:
            return 329;
        case 14:
            return 389;
        case 15:
            return 100;
        case 16:
            return 229;
        case 17:
            return 100;
        default:
            return 0;
        }
    }

// The primary move cells (Kali the flagged 27 odd print without a slash;
// Tvashtri and Yama 15; the Marut the flagged 9 apostrophe print)
inline int idnCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 27;
        case 4:
            return 18;
        case 5:
            return 24;
        case 6:
            return 18;
        case 7:
            return 9;
        case 8:
            return 18;
        case 9:
            return 18;
        case 10:
            return 18;
        case 11:
            return 15;
        case 12:
            return 18;
        case 13:
            return 15;
        case 14:
            return 18;
        case 15:
            return 18;
        case 16:
            return 15;
        case 17:
            return 24;
        default:
            return 0;
        }
    }

// The secondary move cells (Lakshmi the 75 lotus ceiling, Garuda the 48
// flight, the Peacock 24/36; 0 = the single-printed moves)
inline int idnCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 24;
        case 2:
            return 18;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 36;
        case 6:
            return 75;
        case 7:
            return 24;
        case 8:
            return 0;
        case 9:
            return 24;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 24;
        case 13:
            return 24;
        case 14:
            return 27;
        case 15:
            return 48;
        case 16:
            return 0;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (Karttikeya the ten swords, the Elephant 5, Kali 4;
// Lakshmi and Ushas the zero rows)
inline int idnCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 10;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 1;
        default:
            return 0;
        }
    }

// The attack alternative cells (Varuna the one 3/2 slash of the round)
inline int idnCbtAtD(int b)
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
            return 2;
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

// The magic resistance cells (0 = the printed Standard of the Peacock and the
// Buffalo; Lakshmi the 100 ceiling, Vishnu 85, Indra 80; Yama the flagged 25
// with the 100 percent robes note)
inline int idnCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 25;
        case 2:
            return 75;
        case 3:
            return 39;
        case 4:
            return 50;
        case 5:
            return 0;
        case 6:
            return 100;
        case 7:
            return 50;
        case 8:
            return 25;
        case 9:
            return 25;
        case 10:
            return 50;
        case 11:
            return 65;
        case 12:
            return 60;
        case 13:
            return 80;
        case 14:
            return 85;
        case 15:
            return 75;
        case 16:
            return 25;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The size cells in inches (the two pixel-verified X 1/2 foot fractions -
// Ushas 66, Varuna 78; the Buffalo the one true-inch 12 inch shoulders cell;
// Garuda the 720 sixty-footer)
inline int idnCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 72;
        case 1:
            return 240;
        case 2:
            return 120;
        case 3:
            return 240;
        case 4:
            return 240;
        case 5:
            return 240;
        case 6:
            return 72;
        case 7:
            return 72;
        case 8:
            return 60;
        case 9:
            return 72;
        case 10:
            return 120;
        case 11:
            return 72;
        case 12:
            return 66;
        case 13:
            return 78;
        case 14:
            return 72;
        case 15:
            return 720;
        case 16:
            return 84;
        case 17:
            return 12;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (Indra 25 the ceiling, Lakshmi and Surya 20)
inline int idnClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 0;
        case 8:
            return 10;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 15;
        case 12:
            return 20;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 10;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (Kali 10 the in-each pair, Rudra 14 the printed 14th
// level druid)
inline int idnClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 10;
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

// The lower fighter level cells (the three paladin pairs: Surya 16, Varuna
// 14, Vishnu 17)
inline int idnClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 18;
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
            return 16;
        case 11:
            return 11;
        case 12:
            return 0;
        case 13:
            return 14;
        case 14:
            return 17;
        case 15:
            return 0;
        case 16:
            return 14;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The upper fighter level cells (the paladin hi cells; all other fighters
// single-printed, 0)
inline int idnClsFighterHi(int b)
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
            return 16;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 14;
        case 14:
            return 17;
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

// The ranger level cells (none printed this round)
inline int idnClsRanger(int b)
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

// The magic-user level cells (99 = the Agni and Yama printed See below, the
// egp Isis precedent; Vishnu 25 the ceiling)
inline int idnClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 99;
        case 3:
            return 15;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 20;
        case 12:
            return 0;
        case 13:
            return 20;
        case 14:
            return 25;
        case 15:
            return 0;
        case 16:
            return 99;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The illusionist level cells (99 the See below pairs; Rudra 25 the ceiling)
inline int idnClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 99;
        case 3:
            return 15;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 25;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 0;
        case 14:
            return 18;
        case 15:
            return 0;
        case 16:
            return 99;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (Rudra 15 the maximum thieving god, Karttikeya 18)
inline int idnClsThief(int b)
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 15;
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

// The assassin level cells (Kali 15, Ratri 15)
inline int idnClsAssassin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 0;
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

// The monk level cells (Kali 13 the only one printed)
inline int idnClsMonk(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 13;
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

// The bard level cells (Indra 10, Lakshmi 10, Surya 8, Varuna 4)
inline int idnClsBard(int b)
    {
        switch (b) {
        case 0:
            return 10;
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
            return 8;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 4;
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

// The strength cells (the six 25s of Indra, Kali, Karttikeya, Rudra and Agni
// 24; Lakshmi the mortal 10)
inline int idnAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 24;
        case 3:
            return 25;
        case 4:
            return 25;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 19;
        case 9:
            return 21;
        case 10:
            return 24;
        case 11:
            return 19;
        case 12:
            return 17;
        case 13:
            return 23;
        case 14:
            return 23;
        case 15:
            return 0;
        case 16:
            return 21;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The strength to-hit bonuses (0 = the no-printed-bracket rows: Lakshmi and
// the five monsters)
inline int idnAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 6;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 0;
        case 16:
            return 4;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The strength damage bonuses (the four 14s and the Rudra 9)
inline int idnAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 14;
        case 4:
            return 14;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 7;
        case 9:
            return 9;
        case 10:
            return 12;
        case 11:
            return 7;
        case 12:
            return 1;
        case 13:
            return 11;
        case 14:
            return 11;
        case 15:
            return 0;
        case 16:
            return 9;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The intelligence cells (Tvashtri 25 the artificer ceiling, Lakshmi 25; Agni
// 21)
inline int idnAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 21;
        case 3:
            return 18;
        case 4:
            return 20;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 22;
        case 9:
            return 23;
        case 10:
            return 24;
        case 11:
            return 25;
        case 12:
            return 21;
        case 13:
            return 25;
        case 14:
            return 23;
        case 15:
            return 0;
        case 16:
            return 24;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The wisdom cells (Kali the flagged 5 odd print pinned by both voices; the
// four 25s of Indra, Lakshmi, Varuna, Vishnu)
inline int idnAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 5;
        case 4:
            return 16;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 24;
        case 11:
            return 22;
        case 12:
            return 23;
        case 13:
            return 25;
        case 14:
            return 25;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The dexterity cells (Rudra and Ushas 25; Kali 25; the Yama 18 mortal row)
inline int idnAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 25;
        case 3:
            return 25;
        case 4:
            return 25;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 0;
        case 8:
            return 19;
        case 9:
            return 25;
        case 10:
            return 24;
        case 11:
            return 21;
        case 12:
            return 25;
        case 13:
            return 23;
        case 14:
            return 24;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The constitution cells (Indra and Rudra 25; Yama 18)
inline int idnAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 24;
        case 3:
            return 24;
        case 4:
            return 20;
        case 5:
            return 0;
        case 6:
            return 23;
        case 7:
            return 0;
        case 8:
            return 21;
        case 9:
            return 24;
        case 10:
            return 24;
        case 11:
            return 23;
        case 12:
            return 22;
        case 13:
            return 22;
        case 14:
            return 24;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The charisma cells (Kali the minus 7; Vishnu 25; Yama the 18 row)
inline int idnAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return -7;
        case 4:
            return 18;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 23;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 19;
        case 12:
            return 23;
        case 13:
            return 18;
        case 14:
            return 25;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The psionic score cells (0 = every being reads the R849 class table this
// round; no monster point scores printed)
inline int idnAbiPsi(int b)
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

// The roster ordinal cells (the print order, Indra through the Water Buffalo)
inline int idnRosOrd(int b)
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

// The print page cells (75-80, the folio offset PRINT = PDF - 1)
inline int idnRosPage(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 75;
        case 2:
            return 76;
        case 3:
            return 76;
        case 4:
            return 76;
        case 5:
            return 76;
        case 6:
            return 77;
        case 7:
            return 77;
        case 8:
            return 77;
        case 9:
            return 77;
        case 10:
            return 78;
        case 11:
            return 78;
        case 12:
            return 78;
        case 13:
            return 79;
        case 14:
            return 79;
        case 15:
            return 79;
        case 16:
            return 80;
        case 17:
            return 80;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG, 1 NG, 2 CG, 3 LN, 4 N, 5 CN, 6 LE, 7 NE, 8 CE -
// the R852 code scheme)
inline int idnRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 8;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 7;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 4;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 3;
        case 17:
            return 3;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 demigod, 5 monster - no heroes, no
// titans this round)
inline int idnRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 0;
        case 7:
            return 5;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 5;
        case 16:
            return 2;
        case 17:
            return 5;
        default:
            return 0;
        }
    }

// The psionic class cells (the chocr glyph-width decode at 600dpi: the single
// pipe w10 of Agni, Tvashtri, Vishni... corrected: Agni, Tvashtri, Vishnu;
// the Indra TI! w47 three-pipe class III and the Kali III - the R859
// fraction-era calibration; V w36 Ratri, Rudra, Yama; VI w49 Karttikeya,
// Lakshmi, Surya, Ushas, Varuna)
inline int idnRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 0;
        case 6:
            return 6;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 1;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 5;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The plane cells (0 none, 1 Limbo, 2 Gladsheim, 3 the Abyss of Kali, 4 Hades
// of Ratri, 5 Nirvana of Rudra, Varuna, Yama, 6 the Seven Heavens of Surya,
// Vishnu, Garuda, 7 Elysium of Ushas, 8 Concordant Opposition of Tvashtri)
inline int idnRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 8;
        case 12:
            return 7;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 0;
        case 16:
            return 5;
        case 17:
            return 0;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed numeric damage; 0 = the Marut
// by-weapon row and the Lakshmi and Ushas Nil rows)
inline int idnRosDmgFixed(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
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
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells: Indra MU/I, Kali
// C/D and MU/I, Lakshmi MU/I)
inline int idnRosInEach(int b)
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
            return 0;
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

// The enmity flags (none printed this round: zero flags)
inline int idnRosEnmity(int b)
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

}   // namespace rules
