// =========================================================================================
// Adnd1 - rules/dgf.h
// the Central American mythos - the D&DG walk round six, print pp. 32-36:
// fourteen beings from Quetzalcoatl the Law Giver to Xochipilli the Lord of
// Flowers, the twin heroes Hunapu and Xbalanque, the elite-cleric doctrine
// with its compass directions, and the one parallel Prime Material Plane the
// whole mythos dwells on.
// census 776 -> 777.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 033-037; the second printing); the
// collation voice: the archive.org 1st-print derivative
// (deities-demigods-1st-print, djvu.txt + djvu.xml word geometry at 600dpi).
// The adjudications: the Tezcatlipoca psionic class II (the 28px two-glyph IA
// word against the Termux single I), the Tlazolteotl hit points (the
// 2nd-print 211 pinned against the IA 1st-print 217 - a genuine print
// divergence, the Gawaine 112 precedent, flagged for the physical-copy
// eyeball), the size decodes (Chalchiuhtlicue 6 foot 4 and the twins 5 foot 4
// - the R853 foot-mark-misread lesson, the 149px six-glyph cells; Camazotz,
// Huhueteotl, Huitzilopochtli, Mictlantecuhtli and Tlaloc the 15-foot cells,
// Xochipilli the printed 16 feet), and the Tlazolteotl charisma 24/-5 (the
// Termux clean read over the IA garble).
//
namespace rules {

// ---- the R854 census ----

// the Central American mythos round: the D&DG walk round six, print pp. 32-36
inline int dgfRound()
    { return 854; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int dgfPrintStart()
    { return 32; }

// the last print page
inline int dgfPrintEnd()
    { return 36; }

// the fourteen beings of the mythos (Quetzalcoatl through Xochipilli, the
// twin heroes counted separately)
inline int dgfBeingCount()
    { return 14; }

// the four grids (combat, class, ability, roster)
inline int dgfTableCount()
    { return 4; }

// no chains this round
inline int dgfChainCount()
    { return 0; }

// zero registry defs touched - the floor holds at 995
inline int dgfRegistryFloor()
    { return 995; }

// the combat grid rows
inline int dgfCbtRows()
    { return 14; }

// the class grid rows
inline int dgfClsRows()
    { return 14; }

// the ability grid rows
inline int dgfAbiRows()
    { return 14; }

// the roster grid rows
inline int dgfRosRows()
    { return 14; }

// the one printed plane: a parallel Prime Material Plane (the whole mythos)
inline int dgfPlaneCount()
    { return 1; }

// the printed psionic class I (eleven of the fourteen read the single-glyph
// bar)
inline int dgfPsiClassI()
    { return 1; }

// Tezcatlipoca reads the printed class II (the 28px two-glyph IA word against
// the Termux single I)
inline int dgfPsiClassII()
    { return 2; }

// Itzamna reads the printed class VI (the 51px two-glyph word, both voices)
inline int dgfPsiClassVI()
    { return 6; }

// rituals are performed every 20 days
inline int dgfRitualPeriodDays()
    { return 20; }

// when the facing direction is not chosen, the DM rolls a 4-sided die for the
// compass point
inline int dgfCompassDieSides()
    { return 4; }

// attacks made in the cleric's own compass direction gain +1 to hit
inline int dgfCompassHitPlus()
    { return 1; }

// spells cast in the cleric's own compass direction subtract 1 from the
// target's saving throw
inline int dgfCompassSaveMinus()
    { return 1; }

// ---- the mythos intro ----

// the Aztec and Maya presented closely related gods with a moral background
// like other mythoi
inline bool dgfAztecMayaMoralBackground()
    { return true; }

// the beings are just as evil or good, but are not moved by anything
// resembling human thoughts - they act on inscrutable motives
inline bool dgfInscrutableMotives()
    { return true; }

// these beings are said to have come from the stars
inline bool dgfFromTheStars()
    { return true; }

// their plane of origin: the Prime Material Plane of a parallel universe
inline bool dgfParallelPrimeMaterial()
    { return true; }

// commune or gate spells of these clerics connect only with the parallel
// universe and the plane where their gods dwell
inline bool dgfCommuneGateParallelOnly()
    { return true; }

// others cannot summon these deities without the special ceremonies used in
// contacting them
inline bool dgfNoSummonWithoutCeremonies()
    { return true; }

// the deities cannot travel on any planes but the ones they have worshipers
// on
inline bool dgfNoTravelBeyondWorshipers()
    { return true; }

// the clerics of this mythos are the elite of the populace
inline bool dgfEliteClerics()
    { return true; }

// even the lowest-level clerics have absolute authority over any of the
// peasants
inline bool dgfAbsoluteAuthorityOverPeasants()
    { return true; }

// any cleric of a higher level may give orders to lesser clerics of the same
// deity with complete freedom
inline bool dgfHigherLevelsCommandLesser()
    { return true; }

// all sects must usually work together, but there is much clandestine
// infighting for followers among rich and poor alike
inline bool dgfSectInfighting()
    { return true; }

// sacrifices take many forms: food in the spring and fall seasons
inline bool dgfSacrificeFoodSpringFall()
    { return true; }

// humans are sacrificed before and after battles and during the rainy winter
// months
inline bool dgfSacrificeHumansBattles()
    { return true; }

// the public is forced to attend these rituals, always held at the temple of
// the appropriate god
inline bool dgfForcedAttendance()
    { return true; }

// all temples are built on the step pyramid design
inline bool dgfTempleStepPyramid()
    { return true; }

// the temples have entrances at the bottom at the four compass points
inline bool dgfEntrancesFourCompassPoints()
    { return true; }

// the altar at the top sits east of the entrances line of the printed
// doctrine
inline bool dgfAltarTopEast()
    { return true; }

// divine punishment of erring clerics is swift
inline bool dgfPunishmentSwift()
    { return true; }

// small mistakes (broken clerical laws, duels lost) cost some wealth and/or
// experience points
inline bool dgfMinorMistakesCostWealthXP()
    { return true; }

// major failures (lost battles, failed quests, alignment changes) strip all
// possessions and levels - restart from first level
inline bool dgfMajorFailuresStripAll()
    { return true; }

// first level clerics choose a compass direction they pray to, meditate
// towards, and start quests towards
inline bool dgfCompassDirectionChosen()
    { return true; }

// clerics of the east wear red clothes at all times
inline bool dgfEastRed()
    { return true; }

// clerics of the south wear yellow
inline bool dgfSouthYellow()
    { return true; }

// clerics of the west wear black
inline bool dgfWestBlack()
    { return true; }

// clerics of the north wear white
inline bool dgfNorthWhite()
    { return true; }

// ---- the Quetzalcoatl walk ----

// Quetzalcoatl, god of the air, the Law Giver, also known as Kukulcan or (as
// wind god) Ehecatl
inline bool dgfQuetzalcoatlAirGod()
    { return true; }

// he appears in a bewildering number of forms, usually acting per his
// alignment but at times in chaotic or evil ways
inline bool dgfQuetzalcoatlBewilderingForms()
    { return true; }

// he appears occasionally on our plane and works closely with his worshipers
// against other gods
inline bool dgfQuetzalcoatlWorksWithWorshipers()
    { return true; }

// in battle he usually assumes a monster form and attacks with it
inline bool dgfQuetzalcoatlMonsterFormBattle()
    { return true; }

// if he suffers a great loss of hit points, he takes his beginning-of-battle
// form, quadruples its powers, and re-attacks
inline bool dgfQuetzalcoatlQuadrupleOnLoss()
    { return true; }

// he fights until his side has won or he has been personally defeated
inline bool dgfQuetzalcoatlFightsToEnd()
    { return true; }

// he cannot be hurt by creatures of the same form he is using - as a dragon
// immune to dragon types, as a magic-user immune to magical spells
inline bool dgfQuetzalcoatlSameFormImmune()
    { return true; }

// he was the mightiest god of the mythos, though the claim is disputed by the
// followers of Tezcatlipoca, his arch-enemy
inline bool dgfQuetzalcoatlMightiestDisputed()
    { return true; }

// he is patron of the arts and the founder of metallurgy
inline bool dgfQuetzalcoatlPatronOfArts()
    { return true; }

// ---- the Camaxtli walk ----

// sacrifices to Camaxtli are precious metals worth 500,000 gold pieces or
// more
inline int dgfCamaxtliSacrificeGP()
    { return 500000; }

// a 25% chance the god looks favorably on the sacrificer and helps for a
// short period
inline int dgfCamaxtliFavorPct()
    { return 25; }

// in the presence of any light, Camaxtli regenerates 5 hit points per melee
// round
inline int dgfCamaxtliRegenPerMelee()
    { return 5; }

// Camaxtli, god of fate, human-appearing
inline bool dgfCamaxtliFateGod()
    { return true; }

// he is able to see the past and future of any being and put the information
// to use in his own way
inline bool dgfCamaxtliSeesPastFuture()
    { return true; }

// he is not allowed to kill any being
inline bool dgfCamaxtliNotAllowedToKill()
    { return true; }

// he looks into a being's past, finds the force that did the most physical
// damage, and recreates that force exactly to do the same damage again
inline bool dgfCamaxtliRecreatesDamageForce()
    { return true; }

// the sacrifice is always cast into the beyond by the most powerful means
// available (a random teleport, a limited wish, or the like)
inline bool dgfCamaxtliCastIntoBeyond()
    { return true; }

// ---- the Chalchiuhtlicue walk ----

// she can transform 3-300 beings into any single form she wishes (usually
// fish)
inline int dgfChalchiuhtlicueTransformLo()
    { return 3; }

// the transform count ceiling
inline int dgfChalchiuhtlicueTransformHi()
    { return 300; }

// the jade ritual: no other being within a mile of the area
inline int dgfChalchiuhtlicueRitualClearMiles()
    { return 1; }

// clerics performing the ceremony for the needy have a 25% chance of success
inline int dgfChalchiuhtlicueClericPct()
    { return 25; }

// normal worshipers have only a 1% chance of success
inline int dgfChalchiuhtlicueWorshiperPct()
    { return 1; }

// the ritual may be attempted four times a year
inline int dgfChalchiuhtlicueAttemptsPerYear()
    { return 4; }

// Chalchiuhtlicue, goddess of running water and love, the goddess of the jade
// petticoat
inline bool dgfChalchiuhtlicueWaterLove()
    { return true; }

// she is not only a water deity: the goddess of life and chaste love
inline bool dgfChalchiuhtlicueLifeAndChasteLove()
    { return true; }

// those that sacrifice to her (of any alignment) can expect help if the
// proper forms are observed, especially for healing or love
inline bool dgfChalchiuhtlicueAidsAnyAlignment()
    { return true; }

// the transform ability is used only to save the lives of devout worshipers
inline bool dgfChalchiuhtlicueTransformSavesDevout()
    { return true; }

// the ritual sacrifice: tossing jade (the higher the quality the better the
// response) into a bottomless pool of water in the mountains
inline bool dgfChalchiuhtlicueJadeQuality()
    { return true; }

// the ritual is done by the light of the full moon
inline bool dgfChalchiuhtlicueFullMoonRitual()
    { return true; }

// Chalchiuhtlicue is the wife of Tlaloc
inline bool dgfChalchiuhtlicueWifeOfTlaloc()
    { return true; }

// ---- the Camazotz walk ----

// Camazotz is always found with 1,000 normal bats flying around him
inline int dgfCamazotzBatCount()
    { return 1000; }

// his claws do 2-20 per strike (each of the two)
inline int dgfCamazotzClawDmgLo()
    { return 2; }

// the claw damage ceiling
inline int dgfCamazotzClawDmgHi()
    { return 20; }

// his bite does 3-30
inline int dgfCamazotzBiteDmgLo()
    { return 3; }

// the bite damage ceiling
inline int dgfCamazotzBiteDmgHi()
    { return 30; }

// Camazotz, the bat god, appears as a huge bat
inline bool dgfCamazotzBatGod()
    { return true; }

// he may be tempted to comply to a summons by a being that offers many
// insects for his followers
inline bool dgfCamazotzInsectTemptation()
    { return true; }

// priests can actually appease this deity by offering him insect plagues
inline bool dgfCamazotzInsectPlagueAppeasement()
    { return true; }

// a save is necessary versus (paralytic) poison on claws and bite alike
inline bool dgfCamazotzParalyticSave()
    { return true; }

// any weapons cast in the darkness at him will not touch or harm him
inline bool dgfCamazotzDarknessWeaponsPass()
    { return true; }

// ---- the Huhueteotl walk ----

// Huhueteotl casts a beam of searing light once per round doing 50 points of
// damage per strike
inline int dgfHuhueteotlBeamDamage()
    { return 50; }

// the beam has a range of 2 miles
inline int dgfHuhueteotlBeamRangeMiles()
    { return 2; }

// the god keeps time in motion and must have a special sacrifice of gems,
// feather robes, and humans every 52 years
inline int dgfHuhueteotlTimeCycleYears()
    { return 52; }

// Huhueteotl, the fire god: a demon with humanoid body, reptilian facial
// features, flames shooting all around, hair patches where the red gem armor
// does not cover
inline bool dgfHuhueteotlFireGod()
    { return true; }

// the god requires frequent human sacrifices
inline bool dgfHuhueteotlFrequentSacrifices()
    { return true; }

// he punishes erring worshipers with destructive flames whenever a whim takes
// him
inline bool dgfHuhueteotlPunishesWithFlames()
    { return true; }

// sacrifices are valuable articles of clothing or gems and jewels, thrown
// into molten areas in mountains
inline bool dgfHuhueteotlClothingGemsSacrifice()
    { return true; }

// sacrifices are usually made in the waning of the moon
inline bool dgfHuhueteotlWaningMoon()
    { return true; }

// during the fifty-second year the god can stop the motion of any one thing
// in any single day
inline bool dgfHuhueteotlStopMotion()
    { return true; }

// in the stopped state, that thing cannot be harmed by any force in the Prime
// Material Plane
inline bool dgfHuhueteotlStoppedImmune()
    { return true; }

// ---- the Huitzilopochtli walk ----

// his battle axe does 3-30 points (plus strength bonus) with each of his 3
// strikes per melee round
inline int dgfHuitzilopochtliAxeDmgLo()
    { return 3; }

// the axe damage ceiling
inline int dgfHuitzilopochtliAxeDmgHi()
    { return 30; }

// the printed (+14) on the axe line - matching the S:25(+7,+14) damage
// bracket
inline int dgfHuitzilopochtliAxeStrBonus()
    { return 14; }

// when the god chooses to appear for a battle: a 5% chance
inline int dgfHuitzilopochtliAppearPct()
    { return 5; }

// the raised dead warrior lives a long and lucky life: +3 on all saving
// throws
inline int dgfHuitzilopochtliRaisedSaveBonus()
    { return 3; }

// Huitzilopochtli, god of war, depicted fully armed in blue jade armor,
// bright red axe, hummingbird-feather headdress
inline bool dgfHuitzilopochtliWarGod()
    { return true; }

// he may appear on any battlefield where his worshipers are fighting and aid
// them - but not so as to make sure his side wins
inline bool dgfHuitzilopochtliBattlefieldAid()
    { return true; }

// he can rarely be called upon for any non-warlike situation and can never be
// communed with
inline bool dgfHuitzilopochtliNeverCommuned()
    { return true; }

// all attacks on his rear will return on the attacker and never miss
inline bool dgfHuitzilopochtliRearAttacksReturn()
    { return true; }

// sacrifices are made to him only in battle and only by fighting clerics
inline bool dgfHuitzilopochtliBattleSacrifices()
    { return true; }

// when he appears, he takes the body of a dead warrior that won great
// victories during that battle or in the past
inline bool dgfHuitzilopochtliDeadWarriorBody()
    { return true; }

// no matter the outcome (win, lose, or draw) that warrior will be raised and
// live a long and lucky life
inline bool dgfHuitzilopochtliRaisedRegardless()
    { return true; }

// ---- the Hunapu and Xbalanque walk ----

// the twin heroes could shoot their blowgun darts up to 200 yards away with
// accuracy
inline int dgfTwinBlowgunRangeYards()
    { return 200; }

// the blowgun short range: 50 yards
inline int dgfTwinBlowgunShortYards()
    { return 50; }

// the blowgun medium range: 135 yards
inline int dgfTwinBlowgunMediumYards()
    { return 135; }

// in hand-to-hand combat they use axes which inflict 1-10 points of damage
inline int dgfTwinAxeDmgLo()
    { return 1; }

// the hand axe damage ceiling
inline int dgfTwinAxeDmgHi()
    { return 10; }

// the printed (+6) on the damage line - the 18(00) strength bracket damage
// bonus
inline int dgfTwinAxePlus()
    { return 6; }

// they are resistant to cold and fire: one point is subtracted from every die
// of damage they take
inline int dgfTwinResistPerDie()
    { return 1; }

// Hunapu and Xbalanque, the twin brothers, 150 hit points each
inline bool dgfTwinHeroes()
    { return true; }

// the twins are legendary for their thirst for revenge
inline bool dgfTwinRevengeThirst()
    { return true; }

// their father was killed by beings of the underworld; they went down and
// defeated these beings in games and battle
inline bool dgfTwinUnderworldVictory()
    { return true; }

// they were expert with the blow gun
inline bool dgfTwinBlowgunExperts()
    { return true; }

// they try hard not to get close enough to be forced into hand-to-hand combat
inline bool dgfTwinAvoidMelee()
    { return true; }

// their special attack: poisoned blow gun darts
inline bool dgfTwinPoisonedDarts()
    { return true; }

// ---- the Itzamna walk ----

// if battle is forced on him he strikes with his staff or scintillating beams
// of light for 3-24 points of damage
inline int dgfItzamnaStaffDmgLo()
    { return 3; }

// the staff/beam damage ceiling
inline int dgfItzamnaStaffDmgHi()
    { return 24; }

// when attacked he becomes surrounded by a nimbus of light: a protection from
// evil 6' radius
inline int dgfItzamnaNimbusRadiusFeet()
    { return 6; }

// in light form Itzamna is intangible: it requires +2 or better magical
// weapons to strike him
inline int dgfItzamnaWeaponPlusToHit()
    { return 2; }

// Itzamna, god of medicine, normally appears as a toothless old man with
// sunken cheeks and a Roman nose, leaning on a crooked staff
inline bool dgfItzamnaMedicineGod()
    { return true; }

// he may assume the form of light in one of its myriad aspects - a blazing
// globe, a fading ember, a dusty moonbeam - and then may take on any size
inline bool dgfItzamnaLightForms()
    { return true; }

// Itzamna often travels in the world of men
inline bool dgfItzamnaTravelsWorldOfMen()
    { return true; }

// he may see everything that transpires in the world if there is a light
// source present, much like a wizard eye spell
inline bool dgfItzamnaSeesAllWithLight()
    { return true; }

// he is the friend and benefactor of men, instructing mankind in medicine,
// drawing and letters
inline bool dgfItzamnaFriendOfMen()
    { return true; }

// his clerics call on him to intercede for man with the other gods in times
// of calamities and sicknesses
inline bool dgfItzamnaIntercedes()
    { return true; }

// in his dealings with other gods he rarely relies on the strength of his
// arms, using his wits to move them favorably towards man
inline bool dgfItzamnaWitsOverArms()
    { return true; }

// Itzamna is the son of the sun-god Tezcatlipoca and tries to temper his
// father's harsh dealings with man
inline bool dgfItzamnaSonOfTezcatlipoca()
    { return true; }

// if ever in a desperate situation he will call upon his father for help
inline bool dgfItzamnaCallsFather()
    { return true; }

// the nimbus also acts as a robe of scintillating colors
inline bool dgfItzamnaNimbusRobe()
    { return true; }

// he is capable of drawing any one symbol per round in the air
inline bool dgfItzamnaDrawsSymbols()
    { return true; }

// his clerics deal only with spells to bless and heal (abjuration and
// necromancy) or spells of a written nature (symbols)
inline bool dgfItzamnaClericSpells()
    { return true; }

// these clerics wear few garments or just a coarse robe and carry a staff and
// medicine pouch
inline bool dgfItzamnaClericGarb()
    { return true; }

// they may be identified by a necklace with a red hand ornament, and are
// usually excellent scribes
inline bool dgfItzamnaRedHandNecklace()
    { return true; }

// ceremonies are held throughout the year, particularly at crop planting:
// sweet balsam is burned and squirrels are sacrificed
inline bool dgfItzamnaBalsamSquirrels()
    { return true; }

// ---- the Tezcatlipoca walk ----

// in jaguar or bear form he strikes with his claws for 3-30 points of damage
// each
inline int dgfTezcatlipocaClawDmgLo()
    { return 3; }

// the claw damage ceiling
inline int dgfTezcatlipocaClawDmgHi()
    { return 30; }

// Tezcatlipoca (the smoking mirror), god of the sun who ripens the crops but
// also brings drought and famine, also the god of the moon and the night
inline bool dgfTezcatlipocaSunGod()
    { return true; }

// he and his followers are always plotting the overthrow of Quetzalcoatl
inline bool dgfTezcatlipocaPlotsOverthrow()
    { return true; }

// he is the patron of treacherous schemings and betrayals
inline bool dgfTezcatlipocaPatronOfTreachery()
    { return true; }

// he rarely takes on physical form, preferring to remain invisible and
// ethereal
inline bool dgfTezcatlipocaInvisibleEthereal()
    { return true; }

// when he does take form it is usually as a giant jaguar or bear
inline bool dgfTezcatlipocaJaguarBear()
    { return true; }

// he occasionally takes human form to masquerade as someone else in
// furtherance of one of his schemes
inline bool dgfTezcatlipocaHumanMasquerade()
    { return true; }

// once a year at a great religious gathering his priests sacrifice a young,
// perfect human male and offer the god his heart
inline bool dgfTezcatlipocaAnnualHeartSacrifice()
    { return true; }

// the sacrifices (usually war prisoners) are pampered and feted for a full
// year, given almost anything - and always end up on the altar
inline bool dgfTezcatlipocaPamperedVictim()
    { return true; }

// he is a spreader of disorder and war, but also an originator of wealth
inline bool dgfTezcatlipocaDisorderAndWealth()
    { return true; }

// ---- the Mictlantecuhtli walk ----

// at any given time he can instantly summon 20-200 skeletons
inline int dgfMictlantecuhtliSkeletonLo()
    { return 20; }

// the skeleton summon ceiling
inline int dgfMictlantecuhtliSkeletonHi()
    { return 200; }

// he can summon 10-100 ghouls
inline int dgfMictlantecuhtliGhoulLo()
    { return 10; }

// the ghoul summon ceiling
inline int dgfMictlantecuhtliGhoulHi()
    { return 100; }

// he can summon 6-36 wights
inline int dgfMictlantecuhtliWightLo()
    { return 6; }

// the wight summon ceiling
inline int dgfMictlantecuhtliWightHi()
    { return 36; }

// he can summon 2-5 spectres
inline int dgfMictlantecuhtliSpectreLo()
    { return 2; }

// the spectre summon ceiling
inline int dgfMictlantecuhtliSpectreHi()
    { return 5; }

// he can be summoned only after at least 50 live human sacrifices have been
// given the god in worship
inline int dgfMictlantecuhtliSacrificeGate()
    { return 50; }

// Mictlantecuhtli, god of death, usually appears in a lich form
inline bool dgfMictlantecuhtliDeathGod()
    { return true; }

// no undead is able to resist his commands
inline bool dgfMictlantecuhtliCommandsUndead()
    { return true; }

// the god demands these lives during the dark of the moon
inline bool dgfMictlantecuhtliDarkOfMoon()
    { return true; }

// he requires the sacrifices from the ranks of his worshipers
inline bool dgfMictlantecuhtliFromWorshipers()
    { return true; }

// in battle, touching his body with anything causes the toucher to make a
// saving throw versus death
inline bool dgfMictlantecuhtliTouchDeath()
    { return true; }

// he will usually attack with spells when personally in battle
inline bool dgfMictlantecuhtliSpellsInBattle()
    { return true; }

// if enemies dare touch him, he draws out a red jade rod that acts as a
// hammer of thunderbolts per the DUNGEON MASTERS GUIDE
inline bool dgfMictlantecuhtliJadeRod()
    { return true; }

// ---- the Tlaloc walk ----

// Tlaloc has four pitchers of water
inline int dgfTlalocPitcherCount()
    { return 4; }

// his lightning bolt does 40 points of damage to all those in armor
inline int dgfTlalocLightningArmor()
    { return 40; }

// 30 points of damage to all those wearing clothes
inline int dgfTlalocLightningClothed()
    { return 30; }

// 20 points of damage to all naked flesh it hits
inline int dgfTlalocLightningNaked()
    { return 20; }

// Tlaloc, rain god, with great tusks and goggle eyes, wearing all black but
// for a garland of white feathers
inline bool dgfTlalocRainGod()
    { return true; }

// at each full moon a priest of Tlaloc sacrifices a child or baby to him
inline bool dgfTlalocFullMoonChild()
    { return true; }

// once a year a great festival is held in his honor: numerous babies are
// bought or taken from the populace
inline bool dgfTlalocAnnualFestival()
    { return true; }

// the babies are sacrificed to Tlaloc, after which the priests cook and eat
// them
inline bool dgfTlalocCookAndEat()
    { return true; }

// if the babies cry during the sacrifice, this is a good sign that rain will
// be abundant in the coming year
inline bool dgfTlalocCryingGoodSign()
    { return true; }

// if the proper rituals and sacrifices have been followed to the letter, he
// will usually grant the rain his worshipers need
inline bool dgfTlalocGrantsRain()
    { return true; }

// if he thinks his requirements have not been met, the people will be
// punished
inline bool dgfTlalocPunishes()
    { return true; }

// one pitcher is filled with good water to make crops grow properly
inline bool dgfTlalocPitcherGood()
    { return true; }

// one with water that contains spiders' eggs and webs and causes blight
inline bool dgfTlalocPitcherBlight()
    { return true; }

// one with water that turns to frost
inline bool dgfTlalocPitcherFrost()
    { return true; }

// one with water that rots all fruit
inline bool dgfTlalocPitcherRot()
    { return true; }

// if pressed hard in battle he summons a bolt of lightning and fights with it
// against all comers - used as a weapon, not a spell
inline bool dgfTlalocBoltAsWeapon()
    { return true; }

// ---- the Tlazolteotl walk ----

// the printed CH: 24/-5 charisma line - the -5 alternative (the Termux clean
// read; the IA garbles identically)
inline int dgfTlazolteotlChaAlt()
    { return -5; }

// Tlazolteotl, goddess of vice
inline bool dgfTlazolteotlViceGoddess()
    { return true; }

// under stress, rushed, or attacked she appears as an incredible monster -
// humanoid body, demonic fanged face, blazing eyes, talons, black warty
// greasy skin. This is an illusion
inline bool dgfTlazolteotlMonsterIllusion()
    { return true; }

// at ease, before her worshipers, working on a victim, or among strangers,
// she appears as a beautiful woman inspiring desire in any male and jealous
// respect from any female
inline bool dgfTlazolteotlBeautifulAtEase()
    { return true; }

// she tries very hard to ruin lawful good beings all over the Prime Material
// Plane, tempting them and destroying them when they succumb
inline bool dgfTlazolteotlRuinsLawfulGood()
    { return true; }

// though she may assassinate, she will never fight physically; if met with
// beings that cannot be hurt by spells she teleports away
inline bool dgfTlazolteotlNeverFightsPhysically()
    { return true; }

// her favorite attack is charm spells of all sorts
inline bool dgfTlazolteotlCharmFavorite()
    { return true; }

// no evil being can even think of harming her, even if they are magically
// controlled
inline bool dgfTlazolteotlEvilCannotHarm()
    { return true; }

// ---- the Xochipilli walk ----

// Xochipilli's hand axe causes 3-30 points of damage per strike
inline int dgfXochipilliAxeDmgLo()
    { return 3; }

// the hand axe damage ceiling
inline int dgfXochipilliAxeDmgHi()
    { return 30; }

// Xochipilli, god of gambling and chance, the Lord of Flowers, almost always
// appears as a young man
inline bool dgfXochipilliGamblingGod()
    { return true; }

// he wanders among the people bestowing good and bad luck in the form of lost
// or granted saving throws
inline bool dgfXochipilliWanderingLuck()
    { return true; }

// he is predominantly a peaceful being that gives a great deal of happiness
// to his followers
inline bool dgfXochipilliPeaceful()
    { return true; }

// the god is most pleased with beings that take a large calculated risk
inline bool dgfXochipilliCalculatedRisk()
    { return true; }

// his hand axe never misses
inline bool dgfXochipilliNeverMisses()
    { return true; }

// any weapon that has a chance of missing him will miss
inline bool dgfXochipilliWeaponsMiss()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Xochipilli the printed -5, the best of the mythos;
// Huitzilopochtli and Itzamna -3)
inline int dgfCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -2;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return -3;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return -3;
        case 9:
            return -2;
        case 10:
            return -2;
        case 11:
            return -2;
        case 12:
            return -3;
        case 13:
            return -5;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all fourteen
// read single this round)
inline int dgfCbtACAlt(int b)
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
        default:
            return 0;
        }
    }

