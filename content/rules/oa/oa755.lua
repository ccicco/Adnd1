-- oa755: promoted from rules/oa126table84.h (the OA TREASURE - TABLE 84, MARTIAL ARTS CLASS, printed capture p. 293 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 755,
  "prefix" = "oa755",
  "banner" = {
      "title" = "OA TREASURE - TABLE 84, MARTIAL ARTS CLASS, printed capture p. 293 - the",
      "provenance" = "martial arts grid round census 677 -> 678.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 208 closed, 27 open - the Table 84 box flips (census 677 -> 678); NEXT - R756: Table 85: Ninja Class (capture p. 293), prefix dlr (verify free at the landing), audit \"R756 OA Table 85 ninja audit\", include after rules/oa126table84.h",
    },
  "consts" = { {
      "name" = "dlqMartialArtsRowCount",
      "value" = 12,
      "comment" = "the martial arts row count - the twelve d100 bands of the Table 84 martial arts type grid (print capture p. 293)",
    }, {
      "name" = "dlqChainToFangHead",
      "value" = 1,
      "comment" = "the chain and fang head bands - the 01-10 opening stretch, the chain 01-05 and the fang 06-10 (print capture p. 293)",
    }, {
      "name" = "dlqNunchakuBand",
      "value" = 1,
      "comment" = "the nunchaku band - the 41-55, the widest mid-grid band (print capture p. 293)",
    }, {
      "name" = "dlqSaiBand",
      "value" = 1,
      "comment" = "the sai band - the 56-70 (print capture p. 293)",
    }, {
      "name" = "dlqThreePieceRodBand",
      "value" = 1,
      "comment" = "the three-piece-rod band - the 81-90, the hyphenated name of the print (print capture p. 293)",
    }, {
      "name" = "dlqTuiFaTail",
      "value" = 1,
      "comment" = "the tui-fa tail - the 91-100 closing band (print capture p. 293)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlqMartialArtsRollMin",
      "values" = { 1, 6, 11, 21, 31, 36, 41, 56, 71, 76, 81, 91 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 293)",
    }, {
      "name" = "dlqMartialArtsRollMax",
      "values" = { 5, 10, 20, 30, 35, 40, 55, 70, 75, 80, 90, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 293)",
    }, {
      "name" = "dlqMartialArtsCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
      "default" = 0,
      "comment" = "the martial arts type code - 1 the chain; 2 the fang; 3 the gunsen; 4 the jitte; 5 the kau sin ke; 6 the kiseru; 7 the nunchaku; 8 the sai; 9 the sang kauw; 10 the siangkam; 11 the three-piece-rod; 12 the tui-fa (print capture p. 293)",
    } },
  "tables" = { {
      "name" = "dlqMartialArtsClass",
      "tag" = "MartialArtsClass",
      "count" = "dlqMartialArtsRowCount",
      "comment" = "the Table 84 Martial Arts Class grid - the twelve d100 bands of the martial arts weapon types, the chain through the tui-fa (print capture p. 293)",
      "cols" = { "dlqMartialArtsRollMin", "dlqMartialArtsRollMax", "dlqMartialArtsCode" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 293)", "the d100 band maximum - the high roll of the row (print capture p. 293)", "the martial arts type code - 1 the chain; 2 the fang; 3 the gunsen; 4 the jitte; 5 the kau sin ke; 6 the kiseru; 7 the nunchaku; 8 the sai; 9 the sang kauw; 10 the siangkam; 11 the three-piece-rod; 12 the tui-fa (print capture p. 293)" },
      "data" = { { 1, 5, 1 }, { 6, 10, 2 }, { 11, 20, 3 }, { 21, 30, 4 }, { 31, 35, 5 }, { 36, 40, 6 }, { 41, 55, 7 }, { 56, 70, 8 }, { 71, 75, 9 }, { 76, 80, 10 }, { 81, 90, 11 }, { 91, 100, 12 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlqMartialArtsRowCount']() != 12  or  m['dlqChainToFangHead']() != 1  or  m['dlqNunchakuBand']() != 1  or  m['dlqSaiBand']() != 1  or  m['dlqThreePieceRodBand']() != 1  or  m['dlqTuiFaTail']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlqMartialArtsRowCount']() != 12  or m['dlqMartialArtsRollMin'](0) != 1  or m['dlqMartialArtsRollMax'](11) != 100  or m['dlqMartialArtsCode'](0) != 1  or m['dlqMartialArtsCode'](11) != 12",
      "note" = "the grid - the twelve-band Table 84, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlqChainToFangHead']() != 1  or m['dlqMartialArtsRollMax'](6) != 55  or m['dlqMartialArtsCode'](6) != 7  or m['dlqNunchakuBand']() != 1  or m['dlqSaiBand']() != 1  or m['dlqThreePieceRodBand']() != 1  or m['dlqTuiFaTail']() != 1",
      "note" = "the band walk - the key bands, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R755 OA Table 84 martial arts audit",
      "comment" = "OA round one hundred forty-two (capture p. 293): the Table 84 Martial Arts Class - the twelve d100 bands of the martial arts weapon types, the chain through the tui-fa, single-pass pins per the Chapter 9 provenance shift",
    },
}
