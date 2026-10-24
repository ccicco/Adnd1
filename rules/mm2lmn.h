// =========================================================================================
// Adnd1 - rules/mm2lmn.h
// THE MM2 LETTERS LMN WALK - THE LAND LAMPREY, LUCK EATER, LYCANTHROPE,
// MAGMAN, MANDRAGORA, GIANT MANTIS, MANTRAP, MARGOYLE, MARID, SHADOW MASTIFF,
// MIHSTU, MINER, MINIMAL, MODRON, RUSSET MOLD, MONGRELMAN, MOON DOG,
// MUCKDWELLER, MUD-MAN, MYCONID, NEREID AND NARWHALE TURNS (the land lamprey
// and the luck eater p. 80, the lycanthropes pp. 80-82, the magman through
// the mihstu pp. 82-85, the miner and the minimal pp. 85-86, the modrons pp.
// 86-91, the russet mold pp. 91-92, the mongrelman through the myconid pp.
// 92-95, the nereid and the narwhale p. 95), promoted to the live registry;
// the LMN-FLIP round, the Letter L, the Letter M and the Letter N gap boxes
// all flip to closed
// census 730 -> 731.
//
// Round thirteen of the MM2 arc, the THIRD THREE-LETTER pass (the user
// multiple-letters Go call on the landed JK walk: the land lamprey opens p.
// 80 and the narwhale closes p. 95 - the LMN-FLIP round, the letters L, M and
// N all close together). The capture is the Curtiss PDF upload cross-checked
// against the archive.org djvu OCR and the 1eonline transcription, the
// contested cells settled book-internal first: the moon dog VII level, the
// minimal 1/2 move factor and the russet mold missing treasure line read
// against the capture and djvu misreads; every negative armor class rides
// unquoted - the hollyphant precedent
//
// LOADER SEMANTICS (the R805 grim lesson): the composite numAttacks strings
// load as their max clamped between the 1 floor and the 10 ceiling; the armor
// class composites read their first integer and the negative cells ride
// unquoted numbers; every Nil lair reads 0, every Standard and See below
// magic resistance reads 0; the move loads the first bare number; the flat-hp
// cells pin avgHp with hitDiceNum 0; the by_level defs carry no xp fields -
// the walk demands the loaded def equal the pin - walk patches may only touch
// real MonsterDef fields
//
namespace rules {

// ---- the MM2 letters LMN walk round pins (the R808 census) ----

// The MM2 letters LMN walk round: the land lamprey to narwhale turns, the
// THIRD THREE-LETTER pass (the user multiple-letters Go call on the landed JK
// walk)
inline int mm2lmnRound()
    { return 808; }

// The registry census before the R808 promotion (the landed R807 count)
inline int mm2lmnRegistryBefore()
    { return 661; }

// The registry census after the R808 promotion (38 defs)
inline int mm2lmnRegistryAfter()
    { return 699; }

// The .lua defs riding the R808 walk (pp. 80-95: the land lamprey through the
// narwhale)
inline int mm2lmnDefCount()
    { return 38; }

// The pin-time walk entry census (22 A-Z entry heads touched on pp. 80-95)
inline int mm2lmnEntryCount()
    { return 22; }

// The stat-block headings walked at pin time (every entry head carries stat
// blocks except the two doctrine heads and the table-only minimal head)
inline int mm2lmnStatBlockHeadings()
    { return 38; }

// The doctrine-only family heads riding the walk (the LYCANTHROPE family head
// and the MODRON family head)
inline int mm2lmnDoctrineHeads()
    { return 2; }

// The letter-L entries (the land lamprey, the luck eater and the lycanthrope
// family head, p. 80)
inline int mm2lmnLetterLHeadings()
    { return 3; }

// The letter-M entries (the magman through the myconid heads, pp. 82-94)
inline int mm2lmnLetterMHeadings()
    { return 17; }

// The letter-N entries (the nereid and the narwhale, p. 95)
inline int mm2lmnLetterNHeadings()
    { return 2; }

// The LmStats grid row count (the 38 letters-LMN stat blocks in print order)
inline int mm2lmnLmStatRows()
    { return 38; }

// The gap report closed-box census after the LMN-FLIP (16 + the letters L, M
// and N)
inline int mm2lmnGapClosed()
    { return 19; }

// The gap report open-box census after the LMN-FLIP (21 - 3)
inline int mm2lmnGapOpen()
    { return 18; }

// No letters-LMN key was already pinned at pin time (every one of the 38 keys
// collides with nothing)
inline int mm2lmnPriorOwnedEntries()
    { return 0; }

// The MODRON family stat blocks (the monodrone through the primus, pp. 87-91)
inline int mm2lmnModronBlocks()
    { return 15; }

// The by_level xp-source defs (the mandragora, the mongrelman and the myconid
// - the duergar precedent, the Variable/level-ladder xp cells)
inline int mm2lmnByLevelDefs()
    { return 3; }

// The LYCANTHROPE family stat blocks (the foxwoman, the seawolf greater and
// lesser, the wereshark)
inline int mm2lmnLycanthropeStatBlocks()
    { return 4; }

// The MinimalStats table row count (the 29 printed minimal-animal rows, p.
// 85)
inline int mm2lmnMinimalStatRows()
    { return 29; }

// The TelepathyMiles table row count (the hierarch telepathy ladder, p. 86:
// the decaton through the secundus)
inline int mm2lmnTelepathyMilesRows()
    { return 9; }

// The regtest audit-line census before the landing (the landed R807 count)
inline int mm2lmnCensusBefore()
    { return 730; }

// The regtest audit-line census after the landing
inline int mm2lmnCensusAfter()
    { return 731; }

// The first printed page of the walk (the land lamprey and the luck eater, p.
// 80)
inline int mm2lmnPrintOpensPage()
    { return 80; }

// The last printed page of the walk (the nereid and the narwhale, p. 95)
inline int mm2lmnPrintClosesPage()
    { return 95; }

// The modron wheel divides into 64 sectors, each sector with its own governor
// (p. 86)
inline int mm2lmnNirvanaSectors()
    { return 64; }

// Four sectors become a region, maintained by its ruler (p. 86)
inline int mm2lmnNirvanaSectorsPerRegion()
    { return 4; }

// Four regions are ruled by a viceroy as a single quarter (p. 86)
inline int mm2lmnNirvanaRegionsPerQuarter()
    { return 4; }

// There are 36 great armies on the plane of Nirvana, each commanded by a
// hexton (p. 87)
inline int mm2lmnNirvanaArmies()
    { return 36; }

// The modron brigade census: 70 officers, 192 NCOs, 252 messengers and 2628
// line troops, a total of 3142 (p. 87)
inline int mm2lmnNirvanaBrigadeTotal()
    { return 3142; }

// The brigade officers
inline int mm2lmnNirvanaBrigadeOfficers()
    { return 70; }

// The brigade NCOs
inline int mm2lmnNirvanaBrigadeNcos()
    { return 192; }

// The brigade messengers
inline int mm2lmnNirvanaBrigadeMessengers()
    { return 252; }

// The brigade line troops
inline int mm2lmnNirvanaBrigadeLineTroops()
    { return 2628; }

// Modrons slain anywhere return to the energy pool and re-form as new modrons
// in 9 days (p. 87)
inline int mm2lmnModronReformationDays()
    { return 9; }

// Each army comprises 4 corps, each corps led by 40 pentadrones in telepathic
// hookup (p. 87)
inline int mm2lmnModronCorpsPerArmy()
    { return 4; }

// Each corps has 2 divisions commanded by 20 pentadrones (p. 87)
inline int mm2lmnModronDivisionsPerCorps()
    { return 2; }

// Each division has 4 brigades led by 10 pentadrones (p. 87)
inline int mm2lmnModronBrigadesPerDivision()
    { return 4; }

// Each brigade has 4 regiments, the regiment the standard tactical unit led
// by 5 pentadrones (p. 87)
inline int mm2lmnModronRegimentsPerBrigade()
    { return 4; }

// All modrons save vs. cold, fire and acid attacks at +1 and take damage at
// -1 per die (p. 86)
inline int mm2lmnModronSaveBonusVsElements()
    { return 1; }

// The modrons are not affected by any illusions or magic that affects the
// mind - beguilement, charm, domination, hold, hypnosis and sleep the
// examples (p. 86)
inline bool mm2lmnModronImmuneToMindMagic()
    { return true; }

// The modrons are unaffected by attacks based in the Positive or Negative
// Planes, including life-draining or life-stealing (p. 86)
inline bool mm2lmnModronImmuneToEnergyDrain()
    { return true; }

// The modron hierarchs are never surprised and determine the initiative
// sequence in a melee round (p. 86)
inline bool mm2lmnModronHierarchsNeverSurprised()
    { return true; }

// The Primus telepathy row reads All Nirvana (the print table foot; every
// other hierarch carries its mileage pin)
inline bool mm2lmnModronPrimusAllNirvanaTelepathy()
    { return true; }

// ---- the land lamprey pins (the R808 MM2 letters LMN walk) ----

// The land lamprey xpValue (the II/36 + 2/hp cell: 36 + 5 x 2)
inline int mm2lmnLandLampreyXpValue()
    { return 46; }

// The land lamprey xp level (the II/36 + 2/hp cell)
inline int mm2lmnLandLampreyXpLevel()
    { return 2; }

// Once attached, a lamprey drains blood for 3 successive rounds
inline int mm2lmnLandLampreyDrainRounds()
    { return 3; }

// Each attached land lamprey encumbers the victim as a loss of 1 point of
// dexterity
inline int mm2lmnLandLampreyDexLossPerAttached()
    { return 1; }

// The land lamprey is only about 3-feet long
inline int mm2lmnLandLampreyLengthFeet()
    { return 3; }

// Land lampreys can be removed only by killing them or exposing them to fire
inline bool mm2lmnLandLampreyFireReleasesHold()
    { return true; }

// The land lamprey is a mutated version of the sea lamprey that breathes air
// and moves in snake-like fashion
inline bool mm2lmnLandLampreySnakeLikeMutant()
    { return true; }

// ---- the luck eater pins (the R808 MM2 letters LMN walk) ----

// The luck eater xpValue (the II/125 + 4/hp cell: 125 + 14 x 4)
inline int mm2lmnLuckEaterXpValue()
    { return 181; }

// The luck eater xp level (the II/125 + 4/hp cell)
inline int mm2lmnLuckEaterXpLevel()
    { return 2; }

// The purr affects all creatures within 30 feet
inline int mm2lmnLuckEaterPurrRangeFeet()
    { return 30; }

// The luck eater aura: a 10% (-2) penalty on all saving throws, damage and
// chances to hit
inline int mm2lmnLuckEaterPenaltyPct()
    { return 10; }

// The luck eater stays with its victims 2-5 hours
inline int mm2lmnLuckEaterStayHoursMin()
    { return 2; }

// The stay ceiling
inline int mm2lmnLuckEaterStayHoursMax()
    { return 5; }

// The starved aura makes the benefactors fight among themselves for 10 rounds
// or until a death occurs
inline int mm2lmnLuckEaterBrawlRounds()
    { return 10; }

// The previously attracted regain their senses 1-6 turns after the luck eater
// leaves
inline int mm2lmnLuckEaterSensesReturnTurnsMax()
    { return 6; }

// The deceptive form of the luck eater is that of a golden-furred cat
inline bool mm2lmnLuckEaterGoldenFurredCat()
    { return true; }

// The luck eater surprises on 1-4
inline bool mm2lmnLuckEaterSurprisesOnOneToFour()
    { return true; }

// ---- the lycanthrope doctrine pins (the R808 MM2 letters LMN walk) ----

// In periods with a full moon lycanthropes are 90% likely to be compelled to
// assume their alter-shape (p. 80)
inline int mm2lmnLycanthropeFullMoonPct()
    { return 90; }

// Belladonna eaten within 1 hour cures the bite affliction 25% of the time
// (p. 80)
inline int mm2lmnLycanthropeBelladonnaCurePct()
    { return 25; }

// Otherwise a cure disease from a 12th or higher level patriarch must be
// placed within 3 days (p. 80)
inline int mm2lmnLycanthropeCurePatriarchLevel()
    { return 12; }

// A humanoid bitten for damage equal to or greater than 50% of its total
// potential is infected (p. 80)
inline int mm2lmnLycanthropeInfectionDamagePct()
    { return 50; }

// The uncured victim becomes a lycanthrope in 7-14 days (p. 80)
inline int mm2lmnLycanthropeOnsetDaysMin()
    { return 7; }

// The onset ceiling
inline int mm2lmnLycanthropeOnsetDaysMax()
    { return 14; }

// There is a 1% chance that the poison in the belladonna will kill (p. 80)
inline int mm2lmnLycanthropeBelladonnaPoisonDeathPct()
    { return 1; }

// The belladonna infusion incapacitates the victim for 1-4 days (p. 80)
inline int mm2lmnLycanthropeBelladonnaIncapacitateDaysMax()
    { return 4; }

// During the hours of darkness lycanthropes most commonly shape change to
// their animal form (p. 80)
inline bool mm2lmnLycanthropeDarknessShapeChange()
    { return true; }

// Each type knows its own language in addition to Common (p. 80)
inline bool mm2lmnLycanthropeKnowsOwnTonguePlusCommon()
    { return true; }

// ---- the foxwoman pins (the R808 MM2 letters LMN walk) ----

// The foxwoman xpValue (the VII/1700 + 12/hp cell: 1700 + 29 x 12)
inline int mm2lmnFoxwomanXpValue()
    { return 2048; }

// The foxwoman xp level (the VII/1700 + 12/hp cell; the capture "VIl" the OCR
// misread)
inline int mm2lmnFoxwomanXpLevel()
    { return 7; }

// Foxwomen assume 3 forms rather than the standard 2: the silver fox, the
// vixen and the elven woman
inline int mm2lmnFoxwomanForms()
    { return 3; }

// The foxwoman always has 2-5 charmed males as servants and companions
inline int mm2lmnFoxwomanCharmedMalesMin()
    { return 2; }

// The males ceiling
inline int mm2lmnFoxwomanCharmedMalesMax()
    { return 5; }

// Foxwomen have infravision (6") in all forms
inline int mm2lmnFoxwomanInfravisionInches()
    { return 6; }

// The males may be elven (25%), human (25%) or half-elven (50%)
inline int mm2lmnFoxwomanHalfElvenMalesPct()
    { return 50; }

// The vixen bite infects elven and half-elven females who become foxwomen
// within 3 days unless both cure disease and remove curse are used
inline int mm2lmnFoxwomanVixenInfectionDays()
    { return 3; }

// In elven woman form a foxwoman is 90% resistant to sleep and charm spells
inline int mm2lmnFoxwomanSleepCharmResistPct()
    { return 90; }

// In elven woman form the foxwoman has a comeliness rating of 21 with respect
// to human and demihuman males
inline int mm2lmnFoxwomanComeliness()
    { return 21; }

// The stolen elven girl child is 6-13 (1d8+4) years of age; at 12 or 13 she
// is a normal foxwoman
inline int mm2lmnFoxwomanStolenChildAgeMax()
    { return 13; }

// The "2 or 4 or 6" composite armor class: the best form 2, the elven woman
// 4, the vixen 6 - the loader reads the head 2
inline int mm2lmnFoxwomanArmorForms()
    { return 6; }

// Foxwomen can inflict lycanthropy only in their vixen form
inline bool mm2lmnFoxwomanInfectsOnlyInVixenForm()
    { return true; }

// In silver fox form the foxwoman can pass without trace, as the spell
inline bool mm2lmnFoxwomanSilverFoxPassWithoutTrace()
    { return true; }

// ---- the seawolf pins (the R808 MM2 letters LMN walk) ----

// The greater seawolf xpValue (the VI/900 + 12/hp cell: 900 + 33 x 12)
inline int mm2lmnSeawolfGreaterXpValue()
    { return 1296; }

// The greater seawolf xp level (the VI/900 + 12/hp cell)
inline int mm2lmnSeawolfGreaterXpLevel()
    { return 6; }

// The lesser seawolf xpValue (the II/50 + 3/hp cell: 50 + 9 x 3)
inline int mm2lmnSeawolfLesserXpValue()
    { return 77; }

// The lesser seawolf xp level (the II/50 + 3/hp cell)
inline int mm2lmnSeawolfLesserXpLevel()
    { return 2; }

// Seawolves stay submerged 17-24 minutes
inline int mm2lmnSeawolfGreaterSubmergedMinutesMin()
    { return 17; }

// The submersion ceiling
inline int mm2lmnSeawolfGreaterSubmergedMinutesMax()
    { return 24; }

// Non-fatal bites cause seawolf lycanthropy in 2-5 days
inline int mm2lmnSeawolfGreaterInfectionDaysMin()
    { return 2; }

// The infection ceiling
inline int mm2lmnSeawolfGreaterInfectionDaysMax()
    { return 5; }

// The lesser seawolf has 2 forms: the porpoise-shaped mammal and the wolfman
inline int mm2lmnSeawolfLesserForms()
    { return 2; }

// Humans taking 50% or more damage from lesser seawolves contract this form
// of lycanthropy
inline int mm2lmnSeawolfLesserInfectionDamagePct()
    { return 50; }

// Iron weapons as well as silver and magic ones harm the greater seawolf
inline bool mm2lmnSeawolfGreaterIronWeaponsHarm()
    { return true; }

// Unlike other lycanthropes, seawolves can be hit by normal weapons
inline bool mm2lmnSeawolfLesserHitByNormalWeapons()
    { return true; }

// The lesser seawolf wolfman-form statistics are given in parentheses in the
// stat block
inline bool mm2lmnSeawolfLesserWolfmanStatsInParens()
    { return true; }

// ---- the wereshark pins (the R808 MM2 letters LMN walk) ----

// The wereshark xpValue (the VII/1500 + 14/hp cell: 1500 + 38 x 14)
inline int mm2lmnWeresharkXpValue()
    { return 2032; }

// The wereshark xp level (the VII/1500 + 14/hp cell)
inline int mm2lmnWeresharkXpLevel()
    { return 7; }

// The wereshark lair is always guarded by 2-5 normal sharks, whether or not
// the monster is personally present
inline int mm2lmnWeresharkGuardSharksMin()
    { return 2; }

// The guards ceiling
inline int mm2lmnWeresharkGuardSharksMax()
    { return 5; }

// The "% IN LAIR: 20% (if underwater)" composite: the lairPct pins the
// numeric 20
inline int mm2lmnWeresharkLairPctIfUnderwater()
    { return 20; }

// Weresharks are found only in tropical areas
inline bool mm2lmnWeresharkTropicalOnly()
    { return true; }

// The wereshark takes shark form whenever it chooses, as long as it is in
// darkness
inline bool mm2lmnWeresharkChangesInDarkness()
    { return true; }

// In shark form the creatures are huge and resemble great white sharks
inline bool mm2lmnWeresharkGreatWhiteForm()
    { return true; }

// ---- the magman pins (the R808 MM2 letters LMN walk) ----

// The magman xpValue (the III/97 + 2/hp cell: 97 + 7 x 2)
inline int mm2lmnMagmanXpValue()
    { return 111; }

// The magman xp level (the III/97 + 2/hp cell)
inline int mm2lmnMagmanXpLevel()
    { return 3; }

// The combustion touch burns for 1-8 points of damage each round
inline int mm2lmnMagmanBurnDamageMax()
    { return 8; }

// The burning lasts 3-6 (1d4+2) rounds
inline int mm2lmnMagmanBurnRoundsMin()
    { return 3; }

// The burn ceiling
inline int mm2lmnMagmanBurnRoundsMax()
    { return 6; }

// A cornered magman strikes with a molten fist for 3-24 points of damage
inline int mm2lmnMagmanFistDamageMax()
    { return 24; }

// A magman can stay out of lava for only 6 hours before it stiffens and
// becomes immobile
inline int mm2lmnMagmanOutOfLavaHours()
    { return 6; }

// Magmen are 3-foot tall, glowing, human-shaped creatures
inline int mm2lmnMagmanHeightFeet()
    { return 3; }

// A +1 or better weapon is required to hit a magman
inline bool mm2lmnMagmanPlusOneToHit()
    { return true; }

// Any weapon of less than a +2 bonus that contacts a magman will melt
inline bool mm2lmnMagmanNonPlusTwoMelts()
    { return true; }

// Magmen are immune to all fire-based attacks
inline bool mm2lmnMagmanImmuneToFire()
    { return true; }

// The magmen are creatures of the Para-elemental Plane of Heat
inline bool mm2lmnMagmanParaElementalHeatNative()
    { return true; }

// ---- the mandragora pins (the R808 MM2 letters LMN walk) ----

// Full daylight stuns the mandragoras for 1-4 segments
inline int mm2lmnMandragoraDaylightStunSegmentsMin()
    { return 1; }

// The stun ceiling
inline int mm2lmnMandragoraDaylightStunSegmentsMax()
    { return 4; }

// The strangulation damage: 1-4 points per round
inline int mm2lmnMandragoraStrangleDamageMax()
    { return 4; }

// The mandragora always senses creatures within 120 feet
inline int mm2lmnMandragoraSenseRangeFeet()
    { return 120; }

// The mandragora lair census: 45% in lair
inline int mm2lmnMandragoraLairPct()
    { return 45; }

// The mandragora LEVEL/X.P. VALUE reads Variable - the by_level xp source
// (the duergar precedent; the 1+1 or 2+2 size ladder)
inline bool mm2lmnMandragoraByLevelXp()
    { return true; }

// Any to-hit score of 20 indicates a neck/throat hit that causes
// strangulation
inline bool mm2lmnMandragoraThroatHitOnTwenty()
    { return true; }

// The always-wet mandragora suffers only half damage from all forms of fire
inline bool mm2lmnMandragoraHalfDamageFromFire()
    { return true; }

// Being vegetable, the mandragora is not affected by spells which normally
// affect animals; sleep spells have no effect
inline bool mm2lmnMandragoraSleepImmune()
    { return true; }

// ---- the giant mantis pins (the R808 MM2 letters LMN walk) ----

// The giant mantis xpValue (the VII/1350 + 14/hp cell: 1350 + 35 x 14)
inline int mm2lmnGiantMantisXpValue()
    { return 1840; }

// The giant mantis xp level (the VII/1350 + 14/hp cell)
inline int mm2lmnGiantMantisXpLevel()
    { return 7; }

// The 2 vise-like forelimbs inflict 2-12 points and hold prey with under 19
// strength
inline int mm2lmnGiantMantisForelimbDamageMax()
    { return 12; }

// The next-round mandible bite inflicts 3-12 points
inline int mm2lmnGiantMantisBiteDamageMax()
    { return 12; }

// The forelimbs hold fast prey with under 19 strength
inline int mm2lmnGiantMantisHoldStrength()
    { return 19; }

// It is 75% probable that a mantis will attack by surprise
inline int mm2lmnGiantMantisSurprisePct()
    { return 75; }

// The towering giant mantis is 12 feet tall
inline int mm2lmnGiantMantisHeightFeet()
    { return 12; }

// A mantis recognizing danger stays still and avoids detection 75% of the
// time
inline bool mm2lmnGiantMantisAvoidDetectionPct()
    { return true; }

// ---- the mantrap pins (the R808 MM2 letters LMN walk) ----

// The mantrap xpValue (the V/275 + 6/hp cell: 275 + 14 x 6)
inline int mm2lmnMantrapXpValue()
    { return 359; }

// The mantrap xp level (the V/275 + 6/hp cell)
inline int mm2lmnMantrapXpLevel()
    { return 5; }

// The pollen fascinates all creatures within 60 feet during daylight hours
inline int mm2lmnMantrapPollenRangeFeet()
    { return 60; }

// The plant carries 2-5 leaf traps
inline int mm2lmnMantrapLeafTrapsMin()
    { return 2; }

// The leaf-trap ceiling
inline int mm2lmnMantrapLeafTrapsMax()
    { return 5; }

// The fascination cannot be dispelled until the odor sours 24 hours later or
// the plant is burned
inline int mm2lmnMantrapFascinationSourHours()
    { return 24; }

// The mantrap is always in its lair: 100%
inline int mm2lmnMantrapLairPct()
    { return 100; }

// The acidic secretion inflicts points per round equal to the victim armor
// class, a minimum of 1
inline bool mm2lmnMantrapAcidDamageEqualsAc()
    { return true; }

// Items exposed to the acid save once per turn; all metal receives a +2 bonus
inline bool mm2lmnMantrapMetalSaveBonus()
    { return true; }

// The victims cannot be pulled free until the plant is dead
inline bool mm2lmnMantrapVictimHeldUntilPlantDies()
    { return true; }

// ---- the margoyle pins (the R808 MM2 letters LMN walk) ----

// The margoyle xpValue (the V/350 + 6/hp cell: 350 + 21 x 6)
inline int mm2lmnMargoyleXpValue()
    { return 476; }

// The margoyle xp level (the V/350 + 6/hp cell)
inline int mm2lmnMargoyleXpLevel()
    { return 5; }

// The stone-like substance: an 80% probability of going undetected when
// lurking against rock
inline int mm2lmnMargoyleLurkUndetectedPct()
    { return 80; }

// Margoyles are sometimes (20%) found with their lesser kin, gargoyles, as
// masters or leaders
inline int mm2lmnMargoyleGargoyleKinPct()
    { return 20; }

// The margoyle attack load: 2 claws, a pair of horns and a bite with stony
// fangs
inline int mm2lmnMargoyleAttacks()
    { return 4; }

// Only magic weapons equal to or better than +1 will harm a margoyle
inline bool mm2lmnMargoylePlusOneWeaponNeeded()
    { return true; }

// The margoyle language is similar to that of gargoyles and they speak the
// tongue of the latter well enough
inline bool mm2lmnMargoyleSpeaksGargoyleTongue()
    { return true; }

// ---- the marid pins (the R808 MM2 letters LMN walk) ----

// The marid xpValue (the VIII/5000 flat cell: no xp/hp adder, 5000 + 45 x 0)
inline int mm2lmnMaridXpValue()
    { return 5000; }

// The marid xp level (the VIII/5000 cell)
inline int mm2lmnMaridXpLevel()
    { return 8; }

// A marid can freely carry 10,000 gp in weight
inline int mm2lmnMaridCarryGold()
    { return 10000; }

// Marids perform at a level of spell use equal to 26th
inline int mm2lmnMaridSpellLevel()
    { return 26; }

// Once per year a marid can use an alter reality
inline int mm2lmnMaridAlterRealityPerYear()
    { return 1; }

// The water jet causes 1-6 points damage
inline int mm2lmnMaridJetDamageMax()
    { return 6; }

// The jet reaches up to 6" long
inline int mm2lmnMaridJetRangeInches()
    { return 6; }

// Double the free-carry weight causes tiring in but 3 turns
inline int mm2lmnMaridTiringTurns()
    { return 3; }

// A tired marid must rest for 6 turns
inline int mm2lmnMaridRestTurns()
    { return 6; }

// Marids can do the following up to 7 times per day: gaseous form, lower
// water, part water, wall of fog, bestow water breathing
inline int mm2lmnMaridUpToSevenPerDay()
    { return 7; }

// A marid is the most powerful of all geniekind
inline bool mm2lmnMaridMostPowerfulGenie()
    { return true; }

// Marids are not harmed by water-based spells
inline bool mm2lmnMaridWaterSpellsHarmless()
    { return true; }

// Steam does not harm marids
inline bool mm2lmnMaridSteamHarmless()
    { return true; }

// Marids speak all languages through a form of ESP
inline bool mm2lmnMaridSpeaksAllLanguagesByEsp()
    { return true; }

// ---- the shadow mastiff pins (the R808 MM2 letters LMN walk) ----

// The shadow mastiff xpValue (the IV/185 + 4/hp cell: 185 + 14 x 4)
inline int mm2lmnShadowMastiffXpValue()
    { return 241; }

// The shadow mastiff xp level (the IV/185 + 4/hp cell)
inline int mm2lmnShadowMastiffXpLevel()
    { return 4; }

// In shadowy conditions a shadow mastiff can blend so it is 40% unlikely to
// be seen
inline int mm2lmnShadowMastiffShadowUnseenPct()
    { return 40; }

// In bright light it loses 50% of its normal movement ability and cannot use
// shadows for concealment
inline int mm2lmnShadowMastiffBrightLightMoveLossPct()
    { return 50; }

// The lair of a pack is 50% likely to contain 2-5 whelps
inline int mm2lmnShadowMastiffLairWhelpPct()
    { return 50; }

// The whelp range floor
inline int mm2lmnShadowMastiffWhelpsMin()
    { return 2; }

// The whelp range ceiling
inline int mm2lmnShadowMastiffWhelpsMax()
    { return 5; }

// The whelps sell for from 200-500 gp each
inline int mm2lmnShadowMastiffWhelpPriceMin()
    { return 200; }

// The whelp price ceiling
inline int mm2lmnShadowMastiffWhelpPriceMax()
    { return 500; }

// The shadow mastiffs are normally encountered on the Plane of Shadow
inline bool mm2lmnShadowMastiffPlaneOfShadowNative()
    { return true; }

// The baying of a pack causes panic, flight directly away while dropping any
// held item, unless a save vs. spells is made
inline bool mm2lmnShadowMastiffBayingCausesPanic()
    { return true; }

// ---- the mihstu pins (the R808 MM2 letters LMN walk) ----

// The mihstu xpValue (the VII/1700 + 12/hp cell: 1700 + 30 x 12)
inline int mm2lmnMihstuXpValue()
    { return 2060; }

// The mihstu xp level (the VII/1700 + 12/hp cell)
inline int mm2lmnMihstuXpLevel()
    { return 7; }

// When attacking, a mihstu forms 4 solid tentacles tipped with razor-sharp
// talons
inline int mm2lmnMihstuTentacles()
    { return 4; }

// The misty envelope drains 1 constitution point per round; at 0 death occurs
inline int mm2lmnMihstuConDrainPerRound()
    { return 1; }

// One point of constitution may be regained per full day of rest
inline int mm2lmnMihstuConRegainedPerDay()
    { return 1; }

// Cold-based attacks only stun a mihstu for 2d6 rounds
inline int mm2lmnMihstuColdStunRoundsMax()
    { return 12; }

// Mihstu can be harmed only by +2 or better weapons
inline bool mm2lmnMihstuPlusTwoWeaponsNeeded()
    { return true; }

// Mihstu are immune to all electrical and missile attacks, even magic missile
inline bool mm2lmnMihstuImmuneElectricalAndMissile()
    { return true; }

// Mihstu may perform tasks for powerful magic-users in exchange for
// substantial payment of powerful magic items
inline bool mm2lmnMihstuServesForMagicItems()
    { return true; }

// ---- the miner pins (the R808 MM2 letters LMN walk) ----

// The miner xpValue (the VI/1000 + 14/hp cell: 1000 + 35 x 14)
inline int mm2lmnMinerXpValue()
    { return 1490; }

// The miner xp level (the VI/1000 + 14/hp cell)
inline int mm2lmnMinerXpLevel()
    { return 6; }

// Passing creatures step upon the twig-like barbs 75% of the time if
// surprised
inline int mm2lmnMinerStepPctIfSurprised()
    { return 75; }

// Otherwise 25% per creature passing
inline int mm2lmnMinerStepPctOtherwise()
    { return 25; }

// Unsurprised druids and rangers identify the barbs at a 5% chance per
// character level
inline int mm2lmnMinerIdentifyPctPerLevel()
    { return 5; }

// The poisonous barbs paralyze for 2-40 turns, save vs. poison negates
inline int mm2lmnMinerParalysisTurnsMin()
    { return 2; }

// The paralysis ceiling
inline int mm2lmnMinerParalysisTurnsMax()
    { return 40; }

// The central dorsal ridge is lined with 6-25 brown barbs
inline int mm2lmnMinerBarbsMin()
    { return 6; }

// The barb ceiling
inline int mm2lmnMinerBarbsMax()
    { return 25; }

// The miner is a relative of the trapper, adapted to woodland survival
inline bool mm2lmnMinerTrapperRelative()
    { return true; }

// The miner will not reveal its presence until all surface vibrations have
// ceased
inline bool mm2lmnMinerWaitsForStillness()
    { return true; }

// ---- the minimal doctrine pins (the R808 MM2 letters LMN walk) ----

// The minimal MOVE cell: as full size multiplied by 1/2, rounded up (the djvu
// "Va" the misread - the settled 1/2; 1eonline 2/3 its error)
inline int mm2lmnMinimalMoveFactorPct()
    { return 50; }

// The minimal armor class: as full size +2 (worse)
inline int mm2lmnMinimalAcPenalty()
    { return 2; }

// The minimal damage: not to exceed 3-6 points of damage from any single form
inline int mm2lmnMinimalDamageCapMin()
    { return 3; }

// The damage cap ceiling
inline int mm2lmnMinimalDamageCapMax()
    { return 6; }

// The minimal MAGIC RESISTANCE cell: +2 vs. all attack forms vs. level
// equivalent
inline int mm2lmnMinimalSaveBonus()
    { return 2; }

// Minimals gain +4 to saving throws vs. any spell that will charm them,
// including animal friendship
inline int mm2lmnMinimalCharmSaveBonus()
    { return 4; }

// The minimal % IN LAIR: as full size plus 10%
inline int mm2lmnMinimalLairPctBonus()
    { return 10; }

// In a locale where minimals exist they are 80% likely to be the only type of
// mammal in the area
inline int mm2lmnMinimalOnlyMammalPct()
    { return 80; }

// Minimals are found with brownies, pixies, dryads, leprechauns etc. 30%
// likely in a truly isolated locale
inline int mm2lmnMinimalIsolatedKinPct()
    { return 30; }

// The minimal hit dice run as low as 1/4 hit dice and as high as 3+4 hit dice
inline int mm2lmnMinimalMaxHitDice()
    { return 3; }

// The hit-dice ceiling bonus
inline int mm2lmnMinimalMaxHitDiceBonus()
    { return 4; }

// The minimal treasure: 40% for J, K, L, M or N plus 5% for magic
inline int mm2lmnMinimalLairMagicPct()
    { return 5; }

// The J-N letter chance
inline int mm2lmnMinimalTreasureLettersPct()
    { return 40; }

// The minimal lion New HD prints "13" - the 1+3 misprint kept verbatim in the
// table read
inline int mm2lmnMinimalLionHdBonus()
    { return 3; }

// Minimals cannot and will not be familiar under any circumstances
inline bool mm2lmnMinimalNeverFamiliars()
    { return true; }

// Surprise is more likely for carnivores: +1 on such chances
inline bool mm2lmnMinimalCarnivoreSurpriseBonus()
    { return true; }

// Minimals are more difficult to surprise by +1
inline bool mm2lmnMinimalDifficultToSurprise()
    { return true; }

// ---- the modron base-block pins (the R808 MM2 letters LMN walk) ----

// The monodrone xpValue (the II/28 + 2/hp cell: 28 + 4 x 2)
inline int mm2lmnMonodroneXpValue()
    { return 36; }

// The monodrone xp level (the II/28 + 2/hp cell)
inline int mm2lmnMonodroneXpLevel()
    { return 2; }

// Monodrones are usually assembled in units of 12 and supervised by a
// duodrone or tridrone
inline int mm2lmnMonodroneUnitsOf()
    { return 12; }

// The winged messenger monodrones relay perfectly any message of up to 48
// words
inline int mm2lmnMonodroneMessengerWordLimit()
    { return 48; }

// Monodrones have a limited form of infravision (30-foot range)
inline int mm2lmnMonodroneInfravisionFeet()
    { return 30; }

// The duodrone xpValue (the II/50 + 3/hp cell: 50 + 9 x 3)
inline int mm2lmnDuodroneXpValue()
    { return 77; }

// The duodrone xp level (the II/50 + 3/hp cell)
inline int mm2lmnDuodroneXpLevel()
    { return 2; }

// A duodrone is capable of supervising 12 units of monodrones
inline int mm2lmnDuodroneSupervisesMonodroneUnits()
    { return 12; }

// Duodrones have senses equal to most humans and infravision at the normal 90
// feet
inline int mm2lmnDuodroneInfravisionFeet()
    { return 90; }

// The tridrone xpValue (the III/85 + 4/hp cell: 85 + 13 x 4)
inline int mm2lmnTridroneXpValue()
    { return 137; }

// The tridrone xp level (the III/85 + 4/hp cell)
inline int mm2lmnTridroneXpLevel()
    { return 3; }

// Tridrones supervise gross units of 144 monodrones and duodrones
inline int mm2lmnTridroneSupervises()
    { return 144; }

// The tridrone guard units carry 3 javelins per being, hurled before entering
// melee
inline int mm2lmnTridroneJavelins()
    { return 3; }

// Tridrones have infravision and ultravision, 90 feet and 100 yards
// respectively
inline int mm2lmnTridroneUltravisionYards()
    { return 100; }

// The quadrone xpValue (the IV/165 + 5/hp cell: 165 + 18 x 5)
inline int mm2lmnQuadroneXpValue()
    { return 255; }

// The quadrone xp level (the IV/165 + 5/hp cell)
inline int mm2lmnQuadroneXpLevel()
    { return 4; }

// All quadrones have senses equal to 150% human normal
inline int mm2lmnQuadroneSensesPct()
    { return 150; }

// The quadrone infravision: 180-foot range
inline int mm2lmnQuadroneInfravisionFeet()
    { return 180; }

// The quadrone ultravision: 200-yard range
inline int mm2lmnQuadroneUltravisionYards()
    { return 200; }

// The pentadrone xpValue (the V/350 + 7/hp cell: 350 + 22 x 7)
inline int mm2lmnPentadroneXpValue()
    { return 504; }

// The pentadrone xp level (the V/350 + 7/hp cell)
inline int mm2lmnPentadroneXpLevel()
    { return 5; }

// The paralysis gas stream: 2 feet in diameter
inline int mm2lmnPentadroneGasStreamDiameterFeet()
    { return 2; }

// The paralysis gas stream: 5 feet in length
inline int mm2lmnPentadroneGasStreamLengthFeet()
    { return 5; }

// Creatures caught in the stream that fail vs. paralysis remain immobile for
// 5 rounds
inline int mm2lmnPentadroneParalysisRounds()
    { return 5; }

// The gas stream: no more than once every 5 turns
inline int mm2lmnPentadroneGasCooldownTurns()
    { return 5; }

// The gas stream: 5 times per day
inline int mm2lmnPentadroneGasPerDay()
    { return 5; }

// Pentadrones stand temperature extremes of 210 degrees to -100 degrees F.
// without discomfort
inline int mm2lmnPentadroneTempMaxF()
    { return 210; }

// The temperature floor
inline int mm2lmnPentadroneTempMinF()
    { return -100; }

// A dozen pentadrones are assigned to each regimental headquarters as an
// elite unit
inline int mm2lmnPentadroneRegimentalDozen()
    { return 12; }

// One twelfth of all monodrones lack the spider-like arms and have fan-like
// wings
inline bool mm2lmnMonodroneOneTwelfthWinged()
    { return true; }

// The cubic quadrones are excellent archers, capable of wielding 2 bows at
// the same time
inline bool mm2lmnQuadroneTwoBows()
    { return true; }

// As they have sensory organs on all 6 sides, quadrones are never surprised
// under normal circumstances
inline bool mm2lmnQuadroneNeverSurprised()
    { return true; }

// The pentadrones use the gas to levitate as 5th-level magic-users
inline bool mm2lmnPentadroneGasLevitation()
    { return true; }

// Only magical weapons of +1 or better will harm pentadrones
inline bool mm2lmnPentadronePlusOneWeaponNeeded()
    { return true; }

// ---- the modron hierarch pins (the R808 MM2 letters LMN walk) ----

// The decaton xpValue (the VII/2550 + 14/hp cell: 2550 + 45 x 14)
inline int mm2lmnDecatonXpValue()
    { return 3180; }

// The decaton xp level (the VII/2550 + 14/hp cell)
inline int mm2lmnDecatonXpLevel()
    { return 7; }

// There are exactly 100 decatons, the lowest order of officials in Nirvana
inline int mm2lmnDecatonCount()
    { return 100; }

// One decaton serves each sector while the remaining 36 serve with the
// hextons commanding the armed forces
inline int mm2lmnDecatonWithHextons()
    { return 36; }

// Decatons have spell ability equal to a 10th-level cleric
inline int mm2lmnDecatonClericLevel()
    { return 10; }

// The decaton cures 1 hp of damage for all modrons within 144 feet
inline int mm2lmnDecatonCureRadiusFeet()
    { return 144; }

// The decaton cure disease works in a 12-foot radius
inline int mm2lmnDecatonCureDiseaseRadiusFeet()
    { return 12; }

// The decaton heals on touch up to 10 modrons per round
inline int mm2lmnDecatonHealPerRound()
    { return 10; }

// The nonaton xpValue (the VIII/5250 + 16/hp cell: 5250 + 49 x 16)
inline int mm2lmnNonatonXpValue()
    { return 6034; }

// The nonaton xp level (the VIII/5250 + 16/hp cell)
inline int mm2lmnNonatonXpLevel()
    { return 8; }

// There are 81 nonatons, the principal overseers of law and order
inline int mm2lmnNonatonCount()
    { return 81; }

// Nonatons have spell-use as clerics of the 12th level
inline int mm2lmnNonatonClericLevel()
    { return 12; }

// Each nonaton has 12 pentadrone lieutenants
inline int mm2lmnNonatonPentadroneLieutenants()
    { return 12; }

// The nonaton psionic ability: 199
inline int mm2lmnNonatonPsionicScore()
    { return 199; }

// The octon xpValue (the VIII/5250 + 16/hp cell: 5250 + 54 x 16)
inline int mm2lmnOctonXpValue()
    { return 6114; }

// The octon xp level (the VIII/5250 + 16/hp cell)
inline int mm2lmnOctonXpLevel()
    { return 8; }

// Each of the 64 octons is in charge of a sector of the Plane of Nirvana
inline int mm2lmnOctonCount()
    { return 64; }

// The octons use spells as 14th-level clerics
inline int mm2lmnOctonClericLevel()
    { return 14; }

// The octon telekinesis: 3500 gp weight
inline int mm2lmnOctonTelekinesisGold()
    { return 3500; }

// The octon personal staff: 1728 monodrones
inline int mm2lmnOctonStaffMonodrones()
    { return 1728; }

// The octon personal staff: 256 duodrones
inline int mm2lmnOctonStaffDuodrones()
    { return 256; }

// The octon personal staff: 81 tridrones
inline int mm2lmnOctonStaffTridrones()
    { return 81; }

// The octon personal staff: 16 quadrones
inline int mm2lmnOctonStaffQuadrones()
    { return 16; }

// The octon personal staff: 5 pentadrones and 1 decaton and 1 nonaton
inline int mm2lmnOctonStaffPentadrones()
    { return 5; }

// The septon xpValue (the IX/8250 + 18/hp cell: 8250 + 58 x 18)
inline int mm2lmnSeptonXpValue()
    { return 9294; }

// The septon xp level (the IX/8250 + 18/hp cell)
inline int mm2lmnSeptonXpLevel()
    { return 9; }

// There are 49 septons, the officials who maintain order and inspect work and
// records
inline int mm2lmnSeptonCount()
    { return 49; }

// Septons have clerical spells at the 16th level
inline int mm2lmnSeptonClericLevel()
    { return 16; }

// Septons have magic-user spells at the 12th level
inline int mm2lmnSeptonMagicUserLevel()
    { return 12; }

// Each septon has 7 senses which operate continuously: hearing, sight, smell,
// taste, touch, ESP and detect magic
inline int mm2lmnSeptonSenses()
    { return 7; }

// The septon ESP range: 30 feet
inline int mm2lmnSeptonEspRangeFeet()
    { return 30; }

// One septon serves each quinton, 4 serve each secundus, and 8 serve The One
// directly
inline int mm2lmnSeptonsServingPrimus()
    { return 8; }

// The hexton xpValue (the IX/8250 + 18/hp cell: 8250 + 63 x 18)
inline int mm2lmnHextonXpValue()
    { return 9384; }

// The hexton xp level (the IX/8250 + 18/hp cell)
inline int mm2lmnHextonXpLevel()
    { return 9; }

// There are 36 hextons, each a general in charge of 1 of the armies of
// Nirvana
inline int mm2lmnHextonCount()
    { return 36; }

// Hextons use spells as 18th-level clerics
inline int mm2lmnHextonClericLevel()
    { return 18; }

// There is a 75% chance that any hexton will be accompanied by his guard
inline int mm2lmnHextonGuardChancePct()
    { return 75; }

// The hexton guard staff of special pentadrones numbers 12-48
inline int mm2lmnHextonGuardMin()
    { return 12; }

// The guard ceiling
inline int mm2lmnHextonGuardMax()
    { return 48; }

// The quinton xpValue (the X/10,950 + 20/hp cell: 10950 + 67 x 20)
inline int mm2lmnQuintonXpValue()
    { return 12290; }

// The quinton xp level (the X/10,950 + 20/hp cell)
inline int mm2lmnQuintonXpLevel()
    { return 10; }

// There are 25 quintons, the major bureau chiefs and record keepers of
// Nirvana
inline int mm2lmnQuintonCount()
    { return 25; }

// Quintons may cast spells as 20th-level clerics
inline int mm2lmnQuintonClericLevel()
    { return 20; }

// Each quinton has a septon and a staff of 25 pentadrones
inline int mm2lmnQuintonPentadroneStaff()
    { return 25; }

// There are 5 main bureaus in Primus Tower at the capitol, each headed by a
// quinton
inline int mm2lmnQuintonBureausInPrimusTower()
    { return 5; }

// The quinton staff: 64 quadrones
inline int mm2lmnQuintonQuadroneStaff()
    { return 64; }

// The quinton staff: 81 tridrones
inline int mm2lmnQuintonTridroneStaff()
    { return 81; }

// The quarton xpValue (the X/10,950 + 20/hp cell: 10950 + 72 x 20)
inline int mm2lmnQuartonXpValue()
    { return 12390; }

// The quarton xp level (the X/10,950 + 20/hp cell)
inline int mm2lmnQuartonXpLevel()
    { return 10; }

// There are 16 quartons, the rulers of the regions of Nirvana
inline int mm2lmnQuartonCount()
    { return 16; }

// Quartons cast spells as 22nd-level clerics
inline int mm2lmnQuartonClericLevel()
    { return 22; }

// Quartons are 12-foot tall humanoids with 4 jointed arms and fan-like wings
inline int mm2lmnQuartonHeightFeet()
    { return 12; }

// Each quarton has 36 pentadrones that act as a guard unit
inline int mm2lmnQuartonGuardPentadrones()
    { return 36; }

// The tertian xpValue (the X/15,200 + 25/hp cell: 15200 + 76 x 25)
inline int mm2lmnTertianXpValue()
    { return 17100; }

// The tertian xp level (the X/15,200 + 25/hp cell)
inline int mm2lmnTertianXpLevel()
    { return 10; }

// There are 9 tertians: trial, judgment and sentencing of both modrons and
// invading non-natives their province
inline int mm2lmnTertianCount()
    { return 9; }

// Tertians cast spells as clerics of the 24th level
inline int mm2lmnTertianClericLevel()
    { return 24; }

// Tertians cast spells as magic-users of the 20th level
inline int mm2lmnTertianMagicUserLevel()
    { return 20; }

// Tertians look very human save for their 12-foot tall size and the horns on
// their bald heads
inline int mm2lmnTertianHeightFeet()
    { return 12; }

// The secundus xpValue (the X/15,200 + 25/hp cell: 15200 + 81 x 25)
inline int mm2lmnSecundusXpValue()
    { return 17225; }

// The secundus xp level (the X/15,200 + 25/hp cell)
inline int mm2lmnSecundusXpLevel()
    { return 10; }

// The 4 secundi, viceroys of the quarters, are the virtual rulers of Nirvana,
// reporting only to Primus the One
inline int mm2lmnSecundusCount()
    { return 4; }

// The secundi use spells as 26th-level clerics
inline int mm2lmnSecundusClericLevel()
    { return 26; }

// The secundi use spells as 22nd-level magic-users
inline int mm2lmnSecundusMagicUserLevel()
    { return 22; }

// Secundi have special abilities as 13th-level monks
inline int mm2lmnSecundusMonkLevel()
    { return 13; }

// If a secundus scores 5 or better on the number to hit, it has stunned its
// opponent unless that being is of demigod status
inline int mm2lmnSecundusStunHitMargin()
    { return 5; }

// The secundus psionic ability: 300-310 points
inline int mm2lmnSecundusPsionicMin()
    { return 300; }

// The psionic ceiling
inline int mm2lmnSecundusPsionicMax()
    { return 310; }

// The Primus xpValue (the X/32,500 flat cell: 220 flat hp, no xp/hp adder)
inline int mm2lmnPrimusXpValue()
    { return 32500; }

// The Primus xp level (the X/32,500 cell)
inline int mm2lmnPrimusXpLevel()
    { return 10; }

// Primus casts spells as a 30th-level cleric
inline int mm2lmnPrimusClericLevel()
    { return 30; }

// Primus casts spells as a 25th-level magic-user
inline int mm2lmnPrimusMagicUserLevel()
    { return 25; }

// The Primus psionic ability: 365 points
inline int mm2lmnPrimusPsionicScore()
    { return 365; }

// The Primus HIT DICE cell "220 hp" - the flat-hp read (the demilich
// precedent), hitDiceNum 0
inline int mm2lmnPrimusAvgHp()
    { return 220; }

// The Primus magic resistance: 100%
inline int mm2lmnPrimusMrPct()
    { return 100; }

// The decatons lack the power to turn undead
inline bool mm2lmnDecatonCannotTurnUndead()
    { return true; }

// The nonatons may use power word stun once per day
inline bool mm2lmnNonatonPowerWordStunPerDay()
    { return true; }

// The octons are totally immune to psionic combat and effects of psionics
inline bool mm2lmnOctonImmuneToPsionics()
    { return true; }

// Hextons appear as humanoids with 6 arms: 2 large human arms and 4
// claw-tipped tentacles below
inline bool mm2lmnHextonSixArms()
    { return true; }

// Quintons are capable of legend lore, as if the questioned object or person
// were at hand
inline bool mm2lmnQuintonLegendLore()
    { return true; }

// All struck by the tertian mace-like tail must save vs. paralysis at -4 or
// fall, unable to rise
inline bool mm2lmnTertianTailParalysisMinus4()
    { return true; }

// The secundi have the dreaded quivering palm, applicable to any mortal
// creature
inline bool mm2lmnSecundusQuiveringPalm()
    { return true; }

// Creatures struck by the rainbow-bright right hand must save vs. spells or
// be teleported to Arcadia
inline bool mm2lmnPrimusLightHandTeleportsArcadia()
    { return true; }

// Creatures struck by the inky-dark left hand must save or be sent to Acheron
inline bool mm2lmnPrimusDarkHandSendsAcheron()
    { return true; }

// The Prime One may also appear as a normal human
inline bool mm2lmnPrimusAppearsAsNormalHuman()
    { return true; }

// ---- the russet mold pins (the R808 MM2 letters LMN walk) ----

// The barely visible spore cloud stays within a 3-foot radius
inline int mm2lmnRussetMoldSporeRadiusFeet()
    { return 3; }

// Creatures passing within 3 feet take 5-20 points of damage and must save
// vs. poison
inline int mm2lmnRussetMoldToxinDamageMin()
    { return 5; }

// The toxin ceiling
inline int mm2lmnRussetMoldToxinDamageMax()
    { return 20; }

// The failed save sickness kills in 2-5 turns unless a cure disease is cast
inline int mm2lmnRussetMoldDeathTurnsMin()
    { return 2; }

// The sickness ceiling
inline int mm2lmnRussetMoldDeathTurnsMax()
    { return 5; }

// The vegepygmy transformation takes 21-24 hours (1d4+20)
inline int mm2lmnRussetMoldTransformationHoursMin()
    { return 21; }

// The transformation ceiling
inline int mm2lmnRussetMoldTransformationHoursMax()
    { return 24; }

// The mold is mistaken for rust at distances greater than 30 feet (70%
// chance)
inline int mm2lmnRussetMoldMistakenPct()
    { return 70; }

// The mistaking distance
inline int mm2lmnRussetMoldMistakenBeyondFeet()
    { return 30; }

// The russet mold HIT DICE cell "12-16 hp/10 square feet" - the flat-hp read
// 16 (the hitDiceNum 0 precedent)
inline int mm2lmnRussetMoldAvgHp()
    { return 16; }

// A character who dies from touching russet mold sprouts new growths, and a
// vegepygmy rises from the remains
inline bool mm2lmnRussetMoldVegepygmyRises()
    { return true; }

// If the mold grows for more than 1 hour, the victim cannot be recovered
// except by a wish spell
inline bool mm2lmnRussetMoldWishAfterOneHour()
    { return true; }

// The russet mold stat block prints no TREASURE TYPE line (the R806 haunt
// precedent: the field rides empty)
inline bool mm2lmnRussetMoldNoTreasureLine()
    { return true; }

// ---- the mongrelman pins (the R808 MM2 letters LMN walk) ----

// The mongrelman camouflage: an 80% chance of remaining unnoticed, plus 1%
// per extra turn of preparation, up to 95%
inline int mm2lmnMongrelmanCamouflageBasePct()
    { return 80; }

// The camouflage ceiling
inline int mm2lmnMongrelmanCamouflageMaxPct()
    { return 95; }

// One turn is required for a mongrelman to camouflage himself, another
// creature, or an item
inline int mm2lmnMongrelmanCamouflageTurns()
    { return 1; }

// All mongrelmen are accomplished pickpockets, each with a 70% chance of
// success
inline int mm2lmnMongrelmanPickpocketPct()
    { return 70; }

// The lair leader: HD 5, AC 4, MV 12", Dmg 1-12, +1 to-hit
inline int mm2lmnMongrelmanLeaderHd()
    { return 5; }

// The leader armor class
inline int mm2lmnMongrelmanLeaderAc()
    { return 4; }

// The lair holds a leader and 5 bodyguards (HD 4)
inline int mm2lmnMongrelmanBodyguards()
    { return 5; }

// 5% of any group will be armed with blowguns and poison or paralyzing darts
inline int mm2lmnMongrelmanBlowgunPct()
    { return 5; }

// The mongrelman lair census: 35%
inline int mm2lmnMongrelmanLairPct()
    { return 35; }

// The mongrelman LEVEL/X.P. VALUE reads the 1-4 hit-dice ladder (1 HD = 1/20
// + 1/hp) - the by_level xp source
inline bool mm2lmnMongrelmanByLevelXp()
    { return true; }

// All mongrelmen have the abilities of camouflage and mimicry
inline bool mm2lmnMongrelmanCamouflageAndMimicry()
    { return true; }

// ---- the moon dog pins (the R808 MM2 letters LMN walk) ----

// The moon dog xpValue (the VII/2000 + 12/hp cell: 2000 + 44 x 12; the
// capture "V/1/2000" the OCR artifact)
inline int mm2lmnMoonDogXpValue()
    { return 2528; }

// The moon dog xp level (the VII/2000 + 12/hp cell)
inline int mm2lmnMoonDogXpLevel()
    { return 7; }

// The normal bite attack: 3-12 points of damage
inline int mm2lmnMoonDogBiteDamageMax()
    { return 12; }

// Baying causes all evil beings within 8" to save vs. spells or flee in panic
inline int mm2lmnMoonDogBayingRangeInches()
    { return 8; }

// Howling causes creatures of Evil in a 4" radius to suffer 5-8 points of
// damage per round
inline int mm2lmnMoonDogHowlingDamageMin()
    { return 5; }

// The howling damage ceiling
inline int mm2lmnMoonDogHowlingDamageMax()
    { return 8; }

// The howling radius
inline int mm2lmnMoonDogHowlingRadiusInches()
    { return 4; }

// Each affected non-native creature has a cumulative 5% chance per moon dog
// per round of being forced to return to its own plane
inline int mm2lmnMoonDogHowlingPlanePct()
    { return 5; }

// The moon dog spell-like powers perform at the 12th level of ability
inline int mm2lmnMoonDogSpellLevel()
    { return 12; }

// The moon dog detects illusion at 90%
inline int mm2lmnMoonDogIllusionDetectPct()
    { return 90; }

// The moon dog detects invisibility, including the improved form, at 80%
// probability
inline int mm2lmnMoonDogInvisibilityDetectPct()
    { return 80; }

// The moon dog detects magic at 70%
inline int mm2lmnMoonDogMagicDetectPct()
    { return 70; }

// The moon dog detects snares and pits at 100%
inline int mm2lmnMoonDogSnareDetectPct()
    { return 100; }

// In bright, wholesome light the armor class is 2
inline int mm2lmnMoonDogBrightLightAc()
    { return 2; }

// In twilight the armor class equals 0
inline int mm2lmnMoonDogTwilightAc()
    { return 0; }

// In heavy shadow or darkness the armor class is -2 (the negative composite
// rides unquoted - the R806 hollyphant precedent)
inline int mm2lmnMoonDogShadowAc()
    { return -2; }

// A moon dog can never be surprised but is 50% likely to surprise opponents
inline int mm2lmnMoonDogSurprisePct()
    { return 50; }

// A moon dog can be hit only by weapons of +2 or better
inline bool mm2lmnMoonDogPlusTwoWeaponsNeeded()
    { return true; }

// A moon dog can never be surprised
inline bool mm2lmnMoonDogNeverSurprised()
    { return true; }

// The moon dogs come from the Upper Outer Plane of Elysium and serve only
// deities of Good
inline bool mm2lmnMoonDogElysiumNative()
    { return true; }

// The moon dog spell-like powers include shades, once per day, one at a time,
// 1 per round, at will
inline bool mm2lmnMoonDogShadesPerDay()
    { return true; }

// ---- the muckdweller pins (the R808 MM2 letters LMN walk) ----

// The muckdweller xpValue (the I/7 + 1/hp cell: 7 + 4 x 1)
inline int mm2lmnMuckdwellerXpValue()
    { return 11; }

// The muckdweller xp level (the I/7 + 1/hp cell)
inline int mm2lmnMuckdwellerXpLevel()
    { return 1; }

// Several muckdwellers squirt jets of muddy water for up to 10 feet at the
// victim eyes
inline int mm2lmnMuckdwellerJetFeet()
    { return 10; }

// All attacks against a blinded victim are at +2, with no dexterity bonus for
// the victim
inline int mm2lmnMuckdwellerBlindAttackBonus()
    { return 2; }

// If 16 or more monsters are encountered in their lair, there will be double
// the given type Q treasure
inline int mm2lmnMuckdwellerDoublesTreasureAt()
    { return 16; }

// The muckdweller HIT DICE cell "1-4 hp" - the flat-hp read 4 (the hitDiceNum
// 0 precedent)
inline int mm2lmnMuckdwellerAvgHp()
    { return 4; }

// Muckdwellers have been reported serving kuo-toan masters
inline bool mm2lmnMuckdwellerServesKuoToans()
    { return true; }

// The muddy water jet blinds the victim, negated by a save vs. wands, no save
// if surprised
inline bool mm2lmnMuckdwellerBlindedByJet()
    { return true; }

// ---- the mud man pins (the R808 MM2 letters LMN walk) ----

// The mud-man xpValue (the II/28 + 2/hp cell: 28 + 7 x 2; the capture "11/28"
// the OCR misread)
inline int mm2lmnMudManXpValue()
    { return 42; }

// The mud-man xp level (the II/28 + 2/hp cell)
inline int mm2lmnMudManXpLevel()
    { return 2; }

// The mud blob hurling maximum range: 6"
inline int mm2lmnMudManBlobRangeInches()
    { return 6; }

// A mud blob hit slows the victim movement rate by 1"
inline int mm2lmnMudManBlobSlowdown()
    { return 1; }

// The flung mud-man body hit slows the victim by 4" - at the death of the
// mud-man
inline int mm2lmnMudManBodySlowdown()
    { return 4; }

// A victim whose movement reaches zero suffocates for 1-8 points per round
// until the mouth and/or nose is clear
inline int mm2lmnMudManSuffocationDamageMax()
    { return 8; }

// The victim dies from suffocation after 5 rounds unless rescued
inline int mm2lmnMudManSuffocationRounds()
    { return 5; }

// Hardened mud broken away restores movement at a rate of 1" per 5 rounds
inline int mm2lmnMudManMovementRestorePer()
    { return 5; }

// Roused mud-men take 1 round to draw together and rise, attacking the next
// round
inline int mm2lmnMudManRiseRounds()
    { return 1; }

// In their dormant state mud-men are immune to attacks with weapons, magical
// or otherwise
inline bool mm2lmnMudManDormantImmuneToWeapons()
    { return true; }

// Transmute mud to rock kills all mud-men it is able to affect, allowing no
// saving throw
inline bool mm2lmnMudManTransmuteMudToRockKills()
    { return true; }

// Mud-men are unaffected by spells which affect the mind or by psionics
inline bool mm2lmnMudManMindSpellsImmune()
    { return true; }

// ---- the myconid pins (the R808 MM2 letters LMN walk) ----

// A myconid circle usually consists of 20 members, 4 of each hit dice size
// from 1-5
inline int mm2lmnMyconidCircleMembers()
    { return 20; }

// Four of each hit dice size ride the circle
inline int mm2lmnMyconidPerSize()
    { return 4; }

// The 6-hit dice king stands apart from the circles
inline int mm2lmnMyconidKingHd()
    { return 6; }

// The 6-hit dice king stands 12 feet tall
inline int mm2lmnMyconidKingHeightFeet()
    { return 12; }

// Myconids gain 2 feet of height with each hit die
inline int mm2lmnMyconidHeightPerHd()
    { return 2; }

// The rigid circle day: 8 hours rest, 8 hours work, 8 hours melding
inline int mm2lmnMyconidMeldHours()
    { return 8; }

// The distress spore cloud expands at 40 feet per round, 120 feet maximum
inline int mm2lmnMyconidDistressSpeedFeetPerRound()
    { return 40; }

// The distress cloud maximum
inline int mm2lmnMyconidDistressMaxFeet()
    { return 120; }

// Personal contact with myconid skin does 1-4 points to the touching creature
inline int mm2lmnMyconidTouchDamageMax()
    { return 4; }

// The myconid lair census: 70%
inline int mm2lmnMyconidLairPct()
    { return 70; }

// The myconid LEVEL/X.P. VALUE rides the 1-6 hit-dice ladder (the I/14+1
// through V/425+6 cells) - the by_level xp source
inline bool mm2lmnMyconidByLevelXp()
    { return true; }

// Myconids never venture onto the surface and have a deathly fear of direct
// sunlight
inline bool mm2lmnMyconidFearsSunlight()
    { return true; }

// The animator-spore animated corpse resembles a zombie but is not undead and
// cannot be turned by a cleric
inline bool mm2lmnMyconidAnimatorZombiesNotUndead()
    { return true; }

// ---- the nereid pins (the R808 MM2 letters LMN walk) ----

// The nereid xpValue (the IV/200 + 4/hp cell: 200 + 14 x 4)
inline int mm2lmnNereidXpValue()
    { return 256; }

// The nereid xp level (the IV/200 + 4/hp cell)
inline int mm2lmnNereidXpLevel()
    { return 4; }

// The nereid spittle range: 20 feet, blinding 2-12 rounds if it hits
inline int mm2lmnNereidSpitRangeFeet()
    { return 20; }

// The blindness floor
inline int mm2lmnNereidBlindRoundsMin()
    { return 2; }

// The blindness ceiling
inline int mm2lmnNereidBlindRoundsMax()
    { return 12; }

// The nereid controls the water in which she lairs for a radius of 3"
inline int mm2lmnNereidWaterControlRadiusInches()
    { return 3; }

// The roaring waves may deafen characters within 6" for 3-12 rounds
inline int mm2lmnNereidDeafenRadiusInches()
    { return 6; }

// The watery serpent or fist strikes as a 4 hit dice monster, 1-4 points of
// damage, once per round
inline int mm2lmnNereidWateryShapeHd()
    { return 4; }

// In water a nereid is transparent and 95% undetectable except as golden
// angel seaweed
inline int mm2lmnNereidUndetectablePct()
    { return 95; }

// Nereids are 85% likely to have a pet (the 1d8 table)
inline int mm2lmnNereidPetPct()
    { return 85; }

// The nereid greatest weakness lies in her shawl, for it contains her soul;
// its destruction dissolves her into formless water
inline bool mm2lmnNereidShawlHoldsSoul()
    { return true; }

// A kiss forced from a nereid forces a save vs. breath weapons at -2 or
// instant drowning
inline bool mm2lmnNereidForcedKissCanDrown()
    { return true; }

// ---- the narwhale pins (the R808 MM2 letters LMN walk) ----

// The narwhale xpValue (the IV/190 + 6/hp cell: 190 + 27 x 6)
inline int mm2lmnNarwhaleXpValue()
    { return 352; }

// The narwhale xp level (the IV/190 + 6/hp cell)
inline int mm2lmnNarwhaleXpLevel()
    { return 4; }

// The spiral horn is 6-12 feet long
inline int mm2lmnNarwhaleHornFeetMin()
    { return 6; }

// The horn ceiling
inline int mm2lmnNarwhaleHornFeetMax()
    { return 12; }

// The marine mammal ranges from about 20-40+ feet, exclusive of the horn
inline int mm2lmnNarwhaleBodyFeetMin()
    { return 20; }

// The body ceiling
inline int mm2lmnNarwhaleBodyFeetMax()
    { return 40; }

// The "4+4, 5+5 or 6+6" composite: the great form 6+6 heads the grid read (hd
// 6, bonus 6)
inline int mm2lmnNarwhaleGreatFormHd()
    { return 6; }

// Narwhales are used as pets and guards by communities of dolphins and
// trained by aquatic elves
inline bool mm2lmnNarwhaleDolphinPets()
    { return true; }

// The narwhales, the unicorns of the ocean, are basically non-aggressive
inline bool mm2lmnNarwhaleUnicornOfTheOcean()
    { return true; }

// ---- the MM2 letters LMN walk stat grid (the R808 wiring) ----

// The armor class cells (the foxwoman "2 or 4 or 6" and the moon dog "2 or 0
// or -2" composites read the head 2; the seawolf lesser "6 (7)" reads 6; the
// negative modron cells ride unquoted - the R806 hollyphant -4 precedent)
inline int mm2lmnLmStatAc(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 0;
        case 6:
            return 6;
        case 7:
            return 5;
        case 8:
            return 3;
        case 9:
            return 6;
        case 10:
            return 2;
        case 11:
            return 0;
        case 12:
            return 6;
        case 13:
            return -2;
        case 14:
            return 4;
        case 15:
            return 7;
        case 16:
            return 6;
        case 17:
            return 5;
        case 18:
            return 4;
        case 19:
            return 3;
        case 20:
            return 2;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return -1;
        case 24:
            return -2;
        case 25:
            return -3;
        case 26:
            return -4;
        case 27:
            return -5;
        case 28:
            return -6;
        case 29:
            return -10;
        case 30:
            return 9;
        case 31:
            return 5;
        case 32:
            return 2;
        case 33:
            return 6;
        case 34:
            return 10;
        case 35:
            return 10;
        case 36:
            return 10;
        case 37:
            return 6;
        default:
            return 0;
        }
    }

