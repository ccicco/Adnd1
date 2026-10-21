// =========================================================================================
// Adnd1 - rules/oa91huhuien.h
// OA MONSTERS - THE HU HSIEN BOX, printed capture pp. 269-272 - the triple
// round
// census 642 -> 643.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 173 closed, 62 open - the hu hsien box
// flips (census 642 -> 643); NEXT - R721: the Kala (capture p. 272), prefix
// dki (verify free at the landing), audit "R721 OA monsters Kala audit",
// include after rules/oa91huhuien.h
//
namespace rules {

// ---- the hu hsien stat block ----

// the hu hsien armor class - the AC 7 of the stat block (print capture p.
// 270)
inline int dkhHuAC()
    { return 7; }

// the hu hsien move - the 15 of the stat block (print capture p. 270)
inline int dkhHuMove()
    { return 15; }

// the hu hsien hit dice - the 6 of the stat block (print capture p. 270)
inline int dkhHuHD()
    { return 6; }

// the in-lair percentage - the 10% of the stat block (print capture p. 270)
inline int dkhHuLairPct()
    { return 10; }

// the frequency - the rare of the stat block (print capture p. 269)
inline int dkhHuFrequencyRare()
    { return 1; }

// the treasure type - the I, S, T of the stat block (print capture p. 270)
inline int dkhHuTreasureIST()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 270)
inline int dkhHuAttackCount()
    { return 1; }

// the damage minimum - the 1 of the 1-6 or by weapon type (print capture p.
// 270)
inline int dkhHuDmgMin()
    { return 1; }

// the damage maximum - the 6 of the 1-6 or by weapon type (print capture p.
// 270)
inline int dkhHuDmgMax()
    { return 6; }

// the damage clause - the 1-6 or by weapon type of the stat block (print
// capture p. 270)
inline int dkhHuDamageByWeaponType()
    { return 1; }

// the special attacks - the see below of the stat block (print capture p.
// 270)
inline int dkhHuSpecialAttacksSeeBelow()
    { return 1; }

// the special defenses - the see below of the stat block (print capture p.
// 270)
inline int dkhHuSpecialDefensesSeeBelow()
    { return 1; }

// the magic resistance - the 50% of the stat block (print capture p. 270)
inline int dkhHuMRPct()
    { return 50; }

// the intelligence - the genius of the stat block (print capture p. 270)
inline int dkhHuIntelligenceGenius()
    { return 1; }

// the alignment - the chaotic evil of the stat block (print capture p. 270)
inline int dkhHuAlignmentChaoticEvil()
    { return 1; }

// the size class - the M of the stat block (print capture p. 270)
inline int dkhHuSizeMedium()
    { return 1; }

// the psionic ability - the nil of the stat block (print capture p. 270)
inline int dkhHuPsionicNil()
    { return 1; }

// the level value - the VII of the VII/1,150 + 6/hp (print capture p. 270)
inline int dkhHuLevelVII()
    { return 1; }

// the xp base - the 1,150 of the VII/1,150 + 6 per hp (print capture p. 270)
inline int dkhHuXPBase()
    { return 1150; }

// the xp per hit point - the 6 of the VII/1,150 + 6/hp (print capture p. 270)
inline int dkhHuXPPerHP()
    { return 6; }

// ---- the hu hsien fox forms ----

// the race - a race of shapeshifting foxes, supernatural in origin (print
// capture p. 270)
inline int dkhHuShapeshiftingFoxes()
    { return 1; }

// the origin - supernatural in origin (print capture p. 270)
inline int dkhHuSupernaturalOrigin()
    { return 1; }

// the kinship - in many ways similar to the hengeyokai (print capture p. 270)
inline int dkhHuHengeyokaiKin()
    { return 1; }

// the form count - the two basic forms of the shapeshifting fox (print
// capture p. 270)
inline int dkhHuFormsCount()
    { return 2; }

