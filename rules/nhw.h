// =========================================================================================
// Adnd1 - rules/nhw.h
// the Nehwon mythos - the D&DG walk round fifteen, print pp. 96-104:
// twenty-nine stat-block rows - the four heroes Fafhrd and the Gray Mouser,
// Movarl and Pulgh; the two wizards Ningauble of the Seven Eyes and Sheelba
// of the Eyeless Face; the two greater gods Death and Kos; the six lesser
// gods (the Gods of Trouble, Hate, the Nehwon Earth God, the Rat God, the Red
// God, Tyaa); the five demigods (Aarth, the Gods of Lankhmar, Issek of the
// Jug, the Spider God, Votishal) and ten monsters (the Astral Wolf, the
// Behemoth, the Bird of Tyaa, the Cold Woman, the Devourer, the Nehwon Ghoul,
// the Leviathan, the Snow Serpent, the Salt Spider, the Water Cobra) - plus
// the Lankhmar doctrine and the six encounter tables of print p. 104.
// census 785 -> 786.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 097-105; the second printing) with
// the tsv word geometry; the collation voice: the 1eonline Legends & Lore
// transcription (the R853 parity voice - the interior identical to the late
// D&DG prints) plus the tsv digit-glyph calibrations of the R859-R861 era.
// The adjudications: the Mouser quarter-foot 63 decode, the Aarth 3/2 attack
// split, the Death Infinite-move and the tsv minus 5 armor class, the Gods of
// Trouble w22 minus 2, the Tyaa w2 dash, the Votishal 344 token, the
// marsh-table fold restore, and the mountains overlap pinned as printed.
//
namespace rules {

// ---- the Nehwon doctrine ----

// the Nehwon mythos round: the D&DG walk round fifteen
inline int nhwRound()
    { return 863; }

// the section opens on print p. 96
inline int nhwPrintStart()
    { return 96; }

// the section closes on print p. 104 (the encounter tables)
inline int nhwPrintEnd()
    { return 104; }

// the 13 perfect specimens of each animal species
inline int nhwBeastCount()
    { return 13; }

// the Godsland: an astral area where most gods reside
inline bool nhwGodslandAstral()
    { return true; }

// the jeweled skulls and hands of dead guild masters
inline bool nhwGemsAnimateDead()
    { return true; }

// gems are containers of souls and life
inline bool nhwGemsSoulContainers()
    { return true; }

// capturing one of the 13 controls the species
inline bool nhwBeastControlSpecies()
    { return true; }

// the Thieves Guild master thief level
inline int nhwGuildMasterLevel()
    { return 12; }

// the guild fifth-level members, low end
inline int nhwGuildMembersLow()
    { return 3; }

// the guild fifth-level members, high end
inline int nhwGuildMembersHigh()
    { return 24; }

// the guild member ability level
inline int nhwGuildMemberLevel()
    { return 5; }

// the Brotherhood hires fighters from 1st level
inline int nhwSlayerLevelLow()
    { return 1; }

// the Brotherhood hires fighters to 10th level
inline int nhwSlayerLevelHigh()
    { return 10; }

// the snow witch coven size for weather control
inline int nhwWitchCovenSize()
    { return 5; }

// the snow witch preparation hours
inline int nhwWitchHours()
    { return 24; }

// the chilling weather control range in miles
inline int nhwWitchRangeMiles()
    { return 5; }

// fire sorcerers use fire spells at twice level
inline int nhwFireSorcMult()
    { return 2; }

// fire sorcerers drop to half level in all else
inline int nhwFireSorcDiv()
    { return 2; }

// ---- Fafhrd ----

// the obscure-language understanding chance
inline int nhwFafhrdLangPct()
    { return 80; }

// the climb/hide bonus over the thiefly base
inline int nhwFafhrdClimbBonus()
    { return 20; }

// the bastard sword Graywand
inline bool nhwFafhrdNamesSword()
    { return true; }

// the dirk Heartseeker
inline bool nhwFafhrdNamesDirk()
    { return true; }

// Fafhrd sometimes fights with a throwing hand axe
inline bool nhwFafhrdHandAxe()
    { return true; }

// Fafhrd is adept with a long bow
inline bool nhwFafhrdLongBow()
    { return true; }

// ---- the Gray Mouser ----

// the chance the third strike is either weapon
inline int nhwMouserThirdStrikePct()
    { return 50; }

// the rapier Scalpel
inline bool nhwMouserScalpel()
    { return true; }

// the throwing dagger Cats Claw
inline bool nhwMouserCatsClaw()
    { return true; }

// armed with both, the Mouser strikes three times
inline bool nhwMouserArmedThree()
    { return true; }

// ---- Aarth ----

// Aarth instantly knows any device used against him
inline bool nhwAarthKnowsDevice()
    { return true; }

// Aarth negates any device as a rod of cancellation
inline bool nhwAarthNegatesDevice()
    { return true; }

// Aarth fights invisibly in personal battle
inline bool nhwAarthFightsInvisible()
    { return true; }

// ---- the Astral Wolf ----

// the astral wolf hit dice
inline int nhwAstralWolfHD()
    { return 3; }

// the wolf pack size that forces astral sleep
inline int nhwWolfPackMin()
    { return 5; }

// the wolves force sleeping humans into the astral
inline bool nhwAstralWolfForceSleep()
    { return true; }

// the astral wolf xp level (III)
inline int nhwXpAstralWolfLevel()
    { return 3; }

// the astral wolf xp base
inline int nhwXpAstralWolfBase()
    { return 90; }

// the astral wolf xp per hit point
inline int nhwXpAstralWolfPerHp()
    { return 3; }

// ---- the Behemoth ----

// the behemoth hit dice
inline int nhwBehemothHD()
    { return 15; }

// the behemoth always attacks the largest thing
inline bool nhwBehemothAttacksLargest()
    { return true; }

// the white furred snow cousin of the north
inline bool nhwBehemothSnowCousin()
    { return true; }

// the jet black long-legged plains species
inline bool nhwBehemothBlackSpecies()
    { return true; }

// the behemoth xp level (VIII)
inline int nhwXpBehemothLevel()
    { return 8; }

// the behemoth xp base
inline int nhwXpBehemothBase()
    { return 4000; }

// the behemoth xp per hit point
inline int nhwXpBehemothPerHp()
    { return 20; }

// ---- the Bird of Tyaa ----

// the bird of Tyaa hit point range low
inline int nhwBirdHpLow()
    { return 1; }

// the bird of Tyaa hit point range high
inline int nhwBirdHpHigh()
    { return 4; }

// the poisoned-claw chance
inline int nhwBirdClawPoisonPct()
    { return 20; }

// the bird of Tyaa uses a diving attack
inline bool nhwBirdDivingAttack()
    { return true; }

// the bird of Tyaa xp level (II)
inline int nhwXpBirdLevel()
    { return 2; }

// the bird of Tyaa xp base
inline int nhwXpBirdBase()
    { return 30; }

// the bird of Tyaa xp per hit point
inline int nhwXpBirdPerHp()
    { return 1; }

// ---- Death ----

// Death attacks 10 times, one per segment
inline int nhwDeathSegments()
    { return 10; }

// the Death sword slays anything it touches
inline bool nhwDeathSwordSlays()
    { return true; }

// Death knows a being entire past at a glance
inline bool nhwDeathKnowsHistory()
    { return true; }

// even Death is aware that he will die
inline bool nhwDeathMortal()
    { return true; }

// ---- the Cold Woman ----

// the cold woman ray range in inches
inline int nhwColdRayRangeIn()
    { return 6; }

// the cold ray damage low
inline int nhwColdRayLow()
    { return 7; }

// the cold ray damage high
inline int nhwColdRayHigh()
    { return 70; }

// the cold woman bites as a 16+ HD monster
inline int nhwColdWomanBiteHd()
    { return 16; }

// the cold woman bite paralyzes on a failed save
inline bool nhwColdWomanParalyzes()
    { return true; }

// severed parts immediately rejoin the cold woman
inline bool nhwColdWomanRejoins()
    { return true; }

// lightning has the same no-effect as chopping
inline bool nhwColdWomanLightningSame()
    { return true; }

// cold does not bother the cold woman at all
inline bool nhwColdWomanColdImmune()
    { return true; }

// the cold woman implants an egg in the paralyzed
inline bool nhwColdWomanEggImplant()
    { return true; }

// chainmail corrodes in 1 round
inline int nhwCorrodeChainRounds()
    { return 1; }

// plate mail corrodes in 2 rounds
inline int nhwCorrodePlateRounds()
    { return 2; }

// each armor plus adds a corrode round
inline int nhwCorrodePlusRounds()
    { return 1; }

// the cold woman xp level (X)
inline int nhwXpColdWomanLevel()
    { return 10; }

// the cold woman flat xp (no per-hit)
inline int nhwXpColdWomanFlat()
    { return 28500; }

// ---- the Devourer ----

// the devourers come from another PMP
inline bool nhwDevourerOtherPlane()
    { return true; }

// the devourers sell junk magicked valuable
inline bool nhwDevourerSellsJunk()
    { return true; }

// ---- the Nehwon Ghoul ----

// the Nehwon ghoul hit dice
inline int nhwGhoulHD()
    { return 3; }

// the ghoul invisibility-in-dark chance
inline int nhwGhoulInvisPct()
    { return 80; }

// the Nehwon ghouls are not AD&D undead
inline bool nhwGhoulNotUndead()
    { return true; }

// some ghouls ride ghoul horses, bones transparent
inline bool nhwGhoulRideHorses()
    { return true; }

// the Nehwon ghoul xp level (II)
inline int nhwXpGhoulLevel()
    { return 2; }

// the Nehwon ghoul xp base
inline int nhwXpGhoulBase()
    { return 50; }

// the Nehwon ghoul xp per hit point
inline int nhwXpGhoulPerHp()
    { return 3; }

// ---- the Gods of Lankhmar ----

// three gods of Lankhmar
inline int nhwGodsLankhmarCount()
    { return 3; }

// the 13 crypts under the Lankhmar temple
inline int nhwCryptCount()
    { return 13; }

// the Lankhmar gods cast spells twice as fast
inline bool nhwGodsLankhmarSpellsTwice()
    { return true; }

// each carries a double-strength staff of withering
inline bool nhwGodsLankhmarStaffWithering()
    { return true; }

// they appear only when the city is threatened
inline bool nhwGodsLankhmarCityThreat()
    { return true; }

// the Lankhmar temple has no clerics
inline bool nhwGodsLankhmarNoClerics()
    { return true; }

// ---- the Gods of Trouble ----

// three gods of trouble
inline int nhwGodsTroubleCount()
    { return 3; }

// the no-magic radius in feet
inline int nhwTroubleNoMagicFeet()
    { return 30; }

// the trouble gaze fails any attempt, no saving throw
inline bool nhwTroubleGazeFail()
    { return true; }

// under attack they teleport to the astral plane
inline bool nhwTroubleTeleportAstral()
    { return true; }

// the high priest has the gaze, save vs spells
inline bool nhwTroubleHighPriestGaze()
    { return true; }

// ---- Hate ----

// Hate controls up to 6 beings or weapons
inline int nhwHateControlMax()
    { return 6; }

// the weapons fight as 6th level fighters
inline int nhwHateWeaponFighterLevel()
    { return 6; }

// the high priest level to generate Hate
inline int nhwHatePriestLevel()
    { return 10; }

// the worshiper count to generate Hate
inline int nhwHateWorshipers()
    { return 100; }

// the fog travels 5 miles
inline int nhwHateTravelMiles()
    { return 5; }

// the silver-red cord armor class
inline int nhwHateCordAC()
    { return -8; }

// the fog controls up to 6 beings as mass charm
inline bool nhwHateMassCharm()
    { return true; }

// the Hate manifestation is generated at night
inline bool nhwHateNightOnly()
    { return true; }

// cutting the pulsing cord dispels the fog
inline bool nhwHateCordCutDispels()
    { return true; }

// the Hate fog has only one function: to do harm
inline bool nhwHateOnlyHarm()
    { return true; }

// ---- Issek of the Jug ----

// the Issek jug pours out any liquid
inline bool nhwIssekJugAnyLiquid()
    { return true; }

// Issek manifests in humans tortured on the rack
inline bool nhwIssekManifestTortured()
    { return true; }

// the Issek sect is a poor one, preaching perseverance
inline bool nhwIssekPoorSect()
    { return true; }

// ---- Kos ----

// the Kos +6 intelligent broadsword
inline int nhwKosBroadswordPlus()
    { return 6; }

// the broadsword damage low
inline int nhwKosBroadLow()
    { return 8; }

// the broadsword damage high
inline int nhwKosBroadHigh()
    { return 80; }

// the code-of-honor hit point threshold
inline int nhwKosHonorHp()
    { return 100; }

// the Kos +3 hand axe
inline int nhwKosAxePlus()
    { return 3; }

// the axe damage low
inline int nhwKosAxeLow()
    { return 3; }

// the axe damage high
inline int nhwKosAxeHigh()
    { return 30; }

// the sword damages any other wielder
inline int nhwKosWeaponDamage()
    { return 50; }

// the berserker summon low
inline int nhwKosBerserkLow()
    { return 9; }

// the berserker summon high
inline int nhwKosBerserkHigh()
    { return 90; }

// the Kos broadsword is intelligent
inline bool nhwKosSwordIntelligent()
    { return true; }

// the code of honor spares beings under 100 hp
inline bool nhwKosCodeOfHonor()
    { return true; }

// the +6 weapon allows no other wielder
inline bool nhwKosSwordRejectsOthers()
    { return true; }

// ---- the Leviathan ----

// the leviathan hit dice
inline int nhwLeviathanHD()
    { return 40; }

// the leviathan tentacle count
inline int nhwLeviathanTentacles()
    { return 8; }

// the all-tentacle hull damage per melee
inline int nhwLeviathanHullDmg()
    { return 30; }

// below half its hp the leviathan retreats
inline bool nhwLeviathanRetreatsHalf()
    { return true; }

// all 8 tentacles on a ship: the hull damage
inline bool nhwLeviathanHullGrapple()
    { return true; }

// the leviathan xp level (X)
inline int nhwXpLeviathanLevel()
    { return 10; }

// the leviathan xp base
inline int nhwXpLeviathanBase()
    { return 15800; }

// the leviathan xp per hit point
inline int nhwXpLeviathanPerHp()
    { return 35; }

// ---- Movarl ----

// Movarl senses evil within 20 feet
inline int nhwMovarlEvilSenseFeet()
    { return 20; }

// the Movarl +1 two-handed sword damage low
inline int nhwMovarlDmgLow()
    { return 2; }

// the Movarl +1 two-handed sword damage high
inline int nhwMovarlDmgHigh()
    { return 20; }

// Movarl is immune to fear spells
inline bool nhwMovarlImmuneFear()
    { return true; }

// Movarl seeks battle only with the evil
inline bool nhwMovarlAvoidsNonEvil()
    { return true; }

// ---- Ningauble of the Seven Eyes ----

// the seven moving lights/eyes
inline int nhwNingaubleEyeCount()
    { return 7; }

// the seven eyes see through all illusions
inline bool nhwNingaubleSeesIllusions()
    { return true; }

// the caves link other planes, times, multiverses
inline bool nhwNingaubleCavesLinked()
    { return true; }

// Ningauble, the gossiper of the gods
inline bool nhwNingaubleGossiper()
    { return true; }

// probably not originally of Nehwon
inline bool nhwNingaubleNotOfNehwon()
    { return true; }

// ---- the Nehwon Earth God ----

// no forged weapon can hurt the molten earth god
inline bool nhwEarthGodNoForgedWeapon()
    { return true; }

// the earth god mass-charms through consecrated gems
inline bool nhwEarthGodGemCharm()
    { return true; }

// the tropical priests of Klesh serve the earth god
inline bool nhwEarthGodKlesh()
    { return true; }

// the earth god wishes Nehwon molten again
inline bool nhwEarthGodMoltenGoal()
    { return true; }

// ---- Pulgh ----

// the Pulgh +3 spear
inline int nhwPulghSpearPlus()
    { return 3; }

// Pulgh was an evil cleric before the fighter trade
inline bool nhwPulghExCleric()
    { return true; }

// Pulgh avoids notice whenever possible
inline bool nhwPulghShadowy()
    { return true; }

// ---- the Rat God ----

// the rat god summons 20 wererats a day
inline int nhwRatGodWererats()
    { return 20; }

// all felines must run in fear from the rat god
inline bool nhwRatGodFelinesFlee()
    { return true; }

// the rat god can shrink to normal rat size
inline bool nhwRatGodShrinks()
    { return true; }

// ---- Sheelba of the Eyeless Face ----

// the Sheelba hut moves 24 inches
inline int nhwSheelbaHutMoveIn()
    { return 24; }

// Sheelba, a being related to the lower planes
inline bool nhwSheelbaNotOfNehwon()
    { return true; }

// the Sheelba dislike for and rivalry with Ningauble
inline bool nhwSheelbaRivalryNingauble()
    { return true; }

// demons scream in horror and leave instantly
inline bool nhwSheelbaDemonsFlee()
    { return true; }

// ---- the Red God ----

// the red god +4 ring of protection
inline int nhwRedGodRingPlus()
    { return 4; }

// the red god +3 sabre
inline int nhwRedGodSabrePlus()
    { return 3; }

// the sabre damage low
inline int nhwRedGodSabreLow()
    { return 3; }

// the sabre damage high
inline int nhwRedGodSabreHigh()
    { return 30; }

// the red god +4 dirk
inline int nhwRedGodDirkPlus()
    { return 4; }

// the dirk damage low
inline int nhwRedGodDirkLow()
    { return 1; }

// the dirk damage high
inline int nhwRedGodDirkHigh()
    { return 10; }

// the 8th level magic-user aid sent east
inline int nhwRedGodAidLevel()
    { return 8; }

// the sabre casts an anti-magic shell around him
inline bool nhwRedGodAntiMagicShell()
    { return true; }

// the red god aids important worshipers abroad
inline bool nhwRedGodProtectsWorshipers()
    { return true; }

// ---- the Snow Serpent ----

// the snow serpent hit dice
inline int nhwSnowSerpentHD()
    { return 10; }

// the snow serpent constriction damage low
inline int nhwConstrictLow()
    { return 3; }

// the snow serpent constriction damage high
inline int nhwConstrictHigh()
    { return 30; }

// the snow serpent xp level (VII)
inline int nhwXpSnowSerpentLevel()
    { return 7; }

// the snow serpent xp base
inline int nhwXpSnowSerpentBase()
    { return 2050; }

// the snow serpent xp per hit point
inline int nhwXpSnowSerpentPerHp()
    { return 14; }

// ---- the Spider God ----

// the spider god summons 30 phase spiders
inline int nhwSpiderGodPhaseSpiders()
    { return 30; }

// a pet spider per ten sacrifices
inline int nhwSpiderGodSacrifices()
    { return 10; }

// all arachnids obey the spider god
inline bool nhwSpiderGodArachnidsObey()
    { return true; }

// the spider powers transfer to the high priest
inline bool nhwSpiderGodGrantsPowers()
    { return true; }

// ---- the Salt Spider ----

// the salt spider hit dice
inline int nhwSaltSpiderHD()
    { return 3; }

// the salt spider suction pads grip any surface
inline bool nhwSaltSpiderSuctionPads()
    { return true; }

// the salt spider xp level (III)
inline int nhwXpSaltSpiderLevel()
    { return 3; }

// the salt spider xp base
inline int nhwXpSaltSpiderBase()
    { return 105; }

// the salt spider xp per hit point
inline int nhwXpSaltSpiderPerHp()
    { return 3; }

// ---- Tyaa ----

// Tyaa summons any of 20 predatory birds
inline int nhwTyaaPredBirds()
    { return 20; }

// Tyaa summons 100 birds of Tyaa a day
inline int nhwTyaaBirdsPerDay()
    { return 100; }

// the Tyaa +2 poisoned longsword
inline int nhwTyaaSwordPlus()
    { return 2; }

// Tyaa manifests in her high priestess, rarely
inline bool nhwTyaaManifestPriestess()
    { return true; }

// Tyaa fights with poisoned weapons
inline bool nhwTyaaPoisonedWeapons()
    { return true; }

// the Falconers of Tyaa, the male arm of the cult
inline bool nhwTyaaFalconers()
    { return true; }

// ---- Votishal ----

// no cleric rises above 10th without temple loot
inline int nhwVotishalClericCap()
    { return 10; }

// the high cleric patriarch level
inline int nhwVotishalPatriarch()
    { return 15; }

// the high cleric master-thief level
inline int nhwVotishalMasterThief()
    { return 12; }

// manifest, Votishal tries to kill all evil met
inline bool nhwVotishalKillsEvil()
    { return true; }

// his clerics rise alternately cleric and thief
inline bool nhwVotishalAlternatingClerics()
    { return true; }

// the sect opposes and raids the Thieves Guild
inline bool nhwVotishalOpposesGuild()
    { return true; }

// ---- the Water Cobra ----

// the water cobra hit dice
inline int nhwWaterCobraHD()
    { return 3; }

// the water cobra +3 hit dice bonus
inline int nhwWaterCobraHDBonus()
    { return 3; }

// the water cobra is invisible in the water
inline bool nhwWaterCobraWaterInvisible()
    { return true; }

// the water cobra xp level (III)
inline int nhwXpWaterCobraLevel()
    { return 3; }

// the water cobra xp base
inline int nhwXpWaterCobraBase()
    { return 150; }

// the water cobra xp per hit point
inline int nhwXpWaterCobraPerHp()
    { return 4; }

// ---- the combat grid ----

// The armor class cells (Death minus 5 the best, Kos minus 4, Issek minus 3;
// Hate prints See below and Tyaa a bare dash - both pinned 0; the ghoul 10
// the worst)
inline int nhwCbtAC(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 7;
        case 6:
            return -5;
        case 7:
            return -2;
        case 8:
            return 7;
        case 9:
            return 10;
        case 10:
            return 3;
        case 11:
            return -2;
        case 12:
            return 0;
        case 13:
            return -3;
        case 14:
            return -4;
        case 15:
            return -1;
        case 16:
            return 2;
        case 17:
            return -2;
        case 18:
            return -2;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return -2;
        case 23:
            return 6;
        case 24:
            return 2;
        case 25:
            return 6;
        case 26:
            return 0;
        case 27:
            return -2;
        case 28:
            return 8;
        default:
            return 0;
        }
    }

