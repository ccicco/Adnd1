-- weq: promoted from tools/spec_r431.json (the The WSG EFFECTS ON EQUIPMENT, R431: the water and rust rules (the 2-day drying, the 2-week oiling, the armor crack, the shield split, the weapon break), the leather and rope rules, the wet-clothing temperature shift and the sand/dust chafe rules - the section closes the effects-of-the-environment chapter WHOLE.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 431,
  "prefix" = "weq",
  "banner" = {
      "title" = "The WSG EFFECTS ON EQUIPMENT, R431: the water and rust rules (the 2-day drying, the 2-week oiling, the armor crack, the shield split, the weapon break), the leather and rope rules, the wet-clothing temperature shift and the sand/dust chafe rules - the section closes the effects-of-the-environment chapter WHOLE.",
      "provenance" = "Provenance: the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 28-29; the user own copy OCR cross-checked against the djvu text layer, every number matched.",
      "sentinel" = null,
    },
  "consts" = { {
      "name" = "weqWetClothesDeltaTemp",
      "value" = 10,
      "comment" = "Wet clothing at 30 degrees counts as 10 degrees colder.",
    }, {
      "name" = "weqRustDryDays",
      "value" = 2,
      "comment" = "Dry metal off once every 2 days.",
    }, {
      "name" = "weqRustOilWeeks",
      "value" = 2,
      "comment" = "Oil or protect metal once every 2 weeks.",
    }, {
      "name" = "weqArmorCrackRoll",
      "value" = 20,
      "comment" = "The rusted-armor crack trigger: an unmodified 20.",
    }, {
      "name" = "weqArmorCrackDmgMin",
      "value" = 4,
      "comment" = "The crack needs more than 4 points of damage.",
    }, {
      "name" = "weqArmorCrackDen",
      "value" = 3,
      "comment" = "The crack chance: 1 in 3.",
    }, {
      "name" = "weqShieldSplitPct",
      "value" = 50,
      "comment" = "The rusted-shield split chance: 50 percent.",
    }, {
      "name" = "weqWeaponBreakRoll",
      "value" = 1,
      "comment" = "The rusted-weapon break trigger: an unmodified 1.",
    }, {
      "name" = "weqWeaponBreakDen",
      "value" = 3,
      "comment" = "The weapon break chance: 1 in 3.",
    }, {
      "name" = "weqBootsDryDays",
      "value" = 2,
      "comment" = "Thoroughly dry boots once every 2 days or so.",
    }, {
      "name" = "weqWetArrowPenalty",
      "value" = -1,
      "comment" = "A waterlogged arrow: -1 to hit and damage for a non-specialist.",
    }, {
      "name" = "weqChafeSurpriseDen",
      "value" = 6,
      "comment" = "Sand chafe: the surprise chance +1 in 6.",
    }, {
      "name" = "weqChafeMoveNum",
      "value" = 3,
      "comment" = "Severe chafe: 3/4 normal speed (numerator).",
    }, {
      "name" = "weqChafeMoveDen",
      "value" = 4,
      "comment" = "The chafe move denominator.",
    }, {
      "name" = "weqChafeDexPenalty",
      "value" = -1,
      "comment" = "Severe chafe: -1 dexterity for dodging and abrupt moves.",
    } },
  "bools" = { {
      "name" = "weqRustedArmorNoAcPenalty",
      "value" = true,
      "comment" = "Rusted armor suffers no direct AC penalty.",
    }, {
      "name" = "weqArmorCrackOneStepWorse",
      "value" = true,
      "comment" = "A cracked armor is one AC step worse.",
    }, {
      "name" = "weqArmorSecondHitBreaks",
      "value" = true,
      "comment" = "A second crack hit breaks the armor entirely until repaired.",
    }, {
      "name" = "weqShieldNearMissSplits",
      "value" = true,
      "comment" = "A shield hit at one under the needed roll may split it.",
    }, {
      "name" = "weqLeatherCrackedAsRusted",
      "value" = true,
      "comment" = "Cracked leather armor treats blows like rusted metal armor.",
    }, {
      "name" = "weqLeatherHeatCracks",
      "value" = true,
      "comment" = "Too much heat cracks leather drying it.",
    }, {
      "name" = "weqMudCanCrackLeather",
      "value" = true,
      "comment" = "Excessive dried mud can crack leather too.",
    }, {
      "name" = "weqWetKnotHardToUntie",
      "value" = true,
      "comment" = "A dry-made knot in a wet rope is hard to untie.",
    }, {
      "name" = "weqDryKnotLoosens",
      "value" = true,
      "comment" = "A wet-made knot weakens after the rope dries.",
    }, {
      "name" = "weqArrowSpecialistExempt",
      "value" = true,
      "comment" = "A bow specialist takes no wet-arrow penalty.",
    }, {
      "name" = "weqMagicalInkWaterproof",
      "value" = true,
      "comment" = "Spell and protection scrolls use waterproof ink.",
    }, {
      "name" = "weqSandAbrasionNegligible",
      "value" = true,
      "comment" = "Sand abrasion has no short-term effect in the vast majority of sandstorms.",
    }, {
      "name" = "weqSandPotionDmCall",
      "value" = true,
      "comment" = "A sand-contaminated potion may be untainted, ruined or poison at the DM discretion.",
    }, {
      "name" = "weqDustNotAbrasive",
      "value" = true,
      "comment" = "Dust is not abrasive; it penetrates further than sand.",
    }, {
      "name" = "weqDustNoChafe",
      "value" = true,
      "comment" = "Dust in clothing does not chafe; no prompt cleaning needed.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the wet-clothing example: wet gear at 30 degrees acts as 20 (10 colder)",
      "expr" = "m['weqWetClothesDeltaTemp']() != 10 or 30 - m['weqWetClothesDeltaTemp']() != 20",
    }, {
      "note" = "the armor crack gates: an unmodified 20 AND over 4 damage, then 1 in 3",
      "expr" = "m['weqArmorCrackRoll']() != 20 or m['weqArmorCrackDmgMin']() != 4 or m['weqArmorCrackDen']() != 3",
    }, {
      "note" = "the shield and weapon breaks: 50 percent on the near-miss, 1 in 3 on the unmodified 1",
      "expr" = "m['weqShieldSplitPct']() != 50 or m['weqWeaponBreakRoll']() != 1 or m['weqWeaponBreakDen']() != 3",
    }, {
      "note" = "the chafe penalties: +1 in 6 surprise, 3/4 speed, -1 dex",
      "expr" = "m['weqChafeSurpriseDen']() != 6 or 3 * m['weqChafeMoveDen']() != 4 * m['weqChafeMoveNum']() or m['weqChafeDexPenalty']() != -1",
    } },
  "audit" = {
      "label" = "R431 WSG equipment pin audit",
      "comment" = "The equipment effects slice pins the water, rust, leather, sand and dust rules (rules/wsg/wsgequip.h, prefix weq): the moisture and rust mechanics, the leather and rope rules, the wet-arrow penalty and the chafe penalties; census 355 -> 356.",
    },
}
