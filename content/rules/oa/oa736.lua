-- oa736: promoted from rules/oa/oa107tableiia.h (the OA TREASURE - TABLE II.A. (ORIENT), MONETARY TREASURE, printed capture pp.);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 736,
  "prefix" = "oa736",
  "banner" = {
      "title" = "OA TREASURE - TABLE II.A. (ORIENT), MONETARY TREASURE, printed capture pp.",
      "provenance" = "286-287 - the rolled hoard round census 658 -> 659.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 189 closed, 46 open - the Table II.A. box flips (census 658 -> 659); NEXT - R737: Table III. (Orient): Magical Items (capture p. 287), prefix dky (verify free at the landing), audit \"R737 OA Table III Orient magical items audit\", include after rules/oa/oa107tableiia.h",
    },
  "consts" = { {
      "name" = "dkxRowCount",
      "value" = 9,
      "comment" = "the Table II.A. row count - the nine d20 bands of the Oriental monetary treasure table (print capture p. 286)",
    }, {
      "name" = "dkxRerollLimit",
      "value" = 17,
      "comment" = "the reroll limit - the rolls above 17 rerolled by the twice and three-times rows, the capture misreading 97 for the 17 of the 18 row (print capture p. 286)",
    }, {
      "name" = "dkxOneOfEachRow",
      "value" = 20,
      "comment" = "the one-of-each row - the 20 roll yielding one of each treasure above (print capture p. 286)",
    }, {
      "name" = "dkxRollTwice",
      "value" = 1,
      "comment" = "the 18 row - roll twice, rerolling the rolls above the limit (print capture p. 287)",
    }, {
      "name" = "dkxRollThreeTimes",
      "value" = 1,
      "comment" = "the 19 row - roll three times, rerolling the rolls above the limit (print capture p. 287)",
    }, {
      "name" = "dkxOneOfEachTreasure",
      "value" = 1,
      "comment" = "the 20 row - one of each treasure above (print capture p. 287)",
    }, {
      "name" = "dkxRowOneFenYuan",
      "value" = 1,
      "comment" = "the 1-2 row - the 10,000-40,000 fen riding with the 10,000-60,000 yuan (print capture p. 286)",
    }, {
      "name" = "dkxRowTael",
      "value" = 1,
      "comment" = "the 3-5 row - the 10,000-60,000 tael (print capture p. 286)",
    }, {
      "name" = "dkxRowChienOneDieSix",
      "value" = 1,
      "comment" = "the 6-10 row - the 500-1,000 ch'ien of the 1d6 + 4 (print capture p. 287)",
    }, {
      "name" = "dkxRowChienFiveDieFour",
      "value" = 1,
      "comment" = "the 11-12 row - the 500-2,000 ch'ien of the 5d4, the capture misreading 500-200 for the 500-2,000 (print capture p. 287)",
    }, {
      "name" = "dkxRowGems",
      "value" = 1,
      "comment" = "the 13-15 row - the 10-100 gems (print capture p. 287)",
    }, {
      "name" = "dkxRowJewelryOrArt",
      "value" = 1,
      "comment" = "the 16-17 row - the 5-50 pieces of jewelry or art objects (print capture p. 287)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dkxRollMin",
      "values" = { 1, 3, 6, 11, 13, 16, 18, 19, 20 },
      "default" = 0,
      "comment" = "the d20 band minimum - the low roll of the row (print capture p. 286)",
    }, {
      "name" = "dkxRollMax",
      "values" = { 2, 5, 10, 12, 15, 17, 18, 19, 20 },
      "default" = 0,
      "comment" = "the d20 band maximum - the high roll of the row (print capture p. 286)",
    }, {
      "name" = "dkxFenMin",
      "values" = { 10000, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the fen minimum - the low of the 10,000-40,000, the 0 the nil (print capture p. 286)",
    }, {
      "name" = "dkxFenMax",
      "values" = { 40000, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the fen maximum - the high of the 10,000-40,000, the 0 the nil (print capture p. 286)",
    }, {
      "name" = "dkxYuanMin",
      "values" = { 10000, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the yuan minimum - the low of the 10,000-60,000, the 0 the nil (print capture p. 286)",
    }, {
      "name" = "dkxYuanMax",
      "values" = { 60000, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the yuan maximum - the high of the 10,000-60,000, the 0 the nil (print capture p. 286)",
    }, {
      "name" = "dkxTaelMin",
      "values" = { 0, 10000, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the tael minimum - the low of the 10,000-60,000, the 0 the nil (print capture p. 286)",
    }, {
      "name" = "dkxTaelMax",
      "values" = { 0, 60000, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the tael maximum - the high of the 10,000-60,000, the 0 the nil (print capture p. 286)",
    }, {
      "name" = "dkxChienMin",
      "values" = { 0, 0, 500, 500, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the ch'ien minimum - the low of the 500-1,000 and 500-2,000, the 0 the nil (print capture p. 287)",
    }, {
      "name" = "dkxChienMax",
      "values" = { 0, 0, 1000, 2000, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the ch'ien maximum - the high of the 500-1,000 and the 500-2,000 of the capture misreading 500-200, the 0 the nil (print capture p. 287)",
    }, {
      "name" = "dkxGemsMin",
      "values" = { 0, 0, 0, 0, 10, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the gems minimum - the low of the 10-100, the 0 the nil (print capture p. 287)",
    }, {
      "name" = "dkxGemsMax",
      "values" = { 0, 0, 0, 0, 100, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the gems maximum - the high of the 10-100, the 0 the nil (print capture p. 287)",
    }, {
      "name" = "dkxArtMin",
      "values" = { 0, 0, 0, 0, 0, 5, 0, 0, 0 },
      "default" = 0,
      "comment" = "the art minimum - the low of the 5-50 jewelry or art pieces, the 0 the nil (print capture p. 287)",
    }, {
      "name" = "dkxArtMax",
      "values" = { 0, 0, 0, 0, 0, 50, 0, 0, 0 },
      "default" = 0,
      "comment" = "the art maximum - the high of the 5-50, the 0 the nil (print capture p. 287)",
    }, {
      "name" = "dkxRollsCount",
      "values" = { 1, 1, 1, 1, 1, 1, 2, 3, 1 },
      "default" = 0,
      "comment" = "the rolls count - the 2 of the roll twice, the 3 of the roll three times, the 1 elsewhere (print capture p. 287)",
    }, {
      "name" = "dkxRerollAbove",
      "values" = { 0, 0, 0, 0, 0, 0, 17, 17, 0 },
      "default" = 0,
      "comment" = "the reroll limit column - the 17 rerolled-above of the twice and three-times rows, the 0 elsewhere (print capture p. 287)",
    }, {
      "name" = "dkxOneOfEach",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      "default" = 0,
      "comment" = "the one-of-each flag - the 1 of the 20 row, the 0 elsewhere (print capture p. 287)",
    } },
  "tables" = { {
      "name" = "dkxIIA",
      "tag" = "IIA",
      "count" = "dkxRowCount",
      "comment" = "the Table II.A. (Orient) grid - the nine d20 bands row by row, the treasure ranges as the min and max pairs with the nil the 0 sentinel, the roll mechanics riding in the last three columns (print capture p. 286; print capture p. 287)",
      "cols" = { "dkxRollMin", "dkxRollMax", "dkxFenMin", "dkxFenMax", "dkxYuanMin", "dkxYuanMax", "dkxTaelMin", "dkxTaelMax", "dkxChienMin", "dkxChienMax", "dkxGemsMin", "dkxGemsMax", "dkxArtMin", "dkxArtMax", "dkxRollsCount", "dkxRerollAbove", "dkxOneOfEach" },
      "col_comments" = { "the d20 band minimum - the low roll of the row (print capture p. 286)", "the d20 band maximum - the high roll of the row (print capture p. 286)", "the fen minimum - the low of the 10,000-40,000, the 0 the nil (print capture p. 286)", "the fen maximum - the high of the 10,000-40,000, the 0 the nil (print capture p. 286)", "the yuan minimum - the low of the 10,000-60,000, the 0 the nil (print capture p. 286)", "the yuan maximum - the high of the 10,000-60,000, the 0 the nil (print capture p. 286)", "the tael minimum - the low of the 10,000-60,000, the 0 the nil (print capture p. 286)", "the tael maximum - the high of the 10,000-60,000, the 0 the nil (print capture p. 286)", "the ch'ien minimum - the low of the 500-1,000 and 500-2,000, the 0 the nil (print capture p. 287)", "the ch'ien maximum - the high of the 500-1,000 and the 500-2,000 of the capture misreading 500-200, the 0 the nil (print capture p. 287)", "the gems minimum - the low of the 10-100, the 0 the nil (print capture p. 287)", "the gems maximum - the high of the 10-100, the 0 the nil (print capture p. 287)", "the art minimum - the low of the 5-50 jewelry or art pieces, the 0 the nil (print capture p. 287)", "the art maximum - the high of the 5-50, the 0 the nil (print capture p. 287)", "the rolls count - the 2 of the roll twice, the 3 of the roll three times, the 1 elsewhere (print capture p. 287)", "the reroll limit column - the 17 rerolled-above of the twice and three-times rows, the 0 elsewhere (print capture p. 287)", "the one-of-each flag - the 1 of the 20 row, the 0 elsewhere (print capture p. 287)" },
      "data" = { { 1, 2, 10000, 40000, 10000, 60000, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, { 3, 5, 0, 0, 0, 0, 10000, 60000, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, { 6, 10, 0, 0, 0, 0, 0, 0, 500, 1000, 0, 0, 0, 0, 1, 0, 0 }, { 11, 12, 0, 0, 0, 0, 0, 0, 500, 2000, 0, 0, 0, 0, 1, 0, 0 }, { 13, 15, 0, 0, 0, 0, 0, 0, 0, 0, 10, 100, 0, 0, 1, 0, 0 }, { 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 50, 1, 0, 0 }, { 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 17, 0 }, { 19, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 17, 0 }, { 20, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 8, 8, 8, 8, 8, 8, 7, 7, 8, 8, 8, 8, 0, 7, 8 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkxRowCount']() != 9  or m['dkxRerollLimit']() != 17  or m['dkxOneOfEachRow']() != 20  or  m['dkxRowOneFenYuan']() != 1  or  m['dkxRowTael']() != 1  or  m['dkxRowChienOneDieSix']() != 1  or  m['dkxRowChienFiveDieFour']() != 1  or  m['dkxRowGems']() != 1  or  m['dkxRowJewelryOrArt']() != 1  or  m['dkxRollTwice']() != 1  or  m['dkxRollThreeTimes']() != 1  or  m['dkxOneOfEachTreasure']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkxRowOneFenYuan']() != 1  or m['dkxRowTael']() != 1  or m['dkxRowChienOneDieSix']() != 1  or m['dkxRowChienFiveDieFour']() != 1  or m['dkxRowGems']() != 1  or m['dkxRowJewelryOrArt']() != 1  or m['dkxRollTwice']() != 1  or m['dkxRollThreeTimes']() != 1  or m['dkxOneOfEachTreasure']() != 1",
      "note" = "the row bools - the nine-band walkthrough, healthy values, each condition false",
    }, {
      "expr" = "m['dkxRerollLimit']() != 17  or m['dkxOneOfEachRow']() != 20  or m['dkxRerollAbove'](6) != 17  or m['dkxRerollAbove'](7) != 17  or m['dkxRollsCount'](6) != 2  or m['dkxRollsCount'](7) != 3  or m['dkxOneOfEach'](8) != 1",
      "note" = "the mechanics - the reroll limit and the one-of-each row, healthy values, each condition false",
    }, {
      "expr" = "m['dkxRollMin'](0) != 1  or m['dkxRollMax'](0) != 2  or m['dkxRollMax'](8) != 20  or m['dkxRowCount']() != 9",
      "note" = "the bands - the d20 spans abut and cover 1 through 20, healthy values, each condition false",
    }, {
      "expr" = "m['dkxFenMin'](0) != 10000 or m['dkxFenMin'](1) != 0 or m['dkxFenMin'](2) != 0 or m['dkxFenMin'](3) != 0 or m['dkxFenMin'](4) != 0 or m['dkxFenMin'](5) != 0 or m['dkxFenMin'](6) != 0 or m['dkxFenMin'](7) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxFenMin'](8) != 0 or m['dkxFenMin'](9) != 0 or m['dkxFenMax'](0) != 40000 or m['dkxFenMax'](1) != 0 or m['dkxFenMax'](2) != 0 or m['dkxFenMax'](3) != 0 or m['dkxFenMax'](4) != 0 or m['dkxFenMax'](5) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxFenMax'](6) != 0 or m['dkxFenMax'](7) != 0 or m['dkxFenMax'](8) != 0 or m['dkxFenMax'](9) != 0 or m['dkxYuanMin'](0) != 10000 or m['dkxYuanMin'](1) != 0 or m['dkxYuanMin'](2) != 0 or m['dkxYuanMin'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxYuanMin'](4) != 0 or m['dkxYuanMin'](5) != 0 or m['dkxYuanMin'](6) != 0 or m['dkxYuanMin'](7) != 0 or m['dkxYuanMin'](8) != 0 or m['dkxYuanMin'](9) != 0 or m['dkxYuanMax'](0) != 60000 or m['dkxYuanMax'](1) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxYuanMax'](2) != 0 or m['dkxYuanMax'](3) != 0 or m['dkxYuanMax'](4) != 0 or m['dkxYuanMax'](5) != 0 or m['dkxYuanMax'](6) != 0 or m['dkxYuanMax'](7) != 0 or m['dkxYuanMax'](8) != 0 or m['dkxYuanMax'](9) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxTaelMin'](0) != 0 or m['dkxTaelMin'](1) != 10000 or m['dkxTaelMin'](2) != 0 or m['dkxTaelMin'](3) != 0 or m['dkxTaelMin'](4) != 0 or m['dkxTaelMin'](5) != 0 or m['dkxTaelMin'](6) != 0 or m['dkxTaelMin'](7) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxTaelMin'](8) != 0 or m['dkxTaelMin'](9) != 0 or m['dkxTaelMax'](0) != 0 or m['dkxTaelMax'](1) != 60000 or m['dkxTaelMax'](2) != 0 or m['dkxTaelMax'](3) != 0 or m['dkxTaelMax'](4) != 0 or m['dkxTaelMax'](5) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxTaelMax'](6) != 0 or m['dkxTaelMax'](7) != 0 or m['dkxTaelMax'](8) != 0 or m['dkxTaelMax'](9) != 0 or m['dkxChienMin'](0) != 0 or m['dkxChienMin'](1) != 0 or m['dkxChienMin'](2) != 500 or m['dkxChienMin'](3) != 500",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxChienMin'](4) != 0 or m['dkxChienMin'](5) != 0 or m['dkxChienMin'](6) != 0 or m['dkxChienMin'](7) != 0 or m['dkxChienMin'](8) != 0 or m['dkxChienMin'](9) != 0 or m['dkxChienMax'](0) != 0 or m['dkxChienMax'](1) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxChienMax'](2) != 1000 or m['dkxChienMax'](3) != 2000 or m['dkxChienMax'](4) != 0 or m['dkxChienMax'](5) != 0 or m['dkxChienMax'](6) != 0 or m['dkxChienMax'](7) != 0 or m['dkxChienMax'](8) != 0 or m['dkxChienMax'](9) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxGemsMin'](0) != 0 or m['dkxGemsMin'](1) != 0 or m['dkxGemsMin'](2) != 0 or m['dkxGemsMin'](3) != 0 or m['dkxGemsMin'](4) != 10 or m['dkxGemsMin'](5) != 0 or m['dkxGemsMin'](6) != 0 or m['dkxGemsMin'](7) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxGemsMin'](8) != 0 or m['dkxGemsMin'](9) != 0 or m['dkxGemsMax'](0) != 0 or m['dkxGemsMax'](1) != 0 or m['dkxGemsMax'](2) != 0 or m['dkxGemsMax'](3) != 0 or m['dkxGemsMax'](4) != 100 or m['dkxGemsMax'](5) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxGemsMax'](6) != 0 or m['dkxGemsMax'](7) != 0 or m['dkxGemsMax'](8) != 0 or m['dkxGemsMax'](9) != 0 or m['dkxArtMin'](0) != 0 or m['dkxArtMin'](1) != 0 or m['dkxArtMin'](2) != 0 or m['dkxArtMin'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxArtMin'](4) != 0 or m['dkxArtMin'](5) != 5 or m['dkxArtMin'](6) != 0 or m['dkxArtMin'](7) != 0 or m['dkxArtMin'](8) != 0 or m['dkxArtMin'](9) != 0 or m['dkxArtMax'](0) != 0 or m['dkxArtMax'](1) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dkxArtMax'](2) != 0 or m['dkxArtMax'](3) != 0 or m['dkxArtMax'](4) != 0 or m['dkxArtMax'](5) != 50 or m['dkxArtMax'](6) != 0 or m['dkxArtMax'](7) != 0 or m['dkxArtMax'](8) != 0 or m['dkxArtMax'](9) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R736 OA Table II.A. Orient audit",
      "comment" = "OA round one hundred twenty-three (capture pp. 286-287): the Table II.A. (Orient) Monetary Treasure - the nine d20 bands, the treasure ranges as the min and max pairs with the nil the 0 sentinel, the roll-twice and roll-three-times mechanics with the reroll limit, the one-of-each 20 row, the capture misreads pinned against the print, single-pass pins per the Chapter 9 provenance shift",
    },
}