// The alternative armor class cells (none printed - all 0)
inline int nhwCbtACAlt(int b)
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
        default:
            return 0;
        }
    }

// The hit point cells (Kos 377, the Gods of Trouble 366, Death 350, Votishal
// 344 - the L&L prints 244, the divergence noted; Hate prints 0; the seven
// hit-dice rows pinned 0)
inline int nhwCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 120;
        case 1:
            return 96;
        case 2:
            return 244;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 350;
        case 7:
            return 180;
        case 8:
            return 50;
        case 9:
            return 0;
        case 10:
            return 200;
        case 11:
            return 366;
        case 12:
            return 0;
        case 13:
            return 210;
        case 14:
            return 377;
        case 15:
            return 0;
        case 16:
            return 86;
        case 17:
            return 150;
        case 18:
            return 300;
        case 19:
            return 72;
        case 20:
            return 222;
        case 21:
            return 150;
        case 22:
            return 311;
        case 23:
            return 0;
        case 24:
            return 249;
        case 25:
            return 0;
        case 26:
            return 311;
        case 27:
            return 344;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The primary move cells (Death prints Infinite - the minus 1 sentinel; the
// bird 1 with the 18 flight; Issek the odd 12/12 dual print)
inline int nhwCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 12;
        case 5:
            return 1;
        case 6:
            return -1;
        case 7:
            return 9;
        case 8:
            return 15;
        case 9:
            return 12;
        case 10:
            return 9;
        case 11:
            return 12;
        case 12:
            return 6;
        case 13:
            return 12;
        case 14:
            return 18;
        case 15:
            return 9;
        case 16:
            return 12;
        case 17:
            return 9;
        case 18:
            return 12;
        case 19:
            return 12;
        case 20:
            return 18;
        case 21:
            return 9;
        case 22:
            return 18;
        case 23:
            return 9;
        case 24:
            return 18;
        case 25:
            return 15;
        case 26:
            return 9;
        case 27:
            return 18;
        case 28:
            return 12;
        default:
            return 0;
        }
    }

