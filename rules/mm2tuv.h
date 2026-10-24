// =========================================================================================
// Adnd1 - rules/mm2tuv.h
// THE MM2 LETTERS TUV WALK - THE TARRASQUE TO VULTURE TURNS (pp. 117-125: the
// tarrasque p. 117, the tasloi p. 118, the giant harvester termite variant
// table pp. 118-119 (worker, soldier, plus the king and queen royal pair),
// the thessalhydra, thri-kreen, thunder beast and time elemental p. 119, the
// thunderherder and transposer p. 120, the tri-flower frond and the scrag
// variant table p. 121, the twilight bloom and land urchin p. 122, the
// ustilagor p. 122 and vagabond pp. 122-123, the vargouille p. 123, the
// vegepygmy, verme and vilstrak p. 124, the vulchling and vulture variant
// table p. 125), promoted to the live registry; the TUV-FLIP round, the
// Letter T, U and V gap boxes flip to closed
// census 736 -> 737.
//
// Round nineteen of the MM2 arc, the EIGHTH single-letter pass (Curtiss Go
// call on the landed letter S walk; the letters T, U and V pin-time walk
// found TWENTY-ONE entry heads carrying TWENTY-TWO stat blocks - the termite,
// scrag and vulture variant tables one head apiece, the termite royal pair
// the one extra block, no prior-owned heads, no doctrine-only heads)
//
// The pin headers stay the print-fidelity record; the twenty-six .lua defs
// ride the R791 data_files extension in the MM1 registry schema (the
// defensive coercers load the verbatim print cells, the TUVStats grid carries
// the loader values)
//
namespace rules {

// ---- the MM2 letters TUV walk round pins (the R814 census) ----

// The MM2 letters TUV walk round: the tarrasque to vulture turns, the EIGHTH
// single-letter pass (Curtiss Go call on the landed letter S walk)
inline int mm2tuvRound()
    { return 814; }

// The registry census before the R814 promotion (the landed R813 count)
inline int mm2tuvRegistryBefore()
    { return 766; }

// The registry census after the R814 promotion (26 defs riding the R791
// data_files extension)
inline int mm2tuvRegistryAfter()
    { return 792; }

// The 26 letters TUV defs promoted this round
inline int mm2tuvDefCount()
    { return 26; }

// The 21 letters TUV entry heads (the termite, scrag and vulture variant
// tables one head apiece)
inline int mm2tuvEntryCount()
    { return 21; }

// The 22 letters TUV stat blocks (the termite royal pair the one extra block)
inline int mm2tuvStatBlockHeadings()
    { return 22; }

// No doctrine-only family heads in the letters TUV walk
inline int mm2tuvDoctrineHeads()
    { return 0; }

// The 21 letters TUV index entries
inline int mm2tuvLetterTUVHeadings()
    { return 21; }

// The 26-row TUVStats stat grid
inline int mm2tuvTUVStatRows()
    { return 26; }

// The gap census after the TUV-FLIP: 27 boxes closed
inline int mm2tuvGapClosed()
    { return 27; }

// The gap census after the TUV-FLIP: 10 boxes open
inline int mm2tuvGapOpen()
    { return 10; }

// No prior-owned letters TUV heads (the MM1 t/thought_eater.lua print is an
// MM1 entry, not an MM2 letter T head)
inline int mm2tuvPriorOwnedEntries()
    { return 0; }

// ---- the tarrasque pins (the R814 MM2 letters TUV walk) ----

// The Tarrasque xpValue (the print 10 base 37500 + 0/hp x avgHp 300)
inline int mm2tuvTarrasqueXpValue()
    { return 37500; }

// The Tarrasque xp level
inline int mm2tuvTarrasqueXpLevel()
    { return 10; }

// The tarrasque 300 hp the flat-hp read (hdNum 0)
inline int mm2tuvTarrasqueHitPoints()
    { return 300; }

// The tarrasque rush adds 6" once every turn
inline int mm2tuvTarrasqueRushBonusInches()
    { return 6; }

// The tarrasque sweeping tail lash 2-24
inline int mm2tuvTarrasqueTailLashMax()
    { return 24; }

// The tarrasque savage bite 5-50
inline int mm2tuvTarrasqueBiteMax()
    { return 50; }

// Each tarrasque horn thrust 1-10 (2 attacks)
inline int mm2tuvTarrasqueHornMax()
    { return 10; }

// 1 in 6 bolt and ray attacks reflect back upon the caster
inline int mm2tuvTarrasqueReflectChance()
    { return 6; }

// The tarrasque regenerates 1 hit point per round
inline int mm2tuvTarrasqueRegenPerRound()
    { return 1; }

// The tarrasque dies only at -30 or fewer hit points plus a wish
inline int mm2tuvTarrasqueSlayThreshold()
    { return -30; }

// The carapace yields 10-100 diamonds of 1000 gp base value
inline int mm2tuvTarrasqueDiamondMin()
    { return 10; }

// The carapace diamonds up to 100
inline int mm2tuvTarrasqueDiamondMax()
    { return 100; }

// Each carapace diamond 1000 gp base value
inline int mm2tuvTarrasqueDiamondBaseGp()
    { return 1000; }

// The underbelly metal forges 1-4 shields of +5 power
inline int mm2tuvTarrasqueShieldMin()
    { return 1; }

// The shields up to 4
inline int mm2tuvTarrasqueShieldMax()
    { return 4; }

// The forged shields +5
inline int mm2tuvTarrasqueShieldPlus()
    { return 5; }

// The tarrasque sleeps 5-20 months between foraging
inline int mm2tuvTarrasqueDormancyMinMonths()
    { return 5; }

// The dormancy up to 20 months
inline int mm2tuvTarrasqueDormancyMaxMonths()
    { return 20; }

// The active to dormant ratio about 1:30
inline int mm2tuvTarrasqueActiveToDormantRatio()
    { return 30; }

// Fire of any sort has no effect upon the tarrasque
inline bool mm2tuvTarrasqueFireImmune()
    { return true; }

// Bolts and rays bounce off the tarrasque carapace
inline bool mm2tuvTarrasqueReflectsRays()
    { return true; }

// The tarrasque can be struck only by +1 or better magic weapons
inline bool mm2tuvTarrasqueMagicWeaponToHit()
    { return true; }

// ---- the tasloi pins (the R814 MM2 letters TUV walk) ----

// The Tasloi xpValue (the print 1 base 10 + 1/hp x avgHp 3)
inline int mm2tuvTasloiXpValue()
    { return 13; }

// The Tasloi xp level
inline int mm2tuvTasloiXpLevel()
    { return 1; }

// The tasloi surprise on a 1-4 (1d6)
inline int mm2tuvTasloiSurpriseMax()
    { return 4; }

// The tasloi hide in shadows 75% of the time
inline int mm2tuvTasloiHideInShadowsPct()
    { return 75; }

// Full daylight causes a -1 on tasloi to-hit rolls
inline int mm2tuvTasloiDaylightPenalty()
    { return 1; }

// A tasloi chief (5 HD) for every band of 70 or more
inline int mm2tuvTasloiChiefBandSize()
    { return 70; }

// The tasloi chief 5 HD
inline int mm2tuvTasloiChiefHitDice()
    { return 5; }

// A 30% chance any band has a shaman
inline int mm2tuvTasloiShamanChancePct()
    { return 30; }

// Tasloi shamans advance up to 5th level
inline int mm2tuvTasloiShamanMaxLevel()
    { return 5; }

// Using a shield the tasloi armor class becomes 5
inline int mm2tuvTasloiShieldArmorClass()
    { return 5; }

// The lair 1-6 large trees
inline int mm2tuvTasloiLairTreesMin()
    { return 1; }

// The lair trees up to 6
inline int mm2tuvTasloiLairTreesMax()
    { return 6; }

// The lair 4-24 platforms
inline int mm2tuvTasloiPlatformsMin()
    { return 4; }

// The platforms up to 24
inline int mm2tuvTasloiPlatformsMax()
    { return 24; }

// The platforms 50-100 feet from the ground
inline int mm2tuvTasloiPlatformHeightMin()
    { return 50; }

// The platform height up to 100 feet
inline int mm2tuvTasloiPlatformHeightMax()
    { return 100; }

// A 60% chance of 1-6 trained giant spiders
inline int mm2tuvTasloiGiantSpiderChancePct()
    { return 60; }

// A 20% chance of 2-8 trained giant wasps
inline int mm2tuvTasloiGiantWaspChancePct()
    { return 20; }

// About 5% of tasloi know a pidgin Common
inline int mm2tuvTasloiPidginCommonPct()
    { return 5; }

// The tasloi have infravision and are suited to dark jungles
inline bool mm2tuvTasloiInfravision()
    { return true; }

// The tasloi are quick and nimble in the arboreal passageways
inline bool mm2tuvTasloiArboreal()
    { return true; }

// ---- the giant harvester termite pins (the R814 MM2 letters TUV walk) ----

// The Termite, Worker xpValue (the print 1 base 20 + 2/hp x avgHp 5)
inline int mm2tuvTermiteWorkerXpValue()
    { return 30; }

// The Termite, Worker xp level
inline int mm2tuvTermiteWorkerXpLevel()
    { return 1; }

// The termite nest a stone-hard mound about 100 feet in diameter
inline int mm2tuvTermiteNestDiameterFeet()
    { return 100; }

// The nest 200-500 feet high
inline int mm2tuvTermiteNestHeightMinFeet()
    { return 200; }

// The nest up to 500 feet
inline int mm2tuvTermiteNestHeightMaxFeet()
    { return 500; }

// The circular openings 5-8 feet in diameter
inline int mm2tuvTermiteOpeningMinFeet()
    { return 5; }

// The openings up to 8 feet
inline int mm2tuvTermiteOpeningMaxFeet()
    { return 8; }

// In the lair 10 times the workers and soldiers first encountered
inline int mm2tuvTermiteLairMultiplier()
    { return 10; }

// More than 30 workers are accompanied by 3-16 soldiers
inline int mm2tuvTermiteSoldierEscortMin()
    { return 3; }

// The soldier escort up to 16
inline int mm2tuvTermiteSoldierEscortMax()
    { return 16; }

// Chamber guards get a +1 both to hit and to damage
inline int mm2tuvTermiteChamberGuardBonus()
    { return 1; }

// The Termite, Soldier xpValue (the print 2 base 50 + 3/hp x avgHp 9)
inline int mm2tuvTermiteSoldierXpValue()
    { return 77; }

// The Termite, Soldier xp level
inline int mm2tuvTermiteSoldierXpLevel()
    { return 2; }

// The soldier spit blinds for 5-20 rounds (save vs. poison negates)
inline int mm2tuvTermiteSoldierBlindMinRounds()
    { return 5; }

// The blindness up to 20
inline int mm2tuvTermiteSoldierBlindMaxRounds()
    { return 20; }

// Ignited spit inflicts 5-16 points of burning damage
inline int mm2tuvTermiteSoldierBurnMin()
    { return 5; }

// The burning damage up to 16
inline int mm2tuvTermiteSoldierBurnMax()
    { return 16; }

// The spit range 1", volume about 1 pint, once per turn
inline int mm2tuvTermiteSoldierSpitRangeInches()
    { return 1; }

// The Termite, King xpValue (the print 5 base 500 + 10/hp x avgHp 27)
inline int mm2tuvTermiteKingXpValue()
    { return 770; }

// The Termite, King xp level
inline int mm2tuvTermiteKingXpLevel()
    { return 5; }

// The termite king hp 30 or more
inline int mm2tuvTermiteKingHpMin()
    { return 30; }

// The termite king Dmg 3-18
inline int mm2tuvTermiteKingDamageMax()
    { return 18; }

// The Termite, Queen xpValue (the print 6 base 900 + 13/hp x avgHp 36)
inline int mm2tuvTermiteQueenXpValue()
    { return 1368; }

// The Termite, Queen xp level
inline int mm2tuvTermiteQueenXpLevel()
    { return 6; }

// The termite queen hp 40 or more
inline int mm2tuvTermiteQueenHpMin()
    { return 40; }

// The termite queen Dmg 5-30
inline int mm2tuvTermiteQueenDamageMax()
    { return 30; }

// Termites are nocturnal and shun light
inline bool mm2tuvTermiteNocturnal()
    { return true; }

// Formians are the worst enemies of giant termites
inline bool mm2tuvTermiteFormianEnemies()
    { return true; }

// The soldier fluid blinds any creature struck without a save
inline bool mm2tuvTermiteSoldierSpitBlinds()
    { return true; }

// The soldier spit burns if exposed to flame or heat
inline bool mm2tuvTermiteSoldierSpitFlammable()
    { return true; }

// The king spits double range and quantity every other round
inline bool mm2tuvTermiteKingDoubleSpit()
    { return true; }

// As many eggs in the egg chamber as workers and soldiers combined
inline bool mm2tuvTermiteQueenEggCountMatches()
    { return true; }

// ---- the thessalhydra pins (the R814 MM2 letters TUV walk) ----

// The Thessalhydra xpValue (the print 9 base 5800 + 16/hp x avgHp 42)
inline int mm2tuvThessalhydraXpValue()
    { return 6472; }

// The Thessalhydra xp level
inline int mm2tuvThessalhydraXpLevel()
    { return 9; }

// Each fringe head some 6 feet long
inline int mm2tuvThessalhydraFringeHeadFeet()
    { return 6; }

// Fringe heads each take 12 points of damage to sever
inline int mm2tuvThessalhydraSeverDamage()
    { return 12; }

// Lost fringe heads regenerate in 12 days
inline int mm2tuvThessalhydraFringeRegenDays()
    { return 12; }

// The acid spit up to 3" distant
inline int mm2tuvThessalhydraSpitRangeInches()
    { return 3; }

// The spit covers a 12-foot diameter circle
inline int mm2tuvThessalhydraSpitDiameterFeet()
    { return 12; }

// The spit inflicts 12-72 points of acid damage (save for half)
inline int mm2tuvThessalhydraSpitMin()
    { return 12; }

// The spit damage up to 72
inline int mm2tuvThessalhydraSpitMax()
    { return 72; }

// The main mouth bites 1-20 plus another 1-20 acid
inline int mm2tuvThessalhydraMouthMax()
    { return 20; }

// The tail pincer inflicts 1-12 in the grasping
inline int mm2tuvThessalhydraTailMax()
    { return 12; }

// Acids of any sort have no effect upon a thessalhydra
inline bool mm2tuvThessalhydraAcidImmune()
    { return true; }

// Damage to fringe heads does not harm the body
inline bool mm2tuvThessalhydraFringeIsolated()
    { return true; }

// ---- the thri-kreen pins (the R814 MM2 letters TUV walk) ----

// The Thri-Kreen (Mantis Warrior) xpValue (the print 6 base 800 + 8/hp x
// avgHp 24)
inline int mm2tuvThriKreenXpValue()
    { return 992; }

// The Thri-Kreen (Mantis Warrior) xp level
inline int mm2tuvThriKreenXpLevel()
    { return 6; }

// The thri-kreen leap 20 feet up
inline int mm2tuvThriKreenLeapUpFeet()
    { return 20; }

// The thri-kreen leap 50 feet forward
inline int mm2tuvThriKreenLeapForwardFeet()
    { return 50; }

// The polearm damage 3-8
inline int mm2tuvThriKreenPolearmMin()
    { return 3; }

// The polearm damage up to 8
inline int mm2tuvThriKreenPolearmMax()
    { return 8; }

// The throwing wedge damage 3-6
inline int mm2tuvThriKreenWedgeMin()
    { return 3; }

// The wedge damage up to 6
inline int mm2tuvThriKreenWedgeMax()
    { return 6; }

// The wedges thrown up to 9"
inline int mm2tuvThriKreenWedgeRangeInches()
    { return 9; }

// Up to 10 wedges carried
inline int mm2tuvThriKreenWedgeCarryMax()
    { return 10; }

// A thri-kreen dodges missiles on a roll of 9 or better on 1d20
inline int mm2tuvThriKreenDodgeRoll()
    { return 9; }

// The mandible bite 2-5
inline int mm2tuvThriKreenBiteMin()
    { return 2; }

// The bite damage up to 5
inline int mm2tuvThriKreenBiteMax()
    { return 5; }

// The bite paralyzes for 2-16 rounds without a save
inline int mm2tuvThriKreenParalysisMinRounds()
    { return 2; }

// The paralysis up to 16
inline int mm2tuvThriKreenParalysisMaxRounds()
    { return 16; }

// The throwing wedges return to the thrower if they miss
inline bool mm2tuvThriKreenWedgeReturns()
    { return true; }

// Unarmed the thri-kreen strike with 4 clawed appendages (1-4)
inline bool mm2tuvThriKreenFourClaws()
    { return true; }

// ---- the thunder beast pins (the R814 MM2 letters TUV walk) ----

// The Thunder Beast xpValue (the print 6 base 650 + 10/hp x avgHp 15)
inline int mm2tuvThunderBeastXpValue()
    { return 800; }

// The Thunder Beast xp level
inline int mm2tuvThunderBeastXpLevel()
    { return 6; }

// For every 2 adults there is 1 immature thunder beast
inline int mm2tuvThunderBeastYoungPerAdults()
    { return 2; }

// The trampling charge commences from 2" or greater
inline int mm2tuvThunderBeastTrampleRangeInches()
    { return 2; }

// The trample inflicts 1d4 per hit die
inline int mm2tuvThunderBeastTrampleDieMax()
    { return 4; }

// The breath builds to equal a fog cloud after 3 rounds
inline int mm2tuvThunderBeastBreathRounds()
    { return 3; }

// The cloud persists 1-4
inline int mm2tuvThunderBeastCloudMinRounds()
    { return 1; }

// The cloud up to 4 rounds
inline int mm2tuvThunderBeastCloudMaxRounds()
    { return 4; }

// Creatures affected by odors fight at -2 hit probability
inline int mm2tuvThunderBeastOdorPenalty()
    { return 2; }

// The thunder beast has 6 longer legs
inline int mm2tuvThunderBeastLegs()
    { return 6; }

// At least 1 in every 5 thunder beasts has 9 hit dice
inline int mm2tuvThunderBeastRareHd()
    { return 9; }

// The 9-hit-dice chance 1 in 5
inline int mm2tuvThunderBeastRareHdChance()
    { return 5; }

// In combat each thunder beast breathes on its opponent
inline bool mm2tuvThunderBeastFogBreath()
    { return true; }

// The young have no attack form
inline bool mm2tuvThunderBeastYoungHarmless()
    { return true; }

// ---- the time elemental pins (the R814 MM2 letters TUV walk) ----

// The Time Elemental xpValue (the print 7 base 3000 + 20/hp x avgHp 42)
inline int mm2tuvTimeElementalXpValue()
    { return 3840; }

// The Time Elemental xp level
inline int mm2tuvTimeElementalXpLevel()
    { return 7; }

// A common time elemental adds 1-4 additional manifestations
inline int mm2tuvTimeElementalExtraMin()
    { return 1; }

// The manifestations up to 4
inline int mm2tuvTimeElementalExtraMax()
    { return 4; }

// All time-related spells are useless within 3" of a time elemental
inline int mm2tuvTimeElementalDampenInches()
    { return 3; }

// Only 1 chance in 10 that any spell affects a time elemental
inline int mm2tuvTimeElementalSpellChance()
    { return 10; }

// Time pursuit 1" for each hit die
inline int mm2tuvTimeElementalPursuitPerHd()
    { return 1; }

// The common pursuit rate up to 13"
inline int mm2tuvTimeElementalCommonPursuitMax()
    { return 13; }

// The noble pursuit rate up to 17"
inline int mm2tuvTimeElementalNoblePursuitMax()
    { return 17; }

// Time travel 1 round for each hit die
inline int mm2tuvTimeElementalTravelPerHd()
    { return 1; }

// The noble ages or youthens a creature 1-20 years
inline int mm2tuvTimeElementalNobleAgeMin()
    { return 1; }

// The noble aging up to 20
inline int mm2tuvTimeElementalNobleAgeMax()
    { return 20; }

// The noble ages vegetable matter 10-200 years
inline int mm2tuvTimeElementalMatterAgeMin()
    { return 10; }

// The matter aging up to 200
inline int mm2tuvTimeElementalMatterAgeMax()
    { return 200; }

// The noble ages mineral material 100-2000 years
inline int mm2tuvTimeElementalMineralAgeMin()
    { return 100; }

// The mineral aging up to 2000
inline int mm2tuvTimeElementalMineralAgeMax()
    { return 2000; }

// The noble moves up to 4 other creatures along time
inline int mm2tuvTimeElementalNobleMoveMax()
    { return 4; }

// Royal time elementals have 24 or 28 hit dice
inline int mm2tuvTimeElementalRoyalHdMin()
    { return 24; }

// The royal hit dice up to 28
inline int mm2tuvTimeElementalRoyalHdMax()
    { return 28; }

// Royals summon 1-4 common (70%) or 1-2 noble elementals (30%)
inline int mm2tuvTimeElementalRoyalSummonPct()
    { return 70; }

// A noble casts time stop at will, once per day
inline bool mm2tuvTimeElementalTimeStop()
    { return true; }

// Time elementals cannot be conjured, summoned or otherwise brought
inline bool mm2tuvTimeElementalUnsummonable()
    { return true; }

// ---- the thunderherder pins (the R814 MM2 letters TUV walk) ----

// The Thunderherder xpValue (the print 5 base 350 + 8/hp x avgHp 24)
inline int mm2tuvThunderherderXpValue()
    { return 542; }

// The Thunderherder xp level
inline int mm2tuvThunderherderXpLevel()
    { return 5; }

// The thunderherder 3-5 feet wide
inline int mm2tuvThunderherderWidthMinFeet()
    { return 3; }

// The width up to 5 feet
inline int mm2tuvThunderherderWidthMaxFeet()
    { return 5; }

// The thunderherder 5-10 feet long
inline int mm2tuvThunderherderLengthMinFeet()
    { return 5; }

// The length up to 10 feet
inline int mm2tuvThunderherderLengthMaxFeet()
    { return 10; }

// The stampede tremors panic all pack animals
inline bool mm2tuvThunderherderTremors()
    { return true; }

// Thunderherders are not aggressive and do no real damage
inline bool mm2tuvThunderherderNonaggressive()
    { return true; }

// ---- the transposer pins (the R814 MM2 letters TUV walk) ----

// The Transposer xpValue (the print 6 base 625 + 7/hp x avgHp 21)
inline int mm2tuvTransposerXpValue()
    { return 772; }

// The Transposer xp level
inline int mm2tuvTransposerXpLevel()
    { return 6; }

// The transposer hit points build to a maximum of 48
inline int mm2tuvTransposerMaxHp()
    { return 48; }

// The horny-ridged suckers inflict 1-6 points of damage
inline int mm2tuvTransposerSuckerMax()
    { return 6; }

// A 20-point spell attack harms the caster and feeds the transposer
inline int mm2tuvTransposerExampleDamage()
    { return 20; }

// Only healing-type spells harm a bound transposer
inline bool mm2tuvTransposerHealingHarms()
    { return true; }

// The transposer disguises itself with a change self illusion
inline bool mm2tuvTransposerSelfIllusion()
    { return true; }

// ---- the tri-flower frond pins (the R814 MM2 letters TUV walk) ----

// The Tri-Flower Frond xpValue (the print 3 base 120 + 3/hp x avgHp 15)
inline int mm2tuvTriFlowerXpValue()
    { return 165; }

// The Tri-Flower Frond xp level
inline int mm2tuvTriFlowerXpLevel()
    { return 3; }

// The stalks 5-8 feet tall
inline int mm2tuvTriFlowerStalkMinFeet()
    { return 5; }

// The stalks up to 8 feet
inline int mm2tuvTriFlowerStalkMaxFeet()
    { return 8; }

// The orange flower shoots 2-8 tendrils
inline int mm2tuvTriFlowerTendrilMin()
    { return 2; }

// The tendrils up to 8
inline int mm2tuvTriFlowerTendrilMax()
    { return 8; }

// Each tendril 3 feet long
inline int mm2tuvTriFlowerTendrilFeet()
    { return 3; }

// The sticky enzyme 2-8 points per round
inline int mm2tuvTriFlowerEnzymeMin()
    { return 2; }

// The enzyme damage up to 8
inline int mm2tuvTriFlowerEnzymeMax()
    { return 8; }

// Each flask of water reduces enzyme damage by 1 point
inline int mm2tuvTriFlowerWaterReduction()
    { return 1; }

// The red flower tendrils 1 foot long
inline int mm2tuvTriFlowerRedTendrilFeet()
    { return 1; }

// The red flower draws body fluids 1-6 per turn
inline int mm2tuvTriFlowerDrainMin()
    { return 1; }

// The fluid drain up to 6
inline int mm2tuvTriFlowerDrainMax()
    { return 6; }

// Total immersion in water removes the sap entirely
inline bool mm2tuvTriFlowerImmersionCures()
    { return true; }

// The orange pollen comatose slumber without a save vs. poison
inline bool mm2tuvTriFlowerSlumberPollen()
    { return true; }

// ---- the scrag pins (the R814 MM2 letters TUV walk) ----

// The Scrag, Freshwater xpValue (the print 5 base 400 + 8/hp x avgHp 22)
inline int mm2tuvScragFreshwaterXpValue()
    { return 576; }

// The Scrag, Freshwater xp level
inline int mm2tuvScragFreshwaterXpLevel()
    { return 5; }

// The freshwater claws 2-5
inline int mm2tuvScragFreshClawMax()
    { return 5; }

// The enlarged jaw 3-12
inline int mm2tuvScragFreshJawMin()
    { return 3; }

// The jaw damage up to 12
inline int mm2tuvScragFreshJawMax()
    { return 12; }

// Up to 3 different opponents can be attacked in a single round
inline int mm2tuvScragFreshOpponents()
    { return 3; }

// The Scrag, Saltwater xpValue (the print 6 base 900 + 12/hp x avgHp 33)
inline int mm2tuvScragSaltwaterXpValue()
    { return 1296; }

// The Scrag, Saltwater xp level
inline int mm2tuvScragSaltwaterXpLevel()
    { return 6; }

// Some few (10%) saltwater scrags armor themselves
inline int mm2tuvScragSaltArmoredPct()
    { return 10; }

// The shell-and-sharkskin armor gives an effective AC 1
inline int mm2tuvScragSaltArmoredAc()
    { return 1; }

// The saltwater claws 1-4
inline int mm2tuvScragSaltClawMax()
    { return 4; }

// The huge maw 9-16
inline int mm2tuvScragSaltMawMin()
    { return 9; }

// The maw damage up to 16
inline int mm2tuvScragSaltMawMax()
    { return 16; }

// Marine trolls are a gilled form of the common troll
inline bool mm2tuvScragGilled()
    { return true; }

// The freshwater scrag regenerates only when immersed in fresh water
inline bool mm2tuvScragFreshRegenerates()
    { return true; }

// The saltwater scrag regenerates in its saltwater element
inline bool mm2tuvScragSaltRegenerates()
    { return true; }

// ---- the twilight bloom pins (the R814 MM2 letters TUV walk) ----

// The Twilight Bloom (Purple Death) xpValue (the print 3 base 125 + 4/hp x
// avgHp 18)
inline int mm2tuvTwilightBloomXpValue()
    { return 197; }

// The Twilight Bloom (Purple Death) xp level
inline int mm2tuvTwilightBloomXpLevel()
    { return 3; }

// The tall stalk 8-13 feet
inline int mm2tuvTwilightBloomHeightMinFeet()
    { return 8; }

// The stalk up to 13 feet
inline int mm2tuvTwilightBloomHeightMaxFeet()
    { return 13; }

// A 25% chance of being struck by the toxic sap
inline int mm2tuvTwilightBloomSapChancePct()
    { return 25; }

// A failed save vs. poison means instant death
inline bool mm2tuvTwilightBloomSapDeadly()
    { return true; }

// The flowers exude a very attractive perfume and sweet sap
inline bool mm2tuvTwilightBloomPerfumeLure()
    { return true; }

// ---- the land urchin pins (the R814 MM2 letters TUV walk) ----

// The Urchin, Land xpValue (the print 3 base 150 + 4/hp x avgHp 13)
inline int mm2tuvUrchinLandXpValue()
    { return 202; }

// The Urchin, Land xp level
inline int mm2tuvUrchinLandXpLevel()
    { return 3; }

// The urchin shoots 2-12 spines per round
inline int mm2tuvUrchinSpineMin()
    { return 2; }

// The spines up to 12 (the loader 10)
inline int mm2tuvUrchinSpineMax()
    { return 12; }

// Each spine 1-2 damage
inline int mm2tuvUrchinSpineDamageMax()
    { return 2; }

// The spine poison paralyzes for 6 turns without a save
inline int mm2tuvUrchinParalysisTurns()
    { return 6; }

// The dark gas cloud a 10-foot radius escape aid
inline int mm2tuvUrchinSmokeRadiusFeet()
    { return 10; }

// The 2 small antennae detect movement
inline int mm2tuvUrchinAntennae()
    { return 2; }

// The 5 spindly legs rotate to any direction
inline int mm2tuvUrchinLegs()
    { return 5; }

// The urchin pearls worth 100-600 gp
inline int mm2tuvUrchinPearlMinGp()
    { return 100; }

// The pearl value up to 600 gp
inline int mm2tuvUrchinPearlMaxGp()
    { return 600; }

// Very old urchins up to a dozen pearls
inline int mm2tuvUrchinPearlsMax()
    { return 12; }

// The spine victim saves vs. poison or is paralyzed
inline bool mm2tuvUrchinSpinesParalyze()
    { return true; }

// The urchin releases a dark gas cloud to aid its escape
inline bool mm2tuvUrchinSmokeEscape()
    { return true; }

// ---- the ustilagor pins (the R814 MM2 letters TUV walk) ----

// The Ustilagor xpValue (the print 3 base 135 + 4/hp x avgHp 13)
inline int mm2tuvUstilagorXpValue()
    { return 187; }

// The Ustilagor xp level
inline int mm2tuvUstilagorXpLevel()
    { return 3; }

// The ribbon-like tendrils about 3 feet long
inline int mm2tuvUstilagorTendrilFeet()
    { return 3; }

// The alkaline hit 2-5 plus like damage next round without a save
inline int mm2tuvUstilagorAlkaliMin()
    { return 2; }

// The alkaline damage up to 5
inline int mm2tuvUstilagorAlkaliMax()
    { return 5; }

// Ustilagors have no mind as defined by human standards
inline bool mm2tuvUstilagorMindless()
    { return true; }

// Only a psionic blast will affect an ustilagor in turn
inline bool mm2tuvUstilagorPsionic()
    { return true; }

// ---- the vagabond pins (the R814 MM2 letters TUV walk) ----

// The Vagabond xpValue (the print 0 base Variable + 0/hp x avgHp As form -
// the Variable xp the nil read)
inline int mm2tuvVagabondXpValue()
    { return 0; }

// The Vagabond xp level
inline int mm2tuvVagabondXpLevel()
    { return 0; }

// A vagabond invited along will usually agree (90%)
inline int mm2tuvVagabondJoinPct()
    { return 90; }

// Each enchanted gem carries 3 uses of word of recall
inline int mm2tuvVagabondGemCharges()
    { return 3; }

// Vagabonds are immune to all mental attack or control, save psionics
inline bool mm2tuvVagabondMindImmune()
    { return true; }

// A vagabond has no power to change the form once assumed
inline bool mm2tuvVagabondFormFixed()
    { return true; }

// ---- the vargouille pins (the R814 MM2 letters TUV walk) ----

// The Vargouille xpValue (the print 3 base 118 + 2/hp x avgHp 4)
inline int mm2tuvVargouilleXpValue()
    { return 126; }

// The Vargouille xp level
inline int mm2tuvVargouilleXpLevel()
    { return 3; }

// The vargouille bite 1-4 lost forever without a save vs. poison
inline int mm2tuvVargouilleBiteMax()
    { return 4; }

// The vargouille size S (3' wingspread)
inline int mm2tuvVargouilleWingspreadFeet()
    { return 3; }

// Bite damage is lost permanently, restorable only by a wish
inline bool mm2tuvVargouillePermanentDrain()
    { return true; }

// Vargouilles attack torches, shun bright light, are blinded by day
inline bool mm2tuvVargouilleHatesLight()
    { return true; }

// ---- the vegepygmy pins (the R814 MM2 letters TUV walk) ----

// The Vegepygmy xpValue (the print 3 base 53 + 1/hp x avgHp 3)
inline int mm2tuvVegepygmyXpValue()
    { return 56; }

// The Vegepygmy xp level
inline int mm2tuvVegepygmyXpLevel()
    { return 3; }

// Color-matched vegepygmies surprise 50% of the time
inline int mm2tuvVegepygmySurprisePct()
    { return 50; }

// Piercing weapons do only 1 point of damage to vegepygmies
inline int mm2tuvVegepygmyPiercingDamage()
    { return 1; }

// A 40% chance of 1-3 shriekers guarding the lair
inline int mm2tuvVegepygmyShriekerPct()
    { return 40; }

// The shrieker guards 1-3
inline int mm2tuvVegepygmyShriekerMin()
    { return 1; }

// The shriekers up to 3
inline int mm2tuvVegepygmyShriekerMax()
    { return 3; }

// A 70% chance of russet mold near the lair
inline int mm2tuvVegepygmyRussetMoldPct()
    { return 70; }

// One subchief (5 HD) for every 50 vegepygmies
inline int mm2tuvVegepygmySubchiefPer()
    { return 50; }

// The subchief 5 hit dice
inline int mm2tuvVegepygmySubchiefHd()
    { return 5; }

// The subchief bodyguards 2-5
inline int mm2tuvVegepygmySubchiefGuardsMin()
    { return 2; }

// The bodyguards up to 5
inline int mm2tuvVegepygmySubchiefGuardsMax()
    { return 5; }

// The subchief guards 3 hit dice
inline int mm2tuvVegepygmySubchiefGuardHd()
    { return 3; }

// Every band leader 6 hit dice
inline int mm2tuvVegepygmyLeaderHd()
    { return 6; }

// The leader bodyguards 2-8
inline int mm2tuvVegepygmyLeaderGuardsMin()
    { return 2; }

// The leader guards up to 8
inline int mm2tuvVegepygmyLeaderGuardsMax()
    { return 8; }

// The leader guards 4 hit dice
inline int mm2tuvVegepygmyLeaderGuardHd()
    { return 4; }

// The vegepygmy 2-HD ladder rung xp base (the R812 rider precedent)
inline int mm2tuvVegepygmyLadderBase2()
    { return 81; }

// The vegepygmy 2-HD ladder rung xp per hit point
inline int mm2tuvVegepygmyLadderPerHp2()
    { return 2; }

// The vegepygmy 2-HD ladder rung xpValue (the floor formula)
inline int mm2tuvVegepygmyLadderXpValue2()
    { return 95; }

// The vegepygmy 2-HD ladder rung xp level
inline int mm2tuvVegepygmyLadderLevel2()
    { return 3; }

// The vegepygmy 3-HD ladder rung xp base (the R812 rider precedent)
inline int mm2tuvVegepygmyLadderBase3()
    { return 120; }

// The vegepygmy 3-HD ladder rung xp per hit point
inline int mm2tuvVegepygmyLadderPerHp3()
    { return 3; }

// The vegepygmy 3-HD ladder rung xpValue (the floor formula)
inline int mm2tuvVegepygmyLadderXpValue3()
    { return 150; }

// The vegepygmy 3-HD ladder rung xp level
inline int mm2tuvVegepygmyLadderLevel3()
    { return 3; }

// The vegepygmy 4-HD ladder rung xp base (the R812 rider precedent)
inline int mm2tuvVegepygmyLadderBase4()
    { return 175; }

// The vegepygmy 4-HD ladder rung xp per hit point
inline int mm2tuvVegepygmyLadderPerHp4()
    { return 4; }

// The vegepygmy 4-HD ladder rung xpValue (the floor formula)
inline int mm2tuvVegepygmyLadderXpValue4()
    { return 231; }

// The vegepygmy 4-HD ladder rung xp level
inline int mm2tuvVegepygmyLadderLevel4()
    { return 4; }

// The vegepygmy 5-HD ladder rung xp base (the R812 rider precedent)
inline int mm2tuvVegepygmyLadderBase5()
    { return 245; }

// The vegepygmy 5-HD ladder rung xp per hit point
inline int mm2tuvVegepygmyLadderPerHp5()
    { return 5; }

// The vegepygmy 5-HD ladder rung xpValue (the floor formula)
inline int mm2tuvVegepygmyLadderXpValue5()
    { return 330; }

// The vegepygmy 5-HD ladder rung xp level
inline int mm2tuvVegepygmyLadderLevel5()
    { return 4; }

// The vegepygmy 6-HD ladder rung xp base (the R812 rider precedent)
inline int mm2tuvVegepygmyLadderBase6()
    { return 425; }

// The vegepygmy 6-HD ladder rung xp per hit point
inline int mm2tuvVegepygmyLadderPerHp6()
    { return 6; }

// The vegepygmy 6-HD ladder rung xpValue (the floor formula)
inline int mm2tuvVegepygmyLadderXpValue6()
    { return 551; }

// The vegepygmy 6-HD ladder rung xp level
inline int mm2tuvVegepygmyLadderLevel6()
    { return 5; }

// Electrical attacks do no damage to vegepygmies
inline bool mm2tuvVegepygmyElectricImmune()
    { return true; }

// Vegepygmies are immune to charm/enchantment spells except plant-affecting
inline bool mm2tuvVegepygmyCharmImmune()
    { return true; }

// ---- the verme pins (the R814 MM2 letters TUV walk) ----

// The Verme xpValue (the print 9 base 8550 + 25/hp x avgHp 81)
inline int mm2tuvVermeXpValue()
    { return 10575; }

// The Verme xp level
inline int mm2tuvVermeXpLevel()
    { return 9; }

// Swallowing occurs on any hit if prey is not more than 12 feet tall
inline int mm2tuvVermeSwallowHeightFeet()
    { return 12; }

// The swallowing process damage 3d8+4 (max 28)
inline int mm2tuvVermeSwallowMax()
    { return 28; }

// Swallowed creatures take 2-16 additional damage per round
inline int mm2tuvVermeSwallowRoundMin()
    { return 2; }

// The round damage up to 16
inline int mm2tuvVermeSwallowRoundMax()
    { return 16; }

// Any swallowed being will be dissolved in 6 rounds
inline int mm2tuvVermeDissolveRounds()
    { return 6; }

// Edged weapons inflict but 1 point of damage per blow
inline int mm2tuvVermeEdgedDamage()
    { return 1; }

// The verme swallows prey whole, even one as large as a water buffalo
inline bool mm2tuvVermeSwallowsWhole()
    { return true; }

// The thick slime-covered scales make edged weapons useless
inline bool mm2tuvVermeEdgedUseless()
    { return true; }

// Fire-based attacks cause only one-half damage unless internal
inline bool mm2tuvVermeFireHalf()
    { return true; }

// ---- the vilstrak pins (the R814 MM2 letters TUV walk) ----

// The Vilstrak (Marl Mugger, Tunnel Thug) xpValue (the print 1 base 7 + 1/hp
// x avgHp 6)
inline int mm2tuvVilstrakXpValue()
    { return 13; }

// The Vilstrak (Marl Mugger, Tunnel Thug) xp level
inline int mm2tuvVilstrakXpLevel()
    { return 1; }

// Vilstraks are 75% undetectable even at 20-foot distance
inline int mm2tuvVilstrakUndetectablePct()
    { return 75; }

// The merge detection 20-foot distance
inline int mm2tuvVilstrakDetectFeet()
    { return 20; }

// Sometimes (5%) a vilstrak den can be detected and broken into
inline int mm2tuvVilstrakBadLairPct()
    { return 5; }

// A vilstrak can physically merge with earth or stone
inline bool mm2tuvVilstrakMergesWithStone()
    { return true; }

// The vilstrak surprise on a 1-4
inline bool mm2tuvVilstrakSurpriseOneToFour()
    { return true; }

// ---- the vulchling pins (the R814 MM2 letters TUV walk) ----

// The Vulchling xpValue (the print 1 base 10 + 1/hp x avgHp 3)
inline int mm2tuvVulchlingXpValue()
    { return 13; }

// The Vulchling xp level
inline int mm2tuvVulchlingXpLevel()
    { return 1; }

// The vulchling lair 0-9 eggs
inline int mm2tuvVulchlingEggsMin()
    { return 0; }

// The eggs up to 9
inline int mm2tuvVulchlingEggsMax()
    { return 9; }

// Vulchlings consort with harpies or even Type I demons at times
inline bool mm2tuvVulchlingConsortsWithHarpies()
    { return true; }

// The vulchling swoops with extended talons then hops to the beak
inline bool mm2tuvVulchlingTalonSwoop()
    { return true; }

// ---- the vulture pins (the R814 MM2 letters TUV walk) ----

// The Vulture, Giant xpValue (the print 1 base 20 + 2/hp x avgHp 8)
inline int mm2tuvVultureGiantXpValue()
    { return 36; }

// The Vulture, Giant xp level
inline int mm2tuvVultureGiantXpLevel()
    { return 1; }

// Vultures appear 7-12 rounds after a creature is felled
inline int mm2tuvVultureArrivalMinRounds()
    { return 7; }

// The arrival up to 12 rounds
inline int mm2tuvVultureArrivalMaxRounds()
    { return 12; }

// If combatants are not within 20 feet the vultures alight and peck
inline int mm2tuvVulturePeckingFeet()
    { return 20; }

// The pecking vultures 1-6 per round
inline int mm2tuvVulturePeckersMin()
    { return 1; }

// The peckers up to 6
inline int mm2tuvVulturePeckersMax()
    { return 6; }

// The giant vulture L (12' + wingspread)
inline int mm2tuvVultureGiantWingspreadFeet()
    { return 12; }

// The Vulture, Ordinary xpValue (the print 2 base 35 + 0/hp x avgHp 4)
inline int mm2tuvVultureOrdinaryXpValue()
    { return 35; }

// The Vulture, Ordinary xp level
inline int mm2tuvVultureOrdinaryXpLevel()
    { return 2; }

// The ordinary vulture M (5'-6' + wingspread)
inline int mm2tuvVultureOrdinaryWingspreadMinFeet()
    { return 5; }

// The ordinary wingspread up to 6 feet
inline int mm2tuvVultureOrdinaryWingspreadMaxFeet()
    { return 6; }

// Giant vultures must actually be struck to drive them off
inline bool mm2tuvVultureGiantStruckToDeter()
    { return true; }

// Ordinary vultures move out of range and wait for the victim to weaken
inline bool mm2tuvVultureOrdinaryWaitsForWeakness()
    { return true; }

// ---- the TUVStats grid pins (the R814 MM2 letters TUV walk) ----

// The armor class cells (the tarrasque -3 the UNQUOTED number read - the
// phoenix precedent; the tasloi 6 (5), the termite 2/10 and 2/8 head/body and
// the verme 3 (head) the first-int reads; the ordinary vulture 6 the
// capture-wins read against the transcription 7; the vagabond As form the 9
// default - the shade precedent)
inline int mm2tuvTUVStatAc(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return 6;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 7;
        case 12:
            return 9;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 8;
        case 16:
            return 3;
        case 17:
            return 5;
        case 18:
            return 9;
        case 19:
            return 8;
        case 20:
            return 4;
        case 21:
            return 3;
        case 22:
            return 2;
        case 23:
            return 7;
        case 24:
            return 7;
        case 25:
            return 6;
        default:
            return 0;
        }
    }

