// =========================================================================================
// Adnd1 - rules/cth.h
// the Cthulhu mythos - the D&DG walk round eight, print pp. 43-48: fifteen
// beings from Cthulhu the dreamer in sunken R lyeh to Yog-Sothoth the key and
// guardian of the gate, the seven monster races of the Old Ones, and the two
// artifacts - the Elder Sign and the Necronomicon - across four planes.
// census 778 -> 779.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 044-049; the second printing); the
// collation voice: the archive.org 1st-print derivative
// (deities-demigods-1st-print, djvu.txt + djvu.xml word geometry at 600dpi,
// segs 43-48). The adjudications: the psionic classes by word geometry (the
// 10px single bars of Cthulhu, Cthugha, Hastur, Shub-Niggurath and
// Yog-Sothoth; Byakhee the 54px IV, Ithaqua the IV, the Flame Creature V,
// Nyarlathotep V, Azathoth VI), the monster psionic point scores (Great Race
// 280, Mi-Go 90, Primordial One 206 - the R853 Math 200 precedent), the Mi-Go
// size (the IA geometry 8 feet against the Termux 8 inches), the Primordial
// One move (the printed 18/12 slash in both voices - flagged), the Cthulhu
// charisma (both voices read 7, the minus lost - pinned 7, flagged for the
// physical-copy eyeball), and the Cthugha ability line (IA scrawl, the Termux
// fold pinned, flagged).
//
namespace rules {

// ---- the R856 census ----

// the Cthulhu mythos round: the D&DG walk round eight, print pp. 43-48
inline int cthRound()
    { return 856; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int cthPrintStart()
    { return 43; }

// the last print page
inline int cthPrintEnd()
    { return 48; }

// the fifteen beings of the mythos (Cthulhu through Yog-Sothoth, the eight
// deities and the seven monster races)
inline int cthBeingCount()
    { return 15; }

// the four grids (combat, class, ability, roster)
inline int cthTableCount()
    { return 4; }

// no chains this round
inline int cthChainCount()
    { return 0; }

// the live registry def count floor: zero defs touched this round
inline int cthRegistryFloor()
    { return 995; }

// the combat grid rows (one per being)
inline int cthCbtRows()
    { return 15; }

// the class grid rows
inline int cthClsRows()
    { return 15; }

// the ability grid rows
inline int cthAbiRows()
    { return 15; }

// the roster grid rows
inline int cthRosRows()
    { return 15; }

// the four printed planes: Prime Material, Astral, Elemental Fire, Elemental
// Air (0 = the monster rows)
inline int cthPlaneCount()
    { return 4; }

// the R849 psionic class I (Cthulhu, Cthugha, Hastur, Shub-Niggurath,
// Yog-Sothoth)
inline int cthPsiClassI()
    { return 1; }

// the R849 psionic class IV (Byakhee, Ithaqua)
inline int cthPsiClassIV()
    { return 4; }

// the R849 psionic class V (the Flame Creatures, Nyarlathotep)
inline int cthPsiClassV()
    { return 5; }

// the R849 psionic class VI (Azathoth)
inline int cthPsiClassVI()
    { return 6; }

// the two artifacts: the Elder Sign and the Necronomicon
inline int cthArtifactCount()
    { return 2; }

// ---- the mythos intro ----

// the Old Ones descended to Earth from the stars in pre-human times
inline bool cthOldOnesFromStars()
    { return true; }

// the Old Ones were later banished or locked away by the elder gods
inline bool cthOldOnesBanished()
    { return true; }

// the elder gods do not enter the stories much and their identity is a
// mystery
inline bool cthElderGodsMysterious()
    { return true; }

// bits of the old lore were transcribed into books, extremely dangerous books
inline bool cthForbiddenBooksDangerous()
    { return true; }

// August Derleth founded Arkham House to reprint the works and wrote the
// good-vs-evil struggle
inline bool cthDerlethArkhamHouse()
    { return true; }

// Lovecraft's original concept: all his gods evil and chaotic, the best
// mankind could expect was indifference
inline bool cthLovecraftIndifferent()
    { return true; }

// all creatures of nature call out their warning sounds and flee when the Old
// Ones or minions come within range
inline bool cthNatureCreaturesFlee()
    { return true; }

// the release insanity lasts a number of months equal to the creature
// intelligence
inline bool cthInsanityMonthsEqualIntelligence()
    { return true; }

// a god who hears its name spoken will appear and attempt to kill the speaker
inline bool cthNameSpeakingGodAppears()
    { return true; }

// some of the greater gods will send minions to accomplish the killing
inline bool cthNameSpeakingMaySendMinions()
    { return true; }

// some of the seven lesser books have powers similar to, but lesser than, the
// Necronomicon itself
inline bool cthLesserBooksWeakerPowers()
    { return true; }

// ---- the mythos lore ----

// the name-speaking doctrine: a 5 percent chance the god hears its spoken
// name
inline int cthLoreNameHeardPct()
    { return 5; }

// the +4 saving throws against fear and insanity inside risen R lyeh
inline int cthLoreRlyehSaveBonus()
    { return 4; }

// the death-or-insanity saving throw radius in miles when the Elder Sign seal
// is broken
inline int cthLoreReleaseRadiusMiles()
    { return 100; }

// the seven lesser forbidden books (Eibon, Celaeno, Cultes des Goules, De
// Vermis Mysteriis, Dhol Chants, Pnakotic Manuscripts, Unausprechlichen
// Kulten)
inline int cthLoreLesserBookCount()
    { return 7; }

// ---- the Elder Sign walk ----

// the Elder Sign armor class (broken only by magic or incredible force)
inline int cthElderSignAC()
    { return -2; }

// the +6 protection against the attacks of the more powerful masters (as a
// ring of protection)
inline int cthElderSignProtectionBonus()
    { return 6; }

// the small grey (sometimes greenish) stone in the shape of a five-pointed
// star
inline bool cthElderSignGreyStone()
    { return true; }

// the true potent Elder Signs are 100 percent protection against psionic
// attacks
inline bool cthElderSignPsionicProof()
    { return true; }

// strongly presented, they drive off all Shoggoths, Byakhee, Flame Creatures,
// Deep Ones and Mi-Go
inline bool cthElderSignDrivesOffMinions()
    { return true; }

// against the more powerful masters they provide the +6 protection (as a ring
// of protection)
inline bool cthElderSignPlusSixVsMasters()
    { return true; }

// the Elder Signs resist destruction - broken only by magic or incredible
// force
inline bool cthElderSignBrokenByMagicOrForce()
    { return true; }

// the Elder Sign was used by the elder gods to seal off the prisons and
// breaking-through places
inline bool cthElderSignSealedPrisons()
    { return true; }

// ---- the Necronomicon walk ----

// the 40 percent probability of alignment change or madness for readers below
// 5th level
inline int cthNecronomiconInsanityPct()
    { return 40; }

// the level floor of that 40 percent roll
inline int cthNecronomiconLevelFloor()
    { return 5; }

// the probability decreases by 5 percent per level above 4th
inline int cthNecronomiconPctDecrement()
    { return 5; }

// only magic-users of 18 intelligence have a chance of understanding the
// spells
inline int cthNecronomiconIntReq()
    { return 18; }

// the 5 percent per level chance of understanding, starting at the 6th level
inline int cthNecronomiconStudyPct()
    { return 5; }

// the starting level of that study chance
inline int cthNecronomiconStudyStart()
    { return 6; }

// the straight 30 percent chance of insanity when casting a greater summoning
inline int cthNecronomiconSummonInsanityPct()
    { return 30; }

// originally written as Al Azif, the nocturnal sounds of insects
inline bool cthNecronomiconAlAzifTitle()
    { return true; }

// written by Abdul Alhazred, the Mad Arab, after ten years alone in the
// desert
inline bool cthNecronomiconMadArab()
    { return true; }

// Alhazred was seized in the streets of a desert city by invisible demons and
// devoured horribly
inline bool cthNecronomiconDevouredByDemons()
    { return true; }

// the book was banned and all known copies destroyed, but a few translated
// editions remain
inline bool cthNecronomiconBannedDestroyed()
    { return true; }

// the d6 sub-roll: 1-3 alignment change to chaotic, 4-6 going mad
inline bool cthNecronomiconAlignmentOrMadness()
    { return true; }

// many spells require that the stars be right, at certain times of the year
// or in certain places
inline bool cthNecronomiconStarsMustBeRight()
    { return true; }

// the spells often fail to protect the caster from the thing called from the
// outer darkness
inline bool cthNecronomiconProtectionFails()
    { return true; }

// the unfortunates are rarely seen again, though simulacra or zombie-like
// imitations sometimes appear
inline bool cthNecronomiconSimulacraAppear()
    { return true; }

// ---- the Cthulhu walk ----

// the 1-10 damage per attack (x 30)
inline int cthCthulhuDmgLo()
    { return 1; }

// the damage ceiling
inline int cthCthulhuDmgHi()
    { return 10; }

// the 10 hit points regenerated per melee round
inline int cthCthulhuRegen()
    { return 10; }

// the one-half mile teleport at will
inline int cthCthulhuTeleportRangeFeet()
    { return 2640; }

// the 10-100 Deep Ones called up from the sea
inline int cthCthulhuCallDeepOnesLo()
    { return 10; }

// the call ceiling
inline int cthCthulhuCallDeepOnesHi()
    { return 100; }

// Cthulhu's cult is hidden and secret, dedicated to bringing about his return
// and conquest
inline bool cthCthulhuCultSecret()
    { return true; }

// the bloated humanoid form with an octopoid head and a face of tentacle-like
// cilia
inline bool cthCthulhuOctopoidHead()
    { return true; }

// the pair of folded bat-like wings protruding from between its shoulders
inline bool cthCthulhuBatWings()
    { return true; }

// R'lyeh the great sunken city of non-Euclidian geometry hidden beneath the
// ocean
inline bool cthCthulhuSunkenRlyeh()
    { return true; }

// so bizarre its construction that entrants save at +4 against fear and
// insanity
inline bool cthCthulhuNonEuclidian()
    { return true; }

// totally immune to the effects of water, cold and vacuum
inline bool cthCthulhuImmuneWaterColdVacuum()
    { return true; }

// he retreats into his lair if confronted with an intact Elder Sign
inline bool cthCthulhuRetreatElderSign()
    { return true; }

// he retreats if confronted with another of the Old Ones (such as Hastur)
inline bool cthCthulhuRetreatOldOne()
    { return true; }

// he retreats at some natural catastrophe, such as the re-sinking of R lyeh
inline bool cthCthulhuRetreatCatastrophe()
    { return true; }

// served by the Deep Ones as well as his human worshipers
inline bool cthCthulhuServedByDeepOnes()
    { return true; }

// his human worshipers often interbreed with the fish-men
inline bool cthCthulhuInterbreedingCult()
    { return true; }

// the printed FIGHTER cell: As 16+ HD monster
inline bool cthCthulhuFighterAs16HDMonster()
    { return true; }

// ---- the Azathoth walk ----

// the 3-18 damage per pseudopod (x 20)
inline int cthAzathothDmgLo()
    { return 3; }

// the damage ceiling
inline int cthAzathothDmgHi()
    { return 18; }

// the 1,000 mile radius of the permanent-madness aura
inline int cthAzathothAuraMiles()
    { return 1000; }

// the save vs spells modifier inside the aura
inline int cthAzathothAuraSaveMod()
    { return -6; }

// a blind, mindless, amorphous mass the size of a star at the center of the
// universe
inline bool cthAzathothBlindMindless()
    { return true; }

// floating on the astral plane, somewhat solid near the center where it can
// be attacked
inline bool cthAzathothAmorphousStar()
    { return true; }

// attended by satellite creatures that provide an eerie music, like idiot
// flute players
inline bool cthAzathothFluteMusic()
    { return true; }

// it defends itself with its many pseudopods when attacked at the solid
// center
inline bool cthAzathothPseudopodDefense()
    { return true; }

// those who worship Azathoth worship insanity, and his clerics are themselves
// insane
inline bool cthAzathothClericsInsane()
    { return true; }

// it is unknown how Azathoth grants powers, or even if he is aware of his
// clerics (doubtful)
inline bool cthAzathothMaybeUnaware()
    { return true; }

// the printed FIGHTER cell: As 16+ HD monster
inline bool cthAzathothFighterAs16HDMonster()
    { return true; }

// ---- the Cthugha walk ----

// the 3-30 damage per tentacle lash
inline int cthCthughaDmgLo()
    { return 3; }

// the damage ceiling
inline int cthCthughaDmgHi()
    { return 30; }

// the 5-50 body heat damage
inline int cthCthughaHeatLo()
    { return 5; }

// the heat ceiling
inline int cthCthughaHeatHi()
    { return 50; }

// the heat damage radius in yards
inline int cthCthughaHeatRangeYards()
    { return 100; }

// the 30th level fire spell casting
inline int cthCthughaFireCasterLevel()
    { return 30; }

// two fire spells per round
inline int cthCthughaSpellsPerRound()
    { return 2; }

// the +3 or better weapon needed to strike it
inline int cthCthughaWeaponPlus()
    { return 3; }

// the 1-20 flame creatures summoned on arrival
inline int cthCthughaSummonLo()
    { return 1; }

// the summon ceiling
inline int cthCthughaSummonHi()
    { return 20; }

// resembles a flaming amoeba with tentacle-like flames emanating from its
// body
inline bool cthCthughaFlamingAmoeba()
    { return true; }

// the printed CLERIC/DRUID cell: See below
inline bool cthCthughaClericSeeBelow()
    { return true; }

// the printed MAGIC-USER/ILLUSIONIST cell: See below
inline bool cthCthughaMUSeeBelow()
    { return true; }

// it moves as a blink dog and attempts to destroy everything in the summoned
// area
inline bool cthCthughaMovesAsBlinkDog()
    { return true; }

// it cannot be controlled, and is immune to all heat and cold attacks
inline bool cthCthughaImmuneHeatCold()
    { return true; }

// only +3 or better weapons strike it; all others melt when touching him
inline bool cthCthughaMeltsWeapons()
    { return true; }

// its Palace of Fire in an active volcano, filled with flame-resistant
// treasure
inline bool cthCthughaPalaceOfFire()
    { return true; }

// the printed FIGHTER cell: As 16+ HD monster
inline bool cthCthughaFighterAs16HDMonster()
    { return true; }

// ---- the Byakhee walk ----

// the 1-10 damage per attack
inline int cthByakheeDmgLo()
    { return 1; }

// the damage ceiling
inline int cthByakheeDmgHi()
    { return 10; }

// the 10 hit dice
inline int cthByakheeHD()
    { return 10; }

// the 1-4 appearing
inline int cthByakheeAppearingLo()
    { return 1; }

// the appearing ceiling
inline int cthByakheeAppearingHi()
    { return 4; }

// the 5 percent in lair
inline int cthByakheeLairPct()
    { return 5; }

// the IX level/xp value label
inline int cthByakheeXpLevel()
    { return 9; }

// the 9,350 base xp
inline int cthByakheeXpBase()
    { return 9350; }

// the 20 xp per hit point
inline int cthByakheeXpPerHp()
    { return 20; }

// the 1-4 Byakhee of the Hastur gate spell
inline int cthByakheeGateSummonLo()
    { return 1; }

// the gate ceiling
inline int cthByakheeGateSummonHi()
    { return 4; }

// the printed name block: Byakhee (servants of Hastur)
inline bool cthByakheeServantsOfHastur()
    { return true; }

// giant furry bat-like creatures with humanoid legs that enable them to stand
// like men
inline bool cthByakheeBatLike()
    { return true; }

// the humanoid legs carrying human beings on their backs or in their talons
inline bool cthByakheeHumanoidLegs()
    { return true; }

// summoned by clerics of Hastur through use of a gate spell
inline bool cthByakheeGateSummon()
    { return true; }

// able to teleport throughout the Prime Material Plane at will
inline bool cthByakheeTeleport()
    { return true; }

// they obey those who carry the Elder Sign or who appeal successfully to
// Hastur
inline bool cthByakheeObeyElderSign()
    { return true; }

// they are intelligent and telepathic
inline bool cthByakheeTelepathic()
    { return true; }

// ---- the Flame Creature walk ----

// the 2-20 damage per attack
inline int cthFlameDmgLo()
    { return 2; }

// the damage ceiling
inline int cthFlameDmgHi()
    { return 20; }

// the 16 hit dice
inline int cthFlameHD()
    { return 16; }

// the 1-4 appearing
inline int cthFlameAppearingLo()
    { return 1; }

// the appearing ceiling
inline int cthFlameAppearingHi()
    { return 4; }

// the 10 points of heat damage radiated
inline int cthFlameHeatDmg()
    { return 10; }

// the 20 yard heat radius
inline int cthFlameHeatRangeYards()
    { return 20; }

// the 2-20 heat ray damage
inline int cthFlameHeatRayLo()
    { return 2; }

// the heat ray ceiling
inline int cthFlameHeatRayHi()
    { return 20; }

// the VII level/xp value label
inline int cthFlameXpLevel()
    { return 7; }

// the 1,950 base xp
inline int cthFlameXpBase()
    { return 1950; }

// the 14 xp per hit point
inline int cthFlameXpPerHp()
    { return 14; }

// appear to be smaller versions of their master
inline bool cthFlameSmallerVersion()
    { return true; }

// one of their functions is to appear when the god is too busy or chooses not
// to come
inline bool cthFlameStandInForGod()
    { return true; }

// ---- the Deep Ones walk ----

// the 1-4 claw damage (+2)
inline int cthDeepOnesDmgLo()
    { return 1; }

// the damage ceiling
inline int cthDeepOnesDmgHi()
    { return 4; }

// the +2 on the claw damage
inline int cthDeepOnesWeaponPlus()
    { return 2; }

// the 4 hit dice
inline int cthDeepOnesHD()
    { return 4; }

// the 1-100 appearing
inline int cthDeepOnesAppearingLo()
    { return 1; }

// the appearing ceiling
inline int cthDeepOnesAppearingHi()
    { return 100; }

// the 90 percent in lair
inline int cthDeepOnesLairPct()
    { return 90; }

// the III level/xp value label
inline int cthDeepOnesXpLevel()
    { return 3; }

// the 60 base xp
inline int cthDeepOnesXpBase()
    { return 60; }

// the 4 xp per hit point
inline int cthDeepOnesXpPerHp()
    { return 4; }

// the great strength (18) of the prose
inline int cthDeepOnesStr()
    { return 18; }

// the age of 21 when the hybrid transformation begins
inline int cthDeepOnesTransformAge()
    { return 21; }

// humanoid amphibious men-fish, cold-blooded creatures of great strength
inline bool cthDeepOnesAmphibious()
    { return true; }

// they have infravision as well as normal sight
inline bool cthDeepOnesInfravision()
    { return true; }

// they interact with evil humans and interbreed with them
inline bool cthDeepOnesInterbreed()
    { return true; }

// the Deep Ones are soulless and apparently immortal
inline bool cthDeepOnesSoullessImmortal()
    { return true; }

// they promote evil in preparation of Cthulhu's return, funding the cult with
// sea treasures
inline bool cthDeepOnesPromoteEvil()
    { return true; }

// the printed treasure type Z
inline bool cthDeepOnesTreasureTypeZ()
    { return true; }

// ---- the Hastur walk ----

// the 20-200 damage per attack
inline int cthHasturDmgLo()
    { return 20; }

// the damage ceiling
inline int cthHasturDmgHi()
    { return 200; }

// the 200 projecting tentacles
inline int cthHasturTentacles()
    { return 200; }

// the 5 hit points regenerated per melee round
inline int cthHasturRegen()
    { return 5; }

// the 2-20 Byakhee summoned to battle
inline int cthHasturSummonLo()
    { return 2; }

// the summon ceiling
inline int cthHasturSummonHi()
    { return 20; }

// the 25 percent chance the spoken name is heard
inline int cthHasturNameHearPct()
    { return 25; }

// the 1-4 Byakhee sent to slay the speaker
inline int cthHasturByakheeLo()
    { return 1; }

// the Byakhee ceiling
inline int cthHasturByakheeHi()
    { return 4; }

// the 25 percent chance Hastur himself appears
inline int cthHasturAppearPct()
    { return 25; }

// the scaled elongated body, lizard head and maw, taloned lizard claws
inline bool cthHasturScaledBody()
    { return true; }

// at will it can teleport anywhere in the Prime Material Plane
inline bool cthHasturTeleports()
    { return true; }

// creatures able to fly naturally will never attack Hastur, even if
// controlled
inline bool cthHasturFlyersNeverAttack()
    { return true; }

// any being trying to attack the god must make a saving throw against fear
inline bool cthHasturFearSave()
    { return true; }

// Hastur is half-brother to Cthulhu
inline bool cthHasturHalfBrotherCthulhu()
    { return true; }

// like Cthulhu, Hastur has been imprisoned by the star-shaped Elder Sign
inline bool cthHasturElderSignImprisoned()
    { return true; }

// he lies in a crypt at the bottom of Lake Hali near the alien city of
// Carcosa
inline bool cthHasturCryptLakeHali()
    { return true; }

// he exists partly on the Prime Material Plane and partly on the Elemental
// Plane of Air
inline bool cthHasturPartialElementalAir()
    { return true; }

// never more than partially present and therefore not completely solid
inline bool cthHasturNeverFullySolid()
    { return true; }

// the printed FIGHTER cell: As 16+ HD monster
inline bool cthHasturFighterAs16HDMonster()
    { return true; }

// ---- the Great Race walk ----

// the 1-8 damage per attack
inline int cthGreatRaceDmgLo()
    { return 1; }

// the damage ceiling
inline int cthGreatRaceDmgHi()
    { return 8; }

// the 8 hit dice
inline int cthGreatRaceHD()
    { return 8; }

// the 1-10 appearing
inline int cthGreatRaceAppearingLo()
    { return 1; }

// the appearing ceiling
inline int cthGreatRaceAppearingHi()
    { return 10; }

// the 95 percent in lair
inline int cthGreatRaceLairPct()
    { return 95; }

// the VI level/xp value label
inline int cthGreatRaceXpLevel()
    { return 6; }

// the 650 base xp
inline int cthGreatRaceXpBase()
    { return 650; }

// the 10 xp per hit point
inline int cthGreatRaceXpPerHp()
    { return 10; }

// the 280 point psionic ability score
inline int cthGreatRacePsiScore()
    { return 280; }

// the ten foot wide cone
inline int cthGreatRaceConeWidthFeet()
    { return 10; }

// the four tentacles at the top
inline int cthGreatRaceTentacles()
    { return 4; }

// the ten foot long tentacles
inline int cthGreatRaceTentacleFeet()
    { return 10; }

// a highly advanced scientific civilization, with psionics rather than magic
inline bool cthGreatRaceScientificPsionics()
    { return true; }

// when the civilization was destroyed some were frozen in time and are
// occasionally discovered
inline bool cthGreatRaceFrozenInTime()
    { return true; }

// their cities still exist, buried in deserts or other out of the way places
inline bool cthGreatRaceDesertCities()
    { return true; }

// humans discovering and freeing them are sometimes rewarded with gifts of
// knowledge
inline bool cthGreatRaceGiftsOfKnowledge()
    { return true; }

// the printed Attack/Defense Modes: B, C, D, E/All
inline bool cthGreatRaceModesBCDEAll()
    { return true; }

// ---- the Ithaqua walk ----

// the 4-40 damage per attack
inline int cthIthaquaDmgLo()
    { return 4; }

// the damage ceiling
inline int cthIthaquaDmgHi()
    { return 40; }

// the tripled range and effects of his weather control
inline int cthIthaquaWeatherMultiplier()
    { return 3; }

// appears as a cloud of fog or snow, huge but human in shape
inline bool cthIthaquaFogShape()
    { return true; }

// the blazing red eyes
inline bool cthIthaquaBlazingRedEyes()
    { return true; }

// seen passing overhead, the illusion of two bright stars close together
inline bool cthIthaquaTwoStarsIllusion()
    { return true; }

// worshiped by the natives of the far North because of his weather control
inline bool cthIthaquaWeatherControl()
    { return true; }

// his worshipers propitiate him with human sacrifices, carried off no one
// knows where
inline bool cthIthaquaHumanSacrifice()
    { return true; }

// he pursues and captures anyone who sees or annoys him or meddles with his
// altars
inline bool cthIthaquaPursuesWitnesses()
    { return true; }

// Ithaqua serves Hastur in special missions of great importance
inline bool cthIthaquaServesHastur()
    { return true; }

// ---- the Mi-Go walk ----

// the 1-8 damage per attack
inline int cthMiGoDmgLo()
    { return 1; }

// the damage ceiling
inline int cthMiGoDmgHi()
    { return 8; }

// the 5 hit dice
inline int cthMiGoHD()
    { return 5; }

// the 2-12 appearing
inline int cthMiGoAppearingLo()
    { return 2; }

// the appearing ceiling
inline int cthMiGoAppearingHi()
    { return 12; }

// the 40 percent in lair
inline int cthMiGoLairPct()
    { return 40; }

// the IV level/xp value label
inline int cthMiGoXpLevel()
    { return 4; }

// the 240 base xp
inline int cthMiGoXpBase()
    { return 240; }

// the 5 xp per hit point
inline int cthMiGoXpPerHp()
    { return 5; }

// the 90 point psionic ability score
inline int cthMiGoPsiScore()
    { return 90; }

// the 3 inch wiry cilia
inline int cthMiGoCiliaInches()
    { return 3; }

// the 5 red-irised globed eyes
inline int cthMiGoEyes()
    { return 5; }

// the 5 mouthed tentacles at the top
inline int cthMiGoMouthTentacles()
    { return 5; }

// the 5 locomotion tentacles at the base
inline int cthMiGoLegTentacles()
    { return 5; }

// the printed name block: the Fungi from Yuggoth
inline bool cthMiGoFungiFromYuggoth()
    { return true; }

// red bat-winged creatures resembling lobsters, actually fungus creatures
inline bool cthMiGoLobsterLike()
    { return true; }

// immune to the effects of cold, dark and vacuum
inline bool cthMiGoImmuneColdDarkVacuum()
    { return true; }

// they can fly across interstellar space
inline bool cthMiGoInterstellarFlight()
    { return true; }

// they cannot speak but communicate by clicking their pincers
inline bool cthMiGoClickingPincers()
    { return true; }

// the printed Attack/Defense Modes: C, D/F, G, H
inline bool cthMiGoModesCDFGH()
    { return true; }

// ---- the Nyarlathotep walk ----

// the 3-30 damage per attack
inline int cthNyarlathotepDmgLo()
    { return 3; }

// the damage ceiling
inline int cthNyarlathotepDmgHi()
    { return 30; }

// the +4 save of good-aligned beings against his presence
inline int cthNyarlathotepGoodSave()
    { return 4; }

// the -4 save of evil-aligned beings
inline int cthNyarlathotepEvilSave()
    { return -4; }

// the 1-100 wild beasts or mindless humans called up
inline int cthNyarlathotepArmyLo()
    { return 1; }

// the army ceiling
inline int cthNyarlathotepArmyHi()
    { return 100; }

// the one hour notice of the army
inline int cthNyarlathotepArmyHours()
    { return 1; }

// the 3-30 hit points drained per hit
inline int cthNyarlathotepDrainLo()
    { return 3; }

// the drain ceiling
inline int cthNyarlathotepDrainHi()
    { return 30; }

// the drained points add to his total for one full turn
inline int cthNyarlathotepDrainTurns()
    { return 1; }

// the 5 percent chance a continual light drives him into the Astral Plane
inline int cthNyarlathotepLightRepelPct()
    { return 5; }

// the printed name block: the crawling chaos, the messenger of the gods
inline bool cthNyarlathotepCrawlingChaos()
    { return true; }

// his appearance foretells the return of the Old Ones from their imprisonment
inline bool cthNyarlathotepForetellsReturn()
    { return true; }

// he charms humans, humanoids and non-magical animals by his mere presence
inline bool cthNyarlathotepCharmPresence()
    { return true; }

// believed to have various guises, including a red bat-like form with three
// evil eyes
inline bool cthNyarlathotepRedBatGuise()
    { return true; }

// he can call up an army of wild beasts or mindless humans within an hour
// notice
inline bool cthNyarlathotepWildBeastArmy()
    { return true; }

// the continual light chance drives this being off into the Astral Plane
inline bool cthNyarlathotepLightRepel()
    { return true; }

// ---- the Primordial One walk ----

// the 1-6 damage per tentacle (x 3)
inline int cthPrimordialDmgLo()
    { return 1; }

// the damage ceiling
inline int cthPrimordialDmgHi()
    { return 6; }

// the 8 hit dice
inline int cthPrimordialHD()
    { return 8; }

// the 1-8 appearing
inline int cthPrimordialAppearingLo()
    { return 1; }

// the appearing ceiling
inline int cthPrimordialAppearingHi()
    { return 8; }

// the 95 percent in lair
inline int cthPrimordialLairPct()
    { return 95; }

// the VI level/xp value label
inline int cthPrimordialXpLevel()
    { return 6; }

// the 550 base xp
inline int cthPrimordialXpBase()
    { return 550; }

// the 10 xp per hit point
inline int cthPrimordialXpPerHp()
    { return 10; }

// the 206 point psionic ability score
inline int cthPrimordialPsiScore()
    { return 206; }

// the three walking tentacle strikes
inline int cthPrimordialAtkTentacles()
    { return 3; }

// the 5 eyes on the globe
inline int cthPrimordialEyes()
    { return 5; }

// the 5 mouthed tentacles at the top
inline int cthPrimordialMouthTentacles()
    { return 5; }

// the 5 locomotion tentacles at the base
inline int cthPrimordialLegTentacles()
    { return 5; }

// an alien race of high intelligence and advanced science
inline bool cthPrimordialAlienScience()
    { return true; }

// they hate all other types of intelligence and will destroy them if possible
inline bool cthPrimordialHateIntelligence()
    { return true; }

// barrel-shaped cylinders with membranous wings and many-colored cilia
inline bool cthPrimordialBarrelShape()
    { return true; }

// the membranous wings of the barrel body
inline bool cthPrimordialMembranousWings()
    { return true; }

// the printed Attack/Defense Modes: B, C, D/All
inline bool cthPrimordialModesBCDAll()
    { return true; }

// ---- the Shoggoth walk ----

// the 3-30 damage per attack
inline int cthShoggothDmgLo()
    { return 3; }

// the damage ceiling
inline int cthShoggothDmgHi()
    { return 30; }

// the 20 hit dice
inline int cthShoggothHD()
    { return 20; }

// the 1-4 appearing
inline int cthShoggothAppearingLo()
    { return 1; }

// the appearing ceiling
inline int cthShoggothAppearingHi()
    { return 4; }

// the 90 percent in lair
inline int cthShoggothLairPct()
    { return 90; }

// the IX level/xp value label
inline int cthShoggothXpLevel()
    { return 9; }

// the 6,500 base xp
inline int cthShoggothXpBase()
    { return 6500; }

// the 30 xp per hit point
inline int cthShoggothXpPerHp()
    { return 30; }

// originally created by the Primordial Ones as servants
inline bool cthShoggothCreatedServants()
    { return true; }

// they eventually rebelled and destroyed the civilization of their masters
inline bool cthShoggothRebelled()
    { return true; }

// huge intelligent amoebae, forming legs, eyes, mouths or huge weapons as
// needed
inline bool cthShoggothShapeAnything()
    { return true; }

// the few remaining lurk in distant areas, sometimes aiding servants of the
// Old Ones
inline bool cthShoggothAidOldOnes()
    { return true; }

// immune to weakness, paralysis and charm
inline bool cthShoggothImmuneWeakness()
    { return true; }

// ---- the Shub-Niggurath walk ----

// the 100 feet across gray matter pool
inline int cthShubPoolDiameterFeet()
    { return 100; }

// the 1,000 inch approach sense range
inline int cthShubSenseRangeInches()
    { return 1000; }

// the 1-100 small monsters created from the pool each round
inline int cthShubCreateLo()
    { return 1; }

// the creation ceiling
inline int cthShubCreateHi()
    { return 100; }

// one defending monster created per melee round
inline int cthShubDefendPerMelee()
    { return 1; }

// the d6 random monster table (Byakhee, Deep One, Great Race, Mi-Go,
// Primordial One, Shoggoth)
inline int cthShubSummonDie()
    { return 6; }

// the printed name block: black goat of the woods with a thousand young
inline bool cthShubBlackGoatOfTheWoods()
    { return true; }

// the constantly bubbling pool, putting forth mouths, limbs, pseudopods and
// whole creatures
inline bool cthShubBubblingPool()
    { return true; }

// some monsters fall back into the pool, which grows mouths and devours them
inline bool cthShubDevoursOwnSpawn()
    { return true; }

// intelligent and telepathically sensitive
inline bool cthShubTelepathic()
    { return true; }

// the pool tentacle pulls victims in; the escape chance equals the victim
// strength percentage
inline bool cthShubTentaclePullStrength()
    { return true; }

// though its body is trapped, it travels the Prime Material Plane in astral
// form
inline bool cthShubAstralTravels()
    { return true; }

// the printed FIGHTER cell: As 16+ HD monster
inline bool cthShubFighterAs16HDMonster()
    { return true; }

// ---- the Yog-Sothoth walk ----

// the 1-8 damage per attack (x 12)
inline int cthYogDmgLo()
    { return 1; }

// the damage ceiling
inline int cthYogDmgHi()
    { return 8; }

// one Spawn or subject race gated in per melee round
inline int cthYogGatePerMelee()
    { return 1; }

// the astral shape: a congeries of iridescent globes like giant soap bubbles
inline bool cthYogIridescentGlobes()
    { return true; }

// the material shape: a gigantic mass of feelers, legs and stalked organs
inline bool cthYogFeltersShape()
    { return true; }

// in this shape he mates with humans, producing the Spawn of Yog-Sothoth (the
// Dunwich Horror)
inline bool cthYogSpawnOfYogSothoth()
    { return true; }

// not subject to the laws of space and time, entering the universe at any
// point
inline bool cthYogOutsideSpaceTime()
    { return true; }

// he can appear at various parts of the universe simultaneously
inline bool cthYogSimultaneous()
    { return true; }

// highly intelligent and extremely chaotic and unpredictable
inline bool cthYogHighlyChaotic()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Cthulhu 2, Azathoth -2, Cthugha -6, Nyarlathotep 1,
// Shub-Niggurath 4, Yog-Sothoth -2)
inline int cthCbtAC(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return -2;
        case 2:
            return -6;
        case 3:
            return 9;
        case 4:
            return -2;
        case 5:
            return 3;
        case 6:
            return -2;
        case 7:
            return 5;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 6;
        case 12:
            return 2;
        case 13:
            return 4;
        case 14:
            return -2;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all fifteen read
// single this round)
inline int cthCbtACAlt(int b)
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
        default:
            return 0;
        }
    }

// The hit point cells (400 the four greater gods and Shub-Niggurath, Ithaqua
// 250, Nyarlathotep 200; 0 = the hit-dice monster rows)
inline int cthCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 400;
        case 2:
            return 400;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 400;
        case 7:
            return 0;
        case 8:
            return 250;
        case 9:
            return 0;
        case 10:
            return 200;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 400;
        case 14:
            return 400;
        default:
            return 0;
        }
    }