// The hit point cells (400 for Quetzalcoatl and Tezcatlipoca down to 150 per
// twin hero)
inline int dgfCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 350;
        case 2:
            return 200;
        case 3:
            return 362;
        case 4:
            return 373;
        case 5:
            return 389;
        case 6:
            return 150;
        case 7:
            return 150;
        case 8:
            return 369;
        case 9:
            return 400;
        case 10:
            return 339;
        case 11:
            return 377;
        case 12:
            return 211;
        case 13:
            return 381;
        default:
            return 0;
        }
    }

// The primary move cells (-1 = the printed Infinite move; the numeric moves:
// Camaxtli 15, Huhueteotl 18, the 12s)
inline int dgfCbtMove(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 15;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 18;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return -1;
        case 9:
            return -1;
        case 10:
            return -1;
        case 11:
            return 12;
        case 12:
            return -1;
        case 13:
            return -1;
        default:
            return 0;
        }
    }

// The secondary move cells (24 the printed slash ceiling; 0 = a single
// printed move)
inline int dgfCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 24;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 24;
        case 5:
            return 24;
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
            return 24;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (0 = the printed 0, the printed Variable
// (Quetzalcoatl), or the printed See below)
inline int dgfCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 0;
        case 13:
            return 3;
        default:
            return 0;
        }
    }

