// =========================================================================================
// Adnd1 - rules/mm2bc.h
// THE MM2 LETTERS B AND C - the thirty-seven printed B and C entries, the six
// form splits, promoted to the live registry
// census 720 -> 721.
//
// Round two of the MM2 arc, the first MULTI-LETTER pass (the user call after
// the R797 letter-A shakedown: the arc does not run A to Z one letter at a
// time - the letters B and C walk together in one round). The capture is the
// Curtiss PDF upload (pp. 12-27, the full B and C sections) cross-checked
// against an independent transcription, the contested cells settled: the
// behemoth 1800 + 15/hp (the capture primary), the cloaker 6/hp (the
// book-internal tie - the flat-6-HD boggart and slicer beetle both print
// 6/hp), the bumblebee queen 8+6 (the capture hyphen is a plus misread), the
// cave moray roman II, the domestic cat move 5 inches. The pin-time walk
// finds twenty-two B entries (pp. 12-21) and fifteen C entries (pp. 22-27);
// the bat, bee, beetle, cat and centipede entries split two or three ways, so
// forty-three .lua defs ride the R791 data_files extension, registry 491 ->
// 534. The stat blocks pin in the 26-row B grid and the 17-row C grid; the
// barghest growth brackets, the barkburr ladder, the bloodthorn attack-data
// bands and the cat lord summon bands pin as printed grids. The battery
// census reads loaded 534, errors 0. REPAIR (the landing run's one bad, the
// R639 flow): the R797 letter-A walk pinned the live registry census == 491
// and this round's 43 defs grew it to 534, so the stale check read bad 1 and
// its early return truncated the battery into the R797-class census cascade
// (the wave was pure cascade - every label printing after the walk). Both
// walks now read the registry census as a FLOOR (fail only below the landing
// count), so later letter rounds cannot re-break a landed walk; the exact
// census stays pinned by the header consts and the audit mirror.
//
namespace rules {

// ---- the MM2 letters B and C round pins (the R798 census) ----

// The MM2 letters B and C round: the first multi-letter pass of the MM2 arc
// (the user call after the A shakedown - not letter-by-letter)
inline int mm2bcRound()
    { return 798; }

// The pin-time B walk from the print (pp. 12-21): baku, banderlog, barghest,
// barkburr, basidirond, basilisk greater, bat, fire bat, northern bear, bee,
// beetle, behemoth, behir, bloodthorn, boalisk, bodak, boggart, boggle,
// boobrie, bookworm, bowler, buckawn
inline int mm2bcBEntryCount()
    { return 22; }

// The pin-time C walk from the print (pp. 22-27): cat, cat lord, giant
// catfish, cave cricket, cave fisher, cave moray, centipede, cheetah, choke
// creeper, cloaker, cooshee, giant crane, crysmal, crystal ooze, cyclopskin
inline int mm2bcCEntryCount()
    { return 15; }

// The two letters walk together: the 22 B entries plus the 15 C entries in
// one round
inline int mm2bcEntryCount()
    { return 37; }

// The form splits beyond the entries: the bee rides three defs, the bat, cat,
// beetle and centipede each ride two
inline int mm2bcExtraFormDefs()
    { return 6; }

// The promoted def census: the 37 entries plus the 6 extra form defs, all
// through the R791 data_files extension
inline int mm2bcDefCount()
    { return 43; }

// The B def census: 22 entries plus the ordinary bat, the soldier and
// bumblebee bees, and the slicer beetle
inline int mm2bcBDefCount()
    { return 26; }

// The C def census: 15 entries plus the wild cat and the megalo-centipede
inline int mm2bcCDefCount()
    { return 17; }

// The first B print page
inline int mm2bcBFirstPage()
    { return 12; }

// The last B print page
inline int mm2bcBLastPage()
    { return 21; }

// The first C print page
inline int mm2bcCFirstPage()
    { return 22; }

// The last C print page
inline int mm2bcCLastPage()
    { return 27; }

// The registry census before the round (the R797 letter-A landing)
inline int mm2bcRegistryBefore()
    { return 491; }

// The registry census after the round: 491 + 43 defs
inline int mm2bcRegistryAfter()
    { return 534; }

// The B stat grid rows: every promoted B def in print order
inline int mm2bcBStatRows()
    { return 26; }

// The C stat grid rows: every promoted C def in print order
inline int mm2bcCStatRows()
    { return 17; }

// The barghest growth brackets: hit dice 6+6 through 12+12
inline int mm2bcBarghestBracketRows()
    { return 7; }

// The barkburr hit-dice ladder: 1 through 6
inline int mm2bcBarkburrLadderRows()
    { return 6; }

// The bloodthorn size bands of its attack-data table
inline int mm2bcBloodthornRows()
    { return 3; }

// The cat lord feline summon bands: 01-07 through 71-00
inline int mm2bcFelineSummonRows()
    { return 9; }

// The cat lord human-form summon bands: 01-15 through 46-00
inline int mm2bcHumanSummonRows()
    { return 4; }

// The round carries TWO letters - the user-set multi-letter rule after the
// R797 shakedown: the arc never runs letter-by-letter, and the scope past A
// is Curtiss's call each round
inline bool mm2bcMultiLetterPass()
    { return true; }

// The bat entry splits two ways: the mobat and the ordinary bat (the print's
// own sub-entries)
inline bool mm2bcBatRidesTwoDefs()
    { return true; }

// The bee entry splits three ways: worker, soldier and bumblebee (the oni
// precedent)
inline bool mm2bcBeeRidesThreeDefs()
    { return true; }

// The beetle entry splits two ways: the death watch and the slicer
inline bool mm2bcBeetleRidesTwoDefs()
    { return true; }

// The cat entry splits two ways: the domestic and the wild cat
inline bool mm2bcCatRidesTwoDefs()
    { return true; }

// The centipede entry splits two ways: the huge and the megalo
inline bool mm2bcCentipedeRidesTwoDefs()
    { return true; }

// The behemoth LEVEL/X.P. prints VII/1800 + 15/hp - the capture read; the
// independent transcription's 1600 is its own misread (the capture is
// primary)
inline bool mm2bcBehemothXpSettledFromCapture()
    { return true; }

// The cloaker xp/hp settles at 6 by the book-internal tie: the flat-6-HD
// boggart and slicer beetle both print 6/hp (the independent transcription's
// 8 is its misread)
inline bool mm2bcCloakerXpHpSettledBookInternal()
    { return true; }

// The bumblebee nest queen prints 8+6 hit dice - the capture's 8-6 hyphen is
// the plus misread
inline bool mm2bcBeeQueenHdIs8Plus6()
    { return true; }

// The cave moray LEVEL/X.P. carries the roman II (the capture dropped the
// level; the 130 + 5/hp cells read as printed)
inline bool mm2bcCaveMorayXpLevelIsII()
    { return true; }

// The domestic cat MOVE prints 5 inches - the capture table cell (the
// independent transcription's 15 inches carries its own editor noise)
inline bool mm2bcCatDomesticMoveIsFive()
    { return true; }

// The cyclopskin alignment prints "Chaotic - chaotic evil" verbatim (both
// sources agree; the def carries the print)
inline bool mm2bcCyclopskinAlignPrintedVerbatim()
    { return true; }

// The mm2_print xp source rides the R797 xp-audit allowed-source list - no
// xp-audit patch this round
inline bool mm2bcMm2PrintRidesXpAudit()
    { return true; }

// The 43 defs ride the R791 data_files extension (the engine writes them;
// idempotent by existence)
inline bool mm2bcDefsRideDataFiles()
    { return true; }

// The mm2bc pin header stays the print-fidelity record beside the live defs
// (the promotion-seam doctrine)
inline bool mm2bcPinHeaderStaysPrintRecord()
    { return true; }

// ---- the baku pins (the R798 MM2 letters BC) ----

// The baku group size low end (semi-tropical forests)
inline int mm2bcBakuGroupMin()
    { return 2; }

// The baku group size high end
inline int mm2bcBakuGroupMax()
    { return 5; }

// The prehensile trunk length in feet
inline int mm2bcBakuTrunkFt()
    { return 4; }

// The trumpeting roar damage low end
inline int mm2bcBakuRoarDmgMin()
    { return 1; }

// The trumpeting roar damage high end
inline int mm2bcBakuRoarDmgMax()
    { return 8; }

// The roar effect radius in inches
inline int mm2bcBakuRoarRadiusIn()
    { return 4; }

// The roar fires only once every 4 melee rounds
inline int mm2bcBakuRoarCooldown()
    { return 4; }

// The roar panic reads as a fear spell from a 12th-level magic-user
inline int mm2bcBakuFearLevel()
    { return 12; }

// The baku psionic score (with 2-24 bonus points)
inline int mm2bcBakuPsionicScore()
    { return 180; }

// A baku turns invisible at will and holds the dweomer until it acts
inline bool mm2bcBakuInvisibleAtWill()
    { return true; }

// A baku travels both ethereally and astrally
inline bool mm2bcBakuEtherealAndAstral()
    { return true; }

// The two foreleg stomps land only on man-size or smaller foes
inline bool mm2bcBakuStompManSizeOnly()
    { return true; }

// Evil creatures save vs. paralyzation or flee in panic
inline bool mm2bcBakuRoarSaveOrFlee()
    { return true; }

// Baku hate evil and abandon their timid nature to fight malicious monsters
inline bool mm2bcBakuHatesEvil()
    { return true; }

// ---- the banderlog pins (the R798 MM2 letters BC) ----

// The chance the banderlog carry no possessions
inline int mm2bcBanderlogNoGearPct()
    { return 95; }

// The coconut/globe missile damage low end
inline int mm2bcBanderlogMissileDmgMin()
    { return 2; }

// The missile damage high end
inline int mm2bcBanderlogMissileDmgMax()
    { return 5; }

// The missile range in feet
inline int mm2bcBanderlogMissileRangeFt()
    { return 30; }

// The canine bite damage low end
inline int mm2bcBanderlogBiteDmgMin()
    { return 2; }

// The canine bite damage high end
inline int mm2bcBanderlogBiteDmgMax()
    { return 5; }

// The leader-male hit points per die low end
inline int mm2bcBanderlogLeaderHpPerDieMin()
    { return 6; }

// The leader-male hit points per die high end
inline int mm2bcBanderlogLeaderHpPerDieMax()
    { return 8; }

// Banderlog throw coconuts or retch-plant globes as missiles
inline bool mm2bcBanderlogCoconutMissiles()
    { return true; }

// Bands are always led by one or more large males
inline bool mm2bcBanderlogLedByLargeMales()
    { return true; }

// Banderlog speak a simple language of their own
inline bool mm2bcBanderlogOwnLanguage()
    { return true; }

// ---- the barghest pins (the R798 MM2 letters BC) ----

// The whelp litter sent to the Prime Material Plane
inline int mm2bcBarghestLitterSize()
    { return 6; }

// Hit points gained per energy level devoured
inline int mm2bcBarghestHpPerLevel()
    { return 1; }

// Eight devoured levels effectively give another hit die
inline int mm2bcBarghestLevelsPerHitDie()
    { return 8; }

// The strength ladder low end (18/00 at landing)
inline int mm2bcBarghestStrLo()
    { return 18; }

// The strength ladder high end (full growth)
inline int mm2bcBarghestStrHi()
    { return 24; }

// The canine-form move ceiling in inches (double normal)
inline int mm2bcBarghestCanineMoveMax()
    { return 30; }

// The canine-form chance to be unnoticed when motionless
inline int mm2bcBarghestUnnoticedPct()
    { return 75; }

// The canine-form surprise chance (3 in 6)
inline int mm2bcBarghestCanineSurprisePct()
    { return 50; }

// The chance a canine-form barghest is indistinguishable from a dog
inline int mm2bcBarghestDogTellFailPct()
    { return 95; }

// A barghest assumes large dog form at will
inline bool mm2bcBarghestAssumesCanineForm()
    { return true; }

// Only +1 or better magic weapons hit a barghest
inline bool mm2bcBarghestHitOnlyByPlusOne()
    { return true; }

// Fire does absolutely no damage to a barghest
inline bool mm2bcBarghestFireDoesNoDamage()
    { return true; }

// A failed save vs. magical fire in canine form hurls it back to Gehenna
inline bool mm2bcBarghestFireFailReturnsHome()
    { return true; }

// Goblin hosts recognize, worship and serve barghests
inline bool mm2bcBarghestWorshippedByGoblins()
    { return true; }

// The at-will spell-like magic works one operation per round
inline bool mm2bcBarghestAtWillMagicOnePerRound()
    { return true; }

// The charm, dimension door and emotion powers work once per day
inline bool mm2bcBarghestDailyMagicOncePerDay()
    { return true; }

// ---- the barkburr pins (the R798 MM2 letters BC) ----

// The woody carapace armor class
inline int mm2bcBarkburrCarapaceAC()
    { return 0; }

// The soft underside armor class
inline int mm2bcBarkburrUndersideAC()
    { return 8; }

// The anti-forest-act detection radius in miles
inline int mm2bcBarkburrSenseRadiusMiles()
    { return 1; }

// The leap range in feet
inline int mm2bcBarkburrLeapRangeFt()
    { return 20; }

// The druid/ranger recognition chance base (plus 1% per level)
inline int mm2bcBarkburrIdBasePct()
    { return 4; }

// The barbed tube inflicts 1 point of damage
inline int mm2bcBarkburrTubeDmg()
    { return 1; }

// The attach routine resolves as a single attack by a 6-HD monster
inline int mm2bcBarkburrTreatedAsHd()
    { return 6; }

// The poison injection base duration (2 rounds plus 1 per hit die)
inline int mm2bcBarkburrInjectBaseRounds()
    { return 2; }

// The lignification transformation takes 1 turn
inline int mm2bcBarkburrLignifyTurns()
    { return 1; }

// The gear-absorption low end in hours
inline int mm2bcBarkburrAbsorbHoursMin()
    { return 2; }

// The gear-absorption high end in hours
inline int mm2bcBarkburrAbsorbHoursMax()
    { return 7; }

// The cumulative per-round chance fire dislodges a barkburr
inline int mm2bcBarkburrFireDislodgePct()
    { return 15; }

// The sideways-removal tear damage low end
inline int mm2bcBarkburrSidewaysDmgMin()
    { return 1; }

// The sideways-removal tear damage high end
inline int mm2bcBarkburrSidewaysDmgMax()
    { return 10; }

// At most 3 people can pull a barkburr sideways
inline int mm2bcBarkburrRemovalHelpers()
    { return 3; }

// The neutralize poison base chance (plus 5% per caster level)
inline int mm2bcBarkburrNeutralizeBasePct()
    { return 30; }

// The treant final-form hit dice (81-90 on the table)
inline int mm2bcBarkburrTreantFormHd()
    { return 7; }

// The ordinary-tree final form (01-50)
inline int mm2bcBarkburrFormTreeMaxPct()
    { return 50; }

// The adult badger final form low roll
inline int mm2bcBarkburrFormBadgerLo()
    { return 51; }

// The adult badger final form high roll
inline int mm2bcBarkburrFormBadgerHi()
    { return 70; }

// The adult giant weasel final form low roll
inline int mm2bcBarkburrFormWeaselLo()
    { return 71; }

// The adult giant weasel final form high roll
inline int mm2bcBarkburrFormWeaselHi()
    { return 80; }

// The treant final form low roll
inline int mm2bcBarkburrFormTreantLo()
    { return 81; }

// The treant final form high roll
inline int mm2bcBarkburrFormTreantHi()
    { return 90; }

// The druid final form low roll (1st level, W 14, Ch 16)
inline int mm2bcBarkburrFormDruidMin()
    { return 91; }

// Add 10 to the final-form roll for a neutral alignment component
inline int mm2bcBarkburrNeutralComponentAdjust()
    { return 10; }

// Add 20 to the final-form roll for true neutral creatures
inline int mm2bcBarkburrTrueNeutralAdjust()
    { return 20; }

// The ordinary-tree final form grows to full size within 3 months
inline int mm2bcBarkburrTreeGrowMonths()
    { return 3; }

// The chance a 6-HD barkburr carries budding offspring
inline int mm2bcBarkburrOffspringChancePct()
    { return 50; }

// The budding offspring hit dice (1-2 of them)
inline int mm2bcBarkburrOffspringHd()
    { return 2; }

// Barkburrs are always encountered in their lair
inline bool mm2bcBarkburrAlwaysInLair()
    { return true; }

// Its camouflage gains surprise unless recognized (druid/ranger only)
inline bool mm2bcBarkburrAlwaysSurprises()
    { return true; }

// Each injection round demands a save vs. poison or lignification sets in
inline bool mm2bcBarkburrLignifySaveEachRound()
    { return true; }

// Once started the transformation does not cease, even if the barkburr dies
inline bool mm2bcBarkburrLignifyCannotBeStopped()
    { return true; }

// No minds as such - charm monster and sleep are useless
inline bool mm2bcBarkburrImmuneToMindSpells()
    { return true; }

// Only a full wish restores a completed transformation
inline bool mm2bcBarkburrWishRestoresAfterComplete()
    { return true; }

// The direburr variant always ends as a dead tree no wish can restore
inline bool mm2bcBarkburrDireburrAlwaysDeadTree()
    { return true; }

// ---- the basidirond pins (the R798 MM2 letters BC) ----

// The cap-lash damage low end
inline int mm2bcBasidirondSporeDmgMin()
    { return 2; }

// The cap-lash damage high end
inline int mm2bcBasidirondSporeDmgMax()
    { return 8; }

// The smothering low end in rounds (cure disease stops it)
inline int mm2bcBasidirondSmotherRoundsMin()
    { return 2; }

// The smothering high end in rounds
inline int mm2bcBasidirondSmotherRoundsMax()
    { return 5; }

// The hallucinatory cloud radius low end in inches
inline int mm2bcBasidirondCloudRadiusMinIn()
    { return 20; }

// The hallucinatory cloud radius high end in inches
inline int mm2bcBasidirondCloudRadiusMaxIn()
    { return 35; }

// The hallucination persists after leaving the cloud, low end
inline int mm2bcBasidirondHallucinateRoundsMin()
    { return 1; }

// The hallucination after-effect high end
inline int mm2bcBasidirondHallucinateRoundsMax()
    { return 4; }

// The hallucination effect table runs on 1d8
inline int mm2bcBasidirondHallucinationD8()
    { return 8; }

// The hallucinatory spores emit only while standing quietly
inline bool mm2bcBasidirondSporesOnlyWhenStill()
    { return true; }

// Creatures in the cloud save vs. poison each round or hallucinate
inline bool mm2bcBasidirondHallucinationSavesEachRound()
    { return true; }

// No mind by human standards - charm and hold are useless
inline bool mm2bcBasidirondImmuneToMentalAttacks()
    { return true; }

// Cold does no damage but slows the monster to half movement
inline bool mm2bcBasidirondColdSlowsToHalf()
    { return true; }

// A cold-based attack prevents spore attacks
inline bool mm2bcBasidirondColdBlocksSpores()
    { return true; }

// ---- the basilisk greater pins (the R798 MM2 letters BC) ----

// The petrifying gaze range in feet
inline int mm2bcBasiliskGreaterGazeRangeFt()
    { return 50; }

// The nearsighted self-gaze range in feet
inline int mm2bcBasiliskGreaterNearsightFt()
    { return 10; }

// The reflected-gaze self-petrify chance within 10 feet
inline int mm2bcBasiliskGreaterReflectPct()
    { return 10; }

// The weak claw poison saves at +4
inline int mm2bcBasiliskGreaterClawSaveBonus()
    { return 4; }

// The poisonous breath exposure radius in feet
inline int mm2bcBasiliskGreaterBreathRangeFt()
    { return 5; }

// The breath poison saves at +2
inline int mm2bcBasiliskGreaterBreathSaveBonus()
    { return 2; }

// The gaze turns its victims to stone
inline bool mm2bcBasiliskGreaterGazeTurnsToStone()
    { return true; }

// A failed save vs. the foul breath kills on exposure
inline bool mm2bcBasiliskGreaterBreathKills()
    { return true; }

// The greater basilisk sees into the Astral and Ethereal Planes
inline bool mm2bcBasiliskGreaterSeesAstralEthereal()
    { return true; }

// Its normal habitat is said to be the Elemental Plane of Earth
inline bool mm2bcBasiliskGreaterHabitatEarth()
    { return true; }

// ---- the bat pins (the R798 MM2 letters BC) ----

// The mobat wingspread low end in feet
inline int mm2bcMobatWingspreadMinFt()
    { return 12; }

// The mobat wingspread high end in feet
inline int mm2bcMobatWingspreadMaxFt()
    { return 16; }

// The mobat flying surprise chance
inline int mm2bcMobatSurprisePct()
    { return 50; }

// The piercing screech effective radius in feet
inline int mm2bcMobatScreechRadiusFt()
    { return 20; }

// The mobile airborne mobat armor class
inline int mm2bcMobatFlyingAC()
    { return 2; }

// The crowded-flight armor class
inline int mm2bcMobatCrowdedAC()
    { return 7; }

// The out-of-air armor class
inline int mm2bcMobatGroundAC()
    { return 10; }

// The ordinary bat armor class in fine flying conditions
inline int mm2bcBatFineFlightAC()
    { return 4; }

// The ordinary bat grounded armor class
inline int mm2bcBatGroundAC()
    { return 8; }

// The large-cavern swarm ceiling
inline int mm2bcBatCavernMax()
    { return 1000; }

// The screech makes prey cover its ears unless it saves vs. paralysis
inline bool mm2bcMobatScreechSaveVsParalysis()
    { return true; }

// Mobat sonics allow flight through narrow places in total darkness
inline bool mm2bcMobatSonarDarkFlight()
    { return true; }

// The mobat has a dim evil intelligence and a desire for shiny objects
inline bool mm2bcMobatDesiresShinyObjects()
    { return true; }

// Ordinary bats attack only if cornered and forced to
inline bool mm2bcBatAttacksOnlyIfCornered()
    { return true; }

// A startled swarm puts out torches and confuses spell casting
inline bool mm2bcBatSwarmDisruptsCasting()
    { return true; }

// Bat sonar allows flight in total darkness
inline bool mm2bcBatSonarTotalDarkness()
    { return true; }

// ---- the fire bat pins (the R798 MM2 letters BC) ----

// The body length in feet
inline int mm2bcFireBatBodyFt()
    { return 2; }

// The wingspan in feet
inline int mm2bcFireBatWingspanFt()
    { return 4; }

// The attached feed duration in rounds (hit round plus two)
inline int mm2bcFireBatFeedRounds()
    { return 3; }

// The doused attack damage low end
inline int mm2bcFireBatWetDmgMin()
    { return 1; }

// The doused attack damage high end
inline int mm2bcFireBatWetDmgMax()
    { return 4; }

// The minimum cool gallons to douse one fire bat
inline int mm2bcFireBatDouseGallons()
    { return 10; }

// The drying rounds before it can ignite again
inline int mm2bcFireBatDryRounds()
    { return 10; }

// The pack withdraws when it falls below 25% of its starting force
inline int mm2bcFireBatWithdrawPct()
    { return 25; }

// The colony size low end (1 dozen)
inline int mm2bcFireBatColonyMin()
    { return 12; }

// The colony size high end (2 dozen)
inline int mm2bcFireBatColonyMax()
    { return 24; }

// Advanced sonar and infravision detect invisible targets (no penalty)
inline bool mm2bcFireBatDetectsInvisible()
    { return true; }

// Unlike ordinary bats, sunlight does not harm fire bats
inline bool mm2bcFireBatUnharmedBySunlight()
    { return true; }

// Fire bats are allies of fire elementals and never attack them
inline bool mm2bcFireBatAlliedWithFireElementals()
    { return true; }

// Attached fire bats need no further to-hit rolls
inline bool mm2bcFireBatAutoFeedAfterAttach()
    { return true; }

// A dead fire bat returns to the Elemental Plane of Fire and is reborn
inline bool mm2bcFireBatRebornOnHomePlane()
    { return true; }

// The pack splits itself evenly across the victim group
inline bool mm2bcFireBatPackHuntsEvenly()
    { return true; }

// Fire bats glide through hot solutions at flying speed
inline bool mm2bcFireBatGlidesThroughLava()
    { return true; }

// ---- the northern bear pins (the R798 MM2 letters BC) ----

// The paw roll that indicates a hug (18 or better)
inline int mm2bcBearNorthernHugRoll()
    { return 18; }

// The hug damage low end
inline int mm2bcBearNorthernHugDmgMin()
    { return 3; }

// The hug damage high end
inline int mm2bcBearNorthernHugDmgMax()
    { return 18; }

// The fight-past-death low end in rounds
inline int mm2bcBearNorthernFightRoundsMin()
    { return 2; }

// The fight-past-death high end in rounds
inline int mm2bcBearNorthernFightRoundsMax()
    { return 5; }

// It fights on from 0 to -12 hit points; worse damage kills instantly
inline int mm2bcBearNorthernFightToNegative()
    { return 12; }

// An 18+ paw hit becomes a hug with additional damage
inline bool mm2bcBearNorthernHugOnHighRoll()
    { return true; }

// These aggressive animals fight on after being brought below zero
inline bool mm2bcBearNorthernFightsPastZero()
    { return true; }

// ---- the bee pins (the R798 MM2 letters BC) ----

// The hive holds 20 times the rolled workers
inline int mm2bcBeeHiveWorkerMultiple()
    { return 20; }

// The hive soldier low end
inline int mm2bcBeeHiveSoldiersMin()
    { return 3; }

// The hive soldier high end
inline int mm2bcBeeHiveSoldiersMax()
    { return 12; }

// The burrow bumblebee low end
inline int mm2bcBeeNestBumblebeesMin()
    { return 7; }

// The burrow bumblebee high end
inline int mm2bcBeeNestBumblebeesMax()
    { return 12; }

// The noncombatant drone low end
inline int mm2bcBeeHiveDronesMin()
    { return 2; }

// The noncombatant drone high end
inline int mm2bcBeeHiveDronesMax()
    { return 5; }

// The combative bumblebee queen hit dice
inline int mm2bcBeeQueenHdNum()
    { return 8; }

// The queen hit-die bonus (the 8+6 settled read)
inline int mm2bcBeeQueenHdBonus()
    { return 6; }

// The queen sting damage low end
inline int mm2bcBeeQueenStingDmgMin()
    { return 1; }

// The queen sting damage high end
inline int mm2bcBeeQueenStingDmgMax()
    { return 8; }

// Soldier and bumblebee poison saves at -1
inline int mm2bcBeeSoldierSavePenalty()
    { return 1; }

// The queen bumblebee poison saves at -2
inline int mm2bcBeeQueenSavePenalty()
    { return 2; }

// A successful save still inflicts 2-8 points
inline int mm2bcBeeSaveDmgMin()
    { return 2; }

// The successful-save damage high end
inline int mm2bcBeeSaveDmgMax()
    { return 8; }

// A failed save inflicts 5-20 points (plus soldier/queen adjust)
inline int mm2bcBeeFailDmgMin()
    { return 5; }

// The failed-save damage high end
inline int mm2bcBeeFailDmgMax()
    { return 20; }

// The chance royal jelly is found
inline int mm2bcBeeRoyalJellyPct()
    { return 20; }

// The royal jelly potion low end (extra-healing with cure disease)
inline int mm2bcBeeRoyalJellyMin()
    { return 2; }

// The royal jelly potion high end
inline int mm2bcBeeRoyalJellyMax()
    { return 5; }

// The unguent jar low end per royal jelly
inline int mm2bcBeeUnguentJarsMin()
    { return 2; }

// The unguent jar high end
inline int mm2bcBeeUnguentJarsMax()
    { return 5; }

// The unguent preserves a youthful look for up to 1 year
inline int mm2bcBeeUnguentYouthMonths()
    { return 12; }

// The unguent jar price low end on the open market
inline int mm2bcBeeUnguentPriceMinGp()
    { return 3000; }

// The unguent jar price high end
inline int mm2bcBeeUnguentPriceMaxGp()
    { return 8000; }

// The honeybee hive queen and drones are noncombatant
inline bool mm2bcBeeQueenNoncombatantInHive()
    { return true; }

// The bumblebee nest queen is combative (8+6 hit dice)
inline bool mm2bcBeeQueenCombativeInNest()
    { return true; }

// Bee "bread" is excellent food equal to iron rations
inline bool mm2bcBeeBreadEqualsIronRations()
    { return true; }

// Continual unguent use keeps charisma unaffected by age
inline bool mm2bcBeeUnguentPreservesCharisma()
    { return true; }

// ---- the beetle pins (the R798 MM2 letters BC) ----

// The death vibration radius in feet (save vs. death magic or die)
inline int mm2bcDeathWatchVibrationRadiusFt()
    { return 30; }

// The vibration damage on a successful save, low end
inline int mm2bcDeathWatchSaveDmgMin()
    { return 5; }

// The vibration save damage high end
inline int mm2bcDeathWatchSaveDmgMax()
    { return 20; }

// The clicking cooldown low end in hours
inline int mm2bcDeathWatchClickCooldownMinH()
    { return 2; }

// The clicking cooldown high end in hours
inline int mm2bcDeathWatchClickCooldownMaxH()
    { return 5; }

// The chance the diffuse sound hides the monster's location
inline int mm2bcDeathWatchLocateFailPct()
    { return 90; }

// The chance a beetle stays in one locale long enough to hoard
inline int mm2bcDeathWatchStayPct()
    { return 10; }

// The attack roll that nips off a limb (19 or 20)
inline int mm2bcSlicerSeverRollMin()
    { return 19; }

// The lair magical-weapon chance
inline int mm2bcSlicerMagicWeaponPct()
    { return 25; }

// The lair magical-boots chance
inline int mm2bcSlicerMagicBootsPct()
    { return 10; }

// The chance a present boot/gauntlet pair is matched
inline int mm2bcSlicerMatchedPairPct()
    { return 5; }

// The carapace clicking precedes the mandible attack
inline bool mm2bcDeathWatchClickPrecedesBite()
    { return true; }

// It disguises itself in other carapaces or stuck rubbish
inline bool mm2bcDeathWatchCamouflagesItself()
    { return true; }

// A 19 or 20 severs an opponent's arm or leg
inline bool mm2bcSlicerSeversOnHighRoll()
    { return true; }

// A losing slicer grabs convenient food (lost limbs) and flees
inline bool mm2bcSlicerFleesWithFood()
    { return true; }

// Unmatched boots/gauntlets give standard but false identification results
inline bool mm2bcSlicerUnmatchedBootsDeceive()
    { return true; }

// ---- the behemoth pins (the R798 MM2 letters BC) ----

// The bull damage low end
inline int mm2bcBehemothBullDmgMin()
    { return 6; }

// The bull damage high end
inline int mm2bcBehemothBullDmgMax()
    { return 24; }

// The cow damage low end
inline int mm2bcBehemothCowDmgMin()
    { return 4; }

// The cow damage high end
inline int mm2bcBehemothCowDmgMax()
    { return 16; }

// The cows accompanying a bull, low end
inline int mm2bcBehemothCowsMin()
    { return 1; }

// The cows accompanying a bull, high end
inline int mm2bcBehemothCowsMax()
    { return 3; }

// The per-cow chance a calf is present (making cows aggressive)
inline int mm2bcBehemothCalfChancePct()
    { return 25; }

// The chance an aggressive bull rises under a boat and overturns it
inline int mm2bcBehemothOverturnPct()
    { return 50; }

// The submergence ceiling in minutes (running along the bottom)
inline int mm2bcBehemothSubmergeMin()
    { return 30; }

// Bulls are always aggressive
inline bool mm2bcBehemothBullAlwaysAggressive()
    { return true; }

// Cows aggress only when a calf is present
inline bool mm2bcBehemothCowsAggressiveWithCalf()
    { return true; }

// A swimmer or passing boat in its territory draws attack
inline bool mm2bcBehemothAttacksBoatsAndSwimmers()
    { return true; }

// ---- the behir pins (the R798 MM2 letters BC) ----

// The dozen legs
inline int mm2bcBehirLegs()
    { return 12; }

// The lightning stroke length in feet
inline int mm2bcBehirLightningLengthFt()
    { return 20; }

// The stroke fires once every 10 rounds
inline int mm2bcBehirLightningCooldown()
    { return 10; }

// The stroke damage (save vs. breath weapon for half)
inline int mm2bcBehirLightningDamage()
    { return 24; }

// The talon attacks against a looped victim next round
inline int mm2bcBehirTalonAttacks()
    { return 6; }

// The bite roll that swallows prey whole
inline int mm2bcBehirSwallowRoll()
    { return 20; }

// The chance of gems inside (10 gems at 60% per gem)
inline int mm2bcBehirGemsPct()
    { return 10; }

// The chance of 1-8 jewelry pieces inside
inline int mm2bcBehirJewelryPct()
    { return 30; }

// The chance of a small indigestible magic item inside
inline int mm2bcBehirMagicItemPct()
    { return 10; }

// A successful body loop subjects the victim to talon attacks next round
inline bool mm2bcBehirLoopThenTalons()
    { return true; }

// The stroke allows a save vs. breath weapon for half damage
inline bool mm2bcBehirLightningSaveVsBreath()
    { return true; }

// Its legs climb well at half normal speed
inline bool mm2bcBehirClimbsAtHalfSpeed()
    { return true; }

// A behir sometimes swallows prey whole (purple worm effects)
inline bool mm2bcBehirSwallowsWhole()
    { return true; }

// It folds its limbs and slithers snake-fashion at will
inline bool mm2bcBehirSlithersFolded()
    { return true; }

// ---- the bloodthorn pins (the R798 MM2 letters BC) ----

// The tendril count low end
inline int mm2bcBloodthornTendrilsMin()
    { return 5; }

// The tendril count high end
inline int mm2bcBloodthornTendrilsMax()
    { return 12; }

// The tendril length low end in feet
inline int mm2bcBloodthornTendrilLenMinFt()
    { return 7; }

// The tendril length high end in feet
inline int mm2bcBloodthornTendrilLenMaxFt()
    { return 12; }

// The lash-out reach low end in feet
inline int mm2bcBloodthornTendrilReachMinFt()
    { return 5; }

// The lash-out reach high end in feet
inline int mm2bcBloodthornTendrilReachMaxFt()
    { return 7; }

// Each hit drains 25% of the victim's total initial hit points
inline int mm2bcBloodthornDrainPct()
    { return 25; }

// The damage to sever a tendril, low end
inline int mm2bcBloodthornSeverMin()
    { return 5; }

// The damage to sever a tendril, high end
inline int mm2bcBloodthornSeverMax()
    { return 10; }

// The tendril armor class
inline int mm2bcBloodthornTendrilAC()
    { return 4; }

// The stalk/trunk armor class
inline int mm2bcBloodthornTrunkAC()
    { return 3; }

// The chance it grows among hornwood trees it resembles
inline int mm2bcBloodthornHornwoodPct()
    { return 90; }

// Tendril sever damage does not affect the main plant
inline bool mm2bcBloodthornSeverSparesPlant()
    { return true; }

// The vampire vine grows among and resembles hornwood trees
inline bool mm2bcBloodthornResemblesHornwood()
    { return true; }

// The bloodthorn grows singly in forests
inline bool mm2bcBloodthornGrowsSingly()
    { return true; }

// ---- the boalisk pins (the R798 MM2 letters BC) ----

// The chance the gaze is directed at its melee opponent
inline int mm2bcBoaliskGazeAtOpponentPct()
    { return 75; }

// The complete-surprise die low end (1-2 on 1d6)
inline int mm2bcBoaliskSurpriseMin()
    { return 1; }

// The complete-surprise die high end
inline int mm2bcBoaliskSurpriseMax()
    { return 2; }

// Looking away avoids the gaze but worsens armor class by 4
inline int mm2bcBoaliskAvoidAcPenalty()
    { return 4; }

// The chance tropical constrictors include a boalisk (and vice versa)
inline int mm2bcBoaliskWithConstrictorPct()
    { return 25; }

// The boalisk gazes each round in addition to its normal attacks
inline bool mm2bcBoaliskGazeEachRound()
    { return true; }

// A failed save vs. petrification inflicts the mummy's rotting disease
inline bool mm2bcBoaliskGazeRotsLikeMummy()
    { return true; }

// It cannot constrict more than 1 victim at a time
inline bool mm2bcBoaliskConstrictSingleVictim()
    { return true; }

// It is nearly identical to the constrictor snake in all other respects
inline bool mm2bcBoaliskIdenticalToConstrictor()
    { return true; }

// ---- the bodak pins (the R798 MM2 letters BC) ----

// The death-gaze range in feet (save vs. death magic)
inline int mm2bcBodakGazeRangeFt()
    { return 30; }

// The chance a bodak carries a weapon (seldom using it)
inline int mm2bcBodakWeaponChancePct()
    { return 90; }

// The random-employment control factor ceiling (1d20)
inline int mm2bcBodakControlFactorMax()
    { return 20; }

// Direct sunlight inflicts 1 point of damage per round
inline int mm2bcBodakSunlightDmgPerRound()
    { return 1; }

// A met gaze causes death unless a save vs. death magic is made
inline bool mm2bcBodakGazeKills()
    { return true; }

// Only +1 or better magic weapons or cold-wrought iron strike it
inline bool mm2bcBodakPlusOneOrColdIron()
    { return true; }

// Charm, hold, sleep and slow are useless against a bodak
inline bool mm2bcBodakImmuneCharmHoldSleepSlow()
    { return true; }

// Poison does a bodak no harm
inline bool mm2bcBodakUnharmedByPoison()
    { return true; }

// It speaks the tongue of demons but few words of human speech
inline bool mm2bcBodakSpeaksDemonTongue()
    { return true; }

// A bodak was a human changed on the Abyssal Planes
inline bool mm2bcBodakFromTheAbyss()
    { return true; }

// ---- the boggart pins (the R798 MM2 letters BC) ----

// The form-retention low end in rounds
inline int mm2bcBoggartFormHoldRoundsMin()
    { return 10; }

// The form-retention high end in rounds
inline int mm2bcBoggartFormHoldRoundsMax()
    { return 12; }

// The electrical bolt range in feet (every other round)
inline int mm2bcBoggartBoltRangeFt()
    { return 10; }

// The bolt half-damage low end on a saved throw
inline int mm2bcBoggartBoltHalfDmgMin()
    { return 1; }

// The bolt half-damage high end
inline int mm2bcBoggartBoltHalfDmgMax()
    { return 6; }

// The noise-confusion radius in feet
inline int mm2bcBoggartConfusionRadiusFt()
    { return 30; }

// The confusion duration low end in melee rounds
inline int mm2bcBoggartConfusionRoundsMin()
    { return 7; }

// The confusion duration high end
inline int mm2bcBoggartConfusionRoundsMax()
    { return 12; }

// The invisibility ceiling in rounds
inline int mm2bcBoggartInvisibleRoundsMax()
    { return 12; }

// It uses every device to escape at 5 or fewer hit points
inline int mm2bcBoggartFleeAtHp()
    { return 5; }

// The stone-wall thickness it can pass through in wisp form
inline int mm2bcBoggartWallThicknessFt()
    { return 2; }

// A boggart is the immature form of a will-o-wisp
inline bool mm2bcBoggartImmatureWillOWisp()
    { return true; }

// The confusion noise must run 2 consecutive rounds
inline bool mm2bcBoggartConfusionNeedsTwoRounds()
    { return true; }

// Only magic missile, maze and protection from evil affect it
inline bool mm2bcBoggartOnlyThreeSpellsWork()
    { return true; }

// It devours life force and body - no resurrection is possible
inline bool mm2bcBoggartNoResurrectionPossible()
    { return true; }

// Metals ground its energy - it cannot pass through them
inline bool mm2bcBoggartCannotPassMetal()
    { return true; }

// Its own noise never breaks its invisibility
inline bool mm2bcBoggartInvisibleWhileNoisy()
    { return true; }

// A limited ESP lets it understand and speak all languages
inline bool mm2bcBoggartSpeaksAllLanguagesByEsp()
    { return true; }

// ---- the boggle pins (the R798 MM2 letters BC) ----

// The boggle height in feet
inline int mm2bcBoggleHeightFt()
    { return 3; }

// The armor class rolled against to steal from a fallen foe
inline int mm2bcBoggleStealAC()
    { return 5; }

// The extra claw attacks gained from a ceiling drop
inline int mm2bcBoggleDropClawBonus()
    { return 2; }

// The dimension door range in inches (through complete frames)
inline int mm2bcBoggleDoorRangeIn()
    { return 3; }

// They stretch to twice their length or contract to half
inline int mm2bcBoggleStretchFactor()
    { return 2; }

// Weapon attacks suffer -1 point per die of damage
inline int mm2bcBoggleDamageCutPerDie()
    { return 1; }

// Its slick black oil makes trespassers roll dexterity or fall
inline bool mm2bcBoggleOilFellsFoes()
    { return true; }

// Boggles naturally resist fire (as the ring)
inline bool mm2bcBoggleFireResistant()
    { return true; }

// They spider climb at will and cling to ceilings
inline bool mm2bcBoggleSpiderClimbAtWill()
    { return true; }

// They dimension door through any complete frame, hands reaching through
// holes
inline bool mm2bcBoggleDoorsThroughFrames()
    { return true; }

// Their keen smell detects invisible creatures
inline bool mm2bcBoggleSmellsInvisible()
    { return true; }

// Intruders trigger a high-pitched keening wall
inline bool mm2bcBoggleKeeningWarnsMasters()
    { return true; }

// Their slippery rubbery hide absorbs weapon damage
inline bool mm2bcBoggleElasticHide()
    { return true; }

// ---- the boobrie pins (the R798 MM2 letters BC) ----

// The surprise chance in 6 (crouched amidst tall grasses)
inline int mm2bcBoobrieSurpriseIn6()
    { return 2; }

// The adult pair members carry at least 5 hit points per die
inline int mm2bcBoobrieAdultHpPerDie()
    { return 5; }

// The young pair members carry 4 or fewer points per die
inline int mm2bcBoobrieYoungHpPerDie()
    { return 4; }

// The boobrie is totally immune to all forms of poison
inline bool mm2bcBoobrieImmuneToPoison()
    { return true; }

// Its flight is slow but its legs run fast through swamp
inline bool mm2bcBoobrieSlowFlight()
    { return true; }

// Its favorite foods are the huge marsh catfish, humans and sheep
inline bool mm2bcBoobriePrefersCatfishAndMen()
    { return true; }

// ---- the bookworm pins (the R798 MM2 letters BC) ----

// The bookworm body length in inches
inline int mm2bcBookwormLengthIn()
    { return 1; }

// The paper-smell range in feet
inline int mm2bcBookwormSmellRangeFt()
    { return 60; }

// The motionless armor class (agility is its usual defense)
inline int mm2bcBookwormMotionlessAC()
    { return 9; }

// The initial surprise chance
inline int mm2bcBookwormSurprisePct()
    { return 95; }

// The surprise chance against victims who see invisible things
inline int mm2bcBookwormSurpriseVsSeersPct()
    { return 50; }

// The chance surprise lands it visibly on leg or pack
inline int mm2bcBookwormOnVictimPct()
    { return 25; }

// The per-round chance to hear the noisy munching
inline int mm2bcBookwormMunchHearPct()
    { return 50; }

// The flee jump in feet (then a crawl back to its lair)
inline int mm2bcBookwormJumpFt()
    { return 10; }

// The burrow rate through dead wood or leather in inches
inline int mm2bcBookwormBurrowInPerRound()
    { return 3; }

// It destroys scrolls at 1 spell level per round
inline int mm2bcBookwormSpellLevelsPerRound()
    { return 1; }

// The chance undamaged paper items remain
inline int mm2bcBookwormPaperPct()
    { return 30; }

// The chance a map remains
inline int mm2bcBookwormMapPct()
    { return 20; }

// The chance a scroll remains
inline int mm2bcBookwormScrollPct()
    { return 30; }

// The chance an arcane work of MU level 5-10 remains
inline int mm2bcBookwormArcanePct()
    { return 20; }

// The chance a normal spell book of MU level 1-8 remains
inline int mm2bcBookwormSpellbookPct()
    { return 10; }

// It is attracted to paper in all forms
inline bool mm2bcBookwormAttractedToPaper()
    { return true; }

// It cannot digest living matter of any type
inline bool mm2bcBookwormCannotDigestLivingMatter()
    { return true; }

// After any 1 attack it jumps and flees if possible
inline bool mm2bcBookwormFleesAfterAttack()
    { return true; }

// Chameleon-like abilities blend it into any background
inline bool mm2bcBookwormChameleonHides()
    { return true; }

// It always seeks the largest volume of paper in the area
inline bool mm2bcBookwormSeeksLargestVolume()
    { return true; }

// ---- the bowler pins (the R798 MM2 letters BC) ----

// The rolling acceleration in inches per round
inline int mm2bcBowlerAccelInPerRound()
    { return 1; }

// The maximum move in inches
inline int mm2bcBowlerMaxMoveIn()
    { return 15; }

// The weight in pounds per hit point
inline int mm2bcBowlerLbsPerHp()
    { return 28; }

// The beryl gem core base value in gold pieces
inline int mm2bcBowlerCoreGp()
    { return 10; }

// The chance prey notices a quiet bowler first
inline int mm2bcBowlerNoticePct()
    { return 50; }

// The notice range in feet
inline int mm2bcBowlerNoticeRangeFt()
    { return 40; }

// A bowler has no visual organs - it senses sound, vibration and odor
inline bool mm2bcBowlerNoVisualOrgans()
    { return true; }

// Its attack is to roll over and crush its prey
inline bool mm2bcBowlerRollsOverVictims()
    { return true; }

// Its own rolling vibrations detect and avoid walls and pits
inline bool mm2bcBowlerDetectsOwnVibrations()
    { return true; }

// It lairs where rocks provide natural camouflage
inline bool mm2bcBowlerCamouflagedAsRock()
    { return true; }

// ---- the buckawn pins (the R798 MM2 letters BC) ----

// The buckawn spell-like power level
inline int mm2bcBuckawnSpellLevel()
    { return 6; }

// The hide-in-foliage chance per turn
inline int mm2bcBuckawnHidePct()
    { return 80; }

// The reduction to move-silently chances near them
inline int mm2bcBuckawnSilentReductionPct()
    { return 50; }

// Their very superior senses mean they are never surprised
inline bool mm2bcBuckawnNeverSurprised()
    { return true; }

// They see into infra and ultraviolet and detect invisible creatures
inline bool mm2bcBuckawnDetectsInvisible()
    { return true; }

// Their darts are known to be drugged or poisoned
inline bool mm2bcBuckawnDruggedDarts()
    { return true; }

// Audible glamer, change self, dancing lights, invisible: 1 per round at will
inline bool mm2bcBuckawnAtWillPowersPerRound()
    { return true; }

// Entangle, pass without trace, summon insects, trip: once each per day
inline bool mm2bcBuckawnDailyPowersOnceEach()
    { return true; }

// Buckawn shun human contact and are trickier than brownies
inline bool mm2bcBuckawnShunHumans()
    { return true; }

// ---- the cat pins (the R798 MM2 letters BC) ----

// The domestic rear claw rake damage low end
inline int mm2bcCatDomesticRakeMin()
    { return 1; }

// The domestic rear claw rake damage high end
inline int mm2bcCatDomesticRakeMax()
    { return 2; }

// The wild cat rakes 1-2 with each of 2 rear paws (rake max 2)
inline int mm2bcCatWildRakePerPaw()
    { return 2; }

// Both sorts surprise prey on 3 in 6
inline int mm2bcCatSurpriseIn6()
    { return 3; }

// Both sorts are surprised only on 1 in 6
inline int mm2bcCatSurprisedIn6()
    { return 1; }

// They move along tree limbs at half their normal rate
inline int mm2bcCatTreeMoveDivisor()
    { return 2; }

// The domestic cat has only 1 effective forepaw attack
inline bool mm2bcCatDomesticSingleForepaw()
    { return true; }

// The wild cat has 2 forepaw attacks
inline bool mm2bcCatWildTwoForepaws()
    { return true; }

// Both gain rear claw rakes when the forepaw attacks hit
inline bool mm2bcCatRakeOnForepawHit()
    { return true; }

// Domestic cats will not normally attack medium or large creatures
inline bool mm2bcCatDomesticAvoidsBigFoes()
    { return true; }

// Domestic and wild cats are closely related and interbreed
inline bool mm2bcCatInterbreed()
    { return true; }

// ---- the cat lord pins (the R798 MM2 letters BC) ----

// The cat lord strength
inline int mm2bcCatLordStr()
    { return 20; }

// The cat lord intelligence
inline int mm2bcCatLordInt()
    { return 19; }

// The cat lord wisdom
inline int mm2bcCatLordWis()
    { return 17; }

// The cat lord dexterity
inline int mm2bcCatLordDex()
    { return 23; }

// The cat lord constitution
inline int mm2bcCatLordCon()
    { return 16; }

// Charisma toward all felines
inline int mm2bcCatLordChaFelines()
    { return 25; }

// Charisma toward were-felines
inline int mm2bcCatLordChaWereFelines()
    { return 22; }

// Charisma toward partial felines and ailurophiles
inline int mm2bcCatLordChaPartial()
    { return 18; }

// Charisma toward those indifferent to the species
inline int mm2bcCatLordChaIndifferent()
    { return 13; }

// Charisma toward ailurophobes
inline int mm2bcCatLordChaAilurophobe()
    { return 7; }

// The human-form thief level
inline int mm2bcCatLordThiefLevel()
    { return 19; }

// The human-form monk level
inline int mm2bcCatLordMonkLevel()
    { return 13; }

// The spring forward, backward or upward in feet
inline int mm2bcCatLordSpringFt()
    { return 30; }

// The yowl stun radius in feet
inline int mm2bcCatLordYowlRadiusFt()
    { return 19; }

// The yowl stun low end in rounds
inline int mm2bcCatLordYowlStunMin()
    { return 1; }

// The yowl stun high end in rounds
inline int mm2bcCatLordYowlStunMax()
    { return 4; }

// The wound licks per day
inline int mm2bcCatLordLicksPerDay()
    { return 9; }

// The lick healing low end (2-64 points)
inline int mm2bcCatLordLickHealMin()
    { return 2; }

// The lick healing high end
inline int mm2bcCatLordLickHealMax()
    { return 64; }

// Hearing and vision at 5 times human normal
inline int mm2bcCatLordHearingMultiple()
    { return 5; }

// Infravision of 5 times normal (300 feet)
inline int mm2bcCatLordInfravisionFt()
    { return 300; }

// He always moves with 99% silence
inline int mm2bcCatLordSilencePct()
    { return 99; }

// All his powers work at 19th level of ability
inline int mm2bcCatLordSpitLevel()
    { return 19; }

// Astral travel uses per day
inline int mm2bcCatLordAstralPerDay()
    { return 1; }

// Dimension door uses per day
inline int mm2bcCatLordDimensionDoorsPerDay()
    { return 9; }

// Etherealness uses per day
inline int mm2bcCatLordEtherealPerDay()
    { return 2; }

// Haste uses per day (not in human monk form)
inline int mm2bcCatLordHastePerDay()
    { return 2; }

// Teleport without error uses per day
inline int mm2bcCatLordTeleportPerDay()
    { return 1; }

// His speed and ferocity always win initiative in normal circumstances
inline bool mm2bcCatLordAlwaysInitiative()
    { return true; }

// Like most felines he always lands on his feet, instantly ready
inline bool mm2bcCatLordLandsOnFeet()
    { return true; }

// The pre-bite spit needs no to-hit roll; a failed save vs. spells blinds
inline bool mm2bcCatLordSpitBlindsNoRoll()
    { return true; }

// He can spit only prior to biting every other round
inline bool mm2bcCatLordSpitEveryOtherRound()
    { return true; }

// The yowl stuns all creatures except other felines (save vs. spells)
inline bool mm2bcCatLordYowlStunsNonFelines()
    { return true; }

// Each wound lick restores 2-64 points of damage
inline bool mm2bcCatLordLickHeals()
    { return true; }

// Summoned felines, even were-sort, are completely loyal and obedient
inline bool mm2bcCatLordSummonsLoyalFelines()
    { return true; }

// Any feline immediately recognizes the cat lord even in human form
inline bool mm2bcCatLordRecognizedByAllFelines()
    { return true; }

// His haste does not apply when he is in human monk form
inline bool mm2bcCatLordHasteNotInMonkForm()
    { return true; }

// Other than cats, his only known friend is the deity Xan Yae
inline bool mm2bcCatLordFriendXanYae()
    { return true; }

// ---- the giant catfish pins (the R798 MM2 letters BC) ----

// A 7-HD specimen can swallow a gnome or halfling
inline int mm2bcCatfishSwallowAtHdGnome()
    { return 7; }

// An 8-HD specimen can swallow a dwarf
inline int mm2bcCatfishSwallowAtHdDwarf()
    { return 8; }

// A 9-HD specimen can swallow a small human or elf
inline int mm2bcCatfishSwallowAtHdSmall()
    { return 9; }

// A 10-HD specimen can swallow a large human
inline int mm2bcCatfishSwallowAtHdLarge()
    { return 10; }

// The swallowed victim takes 1 point per round from digestive fluids
inline int mm2bcCatfishDigestDmgPerRound()
    { return 1; }

// The swallowed victim's per-round suffocation chance
inline int mm2bcCatfishSuffocatePctPerRound()
    { return 5; }

// Internal damage equal to 50% of its hit points cuts the way out
inline int mm2bcCatfishCutOutAtPct()
    { return 50; }

// Piercing attacks have a 20% chance to also hit a swallowed victim
inline int mm2bcCatfishPierceHitsVictimPct()
    { return 20; }

// The poisonous whisker damage low end
inline int mm2bcCatfishWhiskerDmgMin()
    { return 2; }

// The whisker damage high end
inline int mm2bcCatfishWhiskerDmgMax()
    { return 8; }

// The whisker damage on a saved throw, low end
inline int mm2bcCatfishWhiskerSaveDmgMin()
    { return 1; }

// The whisker save damage high end
inline int mm2bcCatfishWhiskerSaveDmgMax()
    { return 4; }

// The head-lash attacks up to 2 other opponents with feelers
inline int mm2bcCatfishWhiskerExtraTargets()
    { return 2; }

// It swallows recognized food small enough to fit
inline bool mm2bcCatfishSwallowsWhole()
    { return true; }

// Its tentacle-like feelers secrete a strong poison
inline bool mm2bcCatfishWhiskersPoisonous()
    { return true; }

// Only a sharp edged or pointed weapon in hand gives any escape chance
inline bool mm2bcCatfishNeedsEdgedWeaponInside()
    { return true; }

// It is principally a bottom-feeding scavenger but attacks "food"
inline bool mm2bcCatfishBottomFeeder()
    { return true; }

// ---- the cave cricket pins (the R798 MM2 letters BC) ----

// The speech-drowning chirp range in feet
inline int mm2bcCaveCricketChirpRangeFt()
    { return 20; }

// The predator-drawing hearing range in inches
inline int mm2bcCaveCricketHearingRangeIn()
    { return 90; }

// The chance in 6 chirping draws all predators within hearing
inline int mm2bcCaveCricketDrawIn6()
    { return 2; }

// The per-individual chance in 6 of leaping on a character
inline int mm2bcCaveCricketLeapIn6()
    { return 1; }

// The inadvertent leap damage low end
inline int mm2bcCaveCricketLeapDmgMin()
    { return 1; }

// The inadvertent leap damage high end
inline int mm2bcCaveCricketLeapDmgMax()
    { return 4; }

// The hind-leg kick range in feet
inline int mm2bcCaveCricketKickRangeFt()
    { return 10; }

// The chirping noise drowns out all speech
inline bool mm2bcCaveCricketChirpDrownsSpeech()
    { return true; }

// The chirp can draw every predator within hearing range
inline bool mm2bcCaveCricketDrawsPredators()
    { return true; }

// Any creature within 10 feet may be accidentally kicked
inline bool mm2bcCaveCricketKicksNearby()
    { return true; }

// Cave crickets eat vegetation, cloth, paper and fungi
inline bool mm2bcCaveCricketEatsGear()
    { return true; }

// ---- the cave fisher pins (the R798 MM2 letters BC) ----

// The adhesive filament length in feet
inline int mm2bcCaveFisherFilamentFt()
    { return 60; }

// The filament strikes as a 6-hit-dice monster
inline int mm2bcCaveFisherStrikeAsHd()
    { return 6; }

// The winch reel-in rate in feet per round
inline int mm2bcCaveFisherReelFtPerRound()
    { return 15; }

// The pull-in prey ceiling in pounds (4000 gp weight)
inline int mm2bcCaveFisherMaxPreyLbs()
    { return 400; }

// The chance to notice the filament within 10 feet
inline int mm2bcCaveFisherNoticePct()
    { return 20; }

// Beyond this range there is no chance to notice it
inline int mm2bcCaveFisherNoticeRangeFt()
    { return 10; }

// The leg count (2 end in powerful pincers)
inline int mm2bcCaveFisherLegs()
    { return 8; }

// The pincer legs that kill and dismember drawn prey
inline int mm2bcCaveFisherPincerLegs()
    { return 2; }

// The filament cuts only by a +1 or better edged weapon
inline bool mm2bcCaveFisherFilamentPlusOneOnly()
    { return true; }

// High-alcohol liquid (or its own blood) dissolves the adhesive
inline bool mm2bcCaveFisherAlcoholDissolvesAdhesive()
    { return true; }

// Its other 6 legs cement it to the rock with the same adhesive
inline bool mm2bcCaveFisherCementsItself()
    { return true; }

// When local prey learns its abode it dissolves its bindings and moves on
inline bool mm2bcCaveFisherRelocatesWhenAvoided()
    { return true; }

// It prefers ledges over much-traveled paths
inline bool mm2bcCaveFisherHidesOverPaths()
    { return true; }

// ---- the cave moray pins (the R798 MM2 letters BC) ----

// The striking range low end in feet
inline int mm2bcCaveMorayStrikeMinFt()
    { return 3; }

// The striking range high end in feet
inline int mm2bcCaveMorayStrikeMaxFt()
    { return 5; }

// The exposed body armor class
inline int mm2bcCaveMorayBodyAC()
    { return 5; }

// Only a 1 in 20 chance of striking one thus exposed
inline int mm2bcCaveMorayHitChanceIn20()
    { return 1; }

// They dwell in cyst-like burrows and strike from both sides of a passage
inline bool mm2bcCaveMorayStrikesFromCysts()
    { return true; }

// It must withdraw into its cyst to recoil for another strike
inline bool mm2bcCaveMorayWithdrawsToRecoil()
    { return true; }

// Its knobby splotched head looks like rock
inline bool mm2bcCaveMorayLooksLikeRock()
    { return true; }

// ---- the centipede pins (the R798 MM2 letters BC) ----

// The huge centipede weak poison saves at +4
inline int mm2bcCentipedeHugeSaveBonus()
    { return 4; }

// The failed-save damage low end (not death, unlike its giant cousin)
inline int mm2bcCentipedeHugeFailDmgMin()
    { return 4; }

// The failed-save damage high end
inline int mm2bcCentipedeHugeFailDmgMax()
    { return 16; }

// Huge centipedes make their own saving throws at -2
inline int mm2bcCentipedeHugeSelfSavePenalty()
    { return 2; }

// The megalo burn damage low end on a successful save
inline int mm2bcCentipedeMegaloSaveDmgMin()
    { return 1; }

// The megalo burn damage high end
inline int mm2bcCentipedeMegaloSaveDmgMax()
    { return 8; }

// Its smaller size means a failed save deals damage, not death
inline bool mm2bcCentipedeHugePoisonNotDeadly()
    { return true; }

// The megalo toxin saves at normal chances (megalo saves also normal)
inline bool mm2bcCentipedeMegaloNormalSaves()
    { return true; }

// A successful save means the poison burns the skin instead
inline bool mm2bcCentipedeMegaloBurnsSkinOnSave()
    { return true; }

// Both forms are cousins of the giant centipede (q.v.)
inline bool mm2bcCentipedeCousinsOfGiant()
    { return true; }

// ---- the cheetah pins (the R798 MM2 letters BC) ----

// The sprint burst rate in inches (triple speed)
inline int mm2bcCheetahSprintIn()
    { return 45; }

// The sprint duration in rounds
inline int mm2bcCheetahSprintRounds()
    { return 3; }

// The rest needed before another sprint, in turns
inline int mm2bcCheetahRestTurns()
    { return 3; }

// The upward spring in feet
inline int mm2bcCheetahSpringUpFt()
    { return 10; }

// The forward spring in feet
inline int mm2bcCheetahSpringFwdFt()
    { return 20; }

// The camouflage-and-skill surprise chance in 6
inline int mm2bcCheetahSurpriseIn6()
    { return 3; }

// The cubs in a 1-2 animal lair, low end
inline int mm2bcCheetahCubsMin()
    { return 1; }

// The cubs in a lair, high end
inline int mm2bcCheetahCubsMax()
    { return 4; }

// Parents defending young attack at +2 to hit and damage
inline int mm2bcCheetahParentBonus()
    { return 2; }

// It is the only cat with nonretractable claws
inline bool mm2bcCheetahNonretractableClaws()
    { return true; }

// It is the only large cat trainable to a trustworthy level
inline bool mm2bcCheetahTrainable()
    { return true; }

// Both forepaws hitting gains 2 additional rear-claw rakes
inline bool mm2bcCheetahRakesOnDoubleForepawHit()
    { return true; }

// The young have no effective attack
inline bool mm2bcCheetahCubsNoAttack()
    { return true; }

// Parents give their lives in defense of the young
inline bool mm2bcCheetahParentsDefendToDeath()
    { return true; }

// ---- the choke creeper pins (the R798 MM2 letters BC) ----

// The plant stem may exceed 100 feet
inline int mm2bcChokeStemLenFt()
    { return 100; }

// The vine creep rate in feet per round
inline int mm2bcChokeVineCreepFtPerRound()
    { return 5; }

// The damage to sever a vine, low end
inline int mm2bcChokeVineSeverMin()
    { return 2; }

// The damage to sever a vine, high end
inline int mm2bcChokeVineSeverMax()
    { return 16; }

// The huge old ones carry 8 pips per die
inline int mm2bcChokeOldHpPerDie()
    { return 8; }

// The huge old ones reach 200 points
inline int mm2bcChokeOldHp()
    { return 200; }

// Small choke creepers carry 1 pip per die
inline int mm2bcChokeSmallHpPerDie()
    { return 1; }

// The squeeze damage low end per turn
inline int mm2bcChokeSqueezeDmgMin()
    { return 1; }

// The squeeze damage high end
inline int mm2bcChokeSqueezeDmgMax()
    { return 4; }

// The per-turn chance a vine uses its strangling grip
inline int mm2bcChokeStranglePctPerTurn()
    { return 10; }

// The strangler vines per 10-foot section (double at the end)
inline int mm2bcChokeVinesPerSection()
    { return 8; }

// The vine branch length low end in feet
inline int mm2bcChokeVineLenMinFt()
    { return 9; }

// The vine branch length high end in feet
inline int mm2bcChokeVineLenMaxFt()
    { return 16; }

// Cold causes 1 point per damage die
inline int mm2bcChokeColdDmgPerDie()
    { return 1; }

// The cold immobilization low end in rounds
inline int mm2bcChokeColdImmobilizeMin()
    { return 2; }

// The cold immobilization high end in rounds
inline int mm2bcChokeColdImmobilizeMax()
    { return 5; }

// Vines are attracted to light and movement
inline bool mm2bcChokeVinesAttractedToLight()
    { return true; }

// A strangling grip kills the victim at the end of the succeeding round
inline bool mm2bcChokeStrangleKillsNextRound()
    { return true; }

// Small torch-sized fires do not affect it (burning oil does normal damage)
inline bool mm2bcChokeTorchFireHarmless()
    { return true; }

// Electrical attacks double vine movement for 2-5 rounds and do no damage
inline bool mm2bcChokeElectricalDoublesSpeed()
    { return true; }

// Damage to attacking vines does not affect the main plant
inline bool mm2bcChokeVineLossSparesPlant()
    { return true; }

// ---- the cloaker pins (the R798 MM2 letters BC) ----

// The flying rate in inches
inline int mm2bcCloakerFlyIn()
    { return 15; }

// The wall-creeping rate in inches
inline int mm2bcCloakerCreepIn()
    { return 1; }

// The tail damage low end (twice per round)
inline int mm2bcCloakerTailDmgMin()
    { return 1; }

// The tail damage high end
inline int mm2bcCloakerTailDmgMax()
    { return 6; }

// The tail strikes per round
inline int mm2bcCloakerTailStrikes()
    { return 2; }

// The tail armor class
inline int mm2bcCloakerTailAC()
    { return 1; }

// The tail cut-off damage total
inline int mm2bcCloakerTailHp()
    { return 16; }

// The bite base damage low end (plus the victim armor class)
inline int mm2bcCloakerBiteAddMin()
    { return 1; }

// The bite base damage high end
inline int mm2bcCloakerBiteAddMax()
    { return 4; }

// The lowest moan range in feet (fight at -2 to hit and damage)
inline int mm2bcCloakerMoanUneaseRangeFt()
    { return 80; }

// Over 6 consecutive turns the lowest moan numbs listeners
inline int mm2bcCloakerMoanNumbTurns()
    { return 6; }

// The fear moan range in feet
inline int mm2bcCloakerMoanFearRangeFt()
    { return 30; }

// The fear duration in rounds (save vs. spells)
inline int mm2bcCloakerMoanFearRounds()
    { return 2; }

// The nausea cone length in feet
inline int mm2bcCloakerMoanNauseaConeFt()
    { return 30; }

// The nausea cone width at its open end
inline int mm2bcCloakerMoanNauseaWidthFt()
    { return 20; }

// The nausea duration low end in rounds
inline int mm2bcCloakerMoanNauseaMin()
    { return 2; }

// The nausea duration high end
inline int mm2bcCloakerMoanNauseaMax()
    { return 5; }

// The hold-person moan range in feet (1 target)
inline int mm2bcCloakerMoanHoldRangeFt()
    { return 30; }

// The hold duration in rounds
inline int mm2bcCloakerMoanHoldRounds()
    { return 5; }

// The shadow-manipulation armor class
inline int mm2bcCloakerShadowAC()
    { return 1; }

// All its eyespots mean no surprise from the rear side
inline bool mm2bcCloakerNoRearSurprise()
    { return true; }

// It flies at a character, wrapping and pinning the victim's arms
inline bool mm2bcCloakerWrapsVictim()
    { return true; }

// Attacks on a wrapped cloaker split damage half to the victim
inline bool mm2bcCloakerSplitDamageWhenWrapped()
    { return true; }

// The subsonic moaning effects are blocked by stone
inline bool mm2bcCloakerMoanBlockedByStone()
    { return true; }

// Cloakers may not bite and moan at the same time
inline bool mm2bcCloakerNoBiteAndMoanTogether()
    { return true; }

// A neutralize poison spell neutralizes the moaning effects
inline bool mm2bcCloakerMoanNeutralizedByPoisonFix()
    { return true; }

// Shrouded in shadows it produces doubles (as mirror image)
inline bool mm2bcCloakerShadowDoubles()
    { return true; }

// A light spell blinds it and prevents shadow shifting
inline bool mm2bcCloakerLightBlinds()
    { return true; }

// The wrapped bite adds the victim's unadjusted armor class to damage
inline bool mm2bcCloakerBiteAddsVictimAC()
    { return true; }

// ---- the cooshee pins (the R798 MM2 letters BC) ----

// The straight-line chase rate in inches
inline int mm2bcCoosheeChaseIn()
    { return 21; }

// The bark carries a mile or more
inline int mm2bcCoosheeBarkMiles()
    { return 1; }

// The conceal-in-brush chance
inline int mm2bcCoosheeHidePct()
    { return 75; }

// The typical weight low end in pounds
inline int mm2bcCoosheeWeightMinLbs()
    { return 168; }

// The attained weight high end in pounds
inline int mm2bcCoosheeWeightMaxLbs()
    { return 310; }

// Prone opponents are bitten at +2 to hit
inline int mm2bcCoosheeProneHitBonus()
    { return 2; }

// Its forepaws knock 2-footed man-size or smaller foes off their feet
inline bool mm2bcCoosheeKnocksOverFoes()
    { return true; }

// It barks only to warn its masters
inline bool mm2bcCoosheeBarksOnlyToWarn()
    { return true; }

// Elven dogs avoid others of the canine species
inline bool mm2bcCoosheeAvoidsCanines()
    { return true; }

// Its coloration and silence conceal it easily
inline bool mm2bcCoosheeMovesSilently()
    { return true; }

// It is found only in woodlands or meadows frequented by elves
inline bool mm2bcCoosheeElvenCompany()
    { return true; }

// ---- the giant crane pins (the R798 MM2 letters BC) ----

// Above 10 birds, each additional is 50% likely immature
inline int mm2bcCraneImmatureThreshold()
    { return 10; }

// The immature chance per additional bird
inline int mm2bcCraneImmaturePct()
    { return 50; }

// At 20 birds there is a 50% chance of a great flock
inline int mm2bcCraneFlockAtEncounter()
    { return 20; }

// The great-flock chance
inline int mm2bcCraneFlockChancePct()
    { return 50; }

// The great-flock size low end
inline int mm2bcCraneFlockMin()
    { return 31; }

// The great-flock size high end
inline int mm2bcCraneFlockMax()
    { return 50; }

// The half-grown fledglings low end in a flock
inline int mm2bcCraneFledglingsMin()
    { return 3; }

// The fledglings high end
inline int mm2bcCraneFledglingsMax()
    { return 12; }

// They are protective of mates, young and nesting areas
inline bool mm2bcCraneProtectsOwn()
    { return true; }

// Giant cranes are generally nonaggressive
inline bool mm2bcCraneGenerallyNonaggressive()
    { return true; }

// They hunt large fish in marshes and swamps
inline bool mm2bcCraneHuntsLargeFish()
    { return true; }

// ---- the crysmal pins (the R798 MM2 letters BC) ----

// The undigested rough gems inside, low end
inline int mm2bcCrysmalGemsMin()
    { return 4; }

// The undigested rough gems high end
inline int mm2bcCrysmalGemsMax()
    { return 32; }

// The effective armor class vs. edged and piercing weapons
inline int mm2bcCrysmalEdgedAC()
    { return -4; }

// The effective armor class vs. blunt metallic weapons
inline int mm2bcCrysmalBluntAC()
    { return 0; }

// The shot appendage range in inches
inline int mm2bcCrysmalAppendageRangeIn()
    { return 2; }

// The shot appendage damage low end (1d8+8)
inline int mm2bcCrysmalAppendageDmgMin()
    { return 9; }

// The shot appendage damage high end
inline int mm2bcCrysmalAppendageDmgMax()
    { return 16; }

// The primary appendage damage low end
inline int mm2bcCrysmalPrimaryDmgMin()
    { return 3; }

// The secondary appendage damage low end after shooting
inline int mm2bcCrysmalSecondaryDmgMin()
    { return 2; }

// The secondary appendage damage high end
inline int mm2bcCrysmalSecondaryDmgMax()
    { return 8; }

// The shatter spell damage low end
inline int mm2bcCrysmalShatterDmgMin()
    { return 3; }

// The shatter spell damage high end
inline int mm2bcCrysmalShatterDmgMax()
    { return 18; }

// The glassee blindness low end in rounds
inline int mm2bcCrysmalGlasseeBlindMin()
    { return 2; }

// The glassee blindness high end
inline int mm2bcCrysmalGlasseeBlindMax()
    { return 5; }

// Stone to flesh lowers its armor class to 6 for 1 melee round
inline int mm2bcCrysmalStoneToFleshAC()
    { return 6; }

// One round alters its molecular structure to move through rock
inline int mm2bcCrysmalRockShiftRounds()
    { return 1; }

// Medium-sized crysmals run up to 16 hit points (large are 17+)
inline int mm2bcCrysmalMediumHp()
    { return 16; }

// Fire and cold-based spells do not harm it
inline bool mm2bcCrysmalImmuneFireCold()
    { return true; }

// Electrical attacks cause one-quarter or no damage
inline bool mm2bcCrysmalElectricalQuarter()
    { return true; }

// Poisons and gases do not harm it
inline bool mm2bcCrysmalImmunePoisonGas()
    { return true; }

// It moves through solid rock or earth as does a xorn
inline bool mm2bcCrysmalMovesThroughRock()
    { return true; }

// A phase door spell strikes while altering kills it
inline bool mm2bcCrysmalPhaseDoorKillsShifting()
    { return true; }

// Crysmals hate xorn, which prey upon them
inline bool mm2bcCrysmalHatesXorn()
    { return true; }

// After shooting its appendage it attacks with the weaker secondary
inline bool mm2bcCrysmalProjectileLosesPrimary()
    { return true; }

// Its diet is mineral formations - quartz, beryl, corundum, carbon crystals
inline bool mm2bcCrysmalDietMinerals()
    { return true; }

// ---- the crystal ooze pins (the R798 MM2 letters BC) ----

// The immersed invisibility chance
inline int mm2bcCrystalOozeInvisiblePct()
    { return 75; }

// Prey is totally consumed when reduced to -20 hit points
inline int mm2bcCrystalOozeConsumedAtHp()
    { return 20; }

// Weapon blows do only 1 point of damage per hit
inline int mm2bcCrystalOozeBlowDmg()
    { return 1; }

// It flows over a victim and exudes a paralyzing poison
inline bool mm2bcCrystalOozeParalyticPoison()
    { return true; }

// It is unharmed by acid, cold, heat or fire
inline bool mm2bcCrystalOozeImmuneAcidColdHeatFire()
    { return true; }

// Electricity does full damage, as do magic missiles
inline bool mm2bcCrystalOozeElectricityFullDamage()
    { return true; }

// Wooden weapons save vs. acid per hit or are eaten off
inline bool mm2bcCrystalOozeEatsWoodenWeapons()
    { return true; }

// Any dim or dark body of shallow water can be its home
inline bool mm2bcCrystalOozeLivesInShallowWater()
    { return true; }

// ---- the cyclopskin pins (the R798 MM2 letters BC) ----

// Their poor depth perception makes missile attacks at -2 to hit
inline int mm2bcCyclopskinMissilePenalty()
    { return 2; }

// Their strength gives +2 bonus to damage
inline int mm2bcCyclopskinDamageBonus()
    { return 2; }

// The great raiding band was said to number over 80
inline int mm2bcCyclopskinRaidBandMax()
    { return 80; }

// A single eye gives poor depth perception
inline bool mm2bcCyclopskinPoorDepthPerception()
    { return true; }

// They shun other creatures unless those serve as prey or slaves
inline bool mm2bcCyclopskinShunOthers()
    { return true; }

// Each carries a great sling and a heavy throwing spear in addition
inline bool mm2bcCyclopskinCarrySlingAndSpear()
    { return true; }

// They favor rocky places and dwell in caves
inline bool mm2bcCyclopskinDwellInCaves()
    { return true; }

// ---- the MM2 letter B stat grid (the R798 wiring) ----

// The ARMOR CLASS cell (the baku, boggart and crysmal negatives ride bare Lua
// numbers - a string drops the sign; the print strings ride the defs)
inline int mm2bcBStatAC(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return 6;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 4;
        case 5:
            return 2;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 8;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return -6;
        case 21:
            return 5;
        case 22:
            return 5;
        case 23:
            return 2;
        case 24:
            return 4;
        case 25:
            return 3;
        default:
            return 0;
        }
    }

