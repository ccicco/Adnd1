// =========================================================================================
// Adnd1 - rules/s22.h
// The Dragon issue-22 opener part two - the AD&D Sneak Preview of the Dungeon
// Masters Guide
// census 869 -> 870.
//
// The part-two round of the issue-22 four-round shape - the single chain of
// the DMG sneak preview, the table round of the walk. Pinned from The Dragon
// Vol. III No. 8 (February 1979) print 33 through 38 and 41 through 43, the
// Curtiss-provided Dm22.pdf scan voice, print folio the PDF page this issue.
// The preview prints the not-yet-released DMG combat and saving throw
// material ahead of the GenCon XII release - the magic items of the six
// modules, the amulet of the planes, the elemental command rings, the
// protection scrolls, the attack matrices, the cleric-undead matrix, the
// psionic tables and the three saving throw matrices.
//
// Conversions noted, never silent: the cleric-undead matrix pins the T symbol
// as ninety-seven, the D as ninety-eight, the starred destroy as ninety-nine
// and the printed dash as zero; the psychic crush range pins its printed
// dashes as zero; the parchment fireball save prints twenty-five and the
// fighter nine-to-ten row prints its breath and spell cells nine and eleven -
// all pinned as scanned. No watches moved: the Sullin levels 7-9 and the
// brawling sequel still print nowhere and ride to TD 23.
//
namespace rules {

// ---- the AD&D DMG sneak preview (print 33-38, 41-43) ----

// the DMG release year - GenCon XII August 1979 at the University of
// Wisconsin-Parkside in Kenosha the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22GenConYear()
    { return 1979; }

// the GenCon number of the release - the twelfth the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22GenConNumber()
    { return 12; }

// the six modules whose new magic items ride the preview - G1 G2 G3 D1 D2 D3,
// the module-text items not repeated the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22PreviewModules()
    { return 6; }

// the amulet band count - seventeen plane bands on the one table the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22AmuletCount()
    { return 17; }

// the add-twelve rule - a d6 of one to three does not add twelve, four to six
// adds it to the d12 roll the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22AmuletAdd12From()
    { return 4; }

// the random results - one through twenty-four on the combined roll the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22AmuletResults()
    { return 24; }

// the alternate result at twenty-two - the Ethereal Plane the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22AmuletAltEthereal()
    { return 22; }

// the alternate result at twenty-three - the Astral Plane the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22AmuletAltAstral()
    { return 23; }

// the alternate result at twenty-four - the Prime but an alternate earth the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22AmuletAltPrime()
    { return 24; }

// the minimum strength to wield it - eighteen oh-one or better the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22HammerStrengthMin()
    { return 1801; }

// the minimum height to wield it - over six feet the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22HammerHeightFeet()
    { return 6; }

// the basic weapon plus - a plus-three with double damage dice on any hit the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22HammerBasePlus()
    { return 3; }

// the true-name plus - a plus-five with the girdle and the gauntlets worn the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22HammerTrueNamePlus()
    { return 5; }

// the thunderclap radius - all creatures within three inches stunned the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22HammerStunRadiusInches()
    { return 3; }

// the thunderclap stun - one round the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22HammerStunRounds()
    { return 1; }

// the throw limit - five throws within any two-turn period the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22HammerThrowsPerTwoTurns()
    { return 5; }

// the rest after the limit - one turn the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22HammerRestTurns()
    { return 1; }

// the Thor note - about double the listed ranges the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22HammerThorFactor()
    { return 2; }

// the underwater vision factor - five times farther than the water and light
// allow the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22HelmVisionFactor()
    { return 5; }

// the pigment volume - one pot creates a thousand-cubic-foot object the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22PigmentCubicFeet()
    { return 1000; }

// the depiction surface - one hundred square feet painted in two dimensions
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22PigmentSurfaceFeet()
    { return 100; }

// the pots floor - from one to four containers the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PigmentPotsMin()
    { return 1; }

// the pots ceiling - the same one to four the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22PigmentPotsMax()
    { return 4; }

// the depiction time - one turn per object the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22PigmentDepictTurns()
    { return 1; }

// the retention period - one month the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22PearlMonths()
    { return 1; }

// the gain day - the increase at the expiration of thirty days the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22PearlDays()
    { return 30; }

// the cursed share - one in twenty works in reverse the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22PearlCursedPct()
    { return 5; }

// the periapt band count - four plus bands on the chart the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22PeriaptCount()
    { return 4; }

// the emergency save - a ten percent saving throw against poisons which
// normally disallow one the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22PeriaptNoSavePct()
    { return 10; }

// the charm duration floor - four turns plus the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PhilterLoveBaseTurns()
    { return 4; }

// the charm extra - one to four further turns the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PhilterLoveExtraMin()
    { return 1; }

// the charm extra ceiling - the same one to four the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PhilterLoveExtraMax()
    { return 4; }

// the persuasiveness bonus - twenty-five percent on reaction dice the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22PhilterPersuasionPct()
    { return 25; }

// the suggest range - once per turn within three inches the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22PhilterSuggestRangeInches()
    { return 3; }

// the two-dose likelihood - seventy-five percent the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PotionTwoDosePct()
    { return 75; }

// the doses floor - two or four in the container the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PotionDosesMin()
    { return 2; }

// the doses ceiling - the same two or four the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22PotionDosesMax()
    { return 4; }

// the duration - one full hour per dose the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22PotionHoursPerDose()
    { return 1; }

// the variable extra - one to ten further rounds the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PotionExtraRoundsMin()
    { return 1; }

// the variable extra ceiling - the same one to ten the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PotionExtraRoundsMax()
    { return 10; }

// the elemental command ring types - four, air earth fire water the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22RingTypes()
    { return 4; }

// the attuned-keep distance - the elemental cannot approach within five feet
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22RingKeepFeet()
    { return 5; }

// the charm attempt save - at minus two on the die the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22RingCharmSaveMinus()
    { return 2; }

// the plane-creature attack penalty - minus one on their to-hit dice the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22RingFoeHitMinus()
    { return 1; }

// the wearer save bonus - plus two against the creature attacks the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22RingSavePlus()
    { return 2; }

// the wearer hit bonus - plus four to hit the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22RingHitPlus()
    { return 4; }

// the wearer damage bonus - plus six total not per die the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22RingDamagePlus()
    { return 6; }

// the operation level - tenth, or the minimum the spell needs if greater the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22RingOperateLevel()
    { return 10; }

// the additional-power bring-forth - five segments the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22RingPowerSegments()
    { return 5; }

// the owner save penalty - minus two versus the element of the ring the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22RingElementalSaveMinus()
    { return 2; }

// the air powers - gust of wind, fly, wall of force, control winds,
// invisibility the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22RingAirPowers()
    { return 5; }

// the earth powers - stone tell, passwall, wall of stone, stone to flesh,
// move earth, feather fall the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22RingEarthPowers()
    { return 6; }

// the fire powers - burning hands, pyrotechnics, wall of fire, flame strike,
// fire resistance the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22RingFirePowers()
    { return 5; }

// the water powers - purify water, create water, water breathing, wall of
// ice, airy water, lower water, part water, water walking the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22RingWaterPowers()
    { return 8; }

// the protection scroll kinds - demons, devils, elementals, lycanthropes,
// magic, petrifaction, possession, undead the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22ScrollKinds()
    { return 8; }

// the anti-magic reading time - eight segments the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollMagicSegments()
    { return 8; }

// the anti-magic radius - five feet the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22ScrollMagicRadiusFeet()
    { return 5; }

// the item drain likelihood - fifty percent on contact with the globe the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollMagicDrainPct()
    { return 50; }

// the drain save - eleven or better on the d20 the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollMagicSaveFloor()
    { return 11; }

// the anti-magic duration floor - five to thirty rounds the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollMagicRoundsMin()
    { return 5; }

// the anti-magic duration ceiling - the same five to thirty the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ScrollMagicRoundsMax()
    { return 30; }

// the petrifaction reading time - five segments the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollPetrifactionSegments()
    { return 5; }

// the petrifaction duration floor - five to twenty rounds the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollPetrifactionRoundsMin()
    { return 5; }

// the petrifaction duration ceiling - the same five to twenty the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ScrollPetrifactionRoundsMax()
    { return 20; }

// the possession reading time - one full round the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollPossessionRounds()
    { return 1; }

// the possession duration floor - ten to sixty rounds in ninety percent of
// the scrolls the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollPossessionRoundsMin()
    { return 10; }

// the possession duration ceiling - the same ten to sixty the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollPossessionRoundsMax()
    { return 60; }

// the stationary duration floor - ten to sixty turns in the other ten percent
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollPossessionTurnsMin()
    { return 10; }

// the stationary duration ceiling - the same ten to sixty turns the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ScrollPossessionTurnsMax()
    { return 60; }

// the stationary share - ten percent of the scrolls protect longer but do not
// move the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollPossessionStationaryPct()
    { return 10; }

// the undead reading time - four segments the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22ScrollUndeadSegments()
    { return 4; }

// the undead radius - five feet, the physical attacks only the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollUndeadRadiusFeet()
    { return 5; }

// the undead duration floor - ten to eighty rounds the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollUndeadRoundsMin()
    { return 10; }

// the undead duration ceiling - the same ten to eighty the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollUndeadRoundsMax()
    { return 80; }

// the undead restraint - thirty-five hit dice or levels the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollUndeadHdCap()
    { return 35; }

// the demon scroll read - one full round for the demon lords and princes only
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollDemonLordRounds()
    { return 1; }

// the demon scroll read - seven segments for the type four through six and
// the succubi the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollDemonMidSegments()
    { return 7; }

// the demon scroll read - three segments for the type one through three and
// the manes the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollDemonLesserSegments()
    { return 3; }

// the pause that kills - any one-segment pause in reading destroys the scroll
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollDemonPauseSegments()
    { return 1; }

// the demon duration floor - five to twenty rounds the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollDemonRoundsMin()
    { return 5; }

// the demon duration ceiling - the same five to twenty the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollDemonRoundsMax()
    { return 20; }

// the devil scroll read - one round for the arch-devils only the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ScrollDevilArchRounds()
    { return 1; }

// the devil scroll read - seven segments for the greater devils the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ScrollDevilGreaterSegments()
    { return 7; }

// the devil scroll read - three segments for the lesser devils and the
// lemures the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollDevilLesserSegments()
    { return 3; }

// the elemental reading time - six segments the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22ScrollElementalSegments()
    { return 6; }

// the elemental duration floor - five to forty rounds the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollElementalRoundsMin()
    { return 5; }

// the elemental duration ceiling - the same five to forty the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollElementalRoundsMax()
    { return 40; }

// the specific-elemental restraint - twenty-four hit dice the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollElementalSpecificHd()
    { return 24; }

// the all-elemental restraint - sixteen hit dice the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollElementalAllHd()
    { return 16; }

// the lycanthrope reading time - four segments the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollLycanSegments()
    { return 4; }

// the lycanthrope duration floor - five to thirty rounds the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ScrollLycanRoundsMin()
    { return 5; }

// the lycanthrope duration ceiling - the same five to thirty the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ScrollLycanRoundsMax()
    { return 30; }

// the lycanthrope restraint - forty-nine hit dice the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ScrollLycanHdCap()
    { return 49; }

// the rounding rule - hit point plusses round down unless they exceed two the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ScrollLycanPlusThreshold()
    { return 2; }

// the elemental scroll rows - the five elemental planes protection scrolls
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ElemScrollCount()
    { return 5; }

// the lycanthrope scroll rows - seven from werewolf through wereshark the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22LycanScrollCount()
    { return 7; }

// the hit-only rows - the four plus grades one through four the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22HitOnlyCount()
    { return 4; }

// the undead matrix rows - thirteen types from the skeleton through the
// special the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22UndeadCount()
    { return 13; }

// the paladin footnotes - six, the first and second level paladin through the
// eleventh and higher the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22UndeadFootnotes()
    { return 6; }

// the turning count floor - one to twelve affected the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22TurnAffectedMin()
    { return 1; }

// the turning count ceiling - the same one to twelve the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22TurnAffectedMax()
    { return 12; }

// the starred destroy count - seven to twelve rather than one to twelve the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22TurnStarMin()
    { return 7; }

// the turned flee floor - not less than three rounds the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22TurnFleeRoundsMin()
    { return 3; }

// the turned flee ceiling - not more than twelve rounds the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22TurnFleeRoundsMax()
    { return 12; }

// the special floor - one to two of the lower-plane creatures the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22TurnSpecialMin()
    { return 1; }

// the special ceiling - the same one to two the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22TurnSpecialMax()
    { return 2; }

// the special rule of thumb - armor class minus five or better unaffected the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22TurnSpecialAc()
    { return -5; }

// the special rule of thumb - eleven or more hit dice unaffected the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22TurnSpecialHd()
    { return 11; }

// the special rule of thumb - sixty-six percent or greater magic resistance
// unaffected the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22TurnSpecialMrPct()
    { return 66; }

// the psionic blast cost - twenty attack points the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22BlastCost()
    { return 20; }

// the mind thrust cost - four the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22MindThrustCost()
    { return 4; }

// the ego whip cost - seven the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22EgoWhipCost()
    { return 7; }

// the id insinuation cost - ten the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22IdInsinuationCost()
    { return 10; }

// the psychic crush cost - fourteen the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22PsychicCrushCost()
    { return 14; }

// the mind blank cost - one defense point the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22MindBlankCost()
    { return 1; }

// the thought shield cost - two the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22ThoughtShieldCost()
    { return 2; }

// the mental barrier cost - three the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22MentalBarrierCost()
    { return 3; }

// the intellect fortress cost - eight the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22IntellectFortressCost()
    { return 8; }

// the tower of iron will cost - ten the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22TowerIronWillCost()
    { return 10; }

// the crush table rows - six attack strength bands the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PsiCrushCount()
    { return 6; }

// the confused floor - two to eight rounds, no psionic activity the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22PsiConfusedRoundsMin()
    { return 2; }

// the confused ceiling - the same two to eight the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PsiConfusedRoundsMax()
    { return 8; }

// the dazed floor - one to four turns, no psionic or other activity the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22PsiDazedTurnsMin()
    { return 1; }

// the dazed ceiling - the same one to four the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22PsiDazedTurnsMax()
    { return 4; }

// the coma floor - one to four weeks the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22PsiComaWeeksMin()
    { return 1; }

// the coma ceiling - the same one to four the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22PsiComaWeeksMax()
    { return 4; }

// the robot floor - two to eight weeks until released or the save the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22PsiRobotWeeksMin()
    { return 2; }

// the robot ceiling - the same two to eight the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22PsiRobotWeeksMax()
    { return 8; }

// the wounded floor - one mode or discipline unusable for two to eight weeks
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22PsiWoundedWeeksMin()
    { return 2; }

// the wounded ceiling - the same two to eight the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22PsiWoundedWeeksMax()
    { return 8; }

// the catatonic mistake likelihood - ninety-nine percent taken for death the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22PsiCatatonicPct()
    { return 99; }

// the mind bar rule - letter results read as minus forty points until zero
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22PsiMindBarPoints()
    { return 40; }

// the blast table rows - eleven intelligence and wisdom bands the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22PsiBlastCount()
    { return 11; }

// the feebleminded score - a combined intelligence and wisdom of zero to five
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22PsiFeebleCap()
    { return 5; }

// the range table rows - the five attack modes A through E the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22PsiRangeCount()
    { return 5; }

// the series range bonus - fifty percent per linked psionic, two at double
// the range the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22PsiSeriesBonusPct()
    { return 50; }

// the medium-range damage cut - twenty percent, fractions rounded up the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22PsiMediumDamageCutPct()
    { return 20; }

// the long-range strength cut - one category, twenty-five points the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22PsiLongCategoryCut()
    { return 25; }

// the long-range damage cut - twenty percent, fractions rounded up the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22PsiLongDamageCutPct()
    { return 20; }

// the lowest-band long cut - fifty percent, fractions dropped the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22PsiLongLowBandCutPct()
    { return 50; }

// the saving throw matrices - three, the characters, the monsters, the items
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22SaveMatrices()
    { return 3; }

// the automatic failure - a roll of one always fails regardless of
// protections the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22SaveAutoFail()
    { return 1; }

// the character save rows - seven cleric, ten fighter, five magic-user, six
// thief bands the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22SaveCharCount()
    { return 28; }

// the cleric bands - one through three up to nineteen and up the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22SaveClericBands()
    { return 7; }

// the fighter bands - zero level up to seventeen and up the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22SaveFighterBands()
    { return 10; }

// the magic-user bands - one through five up to twenty-one and up the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22SaveMuBands()
    { return 5; }

// the thief bands - one through four up to twenty-one and up the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22SaveThiefBands()
    { return 6; }

// the monster hit-die plus cap - any plus above three equals another hit die
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22MonsterPlusCap()
    { return 3; }

// the non-intelligent divisor - one-half the hit dice rounded upwards the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22NonIntDivisor()
    { return 2; }

// the item rows - fourteen from bone or ivory through wood or rope thick the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ItemRowCount()
    { return 14; }

// the item attack forms - acid through electrical discharge the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ItemAttackForms()
    { return 11; }

// the magic item save bonus - plus two on all rolls the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ItemMagicBonus()
    { return 2; }

// the magic plus bonus - plus one for each plus above the first the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ItemPlusBonus()
    { return 1; }

// the own-mode bonus - plus five versus the attack in the item own mode the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ItemOwnModeBonus()
    { return 5; }

// the fall base - about five feet onto a hard surface the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ItemFallBaseFeet()
    { return 5; }

// the wood-like fall bonus - plus one on the save the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22ItemFallSoftBonus()
    { return 1; }

// the fleshy-soft fall bonus - plus five on the save the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ItemFallFleshyBonus()
    { return 5; }

// the extra-fall penalty - minus one per further five feet the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ItemFallPenaltyFeet()
    { return 5; }

// the cold-strike penalty - minus ten on the die after extreme cold the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22ItemColdSavePenalty()
    { return 10; }

// the paper exposure - one melee round of normal fire the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22ItemPaperRounds()
    { return 1; }

// the cloth exposure - two the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22ItemClothRounds()
    { return 2; }

// the bone or ivory exposure - three the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22ItemBoneRounds()
    { return 3; }

// the grenade range - three inches for every container missile the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22GrenadeRangeInches()
    { return 3; }

// the medium band - beyond one inch the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22GrenadeMediumFrom()
    { return 1; }

// the long band - beyond two inches the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22GrenadeLongFrom()
    { return 2; }

// the medium to-hit penalty - minus two the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22GrenadeMediumMinus()
    { return 2; }

// the long to-hit penalty - minus five the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22GrenadeLongMinus()
    { return 5; }

// the splash radius - all creatures within three feet of the break the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22GrenadeSplashFeet()
    { return 3; }

// the giant boulder - one foot in diameter the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22GiantBoulderFeet()
    { return 1; }

// the siege boulder - two feet the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22SiegeBoulderFeet()
    { return 2; }

// the acid container - one half pint, eight ounces the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22AcidOunces()
    { return 8; }

// the holy water container - one quarter pint, four ounces the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22HolyOunces()
    { return 4; }

// the oil container - one pint, sixteen ounces the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22OilOunces()
    { return 16; }

// the poison container - one quarter pint, four ounces the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22PoisonOunces()
    { return 4; }

// the acid splash - one hit point the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline int s22AcidSplashHp()
    { return 1; }

// the acid direct floor - two to eight hit points the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22AcidDirectMin()
    { return 2; }

// the acid direct ceiling - the same two to eight the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22AcidDirectMax()
    { return 8; }

// the holy water splash - two hit points the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22HolySplashHp()
    { return 2; }

// the holy water direct floor - two to seven hit points the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22HolyDirectMin()
    { return 2; }

// the holy water direct ceiling - the same two to seven the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22HolyDirectMax()
    { return 7; }

// the burning oil area - three feet diameter the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22OilDiameterFeet()
    { return 3; }

// the oil burn floor - one to three segments the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22OilBurnSegmentsMin()
    { return 1; }

// the oil burn ceiling - the same one to three the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22OilBurnSegmentsMax()
    { return 3; }

// the flaming oil direct floor - two to twelve the first round the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22OilDirectFirstMin()
    { return 2; }

// the flaming oil direct ceiling - the same two to twelve the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22OilDirectFirstMax()
    { return 12; }

// the flaming oil second floor - one to six the second round, then out the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22OilDirectSecondMin()
    { return 1; }

// the flaming oil second ceiling - the same one to six the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22OilDirectSecondMax()
    { return 6; }

// the walk-through floor - one to four hit points per melee round the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22OilWalkDamageMin()
    { return 1; }

// the walk-through ceiling - the same one to four the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22OilWalkDamageMax()
    { return 4; }

// the miss distance die - the d6 in feet the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22GrenadeMissDistanceDie()
    { return 6; }

// the miss direction die - the d8, long right through long over the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22GrenadeMissDirectionDie()
    { return 8; }

// the lantern area - a two-foot diameter flaming oil area the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22LanternAreaFeet()
    { return 2; }

// the thieves matrix rows - armor class minus ten through ten the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline int s22ThievesCount()
    { return 21; }

// the missile long penalty - minus five at long range the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22MissileLongMinus()
    { return 5; }

// the missile medium penalty - minus two at medium range the AD&D DMG sneak
// preview (print 33-38, 41-43)
inline int s22MissileMediumMinus()
    { return 2; }

// the armor class floor - below ten not possible the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22AcFloor()
    { return 10; }

// the off-chart projection - repeat twenty six times before continuing with
// twenty-one the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22AcProjectionRepeats()
    { return 6; }

// the monster matrix columns - up to one minus one through sixteen and up the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22MonsterMatrixCols()
    { return 12; }

// the surprise backstab floor - double damage the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline int s22BackstabMin()
    { return 2; }

// the surprise backstab ceiling - quintuple at the thirteenth through
// sixteenth band the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22BackstabMax()
    { return 5; }

// the assassination table rows - assassin levels one through fifteen the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline int s22AssassinationRows()
    { return 15; }

// the I.B print catch - the armor class three row prints eleven where the
// step wants thirteen the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22FighterAc3Prints()
    { return 11; }

// the I.C header - five level bands printed the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline int s22MuHeaderBands()
    { return 5; }

// the I.C data - four columns under the five bands, the count mismatch pinned
// as scanned the AD&D DMG sneak preview (print 33-38, 41-43)
inline int s22MuDataCols()
    { return 4; }

// the band floor of the amulet roll - the combined d6 plus d12, one and two
// the Seven Heavens, three the Twin Paradises, four Elysium, five the Happy
// Hunting Grounds, six and seven Olympus, eight Gladsheim, nine Limbo, ten
// Pandemonium, eleven and twelve the Abyss
inline int s22AmuletLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 11;
        case 9:
            return 13;
        case 10:
            return 14;
        case 11:
            return 15;
        case 12:
            return 16;
        case 13:
            return 18;
        case 14:
            return 19;
        case 15:
            return 20;
        case 16:
            return 21;
        default:
            return -99;
        }
    }

