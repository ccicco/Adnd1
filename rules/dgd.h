// =========================================================================================
// Adnd1 - rules/dgd.h
// the Babylonian mythos - the D&DG walk round four, print pp. 22-25: ten
// beings from Anu the sky chief to Ramman the storm god - the cleric doctrine
// of the kilt and the tithe, the devil-world ruler Druaga, the three-headed
// dragon spirit Dahak, and the hero Gilgamesh.
// census 774 -> 775.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 023-026; the second printing); the
// collation voice: the archive.org 1st-print derivative (djvu.txt + djvu.xml
// word geometry). The adjudications: the Gilgamesh two attacks (the IA xml
// word, clean, against the Termux 3 fold-garble), the Girru +3 axe (the IA
// voice against the Termux +43 garble), the Anu 2-20 (+7) damage line (the IA
// voice; the Termux fold ate the line), the Druaga charisma 4 (the
// single-glyph 15px TSV width against the 24px two-digit calibration), the
// Nergal 12 over 12 and the Ramman 12 over 48 moves (both voices), the Dahak
// length 72 feet (the IA foot mark against the Termux inch mark). The Dahak
// move pins the second-print extract 9 over 18 against the IA 1st-print 9
// over 15 - flagged for the physical-copy eyeball.
//
namespace rules {

// ---- the R852 census ----

// the Babylonian mythos round: the D&DG walk round four, print pp. 22-25
inline int dgdRound()
    { return 852; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int dgdPrintStart()
    { return 22; }

// the last print page
inline int dgdPrintEnd()
    { return 25; }

// the ten beings of the mythos (Anu through Ramman)
inline int dgdBeingCount()
    { return 10; }

// the four grids (combat, class, ability, roster)
inline int dgdTableCount()
    { return 4; }

// no chains this round
inline int dgdChainCount()
    { return 0; }

// zero registry defs touched - the floor holds at 995
inline int dgdRegistryFloor()
    { return 995; }

// the combat grid rows
inline int dgdCbtRows()
    { return 10; }

// the class grid rows
inline int dgdClsRows()
    { return 10; }

// the ability grid rows
inline int dgdAbiRows()
    { return 10; }

// the roster grid rows
inline int dgdRosRows()
    { return 10; }

// the eight printed planes of the mythos (Nirvana through Concordant
// Opposition)
inline int dgdPlaneCount()
    { return 8; }

// the printed psionic class VI of the R849 class table (Anu and Anshar)
inline int dgdPsiClassVI()
    { return 6; }

// ---- the mythos intro ----

// the origins of Babylonian mythology are extremely ancient
inline bool dgdOriginsExtremelyAncient()
    { return true; }

// the consulted sources conflict with each other; the list is designed to be
// close to historically accurate and still playable
inline bool dgdSourcesConflict()
    { return true; }

// all Babylonian clerics wear the wraparound kilt of white with red cuneiform
// writing along the hem
inline bool dgdClericKilt()
    { return true; }

// the clerics enter battle, but always in the rear of the action as support
inline bool dgdClericsRearOfBattle()
    { return true; }

// advancement within a sect is through the payment of gold to the high priest
// court
inline bool dgdAdvancementByPayment()
    { return true; }

// the payment is not level advancement: ability increase does not guarantee
// temporal power
inline bool dgdPaymentNotLevel()
    { return true; }

// successful priests were given great and highly dangerous quests to prove
// their worthiness
inline bool dgdDangerousQuests()
    { return true; }

// the new moon is a time of great ceremony and a tithe paid to the temples to
// appease the gods
inline bool dgdNewMoonCeremony()
    { return true; }

// kings are expected to go forth on quests with clerics and bring back riches
// to further the sect
inline bool dgdKingsQuestForRiches()
    { return true; }

// minor lawbreaking is punished by fasting, prayers, meditation and
// sacrifices until the deity signals forgiveness
inline bool dgdMinorLawFasting()
    { return true; }

// major clerical transgressions are punished by complete denial of spells and
// excommunication
inline bool dgdMajorTransgressionSpells()
    { return true; }

// communicating with intelligent creatures or demi-humans is a crime - all
// are considered demons
inline bool dgdDemiHumansDemons()
    { return true; }

// an erring cleric may atone by taking up a quest aiding the sect in riches
// or power
inline bool dgdQuestAtonement()
    { return true; }

// the high priest is often the king and must be a magic-user/cleric of great
// power
inline bool dgdHighPriestKing()
    { return true; }

// clerical types remain aloof from the normal populace in temples and shrines
inline bool dgdAloofFromPopulace()
    { return true; }

// the clerics work to further the state politically as well as spiritually
inline bool dgdStatePoliticalWork()
    { return true; }

// through Anu and the priest-king all shrine and temple money is dealt out,
// and political power through appointments
inline bool dgdAnuDistributesMoney()
    { return true; }

// ---- the Anu walk ----

// Anu: the brass mace strikes for 2-20
inline int dgdAnuMaceDmgLo()
    { return 2; }

// Anu: the brass mace damage ceiling
inline int dgdAnuMaceDmgHi()
    { return 20; }

// Anu: the strength bonus of 7 points on the mace
inline int dgdAnuMaceBonus()
    { return 7; }

// Anu: beings casting things at him save vs disintegration at -4
inline int dgdAnuCastSavePenalty()
    { return 4; }

// Anu: beings save vs magic at -4 to resist his commands
inline int dgdAnuCommandSavePenalty()
    { return 4; }

// Anu: any dragon type summoned once a week, per type (never royalty)
inline int dgdAnuDragonSummonPerWeek()
    { return 1; }

// Anu, god of the sky, chief of all the Babylonian deities, a greater god
inline bool dgdAnuSkyChief()
    { return true; }

// this god appears as a man
inline bool dgdAnuAppearsAsMan()
    { return true; }

// a strong breeze constantly blows in the direction of his gaze
inline bool dgdAnuBreezeOfGaze()
    { return true; }

// beings casting things at Anu must save vs disintegration at -4 for both
// being and thing
inline bool dgdAnuDisintegrationOnCast()
    { return true; }

// his voice is the voice of all leaders; beings save vs magic at -4 to resist
// his commands
inline bool dgdAnuVoiceOfLeaders()
    { return true; }

// he can summon any dragon type except royalty to fight for him once a week
// per type
inline bool dgdAnuSummonsDragons()
    { return true; }

// he uses a brass mace striking for 2-20 plus his bonus of 7
inline bool dgdAnuBrassMace()
    { return true; }

// Anu is said to have created the heavens and the earth
inline bool dgdAnuCreatedHeavensEarth()
    { return true; }

// all the other Babylonian gods bow to his authority
inline bool dgdAnuAllBowToAuthority()
    { return true; }

// ---- the Anshar walk ----

// Anshar: the darkness beam range, 300 yards maximum
inline int dgdAnsharBeamRangeYards()
    { return 300; }

// Anshar: the beam does 40 points per strike, never regenerated or healed
inline int dgdAnsharBeamDamage()
    { return 40; }

// Anshar: the 200 spell level storage limit
inline int dgdAnsharSpellStoreLimit()
    { return 200; }

// Anshar: one spell effect altered per melee round
inline int dgdAnsharAlteredPerRound()
    { return 1; }

// Anshar, god of darkness and the night, a lesser god
inline bool dgdAnsharGodOfDarkness()
    { return true; }

// the deity always appears as a dark-skinned human
inline bool dgdAnsharDarkSkinned()
    { return true; }

// he only appears at night or in deep darkness
inline bool dgdAnsharNightOnly()
    { return true; }

// the darkness beam does 40 per strike; body parts hit may never be
// regenerated or healed
inline bool dgdAnsharBeamNoRegen()
    { return true; }

// Anshar can only teleport into areas of shadow or darkness
inline bool dgdAnsharTeleportsToShadow()
    { return true; }

// the god is unaffected by any source of light or light reflector
inline bool dgdAnsharUnaffectedByLight()
    { return true; }

// the god can grasp spells out of the air as they pass or hit him, saving
// them like a ring of spell storing or tossing them back
inline bool dgdAnsharGraspsSpells()
    { return true; }

// when preparing for battle he stores one of every ninth level spell, given
// by some other god
inline bool dgdAnsharStartsWithNinths()
    { return true; }

// the storing or returning ability comes from a godly attribute that senses
// spells passing through his area
inline bool dgdAnsharSenseSpells()
    { return true; }

// ---- the Dahak walk ----

// Dahak: the three heads
inline int dgdDahakHeadCount()
    { return 3; }

// Dahak: each head bites for 3-30
inline int dgdDahakBiteDmgLo()
    { return 3; }

// Dahak: the bite damage ceiling
inline int dgdDahakBiteDmgHi()
    { return 30; }

// Dahak: the printed monster-format line, number appearing 1
inline int dgdDahakNoAppearing()
    { return 1; }

// Dahak: 25 percent in lair (the printed monster-format line)
inline int dgdDahakLairPct()
    { return 25; }

// Dahak: the X/24,000 level/xp value line
inline int dgdDahakXpValue()
    { return 24000; }

// Dahak: 72 feet long (the IA 1st-print foot mark against the Termux inch
// mark)
inline int dgdDahakLengthFeet()
    { return 72; }

// Dahak, the three-headed dragon spirit of death, unique
inline bool dgdDahakDragonSpirit()
    { return true; }

// the monster has no corporeal form unless attacking with its bite; the rest
// of the time it is ethereal
inline bool dgdDahakEtherealExceptBite()
    { return true; }

// it appears as a huge three-headed dragon, the scale color depending on its
// whim at the time
inline bool dgdDahakScaleColorWhim()
    { return true; }

// it will only eat the flesh of lawful or good creatures, and it never goes
// hungry
inline bool dgdDahakEatsLawfulGoodFlesh()
    { return true; }

// the monster can breathe any type of dragon breath at any time
inline bool dgdDahakAnyDragonBreath()
    { return true; }

// the creature enjoys crunching things with its teeth
inline bool dgdDahakCrunchesTeeth()
    { return true; }

// it negates any magical device permanently with a touch of all three heads
// at the same time
inline bool dgdDahakNegatesDevices()
    { return true; }

// the printed monster-format intelligence line: average
inline bool dgdDahakAverageIntelligence()
    { return true; }

// ---- the Druaga walk ----

// Druaga: the mace does 35 points every time it hits
inline int dgdDruagaMaceDamage()
    { return 35; }

// Druaga: calls any devil type (never arch-devils), 2-20 a day
inline int dgdDruagaDevilCallLo()
    { return 2; }

// Druaga: the devil call ceiling
inline int dgdDruagaDevilCallHi()
    { return 20; }

// Druaga: the real form has 8 arms ending in talons
inline int dgdDruagaArmCount()
    { return 8; }

// Druaga: 4 legs ending in snakey masses
inline int dgdDruagaLegCount()
    { return 4; }

// Druaga, ruler of the devil world, a lesser god
inline bool dgdDruagaDevilRuler()
    { return true; }

// the real form has the head of a beautiful boy, scaled with ruby red hide
inline bool dgdDruagaBoyHead()
    { return true; }

// the combination is so hideous it often paralyzes enemies with fear
inline bool dgdDruagaParalyzingUgliness()
    { return true; }

// it can shape change at will and never appears the same way twice
inline bool dgdDruagaShapeChange()
    { return true; }

// it calls on any type of devil (except the arch-devils) once a day in
// numbers from 2-20
inline bool dgdDruagaCallsDevils()
    { return true; }

// Druaga is not affected by breath weapons from any creature
inline bool dgdDruagaBreathImmune()
    { return true; }

// Druaga only fights in person when his soul object, always put in a living
// being, is threatened
inline bool dgdDruagaSoulObject()
    { return true; }

// if his body is destroyed the soul object regenerates a whole new being with
// all the memories of the old devil
inline bool dgdDruagaSoulRegenerates()
    { return true; }

// the human with Druaga soul implanted has no knowledge of it and dies when
// the devil body dies
inline bool dgdDruagaHostUnaware()
    { return true; }

// when the human body is buried there is a safe place for the new devil to
// grow
inline bool dgdDruagaBurialDoctrine()
    { return true; }

// Druaga occasionally sends devils to aid worshipers who recently sacrificed
// a virgin
inline bool dgdDruagaAidsSacrificers()
    { return true; }

// his mace turns beings it hits into devils (random type) under his command
// unless they save vs magic
inline bool dgdDruagaMaceDevilMaker()
    { return true; }

// ---- the Gilgamesh walk ----

// Gilgamesh: the +2 mace
inline int dgdGilgameshMacePlus()
    { return 2; }

// Gilgamesh: the mace hits with brutal force, 2-20
inline int dgdGilgameshMaceDmgLo()
    { return 2; }

// Gilgamesh: the mace damage ceiling
inline int dgdGilgameshMaceDmgHi()
    { return 20; }

// Gilgamesh, the hero of legend, warrior/necromancer/high priest ruler of his
// land
inline bool dgdGilgameshHero()
    { return true; }

// he is noted for going out and getting things done when others were unable
inline bool dgdGilgameshGetsThingsDone()
    { return true; }

// he loves to attack by wrestling, preferring it to all other attack modes
inline bool dgdGilgameshPrefersWrestling()
    { return true; }

// stories abound of him wrestling a mighty bull or god to destruction
inline bool dgdGilgameshWrestledBullGod()
    { return true; }

// a great king noted for his tyrannical rule
inline bool dgdGilgameshTyrannical()
    { return true; }

// he governs well and maintains peace, using authority to satisfy personal
// pleasures
inline bool dgdGilgameshGovernsWell()
    { return true; }

// a great lover of all types of earthly pleasure
inline bool dgdGilgameshEarthlyPleasures()
    { return true; }

// stubborn, preferring the direct method for solving problems
inline bool dgdGilgameshStubbornDirect()
    { return true; }

// Gilgamesh has a great fear of death and will do whatever is required to
// avoid it
inline bool dgdGilgameshFearsDeath()
    { return true; }

// his fear seldom occurs when facing a terrible foe; courage heartens him and
// he fights without wavering
inline bool dgdGilgameshCourageVsFoe()
    { return true; }

// the printed special defenses line: cannot be charmed
inline bool dgdGilgameshCannotBeCharmed()
    { return true; }

// ---- the Girru walk ----

// Girru: casts all fire spells as a 40th level magic-user (the See below
// cell)
inline int dgdGirruFireSpellLevel()
    { return 40; }

// Girru: 10 points per melee round of heat damage
inline int dgdGirruHeatDamage()
    { return 10; }

// Girru: the heat aura reaches 10 feet (no saving throw)
inline int dgdGirruHeatFeet()
    { return 10; }

// Girru: the +3 axe (the IA voice against the Termux +43 garble)
inline int dgdGirruAxePlus()
    { return 3; }

// Girru: the axe hits for 2-20 plus strength
inline int dgdGirruAxeDmgLo()
    { return 2; }

// Girru: the axe damage ceiling
inline int dgdGirruAxeDmgHi()
    { return 20; }

// Girru: the axe stuns for 2-8 rounds (save vs petrification)
inline int dgdGirruStunLo()
    { return 2; }

// Girru: the stun ceiling
inline int dgdGirruStunHi()
    { return 8; }

// Girru: the mace barb save vs poison at -4
inline int dgdGirruPoisonSavePenalty()
    { return 4; }

// Girru, god of fire, a lesser god
inline bool dgdGirruGodOfFire()
    { return true; }

// Girru usually manifests himself as a man
inline bool dgdGirruManifestsAsMan()
    { return true; }

// he hates all things evil and destroys them on contact
inline bool dgdGirruHatesEvil()
    { return true; }

// the god is totally unaffected by fire
inline bool dgdGirruUnaffectedByFire()
    { return true; }

// he can shape change and teleport, though only to places with flame in the
// area
inline bool dgdGirruTeleportsToFlame()
    { return true; }

// all within 10 feet suffer 10 points per melee round of heat, no saving
// throw
inline bool dgdGirruHeatAura()
    { return true; }

// a poisoned barb breaks off the mace and embeds in the victim with each hit,
// save vs poison at -4
inline bool dgdGirruPoisonBarb()
    { return true; }

// the +3 axe: save vs petrification or be stunned 2-8 rounds
inline bool dgdGirruStunningAxe()
    { return true; }

// any weapon touching the god body disintegrates after doing its damage, no
// saving throw
inline bool dgdGirruWeaponDisintegrate()
    { return true; }

// ---- the Ishtar walk ----

// Ishtar: casts 2 spells per melee round
inline int dgdIshtarSpellsPerRound()
    { return 2; }

// Ishtar: the flying chariot is pulled by 7 enchanted lions
inline int dgdIshtarLionCount()
    { return 7; }

// Ishtar: each lion has 50 hit points
inline int dgdIshtarLionHP()
    { return 50; }

// Ishtar: each lion has 11 hit dice
inline int dgdIshtarLionHD()
    { return 11; }

// Ishtar: each lion is armor class -2
inline int dgdIshtarLionAC()
    { return -2; }

// Ishtar: the chariot travels at 21 inches per turn
inline int dgdIshtarChariotSpeed()
    { return 21; }

// Ishtar: the crystal rod transforms spell level into energy times ten
inline int dgdIshtarRodMult()
    { return 10; }

// Ishtar: a first level spell strikes for 10 through the rod
inline int dgdIshtarRodMinDamage()
    { return 10; }

// Ishtar: a ninth level spell strikes for 90 through the rod
inline int dgdIshtarRodMaxDamage()
    { return 90; }

// Ishtar, goddess of love and war, a greater goddess
inline bool dgdIshtarGoddessLoveWar()
    { return true; }

// she never appears to worshipers in any form other than a beautiful woman
inline bool dgdIshtarBeautifulWomanOnly()
    { return true; }

// she has the strength of a titan
inline bool dgdIshtarTitanStrength()
    { return true; }

// she can shape change at will
inline bool dgdIshtarShapeChange()
    { return true; }

// she uses her voice as a constant suggestion spell
inline bool dgdIshtarVoiceSuggestion()
    { return true; }

// when interested in a male, the headdress of love and war forces passionate
// love, no saving throw
inline bool dgdIshtarHeaddressLove()
    { return true; }

// when fighting an enemy the headdress gives the wearer the same powers her
// enemies have
inline bool dgdIshtarHeaddressEnemyPowers()
    { return true; }

// Ishtar drives a flying chariot pulled by 7 enchanted lions
inline bool dgdIshtarFlyingChariot()
    { return true; }

// the lions cannot be controlled by any being except the goddess herself
inline bool dgdIshtarLionsUncontrollable()
    { return true; }

// when in the chariot no metal can touch the goddess
inline bool dgdIshtarNoMetalTouch()
    { return true; }

// the blue crystal rod transforms any spell level into direct energy times
// ten against magic-resistant beings
inline bool dgdIshtarRodEnergy()
    { return true; }

// ---- the Marduk walk ----

// Marduk: always shown with four eyes
inline int dgdMardukEyeCount()
    { return 4; }

// Marduk: and four ears
inline int dgdMardukEarCount()
    { return 4; }

// Marduk: the god must remain within 50 feet of the silvery net
inline int dgdMardukNetRangeFeet()
    { return 50; }

// Marduk: summons 20 dice lightning bolts from the sky
inline int dgdMardukLightningDice()
    { return 20; }

// Marduk: +3 or better weapon to hit
inline int dgdMardukWeaponPlusToHit()
    { return 3; }

// Marduk, god of the city, wind, thunder, storms and rain, a greater god
inline bool dgdMardukGodOfCity()
    { return true; }

// one of the few nonhuman-appearing beings of the pantheon
inline bool dgdMardukNonhumanForm()
    { return true; }

// always shown with four eyes, four ears and flames shooting from his mouth
// when he speaks, reddish tinge to his skin
inline bool dgdMardukFlameSpeech()
    { return true; }

// he occasionally assumes leadership of the Babylonian gods when Anu is
// preoccupied
inline bool dgdMardukLeadsWhenAnuBusy()
    { return true; }

// he can borrow any single ability from any one other deity of the pantheon,
// no saving throw, given back at any distance
inline bool dgdMardukBorrowsAbility()
    { return true; }

// in battle he uses a net made of the four winds that binds until released,
// strands unbreakable
inline bool dgdMardukSilveryNet()
    { return true; }

// the god may create any type of weather condition in an instant
inline bool dgdMardukWeatherInstant()
    { return true; }

// Marduk is called the justice bringer and lord of pure incantations
inline bool dgdMardukJusticeBringer()
    { return true; }

// his battles with Tiamat are legendary
inline bool dgdMardukTiamatLegend()
    { return true; }

// ---- the Nergal walk ----

// Nergal: the night-black shield has a bonus of +5
inline int dgdNergalShieldPlus()
    { return 5; }

// Nergal: the death spell aura radius, 30 feet
inline int dgdNergalDeathAuraFeet()
    { return 30; }

// Nergal: no spell of less than the eighth level affects the shield user
inline int dgdNergalSpellFloor()
    { return 8; }

// Nergal: revives the 5 most powerful dead enemies of his foes
inline int dgdNergalReviveCount()
    { return 5; }

// Nergal, god of the underworld, a lesser god
inline bool dgdNergalGodOfUnderworld()
    { return true; }

// this deity rules over all things that are dead
inline bool dgdNergalRulesTheDead()
    { return true; }

// he never uses any form but a human one
inline bool dgdNergalHumanFormOnly()
    { return true; }

// his favorite tactic is reviving the 5 most powerful dead enemies of his
// foes to fight for him
inline bool dgdNergalRevivesEnemies()
    { return true; }

// in personal combat he uses the night-black shield, both a weapon and a
// defense
inline bool dgdNergalBlackShield()
    { return true; }

// when the shield is in use no being can attack the god from behind
inline bool dgdNergalNoBackAttack()
    { return true; }

// the shield casts a death spell aura, saving throw applicable, in a 30 foot
// radius
inline bool dgdNergalDeathAura()
    { return true; }

// his worshipers sacrifice good creatures on the black basalt altar
inline bool dgdNergalBasaltAltar()
    { return true; }

// or dedicate the proceeds of evil actions to the church in a type of
// promised sacrifice
inline bool dgdNergalPromisedSacrifice()
    { return true; }

// ---- the Ramman walk ----

// Ramman: sparks do 30 points to anything within 3 inches of his body
inline int dgdRammanSparkDamage()
    { return 30; }

// Ramman: the spark range
inline int dgdRammanSparkRangeInches()
    { return 3; }

// Ramman: each lightning bolt does 30 points
inline int dgdRammanBoltDamage()
    { return 30; }

// Ramman: lightning bolts cast two per round
inline int dgdRammanBoltsPerRound()
    { return 2; }

// Ramman: spells must be of the fifth level or greater to affect him
inline int dgdRammanSpellFloor()
    { return 5; }

// Ramman: the +4 ring mail of cloud vapor
inline int dgdRammanRingMailPlus()
    { return 4; }

// Ramman: the ten-foot mallet does 30 points every time it hits
inline int dgdRammanMalletDamage()
    { return 30; }

// Ramman: the mallet length in feet
inline int dgdRammanMalletFeet()
    { return 10; }

// Ramman, god of storms and thunder, a lesser god
inline bool dgdRammanGodOfStorms()
    { return true; }

// he appears on earth in human form with a massive build and a rather homely
// face
inline bool dgdRammanHumanMassive()
    { return true; }

// when anything hits him sparks fly doing 30 points to anything within 3
// inches, no saving throw
inline bool dgdRammanSparksOnHit()
    { return true; }

// his lightning bolts are cast two per round, 30 points each
inline bool dgdRammanLightning()
    { return true; }

// his +4 ring mail is made out of cloud vapor
inline bool dgdRammanCloudMail()
    { return true; }

// the thrown mallet does 30 points and returns by itself to his hand
inline bool dgdRammanMalletReturns()
    { return true; }

// the mallet is usually only used against creatures that resist his lightning
// strikes
inline bool dgdRammanMalletVsResisters()
    { return true; }

// his neutral worshipers always perform their services at night
inline bool dgdRammanNightServices()
    { return true; }

// other beings sacrifice expensive liquids to bring rain for crops or cooler
// weather
inline bool dgdRammanRainSacrifices()
    { return true; }

// the printed worshiper line: all neutrals plus special
inline bool dgdRammanAllNeutralsWorship()
    { return true; }

// ---- the combat grid ----

// The armor class cells (the ten printed single armor classes)
inline int dgdCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return -1;
        case 4:
            return 6;
        case 5:
            return -2;
        case 6:
            return -4;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return -4;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all ten read
// single this round)
inline int dgdCbtACAlt(int b)
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
        default:
            return 0;
        }
    }

