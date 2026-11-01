-- oa741: promoted from rules/oa112rods.h (the OA TREASURE - RODS, STAVES, AND WANDS, printed capture p. 288 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 741,
  "prefix" = "oa741",
  "banner" = {
      "title" = "OA TREASURE - RODS, STAVES, AND WANDS, printed capture p. 288 - the",
      "provenance" = "resurrection rod round census 663 -> 664.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 194 closed, 41 open - the rods box flips (census 663 -> 664); NEXT - R742: Miscellaneous Magic (capture pp. 288-289), prefix dld (verify free at the landing), audit \"R742 OA misc magic audit\", include after rules/oa112rods.h",
    },
  "consts" = { {
      "name" = "dlcRodOfResurrection",
      "value" = 1,
      "comment" = "the rod of resurrection - the item expending a number of charges according to the table (print capture p. 288)",
    }, {
      "name" = "dlcChargesClassPlusRace",
      "value" = 1,
      "comment" = "the charge law - the class base plus the race plus of the two columns (print capture p. 288)",
    }, {
      "name" = "dlcClassCount",
      "value" = 10,
      "comment" = "the class row count - the ten classes of the charge table (print capture p. 288)",
    }, {
      "name" = "dlcRaceCount",
      "value" = 4,
      "comment" = "the race row count - the four races of the plus column (print capture p. 288)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlcClassCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
      "default" = 0,
      "comment" = "the class code - 1 the samurai; 2 the shukenja; 3 the bushi; 4 the ninja; 5 the wu jen; 6 the kensai; 7 the sohei; 8 the yakuza; 9 the monk; 10 the barbarian (print capture p. 288)",
    }, {
      "name" = "dlcClassBase",
      "values" = { 3, 1, 2, 4, 3, 2, 1, 3, 3, 3 },
      "default" = 0,
      "comment" = "the base charges - the 3 of the samurai, the 1 of the shukenja, the 2 of the bushi, the 4 of the ninja, the 3 of the wu jen, the 2 of the kensai, the 1 of the sohei, the 3 of the yakuza, the 3 of the monk, the 3 of the barbarian (print capture p. 288)",
    }, {
      "name" = "dlcRaceCode",
      "values" = { 1, 2, 3, 4 },
      "default" = 0,
      "comment" = "the race code - 1 the korobokuru; 2 the spirit folk; 3 the hengeyokai; 4 the human (print capture p. 288)",
    }, {
      "name" = "dlcRacePlus",
      "values" = { 3, 4, 3, 1 },
      "default" = 0,
      "comment" = "the race plus - the 3 of the korobokuru, the 4 of the spirit folk, the 3 of the hengeyokai, the 1 of the human (print capture p. 288)",
    } },
  "tables" = { {
      "name" = "dlcRodClass",
      "tag" = "RodClass",
      "count" = "dlcClassCount",
      "comment" = "the class base charge table - the ten Oriental classes row by row (print capture p. 288)",
      "cols" = { "dlcClassCode", "dlcClassBase" },
      "col_comments" = { "the class code - 1 the samurai; 2 the shukenja; 3 the bushi; 4 the ninja; 5 the wu jen; 6 the kensai; 7 the sohei; 8 the yakuza; 9 the monk; 10 the barbarian (print capture p. 288)", "the base charges - the 3 of the samurai, the 1 of the shukenja, the 2 of the bushi, the 4 of the ninja, the 3 of the wu jen, the 2 of the kensai, the 1 of the sohei, the 3 of the yakuza, the 3 of the monk, the 3 of the barbarian (print capture p. 288)" },
      "data" = { { 1, 3 }, { 2, 1 }, { 3, 2 }, { 4, 4 }, { 5, 3 }, { 6, 2 }, { 7, 1 }, { 8, 3 }, { 9, 3 }, { 10, 3 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0 },
    }, {
      "name" = "dlcRodRace",
      "tag" = "RodRace",
      "count" = "dlcRaceCount",
      "comment" = "the race plus table - the four character races of the plus column (print capture p. 288)",
      "cols" = { "dlcRaceCode", "dlcRacePlus" },
      "col_comments" = { "the race code - 1 the korobokuru; 2 the spirit folk; 3 the hengeyokai; 4 the human (print capture p. 288)", "the race plus - the 3 of the korobokuru, the 4 of the spirit folk, the 3 of the hengeyokai, the 1 of the human (print capture p. 288)" },
      "data" = { { 1, 3 }, { 2, 4 }, { 3, 3 }, { 4, 1 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlcClassCount']() != 10  or m['dlcRaceCount']() != 4  or  m['dlcRodOfResurrection']() != 1  or  m['dlcChargesClassPlusRace']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlcRodOfResurrection']() != 1  or m['dlcChargesClassPlusRace']() != 1",
      "note" = "the prose - the rod and the charge law, healthy values, each condition false",
    }, {
      "expr" = "m['dlcClassCount']() != 10  or m['dlcRaceCount']() != 4  or m['dlcClassBase'](0) != 3  or m['dlcClassBase'](3) != 4  or m['dlcRacePlus'](0) != 3  or m['dlcRacePlus'](1) != 4",
      "note" = "the grids - the two charge tables, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlcClassCode'](0) != 1 or m['dlcClassCode'](1) != 2 or m['dlcClassCode'](2) != 3 or m['dlcClassCode'](3) != 4 or m['dlcClassCode'](4) != 5 or m['dlcClassCode'](5) != 6 or m['dlcClassCode'](6) != 7 or m['dlcClassCode'](7) != 8",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dlcClassCode'](8) != 9 or m['dlcClassCode'](9) != 10 or m['dlcClassCode'](10) != 0 or m['dlcRaceCode'](0) != 1 or m['dlcRaceCode'](1) != 2 or m['dlcRaceCode'](2) != 3 or m['dlcRaceCode'](3) != 4 or m['dlcRaceCode'](4) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R741 OA rods staves wands audit",
      "comment" = "OA round one hundred twenty-eight (capture p. 288): the Rods, Staves, and Wands section - the Rod of Resurrection charge table, the ten class base charges and the four race pluses as the two paired grids, single-pass pins per the Chapter 9 provenance shift",
    },
}
