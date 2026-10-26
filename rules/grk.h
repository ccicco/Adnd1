// =========================================================================================
// Adnd1 - rules/grk.h
// the Greek mythos - the D&DG walk round eleven, print pp. 63-74: forty
// beings from Zeus the thunderbolt sovereign of Olympus to Tyche the luck
// goddess, the ten greater gods (Zeus, Aphrodite, Apollo, Ares, Athena,
// Dionysus, Hades, Hera, Hermes, Poseidon), the eight lesser gods, the six
// heroes (Achilles, Bellerophon, Jason, Odysseus, Perseus, Theseus), the six
// greater titans (Atlas, Coeus, Crius, Epimetheus, Kronos, Oceanus), the
// demigod Heracles, and the nine monsters across seven planes.
// census 781 -> 782.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 064-075; the second printing) with
// the column-split tsv dumps; the collation voice: the archive.org 1st-print
// derivative (deities-demigods-1st-print) - the chocr char-level word
// geometry plus the pure-Python JPEG decode of the BookReader page images
// rendered glyph by glyph. The adjudications: the FRACTION FINGERPRINT (the
// half-height small-1, the long slash and the low looped 2 of the printed X
// 1/2 foot cells decode nine sizes as fractions, not X'Y" inches: Zeus 78,
// Achilles 66, Aphrodite 66, Artemis 66, Bellerophon 66, Hecate 66, Hera 66,
// Hermes 78, Hades 78 - the Hades 6'1" draft read was the fraction), the
// Odysseus 5'4" the one true inch cell, the merged-column swaps (Ares/Athena
// classes, Atlas/Cerberus alignments, Achilles fighter 15), the psionic
// glyph-width decode (Dionysus and Hades the pixel-verified class III
// three-pipe), the Coeus charisma minus four, and the flagged odd prints
// pinned as printed: Ares move 26/24, Hades move 29, Hades CH 24(-9),
// Bellerophon move 12.
//
namespace rules {

// ---- the R859 census ----

// the Greek mythos round: the D&DG walk round eleven, print pp. 63-74
inline int grkRound()
    { return 859; }

// the first print page of the mythos (the folio offset PRINT = PDF - 1)
inline int grkPrintStart()
    { return 63; }

// the last print page of the mythos
inline int grkPrintEnd()
    { return 74; }

// the forty beings of the mythos (Zeus through Tyche: eleven greater, seven
// lesser, one demigod, six heroes, six greater titans, nine monsters)
inline int grkBeingCount()
    { return 40; }

// the four grids of the round (combat, class, ability, roster)
inline int grkTableCount()
    { return 4; }

// no chains this round
inline int grkChainCount()
    { return 0; }

// zero registry defs touched - the floor holds
inline int grkRegistryFloor()
    { return 995; }

// the combat grid rows
inline int grkCbtRows()
    { return 40; }

// the class grid rows
inline int grkClsRows()
    { return 40; }

// the ability grid rows
inline int grkAbiRows()
    { return 40; }

// the roster grid rows
inline int grkRosRows()
    { return 40; }

// the plane codes (none, Olympus, Tarterus, Hades, the Nine Hells, the Prime
// Material, the Twin Paradises)
inline int grkPlaneCount()
    { return 7; }

// the six heroes (Achilles, Bellerophon, Jason, Odysseus, Perseus, Theseus)
inline int grkHeroCount()
    { return 6; }

// the ten greater gods (Zeus, Aphrodite, Apollo, Ares, Athena, Dionysus,
// Hades, Hera, Hermes, Poseidon)
inline int grkGreaterCount()
    { return 10; }

// the eight lesser gods (Artemis, Demeter, Hecate, Hephaestus, Nike, Pan,
// Prometheus, Tyche)
inline int grkLesserCount()
    { return 8; }

// the one demigod (Heracles)
inline int grkDemigodCount()
    { return 1; }

// the six greater titans (Atlas, Coeus, Crius, Epimetheus, Kronos, Oceanus -
// Prometheus the printed lesser god rides rank 0)
inline int grkTitanCount()
    { return 6; }

// the nine monster rows (the White Eagle, Antaeus, Cerberus, Circe, both
// cyclopes, Enceladus, the Furies, the Hecatoncheire)
inline int grkMonsterCount()
    { return 9; }

// the nine printed Nth level in each cells (Zeus MU/I, Apollo MU/I, Athena
// MU/I, Epimetheus C/D, Hera MU/I, Poseidon C/D and MU/I, Oceanus C/D,
// Prometheus C/D, Tyche MU/I)
inline int grkInEachCount()
    { return 9; }

// the four printed rivalry lines (Ares, Athena, Pan against Apollo, Odysseus
// under the Poseidon curse)
inline int grkEnmityCount()
    { return 4; }

// the two paladin heroes (Perseus 15th, Theseus 13th - the fighter lo/hi pair
// plus a bool each)
inline int grkPaladinCount()
    { return 2; }

// all six psionic classes of the R849 table appear (I Hecate, Pan, Tyche; II
// Zeus; III Dionysus, Hades; IV Hephaestus, Hermes; V the ten Vs; VI the six
// VIs)
inline int grkPsiClassKinds()
    { return 6; }

// the nine X 1/2 foot size cells (Zeus, Achilles, Aphrodite, Artemis,
// Bellerophon, Hecate, Hera, Hermes, Hades - the pixel-verified fraction
// cluster)
inline int grkHalfFootCount()
    { return 9; }

// the one artifact (the Aegis of Zeus)
inline int grkArtifactCount()
    { return 1; }

// ---- the Greek pantheon doctrine ----

// the interfaith transgression strips the third and higher level spells
inline int grkSpellLossLevels()
    { return 3; }

// the lunar month of the spell loss (the psm-4 lunar month)
inline int grkSpellLossDays()
    { return 28; }

// many of the gods descended from the greater titans
inline bool grkTitansAncestry()
    { return true; }

// the worship by man gave the sons and daughters of the titans unknown power
inline bool grkWorshipGavePower()
    { return true; }

// the gods threw down the titans and mastered the Prime Material Plane
inline bool grkThrewDownTitans()
    { return true; }

// the gods are jealous, envious, petty and fly into blind rages
inline bool grkMortalTraits()
    { return true; }

// the first places of worship were areas of natural beauty
inline bool grkFirstWorshipNatural()
    { return true; }

// city clerics must build or work in temples
inline bool grkCityTemples()
    { return true; }

// country clerics must find a natural setting for worship
inline bool grkCountryNatural()
    { return true; }

// only clerics worshiping Poseidon may ride horses
inline bool grkPoseidonClericsRide()
    { return true; }

// no cleric may deal with other sects on non-hostile terms
inline bool grkNoOtherSects()
    { return true; }

// all clerics permanently attach to one temple
inline bool grkOneTemple()
    { return true; }

// the sixth and seventh level spells come only from meditation there
inline bool grkHighSpellsMeditation()
    { return true; }

// a sacked or despoiled temple costs the higher spells until reconsecrated
inline bool grkSackedTempleLoss()
    { return true; }

// ---- Zeus and the Aegis ----

// the Zeus lightning bolt cast every melee round alongside the attack
inline int grkZeusBoltDamage()
    { return 30; }

// the blood-spill forms a random sixth level monster
inline int grkZeusBloodMonsterLevel()
    { return 6; }

// the blood monster fights for Zeus until dead or 48 hours elapse
inline int grkZeusBloodHours()
    { return 48; }

// the Aegis is a +5 shield
inline int grkAegisPlus()
    { return 5; }

// the Aegis fear reaches 10 yards, save vs. spells
inline int grkAegisFearYards()
    { return 10; }

// Zeus often shape changes
inline bool grkZeusShapeChange()
    { return true; }

// Zeus disdains armor but will use his +5 shield
inline bool grkZeusDisdainsArmor()
    { return true; }

// the Aegis throws fear into beings near it, save vs. spells
inline bool grkAegisFear()
    { return true; }

// the shield forms itself into a displacer cloak at a word
inline bool grkAegisCloakForm()
    { return true; }

// Athena often has custody of the Aegis
inline bool grkAegisAthenaCustody()
    { return true; }

// ---- the White Eagle of Zeus ----

// the eagle xp line X/14,100
inline int grkEagleXpBase()
    { return 14100; }

// the eagle attacks as a 16+ hit dice monster
inline int grkEagleHitDice()
    { return 16; }

// the eagle teleports from plane to plane
inline bool grkEagleTeleport()
    { return true; }

// the eagle talks to Zeus
inline bool grkEagleTalksToZeus()
    { return true; }

// it carries the god thunder bolts into battle
inline bool grkEagleThunderBolts()
    { return true; }

// it acts as Zeus messenger and symbol
inline bool grkEagleMessenger()
    { return true; }

// ---- Achilles ----

// the immortal horses pull the chariot at 24 per turn
inline int grkAchillesChariotRate()
    { return 24; }

// his skin cannot be pierced by edged weapons except at his left heel
inline bool grkAchillesEdgedImmune()
    { return true; }

// only bludgeon-type weapons can harm him
inline bool grkAchillesBludgeonOnly()
    { return true; }

// he wears gold plated +2 chainmail and a +2 shield
inline bool grkAchillesGoldPlated()
    { return true; }

// ---- Aphrodite ----

// the wave of her hand causes 1-10 points of pain, no save
inline int grkAphroditePainDamage()
    { return 10; }

// her female clerics need charisma 15 or greater
inline int grkAphroditeFemaleCh()
    { return 15; }

// her male clerics need constitution 16 or better
inline int grkAphroditeMaleCon()
    { return 16; }

// the 10 percent chance the vain goddess hears an unfavorable comparison
inline int grkAphroditeVengeancePct()
    { return 10; }

// a charmed viewer can never attack her again
inline bool grkAphroditeCharmPermanent()
    { return true; }

// her clerics sacrifice doves every 10 days
inline bool grkAphroditeDoves()
    { return true; }

// jewelry is destroyed on her altar every new moon
inline bool grkAphroditeNewMoon()
    { return true; }

// the goddess is extremely vain and jealous
inline bool grkAphroditeVainJealous()
    { return true; }

// ---- Antaeus ----

// the printed 100 hp starting block
inline int grkAntaeusHpBase()
    { return 100; }

// each growth step heals all damage and adds 25 hit points
inline int grkAntaeusGrowHeal()
    { return 25; }

// the growth ceiling of 250 total hit points
inline int grkAntaeusHpMax()
    { return 250; }

// the xp line X/14,000
inline int grkAntaeusXpBase()
    { return 14000; }

// plus 35 per hp when killed
inline int grkAntaeusXpPerHp()
    { return 35; }

// Antaeus grows each round he fights on the earth, to titan size
inline bool grkAntaeusGrowsEachRound()
    { return true; }

// each growth heals all damage taken
inline bool grkAntaeusGrowthHeals()
    { return true; }

// on the earth his damage heals each round even after growth stops
inline bool grkAntaeusEarthHealing()
    { return true; }

// lifted off the ground he loses strength and size at the same rate
inline bool grkAntaeusLiftedWeakens()
    { return true; }

// ---- Apollo ----

// the +4 bow of line-of-sight range
inline int grkApolloBowPlus()
    { return 4; }

// the adamantite +3 arrows
inline int grkApolloArrowPlus()
    { return 3; }

// the 60 percent chance Artemis comes to the aid of Apollo
inline int grkApolloCompanionPct()
    { return 60; }

// the purple haze acts as a +5 ring of protection
inline int grkApolloHazePlus()
    { return 5; }

// Apollo shape changes at will
inline bool grkApolloShapeChange()
    { return true; }

// the lyre raises a friendly being strength to a storm giant
inline bool grkApolloLyreStormGiant()
    { return true; }

// the lyre bestows curses and casts disintegrate once per round
inline bool grkApolloLyreCurses()
    { return true; }

// his clerics wear laurel leaves and use laurel wood
inline bool grkApolloLaurel()
    { return true; }

// the sun god carries the sun across the sky in his solar chariot
inline bool grkApolloSunChariot()
    { return true; }

// ---- Ares ----

// the +3 spear causes fear within 10 yards
inline int grkAresSpearFearYards()
    { return 10; }

// Ares appears as a normal man wearing +5 chainmail
inline bool grkAresChainmailPlus5()
    { return true; }

// no being in the Prime Material but Ares can pick up his spear
inline bool grkAresSpearOnlyHeLifts()
    { return true; }

// the +5 sword creates an anti-magic shell at will
inline bool grkAresSwordAntiMagic()
    { return true; }

// he uses either the spear or the sword, never both at once
inline bool grkAresSwordOrSpear()
    { return true; }

// with the spear in hand he moves as a blink dog
inline bool grkAresBlinkDog()
    { return true; }

// the great rivalry between Athena and Ares - their clerics oppose each other
// at every opportunity
inline bool grkAresAthenaRivalry()
    { return true; }

// ---- Artemis ----

// her maximum bow range of 1,000 yards
inline int grkArtemisRangeYards()
    { return 1000; }

// any magical spell sent to hurt her reflects back to the sender
inline bool grkArtemisSpellReflect()
    { return true; }

// in animal shape she is hasted as the spell
inline bool grkArtemisHastedAnimal()
    { return true; }

// magical fang-and-claw creatures cannot hurt her after seeing her once
inline bool grkArtemisFangClawImmune()
    { return true; }

// she has absolute power over all nonmagical forest animals
inline bool grkArtemisAnimalPower()
    { return true; }

// all the clerics in her sect are druids
inline bool grkArtemisDruidsOnly()
    { return true; }

// her druids must be pure of body as well as spirit
inline bool grkArtemisPureBody()
    { return true; }

// ---- Athena ----

// Athena moves as a blink dog
inline bool grkAthenaBlinkDog()
    { return true; }

// she never misses her target
inline bool grkAthenaNeverMisses()
    { return true; }

// her shield bears a medusa head that turns stone-lookers
inline bool grkAthenaMedusaShield()
    { return true; }

// her helm creates an anti-magic shell through which she casts
inline bool grkAthenaHelmAntiMagic()
    { return true; }

// her clerics aggressively spread her worship and scorn all others
inline bool grkAthenaClericsAggressive()
    { return true; }

// ---- Atlas ----

// on the Prime Material there is nothing he cannot lift, bend or break
inline bool grkAtlasPrimeStrength()
    { return true; }

// on other planes his strength is only 25
inline bool grkAtlasOtherPlaneStrength()
    { return true; }

// despite his alignment he keeps his word even unto death
inline bool grkAtlasKeepsWord()
    { return true; }

// ---- Bellerophon ----

// the 25 percent chance an Olympian watches over him
inline int grkBellerophonWatchPct()
    { return 25; }

// the 75 percent chance the watcher saves him from mortal danger
inline int grkBellerophonSavePct()
    { return 75; }

// he rode a pegasus into battle
inline bool grkBellerophonPegasus()
    { return true; }

// ---- Cerberus ----

// the three mastiff heads
inline int grkCerberusHeads()
    { return 3; }

// the 30 hp per head
inline int grkCerberusHpPerHead()
    { return 30; }

// the 100 hit points for the body
inline int grkCerberusHpBody()
    { return 100; }

// the creature regenerates 5 points per melee round
inline int grkCerberusRegen()
    { return 5; }

// the poisonous spittle reaches up to 30 inches
inline int grkCerberusSpittleInches()
    { return 30; }

// the xp line X/26,240
inline int grkCerberusXpBase()
    { return 26240; }

// he keeps beings out of the House of Hades - and keeps them in
inline bool grkCerberusKeepsIn()
    { return true; }

// he cannot be magicked away from his post by any force
inline bool grkCerberusNoMagicRemoval()
    { return true; }

// the collective gaze of the 3 heads turns mortals to stone, one per round,
// save applies
inline bool grkCerberusGazeStone()
    { return true; }

// the middle head spews poisonous spittle that kills on contact, no save
inline bool grkCerberusPoisonSpittle()
    { return true; }

// only one attack form per head per round
inline bool grkCerberusOneFormPerHead()
    { return true; }

// ---- Circe ----

// she has every device capable of turning creatures into other creatures
inline bool grkCircePolymorphDevices()
    { return true; }

// she possesses great prophetic powers
inline bool grkCirceProphetic()
    { return true; }

// she is almost immortal and does not appear to age
inline bool grkCirceAlmostImmortal()
    { return true; }

// ---- Coeus ----

// each angry sight costs 25 percent of total original hit points
inline int grkCoeusFearLossPct()
    { return 25; }

// within 20 yards a save vs. spells or die of fright
inline int grkCoeusApproachYards()
    { return 20; }

// after that a save every 4 melee rounds
inline int grkCoeusSaveRounds()
    { return 4; }

// the failed save runs in fear for 10 turns
inline int grkCoeusFleeTurns()
    { return 10; }

// the failed first-approach save kills by fright
inline bool grkCoeusDieOfFright()
    { return true; }

// he uses a +5 sword striking for 5-30
inline bool grkCoeusSwordPlus5()
    { return true; }

// he travels only at night and never fights during the day
inline bool grkCoeusNightOnly()
    { return true; }

// ---- Crius ----

// the too-heavy-to-lift power lasts 1-4 melee rounds
inline int grkCriusHeavyRoundsMax()
    { return 4; }

// attackers in his gravity field are -4 to hit
inline int grkCriusHitPenalty()
    { return 4; }

// attackers in the field are -1 on armor class
inline int grkCriusAcPenalty()
    { return 1; }

// he increases the weight of objects at will and makes things weightless
inline bool grkCriusWeightControl()
    { return true; }

// a full turn of work makes the heaviness permanent, save vs. the permanency
inline bool grkCriusPermanency()
    { return true; }

// his battle field drops physical attacks short, kills dexterity bonuses
inline bool grkCriusGravityField()
    { return true; }

// ---- the two cyclopes ----

// the greater cyclops 15 HD
inline int grkCyclopsGrHd()
    { return 15; }

// plus 1-8 hit points
inline int grkCyclopsGrBonusHpMax()
    { return 8; }

// the 20 percent reward chance for gift bringers
inline int grkCyclopsGrGiftRewardPct()
    { return 20; }

// the 80 percent kill chance for the presumption
inline int grkCyclopsGrKillPct()
    { return 80; }

// the xp line IX/7,800
inline int grkCyclopsGrXpBase()
    { return 7800; }

// plus 20 per hp
inline int grkCyclopsGrXpPerHp()
    { return 20; }

// the lesser cyclops 13 HD
inline int grkCyclopsLsHd()
    { return 13; }

// the hurled boulders reach 50 inches
inline int grkCyclopsLsRockRange()
    { return 50; }

// the xp line VIII/3,950
inline int grkCyclopsLsXpBase()
    { return 3950; }

// plus 18 per hp
inline int grkCyclopsLsXpPerHp()
    { return 18; }

// the greater cyclopes were a gift to Hephaestus from Hera
inline bool grkCyclopsGrHephaestusGift()
    { return true; }

// they are immune to all fire attacks
inline bool grkCyclopsGrFireImmune()
    { return true; }

// each greater cyclops wears a personal set of magical scale mail
inline bool grkCyclopsGrScaleMail()
    { return true; }

// the lesser brutes hurl huge boulders for 4-40 points
inline bool grkCyclopsLsHurlRocks()
    { return true; }

// ---- Demeter ----

// she creates any weather for any length of time
inline bool grkDemeterWeather()
    { return true; }

// she summons and controls any plant or animal
inline bool grkDemeterPlantAnimal()
    { return true; }

// her chariot is pulled by two ancient green dragons
inline bool grkDemeterGreenDragons()
    { return true; }

// no grain grows if she neglects her duties
inline bool grkDemeterGrainDuty()
    { return true; }

// ---- Dionysus ----

// the chariot panthers armor class 2
inline int grkDionysusPantherAc()
    { return 2; }

// the panthers 11 HD
inline int grkDionysusPantherHd()
    { return 11; }

// the panthers 50 hp each
inline int grkDionysusPantherHp()
    { return 50; }

// the madness save vs. spells at -4
inline int grkDionysusMadnessSavePenalty()
    { return 4; }

// the thyrsus restores all dead things as a raise dead
inline bool grkDionysusThyrsusRaise()
    { return true; }

// it teleports the holder from plant to plant
inline bool grkDionysusThyrsusTeleport()
    { return true; }

// it acts as a mirror of life trapping at a touch
inline bool grkDionysusThyrsusMirror()
    { return true; }

// he controls any feline or ursine creature
inline bool grkDionysusFelineControl()
    { return true; }

// he inflicts madness on attackers or temple defilers
inline bool grkDionysusMadness()
    { return true; }

// ---- Enceladus ----

// up to four spells grabbed per melee round
inline int grkEnceladusSpellGrabs()
    { return 4; }

// the fear radius of 100 yards
inline int grkEnceladusFearYards()
    { return 100; }

// the xp line X/21,175
inline int grkEnceladusXpBase()
    { return 21175; }

// he grabs spells out of the air and negates them
inline bool grkEnceladusSpellGrab()
    { return true; }

// he grabs two spells with one hand and strikes with the other
inline bool grkEnceladusTwoHanded()
    { return true; }

// he has been known to fight the gods of Olympus
inline bool grkEnceladusOlympusFoe()
    { return true; }

// ---- Epimetheus ----

// the 45 percent chance his creation fights him
inline int grkEpimetheusFightPct()
    { return 45; }

// the 5 percent chance of the clay ball reward
inline int grkEpimetheusClayPct()
    { return 5; }

// the clay ball makes any 4th level creature
inline int grkEpimetheusBallLevel()
    { return 4; }

// the 60 percent chance the ball creature tries to kill its maker
inline int grkEpimetheusBetrayPct()
    { return 60; }

// he creates creatures as Prometheus does
inline bool grkEpimetheusCreates()
    { return true; }

// the clay ball creature obeys until its death if it does not attack
inline bool grkEpimetheusBallCreature()
    { return true; }

// ---- the Furies ----

// the three spirits (Alecto, Tisiphone, Megarea)
inline int grkFuriesCount()
    { return 3; }

// the 200 hp each
inline int grkFuriesHpEach()
    { return 200; }

// they are the punishment force of the gods
inline bool grkFuriesPunishmentForce()
    { return true; }

// they can find anyone or anything on their plane unless hidden by magic
inline bool grkFuriesFindAnyone()
    { return true; }

// their punishments cannot be appealed
inline bool grkFuriesNoAppeal()
    { return true; }

// the metal-barbed whips strip ability points with every hit
inline bool grkFuriesWhipDrain()
    { return true; }

// ---- Hades ----

// the eyes cast 2 death spells every melee round
inline int grkHadesDeathSpells()
    { return 2; }

// the death spell range of 120 feet
inline int grkHadesDeathRangeFeet()
    { return 120; }

// the death ray explosion radius of 30 inches
inline int grkHadesExplosionInches()
    { return 30; }

// Hades shape changes at will
inline bool grkHadesShapeChange()
    { return true; }

// his eyes cast death spells when not in hand-to-hand combat
inline bool grkHadesDeathEyes()
    { return true; }

// a nonmetal touch explodes death rays in a radius, save applies
inline bool grkHadesNonmetalExplosion()
    { return true; }

// he has complete control over all things made of the earth
inline bool grkHadesEarthControl()
    { return true; }

// his chair of forgetfulness traps sitters until freed
inline bool grkHadesChairForgetfulness()
    { return true; }

// in his black chariot he cannot be touched by mortals or gods
inline bool grkHadesChariotUntouchable()
    { return true; }

// his helm renders him invisible, used only against Olympus enemies
inline bool grkHadesHelmInvisible()
    { return true; }

// the House of Hades has one entrance, guarded by Cerberus
inline bool grkHadesOneEntrance()
    { return true; }

// ---- Hecate ----

// the 9 hell hound servants
inline int grkHecateHellHounds()
    { return 9; }

// the 10 percent hound-hunt chance per act of desecration
inline int grkHecateHoundPct()
    { return 10; }

// she uses any magic-user or illusionist spell at will as if 20th level
inline bool grkHecateAnySpell()
    { return true; }

// from sunset to sunrise she casts two spells per melee round, one by day
inline bool grkHecateNightTwoSpells()
    { return true; }

// her twin spheres of annihilation move by themselves
inline bool grkHecateTwinSpheres()
    { return true; }

// her clerics have a special rapport with hell hounds
inline bool grkHecateHoundRapport()
    { return true; }

// her clerics sacrifice on the night of the full moon
inline bool grkHecateFullMoon()
    { return true; }

// her images often have three faces
inline bool grkHecateThreeFaces()
    { return true; }

// ---- the Hecatoncheire ----

// the hundred arms
inline int grkHecatoncheireArms()
    { return 100; }

// the fifty heads
inline int grkHecatoncheireHeads()
    { return 50; }

// the boulder maximum range of 30 inches
inline int grkHecatoncheireBoulderRange()
    { return 30; }

// the xp line X/29,300
inline int grkHecatoncheireXpBase()
    { return 29300; }

// the grabbed strength-18(50%) being has a 10 percent pull-free chance
inline int grkHecatoncheireGrabPct()
    { return 10; }

// plus 1 percent per strength point over 50
inline int grkHecatoncheireGrabPerPct()
    { return 1; }

// their hurled boulder groups act as a meteor swarm
inline bool grkHecatoncheireMeteorSwarm()
    { return true; }

// up to ten fists strike close opponents, plus 3-30 for huge ones
inline bool grkHecatoncheireTenFists()
    { return true; }

// all are bitter enemies of the gods of Olympus
inline bool grkHecatoncheireOlympusEnemies()
    { return true; }

// ---- Hephaestus ----

// the 5 percent chance of the +5 any-class shield reward
inline int grkHephaestusShieldPct()
    { return 5; }

// he is the only being able to easily work adamant
inline bool grkHephaestusAdamant()
    { return true; }

// the +5 reward shield is useable by any class
inline bool grkHephaestusShieldAnyClass()
    { return true; }

// he works with greater cyclopes, fire elementals, efreet and demons
inline bool grkHephaestusForgeHelpers()
    { return true; }

// he is friend to the dwarves and teaches their smiths
inline bool grkHephaestusDwarfFriend()
    { return true; }

// a red dragon guards the tunnel to his mountain
inline bool grkHephaestusRedDragon()
    { return true; }

// ---- Hera ----

// the 5 percent chance the goddess hears a prayer
inline int grkHeraListenPct()
    { return 5; }

// her angry voice does 20 points to all within range
inline int grkHeraVoiceDamage()
    { return 20; }

// the voice reaches 50 yards, no saving throw
inline int grkHeraVoiceYards()
    { return 50; }

// a heard prayer about husband problems may curse the offending male, save
// negates
inline bool grkHeraCurse()
    { return true; }

// tracking her husband paramours gave her unparalleled spying methods
inline bool grkHeraSpying()
    { return true; }

// her clerics carry a vengeance drive, planning defeats for years
inline bool grkHeraClericVengeance()
    { return true; }

// the failed save flees in terror from her screaming, as the fear spell
inline bool grkHeraVoiceFear()
    { return true; }

// ---- Heracles ----

// the bow range of 1 mile
inline int grkHeraclesBowRangeMiles()
    { return 1; }

// the berserker rage strength bonus of +25 damage
inline int grkHeraclesRageBonus()
    { return 25; }

// the Nemean lion skin cannot be pierced; thrusts do one point, slashes half
inline bool grkHeraclesNemeanSkin()
    { return true; }

// past half his hit points he rages and attacks friend and foe alike
inline bool grkHeraclesBerserkerRage()
    { return true; }

// his special bow cannot miss
inline bool grkHeraclesBowNeverMiss()
    { return true; }

// he will have nothing to do with magic-users or clerics
inline bool grkHeraclesNoMagicUsers()
    { return true; }

// ---- Hermes ----

// the 15 percent punishment chance per bribe offense
inline int grkHermesGraftPct()
    { return 15; }

// he has maximum thieving abilities
inline bool grkHermesMaxThieving()
    { return true; }

// he moves as a blink dog and is always hasted
inline bool grkHermesBlinkDog()
    { return true; }

// his winged sandals allow flight
inline bool grkHermesWingedSandals()
    { return true; }

// his helm of invisibility is as the ring of the same name
inline bool grkHermesHelmInvisible()
    { return true; }

// the white caduceus controls all nonmagical creatures other than man, no
// save
inline bool grkHermesCaduceus()
    { return true; }

// he is the messenger of the gods to mortals
inline bool grkHermesMessenger()
    { return true; }

// he acts as arbiter of disputes between the gods
inline bool grkHermesArbiter()
    { return true; }

// his clerics must keep physically fit and run long distances
inline bool grkHermesClericsFit()
    { return true; }

// they must carry a white rod as their symbol
inline bool grkHermesWhiteRod()
    { return true; }

// ---- Jason ----

// the fleece raises the dead of less than 3 days
inline int grkJasonFleeceDeathDays()
    { return 3; }

// the 10 percent chance the fleece vanishes after each use
inline int grkJasonFleeceVanishPct()
    { return 10; }

// the golden fleece heals any wound and raises the recently dead
inline bool grkJasonGoldenFleece()
    { return true; }

// Jason is noted for his leadership ability and strength
inline bool grkJasonLeadership()
    { return true; }

// ---- Kronos ----

// the lava ball maximum range of 200 yards
inline int grkKronosLavaRangeYards()
    { return 200; }

// at battle start he hurls lava balls created out of thin air
inline bool grkKronosLavaBalls()
    { return true; }

// his adamant sickle strikes as a +5 weapon
inline bool grkKronosSickleAdamant()
    { return true; }

// ---- Nike ----

// she always uses her divine awe power to stun lesser creatures
inline bool grkNikeDivineAwe()
    { return true; }

// her rod of power inflicts 5-50 at a touch, no save
inline bool grkNikeRodPower()
    { return true; }

// she destroys any device used against her with a touch, save applies
inline bool grkNikeDeviceDestroy()
    { return true; }

// her clerics may not transgress once - the penalty is total destruction by
// lightning
inline bool grkNikeClericStrict()
    { return true; }

// ---- Oceanus ----

// the titan always has a green shimmer around his body
inline bool grkOceanusGreenShimmer()
    { return true; }

// he raises hurricane winds with a motion of his hand
inline bool grkOceanusHurricane()
    { return true; }

// water creatures of less than divine status must obey him
inline bool grkOceanusWaterCommand()
    { return true; }

// Poseidon outranks him on the Prime Material
inline bool grkOceanusPoseidonOutranks()
    { return true; }

// ---- Odysseus ----

// only he can string his powerful bow, gaining his strength bonuses with it
inline bool grkOdysseusBowOnly()
    { return true; }

// he prefers wit and cunning over strength
inline bool grkOdysseusWitOverStrength()
    { return true; }

// blinding Polyphemus brought the Poseidon curse and ten years of wandering
inline bool grkOdysseusPoseidonCurse()
    { return true; }

// ---- Pan ----

// the voice fear range of 50 yards, save applies
inline int grkPanVoiceYards()
    { return 50; }

// the panic shout reaches 100 inches
inline int grkPanShoutInches()
    { return 100; }

// the shout fear lasts 4 melee rounds, no save
inline int grkPanShoutRounds()
    { return 4; }

// the shout comes after losing more than 25 percent of hit points
inline int grkPanShoutThresholdPct()
    { return 25; }

// the god of nature is both beneficent and fearsomely destructive
inline bool grkPanTwoAspects()
    { return true; }

// his voice causes fear as the spell, save applies
inline bool grkPanVoiceFear()
    { return true; }

// his syrinx pipes play as a rod of beguiling
inline bool grkPanSyrinx()
    { return true; }

// past a quarter of his hit points he shouts 4 rounds of fear with no save
inline bool grkPanShout()
    { return true; }

// he and Apollo are enemies - the rivalry reaches the Prime Material
inline bool grkPanApolloEnemy()
    { return true; }

// ---- Perseus ----

// Perseus is a 15th level paladin
inline bool grkPerseusPaladin()
    { return true; }

// he took the head of the first and most powerful medusa
inline bool grkPerseusMedusaHead()
    { return true; }

// Hades loaned him the helm of invisibility
inline bool grkPerseusHadesHelm()
    { return true; }

// Hermes gave him the winged sandals and a vorpal blade
inline bool grkPerseusHermesSandals()
    { return true; }

// Athena lent him the bright Aegis shield - all later returned
inline bool grkPerseusAegis()
    { return true; }

// ---- Poseidon ----

// the +5 trident
inline int grkPoseidonTridentPlus()
    { return 5; }

// the watery haze acts as a +5 ring of protection
inline int grkPoseidonHazePlus()
    { return 5; }

// he commands any non-divine creature of the water
inline bool grkPoseidonWaterCommand()
    { return true; }

// he creates life in any form, often originating new life forms
inline bool grkPoseidonCreateLife()
    { return true; }

// a coastal town that fails the monthly sacrifice risks blood, rubble or
// flood
inline bool grkPoseidonCoastAnger()
    { return true; }

// he is responsible for the creation of all horses
inline bool grkPoseidonHorses()
    { return true; }

// he rewards high priests with a paladin-quality horse
inline bool grkPoseidonPaladinHorse()
    { return true; }

// the trident absorbs one spell per round and returns a like spell
inline bool grkPoseidonTridentAbsorb()
    { return true; }

// his watery haze acts like a +5 ring of protection
inline bool grkPoseidonWateryHaze()
    { return true; }

// ---- Prometheus ----

// the clay creation takes 2 melee rounds
inline int grkPrometheusCreateRounds()
    { return 2; }

// the 30 years chained before Zeus repented
inline int grkPrometheusChainYears()
    { return 30; }

// he creates any mortal creature from clay
inline bool grkPrometheusClayCreation()
    { return true; }

// he stole fire from the sun for humankind
inline bool grkPrometheusFireTheft()
    { return true; }

// his regenerating liver was torn out afresh by a griffon-vulture
inline bool grkPrometheusVulture()
    { return true; }

// his clerics wear an iron ring set with a mountain stone chip
inline bool grkPrometheusIronRing()
    { return true; }

// he expects self-reliance, not self-centeredness - trickery serves only the
// whole human race
inline bool grkPrometheusSelfReliant()
    { return true; }

// his clerics kill griffons and protect titans from attack
inline bool grkPrometheusKillGriffons()
    { return true; }

// ---- Theseus ----

// Theseus is a 13th level paladin
inline bool grkTheseusPaladin()
    { return true; }

// he defeated the first and most powerful minotaur
inline bool grkTheseusMinotaur()
    { return true; }

// he can be counted on to know the habits and weaknesses of all his enemies
inline bool grkTheseusKnowWeaknesses()
    { return true; }

// ---- Tyche ----

// her good luck spell makes the recipient always win any single contest
inline bool grkTycheGoodLuck()
    { return true; }

// her touch drains one-half the attacker total original hit points, no save
inline bool grkTycheTouchDrain()
    { return true; }

// her blue sphere absorbs one attack per round and reflects the damage back
inline bool grkTycheBlueSphere()
    { return true; }

// the pantheon treats her as a poor relative, so she rarely aids them
inline bool grkTychePoorRelative()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Hephaestus -5 the best, Circe 10 the worst; the
// greater cyclops the printed -4 dash garble)
inline int grkCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return -2;
        case 7:
            return 1;
        case 8:
            return -2;
        case 9:
            return -3;
        case 10:
            return 4;
        case 11:
            return 1;
        case 12:
            return 10;
        case 13:
            return 2;
        case 14:
            return -3;
        case 15:
            return -4;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 4;
        case 19:
            return 1;
        case 20:
            return -3;
        case 21:
            return -1;
        case 22:
            return -1;
        case 23:
            return -2;
        case 24:
            return 5;
        case 25:
            return -5;
        case 26:
            return 2;
        case 27:
            return -2;
        case 28:
            return 2;
        case 29:
            return 3;
        case 30:
            return 2;
        case 31:
            return -4;
        case 32:
            return -3;
        case 33:
            return 2;
        case 34:
            return -2;
        case 35:
            return 3;
        case 36:
            return 3;
        case 37:
            return -2;
        case 38:
            return 4;
        case 39:
            return -3;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all forty read
// single this round)
inline int grkCbtACAlt(int b)
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
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (Zeus and Kronos 400 the supreme, down to Circe 51; 0 =
// the hit-dice rows of the two cyclopes, the egp Flame Snake precedent)
inline int grkCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 100;
        case 2:
            return 90;
        case 3:
            return 259;
        case 4:
            return 100;
        case 5:
            return 376;
        case 6:
            return 333;
        case 7:
            return 219;
        case 8:
            return 329;
        case 9:
            return 350;
        case 10:
            return 69;
        case 11:
            return 100;
        case 12:
            return 51;
        case 13:
            return 344;
        case 14:
            return 390;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 219;
        case 18:
            return 380;
        case 19:
            return 219;
        case 20:
            return 345;
        case 21:
            return 200;
        case 22:
            return 390;
        case 23:
            return 289;
        case 24:
            return 300;
        case 25:
            return 312;
        case 26:
            return 300;
        case 27:
            return 187;
        case 28:
            return 340;
        case 29:
            return 129;
        case 30:
            return 400;
        case 31:
            return 357;
        case 32:
            return 390;
        case 33:
            return 83;
        case 34:
            return 359;
        case 35:
            return 112;
        case 36:
            return 390;
        case 37:
            return 388;
        case 38:
            return 103;
        case 39:
            return 200;
        default:
            return 0;
        }
    }

