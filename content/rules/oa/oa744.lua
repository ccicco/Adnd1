-- oa744: promoted from rules/oa115table75.h (the OA TREASURE - TABLE 75, MAGICAL ARMOR, printed capture p. 289 - the armor);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 744,
  "prefix" = "oa744",
  "banner" = {
      "title" = "OA TREASURE - TABLE 75, MAGICAL ARMOR, printed capture p. 289 - the armor",
      "provenance" = "type grid round census 666 -> 667.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 197 closed, 38 open - the Table 75 box flips (census 666 -> 667); NEXT - R745: Table 76. Magical Armor Properties (capture p. 289, the caption prints a period), prefix dlg (verify free at the landing), audit \"R745 OA Table 76 properties audit\", include after rules/oa115table75.h",
    },
  "consts" = { {
      "name" = "dlfArmorRowCount",
      "value" = 23,
      "comment" = "the armor row count - the twenty-three d100 bands of the Table 75 armor type grid (print capture p. 289)",
    }, {
      "name" = "dlfSodePairAsterisk",
      "value" = 1,
      "comment" = "the sode asterisk - the sode, pair row carrying the asterisk of the print (print capture p. 289)",
    }, {
      "name" = "dlfSplintedOverlapMisprint",
      "value" = 1,
      "comment" = "the splinted overlap - the capture printing the 86-92 splinted band below the 87 sode row, an overlap with the 87 row (likely the 88-92 intended), pinned as printed (print capture p. 289)",
    }, {
      "name" = "dlfGajinArmorRollOnDMG",
      "value" = 1,
      "comment" = "the gajin armor - the 100 row rolling on the DMG Armor and Shield Table, the capture misreading gaijin (print capture p. 289)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlfArmorRollMin",
      "values" = { 1, 5, 6, 13, 17, 18, 23, 27, 31, 36, 45, 47, 56, 63, 67, 71, 75, 79, 83, 87, 86, 93, 100 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 289)",
    }, {
      "name" = "dlfArmorRollMax",
      "values" = { 4, 5, 12, 16, 17, 22, 26, 30, 35, 44, 46, 55, 62, 66, 70, 74, 78, 82, 86, 87, 92, 99, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 289)",
    }, {
      "name" = "dlfArmorType",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 },
      "default" = 0,
      "comment" = "the armor type code - 1 the banded; 2 the buckler; 3 the chain; 4 the do-maru; 5 the haidate; 6 the hara-ate; 7 the hara-ate-gawa; 8 the haramaki; 9 the haramaki-do; 10 the hide; 11 the kote; 12 the leather; 13 the o-yoroi; 14 the padded; 15 the ring; 16 the scale, leather; 17 the scale, metal; 18 the shield, large; 19 the shield, medium; 20 the sode, pair; 21 the splinted; 22 the studded; 23 the gajin armor of the DMG Armor and Shield Table (print capture p. 289)",
    } },
  "tables" = { {
      "name" = "dlfMagicalArmor",
      "tag" = "MagicalArmor",
      "count" = "dlfArmorRowCount",
      "comment" = "the Table 75 Magical Armor grid - the twenty-three d100 bands of the armor types, banded through the gajin armor, the splinted overlap pinned as printed (print capture p. 289)",
      "cols" = { "dlfArmorRollMin", "dlfArmorRollMax", "dlfArmorType" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 289)", "the d100 band maximum - the high roll of the row (print capture p. 289)", "the armor type code - 1 the banded; 2 the buckler; 3 the chain; 4 the do-maru; 5 the haidate; 6 the hara-ate; 7 the hara-ate-gawa; 8 the haramaki; 9 the haramaki-do; 10 the hide; 11 the kote; 12 the leather; 13 the o-yoroi; 14 the padded; 15 the ring; 16 the scale, leather; 17 the scale, metal; 18 the shield, large; 19 the shield, medium; 20 the sode, pair; 21 the splinted; 22 the studded; 23 the gajin armor of the DMG Armor and Shield Table (print capture p. 289)" },
      "data" = { { 1, 4, 1 }, { 5, 5, 2 }, { 6, 12, 3 }, { 13, 16, 4 }, { 17, 17, 5 }, { 18, 22, 6 }, { 23, 26, 7 }, { 27, 30, 8 }, { 31, 35, 9 }, { 36, 44, 10 }, { 45, 46, 11 }, { 47, 55, 12 }, { 56, 62, 13 }, { 63, 66, 14 }, { 67, 70, 15 }, { 71, 74, 16 }, { 75, 78, 17 }, { 79, 82, 18 }, { 83, 86, 19 }, { 87, 87, 20 }, { 86, 92, 21 }, { 93, 99, 22 }, { 100, 100, 23 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlfArmorRowCount']() != 23  or  m['dlfSodePairAsterisk']() != 1  or  m['dlfSplintedOverlapMisprint']() != 1  or  m['dlfGajinArmorRollOnDMG']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlfArmorRowCount']() != 23  or m['dlfArmorRollMin'](0) != 1  or m['dlfArmorRollMax'](22) != 100  or m['dlfArmorType'](0) != 1  or m['dlfArmorType'](22) != 23",
      "note" = "the grid - the twenty-three-band Table 75, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlfArmorRollMin'](20) != 86  or m['dlfArmorRollMax'](20) != 92  or m['dlfArmorType'](20) != 21  or m['dlfArmorType'](19) != 20  or m['dlfSodePairAsterisk']() != 1  or m['dlfSplintedOverlapMisprint']() != 1  or m['dlfGajinArmorRollOnDMG']() != 1",
      "note" = "the capture quirks - the splinted overlap and the gajin armor row, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R744 OA Table 75 armor audit",
      "comment" = "OA round one hundred thirty-one (capture p. 289): the Table 75 Magical Armor - the twenty-three d100 bands of the armor types, the splinted overlap misprint pinned as printed, the gajin armor reroll of the 100 row, single-pass pins per the Chapter 9 provenance shift",
    },
}
