-- oa756: promoted from rules/oa127table85.h (the OA TREASURE - TABLE 85, NINJA CLASS, printed capture pp. 293-294 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 756,
  "prefix" = "oa756",
  "banner" = {
      "title" = "OA TREASURE - TABLE 85, NINJA CLASS, printed capture pp. 293-294 - the",
      "provenance" = "ninja grid round census 678 -> 679.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 209 closed, 26 open - the Table 85 box flips (census 678 -> 679); NEXT - R757: Explanation of Weapon Properties (capture p. 294), prefix dls (verify free at the landing), audit \"R757 OA weapon explanation audit\", include after rules/oa127table85.h",
    },
  "consts" = { {
      "name" = "dlrNinjaRowCount",
      "value" = 12,
      "comment" = "the ninja row count - the twelve d100 bands of the Table 85 ninja type grid (print capture p. 293)",
    }, {
      "name" = "dlrPageBreakGrid",
      "value" = 1,
      "comment" = "the page break - the caption and the 01-05 kawanaga row on the one page, the remaining rows on the next (print capture p. 294)",
    }, {
      "name" = "dlrShurikenBands",
      "value" = 1,
      "comment" = "the shuriken bands - the three shuriken rows of the 61-100 tail, the spike and the large and small star (print capture p. 294)",
    }, {
      "name" = "dlrNinjaToBand",
      "value" = 1,
      "comment" = "the ninja-to band - the 31-40, the ninja sword (print capture p. 294)",
    }, {
      "name" = "dlrConcealedWeapons",
      "value" = 1,
      "comment" = "the concealed weapons - the shikomi-zue of the 46-60, the sword-in-cane, and the needle of the 21-25, the blowgun darts (print capture p. 294)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlrNinjaRollMin",
      "values" = { 1, 6, 11, 16, 21, 26, 31, 41, 46, 61, 71, 86 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 293)",
    }, {
      "name" = "dlrNinjaRollMax",
      "values" = { 5, 10, 15, 20, 25, 30, 40, 45, 60, 70, 85, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 294)",
    }, {
      "name" = "dlrNinjaCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
      "default" = 0,
      "comment" = "the ninja type code - 1 the kawanaga; 2 the kumade; 3 the kusari-gama; 4 the kyoketsu-shogi; 5 the needle, 10-60; 6 the nekode; 7 the ninja-to; 8 the shaken, 2-12; 9 the shikomi-zue; 10 the spike shuriken, 2-12; 11 the large star shuriken, 3-18; 12 the small star shuriken, 3-18 (print capture p. 294)",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlrNinjaRowCount']() != 12  or  m['dlrPageBreakGrid']() != 1  or  m['dlrShurikenBands']() != 1  or  m['dlrNinjaToBand']() != 1  or  m['dlrConcealedWeapons']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlrNinjaRowCount']() != 12  or m['dlrNinjaRollMin'](0) != 1  or m['dlrNinjaRollMax'](11) != 100  or m['dlrNinjaCode'](0) != 1  or m['dlrNinjaCode'](11) != 12",
      "note" = "the grid - the twelve-band Table 85, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlrNinjaRollMin'](9) != 61  or m['dlrNinjaCode'](9) != 10  or m['dlrNinjaCode'](10) != 11  or m['dlrNinjaCode'](11) != 12  or m['dlrShurikenBands']() != 1  or m['dlrPageBreakGrid']() != 1  or m['dlrNinjaToBand']() != 1  or m['dlrConcealedWeapons']() != 1",
      "note" = "the shuriken tail and the quirks, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R756 OA Table 85 ninja audit",
      "comment" = "OA round one hundred forty-three (capture pp. 293-294): the Table 85 Ninja Class - the twelve d100 bands of the ninja weapon types, the kawanaga through the small star shuriken, the three shuriken tail, single-pass pins per the Chapter 9 provenance shift",
    },
}