// the first form - the fox that walks on its hind legs and holds items in its
// front paws (print capture p. 270)
inline int dkhHuFoxFormUpright()
    { return 1; }

// the second form - a human maiden of exceptional beauty and grace (print
// capture p. 270)
inline int dkhHuHumanMaidenForm()
    { return 1; }

// the human form charisma - the 18 Charisma of the maiden (print capture p.
// 270)
inline int dkhHuCharisma()
    { return 18; }

// the human form comeliness - the 25 Comeliness of the maiden (print capture
// p. 270)
inline int dkhHuComeliness()
    { return 25; }

// the tell - the hu hsien tail never changes (print capture p. 270)
inline int dkhHuTailNeverChanges()
    { return 1; }

// the conceal - clever to conceal the tail under its robes (print capture p.
// 270)
inline int dkhHuConcealsTailUnderRobes()
    { return 1; }

// the weapon requirement - only hit by +3 weapons or better (print capture p.
// 270)
inline int dkhHuWeaponPlusRequired()
    { return 3; }

// the regeneration - the limited healing of 2 hit points per hour (print
// capture p. 270)
inline int dkhHuRegenPerHour()
    { return 2; }

// ---- the hu hsien power roster ----

// the at-will count - the twelve spell-like effects (print capture p. 270)
inline int dkhHuAtWillCount()
    { return 12; }

// the at-will rate - one per round (print capture p. 270)
inline int dkhHuAtWillPerRound()
    { return 1; }

// the first at-will - the invisible (print capture p. 270)
inline int dkhHuInvisible()
    { return 1; }

// the second at-will - the polymorph self (print capture p. 270)
inline int dkhHuPolymorphSelf()
    { return 1; }

// the third at-will - the disguise (print capture p. 270)
inline int dkhHuDisguise()
    { return 1; }

// the fourth at-will - the chameleon (print capture p. 270)
inline int dkhHuChameleon()
    { return 1; }

// the fifth at-will - the know history (print capture p. 270)
inline int dkhHuKnowHistory()
    { return 1; }

// the sixth at-will - the hypnotism (print capture p. 270)
inline int dkhHuHypnotism()
    { return 1; }

// the seventh at-will - the read magic (print capture p. 270)
inline int dkhHuReadMagic()
    { return 1; }

// the eighth at-will - the comprehend languages (print capture p. 270)
inline int dkhHuComprehendLanguages()
    { return 1; }

// the ninth at-will - the ventriloquism (print capture p. 270)
inline int dkhHuVentriloquism()
    { return 1; }

// the tenth at-will - the apparition (print capture p. 270)
inline int dkhHuApparition()
    { return 1; }

// the eleventh at-will - the ESP (print capture p. 270)
inline int dkhHuESP()
    { return 1; }

// the twelfth at-will - the hypnotic pattern (print capture p. 270)
inline int dkhHuHypnoticPattern()
    { return 1; }

// the once-per-day count - the possess, servant horde, and major creation
// (print capture p. 270)
inline int dkhHuDailyCount()
    { return 3; }

// the first daily - the possess (print capture p. 270)
inline int dkhHuPossess()
    { return 1; }

// the second daily - the servant horde (print capture p. 270)
inline int dkhHuServantHorde()
    { return 1; }

// the third daily - the major creation (print capture p. 270)
inline int dkhHuMajorCreation()
    { return 1; }

// the weekly uses - three times per week (print capture p. 270)
inline int dkhHuWeeklyUses()
    { return 3; }

// the weekly choices - the reward or ancient curse (print capture p. 270)
inline int dkhHuWeeklyPowersCount()
    { return 2; }

// the first weekly - the reward (print capture p. 270)
inline int dkhHuReward()
    { return 1; }

// the second weekly - the ancient curse (print capture p. 270)
inline int dkhHuAncientCurse()
    { return 1; }