// The hit dice num cells (the tarrasque and vilstrak the flat-hp path - hdNum
// 0, avgHp the print hp: 300 and 6 the high-end; the thunder beast 4-9,
// +1/die and the time elemental 12 or 16 (20) the first-number reads; the
// vegepygmy 1 to 6 the low-end read; the transposer 6 (up to 48 hp) the 6
// read; the vagabond As form the 0 read)
inline int mm2tuvTUVStatHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 12;
        case 7:
            return 6;
        case 8:
            return 4;
        case 9:
            return 12;
        case 10:
            return 7;
        case 11:
            return 6;
        case 12:
            return 2;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 18;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the verme 18+18 the +18; the termite king 6+6 and
// queen 8+8; the scrag saltwater 6+12 the capture-wins read against the
// transcription 5+12)
inline int mm2tuvTUVStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 8;
        case 13:
            return 5;
        case 14:
            return 12;
        case 15:
            return 8;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 18;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x hd + bonus) formula; the flat-hp reads
// carry the print hp: the tarrasque 300, the vilstrak 6 the high-end read -
// the scum creeper precedent; the vagabond the nil block 0 - the phantom
// precedent)
inline int mm2tuvTUVStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 9;
        case 4:
            return 27;
        case 5:
            return 36;
        case 6:
            return 42;
        case 7:
            return 24;
        case 8:
            return 15;
        case 9:
            return 42;
        case 10:
            return 24;
        case 11:
            return 21;
        case 12:
            return 15;
        case 13:
            return 22;
        case 14:
            return 33;
        case 15:
            return 18;
        case 16:
            return 13;
        case 17:
            return 13;
        case 18:
            return 0;
        case 19:
            return 4;
        case 20:
            return 3;
        case 21:
            return 81;
        case 22:
            return 6;
        case 23:
            return 3;
        case 24:
            return 8;
        case 25:
            return 4;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the land urchin 2-12 the 10 clamp,
