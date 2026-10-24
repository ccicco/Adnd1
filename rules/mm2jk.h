// =========================================================================================
// Adnd1 - rules/mm2jk.h
// THE MM2 LETTERS JK WALK - THE JANN, MUSTARD JELLY, KAMPFULT, KECH, KORRED
// AND KRAKEN TURNS (the jann and the mustard jelly p. 77, the kampfult, the
// kech and the korred p. 78, the kraken p. 79), promoted to the live
// registry; the JK-FLIP round, both the Letter J and the Letter K gap boxes
// flip to closed
// census 729 -> 730.
//
// Round twelve of the MM2 arc, the THIRD TWO-LETTER pass (the user Go call on
// the landed HI walk: the multiple letters standing call - the jann opens p.
// 77 and the kraken tail closes p. 79 - the JK-FLIP round, both the Letter J
// and the Letter K gap boxes flip to closed). The capture is the Curtiss PDF
// upload cross-checked against the archive.org djvu OCR, the contested cells
// settled book-internal first: the kech treasure "B" and the korred hit dice
// "6+1" read against the capture misreads; the kraken and-sum attack load
// clamps at the loader ceiling
//
// LOADER SEMANTICS (the R805 grim lesson): the composite numAttacks strings
// load as their max or their and-sum clamped at 10; the armor class
// composites read their first integer; every Nil lair reads 0 and every
// Standard magic resistance reads 0; the walk demands the loaded def equal
// the pin - walk patches may only touch real MonsterDef fields
//
namespace rules {

// ---- the MM2 letters JK walk round pins (the R807 census) ----

// The MM2 letters JK walk round: the jann, mustard jelly, kampfult, kech,
// korred and kraken turns, the THIRD TWO-LETTER pass (the user Go call on the
// landed HI walk)
inline int mm2jkRound()
    { return 807; }

// The registry census before the R807 promotion (the landed R806 count)
inline int mm2jkRegistryBefore()
    { return 655; }

// The registry census after the R807 promotion (6 defs)
inline int mm2jkRegistryAfter()
    { return 661; }

// The .lua defs riding the R807 walk (the jann, the mustard jelly, the
// kampfult, the kech, the korred and the kraken)
inline int mm2jkDefCount()
    { return 6; }

// The pin-time walk entry census (6 entries, all with stat blocks)
inline int mm2jkEntryCount()
    { return 6; }

// The stat-block headings walked at pin time from the print pp. 77-79
inline int mm2jkStatBlockHeadings()
    { return 6; }

// No doctrine-only family heads ride the letters JK walk (every entry carries
// a stat block)
inline int mm2jkDoctrineHeads()
    { return 0; }

// The letter-J entries (the jann and the mustard jelly, both p. 77)
inline int mm2jkLetterJHeadings()
    { return 2; }

// The letter-K entries (the kampfult, the kech, the korred p. 78 and the
// kraken p. 79)
inline int mm2jkLetterKHeadings()
    { return 4; }

// The JkStats grid row count (the six letters-JK stat blocks in print order)
inline int mm2jkJkStatRows()
    { return 6; }

// The gap report closed-box census after the JK-FLIP (14 + the letters J and
// K)
inline int mm2jkGapClosed()
    { return 16; }

// The gap report open-box census after the JK-FLIP (23 - 2)
inline int mm2jkGapOpen()
    { return 21; }

// No letters-JK index entries were pinned by earlier rounds (the dao prose
// mentions the jann but pins no jann def)
inline int mm2jkPriorOwnedEntries()
    { return 0; }

// The genie-kind census the jann opens (the dao, djinni, efreeti, jann and
// marid - the jannee the weakest)
inline int mm2jkGenieKinCount()
    { return 5; }

// The jannee are the weakest of the elemental humanoids (a jann is formed out
// of all 4 of the elements)
inline bool mm2jkJannWeakestOfTheGenies()
    { return true; }

// Jannee will accept djinn but shun daos, efreet and marids
inline bool mm2jkJannAcceptDjinnShunDaoEfreetMarid()
    { return true; }

// In addition to the common tongue and the languages of geniekind, jannee are
// able to speak with animals
inline bool mm2jkJannSpeakWithAnimals()
    { return true; }

// The mustard jelly is a strain of, or perhaps a relative of, the ochre jelly
inline bool mm2jkMustardJellyRelativeOfOchreJelly()
    { return true; }

// The mustard jelly cannot move along ceilings as an ochre jelly can
inline bool mm2jkMustardJellyCannotClimbCeilings()
    { return true; }

// Electrical attacks and magic missiles cause the mustard jelly to grow (it
// gains hit points equal to the damage rolled)
inline bool mm2jkMustardJellyGrowsOnElectricityAndMagicMissiles()
    { return true; }

// Half the xp is awarded if half the creature is slain
inline bool mm2jkMustardJellyHalfXpWhenHalfSlain()
    { return true; }

// Only the central section of the kampfult can be harmed
inline bool mm2jkKampfultOnlyCentralSectionHarmed()
    { return true; }

// Once hit by an appendage the victim cannot escape until the kampfult is
// slain
inline bool mm2jkKampfultVictimHeldUntilSlain()
    { return true; }

// Keches imitate calls of distress to lure prey into trapped areas and ambush
inline bool mm2jkKechImitateDistressCalls()
    { return true; }

// The kech camouflage coloration and woodcraft skills make tracks 50%
// unfollowable
inline bool mm2jkKechCamouflageColoration()
    { return true; }

// The kech treasure type reads the letter B (the capture "8" the OCR misread;
// the djvu, the 1eonline compilation and the 2e compendium the agreeing
// voices)
inline bool mm2jkKechTreasureReadsLetterB()
    { return true; }

// The korred hit dice read 6+1 (the capture "8+1" the OCR misread; the same
// three voices agree)
inline bool mm2jkKorredHdReadsSixPlusOne()
    { return true; }

// Korreds are rumored to have built the druid stone circles
inline bool mm2jkKorredBuiltStoneCirclesRumor()
    { return true; }

// The items in a korred's pouch turn to gold if sprinkled with holy water
inline bool mm2jkKorredPouchGoldOnHolyWater()
    { return true; }

// Each week the korreds have a holiday when they dance and play music
inline bool mm2jkKorredWeeklyHolidayDance()
    { return true; }

// The kraken are air-and water-breathing squid-like creatures
inline bool mm2jkKrakenAirAndWaterBreathing()
    { return true; }

// Kraken are aggressive hunters that battle even large sperm whales and
// usually win
inline bool mm2jkKrakenBattlesSpermWhales()
    { return true; }

// It is rumored that some kraken keep and breed human slaves in undersea
// dungeon complexes
inline bool mm2jkKrakenBreedHumanSlavesRumor()
    { return true; }

// The kraken move cell "//3" (21")" pins capture verbatim (the R804 electric
// eel "//9"" precedent; the moveRate reads the swimming 3)
inline bool mm2jkKrakenMovePrintsDoubleSlashVerbatim()
    { return true; }

// ---- the jann pins (the R807 MM2 letters JK walk) ----

// The jann full kill xp (975 + 23 avg hp x 8 per hp)
inline int mm2jkJannXpValue()
    { return 1159; }

// The jann xp level (the print VI)
inline int mm2jkJannXpLevel()
    { return 6; }

// The percent of jannee wearing chainmail
inline int mm2jkJannChainmailPct()
    { return 60; }

// The effective armor class of the jannee chainmail
inline int mm2jkJannChainmailAc()
    { return 2; }

// The female jannee strength floor (01-50 on the table)
inline int mm2jkJannFemaleStrengthMin()
    { return 17; }

// The jann ground move rate (the composite 12/30 reads the ground 12)
inline int mm2jkJannMoveRate()
    { return 12; }

// The jann fly rate (the composite 12/30 tail)
inline int mm2jkJannFlyRate()
    { return 30; }

// The jannee spell-use level (they perform at 12th level ability)
inline int mm2jkJannSpellCasterLevel()
    { return 12; }

// The hours a jann can dwell in any elemental environment
inline int mm2jkJannElementalDwellHours()
    { return 48; }

// The individuals a jann can take along to an elemental plane (the
// hand-holding circle)
inline int mm2jkJannPlaneTravelCompanions()
    { return 6; }

// The damage per hour inflicted on a jann failing to return to the Prime
// Material Plane
inline int mm2jkJannPrimeDamagePerHour()
    { return 1; }

// The Prime Material days of rest before damage-free elemental travel
inline int mm2jkJannTravelPrimeRestDays()
    { return 2; }

// The growth/reduction uses per day (twice each per day)
inline int mm2jkJannGrowthReductionPerDay()
    { return 2; }

// The invisibility uses per day
inline int mm2jkJannInvisibilityPerDay()
    { return 3; }

// The etherealness uses per day
inline int mm2jkJannEtherealnessPerDay()
    { return 1; }

// The maximum etherealness duration in hours
inline int mm2jkJannEtherealnessHours()
    { return 1; }

// The create food and water caster level (as a 7th-level cleric)
inline int mm2jkJannCreateFoodWaterLevel()
    { return 7; }

// The tribe size floor (a group of 11-30 individuals)
inline int mm2jkJannTribeSizeMin()
    { return 11; }

// The tribe size ceiling
inline int mm2jkJannTribeSizeMax()
    { return 30; }

// The viziers a tribe may count (a sheik and 1-2 viziers)
inline int mm2jkJannVizierCount()
    { return 2; }

// The sheik hit-point maximum (the higher hit dice note)
inline int mm2jkJannSheikHpMax()
    { return 84; }

// The amir hit-point maximum
inline int mm2jkJannAmirHpMax()
    { return 95; }

// The greater leader strength (possible 10% of the time)
inline int mm2jkJannLeaderStrength()
    { return 19; }

// The vizier spell-like powers per day each (augury, detect magic and
// divination)
inline int mm2jkJannVizierPowersPerDay()
    { return 3; }

// ---- the mustard jelly pins (the R807 MM2 letters JK walk) ----

// The mustard jelly full kill xp (825 + 38 avg hp x 18 per hp - half awarded
// if half the creature slain)
inline int mm2jkMustardJellyXpValue()
    { return 1509; }

// The mustard jelly xp level (the print VI)
inline int mm2jkMustardJellyXpLevel()
    { return 6; }

// The lethargy vapor radius in feet
inline int mm2jkMustardJellyVaporRadiusFeet()
    { return 10; }

// The toxic effect duration in rounds (cumulative)
inline int mm2jkMustardJellyToxicRounds()
    { return 2; }

// The halves the whole divides into
inline int mm2jkMustardJellyHalvesCount()
    { return 2; }

// The divided-half move floor (move 12-18)
inline int mm2jkMustardJellyDivideMoveMin()
    { return 12; }

// The divided-half move ceiling
inline int mm2jkMustardJellyDivideMoveMax()
    { return 18; }

// The or-form attack load ("1 or 2" reads the max 2 - the R798 duergar
// convention)
inline int mm2jkMustardJellyAttacksMax()
    { return 2; }

// The weapon bonus needed to score effective damage
inline int mm2jkMustardJellyWeaponPlusMin()
    { return 1; }

// The size diameter floor (9-12 feet)
inline int mm2jkMustardJellyDiameterMinFeet()
    { return 9; }

// The size diameter ceiling
inline int mm2jkMustardJellyDiameterMaxFeet()
    { return 12; }

// ---- the kampfult pins (the R807 MM2 letters JK walk) ----

// The kampfult full kill xp (36 + 7 avg hp x 2 per hp)
inline int mm2jkKampfultXpValue()
    { return 50; }

// The kampfult xp level (the print II - the djvu "11" the OCR misread)
inline int mm2jkKampfultXpLevel()
    { return 2; }

// The attack appendages
inline int mm2jkKampfultAttackAppendages()
    { return 6; }

// The movement appendages
inline int mm2jkKampfultMoveAppendages()
    { return 6; }

// The attack appendage length in feet
inline int mm2jkKampfultAppendageLengthFeet()
    { return 6; }

// The movement appendage length in feet
inline int mm2jkKampfultMoveAppendageLengthFeet()
    { return 1; }

// The central trunk length in feet (the only section that can be harmed)
inline int mm2jkKampfultTrunkLengthFeet()
    { return 4; }

// The surprise roll floor (surprise on 1-3)
inline int mm2jkKampfultSurpriseMin()
    { return 1; }

// The surprise roll ceiling
inline int mm2jkKampfultSurpriseMax()
    { return 3; }

// The damage per appendage strike
inline int mm2jkKampfultDamagePerAppendage()
    { return 1; }

// ---- the kech pins (the R807 MM2 letters JK walk) ----

// The kech full kill xp (205 + 17 avg hp x 5 per hp)
inline int mm2jkKechXpValue()
    { return 290; }

// The kech xp level (the print IV)
inline int mm2jkKechXpLevel()
    { return 4; }

// The surprise likelihood (5 in 6)
inline int mm2jkKechSurpriseInSix()
    { return 5; }

// The percent the camouflage tracks cannot be followed
inline int mm2jkKechTracksUnfollowablePct()
    { return 50; }

// The silence move chance
inline int mm2jkKechSilencePct()
    { return 50; }

// The tree-climbing rate in feet per round
inline int mm2jkKechClimbFeetPerRound()
    { return 60; }

// The appearing floor (2-8)
inline int mm2jkKechNoAppearingMin()
    { return 2; }

// The appearing ceiling
inline int mm2jkKechNoAppearingMax()
    { return 8; }

// ---- the korred pins (the R807 MM2 letters JK walk) ----

// The korred full kill xp (900 + 22 avg hp x 8 per hp)
inline int mm2jkKorredXpValue()
    { return 1076; }

// The korred xp level (the print VI)
inline int mm2jkKorredXpLevel()
    { return 6; }

// The hair-snare weaving floor (1-4 rounds)
inline int mm2jkKorredHairSnareRoundsMin()
    { return 1; }

// The hair-snare weaving ceiling
inline int mm2jkKorredHairSnareRoundsMax()
    { return 4; }

// The animated rope armor class
inline int mm2jkKorredRopeArmorClass()
    { return 1; }

// The animated rope hit points
inline int mm2jkKorredRopeHp()
    { return 5; }

// The boulder hurling range in inches
inline int mm2jkKorredBoulderRangeInches()
    { return 10; }

// The boulder damage dice (2d8)
inline int mm2jkKorredBoulderDamageDice()
    { return 2; }

// The boulder damage sides
inline int mm2jkKorredBoulderDamageSides()
    { return 8; }

// The shears damage floor (d4+4)
inline int mm2jkKorredShearDamageMin()
    { return 5; }

// The shears damage ceiling
inline int mm2jkKorredShearDamageMax()
    { return 8; }

// The cudgel damage floor (d6+4)
inline int mm2jkKorredCudgelDamageMin()
    { return 5; }

// The cudgel damage ceiling
inline int mm2jkKorredCudgelDamageMax()
    { return 10; }

// The unarmed damage floor (1-2+4)
inline int mm2jkKorredUnarmedDamageMin()
    { return 5; }

// The unarmed damage ceiling
inline int mm2jkKorredUnarmedDamageMax()
    { return 6; }

// The laughs per day
inline int mm2jkKorredLaughsPerDay()
    { return 3; }

// The laugh radius in inches
inline int mm2jkKorredLaughRadiusInches()
    { return 6; }

// The laugh stun floor (1-4 rounds)
inline int mm2jkKorredLaughStunRoundsMin()
    { return 1; }

// The laugh stun ceiling
inline int mm2jkKorredLaughStunRoundsMax()
    { return 4; }

// The pouch gold floor (50-200 gp on holy water)
inline int mm2jkKorredPouchGoldMin()
    { return 50; }

// The pouch gold ceiling
inline int mm2jkKorredPouchGoldMax()
    { return 200; }

// The interrupting-dancer damage floor (1-4 per round)
inline int mm2jkKorredDanceDamageMin()
    { return 1; }

// The interrupting-dancer damage ceiling
inline int mm2jkKorredDanceDamageMax()
    { return 4; }

// The at-will stone powers (stone shape, animate rock, stone door, shatter
// rock, transmute rock to mud and stone tell)
inline int mm2jkKorredStonePowersCount()
    { return 6; }

// ---- the kraken pins (the R807 MM2 letters JK walk) ----

// The kraken full kill xp (16,900 + 70 avg hp x 30 per hp)
inline int mm2jkKrakenXpValue()
    { return 19000; }

// The kraken xp level (the print X)
inline int mm2jkKrakenXpLevel()
    { return 10; }

// The tentacle armor class (as the exposed head)
inline int mm2jkKrakenTentacleAc()
    { return 6; }

// The exposed head armor class
inline int mm2jkKrakenHeadAc()
    { return 6; }

// The shell body armor class
inline int mm2jkKrakenBodyAc()
    { return 0; }

// The total tentacles
inline int mm2jkKrakenTentaclesTotal()
    { return 10; }

// The tentacles used to anchor or stabilize
inline int mm2jkKrakenTentaclesAnchoring()
    { return 2; }

// The backward jetting rate (the composite move tail)
inline int mm2jkKrakenJetRate()
    { return 21; }

// The swimming rate (the composite move head)
inline int mm2jkKrakenSwimRate()
    { return 3; }

// The constriction damage floor (3-12 on the 2nd and each subsequent round)
inline int mm2jkKrakenConstrictDamageMin()
    { return 3; }

// The constriction damage ceiling
inline int mm2jkKrakenConstrictDamageMax()
    { return 12; }

// The sharp-weapon damage to sever a tentacle
inline int mm2jkKrakenTentacleSeverDamage()
    { return 16; }

// The sepia ink cloud width in inches
inline int mm2jkKrakenInkWidthInches()
    { return 8; }

// The sepia ink cloud height in inches
inline int mm2jkKrakenInkHeightInches()
    { return 8; }

// The sepia ink cloud length in inches
inline int mm2jkKrakenInkLengthInches()
    { return 12; }

// The ink poison floor (2-5 rounds until diluted)
inline int mm2jkKrakenInkPoisonRoundsMin()
    { return 2; }

// The ink poison ceiling
inline int mm2jkKrakenInkPoisonRoundsMax()
    { return 5; }

// The ink cloud damage floor (1-4 per round of exposure)
inline int mm2jkKrakenInkDamageMin()
    { return 1; }

// The ink cloud damage ceiling
inline int mm2jkKrakenInkDamageMax()
    { return 4; }

// The vessel length a kraken can drag beneath the water
inline int mm2jkKrakenDraggableShipFeet()
    { return 60; }

// The percent larger than the largest giant squid
inline int mm2jkKrakenLargerThanSquidPct()
    { return 10; }

// The rounds a larger ship is dragged to a halt in
inline int mm2jkKrakenDragHaltRounds()
    { return 10; }

// The constricting tentacles that ram a vessel (6 or more)
inline int mm2jkKrakenGraspTentacles()
    { return 6; }

// The consecutive grasp rounds (3)
inline int mm2jkKrakenGraspRounds()
    { return 3; }

// The lost-bouyancy sinking floor (2-8 rounds)
inline int mm2jkKrakenSinkRoundsMin()
    { return 2; }

// The lost-bouyancy sinking ceiling
inline int mm2jkKrakenSinkRoundsMax()
    { return 8; }

// The severed tentacles that trigger the immediate retreat
inline int mm2jkKrakenRetreatSeveredTentacles()
    { return 3; }

// The airy water uses per day
inline int mm2jkKrakenAiryWaterPerDay()
    { return 6; }

// The airy water sphere diameter in feet
inline int mm2jkKrakenAiryWaterSphereFeet()
    { return 128; }

// The airy water hemisphere diameter in feet (6 times as large as usual)
inline int mm2jkKrakenAiryWaterHemisphereFeet()
    { return 240; }

// The faerie fire duration in hours
inline int mm2jkKrakenFaerieFireHours()
    { return 8; }

// The control temperature radius in feet
inline int mm2jkKrakenTemperatureRadiusFeet()
    { return 40; }

// The percent a lair holds type A treasure as well as that indicated
inline int mm2jkKrakenLairExtraTreasurePct()
    { return 50; }

// The "2 and 4-6 and 1" attack load (the and-sum 13 clamped at the 10 sanity
// ceiling - the R805 purple worm convention meets the clamp)
inline int mm2jkKrakenAttacksLoadedMax()
    { return 10; }

// ---- the MM2 letters JK walk stat grid (the R807 wiring) ----

// The armor class cells (the jann "5 (plus possible armor)" composite reads
// 5; the kraken "5/0" reads the head 5)
inline int mm2jkJkStatAC(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 5;
        default:
            return 0;
        }
    }