// The HIT DICE number (the flat-hp forms read 0 - the loader flat-hp path;
// the 2-6, 7-10 and 5-30 ranges pin their low ends)
inline int mm2bcBStatHd(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 10;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 8;
        case 10:
            return 3;
        case 11:
            return 4;
        case 12:
            return 6;
        case 13:
            return 9;
        case 14:
            return 6;
        case 15:
            return 10;
        case 16:
            return 12;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 9;
        case 20:
            return 6;
        case 21:
            return 4;
        case 22:
            return 9;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// The HIT DICE bonus points (the buckawn 1-1 carries -1)
inline int mm2bcBStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 0;
        case 2:
            return 6;
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
            return 8;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 4;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 5;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 9;
        case 20:
            return 0;
        case 21:
            return 3;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return -1;
        default:
            return 0;
        }
    }

// The average hit points (floor of dice x 3.5 plus bonus; the flat-hp forms
// carry the print value)
inline int mm2bcBStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 54;
        case 1:
            return 14;
        case 2:
            return 27;
        case 3:
            return 7;
        case 4:
            return 22;
        case 5:
            return 35;
        case 6:
            return 14;
        case 7:
            return 1;
        case 8:
            return 7;
        case 9:
            return 36;
        case 10:
            return 11;
        case 11:
            return 16;
        case 12:
            return 25;
        case 13:
            return 31;
        case 14:
            return 21;
        case 15:
            return 40;
        case 16:
            return 42;
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 40;
        case 20:
            return 21;
        case 21:
            return 17;
        case 22:
            return 31;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 2;
        default:
            return 0;
        }
    }