// The secondary move cells (the Trouble 24, the Leviathan 15, the Behemoth
// and salt spider 18, Tyaa the 36 flight)
inline int nhwCbtMoveAlt(int b)
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
            return 18;
        case 5:
            return 18;
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
            return 12;
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
            return 18;
        case 26:
            return 36;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (Death 10 one per segment; Hate 6; the Leviathan 8;
// the red god 4; Ningauble prints Nil - 0)
inline int nhwCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 10;
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
            return 6;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 8;
        case 16:
            return 3;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 4;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 3;
        case 28:
            return 1;
        default:
            return 0;
        }
    }

// The alternate-attack cells (the 3/2 pairs: Mouser, Aarth, Issek, Movarl,
// Votishal - the Mouser or-3 rides a bool)
inline int nhwCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 2;
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
            return 2;
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
        default:
            return 0;
        }
    }

// The magic resistance cells (Death 95, the earth god 50, Kos 35, Votishal
// 35, Tyaa 32, Aarth and the cold woman 25, Hate and the red god 25, the
// devourer 24, the rat god 20, the spider god 10; the Gods of Trouble print
// Special - 0 with the no-magic radius const)
inline int nhwCbtMR(int b)
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
            return 95;
        case 7:
            return 25;
        case 8:
            return 24;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 25;
        case 13:
            return 0;
        case 14:
            return 35;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 50;
        case 19:
            return 0;
        case 20:
            return 20;
        case 21:
            return 0;
        case 22:
            return 25;
        case 23:
            return 0;
        case 24:
            return 10;
        case 25:
            return 0;
        case 26:
            return 32;
        case 27:
            return 35;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The size inch cells (the Leviathan 3600, the snow serpent 1200, Hate 1080,
// the behemoth 480; Ningauble 108, Aarth 66 - the half-foot print, the Mouser
// 63 - the quarter-foot print; Sheelba the bare M and the devourer Variable
// pinned 0; Fafhrd 6 feet 11 inches - 83)
inline int nhwCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 83;
        case 1:
            return 63;
        case 2:
            return 66;
        case 3:
            return 48;
        case 4:
            return 480;
        case 5:
            return 12;
        case 6:
            return 84;
        case 7:
            return 360;
        case 8:
            return 0;
        case 9:
            return 60;
        case 10:
            return 72;
        case 11:
            return 72;
        case 12:
            return 1080;
        case 13:
            return 84;
        case 14:
            return 84;
        case 15:
            return 3600;
        case 16:
            return 72;
        case 17:
            return 108;
        case 18:
            return 180;
        case 19:
            return 72;
        case 20:
            return 120;
        case 21:
            return 0;
        case 22:
            return 96;
        case 23:
            return 1200;
        case 24:
            return 216;
        case 25:
            return 48;
        case 26:
            return 60;
        case 27:
            return 72;
        case 28:
            return 48;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric levels (Death 30, Aarth, the Trouble and Lankhmar and Issek and
// Tyaa 15, Votishal 13, the rat god 13, the earth god a 14th druid)
inline int nhwClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 30;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 15;
        case 12:
            return 0;
        case 13:
            return 15;
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
            return 4;
        case 20:
            return 13;
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
            return 15;
        case 27:
            return 13;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The druid levels (Kos 10, the earth god 14)
inline int nhwClsDruid(int b)
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
            return 10;
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
        default:
            return 0;
        }
    }

