-- oa633: promoted from rules/oa/oabr.h (the BIRTHRIGHTS AND TABLE 40, printed capture pp. 68-69 - the OA birthrights);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 633,
  "prefix" = "oa633",
  "banner" = {
      "title" = "BIRTHRIGHTS AND TABLE 40, printed capture pp. 68-69 - the OA birthrights",
      "provenance" = "round census 555 -> 556.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. No contested cells detected within the single source: the T40 bands run contiguously 1 through 100 and every honor value sits on its printed row. The T40 result column pins as the 0-11 code (blank 0, roll again 1, property share 2, horse 3, the 1-6 cash strings 4, armor of quality 5, the 1-8 cash strings 6, weapon of quality 7, the 1-4 horses 8, the 2-12 cash strings 9, the magical weapon 10, the d100 roll again 11); the die bands pin as the lo and hi bounds; the honor column is personal honor. OCR normalization: the print capitalization varies (Property Share at 6 and 17-18, Property share at 8, 41-45 and 56-60, Armor of quality and Weapon of quality at their rows) - all pin as the same codes; rows 4 and 7 read \"next higher die or + 10\" while row 100 reads \"with + 10 on die roll\" (the printed d100 doctrine - both pin as the roll-again codes 1 and 11). The Chapter 4 Honor prose (capture pp. 69-73) is deliberately left for the next rounds  the gap census after this round: 74 closed, 161 open - the Birthrights prose and Table 40 boxes flip (census 555 -> 556); NEXT - R634: the Honor chapter opener, the Gaining and Losing Honor prose and Table 41 (Initial Honor), capture pp. 69-70, prefix dgu (verify free), audit \"R634 OA honor audit\", include after rules/oa/oabr.h",
    },
  "consts" = { {
      "name" = "dgtT40RowCount",
      "value" = 26,
      "comment" = "Table 40 (capture pp. 68-69): twenty-six birthrights rows",
    }, {
      "name" = "dgtFirstSonRollPenalty",
      "value" = 1,
      "comment" = "Birthrights prose (capture p. 68): the first son subtracts one from the rolls allowed",
    }, {
      "name" = "dgtPropShareMinPct",
      "value" = 10,
      "comment" = "Property share prose (capture p. 69): the share lower bound, 10 percent of the yearly income",
    }, {
      "name" = "dgtPropShareMaxPct",
      "value" = 30,
      "comment" = "Property share prose (capture p. 69): the share upper bound, 30 percent of the yearly income",
    }, {
      "name" = "dgtCashPerString",
      "value" = 100,
      "comment" = "Cash strings prose (capture p. 69): each string holds 100 coins",
    }, {
      "name" = "dgtMagicWeaponMaxPlus",
      "value" = 2,
      "comment" = "Magical weapon prose (capture p. 69): never more magical than +2",
    } },
  "bools" = { {
      "name" = "dgtBirthrightClanVirtue",
      "value" = true,
      "comment" = "Birthrights prose (capture p. 68): a birthright is something the character begins the game with, by virtue of his family clan - an heirloom or a share of the family holdings",
    }, {
      "name" = "dgtBirthrightMayBeNothing",
      "value" = true,
      "comment" = "Birthrights prose (capture p. 68): it may be nothing, owing to poverty, birth order or chance",
    }, {
      "name" = "dgtSharedClanOwnership",
      "value" = true,
      "comment" = "Birthrights prose (capture p. 68): once determined, the birthright is the property of both the player character and the family clan",
    }, {
      "name" = "dgtDeathReturnsToClan",
      "value" = true,
      "comment" = "Birthrights prose (capture p. 68): if the player character dies, the birthright returns to the possession of the family clan",
    }, {
      "name" = "dgtLostBirthrightLosesHonor",
      "value" = true,
      "comment" = "Birthrights prose (capture p. 68): if the character loses a birthright, he and his family lose honor",
    }, {
      "name" = "dgtRollsDeterminedByT38",
      "value" = true,
      "comment" = "Birthrights prose (capture p. 68): the die type and the number of rolls were determined by Table 38: Character Birth",
    }, {
      "name" = "dgtBirthRankReducesRolls",
      "value" = true,
      "comment" = "Birthrights prose (capture p. 68): the number of rolls allowed is modified by subtracting the character's birth rank",
    }, {
      "name" = "dgtHonorIsPersonal",
      "value" = true,
      "comment" = "T40 honor prose (capture p. 68): the honor gained is personal, not family - it is added to the character's honor at the start of the game and does not increase the family base honor",
    }, {
      "name" = "dgtPropShareAncestorLandsOnly",
      "value" = true,
      "comment" = "Property share prose (capture p. 69): the shares come only from the lands held by the father, the grandfather or the head of the family",
    }, {
      "name" = "dgtPropShareSingleCap",
      "value" = true,
      "comment" = "Property share prose (capture p. 69): never more than a 30 percent share in a single property",
    }, {
      "name" = "dgtPropShareNoPropertyRead",
      "value" = true,
      "comment" = "Property share prose (capture p. 69): if the family holds no productive property, the roll is treated as no result",
    }, {
      "name" = "dgtHorseAnyTypeNoTack",
      "value" = true,
      "comment" = "Horse prose (capture p. 69): one or more horses of any type desired, without a saddle or other tack",
    }, {
      "name" = "dgtCashStringDmCoinType",
      "value" = true,
      "comment" = "Cash strings prose (capture p. 69): the DM determines the type of coin in each string",
    }, {
      "name" = "dgtQualityArmorDmWeaponPlayer",
      "value" = true,
      "comment" = "Heirloom prose (capture p. 69): the DM randomly determines the armor type; the player chooses the weapon type",
    }, {
      "name" = "dgtQualityItemNotTransferable",
      "value" = true,
      "comment" = "Heirloom prose (capture p. 69): the items cannot be given away or sold, since they belong in part to the family, and are expected to pass on through the family",
    }, {
      "name" = "dgtMagicWeaponSwordOrMisc",
      "value" = true,
      "comment" = "Magical weapon prose (capture p. 69): either a sword or a miscellaneous weapon, complete with history",
    }, {
      "name" = "dgtMagicWeaponNoSpecialAbilities",
      "value" = true,
      "comment" = "Magical weapon prose (capture p. 69): the weapon has no special abilities",
    }, {
      "name" = "dgtMagicWeaponNeverSold",
      "value" = true,
      "comment" = "Magical weapon prose (capture p. 69): the character can never give away or sell the item",
    }, {
      "name" = "dgtMagicWeaponLostHonorLoss",
      "value" = true,
      "comment" = "Magical weapon prose (capture p. 69): losing the item and still living means a great loss of honor",
    }, {
      "name" = "dgtRollAgainNextLargerDie",
      "value" = true,
      "comment" = "Roll again prose (capture p. 69): the next larger die (1d4 becomes 1d6, 1d6 becomes 1d8, etc.), or add 10 when already rolling d100",
    } },
  "switches" = { {
      "name" = "dgtT40DieLo",
      "values" = { 1, 4, 5, 6, 7, 8, 9, 17, 19, 20, 21, 31, 34, 41, 46, 51, 56, 61, 64, 71, 76, 81, 91, 96, 99, 100 },
      "default" = -99,
      "comment" = "the die-band lower bound column (capture pp. 68-69).",
    }, {
      "name" = "dgtT40DieHi",
      "values" = { 3, 4, 5, 6, 7, 8, 16, 18, 19, 20, 30, 33, 40, 45, 50, 55, 60, 63, 70, 75, 80, 90, 95, 98, 99, 100 },
      "default" = -99,
      "comment" = "the die-band upper bound column - the bands run contiguously 1 through 100 (capture pp. 68-69).",
    }, {
      "name" = "dgtT40Honor",
      "values" = { 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 2, 0, 1, 0, 0, 1, 2, 0, 2, 1, 0, 0, 2, 4, 0 },
      "default" = -99,
      "comment" = "the honor column: the personal honor gained, 0 to +4 (capture pp. 68-69).",
    }, {
      "name" = "dgtT40Result",
      "values" = { 0, 1, 0, 2, 1, 2, 0, 2, 3, 4, 0, 5, 0, 2, 0, 6, 2, 7, 0, 5, 8, 0, 9, 7, 10, 11 },
      "default" = -99,
      "comment" = "the birthright result column, pinned as the 0-11 code: blank 0, roll again 1, property share 2, horse 3, the 1-6 cash strings 4, armor of quality 5, the 1-8 cash strings 6, weapon of quality 7, the 1-4 horses 8, the 2-12 cash strings 9, the magical weapon 10, the d100 roll again 11 (capture pp. 68-69).",
    } },
  "tables" = { {
      "name" = "dgtT40Grid",
      "tag" = "T40",
      "count" = "dgtT40RowCount",
      "sentinel" = -99,
      "cols" = { "dgtT40DieLo", "dgtT40DieHi", "dgtT40Honor", "dgtT40Result" },
      "data" = { { 1, 3, 0, 0 }, { 4, 4, 0, 1 }, { 5, 5, 0, 0 }, { 6, 6, 1, 2 }, { 7, 7, 0, 1 }, { 8, 8, 1, 2 }, { 9, 16, 0, 0 }, { 17, 18, 1, 2 }, { 19, 19, 0, 3 }, { 20, 20, 0, 4 }, { 21, 30, 0, 0 }, { 31, 33, 2, 5 }, { 34, 40, 0, 0 }, { 41, 45, 1, 2 }, { 46, 50, 0, 0 }, { 51, 55, 0, 6 }, { 56, 60, 1, 2 }, { 61, 63, 2, 7 }, { 64, 70, 0, 0 }, { 71, 75, 2, 5 }, { 76, 80, 1, 8 }, { 81, 90, 0, 0 }, { 91, 95, 0, 9 }, { 96, 98, 2, 7 }, { 99, 99, 4, 10 }, { 100, 100, 0, 11 } },
      "comment" = "the Table 40 birthrights grid (capture pp. 68-69)",
      "col_comments" = { "the die-band lower bound column (capture pp. 68-69).", "the die-band upper bound column - the bands run contiguously 1 through 100 (capture pp. 68-69).", "the honor column: the personal honor gained, 0 to +4 (capture pp. 68-69).", "the birthright result column, pinned as the 0-11 code: blank 0, roll again 1, property share 2, horse 3, the 1-6 cash strings 4, armor of quality 5, the 1-8 cash strings 6, weapon of quality 7, the 1-4 horses 8, the 2-12 cash strings 9, the magical weapon 10, the d100 roll again 11 (capture pp. 68-69)." },
      "audit_comment" = "the Table 40 grid: the die bands, the personal honor column and the coded birthrights (capture pp. 68-69)",
      "sentinel_census" = { 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgtT40RowCount']() != 26  or m['dgtPropShareMinPct']() != 10  or m['dgtPropShareMaxPct']() != 30  or m['dgtCashPerString']() != 100  or m['dgtMagicWeaponMaxPlus']() != 2  or m['dgtFirstSonRollPenalty']() != 1  or  m['dgtBirthrightClanVirtue']() != 1  or  m['dgtBirthrightMayBeNothing']() != 1  or  m['dgtSharedClanOwnership']() != 1  or  m['dgtDeathReturnsToClan']() != 1  or  m['dgtLostBirthrightLosesHonor']() != 1  or  m['dgtRollsDeterminedByT38']() != 1  or  m['dgtBirthRankReducesRolls']() != 1  or  m['dgtHonorIsPersonal']() != 1  or  m['dgtPropShareAncestorLandsOnly']() != 1  or  m['dgtPropShareSingleCap']() != 1  or  m['dgtPropShareNoPropertyRead']() != 1  or  m['dgtHorseAnyTypeNoTack']() != 1  or  m['dgtCashStringDmCoinType']() != 1  or  m['dgtQualityArmorDmWeaponPlayer']() != 1  or  m['dgtQualityItemNotTransferable']() != 1  or  m['dgtMagicWeaponSwordOrMisc']() != 1  or  m['dgtMagicWeaponNoSpecialAbilities']() != 1  or  m['dgtMagicWeaponNeverSold']() != 1  or  m['dgtMagicWeaponLostHonorLoss']() != 1  or  m['dgtRollAgainNextLargerDie']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgtT40RowCount']() != 26",
      "note" = "the dgtT40RowCount pin",
    }, {
      "expr" = "m['dgtPropShareMinPct']() != 10",
      "note" = "the dgtPropShareMinPct pin",
    }, {
      "expr" = "m['dgtPropShareMaxPct']() != 30",
      "note" = "the dgtPropShareMaxPct pin",
    }, {
      "expr" = "m['dgtCashPerString']() != 100",
      "note" = "the dgtCashPerString pin",
    }, {
      "expr" = "m['dgtMagicWeaponMaxPlus']() != 2",
      "note" = "the dgtMagicWeaponMaxPlus pin",
    }, {
      "expr" = "m['dgtFirstSonRollPenalty']() != 1",
      "note" = "the dgtFirstSonRollPenalty pin",
    }, {
      "expr" = "m['dgtBirthrightClanVirtue']() != 1",
      "note" = "the dgtBirthrightClanVirtue pin",
    }, {
      "expr" = "m['dgtBirthrightMayBeNothing']() != 1",
      "note" = "the dgtBirthrightMayBeNothing pin",
    }, {
      "expr" = "m['dgtSharedClanOwnership']() != 1",
      "note" = "the dgtSharedClanOwnership pin",
    }, {
      "expr" = "m['dgtDeathReturnsToClan']() != 1",
      "note" = "the dgtDeathReturnsToClan pin",
    }, {
      "expr" = "m['dgtLostBirthrightLosesHonor']() != 1",
      "note" = "the dgtLostBirthrightLosesHonor pin",
    }, {
      "expr" = "m['dgtRollsDeterminedByT38']() != 1",
      "note" = "the dgtRollsDeterminedByT38 pin",
    }, {
      "expr" = "m['dgtBirthRankReducesRolls']() != 1",
      "note" = "the dgtBirthRankReducesRolls pin",
    }, {
      "expr" = "m['dgtHonorIsPersonal']() != 1",
      "note" = "the dgtHonorIsPersonal pin",
    }, {
      "expr" = "m['dgtPropShareAncestorLandsOnly']() != 1",
      "note" = "the dgtPropShareAncestorLandsOnly pin",
    }, {
      "expr" = "m['dgtPropShareSingleCap']() != 1",
      "note" = "the dgtPropShareSingleCap pin",
    }, {
      "expr" = "m['dgtPropShareNoPropertyRead']() != 1",
      "note" = "the dgtPropShareNoPropertyRead pin",
    }, {
      "expr" = "m['dgtHorseAnyTypeNoTack']() != 1",
      "note" = "the dgtHorseAnyTypeNoTack pin",
    }, {
      "expr" = "m['dgtCashStringDmCoinType']() != 1",
      "note" = "the dgtCashStringDmCoinType pin",
    }, {
      "expr" = "m['dgtQualityArmorDmWeaponPlayer']() != 1",
      "note" = "the dgtQualityArmorDmWeaponPlayer pin",
    }, {
      "expr" = "m['dgtQualityItemNotTransferable']() != 1",
      "note" = "the dgtQualityItemNotTransferable pin",
    }, {
      "expr" = "m['dgtMagicWeaponSwordOrMisc']() != 1",
      "note" = "the dgtMagicWeaponSwordOrMisc pin",
    }, {
      "expr" = "m['dgtMagicWeaponNoSpecialAbilities']() != 1",
      "note" = "the dgtMagicWeaponNoSpecialAbilities pin",
    }, {
      "expr" = "m['dgtMagicWeaponNeverSold']() != 1",
      "note" = "the dgtMagicWeaponNeverSold pin",
    }, {
      "expr" = "m['dgtMagicWeaponLostHonorLoss']() != 1",
      "note" = "the dgtMagicWeaponLostHonorLoss pin",
    }, {
      "expr" = "m['dgtRollAgainNextLargerDie']() != 1",
      "note" = "the dgtRollAgainNextLargerDie pin",
    }, {
      "expr" = "m['dgtT40DieLo'](0) != 1  or m['dgtT40DieHi'](0) != 3  or m['dgtT40Honor'](0) != 0  or m['dgtT40Result'](0) != 0",
      "note" = "the T40 first row - the blank 1-3 band (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtT40Result'](1) != 1  or m['dgtT40Result'](4) != 1  or m['dgtT40Result'](25) != 11",
      "note" = "the T40 roll-again rows - 4 and 7 with the next-higher-die read, 100 with the d100 add-10 read (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtT40Honor'](3) != 1  or m['dgtT40Honor'](5) != 1  or m['dgtT40Honor'](7) != 1  or m['dgtT40Honor'](13) != 1  or m['dgtT40Honor'](16) != 1",
      "note" = "the T40 property-share rows - the +1 honor at 6, 8, 17-18, 41-45 and 56-60 (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtT40Result'](8) != 3  or m['dgtT40Result'](9) != 4  or m['dgtT40Result'](15) != 6  or m['dgtT40Result'](20) != 8  or m['dgtT40Result'](22) != 9",
      "note" = "the T40 horse and cash-string rows - the horse at 19, the 1-6 cash at 20, the 1-8 cash at 51-55, the 1-4 horses at 76-80, the 2-12 cash at 91-95 (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtT40Result'](11) != 5  or m['dgtT40Result'](19) != 5  or m['dgtT40Result'](17) != 7  or m['dgtT40Result'](23) != 7",
      "note" = "the T40 armor and weapon rows - armor of quality at 31-33 and 71-75, weapon of quality at 61-63 and 96-98 (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtT40Honor'](24) != 4  or m['dgtT40Result'](24) != 10",
      "note" = "the T40 magical weapon capstone - the +4 honor at die 99 (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtT40DieLo'](1) -m['dgtT40DieHi'](0) != 1  or m['dgtT40DieLo'](11) -m['dgtT40DieHi'](10) != 1  or m['dgtT40DieLo'](18) -m['dgtT40DieHi'](17) != 1  or m['dgtT40DieLo'](24) -m['dgtT40DieHi'](23) != 1",
      "note" = "the T40 band contiguity - 3 to 4, 30 to 31, 63 to 64, 98 to 99 (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtT40DieLo'](25) != 100  or m['dgtT40Honor'](25) != 0  or m['dgtT40RowCount']() != 26",
      "note" = "the T40 final band - the d100 roll again at 100, twenty-six rows only (capture pp. 68-69)",
    }, {
      "expr" = "m['dgtPropShareMinPct']() != 10  or m['dgtPropShareMaxPct']() != 30  or m['dgtPropShareAncestorLandsOnly']() != 1",
      "note" = "the property-share doctrine - the 10-to-30 percent share of the ancestor-held lands (capture p. 69)",
    } },
  "audit" = {
      "label" = "R633 OA birthrights audit",
      "comment" = "OA round twenty (capture pp. 68-69): the birthrights prose, the effects doctrines and the Table 40 grid",
    },
}
