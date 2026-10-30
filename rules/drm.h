// =========================================================================================
// Adnd1 - rules/drm.h
// The Dragon issue-15 opener - Dragon Magic (folio 3, cont. 13), the
// wandering monster list (folio 7), the wilderness weather system (folios
// 14-15), the pit tables (folio 5) and the settlements random events (folio
// 5): the five-chain round
// census 849 -> 850.
//
// Pinned from The Dragon Vol. III No. 1 (June 1978), the Curtiss-provided
// scan voice (single-voice: the issue-15 source is the uploaded Dm15.pdf with
// its mistral-ocr transcript; no archive.org djvu cross-check exists for
// issue 15, the accessory items end at issue 14). PRINT FOLIO = PDF PAGE
// MINUS TWO in this issue, verified at the page feet (folios 5, 7, 9, 11, 13
// and 14 print at the PDF pages 7, 9, 11, 13, 15 and 16) plus the TOC
// alignments (Dragon Magic at print 3 = PDF 5, the Green Magician at print 23
// = PDF 25, the Boot Hill events at print 32 = PDF 34); the TOC prints two
// swapped folios - Monty Haul listed at 7 sits at print 6, the Wandering
// Monster listed at 6 sits at print 7. The transcripts ride
// extract/dragon/015/p001 through p036, landed this round; the article CHAIN
// is the ink unit, not the folio.
//
// Print quirks pinned AS SCANNED, noted never silent: no full-res visual
// check exists for this issue (the scan is a text-side transcript, no page
// renders), so garbled cells pin sentinel, never guessed - the occupied-pit
// animal band prints 01-35 spikes then 35-65 animal with the 35 shared
// between bands, the animal lower bound pins sentinel; the pit specialist
// ranger band prints 91-85, the upper bound pins sentinel; the seasonal
// unusual cells print non-contiguous faces (winter 1,2,4-9; spring
// 2,3,5,6,8,9; summer 2,3,5,6,9,10) and pin sentinel with the faces riding
// the transcript; the disease immunity column prints the percent sign before
// the digits (%5 = 5 percent, the percent-position class, the digits clean
// and pinned); the wandering-list will o wisp armor class minus 8 is genuine
// print; the as-men movement entries pin sentinel rather than a guessed
// number; the wandering-list damage lines ride the transcript, the table
// pinning the uniform columns.
//
namespace rules {

// ---- the dragon spell system (folio 3, cont. 13) ----

// the dragon spell list - eleven first-level spells (folio 3, PDF 5)
inline int drmSpellsLevel1()
    { return 11; }

// the dragon spell list - twelve second-level spells (folio 3, PDF 5)
inline int drmSpellsLevel2()
    { return 12; }

// the dragon spell list - thirteen third-level spells (folio 3, PDF 5)
inline int drmSpellsLevel3()
    { return 13; }

// the dragon spell list - thirteen fourth-level spells (folio 3, PDF 6)
inline int drmSpellsLevel4()
    { return 13; }

// the dragon spell list - ten fifth-level spells (folio 3, PDF 6)
inline int drmSpellsLevel5()
    { return 10; }

// the count across the five dragon spell lists, computed from the pinned
// level counts
inline int drmSpellsTotal()
    { return 59; }

// speaking a dragon secret name grants one, and only one, demanded service
// (folio 3)
inline int drmNameServiceDemands()
    { return 1; }

// the polymorph self entrapment - a 2 percent chance per day or fraction,
// cumulative (folio 3)
inline int drmPolySelfTrapPercent()
    { return 2; }

// the polymorph others entrapment on a dragon - 5 percent per day or
// fraction, cumulative (folio 3)
inline int drmPolyOtherTrapPercent()
    { return 5; }

// the Seek spell finds direction within plus or minus 20 degrees (folio 3)
inline int drmSeekDirectionErrorDegrees()
    { return 20; }

// the Seek spell finds distance within 20 percent (folio 3)
inline int drmSeekDistanceErrorPercent()
    { return 20; }

// the Magic Pointer has a 30 percent chance of pointing out an opponent one
// level or hit die lower (folio 3)
inline int drmPointerAdjacentLevelPercent()
    { return 30; }

// the Magic Pointer has a 10 percent chance of indicating a random adversary
// (folio 3)
inline int drmPointerRandomPercent()
    { return 10; }

// a dragon has a 10 percent chance per age level of possessing a summoning
// stone (folio 3)
inline int drmSummonStoneChancePerAge()
    { return 10; }

// the servant summoning - from 4 creatures appear (folio 3)
inline int drmServantsMin()
    { return 4; }

// the servant summoning - up to 16 creatures appear (folio 3)
inline int drmServantsMax()
    { return 16; }

// the summoned servants stay from 2 melee rounds (folio 3)
inline int drmServantRoundsMin()
    { return 2; }

// the summoned servants stay up to 12 melee rounds (folio 3)
inline int drmServantRoundsMax()
    { return 12; }

// the summoning-stone birds - armor class 5 (folio 3)
inline int drmServantArmorClass()
    { return 5; }

// the summoning-stone birds move 4 inches on the ground (folio 3)
inline int drmServantMoveGroundInches()
    { return 4; }

// the summoning-stone birds move 48 inches aloft (folio 3)
inline int drmServantMoveFlyInches()
    { return 48; }

// the summoning-stone birds carry from 2 hit points each (folio 3)
inline int drmServantHpMin()
    { return 2; }

// the summoning-stone birds carry up to 12 hit points each (folio 3)
inline int drmServantHpMax()
    { return 12; }

// the summoning-stone birds talon - from 1 point (folio 3)
inline int drmServantTalonDamageMin()
    { return 1; }

// the summoning-stone birds talon - up to 2 points, two talons (folio 3)
inline int drmServantTalonDamageMax()
    { return 2; }

// the summoning-stone birds beak - from 1 point (folio 3)
inline int drmServantBeakDamageMin()
    { return 1; }

// the summoning-stone birds beak - up to 6 points (folio 3)
inline int drmServantBeakDamageMax()
    { return 6; }

// the Heat Metal spell affects a maximum of 1500 gold pieces in weight (folio
// 3)
inline int drmHeatMetalMaxGold()
    { return 1500; }

// the Water to Wine spell converts 20 gallons per age class (folio 3)
inline int drmWaterToWineGallonsPerAge()
    { return 20; }

// the Wood to Sand spell changes 1 cubic foot of wood per age class (folio 3)
inline int drmWoodToSandCuFtPerAge()
    { return 1; }

// the Rock to Sand spell changes 1 cubic foot of stone per age level (folio
// 3)
inline int drmRockToSandCuFtPerAge()
    { return 1; }

// the Call Lightning bolt is 10 dice (folio 3)
inline int drmCallLightningDice()
    { return 10; }

// the Call Lightning bolt dice are 8-sided (folio 3)
inline int drmCallLightningDieSides()
    { return 8; }

// the Call Lightning frequency - one bolt per 10 minutes (folio 3)
inline int drmCallLightningMinutesPerBolt()
    { return 10; }

// the Alarm rune lasts 1 week (folio 3)
inline int drmAlarmDurationWeeks()
    { return 1; }

// the Alarm telepathic link reaches 24 inches (folio 3)
inline int drmAlarmTelepathicInches()
    { return 24; }

// the Hold Mammal spell holds from 1 to 4 mammals (folio 3)
inline int drmHoldMammalMax()
    { return 4; }

// the Hold Mammal range - 12 inches (folio 3)
inline int drmHoldMammalRangeInches()
    { return 12; }

// the Hold Mammal duration - 6 turns (folio 3)
inline int drmHoldMammalDurationTurns()
    { return 6; }

// the Binding Spell freezes metal from 1 turn (folio 3)
inline int drmBindingDurationMinTurns()
    { return 1; }

// the Binding Spell freezes metal up to 4 turns (folio 3)
inline int drmBindingDurationMaxTurns()
    { return 4; }

// the Binding Spell grants magical items two saving throws (folio 3)
inline int drmBindingMagicSaves()
    { return 2; }

// the Control Winds spell changes wind speed by plus or minus 15 mph (folio
// 3)
inline int drmControlWindsSpeedMph()
    { return 15; }

// the Control Winds spell changes direction by 45 degrees (folio 3)
inline int drmControlWindsDirectionDegrees()
    { return 45; }

// the Control Winds duration - 6 turns (folio 3)
inline int drmControlWindsDurationTurns()
    { return 6; }

// the Control Winds range - a 24-inch radius (folio 3)
inline int drmControlWindsRadiusInches()
    { return 24; }

// the Negate Enchantment I spell negates one item per day (folio 3)
inline int drmNegateItemsPerDay()
    { return 1; }

// the Negate Enchantment I lasts from 2 melee rounds (folio 3)
inline int drmNegateDurationMinRounds()
    { return 2; }

// the Negate Enchantment I lasts up to 12 melee rounds (folio 3)
inline int drmNegateDurationMaxRounds()
    { return 12; }

// the Negate Enchantment I range - 6 inches (folio 3)
inline int drmNegateRangeInches()
    { return 6; }

// the Charm Avians spell commands from 2 small birds (folio 3)
inline int drmCharmAviansSmallMin()
    { return 2; }

// the Charm Avians spell commands up to 8 small birds (folio 3)
inline int drmCharmAviansSmallMax()
    { return 8; }

// the Charm Avians spell commands from 1 medium bird (folio 3)
inline int drmCharmAviansMediumMin()
    { return 1; }

// the Charm Avians spell commands up to 3 medium birds (folio 3)
inline int drmCharmAviansMediumMax()
    { return 3; }

// the Charm Avians spell commands 1 man-sized bird (folio 3)
inline int drmCharmAviansManSized()
    { return 1; }

// the Charm Avians range - 12 inches (folio 3)
inline int drmCharmAviansRangeInches()
    { return 12; }

// the Charm Avians duration - 1 day (folio 3)
inline int drmCharmAviansDurationDays()
    { return 1; }

// the See Invisible spell - a 6-inch radius (folio 3)
inline int drmSeeInvisibleRadiusInches()
    { return 6; }

// the See Other Planes duration - 3 turns (folio 3)
inline int drmSeeOtherPlanesDurationTurns()
    { return 3; }

// passing the Wall of Gloom reduces morale by 2 (folio 3)
inline int drmGloomMoralePenalty()
    { return 2; }

// the Wall of Gloom and the Wall of Wind both last from 3 turns (folio 3)
inline int drmWallDurationMinTurns()
    { return 3; }

// the Wall of Gloom and the Wall of Wind both last up to 8 turns (folio 3)
inline int drmWallDurationMaxTurns()
    { return 8; }

// the Weight Control range - 12 inches (folio 3)
inline int drmWeightControlRangeInches()
    { return 12; }

// the Werelight spreads from creature to creature within 3 inches (folio 3)
inline int drmWerelightSpreadInches()
    { return 3; }

// the Werelight may be created within 12 inches of the caster (folio 3)
inline int drmWerelightRangeInches()
    { return 12; }

// the Werelight lasts from 3 melee rounds (folio 3)
inline int drmWerelightDurationMinRounds()
    { return 3; }

// the Werelight lasts up to 18 melee rounds, or 1 full turn (folio 3)
inline int drmWerelightDurationMaxRounds()
    { return 18; }

// the Animate Dead spell animates from 2 hit dice of creatures (folio 13, PDF
// 15)
inline int drmAnimateDeadHdMin()
    { return 2; }

// the Animate Dead spell animates up to 16 hit dice of creatures (folio 13)
inline int drmAnimateDeadHdMax()
    { return 16; }

// the Animate Dead skeletons - up to 8 hit dice of skeletons (folio 13)
inline int drmAnimateDeadSkeletonHdMax()
    { return 8; }

// the Animate Dead range - 6 inches (folio 13)
inline int drmAnimateDeadRangeInches()
    { return 6; }

// the Conjure Elemental strength - 16 dice (folio 13)
inline int drmConjureElementalDice()
    { return 16; }

// a dragon curse may be lifted for 8 hours via a bless spell (folio 13)
inline int drmCurseBlessLiftHours()
    { return 8; }

// two Full Wishes will dispel a dragon curse (folio 13)
inline int drmCurseFullWishesToDispel()
    { return 2; }

// the Evaluate Item worked example - the chimes of opening value 30000 gold
// (folio 3)
inline int drmEvaluateExampleGold()
    { return 30000; }

// if a dragon name is spoken, all works of that dragon magic are dispelled
// (folio 3)
inline bool drmSecretNameDispelsAllWorks()
    { return true; }

// only EVIL dragons use the Servant Summoning spell except in the greatest
// peril (folio 3)
inline bool drmServantEvilOnly()
    { return true; }

// the summoning-stone birds are driven off by strong light (folio 3)
inline bool drmServantDrivenOffByStrongLight()
    { return true; }

// the summoning-stone birds will not cross water under any circumstances
// (folio 3)
inline bool drmServantsNeverCrossWater()
    { return true; }

// Silver, Gold and the Platinum Dragon are not subject to the polymorph
// entrapment (folio 3)
inline bool drmMetallicDragonsPolyImmune()
    { return true; }

// dragons will never use the Charm Monster spell upon each other (folio 3)
inline bool drmDragonsNeverCharmDragons()
    { return true; }

// an air elemental will not turn on the dragon if control is lost (folio 13)
inline bool drmAirElementalNeverTurnsOnDragon()
    { return true; }

// the Phantasmal Forces spell is usable in lieu of any first-level spell
// (folio 3)
inline bool drmPhantasmalForcesAnyFirstLevelSlot()
    { return true; }

// a dragon curse will always come true, the time unspecified (folio 3)
inline bool drmCurseAlwaysComesTrue()
    { return true; }

// no saving throw is allowed the victim of a dragon curse (folio 3)
inline bool drmCurseNoSavingThrow()
    { return true; }

// the animated monsters have half the hit dice of the original creature
// (folio 13)
inline bool drmAnimateDeadHalfDice()
    { return true; }

// the animated monsters attack for half damage (folio 13)
inline bool drmAnimateDeadHalfDamage()
    { return true; }

// ---- the wandering monster list (folio 7) ----

// the fourth-level wandering monster list - twenty entries (folio 7, PDF 9)
inline int drmWanderingRows()
    { return 20; }

// the appearing bands - the counts as printed, sentinel where the entry
// prints no band (folio 7)
inline int drmWAppearMin(int b)
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
            return -1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 4;
        case 16:
            return -1;
        case 17:
            return 3;
        case 18:
            return -1;
        case 19:
            return -1;
        default:
            return -1;
        }
    }

