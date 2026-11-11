-- oa648: promoted from rules/oa/oabardprose.h (the BARDING PROSE, printed capture pp. 98-99 - the OA barding prose round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 648,
  "prefix" = "oa648",
  "banner" = {
      "title" = "BARDING PROSE, printed capture pp. 98-99 - the OA barding prose round",
      "provenance" = "census 570 -> 571.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the section - the barding prose cross-checked paragraph-by-paragraph between the two passes (the intro on capture p. 98, the AC-factor list on capture p. 99 of the print pass); every printed number agrees - zero contested cells. The AC-factor list pins: leather or padded adds 1 factor to the AC and weighs 160#, metal scale adds 2 factors and weighs 250#, chain adds 3 factors and weighs 350#. The half-barding doctrine pins as consts and bools: half barding weighs half the amount of full barding (the divisor 2), increases the AC for frontal attacks only, and attacks from the rear do not gain the AC bonus; half barding is more frequently used than full barding, and half covers the head, neck and forequarters while full covers the entire body (the coverage split rides the comments). The materials paragraph pins: the most common material is quilted and padded cotton, the others in descending order are leather, leather scale, brigandine, metal scale and chain mail (the order rides the comment), and plate barding is never used - as a rule barding is only used on the mounts of important nobles, generals and shock troops (the mounts-only rule rides the comment). The warhorse must be able to carry the barding weight in addition to the rider and any equipment - and the movement-rate reduction cross-references the Table 55 grid already pinned in R646. The armor descriptions box stays open - the last Chapter 5 box  the gap census after this round: 99 closed, 136 open - the Barding prose box flips (census 570 -> 571); NEXT - R649: the armor prose and armor descriptions box (capture pp. 93-98), the suits-and-pieces doctrine and the armor description entries, prefix dhj (verify free), audit \"R649 OA armor descriptions audit\", include after rules/oa/oabardprose.h - the last Chapter 5 box",
    },
  "consts" = { {
      "name" = "dhiBardingMatCount",
      "value" = 3,
      "comment" = "the AC-factor list materials - leather or padded, metal scale and chain (capture p. 99 of the print pass; compressed p. 51)",
    }, {
      "name" = "dhiLeatherAcFactor",
      "value" = 1,
      "comment" = "leather or padded barding adds 1 factor to the AC (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiLeatherWeight",
      "value" = 160,
      "comment" = "leather or padded barding weighs 160# (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiMetalAcFactor",
      "value" = 2,
      "comment" = "metal scale barding adds 2 factors to the AC (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiMetalWeight",
      "value" = 250,
      "comment" = "metal scale barding weighs 250# (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiChainAcFactor",
      "value" = 3,
      "comment" = "chain barding adds 3 factors to the AC (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiChainWeight",
      "value" = 350,
      "comment" = "chain barding weighs 350# (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiHalfWeightDiv",
      "value" = 2,
      "comment" = "half barding weighs half the amount of full barding - the divisor 2 (capture p. 99 of the print pass)",
    } },
  "bools" = { {
      "name" = "dhiHalfMoreCommon",
      "value" = true,
      "comment" = "half barding is more frequently used than full barding - half covers the head, neck and forequarters while full covers the entire body (capture p. 98)",
    }, {
      "name" = "dhiPlateNeverUsed",
      "value" = true,
      "comment" = "plate barding is never used - the most common material is quilted and padded cotton, the others in descending order leather, leather scale, brigandine, metal scale and chain mail (capture p. 98)",
    }, {
      "name" = "dhiHalfFrontalOnly",
      "value" = true,
      "comment" = "half barding increases the AC for frontal attacks only (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiRearNoBonus",
      "value" = true,
      "comment" = "attacks from the rear do not gain the AC bonus (capture p. 99 of the print pass)",
    }, {
      "name" = "dhiMustCarryWeight",
      "value" = true,
      "comment" = "the warhorse must be able to carry the weight of the barding, in addition to that of the rider and any equipment; the movement-rate reduction is the Table 55 grid pinned in R646 (capture p. 99 of the print pass)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhiBardingMatCount']() != 3  or m['dhiLeatherAcFactor']() != 1  or m['dhiLeatherWeight']() != 160  or m['dhiMetalAcFactor']() != 2  or m['dhiMetalWeight']() != 250  or m['dhiChainAcFactor']() != 3  or m['dhiChainWeight']() != 350  or m['dhiHalfWeightDiv']() != 2  or  m['dhiHalfMoreCommon']() != 1  or  m['dhiPlateNeverUsed']() != 1  or  m['dhiHalfFrontalOnly']() != 1  or  m['dhiRearNoBonus']() != 1  or  m['dhiMustCarryWeight']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhiBardingMatCount']() != 3",
      "note" = "the barding material count pin - the AC-factor list",
    }, {
      "expr" = "m['dhiLeatherAcFactor']() != 1  or m['dhiLeatherWeight']() != 160",
      "note" = "the leather-or-padded factor and weight pins - 1 factor, 160#",
    }, {
      "expr" = "m['dhiMetalAcFactor']() != 2  or m['dhiMetalWeight']() != 250",
      "note" = "the metal-scale factor and weight pins - 2 factors, 250#",
    }, {
      "expr" = "m['dhiChainAcFactor']() != 3  or m['dhiChainWeight']() != 350",
      "note" = "the chain factor and weight pins - 3 factors, 350#",
    }, {
      "expr" = "m['dhiHalfWeightDiv']() != 2",
      "note" = "the half-barding weight divisor pin - half of full",
    }, {
      "expr" = "m['dhiHalfFrontalOnly']() != 1  or m['dhiRearNoBonus']() != 1  or m['dhiHalfMoreCommon']() != 1",
      "note" = "the half-barding doctrine pins - frontal only, rear no bonus, more common",
    }, {
      "expr" = "m['dhiPlateNeverUsed']() != 1",
      "note" = "the plate-never-used rule pin",
    }, {
      "expr" = "m['dhiMustCarryWeight']() != 1",
      "note" = "the must-carry-weight rule pin",
    } },
  "audit" = {
      "label" = "R648 OA barding prose audit",
      "comment" = "OA round thirty-five (capture pp. 98-99): the barding prose - the AC factors, the weights and the half-barding doctrine",
    },
}