// The hit dice num cells (the flat-hp reads: the primus 220, the russet mold
// 16 and the muckdweller 4 - hitDiceNum 0)
inline int mm2lmnLmStatHd(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 8;
        case 3:
            return 9;
        case 4:
            return 2;
        case 5:
            return 10;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 10;
        case 9:
            return 4;
        case 10:
            return 6;
        case 11:
            return 13;
        case 12:
            return 4;
        case 13:
            return 8;
        case 14:
            return 10;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 5;
        case 20:
            return 10;
        case 21:
            return 11;
        case 22:
            return 12;
        case 23:
            return 13;
        case 24:
            return 14;
        case 25:
            return 15;
        case 26:
            return 16;
        case 27:
            return 17;
        case 28:
            return 18;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 1;
        case 32:
            return 8;
        case 33:
            return 0;
        case 34:
            return 2;
        case 35:
            return 1;
        case 36:
            return 4;
        case 37:
            return 6;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the modron ladder 1+1 through 18+18; the moon dog
// 8+16 print oddity; the narwhale 6+6 great form)
inline int mm2lmnLmStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 2;
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
            return 1;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 5;
        case 20:
            return 10;
        case 21:
            return 11;
        case 22:
            return 12;
        case 23:
            return 13;
        case 24:
            return 14;
        case 25:
            return 15;
        case 26:
            return 16;
        case 27:
            return 17;
        case 28:
            return 18;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 16;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 6;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x HD + bonus) formula; the primus flat 220,