// the appearing bands upper bounds - sentinel where not printed (folio 7)
inline int drmWAppearMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return -1;
        case 12:
            return 6;
        case 13:
            return 4;
        case 14:
            return 6;
        case 15:
            return 16;
        case 16:
            return -1;
        case 17:
            return 12;
        case 18:
            return -1;
        case 19:
            return -1;
        default:
            return -1;
        }
    }

// the hit points - per the printed list; the curate row pins the curate 20
// with the men-at-arms 5 each riding the transcript, the lycanthrope row
// sentinel with the four kinds riding the transcript (folio 7)
inline int drmWHitPoints(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 9;
        case 2:
            return 12;
        case 3:
            return 22;
        case 4:
            return 20;
        case 5:
            return 23;
        case 6:
            return 10;
        case 7:
            return 17;
        case 8:
            return 9;
        case 9:
            return 15;
        case 10:
            return 20;
        case 11:
            return -1;
        case 12:
            return 22;
        case 13:
            return 15;
        case 14:
            return 22;
        case 15:
            return 13;
        case 16:
            return 24;
        case 17:
            return 8;
        case 18:
            return 33;
        case 19:
            return 19;
        default:
            return -1;
        }
    }

// the armor classes - the will o wisp minus 8 is genuine print; sentinel
// where the entry prints no armor class (folio 7)
inline int drmWArmorClass(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return 7;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 4;
        case 15:
            return 5;
        case 16:
            return 5;
        case 17:
            return 4;
        case 18:
            return -8;
        case 19:
            return 2;
        default:
            return -1;
        }
    }