// The primary move cells (Hades the flagged 29 odd print; Ares the flagged
// 26)
inline int grkCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 6;
        case 2:
            return 18;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 15;
        case 6:
            return 26;
        case 7:
            return 18;
        case 8:
            return 15;
        case 9:
            return 24;
        case 10:
            return 12;
        case 11:
            return 24;
        case 12:
            return 12;
        case 13:
            return 24;
        case 14:
            return 24;
        case 15:
            return 15;
        case 16:
            return 15;
        case 17:
            return 15;
        case 18:
            return 15;
        case 19:
            return 15;
        case 20:
            return 24;
        case 21:
            return 18;
        case 22:
            return 29;
        case 23:
            return 12;
        case 24:
            return 15;
        case 25:
            return 9;
        case 26:
            return 12;
        case 27:
            return 15;
        case 28:
            return 18;
        case 29:
            return 12;
        case 30:
            return 24;
        case 31:
            return 24;
        case 32:
            return 24;
        case 33:
            return 12;
        case 34:
            return 18;
        case 35:
            return 12;
        case 36:
            return 18;
        case 37:
            return 15;
        case 38:
            return 12;
        case 39:
            return 12;
        default:
            return 0;
        }
    }

// The secondary move cells (the printed slash ceilings - Zeus 18/24, the
// eagle 6/48, Nike 24/36, Tyche 12/36, Atlas 24/30, Ares the flagged 26/24)
inline int grkCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 48;
        case 2:
            return 0;
        case 3:
            return 24;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 24;
        case 9:
            return 30;
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
            return 24;
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
            return 48;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 36;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 24;
        case 36:
            return 0;
        case 37:
            return 24;
        case 38:
            return 0;
        case 39:
            return 36;
        default:
            return 0;
        }
    }