// The attack slash cells (2 = the printed 3/2; 0 = a single printed attack
// number)
inline int dgfCbtAtD(int b)
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
            return 2;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 2;
        default:
            return 0;
        }
    }

// The magic resistance cells (0 = the printed Standard of the twin heroes,
// the R849 standard doctrine)
inline int dgfCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 50;
        case 2:
            return 95;
        case 3:
            return 50;
        case 4:
            return 80;
        case 5:
            return 50;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 85;
        case 9:
            return 85;
        case 10:
            return 95;
        case 11:
            return 50;
        case 12:
            return 25;
        case 13:
            return 25;
        default:
            return 0;
        }
    }

// The size cells in inches (180 = the printed 15 feet, 192 Xochipilli 16
// feet, 76 Chalchiuhtlicue 6'4", 64 the twins 5'4"; 0 = the printed Variable)
inline int dgfCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 180;
        case 1:
            return 180;
        case 2:
            return 76;
        case 3:
            return 180;
        case 4:
            return 180;
        case 5:
            return 180;
        case 6:
            return 64;
        case 7:
            return 64;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 180;
        case 11:
            return 180;
        case 12:
            return 180;
        case 13:
            return 192;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (0 = Nil; Quetzalcoatl the 25th level cleric)
inline int dgfClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 13;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 22;
        case 9:
            return 9;
        case 10:
            return 14;
        case 11:
            return 20;
        case 12:
            return 14;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// The druid level cells (0 = Nil; the in-each 13s and 14s, the twins 10th