// The fighter levels (the Mouser 11, the devourer 5)
inline int nhwClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 11;
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
            return 5;
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
        default:
            return 0;
        }
    }

// The paladin levels ride this col (Issek 12, Movarl 12)
inline int nhwClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 30;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 5;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 12;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 12;
        case 17:
            return 0;
        case 18:
            return 15;
        case 19:
            return 15;
        case 20:
            return 15;
        case 21:
            return 0;
        case 22:
            return 20;
        case 23:
            return 0;
        case 24:
            return 15;
        case 25:
            return 0;
        case 26:
            return 10;
        case 27:
            return 12;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The ranger levels (Fafhrd 15, Kos 15)
inline int nhwClsRanger(int b)
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
            return 15;
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
        default:
            return 0;
        }
    }

// The magic-user levels (Death and Aarth 30; Hate prints See below - the 99
// pair)
inline int nhwClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 30;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 30;
        case 7:
            return 0;
        case 8:
            return 13;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 99;
        case 13:
            return 10;
        case 14:
            return 20;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 20;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 20;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 15;
        case 25:
            return 0;
        case 26:
            return 15;
        case 27:
            return 15;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The illusionist levels (Death 30; the in-each pairs: Trouble 20, the red
// god 12)
inline int nhwClsIllus(int b)
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
            return 30;
        case 7:
            return 0;
        case 8:
            return 25;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 20;
        case 12:
            return 99;
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
            return 5;
        case 22:
            return 12;
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
        default:
            return 0;
        }
    }

