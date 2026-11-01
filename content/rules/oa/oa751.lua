-- oa751: promoted from rules/oa122table80.h (the OA TREASURE - TABLE 80, SWORD CLASS, printed capture p. 292 - the sword);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 751,
  "prefix" = "oa751",
  "banner" = {
      "title" = "OA TREASURE - TABLE 80, SWORD CLASS, printed capture p. 292 - the sword",
      "provenance" = "type grid round census 673 -> 674.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 204 closed, 31 open - the Table 80 box flips (census 673 -> 674); NEXT - R752: Table 81: Bow, Crossbow, And Sling Class (capture p. 292), prefix dln (verify free at the landing), audit \"R752 OA Table 81 bow class audit\", include after rules/oa122table80.h",
    },
  "consts" = { {
      "name" = "dlmSwordRowCount",
      "value" = 7,
      "comment" = "the sword row count - the seven d100 bands of the Table 80 sword type grid (print capture p. 292)",
    }, {
      "name" = "dlmKatanaBand",
      "value" = 1,
      "comment" = "the katana band - the 01-30, the heaviest weight of the grid (print capture p. 292)",
    }, {
      "name" = "dlmParangBand",
      "value" = 1,
      "comment" = "the parang band - the 31-35 (print capture p. 292)",
    }, {
      "name" = "dlmBroadSwordBand",
      "value" = 1,
      "comment" = "the broad sword band - the 36-50 (print capture p. 292)",
    }, {
      "name" = "dlmLongSwordBand",
      "value" = 1,
      "comment" = "the long sword band - the 51-65 (print capture p. 292)",
    }, {
      "name" = "dlmShortSwordBand",
      "value" = 1,
      "comment" = "the short sword band - the 66-80 (print capture p. 292)",
    }, {
      "name" = "dlmTwoHandedSwordBand",
      "value" = 1,
      "comment" = "the two-handed sword band - the 81-85 (print capture p. 292)",
    }, {
      "name" = "dlmWakizashiBand",
      "value" = 1,
      "comment" = "the wakizashi band - the 86-100, the companion blade of the katana (print capture p. 292)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlmSwordRollMin",
      "values" = { 1, 31, 36, 51, 66, 81, 86 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 292)",
    }, {
      "name" = "dlmSwordRollMax",
      "values" = { 30, 35, 50, 65, 80, 85, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 292)",
    }, {
      "name" = "dlmSwordCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7 },
      "default" = 0,
      "comment" = "the sword type code - 1 the katana; 2 the parang; 3 the broad sword; 4 the long sword; 5 the short sword; 6 the two-handed sword; 7 the wakizashi (print capture p. 292)",
    } },
  "tables" = { {
      "name" = "dlmSwordClass",
      "tag" = "SwordClass",
      "count" = "dlmSwordRowCount",
      "comment" = "the Table 80 Sword Class grid - the seven d100 bands of the sword types, the katana through the wakizashi (print capture p. 292)",
      "cols" = { "dlmSwordRollMin", "dlmSwordRollMax", "dlmSwordCode" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 292)", "the d100 band maximum - the high roll of the row (print capture p. 292)", "the sword type code - 1 the katana; 2 the parang; 3 the broad sword; 4 the long sword; 5 the short sword; 6 the two-handed sword; 7 the wakizashi (print capture p. 292)" },
      "data" = { { 1, 30, 1 }, { 31, 35, 2 }, { 36, 50, 3 }, { 51, 65, 4 }, { 66, 80, 5 }, { 81, 85, 6 }, { 86, 100, 7 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlmSwordRowCount']() != 7  or  m['dlmKatanaBand']() != 1  or  m['dlmParangBand']() != 1  or  m['dlmBroadSwordBand']() != 1  or  m['dlmLongSwordBand']() != 1  or  m['dlmShortSwordBand']() != 1  or  m['dlmTwoHandedSwordBand']() != 1  or  m['dlmWakizashiBand']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlmSwordRowCount']() != 7  or m['dlmSwordRollMin'](0) != 1  or m['dlmSwordRollMax'](6) != 100  or m['dlmSwordCode'](0) != 1  or m['dlmSwordCode'](6) != 7",
      "note" = "the grid - the seven-band Table 80, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlmKatanaBand']() != 1  or m['dlmParangBand']() != 1  or m['dlmBroadSwordBand']() != 1  or m['dlmLongSwordBand']() != 1  or m['dlmShortSwordBand']() != 1  or m['dlmTwoHandedSwordBand']() != 1  or m['dlmWakizashiBand']() != 1",
      "note" = "the band walk - the seven sword types, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R751 OA Table 80 sword audit",
      "comment" = "OA round one hundred thirty-eight (capture p. 292): the Table 80 Sword Class - the seven d100 bands of the sword types, the katana through the wakizashi, single-pass pins per the Chapter 9 provenance shift",
    },
}