// level druids)
inline int dgfClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 10;
        case 5:
            return 13;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 14;
        case 11:
            return 0;
        case 12:
            return 14;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// The fighter level floor cells (0 = the printed Nil of Tlazolteotl and the
// ranger-slot beings)
inline int dgfClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 12;
        case 2:
            return 12;
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
            return 13;
        case 9:
            return 20;
        case 10:
            return 0;
        case 11:
            return 10;
        case 12:
            return 0;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells (single printed levels read floor =
// ceiling)
inline int dgfClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 12;
        case 2:
            return 12;
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
            return 13;
        case 9:
            return 20;
        case 10:
            return 0;
        case 11:
            return 10;
        case 12:
            return 0;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// The ranger level cells (Huitzilopochtli 20, the twins 10, Mictlantecuhtli
// 15 - the ranger fighter slots)
inline int dgfClsRanger(int b)
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
            return 20;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells
inline int dgfClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 18;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 15;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 15;
        case 9:
            return 15;
        case 10:
            return 18;
        case 11:
            return 20;
        case 12:
            return 15;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// The illusionist level cells (Tlazolteotl the 25th level illusionist over
// her 15th magic-user)
inline int dgfClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 20;
        case 4:
            return 15;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 18;
        case 11:
            return 0;
        case 12:
            return 25;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// The thief level cells (0 = Nil; Xochipilli the 12th level thief,
// Quetzalcoatl the 20th)
inline int dgfClsThief(int b)
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
            return 12;
        default:
            return 0;
        }
    }