// the russet mold 16, the muckdweller 4)
inline int mm2lmnLmStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 14;
        case 2:
            return 29;
        case 3:
            return 33;
        case 4:
            return 9;
        case 5:
            return 38;
        case 6:
            return 7;
        case 7:
            return 9;
        case 8:
            return 35;
        case 9:
            return 14;
        case 10:
            return 21;
        case 11:
            return 45;
        case 12:
            return 14;
        case 13:
            return 30;
        case 14:
            return 35;
        case 15:
            return 4;
        case 16:
            return 9;
        case 17:
            return 13;
        case 18:
            return 18;
        case 19:
            return 22;
        case 20:
            return 45;
        case 21:
            return 49;
        case 22:
            return 54;
        case 23:
            return 58;
        case 24:
            return 63;
        case 25:
            return 67;
        case 26:
            return 72;
        case 27:
            return 76;
        case 28:
            return 81;
        case 29:
            return 220;
        case 30:
            return 16;
        case 31:
            return 3;
        case 32:
            return 44;
        case 33:
            return 4;
        case 34:
            return 7;
        case 35:
            return 3;
        case 36:
            return 14;
        case 37:
            return 27;
        default:
            return 0;
        }
    }

// The attack cells (the loader max read: the seawolf lesser "1 (3)" reads 3,
// the quadrone "4 or 2" reads 4, the mantrap "2-5" reads 5; every Nil and See
// below floors at 1)
inline int mm2lmnLmStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 4;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 4;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 5;
        case 20:
            return 10;
        case 21:
            return 9;
        case 22:
            return 8;
        case 23:
            return 7;
        case 24:
            return 6;
        case 25:
            return 5;
        case 26:
            return 4;
        case 27:
            return 3;
        case 28:
            return 2;
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
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        default:
            return 0;
        }
    }