// the dungeon move in feet per turn - the gargoyle air move 150 rides the
// transcript; sentinel for the as-men entries, never guessed (folio 7)
inline int drmWMoveFeet(int b)
    {
        switch (b) {
        case 0:
            return 90;
        case 1:
            return 120;
        case 2:
            return 90;
        case 3:
            return 90;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return 90;
        case 9:
            return 60;
        case 10:
            return 90;
        case 11:
            return -1;
        case 12:
            return 90;
        case 13:
            return 120;
        case 14:
            return 150;
        case 15:
            return 120;
        case 16:
            return 150;
        case 17:
            return 30;
        case 18:
            return 180;
        case 19:
            return 120;
        default:
            return -1;
        }
    }

// ---- the wilderness weather system (folios 14-15) ----

// roll a six-sided die for the number of days or weeks the weather pattern
// occurs (folio 14)
inline int drmWeatherPatternDieSides()
    { return 6; }

// the terrain weather table rolls an eight-sided die (folio 14)
inline int drmWeatherTerrainDieSides()
    { return 8; }

// the Dense Fog visibility - only 30 feet (folio 14)
inline int drmDenseFogVisibilityFeet()
    { return 30; }

// the Light Fog visibility - 180 feet (folio 15)
inline int drmLightFogVisibilityFeet()
    { return 180; }