// The assassin level cells (the 15s across the evil gods; Xochipilli 0)
inline int dgfClsAssassin(int b)
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
            return 15;
        case 5:
            return 15;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 15;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (Huhueteotl and Huitzilopochtli 10th; Xochipilli 12th)
inline int dgfClsMonk(int b)
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
            return 10;
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
            return 12;
        default:
            return 0;
        }
    }

// The bard level cells (Quetzalcoatl 20th, Chalchiuhtlicue 15th; Tezcatlipoca
// the 6th level bard)
inline int dgfClsBard(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 15;
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
            return 6;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the 25s of Quetzalcoatl, Huitzilopochtli and
// Tezcatlipoca; Tlazolteotl the printed S:10)
inline int dgfAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 15;
        case 3:
            return 19;
        case 4:
            return 23;
        case 5:
            return 25;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 21;
        case 9:
            return 25;
        case 10:
            return 25;
        case 11:
            return 20;
        case 12:
            return 10;
        case 13:
            return 24;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = no printed bracket)
inline int dgfAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 7;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 3;
        case 12:
            return 0;
        case 13:
            return 6;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells (the +14 brackets matching
// S:25)
inline int dgfAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 7;
        case 4:
            return 0;
        case 5:
            return 14;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 9;
        case 9:
            return 14;
        case 10:
            return 14;
        case 11:
            return 8;
        case 12:
            return 0;
        case 13:
            return 12;
        default:
            return 0;
        }
    }