// The xp cells (the moon dog VII/2000 + 12/hp - the capture "V/1/2000" the
// OCR artifact; the marid VIII/5000 flat; the primus X/32,500 flat; the
// by_level rows read 0)
inline int mm2lmnLmStatXp(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 125;
        case 2:
            return 1700;
        case 3:
            return 900;
        case 4:
            return 50;
        case 5:
            return 1500;
        case 6:
            return 97;
        case 7:
            return 0;
        case 8:
            return 1350;
        case 9:
            return 275;
        case 10:
            return 350;
        case 11:
            return 5000;
        case 12:
            return 185;
        case 13:
            return 1700;
        case 14:
            return 1000;
        case 15:
            return 28;
        case 16:
            return 50;
        case 17:
            return 85;
        case 18:
            return 165;
        case 19:
            return 350;
        case 20:
            return 2550;
        case 21:
            return 5250;
        case 22:
            return 5250;
        case 23:
            return 8250;
        case 24:
            return 8250;
        case 25:
            return 10950;
        case 26:
            return 10950;
        case 27:
            return 15200;
        case 28:
            return 15200;
        case 29:
            return 32500;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 2000;
        case 33:
            return 7;
        case 34:
            return 28;
        case 35:
            return 0;
        case 36:
            return 200;
        case 37:
            return 190;
        default:
            return 0;
        }
    }