// The attack count cells (the Hecatoncheire the ten fists, the eagle and
// Cerberus 3, most gods 2)
inline int grkCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 2;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 10;
        case 25:
            return 2;
        case 26:
            return 3;
        case 27:
            return 2;
        case 28:
            return 2;
        case 29:
            return 2;
        case 30:
            return 2;
        case 31:
            return 2;
        case 32:
            return 2;
        case 33:
            return 2;
        case 34:
            return 3;
        case 35:
            return 2;
        case 36:
            return 2;
        case 37:
            return 2;
        case 38:
            return 2;
        case 39:
            return 1;
        default:
            return 0;
        }
    }

// The attack alternative cells (the 3/2 slashes of Bellerophon, Demeter,
// Hera, Pan)
inline int grkCbtAtD(int b)
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
            return 2;
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
            return 2;
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
            return 2;
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
            return 2;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells (0 = the printed Standard or See below of the
// eight hero and sorceress rows; the Furies and Tyche the 100 ceiling)
inline int grkCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 50;
        case 4:
            return 0;
        case 5:
            return 56;
        case 6:
            return 59;
        case 7:
            return 0;
        case 8:
            return 80;
        case 9:
            return 95;
        case 10:
            return 0;
        case 11:
            return 25;
        case 12:
            return 0;
        case 13:
            return 50;
        case 14:
            return 50;
        case 15:
            return 25;
        case 16:
            return 0;
        case 17:
            return 29;
        case 18:
            return 45;
        case 19:
            return 0;
        case 20:
            return 50;
        case 21:
            return 100;
        case 22:
            return 75;
        case 23:
            return 89;
        case 24:
            return 25;
        case 25:
            return 50;
        case 26:
            return 50;
        case 27:
            return 0;
        case 28:
            return 35;
        case 29:
            return 0;
        case 30:
            return 50;
        case 31:
            return 85;
        case 32:
            return 50;
        case 33:
            return 0;
        case 34:
            return 89;
        case 35:
            return 0;
        case 36:
            return 75;
        case 37:
            return 50;
        case 38:
            return 0;
        case 39:
            return 100;
        default:
            return 0;
        }
    }