// The primary move cells (0 = the printed None of Azathoth and
// Shub-Niggurath; Shoggoth the printed 9)
inline int cthCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 0;
        case 2:
            return 36;
        case 3:
            return 6;
        case 4:
            return 24;
        case 5:
            return 12;
        case 6:
            return 36;
        case 7:
            return 15;
        case 8:
            return 24;
        case 9:
            return 15;
        case 10:
            return 15;
        case 11:
            return 18;
        case 12:
            return 9;
        case 13:
            return 0;
        case 14:
            return 18;
        default:
            return 0;
        }
    }

// The secondary move cells (the printed slash ceilings; Primordial One the
// printed 18/12 - flagged; Mi-Go 15/30)
inline int cthCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 24;
        case 4:
            return 0;
        case 5:
            return 24;
        case 6:
            return 36;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 30;
        case 10:
            return 0;
        case 11:
            return 12;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (Cthulhu 30, Azathoth 20, Yog-Sothoth 12, Primordial
// One 3)
inline int cthCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 20;
        case 2:
            return 2;
        case 3:
            return 2;
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
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 12;
        default:
            return 0;
        }
    }

// The attack alternative cells (the Deep Ones printed 2 or 1)
inline int cthCbtAtD(int b)
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
        default:
            return 0;
        }
    }