// The xp per hp cells (the marid and primus flat 0 adders; the tertian and
// secundus 25 ceilings)
inline int mm2lmnLmStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 3;
        case 5:
            return 14;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 14;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 0;
        case 12:
            return 4;
        case 13:
            return 12;
        case 14:
            return 14;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 5;
        case 19:
            return 7;
        case 20:
            return 14;
        case 21:
            return 16;
        case 22:
            return 16;
        case 23:
            return 18;
        case 24:
            return 18;
        case 25:
            return 20;
        case 26:
            return 20;
        case 27:
            return 25;
        case 28:
            return 25;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 12;
        case 33:
            return 1;
        case 34:
            return 2;
        case 35:
            return 0;
        case 36:
            return 4;
        case 37:
            return 6;
        default:
            return 0;
        }
    }

// The lair pct cells (the numeric-string convention; the wereshark "20% (if
// underwater)" reads 20; the mantrap, mud-man and nereid 100)
inline int mm2lmnLmStatLairPct(int b)
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
            return 20;
        case 6:
            return 0;
        case 7:
            return 45;
        case 8:
            return 0;
        case 9:
            return 100;
        case 10:
            return 30;
        case 11:
            return 0;
        case 12:
            return 20;
        case 13:
            return 10;
        case 14:
            return 40;
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
            return 35;
        case 32:
            return 0;
        case 33:
            return 40;
        case 34:
            return 100;
        case 35:
            return 70;
        case 36:
            return 100;
        case 37:
            return 0;
        default:
            return 0;
        }
    }

