-- ua354: promoted from rules/uadruidspells6.h (the The UA NEW DRUID SPELLS (p. 45) pins, R354: the 6th-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 354,
  "prefix" = "ua354",
  "banner" = {
      "title" = "The UA NEW DRUID SPELLS (p. 45) pins, R354: the 6th-level",
      "provenance" = "spell descriptions - liveoak and water to dust.  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs (the decode method): - the digit-garble family (the R343 precedent): the liveoak casting time prints \"7 turn\" - the family decodes 1 turn (liveoak prints a clean \"Level: 6\" cell; water to dust prints a clean 6 and a clean \"8 segments\"). - the water to dust name header prints \"Water To Dust (,\" [sic]) - the school is lost in the garble; the gap item list calls it \"transmute water to dust\" - the spell pins as Water To Dust with the school and the transmute prefix flagged as holes. - the water to dust stat block interleaves both columns: the components cell prints only \"V,\"; the prose pins the full components (diamond dust of at least 500 gp value, a bit of seashell, and the druid's mistletoe; the reverse adds a pinch of normal dust). - the liveoak treant interleave: \", matching the specifications of the Monster Manual de-\" + \"scription, but with only a 3\\\" + \"rate. An oak\" reassembles as: matching the Monster Manual description, but with only a 3\" movement rate. An oak spell will radiate a magic aura - the word between 3\" and \"rate\" position-decodes as \"movement\", flagged with doubt pending the PDF.  OCR holes (the item stays open - the 7th level pins in the next round; these stay pending the PDF): the liveoak movement word; the water to dust school and transmute prefix; the water to dust components cell beyond the \"V,\" fragment.",
    },
  "consts" = { {
      "name" = "uad6LiveoakName",
      "value" = "Liveoak (Enchantment)",
      "comment" = "---- liveoak (Enchantment), p. 45 ----",
    }, {
      "name" = "uad6LiveoakLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakDurationDaysPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakCastingTimeTurns",
      "value" = 1,
      "comment" = "The casting time prints \"7 turn\" - the digit-garble family decodes 1 turn.",
    }, {
      "name" = "uad6LiveoakDwellingFeet",
      "value" = 10,
      "comment" = "The tree must be within 10 feet of the druid's dwelling place, within a place sacred to the druid, or within 10 inches of something which the druid wishes to guard or protect.",
    }, {
      "name" = "uad6LiveoakGuardedInches",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakTriggerWordsPerLevel",
      "value" = 1,
      "comment" = "A triggering phrase of up to one word per level of the caster is placed upon the dweomered oak.",
    }, {
      "name" = "uad6LiveoakExampleTriggerWords",
      "value" = 11,
      "comment" = "The example: an 11-word trigger usable by a druid of 11th or higher level - attack any persons who come near without first saying the sacred mistletoe phrase.",
    }, {
      "name" = "uad6LiveoakExampleCasterLevel",
      "value" = 11,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakTreantMovementRateInches",
      "value" = 3,
      "comment" = "The treant moves with only a 3-inch movement rate (the interleave decode; the movement word position-decoded with doubt).",
    }, {
      "name" = "uad6WaterToDustName",
      "value" = "Water To Dust",
      "comment" = "---- water to dust, p. 45 ---- The name header prints \"Water To Dust (,\" [sic]) - the school is lost in the garble; the gap item list calls the spell \"transmute water to dust\".",
    }, {
      "name" = "uad6WaterToDustLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustRangeInches",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustCastingTimeSegments",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustAoeCubicInchesPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustMuddyAreaMultiplier",
      "value" = 2,
      "comment" = "Muddy water expands the area of effect to double normal; wet mud quadruples it.",
    }, {
      "name" = "uad6WaterToDustWetMudAreaMultiplier",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustDiamondDustMinGp",
      "value" = 500,
      "comment" = "For either usage: diamond dust of at least 500 gp value, a bit of seashell, and the druid's mistletoe.",
    } },
  "bools" = { {
      "name" = "uad6LiveoakComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakAoeOneOakTree",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakSingleTreeAtATime",
      "value" = true,
      "comment" = "The spell is cast on but a single tree at a time, and while a liveoak cast by a particular druid is in effect, he or she cannot cast another such spell.",
    }, {
      "name" = "uad6LiveoakOnlyOnePerDruid",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakWithinSacredPlace",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakSizePerDesireAndAvailability",
      "value" = true,
      "comment" = "A healthy tree of small, medium, or large size, according to desire and availability.",
    }, {
      "name" = "uad6LiveoakBecomesTreantMmSpec",
      "value" = true,
      "comment" = "The liveoak triggers the tree into becoming a treant of appropriate size and attack capability, matching the Monster Manual specification.",
    }, {
      "name" = "uad6LiveoakMovementWordDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakRadiatesMagicAura",
      "value" = true,
      "comment" = "The oak spell radiates a magic aura, and can be returned to normal by a successful dispel magic or upon the desire of the druid who enchanted it.",
    }, {
      "name" = "uad6LiveoakDispelOrDesireReturns",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6LiveoakMaterialMistletoe",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustNameHeaderGarbled",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustSchoolLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustGapItemSaysTransmute",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustComponentsCellLost",
      "value" = true,
      "comment" = "The components cell prints only \"V,\" - a hole; the prose pins the full components.",
    }, {
      "name" = "uad6WaterToDustSaveNoneAndSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustStatBlockInterleaveDecoded",
      "value" = true,
      "comment" = "The stat block interleaves both columns; the prose opener splits as \"in-\" + \"stantly\" across the block.",
    }, {
      "name" = "uad6WaterToDustLiquidToPowderyDust",
      "value" = true,
      "comment" = "The subject area instantly undergoes a change from liquid to powdery dust.",
    }, {
      "name" = "uad6WaterToDustContactFormsSiltyMud",
      "value" = true,
      "comment" = "Water remaining in contact with the transmuted dust quickly permeates it, turning the dust into silty mud if a sufficient quantity exists, otherwise soaking or dampening accordingly.",
    }, {
      "name" = "uad6WaterToDustOnlyLiquidAtCasting",
      "value" = true,
      "comment" = "Only liquid actually existing in the area at the moment of casting is affected.",
    }, {
      "name" = "uad6WaterToDustPartialWaterAffected",
      "value" = true,
      "comment" = "Liquids only partially water are affected as far as the actual water is concerned; potions containing water as a component part are rendered useless.",
    }, {
      "name" = "uad6WaterToDustPotionsRenderedUseless",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustLivingUnaffectedExceptWaterNatives",
      "value" = true,
      "comment" = "Living creatures are unaffected, except those native to the Elemental Plane of Water: they receive a saving throw versus spell to escape, and only one such creature can be affected by any single casting, regardless of size (creature or area).",
    }, {
      "name" = "uad6WaterToDustWaterNativeSaveVsSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustOneCreaturePerCasting",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustReverseCreateWater",
      "value" = true,
      "comment" = "The reverse is simply a very high-powered create water spell requiring a pinch of normal dust as an additional material component.",
    }, {
      "name" = "uad6WaterToDustReverseAddsDustPinch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustMaterialSeashell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uad6WaterToDustMaterialMistletoe",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uad6LiveoakName'](), \"Liveoak (Enchantment)\") != 0  or  m['uad6LiveoakComponentsVSM']() != 1  or m['uad6LiveoakLevel']() != 6  or  m['uad6LiveoakRangeTouch']() != 1  or m['uad6LiveoakDurationDaysPerLevel']() != 1  or  m['uad6LiveoakAoeOneOakTree']() != 1  or m['uad6LiveoakCastingTimeTurns']() != 1  or  m['uad6LiveoakSaveNone']() != 1  or  m['uad6LiveoakSingleTreeAtATime']() != 1  or  m['uad6LiveoakOnlyOnePerDruid']() != 1  or m['uad6LiveoakDwellingFeet']() != 10  or  m['uad6LiveoakWithinSacredPlace']() != 1  or m['uad6LiveoakGuardedInches']() != 10  or  m['uad6LiveoakSizePerDesireAndAvailability']() != 1  or m['uad6LiveoakTriggerWordsPerLevel']() != 1  or m['uad6LiveoakExampleTriggerWords']() != 11  or m['uad6LiveoakExampleCasterLevel']() != 11  or  m['uad6LiveoakBecomesTreantMmSpec']() != 1  or m['uad6LiveoakTreantMovementRateInches']() != 3  or  m['uad6LiveoakMovementWordDecoded']() != 1  or  m['uad6LiveoakRadiatesMagicAura']() != 1  or  m['uad6LiveoakDispelOrDesireReturns']() != 1  or  m['uad6LiveoakMaterialMistletoe']() != 1",
      "note" = "U1: liveoak",
    }, {
      "expr" = "strcmp(m['uad6WaterToDustName'](), \"Water To Dust\") != 0  or  m['uad6WaterToDustNameHeaderGarbled']() != 1  or  m['uad6WaterToDustSchoolLost']() != 1  or  m['uad6WaterToDustGapItemSaysTransmute']() != 1  or  m['uad6WaterToDustComponentsCellLost']() != 1  or m['uad6WaterToDustLevel']() != 6  or m['uad6WaterToDustRangeInches']() != 6  or m['uad6WaterToDustCastingTimeSegments']() != 8  or  m['uad6WaterToDustSaveNoneAndSpecial']() != 1  or  m['uad6WaterToDustDurationPermanent']() != 1  or m['uad6WaterToDustAoeCubicInchesPerLevel']() != 1  or  m['uad6WaterToDustStatBlockInterleaveDecoded']() != 1  or  m['uad6WaterToDustLiquidToPowderyDust']() != 1  or m['uad6WaterToDustMuddyAreaMultiplier']() != 2  or m['uad6WaterToDustWetMudAreaMultiplier']() != 4  or  m['uad6WaterToDustContactFormsSiltyMud']() != 1  or  m['uad6WaterToDustOnlyLiquidAtCasting']() != 1  or  m['uad6WaterToDustPartialWaterAffected']() != 1  or  m['uad6WaterToDustPotionsRenderedUseless']() != 1  or  m['uad6WaterToDustLivingUnaffectedExceptWaterNatives']() != 1  or  m['uad6WaterToDustWaterNativeSaveVsSpell']() != 1  or  m['uad6WaterToDustOneCreaturePerCasting']() != 1  or  m['uad6WaterToDustReverseCreateWater']() != 1  or  m['uad6WaterToDustReverseAddsDustPinch']() != 1  or m['uad6WaterToDustDiamondDustMinGp']() != 500  or  m['uad6WaterToDustMaterialSeashell']() != 1  or  m['uad6WaterToDustMaterialMistletoe']() != 1",
      "note" = "U2: water to dust",
    }, {
      "expr" = "m['uastDruid6thCount']() != 5  or strcmp(m['uastDruid6thName'](0), \"Cure Critical Wounds\") != 0  or strcmp(m['uastDruid6thName'](4), \"Weather Summoning\") != 0",
      "note" = "U3: the R341 table seam",
    } },
  "audit" = {
      "label" = "R354: the UA new druid 6th level spells pin audit",
      "comment" = "The UA NEW DRUID SPELLS (p. 45), the 6th level - liveoak (the triggered treant with the 3-inch movement decode) and water to dust (the scrambled stat block with the muddy multipliers and the water-native save gate). The digit-garble family decodes the \"7 turn\" as 1. The item stays open (the 7th level).",
    },
}