// the fascination - the 25 Comeliness power of the human form (print capture
// p. 270)
inline int dkhHuComelinessFascination()
    { return 1; }

// ---- the hu hsien defenses ----

// the fire immunity - immune to fire (print capture p. 270)
inline int dkhHuImmuneToFire()
    { return 1; }

// the cold resistance - only half damage from cold attacks, no damage on a
// successful save (print capture p. 270)
inline int dkhHuHalfColdDamage()
    { return 1; }

// the electrical vulnerability - double damage from electrical-based attacks
// (print capture p. 270)
inline int dkhHuDoubleElectricalDamage()
    { return 1; }

// the storm fear - greatly fears thunderstorms (print capture p. 270)
inline int dkhHuFearsThunderstorms()
    { return 1; }

// the celestial clause - the Celestial Emperor sometimes sends the Thunder
// God to punish the wicked (print capture p. 270)
inline int dkhHuThunderGodPunishment()
    { return 1; }

// ---- the hu hsien life drain ----

// the power source - gain the shapeshifting power by draining the life force
// of human victims (print capture p. 270)
inline int dkhHuDrainsLifeForce()
    { return 1; }

// the snare - must assume human form and snare the victim in its web (print
// capture p. 270)
inline int dkhHuHumanFormSnare()
    { return 1; }

// the drain rate - the loss of one level of experience per day with the hu
// hsien (print capture p. 270)
inline int dkhHuDrainLevelsPerDay()
    { return 1; }

// the blind love - the victim is not aware of what is happening (print
// capture p. 270)
inline int dkhHuVictimUnaware()
    { return 1; }

// the rescue - only saved if the hu hsien is driven away or destroyed by
// others (print capture p. 270)
inline int dkhHuSavedOnlyByOthers()
    { return 1; }

// ---- the hu hsien character and lair ----

// the softer side - not totally cruel and ungrateful (print capture p. 270)
inline int dkhHuNotTotallyCruel()
    { return 1; }

// the gratitude - known to reward or aid people who helped them (print
// capture p. 270)
inline int dkhHuRewardsHelpers()
    { return 1; }

// the scholarly lure - particularly attracted to scholars, both for good and
// ill (print capture p. 270)
inline int dkhHuAttractedToScholars()
    { return 1; }

// the tricks - noted for devious tricks, especially on those who scoff at
// their existence (print capture p. 270)
inline int dkhHuDeviousTricks()
    { return 1; }

// the vice - particularly fond of wine, unable to resist its temptation
// (print capture p. 270)
inline int dkhHuFondOfWine()
    { return 1; }

// the tell - once intoxicated they unwillingly revert to their true forms
// (print capture p. 270)
inline int dkhHuRevertsWhenIntoxicated()
    { return 1; }

// the placement - lairs normally on the edges of human villages (print
// capture p. 270)
inline int dkhHuLairOnVillageEdge()
    { return 1; }

// the first lair - an abandoned house with the illusion of great wealth and
// luxury (print capture p. 270)
inline int dkhHuAbandonedHouseIllusion()
    { return 1; }

// the second lair - a fox den enchanted to appear as a great mansion inside
// (print capture p. 270)
inline int dkhHuFoxDenMansion()
    { return 1; }

// the morning after - the traveler dines in a grand hall and awakens in the
// cramped space under the floors (print capture p. 270)
inline int dkhHuGrandHallFloorboards()
    { return 1; }

// ---- the ikiryo stat block ----

// the frequency - the very rare of the stat block (print capture p. 271)
inline int dkhIkFrequencyVeryRare()
    { return 1; }

// the appearing - the 1 of the stat block (print capture p. 271)
inline int dkhIkAppear()
    { return 1; }

// the armor class - the nil of the stat block (print capture p. 271)
inline int dkhIkACNil()
    { return 1; }

// the move - the nil of the stat block (print capture p. 271)
inline int dkhIkMoveNil()
    { return 1; }