// the Low Clouds visibility - about 2 miles (folio 15)
inline int drmLowCloudsVisibilityMiles()
    { return 2; }

// the Medium Clouds visibility - 6 miles (folio 15)
inline int drmMediumCloudsVisibilityMiles()
    { return 6; }

// the High Clouds visibility - over 20 miles (folio 15)
inline int drmHighCloudsVisibilityMiles()
    { return 20; }

// the Cold weather - a 15 percent chance of hypothermia without warm clothing
// (folio 14)
inline int drmColdHypothermiaPercent()
    { return 15; }

// the Cold weather - a 10 percent weekly chance of pneumonia when not warm
// (folio 14)
inline int drmColdPneumoniaWeeklyPercent()
    { return 10; }

// the Cold weather - a 15 percent weekly chance of the flu when not warm
// (folio 14)
inline int drmColdFluWeeklyPercent()
    { return 15; }

// the Cold weather - a 50 percent weekly chance of a cold when not warm
// (folio 14)
inline int drmColdColdWeeklyPercent()
    { return 50; }

// the Cold weather staying warm - a 2 percent pneumonia chance (folio 14)
inline int drmColdWarmPneumoniaPercent()
    { return 2; }

// the Cold weather staying warm - a 5 percent flu chance (folio 14)
inline int drmColdWarmFluPercent()
    { return 5; }

// the Cold weather staying warm - a 25 percent cold chance (folio 14)
inline int drmColdWarmColdPercent()
    { return 25; }

// traveling in the Cold - a 25 percent weekly chance of frostbite (folio 14)
inline int drmFrostbiteWeeklyPercent()
    { return 25; }

// the frostbite damage - from 1 point (folio 14)
inline int drmFrostbiteDamageMin()
    { return 1; }

// the frostbite damage - up to 6 points (folio 14)
inline int drmFrostbiteDamageMax()
    { return 6; }

// the Snow weather increases the chance of disease by 5 percent (folio 15)
inline int drmSnowDiseaseBonusPercent()
    { return 5; }

// the Snow frostbite damage increased to 1-12 points (folio 15)
inline int drmSnowFrostbiteDamageMax()
    { return 12; }

// the Thunderstorm - a 2 percent daily chance of being hit by lightning
// (folio 15)
inline int drmThunderLightningDailyPercent()
    { return 2; }

// the Thunderstorm lightning chance reduced to 1 percent if armor is removed
// (folio 15)
inline int drmThunderUnarmoredDailyPercent()
    { return 1; }

// the lightning strike damage - from 10 points (folio 15)
inline int drmLightningDamageMin()
    { return 10; }

// the lightning strike damage - up to 100 points (folio 15)
inline int drmLightningDamageMax()
    { return 100; }

// the lightning strike stuns a victim for 2 days (folio 15)
inline int drmLightningStunDays()
    { return 2; }