// the tasloi 2 or 1, the thri-kreen 5 or 3 and the vulchling 1 or 2 the max
// reads, the thessalhydra Up to 10 the 10 read, the tri-flower and twilight
// bloom See below and the vagabond As form the 1 floor)
inline int mm2tuvTUVStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 10;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 10;
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
            return 2;
        case 23:
            return 2;
        case 24:
            return 1;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// The xp base cells (the vagabond Variable the 0 read - the phantom
// precedent; the transposer 625 the capture-wins read against the
// transcription 525; the thessalhydra 5800 the 5S00 capture read; the
// ordinary vulture II/35 with no per-hp)
inline int mm2tuvTUVStatXp(int b)
    {
        switch (b) {
        case 0:
            return 37500;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 50;
        case 4:
            return 500;
        case 5:
            return 900;
        case 6:
            return 5800;
        case 7:
            return 800;
        case 8:
            return 650;
        case 9:
            return 3000;
        case 10:
            return 350;
        case 11:
            return 625;
        case 12:
            return 120;
        case 13:
            return 400;
        case 14:
            return 900;
        case 15:
            return 125;
        case 16:
            return 150;
        case 17:
            return 135;
        case 18:
            return 0;
        case 19:
            return 118;
        case 20:
            return 53;
        case 21:
            return 8550;
        case 22:
            return 7;
        case 23:
            return 10;
        case 24:
            return 20;
        case 25:
            return 35;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the vegepygmy 1-6 ladder the 1/hp low rung; the
// ordinary vulture the 0 read; the verme 25 and the time elemental 20 the
// highest letter-TUV rates)
inline int mm2tuvTUVStatXpHp(int b)
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
            return 10;
        case 5:
            return 13;
        case 6:
            return 16;
        case 7:
            return 8;
        case 8:
            return 10;
        case 9:
            return 20;
        case 10:
            return 8;
        case 11:
            return 7;
        case 12:
            return 3;
        case 13:
            return 8;
        case 14:
            return 12;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 0;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 25;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 0;
        default:
            return 0;
        }
    }

