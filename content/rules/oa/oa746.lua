-- oa746: promoted from rules/oa117table77.h (the OA TREASURE - TABLE 77, SPECIAL PROPERTIES, printed capture p. 290 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 746,
  "prefix" = "oa746",
  "banner" = {
      "title" = "OA TREASURE - TABLE 77, SPECIAL PROPERTIES, printed capture p. 290 - the",
      "provenance" = "special property grid round census 668 -> 669.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 199 closed, 36 open - the Table 77 box flips (census 668 -> 669); NEXT - R747: Explanation of Armor Properties (capture p. 290), prefix dli (verify free at the landing), audit \"R747 OA armor explanation audit\", include after rules/oa117table77.h",
    },
  "consts" = { {
      "name" = "dlhSpecialRowCount",
      "value" = 11,
      "comment" = "the special property row count - the eleven d100 bands of the Table 77 special property grid (print capture p. 290)",
    }, {
      "name" = "dlhEtherealnessBand",
      "value" = 1,
      "comment" = "the etherealness band - the 01-05, its mechanics in the Explanation prose (print capture p. 290)",
    }, {
      "name" = "dlhVersusMissilesBands",
      "value" = 1,
      "comment" = "the versus-missiles bands - the +3, +4, and +5 of the 06-50 stretch, three grades of the missile protection (print capture p. 290)",
    }, {
      "name" = "dlhVulnerabilityBand",
      "value" = 1,
      "comment" = "the vulnerability band - the 51-65, the pluses a penalty per the Explanation (print capture p. 290)",
    }, {
      "name" = "dlhMissileAttractionBand",
      "value" = 1,
      "comment" = "the missile attraction band - the 66-75, the cursed shield function of the Explanation (print capture p. 290)",
    }, {
      "name" = "dlhPresenceBand",
      "value" = 1,
      "comment" = "the presence band - the 76-80, the commanding aura of the Explanation (print capture p. 290)",
    }, {
      "name" = "dlhBlendingBand",
      "value" = 1,
      "comment" = "the blending band - the 81-85, the normal-clothing disguise of the Explanation (print capture p. 290)",
    }, {
      "name" = "dlhFearBand",
      "value" = 1,
      "comment" = "the fear band - the 86-90, the fear charges of the Explanation (print capture p. 290)",
    }, {
      "name" = "dlhPossessionBand",
      "value" = 1,
      "comment" = "the possession band - the 91-95, the lifeforce possession of the Explanation prose (print capture p. 290)",
    }, {
      "name" = "dlhHealingBand",
      "value" = 1,
      "comment" = "the healing band - the 96-100, the healing armor of the Explanation (print capture p. 290)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlhSpecialRollMin",
      "values" = { 1, 6, 31, 41, 51, 66, 76, 81, 86, 91, 96 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 290)",
    }, {
      "name" = "dlhSpecialRollMax",
      "values" = { 5, 30, 40, 50, 65, 75, 80, 85, 90, 95, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 290)",
    }, {
      "name" = "dlhSpecialCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
      "default" = 0,
      "comment" = "the special property code - 1 the etherealness; 2 the +3 versus missiles; 3 the +4 versus missiles; 4 the +5 versus missiles; 5 the vulnerability; 6 the missile attraction; 7 the presence; 8 the blending; 9 the fear; 10 the possession; 11 the healing (print capture p. 290)",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlhSpecialRowCount']() != 11  or  m['dlhEtherealnessBand']() != 1  or  m['dlhVersusMissilesBands']() != 1  or  m['dlhVulnerabilityBand']() != 1  or  m['dlhMissileAttractionBand']() != 1  or  m['dlhPresenceBand']() != 1  or  m['dlhBlendingBand']() != 1  or  m['dlhFearBand']() != 1  or  m['dlhPossessionBand']() != 1  or  m['dlhHealingBand']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlhSpecialRowCount']() != 11  or m['dlhSpecialRollMin'](0) != 1  or m['dlhSpecialRollMax'](10) != 100  or m['dlhSpecialCode'](0) != 1  or m['dlhSpecialCode'](10) != 11",
      "note" = "the grid - the eleven-band Table 77, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlhEtherealnessBand']() != 1  or m['dlhVersusMissilesBands']() != 1  or m['dlhVulnerabilityBand']() != 1  or m['dlhMissileAttractionBand']() != 1  or m['dlhPresenceBand']() != 1  or m['dlhBlendingBand']() != 1  or m['dlhFearBand']() != 1  or m['dlhPossessionBand']() != 1  or m['dlhHealingBand']() != 1",
      "note" = "the band bools - the eleven special properties walked, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R746 OA Table 77 special audit",
      "comment" = "OA round one hundred thirty-three (capture p. 290): the Table 77 Special Properties - the eleven d100 bands, the etherealness through the healing, the three versus-missiles grades, the possession band whose mechanics ride in the Explanation prose, single-pass pins per the Chapter 9 provenance shift",
    },
}
