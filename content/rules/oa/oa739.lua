-- oa739: promoted from rules/oa110potions.h (the OA TREASURE - POTIONS, printed capture pp. 287-288 - the control brews);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 739,
  "prefix" = "oa739",
  "banner" = {
      "title" = "OA TREASURE - POTIONS, printed capture pp. 287-288 - the control brews",
      "provenance" = "round census 661 -> 662.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 192 closed, 43 open - the potions box flips (census 661 -> 662); NEXT - R740: Scrolls (capture p. 288), prefix dlb (verify free at the landing), audit \"R740 OA scrolls audit\", include after rules/oa110potions.h",
    },
  "consts" = { {
      "name" = "dlaDragonRowCount",
      "value" = 12,
      "comment" = "the dragon control row count - the twelve d20 bands of the potion table (print capture p. 287)",
    }, {
      "name" = "dlaDragonControlExists",
      "value" = 1,
      "comment" = "the existence - the potions of dragon control do exist (print capture p. 287)",
    }, {
      "name" = "dlaNotSameDragonsAsDMG",
      "value" = 1,
      "comment" = "the difference - they do not affect the same types of dragons as those listed in the DMG (print capture p. 287)",
    }, {
      "name" = "dlaUseTableBelow",
      "value" = 1,
      "comment" = "the instruction - use the table given below (print capture p. 287)",
    }, {
      "name" = "dlaChiangLung",
      "value" = 1,
      "comment" = "the 1-2 band - the chiang lung control (print capture p. 287)",
    }, {
      "name" = "dlaPanLung",
      "value" = 1,
      "comment" = "the 3-4 band - the pan lung control (print capture p. 287)",
    }, {
      "name" = "dlaYuLung",
      "value" = 1,
      "comment" = "the 5-7 band - the yu lung control (print capture p. 287)",
    }, {
      "name" = "dlaShenLung",
      "value" = 1,
      "comment" = "the 8-9 band - the shen lung control (print capture p. 287)",
    }, {
      "name" = "dlaLiLung",
      "value" = 1,
      "comment" = "the 10 band - the li lung control (print capture p. 287)",
    }, {
      "name" = "dlaMistDragon",
      "value" = 1,
      "comment" = "the 11-12 band - the mist dragon control (print capture p. 287)",
    }, {
      "name" = "dlaCloudDragon",
      "value" = 1,
      "comment" = "the 13-14 band - the cloud dragon control (print capture p. 287)",
    }, {
      "name" = "dlaLungWang",
      "value" = 1,
      "comment" = "the 15 band - the lung wang control (print capture p. 287)",
    }, {
      "name" = "dlaTienLung",
      "value" = 1,
      "comment" = "the 16 band - the t'ien lung control (print capture p. 287)",
    }, {
      "name" = "dlaGiantControlHillGiant",
      "value" = 1,
      "comment" = "the giant control - the only type commonly found is the hill giant control (print capture p. 287)",
    }, {
      "name" = "dlaHumanRowCount",
      "value" = 7,
      "comment" = "the human control row count - the seven d20 bands of the potion controls table (print capture p. 288)",
    }, {
      "name" = "dlaHumanControlIntro",
      "value" = 1,
      "comment" = "the human control intro - when determining the type of creature that can be controlled, use the following table (print capture p. 287)",
    }, {
      "name" = "dlaGajinRollOnDMG",
      "value" = 1,
      "comment" = "the 20 band - the gajin, rolled on the DMG table (print capture p. 288)",
    }, {
      "name" = "dlaUndeadControlRerolled",
      "value" = 1,
      "comment" = "the undead control - not normally available in Oriental lands, the result rerolled (print capture p. 288)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlaDragonRollMin",
      "values" = { 1, 3, 5, 8, 10, 11, 13, 15, 16, 17, 18, 20 },
      "default" = 0,
      "comment" = "the d20 band minimum - the low roll of the row (print capture p. 287)",
    }, {
      "name" = "dlaDragonRollMax",
      "values" = { 2, 4, 7, 9, 10, 12, 14, 15, 16, 17, 19, 20 },
      "default" = 0,
      "comment" = "the d20 band maximum - the high roll of the row (print capture p. 287)",
    }, {
      "name" = "dlaDragonCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
      "default" = 0,
      "comment" = "the dragon code - 1 the chiang lung; 2 the pan lung; 3 the yu lung; 4 the shen lung; 5 the li lung; 6 the mist dragon; 7 the cloud dragon; 8 the lung wang; 9 the t'ien lung; 10 the gold dragon; 11 the evil dragon; 12 the good dragon (print capture p. 287)",
    }, {
      "name" = "dlaHumanRollMin",
      "values" = { 1, 3, 6, 7, 16, 17, 20 },
      "default" = 0,
      "comment" = "the d20 band minimum - the low roll of the row (print capture p. 288)",
    }, {
      "name" = "dlaHumanRollMax",
      "values" = { 2, 5, 6, 15, 16, 19, 20 },
      "default" = 0,
      "comment" = "the d20 band maximum - the high roll of the row (print capture p. 288)",
    }, {
      "name" = "dlaHumanCode",
      "values" = { 1, 2, 3, 4, 5, 6, 7 },
      "default" = 0,
      "comment" = "the controls code - 1 the korobokuru; 2 the hengeyokai; 3 the spirit folk; 4 the human; 5 the tengu; 6 the korobokuru, hengeyokai, and humans; 7 the gajin of the DMG table (print capture p. 288)",
    } },
  "tables" = { {
      "name" = "dlaDragonControl",
      "tag" = "DragonControl",
      "count" = "dlaDragonRowCount",
      "comment" = "the dragon control potion table - the twelve d20 bands of the Oriental dragon types, chiang lung through good dragon (print capture p. 287)",
      "cols" = { "dlaDragonRollMin", "dlaDragonRollMax", "dlaDragonCode" },
      "col_comments" = { "the d20 band minimum - the low roll of the row (print capture p. 287)", "the d20 band maximum - the high roll of the row (print capture p. 287)", "the dragon code - 1 the chiang lung; 2 the pan lung; 3 the yu lung; 4 the shen lung; 5 the li lung; 6 the mist dragon; 7 the cloud dragon; 8 the lung wang; 9 the t'ien lung; 10 the gold dragon; 11 the evil dragon; 12 the good dragon (print capture p. 287)" },
      "data" = { { 1, 2, 1 }, { 3, 4, 2 }, { 5, 7, 3 }, { 8, 9, 4 }, { 10, 10, 5 }, { 11, 12, 6 }, { 13, 14, 7 }, { 15, 15, 8 }, { 16, 16, 9 }, { 17, 17, 10 }, { 18, 19, 11 }, { 20, 20, 12 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dlaHumanControl",
      "tag" = "HumanControl",
      "count" = "dlaHumanRowCount",
      "comment" = "the human control potion table - the seven d20 bands of the potion controls, korobokuru through the gajin of the DMG table (print capture p. 288)",
      "cols" = { "dlaHumanRollMin", "dlaHumanRollMax", "dlaHumanCode" },
      "col_comments" = { "the d20 band minimum - the low roll of the row (print capture p. 288)", "the d20 band maximum - the high roll of the row (print capture p. 288)", "the controls code - 1 the korobokuru; 2 the hengeyokai; 3 the spirit folk; 4 the human; 5 the tengu; 6 the korobokuru, hengeyokai, and humans; 7 the gajin of the DMG table (print capture p. 288)" },
      "data" = { { 1, 2, 1 }, { 3, 5, 2 }, { 6, 6, 3 }, { 7, 15, 4 }, { 16, 16, 5 }, { 17, 19, 6 }, { 20, 20, 7 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlaDragonRowCount']() != 12  or m['dlaHumanRowCount']() != 7  or  m['dlaDragonControlExists']() != 1  or  m['dlaNotSameDragonsAsDMG']() != 1  or  m['dlaUseTableBelow']() != 1  or  m['dlaChiangLung']() != 1  or  m['dlaPanLung']() != 1  or  m['dlaYuLung']() != 1  or  m['dlaShenLung']() != 1  or  m['dlaLiLung']() != 1  or  m['dlaMistDragon']() != 1  or  m['dlaCloudDragon']() != 1  or  m['dlaLungWang']() != 1  or  m['dlaTienLung']() != 1  or  m['dlaGiantControlHillGiant']() != 1  or  m['dlaHumanControlIntro']() != 1  or  m['dlaGajinRollOnDMG']() != 1  or  m['dlaUndeadControlRerolled']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlaDragonControlExists']() != 1  or m['dlaNotSameDragonsAsDMG']() != 1  or m['dlaUseTableBelow']() != 1  or m['dlaChiangLung']() != 1  or m['dlaPanLung']() != 1  or m['dlaYuLung']() != 1  or m['dlaShenLung']() != 1  or m['dlaLiLung']() != 1  or m['dlaMistDragon']() != 1  or m['dlaCloudDragon']() != 1  or m['dlaLungWang']() != 1  or m['dlaTienLung']() != 1",
      "note" = "the dragon control prose and the band bools, healthy values, each condition false",
    }, {
      "expr" = "m['dlaGiantControlHillGiant']() != 1  or m['dlaHumanControlIntro']() != 1  or m['dlaGajinRollOnDMG']() != 1  or m['dlaUndeadControlRerolled']() != 1",
      "note" = "the giant, human, and undead notes, healthy values, each condition false",
    }, {
      "expr" = "m['dlaDragonRowCount']() != 12  or m['dlaHumanRowCount']() != 7  or m['dlaDragonRollMin'](0) != 1  or m['dlaDragonRollMax'](11) != 20  or m['dlaHumanRollMin'](0) != 1  or m['dlaHumanRollMax'](6) != 20",
      "note" = "the grids - the two potion tables, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlaDragonCode'](0) != 1 or m['dlaDragonCode'](1) != 2 or m['dlaDragonCode'](2) != 3 or m['dlaDragonCode'](3) != 4 or m['dlaDragonCode'](4) != 5 or m['dlaDragonCode'](5) != 6 or m['dlaDragonCode'](6) != 7 or m['dlaDragonCode'](7) != 8",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dlaDragonCode'](8) != 9 or m['dlaDragonCode'](9) != 10 or m['dlaDragonCode'](10) != 11 or m['dlaDragonCode'](11) != 12 or m['dlaDragonCode'](12) != 0 or m['dlaHumanCode'](0) != 1 or m['dlaHumanCode'](1) != 2 or m['dlaHumanCode'](2) != 3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dlaHumanCode'](3) != 4 or m['dlaHumanCode'](4) != 5 or m['dlaHumanCode'](5) != 6 or m['dlaHumanCode'](6) != 7 or m['dlaHumanCode'](7) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R739 OA potions audit",
      "comment" = "OA round one hundred twenty-six (capture pp. 287-288): the Potions section - the dragon control potion with its twelve-band d20 table, the hill giant giant control, the human control table of seven bands with the gajin DMG-table row, the undead control reroll, single-pass pins per the Chapter 9 provenance shift",
    },
}