// The magic resistance cells (0 = the printed Standard of the Deep Ones,
// Great Race, Mi-Go and Primordial One)
inline int cthCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 95;
        case 2:
            return 50;
        case 3:
            return 20;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 50;
        case 7:
            return 0;
        case 8:
            return 30;
        case 9:
            return 0;
        case 10:
            return 25;
        case 11:
            return 0;
        case 12:
            return 30;
        case 13:
            return 95;
        case 14:
            return 50;
        default:
            return 0;
        }
    }

// The size cells in inches (Cthulhu 100 feet, Hastur 600 feet, Cthugha the 40
// yard radius, Azathoth the printed inconceivable and Nyarlathotep the
// printed Variable - both sentinels, flagged; Mi-Go the IA 8 feet against the
// Termux 8 inches - flagged)
inline int cthCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 1200;
        case 1:
            return 0;
        case 2:
            return 1440;
        case 3:
            return 240;
        case 4:
            return 360;
        case 5:
            return 72;
        case 6:
            return 7200;
        case 7:
            return 120;
        case 8:
            return 240;
        case 9:
            return 96;
        case 10:
            return 0;
        case 11:
            return 108;
        case 12:
            return 180;
        case 13:
            return 1200;
        case 14:
            return 600;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (99 = the printed See below: Cthugha the 30th level
// fire caster doctrine; Ithaqua 13th, Nyarlathotep 12th in each)
inline int cthClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 99;
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
            return 13;
        case 9:
            return 0;
        case 10:
            return 12;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (Nyarlathotep 12th in each; all others Nil)
inline int cthClsDruid(int b)
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
            return 12;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The fighter level floor cells (Ithaqua 15th and Nyarlathotep 15th; 0 = the
// as-16-plus-HD-monster gods, pinned as bools, and the monster rows)
inline int cthClsFighterLo(int b)
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
            return 15;
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
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The fighter level ceiling cells (single printed levels read floor =
// ceiling)
inline int cthClsFighterHi(int b)
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
            return 15;
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
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The ranger level cells (all Nil this round)
inline int cthClsRanger(int b)
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
        default:
            return 0;
        }
    }

// The magic-user level cells (99 = the printed See below: Cthugha; Cthulhu
// 20th, Hastur 23rd in each, Nyarlathotep 13th in each, Yog-Sothoth 15th)
inline int cthClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 99;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 23;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 13;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 15;
        default:
            return 0;
        }
    }