// the band ceiling of the same seventeen plane bands through twenty-one to
// twenty-four the Prime Material Plane
inline int s22AmuletHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 12;
        case 9:
            return 13;
        case 10:
            return 14;
        case 11:
            return 15;
        case 12:
            return 17;
        case 13:
            return 18;
        case 14:
            return 19;
        case 15:
            return 20;
        case 16:
            return 24;
        default:
            return -99;
        }
    }

// the plane code by band order, one the Seven Heavens through seventeen the
// Prime, the alternate results twenty-two the Ethereal twenty-three the
// Astral and twenty-four the alternate earth pinned as consts
inline int s22AmuletPlane(int b)
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
        default:
            return -99;
        }
    }

// the die floor of the periapt chart - one through eight the plus one
inline int s22PeriaptLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 9;
        case 2:
            return 15;
        case 3:
            return 19;
        default:
            return -99;
        }
    }

// the die ceiling through nineteen and twenty the plus four
inline int s22PeriaptHi(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 14;
        case 2:
            return 18;
        case 3:
            return 20;
        default:
            return -99;
        }
    }

// the permanent plus of the periapt by band, one through four
inline int s22PeriaptPlus(int b)
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
        default:
            return -99;
        }
    }

// the defender weapon grade - hit only by plus one through plus four
inline int s22HitOnlyPlus(int b)
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
        default:
            return -99;
        }
    }