// The thief levels (Votishal 25, the Mouser 15, Fafhrd 13)
inline int nhwClsThief(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 15;
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
            return 0;
        case 26:
            return 0;
        case 27:
            return 25;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The assassin levels (Death and the Trouble 15, the rat god 12, the red god
// 10, Pulgh 5)
inline int nhwClsAssassin(int b)
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
            return 5;
        case 20:
            return 12;
        case 21:
            return 0;
        case 22:
            return 10;
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
        default:
            return 0;
        }
    }

// The monk levels (Sheelba and the red god 10)
inline int nhwClsMonk(int b)
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
            return 10;
        case 22:
            return 10;
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
        default:
            return 0;
        }
    }

// The bard levels (Death 23, Issek 15, Fafhrd 5, Ningauble 10, Votishal 3)
inline int nhwClsBard(int b)
    {
        switch (b) {
        case 0:
            return 5;
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
            return 15;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 10;
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
            return 3;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (Kos, Issek and the earth god 25; Hate 10 the low)
inline int nhwAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 16;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 0;
        case 10:
            return 19;
        case 11:
            return 12;
        case 12:
            return 10;
        case 13:
            return 25;
        case 14:
            return 25;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 14;
        case 18:
            return 25;
        case 19:
            return 17;
        case 20:
            return 20;
        case 21:
            return 20;
        case 22:
            return 24;
        case 23:
            return 0;
        case 24:
            return 22;
        case 25:
            return 0;
        case 26:
            return 18;
        case 27:
            return 20;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The strength hit bonuses (Kos/Issek/earth 25 (+7,+14))
inline int nhwAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 6;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 7;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 6;
        case 23:
            return 0;
        case 24:
            return 4;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 3;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The strength damage bonuses (Fafhrd 18(00) (+3,+6); Movarl 18(51) (+2,+3))
inline int nhwAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 0;
        case 2:
            return 8;
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
            return 7;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 14;
        case 14:
            return 14;
        case 15:
            return 0;
        case 16:
            return 3;
        case 17:
            return 0;
        case 18:
            return 14;
        case 19:
            return 1;
        case 20:
            return 8;
        case 21:
            return 8;
        case 22:
            return 12;
        case 23:
            return 0;
        case 24:
            return 10;
        case 25:
            return 0;
        case 26:
            return 2;
        case 27:
            return 8;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The intelligence cells (Aarth 25; the devourer W 5 the low)
inline int nhwAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 25;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 19;
        case 9:
            return 0;
        case 10:
            return 24;
        case 11:
            return 23;
        case 12:
            return 10;
        case 13:
            return 23;
        case 14:
            return 24;
        case 15:
            return 0;
        case 16:
            return 14;
        case 17:
            return 19;
        case 18:
            return 10;
        case 19:
            return 14;
        case 20:
            return 18;
        case 21:
            return 19;
        case 22:
            return 22;
        case 23:
            return 0;
        case 24:
            return 18;
        case 25:
            return 0;
        case 26:
            return 19;
        case 27:
            return 21;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The wisdom cells (Hate prints a dash - 0; the earth god 10; the spider god
// 9)
inline int nhwAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 14;
        case 2:
            return 24;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 9;
        case 11:
            return 18;
        case 12:
            return 0;
        case 13:
            return 25;
        case 14:
            return 23;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 12;
        case 19:
            return 17;
        case 20:
            return 13;
        case 21:
            return 10;
        case 22:
            return 17;
        case 23:
            return 0;
        case 24:
            return 9;
        case 25:
            return 0;
        case 26:
            return 20;
        case 27:
            return 19;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The dexterity cells (Aarth and Kos 25)
inline int nhwAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 19;
        case 2:
            return 25;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 17;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 18;
        case 12:
            return 10;
        case 13:
            return 22;
        case 14:
            return 25;
        case 15:
            return 0;
        case 16:
            return 17;
        case 17:
            return 16;
        case 18:
            return 18;
        case 19:
            return 17;
        case 20:
            return 23;
        case 21:
            return 16;
        case 22:
            return 25;
        case 23:
            return 0;
        case 24:
            return 22;
        case 25:
            return 0;
        case 26:
            return 25;
        case 27:
            return 25;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The constitution cells (Hate prints a dash - 0)
inline int nhwAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 17;
        case 2:
            return 23;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 19;
        case 9:
            return 0;
        case 10:
            return 23;
        case 11:
            return 23;
        case 12:
            return 0;
        case 13:
            return 24;
        case 14:
            return 24;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 25;
        case 19:
            return 16;
        case 20:
            return 19;
        case 21:
            return 19;
        case 22:
            return 24;
        case 23:
            return 0;
        case 24:
            return 24;
        case 25:
            return 0;
        case 26:
            return 20;
        case 27:
            return 20;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The charisma cells (the rat god minus 6; the Lankhmar gods and spider god
// minus 3; Hate prints a dash - 0)
inline int nhwAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 22;
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
            return 20;
        case 9:
            return 0;
        case 10:
            return -3;
        case 11:
            return 18;
        case 12:
            return 0;
        case 13:
            return 24;
        case 14:
            return 24;
        case 15:
            return 0;
        case 16:
            return 18;
        case 17:
            return 16;
        case 18:
            return 11;
        case 19:
            return 8;
        case 20:
            return -6;
        case 21:
            return 7;
        case 22:
            return 24;
        case 23:
            return 0;
        case 24:
            return -3;
        case 25:
            return 0;
        case 26:
            return 24;
        case 27:
            return 20;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The psionic ability cells (none printed with a score - 0)
inline int nhwAbiPsi(int b)
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
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinals 0-28 in print order
inline int nhwRosOrd(int b)
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
        default:
            return 0;
        }
    }

// The print pages 96-104 (one being the walk spans nine pages)
inline int nhwRosPage(int b)
    {
        switch (b) {
        case 0:
            return 96;
        case 1:
            return 97;
        case 2:
            return 97;
        case 3:
            return 97;
        case 4:
            return 97;
        case 5:
            return 98;
        case 6:
            return 98;
        case 7:
            return 98;
        case 8:
            return 98;
        case 9:
            return 99;
        case 10:
            return 99;
        case 11:
            return 99;
        case 12:
            return 100;
        case 13:
            return 100;
        case 14:
            return 100;
        case 15:
            return 100;
        case 16:
            return 101;
        case 17:
            return 101;
        case 18:
            return 101;
        case 19:
            return 101;
        case 20:
            return 102;
        case 21:
            return 102;
        case 22:
            return 102;
        case 23:
            return 102;
        case 24:
            return 103;
        case 25:
            return 103;
        case 26:
            return 103;
        case 27:
            return 103;
        case 28:
            return 104;
        default:
            return 0;
        }
    }

// The alignment codes (0 LG 1 NG 3 LN 4 N 6 LE 7 NE 8 CE; twelve neutral
// rows)
inline int nhwRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 7;
        case 4:
            return 4;
        case 5:
            return 7;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 8;
        case 12:
            return 8;
        case 13:
            return 0;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 0;
        case 17:
            return 4;
        case 18:
            return 8;
        case 19:
            return 6;
        case 20:
            return 8;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 8;
        case 25:
            return 4;
        case 26:
            return 8;
        case 27:
            return 0;
        case 28:
            return 4;
        default:
            return 0;
        }
    }