// The hit point cells (400 for Anu the greater god down to 180 for the hero
// Gilgamesh)
inline int dgdCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 300;
        case 2:
            return 200;
        case 3:
            return 230;
        case 4:
            return 180;
        case 5:
            return 280;
        case 6:
            return 250;
        case 7:
            return 350;
        case 8:
            return 300;
        case 9:
            return 325;
        default:
            return 0;
        }
    }

// The primary move cells (0 = the printed Infinite: Marduk; Dahak reads the
// flagged 9 of the second-print extract against the 1st-print 15)
inline int dgdCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 9;
        case 3:
            return 21;
        case 4:
            return 15;
        case 5:
            return 18;
        case 6:
            return 12;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 12;
        default:
            return 0;
        }
    }

// The alternate move cells (0 = a single printed move; Nergal reads 12 over
// 12, Ramman 12 over 48, Druaga 21 over 45, Dahak the flagged 18)
inline int dgdCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 45;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 48;
        default:
            return 0;
        }
    }

// The attacks-per-round numerator cells (Anshar reads the printed 0)
inline int dgdCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        default:
            return 0;
        }
    }

// The attacks-per-round denominator cells (0 = a single printed figure)
inline int dgdCbtAtD(int b)
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
        default:
            return 0;
        }
    }

// The magic resistance cells (99 = the printed See below: Nergal the shield
// doctrine)
inline int dgdCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 50;
        case 2:
            return 55;
        case 3:
            return 75;
        case 4:
            return 10;
        case 5:
            return 50;
        case 6:
            return 75;
        case 7:
            return 50;
        case 8:
            return 99;
        case 9:
            return 50;
        default:
            return 0;
        }
    }