// The size cells in inches (the nine pixel-verified X 1/2 foot fractions -
// Zeus, Achilles, Aphrodite, Artemis, Bellerophon, Hecate, Hera, Hermes,
// Hades; Odysseus the one true inch cell 5 foot 4; Antaeus the 11-21 growth
// range floor; the eagle the 50 wingspan)
inline int grkCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 78;
        case 1:
            return 50;
        case 2:
            return 66;
        case 3:
            return 66;
        case 4:
            return 132;
        case 5:
            return 240;
        case 6:
            return 72;
        case 7:
            return 66;
        case 8:
            return 72;
        case 9:
            return 600;
        case 10:
            return 66;
        case 11:
            return 360;
        case 12:
            return 60;
        case 13:
            return 252;
        case 14:
            return 1200;
        case 15:
            return 252;
        case 16:
            return 240;
        case 17:
            return 60;
        case 18:
            return 84;
        case 19:
            return 1020;
        case 20:
            return 1200;
        case 21:
            return 60;
        case 22:
            return 78;
        case 23:
            return 66;
        case 24:
            return 1200;
        case 25:
            return 240;
        case 26:
            return 66;
        case 27:
            return 72;
        case 28:
            return 78;
        case 29:
            return 72;
        case 30:
            return 1200;
        case 31:
            return 84;
        case 32:
            return 1200;
        case 33:
            return 64;
        case 34:
            return 60;
        case 35:
            return 72;
        case 36:
            return 360;
        case 37:
            return 1200;
        case 38:
            return 72;
        case 39:
            return 60;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (Zeus and Kronos 25 the ceiling, Apollo and Athena
// 20)
inline int grkClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 20;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 20;
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
            return 15;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 15;
        case 19:
            return 0;
        case 20:
            return 10;
        case 21:
            return 0;
        case 22:
            return 20;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 15;
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
            return 10;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 12;
        case 37:
            return 13;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (Artemis, Demeter, Hecate, Hermes, Pan; Apollo and
// Athena the printed cleric/druid pair)
inline int grkClsDruid(int b)
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
            return 14;
        case 6:
            return 0;
        case 7:
            return 14;
        case 8:
            return 14;
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
            return 14;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 10;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 14;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 14;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 10;
        case 33:
            return 0;
        case 34:
            return 14;
        case 35:
            return 0;
        case 36:
            return 12;
        case 37:
            return 13;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The lower fighter level cells (the paladin pairs of Perseus 15 and Theseus
// 13)
inline int grkClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 17;
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
            return 20;
        case 9:
            return 19;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 16;
        case 14:
            return 16;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 14;
        case 19:
            return 0;
        case 20:
            return 14;
        case 21:
            return 0;
        case 22:
            return 15;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 18;
        case 26:
            return 10;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 17;
        case 31:
            return 20;
        case 32:
            return 15;
        case 33:
            return 13;
        case 34:
            return 0;
        case 35:
            return 15;
        case 36:
            return 13;
        case 37:
            return 0;
        case 38:
            return 13;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The upper fighter level cells (the paladin hi cells; all other fighters
// single-printed, 0)
inline int grkClsFighterHi(int b)
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
        case 35:
            return 15;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 13;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The ranger level cells (Ares 20 the flagged print, Artemis 16, Jason 16,
// Apollo 15, Athena none - the merged-column swap settled by the tsv
// x-geometry)
inline int grkClsRanger(int b)
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
            return 15;
        case 6:
            return 20;
        case 7:
            return 16;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 10;
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
            return 15;
        case 28:
            return 15;
        case 29:
            return 16;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 13;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 16;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells (99 = the Nike printed See below, the egp Isis
// precedent)
inline int grkClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 12;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 0;
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
            return 12;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 13;
        case 19:
            return 0;
        case 20:
            return 15;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 18;
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
            return 99;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 17;
        case 37:
            return 15;
        case 38:
            return 0;
        case 39:
            return 15;
        default:
            return 0;
        }
    }

// The illusionist level cells (Hades 25 the ceiling; 99 the Nike See below)
inline int grkClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 12;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 9;
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
        case 18:
            return 13;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 25;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 12;
        case 27:
            return 0;
        case 28:
            return 15;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 99;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 15;
        case 35:
            return 0;
        case 36:
            return 17;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 15;
        default:
            return 0;
        }
    }

// The thief level cells (Hermes 25 the maximum thieving god)
inline int grkClsThief(int b)
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
            return 25;
        case 29:
            return 4;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 9;
        case 34:
            return 15;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 10;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The assassin level cells (Ares 12, Hades 15, Hecate 15)
inline int grkClsAssassin(int b)
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
            return 12;
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
            return 15;
        case 23:
            return 15;
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
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (Atlas and Ares 10, Hades 15)
inline int grkClsMonk(int b)
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
            return 12;
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
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The bard level cells (Apollo 23 the ceiling, Dionysus 19, Hermes and Pan
// 15)
inline int grkClsBard(int b)
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
            return 0;
        case 5:
            return 23;
        case 6:
            return 0;
        case 7:
            return 5;
        case 8:
            return 12;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 5;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 10;
        case 18:
            return 19;
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
            return 3;
        case 28:
            return 15;
        case 29:
            return 7;
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
        case 35:
            return 5;
        case 36:
            return 10;
        case 37:
            return 10;
        case 38:
            return 9;
        case 39:
            return 10;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the five 25s of the titans and Apollo, Poseidon, Pan;
// Circe the mortal 10; Hecate 12)
inline int grkAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 19;
        case 4:
            return 0;
        case 5:
            return 25;
        case 6:
            return 21;
        case 7:
            return 21;
        case 8:
            return 23;
        case 9:
            return 25;
        case 10:
            return 18;
        case 11:
            return 0;
        case 12:
            return 10;
        case 13:
            return 24;
        case 14:
            return 25;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 21;
        case 18:
            return 24;
        case 19:
            return 0;
        case 20:
            return 25;
        case 21:
            return 0;
        case 22:
            return 24;
        case 23:
            return 12;
        case 24:
            return 0;
        case 25:
            return 25;
        case 26:
            return 17;
        case 27:
            return 25;
        case 28:
            return 22;
        case 29:
            return 18;
        case 30:
            return 25;
        case 31:
            return 23;
        case 32:
            return 25;
        case 33:
            return 18;
        case 34:
            return 25;
        case 35:
            return 18;
        case 36:
            return 25;
        case 37:
            return 24;
        case 38:
            return 18;
        case 39:
            return 20;
        default:
            return 0;
        }
    }

// The strength to-hit bonuses (0 = no printed bracket: the two monsters,
// Circe, Hecate)
inline int grkAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 7;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 7;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 6;
        case 14:
            return 7;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 4;
        case 18:
            return 6;
        case 19:
            return 0;
        case 20:
            return 7;
        case 21:
            return 0;
        case 22:
            return 6;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 7;
        case 26:
            return 1;
        case 27:
            return 7;
        case 28:
            return 4;
        case 29:
            return 3;
        case 30:
            return 7;
        case 31:
            return 5;
        case 32:
            return 7;
        case 33:
            return 3;
        case 34:
            return 7;
        case 35:
            return 2;
        case 36:
            return 7;
        case 37:
            return 6;
        case 38:
            return 2;
        case 39:
            return 3;
        default:
            return 0;
        }
    }

