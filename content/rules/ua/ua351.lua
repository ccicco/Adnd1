-- ua351: promoted from rules/uadruidspells2.h (the The UA NEW DRUID SPELLS (pp. 43-44) pins, R351: the 2nd-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 351,
  "prefix" = "ua351",
  "banner" = {
      "title" = "The UA NEW DRUID SPELLS (pp. 43-44) pins, R351: the 2nd-level",
      "provenance" = "spell descriptions - flame blade, goodberry, reflecting pool and slow poison.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the flame blade and reflecting pool durations print \"7 round/level\" and the goodberry casting time prints \"7 round\" - the family decodes each as 1 (flame blade prints a clean \"Level: 2\" cell). - the goodberry name header and school never print (the stat block follows the flame blade material sentence directly); identified by the prose \"goodberry spell\" plus the gap item list. - the reflecting pool name header prints \"Pool ion -\" - a two-column garble of \"Reflecting Pool\"; identified by the prose \"cast through a reflecting pool\" plus the gap item list. The school never prints. - the flame blade damage sentence splits after \"if the creature is\": the scrambled fragments reassemble as the -2 clause (a fire-dweller or which uses fire attack form) and the protected-from-fire sentence (no damage can be inflicted upon a creature which is protected from fire). - the flame blade material fragments reassemble: \"In addition to mistletoe, the druid must have a leaf of the sumac in order to cast this spell\" (the \"class. order\" fragment carries the lost \"order\"). - the flame blade area cell prints \"3 long, sword-like blade\" - the unit mark is lost; position-decoded as a 3-foot blade, pinned with doubt pending the PDF. - the goodberry duration prints \"1 day + 1/level\" - the per-level unit is lost; pinned verbatim with the unit flagged as a hole. - the reflecting pool material fragments scramble around the walnut oil: mistletoe plus oil extracted from nuts such as the walnut; the measure fragment stays a hole. - the reflecting pool prose loses the spell name after \"the spells starshine and\" - a hole (see hereafter points into this chapter). - the slow poison range cell prints head-lost as \"ge: Touch\" = Range: Touch; the level cell never prints - position-certain 2 by the section header. The stray \"that\" fragment after the saving throw is the tail of the \"is able to determine that\" clause.  OCR holes (the item stays open - the 3rd-7th levels pin in later rounds; these stay pending the PDF): the goodberry name header and school; the goodberry duration unit; the reflecting pool name header and school; the reflecting pool material measure; the lost spell name after \"starshine and\"; the flame blade area unit mark.",
    },
  "consts" = { {
      "name" = "uad2FlameBladeName",
      "value" = "Flame Blade (Evocation)",
      "comment" = "---- flame blade (Evocation), p. 43 ----",
    }, {
      "name" = "uad2FlameBladeLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeRangeInches",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round/level\" - the digit-garble family decodes 1 round/level.",
    }, {
      "name" = "uad2FlameBladeBladeLengthFeet",
      "value" = 3,
      "comment" = "The area cell prints \"3 long, sword-like blade\" - the unit mark is lost; position-decoded as 3 feet, with doubt.",
    }, {
      "name" = "uad2FlameBladeDamageMin",
      "value" = 5,
      "comment" = "A successful hit inflicts 5-8 points of damage; +2 if the creature is undead or especially vulnerable to fire; -2 if a fire-dweller or a fire-attack-form user.",
    }, {
      "name" = "uad2FlameBladeDamageMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeUndeadOrFireVulnerableBonus",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeFireDwellerPenalty",
      "value" = -2,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryName",
      "value" = "Goodberry",
      "comment" = "---- goodberry, p. 44 ---- The name header and school never print; identified by the prose \"goodberry spell\" plus the gap item list.",
    }, {
      "name" = "uad2GoodberryLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uad2GoodberryDurationDaysBase",
      "value" = 1,
      "comment" = "The duration prints \"1 day + 1/level\" - the per-level unit is lost; pinned verbatim with the unit flagged.",
    }, {
      "name" = "uad2GoodberryDurationPerLevelAddend",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryBerriesMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryBerriesMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryCurePerBerry",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryCureMaxPer24h",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryBadberryPoisonPoints",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolName",
      "value" = "Reflecting Pool",
      "comment" = "---- reflecting pool, p. 44 ---- The name header prints \"Pool ion -\" - a two-column garble of Reflecting Pool; identified by the prose \"cast through a reflecting pool\" plus the gap item list.",
    }, {
      "name" = "uad2ReflectingPoolLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolCastingTimeHours",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolRangeInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolDurationRoundsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 round/level\" - the family decodes 1 round/level.",
    }, {
      "name" = "uad2ReflectingPoolDiameterFeetPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolCastThroughChancePctPerLevel",
      "value" = 5,
      "comment" = "The spells cast through the pool, with a 5% per level chance of operating correctly: detect magic, detect snares and pits, detect poison.",
    }, {
      "name" = "uad2ReflectingPoolCastThroughCount",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonName",
      "value" = "Slow Poison (Necromantic)",
      "comment" = "---- slow poison (Necromantic), p. 44 ----",
    }, {
      "name" = "uad2SlowPoisonLevel",
      "value" = 2,
      "comment" = "The level cell never prints - position-certain 2 by the section header.",
    }, {
      "name" = "uad2SlowPoisonDurationHoursPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonCastingTimeSegments",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonAntidoteChancePctPerLevel",
      "value" = 5,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uad2FlameBladeComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeBladeUnitLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeWieldedAsScimitar",
      "value" = true,
      "comment" = "A blazing ray of red-hot fire springs from the druid's hand, wielded as if it were a scimitar.",
    }, {
      "name" = "uad2FlameBladeNoDamageOnFireProtected",
      "value" = true,
      "comment" = "No damage can be inflicted upon a creature protected from fire (the interleave decode).",
    }, {
      "name" = "uad2FlameBladeIgnitesDryMaterials",
      "value" = true,
      "comment" = "The blade will ignite dry materials such as straw, sticks, cloth, etc.",
    }, {
      "name" = "uad2FlameBladeNotMagicalExceptVsUndead",
      "value" = true,
      "comment" = "Not a magical weapon in the normal sense except with respect to undead monsters - creatures struck only by magical weapons are not harmed unless of the undead class.",
    }, {
      "name" = "uad2FlameBladeMagicOnlyCreaturesImmuneUnlessUndead",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeMaterialMistletoe",
      "value" = true,
      "comment" = "The material: mistletoe plus a leaf of the sumac (the interleave decode; the \"order\" fragment).",
    }, {
      "name" = "uad2FlameBladeMaterialSumacLeaf",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2FlameBladeMaterialInterleaveDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryNameHeaderLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberrySchoolLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberrySaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryDurationUnitLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryDiscernedByDruid3rdPlus",
      "value" = true,
      "comment" = "The casting druid (or any druid of 3rd or higher level) immediately discerns the affected berries; detect magic discovers them also.",
    }, {
      "name" = "uad2GoodberryDetectMagicReveals",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryNourishAsFullMeal",
      "value" = true,
      "comment" = "Each berry either nourishes a hungry man-size creature as a full meal or cures 1 point of damage, to a maximum of 8 points of curing in any 24-hour period.",
    }, {
      "name" = "uad2GoodberryReverseBadberry",
      "value" = true,
      "comment" = "The reverse, badberry: rotten berries appear wholesome but each delivers 1 point of poison damage, no saving throw.",
    }, {
      "name" = "uad2GoodberryBadberryNoSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2GoodberryMaterialMistletoe",
      "value" = true,
      "comment" = "The material is mistletoe passed over the freshly picked, edible berries; the example list tail survives (currants, gooseberries, etc.) - the first list item is lost.",
    }, {
      "name" = "uad2GoodberryExampleListFirstItemLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolNameHeaderGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolSchoolLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolAoeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolNaturalWaterOnly",
      "value" = true,
      "comment" = "The pool is normal water in a natural setting, acting as a scrying device of no greater diameter than 2 feet per level of the caster.",
    }, {
      "name" = "uad2ReflectingPoolCrystalBallLike",
      "value" = true,
      "comment" = "Similar to a crystal ball, in the fashion of the magic-user magic mirror and the clerical magic font.",
    }, {
      "name" = "uad2ReflectingPoolMagicMirrorAndFontRef",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolCoexistentPlanesOnly",
      "value" = true,
      "comment" = "The scrying extends only to planes coexistent with or bordering the Prime Material - the Inner Planes, including the Para-elemental Planes and the Plane of Shadow; the crystal ball penalties (DMG) apply beyond the druid's own plane.",
    }, {
      "name" = "uad2ReflectingPoolIncludesParaElementalAndShadow",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolCrystalBallPenaltiesApply",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolInfraAndUltravisionNormal",
      "value" = true,
      "comment" = "Infravision and ultravision operate normally through the pool, as will the spells starshine and [the companion name is lost - a hole].",
    }, {
      "name" = "uad2ReflectingPoolStarshineOperates",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolCompanionSpellNameLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolMaterialMistletoe",
      "value" = true,
      "comment" = "The material: mistletoe and oil extracted from nuts such as the walnut; the measure fragment stays a hole.",
    }, {
      "name" = "uad2ReflectingPoolMaterialNutOil",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2ReflectingPoolMaterialMeasureLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonRangeTouch",
      "value" = true,
      "comment" = "The range cell prints head-lost as \"ge: Touch\" = Touch.",
    }, {
      "name" = "uad2SlowPoisonRangeCellHeadLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonAoeCreatureTouched",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonIdenticalToClerical",
      "value" = true,
      "comment" = "Identical to the 2nd-level clerical slow poison, except: if the poison was made from some living plant, the druid has a 5% chance per level of knowing an herbal antidote which will neutralize the poison.",
    }, {
      "name" = "uad2SlowPoisonPlantPoisonCondition",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonDetectPoisonIndicatesOrganic",
      "value" = true,
      "comment" = "If the actual type of poison is not given by the DM, a successful detect poison (type) indicates an organic poison which can be countered; a dice roll equal to or less than the druid's chance indicates neutralization.",
    }, {
      "name" = "uad2SlowPoisonRollEqualOrLessNeutralizes",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonMaterialMistletoe",
      "value" = true,
      "comment" = "The material: mistletoe, plus crushed garlic rubbed on the recipient's feet; antidotes from green vegetables outdoors or an herbalist or similar source.",
    }, {
      "name" = "uad2SlowPoisonMaterialGarlicOnFeet",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad2SlowPoisonAntidoteOutdoorOrHerbalist",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uad2ReflectingPoolCastThroughName",
      "comment" = "",
      "kind" = "string array",
      "count" = 3,
      "values" = { "Detect Magic", "Detect Snares and Pits", "Detect Poison" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uad2FlameBladeName'](), \"Flame Blade (Evocation)\") != 0  or  m['uad2FlameBladeComponentsVSM']() != 1  or m['uad2FlameBladeLevel']() != 2  or m['uad2FlameBladeCastingTimeSegments']() != 3  or m['uad2FlameBladeRangeInches']() != 0  or  m['uad2FlameBladeSaveNone']() != 1  or m['uad2FlameBladeDurationRoundsPerLevel']() != 1  or m['uad2FlameBladeBladeLengthFeet']() != 3  or  m['uad2FlameBladeBladeUnitLost']() != 1  or  m['uad2FlameBladeWieldedAsScimitar']() != 1  or m['uad2FlameBladeDamageMin']() != 5  or m['uad2FlameBladeDamageMax']() != 8  or m['uad2FlameBladeUndeadOrFireVulnerableBonus']() != 2  or m['uad2FlameBladeFireDwellerPenalty']() != -2  or  m['uad2FlameBladeNoDamageOnFireProtected']() != 1  or  m['uad2FlameBladeIgnitesDryMaterials']() != 1  or  m['uad2FlameBladeNotMagicalExceptVsUndead']() != 1  or  m['uad2FlameBladeMagicOnlyCreaturesImmuneUnlessUndead']() != 1  or  m['uad2FlameBladeMaterialMistletoe']() != 1  or  m['uad2FlameBladeMaterialSumacLeaf']() != 1  or  m['uad2FlameBladeMaterialInterleaveDecoded']() != 1",
      "note" = "U1: flame blade",
    }, {
      "expr" = "strcmp(m['uad2GoodberryName'](), \"Goodberry\") != 0  or  m['uad2GoodberryNameHeaderLost']() != 1  or  m['uad2GoodberrySchoolLost']() != 1  or  m['uad2GoodberryComponentsVSM']() != 1  or m['uad2GoodberryLevel']() != 2  or m['uad2GoodberryCastingTimeRounds']() != 1  or  m['uad2GoodberryRangeTouch']() != 1  or  m['uad2GoodberrySaveNone']() != 1  or m['uad2GoodberryDurationDaysBase']() != 1  or m['uad2GoodberryDurationPerLevelAddend']() != 1  or  m['uad2GoodberryDurationUnitLost']() != 1  or m['uad2GoodberryBerriesMin']() != 2  or m['uad2GoodberryBerriesMax']() != 8  or  m['uad2GoodberryDiscernedByDruid3rdPlus']() != 1  or  m['uad2GoodberryDetectMagicReveals']() != 1  or  m['uad2GoodberryNourishAsFullMeal']() != 1  or m['uad2GoodberryCurePerBerry']() != 1  or m['uad2GoodberryCureMaxPer24h']() != 8  or  m['uad2GoodberryReverseBadberry']() != 1  or m['uad2GoodberryBadberryPoisonPoints']() != 1  or  m['uad2GoodberryBadberryNoSave']() != 1  or  m['uad2GoodberryMaterialMistletoe']() != 1  or  m['uad2GoodberryExampleListFirstItemLost']() != 1",
      "note" = "U2: goodberry",
    }, {
      "expr" = "strcmp(m['uad2ReflectingPoolName'](), \"Reflecting Pool\") != 0  or  m['uad2ReflectingPoolNameHeaderGarbled']() != 1  or  m['uad2ReflectingPoolSchoolLost']() != 1  or  m['uad2ReflectingPoolComponentsVSM']() != 1  or m['uad2ReflectingPoolLevel']() != 2  or m['uad2ReflectingPoolCastingTimeHours']() != 2  or m['uad2ReflectingPoolRangeInches']() != 1  or  m['uad2ReflectingPoolSaveNone']() != 1  or m['uad2ReflectingPoolDurationRoundsPerLevel']() != 1  or  m['uad2ReflectingPoolAoeSpecial']() != 1  or  m['uad2ReflectingPoolNaturalWaterOnly']() != 1  or m['uad2ReflectingPoolDiameterFeetPerLevel']() != 2  or  m['uad2ReflectingPoolCrystalBallLike']() != 1  or  m['uad2ReflectingPoolMagicMirrorAndFontRef']() != 1  or  m['uad2ReflectingPoolCoexistentPlanesOnly']() != 1  or  m['uad2ReflectingPoolIncludesParaElementalAndShadow']() != 1  or  m['uad2ReflectingPoolCrystalBallPenaltiesApply']() != 1  or m['uad2ReflectingPoolCastThroughChancePctPerLevel']() != 5  or m['uad2ReflectingPoolCastThroughCount']() != 3  or strcmp(m['uad2ReflectingPoolCastThroughName'](0), \"Detect Magic\") != 0  or strcmp(m['uad2ReflectingPoolCastThroughName'](1), \"Detect Snares and Pits\") != 0  or strcmp(m['uad2ReflectingPoolCastThroughName'](2), \"Detect Poison\") != 0  or  m['uad2ReflectingPoolInfraAndUltravisionNormal']() != 1  or  m['uad2ReflectingPoolStarshineOperates']() != 1  or  m['uad2ReflectingPoolCompanionSpellNameLost']() != 1  or  m['uad2ReflectingPoolMaterialMistletoe']() != 1  or  m['uad2ReflectingPoolMaterialNutOil']() != 1  or  m['uad2ReflectingPoolMaterialMeasureLost']() != 1",
      "note" = "U3: reflecting pool",
    }, {
      "expr" = "strcmp(m['uad2SlowPoisonName'](), \"Slow Poison (Necromantic)\") != 0  or  m['uad2SlowPoisonComponentsVSM']() != 1  or m['uad2SlowPoisonLevel']() != 2  or  m['uad2SlowPoisonRangeTouch']() != 1  or  m['uad2SlowPoisonRangeCellHeadLost']() != 1  or  m['uad2SlowPoisonSaveNone']() != 1  or m['uad2SlowPoisonDurationHoursPerLevel']() != 1  or  m['uad2SlowPoisonAoeCreatureTouched']() != 1  or m['uad2SlowPoisonCastingTimeSegments']() != 1  or  m['uad2SlowPoisonIdenticalToClerical']() != 1  or m['uad2SlowPoisonAntidoteChancePctPerLevel']() != 5  or  m['uad2SlowPoisonPlantPoisonCondition']() != 1  or  m['uad2SlowPoisonDetectPoisonIndicatesOrganic']() != 1  or  m['uad2SlowPoisonRollEqualOrLessNeutralizes']() != 1  or  m['uad2SlowPoisonMaterialMistletoe']() != 1  or  m['uad2SlowPoisonMaterialGarlicOnFeet']() != 1  or  m['uad2SlowPoisonAntidoteOutdoorOrHerbalist']() != 1",
      "note" = "U4: slow poison",
    }, {
      "expr" = "m['uastDruid1stCount']() != 4  or strcmp(m['uastDruid1stName'](0), \"Locate Animals\") != 0  or m['uastDruid4thCount']() != 6  or strcmp(m['uastDruid4thName'](0), \"Cure Serious Wounds\") != 0  or m['uastDruid5thCount']() != 6  or strcmp(m['uastDruid5thName'](0), \"Commune With Nature\") != 0",
      "note" = "U5: the R341 table seam",
    } },
  "audit" = {
      "label" = "R351: the UA new druid 2nd level spells pin audit",
      "comment" = "The UA NEW DRUID SPELLS (pp. 43-44), the 2nd level - flame blade (the undead/fire damage modifiers), goodberry (the name header lost), reflecting pool (the \"Pool ion -\" garble, the scrying mechanics) and slow poison (the herbal antidote chance). The digit-garble family decodes the \"7 round\" and the two \"7 round/level\" cells as 1 (flame blade prints the clean 2). The item stays open (the 3rd-7th levels).",
    },
}
