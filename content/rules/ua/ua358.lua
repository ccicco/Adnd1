-- ua358: promoted from rules/ua/uamuspells3.h (the The UA NEW MAGIC-USER SPELLS (pp. 51-66) pins, R358: the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 358,
  "prefix" = "ua358",
  "banner" = {
      "title" = "The UA NEW MAGIC-USER SPELLS (pp. 51-66) pins, R358: the",
      "provenance" = "3rd-level spell descriptions - cloudburst, detect illusion, item, material, the Melf minute meteors, secret page, the sepia snake sigil and wind wall.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the casting-time, duration and range 7s decode as 1 - the cloudburst 7\"/level range as 1 inch per level and the \"7 round\" duration as 1 round per level (the R352 druid seam pins 1 round per level; the per-level is lost in the MU interleave); the material \"7 degree\" range as 1, the unit (inch or foot) uncertain pending the PDF; the wind wall \"7 round/level\" as 1 round per level. - the cloudburst stat block scrambles its cell order (the save cell prints before the duration); the save cell truncates at None + ampersand; the casting-time number is lost (\"Casting Tim ... segment\"); the area prints a 3 inch diameter where the R352 druid seam pins 4 - a discrepancy flagged pending the PDF; the MU block supplies the range cell the druid block lost. - the detect illusion name header loses its tail - \"Detect (Divination)\" only; the name pins from the prose (the same as the 1st-level illusionist spell); the \"except as noted\" tail truncates; the area length number is lost; no illusionist seam exists (the item stays open). - the item components cell splits at \"V,\" + \"M\" across the interleave (an S, if any, is lost); the duration prints 6 turns/level with the asterisk (quadrupled on non-living material). - the material components cell garbles at \"V,\" plus a section-mark; the prose head scrambles - \"A ial spell allows the magi toac-\" - the area 7 is genuine (not a casting-time or duration cell). - the Melf minute meteors range cell prints empty - a hole pending the PDF; the firing-rate sentence interleaves with the sepia snake sigil tail but the two rates pin (1 every 2 segments, or 1 every round). - the secret page description prints under the 4th level heading; its stat block interleaves with dispel illusion (4th level, next round): the secret page cells pin as 1 turn casting time, touch, until dispelled, none, one page up to 2 ft. square; the prose scrambles with the dispel illusion and Evard tentacle text. - the sepia snake sigil body prints in the 4th level region; its casting-time head is lost (\"Time: 3 segments\"); the range prints \"\"2\"\" - pinned as 2 inches with the quote garble noted. - the wind wall components cell truncates at \"V, S,\" - the prose supplies the material; the casting-time unit is lost (the 3 pins, decoded as segments with doubt pending the PDF).",
    },
  "consts" = { {
      "name" = "uam3CloudburstName",
      "value" = "Cloudburst (Alteration)",
      "comment" = "---- cloudburst (Alteration), the 3rd level ----",
    }, {
      "name" = "uam3CloudburstLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3CloudburstRangeInchesPerLevel",
      "value" = 1,
      "comment" = "The range prints 7\"/level - the family decodes 1 inch per level. This is the cell the R352 druid block lost.",
    }, {
      "name" = "uam3CloudburstDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round\" - the family decodes 1 round per level (the R352 druid seam).",
    }, {
      "name" = "uam3CloudburstCylinderDiameterInches",
      "value" = 3,
      "comment" = "The area prints a 3\" diameter - the R352 druid seam pins 4; the disagreement is flagged pending the PDF.",
    }, {
      "name" = "uam3CloudburstCylinderHeightInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam3DetectName",
      "value" = "Detect Illusion (Divination)",
      "comment" = "---- detect illusion (Divination), the 3rd level ---- The name header loses its tail - \"Detect (Divination)\" only; the name pins from the prose.",
    }, {
      "name" = "uam3DetectLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3DetectCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3DetectDurationRoundsMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam3DetectDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3ItemName",
      "value" = "Item (Alteration)",
      "comment" = "---- item (Alteration), the 3rd level ----",
    }, {
      "name" = "uam3ItemLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3ItemDurationTurnsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam3ItemAoeCuFtPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam3ItemLivingSavePlus4",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam3ItemCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3MaterialName",
      "value" = "Material (Evocation-Conjuration)",
      "comment" = "---- material (Evocation-Conjuration), the 3rd ----",
    }, {
      "name" = "uam3MaterialLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3MaterialCastingTimeRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3MaterialRangeDecodedOne",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3MaterialAoeCuFtPerLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uam3MaterialGrassBaseFailurePct",
      "value" = 100,
      "comment" = "Grass: a base 100% chance of total failure, modified downward by 1% per level of the caster.",
    }, {
      "name" = "uam3MeteorsName",
      "value" = "Melf's Minute Meteors (Evocation/Alteration)",
      "comment" = "---- the Melf minute meteors (Evocation/Alteration) ----",
    }, {
      "name" = "uam3MeteorsLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsBurstDiameterFeet",
      "value" = 1,
      "comment" = "Each globe bursts into a 1 ft. diameter sphere on impact, inflicting 1-4 points of damage.",
    }, {
      "name" = "uam3MeteorsDamageMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsDamageMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsTubeCostGpMin",
      "value" = 1000,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageName",
      "value" = "Secret Page (Alteration)",
      "comment" = "---- secret page (Alteration), the 3rd level ---- The description prints under the 4th level heading; its stat block interleaves with dispel illusion (the 4th level, next round).",
    }, {
      "name" = "uam3SecretPageLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageCastingTimeTurns",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageAoeMaxFt",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam3SepiaName",
      "value" = "Sepia Snake Sigil (Conjuration/Summoning)",
      "comment" = "---- the sepia snake sigil (Conjuration/Summoning) ---- The body prints in the 4th level region; the casting head is lost (\"Time: 3 segments\").",
    }, {
      "name" = "uam3SepiaLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3SepiaRangeInches",
      "value" = 2,
      "comment" = "The range cell prints \"\"2\"\" - pinned as 2 inches with the quote garble noted.",
    }, {
      "name" = "uam3SepiaCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3SepiaMissSmokeInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3SepiaMissSmokeRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3SepiaMaterialAmberGp",
      "value" = 100,
      "comment" = "The components: 100 gp worth of powdered amber, a scale from any snake, and a pinch of mushroom spores.",
    }, {
      "name" = "uam3WindWallName",
      "value" = "Wind Wall (Alteration)",
      "comment" = "---- wind wall (Alteration), the 3rd level ----",
    }, {
      "name" = "uam3WindWallLevel",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam3WindWallRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam3WindWallCastingTimeSegments",
      "value" = 3,
      "comment" = "The casting time prints 3 with the unit lost - the 3 pins, decoded as segments with doubt pending the PDF.",
    }, {
      "name" = "uam3WindWallDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round/level\" - the family decodes 1 round per level.",
    }, {
      "name" = "uam3WindWallAoeInchesPerLevel",
      "value" = 1,
      "comment" = "An area 1\" wide and high per level of caster.",
    } },
  "bools" = { {
      "name" = "uam3CloudburstComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3CloudburstCastingTimeNumberLost",
      "value" = true,
      "comment" = "The casting-time number is lost; only the unit prints.",
    }, {
      "name" = "uam3CloudburstCastingTimeUnitSegments",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3CloudburstStatBlockScrambled",
      "value" = true,
      "comment" = "The save cell prints before the duration (scrambled).",
    }, {
      "name" = "uam3CloudburstSaveNoneAndSpecial",
      "value" = true,
      "comment" = "The save cell truncates at None + ampersand - the R352 druid seam pins none and special.",
    }, {
      "name" = "uam3CloudburstSaveCellTruncated",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3CloudburstDiameterDisagreesWithDruidSeam",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3CloudburstIdenticalToClerical3rd",
      "value" = true,
      "comment" = "The spell is identical to the 3rd-level clerical spell of the same name, except that a holy symbol is not part of the material component.",
    }, {
      "name" = "uam3CloudburstNoHolySymbolComponent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3DetectNameHeaderTailLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3DetectComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3DetectRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3DetectSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3DetectAoeLineOfSightOneInchWide",
      "value" = true,
      "comment" = "The area prints Line of sight 1\" wide, then the length number is lost - a hole pending the PDF.",
    }, {
      "name" = "uam3DetectAoeLengthLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3DetectSameAsIllusionist1st",
      "value" = true,
      "comment" = "The spell is the same as the 1st-level illusionist spell detect illusion, except as noted (the tail truncates). No illusionist seam exists yet.",
    }, {
      "name" = "uam3DetectExceptAsNotedTruncated",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemDurationQuadrupledNonLiving",
      "value" = true,
      "comment" = "The asterisk: the duration quadruples on non-living material.",
    }, {
      "name" = "uam3ItemShrinksToOneTwelfth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemClothCompositionOption",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemLivingEntitledToSave",
      "value" = true,
      "comment" = "Only living things are entitled to a save, at +4.",
    }, {
      "name" = "uam3ItemClothSavesNormally",
      "value" = true,
      "comment" = "Objects and creatures transformed to cloth save normally against subsequent attacks.",
    }, {
      "name" = "uam3ItemReturnsOnTossOrCommand",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemCanAffectFireAndFuel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemComponentsV",
      "value" = true,
      "comment" = "The components cell splits at \"V,\" + \"M\" across the interleave; an S, if any, is lost.",
    }, {
      "name" = "uam3ItemComponentsM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemComponentsCellSplit",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3ItemSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialComponentsV",
      "value" = true,
      "comment" = "The components cell garbles at \"V,\" plus a section-mark.",
    }, {
      "name" = "uam3MaterialComponentsCellGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialRangePrintsDegrees",
      "value" = true,
      "comment" = "The range prints \"7 degrees\" - the family decodes 1; the unit (inch or foot) is uncertain pending the PDF.",
    }, {
      "name" = "uam3MaterialSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialProseHeadScrambled",
      "value" = true,
      "comment" = "The prose head scrambles: A ial spell allows the magi toac- tually bring into being certain common things.",
    }, {
      "name" = "uam3MaterialCommonStoneEarthWood",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialInorganicNonLivingEtc",
      "value" = true,
      "comment" = "Other inorganic or non-living materials: water, air, dung, straw, etc. (the \"living\" head is lost in the interleave).",
    }, {
      "name" = "uam3MaterialGrassFailureMinusOnePctPerLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialAnimalLifeNever",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialNoWorkedRefinedFabricated",
      "value" = true,
      "comment" = "No worked, refined or fabricated items; no rough gems or precious metals.",
    }, {
      "name" = "uam3MaterialNoRoughGemsOrPreciousMetals",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MaterialCreatesCommonBasicThings",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsRangeCellEmpty",
      "value" = true,
      "comment" = "The range cell prints empty - a hole pending the PDF.",
    }, {
      "name" = "uam3MeteorsDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsAoeOneTargetPerMissile",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsIgnitesCombustibles",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsMissileWeapons",
      "value" = true,
      "comment" = "The meteors are missile weapons thrown by the mage; misses are treated as grenade-like missiles.",
    }, {
      "name" = "uam3MeteorsMissesGrenadeLike",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsOnePerLevelOfExperience",
      "value" = true,
      "comment" = "One missile per level of experience; the firing continues until the caster foregoes the remainder or a dispel magic succeeds.",
    }, {
      "name" = "uam3MeteorsDispelMagicEnds",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsFireRateSentenceScrambled",
      "value" = true,
      "comment" = "The firing-rate sentence interleaves with the sepia snake sigil tail - the two rates still pin.",
    }, {
      "name" = "uam3MeteorsTwoRateOptions",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsRateOneEvery2Segments",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsRateOneEveryRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsRateChoiceCannotSwitch",
      "value" = true,
      "comment" = "The caster may not switch between the options once one is chosen.",
    }, {
      "name" = "uam3MeteorsRateOnePointEvery2Segments",
      "value" = true,
      "comment" = "Option one: point at the target on the second segment after casting, repeated every 2 segments; the spell usually carries into at least the following round.",
    }, {
      "name" = "uam3MeteorsCarriesIntoFollowingRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsRateTwoWithholdPerRound",
      "value" = true,
      "comment" = "Option two: withhold or discharge missiles at will, so long as one goes each round; the caster can discharge one and cast another spell in the same round, if the other spell needs no continuing concentration; a lost mental count forfeits the remainder.",
    }, {
      "name" = "uam3MeteorsRateTwoSpellSameRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsRateTwoNoConcentration",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsLoseRemainderOnLostCount",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsMaterialNitreSulphurPineTarBead",
      "value" = true,
      "comment" = "The components: nitre and sulphur formed into a bead with pine tar, and a small tube of gold costing no less than 1,000 gp, potent through numerous castings unless damaged.",
    }, {
      "name" = "uam3MeteorsMaterialGoldTube",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsTubeReusableUnlessDamaged",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3MeteorsSepiaTailInterleaved",
      "value" = true,
      "comment" = "The sepia snake sigil tail - \"grow hungry, sleep or regain spells...\" - interleaves into the material paragraph.",
    }, {
      "name" = "uam3SecretPageUnderFourthHeading",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageStatInterleavedWithDispelIllusion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageDurationUntilDispelled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageAoeOnePageUpTo2FtSquare",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageAltersContents",
      "value" = true,
      "comment" = "The spell alters the actual contents of a page to appear as something entirely different - a map to a treatise on burnishing ebony walking sticks, a spell text to a ledger or another spell.",
    }, {
      "name" = "uam3SecretPageMapToTreatiseExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageRunesAllowed",
      "value" = true,
      "comment" = "Confuse and explosive runes may be cast upon the secret page; a comprehend languages will not reveal the actual contents.",
    }, {
      "name" = "uam3SecretPageComprehendLanguagesFails",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageReversedByCommandWord",
      "value" = true,
      "comment" = "The caster reverses the effect by the mere utterance of the command word, peruses the actual page, and returns it to secret page form; a double repetition of the command word removes the spell.",
    }, {
      "name" = "uam3SecretPageRemovedByDoubleCommand",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageFailedDispelDestroysPage",
      "value" = true,
      "comment" = "Others noting the dim magic can attempt a dispel magic; if it fails, the page is destroyed. Short of alter reality or wish, only will-o-wisp or boggart essence reveals the true nature.",
    }, {
      "name" = "uam3SecretPageEssenceReveals",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SecretPageMaterialHerringScales",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaBodyPrintsInFourthRegion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaRangePrintsQuotedTwo",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaAoeOneSigil",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaCastingTimeHeadLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaThreeForms",
      "value" = true,
      "comment" = "Three forms of the spell, each eventually conjuring a deep brown snake-like force that springs at the nearest living creature - never the caster - striking as a monster with hit dice equal to the caster level.",
    }, {
      "name" = "uam3SepiaStrikesNearestLiving",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaNeverAttacksCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaAttackHdPerLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaEngulfsOnStrike",
      "value" = true,
      "comment" = "A struck victim is engulfed in a shimmering amber field of force, frozen and immobilized until the caster releases it or a dispel magic does so; nothing can get at the victim, move the force, or affect either.",
    }, {
      "name" = "uam3SepiaAmberFieldOfForce",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaFrozenUntilReleaseOrDispel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaNothingCanAffect",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaNoAgeHungerSleepOrSpells",
      "value" = true,
      "comment" = "The victim does not age, grow hungry, sleep or regain spells, and is not aware of the surroundings.",
    }, {
      "name" = "uam3SepiaMissDissipatesBrownFlash",
      "value" = true,
      "comment" = "A miss dissipates in a flash of brown light, a loud noise and dun-colored smoke 1\" in diameter lasting 1 round.",
    }, {
      "name" = "uam3SepiaApplicationAirSigil",
      "value" = true,
      "comment" = "The three applications: a glowing sigil in the air drawn by the caster and pointed at the target; a glyph of umber marked on a surface touched or gazed upon; a small character written into a magic work to protect it.",
    }, {
      "name" = "uam3SepiaApplicationGlyphUmber",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaApplicationWrittenIntoWork",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaMaterialSnakeScale",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3SepiaMaterialMushroomSpores",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallComponentsCellTruncated",
      "value" = true,
      "comment" = "The components cell truncates at \"V, S,\" - the prose supplies the material.",
    }, {
      "name" = "uam3WindWallMaterialTinyFanAndExoticFeather",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallCastingTimeUnitLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallAoeWideAndHigh",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallInvisibleCurtain",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallBlowsBirdsUpToCrows",
      "value" = true,
      "comment" = "Sufficient to blow birds as large as crows upward, or to tear papers and like materials from unsuspecting hands (a saving throw versus spell maintains the grasp); normal insects cannot pass; loose material, even cloth garments, caught in the wall flies upward.",
    }, {
      "name" = "uam3WindWallTearsPapersFromHands",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallSaveToMaintainGrasp",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallNormalInsectsCannotPass",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam3WindWallLooseMaterialFliesUpward",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uam3CloudburstName'](), \"Cloudburst (Alteration)\") != 0  or m['uam3CloudburstLevel']() != 3  or  m['uam3CloudburstComponentsVSM']() != 1  or m['uam3CloudburstRangeInchesPerLevel']() != 1  or  m['uam3CloudburstCastingTimeNumberLost']() != 1  or  m['uam3CloudburstCastingTimeUnitSegments']() != 1  or  m['uam3CloudburstStatBlockScrambled']() != 1  or  m['uam3CloudburstSaveNoneAndSpecial']() != 1  or  m['uam3CloudburstSaveCellTruncated']() != 1  or m['uam3CloudburstDurationRoundsPerLevel']() != 1  or m['uam3CloudburstCylinderDiameterInches']() != 3  or  m['uam3CloudburstDiameterDisagreesWithDruidSeam']() != 1  or m['uam3CloudburstCylinderHeightInches']() != 6  or  m['uam3CloudburstIdenticalToClerical3rd']() != 1  or  m['uam3CloudburstNoHolySymbolComponent']() != 1  or m['uad3CloudburstDurationRoundsPerLevel']() !=m['uam3CloudburstDurationRoundsPerLevel']()  or m['uad3CloudburstCylinderHeightInches']() !=m['uam3CloudburstCylinderHeightInches']()  or m['uad3CloudburstComponentsVSM']() !=m['uam3CloudburstComponentsVSM']()  or m['uad3CloudburstSaveNoneAndSpecial']() !=m['uam3CloudburstSaveNoneAndSpecial']()  or  m['uad3CloudburstRangeLost']() != 1  or m['uad3CloudburstCastingTimeSegments']() != 5  or m['uad3CloudburstCylinderDiameterInches']() != 4",
      "note" = "U1: cloudburst",
    }, {
      "expr" = "strcmp(m['uam3DetectName'](), \"Detect Illusion (Divination)\") != 0  or  m['uam3DetectNameHeaderTailLost']() != 1  or m['uam3DetectLevel']() != 3  or  m['uam3DetectComponentsVSM']() != 1  or m['uam3DetectCastingTimeSegments']() != 3  or  m['uam3DetectRangeTouch']() != 1  or  m['uam3DetectSaveNone']() != 1  or m['uam3DetectDurationRoundsMin']() != 2  or m['uam3DetectDurationRoundsPerLevel']() != 1  or  m['uam3DetectAoeLineOfSightOneInchWide']() != 1  or  m['uam3DetectAoeLengthLost']() != 1  or  m['uam3DetectSameAsIllusionist1st']() != 1  or  m['uam3DetectExceptAsNotedTruncated']() != 1",
      "note" = "U2: detect illusion",
    }, {
      "expr" = "strcmp(m['uam3ItemName'](), \"Item (Alteration)\") != 0  or m['uam3ItemLevel']() != 3  or  m['uam3ItemRangeTouch']() != 1  or m['uam3ItemDurationTurnsPerLevel']() != 6  or  m['uam3ItemDurationQuadrupledNonLiving']() != 1  or m['uam3ItemAoeCuFtPerLevel']() != 2  or  m['uam3ItemShrinksToOneTwelfth']() != 1  or  m['uam3ItemClothCompositionOption']() != 1  or  m['uam3ItemLivingEntitledToSave']() != 1  or m['uam3ItemLivingSavePlus4']() != 4  or  m['uam3ItemClothSavesNormally']() != 1  or  m['uam3ItemReturnsOnTossOrCommand']() != 1  or  m['uam3ItemCanAffectFireAndFuel']() != 1  or  m['uam3ItemComponentsV']() != 1  or  m['uam3ItemComponentsM']() != 1  or  m['uam3ItemComponentsCellSplit']() != 1  or m['uam3ItemCastingTimeSegments']() != 3  or  m['uam3ItemSaveSpecial']() != 1",
      "note" = "U3: item",
    }, {
      "expr" = "strcmp(m['uam3MaterialName'](), \"Material (Evocation-Conjuration)\") != 0  or m['uam3MaterialLevel']() != 3  or  m['uam3MaterialComponentsV']() != 1  or  m['uam3MaterialComponentsCellGarbled']() != 1  or m['uam3MaterialCastingTimeRounds']() != 1  or  m['uam3MaterialRangePrintsDegrees']() != 1  or m['uam3MaterialRangeDecodedOne']() != 1  or  m['uam3MaterialSaveNone']() != 1  or  m['uam3MaterialDurationPermanent']() != 1  or m['uam3MaterialAoeCuFtPerLevel']() != 7  or  m['uam3MaterialProseHeadScrambled']() != 1  or  m['uam3MaterialCommonStoneEarthWood']() != 1  or  m['uam3MaterialInorganicNonLivingEtc']() != 1  or m['uam3MaterialGrassBaseFailurePct']() != 100  or  m['uam3MaterialGrassFailureMinusOnePctPerLevel']() != 1  or  m['uam3MaterialAnimalLifeNever']() != 1  or  m['uam3MaterialNoWorkedRefinedFabricated']() != 1  or  m['uam3MaterialNoRoughGemsOrPreciousMetals']() != 1  or  m['uam3MaterialCreatesCommonBasicThings']() != 1",
      "note" = "U4: material",
    }, {
      "expr" = "strcmp(m['uam3MeteorsName'](), \"Melf's Minute Meteors (Evocation/Alteration)\") != 0  or m['uam3MeteorsLevel']() != 3  or  m['uam3MeteorsComponentsVSM']() != 1  or m['uam3MeteorsCastingTimeSegments']() != 5  or  m['uam3MeteorsRangeCellEmpty']() != 1  or  m['uam3MeteorsDurationSpecial']() != 1  or  m['uam3MeteorsSaveNone']() != 1  or  m['uam3MeteorsAoeOneTargetPerMissile']() != 1  or m['uam3MeteorsBurstDiameterFeet']() != 1  or m['uam3MeteorsDamageMin']() != 1  or m['uam3MeteorsDamageMax']() != 4  or  m['uam3MeteorsIgnitesCombustibles']() != 1  or  m['uam3MeteorsMissileWeapons']() != 1  or  m['uam3MeteorsMissesGrenadeLike']() != 1  or  m['uam3MeteorsOnePerLevelOfExperience']() != 1  or  m['uam3MeteorsDispelMagicEnds']() != 1  or  m['uam3MeteorsFireRateSentenceScrambled']() != 1  or  m['uam3MeteorsTwoRateOptions']() != 1  or  m['uam3MeteorsRateOneEvery2Segments']() != 1  or  m['uam3MeteorsRateOneEveryRound']() != 1  or  m['uam3MeteorsRateChoiceCannotSwitch']() != 1  or  m['uam3MeteorsRateOnePointEvery2Segments']() != 1  or  m['uam3MeteorsCarriesIntoFollowingRound']() != 1  or  m['uam3MeteorsRateTwoWithholdPerRound']() != 1  or  m['uam3MeteorsRateTwoSpellSameRound']() != 1  or  m['uam3MeteorsRateTwoNoConcentration']() != 1  or  m['uam3MeteorsLoseRemainderOnLostCount']() != 1  or  m['uam3MeteorsMaterialNitreSulphurPineTarBead']() != 1  or  m['uam3MeteorsMaterialGoldTube']() != 1  or m['uam3MeteorsTubeCostGpMin']() != 1000  or  m['uam3MeteorsTubeReusableUnlessDamaged']() != 1  or  m['uam3MeteorsSepiaTailInterleaved']() != 1",
      "note" = "U5: the Melf minute meteors",
    }, {
      "expr" = "strcmp(m['uam3SecretPageName'](), \"Secret Page (Alteration)\") != 0  or  m['uam3SecretPageUnderFourthHeading']() != 1  or  m['uam3SecretPageStatInterleavedWithDispelIllusion']() != 1  or m['uam3SecretPageLevel']() != 3  or  m['uam3SecretPageComponentsVSM']() != 1  or m['uam3SecretPageCastingTimeTurns']() != 1  or  m['uam3SecretPageRangeTouch']() != 1  or  m['uam3SecretPageDurationUntilDispelled']() != 1  or  m['uam3SecretPageSaveNone']() != 1  or m['uam3SecretPageAoeMaxFt']() != 2  or  m['uam3SecretPageAoeOnePageUpTo2FtSquare']() != 1  or  m['uam3SecretPageAltersContents']() != 1  or  m['uam3SecretPageMapToTreatiseExample']() != 1  or  m['uam3SecretPageRunesAllowed']() != 1  or  m['uam3SecretPageComprehendLanguagesFails']() != 1  or  m['uam3SecretPageReversedByCommandWord']() != 1  or  m['uam3SecretPageRemovedByDoubleCommand']() != 1  or  m['uam3SecretPageFailedDispelDestroysPage']() != 1  or  m['uam3SecretPageEssenceReveals']() != 1  or  m['uam3SecretPageMaterialHerringScales']() != 1",
      "note" = "U6: secret page",
    }, {
      "expr" = "strcmp(m['uam3SepiaName'](), \"Sepia Snake Sigil (Conjuration/Summoning)\") != 0  or  m['uam3SepiaBodyPrintsInFourthRegion']() != 1  or m['uam3SepiaLevel']() != 3  or  m['uam3SepiaComponentsVSM']() != 1  or m['uam3SepiaRangeInches']() != 2  or  m['uam3SepiaRangePrintsQuotedTwo']() != 1  or  m['uam3SepiaDurationSpecial']() != 1  or  m['uam3SepiaAoeOneSigil']() != 1  or  m['uam3SepiaCastingTimeHeadLost']() != 1  or m['uam3SepiaCastingTimeSegments']() != 3  or  m['uam3SepiaSaveNone']() != 1  or  m['uam3SepiaThreeForms']() != 1  or  m['uam3SepiaStrikesNearestLiving']() != 1  or  m['uam3SepiaNeverAttacksCaster']() != 1  or  m['uam3SepiaAttackHdPerLevel']() != 1  or  m['uam3SepiaEngulfsOnStrike']() != 1  or  m['uam3SepiaAmberFieldOfForce']() != 1  or  m['uam3SepiaFrozenUntilReleaseOrDispel']() != 1  or  m['uam3SepiaNothingCanAffect']() != 1  or  m['uam3SepiaNoAgeHungerSleepOrSpells']() != 1  or  m['uam3SepiaMissDissipatesBrownFlash']() != 1  or m['uam3SepiaMissSmokeInches']() != 1  or m['uam3SepiaMissSmokeRounds']() != 1  or  m['uam3SepiaApplicationAirSigil']() != 1  or  m['uam3SepiaApplicationGlyphUmber']() != 1  or  m['uam3SepiaApplicationWrittenIntoWork']() != 1  or m['uam3SepiaMaterialAmberGp']() != 100  or  m['uam3SepiaMaterialSnakeScale']() != 1  or  m['uam3SepiaMaterialMushroomSpores']() != 1",
      "note" = "U7: the sepia snake sigil",
    }, {
      "expr" = "strcmp(m['uam3WindWallName'](), \"Wind Wall (Alteration)\") != 0  or m['uam3WindWallLevel']() != 3  or  m['uam3WindWallComponentsCellTruncated']() != 1  or  m['uam3WindWallMaterialTinyFanAndExoticFeather']() != 1  or m['uam3WindWallRangeInchesPerLevel']() != 1  or m['uam3WindWallCastingTimeSegments']() != 3  or  m['uam3WindWallCastingTimeUnitLost']() != 1  or  m['uam3WindWallSaveSpecial']() != 1  or m['uam3WindWallDurationRoundsPerLevel']() != 1  or m['uam3WindWallAoeInchesPerLevel']() != 1  or  m['uam3WindWallAoeWideAndHigh']() != 1  or  m['uam3WindWallInvisibleCurtain']() != 1  or  m['uam3WindWallBlowsBirdsUpToCrows']() != 1  or  m['uam3WindWallTearsPapersFromHands']() != 1  or  m['uam3WindWallSaveToMaintainGrasp']() != 1  or  m['uam3WindWallNormalInsectsCannotPass']() != 1  or  m['uam3WindWallLooseMaterialFliesUpward']() != 1",
      "note" = "U8: wind wall",
    }, {
      "expr" = "m['uas2Mu3rdCount']() != 28  or strcmp(m['uas2Mu3rdName'](16), \"Melf's Minute Meteor\") != 0  or strcmp(m['uas2Mu3rdName'](21), \"Secret Page\") != 0  or strcmp(m['uas2Mu3rdName'](22), \"Sepia Snake Sigil\") != 0  or strcmp(m['uas2Mu3rdName'](27), \"Wind Wall\") != 0",
      "note" = "the R342 table seam (4 of 8 names)",
    }, {
      "expr" = "strcmp(n, \"Cloudburst\") == 0  or strcmp(n, \"Detect Illusion\") == 0  or strcmp(n, \"Item\") == 0  or strcmp(n, \"Material\") == 0",
      "note" = "the four names absent from the seam",
    } },
  "audit" = {
      "label" = "R358: the UA new magic-user 3rd level spells pin audit",
      "comment" = "The UA NEW MAGIC-USER SPELLS (pp. 51-66), the 3rd level - cloudburst (the R352 druid seam minus the holy symbol, the 3 diam. print flagged against the druid 4), detect illusion behind the lost name tail, item, material behind the degree range, the Melf minute meteors behind the empty range, secret page behind the 4th-heading interleave, the sepia snake sigil behind the lost casting-time head, wind wall. The family decodes the 7s as 1. The R342 table seam pins 4 of 8; the item stays open (the 4th-9th levels).",
    },
}