// the hit dice - the nil of the stat block (print capture p. 271)
inline int dkhIkHDNil()
    { return 1; }

// the in-lair - the nil of the stat block (print capture p. 271)
inline int dkhIkLairNil()
    { return 1; }

// the treasure type - the nil of the stat block (print capture p. 271)
inline int dkhIkTreasureNil()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 271)
inline int dkhIkAttackCount()
    { return 1; }

// the damage - the nil of the stat block (print capture p. 271)
inline int dkhIkDamageNil()
    { return 1; }

// the special attack - the ability drain of the stat block (print capture p.
// 271)
inline int dkhIkSpecialAttackAbilityDrain()
    { return 1; }

// the special defenses - the see below of the stat block (print capture p.
// 271)
inline int dkhIkSpecialDefensesSeeBelow()
    { return 1; }

// the magic resistance - the see below of the stat block (print capture p.
// 271)
inline int dkhIkMRSeeBelow()
    { return 1; }

// the intelligence - the very of the stat block (print capture p. 271)
inline int dkhIkIntelligenceVery()
    { return 1; }

// the alignment - the chaotic evil of the stat block (print capture p. 271)
inline int dkhIkAlignmentChaoticEvil()
    { return 1; }

// the size - the nil of the stat block (print capture p. 271)
inline int dkhIkSizeNil()
    { return 1; }

// the psionic minimum - the 200 of the 200-260 psionic ability (print capture
// p. 271)
inline int dkhIkPsionicMin()
    { return 200; }

// the psionic maximum - the 260 of the 200-260 psionic ability (print capture
// p. 271)
inline int dkhIkPsionicMax()
    { return 260; }

// the attack modes - the B, C, D, E of the stat block (print capture p. 271)
inline int dkhIkAttackModesBCDE()
    { return 1; }

// the attack mode count - the B, C, D, E of the modes (print capture p. 271)
inline int dkhIkAttackModesCount()
    { return 4; }

// the defense modes - the F, G, H of the stat block (print capture p. 271)
inline int dkhIkDefenseModesFGH()
    { return 1; }

// the defense mode count - the F, G, H of the modes (print capture p. 271)
inline int dkhIkDefenseModesCount()
    { return 3; }

// the level value - the VIII of the VIII/3,500 (print capture p. 271)
inline int dkhIkLevelVIII()
    { return 1; }

// the xp base - the 3,500 of the VIII/3,500 (print capture p. 271)
inline int dkhIkXPBase()
    { return 3500; }

// ---- the ikiryo nature ----

// the nature - a projection of the evil thoughts of a living person (print
// capture p. 271)
inline int dkhIkProjectionOfEvilThoughts()
    { return 1; }

// the origin - comes into being from intense thoughts of hate or jealousy
// (print capture p. 271)
inline int dkhIkBornOfHateOrJealousy()
    { return 1; }

// the unknowing source - born without the knowledge of the person who has the
// feelings (print capture p. 271)
inline int dkhIkSourceUnaware()
    { return 1; }

// the independence - once in existence it has a will of its own (print
// capture p. 271)
inline int dkhIkWillOfItsOwn()
    { return 1; }

// the body - no form or real body, only a presence of psychic energy (print
// capture p. 271)
inline int dkhIkPsychicPresence()
    { return 1; }

// the concealment - cannot be seen or detected by detect invisibility or
// detect life (print capture p. 271)
inline int dkhIkHiddenFromDetection()
    { return 1; }

// the detect evil - reveals an aura of evil surrounding the victim (print
// capture p. 271)
inline int dkhIkRevealedByDetectEvil()
    { return 1; }

// the detect harmony - reveals something out of balance (print capture p.
// 271)
inline int dkhIkRevealedByDetectHarmony()
    { return 1; }

// the true sight - reveals the ikiryo in the form of its source person (print
// capture p. 271)
inline int dkhIkRevealedByTrueSight()
    { return 1; }