// the Heavy Rain - a 5 percent chance of catching the flu (folio 15)
inline int drmHeavyRainFluPercent()
    { return 5; }

// the Heavy Rain - a 15 percent chance of getting a cold (folio 15)
inline int drmHeavyRainColdPercent()
    { return 15; }

// the Heavy Rain - party morale at minus 2 (folio 15)
inline int drmHeavyRainMoralePenalty()
    { return 2; }

// the Medium Rain - a 10 percent chance of catching a cold (folio 15)
inline int drmMediumRainColdPercent()
    { return 10; }

// the Medium Rain - a 1 percent chance of getting the flu (folio 15)
inline int drmMediumRainFluPercent()
    { return 1; }

// the Medium Rain - party morale at minus 1 (folio 15)
inline int drmMediumRainMoralePenalty()
    { return 1; }

// the Light Rain - only a 5 percent chance of contracting a cold (folio 15)
inline int drmLightRainColdPercent()
    { return 5; }

// the High Wind in the Desert - a 25 percent chance of a sandstorm (folio 15)
inline int drmHighWindSandstormPercent()
    { return 25; }

// the sandstorm - a 15 percent chance of suffocation (folio 15)
inline int drmSandstormSuffocationPercent()
    { return 15; }

// the Hot weather - check for irritation daily at 15 percent (folio 14)
inline int drmHotIrritationDailyPercent()
    { return 15; }

// the Hot weather - checked for heat exhaustion daily at 15 percent (folio
// 14)
inline int drmHotExhaustionDailyPercent()
    { return 15; }

// the Hot weather - combat cannot last beyond 15 melee turns (folio 14)
inline int drmHotCombatMaxRounds()
    { return 15; }

// the Warm weather - irritation checked at 10 percent (folio 14)
inline int drmWarmIrritationPercent()
    { return 10; }

// the Cool weather - a 20 percent chance of a cold every three weeks exposed
// (folio 14)
inline int drmCoolColdPercent()
    { return 20; }

// the Cool weather - a 2 percent flu chance for the same period (folio 14)
inline int drmCoolFluPercent()
    { return 2; }

// the Cool weather without warm clothing - the cold checked weekly at 25
// percent (folio 14)
inline int drmCoolBareWeeklyColdPercent()
    { return 25; }

// the Cool weather without warm clothing - the flu checked weekly at 10
// percent (folio 14)
inline int drmCoolBareWeeklyFluPercent()
    { return 10; }

// the Fair weather - party morale at plus 2 (folio 14)
inline int drmFairMoraleBonus()
    { return 2; }

// the Fair weather - the party fights with plus 1 (folio 14)
inline int drmFairCombatBonus()
    { return 1; }

// the Cold weather - all morale at minus 1 (folio 14)
inline int drmColdMoralePenalty()
    { return 1; }

// the Cold weather - any combat at minus 1 (folio 14)
inline int drmColdCombatPenalty()
    { return 1; }

// the Hot weather - morale at minus 2 (folio 14)
inline int drmHotMoralePenalty()
    { return 2; }

// the Hot weather - combat at minus 2 (folio 14)
inline int drmHotCombatPenalty()
    { return 2; }

// the Heavy Rain movement penalty - half speed, the denominator conversion
// (folio 15)
inline int drmHeavyRainMoveDenominator()
    { return 2; }

// the Heavy Rain plate-armor movement - quarter speed, the denominator
// conversion (folio 15)
inline int drmHeavyRainPlateDenominator()
    { return 4; }

// the Medium Rain movement penalty - quarter speed, the denominator
// conversion (folio 15)
inline int drmMediumRainMoveDenominator()
    { return 4; }

// the Medium Rain plate-armor movement - half speed, the denominator
// conversion (folio 15)
inline int drmMediumRainPlateDenominator()
    { return 2; }

// the Light Rain plate-armor movement penalty - quarter speed (folio 15)
inline int drmLightRainPlateDenominator()
    { return 4; }

// the article worked Cold/Snow example - a 35 percent chance of hypothermia
// (folio 15)
inline int drmColdSnowExampleHypothermiaPercent()
    { return 35; }

// the worked Cold/Snow example - a 35 percent flu chance (folio 15)
inline int drmColdSnowExampleFluPercent()
    { return 35; }

// the worked Cold/Snow example - a 25 percent pneumonia chance (folio 15)
inline int drmColdSnowExamplePneumoniaPercent()
    { return 25; }

// the worked Cold/Snow example - a 100 percent chance of getting a cold
// (folio 15)
inline int drmColdSnowExampleColdPercent()
    { return 100; }

// the worked Cold/Snow example - a 55 percent frostbite chance (folio 15)
inline int drmColdSnowExampleFrostbitePercent()
    { return 55; }

// the worked Cold/Snow example frostbite - from 2 points (folio 15)
inline int drmColdSnowExampleFrostbiteDamageMin()
    { return 2; }

// the worked Cold/Snow example frostbite - up to 18 points per attack (folio
// 15)
inline int drmColdSnowExampleFrostbiteDamageMax()
    { return 18; }

// reptiles - dragons, lizard men and the like - cannot move at all in Cold
// weather (folio 14)
inline bool drmReptilesImmobileInCold()
    { return true; }