// The NO. OF ATTACKS (the behir 1 and 1 or 1 and 6 sums to 9 - the loader
// sum-and-clamp; the boggle 3(2) reads 3)
inline int mm2bcBStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 1;
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
            return 9;
        case 17:
            return 8;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// The LEVEL/X.P. base value (the behemoth 1800 settled from the capture)
inline int mm2bcBStatXp(int b)
    {
        switch (b) {
        case 0:
            return 4900;
        case 1:
            return 60;
        case 2:
            return 1275;
        case 3:
            return 65;
        case 4:
            return 475;
        case 5:
            return 3000;
        case 6:
            return 150;
        case 7:
            return 1;
        case 8:
            return 28;
        case 9:
            return 900;
        case 10:
            return 150;
        case 11:
            return 200;
        case 12:
            return 400;
        case 13:
            return 1400;
        case 14:
            return 275;
        case 15:
            return 1800;
        case 16:
            return 2850;
        case 17:
            return 800;
        case 18:
            return 350;
        case 19:
            return 1950;
        case 20:
            return 625;
        case 21:
            return 170;
        case 22:
            return 900;
        case 23:
            return 7;
        case 24:
            return 5;
        case 25:
            return 65;
        default:
            return 0;
        }
    }

// The xp per hit point (the cloaker 6 settled by the book-internal tie)
inline int mm2bcBStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 4;
        case 2:
            return 10;
        case 3:
            return 2;
        case 4:
            return 6;
        case 5:
            return 14;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 12;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 8;
        case 13:
            return 12;
        case 14:
            return 6;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 35;
        case 18:
            return 6;
        case 19:
            return 14;
        case 20:
            return 6;
        case 21:
            return 5;
        case 22:
            return 12;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// The % IN LAIR cell (Nil reads 0)