// The move cells (the loader first bare number: the narwhale "//21" reads 21;
// the mantrap Nil reads 0; the russet mold 0"
inline int mm2lmnLmStatMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 24;
        case 3:
            return 9;
        case 4:
            return 30;
        case 5:
            return 12;
        case 6:
            return 9;
        case 7:
            return 12;
        case 8:
            return 6;
        case 9:
            return 0;
        case 10:
            return 6;
        case 11:
            return 9;
        case 12:
            return 18;
        case 13:
            return 6;
        case 14:
            return 3;
        case 15:
            return 6;
        case 16:
            return 9;
        case 17:
            return 12;
        case 18:
            return 15;
        case 19:
            return 18;
        case 20:
            return 15;
        case 21:
            return 18;
        case 22:
            return 9;
        case 23:
            return 9;
        case 24:
            return 12;
        case 25:
            return 6;
        case 26:
            return 12;
        case 27:
            return 12;
        case 28:
            return 18;
        case 29:
            return 24;
        case 30:
            return 0;
        case 31:
            return 9;
        case 32:
            return 30;
        case 33:
            return 3;
        case 34:
            return 3;
        case 35:
            return 9;
        case 36:
            return 12;
        case 37:
            return 21;
        default:
            return 0;
        }
    }

// The magic resistance cells (the percent reads decaton 10 through secundus
// 90 and primus 100 in +10 steps; every Standard and See below reads 0)
inline int mm2lmnLmStatMr(int b)
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
            return 20;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 25;
        case 12:
            return 0;
        case 13:
            return 10;
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
            return 10;
        case 21:
            return 20;
        case 22:
            return 30;
        case 23:
            return 40;
        case 24:
            return 50;
        case 25:
            return 60;
        case 26:
            return 70;
        case 27:
            return 80;
        case 28:
            return 90;
        case 29:
            return 100;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 25;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 50;
        case 37:
            return 0;
        default:
            return 0;
        }
    }

