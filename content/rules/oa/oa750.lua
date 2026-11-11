-- oa750: promoted from rules/oa/oa121table79.h (the OA TREASURE - TABLE 79, WEAPON PROPERTIES, printed capture pp. 291-292 -);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 750,
  "prefix" = "oa750",
  "banner" = {
      "title" = "OA TREASURE - TABLE 79, WEAPON PROPERTIES, printed capture pp. 291-292 -",
      "provenance" = "the property grid round census 672 -> 673.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 203 closed, 32 open - the Table 79 box flips (census 672 -> 673); NEXT - R751: Table 80: Sword Class (capture p. 292), prefix dlm (verify free at the landing), audit \"R751 OA Table 80 sword audit\", include after rules/oa/oa121table79.h",
    },
  "consts" = { {
      "name" = "dllPropRowCount",
      "value" = 20,
      "comment" = "the property row count - the twenty d100 bands of the Table 79 property grid (print capture p. 291)",
    }, {
      "name" = "dllBowColumn",
      "value" = 1,
      "comment" = "the bow column - the weapon type of the first column, the quality through the speed (print capture p. 291)",
    }, {
      "name" = "dllMissileColumn",
      "value" = 1,
      "comment" = "the missile column - the weapon type of the second column, the damage pluses through the slaying (print capture p. 291)",
    }, {
      "name" = "dllMeleeColumn",
      "value" = 1,
      "comment" = "the melee column - the weapon type of the third column, the quality through the intelligence (print capture p. 291)",
    }, {
      "name" = "dllMartialArtsColumn",
      "value" = 1,
      "comment" = "the martial arts column - the weapon type of the fourth column, the quality through the roll twice (print capture p. 292)",
    }, {
      "name" = "dllNinjaColumn",
      "value" = 1,
      "comment" = "the ninja column - the weapon type of the fifth column, the quality through the roll twice (print capture p. 292)",
    }, {
      "name" = "dllRollTwiceTails",
      "value" = 1,
      "comment" = "the roll twice tails - the 96-100 martial arts and ninja cells rolling twice on the same grid (print capture p. 292)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dllPropRollMin",
      "values" = { 1, 6, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81, 86, 91, 96 },
      "default" = 0,
      "comment" = "the d100 band minimum - the low roll of the row (print capture p. 291)",
    }, {
      "name" = "dllPropRollMax",
      "values" = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 },
      "default" = 0,
      "comment" = "the d100 band maximum - the high roll of the row (print capture p. 292)",
    }, {
      "name" = "dllPropBow",
      "values" = { 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 6, 6, 7, 2, 3, 13, 18, 22, 14 },
      "default" = 0,
      "comment" = "the bow column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 291)",
    }, {
      "name" = "dllPropMissile",
      "values" = { 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 2, 2, 3, 4, 24 },
      "default" = 0,
      "comment" = "the missile column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 291)",
    }, {
      "name" = "dllPropMelee",
      "values" = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 11, 12, 19, 13, 25 },
      "default" = 0,
      "comment" = "the melee column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 291)",
    }, {
      "name" = "dllPropMartialArts",
      "values" = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 4, 14, 16, 20, 20, 26 },
      "default" = 0,
      "comment" = "the martial arts column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 292)",
    }, {
      "name" = "dllPropNinja",
      "values" = { 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 15, 17, 21, 23, 26 },
      "default" = 0,
      "comment" = "the ninja column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 292)",
    } },
  "tables" = { {
      "name" = "dllWeaponProps",
      "tag" = "WeaponProps",
      "count" = "dllPropRowCount",
      "comment" = "the Table 79 Weapon Properties grid - the twenty d100 bands by the five weapon-type columns (bow, missile, melee, martial arts, ninja), the quality and plus grades through the special rows, the grid spanning the page break (print capture p. 291)",
      "cols" = { "dllPropRollMin", "dllPropRollMax", "dllPropBow", "dllPropMissile", "dllPropMelee", "dllPropMartialArts", "dllPropNinja" },
      "col_comments" = { "the d100 band minimum - the low roll of the row (print capture p. 291)", "the d100 band maximum - the high roll of the row (print capture p. 292)", "the bow column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 291)", "the missile column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 291)", "the melee column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 291)", "the martial arts column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 292)", "the ninja column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print capture p. 292)" },
      "data" = { { 1, 5, 1, 8, 1, 1, 1 }, { 6, 10, 1, 8, 1, 1, 1 }, { 11, 15, 1, 8, 1, 1, 1 }, { 16, 20, 1, 8, 1, 1, 2 }, { 21, 25, 1, 8, 1, 1, 2 }, { 26, 30, 1, 8, 2, 2, 2 }, { 31, 35, 5, 8, 2, 2, 2 }, { 36, 40, 5, 8, 2, 2, 2 }, { 41, 45, 5, 8, 2, 2, 3 }, { 46, 50, 5, 9, 2, 2, 3 }, { 51, 55, 5, 9, 3, 2, 3 }, { 56, 60, 6, 9, 3, 3, 3 }, { 61, 65, 6, 9, 3, 3, 4 }, { 66, 70, 7, 9, 4, 3, 4 }, { 71, 75, 2, 10, 4, 4, 4 }, { 76, 80, 3, 2, 11, 14, 15 }, { 81, 85, 13, 2, 12, 16, 17 }, { 86, 90, 18, 3, 19, 20, 21 }, { 91, 95, 22, 4, 13, 20, 23 }, { 96, 100, 14, 24, 25, 26, 26 } },
      "sentinel" = 0,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dllPropRowCount']() != 20  or  m['dllBowColumn']() != 1  or  m['dllMissileColumn']() != 1  or  m['dllMeleeColumn']() != 1  or  m['dllMartialArtsColumn']() != 1  or  m['dllNinjaColumn']() != 1  or  m['dllRollTwiceTails']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dllPropRowCount']() != 20  or m['dllPropRollMin'](0) != 1  or m['dllPropRollMax'](19) != 100  or m['dllPropBow'](0) != 1  or m['dllPropMissile'](0) != 8  or m['dllPropMelee'](14) != 4  or m['dllPropMartialArts'](19) != 26  or m['dllPropNinja'](19) != 26",
      "note" = "the grid - the twenty-band Table 79, audited cell by cell by the table audit",
    }, {
      "expr" = "m['dllPropBow'](15) != 3  or m['dllPropMelee'](15) != 11  or m['dllPropBow'](16) != 13  or m['dllPropMelee'](16) != 12  or m['dllPropBow'](18) != 22  or m['dllPropMelee'](18) != 13  or m['dllPropMissile'](19) != 24  or m['dllPropMelee'](19) != 25  or m['dllRollTwiceTails']() != 1",
      "note" = "the special rows - the 76-100 stretch of the special properties, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R750 OA Table 79 properties audit",
      "comment" = "OA round one hundred thirty-seven (capture pp. 291-292): the Table 79 Weapon Properties - the twenty d100 bands by the five weapon-type columns, the quality and plus grades through the special rows and the roll-twice tails, single-pass pins per the Chapter 9 provenance shift",
    },
}