// reptiles move at half speed in Cool weather (folio 14)
inline bool drmReptilesHalfSpeedInCool()
    { return true; }

// reptiles become overheated and move at half speed in Hot weather (folio 14)
inline bool drmReptilesHalfSpeedInHot()
    { return true; }

// flying is totally impossible in Dense Fog (folio 14)
inline bool drmFlyingImpossibleDenseFog()
    { return true; }

// the combined weather situations add up - everything is cumulative (folio
// 15)
inline bool drmWeatherCumulative()
    { return true; }

// missile weapons are ineffective in Dense Fog and fire at minus 3 (folio 14)
inline bool drmMissilesIneffectiveDenseFog()
    { return true; }

// the terrain weather matrix - eight die faces (folio 14, PDF 16)
inline int drmTerrainFaces()
    { return 8; }

// the open clear-terrain column - faces 1-3 clear, 4 unusual, 5-6 cloudy, 7
// stormy, 8 winds (folio 14)
inline int drmTClear(int b)
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
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        default:
            return -1;
        }
    }

// the woods column - faces 1-4 clear, 5-6 cloudy, 7-8 stormy (folio 14)
inline int drmTWoods(int b)
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
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the river column - faces 1-5 clear, 6-8 stormy (folio 14)
inline int drmTRiver(int b)
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
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the swamp column - faces 1-5 clear, 6 unusual, 7-8 stormy (folio 14)
inline int drmTSwamp(int b)
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
            return 2;
        case 5:
            return 5;
        case 6:
            return 3;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the mountains column - faces 1-3 clear, 4 unusual, 5-6 cloudy, 7-8 stormy
// (folio 14)
inline int drmTMountains(int b)
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
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        default:
            return -1;
        }
    }

// the desert column - faces 1-5 clear, 6 stormy, 7-8 winds (folio 14)
inline int drmTDesert(int b)
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
            return 5;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        default:
            return -1;
        }
    }

// the city column - faces 1-5 clear, 6 stormy, 7-8 unusual (folio 14)
inline int drmTCity(int b)
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
            return 2;
        case 5:
            return 3;
        case 6:
            return 5;
        case 7:
            return 5;
        default:
            return -1;
        }
    }

// the seasonal weather planner - four seasons (folio 15, PDF 17)
inline int drmSeasonRows()
    { return 4; }

// the weather-pattern length in weeks, lower bound - winter 1-4, spring 1-2,
// summer 1-6, fall 1-2 (folio 15)
inline int drmSWeeksMin(int b)
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
        default:
            return -1;
        }
    }

// the weather-pattern length in weeks, upper bound (folio 15)
inline int drmSWeeksMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 6;
        case 3:
            return 2;
        default:
            return -1;
        }
    }

// the clear faces, lower bound - winter 1-4, spring 2-9, summer 5-10, fall
// 1-10 (folio 15)
inline int drmSClearMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 1;
        default:
            return -1;
        }
    }

// the clear faces, upper bound (folio 15)
inline int drmSClearMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 9;
        case 2:
            return 10;
        case 3:
            return 10;
        default:
            return -1;
        }
    }

// the cloudy faces, lower bound - 1-10 every season (folio 15)
inline int drmSCloudyMin(int b)
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
        default:
            return -1;
        }
    }

// the cloudy faces, upper bound (folio 15)
inline int drmSCloudyMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        default:
            return -1;
        }
    }

// the stormy faces, lower bound - winter and fall 1-10, spring and summer 2-9
// (folio 15)
inline int drmSStormyMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        default:
            return -1;
        }
    }

// the stormy faces, upper bound (folio 15)
inline int drmSStormyMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 9;
        case 3:
            return 10;
        default:
            return -1;
        }
    }

// the winds faces, lower bound - 1-10 every season (folio 15)
inline int drmSWindsMin(int b)
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
        default:
            return -1;
        }
    }

// the winds faces, upper bound (folio 15)
inline int drmSWindsMax(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        default:
            return -1;
        }
    }

// the unusual faces, lower bound - sentinel for the three seasons printing
// non-contiguous faces (winter 1,2,4-9; spring 2,3,5,6,8,9; summer
// 2,3,5,6,9,10), the faces riding the transcript, never guessed; the fall
// 1-10 contiguous (folio 15)
inline int drmSUnusualMin(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return 1;
        default:
            return -1;
        }
    }

// the unusual faces, upper bound - sentinel for the same three seasons (folio
// 15)
inline int drmSUnusualMax(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return 10;
        default:
            return -1;
        }
    }

// the weather-disease table - six diseases (folio 14, PDF 16)
inline int drmDiseaseRows()
    { return 6; }

// the chance of immunity - the percent sign prints before the digits (%5 = 5
// percent, the percent-position class, the digits clean and pinned); heat
// stroke prints no immunity, sentinel (folio 14)
inline int drmDImmunityPercent(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return -1;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 10;
        case 5:
            return 15;
        default:
            return -1;
        }
    }

// the duration lower bound in days (folio 14)
inline int drmDDurationMinDays(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 1;
        default:
            return -1;
        }
    }