// the attacker weapon grade that hits it, the same plus one through four
inline int s22HitOnlyAttacker(int b)
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
        default:
            return -99;
        }
    }

// the monster hit-dice floor of the alternative - four, six, eight, ten
inline int s22HitOnlyHdBase(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        default:
            return -99;
        }
    }

// the hit-dice plus of the alternative - one through four, characters of any
// sort exempt
inline int s22HitOnlyHdPlus(int b)
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
        default:
            return -99;
        }
    }

// the opponent armor class of the I.D point one matrix, minus ten through ten
inline int s22ThievesAc(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return -9;
        case 2:
            return -8;
        case 3:
            return -7;
        case 4:
            return -6;
        case 5:
            return -5;
        case 6:
            return -4;
        case 7:
            return -3;
        case 8:
            return -2;
        case 9:
            return -1;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 7;
        case 18:
            return 8;
        case 19:
            return 9;
        case 20:
            return 10;
        default:
            return -99;
        }
    }

// the to-hit score of the one-to-four band, the surprise backstab double
// damage
inline int s22ThievesL1(int b)
    {
        switch (b) {
        case 0:
            return 26;
        case 1:
            return 25;
        case 2:
            return 24;
        case 3:
            return 23;
        case 4:
            return 22;
        case 5:
            return 21;
        case 6:
            return 20;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 20;
        case 12:
            return 19;
        case 13:
            return 18;
        case 14:
            return 17;
        case 15:
            return 16;
        case 16:
            return 15;
        case 17:
            return 14;
        case 18:
            return 13;
        case 19:
            return 12;
        case 20:
            return 11;
        default:
            return -99;
        }
    }