// The rank codes (0 lesser 1 greater 2 hero 3 demigod 4 wizard 5 monster)
inline int nhwRosRank(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 1;
        case 15:
            return 5;
        case 16:
            return 2;
        case 17:
            return 4;
        case 18:
            return 0;
        case 19:
            return 2;
        case 20:
            return 0;
        case 21:
            return 4;
        case 22:
            return 0;
        case 23:
            return 5;
        case 24:
            return 3;
        case 25:
            return 5;
        case 26:
            return 0;
        case 27:
            return 3;
        case 28:
            return 5;
        default:
            return 0;
        }
    }

// The psionic class cells (Death and the Trouble and the rat god I, Votishal
// and the Lankhmar gods V, the earth god and red god VI)
inline int nhwRosPsiClass(int b)
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
            return 5;
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
            return 6;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 6;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 5;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The plane codes (-1 none printed, 0 Godsland, 1 PMP, 2 astral; Hate alone
// on the astral)
inline int nhwRosPlane(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return 1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return -1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return -1;
        case 16:
            return -1;
        case 17:
            return -1;
        case 18:
            return 1;
        case 19:
            return -1;
        case 20:
            return 0;
        case 21:
            return -1;
        case 22:
            return 0;
        case 23:
            return -1;
        case 24:
            return 0;
        case 25:
            return -1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return -1;
        default:
            return 0;
        }
    }