// The size-in-inches cells (Dahak is 72 feet long - 864 inches; Druaga and
// Marduk are 9 feet - 108; Ramman 7 feet - 84; Anu the 6 is clean in both
// voices but the inch mark garbles)
inline int dgdCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 72;
        case 1:
            return 72;
        case 2:
            return 864;
        case 3:
            return 108;
        case 4:
            return 72;
        case 5:
            return 72;
        case 6:
            return 72;
        case 7:
            return 108;
        case 8:
            return 72;
        case 9:
            return 84;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (0 = Nil; Nergal the 25th level cleric)
inline int dgdClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 5;
        case 5:
            return 0;
        case 6:
            return 15;
        case 7:
            return 0;
        case 8:
            return 25;
        case 9:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (Gilgamesh reads 5th level in each with the cleric)
inline int dgdClsDruid(int b)
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
            return 5;
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
        default:
            return 0;
        }
    }

// The fighter level floor cells
inline int dgdClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 0;
        case 5:
            return 16;
        case 6:
            return 0;
        case 7:
            return 19;
        case 8:
            return 12;
        case 9:
            return 17;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells
inline int dgdClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 0;
        case 5:
            return 16;
        case 6:
            return 0;
        case 7:
            return 19;
        case 8:
            return 12;
        case 9:
            return 17;
        default:
            return 0;
        }
    }