inline int mm2bcBStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 0;
        case 3:
            return 100;
        case 4:
            return 60;
        case 5:
            return 50;
        case 6:
            return 15;
        case 7:
            return 0;
        case 8:
            return 50;
        case 9:
            return 0;
        case 10:
            return 20;
        case 11:
            return 90;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 25;
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
            return 25;
        case 22:
            return 0;
        case 23:
            return 25;
        case 24:
            return 35;
        case 25:
            return 10;
        default:
            return 0;
        }
    }

// The primary MOVE rate in inches (the first N-M pair reads its low end)
inline int mm2bcBStatMove(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 6;
        case 2:
            return 15;
        case 3:
            return 0;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 6;
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
            return 6;
        case 15:
            return 6;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 12;
        case 19:
            return 6;
        case 20:
            return 18;
        case 21:
            return 9;
        case 22:
            return 15;
        case 23:
            return 12;
        case 24:
            return 6;
        case 25:
            return 12;
        default:
            return 0;
        }
    }

// ---- the MM2 letter C stat grid (the R798 wiring) ----

// The ARMOR CLASS cell (the cat lord -9 rides a bare Lua number - a string
// drops the sign; the print strings ride the defs)
inline int mm2bcCStatAC(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return -9;
        case 3:
            return 7;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 9;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 3;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return -4;
        case 15:
            return 8;
        case 16:
            return 3;
        default:
            return 0;
        }
    }