// The intelligence cells
inline int dgfAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 24;
        case 2:
            return 24;
        case 3:
            return 20;
        case 4:
            return 23;
        case 5:
            return 23;
        case 6:
            return 16;
        case 7:
            return 16;
        case 8:
            return 24;
        case 9:
            return 25;
        case 10:
            return 24;
        case 11:
            return 24;
        case 12:
            return 25;
        case 13:
            return 24;
        default:
            return 0;
        }
    }

// The wisdom cells (Itzamna the 25)
inline int dgfAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 25;
        case 3:
            return 18;
        case 4:
            return 23;
        case 5:
            return 20;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 25;
        case 9:
            return 24;
        case 10:
            return 19;
        case 11:
            return 23;
        case 12:
            return 18;
        case 13:
            return 20;
        default:
            return 0;
        }
    }

// The dexterity cells (Itzamna the 17, the lowest)
inline int dgfAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 25;
        case 3:
            return 20;
        case 4:
            return 23;
        case 5:
            return 25;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 17;
        case 9:
            return 25;
        case 10:
            return 23;
        case 11:
            return 24;
        case 12:
            return 25;
        case 13:
            return 25;
        default:
            return 0;
        }
    }

// The constitution cells (Camazotz the 24, Tlaloc the 24)
inline int dgfAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 23;
        case 3:
            return 24;
        case 4:
            return 23;
        case 5:
            return 25;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 21;
        case 9:
            return 25;
        case 10:
            return 24;
        case 11:
            return 24;
        case 12:
            return 25;
        case 13:
            return 24;
        default:
            return 0;
        }
    }