// The printed-damage flags (seventeen dice-formula rows)
inline int nhwRosDmgFixed(int b)
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
            return 1;
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
            return 1;
        case 11:
            return 0;
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
            return 0;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        default:
            return 0;
        }
    }

// The in-each flags (Death, the Gods of Trouble, the red god)
inline int nhwRosInEach(int b)
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
        default:
            return 0;
        }
    }

// The advisor rivalry flags (Ningauble and Sheelba - the printed rivalry)
inline int nhwRosRivalry(int b)
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
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 1;
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
        default:
            return 0;
        }
    }

// ---- the encounter grid ----

// The encounter ordinals 1-74 across the six regions
inline int nhwEncOrd(int b)
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
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 14;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 17;
        case 17:
            return 18;
        case 18:
            return 19;
        case 19:
            return 20;
        case 20:
            return 21;
        case 21:
            return 22;
        case 22:
            return 23;
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 26;
        case 26:
            return 27;
        case 27:
            return 28;
        case 28:
            return 29;
        case 29:
            return 30;
        case 30:
            return 31;
        case 31:
            return 32;
        case 32:
            return 33;
        case 33:
            return 34;
        case 34:
            return 35;
        case 35:
            return 36;
        case 36:
            return 37;
        case 37:
            return 38;
        case 38:
            return 39;
        case 39:
            return 40;
        case 40:
            return 41;
        case 41:
            return 42;
        case 42:
            return 43;
        case 43:
            return 44;
        case 44:
            return 45;
        case 45:
            return 46;
        case 46:
            return 47;
        case 47:
            return 48;
        case 48:
            return 49;
        case 49:
            return 50;
        case 50:
            return 51;
        case 51:
            return 52;
        case 52:
            return 53;
        case 53:
            return 54;
        case 54:
            return 55;
        case 55:
            return 56;
        case 56:
            return 57;
        case 57:
            return 58;
        case 58:
            return 59;
        case 59:
            return 60;
        case 60:
            return 61;
        case 61:
            return 62;
        case 62:
            return 63;
        case 63:
            return 64;
        case 64:
            return 65;
        case 65:
            return 66;
        case 66:
            return 67;
        case 67:
            return 68;
        case 68:
            return 69;
        case 69:
            return 70;
        case 70:
            return 71;
        case 71:
            return 72;
        case 72:
            return 73;
        case 73:
            return 74;
        default:
            return 0;
        }
    }

// The region codes (0 cold 1 forest 2 marsh 3 mountains 4 plains 5
// waterborne)
inline int nhwEncRegion(int b)
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
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
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
            return 2;
        case 33:
            return 2;
        case 34:
            return 2;
        case 35:
            return 2;
        case 36:
            return 2;
        case 37:
            return 2;
        case 38:
            return 2;
        case 39:
            return 2;
        case 40:
            return 2;
        case 41:
            return 2;
        case 42:
            return 3;
        case 43:
            return 3;
        case 44:
            return 3;
        case 45:
            return 3;
        case 46:
            return 3;
        case 47:
            return 3;
        case 48:
            return 3;
        case 49:
            return 3;
        case 50:
            return 3;
        case 51:
            return 3;
        case 52:
            return 3;
        case 53:
            return 4;
        case 54:
            return 4;
        case 55:
            return 4;
        case 56:
            return 4;
        case 57:
            return 4;
        case 58:
            return 4;
        case 59:
            return 4;
        case 60:
            return 4;
        case 61:
            return 4;
        case 62:
            return 4;
        case 63:
            return 4;
        case 64:
            return 4;
        case 65:
            return 5;
        case 66:
            return 5;
        case 67:
            return 5;
        case 68:
            return 5;
        case 69:
            return 5;
        case 70:
            return 5;
        case 71:
            return 5;
        case 72:
            return 5;
        case 73:
            return 5;
        default:
            return 0;
        }
    }

// The dice-roll lows (the mountains overlap: the astral wolf 01-05 and the
// bird of Tyaa 03-06 - pinned as printed)
inline int nhwEncLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 9;
        case 3:
            return 13;
        case 4:
            return 18;
        case 5:
            return 22;
        case 6:
            return 26;
        case 7:
            return 32;
        case 8:
            return 35;
        case 9:
            return 41;
        case 10:
            return 44;
        case 11:
            return 56;
        case 12:
            return 62;
        case 13:
            return 66;
        case 14:
            return 71;
        case 15:
            return 78;
        case 16:
            return 83;
        case 17:
            return 86;
        case 18:
            return 91;
        case 19:
            return 97;
        case 20:
            return 1;
        case 21:
            return 7;
        case 22:
            return 10;
        case 23:
            return 19;
        case 24:
            return 27;
        case 25:
            return 35;
        case 26:
            return 51;
        case 27:
            return 59;
        case 28:
            return 67;
        case 29:
            return 83;
        case 30:
            return 91;
        case 31:
            return 97;
        case 32:
            return 1;
        case 33:
            return 4;
        case 34:
            return 16;
        case 35:
            return 21;
        case 36:
            return 43;
        case 37:
            return 51;
        case 38:
            return 71;
        case 39:
            return 81;
        case 40:
            return 86;
        case 41:
            return 96;
        case 42:
            return 1;
        case 43:
            return 3;
        case 44:
            return 7;
        case 45:
            return 16;
        case 46:
            return 25;
        case 47:
            return 46;
        case 48:
            return 58;
        case 49:
            return 67;
        case 50:
            return 83;
        case 51:
            return 91;
        case 52:
            return 97;
        case 53:
            return 1;
        case 54:
            return 3;
        case 55:
            return 8;
        case 56:
            return 17;
        case 57:
            return 19;
        case 58:
            return 28;
        case 59:
            return 38;
        case 60:
            return 44;
        case 61:
            return 53;
        case 62:
            return 62;
        case 63:
            return 71;
        case 64:
            return 91;
        case 65:
            return 1;
        case 66:
            return 4;
        case 67:
            return 16;
        case 68:
            return 18;
        case 69:
            return 30;
        case 70:
            return 40;
        case 71:
            return 65;
        case 72:
            return 75;
        case 73:
            return 87;
        default:
            return 0;
        }
    }

