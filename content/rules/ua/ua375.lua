-- ua375: promoted from rules/ua/uadetskel.h (the The UA RANDOM TREASURE);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 375,
  "prefix" = "ua375",
  "banner" = {
      "title" = "The UA RANDOM TREASURE",
      "provenance" = "DETERMINATION - MAGIC ITEMS (Revised Table) skeleton pins (pp. 84-89), R375: the top-level category bands and the sub-table splits. The row bodies ride R395 - the clean PDF read fills every row (rules/ua/uadetrows.h); the extract markers below flip with it. The dial ride: the R374 seam (checked in the regtest audit, not here).",
    },
  "consts" = { {
      "name" = "uadsCategoryCount",
      "value" = 8,
      "comment" = "---- the top-level categories ---- The printed order, eight categories.",
    }, {
      "name" = "uadsPotionSplitLo",
      "value" = 65,
      "comment" = "---- the sub-table splits ---- Each category's second roll splits low/high; the low band is the new UA table, the high band the original DMG table (the potions low band carries the new potions - the elixirs and oils).",
    }, {
      "name" = "uadsScrollSplitLo",
      "value" = 85,
      "comment" = "",
    }, {
      "name" = "uadsRingSplitLo",
      "value" = 67,
      "comment" = "",
    }, {
      "name" = "uadsRodSplitLo",
      "value" = 40,
      "comment" = "",
    }, {
      "name" = "uadsArmorSplitLo",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uadsSwordSplitLo",
      "value" = 95,
      "comment" = "",
    }, {
      "name" = "uadsWeaponSplitLo",
      "value" = 50,
      "comment" = "",
    }, {
      "name" = "uadsMiscSubCount",
      "value" = 7,
      "comment" = "---- the miscellaneous magic sub-tables ---- SEVEN sub-bands, all named - III.E.1 through III.E.7; the R395 clean read names the seventh the extract lost.",
    }, {
      "name" = "uadsMiscSubNamedCount",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uadsScrollClericalPct",
      "value" = 30,
      "comment" = "---- the scroll footnotes ---- 30% of all spell scrolls are clerical (the dice 71-00 band); 25% of clerical scrolls are druidical; 10% of MU spell scrolls are illusionist - the applies-only-to-01-60 clause.",
    }, {
      "name" = "uadsScrollClericalDruidPct",
      "value" = 25,
      "comment" = "",
    }, {
      "name" = "uadsScrollMuIllusionistPct",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uadsScrollCurseDmgPage",
      "value" = 121,
      "comment" = "The cursed-scroll footnote points at the DMG, p. 121.",
    } },
  "bools" = { {
      "name" = "uadsIsTheRevisedTable",
      "value" = true,
      "comment" = "The printed heading: MAGIC ITEMS (Revised Table).",
    }, {
      "name" = "uadsPotionLowBandIsNewPotions",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadsScrollSecondTableIsIIB2",
      "value" = true,
      "comment" = "The named second tables the print carries: the scroll II.B.2, the rod II.D.2, the sword II.G and II.G.2.",
    }, {
      "name" = "uadsRodSecondTableIsIID2",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadsSwordFirstTableIsIIG",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadsSwordSecondTableIsIIG2",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadsMiscSubSeventhNameGarbles",
      "value" = false,
      "comment" = "",
    }, {
      "name" = "uadsScrollFootnoteBandIs71To00",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uadsRowBodiesGarble",
      "value" = false,
      "comment" = "---- the extract read ---- The R395 clean read delivers every row body - the marker flips false (the rows pin in rules/ua/uadetrows.h).",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uadsCategoryName",
      "comment" = "",
      "kind" = "string array",
      "count" = 8,
      "values" = { "Potions", "Scrolls", "Rings", "Rods, Staves & Wands", "Miscellaneous Magic", "Armor & Shields", "Swords", "Miscellaneous Weapons" },
    }, {
      "name" = "uadsCategoryLo",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[8] = { 1, 21, 36, 41, 46, 61, 76, 87 }; if (i < 0) i = 0; if (i > 7) i = 7; return k[i];",
    }, {
      "name" = "uadsCategoryHi",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[8] = { 20, 35, 40, 45, 60, 75, 86, 100 }; if (i < 0) i = 0; if (i > 7) i = 7; return k[i];",
    }, {
      "name" = "uadsMiscSubLo",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[7] = { 1, 15, 29, 43, 57, 71, 86 }; if (i < 0) i = 0; if (i > 6) i = 6; return k[i];",
    }, {
      "name" = "uadsMiscSubHi",
      "comment" = "",
      "kind" = "header pin",
      "body" = "static const int k[7] = { 14, 28, 42, 56, 70, 85, 100 }; if (i < 0) i = 0; if (i > 6) i = 6; return k[i];",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uadsCategoryCount']() != 8  or m['uadsCategoryLo'](0) != 1  or m['uadsCategoryHi'](7) != 100  or strcmp(m['uadsCategoryName'](0), \"Potions\") != 0  or strcmp(m['uadsCategoryName'](3), \"Rods, Staves & Wands\") != 0  or strcmp(m['uadsCategoryName'](7), \"Miscellaneous Weapons\") != 0  or m['uadsCategoryLo'](i) != kLo[i]  or m['uadsCategoryHi'](i) != kHi[i]  or i < 7 && kHi[i] + 1 != kLo[i + 1]  or  m['uadsIsTheRevisedTable']() != 1",
      "note" = "---- the top-level bands ----",
    }, {
      "expr" = "m['uadsPotionSplitLo']() != 65  or  m['uadsPotionLowBandIsNewPotions']() != 1  or m['uadsScrollSplitLo']() != 85  or m['uadsRingSplitLo']() != 67  or m['uadsRodSplitLo']() != 40  or m['uadsArmorSplitLo']() != 50  or m['uadsSwordSplitLo']() != 95  or m['uadsWeaponSplitLo']() != 50  or  m['uadsScrollSecondTableIsIIB2']() != 1  or  m['uadsRodSecondTableIsIID2']() != 1  or  m['uadsSwordFirstTableIsIIG']() != 1  or  m['uadsSwordSecondTableIsIIG2']() != 1",
      "note" = "---- the splits ----",
    }, {
      "expr" = "m['uadsMiscSubCount']() != 7  or m['uadsMiscSubNamedCount']() != 7  or m['uadsMiscSubSeventhNameGarbles']()  or m['uadsMiscSubLo'](i) != mLo[i]  or m['uadsMiscSubHi'](i) != mHi[i]  or i < 6 && mHi[i] + 1 != mLo[i + 1]",
      "note" = "---- the misc sub-bands ----",
    }, {
      "expr" = "m['uadsScrollClericalPct']() != 30  or m['uadsScrollClericalDruidPct']() != 25  or m['uadsScrollMuIllusionistPct']() != 10  or  m['uadsScrollFootnoteBandIs71To00']() != 1  or m['uadsScrollCurseDmgPage']() != 121",
      "note" = "---- the scroll footnotes ----",
    }, {
      "expr" = "m['uadsRowBodiesGarble']()",
      "note" = "---- the extract read ----",
    }, {
      "expr" = "m['uatdModeDmg']() != 0  or m['uatdModeUa']() != 1  or m['uatdModeMerged']() != 2  or m['uatdDefaultMode']() !=m['uatdModeDmg']()  or  m['uatdRunBothDecided']() != 1  or m['uatdUaPinRoundsPending']()",
      "note" = "---- the R374 dial seam ----",
    } },
  "audit" = {
      "label" = "R375: the UA determination skeleton pin audit",
      "comment" = "The MAGIC ITEMS (Revised Table) skeleton (pp. 84-89): the top-level category bands, the sub-table splits, the seven misc-magic sub-bands, the scroll footnotes. The row bodies of the eight tables OCR-scramble - flagged; the item stays open, PDF-gated. The R374 dial seam cross-checks the modes; the census 301 -> 302.",
    },
}
