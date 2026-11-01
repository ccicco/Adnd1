-- oa753: promoted from rules/oa124table82.h (the OA TREASURE - TABLE 82, MISCELLANEOUS, printed capture pp. 292-293 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 753,
  "prefix" = "oa753",
  "banner" = {
      "title" = "OA TREASURE - TABLE 82, MISCELLANEOUS, printed capture pp. 292-293 - the",
      "provenance" = "misc melee grid round census 675 -> 676.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 206 closed, 29 open - the Table 82 box flips (census 675 -> 676); NEXT - R754: Table 83: Missile Class (capture p. 293), prefix dlp (verify free at the landing), audit \"R754 OA Table 83 missile audit\", include after rules/oa124table82.h",
    },
  "consts" = { {
      "name" = "dloMiscRowCount",
      "value" = 13,
      "comment" = "the misc row count - the thirteen d100 bands of the Table 82 misc melee grid (print capture p. 292)",
    }, {
      "name" = "dloMeleeClassBanner",
      "value" = 1,
      "comment" = "the melee class banner - the grid captioned the MELEE CLASS above the d100 roll header (print capture p. 292)",
    }, {
      "name" = "dloNagasakiMisprint",
      "value" = 1,
      "comment" = "the nagamaki misprint - the capture printing the Nagasaki for the 61-65 band, almost certainly the nagamaki intended, pinned as printed (print capture p. 293)",
    }, {
      "name" = "dloSingleRollBands",
      "value" = 1,
      "comment" = "the single-roll bands - the 55 lajatang and the 61-65 of the misprint row, the narrow one-number or five-number bands of the grid (print capture p. 293)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dloMiscRollMin",
      "values" = { 1, 6, 16, 31, 46, 49, 55, 56, 61, 66, 76, 91, 96 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 292)",
    }, {
      "name" = "dloMiscRollMax",
      "values" = { 5, 15, 30, 45, 48, 54, 55, 60, 65, 75, 90, 95, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 293)",
    }, {
      "name" = "dloMiscCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
      "default" = 0,
      "comment" = "the misc melee type code - 1 the battle axe; 2 the bo stick; 3 the dagger; 4 the halberd; 5 the jo stick; 6 the kama; 7 the lajatang; 8 the lance; 9 the nagamaki - the capture printing the Nagasaki, the misprint pinned as printed; 10 the naginata; 11 the spear; 12 the tetsubo; 13 the trident (print capture p. 293)",
    } },
  "tables" = { {
      "name" = "dloMiscMelee",
      "tag" = "MiscMelee",
      "count" = "dloMiscRowCount",
      "comment" = "the Table 82 Miscellaneous melee grid - the thirteen d100 bands, the battle axe through the trident, the grid spanning the page break (print capture p. 292)",
      "cols" = { "dloMiscRollMin", "dloMiscRollMax", "dloMiscCode" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 292)", "the d100 band maximum - the high roll of the row (print capture p. 293)", "the misc melee type code - 1 the battle axe; 2 the bo stick; 3 the dagger; 4 the halberd; 5 the jo stick; 6 the kama; 7 the lajatang; 8 the lance; 9 the nagamaki - the capture printing the Nagasaki, the misprint pinned as printed; 10 the naginata; 11 the spear; 12 the tetsubo; 13 the trident (print capture p. 293)" },
      "data" = { { 1, 5, 1 }, { 6, 15, 2 }, { 16, 30, 3 }, { 31, 45, 4 }, { 46, 48, 5 }, { 49, 54, 6 }, { 55, 55, 7 }, { 56, 60, 8 }, { 61, 65, 9 }, { 66, 75, 10 }, { 76, 90, 11 }, { 91, 95, 12 }, { 96, 100, 13 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dloMiscRowCount']() != 13  or  m['dloMeleeClassBanner']() != 1  or  m['dloNagasakiMisprint']() != 1  or  m['dloSingleRollBands']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dloMiscRowCount']() != 13  or m['dloMiscRollMin'](0) != 1  or m['dloMiscRollMax'](12) != 100  or m['dloMiscCode'](0) != 1  or m['dloMiscCode'](12) != 13",
      "note" = "the grid - the thirteen-band Table 82, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dloMiscRollMin'](8) != 61  or m['dloMiscRollMax'](8) != 65  or m['dloMiscCode'](8) != 9  or m['dloNagasakiMisprint']() != 1  or m['dloMeleeClassBanner']() != 1  or m['dloSingleRollBands']() != 1",
      "note" = "the quirks - the misprint band and the banner, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R753 OA Table 82 misc melee audit",
      "comment" = "OA round one hundred forty (capture pp. 292-293): the Table 82 Miscellaneous - the thirteen d100 bands of the misc melee types, the battle axe through the trident, the nagamaki band carrying the capture Nagasaki misprint pinned as printed, single-pass pins per the Chapter 9 provenance shift",
    },
}