// The lair percent cells (the bare-numeral read - the R812 repair lesson; the
// ustilagor 90 and vargouille 80 the highest letter-TUV rates; the tarrasque
// See below the 0 read; the vagabond 0)
inline int mm2tuvTUVStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 30;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 50;
        case 7:
            return 5;
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
            return 20;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 90;
        case 18:
            return 0;
        case 19:
            return 80;
        case 20:
            return 40;
        case 21:
            return 0;
        case 22:
            return 5;
        case 23:
            return 25;
        case 24:
            return 0;
        case 25:
            return 0;
        default:
            return 0;
        }
    }

// The move cells (the walking-rate first-int read: the vultures 3"/24" and
// 3"/27", the scrags 3"/15" and 3"/12" the 3 reads, the vargouille /12" the
// flight-rate 12 read, the thunder beast 9" (18" charge) the 9 read; the
// tri-flower and twilight bloom Nil the 0 reads; the vagabond As form the 0
// read)
inline int mm2tuvTUVStatMove(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 9;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 6;
        case 5:
            return 3;
        case 6:
            return 12;
        case 7:
            return 18;
        case 8:
            return 9;
        case 9:
            return 1;
        case 10:
            return 20;
        case 11:
            return 15;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 0;
        case 16:
            return 12;
        case 17:
            return 9;
        case 18:
            return 0;
        case 19:
            return 12;
        case 20:
            return 12;
        case 21:
            return 18;
        case 22:
            return 9;
        case 23:
            return 6;
        case 24:
            return 3;
        case 25:
            return 3;
        default:
            return 0;
        }
    }

// The magic resistance cells (every Standard, See below, As form and Special,
// see below read 0 - no letter-TUV def carries an innate percent)
inline int mm2tuvTUVStatMr(int b)
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
        default:
            return 0;
        }
    }

}   // namespace rules