// The strength damage bonuses (Hermes the unusual +10)
inline int grkAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 7;
        case 4:
            return 0;
        case 5:
            return 14;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 11;
        case 9:
            return 14;
        case 10:
            return 6;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 12;
        case 14:
            return 14;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 9;
        case 18:
            return 12;
        case 19:
            return 0;
        case 20:
            return 14;
        case 21:
            return 0;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 14;
        case 26:
            return 1;
        case 27:
            return 14;
        case 28:
            return 10;
        case 29:
            return 6;
        case 30:
            return 14;
        case 31:
            return 11;
        case 32:
            return 14;
        case 33:
            return 6;
        case 34:
            return 14;
        case 35:
            return 4;
        case 36:
            return 14;
        case 37:
            return 12;
        case 38:
            return 4;
        case 39:
            return 8;
        default:
            return 0;
        }
    }

// The intelligence cells (Hephaestus and Prometheus 25; Heracles the mortal
// 11)
inline int grkAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 20;
        case 4:
            return 0;
        case 5:
            return 24;
        case 6:
            return 20;
        case 7:
            return 23;
        case 8:
            return 25;
        case 9:
            return 12;
        case 10:
            return 17;
        case 11:
            return 0;
        case 12:
            return 17;
        case 13:
            return 20;
        case 14:
            return 23;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 24;
        case 18:
            return 22;
        case 19:
            return 0;
        case 20:
            return 21;
        case 21:
            return 0;
        case 22:
            return 24;
        case 23:
            return 25;
        case 24:
            return 0;
        case 25:
            return 25;
        case 26:
            return 20;
        case 27:
            return 11;
        case 28:
            return 25;
        case 29:
            return 16;
        case 30:
            return 25;
        case 31:
            return 23;
        case 32:
            return 24;
        case 33:
            return 18;
        case 34:
            return 18;
        case 35:
            return 14;
        case 36:
            return 20;
        case 37:
            return 25;
        case 38:
            return 18;
        case 39:
            return 25;
        default:
            return 0;
        }
    }