// the five-to-eight band, the triple damage backstab
inline int s22ThievesL2(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 23;
        case 2:
            return 22;
        case 3:
            return 21;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 19;
        case 11:
            return 18;
        case 12:
            return 17;
        case 13:
            return 16;
        case 14:
            return 15;
        case 15:
            return 14;
        case 16:
            return 13;
        case 17:
            return 12;
        case 18:
            return 11;
        case 19:
            return 10;
        case 20:
            return 9;
        default:
            return -99;
        }
    }

// the nine-to-twelve band, the quadruple damage backstab
inline int s22ThievesL3(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 19;
        case 8:
            return 18;
        case 9:
            return 17;
        case 10:
            return 16;
        case 11:
            return 15;
        case 12:
            return 14;
        case 13:
            return 13;
        case 14:
            return 12;
        case 15:
            return 11;
        case 16:
            return 10;
        case 17:
            return 9;
        case 18:
            return 8;
        case 19:
            return 7;
        case 20:
            return 6;
        default:
            return -99;
        }
    }

// the thirteen-to-sixteen band, the quintuple damage backstab
inline int s22ThievesL4(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 19;
        case 6:
            return 18;
        case 7:
            return 17;
        case 8:
            return 16;
        case 9:
            return 15;
        case 10:
            return 14;
        case 11:
            return 13;
        case 12:
            return 12;
        case 13:
            return 11;
        case 14:
            return 10;
        case 15:
            return 9;
        case 16:
            return 8;
        case 17:
            return 7;
        case 18:
            return 6;
        case 19:
            return 5;
        case 20:
            return 4;
        default:
            return -99;
        }
    }