// The charisma cells (Camazotz the printed -2, Mictlantecuhtli the printed -4
// - the negative printings; Tlazolteotl the 24 with the -5 alternative const)
inline int dgfAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 23;
        case 2:
            return 25;
        case 3:
            return -2;
        case 4:
            return 9;
        case 5:
            return 25;
        case 6:
            return 18;
        case 7:
            return 18;
        case 8:
            return 23;
        case 9:
            return 25;
        case 10:
            return -4;
        case 11:
            return 19;
        case 12:
            return 24;
        case 13:
            return 25;
        default:
            return 0;
        }
    }

// The psionic score cells (0 = no printed numeric score this round - the
// psionic ability prints class letters only)
inline int dgfAbiPsi(int b)
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
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Quetzalcoatl through Xochipilli)
inline int dgfRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print page cells (32-36, the folio offset PRINT = PDF - 1)
inline int dgfRosPage(int b)
    {
        switch (b) {
        case 0:
            return 32;
        case 1:
            return 33;
        case 2:
            return 33;
        case 3:
            return 33;
        case 4:
            return 33;
        case 5:
            return 34;
        case 6:
            return 34;
        case 7:
            return 34;
        case 8:
            return 34;
        case 9:
            return 35;
        case 10:
            return 35;
        case 11:
            return 35;
        case 12:
            return 36;
        case 13:
            return 36;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG the twins, 1 NG Itzamna, 2 CG Chalchiuhtlicue, 3
// LN Quetzalcoatl, 4 N Camaxtli/Huitzilopochtli/Xochipilli, 6 LE
// Mictlantecuhtli/Tlaloc, 8 CE the four - the R852 code scheme)
inline int dgfRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 8;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 8;
        case 13:
            return 4;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 hero - the twin heroes carry no rank
// line)
inline int dgfRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 2;
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
            return 0;
        default:
            return 0;
        }
    }

// The psionic class cells (0 Nil the twins, 1 class I, 2 class II
// Tezcatlipoca, 6 class VI Itzamna - the R849 class table)
inline int dgfRosPsiClass(int b)
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
            return 6;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The plane cells (1 = the parallel Prime Material Plane; 0 = no plane line,
// the twin heroes)
inline int dgfRosPlane(int b)
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
            return 1;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed DAMAGE/ATTACK cell is numeric
// damage; 0 = Nil, See below, or Variable)
inline int dgfRosDmgFixed(int b)
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
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells: Quetzalcoatl,
// Camazotz, Huhueteotl, Huitzilopochtli, Mictlantecuhtli, Tlazolteotl,
// Xochipilli)
inline int dgfRosInEach(int b)
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
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The twin-pair flags (Hunapu and Xbalanque, the identical twin stat blocks)
inline int dgfRosTwinPair(int b)
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
            return 1;
        case 7:
            return 1;
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
        default:
            return 0;
        }
    }

}   // namespace rules
