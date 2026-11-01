-- ua359: promoted from rules/uamuspells4.h (the The UA NEW MAGIC-USER SPELLS (pp. 51-66) pins, R359: the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 359,
  "prefix" = "ua359",
  "banner" = {
      "title" = "The UA NEW MAGIC-USER SPELLS (pp. 51-66) pins, R359: the",
      "provenance" = "4th-level spell descriptions - dispel illusion, the Evard black tentacles, the Leomund secure shelter, magic mirror, the Otiluke resilient sphere, shout, stoneskin and ultravision.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the casting-time and duration 7s decode as 1 - the magic mirror \"7 hour\" as 1 hour and \"7 round/level\" as 1 round per level; the shout and stoneskin \"7 segment\" casting times as 1 segment. - the dispel illusion header loses its tail - only \"Dispel (Abjuration)\" prints; the name pins from the prose (dispel an illusion). Its stat block interleaves with secret page (R358-pinned) - the dispel cells pin as level 4, V S, 4 segments, half inch per level (the fraction cell prints garbled), permanent, none, special. - the Evard tentacles stat block prints a stray \"gf\" after the components and loses both the level and the range cells - the level pins from the section heading, the range is a hole pending the PDF. - the Leomund secure shelter prose scrambles the wind and strength sentences; the cells pin clean. - the magic mirror prose scrambles the component list (the hawk, eagle or roc eye; zinc, copper and nitric acid) and the spell-through list; the cells pin, the lists pin from the fragments. - the Otiluke sphere prose head is scrambled - the globe sentence is lost; the effect pins from the surviving tail. - the shout area cell prints 1 inch with the tail scrambled (\"x 3 cone\"); the prose pins the cone radiating from the mouth to a 3 inch terminus. - the stoneskin stat block loses the level and range cells (the level pins from the section heading; the range is a hole pending the PDF) and prints its components, casting time, save and area after the prose - an interleave. - the ultravision prose tail (the 3-foot radius sentence and the amethyst) prints past the 5th level heading; the cells pin clean. - the region also carries the R358-pinned secret page and sepia snake sigil bodies; their pins live in rules/uamuspells3.h.",
    },
  "consts" = { {
      "name" = "uam4DispelName",
      "value" = "Dispel Illusion (Abjuration)",
      "comment" = "---- dispel illusion (Abjuration), the 4th level ---- The header loses its tail - \"Dispel (Abjuration)\" only; the name pins from the prose.",
    }, {
      "name" = "uam4DispelLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4DispelCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4DispelRangeHalfInchesPerLevel",
      "value" = 1,
      "comment" = "The range cell prints a garbled half fraction per level - decoded as half an inch per level.",
    }, {
      "name" = "uam4DispelLevelPenaltyVsIllusionist",
      "value" = 2,
      "comment" = "A magic-user attempting to dispel an illusion is considered at two levels below his actual level with respect to spells cast by an illusionist.",
    }, {
      "name" = "uam4EvardName",
      "value" = "Evard's Black Tentacles (Conjuration/Summoning)",
      "comment" = "---- the Evard black tentacles (Conjuration/Summoning) ----",
    }, {
      "name" = "uam4EvardLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4EvardCastingTimeSegments",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam4EvardDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam4EvardAoeSqFtPerLevel",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uam4EvardTentacleFeet",
      "value" = 10,
      "comment" = "Each tentacle is 10 feet long (the degree family), AC 4, and takes as many points of damage to destroy as the caster has levels of experience.",
    }, {
      "name" = "uam4EvardTentacleAc",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4EvardDamageOnSaveMin",
      "value" = 1,
      "comment" = "Save success: 1-4 damage from initial contact and the tentacle is destroyed. Failure: 2-8 damage, the member wraps its victim, and 3-12 points on the second and succeeding rounds.",
    }, {
      "name" = "uam4EvardDamageOnSaveMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4EvardDamageOnFailMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam4EvardDamageOnFailMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam4EvardDamageWrappedMin",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam4EvardDamageWrappedMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam4ShelterName",
      "value" = "Leomund's Secure Shelter (Alteration - Enchantment)",
      "comment" = "---- the Leomund secure shelter (Alteration/Enchantment) ----",
    }, {
      "name" = "uam4ShelterLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4ShelterCastingTimeTurns",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4ShelterRangeInches",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam4ShelterDurationTurnsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam4ShelterAoeSqFtPerLevel",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uam4ShelterWindResistanceMph",
      "value" = 70,
      "comment" = "The scrambled prose: the lodging is secure against winds of up to natural 70 miles per hour.",
    }, {
      "name" = "uam4ShelterBunksMax",
      "value" = 8,
      "comment" = "Crude furnishings as desired: up to 8 bunks, a trestle table and benches, as many as 4 chairs or 8 stools, and a writing desk.",
    }, {
      "name" = "uam4ShelterChairsMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4ShelterStoolsMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam4MirrorName",
      "value" = "Magic Mirror (Enchantment - Divination)",
      "comment" = "---- magic mirror (Enchantment/Divination), the 4th ----",
    }, {
      "name" = "uam4MirrorLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4MirrorCastingTimeHours",
      "value" = 1,
      "comment" = "The casting time prints \"7 hour\" - the family decodes 1 hour.",
    }, {
      "name" = "uam4MirrorDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam4MirrorSilverCostGpMin",
      "value" = 1000,
      "comment" = "The mirror must be finely wrought, highly polished silver of a minimum cost of 1,000 gp; the mirror is not harmed by the casting - the other components are.",
    }, {
      "name" = "uam4MirrorPctPerLevel",
      "value" = 5,
      "comment" = "The following have a 5% chance per level of the caster of operating correctly: detect magic, detect good/evil, message, and detect illusion.",
    }, {
      "name" = "uam4MirrorCavalierDetectPct",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam4MirrorBarbarianDetectPct",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeName",
      "value" = "Otiluke's Resilient Sphere (Alteration - Evocation)",
      "comment" = "---- the Otiluke resilient sphere (Alteration/Evocation) ----",
    }, {
      "name" = "uam4OtilukeLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeRangeInches",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round/level\" - the family decodes 1 round per level.",
    }, {
      "name" = "uam4OtilukeSphereFeetPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam4ShoutName",
      "value" = "Shout (Evocation)",
      "comment" = "---- shout (Evocation), the 4th level ----",
    }, {
      "name" = "uam4ShoutLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4ShoutAoeTerminusInches",
      "value" = 3,
      "comment" = "The area cell prints 1 inch with the tail scrambled (\"x 3 cone\"); the prose pins the cone radiating from the mouth to a 3 inch terminus.",
    }, {
      "name" = "uam4ShoutCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segment\" - the family decodes 1 segment.",
    }, {
      "name" = "uam4ShoutDeafenRoundsMin",
      "value" = 2,
      "comment" = "The caster releases an ear-splitting noise; any creature in the cone is deafened for 2-12 rounds and takes a like 2-12 points of damage unless a save is made.",
    }, {
      "name" = "uam4ShoutDeafenRoundsMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam4ShoutDamageMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam4ShoutDamageMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinName",
      "value" = "Stoneskin (Alteration)",
      "comment" = "---- stoneskin (Alteration), the 4th level ----",
    }, {
      "name" = "uam4StoneskinLevel",
      "value" = 4,
      "comment" = "The stat block loses the level and range cells; the level pins from the section heading, the range is a hole pending the PDF.",
    }, {
      "name" = "uam4StoneskinCastingTimeSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinSoftWeaponDamageMin",
      "value" = 1,
      "comment" = "Relatively soft weapons - a monk's hands, an ogrillon's fist - inflict 1-2 points on the attacker per attack and do not dispel the dweomer.",
    }, {
      "name" = "uam4StoneskinSoftWeaponDamageMax",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionName",
      "value" = "Ultravision (Alteration)",
      "comment" = "---- ultravision (Alteration), the 4th level ----",
    }, {
      "name" = "uam4UltravisionLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionCastingTimeSegments",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionDurationTurnsMin",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionDurationTurnsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionClearYards",
      "value" = 100,
      "comment" = "In night conditions vision is clear, as if daylight, to 100 yards, and shadowy and indistinct from beyond 100 yards to about 300 yards.",
    }, {
      "name" = "uam4UltravisionShadowyYards",
      "value" = 300,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionDarkNightReductionPct",
      "value" = 50,
      "comment" = "A very dark night with thick clouds overhead reduces ultravisual sight by 50%.",
    }, {
      "name" = "uam4UltravisionEarthFeet",
      "value" = 6,
      "comment" = "Where more than about 6 feet of earth or 3 feet of stone interpose between the sky and the individual - virtually any underground area - only vision of the dimmest sort in about a 3-foot radius, the rays screened out.",
    }, {
      "name" = "uam4UltravisionStoneFeet",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionUndergroundRadiusFeet",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionMaterialAmethystGp",
      "value" = 500,
      "comment" = "The material: a crushed amethyst of at least 500 gp value.",
    } },
  "bools" = { {
      "name" = "uam4DispelNameHeaderTailLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4DispelStatInterleavedWithSecretPage",
      "value" = true,
      "comment" = "The stat block interleaves with secret page (R358).",
    }, {
      "name" = "uam4DispelComponentsVS",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4DispelRangeFractionGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4DispelDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4DispelSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4DispelAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4DispelSameAsIllusionist3rd",
      "value" = true,
      "comment" = "The spell is similar to the 3rd-level illusionist spell of the same name; no illusionist seam exists yet.",
    }, {
      "name" = "uam4EvardLevelCellLost",
      "value" = true,
      "comment" = "The level and range cells are lost; the level pins from the section heading, the range is a hole pending the PDF.",
    }, {
      "name" = "uam4EvardRangeCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4EvardStrayGfLine",
      "value" = true,
      "comment" = "A stray \"gf\" prints after the components line.",
    }, {
      "name" = "uam4EvardComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4EvardSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4EvardSpringsFromAnySurface",
      "value" = true,
      "comment" = "Many rubbery, black tentacles spring forth from the earth, floor or whatever surface is underfoot - including water.",
    }, {
      "name" = "uam4EvardTentacleHpPerCasterLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4EvardOneTentaclePerLevel",
      "value" = true,
      "comment" = "One tentacle for each of the caster's levels.",
    }, {
      "name" = "uam4EvardMultiTargetDieRoll",
      "value" = true,
      "comment" = "Any creature within range is subject to attack; with more than one target in range, the probability is determined by die roll.",
    }, {
      "name" = "uam4EvardMayEntwineObjects",
      "value" = true,
      "comment" = "With no intelligence to guide them, the tentacles may entwine any object - a tree, post, pillar - or continue to squeeze a dead opponent.",
    }, {
      "name" = "uam4EvardContinuesSqueezingDead",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4EvardMaterialOctopusOrSquidTentacle",
      "value" = true,
      "comment" = "The component (printing in the sepia interleave): a piece of tentacle from a giant octopus or giant squid.",
    }, {
      "name" = "uam4ShelterComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterCottageOfLocalMaterial",
      "value" = true,
      "comment" = "The spell magically calls into being a sturdy cottage or lodge of material common in the area - stone, timber, or (at worst) sod.",
    }, {
      "name" = "uam4ShelterFloorLevelCleanDry",
      "value" = true,
      "comment" = "The floor area is 30 square feet per level, level, clean and dry; a sturdy door, two or more shuttered windows, and a small fireplace.",
    }, {
      "name" = "uam4ShelterDoorWindowsFireplace",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterWindSentenceScrambled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterNoHeatingQualities",
      "value" = true,
      "comment" = "The lodging has no heating qualities - it must be heated as a normal dwelling, and extreme heat will affect it and its occupants adversely.",
    }, {
      "name" = "uam4ShelterStrongAsStone",
      "value" = true,
      "comment" = "It is as strong as a normal stone building regardless of material, resists flames and fire as if stone, and is impervious to normal missiles (but not siege machinery or giants).",
    }, {
      "name" = "uam4ShelterResistsFlamesAsStone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterImperviousToNormalMissiles",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterDoorShuttersWizardLocked",
      "value" = true,
      "comment" = "The door and shutters are wizard locked; the chimney is secured by a top grate of iron and a narrow flue; the three areas are protected by an alarm spell.",
    }, {
      "name" = "uam4ShelterChimneyGrateAndFlue",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterAlarmProtected",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterUnseenServant",
      "value" = true,
      "comment" = "An unseen servant is called up to serve the caster.",
    }, {
      "name" = "uam4ShelterTrestleTableAndDesk",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShelterMaterialStoneLimeSandWaterWood",
      "value" = true,
      "comment" = "The materials: a square chip of stone, crushed lime, a few grains of sand, a sprinkling of water, and several splinters of wood.",
    }, {
      "name" = "uam4ShelterMaterialAugmentedByAlarmServant",
      "value" = true,
      "comment" = "Augmented by the alarm and unseen servant components if included: string, silver wire, and a small bell.",
    }, {
      "name" = "uam4MirrorComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorMirrorBecomesScryingDevice",
      "value" = true,
      "comment" = "The spell changes a normal mirror into a scrying device similar to a crystal ball (the details on p. 141 of the DMG).",
    }, {
      "name" = "uam4MirrorNotHarmedByCasting",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorMaterialEyeOfHawkEagleRoc",
      "value" = true,
      "comment" = "The component list scrambles: the eye of a hawk, an eagle, or even a roc; zinc, copper, and nitric acid.",
    }, {
      "name" = "uam4MirrorMaterialZincCopperNitricAcid",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorComponentListScrambled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorCastsThroughComprehend",
      "value" = true,
      "comment" = "2nd-level spells can be cast through a magic mirror: comprehend languages, tongues, infravision, and ultravision.",
    }, {
      "name" = "uam4MirrorCastsThroughTonguesInfravisionUltravision",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorDetectSpellsByChance",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4MirrorTargetMayDetectScrying",
      "value" = true,
      "comment" = "There is a chance of the target realizing he or she is being watched - the base chance per the crystal ball item description; a cavalier has a base 5% chance of detecting scrying, a barbarian a base 1% chance.",
    }, {
      "name" = "uam4OtilukeComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeSaveNeg",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeProseHeadScrambled",
      "value" = true,
      "comment" = "The prose head scrambles - the globe sentence is lost; the subject is small enough to fit within the diameter of the sphere.",
    }, {
      "name" = "uam4OtilukeSubjectFitsWithin",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeNotDamagedNormally",
      "value" = true,
      "comment" = "The sphere persists as long as its dweomer persists; the subject is not subject to damage of any sort except from a rod of cancellation, a wand of negation, or a disintegrate or dispel magic spell - which destroy it without harm to the subject.",
    }, {
      "name" = "uam4OtilukeDestroyedByNegationOrDispel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeDestroyedWithoutHarm",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeNothingPassesThrough",
      "value" = true,
      "comment" = "Nothing can pass through the sphere, inside or out, and the target can breathe normally.",
    }, {
      "name" = "uam4OtilukeSubjectBreathes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeStruggleMovesSphereOnly",
      "value" = true,
      "comment" = "The subject may struggle, but all that occurs is movement of the sphere; it can be physically moved from outside or by the struggles of those within.",
    }, {
      "name" = "uam4OtilukeMovableFromOutsideOrWithin",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4OtilukeMaterialDiamondHemisphere",
      "value" = true,
      "comment" = "The components: a hemispherical piece of diamond (or similar hard, clear gem material) and a matching hemispherical piece of gum arabic.",
    }, {
      "name" = "uam4OtilukeMaterialGumArabicHemisphere",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShoutRangeZero",
      "value" = true,
      "comment" = "The range cell prints 0.",
    }, {
      "name" = "uam4ShoutDurationInstantaneous",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShoutAoeCellScrambled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShoutConeFromTheMouth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShoutComponentsVM",
      "value" = true,
      "comment" = "The components cell prints V, M after the prose - an interleave.",
    }, {
      "name" = "uam4ShoutStatTailInterleaved",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShoutSaveNeg",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShoutShattersBrittleSubstances",
      "value" = true,
      "comment" = "Exposed brittle or similar substance subject to sonic vibrations shatters - e.g. a wall of ice.",
    }, {
      "name" = "uam4ShoutWallOfIceExample",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4ShoutOncePerDay",
      "value" = true,
      "comment" = "Usable but once per day, else the caster might permanently deafen himself or herself.",
    }, {
      "name" = "uam4ShoutMaterialHoneyAcidHornCone",
      "value" = true,
      "comment" = "The materials: a drop of honey, a drop of citric acid, and a small cone made from a bull's or ram's horn.",
    }, {
      "name" = "uam4StoneskinLevelCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinRangeCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinStatTailInterleaved",
      "value" = true,
      "comment" = "The components, casting time, save and area print after the prose - an interleave.",
    }, {
      "name" = "uam4StoneskinComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinImmuneToPhysicalAttacks",
      "value" = true,
      "comment" = "The affected creature gains virtual immunity to any attack by cut, blow, projectile or the like - even a sword of sharpness, a giant-hurled rock, a snake's strike.",
    }, {
      "name" = "uam4StoneskinSwordOfSharpnessIneffective",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinMagicAttacksNormal",
      "value" = true,
      "comment" = "Magic attacks - fireball, magic missile, lightning bolt, and so forth - have normal effect.",
    }, {
      "name" = "uam4StoneskinOneOpponentDispels",
      "value" = true,
      "comment" = "Any attack or attack sequence from a single opponent dispels the dweomer, although it makes the creature immune to that single attack or sequence.",
    }, {
      "name" = "uam4StoneskinImmuneToThatAttack",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinSoftWeaponsDoNotDispels",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4StoneskinMaterialGraniteDiamondDust",
      "value" = true,
      "comment" = "The materials: granite and diamond dust sprinkled on the recipient's skin.",
    }, {
      "name" = "uam4UltravisionComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionSeesUltraviolet",
      "value" = true,
      "comment" = "The recipient sees radiation in the ultraviolet spectrum.",
    }, {
      "name" = "uam4UltravisionUndergroundDimOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam4UltravisionEmissionSourceImproves",
      "value" = true,
      "comment" = "An emission source nearby improves the visual capabilities accordingly.",
    }, {
      "name" = "uam4UltravisionNearbyLightSpoils",
      "value" = true,
      "comment" = "Nearby light, including the radiance shed by magic items, spoils ultravision - the brightness blinding the eyes to dimmer, more distant areas.",
    }, {
      "name" = "uam4UltravisionTailPastFifthHeading",
      "value" = true,
      "comment" = "The prose tail (the 3-foot radius sentence and the amethyst) prints past the 5th level heading.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uam4DispelName'](), \"Dispel Illusion (Abjuration)\") != 0  or  m['uam4DispelNameHeaderTailLost']() != 1  or m['uam4DispelLevel']() != 4  or  m['uam4DispelStatInterleavedWithSecretPage']() != 1  or  m['uam4DispelComponentsVS']() != 1  or m['uam4DispelCastingTimeSegments']() != 4  or m['uam4DispelRangeHalfInchesPerLevel']() != 1  or  m['uam4DispelRangeFractionGarbled']() != 1  or  m['uam4DispelDurationPermanent']() != 1  or  m['uam4DispelSaveNone']() != 1  or  m['uam4DispelAoeSpecial']() != 1  or  m['uam4DispelSameAsIllusionist3rd']() != 1  or m['uam4DispelLevelPenaltyVsIllusionist']() != 2",
      "note" = "U1: dispel illusion",
    }, {
      "expr" = "strcmp(m['uam4EvardName'](), \"Evard's Black Tentacles (Conjuration/Summoni\" \"ng)\") != 0  or m['uam4EvardLevel']() != 4  or  m['uam4EvardLevelCellLost']() != 1  or  m['uam4EvardRangeCellLost']() != 1  or  m['uam4EvardStrayGfLine']() != 1  or  m['uam4EvardComponentsVSM']() != 1  or m['uam4EvardCastingTimeSegments']() != 8  or  m['uam4EvardSaveNone']() != 1  or m['uam4EvardDurationRoundsPerLevel']() != 1  or m['uam4EvardAoeSqFtPerLevel']() != 30  or  m['uam4EvardSpringsFromAnySurface']() != 1  or m['uam4EvardTentacleFeet']() != 10  or m['uam4EvardTentacleAc']() != 4  or  m['uam4EvardTentacleHpPerCasterLevel']() != 1  or  m['uam4EvardOneTentaclePerLevel']() != 1  or  m['uam4EvardMultiTargetDieRoll']() != 1  or m['uam4EvardDamageOnSaveMin']() != 1  or m['uam4EvardDamageOnSaveMax']() != 4  or m['uam4EvardDamageOnFailMin']() != 2  or m['uam4EvardDamageOnFailMax']() != 8  or m['uam4EvardDamageWrappedMin']() != 3  or m['uam4EvardDamageWrappedMax']() != 12  or  m['uam4EvardMayEntwineObjects']() != 1  or  m['uam4EvardContinuesSqueezingDead']() != 1  or  m['uam4EvardMaterialOctopusOrSquidTentacle']() != 1",
      "note" = "U2: the Evard black tentacles",
    }, {
      "expr" = "strcmp(m['uam4ShelterName'](), \"Leomund's Secure Shelter (Alteration - Encha\" \"ntment)\") != 0  or m['uam4ShelterLevel']() != 4  or  m['uam4ShelterComponentsVSM']() != 1  or m['uam4ShelterCastingTimeTurns']() != 4  or m['uam4ShelterRangeInches']() != 2  or  m['uam4ShelterSaveNone']() != 1  or m['uam4ShelterDurationTurnsPerLevel']() != 6  or m['uam4ShelterAoeSqFtPerLevel']() != 30  or  m['uam4ShelterCottageOfLocalMaterial']() != 1  or  m['uam4ShelterFloorLevelCleanDry']() != 1  or  m['uam4ShelterDoorWindowsFireplace']() != 1  or m['uam4ShelterWindResistanceMph']() != 70  or  m['uam4ShelterWindSentenceScrambled']() != 1  or  m['uam4ShelterNoHeatingQualities']() != 1  or  m['uam4ShelterStrongAsStone']() != 1  or  m['uam4ShelterResistsFlamesAsStone']() != 1  or  m['uam4ShelterImperviousToNormalMissiles']() != 1  or  m['uam4ShelterDoorShuttersWizardLocked']() != 1  or  m['uam4ShelterChimneyGrateAndFlue']() != 1  or  m['uam4ShelterAlarmProtected']() != 1  or  m['uam4ShelterUnseenServant']() != 1  or m['uam4ShelterBunksMax']() != 8  or m['uam4ShelterChairsMax']() != 4  or m['uam4ShelterStoolsMax']() != 8  or  m['uam4ShelterTrestleTableAndDesk']() != 1  or  m['uam4ShelterMaterialStoneLimeSandWaterWood']() != 1  or  m['uam4ShelterMaterialAugmentedByAlarmServant']() != 1",
      "note" = "U3: the Leomund secure shelter",
    }, {
      "expr" = "strcmp(m['uam4MirrorName'](), \"Magic Mirror (Enchantment - Divination)\") != 0  or m['uam4MirrorLevel']() != 4  or  m['uam4MirrorComponentsVSM']() != 1  or m['uam4MirrorCastingTimeHours']() != 1  or  m['uam4MirrorRangeTouch']() != 1  or  m['uam4MirrorSaveNone']() != 1  or m['uam4MirrorDurationRoundsPerLevel']() != 1  or  m['uam4MirrorAoeSpecial']() != 1  or  m['uam4MirrorMirrorBecomesScryingDevice']() != 1  or m['uam4MirrorSilverCostGpMin']() != 1000  or  m['uam4MirrorNotHarmedByCasting']() != 1  or  m['uam4MirrorMaterialEyeOfHawkEagleRoc']() != 1  or  m['uam4MirrorMaterialZincCopperNitricAcid']() != 1  or  m['uam4MirrorComponentListScrambled']() != 1  or  m['uam4MirrorCastsThroughComprehend']() != 1  or  m['uam4MirrorCastsThroughTonguesInfravisionUltravision']() != 1  or m['uam4MirrorPctPerLevel']() != 5  or  m['uam4MirrorDetectSpellsByChance']() != 1  or  m['uam4MirrorTargetMayDetectScrying']() != 1  or m['uam4MirrorCavalierDetectPct']() != 5  or m['uam4MirrorBarbarianDetectPct']() != 1",
      "note" = "U4: magic mirror",
    }, {
      "expr" = "strcmp(m['uam4OtilukeName'](), \"Otiluke's Resilient Sphere (Alteration - Evo\" \"cation)\") != 0  or m['uam4OtilukeLevel']() != 4  or  m['uam4OtilukeComponentsVSM']() != 1  or m['uam4OtilukeCastingTimeSegments']() != 4  or m['uam4OtilukeRangeInches']() != 2  or  m['uam4OtilukeSaveNeg']() != 1  or m['uam4OtilukeDurationRoundsPerLevel']() != 1  or m['uam4OtilukeSphereFeetPerLevel']() != 1  or  m['uam4OtilukeProseHeadScrambled']() != 1  or  m['uam4OtilukeSubjectFitsWithin']() != 1  or  m['uam4OtilukeNotDamagedNormally']() != 1  or  m['uam4OtilukeDestroyedByNegationOrDispel']() != 1  or  m['uam4OtilukeDestroyedWithoutHarm']() != 1  or  m['uam4OtilukeNothingPassesThrough']() != 1  or  m['uam4OtilukeSubjectBreathes']() != 1  or  m['uam4OtilukeStruggleMovesSphereOnly']() != 1  or  m['uam4OtilukeMovableFromOutsideOrWithin']() != 1  or  m['uam4OtilukeMaterialDiamondHemisphere']() != 1  or  m['uam4OtilukeMaterialGumArabicHemisphere']() != 1",
      "note" = "U5: the Otiluke resilient sphere",
    }, {
      "expr" = "strcmp(m['uam4ShoutName'](), \"Shout (Evocation)\") != 0  or m['uam4ShoutLevel']() != 4  or  m['uam4ShoutRangeZero']() != 1  or  m['uam4ShoutDurationInstantaneous']() != 1  or m['uam4ShoutAoeTerminusInches']() != 3  or  m['uam4ShoutAoeCellScrambled']() != 1  or  m['uam4ShoutConeFromTheMouth']() != 1  or  m['uam4ShoutComponentsVM']() != 1  or  m['uam4ShoutStatTailInterleaved']() != 1  or m['uam4ShoutCastingTimeSegments']() != 1  or  m['uam4ShoutSaveNeg']() != 1  or m['uam4ShoutDeafenRoundsMin']() != 2  or m['uam4ShoutDeafenRoundsMax']() != 12  or m['uam4ShoutDamageMin']() != 2  or m['uam4ShoutDamageMax']() != 12  or  m['uam4ShoutShattersBrittleSubstances']() != 1  or  m['uam4ShoutWallOfIceExample']() != 1  or  m['uam4ShoutOncePerDay']() != 1  or  m['uam4ShoutMaterialHoneyAcidHornCone']() != 1",
      "note" = "U6: shout",
    }, {
      "expr" = "strcmp(m['uam4StoneskinName'](), \"Stoneskin (Alteration)\") != 0  or m['uam4StoneskinLevel']() != 4  or  m['uam4StoneskinLevelCellLost']() != 1  or  m['uam4StoneskinRangeCellLost']() != 1  or  m['uam4StoneskinStatTailInterleaved']() != 1  or  m['uam4StoneskinComponentsVSM']() != 1  or m['uam4StoneskinCastingTimeSegments']() != 1  or  m['uam4StoneskinDurationSpecial']() != 1  or  m['uam4StoneskinSaveNone']() != 1  or  m['uam4StoneskinAoeOneCreature']() != 1  or  m['uam4StoneskinImmuneToPhysicalAttacks']() != 1  or  m['uam4StoneskinSwordOfSharpnessIneffective']() != 1  or  m['uam4StoneskinMagicAttacksNormal']() != 1  or  m['uam4StoneskinOneOpponentDispels']() != 1  or  m['uam4StoneskinImmuneToThatAttack']() != 1  or m['uam4StoneskinSoftWeaponDamageMin']() != 1  or m['uam4StoneskinSoftWeaponDamageMax']() != 2  or  m['uam4StoneskinSoftWeaponsDoNotDispels']() != 1  or  m['uam4StoneskinMaterialGraniteDiamondDust']() != 1",
      "note" = "U7: stoneskin",
    }, {
      "expr" = "strcmp(m['uam4UltravisionName'](), \"Ultravision (Alteration)\") != 0  or m['uam4UltravisionLevel']() != 4  or  m['uam4UltravisionComponentsVSM']() != 1  or  m['uam4UltravisionRangeTouch']() != 1  or m['uam4UltravisionCastingTimeSegments']() != 4  or  m['uam4UltravisionSaveNone']() != 1  or m['uam4UltravisionDurationTurnsMin']() != 6  or m['uam4UltravisionDurationTurnsPerLevel']() != 6  or  m['uam4UltravisionAoeOneCreature']() != 1  or  m['uam4UltravisionSeesUltraviolet']() != 1  or m['uam4UltravisionClearYards']() != 100  or m['uam4UltravisionShadowyYards']() != 300  or m['uam4UltravisionDarkNightReductionPct']() != 50  or m['uam4UltravisionEarthFeet']() != 6  or m['uam4UltravisionStoneFeet']() != 3  or m['uam4UltravisionUndergroundRadiusFeet']() != 3  or  m['uam4UltravisionUndergroundDimOnly']() != 1  or  m['uam4UltravisionEmissionSourceImproves']() != 1  or  m['uam4UltravisionNearbyLightSpoils']() != 1  or m['uam4UltravisionMaterialAmethystGp']() != 500  or  m['uam4UltravisionTailPastFifthHeading']() != 1",
      "note" = "U8: ultravision",
    }, {
      "expr" = "m['uas2Mu4thCount']() != 28  or strcmp(m['uas2Mu4thName'](5), \"Evard's Black Tentacles\") != 0  or strcmp(m['uas2Mu4thName'](12), \"Leomund's Secure Shelter\") != 0  or strcmp(m['uas2Mu4thName'](13), \"Magic Mirror\") != 0  or strcmp(m['uas2Mu4thName'](16), \"Otiluke's Resilient Sphere\") != 0  or strcmp(m['uas2Mu4thName'](22), \"Shout\") != 0  or strcmp(m['uas2Mu4thName'](23), \"Stoneskin\") != 0  or strcmp(m['uas2Mu4thName'](24), \"Ultravision\") != 0",
      "note" = "the R342 table seam (7 of 8 names; the Dispel fragment cell is a hole)",
    }, {
      "expr" = "strcmp(n, \"Dispel Illusion\") == 0",
      "note" = "the absent name (the Dispel hole)",
    } },
  "audit" = {
      "label" = "R359: the UA new magic-user 4th level spells pin audit",
      "comment" = "The UA NEW MAGIC-USER SPELLS (pp. 51-66), the 4th level - dispel illusion behind the lost name tail and the garbled half-inch range, the Evard black tentacles behind the lost level and range cells, the Leomund secure shelter, magic mirror, the Otiluke resilient sphere, shout with the scrambled area tail, stoneskin behind the lost level and range cells, ultravision. The family decodes the 7s as 1. The R342 table seam pins 7 of 8; the item stays open (the 5th-9th levels).",
    },
}