// The dice-roll highs (00 read as 100)
inline int nhwEncHigh(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 8;
        case 2:
            return 12;
        case 3:
            return 17;
        case 4:
            return 21;
        case 5:
            return 25;
        case 6:
            return 31;
        case 7:
            return 34;
        case 8:
            return 40;
        case 9:
            return 43;
        case 10:
            return 55;
        case 11:
            return 61;
        case 12:
            return 65;
        case 13:
            return 70;
        case 14:
            return 77;
        case 15:
            return 82;
        case 16:
            return 85;
        case 17:
            return 90;
        case 18:
            return 96;
        case 19:
            return 100;
        case 20:
            return 6;
        case 21:
            return 9;
        case 22:
            return 18;
        case 23:
            return 26;
        case 24:
            return 34;
        case 25:
            return 50;
        case 26:
            return 58;
        case 27:
            return 66;
        case 28:
            return 82;
        case 29:
            return 90;
        case 30:
            return 96;
        case 31:
            return 100;
        case 32:
            return 3;
        case 33:
            return 15;
        case 34:
            return 20;
        case 35:
            return 42;
        case 36:
            return 50;
        case 37:
            return 70;
        case 38:
            return 80;
        case 39:
            return 85;
        case 40:
            return 95;
        case 41:
            return 100;
        case 42:
            return 5;
        case 43:
            return 6;
        case 44:
            return 15;
        case 45:
            return 24;
        case 46:
            return 45;
        case 47:
            return 57;
        case 48:
            return 66;
        case 49:
            return 82;
        case 50:
            return 90;
        case 51:
            return 96;
        case 52:
            return 100;
        case 53:
            return 2;
        case 54:
            return 7;
        case 55:
            return 16;
        case 56:
            return 18;
        case 57:
            return 27;
        case 58:
            return 37;
        case 59:
            return 43;
        case 60:
            return 52;
        case 61:
            return 61;
        case 62:
            return 70;
        case 63:
            return 90;
        case 64:
            return 100;
        case 65:
            return 3;
        case 66:
            return 15;
        case 67:
            return 17;
        case 68:
            return 29;
        case 69:
            return 39;
        case 70:
            return 64;
        case 71:
            return 74;
        case 72:
            return 86;
        case 73:
            return 100;
        default:
            return 0;
        }
    }

// ---- the R863 census ----

// twenty-nine stat-block rows walk the section
inline int nhwBeingCount()
    { return 29; }

// the five grids (combat, class, ability, roster, encounter)
inline int nhwTableCount()
    { return 5; }

// no chains this round
inline int nhwChainCount()
    { return 0; }

// zero registry defs touched - the floor holds
inline int nhwRegistryFloor()
    { return 995; }

// the combat grid rows
inline int nhwCbtRows()
    { return 29; }

// the class grid rows
inline int nhwClsRows()
    { return 29; }

// the ability grid rows
inline int nhwAbiRows()
    { return 29; }

// the roster grid rows
inline int nhwRosRows()
    { return 29; }

// the encounter grid rows (the six print tables)
inline int nhwEncRows()
    { return 74; }

// six outdoor encounter regions (print p. 104)
inline int nhwEncTables()
    { return 6; }

// the cold region rows
inline int nhwEncColdRows()
    { return 20; }

// the forest rows
inline int nhwEncForestRows()
    { return 12; }

// the marsh rows
inline int nhwEncMarshRows()
    { return 10; }

// the mountains rows
inline int nhwEncMtnRows()
    { return 11; }

// the plains/hills rows
inline int nhwEncPlainRows()
    { return 12; }

// the waterborne rows
inline int nhwEncWaterRows()
    { return 9; }

// three plane codes: Godsland, PMP, astral
inline int nhwPlaneCount()
    { return 3; }

// two greater gods: Death and Kos
inline int nhwGreaterCount()
    { return 2; }

// six lesser gods: Trouble, Hate, Earth, Rat, Red, Tyaa
inline int nhwLesserCount()
    { return 6; }

// five demigods: Aarth, Lankhmar, Issek, Spider, Votishal
inline int nhwDemigodCount()
    { return 5; }

// four heroes: Fafhrd, Mouser, Movarl, Pulgh
inline int nhwHeroCount()
    { return 4; }

// two wizards: Ningauble and Sheelba
inline int nhwWizardCount()
    { return 2; }

// ten monsters
inline int nhwMonsterCount()
    { return 10; }

// three in-each pairs: Death, Trouble, Red God
inline int nhwInEachCount()
    { return 3; }

// the advisor rivalry pair: Ningauble and Sheelba
inline int nhwRivalryCount()
    { return 2; }

// two paladins: Issek and Movarl
inline int nhwPaladinCount()
    { return 2; }

// seven psionic rows
inline int nhwPsiRowCount()
    { return 7; }

// three psionic classes printed: I, V and VI
inline int nhwPsiClassKinds()
    { return 3; }

// two half-foot size cells: Aarth 66 and the L&L 5.5 print
inline int nhwHalfFootCount()
    { return 2; }

// the quarter-foot cell: the Mouser 5 1/4 foot print (63)
inline int nhwQuarterFootCount()
    { return 1; }

// the three Hate dash cells: W, C and CH pinned 0
inline int nhwDashAbilityCount()
    { return 3; }

// the Hate MU/I See below pair pinned 99/99
inline int nhwSeeBelowPairCount()
    { return 2; }

// seventeen printed-damage formula rows
inline int nhwDmgFixedCount()
    { return 17; }

// seven hit-dice monster rows (hp pinned 0)
inline int nhwHDRowCount()
    { return 7; }

// eight Godsland rows in the roster
inline int nhwGodslandCount()
    { return 8; }

}   // namespace rules