// the hedge - a protection from spirits or evil 10 foot radius hedges it out
// without harm (print capture p. 271)
inline int dkhIkHedgedByProtection()
    { return 1; }

// the blind - invisibility to spirits makes it impossible to find the victim
// (print capture p. 271)
inline int dkhIkBlindedByInvisibilityToSpirits()
    { return 1; }

// the dispel evil - drives it away for a 24-hour period (print capture p.
// 271)
inline int dkhIkDrivenOffByDispelEvil()
    { return 1; }

// the dispel evil respite - driven away for a 24-hour period (print capture
// p. 271)
inline int dkhIkDispelEvilHours()
    { return 24; }

// the summon spirit - causes it to take the form of its source person (print
// capture p. 271)
inline int dkhIkFormedBySummonSpirit()
    { return 1; }

// the exorcism - if successful, banishes it never to return (print capture p.
// 271)
inline int dkhIkBanishedByExorcism()
    { return 1; }

// the truth - confronting the source person makes it vanish forever (print
// capture p. 271)
inline int dkhIkVanishesOnConfrontation()
    { return 1; }

// ---- the ikiryo drain ----

// the pursuit - seeks out its victim, staying until destroyed (print capture
// p. 271)
inline int dkhIkStaysUntilDestroyed()
    { return 1; }

// the daily drain - one point from every ability score each 24-hour period
// (print capture p. 271)
inline int dkhIkDrainsEveryAbilityScore()
    { return 1; }

// the ability breadth - the point lost from every one of the six ability
// scores (print capture p. 271)
inline int dkhIkAbilityScoreCount()
    { return 6; }

// the drain rate - one point from every ability score per 24-hour period
// (print capture p. 271)
inline int dkhIkDrainPerDay()
    { return 1; }

// the symptoms - disturbed and restless, the air oppressive and stagnant,
// tired and exhausted (print capture p. 271)
inline int dkhIkDisturbedAndRestless()
    { return 1; }

// the death clause - if any ability score is reduced to 0, the victim dies
// (print capture p. 271)
inline int dkhIkDiesAtZeroAbility()
    { return 1; }

// the hold - lost ability points are not regained until the ikiryo is
// destroyed (print capture p. 271)
inline int dkhIkNoRecoveryUntilDestroyed()
    { return 1; }

// the recovery rate - one point per ability score per day after destruction
// (print capture p. 271)
inline int dkhIkRecoveryPerDay()
    { return 1; }

// the healing - after destruction, one point per ability score per day (print
// capture p. 271)
inline int dkhIkRecoversOnePerDay()
    { return 1; }

// ---- the ikiryo dm guidance ----

// the dm choice - the ikiryo attacks a player character or springs from one
// (print capture p. 271)
inline int dkhIkMayAttackOrSpring()
    { return 1; }

// the grudge source - may spring from an NPC secret resentment against a
// player character (print capture p. 271)
inline int dkhIkSpringsFromResentment()
    { return 1; }

// the limit - in no case can a character consciously summon an ikiryo (print
// capture p. 271)
inline int dkhIkNeverConsciouslySummoned()
    { return 1; }

// the compass - its actions are never done for the good of the character
// (print capture p. 271)
inline int dkhIkNeverForTheGood()
    { return 1; }

// ---- the jishin mushi stat block ----

// the frequency - the very rare of the stat block (print capture p. 271)
inline int dkhJmFrequencyVeryRare()
    { return 1; }

// the appearing minimum - the 1 of the 1-3 appearing (print capture p. 271)
inline int dkhJmAppearMin()
    { return 1; }

// the appearing maximum - the 3 of the 1-3 appearing (print capture p. 271)
inline int dkhJmAppearMax()
    { return 3; }

// the jishin mushi armor class - the AC 3 of the stat block (print capture p.
// 271)
inline int dkhJmAC()
    { return 3; }