// the seventeen-to-twenty band, its footnote e missing from the print
inline int s22ThievesL5(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 19;
        case 4:
            return 18;
        case 5:
            return 17;
        case 6:
            return 16;
        case 7:
            return 15;
        case 8:
            return 14;
        case 9:
            return 13;
        case 10:
            return 12;
        case 11:
            return 11;
        case 12:
            return 10;
        case 13:
            return 9;
        case 14:
            return 8;
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
        default:
            return -99;
        }
    }

// the twenty-one-and-up band, the d footnote reused in the print
inline int s22ThievesL6(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 19;
        case 2:
            return 18;
        case 3:
            return 17;
        case 4:
            return 16;
        case 5:
            return 15;
        case 6:
            return 14;
        case 7:
            return 13;
        case 8:
            return 12;
        case 9:
            return 11;
        case 10:
            return 10;
        case 11:
            return 9;
        case 12:
            return 8;
        case 13:
            return 7;
        case 14:
            return 6;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 3;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 0;
        default:
            return -99;
        }
    }

// the percentile floor of the elemental scroll varieties - one through
// fifteen the air
inline int s22ElemScrollLo(int b)
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
        case 4:
            return 61;
        default:
            return -99;
        }
    }

// the percentile ceiling through sixty-one to one hundred the all
inline int s22ElemScrollHi(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 30;
        case 2:
            return 45;
        case 3:
            return 60;
        case 4:
            return 100;
        default:
            return -99;
        }
    }

// the variety code by row order - air, earth, fire, water, all
inline int s22ElemScrollKind(int b)
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
        default:
            return -99;
        }
    }

// the percentile floor of the lycanthrope scroll varieties - one through five
// the werebears, six through ten the wereboars, eleven through twenty the
// wererats, twenty-one through twenty-five the weretigers, twenty-six through
// forty the werewolves
inline int s22LycanScrollLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 21;
        case 4:
            return 26;
        case 5:
            return 41;
        case 6:
            return 99;
        default:
            return -99;
        }
    }

// the percentile ceiling through ninety-nine to one hundred the
// shape-changers
inline int s22LycanScrollHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 40;
        case 5:
            return 98;
        case 6:
            return 100;
        default:
            return -99;
        }
    }

// the variety code by row order - the five types through the all at forty-one
// through ninety-eight, the shape-changers last
inline int s22LycanScrollKind(int b)
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
        default:
            return -99;
        }
    }

// the attack strength band floor - one, twenty-six, fifty-one, seventy-six,
// one hundred one, one hundred twenty-six and up
inline int s22PsiCrushBand(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 26;
        case 2:
            return 51;
        case 3:
            return 76;
        case 4:
            return 101;
        case 5:
            return 126;
        default:
            return -99;
        }
    }

// the crush percent against the ten-to-fifty-nine defender band
inline int s22PsiCrushC1(int b)
    {
        switch (b) {
        case 0:
            return 72;
        case 1:
            return 75;
        case 2:
            return 79;
        case 3:
            return 84;
        case 4:
            return 90;
        case 5:
            return 97;
        default:
            return -99;
        }
    }

// the crush percent against the sixty-to-one-hundred-nine band
inline int s22PsiCrushC2(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 62;
        case 2:
            return 65;
        case 3:
            return 69;
        case 4:
            return 74;
        case 5:
            return 80;
        default:
            return -99;
        }
    }

// the crush percent against the hundred-ten-to-one-hundred-fifty-nine band
inline int s22PsiCrushC3(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 52;
        case 2:
            return 55;
        case 3:
            return 59;
        case 4:
            return 64;
        case 5:
            return 70;
        default:
            return -99;
        }
    }

// the crush percent against the hundred-sixty-to-two-hundred-nine band
inline int s22PsiCrushC4(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 42;
        case 2:
            return 45;
        case 3:
            return 49;
        case 4:
            return 54;
        case 5:
            return 60;
        default:
            return -99;
        }
    }

// the crush percent against the two-hundred-ten defender band - the printed
// overlap pinned as scanned
inline int s22PsiCrushC5(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 32;
        case 2:
            return 35;
        case 3:
            return 39;
        case 4:
            return 44;
        case 5:
            return 50;
        default:
            return -99;
        }
    }

// the crush percent against the two-hundred-sixty-to-three-hundred-nine band
inline int s22PsiCrushC6(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 22;
        case 2:
            return 25;
        case 3:
            return 29;
        case 4:
            return 34;
        case 5:
            return 40;
        default:
            return -99;
        }
    }

// the crush percent against the three-hundred-ten-and-up band
inline int s22PsiCrushC7(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 15;
        case 3:
            return 19;
        case 4:
            return 24;
        case 5:
            return 30;
        default:
            return -99;
        }
    }

// the intelligence and wisdom band floor - zero through five up to
// thirty-eight and up, eleven bands
inline int s22PsiBlastIntLo(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 6;
        case 2:
            return 10;
        case 3:
            return 14;
        case 4:
            return 18;
        case 5:
            return 22;
        case 6:
            return 26;
        case 7:
            return 30;
        case 8:
            return 34;
        case 9:
            return 36;
        case 10:
            return 38;
        default:
            return -99;
        }
    }

// the saving throw at short range - twenty down to zero
inline int s22PsiBlastShort(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 18;
        case 2:
            return 16;
        case 3:
            return 14;
        case 4:
            return 12;
        case 5:
            return 10;
        case 6:
            return 8;
        case 7:
            return 6;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 0;
        default:
            return -99;
        }
    }

// the saving throw at medium range - nineteen down to minus one
inline int s22PsiBlastMedium(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 17;
        case 2:
            return 15;
        case 3:
            return 13;
        case 4:
            return 11;
        case 5:
            return 9;
        case 6:
            return 7;
        case 7:
            return 5;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return -1;
        default:
            return -99;
        }
    }

// the saving throw at long range - eighteen down to minus two, death through
// the two insanities
inline int s22PsiBlastLong(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 16;
        case 2:
            return 14;
        case 3:
            return 12;
        case 4:
            return 10;
        case 5:
            return 8;
        case 6:
            return 6;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return -2;
        default:
            return -99;
        }
    }

// the short range in inches - the blast two, the thrust three, the whip four,
// the id six, the crush five
inline int s22PsiRangeShort(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 5;
        default:
            return -99;
        }
    }