// The ranger level cells (Gilgamesh 12th level ranger, Ishtar 20th)
inline int dgdClsRanger(int b)
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
            return 12;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return 0;
        }
    }

// The magic-user level cells (99 = the printed See below: Anu, Anshar, Girru
// - the Girru 40th level fire-spell doctrine rides the consts)
inline int dgdClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 99;
        case 2:
            return 0;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 99;
        case 6:
            return 25;
        case 7:
            return 16;
        case 8:
            return 20;
        case 9:
            return 15;
        default:
            return 0;
        }
    }

// The illusionist level cells (Ramman 15th level in each with the magic-user)
inline int dgdClsIllus(int b)
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
            return 15;
        default:
            return 0;
        }
    }

// The thief level cells (0 = Nil - none printed this round)
inline int dgdClsThief(int b)
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
        default:
            return 0;
        }
    }

// The assassin level cells (Druaga the 15th level assassin)
inline int dgdClsAssassin(int b)
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
            return 0;
        case 9:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (Gilgamesh 11th level monk)
inline int dgdClsMonk(int b)
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
            return 11;
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
        default:
            return 0;
        }
    }

// The bard level cells (Gilgamesh 5th, Marduk 15th)
inline int dgdClsBard(int b)
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
            return 5;
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
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (0 = the Dahak monster row, no printed ability grid)
inline int dgdAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 16;
        case 2:
            return 0;
        case 3:
            return 24;
        case 4:
            return 20;
        case 5:
            return 24;
        case 6:
            return 25;
        case 7:
            return 24;
        case 8:
            return 19;
        case 9:
            return 22;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = none printed: Anshar