// The minimal attack cells (the gorilla through the tiger at 3, the
// one-attack rows at 1)
inline int mm2lmnMinimalStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 5;
        case 25:
            return 1;
        case 26:
            return 2;
        case 27:
            return 3;
        case 28:
            return 1;
        default:
            return 0;
        }
    }

// The minimal xp base cells (the 10+1/hp gorilla through the 5+1/hp wolf; the
// mammoth and the African elephant share the 125 ceiling; the lion prints
// 65+2/hp)
inline int mm2lmnMinimalStatXpBase(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 30;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 12;
        case 5:
            return 28;
        case 6:
            return 50;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 20;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 7;
        case 13:
            return 5;
        case 14:
            return 90;
        case 15:
            return 125;
        case 16:
            return 20;
        case 17:
            return 5;
        case 18:
            return 10;
        case 19:
            return 45;
        case 20:
            return 45;
        case 21:
            return 65;
        case 22:
            return 25;
        case 23:
            return 5;
        case 24:
            return 125;
        case 25:
            return 90;
        case 26:
            return 7;
        case 27:
            return 50;
        case 28:
            return 5;
        default:
            return 0;
        }
    }

// The minimal xp per hp cells (the 1, 2, 3 and 4 adders)
inline int mm2lmnMinimalStatXpPerHp(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
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
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 4;
        case 25:
            return 3;
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

// The hierarch rank cells (the decaton 1 through the secundus 9)
inline int mm2lmnTelepathyRank(int b)
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
        default:
            return 0;
        }
    }

// The telepathy mile cells (the decaton 44 through the secundus 420)
inline int mm2lmnTelepathyMiles(int b)
    {
        switch (b) {
        case 0:
            return 44;
        case 1:
            return 63;
        case 2:
            return 80;
        case 3:
            return 190;
        case 4:
            return 216;
        case 5:
            return 238;
        case 6:
            return 384;
        case 7:
            return 405;
        case 8:
            return 420;
        default:
            return 0;
        }
    }

}   // namespace rules