// The illusionist level cells (Ithaqua 12th; Hastur and Nyarlathotep the
// in-each 23s and 13s)
inline int cthClsIllus(int b)
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
            return 23;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 0;
        case 10:
            return 13;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (all Nil this round)
inline int cthClsThief(int b)
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
        default:
            return 0;
        }
    }

// The assassin level cells (Nyarlathotep the 15th level assassin)
inline int cthClsAssassin(int b)
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
            return 15;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (all Nil this round)
inline int cthClsMonk(int b)
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
        default:
            return 0;
        }
    }

// The bard level cells (all Nil this round)
inline int cthClsBard(int b)
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
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the S:25s of five gods, Ithaqua 21, Shub-Niggurath 24;
// the monster rows 0 - the Deep Ones strength 18 rides a const)
inline int cthAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 21;
        case 9:
            return 0;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 24;
        case 14:
            return 25;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = no printed bracket)
inline int cthAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 0;
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
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells (the +14s of the S:25s, the
// +9 of Ithaqua)
inline int cthAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 14;
        case 2:
            return 14;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 14;
        case 7:
            return 0;
        case 8:
            return 9;
        case 9:
            return 0;
        case 10:
            return 7;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 12;
        case 14:
            return 14;
        default:
            return 0;
        }
    }