// reads the printed 0 bracket)
inline int dgdAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 6;
        case 8:
            return 3;
        case 9:
            return 4;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells
inline int dgdAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 12;
        case 4:
            return 8;
        case 5:
            return 12;
        case 6:
            return 14;
        case 7:
            return 12;
        case 8:
            return 7;
        case 9:
            return 10;
        default:
            return 0;
        }
    }

// The intelligence cells
inline int dgdAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 20;
        case 2:
            return 0;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 20;
        case 6:
            return 22;
        case 7:
            return 23;
        case 8:
            return 20;
        case 9:
            return 20;
        default:
            return 0;
        }
    }

// The wisdom cells
inline int dgdAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 12;
        case 2:
            return 0;
        case 3:
            return 13;
        case 4:
            return 17;
        case 5:
            return 14;
        case 6:
            return 12;
        case 7:
            return 24;
        case 8:
            return 20;
        case 9:
            return 16;
        default:
            return 0;
        }
    }

// The dexterity cells
inline int dgdAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 18;
        case 2:
            return 0;
        case 3:
            return 23;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 25;
        case 7:
            return 20;
        case 8:
            return 19;
        case 9:
            return 21;
        default:
            return 0;
        }
    }

// The constitution cells (the printed C: column)
inline int dgdAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 22;
        case 2:
            return 0;
        case 3:
            return 25;
        case 4:
            return 19;
        case 5:
            return 23;
        case 6:
            return 23;
        case 7:
            return 24;
        case 8:
            return 23;
        case 9:
            return 24;
        default:
            return 0;
        }
    }