// the duration upper bound in days (folio 14)
inline int drmDDurationMaxDays(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 10;
        default:
            return -1;
        }
    }

// the incubation lower bound in days - hypothermia prints 0 (folio 14)
inline int drmDIncubationMinDays(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        default:
            return -1;
        }
    }

// the incubation upper bound in days (folio 14)
inline int drmDIncubationMaxDays(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 8;
        case 5:
            return 2;
        default:
            return -1;
        }
    }

// the chance of communication - the dash cells of heat stroke, hypothermia
// and irritation pin sentinel (folio 14)
inline int drmDCommunicationPercent(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 20;
        case 5:
            return 25;
        default:
            return -1;
        }
    }

// the recovery in weeks (folio 14)
inline int drmDRecoveryWeeks(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 1;
        default:
            return -1;
        }
    }

// the fatality percent - the heat-stroke 25 percent without rest and the
// hypothermia 75 percent unless warmed and rested ride the transcript
// footnotes (folio 14)
inline int drmDFatalityPercent(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 7;
        case 2:
            return 15;
        case 3:
            return 1;
        case 4:
            return 15;
        case 5:
            return 2;
        default:
            return -1;
        }
    }

// ---- the pit tables (folio 5) ----

// the citizen table - twelve careers from pipeweed grower to trapper (folio
// 5)
inline int drmCitizenCareers()
    { return 12; }

// wherever the pit tables print the asterisk there is a 40 percent chance of
// poison (folio 5)
inline int drmPitPoisonPercent()
    { return 40; }

// the special table - a tied-down citizen on 01-40 (folio 5)
inline int drmSpecialCitizenMax()
    { return 40; }

// the special table - a tied-down specialist on 41-80, a monster on 81-00
// (folio 5)
inline int drmSpecialSpecialistMax()
    { return 80; }

// a freed chained monster - 50 percent friend, 50 percent attack (folio 5)
inline int drmFreedMonsterFriendPercent()
    { return 50; }

// the grateful freed specialist helps rescuers from 2 days (folio 5)
inline int drmGratitudeDaysMin()
    { return 2; }

// the grateful freed specialist helps rescuers up to 20 days (folio 5)
inline int drmGratitudeDaysMax()
    { return 20; }

// the undecided freed monster - loyal on a die roll of 1-4 of 6 (folio 5)
inline int drmFreedLoyalDieMax()
    { return 4; }

// the giant centipedes are always poisonous, no other damage (folio 5)
inline bool drmCentipedesAlwaysPoisonous()
    { return true; }

// pits can open wide at the bottom into a monster chamber without other exits
// (folio 5)
inline bool drmPitsOpenWideAtBottom()
    { return true; }

// the specials of table 5 are usually totally stripped of their valuables
// (folio 5)
inline bool drmSpecialsStripped()
    { return true; }

// an untied freed monster remembers the faces and will hunt them down if ever
// freed (folio 5)
inline bool drmFreedMonsterRemembersFaces()
    { return true; }

// the pit table - four bands, empty, occupied, teleporting, bottomless (folio
// 5, PDF 7)
inline int drmPitBandRows()
    { return 4; }

// the pit band lower bound (folio 5)
inline int drmPBandMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 61;
        case 2:
            return 96;
        case 3:
            return 99;
        default:
            return -1;
        }
    }

// the pit band upper bound - empty 01-60, occupied 61-95, teleporting 96-98,
// bottomless 99-00 (folio 5)
inline int drmPBandMax(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 95;
        case 2:
            return 98;
        case 3:
            return 100;
        default:
            return -1;
        }
    }

// the occupied-pit table - five bands (folio 5)
inline int drmPitOccupantRows()
    { return 5; }

// the occupied-pit band lower bound - the animal band prints 35-65 sharing
// the 35 with the spikes band, the lower bound pins sentinel, never guessed
// (folio 5)
inline int drmPOccMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return -1;
        case 2:
            return 66;
        case 3:
            return 71;
        case 4:
            return 91;
        default:
            return -1;
        }
    }

// the occupied-pit band upper bound - spikes 01-35, animal to 65, teleporting
// 66-70, monster 71-90, special 91-00 (folio 5)
inline int drmPOccMax(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 65;
        case 2:
            return 70;
        case 3:
            return 90;
        case 4:
            return 100;
        default:
            return -1;
        }
    }

// the animal and insect table - six bands (folio 5)
inline int drmPitAnimalRows()
    { return 6; }

// the animal or insect band lower bound (folio 5)
inline int drmPAnimalMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 36;
        case 2:
            return 46;
        case 3:
            return 56;
        case 4:
            return 71;
        case 5:
            return 86;
        default:
            return -1;
        }
    }

// the animal or insect band upper bound - snakes 01-35, lizards 36-45, giant
// tick 46-55, giant serpent 56-70, giant weasels 71-85, giant centipedes
// 86-00 always poisonous (folio 5)
inline int drmPAnimalMax(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 45;
        case 2:
            return 55;
        case 3:
            return 70;
        case 4:
            return 85;
        case 5:
            return 100;
        default:
            return -1;
        }
    }