// The intelligence cells (Azathoth the printed dash, 0; Yog-Sothoth 25,
// Cthulhu 20)
inline int cthAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 22;
        case 7:
            return 0;
        case 8:
            return 16;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 25;
        case 14:
            return 25;
        default:
            return 0;
        }
    }

// The wisdom cells (Azathoth the printed dash, 0; the rest as printed)
inline int cthAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 0;
        case 2:
            return 18;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 23;
        case 7:
            return 0;
        case 8:
            return 13;
        case 9:
            return 0;
        case 10:
            return 12;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 20;
        case 14:
            return 23;
        default:
            return 0;
        }
    }

// The dexterity cells (Cthugha 25 the Termux fold line, flagged)
inline int cthAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 21;
        case 7:
            return 0;
        case 8:
            return 18;
        case 9:
            return 0;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 19;
        case 14:
            return 20;
        default:
            return 0;
        }
    }

// The constitution cells (the 25s)
inline int cthAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 23;
        case 7:
            return 0;
        case 8:
            return 20;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 25;
        case 14:
            return 25;
        default:
            return 0;
        }
    }

// The charisma cells (Cthulhu the flagged 7 - both voices drop the minus,
// eyeball; Cthugha the flagged 1; Azathoth and Yog-Sothoth -7, Hastur and
// Shub-Niggurath -4, Ithaqua -1, Nyarlathotep 19)
inline int cthAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return -7;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return -4;
        case 7:
            return 0;
        case 8:
            return -1;
        case 9:
            return 0;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return -4;
        case 14:
            return -7;
        default:
            return 0;
        }
    }