// The charisma cells (Druaga reads the printed 4 - the single-glyph 15px TSV
// width against the 24px two-digit calibration)
inline int dgdAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 18;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 25;
        case 7:
            return 23;
        case 8:
            return 24;
        case 9:
            return 16;
        default:
            return 0;
        }
    }

// The psionic cells (0 = Nil; this mythos prints roman-numeral classes, not
// scores - the VI cells ride the roster grid)
inline int dgdAbiPsi(int b)
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
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Anu through Ramman)
inline int dgdRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print page cells (22-25, the folio offset PRINT = PDF - 1)
inline int dgdRosPage(int b)
    {
        switch (b) {
        case 0:
            return 22;
        case 1:
            return 22;
        case 2:
            return 23;
        case 3:
            return 23;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 24;
        case 8:
            return 25;
        case 9:
            return 25;
        default:
            return 0;
        }
    }

// The alignment cells (0 lawful good, 1 neutral good, 3 lawful neutral, 4
// neutral, 6 lawful evil, 7 neutral evil, 8 chaotic evil)
inline int dgdRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 8;
        case 2:
            return 8;
        case 3:
            return 6;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 4;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser god, 1 greater god, 2 hero, 3 monster format:
// Gilgamesh the hero, Dahak the monster)
inline int dgdRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 0;
        case 4:
            return 2;
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
        default:
            return 0;
        }
    }

