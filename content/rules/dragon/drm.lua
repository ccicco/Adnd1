-- drm: promoted from tools/spec_r927.json (the The Dragon issue-15 opener - Dragon Magic (folio 3, cont. 13), the wandering monster list (folio 7), the wilderness weather system (folios 14-15), the pit tables (folio 5) and the settlements random events (folio 5): the five-chain round);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 927,
  "prefix" = "drm",
  "banner" = {
      "title" = "The Dragon issue-15 opener - Dragon Magic (folio 3, cont. 13), the wandering monster list (folio 7), the wilderness weather system (folios 14-15), the pit tables (folio 5) and the settlements random events (folio 5): the five-chain round",
      "provenance" = "Pinned from The Dragon Vol. III No. 1 (June 1978), the Curtiss-provided scan voice (single-voice: the issue-15 source is the uploaded Dm15.pdf with its mistral-ocr transcript; no archive.org djvu cross-check exists for issue 15, the accessory items end at issue 14). PRINT FOLIO = PDF PAGE MINUS TWO in this issue, verified at the page feet (folios 5, 7, 9, 11, 13 and 14 print at the PDF pages 7, 9, 11, 13, 15 and 16) plus the TOC alignments (Dragon Magic at print 3 = PDF 5, the Green Magician at print 23 = PDF 25, the Boot Hill events at print 32 = PDF 34); the TOC prints two swapped folios - Monty Haul listed at 7 sits at print 6, the Wandering Monster listed at 6 sits at print 7. The transcripts ride extract/dragon/015/p001 through p036, landed this round; the article CHAIN is the ink unit, not the folio.",
      "sentinel" = "Print quirks pinned AS SCANNED, noted never silent: no full-res visual check exists for this issue (the scan is a text-side transcript, no page renders), so garbled cells pin sentinel, never guessed - the occupied-pit animal band prints 01-35 spikes then 35-65 animal with the 35 shared between bands, the animal lower bound pins sentinel; the pit specialist ranger band prints 91-85, the upper bound pins sentinel; the seasonal unusual cells print non-contiguous faces (winter 1,2,4-9; spring 2,3,5,6,8,9; summer 2,3,5,6,9,10) and pin sentinel with the faces riding the transcript; the disease immunity column prints the percent sign before the digits (%5 = 5 percent, the percent-position class, the digits clean and pinned); the wandering-list will o wisp armor class minus 8 is genuine print; the as-men movement entries pin sentinel rather than a guessed number; the wandering-list damage lines ride the transcript, the table pinning the uniform columns.",
    },
  "consts" = { {
      "name" = "drmSpellsLevel1",
      "value" = 11,
      "comment" = "the dragon spell list - eleven first-level spells (folio 3, PDF 5)",
    }, {
      "name" = "drmSpellsLevel2",
      "value" = 12,
      "comment" = "the dragon spell list - twelve second-level spells (folio 3, PDF 5)",
    }, {
      "name" = "drmSpellsLevel3",
      "value" = 13,
      "comment" = "the dragon spell list - thirteen third-level spells (folio 3, PDF 5)",
    }, {
      "name" = "drmSpellsLevel4",
      "value" = 13,
      "comment" = "the dragon spell list - thirteen fourth-level spells (folio 3, PDF 6)",
    }, {
      "name" = "drmSpellsLevel5",
      "value" = 10,
      "comment" = "the dragon spell list - ten fifth-level spells (folio 3, PDF 6)",
    }, {
      "name" = "drmSpellsTotal",
      "value" = 59,
      "comment" = "the count across the five dragon spell lists, computed from the pinned level counts",
    }, {
      "name" = "drmNameServiceDemands",
      "value" = 1,
      "comment" = "speaking a dragon secret name grants one, and only one, demanded service (folio 3)",
    }, {
      "name" = "drmPolySelfTrapPercent",
      "value" = 2,
      "comment" = "the polymorph self entrapment - a 2 percent chance per day or fraction, cumulative (folio 3)",
    }, {
      "name" = "drmPolyOtherTrapPercent",
      "value" = 5,
      "comment" = "the polymorph others entrapment on a dragon - 5 percent per day or fraction, cumulative (folio 3)",
    }, {
      "name" = "drmSeekDirectionErrorDegrees",
      "value" = 20,
      "comment" = "the Seek spell finds direction within plus or minus 20 degrees (folio 3)",
    }, {
      "name" = "drmSeekDistanceErrorPercent",
      "value" = 20,
      "comment" = "the Seek spell finds distance within 20 percent (folio 3)",
    }, {
      "name" = "drmPointerAdjacentLevelPercent",
      "value" = 30,
      "comment" = "the Magic Pointer has a 30 percent chance of pointing out an opponent one level or hit die lower (folio 3)",
    }, {
      "name" = "drmPointerRandomPercent",
      "value" = 10,
      "comment" = "the Magic Pointer has a 10 percent chance of indicating a random adversary (folio 3)",
    }, {
      "name" = "drmSummonStoneChancePerAge",
      "value" = 10,
      "comment" = "a dragon has a 10 percent chance per age level of possessing a summoning stone (folio 3)",
    }, {
      "name" = "drmServantsMin",
      "value" = 4,
      "comment" = "the servant summoning - from 4 creatures appear (folio 3)",
    }, {
      "name" = "drmServantsMax",
      "value" = 16,
      "comment" = "the servant summoning - up to 16 creatures appear (folio 3)",
    }, {
      "name" = "drmServantRoundsMin",
      "value" = 2,
      "comment" = "the summoned servants stay from 2 melee rounds (folio 3)",
    }, {
      "name" = "drmServantRoundsMax",
      "value" = 12,
      "comment" = "the summoned servants stay up to 12 melee rounds (folio 3)",
    }, {
      "name" = "drmServantArmorClass",
      "value" = 5,
      "comment" = "the summoning-stone birds - armor class 5 (folio 3)",
    }, {
      "name" = "drmServantMoveGroundInches",
      "value" = 4,
      "comment" = "the summoning-stone birds move 4 inches on the ground (folio 3)",
    }, {
      "name" = "drmServantMoveFlyInches",
      "value" = 48,
      "comment" = "the summoning-stone birds move 48 inches aloft (folio 3)",
    }, {
      "name" = "drmServantHpMin",
      "value" = 2,
      "comment" = "the summoning-stone birds carry from 2 hit points each (folio 3)",
    }, {
      "name" = "drmServantHpMax",
      "value" = 12,
      "comment" = "the summoning-stone birds carry up to 12 hit points each (folio 3)",
    }, {
      "name" = "drmServantTalonDamageMin",
      "value" = 1,
      "comment" = "the summoning-stone birds talon - from 1 point (folio 3)",
    }, {
      "name" = "drmServantTalonDamageMax",
      "value" = 2,
      "comment" = "the summoning-stone birds talon - up to 2 points, two talons (folio 3)",
    }, {
      "name" = "drmServantBeakDamageMin",
      "value" = 1,
      "comment" = "the summoning-stone birds beak - from 1 point (folio 3)",
    }, {
      "name" = "drmServantBeakDamageMax",
      "value" = 6,
      "comment" = "the summoning-stone birds beak - up to 6 points (folio 3)",
    }, {
      "name" = "drmHeatMetalMaxGold",
      "value" = 1500,
      "comment" = "the Heat Metal spell affects a maximum of 1500 gold pieces in weight (folio 3)",
    }, {
      "name" = "drmWaterToWineGallonsPerAge",
      "value" = 20,
      "comment" = "the Water to Wine spell converts 20 gallons per age class (folio 3)",
    }, {
      "name" = "drmWoodToSandCuFtPerAge",
      "value" = 1,
      "comment" = "the Wood to Sand spell changes 1 cubic foot of wood per age class (folio 3)",
    }, {
      "name" = "drmRockToSandCuFtPerAge",
      "value" = 1,
      "comment" = "the Rock to Sand spell changes 1 cubic foot of stone per age level (folio 3)",
    }, {
      "name" = "drmCallLightningDice",
      "value" = 10,
      "comment" = "the Call Lightning bolt is 10 dice (folio 3)",
    }, {
      "name" = "drmCallLightningDieSides",
      "value" = 8,
      "comment" = "the Call Lightning bolt dice are 8-sided (folio 3)",
    }, {
      "name" = "drmCallLightningMinutesPerBolt",
      "value" = 10,
      "comment" = "the Call Lightning frequency - one bolt per 10 minutes (folio 3)",
    }, {
      "name" = "drmAlarmDurationWeeks",
      "value" = 1,
      "comment" = "the Alarm rune lasts 1 week (folio 3)",
    }, {
      "name" = "drmAlarmTelepathicInches",
      "value" = 24,
      "comment" = "the Alarm telepathic link reaches 24 inches (folio 3)",
    }, {
      "name" = "drmHoldMammalMax",
      "value" = 4,
      "comment" = "the Hold Mammal spell holds from 1 to 4 mammals (folio 3)",
    }, {
      "name" = "drmHoldMammalRangeInches",
      "value" = 12,
      "comment" = "the Hold Mammal range - 12 inches (folio 3)",
    }, {
      "name" = "drmHoldMammalDurationTurns",
      "value" = 6,
      "comment" = "the Hold Mammal duration - 6 turns (folio 3)",
    }, {
      "name" = "drmBindingDurationMinTurns",
      "value" = 1,
      "comment" = "the Binding Spell freezes metal from 1 turn (folio 3)",
    }, {
      "name" = "drmBindingDurationMaxTurns",
      "value" = 4,
      "comment" = "the Binding Spell freezes metal up to 4 turns (folio 3)",
    }, {
      "name" = "drmBindingMagicSaves",
      "value" = 2,
      "comment" = "the Binding Spell grants magical items two saving throws (folio 3)",
    }, {
      "name" = "drmControlWindsSpeedMph",
      "value" = 15,
      "comment" = "the Control Winds spell changes wind speed by plus or minus 15 mph (folio 3)",
    }, {
      "name" = "drmControlWindsDirectionDegrees",
      "value" = 45,
      "comment" = "the Control Winds spell changes direction by 45 degrees (folio 3)",
    }, {
      "name" = "drmControlWindsDurationTurns",
      "value" = 6,
      "comment" = "the Control Winds duration - 6 turns (folio 3)",
    }, {
      "name" = "drmControlWindsRadiusInches",
      "value" = 24,
      "comment" = "the Control Winds range - a 24-inch radius (folio 3)",
    }, {
      "name" = "drmNegateItemsPerDay",
      "value" = 1,
      "comment" = "the Negate Enchantment I spell negates one item per day (folio 3)",
    }, {
      "name" = "drmNegateDurationMinRounds",
      "value" = 2,
      "comment" = "the Negate Enchantment I lasts from 2 melee rounds (folio 3)",
    }, {
      "name" = "drmNegateDurationMaxRounds",
      "value" = 12,
      "comment" = "the Negate Enchantment I lasts up to 12 melee rounds (folio 3)",
    }, {
      "name" = "drmNegateRangeInches",
      "value" = 6,
      "comment" = "the Negate Enchantment I range - 6 inches (folio 3)",
    }, {
      "name" = "drmCharmAviansSmallMin",
      "value" = 2,
      "comment" = "the Charm Avians spell commands from 2 small birds (folio 3)",
    }, {
      "name" = "drmCharmAviansSmallMax",
      "value" = 8,
      "comment" = "the Charm Avians spell commands up to 8 small birds (folio 3)",
    }, {
      "name" = "drmCharmAviansMediumMin",
      "value" = 1,
      "comment" = "the Charm Avians spell commands from 1 medium bird (folio 3)",
    }, {
      "name" = "drmCharmAviansMediumMax",
      "value" = 3,
      "comment" = "the Charm Avians spell commands up to 3 medium birds (folio 3)",
    }, {
      "name" = "drmCharmAviansManSized",
      "value" = 1,
      "comment" = "the Charm Avians spell commands 1 man-sized bird (folio 3)",
    }, {
      "name" = "drmCharmAviansRangeInches",
      "value" = 12,
      "comment" = "the Charm Avians range - 12 inches (folio 3)",
    }, {
      "name" = "drmCharmAviansDurationDays",
      "value" = 1,
      "comment" = "the Charm Avians duration - 1 day (folio 3)",
    }, {
      "name" = "drmSeeInvisibleRadiusInches",
      "value" = 6,
      "comment" = "the See Invisible spell - a 6-inch radius (folio 3)",
    }, {
      "name" = "drmSeeOtherPlanesDurationTurns",
      "value" = 3,
      "comment" = "the See Other Planes duration - 3 turns (folio 3)",
    }, {
      "name" = "drmGloomMoralePenalty",
      "value" = 2,
      "comment" = "passing the Wall of Gloom reduces morale by 2 (folio 3)",
    }, {
      "name" = "drmWallDurationMinTurns",
      "value" = 3,
      "comment" = "the Wall of Gloom and the Wall of Wind both last from 3 turns (folio 3)",
    }, {
      "name" = "drmWallDurationMaxTurns",
      "value" = 8,
      "comment" = "the Wall of Gloom and the Wall of Wind both last up to 8 turns (folio 3)",
    }, {
      "name" = "drmWeightControlRangeInches",
      "value" = 12,
      "comment" = "the Weight Control range - 12 inches (folio 3)",
    }, {
      "name" = "drmWerelightSpreadInches",
      "value" = 3,
      "comment" = "the Werelight spreads from creature to creature within 3 inches (folio 3)",
    }, {
      "name" = "drmWerelightRangeInches",
      "value" = 12,
      "comment" = "the Werelight may be created within 12 inches of the caster (folio 3)",
    }, {
      "name" = "drmWerelightDurationMinRounds",
      "value" = 3,
      "comment" = "the Werelight lasts from 3 melee rounds (folio 3)",
    }, {
      "name" = "drmWerelightDurationMaxRounds",
      "value" = 18,
      "comment" = "the Werelight lasts up to 18 melee rounds, or 1 full turn (folio 3)",
    }, {
      "name" = "drmAnimateDeadHdMin",
      "value" = 2,
      "comment" = "the Animate Dead spell animates from 2 hit dice of creatures (folio 13, PDF 15)",
    }, {
      "name" = "drmAnimateDeadHdMax",
      "value" = 16,
      "comment" = "the Animate Dead spell animates up to 16 hit dice of creatures (folio 13)",
    }, {
      "name" = "drmAnimateDeadSkeletonHdMax",
      "value" = 8,
      "comment" = "the Animate Dead skeletons - up to 8 hit dice of skeletons (folio 13)",
    }, {
      "name" = "drmAnimateDeadRangeInches",
      "value" = 6,
      "comment" = "the Animate Dead range - 6 inches (folio 13)",
    }, {
      "name" = "drmConjureElementalDice",
      "value" = 16,
      "comment" = "the Conjure Elemental strength - 16 dice (folio 13)",
    }, {
      "name" = "drmCurseBlessLiftHours",
      "value" = 8,
      "comment" = "a dragon curse may be lifted for 8 hours via a bless spell (folio 13)",
    }, {
      "name" = "drmCurseFullWishesToDispel",
      "value" = 2,
      "comment" = "two Full Wishes will dispel a dragon curse (folio 13)",
    }, {
      "name" = "drmEvaluateExampleGold",
      "value" = 30000,
      "comment" = "the Evaluate Item worked example - the chimes of opening value 30000 gold (folio 3)",
    }, {
      "name" = "drmWanderingRows",
      "value" = 20,
      "comment" = "the fourth-level wandering monster list - twenty entries (folio 7, PDF 9)",
    }, {
      "name" = "drmWeatherPatternDieSides",
      "value" = 6,
      "comment" = "roll a six-sided die for the number of days or weeks the weather pattern occurs (folio 14)",
    }, {
      "name" = "drmWeatherTerrainDieSides",
      "value" = 8,
      "comment" = "the terrain weather table rolls an eight-sided die (folio 14)",
    }, {
      "name" = "drmDiseaseRows",
      "value" = 6,
      "comment" = "the weather-disease table - six diseases (folio 14, PDF 16)",
    }, {
      "name" = "drmSeasonRows",
      "value" = 4,
      "comment" = "the seasonal weather planner - four seasons (folio 15, PDF 17)",
    }, {
      "name" = "drmTerrainFaces",
      "value" = 8,
      "comment" = "the terrain weather matrix - eight die faces (folio 14, PDF 16)",
    }, {
      "name" = "drmDenseFogVisibilityFeet",
      "value" = 30,
      "comment" = "the Dense Fog visibility - only 30 feet (folio 14)",
    }, {
      "name" = "drmLightFogVisibilityFeet",
      "value" = 180,
      "comment" = "the Light Fog visibility - 180 feet (folio 15)",
    }, {
      "name" = "drmLowCloudsVisibilityMiles",
      "value" = 2,
      "comment" = "the Low Clouds visibility - about 2 miles (folio 15)",
    }, {
      "name" = "drmMediumCloudsVisibilityMiles",
      "value" = 6,
      "comment" = "the Medium Clouds visibility - 6 miles (folio 15)",
    }, {
      "name" = "drmHighCloudsVisibilityMiles",
      "value" = 20,
      "comment" = "the High Clouds visibility - over 20 miles (folio 15)",
    }, {
      "name" = "drmColdHypothermiaPercent",
      "value" = 15,
      "comment" = "the Cold weather - a 15 percent chance of hypothermia without warm clothing (folio 14)",
    }, {
      "name" = "drmColdPneumoniaWeeklyPercent",
      "value" = 10,
      "comment" = "the Cold weather - a 10 percent weekly chance of pneumonia when not warm (folio 14)",
    }, {
      "name" = "drmColdFluWeeklyPercent",
      "value" = 15,
      "comment" = "the Cold weather - a 15 percent weekly chance of the flu when not warm (folio 14)",
    }, {
      "name" = "drmColdColdWeeklyPercent",
      "value" = 50,
      "comment" = "the Cold weather - a 50 percent weekly chance of a cold when not warm (folio 14)",
    }, {
      "name" = "drmColdWarmPneumoniaPercent",
      "value" = 2,
      "comment" = "the Cold weather staying warm - a 2 percent pneumonia chance (folio 14)",
    }, {
      "name" = "drmColdWarmFluPercent",
      "value" = 5,
      "comment" = "the Cold weather staying warm - a 5 percent flu chance (folio 14)",
    }, {
      "name" = "drmColdWarmColdPercent",
      "value" = 25,
      "comment" = "the Cold weather staying warm - a 25 percent cold chance (folio 14)",
    }, {
      "name" = "drmFrostbiteWeeklyPercent",
      "value" = 25,
      "comment" = "traveling in the Cold - a 25 percent weekly chance of frostbite (folio 14)",
    }, {
      "name" = "drmFrostbiteDamageMin",
      "value" = 1,
      "comment" = "the frostbite damage - from 1 point (folio 14)",
    }, {
      "name" = "drmFrostbiteDamageMax",
      "value" = 6,
      "comment" = "the frostbite damage - up to 6 points (folio 14)",
    }, {
      "name" = "drmSnowDiseaseBonusPercent",
      "value" = 5,
      "comment" = "the Snow weather increases the chance of disease by 5 percent (folio 15)",
    }, {
      "name" = "drmSnowFrostbiteDamageMax",
      "value" = 12,
      "comment" = "the Snow frostbite damage increased to 1-12 points (folio 15)",
    }, {
      "name" = "drmThunderLightningDailyPercent",
      "value" = 2,
      "comment" = "the Thunderstorm - a 2 percent daily chance of being hit by lightning (folio 15)",
    }, {
      "name" = "drmThunderUnarmoredDailyPercent",
      "value" = 1,
      "comment" = "the Thunderstorm lightning chance reduced to 1 percent if armor is removed (folio 15)",
    }, {
      "name" = "drmLightningDamageMin",
      "value" = 10,
      "comment" = "the lightning strike damage - from 10 points (folio 15)",
    }, {
      "name" = "drmLightningDamageMax",
      "value" = 100,
      "comment" = "the lightning strike damage - up to 100 points (folio 15)",
    }, {
      "name" = "drmLightningStunDays",
      "value" = 2,
      "comment" = "the lightning strike stuns a victim for 2 days (folio 15)",
    }, {
      "name" = "drmHeavyRainFluPercent",
      "value" = 5,
      "comment" = "the Heavy Rain - a 5 percent chance of catching the flu (folio 15)",
    }, {
      "name" = "drmHeavyRainColdPercent",
      "value" = 15,
      "comment" = "the Heavy Rain - a 15 percent chance of getting a cold (folio 15)",
    }, {
      "name" = "drmHeavyRainMoralePenalty",
      "value" = 2,
      "comment" = "the Heavy Rain - party morale at minus 2 (folio 15)",
    }, {
      "name" = "drmMediumRainColdPercent",
      "value" = 10,
      "comment" = "the Medium Rain - a 10 percent chance of catching a cold (folio 15)",
    }, {
      "name" = "drmMediumRainFluPercent",
      "value" = 1,
      "comment" = "the Medium Rain - a 1 percent chance of getting the flu (folio 15)",
    }, {
      "name" = "drmMediumRainMoralePenalty",
      "value" = 1,
      "comment" = "the Medium Rain - party morale at minus 1 (folio 15)",
    }, {
      "name" = "drmLightRainColdPercent",
      "value" = 5,
      "comment" = "the Light Rain - only a 5 percent chance of contracting a cold (folio 15)",
    }, {
      "name" = "drmHighWindSandstormPercent",
      "value" = 25,
      "comment" = "the High Wind in the Desert - a 25 percent chance of a sandstorm (folio 15)",
    }, {
      "name" = "drmSandstormSuffocationPercent",
      "value" = 15,
      "comment" = "the sandstorm - a 15 percent chance of suffocation (folio 15)",
    }, {
      "name" = "drmHotIrritationDailyPercent",
      "value" = 15,
      "comment" = "the Hot weather - check for irritation daily at 15 percent (folio 14)",
    }, {
      "name" = "drmHotExhaustionDailyPercent",
      "value" = 15,
      "comment" = "the Hot weather - checked for heat exhaustion daily at 15 percent (folio 14)",
    }, {
      "name" = "drmHotCombatMaxRounds",
      "value" = 15,
      "comment" = "the Hot weather - combat cannot last beyond 15 melee turns (folio 14)",
    }, {
      "name" = "drmWarmIrritationPercent",
      "value" = 10,
      "comment" = "the Warm weather - irritation checked at 10 percent (folio 14)",
    }, {
      "name" = "drmCoolColdPercent",
      "value" = 20,
      "comment" = "the Cool weather - a 20 percent chance of a cold every three weeks exposed (folio 14)",
    }, {
      "name" = "drmCoolFluPercent",
      "value" = 2,
      "comment" = "the Cool weather - a 2 percent flu chance for the same period (folio 14)",
    }, {
      "name" = "drmCoolBareWeeklyColdPercent",
      "value" = 25,
      "comment" = "the Cool weather without warm clothing - the cold checked weekly at 25 percent (folio 14)",
    }, {
      "name" = "drmCoolBareWeeklyFluPercent",
      "value" = 10,
      "comment" = "the Cool weather without warm clothing - the flu checked weekly at 10 percent (folio 14)",
    }, {
      "name" = "drmFairMoraleBonus",
      "value" = 2,
      "comment" = "the Fair weather - party morale at plus 2 (folio 14)",
    }, {
      "name" = "drmFairCombatBonus",
      "value" = 1,
      "comment" = "the Fair weather - the party fights with plus 1 (folio 14)",
    }, {
      "name" = "drmColdMoralePenalty",
      "value" = 1,
      "comment" = "the Cold weather - all morale at minus 1 (folio 14)",
    }, {
      "name" = "drmColdCombatPenalty",
      "value" = 1,
      "comment" = "the Cold weather - any combat at minus 1 (folio 14)",
    }, {
      "name" = "drmHotMoralePenalty",
      "value" = 2,
      "comment" = "the Hot weather - morale at minus 2 (folio 14)",
    }, {
      "name" = "drmHotCombatPenalty",
      "value" = 2,
      "comment" = "the Hot weather - combat at minus 2 (folio 14)",
    }, {
      "name" = "drmHeavyRainMoveDenominator",
      "value" = 2,
      "comment" = "the Heavy Rain movement penalty - half speed, the denominator conversion (folio 15)",
    }, {
      "name" = "drmHeavyRainPlateDenominator",
      "value" = 4,
      "comment" = "the Heavy Rain plate-armor movement - quarter speed, the denominator conversion (folio 15)",
    }, {
      "name" = "drmMediumRainMoveDenominator",
      "value" = 4,
      "comment" = "the Medium Rain movement penalty - quarter speed, the denominator conversion (folio 15)",
    }, {
      "name" = "drmMediumRainPlateDenominator",
      "value" = 2,
      "comment" = "the Medium Rain plate-armor movement - half speed, the denominator conversion (folio 15)",
    }, {
      "name" = "drmLightRainPlateDenominator",
      "value" = 4,
      "comment" = "the Light Rain plate-armor movement penalty - quarter speed (folio 15)",
    }, {
      "name" = "drmColdSnowExampleHypothermiaPercent",
      "value" = 35,
      "comment" = "the article worked Cold/Snow example - a 35 percent chance of hypothermia (folio 15)",
    }, {
      "name" = "drmColdSnowExampleFluPercent",
      "value" = 35,
      "comment" = "the worked Cold/Snow example - a 35 percent flu chance (folio 15)",
    }, {
      "name" = "drmColdSnowExamplePneumoniaPercent",
      "value" = 25,
      "comment" = "the worked Cold/Snow example - a 25 percent pneumonia chance (folio 15)",
    }, {
      "name" = "drmColdSnowExampleColdPercent",
      "value" = 100,
      "comment" = "the worked Cold/Snow example - a 100 percent chance of getting a cold (folio 15)",
    }, {
      "name" = "drmColdSnowExampleFrostbitePercent",
      "value" = 55,
      "comment" = "the worked Cold/Snow example - a 55 percent frostbite chance (folio 15)",
    }, {
      "name" = "drmColdSnowExampleFrostbiteDamageMin",
      "value" = 2,
      "comment" = "the worked Cold/Snow example frostbite - from 2 points (folio 15)",
    }, {
      "name" = "drmColdSnowExampleFrostbiteDamageMax",
      "value" = 18,
      "comment" = "the worked Cold/Snow example frostbite - up to 18 points per attack (folio 15)",
    }, {
      "name" = "drmPitBandRows",
      "value" = 4,
      "comment" = "the pit table - four bands, empty, occupied, teleporting, bottomless (folio 5, PDF 7)",
    }, {
      "name" = "drmPitOccupantRows",
      "value" = 5,
      "comment" = "the occupied-pit table - five bands (folio 5)",
    }, {
      "name" = "drmPitAnimalRows",
      "value" = 6,
      "comment" = "the animal and insect table - six bands (folio 5)",
    }, {
      "name" = "drmPitSpecialistRows",
      "value" = 10,
      "comment" = "the specialist table - ten bands (folio 5)",
    }, {
      "name" = "drmCitizenCareers",
      "value" = 12,
      "comment" = "the citizen table - twelve careers from pipeweed grower to trapper (folio 5)",
    }, {
      "name" = "drmPitPoisonPercent",
      "value" = 40,
      "comment" = "wherever the pit tables print the asterisk there is a 40 percent chance of poison (folio 5)",
    }, {
      "name" = "drmSpecialCitizenMax",
      "value" = 40,
      "comment" = "the special table - a tied-down citizen on 01-40 (folio 5)",
    }, {
      "name" = "drmSpecialSpecialistMax",
      "value" = 80,
      "comment" = "the special table - a tied-down specialist on 41-80, a monster on 81-00 (folio 5)",
    }, {
      "name" = "drmFreedMonsterFriendPercent",
      "value" = 50,
      "comment" = "a freed chained monster - 50 percent friend, 50 percent attack (folio 5)",
    }, {
      "name" = "drmGratitudeDaysMin",
      "value" = 2,
      "comment" = "the grateful freed specialist helps rescuers from 2 days (folio 5)",
    }, {
      "name" = "drmGratitudeDaysMax",
      "value" = 20,
      "comment" = "the grateful freed specialist helps rescuers up to 20 days (folio 5)",
    }, {
      "name" = "drmFreedLoyalDieMax",
      "value" = 4,
      "comment" = "the undecided freed monster - loyal on a die roll of 1-4 of 6 (folio 5)",
    }, {
      "name" = "drmEventRows",
      "value" = 16,
      "comment" = "the settlements random events table - sixteen event rows (folio 5, PDF 7)",
    } },
  "bools" = { {
      "name" = "drmSecretNameDispelsAllWorks",
      "value" = true,
      "comment" = "if a dragon name is spoken, all works of that dragon magic are dispelled (folio 3)",
    }, {
      "name" = "drmServantEvilOnly",
      "value" = true,
      "comment" = "only EVIL dragons use the Servant Summoning spell except in the greatest peril (folio 3)",
    }, {
      "name" = "drmServantDrivenOffByStrongLight",
      "value" = true,
      "comment" = "the summoning-stone birds are driven off by strong light (folio 3)",
    }, {
      "name" = "drmServantsNeverCrossWater",
      "value" = true,
      "comment" = "the summoning-stone birds will not cross water under any circumstances (folio 3)",
    }, {
      "name" = "drmMetallicDragonsPolyImmune",
      "value" = true,
      "comment" = "Silver, Gold and the Platinum Dragon are not subject to the polymorph entrapment (folio 3)",
    }, {
      "name" = "drmDragonsNeverCharmDragons",
      "value" = true,
      "comment" = "dragons will never use the Charm Monster spell upon each other (folio 3)",
    }, {
      "name" = "drmAirElementalNeverTurnsOnDragon",
      "value" = true,
      "comment" = "an air elemental will not turn on the dragon if control is lost (folio 13)",
    }, {
      "name" = "drmPhantasmalForcesAnyFirstLevelSlot",
      "value" = true,
      "comment" = "the Phantasmal Forces spell is usable in lieu of any first-level spell (folio 3)",
    }, {
      "name" = "drmCurseAlwaysComesTrue",
      "value" = true,
      "comment" = "a dragon curse will always come true, the time unspecified (folio 3)",
    }, {
      "name" = "drmCurseNoSavingThrow",
      "value" = true,
      "comment" = "no saving throw is allowed the victim of a dragon curse (folio 3)",
    }, {
      "name" = "drmAnimateDeadHalfDice",
      "value" = true,
      "comment" = "the animated monsters have half the hit dice of the original creature (folio 13)",
    }, {
      "name" = "drmAnimateDeadHalfDamage",
      "value" = true,
      "comment" = "the animated monsters attack for half damage (folio 13)",
    }, {
      "name" = "drmReptilesImmobileInCold",
      "value" = true,
      "comment" = "reptiles - dragons, lizard men and the like - cannot move at all in Cold weather (folio 14)",
    }, {
      "name" = "drmReptilesHalfSpeedInCool",
      "value" = true,
      "comment" = "reptiles move at half speed in Cool weather (folio 14)",
    }, {
      "name" = "drmReptilesHalfSpeedInHot",
      "value" = true,
      "comment" = "reptiles become overheated and move at half speed in Hot weather (folio 14)",
    }, {
      "name" = "drmFlyingImpossibleDenseFog",
      "value" = true,
      "comment" = "flying is totally impossible in Dense Fog (folio 14)",
    }, {
      "name" = "drmWeatherCumulative",
      "value" = true,
      "comment" = "the combined weather situations add up - everything is cumulative (folio 15)",
    }, {
      "name" = "drmMissilesIneffectiveDenseFog",
      "value" = true,
      "comment" = "missile weapons are ineffective in Dense Fog and fire at minus 3 (folio 14)",
    }, {
      "name" = "drmCentipedesAlwaysPoisonous",
      "value" = true,
      "comment" = "the giant centipedes are always poisonous, no other damage (folio 5)",
    }, {
      "name" = "drmPitsOpenWideAtBottom",
      "value" = true,
      "comment" = "pits can open wide at the bottom into a monster chamber without other exits (folio 5)",
    }, {
      "name" = "drmSpecialsStripped",
      "value" = true,
      "comment" = "the specials of table 5 are usually totally stripped of their valuables (folio 5)",
    }, {
      "name" = "drmFreedMonsterRemembersFaces",
      "value" = true,
      "comment" = "an untied freed monster remembers the faces and will hunt them down if ever freed (folio 5)",
    }, {
      "name" = "drmEventsMonthlyPerProvince",
      "value" = true,
      "comment" = "the referee rolls once each month for every province or fief of each kingdom (folio 5)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "drmWandering",
      "tag" = "WW",
      "count" = "drmWanderingRows",
      "sentinel" = -1,
      "sentinel_census" = { 4, 4, 1, 4, 5 },
      "audit_comment" = "the Ward pre-rolled fourth-level wandering monster list - twenty entries, the uniform columns pinned (appearing band, hit points, armor class, dungeon move in feet) and the damage lines with their special rules riding the transcript, noted never silent; the as-men movement entries pin sentinel rather than a guessed number, and the will o wisp armor class minus 8 is genuine print (folio 7, PDF 9)",
      "cols" = { "drmWAppearMin", "drmWAppearMax", "drmWHitPoints", "drmWArmorClass", "drmWMoveFeet" },
      "col_comments" = { "the appearing bands - the counts as printed, sentinel where the entry prints no band (folio 7)", "the appearing bands upper bounds - sentinel where not printed (folio 7)", "the hit points - per the printed list; the curate row pins the curate 20 with the men-at-arms 5 each riding the transcript, the lycanthrope row sentinel with the four kinds riding the transcript (folio 7)", "the armor classes - the will o wisp minus 8 is genuine print; sentinel where the entry prints no armor class (folio 7)", "the dungeon move in feet per turn - the gargoyle air move 150 rides the transcript; sentinel for the as-men entries, never guessed (folio 7)" },
      "data" = { { 1, 2, 17, 5, 90 }, { 1, 4, 9, 3, 120 }, { 1, 2, 12, 5, 90 }, { 1, 4, 22, 5, 90 }, { 1, 6, 20, -1, -1 }, { 1, 4, 23, -1, -1 }, { 1, 4, 10, -1, -1 }, { 1, 4, 17, -1, -1 }, { 1, 4, 9, 7, 90 }, { 1, 2, 15, 3, 60 }, { 1, 4, 20, 3, 90 }, { -1, -1, -1, 4, -1 }, { 1, 6, 22, 4, 90 }, { 1, 4, 15, 5, 120 }, { 2, 6, 22, 4, 150 }, { 4, 16, 13, 5, 120 }, { -1, -1, 24, 5, 150 }, { 3, 12, 8, 4, 30 }, { -1, -1, 33, -8, 180 }, { -1, -1, 19, 2, 120 } },
    }, {
      "name" = "drmDisease",
      "tag" = "DI",
      "count" = "drmDiseaseRows",
      "sentinel" = -1,
      "sentinel_census" = { 1, 0, 0, 0, 0, 3, 0, 0 },
      "audit_comment" = "the weather-disease table - pneumonia, heat stroke, hypothermia, irritation, flu and cold, pinned as scanned; the immunity column prints the percent sign before the digits, the digits clean; the heat-stroke and hypothermia fatality footnotes ride the transcript (folio 14, PDF 16)",
      "cols" = { "drmDImmunityPercent", "drmDDurationMinDays", "drmDDurationMaxDays", "drmDIncubationMinDays", "drmDIncubationMaxDays", "drmDCommunicationPercent", "drmDRecoveryWeeks", "drmDFatalityPercent" },
      "col_comments" = { "the chance of immunity - the percent sign prints before the digits (%5 = 5 percent, the percent-position class, the digits clean and pinned); heat stroke prints no immunity, sentinel (folio 14)", "the duration lower bound in days (folio 14)", "the duration upper bound in days (folio 14)", "the incubation lower bound in days - hypothermia prints 0 (folio 14)", "the incubation upper bound in days (folio 14)", "the chance of communication - the dash cells of heat stroke, hypothermia and irritation pin sentinel (folio 14)", "the recovery in weeks (folio 14)", "the fatality percent - the heat-stroke 25 percent without rest and the hypothermia 75 percent unless warmed and rested ride the transcript footnotes (folio 14)" },
      "data" = { { 5, 10, 100, 1, 6, 10, 6, 20 }, { -1, 1, 2, 1, 1, -1, 1, 7 }, { 5, 1, 1, 0, 0, -1, 2, 15 }, { 2, 2, 20, 1, 4, -1, 1, 1 }, { 10, 2, 20, 1, 8, 20, 2, 15 }, { 15, 1, 10, 2, 2, 25, 1, 2 } },
    }, {
      "name" = "drmTerrain",
      "tag" = "TE",
      "count" = "drmTerrainFaces",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0 },
      "audit_comment" = "the terrain weather matrix - the d8 face by the seven terrains, pinned as the category conversion (1 Clear, 2 Cloudy, 3 Stormy, 4 Winds, 5 Unusual), the conversion noted never silent; the companion weather-type table of names rides the transcript (folio 14, PDF 16)",
      "cols" = { "drmTClear", "drmTWoods", "drmTRiver", "drmTSwamp", "drmTMountains", "drmTDesert", "drmTCity" },
      "col_comments" = { "the open clear-terrain column - faces 1-3 clear, 4 unusual, 5-6 cloudy, 7 stormy, 8 winds (folio 14)", "the woods column - faces 1-4 clear, 5-6 cloudy, 7-8 stormy (folio 14)", "the river column - faces 1-5 clear, 6-8 stormy (folio 14)", "the swamp column - faces 1-5 clear, 6 unusual, 7-8 stormy (folio 14)", "the mountains column - faces 1-3 clear, 4 unusual, 5-6 cloudy, 7-8 stormy (folio 14)", "the desert column - faces 1-5 clear, 6 stormy, 7-8 winds (folio 14)", "the city column - faces 1-5 clear, 6 stormy, 7-8 unusual (folio 14)" },
      "data" = { { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1 }, { 5, 1, 1, 1, 5, 1, 1 }, { 2, 2, 2, 2, 2, 5, 2 }, { 2, 2, 2, 5, 2, 3, 3 }, { 3, 3, 3, 3, 3, 4, 5 }, { 4, 3, 3, 3, 3, 4, 5 } },
    }, {
      "name" = "drmSeason",
      "tag" = "SS",
      "count" = "drmSeasonRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3 },
      "audit_comment" = "the seasonal weather planner - the pattern length and the die faces per category for each season; the unusual cells of winter, spring and summer print non-contiguous faces and pin sentinel with the faces riding the transcript, the fall column contiguous 1-10 (folio 15, PDF 17)",
      "cols" = { "drmSWeeksMin", "drmSWeeksMax", "drmSClearMin", "drmSClearMax", "drmSCloudyMin", "drmSCloudyMax", "drmSStormyMin", "drmSStormyMax", "drmSWindsMin", "drmSWindsMax", "drmSUnusualMin", "drmSUnusualMax" },
      "col_comments" = { "the weather-pattern length in weeks, lower bound - winter 1-4, spring 1-2, summer 1-6, fall 1-2 (folio 15)", "the weather-pattern length in weeks, upper bound (folio 15)", "the clear faces, lower bound - winter 1-4, spring 2-9, summer 5-10, fall 1-10 (folio 15)", "the clear faces, upper bound (folio 15)", "the cloudy faces, lower bound - 1-10 every season (folio 15)", "the cloudy faces, upper bound (folio 15)", "the stormy faces, lower bound - winter and fall 1-10, spring and summer 2-9 (folio 15)", "the stormy faces, upper bound (folio 15)", "the winds faces, lower bound - 1-10 every season (folio 15)", "the winds faces, upper bound (folio 15)", "the unusual faces, lower bound - sentinel for the three seasons printing non-contiguous faces (winter 1,2,4-9; spring 2,3,5,6,8,9; summer 2,3,5,6,9,10), the faces riding the transcript, never guessed; the fall 1-10 contiguous (folio 15)", "the unusual faces, upper bound - sentinel for the same three seasons (folio 15)" },
      "data" = { { 1, 4, 1, 4, 1, 10, 1, 10, 1, 10, -1, -1 }, { 1, 2, 2, 9, 1, 10, 2, 9, 1, 10, -1, -1 }, { 1, 6, 5, 10, 1, 10, 2, 9, 1, 10, -1, -1 }, { 1, 2, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10 } },
    }, {
      "name" = "drmEvents",
      "tag" = "EV",
      "count" = "drmEventRows",
      "sentinel" = -1,
      "sentinel_census" = { 3, 3, 3, 3, 0, 0, 3, 3 },
      "audit_comment" = "the Crossby random events table for settlements - the sixteen events by season, the 00 faces pinned as 100; the dash cells pin sentinel, never guessed (folio 5, PDF 7)",
      "cols" = { "drmESpringMin", "drmESpringMax", "drmESummerMin", "drmESummerMax", "drmEAutumnMin", "drmEAutumnMax", "drmEWinterMin", "drmEWinterMax" },
      "col_comments" = { "the spring band, lower bound (folio 5)", "the spring band, upper bound (folio 5)", "the summer band, lower bound (folio 5)", "the summer band, upper bound (folio 5)", "the autumn band, lower bound (folio 5)", "the autumn band, upper bound (folio 5)", "the winter band, lower bound - sentinel for the dash cells (folio 5)", "the winter band, upper bound - sentinel for the dash cells (folio 5)" },
      "data" = { { 1, 83, 1, 79, 1, 79, 1, 80 }, { 84, 84, 80, 81, 80, 80, -1, -1 }, { -1, -1, -1, -1, 81, 81, 81, 85 }, { 85, 86, 82, 82, 82, 82, 86, 87 }, { 87, 87, 83, 83, 83, 83, 88, 89 }, { -1, -1, -1, -1, 84, 85, -1, -1 }, { -1, -1, -1, -1, 86, 87, -1, -1 }, { 88, 88, 84, 84, 88, 88, 90, 90 }, { 89, 89, 85, 85, 89, 89, 91, 91 }, { 90, 90, 86, 86, 90, 90, 92, 92 }, { 91, 91, 87, 87, 91, 91, 93, 93 }, { 92, 94, 88, 90, 92, 92, 94, 94 }, { 95, 96, 91, 92, 93, 93, 95, 95 }, { 97, 97, 93, 95, 94, 95, 96, 96 }, { 98, 99, 96, 98, 96, 98, 97, 98 }, { 100, 100, 99, 100, 99, 100, 99, 100 } },
    }, {
      "name" = "drmPitBands",
      "tag" = "PB",
      "count" = "drmPitBandRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0 },
      "audit_comment" = "the main pit table - empty 01-60, occupied 61-95, teleporting 96-98, bottomless 99-00 (folio 5, PDF 7)",
      "cols" = { "drmPBandMin", "drmPBandMax" },
      "col_comments" = { "the pit band lower bound (folio 5)", "the pit band upper bound - empty 01-60, occupied 61-95, teleporting 96-98, bottomless 99-00 (folio 5)" },
      "data" = { { 1, 60 }, { 61, 95 }, { 96, 98 }, { 99, 100 } },
    }, {
      "name" = "drmPitOccupants",
      "tag" = "PO",
      "count" = "drmPitOccupantRows",
      "sentinel" = -1,
      "sentinel_census" = { 1, 0 },
      "audit_comment" = "the occupied-pit table - spikes, animal or insect, teleporting pit, monster, special; the animal lower bound pins sentinel for the shared-35 print, the 40 percent poison asterisk rule pinned as a const (folio 5, PDF 7)",
      "cols" = { "drmPOccMin", "drmPOccMax" },
      "col_comments" = { "the occupied-pit band lower bound - the animal band prints 35-65 sharing the 35 with the spikes band, the lower bound pins sentinel, never guessed (folio 5)", "the occupied-pit band upper bound - spikes 01-35, animal to 65, teleporting 66-70, monster 71-90, special 91-00 (folio 5)" },
      "data" = { { 1, 35 }, { -1, 65 }, { 66, 70 }, { 71, 90 }, { 91, 100 } },
    }, {
      "name" = "drmPitAnimals",
      "tag" = "PA",
      "count" = "drmPitAnimalRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 0 },
      "audit_comment" = "the animal and insect subtable of the occupied pit - six bands, the snakes, lizards and serpents carrying the 40 percent poison asterisk, the centipedes always poisonous (folio 5, PDF 7)",
      "cols" = { "drmPAnimalMin", "drmPAnimalMax" },
      "col_comments" = { "the animal or insect band lower bound (folio 5)", "the animal or insect band upper bound - snakes 01-35, lizards 36-45, giant tick 46-55, giant serpent 56-70, giant weasels 71-85, giant centipedes 86-00 always poisonous (folio 5)" },
      "data" = { { 1, 35 }, { 36, 45 }, { 46, 55 }, { 56, 70 }, { 71, 85 }, { 86, 100 } },
    }, {
      "name" = "drmPitSpecialists",
      "tag" = "PS",
      "count" = "drmPitSpecialistRows",
      "sentinel" = -1,
      "sentinel_census" = { 0, 1 },
      "audit_comment" = "the specialist subtable of the special pit - magic-user, fighter, cleric, thief, alchemist, druid, monk, assassin, ranger, scribe; the ranger upper bound prints the 91-85 garble and pins sentinel, never guessed (folio 5, PDF 7)",
      "cols" = { "drmPSpecMin", "drmPSpecMax" },
      "col_comments" = { "the specialist band lower bound (folio 5)", "the specialist band upper bound - the ranger band prints 91-85, the upper bound pins sentinel, never guessed; the scribe closes 96-00 (folio 5)" },
      "data" = { { 1, 15 }, { 16, 50 }, { 51, 60 }, { 61, 70 }, { 71, 75 }, { 76, 80 }, { 81, 85 }, { 86, 90 }, { 91, -1 }, { 96, 100 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['drmSpellsLevel1']() != 11 or m['drmSpellsLevel2']() != 12 or m['drmSpellsLevel3']() != 13 or m['drmSpellsLevel4']() != 13 or m['drmSpellsLevel5']() != 10 or m['drmSpellsTotal']() != 59 or m['drmPolySelfTrapPercent']() != 2 or m['drmPolyOtherTrapPercent']() != 5 or m['drmSummonStoneChancePerAge']() != 10 or m['drmNameServiceDemands']() != 1",
      "note" = "the dragon magic lists - 11, 12, 13, 13 and 10 spells across the five levels, 59 total, the polymorph entrapment 2 and 5 percent, the summoning stone 10 percent per age, the secret name granting one service (folio 3)",
    }, {
      "expr" = "m['drmServantArmorClass']() != 5 or m['drmServantMoveGroundInches']() != 4 or m['drmServantMoveFlyInches']() != 48 or m['drmServantHpMin']() != 2 or m['drmServantHpMax']() != 12 or m['drmServantBeakDamageMax']() != 6 or m['drmServantEvilOnly']() != 1 or m['drmServantsNeverCrossWater']() != 1 or m['drmMetallicDragonsPolyImmune']() != 1",
      "note" = "the summoning-stone birds - armor class 5, move 4 over ground and 48 aloft, 2-12 hit points, the beak to 6, only evil dragons summoning, never crossing water, the metallic dragons immune to the polymorph entrapment (folio 3)",
    }, {
      "expr" = "m['drmDenseFogVisibilityFeet']() != 30 or m['drmLightFogVisibilityFeet']() != 180 or m['drmHighCloudsVisibilityMiles']() != 20 or m['drmThunderLightningDailyPercent']() != 2 or m['drmThunderUnarmoredDailyPercent']() != 1 or m['drmLightningStunDays']() != 2 or m['drmReptilesImmobileInCold']() != 1 or m['drmWeatherCumulative']() != 1",
      "note" = "the weather ink - the fog visibilities 30 and 180 feet, the high-cloud 20 miles, the thunderstorm lightning 2 percent and 1 percent unarmored, the 2-day stun, the reptile freeze in cold, everything cumulative (folios 14-15)",
    }, {
      "expr" = "m['drmPitPoisonPercent']() != 40 or m['drmSpecialCitizenMax']() != 40 or m['drmSpecialSpecialistMax']() != 80 or m['drmFreedMonsterFriendPercent']() != 50 or m['drmGratitudeDaysMin']() != 2 or m['drmGratitudeDaysMax']() != 20 or m['drmCitizenCareers']() != 12",
      "note" = "the pit ink - the 40 percent poison asterisk, the special bands to 40 and 80, the freed monster 50 percent friendly, the 2-20 day gratitude, the twelve citizen careers (folio 5)",
    } },
  "audit" = {
      "label" = "R927 issue-15 opener audit",
      "comment" = "THE DRAGON ISSUE-15 OPENER ROUND - all five engine-relevant chains in one round. CHAIN ONE, Dragon Magic by Michael Benveniste (folio 3, cont. 13; PDF 5-6, 15): the dragon-only spell system, five lists of 11, 12, 13, 13 and 10 spells, the secret-name rule (one service demand, all works dispelled), the polymorph entrapment at 2 and 5 percent per day cumulative with the metallic dragons immune, the Seek spell at 20 degrees and 20 percent, the summoning-stone birds (armor class 5, move 4 and 48, 2-12 hit points, talons 1-2, beak 1-6, driven off by strong light, never crossing water, evil dragons only). CHAIN TWO, the Wandering Monster by James Ward (folio 7, PDF 9): the pre-rolled twenty-entry fourth-level list, the appearing bands, hit points, armor classes and dungeon move in feet pinned in the table, the damage lines riding the transcript, the will o wisp armor class minus 8 genuine print. CHAIN THREE, Weather in the Wilderness by David Tillery (folios 14-15, PDF 16-17): the terrain matrix, the weather descriptions with their disease and morale percentages, the six-disease table, the seasonal planner. CHAIN FOUR, the Pits tables by Merferger the 11 and 3/4 Lord of Mecic, alias Richard Morenoff (folio 5, PDF 7): the pit bands, the occupied bands, the animal and insect bands, the specialist bands, the 40 percent poison rule. CHAIN FIVE, the Random Events Table for Settlements by N. Robin Crossby (folio 5, PDF 7): the sixteen events by season. No full-res visual check exists for this issue (the scan is a text-side mistral transcript, no page renders), so the garbled cells pin sentinel, never guessed: the occupied-pit animal lower bound (the shared-35 print), the specialist ranger upper bound (the 91-85 print), the seasonal unusual faces of winter, spring and summer (non-contiguous prints riding the transcript); the disease immunity column prints the percent sign before the digits (the percent-position class, the digits clean and pinned).",
    },
}