// The HIT DICE number (the flat-hp cats read 0 - the loader flat-hp path; the
// 7-10 giant catfish pins its low end)
inline int mm2bcCStatHd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 7;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 25;
        case 11:
            return 6;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 6;
        case 15:
            return 4;
        case 16:
            return 5;
        default:
            return 0;
        }
    }

// The HIT DICE bonus points
inline int mm2bcCStatHdBonus(int b)
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
            return 3;
        case 5:
            return 0;
        case 6:
            return 4;
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
            return 3;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 0;
        case 16:
            return 0;
        default:
            return 0;
        }
    }

// The average hit points (floor of dice x 3.5 plus bonus; the cat lord
// carries its flat 81)
inline int mm2bcCStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 81;
        case 3:
            return 24;
        case 4:
            return 6;
        case 5:
            return 10;
        case 6:
            return 18;
        case 7:
            return 1;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 87;
        case 11:
            return 21;
        case 12:
            return 13;
        case 13:
            return 10;
        case 14:
            return 27;
        case 15:
            return 14;
        case 16:
            return 17;
        default:
            return 0;
        }
    }

// The NO. OF ATTACKS (the choke 8-or-more and the 1/round strings read their
// loader max; Nil reads 1)
inline int mm2bcCStatAttacks(int b)
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
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 8;
        case 11:
            return 2;
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
        default:
            return 0;
        }
    }

