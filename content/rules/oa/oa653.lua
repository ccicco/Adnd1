-- oa653: promoted from rules/oacharprof.h (the TABLE 56 CHARACTER PROFICIENCIES, printed capture p. 99 - the OA character);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 653,
  "prefix" = "oa653",
  "banner" = {
      "title" = "TABLE 56 CHARACTER PROFICIENCIES, printed capture p. 99 - the OA character",
      "provenance" = "proficiencies round census 575 -> 576.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the table - the Table 56 grid cross-checked cell-by-cell between the two passes (the table printing on capture p. 99 of the print pass; compressed p. 52); every printed cell agrees - zero contested cells. The grid pins as a table: the class rows 0 samurai, 1 shukenja, 2 sohei, 3 kensai, 4 o. barbarian, 5 bushi, 6 wu jen and 7 ninja riding the first column comment, three data columns - the initial number of proficiencies at 1st level (5, 6, 4, 3, 9, 4, 6, 2), the levels per added proficiency as the denominator of the printed 1/N notation (1, 2, 3, 2, 3, 2, 2, 3) and the non-proficiency weapon penalty (2, 4, 2, 3, 2, 2, 5, 4). The column doctrines ride the comments: the initial-number reading (the number at 1st level), the 1/N reading (1/1 a proficiency each level, 1/4 four levels per proficiency, 1st level included when counting) and the penalty reading (the minus on to hit with a weapon not proficient in). The ninja rule pins as a bool - the ninja can only use his proficiencies for ninja weapons, the non-proficiency penalty applying only to ninja weapons, all other weapons taking the other class penalty. The table tag T56Data identifier-safe per the R639 lesson; the slot-system prose cross-references stay with R650  the gap census after this round: 105 closed, 130 open - the Table 56 box flips (census 575 -> 576); NEXT - R654: Table 58 (Artisan Proficiencies), capture p. 103, prefix dho (verify free), audit \"R654 OA artisan proficiencies audit\", include after rules/oacharprof.h",
    },
  "consts" = { {
      "name" = "dhnT56ClassCount",
      "value" = 8,
      "comment" = "the eight character classes of the Table 56 grid (capture p. 99 of the print pass; compressed p. 52)",
    } },
  "bools" = { {
      "name" = "dhnNinjaNinjaWeaponsOnly",
      "value" = true,
      "comment" = "the ninja can only use his proficiencies for ninja weapons - the non-proficiency penalty applies only when using ninja weapons, all other weapons take the other class penalty (capture p. 99 of the print pass; compressed p. 52)",
    } },
  "switches" = { {
      "name" = "dhnT56InitialProf",
      "values" = { 5, 6, 4, 3, 9, 4, 6, 2 },
      "default" = -99,
      "comment" = "the initial number of proficiencies at 1st level (capture p. 99 of the print pass; compressed p. 52). The class rows ride this comment: 0 samurai, 1 shukenja, 2 sohei, 3 kensai, 4 o. barbarian, 5 bushi, 6 wu jen, 7 ninja - the printed header reads Initial # of Prof.",
    }, {
      "name" = "dhnT56LevelsPerProf",
      "values" = { 1, 2, 3, 2, 3, 2, 2, 3 },
      "default" = -99,
      "comment" = "the levels that must be earned per additional proficiency - the denominator of the printed 1/N notation, 1/1 a proficiency each level (capture p. 99 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhnT56NonprofPenalty",
      "values" = { 2, 4, 2, 3, 2, 2, 5, 4 },
      "default" = -99,
      "comment" = "the non-proficiency weapon penalty - the minus on to hit with a weapon not proficient in (capture p. 99 of the print pass; compressed p. 52)",
    } },
  "tables" = { {
      "name" = "dhnT56Grid",
      "tag" = "T56Data",
      "count" = "dhnT56ClassCount",
      "sentinel" = -99,
      "cols" = { "dhnT56InitialProf", "dhnT56LevelsPerProf", "dhnT56NonprofPenalty" },
      "col_comments" = { "the initial number of proficiencies at 1st level (capture p. 99 of the print pass; compressed p. 52). The class rows ride this comment: 0 samurai, 1 shukenja, 2 sohei, 3 kensai, 4 o. barbarian, 5 bushi, 6 wu jen, 7 ninja - the printed header reads Initial # of Prof.", "the levels that must be earned per additional proficiency - the denominator of the printed 1/N notation, 1/1 a proficiency each level (capture p. 99 of the print pass; compressed p. 52)", "the non-proficiency weapon penalty - the minus on to hit with a weapon not proficient in (capture p. 99 of the print pass; compressed p. 52)" },
      "data" = { { 5, 1, 2 }, { 6, 2, 4 }, { 4, 3, 2 }, { 3, 2, 3 }, { 9, 3, 2 }, { 4, 2, 2 }, { 6, 2, 5 }, { 2, 3, 4 } },
      "comment" = "the Table 56 character proficiencies grid (capture p. 99 of the print pass; compressed p. 52)",
      "audit_comment" = "the Table 56 grid: the initial proficiencies, the levels per added proficiency and the non-proficiency penalties by class",
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhnT56ClassCount']() != 8  or  m['dhnNinjaNinjaWeaponsOnly']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhnT56InitialProf'](0) != 5  or m['dhnT56InitialProf'](1) != 6  or m['dhnT56InitialProf'](2) != 4  or m['dhnT56InitialProf'](3) != 3  or m['dhnT56InitialProf'](4) != 9  or m['dhnT56InitialProf'](5) != 4  or m['dhnT56InitialProf'](6) != 6  or m['dhnT56InitialProf'](7) != 2",
      "note" = "the Table 56 initial-proficiency pins - samurai 5, shukenja 6, sohei 4, kensai 3, o. barbarian 9, bushi 4, wu jen 6, ninja 2",
    }, {
      "expr" = "m['dhnT56LevelsPerProf'](0) != 1  or m['dhnT56LevelsPerProf'](1) != 2  or m['dhnT56LevelsPerProf'](2) != 3  or m['dhnT56LevelsPerProf'](3) != 2  or m['dhnT56LevelsPerProf'](4) != 3  or m['dhnT56LevelsPerProf'](5) != 2  or m['dhnT56LevelsPerProf'](6) != 2  or m['dhnT56LevelsPerProf'](7) != 3",
      "note" = "the levels-per-added-proficiency pins - 1/1 samurai, 1/2 shukenja kensai bushi wu jen, 1/3 sohei o. barbarian ninja",
    }, {
      "expr" = "m['dhnT56NonprofPenalty'](0) != 2  or m['dhnT56NonprofPenalty'](1) != 4  or m['dhnT56NonprofPenalty'](2) != 2  or m['dhnT56NonprofPenalty'](3) != 3  or m['dhnT56NonprofPenalty'](4) != 2  or m['dhnT56NonprofPenalty'](5) != 2  or m['dhnT56NonprofPenalty'](6) != 5  or m['dhnT56NonprofPenalty'](7) != 4",
      "note" = "the non-proficiency penalty pins - samurai -2, shukenja -4, sohei -2, kensai -3, o. barbarian -2, bushi -2, wu jen -5, ninja -4",
    }, {
      "expr" = "m['dhnNinjaNinjaWeaponsOnly']() != 1",
      "note" = "the ninja pin - the ninja weapon-only rule with the other-class penalty for all other weapons",
    } },
  "audit" = {
      "label" = "R653 OA character proficiencies audit",
      "comment" = "OA round forty (capture p. 99): Table 56 - the character proficiencies grid, the initial proficiencies, the levels per added proficiency and the non-proficiency penalties by class, with the ninja weapon-only rule",
    },
}
