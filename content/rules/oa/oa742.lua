-- oa742: promoted from rules/oa/oa113miscmagic.h (the OA TREASURE - MISCELLANEOUS MAGIC, printed capture pp. 288-289 - the misc);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 742,
  "prefix" = "oa742",
  "banner" = {
      "title" = "OA TREASURE - MISCELLANEOUS MAGIC, printed capture pp. 288-289 - the misc",
      "provenance" = "item notes round census 664 -> 665.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 195 closed, 40 open - the misc magic box flips (census 664 -> 665); NEXT - R743: Armor and Shield prose (capture pp. 289-291), prefix dle (verify free at the landing), audit \"R743 OA armor shield audit\", include after rules/oa/oa113miscmagic.h",
    },
  "consts" = { {
      "name" = "dldBootsOfElvenkindRerolled",
      "value" = 1,
      "comment" = "the boots of elvenkind - not commonly available in Oriental lands, the result rerolled (print capture p. 288)",
    }, {
      "name" = "dldBroomOfAnimatedAttackRerolled",
      "value" = 1,
      "comment" = "the broom of animated attack - not commonly available in Oriental lands, the result rerolled (print capture p. 288)",
    }, {
      "name" = "dldBroomOfFlyingRerolled",
      "value" = 1,
      "comment" = "the broom of flying - not commonly available in Oriental lands, the result rerolled (print capture p. 288)",
    }, {
      "name" = "dldCloakOfElvenkindRerolled",
      "value" = 1,
      "comment" = "the cloak of elvenkind - not common to Oriental lands, the result rerolled (print capture p. 289)",
    }, {
      "name" = "dldInstrumentsOfTheBardsRerolled",
      "value" = 1,
      "comment" = "the instruments of the bards - not found in Oriental lands, the result rerolled (print capture p. 289)",
    }, {
      "name" = "dldManualOfGolemsRerolled",
      "value" = 1,
      "comment" = "the manual of golems - the magical book not found in Oriental lands, the result rerolled (print capture p. 289)",
    }, {
      "name" = "dldEverfulPurseIntro",
      "value" = 1,
      "comment" = "the everful purse - when opened, the purse will contain the table (print capture p. 288)",
    }, {
      "name" = "dldPurseRowCount",
      "value" = 3,
      "comment" = "the purse row count - the three d100 bands of the everful purse contents (print capture p. 289)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dldPurseRollMin",
      "values" = { 1, 51, 91 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 289)",
    }, {
      "name" = "dldPurseRollMax",
      "values" = { 50, 90, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 289)",
    }, {
      "name" = "dldPurseFen",
      "values" = { 0, 20, 20 },
      "default" = 0,
      "comment" = "the fen count - the 20 of the 51-100 rows, the 0 the nil (print capture p. 289)",
    }, {
      "name" = "dldPurseYuan",
      "values" = { 10, 0, 0 },
      "default" = 0,
      "comment" = "the yuan count - the 10 of the 01-50 row, the 0 the nil (print capture p. 289)",
    }, {
      "name" = "dldPurseTael",
      "values" = { 5, 5, 5 },
      "default" = 0,
      "comment" = "the tael count - the 5 of every row (print capture p. 289)",
    }, {
      "name" = "dldPurseChien",
      "values" = { 1, 2, 0 },
      "default" = 0,
      "comment" = "the ch'ien count - the 1 and 2 of the first two rows, the 0 the nil of the 91-100 (print capture p. 289)",
    }, {
      "name" = "dldPurseGems",
      "values" = { 0, 0, 10 },
      "default" = 0,
      "comment" = "the gems count - the 10 of the 91-100 row, the 0 the nil (print capture p. 289)",
    } },
  "tables" = { {
      "name" = "dldEverfulPurse",
      "tag" = "EverfulPurse",
      "count" = "dldPurseRowCount",
      "comment" = "the Bucknard's everful purse contents table - the three d100 bands of the coins and gems (print capture p. 289)",
      "cols" = { "dldPurseRollMin", "dldPurseRollMax", "dldPurseFen", "dldPurseYuan", "dldPurseTael", "dldPurseChien", "dldPurseGems" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 289)", "the d100 band maximum - the high roll of the row (print capture p. 289)", "the fen count - the 20 of the 51-100 rows, the 0 the nil (print capture p. 289)", "the yuan count - the 10 of the 01-50 row, the 0 the nil (print capture p. 289)", "the tael count - the 5 of every row (print capture p. 289)", "the ch'ien count - the 1 and 2 of the first two rows, the 0 the nil of the 91-100 (print capture p. 289)", "the gems count - the 10 of the 91-100 row, the 0 the nil (print capture p. 289)" },
      "data" = { { 1, 50, 0, 10, 5, 1, 0 }, { 51, 90, 20, 0, 5, 2, 0 }, { 91, 100, 20, 0, 5, 0, 10 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 1, 2, 0, 1, 2 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dldPurseRowCount']() != 3  or  m['dldBootsOfElvenkindRerolled']() != 1  or  m['dldBroomOfAnimatedAttackRerolled']() != 1  or  m['dldBroomOfFlyingRerolled']() != 1  or  m['dldEverfulPurseIntro']() != 1  or  m['dldCloakOfElvenkindRerolled']() != 1  or  m['dldInstrumentsOfTheBardsRerolled']() != 1  or  m['dldManualOfGolemsRerolled']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dldBootsOfElvenkindRerolled']() != 1  or m['dldBroomOfAnimatedAttackRerolled']() != 1  or m['dldBroomOfFlyingRerolled']() != 1  or m['dldCloakOfElvenkindRerolled']() != 1  or m['dldInstrumentsOfTheBardsRerolled']() != 1  or m['dldManualOfGolemsRerolled']() != 1",
      "note" = "the rerolled and absent items, healthy values, each condition false",
    }, {
      "expr" = "m['dldPurseRowCount']() != 3  or m['dldPurseYuan'](0) != 10  or m['dldPurseChien'](1) != 2  or m['dldPurseGems'](2) != 10  or m['dldPurseTael'](2) != 5",
      "note" = "the purse - the three-band contents table, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dldPurseRollMin'](0) != 1 or m['dldPurseRollMin'](1) != 51 or m['dldPurseRollMin'](2) != 91 or m['dldPurseRollMin'](3) != 0 or m['dldPurseRollMax'](0) != 50 or m['dldPurseRollMax'](1) != 90 or m['dldPurseRollMax'](2) != 100 or m['dldPurseRollMax'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dldPurseFen'](0) != 0 or m['dldPurseFen'](1) != 20 or m['dldPurseFen'](2) != 20 or m['dldPurseFen'](3) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R742 OA misc magic audit",
      "comment" = "OA round one hundred twenty-nine (capture pp. 288-289): the Miscellaneous Magic section - the six rerolled or absent items, the Bucknard's everful purse with its three-band contents table, single-pass pins per the Chapter 9 provenance shift",
    },
}