// The LEVEL/X.P. base value (the cat lord 13900 carries no per-hit addend)
inline int mm2bcCStatXp(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 13900;
        case 3:
            return 650;
        case 4:
            return 20;
        case 5:
            return 85;
        case 6:
            return 130;
        case 7:
            return 31;
        case 8:
            return 125;
        case 9:
            return 65;
        case 10:
            return 7600;
        case 11:
            return 350;
        case 12:
            return 110;
        case 13:
            return 35;
        case 14:
            return 825;
        case 15:
            return 225;
        case 16:
            return 90;
        default:
            return 0;
        }
    }

// The xp per hit point (the cave moray LEVEL/X.P. carries the roman II)
inline int mm2bcCStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 12;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 35;
        case 11:
            return 6;
        case 12:
            return 4;
        case 13:
            return 3;
        case 14:
            return 10;
        case 15:
            return 4;
        case 16:
            return 5;
        default:
            return 0;
        }
    }

// The % IN LAIR cell (Nil reads 0)
inline int mm2bcCStatLairPct(int b)
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
            return 100;
        case 6:
            return 100;
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
            return 0;
        case 15:
            return 0;
        case 16:
            return 35;
        default:
            return 0;
        }
    }

// The primary MOVE rate in inches (the domestic cat 5 settled from the
// capture table cell)
inline int mm2bcCStatMove(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 18;
        case 2:
            return 27;
        case 3:
            return 18;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 21;
        case 8:
            return 18;
        case 9:
            return 15;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 15;
        case 13:
            return 9;
        case 14:
            return 6;
        case 15:
            return 1;
        case 16:
            return 12;
        default:
            return 0;
        }
    }

