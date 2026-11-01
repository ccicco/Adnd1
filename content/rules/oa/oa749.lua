-- oa749: promoted from rules/oa120table78.h (the OA TREASURE - TABLE 78, MAGICAL WEAPONS, printed capture p. 291 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 749,
  "prefix" = "oa749",
  "banner" = {
      "title" = "OA TREASURE - TABLE 78, MAGICAL WEAPONS, printed capture p. 291 - the",
      "provenance" = "weapon class grid round census 671 -> 672.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 202 closed, 33 open - the Table 78 box flips (census 671 -> 672); NEXT - R750: Table 79: Weapon Properties (capture p. 291, the grid runs onto p. 292), prefix dll (verify free at the landing), audit \"R750 OA Table 79 properties audit\", include after rules/oa120table78.h",
    },
  "consts" = { {
      "name" = "dlkClassRowCount",
      "value" = 6,
      "comment" = "the class row count - the six d100 bands of the Table 78 weapon class grid (print capture p. 291)",
    }, {
      "name" = "dlkSwordClass",
      "value" = 1,
      "comment" = "the sword class - the 01-40 band rolling on the Table 80 Sword Class (print capture p. 291)",
    }, {
      "name" = "dlkBowCrossbowSlingClass",
      "value" = 1,
      "comment" = "the bow class - the 41-52 band of the bow, crossbow, or sling, rolling on the Table 81 (print capture p. 291)",
    }, {
      "name" = "dlkMiscMeleeClass",
      "value" = 1,
      "comment" = "the miscellaneous melee class - the 53-68 band rolling on the Table 82 (print capture p. 291)",
    }, {
      "name" = "dlkMissileClass",
      "value" = 1,
      "comment" = "the missile class - the 69-80 band rolling on the Table 83 (print capture p. 291)",
    }, {
      "name" = "dlkMartialArtsClass",
      "value" = 1,
      "comment" = "the martial arts class - the 81-90 band rolling on the Table 84 (print capture p. 291)",
    }, {
      "name" = "dlkNinjaClass",
      "value" = 1,
      "comment" = "the ninja class - the 91-100 band rolling on the Table 85 (print capture p. 291)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dlkClassRollMin",
      "values" = { 1, 41, 53, 69, 81, 91 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 291)",
    }, {
      "name" = "dlkClassRollMax",
      "values" = { 40, 52, 68, 80, 90, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 291)",
    }, {
      "name" = "dlkClassCode",
      "values" = { 1, 2, 3, 4, 5, 6 },
      "default" = 0,
      "comment" = "the weapon class code - 1 the sword; 2 the bow, crossbow, or sling; 3 the miscellaneous melee weapon; 4 the missile weapon; 5 the martial arts weapon; 6 the ninja weapon (print capture p. 291)",
    } },
  "tables" = { {
      "name" = "dlkWeaponClasses",
      "tag" = "WeaponClasses",
      "count" = "dlkClassRowCount",
      "comment" = "the Table 78 Magical Weapons grid - the six d100 bands of the weapon classes, the sword through the ninja (print capture p. 291)",
      "cols" = { "dlkClassRollMin", "dlkClassRollMax", "dlkClassCode" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 291)", "the d100 band maximum - the high roll of the row (print capture p. 291)", "the weapon class code - 1 the sword; 2 the bow, crossbow, or sling; 3 the miscellaneous melee weapon; 4 the missile weapon; 5 the martial arts weapon; 6 the ninja weapon (print capture p. 291)" },
      "data" = { { 1, 40, 1 }, { 41, 52, 2 }, { 53, 68, 3 }, { 69, 80, 4 }, { 81, 90, 5 }, { 91, 100, 6 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlkClassRowCount']() != 6  or  m['dlkSwordClass']() != 1  or  m['dlkBowCrossbowSlingClass']() != 1  or  m['dlkMiscMeleeClass']() != 1  or  m['dlkMissileClass']() != 1  or  m['dlkMartialArtsClass']() != 1  or  m['dlkNinjaClass']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlkClassRowCount']() != 6  or m['dlkClassRollMin'](0) != 1  or m['dlkClassRollMax'](5) != 100  or m['dlkClassCode'](0) != 1  or m['dlkClassCode'](5) != 6",
      "note" = "the grid - the six-band Table 78, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dlkSwordClass']() != 1  or m['dlkBowCrossbowSlingClass']() != 1  or m['dlkMiscMeleeClass']() != 1  or m['dlkMissileClass']() != 1  or m['dlkMartialArtsClass']() != 1  or m['dlkNinjaClass']() != 1",
      "note" = "the class walk - the six weapon classes, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R749 OA Table 78 weapons audit",
      "comment" = "OA round one hundred thirty-six (capture p. 291): the Table 78 Magical Weapons - the six d100 bands of the weapon classes, the sword through the ninja, each class pointing to its specific type table, single-pass pins per the Chapter 9 provenance shift",
    },
}