// the walking rate - the 9 of the move 9/13 (print capture p. 272)
inline int dkhJmMoveWalk()
    { return 9; }

// the flying rate - the 13 of the move 9/13 (print capture p. 272)
inline int dkhJmMoveFly()
    { return 13; }

// the hit dice - the 5 of the 5+4 (print capture p. 272)
inline int dkhJmHD()
    { return 5; }

// the hit dice bonus - the +4 of the 5+4 (print capture p. 272)
inline int dkhJmHDPlus()
    { return 4; }

// the in-lair - the nil of the stat block (print capture p. 272)
inline int dkhJmLairNil()
    { return 1; }

// the treasure type - the nil of the stat block (print capture p. 272)
inline int dkhJmTreasureNil()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 272)
inline int dkhJmAttackCount()
    { return 1; }

// the damage minimum - the 2 of the 2-16 (print capture p. 272)
inline int dkhJmDmgMin()
    { return 2; }

// the damage maximum - the 16 of the 2-16 (print capture p. 272)
inline int dkhJmDmgMax()
    { return 16; }

// the special attack - the tremor of the stat block (print capture p. 272)
inline int dkhJmSpecialAttackTremor()
    { return 1; }

// the special defenses - the nil of the stat block (print capture p. 272)
inline int dkhJmSpecialDefensesNil()
    { return 1; }

// the magic resistance - the standard of the stat block (print capture p.
// 272)
inline int dkhJmMRStandard()
    { return 1; }

// the intelligence - the animal of the stat block (print capture p. 272)
inline int dkhJmIntelligenceAnimal()
    { return 1; }

// the alignment - the neutral of the stat block (print capture p. 272)
inline int dkhJmAlignmentNeutral()
    { return 1; }

// the size class - the L of the L 8-10 (print capture p. 272)
inline int dkhJmSizeLarge()
    { return 1; }

// the size minimum - the 8 of the L 8-10 (print capture p. 272)
inline int dkhJmSizeMinFeet()
    { return 8; }

// the size maximum - the 10 of the L 8-10 (print capture p. 272)
inline int dkhJmSizeMaxFeet()
    { return 10; }

// the psionic ability - the nil and the nil attack/defense modes (print
// capture p. 272)
inline int dkhJmPsionicNil()
    { return 1; }

// the level value - the V of the V/275 + 6/hp (print capture p. 272)
inline int dkhJmLevelV()
    { return 1; }

// the xp base - the 275 of the V/275 + 6 per hp (print capture p. 272)
inline int dkhJmXPBase()
    { return 275; }

// the xp per hit point - the 6 of the V/275 + 6/hp (print capture p. 272)
inline int dkhJmXPPerHP()
    { return 6; }

// ---- the earthquake beetle ----

// the name - the jishin mushi, or earthquake beetle (print capture p. 272)
inline int dkhJmEarthquakeBeetleName()
    { return 1; }

// the kind - a species of giant beetle (print capture p. 272)
inline int dkhJmGiantBeetleSpecies()
    { return 1; }

// the look - scintillating blue-green in color (print capture p. 272)
inline int dkhJmBlueGreenColor()
    { return 1; }

// the shell - a hard carapace which hides its small wings (print capture p.
// 272)
inline int dkhJmHardCarapaceSmallWings()
    { return 1; }

// the range - prowls the temperate forests (print capture p. 272)
inline int dkhJmTemperateForests()
    { return 1; }

// the diet - looking for meat which forms its main diet (print capture p.
// 272)
inline int dkhJmMeatDiet()
    { return 1; }

// the lure - particularly attracted to the scent of oxen (print capture p.
// 272)
inline int dkhJmOxenScentAttraction()
    { return 1; }

// the raid - sometimes attacks the oxen as they work in the farmer fields
// (print capture p. 272)
inline int dkhJmAttacksOxenInFields()
    { return 1; }

