-- ua345: promoted from rules/ua/uaclericspells3.h (the The UA NEW CLERIC SPELLS (pp. 36-38) pins, R345: the 3rd-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 345,
  "prefix" = "ua345",
  "banner" = {
      "title" = "The UA NEW CLERIC SPELLS (pp. 36-38) pins, R345: the 3rd-level",
      "provenance" = "spell descriptions - cloudburst, death's door, flame walk, magical vestment, meld into stone, negative plane protection, remove paralysis, water walk.  Pin-era pattern (R322): pinned data only - no engine site exists. The R341 cleric table pin (rules/ua/uaspelltables.h) is the name seam - the 3rd-level column is fully readable (20 of 20 rows), so this round has no hole decode.  JUDGMENTs (the decode method): - the digit-garble family (established R343, corroborated R344): the OCR prints 7 where 1 belongs in the stat cells. This round's six 7s all decode as 1: cloudburst duration \"7 round\" = 1 round (corroborated - the hot-and-humid extension \"to 2 rounds\" implies the base 1); death's door duration \"7 hour/level\" = 1 hour/level; magical vestment casting \"7 round\" = 1 round; negative plane protection casting \"7 round\" = 1 round and duration \"7 turn/level\" = 1 turn/level (both corroborated - the prose prints a clean \"1 turn per level of the cleric\"); meld into stone casting \"7 segments\" = 1 segment - the family decode with no independent corroboration this round, verbatim with doubt pending the PDF. Every \"Level: 3\" cell prints clean. - cloudburst's rain-rate cell prints \"at the rate of inch per segment, or 1 inch of rainfall in 1 round\" - the clauses conflict (a round is six segments); the clean per-round clause is pinned (1 inch per round), the per-segment rate fragment is an OCR hole. - cloudburst's material cell scrambles two columns (\"for sion the spell holy are\") - the material decodes as silver and powdered iodine crystals plus the cleric's holy symbol. - flame walk's stat cells print inverted (the value \"5 segments\" precedes its \"Casting Time:\" label) - decoded as the casting time. - flame walk's lead sentence is column-scrambled: the readable fragments give the man-size/mass empowerment and the magical fires up to 2,000 F; the verb phrase is an OCR hole. The halfling fragment \"Va hu-\" = 1/2 human; the \"apiece, and pi\" fragments stay unresolved. - negative plane protection's lead paragraph interleaves two columns (\"partially Il protected enabl the caster from an or undead any other mon-el-igible creature touched be\") - decoded as: the caster partially protects an otherwise eligible creature touched from an undead or any other monster with an existence on the Negative Material Plane. - meld into stone's duration is corroborated in-round: the stat cell \"8 rounds + 1-8\" matches the clean prose \"9-16 (1d8 + 8) rounds\". - the remove paralysis header prints \" Reversible\" on the name line; pinned verbatim in the name string.  OCR holes (the item stays open - the 4th-7th levels pin in later rounds; these stay pending the PDF): the cloudburst range cell and the per-segment rain rate; the flame walk lead verb phrase and the \"apiece, and pi\" fragments; the water walk casting-time numeral (the cell prints \"Casting / segments\"); the meld into stone casting-time family decode.",
    },
  "consts" = { {
      "name" = "uac3CloudName",
      "value" = "Cloudburst (Alteration)",
      "comment" = "---- cloudburst (Alteration), p. 36-37 ----",
    }, {
      "name" = "uac3CloudCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac3CloudDurationRounds",
      "value" = 1,
      "comment" = "The duration prints \"7 round\" - the digit-garble family decodes 1 round (corroborated: the hot-and-humid extension to 2 rounds).",
    }, {
      "name" = "uac3CloudCylinderDiameterInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac3CloudCylinderHeightInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac3CloudRainfallInchesPerRound",
      "value" = 1,
      "comment" = "The rain rate: the per-round clause prints clean; the per-segment rate fragment is an OCR hole.",
    }, {
      "name" = "uac3CloudDrenchWithinSegments",
      "value" = 1,
      "comment" = "Everything in the area is drenched within 1 segment.",
    }, {
      "name" = "uac3CloudMediumFiresOutMinSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac3CloudMediumFiresOutMaxSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac3CloudLargeFiresOutMinSegments",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uac3CloudLargeFiresOutMaxSegments",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uac3CloudPermanentRelightMinRounds",
      "value" = 1,
      "comment" = "Permanent magical fires re-light in 1-2 rounds.",
    }, {
      "name" = "uac3CloudPermanentRelightMaxRounds",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac3CloudSteamAreaMultiplier",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac3CloudSteamCylinderDiameterInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac3CloudSteamCylinderHeightInches",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uac3CloudSteamDamageMin",
      "value" = 1,
      "comment" = "The steam inflicts 1-3 points per round on normal creatures, twice that to cold-dwelling or cold-using creatures.",
    }, {
      "name" = "uac3CloudSteamDamageMax",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac3CloudSteamColdCreatureMultiplier",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac3CloudSteamMinRounds",
      "value" = 2,
      "comment" = "The steam persists 2-5 rounds, half that in a breeze, only 1 round in a strong wind.",
    }, {
      "name" = "uac3CloudSteamMaxRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac3CloudHotHumidDurationRounds",
      "value" = 2,
      "comment" = "In hot and humid areas the duration extends to 2 rounds.",
    }, {
      "name" = "uac3CloudSleetHighF",
      "value" = 33,
      "comment" = "33-31 F inclusive: sleet rather than rain, with ice and slush formed when it accumulates. 30 F and lower: a snowburst, one inch of snow per segment.",
    }, {
      "name" = "uac3CloudSleetLowF",
      "value" = 31,
      "comment" = "",
    }, {
      "name" = "uac3CloudSnowAtOrBelowF",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uac3CloudSnowInchesPerSegment",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3DeathsDoorName",
      "value" = "Death's Door (Necromantic)",
      "comment" = "---- death's door (Necromantic), p. 37 ----",
    }, {
      "name" = "uac3DeathsDoorRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac3DeathsDoorDurationHoursPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 hour/level\" - the family decodes 1 hour/level.",
    }, {
      "name" = "uac3DeathsDoorCastingTimeSegments",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac3DeathsDoorDoorLowestHp",
      "value" = -9,
      "comment" = "Touches a human or demi-human unconscious and \"at death's door\" (-1 to -9 hit points); the spell immediately brings the individual to 0 hit points.",
    }, {
      "name" = "uac3DeathsDoorDoorHighestHp",
      "value" = -1,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkName",
      "value" = "Flame Walk (Alteration)",
      "comment" = "---- flame walk (Alteration), p. 37 ----",
    }, {
      "name" = "uac3FlameWalkRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkDurationBaseTurns",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkCastingTimeSegments",
      "value" = 5,
      "comment" = "The stat cells print inverted - the value precedes its label.",
    }, {
      "name" = "uac3FlameWalkMaxTempF",
      "value" = 2000,
      "comment" = "The readable fragments: magical fires up to 2,000 F, and a +2 bonus to saving throws against magical fires.",
    }, {
      "name" = "uac3FlameWalkSaveBonusVsMagicalFire",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkMinCasterLevel",
      "value" = 5,
      "comment" = "For every level above the minimum (5th) the caster affects an additional man-sized creature.",
    }, {
      "name" = "uac3FlameWalkExtraCreaturesPerLevelAbove",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkExampleCasterLevel",
      "value" = 11,
      "comment" = "The 11th-level example: the caster and a steed such as a horse moving in molten lava.",
    }, {
      "name" = "uac3FlameWalkHorseEqualsHumans",
      "value" = 6,
      "comment" = "A horse counts as 6 humans for purposes of this spell; the halfling fragment \"Va hu-\" decodes as 1/2 human each.",
    }, {
      "name" = "uac3FlameWalkRubyMinValueGp",
      "value" = 500,
      "comment" = "",
    }, {
      "name" = "uac3VestmentName",
      "value" = "Magical Vestment (Conjuration/Alteration)",
      "comment" = "---- magical vestment (Conjuration/Alteration), p. 37 ----",
    }, {
      "name" = "uac3VestmentRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac3VestmentCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uac3VestmentDurationRoundsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac3VestmentEnchantmentPerFourLevels",
      "value" = 1,
      "comment" = "With no other protection worn: +1 enchantment per four levels, to a maximum of chain mail +4 (base AC 1).",
    }, {
      "name" = "uac3VestmentMaxEnchantment",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac3VestmentBaseAcAtMax",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3MeldName",
      "value" = "Meld Into Stone (Alteration)",
      "comment" = "---- meld into stone (Alteration), p. 37-38 ----",
    }, {
      "name" = "uac3MeldRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac3MeldCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segments\" - the family decodes 1 segment; no independent corroboration this round, verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac3MeldDurationBaseRounds",
      "value" = 8,
      "comment" = "The duration: stat cell \"8 rounds + 1-8\" = the prose \"9-16 (1d8 + 8) rounds\", the variable part rolled secretly by the DM.",
    }, {
      "name" = "uac3MeldDurationMinRounds",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uac3MeldDurationMaxRounds",
      "value" = 16,
      "comment" = "",
    }, {
      "name" = "uac3MeldGearMaxPounds",
      "value" = 100,
      "comment" = "The cleric and up to 100 pounds of non-living gear blend into the stone; magical artifacts and relics are not affected.",
    }, {
      "name" = "uac3MeldExpelDamageMin",
      "value" = 4,
      "comment" = "Duration expiry: expelled, 4-32 (4d8) points of damage, and each piece of gear must save versus petrification or turn to stone.",
    }, {
      "name" = "uac3MeldExpelDamageMax",
      "value" = 32,
      "comment" = "",
    }, {
      "name" = "uac3MeldStoneShapeDamageMin",
      "value" = 4,
      "comment" = "Stone shape: 4-16 (4d4) points of damage, but no expulsion.",
    }, {
      "name" = "uac3MeldStoneShapeDamageMax",
      "value" = 16,
      "comment" = "",
    }, {
      "name" = "uac3NppName",
      "value" = "Negative Plane Protection (Abjuration)",
      "comment" = "---- negative plane protection (Abjuration), p. 38 ----",
    }, {
      "name" = "uac3NppRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac3NppCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uac3NppDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 turn/level\" - the family decodes 1 turn/level, corroborated by the clean prose (\"will last for 1 turn per level of the cleric casting the spell\").",
    }, {
      "name" = "uac3NppNmpMonsterExamples",
      "value" = "shadow, wight, wraith, spectre, vampire",
      "comment" = "",
    }, {
      "name" = "uac3NppUndeadTakesDamageMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac3NppUndeadTakesDamageMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac3RemParName",
      "value" = "Remove Paralysis (Abjuration) Reversible",
      "comment" = "---- remove paralysis (Abjuration) Reversible, p. 38 ----",
    }, {
      "name" = "uac3RemParRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3RemParCastingTimeSegments",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac3RemParMaxTargets",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac3RemParAreaSquareInches",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac3RemParSaveBonusOneTarget",
      "value" = 3,
      "comment" = "Each target obtains a new saving throw versus paralyzation: +3 if one creature, +2 if two, +1 if three or four.",
    }, {
      "name" = "uac3RemParSaveBonusTwoTargets",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac3RemParSaveBonusThreeOrFour",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3RemParReverseDurationMinRounds",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3RemParReverseDurationMaxRounds",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac3RemParReverseExtraRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkName",
      "value" = "Water Walk (Alteration)",
      "comment" = "---- water walk (Alteration), p. 38 ----",
    }, {
      "name" = "uac3WaterWalkRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkDurationBaseTurns",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkMinCasterLevel",
      "value" = 5,
      "comment" = "For every level above the minimum (5th) the caster affects an additional man-sized creature; the 11th-level example adds a horse (6 humans) so the caster moves atop the waves mounted.",
    }, {
      "name" = "uac3WaterWalkExtraCreaturesPerLevelAbove",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkExampleCasterLevel",
      "value" = 11,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkHorseEqualsHumans",
      "value" = 6,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uac3CloudComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3CloudSmallFiresOutInstantly",
      "value" = true,
      "comment" = "Normal fires: small ones out instantly, medium in 3-5 segments, large-sized in 8-10 segments.",
    }, {
      "name" = "uac3CloudMagicalFiresExtinguished",
      "value" = true,
      "comment" = "Magical fires are also extinguished.",
    }, {
      "name" = "uac3CloudRekindlableDuringOnly",
      "value" = true,
      "comment" = "Rekindlable magical fires (a flame tongue sword) are affected only during the actual cloudburst.",
    }, {
      "name" = "uac3CloudNegatesProduceFireBurningHands",
      "value" = true,
      "comment" = "Produce fire and burning hands are negated.",
    }, {
      "name" = "uac3CloudLargeAreaSpellsMakeSteam",
      "value" = true,
      "comment" = "Large-area spells (fireball, flame strike, wall of fire) vaporize the rain into steam of four times the area: a cylinder up to 12 inches in diameter and as much as 24 inches high.",
    }, {
      "name" = "uac3CloudSteamBreezeHalves",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3CloudSteamStrongWindOneRound",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3CloudAridDoubleStrengthPrecipitation",
      "value" = true,
      "comment" = "In arid regions the cloudburst acts only as a double-strength precipitation spell.",
    }, {
      "name" = "uac3CloudMaterialSilverIodineSymbol",
      "value" = true,
      "comment" = "The material cell scrambles - the material decodes as silver and powdered iodine crystals plus the cleric's holy symbol.",
    }, {
      "name" = "uac3CloudRangeLost",
      "value" = true,
      "comment" = "The range cell prints empty - a hole.",
    }, {
      "name" = "uac3CloudSegmentRateHole",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3DeathsDoorComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3DeathsDoorBringsToZeroHp",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3DeathsDoorBleedingStopped",
      "value" = true,
      "comment" = "While unconscious, bleeding and deterioration are stopped for the duration.",
    }, {
      "name" = "uac3DeathsDoorDeteriorationStopped",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3DeathsDoorRestorableByCureMagic",
      "value" = true,
      "comment" = "The subject at 0 hit points can be brought to consciousness and have hit points restored by cure light wounds, cure serious wounds, healing, etc., or clerical or other items which magically restore lost hit points.",
    }, {
      "name" = "uac3DeathsDoorMaterialSymbolLinenUnguent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkEmpowersManSizeCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkHalflingHalfHuman",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3FlameWalkMaterialRubyAndSymbol",
      "value" = true,
      "comment" = "The material: powdered ruby and the cleric's holy/unholy symbol; the fragments give the ruby at least 500 gp.",
    }, {
      "name" = "uac3FlameWalkLeadSentenceLost",
      "value" = true,
      "comment" = "The lead sentence's verb phrase is column-scrambled - a hole.",
    }, {
      "name" = "uac3VestmentComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3VestmentProtectsAsArmor",
      "value" = true,
      "comment" = "Enchants the caster's vestment, providing protection equivalent to armor; functions only on ground consecrated to the cleric's deity (cf. the 1st-level ceremony spell).",
    }, {
      "name" = "uac3VestmentRequiresConsecratedGround",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3VestmentCfCeremonySpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3VestmentArmorWornMeansPlainChain",
      "value" = true,
      "comment" = "If any armor or protective device is worn, the vestment protects as normal chain mail only.",
    }, {
      "name" = "uac3VestmentEndsIfUnconscious",
      "value" = true,
      "comment" = "Lasts 6 rounds per level, or until the caster loses consciousness or leaves the consecrated area.",
    }, {
      "name" = "uac3VestmentEndsIfLeavesArea",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3VestmentMaterialVestmentAndSymbol",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldCastingTimeFamilyDecode",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldDurationRolledSecretly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldStoneMustFitBody3D",
      "value" = true,
      "comment" = "The stone must be large enough to accommodate the cleric's body in all three dimensions, and the cleric holds a small sample of the same type of stone while casting.",
    }, {
      "name" = "uac3MeldRequiresStoneSample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldArtifactsNotAffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldFailsIfStoneTooSmall",
      "value" = true,
      "comment" = "Insufficient stone dimensions or more than 100 pounds of gear: the spell fails and is wasted.",
    }, {
      "name" = "uac3MeldFailsIfGearTooHeavy",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldExitSameSurfaceOnly",
      "value" = true,
      "comment" = "The cleric steps out along the same surface used to enter - no movement through the stone (cf. passwall or phase door).",
    }, {
      "name" = "uac3MeldNoMovementThroughStone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldGearSavesVsPetrification",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldAwareOfTimePassage",
      "value" = true,
      "comment" = "While in the stone: aware of the passage of time, but cannot see or hear anything around the stone.",
    }, {
      "name" = "uac3MeldCannotSeeOrHear",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldStoneToFleshExpels",
      "value" = true,
      "comment" = "Stone to flesh: expels the cleric, 4-32 points of damage, but items carried need not save.",
    }, {
      "name" = "uac3MeldStoneToFleshItemsExempt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldStoneShapeDoesNotExpel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3MeldTransmuteExpels",
      "value" = true,
      "comment" = "Transmute rock to mud: expels the cleric and slays instantly unless the saving throw versus spell succeeds.",
    }, {
      "name" = "uac3MeldTransmuteSlaysUnlessSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppTargetPrimeMaterialOnly",
      "value" = true,
      "comment" = "One Prime Material Plane creature touched.",
    }, {
      "name" = "uac3NppProtectsVsNegativePlaneMonsters",
      "value" = true,
      "comment" = "The scrambled lead decodes: the caster partially protects an otherwise eligible creature touched from an undead or any other monster with an existence on the Negative Material Plane - such as a shadow, wight, wraith, spectre or vampire.",
    }, {
      "name" = "uac3NppOpensPositiveChannel",
      "value" = true,
      "comment" = "The dweomer opens a channel to the Positive Material Plane, whose energy helps offset the undead attack.",
    }, {
      "name" = "uac3NppSaveVsDeathMagic",
      "value" = true,
      "comment" = "Touched (attacked) by an undead creature: a saving throw versus death magic. Success: normal damage from the attack but no loss of experience; additionally the undead creature takes 2-12 (2d6) points of damage from the Positive Plane energy.",
    }, {
      "name" = "uac3NppSuccessNoLevelDrain",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppSuccessNormalDamage",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppOneAttackOnly",
      "value" = true,
      "comment" = "The magic is proof against only one such attack and dissipates after it, whether or not the save succeeds.",
    }, {
      "name" = "uac3NppDissipatesAfterAttack",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppFailedSaveDoublePhysicalDamage",
      "value" = true,
      "comment" = "A failed save: double the usual physical damage plus the normal loss of experience.",
    }, {
      "name" = "uac3NppFailedSaveNormalEnergyDrain",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppBlocksEnergyDrainSpell",
      "value" = true,
      "comment" = "Also protects from a magic-user's energy drain spell, but the magic-user is then not affected.",
    }, {
      "name" = "uac3NppEnergyDrainCasterUnaffected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppFlashAndThunderclap",
      "value" = true,
      "comment" = "The planar contact causes a bright flash and a thunderclap sound; these phenomena cause no damage.",
    }, {
      "name" = "uac3NppPhenomenaCauseNoDamage",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3NppEndsOnSuccessfulAttack",
      "value" = true,
      "comment" = "Lasts 1 turn per level or until the recipient is successfully attacked; cannot be cast on the Negative Material Plane.",
    }, {
      "name" = "uac3NppNotCastableOnNegativePlane",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParComponentsVS",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParRemovesHoldSpell",
      "value" = true,
      "comment" = "Frees subjects from paralysis or similar forces (such as a hold spell); as many as 4 creatures within range and within a 2-inch by 2-inch area of effect.",
    }, {
      "name" = "uac3RemParRequiresLineOfEffect",
      "value" = true,
      "comment" = "No physical or magical barrier may stand between caster and target, or the spell fails and is wasted.",
    }, {
      "name" = "uac3RemParBarrierWastesSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParReverseSingleTarget",
      "value" = true,
      "comment" = "The reverse, cause paralysis: only one target, touched by the cleric (a successful \"to hit\" roll) using the holy/unholy symbol; a failed save versus spell paralyzes for 1-6 rounds plus 1 round per level of the caster.",
    }, {
      "name" = "uac3RemParReverseRequiresTouchHit",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParReverseUsesHolySymbol",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParReverseSaveVsSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3RemParGoodClericsDiscerning",
      "value" = true,
      "comment" = "Good-aligned clerics should be discerning; the spell might be prohibited in certain good-aligned orders.",
    }, {
      "name" = "uac3RemParProhibitedInSomeGoodOrders",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkTreadsOnWaterAsGround",
      "value" = true,
      "comment" = "Tread upon water as if it were firm, grassy ground (cf. the ring of water walking).",
    }, {
      "name" = "uac3WaterWalkCfRingOfWaterWalking",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkMaterialCorkAndSymbol",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac3WaterWalkCastingTimeLost",
      "value" = true,
      "comment" = "The casting-time numeral is lost (the cell prints \"Casting / segments\") - a hole.",
    }, {
      "name" = "uac3R341SeamNoHoles",
      "value" = true,
      "comment" = "The R341 seam: the 3rd-level column is fully readable (20 of 20) - this round has no hole decode.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uac3CloudName'](), \"Cloudburst (Alteration)\") != 0  or  m['uac3CloudComponentsVSM']() != 1  or m['uac3CloudCastingTimeSegments']() != 5  or m['uac3CloudDurationRounds']() != 1  or m['uac3CloudCylinderDiameterInches']() != 3  or m['uac3CloudCylinderHeightInches']() != 6  or m['uac3CloudRainfallInchesPerRound']() != 1  or m['uac3CloudDrenchWithinSegments']() != 1  or  m['uac3CloudSmallFiresOutInstantly']() != 1  or m['uac3CloudMediumFiresOutMinSegments']() != 3  or m['uac3CloudMediumFiresOutMaxSegments']() != 5  or m['uac3CloudLargeFiresOutMinSegments']() != 8  or m['uac3CloudLargeFiresOutMaxSegments']() != 10  or  m['uac3CloudMagicalFiresExtinguished']() != 1  or m['uac3CloudPermanentRelightMinRounds']() != 1  or m['uac3CloudPermanentRelightMaxRounds']() != 2  or  m['uac3CloudRekindlableDuringOnly']() != 1  or  m['uac3CloudNegatesProduceFireBurningHands']() != 1  or  m['uac3CloudLargeAreaSpellsMakeSteam']() != 1  or m['uac3CloudSteamAreaMultiplier']() != 4  or m['uac3CloudSteamCylinderDiameterInches']() != 12  or m['uac3CloudSteamCylinderHeightInches']() != 24  or m['uac3CloudSteamDamageMin']() != 1  or m['uac3CloudSteamDamageMax']() != 3  or m['uac3CloudSteamColdCreatureMultiplier']() != 2  or m['uac3CloudSteamMinRounds']() != 2  or m['uac3CloudSteamMaxRounds']() != 5  or  m['uac3CloudSteamBreezeHalves']() != 1  or  m['uac3CloudSteamStrongWindOneRound']() != 1  or  m['uac3CloudAridDoubleStrengthPrecipitation']() != 1  or m['uac3CloudHotHumidDurationRounds']() != 2  or m['uac3CloudSleetHighF']() != 33  or m['uac3CloudSleetLowF']() != 31  or m['uac3CloudSnowAtOrBelowF']() != 30  or m['uac3CloudSnowInchesPerSegment']() != 1  or  m['uac3CloudMaterialSilverIodineSymbol']() != 1  or  m['uac3CloudRangeLost']() != 1  or  m['uac3CloudSegmentRateHole']() != 1",
      "note" = "U1: cloudburst",
    }, {
      "expr" = "strcmp(m['uac3DeathsDoorName'](), \"Death's Door (Necromantic)\") != 0  or  m['uac3DeathsDoorComponentsVSM']() != 1  or m['uac3DeathsDoorRangeTouch']() != 0  or m['uac3DeathsDoorDurationHoursPerLevel']() != 1  or m['uac3DeathsDoorCastingTimeSegments']() != 5  or m['uac3DeathsDoorDoorLowestHp']() != -9  or m['uac3DeathsDoorDoorHighestHp']() != -1  or  m['uac3DeathsDoorBringsToZeroHp']() != 1  or  m['uac3DeathsDoorBleedingStopped']() != 1  or  m['uac3DeathsDoorDeteriorationStopped']() != 1  or  m['uac3DeathsDoorRestorableByCureMagic']() != 1  or  m['uac3DeathsDoorMaterialSymbolLinenUnguent']() != 1",
      "note" = "U2: death's door",
    }, {
      "expr" = "strcmp(m['uac3FlameWalkName'](), \"Flame Walk (Alteration)\") != 0  or  m['uac3FlameWalkComponentsVSM']() != 1  or m['uac3FlameWalkRangeTouch']() != 0  or m['uac3FlameWalkDurationBaseTurns']() != 1  or m['uac3FlameWalkDurationTurnsPerLevel']() != 1  or m['uac3FlameWalkCastingTimeSegments']() != 5  or m['uac3FlameWalkMaxTempF']() != 2000  or m['uac3FlameWalkSaveBonusVsMagicalFire']() != 2  or  m['uac3FlameWalkEmpowersManSizeCreature']() != 1  or m['uac3FlameWalkMinCasterLevel']() != 5  or m['uac3FlameWalkExtraCreaturesPerLevelAbove']() != 1  or m['uac3FlameWalkExampleCasterLevel']() != 11  or m['uac3FlameWalkHorseEqualsHumans']() != 6  or  m['uac3FlameWalkHalflingHalfHuman']() != 1  or  m['uac3FlameWalkMaterialRubyAndSymbol']() != 1  or m['uac3FlameWalkRubyMinValueGp']() != 500  or  m['uac3FlameWalkLeadSentenceLost']() != 1",
      "note" = "U3: flame walk",
    }, {
      "expr" = "strcmp(m['uac3VestmentName'](), \"Magical Vestment (Conjuration/Alteration)\") != 0  or  m['uac3VestmentComponentsVSM']() != 1  or m['uac3VestmentRangeTouch']() != 0  or m['uac3VestmentCastingTimeRounds']() != 1  or m['uac3VestmentDurationRoundsPerLevel']() != 6  or  m['uac3VestmentProtectsAsArmor']() != 1  or  m['uac3VestmentRequiresConsecratedGround']() != 1  or  m['uac3VestmentCfCeremonySpell']() != 1  or  m['uac3VestmentArmorWornMeansPlainChain']() != 1  or m['uac3VestmentEnchantmentPerFourLevels']() != 1  or m['uac3VestmentMaxEnchantment']() != 4  or m['uac3VestmentBaseAcAtMax']() != 1  or  m['uac3VestmentEndsIfUnconscious']() != 1  or  m['uac3VestmentEndsIfLeavesArea']() != 1  or  m['uac3VestmentMaterialVestmentAndSymbol']() != 1",
      "note" = "U4: magical vestment",
    }, {
      "expr" = "strcmp(m['uac3MeldName'](), \"Meld Into Stone (Alteration)\") != 0  or  m['uac3MeldComponentsVSM']() != 1  or m['uac3MeldRangeTouch']() != 0  or m['uac3MeldCastingTimeSegments']() != 1  or  m['uac3MeldCastingTimeFamilyDecode']() != 1  or m['uac3MeldDurationBaseRounds']() != 8  or m['uac3MeldDurationMinRounds']() != 9  or m['uac3MeldDurationMaxRounds']() != 16  or  m['uac3MeldDurationRolledSecretly']() != 1  or  m['uac3MeldStoneMustFitBody3D']() != 1  or  m['uac3MeldRequiresStoneSample']() != 1  or m['uac3MeldGearMaxPounds']() != 100  or  m['uac3MeldArtifactsNotAffected']() != 1  or  m['uac3MeldFailsIfStoneTooSmall']() != 1  or  m['uac3MeldFailsIfGearTooHeavy']() != 1  or  m['uac3MeldExitSameSurfaceOnly']() != 1  or  m['uac3MeldNoMovementThroughStone']() != 1  or m['uac3MeldExpelDamageMin']() != 4  or m['uac3MeldExpelDamageMax']() != 32  or  m['uac3MeldGearSavesVsPetrification']() != 1  or  m['uac3MeldAwareOfTimePassage']() != 1  or  m['uac3MeldCannotSeeOrHear']() != 1  or  m['uac3MeldStoneToFleshExpels']() != 1  or  m['uac3MeldStoneToFleshItemsExempt']() != 1  or m['uac3MeldStoneShapeDamageMin']() != 4  or m['uac3MeldStoneShapeDamageMax']() != 16  or  m['uac3MeldStoneShapeDoesNotExpel']() != 1  or  m['uac3MeldTransmuteExpels']() != 1  or  m['uac3MeldTransmuteSlaysUnlessSave']() != 1",
      "note" = "U5: meld into stone",
    }, {
      "expr" = "strcmp(m['uac3NppName'](), \"Negative Plane Protection (Abjuration)\") != 0  or  m['uac3NppComponentsVSM']() != 1  or m['uac3NppRangeTouch']() != 0  or m['uac3NppCastingTimeRounds']() != 1  or m['uac3NppDurationTurnsPerLevel']() != 1  or  m['uac3NppTargetPrimeMaterialOnly']() != 1  or  m['uac3NppProtectsVsNegativePlaneMonsters']() != 1  or strcmp(m['uac3NppNmpMonsterExamples'](), \"shadow, wight, wraith, spectre, vampire\") != 0  or  m['uac3NppOpensPositiveChannel']() != 1  or  m['uac3NppSaveVsDeathMagic']() != 1  or  m['uac3NppSuccessNoLevelDrain']() != 1  or  m['uac3NppSuccessNormalDamage']() != 1  or m['uac3NppUndeadTakesDamageMin']() != 2  or m['uac3NppUndeadTakesDamageMax']() != 12  or  m['uac3NppOneAttackOnly']() != 1  or  m['uac3NppDissipatesAfterAttack']() != 1  or  m['uac3NppFailedSaveDoublePhysicalDamage']() != 1  or  m['uac3NppFailedSaveNormalEnergyDrain']() != 1  or  m['uac3NppBlocksEnergyDrainSpell']() != 1  or  m['uac3NppEnergyDrainCasterUnaffected']() != 1  or  m['uac3NppFlashAndThunderclap']() != 1  or  m['uac3NppPhenomenaCauseNoDamage']() != 1  or  m['uac3NppEndsOnSuccessfulAttack']() != 1  or  m['uac3NppNotCastableOnNegativePlane']() != 1",
      "note" = "U6: negative plane protection",
    }, {
      "expr" = "strcmp(m['uac3RemParName'](), \"Remove Paralysis (Abjuration) Reversible\") != 0  or  m['uac3RemParReversible']() != 1  or  m['uac3RemParComponentsVS']() != 1  or m['uac3RemParRangeInchesPerLevel']() != 1  or m['uac3RemParCastingTimeSegments']() != 6  or  m['uac3RemParDurationPermanent']() != 1  or  m['uac3RemParRemovesHoldSpell']() != 1  or m['uac3RemParMaxTargets']() != 4  or m['uac3RemParAreaSquareInches']() != 2  or  m['uac3RemParRequiresLineOfEffect']() != 1  or  m['uac3RemParBarrierWastesSpell']() != 1  or m['uac3RemParSaveBonusOneTarget']() != 3  or m['uac3RemParSaveBonusTwoTargets']() != 2  or m['uac3RemParSaveBonusThreeOrFour']() != 1  or  m['uac3RemParReverseSingleTarget']() != 1  or  m['uac3RemParReverseRequiresTouchHit']() != 1  or  m['uac3RemParReverseUsesHolySymbol']() != 1  or  m['uac3RemParReverseSaveVsSpell']() != 1  or m['uac3RemParReverseDurationMinRounds']() != 1  or m['uac3RemParReverseDurationMaxRounds']() != 6  or m['uac3RemParReverseExtraRoundsPerLevel']() != 1  or  m['uac3RemParGoodClericsDiscerning']() != 1  or  m['uac3RemParProhibitedInSomeGoodOrders']() != 1",
      "note" = "U7: remove paralysis",
    }, {
      "expr" = "strcmp(m['uac3WaterWalkName'](), \"Water Walk (Alteration)\") != 0  or  m['uac3WaterWalkComponentsVSM']() != 1  or m['uac3WaterWalkRangeTouch']() != 0  or m['uac3WaterWalkDurationBaseTurns']() != 1  or m['uac3WaterWalkDurationTurnsPerLevel']() != 1  or  m['uac3WaterWalkTreadsOnWaterAsGround']() != 1  or  m['uac3WaterWalkCfRingOfWaterWalking']() != 1  or m['uac3WaterWalkMinCasterLevel']() != 5  or m['uac3WaterWalkExtraCreaturesPerLevelAbove']() != 1  or m['uac3WaterWalkExampleCasterLevel']() != 11  or m['uac3WaterWalkHorseEqualsHumans']() != 6  or  m['uac3WaterWalkMaterialCorkAndSymbol']() != 1  or  m['uac3WaterWalkCastingTimeLost']() != 1",
      "note" = "U8: water walk",
    }, {
      "expr" = "strcmp(m['uastClericName'](3, 1), \"Cloudburst\") != 0  or strcmp(m['uastClericName'](3, 6), \"Death's Door\") != 0  or strcmp(m['uastClericName'](3, 9), \"Flame Walk\") != 0  or strcmp(m['uastClericName'](3, 12), \"Magical Vestment\") != 0  or strcmp(m['uastClericName'](3, 13), \"Meld Into Stone\") != 0  or strcmp(m['uastClericName'](3, 14), \"Negative Plane Protection\") != 0  or strcmp(m['uastClericName'](3, 17), \"Remove Paralysis\") != 0  or strcmp(m['uastClericName'](3, 19), \"Water Walk\") != 0  or m['uastClericReadableCount'](3) != 20  or  m['uac3R341SeamNoHoles']() != 1",
      "note" = "U9: the R341 table seam",
    } },
  "audit" = {
      "label" = "R345: the UA new cleric 3rd level spells pin audit",
      "comment" = "The UA NEW CLERIC SPELLS (pp. 36-38), the 3rd level - cloudburst (the fire ladder and the steam mechanics), death's door, flame walk (the 2,000 F and the 500 gp ruby), magical vestment (the chain mail +4 ladder), meld into stone (the 9-16 rounds and the expulsion damage), negative plane protection (the 2d6 Positive energy counterstrike), remove paralysis (the +3/+2/+1 save ladder) and water walk. The digit-garble family decodes this round's six 7s as 1; the R341 3rd-level column is fully readable - no hole decode this round. The item stays open (the 4th-7th levels).",
    },
}
