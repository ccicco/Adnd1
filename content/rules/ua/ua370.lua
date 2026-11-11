-- ua370: promoted from rules/ua/uasmalls1.h (the The UA DM-SECTION SMALLS, part 1,);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 370,
  "prefix" = "ua370",
  "banner" = {
      "title" = "The UA DM-SECTION SMALLS, part 1,",
      "provenance" = "R370: three items - Method V (p. 74), the starting hit-point minimums (p. 74), the warhorses and barding movement rate table (p. 76).  Pin-era pattern (R322): pinned data only - no engine site exists. The R368 seam cross-checks the cavalier starting floor against the level-1 d10 pin (rules/ua/uacavtable.h).  JUDGMENTs (the decode method): - the Method V prose prints clean (the humans-only class-first read, the best-three-of-N roll, the minimum and maximum clamps, the 9d6 fighter strength example); the dice-count table body extracts EMPTY - every cell a hole, flagged pending the PDF. - the starting hit-point minimums print clean - the 12 class floors, the multi-class average rounded up with the fighter/magic-user 5 example, the constitution adjustment with the con-17 fighter 9 example. - R394: the clean PDF read fills the Method V dice-count table (the 12 x 7 matrix cell by cell) and repins the barding columns - the R370 labels sat one column off: light leather 21 scale 15 chain NA, medium 17/15/12, heavy leather 15 scale 14 chain 13 plate 12.",
    },
  "consts" = { {
      "name" = "uasm1MethodVFighterStrengthDice",
      "value" = 9,
      "comment" = "The worked example: the fighter strength rolls 9d6, keep the three highest.",
    }, {
      "name" = "uasm1StartHpClassCount",
      "value" = 12,
      "comment" = "---- the starting hit-point minimums (p. 74) ---- Slots: 0 Cavalier, 1 Paladin, 2 Cleric, 3 Druid, 4 Fighter, 5 Barbarian, 6 Ranger, 7 Magic-user, 8 Illusionist, 9 Thief, 10 Assassin, 11 Monk.",
    }, {
      "name" = "uasm1StartHpExampleFighterMage",
      "value" = 5,
      "comment" = "The worked example: (6 + 3) / 2 = 5.",
    }, {
      "name" = "uasm1StartHpExampleCon17Fighter",
      "value" = 9,
      "comment" = "The worked example: a 1st-level fighter with a 17 constitution has at least 9.",
    }, {
      "name" = "uasm1MethodVClassCount",
      "value" = 12,
      "comment" = "---- the Method V dice-count table (p. 74, the R394 clean read) ---- Rows: 0 Cavalier, 1 Paladin, 2 Cleric, 3 Druid, 4 Fighter, 5 Barbarian, 6 Ranger, 7 Magic-user, 8 Illusionist, 9 Thief, 10 Assassin, 11 Monk. Columns: 0 Str, 1 Int, 2 Wis, 3 Dex, 4 Con, 5 Cha, 6 Com.",
    }, {
      "name" = "uasm1MethodVAbilityCount",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uasm1BardLightLeather",
      "value" = 21,
      "comment" = "---- the barding movement table (p. 76) ----// Base movement rates in inches; NA = the heavier barding is not allowed on the lighter horse.",
    }, {
      "name" = "uasm1BardLightScale",
      "value" = 15,
      "comment" = "The R394 clean read: the light row is leather 21, scale 15, chain NA - the R370 15 sat on the scale cell and the NA on the chain.",
    }, {
      "name" = "uasm1BardLightChain",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uasm1BardMediumLeather",
      "value" = 17,
      "comment" = "",
    }, {
      "name" = "uasm1BardMediumScale",
      "value" = 15,
      "comment" = "The R394 clean read: medium scale 15, chain 12 - the R370 15 was the scale value on the chain cell.",
    }, {
      "name" = "uasm1BardMediumChain",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uasm1BardHeavyLeather",
      "value" = 15,
      "comment" = "The R394 clean read: the heavy row is leather 15, scale 14, chain 13 - the R370 values sat one column left.",
    }, {
      "name" = "uasm1BardHeavyChain",
      "value" = 13,
      "comment" = "",
    }, {
      "name" = "uasm1BardHeavyScale",
      "value" = 14,
      "comment" = "",
    }, {
      "name" = "uasm1BardHeavyPlate",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingCostMultiple",
      "value" = 5,
      "comment" = "---- the magical barding ---- Worth five times the cost of comparable armor; the plus can never exceed +3.",
    }, {
      "name" = "uasm1MagBardingPlusCap",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingPlus1Pct",
      "value" = 65,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingPlus2Pct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingPlus3Pct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingLeatherPct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingScalePct",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingChainPct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uasm1MagBardingPlatePct",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uasm1StrongMountPlateReductionMin",
      "value" = 5,
      "comment" = "A very strong mount in plate barding loses from one-fifth to one-eighth of its movement; an elephant the least (the one-eighth).",
    }, {
      "name" = "uasm1StrongMountPlateReductionMax",
      "value" = 8,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uasm1MethodVHumansOnly",
      "value" = true,
      "comment" = "---- Method V (p. 74) ---- The class-first generation: the player picks the class (subject to DM approval), rolls N dice per ability, keeps the best three.",
    }, {
      "name" = "uasm1MethodVClassFirst",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1MethodVRequiresDmApproval",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1MethodVBestThreeOfN",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1MethodVMinClampApplies",
      "value" = true,
      "comment" = "If the best-three total is below the class minimum the minimum applies; if above the maximum allowable (the barbarian wisdom) the maximum applies.",
    }, {
      "name" = "uasm1MethodVMaxClampApplies",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1MethodVTableCellsLost",
      "value" = false,
      "comment" = "The dice-count table body extracts empty in the markdown; the R394 clean PDF read fills the matrix.",
    }, {
      "name" = "uasm1StartHpMultiClassAverageRoundedUp",
      "value" = true,
      "comment" = "A multi-class character uses the average of the applicable minimums, rounded up.",
    }, {
      "name" = "uasm1StartHpConAdjustApplies",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1BardLightChainNa",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1BardLightScaleNa",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uasm1BardLightPlateNa",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1BardMediumScaleCellLost",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uasm1BardMediumPlateNa",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1BardHeavyLeatherCellLost",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uasm1BardEnduranceFromBaseRate",
      "value" = true,
      "comment" = "The endurance rule: the base movement rate gives the miles per day.",
    }, {
      "name" = "uasm1FlyingSteedsLeatherOrElfinOnly",
      "value" = true,
      "comment" = "---- the other steeds ---- Flying steeds wear only leather (or elfin chain) barding, with the movement reduced by one-eighth; aquatic steeds cannot be barded.",
    }, {
      "name" = "uasm1FlyingSteedsReductionEighth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1AquaticSteedsNotBarded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uasm1UnicornGriffonElfinWeightAsLeather",
      "value" = true,
      "comment" = "Elfin chain for unicorns or griffons: the weight and movement effect equal leather barding; the protection equal chain.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uasm1StartHpMin",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[12] = { 6, 6, 5, 5, 6, 7, 9, 3, 3, 4, 4, 5, }; if (slot < 0) slot = 0; if (slot > 11) slot = 11; return k[slot];",
    }, {
      "name" = "uasm1MethodVDice",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[12][7] = { {8, 6, 4, 7, 9, 3, 5}, {7, 5, 8, 3, 6, 9, 4}, {7, 4, 9, 5, 8, 6, 3}, {7, 4, 8, 5, 6, 9, 3}, {9, 3, 5, 7, 8, 6, 4}, {9, 3, 5, 7, 8, 6, 4}, {7, 6, 8, 5, 9, 4, 3}, {4, 9, 7, 8, 6, 5, 3}, {3, 8, 7, 9, 5, 6, 4}, {6, 5, 3, 9, 7, 4, 8}, {6, 7, 4, 9, 8, 3, 5}, {7, 5, 9, 8, 6, 4, 3}, }; if (cls < 0) cls = 0; if (cls > 11) cls = 11; if (ab < 0) ab = 0; if (ab > 6) ab = 6; return k[cls][ab];",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uasm1MethodVHumansOnly']() != 1  or  m['uasm1MethodVClassFirst']() != 1  or  m['uasm1MethodVRequiresDmApproval']() != 1  or  m['uasm1MethodVBestThreeOfN']() != 1  or  m['uasm1MethodVMinClampApplies']() != 1  or  m['uasm1MethodVMaxClampApplies']() != 1  or m['uasm1MethodVFighterStrengthDice']() != 9  or m['uasm1MethodVTableCellsLost']()",
      "note" = "---- Method V ----",
    }, {
      "expr" = "m['uasm1StartHpClassCount']() != 12  or m['uasm1StartHpMin'](i) != hp[i]  or  m['uasm1StartHpMultiClassAverageRoundedUp']() != 1  or m['uasm1StartHpExampleFighterMage']() != 5  or  m['uasm1StartHpConAdjustApplies']() != 1  or m['uasm1StartHpExampleCon17Fighter']() != 9  or (6 + 3 + 1) / 2 !=m['uasm1StartHpExampleFighterMage']()  or m['uasm1StartHpMin'](4) + 3 !=m['uasm1StartHpExampleCon17Fighter']()",
      "note" = "---- the starting hit points ----",
    }, {
      "expr" = "m['uasm1BardLightLeather']() != 21  or  m['uasm1BardLightChainNa']() != 1  or m['uasm1BardLightScale']() != 15  or m['uasm1BardLightScaleNa']()  or  m['uasm1BardLightPlateNa']() != 1  or m['uasm1BardMediumLeather']() != 17  or m['uasm1BardMediumChain']() != 12  or m['uasm1BardMediumScaleCellLost']()  or m['uasm1BardMediumScale']() != 15  or  m['uasm1BardMediumPlateNa']() != 1  or m['uasm1BardHeavyLeatherCellLost']()  or m['uasm1BardHeavyLeather']() != 15  or m['uasm1BardHeavyChain']() != 13  or m['uasm1BardHeavyScale']() != 14  or m['uasm1BardHeavyPlate']() != 12  or m['uasm1BardHeavyLeather']() <=m['uasm1BardHeavyScale']()  or m['uasm1BardHeavyChain']() <=m['uasm1BardHeavyPlate']()  or m['uasm1BardLightLeather']() <=m['uasm1BardMediumLeather']()  or  m['uasm1BardEnduranceFromBaseRate']() != 1",
      "note" = "---- the barding table ----",
    }, {
      "expr" = "m['uasm1MagBardingCostMultiple']() != 5  or m['uasm1MagBardingPlusCap']() != 3  or m['uasm1MagBardingPlus1Pct']() +m['uasm1MagBardingPlus2Pct']() +m['uasm1MagBardingPlus3Pct']() != 100  or m['uasm1MagBardingLeatherPct']() +m['uasm1MagBardingScalePct']() +m['uasm1MagBardingChainPct']() +m['uasm1MagBardingPlatePct']() != 100  or m['uasm1MagBardingPlus1Pct']() != 65  or m['uasm1MagBardingPlus2Pct']() != 25  or m['uasm1MagBardingPlus3Pct']() != 10  or m['uasm1MagBardingLeatherPct']() != 10  or m['uasm1MagBardingScalePct']() != 15  or m['uasm1MagBardingChainPct']() != 25  or m['uasm1MagBardingPlatePct']() != 50",
      "note" = "---- the magical barding ----",
    }, {
      "expr" = "m['uasm1FlyingSteedsLeatherOrElfinOnly']() != 1  or  m['uasm1FlyingSteedsReductionEighth']() != 1  or  m['uasm1AquaticSteedsNotBarded']() != 1  or m['uasm1StrongMountPlateReductionMin']() != 5  or m['uasm1StrongMountPlateReductionMax']() != 8  or  m['uasm1UnicornGriffonElfinWeightAsLeather']() != 1",
      "note" = "---- the other steeds ----",
    }, {
      "expr" = "m['uasm1StartHpMin'](0) >m['uacavtDirectFirstSides']()",
      "note" = "---- the R368 seam ----",
    } },
  "audit" = {
      "label" = "R370: the UA DM-section smalls pin audit",
      "comment" = "The UA DM-section smalls, part 1: Method V (p. 74) - the class-first humans-only generation, the best-three-of-N roll with the DM approval, the minimum and maximum clamps, the 9d6 fighter strength example (the dice table cells lost, flagged); the starting hit-point minimums (p. 74) - the 12 class floors, the multi-class average rounded up, the constitution adjustment; the warhorses and barding (p. 76) - the movement rate table (the medium scale and heavy leather cells lost, flagged), the endurance rule, the magical barding costs and percentages, the flying and aquatic steeds rules. The R368 seam cross-checks the cavalier d10 floor. Three items flip CLOSED; the census 296 -> 297.",
    },
}