// ---- the letters B and C printed grids (the R798 wiring) ----

// The bracket hit-dice number (6 through 12)
inline int mm2bcBarghestHd(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 12;
        default:
            return 0;
        }
    }

// The bracket hit-die bonus (6 through 12)
inline int mm2bcBarghestHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 12;
        default:
            return 0;
        }
    }

// The armor class (2 to -4, one place per additional hit die)
inline int mm2bcBarghestAC(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return -1;
        case 4:
            return -2;
        case 5:
            return -3;
        case 6:
            return -4;
        default:
            return 0;
        }
    }

// The magic resistance percent (5% per hit die, the pluses ignored)
inline int mm2bcBarghestMR(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 35;
        case 2:
            return 40;
        case 3:
            return 45;
        case 4:
            return 50;
        case 5:
            return 55;
        case 6:
            return 60;
        default:
            return 0;
        }
    }

// The LEVEL/X.P. base value of the bracket
inline int mm2bcBarghestXp(int b)
    {
        switch (b) {
        case 0:
            return 1275;
        case 1:
            return 2000;
        case 2:
            return 3450;
        case 3:
            return 3600;
        case 4:
            return 6100;
        case 5:
            return 6250;
        case 6:
            return 7300;
        default:
            return 0;
        }
    }

// The xp per hit point of the bracket
inline int mm2bcBarghestXpHp(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 14;
        case 3:
            return 14;
        case 4:
            return 16;
        case 5:
            return 16;
        case 6:
            return 18;
        default:
            return 0;
        }
    }