// The wisdom cells (Ares the printed 9 odd, Hera 25)
inline int grkAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 0;
        case 5:
            return 23;
        case 6:
            return 9;
        case 7:
            return 24;
        case 8:
            return 25;
        case 9:
            return 12;
        case 10:
            return 17;
        case 11:
            return 0;
        case 12:
            return 9;
        case 13:
            return 14;
        case 14:
            return 19;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 24;
        case 18:
            return 20;
        case 19:
            return 0;
        case 20:
            return 19;
        case 21:
            return 0;
        case 22:
            return 20;
        case 23:
            return 9;
        case 24:
            return 0;
        case 25:
            return 20;
        case 26:
            return 25;
        case 27:
            return 9;
        case 28:
            return 19;
        case 29:
            return 14;
        case 30:
            return 14;
        case 31:
            return 23;
        case 32:
            return 10;
        case 33:
            return 10;
        case 34:
            return 18;
        case 35:
            return 12;
        case 36:
            return 22;
        case 37:
            return 20;
        case 38:
            return 17;
        case 39:
            return 25;
        default:
            return 0;
        }
    }

// The dexterity cells (the many 25s; Odysseus 16)
inline int grkAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 23;
        case 4:
            return 0;
        case 5:
            return 25;
        case 6:
            return 25;
        case 7:
            return 24;
        case 8:
            return 22;
        case 9:
            return 20;
        case 10:
            return 18;
        case 11:
            return 0;
        case 12:
            return 17;
        case 13:
            return 20;
        case 14:
            return 23;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 25;
        case 18:
            return 23;
        case 19:
            return 0;
        case 20:
            return 23;
        case 21:
            return 0;
        case 22:
            return 24;
        case 23:
            return 20;
        case 24:
            return 0;
        case 25:
            return 22;
        case 26:
            return 23;
        case 27:
            return 19;
        case 28:
            return 25;
        case 29:
            return 18;
        case 30:
            return 25;
        case 31:
            return 23;
        case 32:
            return 24;
        case 33:
            return 16;
        case 34:
            return 25;
        case 35:
            return 18;
        case 36:
            return 24;
        case 37:
            return 24;
        case 38:
            return 18;
        case 39:
            return 25;
        default:
            return 0;
        }
    }

