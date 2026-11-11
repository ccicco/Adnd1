-- ua356: promoted from rules/ua/uamuspells1.h (the The UA NEW MAGIC-USER SPELLS (p. 51) pins, R356: the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 356,
  "prefix" = "ua356",
  "banner" = {
      "title" = "The UA NEW MAGIC-USER SPELLS (p. 51) pins, R356: the",
      "provenance" = "1st-level spell descriptions - alarm, armor, firewater, grease, melt, mount, precipitation, run, taunt and wizard mark.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the level cells print 7 for alarm, armor, firewater, grease, precipitation, melt and wizard mark - the family decodes 1 (mount, run and taunt print the clean 1; the family corroborates). The casting time cells print \"7 turn\"/\"7 round\"/\"7 segment\" - the family decodes 1 of the printed unit; the firewater and wizard mark blocks print the clean 1 segment. - the stat blocks interleave both columns across the whole level (mount/firewater, melt/run, melt/taunt): the melt range cell position-decodes as 3\" from the run block (the run prose pins touch), flagged with doubt pending the PDF. - the alarm radius sentence loses the door value: \"Reduce the radius by for interposing doors\" [sic] - the wall value 20 degrees pins clean; the door value is a hole. - the alarm components cell scrambles: \"V,\" + \"M\" fragments; the prose pins the materials. - the run/melt block prints \"V. S, M\" - the period decodes as a comma [sic]. - the taunt opener interleaves: \"an i caster to jape god ol\" [sic] - the prose reassembles as \"enables the caster to jape and jeer at any creature\". - the precipitation prose: identical to the 1st-level clerical spell of the same name, except that a holy symbol is not part of the material component - the seam-check runs against the R343 clerical pin; the MU stat block prints the components cell the clerical block lost. - the armor note loses words before \"devices other than a ring of protection\" - a hole pending the PDF.  OCR holes (the item stays open - the 2nd through 9th levels pin in later rounds; these stay pending the PDF): the alarm range and door-value cells; the melt range doubt; the armor note words; the firewater range cell.",
    },
  "consts" = { {
      "name" = "uam1AlarmName",
      "value" = "Alarm (Evocation)",
      "comment" = "---- alarm (Evocation), p. 51 ----",
    }, {
      "name" = "uam1AlarmLevel",
      "value" = 1,
      "comment" = "The level cell prints 7 - the digit-garble family decodes 1.",
    }, {
      "name" = "uam1AlarmDurationTurnsMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam1AlarmDurationTurnsMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam1AlarmDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1AlarmAoeSqFtPerLevel",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uam1AlarmCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uam1AlarmTriggerVolumeHalfCuFt",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1AlarmTriggerWeightPounds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam1AlarmRadiusInches",
      "value" = 60,
      "comment" = "The loud ringing is clearly heard within a 60\" radius.",
    }, {
      "name" = "uam1AlarmWallReductionDegrees",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uam1AlarmSoundSegments",
      "value" = 1,
      "comment" = "The sound lasts 1 segment and then ceases.",
    }, {
      "name" = "uam1ArmorName",
      "value" = "Armor (Conjuration)",
      "comment" = "---- armor (Conjuration), p. 51 ----",
    }, {
      "name" = "uam1ArmorLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1ArmorDamageThresholdBase",
      "value" = 8,
      "comment" = "It lasts until dispelled or until cumulative damage exceeds 8 points plus 1 per level of the caster.",
    }, {
      "name" = "uam1ArmorDamageThresholdPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1ArmorExampleCasterLevelForExceed",
      "value" = 2,
      "comment" = "Unless cast by a magic-user of 2nd level or higher, the 8-then-1 example would dispel it at that point.",
    }, {
      "name" = "uam1MountName",
      "value" = "Mount (Conjuration/Summoning)",
      "comment" = "---- mount (Conjuration/Summoning), p. 51 ----",
    }, {
      "name" = "uam1MountLevel",
      "value" = 1,
      "comment" = "The level cell prints the clean 1.",
    }, {
      "name" = "uam1MountCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uam1MountDurationTurnsBase",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam1MountDurationTurnsPerLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uam1MountMuleLightHorseMaxLevel",
      "value" = 3,
      "comment" = "The mount ladder: 1st-3rd level, mule or light horse.",
    }, {
      "name" = "uam1MountDraftWarhorseMinLevel",
      "value" = 4,
      "comment" = "4th-7th level: draft horse or warhorse.",
    }, {
      "name" = "uam1MountDraftWarhorseMaxLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uam1MountCamelMinLevel",
      "value" = 8,
      "comment" = "8th-12th level: camel.",
    }, {
      "name" = "uam1MountCamelMaxLevel",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam1MountElephantMinLevel",
      "value" = 13,
      "comment" = "13th level and up: elephant, with a houda at 18th.",
    }, {
      "name" = "uam1MountHoudaAtLevel",
      "value" = 18,
      "comment" = "",
    }, {
      "name" = "uam1FirewaterName",
      "value" = "Firewater (Alteration)",
      "comment" = "---- firewater (Alteration), p. 51 ----",
    }, {
      "name" = "uam1FirewaterLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1FirewaterCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints the clean 1 segment.",
    }, {
      "name" = "uam1FirewaterDamageMin",
      "value" = 2,
      "comment" = "Each creature subject to firewater flame suffers 2-12 hit points of damage.",
    }, {
      "name" = "uam1FirewaterDamageMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam1FirewaterEvaporatesInRounds",
      "value" = 1,
      "comment" = "The firewater evaporates and is useless within 1 round; it must be ignited within 10 segments of its creation, even if sealed.",
    }, {
      "name" = "uam1FirewaterIgniteWithinSegments",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uam1GreaseName",
      "value" = "Grease (Evocation)",
      "comment" = "---- grease (Evocation), p. 51 ----",
    }, {
      "name" = "uam1GreaseLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1GreaseCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints the clean 1 segment.",
    }, {
      "name" = "uam1GreaseRangeInches",
      "value" = 1,
      "comment" = "The range prints \"7\\\"\" - the family decodes 1 inch.",
    }, {
      "name" = "uam1GreaseAoeSqFtPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1PrecipName",
      "value" = "Precipitation (Alteration)",
      "comment" = "---- precipitation (Alteration), p. 51 ----",
    }, {
      "name" = "uam1PrecipLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1PrecipCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segment\" - the family decodes 1 segment.",
    }, {
      "name" = "uam1PrecipDurationSegmentsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1PrecipCylinderDiameterInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam1PrecipCylinderHeightInches",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uam1MeltName",
      "value" = "Melt (Alteration)",
      "comment" = "---- melt (Alteration), p. 51 ----",
    }, {
      "name" = "uam1MeltLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1MeltRangeInches",
      "value" = 3,
      "comment" = "The melt/run blocks interleave; the melt range position-decodes as 3 inches from the run block (the run prose pins touch), with doubt pending the PDF.",
    }, {
      "name" = "uam1MeltAoeIceCuYdPerLevel",
      "value" = 1,
      "comment" = "The area of effect prints \"7 cu. yd. of ice or 2 cu. yds. of snow per level\" - the family decodes 1 cubic yard of ice per level.",
    }, {
      "name" = "uam1MeltAoeSnowCuYdPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam1MeltIceInRounds",
      "value" = 1,
      "comment" = "The warmth melts ice in 1 round - a 1st-level caster melts a 1-yard cube of ice to water.",
    }, {
      "name" = "uam1MeltDamagePerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uam1MeltDamagePerLevelOnSave",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1RunName",
      "value" = "Run (Enchantment)",
      "comment" = "---- run (Enchantment), p. 51 ----",
    }, {
      "name" = "uam1RunLevel",
      "value" = 1,
      "comment" = "The level cell prints the clean 1.",
    }, {
      "name" = "uam1RunDurationHoursMin",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam1RunDurationHoursMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam1RunExtraRecipientPer2Levels",
      "value" = 1,
      "comment" = "For every 2 levels of the caster, another individual can be affected.",
    }, {
      "name" = "uam1RunMaterialCastorBeansMin",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uam1RunMaterialCastorBeansMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uam1TauntName",
      "value" = "Taunt (Enchantment)",
      "comment" = "---- taunt (Enchantment), p. 52 ----",
    }, {
      "name" = "uam1TauntLevel",
      "value" = 1,
      "comment" = "The level cell prints the clean 1.",
    }, {
      "name" = "uam1TauntRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uam1TauntCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uam1TauntAoeLevelsPerLevel",
      "value" = 2,
      "comment" = "The area of effect: 2 levels or hit dice of creatures per level of the caster.",
    }, {
      "name" = "uam1TauntLeaderBonusMin",
      "value" = 1,
      "comment" = "Troops under a strong leader gain a save bonus of +1 to +4 at the DM discretion.",
    }, {
      "name" = "uam1TauntLeaderBonusMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkName",
      "value" = "Wizard Mark (Alteration)",
      "comment" = "---- wizard mark (Alteration), p. 52 ----",
    }, {
      "name" = "uam1WizardMarkLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints the clean 1 segment.",
    }, {
      "name" = "uam1WizardMarkAoeSqFt",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkExtraCharacters",
      "value" = 6,
      "comment" = "The caster inscribes a personal rune or mark, visibly or invisibly, plus up to six smaller characters.",
    }, {
      "name" = "uam1WizardMarkDiamondDustGp",
      "value" = 50,
      "comment" = "The material: a pinch of diamond dust, about 50 gp worth, and pigment or pigments; an invisible mark uses a stylus rather than the digit.",
    } },
  "bools" = { {
      "name" = "uam1AlarmLevelGarbleDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1AlarmRangeCellLost",
      "value" = true,
      "comment" = "The range cell prints empty - a hole.",
    }, {
      "name" = "uam1AlarmComponentsCellScrambled",
      "value" = true,
      "comment" = "The components cell scrambles: only \"V,\" and \"M\" fragments print.",
    }, {
      "name" = "uam1AlarmSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1AlarmTriggerLargerThanRat",
      "value" = true,
      "comment" = "The area reacts to any living creature larger than a normal rat - about one-half cubic foot or 3 pounds.",
    }, {
      "name" = "uam1AlarmPortalFloorStairsArea",
      "value" = true,
      "comment" = "The area can be a portal, a section of floor, stairs, and the like; contact triggers the evocation.",
    }, {
      "name" = "uam1AlarmDoorValueLost",
      "value" = true,
      "comment" = "\"Reduce the radius by for interposing doors\" [sic] - the door value is lost; the wall value pins at 20 degrees.",
    }, {
      "name" = "uam1AlarmUndeadNeverTrigger",
      "value" = true,
      "comment" = "Undead creatures never cause the spell to function.",
    }, {
      "name" = "uam1AlarmInvisibleAndPlanarTrigger",
      "value" = true,
      "comment" = "Invisible creatures and living creatures from other planes do trigger it.",
    }, {
      "name" = "uam1AlarmFlyingLevitatingTrigger",
      "value" = true,
      "comment" = "Flying and levitating creatures trigger it.",
    }, {
      "name" = "uam1AlarmMaterialTinyBell",
      "value" = true,
      "comment" = "The material: a tiny bell and a piece of very fine silver wire.",
    }, {
      "name" = "uam1AlarmMaterialFineSilverWire",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1ArmorRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1ArmorDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1ArmorAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1ArmorSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1ArmorCreatesForceFieldAc8",
      "value" = true,
      "comment" = "The caster creates an invisible field of force serving as leather armor, AC 8.",
    }, {
      "name" = "uam1ArmorNoEffectIfAlreadyArmored",
      "value" = true,
      "comment" = "Cast on a person already armored, it has no effect.",
    }, {
      "name" = "uam1ArmorBetterThanNineGainsOneStep",
      "value" = true,
      "comment" = "A creature with armor class normally better than 9 benefits by one step: AC 8 becomes 7, 7 becomes 6, and so on.",
    }, {
      "name" = "uam1ArmorNoWeightOrEncumbrance",
      "value" = true,
      "comment" = "The spell does not slow or hinder movement, adds no weight or encumbrance, and does not prevent spell casting.",
    }, {
      "name" = "uam1ArmorDoesNotPreventCasting",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1ArmorNoteWordsLost",
      "value" = true,
      "comment" = "The note loses words before \"devices other than a ring of protection\" - a hole.",
    }, {
      "name" = "uam1ArmorMaterialBlessedLeather",
      "value" = true,
      "comment" = "The material: a piece of finely cured leather blessed by a cleric.",
    }, {
      "name" = "uam1MountAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1MountSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1MountServesThenReturns",
      "value" = true,
      "comment" = "The caster calls a normal animal to serve as a mount; at expiration it disappears, returning to its own place.",
    }, {
      "name" = "uam1MountLowerLevelChoiceAllowed",
      "value" = true,
      "comment" = "A caster may always choose a lower-level mount.",
    }, {
      "name" = "uam1MountNoRidingGearUnlessLowerClass",
      "value" = true,
      "comment" = "The mount comes with no riding gear unless it is of a class lower than the caster would normally gain.",
    }, {
      "name" = "uam1MountStatsTypicalOfClass",
      "value" = true,
      "comment" = "The statistics of the animal are typical of all creatures of the same class.",
    }, {
      "name" = "uam1MountMaterialHairOrDung",
      "value" = true,
      "comment" = "The material: a bit of hair or dung from the type of animal to be conjured.",
    }, {
      "name" = "uam1FirewaterRangeCellLost",
      "value" = true,
      "comment" = "The range cell is lost in the interleave - a hole.",
    }, {
      "name" = "uam1FirewaterSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1FirewaterVolatileAlcoholLike",
      "value" = true,
      "comment" = "The magic-user changes a volume of water to a volatile, flammable substance similar to alcohol and lighter than water.",
    }, {
      "name" = "uam1FirewaterLighterThanWater",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1FirewaterIgnitesOnSpark",
      "value" = true,
      "comment" = "Exposed to flame, fire or even a spark, it bursts into flames and burns with a hot fire.",
    }, {
      "name" = "uam1FirewaterMaterialSugarGrains",
      "value" = true,
      "comment" = "The material: a few grains of sugar and a raisin.",
    }, {
      "name" = "uam1FirewaterMaterialRaisin",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1GreaseDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1GreaseSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1GreaseSaveVsPetrificationOrFall",
      "value" = true,
      "comment" = "A creature stepping on the area must save versus petrification or slip, skid and fall; an aware creature can possibly avoid it.",
    }, {
      "name" = "uam1GreaseAwareCreatureCanAvoid",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1GreaseCoatsOtherSurfaces",
      "value" = true,
      "comment" = "The spell can coat a surface other than underfoot - a rope, ladder rungs, weapon handle.",
    }, {
      "name" = "uam1GreaseLoneObjectsAlwaysSubject",
      "value" = true,
      "comment" = "Lone material objects are always subject; an object wielded by a creature needs its failed save versus spell; a single save negates.",
    }, {
      "name" = "uam1GreaseWieldedNeedsFailedSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1GreaseSingleSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1GreaseMaterialPorkRindEtc",
      "value" = true,
      "comment" = "The material: a bit of pork rind, butter, or other greasy material.",
    }, {
      "name" = "uam1PrecipSaveNoneAndSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1PrecipComponentsVSM",
      "value" = true,
      "comment" = "The MU stat block prints the components cell the clerical block lost: V, S, M.",
    }, {
      "name" = "uam1PrecipIdenticalToClericalMinusHolySymbol",
      "value" = true,
      "comment" = "The spell is identical to the 1st-level clerical spell of the same name, except that a holy symbol is not part of the material component.",
    }, {
      "name" = "uam1PrecipNoHolySymbolComponent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1MeltRangeDecodedWithDoubt",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1MeltComponentsPeriodGarble",
      "value" = true,
      "comment" = "The components print \"V. S, M\" - the period decodes as a comma [sic].",
    }, {
      "name" = "uam1MeltSnowToWaterOneRound",
      "value" = true,
      "comment" = "Two cubic yards of snow turn to water in 1 round.",
    }, {
      "name" = "uam1MeltAffectsColdCreatures",
      "value" = true,
      "comment" = "Against cold-based creatures - white dragons, winter wolves, yeti, woolly rhinos, para-elemental and the like - the spell inflicts 2 points of damage per level, or 1 per level on a successful save versus spell.",
    }, {
      "name" = "uam1MeltIneffectiveAgainstOthers",
      "value" = true,
      "comment" = "The spell is generally ineffective against other types of creatures.",
    }, {
      "name" = "uam1MeltMaterialRockSalt",
      "value" = true,
      "comment" = "The material: a few crystals or rock salt and a pinch of soot.",
    }, {
      "name" = "uam1MeltMaterialSootPinch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1RunRangeTouch",
      "value" = true,
      "comment" = "The range cell position-decodes as touch - the prose pins touched recipients.",
    }, {
      "name" = "uam1RunSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1RunAoeHumansDemiHumansOnly",
      "value" = true,
      "comment" = "The area of effect: special, humans and demi-humans only.",
    }, {
      "name" = "uam1RunTwiceNormalSpeed",
      "value" = true,
      "comment" = "The recipient runs at full speed - twice normal - for the duration without tiring.",
    }, {
      "name" = "uam1RunLikeRestHours",
      "value" = true,
      "comment" = "After running, the individual must rest a like number of hours, drinking plenty of liquids and eating heartily.",
    }, {
      "name" = "uam1RunNaturalFormsOnly",
      "value" = true,
      "comment" = "Only humans and demi-humans in their natural forms are affected; barbarians with the running ability are immune.",
    }, {
      "name" = "uam1RunBarbariansImmune",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1RunMaterialPlumElixir",
      "value" = true,
      "comment" = "The material: an elixir of dried-plum juice boiled in spring water and the oil of 5-8 spurge [castor] beans.",
    }, {
      "name" = "uam1TauntDurationInstantaneous",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1TauntSaveNegates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1TauntOpenerGarbleDecoded",
      "value" = true,
      "comment" = "The opener interleaves: \"an i caster to jape god ol\" [sic] - the prose reassembles as enables the caster to jape and jeer at any creature.",
    }, {
      "name" = "uam1TauntChallengesAndInsults",
      "value" = true,
      "comment" = "The dweomer gives the words and sounds real meaning: challenging, insulting, causing irritation and anger.",
    }, {
      "name" = "uam1TauntRushForthInFury",
      "value" = true,
      "comment" = "On a failed save the subjects rush forth in fury to do battle with the caster, attacking with body and hand-held weapons rather than from a distance.",
    }, {
      "name" = "uam1TauntAttackMeleePreferred",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1TauntBoundaryBreaksSpell",
      "value" = true,
      "comment" = "Separation by an impenetrable or uncrossable boundary - a wall of flame, a deep chasm - breaks the spell.",
    }, {
      "name" = "uam1TauntOneSortPerCasting",
      "value" = true,
      "comment" = "Only one sort of creature is affected per casting - orcs or goblins, not both.",
    }, {
      "name" = "uam1TauntNearestFirst",
      "value" = true,
      "comment" = "The magic affects creatures closest to the caster first, regardless of maximum range.",
    }, {
      "name" = "uam1WizardMarkRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkEtchesStoneMetalSofter",
      "value" = true,
      "comment" = "The rune etches upon stone, metal or any softer substance without harm to the material.",
    }, {
      "name" = "uam1WizardMarkDetectMagicGlows",
      "value" = true,
      "comment" = "Detect magic causes an invisible mark to glow and be readable - not necessarily understandable.",
    }, {
      "name" = "uam1WizardMarkDetectionSuiteReveals",
      "value" = true,
      "comment" = "Detect invisibility, true seeing, true sight, a gem of seeing, or a robe of eyes also notes it.",
    }, {
      "name" = "uam1WizardMarkReadMagicRevealsIntent",
      "value" = true,
      "comment" = "Read magic reveals the maker intent; erase wipes the surface clean.",
    }, {
      "name" = "uam1WizardMarkEraseWipes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkMaterialPigments",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uam1WizardMarkInvisibleUsesStylus",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uam1AlarmName'](), \"Alarm (Evocation)\") != 0  or m['uam1AlarmLevel']() != 1  or  m['uam1AlarmLevelGarbleDecoded']() != 1  or  m['uam1AlarmRangeCellLost']() != 1  or m['uam1AlarmDurationTurnsMin']() != 2  or m['uam1AlarmDurationTurnsMax']() != 8  or m['uam1AlarmDurationTurnsPerLevel']() != 1  or m['uam1AlarmAoeSqFtPerLevel']() != 20  or  m['uam1AlarmComponentsCellScrambled']() != 1  or m['uam1AlarmCastingTimeRounds']() != 1  or  m['uam1AlarmSaveNone']() != 1  or  m['uam1AlarmTriggerLargerThanRat']() != 1  or m['uam1AlarmTriggerVolumeHalfCuFt']() != 1  or m['uam1AlarmTriggerWeightPounds']() != 3  or  m['uam1AlarmPortalFloorStairsArea']() != 1  or m['uam1AlarmRadiusInches']() != 60  or  m['uam1AlarmDoorValueLost']() != 1  or m['uam1AlarmWallReductionDegrees']() != 20  or m['uam1AlarmSoundSegments']() != 1  or  m['uam1AlarmUndeadNeverTrigger']() != 1  or  m['uam1AlarmInvisibleAndPlanarTrigger']() != 1  or  m['uam1AlarmFlyingLevitatingTrigger']() != 1  or  m['uam1AlarmMaterialTinyBell']() != 1  or  m['uam1AlarmMaterialFineSilverWire']() != 1",
      "note" = "U1: alarm",
    }, {
      "expr" = "strcmp(m['uam1ArmorName'](), \"Armor (Conjuration)\") != 0  or m['uam1ArmorLevel']() != 1  or  m['uam1ArmorRangeTouch']() != 1  or  m['uam1ArmorDurationSpecial']() != 1  or  m['uam1ArmorAoeOneCreature']() != 1  or  m['uam1ArmorSaveNone']() != 1  or  m['uam1ArmorCreatesForceFieldAc8']() != 1  or  m['uam1ArmorNoEffectIfAlreadyArmored']() != 1  or  m['uam1ArmorBetterThanNineGainsOneStep']() != 1  or  m['uam1ArmorNoWeightOrEncumbrance']() != 1  or  m['uam1ArmorDoesNotPreventCasting']() != 1  or m['uam1ArmorDamageThresholdBase']() != 8  or m['uam1ArmorDamageThresholdPerLevel']() != 1  or m['uam1ArmorExampleCasterLevelForExceed']() != 2  or  m['uam1ArmorNoteWordsLost']() != 1  or  m['uam1ArmorMaterialBlessedLeather']() != 1",
      "note" = "U2: armor",
    }, {
      "expr" = "strcmp(m['uam1MountName'](), \"Mount (Conjuration/Summoning)\") != 0  or m['uam1MountLevel']() != 1  or m['uam1MountCastingTimeRounds']() != 1  or m['uam1MountDurationTurnsBase']() != 12  or m['uam1MountDurationTurnsPerLevel']() != 6  or  m['uam1MountAoeOneCreature']() != 1  or  m['uam1MountSaveNone']() != 1  or  m['uam1MountServesThenReturns']() != 1  or m['uam1MountMuleLightHorseMaxLevel']() != 3  or m['uam1MountDraftWarhorseMinLevel']() != 4  or m['uam1MountDraftWarhorseMaxLevel']() != 7  or m['uam1MountCamelMinLevel']() != 8  or m['uam1MountCamelMaxLevel']() != 12  or m['uam1MountElephantMinLevel']() != 13  or m['uam1MountHoudaAtLevel']() != 18  or  m['uam1MountLowerLevelChoiceAllowed']() != 1  or  m['uam1MountNoRidingGearUnlessLowerClass']() != 1  or  m['uam1MountStatsTypicalOfClass']() != 1  or  m['uam1MountMaterialHairOrDung']() != 1",
      "note" = "U3: mount",
    }, {
      "expr" = "strcmp(m['uam1FirewaterName'](), \"Firewater (Alteration)\") != 0  or m['uam1FirewaterLevel']() != 1  or m['uam1FirewaterCastingTimeSegments']() != 1  or  m['uam1FirewaterRangeCellLost']() != 1  or  m['uam1FirewaterSaveNone']() != 1  or  m['uam1FirewaterVolatileAlcoholLike']() != 1  or  m['uam1FirewaterLighterThanWater']() != 1  or  m['uam1FirewaterIgnitesOnSpark']() != 1  or m['uam1FirewaterDamageMin']() != 2  or m['uam1FirewaterDamageMax']() != 12  or m['uam1FirewaterEvaporatesInRounds']() != 1  or m['uam1FirewaterIgniteWithinSegments']() != 10  or  m['uam1FirewaterMaterialSugarGrains']() != 1  or  m['uam1FirewaterMaterialRaisin']() != 1",
      "note" = "U4: firewater",
    }, {
      "expr" = "strcmp(m['uam1GreaseName'](), \"Grease (Evocation)\") != 0  or m['uam1GreaseLevel']() != 1  or m['uam1GreaseCastingTimeSegments']() != 1  or m['uam1GreaseRangeInches']() != 1  or  m['uam1GreaseDurationPermanent']() != 1  or m['uam1GreaseAoeSqFtPerLevel']() != 1  or  m['uam1GreaseSaveSpecial']() != 1  or  m['uam1GreaseSaveVsPetrificationOrFall']() != 1  or  m['uam1GreaseAwareCreatureCanAvoid']() != 1  or  m['uam1GreaseCoatsOtherSurfaces']() != 1  or  m['uam1GreaseLoneObjectsAlwaysSubject']() != 1  or  m['uam1GreaseWieldedNeedsFailedSave']() != 1  or  m['uam1GreaseSingleSaveNegates']() != 1  or  m['uam1GreaseMaterialPorkRindEtc']() != 1",
      "note" = "U5: grease",
    }, {
      "expr" = "strcmp(m['uam1PrecipName'](), \"Precipitation (Alteration)\") != 0  or m['uam1PrecipLevel']() != 1  or m['uam1PrecipCastingTimeSegments']() != 1  or m['uam1PrecipDurationSegmentsPerLevel']() != 1  or m['uam1PrecipCylinderDiameterInches']() != 3  or m['uam1PrecipCylinderHeightInches']() != 12  or  m['uam1PrecipSaveNoneAndSpecial']() != 1  or  m['uam1PrecipComponentsVSM']() != 1  or  m['uam1PrecipIdenticalToClericalMinusHolySymbol']() != 1  or  m['uam1PrecipNoHolySymbolComponent']() != 1  or m['uam1PrecipDurationSegmentsPerLevel']() !=m['uac1PrecipDurationSegmentsPerLevel']()  or m['uam1PrecipCylinderDiameterInches']() !=m['uac1PrecipCylinderDiameterInches']()  or m['uam1PrecipCylinderHeightInches']() !=m['uac1PrecipCylinderHeightInches']()",
      "note" = "U6: precipitation - the clerical seam",
    }, {
      "expr" = "strcmp(m['uam1MeltName'](), \"Melt (Alteration)\") != 0  or m['uam1MeltLevel']() != 1  or m['uam1MeltRangeInches']() != 3  or  m['uam1MeltRangeDecodedWithDoubt']() != 1  or  m['uam1MeltComponentsPeriodGarble']() != 1  or m['uam1MeltAoeIceCuYdPerLevel']() != 1  or m['uam1MeltAoeSnowCuYdPerLevel']() != 2  or m['uam1MeltIceInRounds']() != 1  or  m['uam1MeltSnowToWaterOneRound']() != 1  or  m['uam1MeltAffectsColdCreatures']() != 1  or m['uam1MeltDamagePerLevel']() != 2  or m['uam1MeltDamagePerLevelOnSave']() != 1  or  m['uam1MeltIneffectiveAgainstOthers']() != 1  or  m['uam1MeltMaterialRockSalt']() != 1  or  m['uam1MeltMaterialSootPinch']() != 1",
      "note" = "U7: melt",
    }, {
      "expr" = "strcmp(m['uam1RunName'](), \"Run (Enchantment)\") != 0  or m['uam1RunLevel']() != 1  or  m['uam1RunRangeTouch']() != 1  or m['uam1RunDurationHoursMin']() != 5  or m['uam1RunDurationHoursMax']() != 8  or  m['uam1RunSaveNone']() != 1  or  m['uam1RunAoeHumansDemiHumansOnly']() != 1  or  m['uam1RunTwiceNormalSpeed']() != 1  or  m['uam1RunLikeRestHours']() != 1  or m['uam1RunExtraRecipientPer2Levels']() != 1  or  m['uam1RunNaturalFormsOnly']() != 1  or  m['uam1RunBarbariansImmune']() != 1  or  m['uam1RunMaterialPlumElixir']() != 1  or m['uam1RunMaterialCastorBeansMin']() != 5  or m['uam1RunMaterialCastorBeansMax']() != 8",
      "note" = "U8: run",
    }, {
      "expr" = "strcmp(m['uam1TauntName'](), \"Taunt (Enchantment)\") != 0  or m['uam1TauntLevel']() != 1  or m['uam1TauntRangeInches']() != 3  or m['uam1TauntCastingTimeRounds']() != 1  or  m['uam1TauntDurationInstantaneous']() != 1  or  m['uam1TauntSaveNegates']() != 1  or m['uam1TauntAoeLevelsPerLevel']() != 2  or  m['uam1TauntOpenerGarbleDecoded']() != 1  or  m['uam1TauntChallengesAndInsults']() != 1  or  m['uam1TauntRushForthInFury']() != 1  or  m['uam1TauntAttackMeleePreferred']() != 1  or  m['uam1TauntBoundaryBreaksSpell']() != 1  or  m['uam1TauntOneSortPerCasting']() != 1  or  m['uam1TauntNearestFirst']() != 1  or m['uam1TauntLeaderBonusMin']() != 1  or m['uam1TauntLeaderBonusMax']() != 4",
      "note" = "U9: taunt",
    }, {
      "expr" = "strcmp(m['uam1WizardMarkName'](), \"Wizard Mark (Alteration)\") != 0  or m['uam1WizardMarkLevel']() != 1  or m['uam1WizardMarkCastingTimeSegments']() != 1  or  m['uam1WizardMarkRangeTouch']() != 1  or  m['uam1WizardMarkDurationPermanent']() != 1  or m['uam1WizardMarkAoeSqFt']() != 1  or  m['uam1WizardMarkSaveNone']() != 1  or m['uam1WizardMarkExtraCharacters']() != 6  or  m['uam1WizardMarkEtchesStoneMetalSofter']() != 1  or  m['uam1WizardMarkDetectMagicGlows']() != 1  or  m['uam1WizardMarkDetectionSuiteReveals']() != 1  or  m['uam1WizardMarkReadMagicRevealsIntent']() != 1  or  m['uam1WizardMarkEraseWipes']() != 1  or m['uam1WizardMarkDiamondDustGp']() != 50  or  m['uam1WizardMarkMaterialPigments']() != 1  or  m['uam1WizardMarkInvisibleUsesStylus']() != 1",
      "note" = "U10: wizard mark",
    } },
  "audit" = {
      "label" = "R356: the UA new magic-user 1st level spells pin audit",
      "comment" = "The UA NEW MAGIC-USER SPELLS (p. 51), the 1st level - alarm (the lost range cell and the door-value hole), armor, firewater, grease, melt (the run interleave), mount (the level ladder), precipitation (the clerical seam minus the holy symbol), run, taunt (the scrambled opener) and wizard mark. The family decodes the 7s as 1. The item stays open (the 2nd-9th levels).",
    },
}