// The psionic class cells (6 = the printed class VI of the R849 class table:
// Anu and Anshar; 0 = Nil)
inline int dgdRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
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
        default:
            return 0;
        }
    }

// The plane cells (1 Nirvana, 2 Pandemonium, 3 Nine Hells, 4 Seven Heavens, 5
// Elysium, 6 Arcadia, 7 Hades, 8 Concordant Opposition; 0 = none printed: the
// Dahak monster row and the Gilgamesh hero row)
inline int dgdRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 7;
        case 9:
            return 8;
        default:
            return 0;
        }
    }

// The fixed-damage cells (1 = a printed damage figure instead of by weapon
// type: Anu 2-20+7, Dahak 3-30 x3, Druaga 35, Gilgamesh 2-20+8, Girru 1-8+12
// / 2-20+12, Ramman 30; the four See below / Nil rows read 0)
inline int dgdRosDmgFixed(int b)
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
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return 0;
        }
    }

// The percent-in-lair cells (the Dahak monster-format 25 percent; the deity
// rows read 0)
inline int dgdRosLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 25;
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
        default:
            return 0;
        }
    }

// The ethereal cells (1 = the Dahak ethereal-except-bite doctrine)
inline int dgdRosEthereal(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
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
        default:
            return 0;
        }
    }

}   // namespace rules
