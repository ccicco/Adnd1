-- oa752: promoted from rules/oa123table81.h (the OA TREASURE - TABLE 81, BOW, CROSSBOW, AND SLING CLASS, printed capture p.);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 752,
  "prefix" = "oa752",
  "banner" = {
      "title" = "OA TREASURE - TABLE 81, BOW, CROSSBOW, AND SLING CLASS, printed capture p.",
      "provenance" = "292 - the bow class grid round census 674 -> 675.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 205 closed, 30 open - the Table 81 box flips (census 674 -> 675); NEXT - R753: Table 82: Miscellaneous (capture p. 292), prefix dlo (verify free at the landing), audit \"R753 OA Table 82 misc melee audit\", include after rules/oa123table81.h",
    },
  "consts" = { {
      "name" = "dlnBowRowCount",
      "value" = 10,
      "comment" = "the bow row count - the ten d100 bands of the Table 81 bow type grid (print capture p. 292)",
    }, {
      "name" = "dlnCompositeShortbowBand",
      "value" = 1,
      "comment" = "the composite shortbow band - the 01-15 (print capture p. 292)",
    }, {
      "name" = "dlnShortBowBand",
      "value" = 1,
      "comment" = "the short bow band - the 16-30 (print capture p. 292)",
    }, {
      "name" = "dlnChuKoNuBand",
      "value" = 1,
      "comment" = "the chu-ko-nu band - the 31, the single-roll repeating crossbow (print capture p. 292)",
    }, {
      "name" = "dlnHeavyCrossbowBand",
      "value" = 1,
      "comment" = "the heavy crossbow band - the 32-45 (print capture p. 292)",
    }, {
      "name" = "dlnLightCrossbowBand",
      "value" = 1,
      "comment" = "the light crossbow band - the 46-60 (print capture p. 292)",
    }, {
      "name" = "dlnDaikyuBand",
      "value" = 1,
      "comment" = "the daikyu band - the 61-80, the Japanese great bow (print capture p. 292)",
    }, {
      "name" = "dlnHankyuBand",
      "value" = 1,
      "comment" = "the hankyu band - the 81-90, the Japanese short bow (print capture p. 292)",
    }, {
      "name" = "dlnPelletBowBand",
      "value" = 1,
      "comment" = "the pellet bow band - the 91 (print capture p. 292)",
    }, {
      "name" = "dlnSlingBand",
      "value" = 1,
      "comment" = "the sling band - the 92-96 (print capture p. 292)",
    }, {
      "name" = "dlnStaffSlingBand",
      "value" = 1,
      "comment" = "the staff sling band - the 97-100 (print capture p. 292)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlnBowRollMin",
      "values" = { 1, 16, 31, 32, 46, 61, 81, 91, 92, 97 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 292)",
    }, {
      "name" = "dlnBowRollMax",
      "values" = { 15, 30, 31, 45, 60, 80, 90, 91, 96, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 292)",
    }, {
      "name" = "dlnBowCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
      "default" = 0,
      "comment" = "the bow type code - 1 the composite shortbow; 2 the short bow; 3 the chu-ko-nu; 4 the heavy crossbow; 5 the light crossbow; 6 the daikyu; 7 the hankyu; 8 the pellet bow; 9 the sling; 10 the staff sling (print capture p. 292)",
    } },
  "tables" = { {
      "name" = "dlnBowClass",
      "tag" = "BowClass",
      "count" = "dlnBowRowCount",
      "comment" = "the Table 81 Bow, Crossbow, And Sling Class grid - the ten d100 bands of the missile weapon types, the composite shortbow through the staff sling (print capture p. 292)",
      "cols" = { "dlnBowRollMin", "dlnBowRollMax", "dlnBowCode" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 292)", "the d100 band maximum - the high roll of the row (print capture p. 292)", "the bow type code - 1 the composite shortbow; 2 the short bow; 3 the chu-ko-nu; 4 the heavy crossbow; 5 the light crossbow; 6 the daikyu; 7 the hankyu; 8 the pellet bow; 9 the sling; 10 the staff sling (print capture p. 292)" },
      "data" = { { 1, 15, 1 }, { 16, 30, 2 }, { 31, 31, 3 }, { 32, 45, 4 }, { 46, 60, 5 }, { 61, 80, 6 }, { 81, 90, 7 }, { 91, 91, 8 }, { 92, 96, 9 }, { 97, 100, 10 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlnBowRowCount']() != 10  or  m['dlnCompositeShortbowBand']() != 1  or  m['dlnShortBowBand']() != 1  or  m['dlnChuKoNuBand']() != 1  or  m['dlnHeavyCrossbowBand']() != 1  or  m['dlnLightCrossbowBand']() != 1  or  m['dlnDaikyuBand']() != 1  or  m['dlnHankyuBand']() != 1  or  m['dlnPelletBowBand']() != 1  or  m['dlnSlingBand']() != 1  or  m['dlnStaffSlingBand']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlnBowRowCount']() != 10  or m['dlnBowRollMin'](0) != 1  or m['dlnBowRollMax'](9) != 100  or m['dlnBowCode'](0) != 1  or m['dlnBowCode'](9) != 10",
      "note" = "the grid - the ten-band Table 81, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlnCompositeShortbowBand']() != 1  or m['dlnShortBowBand']() != 1  or m['dlnChuKoNuBand']() != 1  or m['dlnHeavyCrossbowBand']() != 1  or m['dlnLightCrossbowBand']() != 1  or m['dlnDaikyuBand']() != 1  or m['dlnHankyuBand']() != 1  or m['dlnPelletBowBand']() != 1  or m['dlnSlingBand']() != 1  or m['dlnStaffSlingBand']() != 1",
      "note" = "the band walk - the ten missile weapon types, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R752 OA Table 81 bow class audit",
      "comment" = "OA round one hundred thirty-nine (capture p. 292): the Table 81 Bow, Crossbow, And Sling Class - the ten d100 bands of the missile weapon types, the composite shortbow through the staff sling, single-pass pins per the Chapter 9 provenance shift",
    },
}
