-- ua355: promoted from rules/uadruidspells7.h (the The UA NEW DRUID SPELLS (p. 45) pins, R355: the 7th-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 355,
  "prefix" = "ua355",
  "banner" = {
      "title" = "The UA NEW DRUID SPELLS (p. 45) pins, R355: the 7th-level",
      "provenance" = "spell descriptions - changestaff and sunray. This round CLOSES the druid spells item.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the changestaff name header is lost - the section prints only a stray \"-\" line where the name header belongs; the name pins as Changestaff from the gap item list and the prose; the school cell is lost with the header. - the changestaff stat block interleaves both columns; the Level cell is lost - the spell pins as 7th level from the section heading; components, range, casting time, duration, save and area cells pin clean. - the changestaff lightning sentence interleaves: \"chance for any given tree,\" + \"on the severity of\" + \"(\" [sic] + \"). He\" - words are lost between the fragments; position-decoded as \"depending on the severity of the storm\", with doubt pending the PDF. - the changestaff hit-die garbles: \"re- duces it my 1 hit die\" [sic] - the my decodes as by; \"Justi ke powder\" [sic] pins verbatim, flagged pending the PDF; \"itis by no means a true treant\" [sic] - the itis decodes as \"it is\". - the digit-garble family (the R343 precedent): the sunray duration prints \"7 round\" - the family decodes 1 round (sunray prints a clean \"Level: 7\" cell and clean 3 segments). - the item header list names only changestaff for the 7th level - the section prints two spells; sunray joins the pin this round.  OCR holes (the item CLOSES this round; these stay pending the PDF): the changestaff school cell; the changestaff lightning-sentence lost words; the Justi ke powder garble.",
    },
  "consts" = { {
      "name" = "uad7ChangestaffName",
      "value" = "Changestaff",
      "comment" = "---- changestaff, p. 45 ---- The name header is lost - a stray \"-\" line; the name pins from the gap item list and the prose.",
    }, {
      "name" = "uad7ChangestaffLevel",
      "value" = 7,
      "comment" = "The Level cell is lost in the stat-block interleave; the spell pins as 7th level from the section heading.",
    }, {
      "name" = "uad7ChangestaffCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffLightningTreeHours",
      "value" = 24,
      "comment" = "The druid must first have located a tree struck by lightning within the past 24 hours.",
    }, {
      "name" = "uad7ChangestaffLightningChanceMinPct",
      "value" = 1,
      "comment" = "The chance prints 1%-5% for any given tree, on the severity of the storm (the lost words position-decoded, with doubt).",
    }, {
      "name" = "uad7ChangestaffLightningChanceMaxPct",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffCuringDays",
      "value" = 28,
      "comment" = "Curing by sun drying and special smoke requires 28 days; shaping, carving, smoothing and polishing require another 28 days; the druid cannot engage in other activity during either period.",
    }, {
      "name" = "uad7ChangestaffShapingDays",
      "value" = 28,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffStartHitDice",
      "value" = 12,
      "comment" = "The staff/treant begins at 12 hit dice and 96 hit points, and goes to 11 and 88, 10 and 80, 9 and 72, and so on.",
    }, {
      "name" = "uad7ChangestaffStartHitPoints",
      "value" = 96,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffDamagePerHitDieLost",
      "value" = 8,
      "comment" = "Each 8 points of damage accumulated reduces it by 1 hit die (the \"my\" garble decodes as \"by\").",
    }, {
      "name" = "uad7ChangestaffCrumbleBelowHitDice",
      "value" = 7,
      "comment" = "As it loses hit dice it becomes smaller, losing attack power; brought below 7 hit dice, it crumbles to Justi ke powder [sic] and is lost.",
    }, {
      "name" = "uad7ChangestaffDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "The transformation lasts as many turns as the druid has levels, until commanded to return to true form, or until destroyed, whichever first occurs.",
    }, {
      "name" = "uad7SunrayName",
      "value" = "Sunray (Evocation - Alteration)",
      "comment" = "---- sunray (Evocation - Alteration), p. 45 ----",
    }, {
      "name" = "uad7SunrayLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uad7SunrayRangeInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad7SunrayDurationRounds",
      "value" = 1,
      "comment" = "The duration prints \"7 round\" - the digit-garble family decodes 1 round.",
    }, {
      "name" = "uad7SunrayCastingTimeSegments",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad7SunrayBlindnessMinRounds",
      "value" = 1,
      "comment" = "It inflicts blindness for 1-3 rounds upon all creatures within the area of effect unless a save versus spell is made.",
    }, {
      "name" = "uad7SunrayBlindnessMaxRounds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uad7SunrayUltravisionBlindnessMinRounds",
      "value" = 2,
      "comment" = "Creatures using ultravision may be blinded for 2-8 rounds.",
    }, {
      "name" = "uad7SunrayUltravisionBlindnessMaxRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uad7SunraySunlightHarmfulMaxRoundsOnSave",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uad7SunrayInfravisionLossMinRounds",
      "value" = 2,
      "comment" = "Those within the area of effect, and creatures within 2 inches of its perimeter, have no infravisual capabilities for 2-5 rounds.",
    }, {
      "name" = "uad7SunrayInfravisionLossMaxRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uad7SunrayInfravisionLossRadiusInches",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uad7SunrayUndeadDamageDiceCount",
      "value" = 8,
      "comment" = "Undead, including vampires, caught within the main area of effect must save versus spell, taking 8-48 points of damage or half damage if the save is made.",
    }, {
      "name" = "uad7SunrayUndeadDamageDiceSides",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uad7SunraySecondaryDamageDiceCount",
      "value" = 3,
      "comment" = "Those within the secondary area of effect, up to 2 inches from the perimeter, take 3-18 points of damage or none if the save is made.",
    }, {
      "name" = "uad7SunraySecondaryDamageDiceSides",
      "value" = 6,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uad7ChangestaffNameHeaderLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffSchoolLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffLevelCellLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffAoeTheDruidsStaff",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffStaffToLargestTreant",
      "value" = true,
      "comment" = "The spell changes the staff from a pole of dead wood into a treant of largest size.",
    }, {
      "name" = "uad7ChangestaffSeverityWordsLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffStaffAshOakYew",
      "value" = true,
      "comment" = "The staff must be of ash, oak, or yew wood.",
    }, {
      "name" = "uad7ChangestaffNoOtherActivityDuringPrep",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffHollyBerryJuiceRub",
      "value" = true,
      "comment" = "The finished staff, engraved with scenes of woodland life, is rubbed with the juice of holly berries, and its end is thrust into the earth of the druid grove while the druid speaks with plants, calling upon the staff to assist in time of need.",
    }, {
      "name" = "uad7ChangestaffGroveEarthAndSpeakWithPlants",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffDweomerLastsManyChanges",
      "value" = true,
      "comment" = "The item is charged with a dweomer which lasts for many changes from staff to treant and back again.",
    }, {
      "name" = "uad7ChangestaffMyGarbleDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffJustiKePowderGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffNeverRegainedExceptWish",
      "value" = true,
      "comment" = "The staff can never be brought upwards in hit dice or hit points, except by a wish, which restores it completely.",
    }, {
      "name" = "uad7ChangestaffWishRestoresCompletely",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffPlantsAndSpeaksInvocation",
      "value" = true,
      "comment" = "The transformation: the druid plants the staff end in the ground and speaks a special command prayer and invocation.",
    }, {
      "name" = "uad7ChangestaffNotATrueTreant",
      "value" = true,
      "comment" = "The staff/treant defends the druid or obeys in any way, but is by no means a true treant and cannot converse with actual treants (the \"itis\" garble decodes as \"it is\").",
    }, {
      "name" = "uad7ChangestaffCannotConverseWithTreants",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffEndsOnCommandOrDestruction",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7ChangestaffMaterialMistletoeOrMatchingLeaves",
      "value" = true,
      "comment" = "The material: mistletoe, or leaves of ash, oak, or yew of the same sort as the staff.",
    }, {
      "name" = "uad7SunrayComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunrayDurationGarbleDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunrayAoeOneInchDiameterSpherePlusSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunraySaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunrayBeamLikeActualSunlight",
      "value" = true,
      "comment" = "The spell evokes a burning beam of light similar to actual sunlight in all important aspects.",
    }, {
      "name" = "uad7SunraySaveNegatesBlindness",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunraySunlightHarmfulPermanentUnlessSave",
      "value" = true,
      "comment" = "Those to whom sunlight is harmful or unnatural suffer permanent blindness unless the save is made, in which case the blindness lasts 2-12 rounds.",
    }, {
      "name" = "uad7SunrayUndeadHalfDamageOnSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunraySecondaryNoDamageOnSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunrayFungoidDamagedAsUndead",
      "value" = true,
      "comment" = "The ultraviolet light damages fungoid creatures and subterranean fungi as if they were undead, but no saving throw is possible.",
    }, {
      "name" = "uad7SunrayFungoidNoSavePossible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad7SunrayMaterialAsterSeed",
      "value" = true,
      "comment" = "The material components are an aster seed and a piece of aventurine feldspar (sunstone).",
    }, {
      "name" = "uad7SunrayMaterialSunstoneFeldspar",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uad7ChangestaffName'](), \"Changestaff\") != 0  or  m['uad7ChangestaffNameHeaderLost']() != 1  or  m['uad7ChangestaffSchoolLost']() != 1  or m['uad7ChangestaffLevel']() != 7  or  m['uad7ChangestaffLevelCellLost']() != 1  or  m['uad7ChangestaffComponentsVSM']() != 1  or  m['uad7ChangestaffRangeTouch']() != 1  or m['uad7ChangestaffCastingTimeSegments']() != 3  or  m['uad7ChangestaffDurationSpecial']() != 1  or  m['uad7ChangestaffSaveNone']() != 1  or  m['uad7ChangestaffAoeTheDruidsStaff']() != 1  or  m['uad7ChangestaffStaffToLargestTreant']() != 1  or m['uad7ChangestaffLightningTreeHours']() != 24  or m['uad7ChangestaffLightningChanceMinPct']() != 1  or m['uad7ChangestaffLightningChanceMaxPct']() != 5  or  m['uad7ChangestaffSeverityWordsLost']() != 1  or  m['uad7ChangestaffStaffAshOakYew']() != 1  or m['uad7ChangestaffCuringDays']() != 28  or m['uad7ChangestaffShapingDays']() != 28  or  m['uad7ChangestaffNoOtherActivityDuringPrep']() != 1  or  m['uad7ChangestaffHollyBerryJuiceRub']() != 1  or  m['uad7ChangestaffGroveEarthAndSpeakWithPlants']() != 1  or  m['uad7ChangestaffDweomerLastsManyChanges']() != 1  or m['uad7ChangestaffStartHitDice']() != 12  or m['uad7ChangestaffStartHitPoints']() != 96  or m['uad7ChangestaffDamagePerHitDieLost']() != 8  or  m['uad7ChangestaffMyGarbleDecoded']() != 1  or m['uad7ChangestaffCrumbleBelowHitDice']() != 7  or  m['uad7ChangestaffJustiKePowderGarbled']() != 1  or  m['uad7ChangestaffNeverRegainedExceptWish']() != 1  or  m['uad7ChangestaffWishRestoresCompletely']() != 1  or  m['uad7ChangestaffPlantsAndSpeaksInvocation']() != 1  or  m['uad7ChangestaffNotATrueTreant']() != 1  or  m['uad7ChangestaffCannotConverseWithTreants']() != 1  or m['uad7ChangestaffDurationTurnsPerLevel']() != 1  or  m['uad7ChangestaffEndsOnCommandOrDestruction']() != 1  or  m['uad7ChangestaffMaterialMistletoeOrMatchingLeaves']() != 1",
      "note" = "U1: changestaff",
    }, {
      "expr" = "strcmp(m['uad7SunrayName'](), \"Sunray (Evocation - Alteration)\") != 0  or  m['uad7SunrayComponentsVSM']() != 1  or m['uad7SunrayLevel']() != 7  or m['uad7SunrayRangeInchesPerLevel']() != 1  or m['uad7SunrayDurationRounds']() != 1  or  m['uad7SunrayDurationGarbleDecoded']() != 1  or  m['uad7SunrayAoeOneInchDiameterSpherePlusSpecial']() != 1  or m['uad7SunrayCastingTimeSegments']() != 3  or  m['uad7SunraySaveSpecial']() != 1  or  m['uad7SunrayBeamLikeActualSunlight']() != 1  or m['uad7SunrayBlindnessMinRounds']() != 1  or m['uad7SunrayBlindnessMaxRounds']() != 3  or  m['uad7SunraySaveNegatesBlindness']() != 1  or m['uad7SunrayUltravisionBlindnessMinRounds']() != 2  or m['uad7SunrayUltravisionBlindnessMaxRounds']() != 8  or  m['uad7SunraySunlightHarmfulPermanentUnlessSave']() != 1  or m['uad7SunraySunlightHarmfulMaxRoundsOnSave']() != 12  or m['uad7SunrayInfravisionLossMinRounds']() != 2  or m['uad7SunrayInfravisionLossMaxRounds']() != 5  or m['uad7SunrayInfravisionLossRadiusInches']() != 2  or m['uad7SunrayUndeadDamageDiceCount']() != 8  or m['uad7SunrayUndeadDamageDiceSides']() != 6  or  m['uad7SunrayUndeadHalfDamageOnSave']() != 1  or m['uad7SunraySecondaryDamageDiceCount']() != 3  or m['uad7SunraySecondaryDamageDiceSides']() != 6  or  m['uad7SunraySecondaryNoDamageOnSave']() != 1  or  m['uad7SunrayFungoidDamagedAsUndead']() != 1  or  m['uad7SunrayFungoidNoSavePossible']() != 1  or  m['uad7SunrayMaterialAsterSeed']() != 1  or  m['uad7SunrayMaterialSunstoneFeldspar']() != 1",
      "note" = "U2: sunray",
    }, {
      "expr" = "m['uad7ChangestaffNotATrueTreant']() != 1  or  m['uad6LiveoakBecomesTreantMmSpec']() != 1  or m['uastDruid6thCount']() != 5",
      "note" = "U3: the treant seam and the closure",
    } },
  "audit" = {
      "label" = "R355: the UA new druid 7th level spells pin audit",
      "comment" = "The UA NEW DRUID SPELLS (p. 45), the 7th level - changestaff (the lost name header, the hit-die ladder with the wish-only recovery) and sunray (the blindness tiers and the undead damage split). The family decodes the \"7 round\" as 1. The item CLOSES this round.",
    },
}