// the grab - attacks with its powerful mandibles, grasping victims and
// dragging them back to the trees (print capture p. 272)
inline int dkhJmMandiblesGraspAndDrag()
    { return 1; }

// the escape - a character can easily slip free of the poorly designed
// mandibles (print capture p. 272)
inline int dkhJmSlipFreeEasily()
    { return 1; }

// ---- the tremor rounds ----

// the buildup - weak at first but growing in intensity with repeated blows of
// the abdomen on the ground (print capture p. 272)
inline int dkhJmTremorGrowsWithBlows()
    { return 1; }

// the round one save - knocked to the ground unless the saving throw vs.
// breath weapon succeeds (print capture p. 272)
inline int dkhJmKnockdownSaveVsBreath()
    { return 1; }

// the round one radius - any creature within five feet saves vs. breath
// weapon or is knocked down (print capture p. 272)
inline int dkhJmTremorRoundOneRadius()
    { return 5; }

// the round two radius - extends to a 10-foot radius (print capture p. 272)
inline int dkhJmTremorRoundTwoRadius()
    { return 10; }

// the round three radius - the radius is 15 feet (print capture p. 272)
inline int dkhJmTremorRoundThreeRadius()
    { return 15; }

// the round three loss - thrown violently about for damage and lose the
// attack that round (print capture p. 272)
inline int dkhJmThrownViolentlyLoseAttack()
    { return 1; }

// the round three damage radius - those within five feet are thrown violently
// about (print capture p. 272)
inline int dkhJmTremorRoundThreeDamageRadius()
    { return 5; }

// the round three damage dice - the 1d6 points of damage (print capture p.
// 272)
inline int dkhJmTremorRoundThreeDmgDice()
    { return 1; }

// the round three damage sides - the 1d6 points of damage (print capture p.
// 272)
inline int dkhJmTremorRoundThreeDmgSides()
    { return 6; }

// the round four radius - the radius is 20 feet (print capture p. 272)
inline int dkhJmTremorRoundFourRadius()
    { return 20; }

// the round four damage radius - those within 10 feet take damage (print
// capture p. 272)
inline int dkhJmTremorRoundFourDamageRadius()
    { return 10; }

// the round five radius - extends to 25 feet (print capture p. 272)
inline int dkhJmTremorRoundFiveRadius()
    { return 25; }

// the round five damage radius - 15 feet respectively (print capture p. 272)
inline int dkhJmTremorRoundFiveDamageRadius()
    { return 15; }

// the round five cracks - cracks in the earth begin to appear (print capture
// p. 272)
inline int dkhJmCracksAppear()
    { return 1; }

// the round five cracks - cracks begin to appear within five feet (print
// capture p. 272)
inline int dkhJmTremorRoundFiveCrackRadius()
    { return 5; }

// the round six radius - the radii are 30 feet (print capture p. 272)
inline int dkhJmTremorRoundSixRadius()
    { return 30; }

// the round six damage radius - and 20 feet (print capture p. 272)
inline int dkhJmTremorRoundSixDamageRadius()
    { return 20; }

// the round six climax - the area suffers the effects of an earthquake spell
// (print capture p. 272)
inline int dkhJmEarthquakeAtRoundSix()
    { return 1; }

// the round six earthquake - the area within 10 feet suffers an earthquake
// spell (print capture p. 272)
inline int dkhJmTremorRoundSixEarthquakeRadius()
    { return 10; }

// the exit - takes to the air to avoid the consequences of its own deeds
// (print capture p. 272)
inline int dkhJmTakesToAir()
    { return 1; }

// ---- the ichor ----

// the market - the ichor is greatly prized by incense makers (print capture
// p. 272)
inline int dkhJmIchorPrizedByIncenseMakers()
    { return 1; }

// the ichor price - fetching as much as 2 tael for a flask (print capture p.
// 272)
inline int dkhJmIchorTaelPerFlask()
    { return 2; }

}   // namespace rules