// The hit-dice rung (1 through 6)
inline int mm2bcBarkburrHd(int b)
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
        default:
            return 0;
        }
    }

// The base xp of the rung
inline int mm2bcBarkburrXp(int b)
    {
        switch (b) {
        case 0:
            return 45;
        case 1:
            return 65;
        case 2:
            return 90;
        case 3:
            return 125;
        case 4:
            return 165;
        case 5:
            return 275;
        default:
            return 0;
        }
    }

// The xp per hit point of the rung
inline int mm2bcBarkburrXpHp(int b)
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
        default:
            return 0;
        }
    }

// The band hit-dice low end
inline int mm2bcBloodthornHdLo(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 17;
        case 2:
            return 26;
        default:
            return 0;
        }
    }

// The band hit-dice high end
inline int mm2bcBloodthornHdHi(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 25;
        case 2:
            return 30;
        default:
            return 0;
        }
    }

// The tendril count of the band
inline int mm2bcBloodthornTendrils(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 8;
        case 2:
            return 12;
        default:
            return 0;
        }
    }

// The lash reach in feet
inline int mm2bcBloodthornRangeFt(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 7;
        default:
            return 0;
        }
    }

// The tendril hit-point low end (to sever)
inline int mm2bcBloodthornTvHpMin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 9;
        default:
            return 0;
        }
    }

// The tendril hit-point high end (to sever)
inline int mm2bcBloodthornTvHpMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

// The attacks-as hit dice
inline int mm2bcBloodthornAttacksAs(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        default:
            return 0;
        }
    }

// The percentile band low end
inline int mm2bcFelineLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 8;
        case 2:
            return 16;
        case 3:
            return 26;
        case 4:
            return 35;
        case 5:
            return 44;
        case 6:
            return 53;
        case 7:
            return 62;
        case 8:
            return 71;
        default:
            return 0;
        }
    }

// The percentile band high end
inline int mm2bcFelineHi(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 15;
        case 2:
            return 25;
        case 3:
            return 34;
        case 4:
            return 43;
        case 5:
            return 52;
        case 6:
            return 61;
        case 7:
            return 70;
        case 8:
            return 100;
        default:
            return 0;
        }
    }

// The minimum felines summoned
inline int mm2bcFelineMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 6;
        default:
            return 0;
        }
    }

// The maximum felines summoned
inline int mm2bcFelineMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 9;
        default:
            return 0;
        }
    }

// The percentile band low end
inline int mm2bcHumanLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 16;
        case 2:
            return 31;
        case 3:
            return 46;
        default:
            return 0;
        }
    }

// The percentile band high end
inline int mm2bcHumanHi(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 30;
        case 2:
            return 45;
        case 3:
            return 100;
        default:
            return 0;
        }
    }

// The minimum summons
inline int mm2bcHumanMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 7;
        case 3:
            return 31;
        default:
            return 0;
        }
    }

// The maximum summons
inline int mm2bcHumanMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 8;
        case 2:
            return 12;
        case 3:
            return 50;
        default:
            return 0;
        }
    }

}   // namespace rules
