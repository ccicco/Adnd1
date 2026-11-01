-- ua364: promoted from the round R364 pin headers (the the UA new illusionist 3rd/4th/5th level spells);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 364,
  "prefix" = "ua364",
  "banner" = {
      "title" = "the UA new illusionist 3rd/4th/5th level spells",
      "provenance" = "rules/uailspells3.h (the The UA NEW ILLUSIONIST SPELLS (pp. 68-69) pins, R364:): the 3rd-level spell descriptions - delude, phantom steed, phantom wind and wraithform.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the delude and wraithform level cells print the clean 3 under the Third Level Spells header - the item list (the R322 index) carries both at 2nd; the print wins (the R363 phantom-armor precedent), the divergence flagged in the round note pending the PDF. - phantom steed and phantom wind appear under the same printed header but nowhere in the item list (its 3rd-level claim says nothing new per the headers) - both pinned as printed; the R342 IL table seam carries a Phantom Wind fragment among its lost-column holes, corroborating the wind. - the wraithform casting cell prints 7 segment - the digit-garble family (the R343 precedent, the R363 chromatic-orb reuse) decodes the 1 segment. - the bare-7 duration cells (phantom wind 7 round/level) and the empty cells (the phantom steed casting time, the saving throw, the phantom wind range) read as holes pending the PDF - no corroborating print exists to decode them, so no numeric pin. - the phantom steed components cell prints V, S with a trailing comma - the tail is lost, a hole; the phantom wind and wraithform section garbles (the section sign for S, the lllusion school tail) decode per the R363 convention. - the R342 IL table seam: the 3rd-level column is wholly lost - none of the new names seam-checks, asserted in the audit.  rules/uailspells4.h (the The UA NEW ILLUSIONIST SPELLS (pp. 69-70) pins,): R364: the 4th-level spell descriptions - dispel magic, rainbow pattern, solid fog and vacancy.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the vacancy level cell prints the clean 4 - it matches the item list; the print sits between a stray 5TH LEVEL header and the Fifth Level Spells header - the level cell wins, the header noise noted. - the solid fog level cell does not print - the level pins from the Fourth Level Spells section header (the R363 read-magic precedent); its area cell prints 2 cubic with the unit lost and its component cell garbles (a peas/hoof fragment pile) - holes pending the PDF. - the dispel magic area cell interleaves with the prose (the 3 inch cube fragments) - the cell decodes from the fragments; the two-levels-below cast read and the clerical cross-reference pin from the prose. - the rainbow pattern casting-time cell prints a bare Casting Time - the value is lost, a hole. - the section sign components cells (dispel magic) decode to the somatic S per the R363 convention. - the bare-7 duration cell (vacancy 7 turn/level) reads as a hole pending the PDF - no corroborating print exists to decode it, so no numeric pin. - the R342 IL table seam: the 4th-level column is wholly lost - none of the new names seam-checks, asserted in the audit.  rules/uailspells5.h (the The UA NEW ILLUSIONIST SPELLS (pp. 70-71) pins,): R364: the 5th-level spell descriptions - the advanced illusion, dream, magic mirror and tempus fugit.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the first name header garbles to a bare (lllusi ) parenthesis fragment - the name pins from the gap item list (the R363 chromatic-orb precedent): advanced illusion; the prose program spell cross-reference garbles and its components (a bit of fleece and several grains of sand) corroborate the identification. - the bare-7 cells (the advanced illusion and magic mirror durations, both 7 round/level; the dream casting time, 7 day) read as holes pending the PDF - the R343 digit-garble precedent decoded only the 7 segment form with its corroborated 1, and no corroborating print exists here, so no numeric pin. - the magic mirror is a cross-reference reprint (virtually the same as the 4th-level magic-user spell); its dollar-sign components cell decodes to V, S, M per the R363 symbol-garble convention. - the tempus fugit area cell prints 7 radius - unlike the per-level duration cells an area radius has no corroborating print either way; pinned as printed, the doubt noted pending the PDF. - the R342 IL table seam: the 5th-level column is wholly lost - none of the new names seam-checks, asserted in the audit.",
    },
  "consts" = { {
      "name" = "uail3DeludeName",
      "value" = "Delude (Alteration)",
      "comment" = "---- delude ---- The components cell prints a bare V with a trailing comma - the tail is lost, a hole pending the PDF.",
    }, {
      "name" = "uail3DeludeLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail3DeludeRangeInches",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uail3DeludeCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail3DeludeDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail3DeludeAuraRadiusInches",
      "value" = 3,
      "comment" = "The aura exchange radius: 3 inches.",
    }, {
      "name" = "uail3SteedName",
      "value" = "Phantom Steed (Conjuration/Phantasm)",
      "comment" = "---- phantom steed ---- The casting-time cell garbles (a bare Casting Tim) and the saving-throw cell prints empty - holes pending the PDF.",
    }, {
      "name" = "uail3SteedLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail3SteedDurationTurnsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail3SteedDamageToDispel",
      "value" = 12,
      "comment" = "More than 12 points of damage dispels the steed.",
    }, {
      "name" = "uail3SteedMaxRateInchesPerLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail3PwindName",
      "value" = "Phantom Wind (Alteration/Phantasm)",
      "comment" = "---- phantom wind ---- The components cell prints V with a section sign - the R363 convention decodes the somatic S; the range cell prints empty and the duration cell prints a bare 7 round/level - holes pending the PDF (no corroborating print exists to decode the 7).",
    }, {
      "name" = "uail3PwindLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail3PwindCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail3PwindAoeInchesBroadPath",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail3PwindPathGrowsInchesPerRound",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail3WraithName",
      "value" = "Wraithform (Alteration/Illusion)",
      "comment" = "---- wraithform ---- The stat tail prints displaced after the prose (the components and casting-time cells follow the description); the school tail garbles (lllusion) and decodes per the R363 convention; the casting cell prints 7 segment - the R343 digit-garble precedent decodes the 1 segment.",
    }, {
      "name" = "uail3WraithLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail3WraithRangeInches",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uail3WraithDurationRoundsPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uail3WraithCastingTimeSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail3WraithLichRecognizeSaveMod",
      "value" = -4,
      "comment" = "The lich save versus spell carries the -4 penalty.",
    }, {
      "name" = "uail4DispelName",
      "value" = "Dispel Magic (Abjuration)",
      "comment" = "---- dispel magic ---- The area cell interleaves with the prose; the fragments (3 inch cube, identical to the 3rd-level clerical spell) decode the cell.",
    }, {
      "name" = "uail4DispelLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail4DispelRangeInches",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uail4DispelAoeInchesCube",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail4DispelCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail4RainbowName",
      "value" = "Rainbow Pattern (Alteration/Phantasm)",
      "comment" = "---- rainbow pattern ---- The casting-time cell prints a bare Casting Time - the value is lost, a hole pending the PDF.",
    }, {
      "name" = "uail4RainbowLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail4RainbowRangeInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail4RainbowAoeInchesSquare",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail4RainbowSpeedInchesPerRound",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail4RainbowPersistsRoundsMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail4RainbowPersistsRoundsMax",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail4RainbowFollowerLevelsOrHdCap",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uail4FogName",
      "value" = "Solid Fog (Alteration)",
      "comment" = "---- solid fog ---- The level cell does not print - the level pins from the Fourth Level Spells section header (the R363 read-magic precedent); the area cell prints 2 cubic with the unit lost and the component cell garbles - holes pending the PDF.",
    }, {
      "name" = "uail4FogLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail4FogDurationRoundsBaseMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uail4FogDurationRoundsBaseMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uail4FogDurationPlusPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail4FogAoeCubicPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uail4FogCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail4FogMoveInchesPerRound",
      "value" = 1,
      "comment" = "Movement through the fog: 1 inch of normal rate per inch of fog per round.",
    }, {
      "name" = "uail4VacancyName",
      "value" = "Vacancy (Alteration/Phantasm)",
      "comment" = "---- vacancy ---- The duration cell prints a bare 7 turn/level - a hole pending the PDF (no corroborating print exists to decode the 7); the area cell interleaves (the 1 inch radius per level fragments).",
    }, {
      "name" = "uail4VacancyLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail4VacancyCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail4VacancyRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail4VacancyAoeRadiusInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail4VacancySilkMinGpValue",
      "value" = 100,
      "comment" = "The material component: a square of finest black silk of not less than 100 gp value.",
    }, {
      "name" = "uail5AdvilName",
      "value" = "Advanced Illusion (Illusion/Phantasm)",
      "comment" = "---- advanced illusion ---- The name header garbles to a bare (lllusi ) fragment - the name pins from the gap item list; the prose cross-reference garbles (the similar-to fragment), a hole pending the PDF.",
    }, {
      "name" = "uail5AdvilLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uail5AdvilCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uail5AdvilRangeInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail5AdvilRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail5AdvilAoeSquares",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail5AdvilAoeSquaresPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail5AdvilConcentrationSegments",
      "value" = 5,
      "comment" = "The caster need only concentrate 5 segments after casting; the program then runs alone.",
    }, {
      "name" = "uail5AdvilCommunicatedDisbeliefBonus",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail5DreamName",
      "value" = "Dream (Alteration - Illusion/Phantasm)",
      "comment" = "---- dream ---- The casting-time cell prints a bare 7 day - a hole pending the PDF (no corroborating print exists to decode the 7).",
    }, {
      "name" = "uail5DreamLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uail5DreamUndisturbedSleepHours",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uail5DreamEffectuatedHoursMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail5DreamEffectuatedHoursMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uail5DreamScriedSaveHdThreshold",
      "value" = 7,
      "comment" = "A scried creature of the printed hit-dice threshold may save; the threshold prints the clean 7 in the prose (unlike the stat-cell garbles), pinned as printed pending the PDF.",
    }, {
      "name" = "uail5DreamCompanionTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail5DreamSecondCastAgesYearsMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail5DreamSecondCastAgesYearsMax",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uail5MirrorName",
      "value" = "Magic Mirror (Enchantment - Divination)",
      "comment" = "---- magic mirror ---- A cross-reference reprint: virtually the same as the 4th-level magic-user spell of the same name; the dollar-sign components cell decodes to V, S, M per the R363 symbol-garble convention; the duration cell prints a bare 7 round/level - a hole pending the PDF.",
    }, {
      "name" = "uail5MirrorLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uail5MirrorCastingTimeHours",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail5TempusName",
      "value" = "Tempus Fugit (Illusion/Phantasm)",
      "comment" = "---- tempus fugit ---- The area cell prints 7 radius - pinned as printed (an area radius has no corroborating print either way), the doubt noted pending the PDF.",
    }, {
      "name" = "uail5TempusLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uail5TempusCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uail5TempusRangeInches",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uail5TempusDurationTurnsPerLevel",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uail5TempusAoeRadiusInches",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uail5TempusReverseLingersTurnsMin",
      "value" = 1,
      "comment" = "Under the reverse the effects last at least 1 turn after the caster desires the dispelling (the slowed-reactions read).",
    } },
  "bools" = { {
      "name" = "uail3DeludeVerbalComponent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeComponentsTailLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeAoeTheIllusionist",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeTargetMustExceedAnimalInt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeTargetRetainsAlignment",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeKnowAlignmentSeesAuraOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeDetectSeesSubstitutedAura",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeCopiedCreatureRadiatesMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeCasterRadiatesToSourceOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeWithChangeOrAlterSelfHides",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3DeludeSaveOnlyOnAuraTransfer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedComponentsVerbalSomatic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedComponentsTailLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedCastingTimeCellGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedSaveCellEmpty",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedQuasiRealHorseLike",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedRiddenOnlyByCasterOrNamed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedBlackHeadsAndBodies",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedGrayManesAndTails",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedSmokeColoredHooves",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedHoovesMakeNoSound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedMilkyEyes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedDoesNotFight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedNormalAnimalsShun",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedOnlyMonstrousAnimalsAttack",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedSeemingSaddleAndBridle",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedCannotCarrySaddlebags",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedPower8thSoftGround",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedPower10thOverWater",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedPower12thAirTravel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedPower12thNoCasualFlight",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3SteedPower14thAsPegasus",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindComponentsVerbalSomatic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindRangeCellEmpty",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindDurationCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindCannotBeSeenOrFelt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindBlowsLightObjects",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindFluttersCurtainsAndDrapes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindFlapsLooseClothing",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindFansFires",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindMovesGaseousClouds",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindMovesInPointedDirection",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindEffectsLastWholePath",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3PwindVesselSentenceGarbled",
      "value" = true,
      "comment" = "The vessel sentence interleaves as fragments (es the one iled to vessels) - a hole pending the PDF.",
    }, {
      "name" = "uail3WraithAoeTheIllusionist",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithComponentsSomaticMaterial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithInsubstantialWithGear",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithHitOnlyByPlusOneOrBetter",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithEtherealAbleCreaturesHit",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithMostUndeadIgnore",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithAppearsAsWraithOrSpectre",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithLichMayRecognize",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithPassesThroughCracksWithGear",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithNoAttacksExceptVsEthereal",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithEtherealCombatNormalBothWays",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithDispelForcesNormalForm",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithReturnAtWillEndsSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail3WraithComponentsGauzeAndSmoke",
      "value" = true,
      "comment" = "The material components: a bit of gauze and a wisp of smoke.",
    }, {
      "name" = "uail4DispelDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4DispelAoeCellInterleaved",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4DispelComponentsVerbalSomatic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4DispelSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4DispelSameAsClericalThirdLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4DispelCastsTwoLevelsBelow",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4DispelExampleNinthCastsAsSeventh",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowComponentsSomaticMaterial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowCastingTimeCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowPastelGlowingBand",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowSameEffectAsHypnoticPattern",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowMovesInGesturedDirection",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowDangerAllowsSecondSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowBlockedViewNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowObscurementExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4RainbowComponentsPrismPhosphor",
      "value" = true,
      "comment" = "The material components: a crystal prism and a piece of phosphor.",
    }, {
      "name" = "uail4FogLevelCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogAoeUnitCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogRollingBillowingWallOfFog",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogOnlyVeryStrongWindMoves",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogGustOfWindCannotAffect",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogFireballBurnsAwayOneRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogFlameStrikeBurnsAway",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogWallOfFireBurnsAway",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4FogComponentCellGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancySaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyDurationCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyAreaSeemsVacantNeglected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyDustCobwebsDirtTypical",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyPassageSeemsToLeaveTracks",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyPassageTearsCobwebs",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyOnlyForcefulContactDisturbs",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyCloaksOnlyNonLivingThings",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyLivingThingsNotInvisible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyForcefulContactGrantsSaves",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyFailedSaveBelievesInvisible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyDispelRemovesDweomer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyTrueSeeingPenetrates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyGemOfSeeingPenetrates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail4VacancyDetectInvisibilityCannot",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilNameHeaderGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilDurationCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilAoeCellInterleaved",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilProgramSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilCrossRefCellGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilProgramRunsAlone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilVisualComponent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilFullAudialComponent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilOlfactoryComponent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilThermalComponent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilActiveDisbelieveGrantsSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5AdvilComponentsFleeceAndSand",
      "value" = true,
      "comment" = "The material components: a bit of fleece and several grains of sand - they corroborate the name decode.",
    }, {
      "name" = "uail5DreamRangeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamComponentsSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamCastingTimeCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamLimitedWishForm",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamMoreLimitedScope",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamMustLieProneAndSleep",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamResultRecoverLostHp",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamResultRestoreBodyMember",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamResultLocateUnguardedObject",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamResultDiscoverIngressEgress",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamResultSafeWildernessPath",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamResultImproveTreasureChances",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamScriedSaveHidesFromDream",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamScriedMaySenseCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamResultsStrictlyLimited",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamNeverExceedsOnPermanentBasis",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamUnaffectedByExtensionOrPermanency",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamOncePerWeek",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5DreamSecondCastInWeekFails",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorDurationCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorSameAsFourthLevelMuSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorSameMaterialComponents",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorVisionSpellReplacesComponents",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorStillScrysWithVision",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5MirrorVisionDoesNotFunctionNormally",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusComponentsVerbalSomatic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusAffectsMindsAndBodies",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusLatecomersAlsoAffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusTurnSeemsLikeAnHour",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusFunctionsSpedUp",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusOtherSpellDurationsSped",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusOneHourIsAsSix",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusFourHoursAFullDay",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusAllowsRestRenewalRecovery",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusReversalSlowsTime",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusReverseHourSeemsATurn",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusReverseDayMereFourHours",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusReversalNeedsNoPreparation",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusCasterAlsoAffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail5TempusReverseLingersBySlowReactions",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uail3DeludeName'](), \"Delude (Alteration)\") != 0  or  m['uail3DeludeVerbalComponent']() != 1  or  m['uail3DeludeComponentsTailLost']() != 1  or m['uail3DeludeLevel']() != 3  or m['uail3DeludeRangeInches']() != 0  or m['uail3DeludeCastingTimeSegments']() != 3  or  m['uail3DeludeSaveNegates']() != 1  or m['uail3DeludeDurationTurnsPerLevel']() != 1  or  m['uail3DeludeAoeTheIllusionist']() != 1  or m['uail3DeludeAuraRadiusInches']() != 3  or  m['uail3DeludeTargetMustExceedAnimalInt']() != 1  or  m['uail3DeludeTargetRetainsAlignment']() != 1  or  m['uail3DeludeKnowAlignmentSeesAuraOnly']() != 1  or  m['uail3DeludeDetectSeesSubstitutedAura']() != 1  or  m['uail3DeludeCopiedCreatureRadiatesMagic']() != 1  or  m['uail3DeludeCasterRadiatesToSourceOnly']() != 1  or  m['uail3DeludeWithChangeOrAlterSelfHides']() != 1  or  m['uail3DeludeSaveOnlyOnAuraTransfer']() != 1  or strcmp(m['uail3SteedName'](), \"Phantom Steed (Conjuration/Phantasm)\") != 0  or m['uail3SteedLevel']() != 3  or  m['uail3SteedComponentsVerbalSomatic']() != 1  or  m['uail3SteedComponentsTailLost']() != 1  or  m['uail3SteedRangeTouch']() != 1  or  m['uail3SteedCastingTimeCellGarbled']() != 1  or m['uail3SteedDurationTurnsPerLevel']() != 6  or  m['uail3SteedSaveCellEmpty']() != 1  or  m['uail3SteedAoeSpecial']() != 1  or  m['uail3SteedQuasiRealHorseLike']() != 1  or  m['uail3SteedRiddenOnlyByCasterOrNamed']() != 1  or  m['uail3SteedBlackHeadsAndBodies']() != 1  or  m['uail3SteedGrayManesAndTails']() != 1  or  m['uail3SteedSmokeColoredHooves']() != 1  or  m['uail3SteedHoovesMakeNoSound']() != 1  or  m['uail3SteedMilkyEyes']() != 1  or  m['uail3SteedDoesNotFight']() != 1  or  m['uail3SteedNormalAnimalsShun']() != 1  or  m['uail3SteedOnlyMonstrousAnimalsAttack']() != 1  or m['uail3SteedDamageToDispel']() != 12  or m['uail3SteedMaxRateInchesPerLevel']() != 4  or  m['uail3SteedSeemingSaddleAndBridle']() != 1  or  m['uail3SteedCannotCarrySaddlebags']() != 1  or  m['uail3SteedPower8thSoftGround']() != 1  or  m['uail3SteedPower10thOverWater']() != 1  or  m['uail3SteedPower12thAirTravel']() != 1  or  m['uail3SteedPower12thNoCasualFlight']() != 1  or  m['uail3SteedPower14thAsPegasus']() != 1  or strcmp(m['uail3PwindName'](), \"Phantom Wind (Alteration/Phantasm)\") != 0  or m['uail3PwindLevel']() != 3  or  m['uail3PwindComponentsVerbalSomatic']() != 1  or m['uail3PwindCastingTimeSegments']() != 3  or  m['uail3PwindRangeCellEmpty']() != 1  or  m['uail3PwindSaveNone']() != 1  or  m['uail3PwindDurationCellSuspectGarble']() != 1  or m['uail3PwindAoeInchesBroadPath']() != 1  or  m['uail3PwindCannotBeSeenOrFelt']() != 1  or  m['uail3PwindBlowsLightObjects']() != 1  or  m['uail3PwindFluttersCurtainsAndDrapes']() != 1  or  m['uail3PwindFlapsLooseClothing']() != 1  or  m['uail3PwindFansFires']() != 1  or  m['uail3PwindMovesGaseousClouds']() != 1  or  m['uail3PwindMovesInPointedDirection']() != 1  or m['uail3PwindPathGrowsInchesPerRound']() != 1  or  m['uail3PwindEffectsLastWholePath']() != 1  or  m['uail3PwindVesselSentenceGarbled']() != 1  or strcmp(m['uail3WraithName'](), \"Wraithform (Alteration/Illusion)\") != 0  or m['uail3WraithLevel']() != 3  or m['uail3WraithRangeInches']() != 0  or m['uail3WraithDurationRoundsPerLevel']() != 2  or  m['uail3WraithAoeTheIllusionist']() != 1  or  m['uail3WraithComponentsSomaticMaterial']() != 1  or m['uail3WraithCastingTimeSegments']() != 1  or  m['uail3WraithSaveNone']() != 1  or  m['uail3WraithInsubstantialWithGear']() != 1  or  m['uail3WraithHitOnlyByPlusOneOrBetter']() != 1  or  m['uail3WraithEtherealAbleCreaturesHit']() != 1  or  m['uail3WraithMostUndeadIgnore']() != 1  or  m['uail3WraithAppearsAsWraithOrSpectre']() != 1  or  m['uail3WraithLichMayRecognize']() != 1  or m['uail3WraithLichRecognizeSaveMod']() != -4  or  m['uail3WraithPassesThroughCracksWithGear']() != 1  or  m['uail3WraithNoAttacksExceptVsEthereal']() != 1  or  m['uail3WraithEtherealCombatNormalBothWays']() != 1  or  m['uail3WraithDispelForcesNormalForm']() != 1  or  m['uail3WraithReturnAtWillEndsSpell']() != 1  or  m['uail3WraithComponentsGauzeAndSmoke']() != 1",
      "note" = "---- delude ---- ---- phantom steed ---- ---- phantom wind ---- ---- wraithform ----",
    }, {
      "expr" = "strcmp(m['uail4DispelName'](), \"Dispel Magic (Abjuration)\") != 0  or m['uail4DispelLevel']() != 4  or m['uail4DispelRangeInches']() != 9  or  m['uail4DispelDurationPermanent']() != 1  or m['uail4DispelAoeInchesCube']() != 3  or  m['uail4DispelAoeCellInterleaved']() != 1  or  m['uail4DispelComponentsVerbalSomatic']() != 1  or m['uail4DispelCastingTimeSegments']() != 4  or  m['uail4DispelSaveNone']() != 1  or  m['uail4DispelSameAsClericalThirdLevel']() != 1  or  m['uail4DispelCastsTwoLevelsBelow']() != 1  or  m['uail4DispelExampleNinthCastsAsSeventh']() != 1  or strcmp(m['uail4RainbowName'](), \"Rainbow Pattern (Alteration/Phantasm)\") != 0  or m['uail4RainbowLevel']() != 4  or  m['uail4RainbowComponentsSomaticMaterial']() != 1  or  m['uail4RainbowCastingTimeCellLost']() != 1  or m['uail4RainbowRangeInches']() != 1  or  m['uail4RainbowSaveNegates']() != 1  or  m['uail4RainbowDurationSpecial']() != 1  or m['uail4RainbowAoeInchesSquare']() != 3  or  m['uail4RainbowPastelGlowingBand']() != 1  or  m['uail4RainbowSameEffectAsHypnoticPattern']() != 1  or  m['uail4RainbowMovesInGesturedDirection']() != 1  or m['uail4RainbowSpeedInchesPerRound']() != 3  or m['uail4RainbowPersistsRoundsMin']() != 1  or m['uail4RainbowPersistsRoundsMax']() != 3  or m['uail4RainbowFollowerLevelsOrHdCap']() != 24  or  m['uail4RainbowDangerAllowsSecondSave']() != 1  or  m['uail4RainbowBlockedViewNegates']() != 1  or  m['uail4RainbowObscurementExample']() != 1  or  m['uail4RainbowComponentsPrismPhosphor']() != 1  or strcmp(m['uail4FogName'](), \"Solid Fog (Alteration)\") != 0  or m['uail4FogLevel']() != 4  or  m['uail4FogLevelCellLost']() != 1  or m['uail4FogDurationRoundsBaseMin']() != 2  or m['uail4FogDurationRoundsBaseMax']() != 8  or m['uail4FogDurationPlusPerLevel']() != 1  or m['uail4FogAoeCubicPerLevel']() != 2  or  m['uail4FogAoeUnitCellLost']() != 1  or  m['uail4FogComponentsVSM']() != 1  or m['uail4FogCastingTimeSegments']() != 4  or  m['uail4FogSaveNone']() != 1  or  m['uail4FogRollingBillowingWallOfFog']() != 1  or  m['uail4FogOnlyVeryStrongWindMoves']() != 1  or  m['uail4FogGustOfWindCannotAffect']() != 1  or m['uail4FogMoveInchesPerRound']() != 1  or  m['uail4FogFireballBurnsAwayOneRound']() != 1  or  m['uail4FogFlameStrikeBurnsAway']() != 1  or  m['uail4FogWallOfFireBurnsAway']() != 1  or  m['uail4FogComponentCellGarbled']() != 1  or strcmp(m['uail4VacancyName'](), \"Vacancy (Alteration/Phantasm)\") != 0  or m['uail4VacancyLevel']() != 4  or  m['uail4VacancyComponentsVSM']() != 1  or m['uail4VacancyCastingTimeSegments']() != 4  or m['uail4VacancyRangeInchesPerLevel']() != 1  or  m['uail4VacancySaveNone']() != 1  or  m['uail4VacancyDurationCellSuspectGarble']() != 1  or m['uail4VacancyAoeRadiusInchesPerLevel']() != 1  or  m['uail4VacancyAreaSeemsVacantNeglected']() != 1  or  m['uail4VacancyDustCobwebsDirtTypical']() != 1  or  m['uail4VacancyPassageSeemsToLeaveTracks']() != 1  or  m['uail4VacancyPassageTearsCobwebs']() != 1  or  m['uail4VacancyOnlyForcefulContactDisturbs']() != 1  or  m['uail4VacancyCloaksOnlyNonLivingThings']() != 1  or  m['uail4VacancyLivingThingsNotInvisible']() != 1  or  m['uail4VacancyForcefulContactGrantsSaves']() != 1  or  m['uail4VacancyFailedSaveBelievesInvisible']() != 1  or  m['uail4VacancyDispelRemovesDweomer']() != 1  or  m['uail4VacancyTrueSeeingPenetrates']() != 1  or  m['uail4VacancyGemOfSeeingPenetrates']() != 1  or  m['uail4VacancyDetectInvisibilityCannot']() != 1  or m['uail4VacancySilkMinGpValue']() != 100",
      "note" = "---- dispel magic ---- ---- rainbow pattern ---- ---- solid fog ---- ---- vacancy ----",
    }, {
      "expr" = "strcmp(m['uail5AdvilName'](), \"Advanced Illusion (Illusion/Phantasm)\") != 0  or  m['uail5AdvilNameHeaderGarbled']() != 1  or m['uail5AdvilLevel']() != 5  or  m['uail5AdvilComponentsVSM']() != 1  or m['uail5AdvilCastingTimeSegments']() != 5  or m['uail5AdvilRangeInches']() != 6  or m['uail5AdvilRangeInchesPerLevel']() != 1  or  m['uail5AdvilSaveSpecial']() != 1  or  m['uail5AdvilDurationCellSuspectGarble']() != 1  or m['uail5AdvilAoeSquares']() != 4  or m['uail5AdvilAoeSquaresPerLevel']() != 1  or  m['uail5AdvilAoeCellInterleaved']() != 1  or  m['uail5AdvilProgramSpell']() != 1  or  m['uail5AdvilCrossRefCellGarbled']() != 1  or m['uail5AdvilConcentrationSegments']() != 5  or  m['uail5AdvilProgramRunsAlone']() != 1  or  m['uail5AdvilVisualComponent']() != 1  or  m['uail5AdvilFullAudialComponent']() != 1  or  m['uail5AdvilOlfactoryComponent']() != 1  or  m['uail5AdvilThermalComponent']() != 1  or  m['uail5AdvilActiveDisbelieveGrantsSave']() != 1  or m['uail5AdvilCommunicatedDisbeliefBonus']() != 4  or  m['uail5AdvilComponentsFleeceAndSand']() != 1  or strcmp(m['uail5DreamName'](), \"Dream (Alteration - Illusion/Phantasm)\") != 0  or m['uail5DreamLevel']() != 5  or  m['uail5DreamRangeSpecial']() != 1  or  m['uail5DreamDurationSpecial']() != 1  or  m['uail5DreamAoeSpecial']() != 1  or  m['uail5DreamComponentsSpecial']() != 1  or  m['uail5DreamCastingTimeCellSuspectGarble']() != 1  or  m['uail5DreamSaveNegates']() != 1  or  m['uail5DreamLimitedWishForm']() != 1  or  m['uail5DreamMoreLimitedScope']() != 1  or  m['uail5DreamMustLieProneAndSleep']() != 1  or m['uail5DreamUndisturbedSleepHours']() != 8  or m['uail5DreamEffectuatedHoursMin']() != 1  or m['uail5DreamEffectuatedHoursMax']() != 12  or  m['uail5DreamResultRecoverLostHp']() != 1  or  m['uail5DreamResultRestoreBodyMember']() != 1  or  m['uail5DreamResultLocateUnguardedObject']() != 1  or  m['uail5DreamResultDiscoverIngressEgress']() != 1  or  m['uail5DreamResultSafeWildernessPath']() != 1  or  m['uail5DreamResultImproveTreasureChances']() != 1  or m['uail5DreamScriedSaveHdThreshold']() != 7  or  m['uail5DreamScriedSaveHidesFromDream']() != 1  or  m['uail5DreamScriedMaySenseCaster']() != 1  or  m['uail5DreamResultsStrictlyLimited']() != 1  or  m['uail5DreamNeverExceedsOnPermanentBasis']() != 1  or m['uail5DreamCompanionTurnsPerLevel']() != 1  or  m['uail5DreamUnaffectedByExtensionOrPermanency']() != 1  or  m['uail5DreamOncePerWeek']() != 1  or  m['uail5DreamSecondCastInWeekFails']() != 1  or m['uail5DreamSecondCastAgesYearsMin']() != 1  or m['uail5DreamSecondCastAgesYearsMax']() != 10  or strcmp(m['uail5MirrorName'](), \"Magic Mirror (Enchantment - Divination)\") != 0  or m['uail5MirrorLevel']() != 5  or  m['uail5MirrorComponentsVSM']() != 1  or m['uail5MirrorCastingTimeHours']() != 1  or  m['uail5MirrorRangeTouch']() != 1  or  m['uail5MirrorSaveNone']() != 1  or  m['uail5MirrorDurationCellSuspectGarble']() != 1  or  m['uail5MirrorAoeSpecial']() != 1  or  m['uail5MirrorSameAsFourthLevelMuSpell']() != 1  or  m['uail5MirrorSameMaterialComponents']() != 1  or  m['uail5MirrorVisionSpellReplacesComponents']() != 1  or  m['uail5MirrorStillScrysWithVision']() != 1  or  m['uail5MirrorVisionDoesNotFunctionNormally']() != 1  or strcmp(m['uail5TempusName'](), \"Tempus Fugit (Illusion/Phantasm)\") != 0  or  m['uail5TempusReversible']() != 1  or m['uail5TempusLevel']() != 5  or  m['uail5TempusComponentsVerbalSomatic']() != 1  or m['uail5TempusCastingTimeSegments']() != 5  or m['uail5TempusRangeInches']() != 0  or  m['uail5TempusSaveNone']() != 1  or m['uail5TempusDurationTurnsPerLevel']() != 5  or m['uail5TempusAoeRadiusInches']() != 7  or  m['uail5TempusAffectsMindsAndBodies']() != 1  or  m['uail5TempusLatecomersAlsoAffected']() != 1  or  m['uail5TempusTurnSeemsLikeAnHour']() != 1  or  m['uail5TempusFunctionsSpedUp']() != 1  or  m['uail5TempusOtherSpellDurationsSped']() != 1  or  m['uail5TempusOneHourIsAsSix']() != 1  or  m['uail5TempusFourHoursAFullDay']() != 1  or  m['uail5TempusAllowsRestRenewalRecovery']() != 1  or  m['uail5TempusReversalSlowsTime']() != 1  or  m['uail5TempusReverseHourSeemsATurn']() != 1  or  m['uail5TempusReverseDayMereFourHours']() != 1  or  m['uail5TempusReversalNeedsNoPreparation']() != 1  or  m['uail5TempusCasterAlsoAffected']() != 1  or m['uail5TempusReverseLingersTurnsMin']() != 1  or  m['uail5TempusReverseLingersBySlowReactions']() != 1",
      "note" = "---- advanced illusion ---- ---- dream ---- ---- magic mirror ---- ---- tempus fugit ----",
    }, {
      "expr" = "m['uas2Il1stCount']() != 5  or m['uas2Il2ndCount']() != 4  or m['uas2Il7thCount']() != 1  or strcmp(m['uas2Il7thName'](0), \"Shadow Walk\") != 0  or m['uas2IlCantripCount']() != 8",
      "note" = "the R342 IL table seam: the 3rd through 6th columns are wholly lost; the readable columns still print only PHB names, and the lost-column Phantom Wind fragment corroborates the wind pin",
    }, {
      "expr" = "strcmp(m['uas2Il7thName'](0), nn[n]) == 0",
      "note" = "none of the new illusionist names seam-checks in the readable columns",
    } },
  "audit" = {
      "label" = "R364: the UA new illusionist 3rd/4th/5th level spells pin audit",
      "comment" = "The UA NEW ILLUSIONIST SPELLS (pp. 68-71) - the 3rd-level four (delude with the aura exchange, the phantom steed with the level-power ladder, the phantom wind and wraithform with the casting-time decode); the 4th- level four (dispel magic with the two-levels-below read, rainbow pattern with the follower cap, solid fog, vacancy); the 5th- level four (the advanced illusion named from the item list, dream with the once-per-week aging tail, the magic mirror reprint, tempus fugit reversible). The R342 IL table 3rd-6th columns are wholly lost - none of the new names seam-checks. The item stays open - the 6th and 7th levels pin in the next round.",
    },
}