// The hit dice num cells (the korred settled 6+1 - the capture "8+1" the OCR
// misread; the kraken flat 20)
inline int mm2jkJkStatHd(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the jann 6+2, the mustard jelly 7+14, the korred
// 6+1)
inline int mm2jkJkStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 14;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x HD + bonus) formula - the jann 23, the
// mustard jelly 38, the kampfult 7, the kech 17, the korred 22, the kraken
// 70)
inline int mm2jkJkStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 38;
        case 2:
            return 7;
        case 3:
            return 17;
        case 4:
            return 22;
        case 5:
            return 70;
        default:
            return 0;
        }
    }

// The attack load cells (the mustard jelly "1 or 2" max 2; the korred "1 or
// by weapon" the 1 floor; the kraken "2 and 4-6 and 1" the and-sum 13 clamped
// at the 10 sanity ceiling)
inline int mm2jkJkStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 6;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 10;
        default:
            return 0;
        }
    }

// The xp base cells (the jann 975, the mustard jelly 825, the kampfult 36,
// the kech 205, the korred 900, the kraken 16,900)
inline int mm2jkJkStatXp(int b)
    {
        switch (b) {
        case 0:
            return 975;
        case 1:
            return 825;
        case 2:
            return 36;
        case 3:
            return 205;
        case 4:
            return 900;
        case 5:
            return 16900;
        default:
            return 0;
        }
    }

// The xp-per-hit-point cells (the jann 8, the mustard jelly 18, the kampfult
// 2, the kech 5, the korred 8, the kraken 30)
inline int mm2jkJkStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 18;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 8;
        case 5:
            return 30;
        default:
            return 0;
        }
    }

// The lair percent cells (the jann Nil 0, the mustard jelly 35, the kampfult
// 35, the kech 30, the korred 1, the kraken 75)
inline int mm2jkJkStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 35;
        case 2:
            return 35;
        case 3:
            return 30;
        case 4:
            return 1;
        case 5:
            return 75;
        default:
            return 0;
        }
    }

// The move cells (the jann 12/30 composite head 12; the kraken "//3" (21")"
// head 3 - the R804 electric eel precedent)
inline int mm2jkJkStatMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 9;
        case 2:
            return 3;
        case 3:
            return 15;
        case 4:
            return 9;
        case 5:
            return 3;
        default:
            return 0;
        }
    }

// The magic resistance cells (the jann 20%, the mustard jelly 10%, the korred
// 25%; every Standard reads 0)
inline int mm2jkJkStatMr(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 25;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