// the specialist table - ten bands (folio 5)
inline int drmPitSpecialistRows()
    { return 10; }

// the specialist band lower bound (folio 5)
inline int drmPSpecMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 16;
        case 2:
            return 51;
        case 3:
            return 61;
        case 4:
            return 71;
        case 5:
            return 76;
        case 6:
            return 81;
        case 7:
            return 86;
        case 8:
            return 91;
        case 9:
            return 96;
        default:
            return -1;
        }
    }

// the specialist band upper bound - the ranger band prints 91-85, the upper
// bound pins sentinel, never guessed; the scribe closes 96-00 (folio 5)
inline int drmPSpecMax(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 50;
        case 2:
            return 60;
        case 3:
            return 70;
        case 4:
            return 75;
        case 5:
            return 80;
        case 6:
            return 85;
        case 7:
            return 90;
        case 8:
            return -1;
        case 9:
            return 100;
        default:
            return -1;
        }
    }

// ---- the settlements random events (folio 5) ----

// the settlements random events table - sixteen event rows (folio 5, PDF 7)
inline int drmEventRows()
    { return 16; }

// the spring band, lower bound (folio 5)
inline int drmESpringMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 84;
        case 2:
            return -1;
        case 3:
            return 85;
        case 4:
            return 87;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 91;
        case 11:
            return 92;
        case 12:
            return 95;
        case 13:
            return 97;
        case 14:
            return 98;
        case 15:
            return 100;
        default:
            return -1;
        }
    }

// the spring band, upper bound (folio 5)
inline int drmESpringMax(int b)
    {
        switch (b) {
        case 0:
            return 83;
        case 1:
            return 84;
        case 2:
            return -1;
        case 3:
            return 86;
        case 4:
            return 87;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 91;
        case 11:
            return 94;
        case 12:
            return 96;
        case 13:
            return 97;
        case 14:
            return 99;
        case 15:
            return 100;
        default:
            return -1;
        }
    }

// the summer band, lower bound (folio 5)
inline int drmESummerMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 80;
        case 2:
            return -1;
        case 3:
            return 82;
        case 4:
            return 83;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 84;
        case 8:
            return 85;
        case 9:
            return 86;
        case 10:
            return 87;
        case 11:
            return 88;
        case 12:
            return 91;
        case 13:
            return 93;
        case 14:
            return 96;
        case 15:
            return 99;
        default:
            return -1;
        }
    }

// the summer band, upper bound (folio 5)
inline int drmESummerMax(int b)
    {
        switch (b) {
        case 0:
            return 79;
        case 1:
            return 81;
        case 2:
            return -1;
        case 3:
            return 82;
        case 4:
            return 83;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 84;
        case 8:
            return 85;
        case 9:
            return 86;
        case 10:
            return 87;
        case 11:
            return 90;
        case 12:
            return 92;
        case 13:
            return 95;
        case 14:
            return 98;
        case 15:
            return 100;
        default:
            return -1;
        }
    }

// the autumn band, lower bound (folio 5)
inline int drmEAutumnMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 80;
        case 2:
            return 81;
        case 3:
            return 82;
        case 4:
            return 83;
        case 5:
            return 84;
        case 6:
            return 86;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 91;
        case 11:
            return 92;
        case 12:
            return 93;
        case 13:
            return 94;
        case 14:
            return 96;
        case 15:
            return 99;
        default:
            return -1;
        }
    }

// the autumn band, upper bound (folio 5)
inline int drmEAutumnMax(int b)
    {
        switch (b) {
        case 0:
            return 79;
        case 1:
            return 80;
        case 2:
            return 81;
        case 3:
            return 82;
        case 4:
            return 83;
        case 5:
            return 85;
        case 6:
            return 87;
        case 7:
            return 88;
        case 8:
            return 89;
        case 9:
            return 90;
        case 10:
            return 91;
        case 11:
            return 92;
        case 12:
            return 93;
        case 13:
            return 95;
        case 14:
            return 98;
        case 15:
            return 100;
        default:
            return -1;
        }
    }

// the winter band, lower bound - sentinel for the dash cells (folio 5)
inline int drmEWinterMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return -1;
        case 2:
            return 81;
        case 3:
            return 86;
        case 4:
            return 88;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 90;
        case 8:
            return 91;
        case 9:
            return 92;
        case 10:
            return 93;
        case 11:
            return 94;
        case 12:
            return 95;
        case 13:
            return 96;
        case 14:
            return 97;
        case 15:
            return 99;
        default:
            return -1;
        }
    }

// the winter band, upper bound - sentinel for the dash cells (folio 5)
inline int drmEWinterMax(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return -1;
        case 2:
            return 85;
        case 3:
            return 87;
        case 4:
            return 89;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 90;
        case 8:
            return 91;
        case 9:
            return 92;
        case 10:
            return 93;
        case 11:
            return 94;
        case 12:
            return 95;
        case 13:
            return 96;
        case 14:
            return 98;
        case 15:
            return 100;
        default:
            return -1;
        }
    }

// the referee rolls once each month for every province or fief of each
// kingdom (folio 5)
inline bool drmEventsMonthlyPerProvince()
    { return true; }

}   // namespace rules