// the medium range - four through twelve, the crush prints no medium, pinned
// zero with the conversion noted
inline int s22PsiRangeMedium(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 12;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// the long range - six through eighteen, the crush prints no long, pinned
// zero with the conversion noted
inline int s22PsiRangeLong(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 9;
        case 2:
            return 12;
        case 3:
            return 18;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

// the die score the level one cleric needs - skeleton ten, zombie thirteen,
// ghoul sixteen, shadow nineteen, wight twenty, the printed dash pinned zero
// with the conversion noted
inline int s22TurnLev1(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 13;
        case 2:
            return 16;
        case 3:
            return 19;
        case 4:
            return 20;
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
        default:
            return -99;
        }
    }

// the level two band - ghost twenty, wraith twenty, the mummy through special
// dashed
inline int s22TurnLev2(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 10;
        case 2:
            return 13;
        case 3:
            return 16;
        case 4:
            return 19;
        case 5:
            return 20;
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
        default:
            return -99;
        }
    }

// the level three band - wraith twenty, the mummy and beyond dashed
inline int s22TurnLev3(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 7;
        case 2:
            return 10;
        case 3:
            return 13;
        case 4:
            return 16;
        case 5:
            return 19;
        case 6:
            return 20;
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
        default:
            return -99;
        }
    }

// the level four band - mummy twenty, the spectre and beyond dashed
inline int s22TurnLev4(int b)
    {
        switch (b) {
        case 0:
            return 97;
        case 1:
            return 97;
        case 2:
            return 4;
        case 3:
            return 7;
        case 4:
            return 10;
        case 5:
            return 13;
        case 6:
            return 16;
        case 7:
            return 20;
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
        default:
            return -99;
        }
    }

// the level five band - spectre twenty, the vampire and beyond dashed
inline int s22TurnLev5(int b)
    {
        switch (b) {
        case 0:
            return 97;
        case 1:
            return 97;
        case 2:
            return 97;
        case 3:
            return 4;
        case 4:
            return 7;
        case 5:
            return 10;
        case 6:
            return 13;
        case 7:
            return 16;
        case 8:
            return 20;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return -99;
        }
    }

// the level six band - vampire twenty, the ghast row dashed
inline int s22TurnLev6(int b)
    {
        switch (b) {
        case 0:
            return 98;
        case 1:
            return 98;
        case 2:
            return 97;
        case 3:
            return 97;
        case 4:
            return 4;
        case 5:
            return 7;
        case 6:
            return 10;
        case 7:
            return 13;
        case 8:
            return 16;
        case 9:
            return 20;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return -99;
        }
    }

// the level seven band - ghast twenty, the lich and special dashed
inline int s22TurnLev7(int b)
    {
        switch (b) {
        case 0:
            return 98;
        case 1:
            return 98;
        case 2:
            return 98;
        case 3:
            return 97;
        case 4:
            return 97;
        case 5:
            return 4;
        case 6:
            return 7;
        case 7:
            return 10;
        case 8:
            return 13;
        case 9:
            return 16;
        case 10:
            return 20;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return -99;
        }
    }

// the level eight band - lich nineteen, special twenty
inline int s22TurnLev8(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 98;
        case 2:
            return 98;
        case 3:
            return 98;
        case 4:
            return 97;
        case 5:
            return 97;
        case 6:
            return 4;
        case 7:
            return 7;
        case 8:
            return 10;
        case 9:
            return 13;
        case 10:
            return 16;
        case 11:
            return 19;
        case 12:
            return 20;
        default:
            return -99;
        }
    }

// the nine-to-thirteen band, the T symbol pinned ninety-seven and the D
// ninety-eight with the conversion noted
inline int s22TurnLev9(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 99;
        case 2:
            return 98;
        case 3:
            return 98;
        case 4:
            return 98;
        case 5:
            return 97;
        case 6:
            return 97;
        case 7:
            return 4;
        case 8:
            return 7;
        case 9:
            return 10;
        case 10:
            return 13;
        case 11:
            return 16;
        case 12:
            return 19;
        default:
            return -99;
        }
    }

// the fourteen-and-up band, the starred destroy pinned ninety-nine with the
// conversion noted
inline int s22TurnLev14(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 99;
        case 2:
            return 99;
        case 3:
            return 99;
        case 4:
            return 98;
        case 5:
            return 98;
        case 6:
            return 98;
        case 7:
            return 97;
        case 8:
            return 97;
        case 9:
            return 4;
        case 10:
            return 7;
        case 11:
            return 10;
        case 12:
            return 13;
        default:
            return -99;
        }
    }

// the class code - one cleric, two fighter, three magic-user, four thief
inline int s22SaveClass(int b)
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
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        default:
            return -99;
        }
    }

// the level band floor - one through three, zero level, one through five, one
// through four
inline int s22SaveLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 7;
        case 3:
            return 10;
        case 4:
            return 13;
        case 5:
            return 16;
        case 6:
            return 19;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 5;
        case 11:
            return 7;
        case 12:
            return 9;
        case 13:
            return 11;
        case 14:
            return 13;
        case 15:
            return 15;
        case 16:
            return 17;
        case 17:
            return 1;
        case 18:
            return 6;
        case 19:
            return 11;
        case 20:
            return 16;
        case 21:
            return 21;
        case 22:
            return 1;
        case 23:
            return 5;
        case 24:
            return 9;
        case 25:
            return 13;
        case 26:
            return 17;
        case 27:
            return 21;
        default:
            return -99;
        }
    }

// the poison or death magic score
inline int s22SavePoison(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 16;
        case 8:
            return 14;
        case 9:
            return 13;
        case 10:
            return 11;
        case 11:
            return 10;
        case 12:
            return 8;
        case 13:
            return 7;
        case 14:
            return 5;
        case 15:
            return 4;
        case 16:
            return 3;
        case 17:
            return 14;
        case 18:
            return 13;
        case 19:
            return 11;
        case 20:
            return 10;
        case 21:
            return 8;
        case 22:
            return 13;
        case 23:
            return 12;
        case 24:
            return 11;
        case 25:
            return 10;
        case 26:
            return 9;
        case 27:
            return 8;
        default:
            return -99;
        }
    }

// the petrifaction or polymorph score
inline int s22SavePetrify(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 12;
        case 2:
            return 10;
        case 3:
            return 9;
        case 4:
            return 8;
        case 5:
            return 7;
        case 6:
            return 5;
        case 7:
            return 17;
        case 8:
            return 15;
        case 9:
            return 14;
        case 10:
            return 12;
        case 11:
            return 11;
        case 12:
            return 9;
        case 13:
            return 8;
        case 14:
            return 6;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 13;
        case 18:
            return 11;
        case 19:
            return 9;
        case 20:
            return 7;
        case 21:
            return 5;
        case 22:
            return 12;
        case 23:
            return 11;
        case 24:
            return 10;
        case 25:
            return 9;
        case 26:
            return 8;
        case 27:
            return 7;
        default:
            return -99;
        }
    }