// The constitution cells (Hades 25; the printed Coeus 23)
inline int grkAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 21;
        case 4:
            return 0;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 19;
        case 8:
            return 23;
        case 9:
            return 23;
        case 10:
            return 17;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return 23;
        case 14:
            return 23;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 21;
        case 18:
            return 25;
        case 19:
            return 0;
        case 20:
            return 22;
        case 21:
            return 0;
        case 22:
            return 25;
        case 23:
            return 22;
        case 24:
            return 0;
        case 25:
            return 23;
        case 26:
            return 23;
        case 27:
            return 20;
        case 28:
            return 24;
        case 29:
            return 18;
        case 30:
            return 25;
        case 31:
            return 24;
        case 32:
            return 25;
        case 33:
            return 17;
        case 34:
            return 25;
        case 35:
            return 18;
        case 36:
            return 25;
        case 37:
            return 24;
        case 38:
            return 18;
        case 39:
            return 22;
        default:
            return 0;
        }
    }

// The charisma cells (Coeus the pixel-verified -4 minus, Hephaestus the 9,
// Heracles 17; Hades the flagged printed 24(-9))
inline int grkAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 25;
        case 4:
            return 0;
        case 5:
            return 25;
        case 6:
            return 22;
        case 7:
            return 25;
        case 8:
            return 21;
        case 9:
            return 20;
        case 10:
            return 18;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return -4;
        case 14:
            return 23;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 25;
        case 18:
            return 23;
        case 19:
            return 0;
        case 20:
            return 22;
        case 21:
            return 0;
        case 22:
            return 24;
        case 23:
            return 25;
        case 24:
            return 0;
        case 25:
            return 9;
        case 26:
            return 23;
        case 27:
            return 17;
        case 28:
            return 24;
        case 29:
            return 19;
        case 30:
            return 25;
        case 31:
            return 25;
        case 32:
            return 20;
        case 33:
            return 18;
        case 34:
            return 22;
        case 35:
            return 18;
        case 36:
            return 22;
        case 37:
            return 25;
        case 38:
            return 18;
        case 39:
            return 25;
        default:
            return 0;
        }
    }