// The psionic score cells (the monster point scores: Great Race 280, Mi-Go
// 90, Primordial One 206; 0 = the deities read the R849 class table and the
// Nil monsters)
inline int cthAbiPsi(int b)
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
            return 280;
        case 8:
            return 0;
        case 9:
            return 90;
        case 10:
            return 0;
        case 11:
            return 206;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Cthulhu through Yog-Sothoth)
inline int cthRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print page cells (43-47, the folio offset PRINT = PDF - 1)
inline int cthRosPage(int b)
    {
        switch (b) {
        case 0:
            return 43;
        case 1:
            return 44;
        case 2:
            return 44;
        case 3:
            return 44;
        case 4:
            return 44;
        case 5:
            return 45;
        case 6:
            return 45;
        case 7:
            return 45;
        case 8:
            return 45;
        case 9:
            return 46;
        case 10:
            return 46;
        case 11:
            return 46;
        case 12:
            return 46;
        case 13:
            return 47;
        case 14:
            return 47;
        default:
            return 0;
        }
    }

// The alignment cells (3 LN the Great Race, 5 CN Azathoth, 6 LE the
// Primordial One, 8 CE the other twelve - the R852 code scheme)
inline int cthRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 5;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 3;
        case 8:
            return 8;
        case 9:
            return 8;
        case 10:
            return 8;
        case 11:
            return 6;
        case 12:
            return 8;
        case 13:
            return 8;
        case 14:
            return 8;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser Nyarlathotep and Shub-Niggurath, 1 greater, 2