// the rod staff or wand score
inline int s22SaveRod(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 13;
        case 2:
            return 11;
        case 3:
            return 10;
        case 4:
            return 9;
        case 5:
            return 8;
        case 6:
            return 6;
        case 7:
            return 18;
        case 8:
            return 16;
        case 9:
            return 15;
        case 10:
            return 13;
        case 11:
            return 12;
        case 12:
            return 10;
        case 13:
            return 9;
        case 14:
            return 7;
        case 15:
            return 6;
        case 16:
            return 5;
        case 17:
            return 11;
        case 18:
            return 9;
        case 19:
            return 7;
        case 20:
            return 5;
        case 21:
            return 3;
        case 22:
            return 14;
        case 23:
            return 12;
        case 24:
            return 10;
        case 25:
            return 8;
        case 26:
            return 6;
        case 27:
            return 4;
        default:
            return -99;
        }
    }

// the breath weapon score - the fighter nine-to-ten row prints nine where the
// eleven would sit, pinned as scanned
inline int s22SaveBreath(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 15;
        case 2:
            return 13;
        case 3:
            return 12;
        case 4:
            return 11;
        case 5:
            return 10;
        case 6:
            return 8;
        case 7:
            return 20;
        case 8:
            return 17;
        case 9:
            return 16;
        case 10:
            return 13;
        case 11:
            return 12;
        case 12:
            return 9;
        case 13:
            return 8;
        case 14:
            return 5;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 15;
        case 18:
            return 13;
        case 19:
            return 11;
        case 20:
            return 9;
        case 21:
            return 7;
        case 22:
            return 16;
        case 23:
            return 15;
        case 24:
            return 14;
        case 25:
            return 13;
        case 26:
            return 12;
        case 27:
            return 11;
        default:
            return -99;
        }
    }

// the spell score - the same row prints eleven, pinned as scanned
inline int s22SaveSpell(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 14;
        case 2:
            return 12;
        case 3:
            return 11;
        case 4:
            return 10;
        case 5:
            return 9;
        case 6:
            return 7;
        case 7:
            return 19;
        case 8:
            return 17;
        case 9:
            return 16;
        case 10:
            return 14;
        case 11:
            return 13;
        case 12:
            return 11;
        case 13:
            return 10;
        case 14:
            return 8;
        case 15:
            return 7;
        case 16:
            return 6;
        case 17:
            return 12;
        case 18:
            return 10;
        case 19:
            return 8;
        case 20:
            return 6;
        case 21:
            return 4;
        case 22:
            return 15;
        case 23:
            return 13;
        case 24:
            return 11;
        case 25:
            return 9;
        case 26:
            return 7;
        case 27:
            return 5;
        default:
            return -99;
        }
    }

// the acid save - bone or ivory eleven through the parchment sixteen
inline int s22ItemAcid(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 4;
        case 2:
            return 12;
        case 3:
            return 6;
        case 4:
            return 5;
        case 5:
            return 10;
        case 6:
            return 15;
        case 7:
            return 7;
        case 8:
            return 13;
        case 9:
            return 12;
        case 10:
            return 16;
        case 11:
            return 3;
        case 12:
            return 9;
        case 13:
            return 8;
        default:
            return -99;
        }
    }

// the crushing blow save - the hurled flask against the hard surface
inline int s22ItemCrush(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 18;
        case 2:
            return 6;
        case 3:
            return 19;
        case 4:
            return 20;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 6;
        case 8:
            return 14;
        case 9:
            return 20;
        case 10:
            return 11;
        case 11:
            return 17;
        case 12:
            return 13;
        case 13:
            return 10;
        default:
            return -99;
        }
    }

// the normal blow save - against the tough but slightly yielding surface
inline int s22ItemBlow(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 3;
        case 3:
            return 14;
        case 4:
            return 15;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 9;
        case 9:
            return 15;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 6;
        case 13:
            return 3;
        default:
            return -99;
        }
    }

// the disintegration save - the magical effect
inline int s22ItemDisint(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 19;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 17;
        case 8:
            return 19;
        case 9:
            return 20;
        case 10:
            return 20;
        case 11:
            return 18;
        case 12:
            return 20;
        case 13:
            return 19;
        default:
            return -99;
        }
    }

// the fall save - parchment prints zero, pinned as scanned
inline int s22ItemFall(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 11;
        case 2:
            return 2;
        case 3:
            return 13;
        case 4:
            return 14;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 4;
        case 9:
            return 13;
        case 10:
            return 0;
        case 11:
            return 4;
        case 12:
            return 2;
        case 13:
            return 1;
        default:
            return -99;
        }
    }

// the fireball save - the parchment prints twenty-five, pinned as scanned
inline int s22ItemFireball(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 5;
        case 2:
            return 20;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 13;
        case 6:
            return 15;
        case 7:
            return 6;
        case 8:
            return 18;
        case 9:
            return 14;
        case 10:
            return 25;
        case 11:
            return 7;
        case 12:
            return 15;
        case 13:
            return 11;
        default:
            return -99;
        }
    }

// the magical fire save
inline int s22ItemFireMag(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 3;
        case 2:
            return 16;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 6;
        case 6:
            return 14;
        case 7:
            return 2;
        case 8:
            return 13;
        case 9:
            return 9;
        case 10:
            return 21;
        case 11:
            return 3;
        case 12:
            return 11;
        case 13:
            return 7;
        default:
            return -99;
        }
    }

// the normal fire save - the oil and the wood fire
inline int s22ItemFireNorm(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 13;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 13;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 18;
        case 11:
            return 2;
        case 12:
            return 9;
        case 13:
            return 5;
        default:
            return -99;
        }
    }

// the frost save - the white dragon breath and the cone of cold
inline int s22ItemFrost(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 1;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 3;
        case 6:
            return 12;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 6;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        default:
            return -99;
        }
    }

// the lightning bolt save - the blue dragon breath
inline int s22ItemBolt(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 2;
        case 2:
            return 18;
        case 3:
            return 15;
        case 4:
            return 17;
        case 5:
            return 13;
        case 6:
            return 18;
        case 7:
            return 11;
        case 8:
            return 16;
        case 9:
            return 18;
        case 10:
            return 20;
        case 11:
            return 14;
        case 12:
            return 10;
        case 13:
            return 12;
        default:
            return -99;
        }
    }

// the electrical discharge save - the eel the trap the item
inline int s22ItemElec(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 15;
        case 7:
            return 1;
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
            return 1;
        default:
            return -99;
        }
    }

// the preview doctrine - magic items explained in the text of the modules are
// not repeated the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ModuleItemsNotRepeated()
    { return true; }

// the creation doctrine - assign the properties of one magic item to a
// different ordinary item, the bracers sandals and earrings of invisibility,
// the fire elemental gem from the ring of fire the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline bool s22NewItemDoctrine()
    { return true; }

