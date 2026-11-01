-- oa737: promoted from rules/oa108tableiii.h (the OA TREASURE - TABLE III. (ORIENT), MAGICAL ITEMS, printed capture p. 287 -);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 737,
  "prefix" = "oa737",
  "banner" = {
      "title" = "OA TREASURE - TABLE III. (ORIENT), MAGICAL ITEMS, printed capture p. 287 -",
      "provenance" = "the item draw round census 659 -> 660.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 190 closed, 45 open - the Table III box flips (census 659 -> 660); NEXT - R738: the Modifications to Standard Magical Items prose (capture p. 286), prefix dkz (verify free at the landing), audit \"R738 OA standard item mods audit\", include after rules/oa108tableiii.h",
    },
  "consts" = { {
      "name" = "dkyRowCount",
      "value" = 12,
      "comment" = "the Table III row count - the twelve d100 bands of the Oriental magical items table (print capture p. 287)",
    }, {
      "name" = "dkyCatPotions",
      "value" = 1,
      "comment" = "the potions category - the 01-10 band of the DMG Table III.A. (print capture p. 287)",
    }, {
      "name" = "dkyCatScrolls",
      "value" = 2,
      "comment" = "the scrolls category - the 11-35 band of the DMG Table III.B. (print capture p. 287)",
    }, {
      "name" = "dkyCatRings",
      "value" = 3,
      "comment" = "the rings category - the 36-40 band of the DMG Table III.C. (print capture p. 287)",
    }, {
      "name" = "dkyCatRods",
      "value" = 4,
      "comment" = "the rods, staves, and wands category - the 41-45 band of the DMG Table III.D. (print capture p. 287)",
    }, {
      "name" = "dkyCatMiscMagic",
      "value" = 5,
      "comment" = "the miscellaneous magic category - the five IIIE bands of the DMG Table III.E.1 through III.E.5 (print capture p. 287)",
    }, {
      "name" = "dkyCatOriental",
      "value" = 6,
      "comment" = "the oriental magical items category - the 56-60 band of this book (print capture p. 287)",
    }, {
      "name" = "dkyCatArmorShields",
      "value" = 7,
      "comment" = "the armor and shields category - the 61-75 band, the capture misreading 8 for the and of the Armor & Shields (print capture p. 287)",
    }, {
      "name" = "dkyCatWeapons",
      "value" = 8,
      "comment" = "the magical weapons category - the 76-100 band (print capture p. 287)",
    }, {
      "name" = "dkyBandPotions",
      "value" = 1,
      "comment" = "the potions band - the 01-10 roll of the IIIA subtable (print capture p. 287)",
    }, {
      "name" = "dkyBandScrolls",
      "value" = 1,
      "comment" = "the scrolls band - the 11-35 roll of the IIIB subtable (print capture p. 287)",
    }, {
      "name" = "dkyBandRings",
      "value" = 1,
      "comment" = "the rings band - the 36-40 roll of the IIIC subtable (print capture p. 287)",
    }, {
      "name" = "dkyBandRods",
      "value" = 1,
      "comment" = "the rods, staves, and wands band - the 41-45 roll of the IIID subtable (print capture p. 287)",
    }, {
      "name" = "dkyBandMiscMagic",
      "value" = 1,
      "comment" = "the misc magic bands - the five 46-55 sub-bands of the IIIE.1 through IIIE.5 subtables (print capture p. 287)",
    }, {
      "name" = "dkyBandOriental",
      "value" = 1,
      "comment" = "the oriental items band - the 56-60 roll of the Table 86 items of this book (print capture p. 287)",
    }, {
      "name" = "dkyBandArmorShields",
      "value" = 1,
      "comment" = "the armor and shields band - the 61-75 roll, the capture misreading the 8 for the & (print capture p. 287)",
    }, {
      "name" = "dkyBandWeapons",
      "value" = 1,
      "comment" = "the magical weapons band - the 76-100 roll (print capture p. 287)",
    }, {
      "name" = "dkyDMGPageFirst",
      "value" = 121,
      "comment" = "the DMG first page - the 121 of the footnote, the parentheses referring to the DMG tables of the pages 121-124 (print capture p. 287)",
    }, {
      "name" = "dkyDMGPageLast",
      "value" = 124,
      "comment" = "the DMG last page - the 124 of the footnote (print capture p. 287)",
    }, {
      "name" = "dkyFootnoteDMGTables",
      "value" = 1,
      "comment" = "the footnote - the parentheses referring to the tables in the DMG, the pages 121-124 (print capture p. 287)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dkyRollMin",
      "values" = { 1, 11, 36, 41, 46, 48, 50, 52, 54, 56, 61, 76 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 287)",
    }, {
      "name" = "dkyRollMax",
      "values" = { 10, 35, 40, 45, 47, 49, 51, 53, 55, 60, 75, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 287)",
    }, {
      "name" = "dkyCat",
      "values" = { 1, 2, 3, 4, 5, 5, 5, 5, 5, 6, 7, 8 },
      "default" = 0,
      "comment" = "the category code - the potions 1, scrolls 2, rings 3, rods 4, misc magic 5, oriental 6, armor and shields 7, weapons 8 (print capture p. 287)",
    }, {
      "name" = "dkySub",
      "values" = { 1, 2, 3, 4, 1, 2, 3, 4, 5, 0, 0, 0 },
      "default" = 0,
      "comment" = "the subtable code - the IIIA 1, IIIB 2, IIIC 3, IIID 4, and the IIIE.1 through IIIE.5 of the five misc bands, the 0 the none of the untabled rows (print capture p. 287)",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkyRowCount']() != 12  or m['dkyDMGPageFirst']() != 121  or m['dkyDMGPageLast']() != 124  or m['dkyCatPotions']() != 1  or m['dkyCatScrolls']() != 2  or m['dkyCatRings']() != 3  or m['dkyCatRods']() != 4  or m['dkyCatMiscMagic']() != 5  or m['dkyCatOriental']() != 6  or m['dkyCatArmorShields']() != 7  or m['dkyCatWeapons']() != 8  or  m['dkyFootnoteDMGTables']() != 1  or  m['dkyBandPotions']() != 1  or  m['dkyBandScrolls']() != 1  or  m['dkyBandRings']() != 1  or  m['dkyBandRods']() != 1  or  m['dkyBandMiscMagic']() != 1  or  m['dkyBandOriental']() != 1  or  m['dkyBandArmorShields']() != 1  or  m['dkyBandWeapons']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkyBandPotions']() != 1  or m['dkyBandScrolls']() != 1  or m['dkyBandRings']() != 1  or m['dkyBandRods']() != 1  or m['dkyBandMiscMagic']() != 1  or m['dkyBandOriental']() != 1  or m['dkyBandArmorShields']() != 1  or m['dkyBandWeapons']() != 1  or m['dkyFootnoteDMGTables']() != 1",
      "note" = "the band bools - the eight category walkthrough, healthy values, each condition false",
    }, {
      "expr" = "m['dkyCatPotions']() != 1  or m['dkyCatScrolls']() != 2  or m['dkyCatRings']() != 3  or m['dkyCatRods']() != 4  or m['dkyCatMiscMagic']() != 5  or m['dkyCatOriental']() != 6  or m['dkyCatArmorShields']() != 7  or m['dkyCatWeapons']() != 8  or m['dkyDMGPageFirst']() != 121  or m['dkyDMGPageLast']() != 124",
      "note" = "the codes - the eight category codes and the DMG footnote pages, healthy values, each condition false",
    }, {
      "expr" = "m['dkyRowCount']() != 12",
      "note" = "the grid - the twelve-band Table III, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dkyRollMin'](0) != 1 or m['dkyRollMin'](1) != 11 or m['dkyRollMin'](2) != 36 or m['dkyRollMin'](3) != 41 or m['dkyRollMin'](4) != 46 or m['dkyRollMin'](5) != 48 or m['dkyRollMin'](6) != 50 or m['dkyRollMin'](7) != 52",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkyRollMin'](8) != 54 or m['dkyRollMin'](9) != 56 or m['dkyRollMin'](10) != 61 or m['dkyRollMin'](11) != 76 or m['dkyRollMin'](12) != 0 or m['dkyRollMax'](0) != 10 or m['dkyRollMax'](1) != 35 or m['dkyRollMax'](2) != 40",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkyRollMax'](3) != 45 or m['dkyRollMax'](4) != 47 or m['dkyRollMax'](5) != 49 or m['dkyRollMax'](6) != 51 or m['dkyRollMax'](7) != 53 or m['dkyRollMax'](8) != 55 or m['dkyRollMax'](9) != 60 or m['dkyRollMax'](10) != 75",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkyRollMax'](11) != 100 or m['dkyRollMax'](12) != 0 or m['dkyCat'](0) != 1 or m['dkyCat'](1) != 2 or m['dkyCat'](2) != 3 or m['dkyCat'](3) != 4 or m['dkyCat'](4) != 5 or m['dkyCat'](5) != 5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkyCat'](6) != 5 or m['dkyCat'](7) != 5 or m['dkyCat'](8) != 5 or m['dkyCat'](9) != 6 or m['dkyCat'](10) != 7 or m['dkyCat'](11) != 8 or m['dkyCat'](12) != 0 or m['dkySub'](0) != 1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkySub'](1) != 2 or m['dkySub'](2) != 3 or m['dkySub'](3) != 4 or m['dkySub'](4) != 1 or m['dkySub'](5) != 2 or m['dkySub'](6) != 3 or m['dkySub'](7) != 4 or m['dkySub'](8) != 5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkySub'](9) != 0 or m['dkySub'](10) != 0 or m['dkySub'](11) != 0 or m['dkySub'](12) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R737 OA Table III Orient audit",
      "comment" = "OA round one hundred twenty-four (capture p. 287): the Table III. (Orient) Magical Items - the twelve d100 bands, the category and subtable codes of the DMG III.A. through III.E.5 riding with the band edges, the oriental items band of this book, the armor and shields of the capture misreading 8 for the &, the footnote to the DMG pages 121-124, single-pass pins per the Chapter 9 provenance shift",
    },
}
