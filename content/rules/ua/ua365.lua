-- ua365: promoted from the round R365 pin headers (the the UA new illusionist 6th/7th spells, acquisition and cost);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 365,
  "prefix" = "ua365",
  "banner" = {
      "title" = "the UA new illusionist 6th/7th spells, acquisition and cost",
      "provenance" = "rules/ua/uailacquisition.h (the The UA ILLUSIONIST SPELL ACQUISITION (pp. 33-34): players extract, p. 80 print) pins, R365: the starting-list table, the illusionist spell book differences and the illusionist cantrip counts.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - R393 (the clean PDF read, p. 80): the starting-list table decodes column-wise in full - three columns, six rows each; the R365 interleave decode corrects (Darkness defensive row 2, Phantom Armor defensive row 5, Chromatic Orb plain, Spook offensive row 6); the (choose) markers read as the defensive row 6 and the misc rows 5-6, the asterisk on the misc row 6. - the chromatic orb row prints plain (the R365 (choose) read corrects) and the UA-addition note prints clean (spells from this work were added to the initial lists for illusionists only, not for magic-users). - the book-difference list prints clean (the 24/16/8 standard capacities, the 6/4/2 travelling capacities, the separate book for magic-user 1st-level spells). - the illusionist cantrip counts print with one category tail garbled (the personal 2-5 cell) - pinned per the fragments.  rules/ua/uailspells6.h (the The UA NEW ILLUSIONIST SPELLS (pp. 71-72) pins,): R365: the 6th-level spell descriptions - death fog, mislead, phantasmagoria and the mirage arcane (printed at the 6th cell).  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the mirage arcane level cell prints the clean 6 under the ILLUSIONIST SPELLS (7TH LEVEL) header - the item list (the R322 index) names it at 7th; the print wins (the R363 phantom-armor precedent), the divergence flagged in the round note pending the PDF; the R342 IL table seam corroborates the print - the readable 7th column carries only Shadow Walk. - the phantasmagoria level cell does not print - the level pins from the Sixth Level Spells section header (the R364 solid-fog precedent). - the suspect cells read as holes pending the PDF, no numeric pin: the death fog duration (7-4 rounds + 1/level - the solid-fog parallel prints 2-8, no decode exists), the mislead range (a bare 7), the phantasmagoria duration (a bare 7) and its area cell (4 square + 1 square with the units lost). - the mirage arcane casting time prints the clean 3 or 6 segments - both forms pin, corroborated by the prose (the basic form 3, the complex material-component form 6). - the R342 IL table seam: the 6th-level column is wholly lost - none of the new names seam-checks, asserted in the audit.  rules/ua/uailspells7.h (the The UA NEW ILLUSIONIST SPELLS (pp. 72-73) pins,): R365: the 7th-level spell descriptions - shadow walk and weird.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the shadow walk components cell garbles (a dollar sign) - the symbol does not decode (the R364 magic-mirror S$ cell carried its S; a bare $ is ambiguous), a hole pending the PDF; the school tail garbles (lllusion) and decodes per the R363 convention. - the shadow walk casting cell prints 7 segment - the digit-garble family (the R343 precedent) decodes the 1 segment; the weird casting cell prints 7 segments (the plural) and pins clean at 7. - the weird description is largely OCR-lost - the interleaved mirage arcane tail (the mind of the beholder sentence) belongs to the mirage arcane pin, not the weird; only the stat block and a caster-must fragment pin, the prose hole documented. - the R342 IL table seam: the readable 7th column prints only Shadow Walk (asserted); the 7th names beyond it are lost-column.  rules/ua/uaspellcost.h (the The UA COST OF MAGIC-USER/ILLUSIONIST SPELL): CASTING (p. 81 print) pins, R365.  Pin-era pattern (R322): pinned data only - no engine site exists. The section prose prints clean; the one interleaved fragment (the danger clause) is noted in-header.",
    },
  "consts" = { {
      "name" = "uailaOffensiveRowCount",
      "value" = 6,
      "comment" = "The R393 clean read (p. 80): the starting list decodes column-wise, three columns with six rows each. Offensive: 1 - color spray; 2 - hypnotism; 3 - light; 4 - phantasmal force; 5 - chromatic orb (plain); 6 - spook. Defensive: 1 - audible glamer; 2 - darkness; 3 - gaze reflection; 4 - wall of fog; 5 - phantom armor; 6 - (choose). Misc: 1 - change self; 2 - dancing lights; 3 - detect illusion; 4 - detect invisibility; 5 - (choose); 6 - (choose)*.",
    }, {
      "name" = "uailaDefensiveRowCount",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uailaMiscRowCount",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uailaDmOptionCount",
      "value" = 3,
      "comment" = "The DM three-options note for the asterisked choose: a 5th miscellaneous spell, a player re-selection of an offensive spell, or the roll read as a miscellaneous choice.",
    }, {
      "name" = "uailaStandardBookLowLevelSpells",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uailaStandardBookMidLevelSpells",
      "value" = 16,
      "comment" = "",
    }, {
      "name" = "uailaStandardBookHighLevelSpells",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uailaMuFirstLevelBookCapacity",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uailaTravellingBookLowLevelSpells",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uailaTravellingBookMidLevelSpells",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uailaTravellingBookHighLevelSpells",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uailaMinorIllusionCantripsMin",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uailaMinorIllusionCantripsMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uailaUsefulCapIntMinus",
      "value" = 3,
      "comment" = "The useful-category cap: one per point of intelligence minus 3 - an 18-intelligence illusionist chooses 15.",
    }, {
      "name" = "uailaUsefulCapAtInt18",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uailaReversedKnownMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uailaReversedKnownMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uailaLegerdemainKnownMin",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uailaLegerdemainKnownMax",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uailaPersonAffectingKnownMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uailaPersonAffectingKnownMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uailaPersonalKnownMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uailaPersonalKnownMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uailaHauntingSoundKnownMin",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uailaHauntingSoundKnownMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uail6DfogName",
      "value" = "Death Fog (Alteration - Evocation)",
      "comment" = "---- death fog ----",
    }, {
      "name" = "uail6DfogLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6DfogCastingTimeSegments",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6DfogRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail6DfogAoeCubicPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uail6DfogPlantsDieInRounds",
      "value" = 2,
      "comment" = "Plants exposed to the vapors die in 2 rounds.",
    }, {
      "name" = "uail6DfogBushesShrubsDieInRounds",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail6DfogSmallTreesDieInRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uail6DfogLargeTreesDieInRounds",
      "value" = 16,
      "comment" = "",
    }, {
      "name" = "uail6DfogDamageRound1",
      "value" = 1,
      "comment" = "The acid damage ladder by exposure round: 1, 2, 4, then 8 points every succeeding round.",
    }, {
      "name" = "uail6DfogDamageRound2",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uail6DfogDamageRound3",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uail6DfogDamageRound4On",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uail6MisleadName",
      "value" = "Mislead (Illusion/Phantasm)",
      "comment" = "---- mislead ---- The range cell prints a bare 7 - a hole pending the PDF (no corroborating print exists to decode it).",
    }, {
      "name" = "uail6MisleadLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6MisleadCastingTimeSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail6MisleadDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail6PhantName",
      "value" = "Phantasmagoria (Illusion/Phantasm)",
      "comment" = "---- phantasmagoria ---- The level cell does not print - the level pins from the Sixth Level Spells section header (the R364 solid-fog precedent); the duration prints a bare 7 round/level and the area cell garbles (4 square + 1 square with the units lost) - holes pending the PDF.",
    }, {
      "name" = "uail6PhantLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6PhantCastingTimeSegments",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6MirageName",
      "value" = "Mirage Arcane (Illusion/Phantasm - Alteration)",
      "comment" = "---- mirage arcane ---- The level cell prints the clean 6 under the 7TH LEVEL header - the item list names it at 7th; the print wins, the divergence flagged in the round note pending the PDF.",
    }, {
      "name" = "uail6MirageLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6MirageRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail6MirageCastingTimeBasicSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail6MirageCastingTimeComplexSegments",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6MirageAoeRadiusInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail6MiragePersistsBaseTurns",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail6MiragePersistsTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail7ShadowName",
      "value" = "Shadow Walk (Illusion - Enchantment)",
      "comment" = "---- shadow walk ----",
    }, {
      "name" = "uail7ShadowLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uail7ShadowCastingTimeSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uail7ShadowDurationTurnsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uail7ShadowLeaguesPerTurn",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uail7WeirdName",
      "value" = "Weird (Evocation - Illusion/Phantasm)",
      "comment" = "---- weird ---- The description is largely OCR-lost - the interleaved belief-effect prose belongs to the mirage arcane pin; only the stat block and a caster-must fragment print for the weird.",
    }, {
      "name" = "uail7WeirdLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uail7WeirdCastingTimeSegments",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uail7WeirdRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uail7WeirdAoeRadiusInches",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uascFeePerSpellLevelGp",
      "value" = 200,
      "comment" = "---- the basic fee ----",
    }, {
      "name" = "uascOrdinarySurchargePercent",
      "value" = 10,
      "comment" = "---- the surcharges ---- Failing to furnish ordinary material components brings a surcharge of 10 percent or three times the component value, whichever is greater.",
    }, {
      "name" = "uascOrdinarySurchargeValueMultiple",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uascExtraordinarySurchargePercent",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uascExtraordinaryValueMultiple",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uascElfExampleAgingYears",
      "value" = 5,
      "comment" = "The printed example: a young elf unconcerned about aging 5 years, though a fee of ten times normal might be charged.",
    }, {
      "name" = "uascElfExampleFeeMultiple",
      "value" = 10,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uailaThreeGroupsOneEach",
      "value" = true,
      "comment" = "---- the starting list ----",
    }, {
      "name" = "uailaAlwaysKnowsReadIllusionistMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaOffRow1ColorSpray",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaOffRow2Hypnotism",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaOffRow3Light",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaOffRow4PhantasmalForce",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaOffRow5ChromaticOrb",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaChromaticOrbPrintsPlain",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaOffRow6Spook",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaDefRow1AudibleGlamer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaDefRow2Darkness",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaDefRow3GazeReflection",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaDefRow4WallOfFog",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaDefRow5PhantomArmor",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaDefRow6IsChoose",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaMiscRow1ChangeSelf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaMiscRow2DancingLights",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaMiscRow3DetectIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaMiscRow4DetectInvisibility",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaMiscRow5IsChoose",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaMiscRow6IsChooseAsterisk",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaColumnsDecodeColumnWise",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaUaSpellsAddedForIllusionistsOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaNotDoneForMagicUsers",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaBooksSameAsMuWithExceptions",
      "value" = true,
      "comment" = "---- the illusionist spell book differences ----",
    }, {
      "name" = "uailaMuFirstLevelNeedsNewBook",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaScriptReadableByIllusionistsOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaCrossClassBookBan",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaNamesakeSpellsTriggerDifferently",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaHasAllMuCantrips",
      "value" = true,
      "comment" = "---- the illusionist cantrip counts ----",
    }, {
      "name" = "uailaMinorIllusionNotAvailableToMu",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uailaMuCantripPropertiesOtherwiseApply",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogDurationCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogAoeUnitCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogCreatesSolidFogArea",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogHighlyAcidic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogVaporsDeadlyToVegetation",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogAnimalsNotImmuneSuffer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogOtherwiseSameAsSolidFog",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogComponentsPeasHoofAcid",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6DfogAcidIncludesVinegarCrystals",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadSomaticOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadRangeCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadCreatesPhantasmalDouble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadCloakedByImprovedInvis",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadCasterFreeToGoElsewhere",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadPhantasmSeeminglyMovesAway",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadPhantasmSpeaksAndGestures",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadSensorySentenceGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadTrueSightRevealsIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadGemOfSeeingRevealsIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadDetectInvisDetectsCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadTrueSightDetectsCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadTrueSeeingDetectsCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadRobeOfEyesDetectsCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MisleadShadowDoorCrossRef",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantLevelCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantComponentsVerbalSomatic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantDurationCellSuspectGarble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantAoeCellGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantSpecialFormOfSpectralForces",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantTriggeredBySpecialAction",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantFullVisualAudialOlfactoryTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantFallingSlidingMovingRapidly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantTriggerOnPitFallOrDoorOpen",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantMustInvolveFallingRushing",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantDwindlingPerspectiveRead",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6PhantUnlikeProgrammedIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageLevelDivergenceFlagged",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageComponentsVSOptionalM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageSimilarToVacancyButStronger",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageSimilarToMirageCantrip",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageAreaAppearsOtherThanItIs",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageEnvisionedByCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageHeldByFaintConcentration",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageConcentrationOkInConversation",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageConcentrationNotInCombat",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageMustBePersonallySeen",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageMaterialBitGrantsReality",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageBasicForcefulContactNeeded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageComplexDetectionOnlyMagical",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageSubjectToDispelIllusionOrMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageMindCausesBodyEffects",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageBeliefCannotAffectLawsOfNature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageHotCoalsExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageImaginaryFoodNourishes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageFeatherbedExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageGravityUnaffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageEnvisionedBridgeWillNotHold",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageWitnessesSeeDisappearance",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail6MirageDisappearanceNotLinkedToIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowComponentsCellGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowRequiresHeavyShadows",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowEdgeOfPrimeMaterial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowAwareOfPrimePosition",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowRapidTravelByStepping",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowDestinationControlled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowOtherPlanesPerilousTransit",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowTouchedAlsoTransition",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowMayFollowWanderOrStumble",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowLostOrAbandonedFiftyFifty",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7ShadowUnwillingSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7WeirdComponentsVerbalSomatic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7WeirdSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7WeirdDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7WeirdProseLargelyLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uail7WeirdCasterMustFragmentPrints",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascWillingCasterWorksForFee",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascMaterialComponentsDoubled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascComponentSubstitutionsAllowed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascSurchargeWhicheverIsGreater",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascDangerSpellsAtLeastDoubleFee",
      "value" = true,
      "comment" = "---- the danger and aging clauses ----",
    }, {
      "name" = "uascDangerGuaranteesRequired",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascDangerClauseInterleaved",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascAgingSpellsNeedCounterFirst",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascInsignificantAgingException",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascMagicItemAcceptedInLieuOfCash",
      "value" = true,
      "comment" = "---- the payment reads ----",
    }, {
      "name" = "uascItemValueAdjustedByReaction",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascNpcCharacterAffectsCosts",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascHostileAtLeastDoubleFee",
      "value" = true,
      "comment" = "---- the hostile caster reads ----",
    }, {
      "name" = "uascHostileMayRefuseEntirely",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascHostileMayBeBribedWithItem",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascGoodUnlikelyToCastForEvil",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uascDuressUsesDmgRules",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uail6DfogName'](), \"Death Fog (Alteration - Evocation)\") != 0  or m['uail6DfogLevel']() != 6  or  m['uail6DfogComponentsVSM']() != 1  or m['uail6DfogCastingTimeSegments']() != 6  or m['uail6DfogRangeInches']() != 3  or  m['uail6DfogSaveNone']() != 1  or  m['uail6DfogDurationCellSuspectGarble']() != 1  or m['uail6DfogAoeCubicPerLevel']() != 2  or  m['uail6DfogAoeUnitCellLost']() != 1  or  m['uail6DfogCreatesSolidFogArea']() != 1  or  m['uail6DfogHighlyAcidic']() != 1  or  m['uail6DfogVaporsDeadlyToVegetation']() != 1  or m['uail6DfogPlantsDieInRounds']() != 2  or m['uail6DfogBushesShrubsDieInRounds']() != 4  or m['uail6DfogSmallTreesDieInRounds']() != 8  or m['uail6DfogLargeTreesDieInRounds']() != 16  or  m['uail6DfogAnimalsNotImmuneSuffer']() != 1  or m['uail6DfogDamageRound1']() != 1  or m['uail6DfogDamageRound2']() != 2  or m['uail6DfogDamageRound3']() != 4  or m['uail6DfogDamageRound4On']() != 8  or  m['uail6DfogOtherwiseSameAsSolidFog']() != 1  or  m['uail6DfogComponentsPeasHoofAcid']() != 1  or  m['uail6DfogAcidIncludesVinegarCrystals']() != 1  or strcmp(m['uail6MisleadName'](), \"Mislead (Illusion/Phantasm)\") != 0  or m['uail6MisleadLevel']() != 6  or  m['uail6MisleadSomaticOnly']() != 1  or m['uail6MisleadCastingTimeSegments']() != 1  or  m['uail6MisleadRangeCellSuspectGarble']() != 1  or  m['uail6MisleadSaveNone']() != 1  or m['uail6MisleadDurationRoundsPerLevel']() != 1  or  m['uail6MisleadAoeSpecial']() != 1  or  m['uail6MisleadCreatesPhantasmalDouble']() != 1  or  m['uail6MisleadCloakedByImprovedInvis']() != 1  or  m['uail6MisleadCasterFreeToGoElsewhere']() != 1  or  m['uail6MisleadPhantasmSeeminglyMovesAway']() != 1  or  m['uail6MisleadPhantasmSpeaksAndGestures']() != 1  or  m['uail6MisleadSensorySentenceGarbled']() != 1  or  m['uail6MisleadTrueSightRevealsIllusion']() != 1  or  m['uail6MisleadGemOfSeeingRevealsIllusion']() != 1  or  m['uail6MisleadDetectInvisDetectsCaster']() != 1  or  m['uail6MisleadTrueSightDetectsCaster']() != 1  or  m['uail6MisleadTrueSeeingDetectsCaster']() != 1  or  m['uail6MisleadRobeOfEyesDetectsCaster']() != 1  or  m['uail6MisleadShadowDoorCrossRef']() != 1  or strcmp(m['uail6PhantName'](), \"Phantasmagoria (Illusion/Phantasm)\") != 0  or m['uail6PhantLevel']() != 6  or  m['uail6PhantLevelCellLost']() != 1  or  m['uail6PhantComponentsVerbalSomatic']() != 1  or m['uail6PhantCastingTimeSegments']() != 6  or  m['uail6PhantSaveNegates']() != 1  or  m['uail6PhantDurationCellSuspectGarble']() != 1  or  m['uail6PhantAoeCellGarbled']() != 1  or  m['uail6PhantSpecialFormOfSpectralForces']() != 1  or  m['uail6PhantTriggeredBySpecialAction']() != 1  or  m['uail6PhantFullVisualAudialOlfactoryTouch']() != 1  or  m['uail6PhantFallingSlidingMovingRapidly']() != 1  or  m['uail6PhantTriggerOnPitFallOrDoorOpen']() != 1  or  m['uail6PhantMustInvolveFallingRushing']() != 1  or  m['uail6PhantDwindlingPerspectiveRead']() != 1  or  m['uail6PhantUnlikeProgrammedIllusion']() != 1  or strcmp(m['uail6MirageName'](), \"Mirage Arcane (Illusion/Phantasm - \" \"Alteration)\") != 0  or m['uail6MirageLevel']() != 6  or  m['uail6MirageLevelDivergenceFlagged']() != 1  or  m['uail6MirageComponentsVSOptionalM']() != 1  or m['uail6MirageRangeInchesPerLevel']() != 1  or m['uail6MirageCastingTimeBasicSegments']() != 3  or m['uail6MirageCastingTimeComplexSegments']() != 6  or  m['uail6MirageSaveNone']() != 1  or  m['uail6MirageDurationSpecial']() != 1  or m['uail6MirageAoeRadiusInchesPerLevel']() != 1  or  m['uail6MirageSimilarToVacancyButStronger']() != 1  or  m['uail6MirageSimilarToMirageCantrip']() != 1  or  m['uail6MirageAreaAppearsOtherThanItIs']() != 1  or  m['uail6MirageEnvisionedByCaster']() != 1  or  m['uail6MirageHeldByFaintConcentration']() != 1  or m['uail6MiragePersistsBaseTurns']() != 6  or m['uail6MiragePersistsTurnsPerLevel']() != 1  or  m['uail6MirageConcentrationOkInConversation']() != 1  or  m['uail6MirageConcentrationNotInCombat']() != 1  or  m['uail6MirageMustBePersonallySeen']() != 1  or  m['uail6MirageMaterialBitGrantsReality']() != 1  or  m['uail6MirageBasicForcefulContactNeeded']() != 1  or  m['uail6MirageComplexDetectionOnlyMagical']() != 1  or  m['uail6MirageSubjectToDispelIllusionOrMagic']() != 1  or  m['uail6MirageMindCausesBodyEffects']() != 1  or  m['uail6MirageBeliefCannotAffectLawsOfNature']() != 1  or  m['uail6MirageHotCoalsExample']() != 1  or  m['uail6MirageImaginaryFoodNourishes']() != 1  or  m['uail6MirageFeatherbedExample']() != 1  or  m['uail6MirageGravityUnaffected']() != 1  or  m['uail6MirageEnvisionedBridgeWillNotHold']() != 1  or  m['uail6MirageWitnessesSeeDisappearance']() != 1  or  m['uail6MirageDisappearanceNotLinkedToIllusion']() != 1",
      "note" = "---- death fog ---- ---- mislead ---- ---- phantasmagoria ---- ---- mirage arcane ----",
    }, {
      "expr" = "strcmp(m['uail7ShadowName'](), \"Shadow Walk (Illusion - Enchantment)\") != 0  or m['uail7ShadowLevel']() != 7  or  m['uail7ShadowComponentsCellGarbled']() != 1  or  m['uail7ShadowRangeTouch']() != 1  or m['uail7ShadowCastingTimeSegments']() != 1  or  m['uail7ShadowSaveNone']() != 1  or m['uail7ShadowDurationTurnsPerLevel']() != 6  or  m['uail7ShadowAoeSpecial']() != 1  or  m['uail7ShadowRequiresHeavyShadows']() != 1  or  m['uail7ShadowEdgeOfPrimeMaterial']() != 1  or  m['uail7ShadowAwareOfPrimePosition']() != 1  or m['uail7ShadowLeaguesPerTurn']() != 7  or  m['uail7ShadowRapidTravelByStepping']() != 1  or  m['uail7ShadowDestinationControlled']() != 1  or  m['uail7ShadowOtherPlanesPerilousTransit']() != 1  or  m['uail7ShadowTouchedAlsoTransition']() != 1  or  m['uail7ShadowMayFollowWanderOrStumble']() != 1  or  m['uail7ShadowLostOrAbandonedFiftyFifty']() != 1  or  m['uail7ShadowUnwillingSaveNegates']() != 1  or strcmp(m['uail7WeirdName'](), \"Weird (Evocation - Illusion/Phantasm)\") != 0  or m['uail7WeirdLevel']() != 7  or  m['uail7WeirdComponentsVerbalSomatic']() != 1  or m['uail7WeirdCastingTimeSegments']() != 7  or m['uail7WeirdRangeInches']() != 3  or  m['uail7WeirdSaveSpecial']() != 1  or  m['uail7WeirdDurationSpecial']() != 1  or m['uail7WeirdAoeRadiusInches']() != 2  or  m['uail7WeirdProseLargelyLost']() != 1  or  m['uail7WeirdCasterMustFragmentPrints']() != 1",
      "note" = "---- shadow walk ---- ---- weird ----",
    }, {
      "expr" = "m['uailaThreeGroupsOneEach']() != 1  or  m['uailaAlwaysKnowsReadIllusionistMagic']() != 1  or m['uailaOffensiveRowCount']() != 6  or m['uailaDefensiveRowCount']() != 6  or m['uailaMiscRowCount']() != 6  or  m['uailaOffRow1ColorSpray']() != 1  or  m['uailaOffRow2Hypnotism']() != 1  or  m['uailaOffRow3Light']() != 1  or  m['uailaOffRow4PhantasmalForce']() != 1  or  m['uailaOffRow5ChromaticOrb']() != 1  or  m['uailaChromaticOrbPrintsPlain']() != 1  or  m['uailaOffRow6Spook']() != 1  or  m['uailaDefRow1AudibleGlamer']() != 1  or  m['uailaDefRow2Darkness']() != 1  or  m['uailaDefRow3GazeReflection']() != 1  or  m['uailaDefRow4WallOfFog']() != 1  or  m['uailaDefRow5PhantomArmor']() != 1  or  m['uailaDefRow6IsChoose']() != 1  or  m['uailaMiscRow1ChangeSelf']() != 1  or  m['uailaMiscRow2DancingLights']() != 1  or  m['uailaMiscRow3DetectIllusion']() != 1  or  m['uailaMiscRow4DetectInvisibility']() != 1  or  m['uailaMiscRow5IsChoose']() != 1  or  m['uailaMiscRow6IsChooseAsterisk']() != 1  or  m['uailaColumnsDecodeColumnWise']() != 1  or m['uailaDmOptionCount']() != 3  or  m['uailaUaSpellsAddedForIllusionistsOnly']() != 1  or  m['uailaNotDoneForMagicUsers']() != 1  or  m['uailaBooksSameAsMuWithExceptions']() != 1  or m['uailaStandardBookLowLevelSpells']() != 24  or m['uailaStandardBookMidLevelSpells']() != 16  or m['uailaStandardBookHighLevelSpells']() != 8  or  m['uailaMuFirstLevelNeedsNewBook']() != 1  or m['uailaMuFirstLevelBookCapacity']() != 24  or m['uailaTravellingBookLowLevelSpells']() != 6  or m['uailaTravellingBookMidLevelSpells']() != 4  or m['uailaTravellingBookHighLevelSpells']() != 2  or  m['uailaScriptReadableByIllusionistsOnly']() != 1  or  m['uailaCrossClassBookBan']() != 1  or  m['uailaNamesakeSpellsTriggerDifferently']() != 1  or  m['uailaHasAllMuCantrips']() != 1  or m['uailaMinorIllusionCantripsMin']() != 5  or m['uailaMinorIllusionCantripsMax']() != 8  or  m['uailaMinorIllusionNotAvailableToMu']() != 1  or m['uailaUsefulCapIntMinus']() != 3  or m['uailaUsefulCapAtInt18']() != 15  or m['uailaReversedKnownMin']() != 2  or m['uailaReversedKnownMax']() != 5  or m['uailaLegerdemainKnownMin']() != 3  or m['uailaLegerdemainKnownMax']() != 6  or m['uailaPersonAffectingKnownMin']() != 2  or m['uailaPersonAffectingKnownMax']() != 5  or m['uailaPersonalKnownMin']() != 2  or m['uailaPersonalKnownMax']() != 5  or m['uailaHauntingSoundKnownMin']() != 5  or m['uailaHauntingSoundKnownMax']() != 8  or  m['uailaMuCantripPropertiesOtherwiseApply']() != 1",
      "note" = "---- the starting list ---- ---- the illusionist spell book differences ---- ---- the illusionist cantrip counts ----",
    }, {
      "expr" = "m['uascFeePerSpellLevelGp']() != 200  or  m['uascWillingCasterWorksForFee']() != 1  or  m['uascMaterialComponentsDoubled']() != 1  or  m['uascComponentSubstitutionsAllowed']() != 1  or m['uascOrdinarySurchargePercent']() != 10  or m['uascOrdinarySurchargeValueMultiple']() != 3  or m['uascExtraordinarySurchargePercent']() != 100  or m['uascExtraordinaryValueMultiple']() != 3  or  m['uascSurchargeWhicheverIsGreater']() != 1  or  m['uascDangerSpellsAtLeastDoubleFee']() != 1  or  m['uascDangerGuaranteesRequired']() != 1  or  m['uascDangerClauseInterleaved']() != 1  or  m['uascAgingSpellsNeedCounterFirst']() != 1  or  m['uascInsignificantAgingException']() != 1  or m['uascElfExampleAgingYears']() != 5  or m['uascElfExampleFeeMultiple']() != 10  or  m['uascMagicItemAcceptedInLieuOfCash']() != 1  or  m['uascItemValueAdjustedByReaction']() != 1  or  m['uascNpcCharacterAffectsCosts']() != 1  or  m['uascHostileAtLeastDoubleFee']() != 1  or  m['uascHostileMayRefuseEntirely']() != 1  or  m['uascHostileMayBeBribedWithItem']() != 1  or  m['uascGoodUnlikelyToCastForEvil']() != 1  or  m['uascDuressUsesDmgRules']() != 1",
      "note" = "---- the basic fee ---- ---- the surcharges ---- ---- the danger and aging clauses ---- ---- the payment reads ---- ---- the hostile caster reads ----",
    }, {
      "expr" = "m['uas2Il1stCount']() != 5  or m['uas2Il2ndCount']() != 4  or m['uas2Il7thCount']() != 1  or strcmp(m['uas2Il7thName'](0), \"Shadow Walk\") != 0  or m['uas2IlCantripCount']() != 8  or strcmp(m['uas2Il7thName'](0), nn[n]) == 0",
      "note" = "the R342 IL table seam: the readable columns print only PHB names except Shadow Walk at the 7th; none of the new 6th/7th names seam-checks",
    } },
  "audit" = {
      "label" = "R365: the UA new illusionist 6th/7th spells, acquisition and cost pin audit",
      "comment" = "The UA NEW ILLUSIONIST SPELLS (pp. 71-73) - the 6th-level four (death fog with the acid ladder, mislead with the improved- invisibility cloak, phantasmagoria with the lost level cell, the mirage arcane at the printed 6th cell - the item-list 7th divergence flagged) and the 7th-level pair (shadow walk with the plane reads, weird with the lost prose); the UA ILLUSIONIST SPELL ACQUISITION fragments and the UA COST OF SPELL CASTING pins. The R342 IL table seam prints only Shadow Walk at the readable 7th; the 6th column is wholly lost. The item closes this round - all printed levels pinned R363-R365.",
    },
}
