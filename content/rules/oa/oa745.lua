-- oa745: promoted from rules/oa116table76.h (the OA TREASURE - TABLE 76, MAGICAL ARMOR PROPERTIES, printed capture pp.);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 745,
  "prefix" = "oa745",
  "banner" = {
      "title" = "OA TREASURE - TABLE 76, MAGICAL ARMOR PROPERTIES, printed capture pp.",
      "provenance" = "289-290 - the property grid round census 667 -> 668.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 198 closed, 37 open - the Table 76 box flips (census 667 -> 668); NEXT - R746: Table 77: Special Properties (capture p. 290), prefix dlh (verify free at the landing), audit \"R746 OA Table 77 special audit\", include after rules/oa116table76.h",
    },
  "consts" = { {
      "name" = "dlgPropRowCount",
      "value" = 7,
      "comment" = "the property row count - the seven d100 bands of the Table 76 property grid (print capture p. 289)",
    }, {
      "name" = "dlgPiecePlus",
      "value" = 1,
      "comment" = "the armor piece plus - the +1 taken by an individual armor piece in place of the row plus (print capture p. 290)",
    }, {
      "name" = "dlgCaptionPeriod",
      "value" = 1,
      "comment" = "the caption quirk - the caption printing the Table 76. with a period (print capture p. 289)",
    }, {
      "name" = "dlgQualityAsterisk",
      "value" = 1,
      "comment" = "the quality asterisk - the armor of quality row carrying the asterisk of the footnote (print capture p. 289)",
    }, {
      "name" = "dlgSpecialRerollTable77",
      "value" = 1,
      "comment" = "the special reroll - the 91-100 band rolling again on the Table 77, its asterisk carried (print capture p. 290)",
    }, {
      "name" = "dlgFootnoteNoSpecialProperty",
      "value" = 1,
      "comment" = "the footnote - the armor of quality and the pieces of armor can never have a special property (print capture p. 290)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlgPropRollMin",
      "values" = { 1, 41, 66, 81, 86, 89, 91 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 289)",
    }, {
      "name" = "dlgPropRollMax",
      "values" = { 40, 65, 80, 85, 88, 90, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 290)",
    }, {
      "name" = "dlgPropPlus",
      "values" = { 0, 1, 2, 3, 4, 5, 6 },
      "default" = 0,
      "comment" = "the property code - 0 the armor of quality (the 0 the no plus); 1 the +1; 2 the +2 (the +1 if an armor piece); 3 the +3 (the +1 if an armor piece); 4 the +4 (the +1 if an armor piece); 5 the +5 (the +1 if an armor piece); 6 the special property, rolled again on the Table 77 (print capture p. 290)",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlgPropRowCount']() != 7  or m['dlgPiecePlus']() != 1  or  m['dlgCaptionPeriod']() != 1  or  m['dlgQualityAsterisk']() != 1  or  m['dlgSpecialRerollTable77']() != 1  or  m['dlgFootnoteNoSpecialProperty']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlgPropRowCount']() != 7  or m['dlgPropRollMin'](0) != 1  or m['dlgPropRollMax'](6) != 100  or m['dlgPropPlus'](0) != 0  or m['dlgPropPlus'](6) != 6",
      "note" = "the grid - the seven-band Table 76, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlgCaptionPeriod']() != 1  or m['dlgQualityAsterisk']() != 1  or m['dlgSpecialRerollTable77']() != 1  or m['dlgFootnoteNoSpecialProperty']() != 1  or m['dlgPiecePlus']() != 1",
      "note" = "the caption quirk, the footnote, and the piece plus, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R745 OA Table 76 properties audit",
      "comment" = "OA round one hundred thirty-two (capture pp. 289-290): the Table 76 Magical Armor Properties - the seven d100 bands of the quality and plus properties with the armor-piece +1 clause, the special property reroll on the Table 77, the no-special-property footnote, the caption printing a period, single-pass pins per the Chapter 9 provenance shift",
    },
}