// demigod Ithaqua, 3 monster - the seven monster races)
inline int cthRosRank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 0;
        case 14:
            return 1;
        default:
            return 0;
        }
    }

// The psionic class cells (0 Nil the five Nil monsters and the score-readers,
// 1 the class I gods, 4 Byakhee and Ithaqua, 5 the Flame Creatures and
// Nyarlathotep, 6 Azathoth - the R849 class table)
inline int cthRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 0;
        case 10:
            return 5;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        default:
            return 0;
        }
    }

// The plane cells (1 Prime Material, 2 Astral, 3 Elemental Fire, 4 Elemental
// Air; 0 = the monster rows)
inline int cthRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
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
            return 4;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 2;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed DAMAGE/ATTACK cell is numeric
// damage; 0 = Shub-Niggurath the printed See below)
inline int cthRosDmgFixed(int b)
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
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells: Hastur the 23rd,
// Nyarlathotep the 12th cleric-druid and 13th magic-user-illusionist)
inline int cthRosInEach(int b)
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return 0;
        }
    }

// The summon-list flags (the six Shub-Niggurath d6 table monsters: Byakhee,
// Deep One, Great Race, Mi-Go, Primordial One, Shoggoth)
inline int cthRosSummonList(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 0;
        case 7:
            return 1;
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
        default:
            return 0;
        }
    }

}   // namespace rules