// The psionic score cells (0 = every being reads the R849 class table this
// round; no monster point scores printed)
inline int grkAbiPsi(int b)
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
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Zeus through Tyche)
inline int grkRosOrd(int b)
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
        case 21:
            return 21;
        case 22:
            return 22;
        case 23:
            return 23;
        case 24:
            return 24;
        case 25:
            return 25;
        case 26:
            return 26;
        case 27:
            return 27;
        case 28:
            return 28;
        case 29:
            return 29;
        case 30:
            return 30;
        case 31:
            return 31;
        case 32:
            return 32;
        case 33:
            return 33;
        case 34:
            return 34;
        case 35:
            return 35;
        case 36:
            return 36;
        case 37:
            return 37;
        case 38:
            return 38;
        case 39:
            return 39;
        default:
            return 0;
        }
    }

// The print page cells (63-74, the folio offset PRINT = PDF - 1)
inline int grkRosPage(int b)
    {
        switch (b) {
        case 0:
            return 63;
        case 1:
            return 63;
        case 2:
            return 64;
        case 3:
            return 64;
        case 4:
            return 64;
        case 5:
            return 64;
        case 6:
            return 65;
        case 7:
            return 65;
        case 8:
            return 65;
        case 9:
            return 66;
        case 10:
            return 66;
        case 11:
            return 66;
        case 12:
            return 66;
        case 13:
            return 67;
        case 14:
            return 67;
        case 15:
            return 67;
        case 16:
            return 67;
        case 17:
            return 68;
        case 18:
            return 68;
        case 19:
            return 68;
        case 20:
            return 68;
        case 21:
            return 69;
        case 22:
            return 69;
        case 23:
            return 69;
        case 24:
            return 69;
        case 25:
            return 70;
        case 26:
            return 70;
        case 27:
            return 70;
        case 28:
            return 71;
        case 29:
            return 71;
        case 30:
            return 72;
        case 31:
            return 72;
        case 32:
            return 72;
        case 33:
            return 72;
        case 34:
            return 73;
        case 35:
            return 73;
        case 36:
            return 73;
        case 37:
            return 74;
        case 38:
            return 74;
        case 39:
            return 74;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG, 1 NG, 2 CG, 3 LN, 4 N, 5 CN, 6 LE, 7 NE, 8 CE -
// the R852 code scheme)
inline int grkRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 8;
        case 5:
            return 2;
        case 6:
            return 8;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 8;
        case 10:
            return 0;
        case 11:
            return 7;
        case 12:
            return 8;
        case 13:
            return 8;
        case 14:
            return 8;
        case 15:
            return 2;
        case 16:
            return 8;
        case 17:
            return 1;
        case 18:
            return 5;
        case 19:
            return 8;
        case 20:
            return 2;
        case 21:
            return 4;
        case 22:
            return 7;
        case 23:
            return 6;
        case 24:
            return 5;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 5;
        case 28:
            return 4;
        case 29:
            return 1;
        case 30:
            return 8;
        case 31:
            return 3;
        case 32:
            return 8;
        case 33:
            return 2;
        case 34:
            return 5;
        case 35:
            return 0;
        case 36:
            return 5;
        case 37:
            return 1;
        case 38:
            return 0;
        case 39:
            return 4;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 demigod Heracles, 3 hero, 4 greater
// titan, 5 monster - Prometheus the printed lesser god)
inline int grkRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 5;
        case 20:
            return 4;
        case 21:
            return 5;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 5;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 1;
        case 29:
            return 3;
        case 30:
            return 4;
        case 31:
            return 0;
        case 32:
            return 4;
        case 33:
            return 3;
        case 34:
            return 0;
        case 35:
            return 3;
        case 36:
            return 1;
        case 37:
            return 0;
        case 38:
            return 3;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The psionic class cells (the chocr glyph-width decode: I 9-11px Hecate,
// Pan, Tyche, Apollo; II 30px Zeus; III 47px Dionysus and Hades - the three
// pipe bars, the R850 Coyote precedent, pixel-verified; IV Hephaestus,
// Hermes; V the ten 36px readers; VI the six 50px readers)
inline int grkRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 6;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 6;
        case 18:
            return 3;
        case 19:
            return 0;
        case 20:
            return 5;
        case 21:
            return 5;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 4;
        case 26:
            return 6;
        case 27:
            return 0;
        case 28:
            return 4;
        case 29:
            return 0;
        case 30:
            return 5;
        case 31:
            return 6;
        case 32:
            return 5;
        case 33:
            return 0;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 6;
        case 37:
            return 5;
        case 38:
            return 0;
        case 39:
            return 1;
        default:
            return 0;
        }
    }

// The plane cells (0 none, 1 Olympus, 2 Tarterus, 3 Hades, 4 the Nine Hells
// of Hecate, 5 the Prime Material of Hephaestus and Heracles, 6 the Twin
// Paradises of Epimetheus)
inline int grkRosPlane(int b)
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 6;
        case 21:
            return 0;
        case 22:
            return 3;
        case 23:
            return 4;
        case 24:
            return 0;
        case 25:
            return 5;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 0;
        case 30:
            return 2;
        case 31:
            return 1;
        case 32:
            return 2;
        case 33:
            return 0;
        case 34:
            return 5;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 0;
        case 39:
            return 1;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed numeric damage; 0 = the by-weapon
// rows of Bellerophon, Jason, Perseus, Theseus and the See-below rows of
// Hecate, Tyche)
inline int grkRosDmgFixed(int b)
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
            return 1;
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
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 0;
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
            return 0;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells: Zeus, Apollo,
// Athena, Epimetheus, Hera, Poseidon, Oceanus, Prometheus, Tyche)
inline int grkRosInEach(int b)
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
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
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
            return 1;
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
            return 1;
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
            return 1;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 0;
        case 39:
            return 1;
        default:
            return 0;
        }
    }

// The enmity flags (the printed rivalry lines: Ares and Athena the war
// rivalry, Pan the Apollo enemy, Odysseus under the Poseidon curse)
inline int grkRosEnmity(int b)
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
            return 0;
        case 8:
            return 1;
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
            return 1;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