// the amulet - the travel is absolutely safe, random until the device is
// learned the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22AmuletSafeTravel()
    { return true; }

// the hammer - with the girdle and the gauntlets and the true name it strikes
// dead any giant it hits the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22HammerGiantSlain()
    { return true; }

// the hammer - only one throw every other round, it is too difficult to hurl
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22HammerEveryOtherRound()
    { return true; }

// the helm - the globe of air on the command word, maintained until it is
// spoken again the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22HelmCommandGlobe()
    { return true; }

// the pigments - only normal inanimate things, never monsters people or
// golems the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PigmentInanimateOnly()
    { return true; }

// the pigments - depicted valuables appear valuable but are tin lead paste
// gems brass and bone the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PigmentValuablesFalse()
    { return true; }

// the pearl - keep it on the person or the wisdom gain is lost the AD&D DMG
// sneak preview (print 33-38, 41-43)
inline bool s22PearlRetainOrLose()
    { return true; }

// the periapt - roll once when found, the result is the permanent plus of the
// item the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PeriaptPermanentPlus()
    { return true; }

// the philter of love - the enamouring lasts until a dispel magic is cast the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PhilterDispelEnds()
    { return true; }

// the ring - forego the protection to attempt the charm at minus two, a
// failure loses the protection for good the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline bool s22RingCharmGamble()
    { return true; }

// the ring - any weapon the wearer uses hits the attuned elementals even if
// it is not magical the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22RingAnyWeaponHits()
    { return true; }

// the ring - the elementals recognize it, respect if the wearer is strong,
// hatred and the desire to slay if weak the AD&D DMG sneak preview (print
// 33-38, 41-43)
inline bool s22RingRespectDoctrine()
    { return true; }

// the special note - all protection scrolls are cumulative in effect but not
// in duration the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ScrollsCumulative()
    { return true; }

// the anti-magic globe - a drained item cancels the spell and the protection
// ceases the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ScrollMagicDrainCancels()
    { return true; }

// the anti-magic globe - artifacts and relics do not suffer its relatively
// weak magic the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ScrollMagicArtifactsImmune()
    { return true; }

// the possession scroll - it protects even dead bodies within the circle the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ScrollPossessionDeadBodies()
    { return true; }

// the shape-changer scroll - it covers the doppelgangers and the jackolweres
// as well as the actual lycanthropes the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline bool s22ScrollLycanShapechangers()
    { return true; }

// the hit-only table - the hit-dice alternative does not apply to characters
// of any sort the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22HitOnlyCharactersExempt()
    { return true; }

// the grenades - oil must be alight to cause damage, the rag or the torch the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22GrenadeOilAlightOnly()
    { return true; }

// the grenades - an unstoppered container hurled into the mouth needs no
// breakage the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22GrenadePoisonSwallowed()
    { return true; }

// the holy water - a non-material ghost or a gaseous vampire cannot be harmed
// by it the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22HolyWaterNonmaterialImmune()
    { return true; }

// the turning - a failure means no further attempt against those undead the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22TurnNoRetry()
    { return true; }

// the evil cleric - the neutral undead ignore the party, the friendly ones
// follow the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22TurnNeutralIgnore()
    { return true; }

// the psionic combat - all attacks and defenses are simultaneous, the points
// taken at the end of the segment the AD&D DMG sneak preview (print 33-38,
// 41-43)
inline bool s22PsiSimultaneous()
    { return true; }

// the psychic crush - the user may use only the G thought shield defense the
// AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PsiCrushThoughtShieldOnly()
    { return true; }

// the mind bar - the letter results read as minus forty points until the
// psionic strength is gone the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PsiMindBarLetters()
    { return true; }

// the idiocy - the psionic ability is lost forever but the idiocy is curable
// by a heal spell the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PsiIdiocyHealable()
    { return true; }

// the robot - the control holds until released or two to eight weeks and a
// saving throw versus magic the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PsiRobotSaveVsMagic()
    { return true; }

// the multi-class rule - check the matrix for each class and use the most
// favorable result the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22SaveMultiClassBest()
    { return true; }

// the monster saves - a plus in hit points moves the creature upwards by one
// hit die the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22MonsterPlusBump()
    { return true; }

// the non-intelligent save - one-half the hit dice, rounded upwards the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline bool s22NonIntRoundedUp()
    { return true; }

// the non-intelligent save - the halving never applies to poison or death
// magic the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22NonIntPoisonException()
    { return true; }

// the items - non-conforming items interpolate, the exposure actually lands
// on the item the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ItemInterpolated()
    { return true; }

// the items - the own-mode plus five holds for magical and non-magical alike
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ItemOwnModeBoth()
    { return true; }

// the save footnotes - the polymorph wand, the petrifying breath and the
// self-saved spells excluded from their columns the AD&D DMG sneak preview
// (print 33-38, 41-43)
inline bool s22SaveSpellExclusions()
    { return true; }

// the print catch - the preview prints Glacial Rift of the Freet Giant Jari
// for the G2 Frost Giant Jarl the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22FreetJariPrintCatch()
    { return true; }

// the print catch - the demon scroll prints con penetrate for cannot
// penetrate the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ConPenetratePrintCatch()
    { return true; }

// the print catch - the lycanthrope scroll prints jackolwere for the
// jackalwere the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22JackolwerePrintCatch()
    { return true; }

// the print catch - the undead scroll prints wralths for the wraiths the AD&D
// DMG sneak preview (print 33-38, 41-43)
inline bool s22WralthsPrintCatch()
    { return true; }

// the print catch - the undead matrix prints Ghost twice, the second row for
// the Ghast the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22GhastPrintsGhost()
    { return true; }

// the print - the scroll heading prints Petrifaction for petrification,
// pinned as scanned the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PetrifactionPrint()
    { return true; }

// the print catch - the items cold footnote prints farce for force and an die
// for on the die the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22FarceAnDiePrintCatch()
    { return true; }

// the print catch - the I.D point one header points the seventeen-to-twenty
// band at a footnote e that never prints, reusing the d footnote at
// twenty-one and up the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22ThievesFootnotePrintCatch()
    { return true; }

// the print catch - the I.B armor class three row prints eleven where the
// column step wants thirteen the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22FighterAc3PrintCatch()
    { return true; }

// the print catch - the I.B armor class ten row drops its three-to-four level
// cell the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22FighterAc10GapPrintCatch()
    { return true; }

// the print catch - the I.C header prints five level bands over four data
// columns the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22MuBandsPrintCatch()
    { return true; }

// the print catch - the I.C heading carries a dangling Opponent at its end
// the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22MuOpponentDangling()
    { return true; }

// the print catch - the IV.B defender bands print two hundred ten through two
// hundred sixty-nine against the two hundred sixty through three hundred nine
// band the AD&D DMG sneak preview (print 33-38, 41-43)
inline bool s22PsiBandPrintCatch()
    { return true; }

}   // namespace rules
