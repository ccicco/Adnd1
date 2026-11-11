-- oa754: promoted from rules/oa/oa125table83.h (the OA TREASURE - TABLE 83, MISSILE CLASS, printed capture p. 293 - the missile);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 754,
  "prefix" = "oa754",
  "banner" = {
      "title" = "OA TREASURE - TABLE 83, MISSILE CLASS, printed capture p. 293 - the missile",
      "provenance" = "type grid round census 676 -> 677.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 207 closed, 28 open - the Table 83 box flips (census 676 -> 677); NEXT - R755: Table 84: Martial Arts Class (capture p. 293), prefix dlq (verify free at the landing), audit \"R755 OA Table 84 martial arts audit\", include after rules/oa/oa125table83.h",
    },
  "consts" = { {
      "name" = "dlpMissileRowCount",
      "value" = 12,
      "comment" = "the missile row count - the twelve d100 bands of the Table 83 missile type grid (print capture p. 293)",
    }, {
      "name" = "dlpArrowBands",
      "value" = 1,
      "comment" = "the arrow bands - the five arrow types of the 01-60 stretch, the armor piercer through the normal (print capture p. 293)",
    }, {
      "name" = "dlpSingleRollBands",
      "value" = 1,
      "comment" = "the single-roll bands - the 71 blowpipe dart and the 72 thrown dart, the one-number bands of the grid (print capture p. 293)",
    }, {
      "name" = "dlpUchiNeTail",
      "value" = 1,
      "comment" = "the uchi-ne tail - the 99-100 closing band, the short Japanese throwing dart (print capture p. 293)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlpMissileRollMin",
      "values" = { 1, 11, 21, 26, 41, 61, 71, 72, 73, 78, 91, 99 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 293)",
    }, {
      "name" = "dlpMissileRollMax",
      "values" = { 10, 20, 25, 40, 60, 70, 71, 72, 77, 90, 98, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 293)",
    }, {
      "name" = "dlpMissileCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
      "default" = 0,
      "comment" = "the missile type code - 1 the armor piercer arrow, 2-12 damage; 2 the frog crotch arrow, 2-8 damage; 3 the humming bulb arrow, 2-5 damage; 4 the leaf head arrow, 2-12 damage; 5 the normal arrow, 3-24 damage; 6 the throwing axe; 7 the blowpipe dart, 2-8 damage; 8 the thrown dart, 3-12 damage; 9 the javelin; 10 the quarrel, 2-24 damage; 11 the sling and pellet bow bullets, 2-20 damage; 12 the uchi-ne (print capture p. 293)",
    } },
  "tables" = { {
      "name" = "dlpMissileClass",
      "tag" = "MissileClass",
      "count" = "dlpMissileRowCount",
      "comment" = "the Table 83 Missile Class grid - the twelve d100 bands of the missile types, the armor piercer arrow through the uchi-ne (print capture p. 293)",
      "cols" = { "dlpMissileRollMin", "dlpMissileRollMax", "dlpMissileCode" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 293)", "the d100 band maximum - the high roll of the row (print capture p. 293)", "the missile type code - 1 the armor piercer arrow, 2-12 damage; 2 the frog crotch arrow, 2-8 damage; 3 the humming bulb arrow, 2-5 damage; 4 the leaf head arrow, 2-12 damage; 5 the normal arrow, 3-24 damage; 6 the throwing axe; 7 the blowpipe dart, 2-8 damage; 8 the thrown dart, 3-12 damage; 9 the javelin; 10 the quarrel, 2-24 damage; 11 the sling and pellet bow bullets, 2-20 damage; 12 the uchi-ne (print capture p. 293)" },
      "data" = { { 1, 10, 1 }, { 11, 20, 2 }, { 21, 25, 3 }, { 26, 40, 4 }, { 41, 60, 5 }, { 61, 70, 6 }, { 71, 71, 7 }, { 72, 72, 8 }, { 73, 77, 9 }, { 78, 90, 10 }, { 91, 98, 11 }, { 99, 100, 12 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlpMissileRowCount']() != 12  or  m['dlpArrowBands']() != 1  or  m['dlpSingleRollBands']() != 1  or  m['dlpUchiNeTail']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlpMissileRowCount']() != 12  or m['dlpMissileRollMin'](0) != 1  or m['dlpMissileRollMax'](11) != 100  or m['dlpMissileCode'](0) != 1  or m['dlpMissileCode'](11) != 12",
      "note" = "the grid - the twelve-band Table 83, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlpMissileRollMax'](4) != 60  or m['dlpMissileCode'](4) != 5  or m['dlpMissileRollMin'](6) != 71  or m['dlpMissileRollMax'](7) != 72  or m['dlpArrowBands']() != 1  or m['dlpSingleRollBands']() != 1  or m['dlpUchiNeTail']() != 1",
      "note" = "the quirks - the arrow stretch, the single-roll bands, and the tail, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R754 OA Table 83 missile audit",
      "comment" = "OA round one hundred forty-one (capture p. 293): the Table 83 Missile Class - the twelve d100 bands of the missile types, the five arrow types through the uchi-ne, single-pass pins per the Chapter 9 provenance shift",
    },
}
