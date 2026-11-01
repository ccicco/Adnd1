-- oa691: promoted from rules/oa69combos.h (the OA TABLE 69, printed capture p. 226 - the martial style combinations round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 691,
  "prefix" = "oa691",
  "banner" = {
      "title" = "OA TABLE 69, printed capture p. 226 - the martial style combinations round",
      "provenance" = "census 613 -> 614.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE FORM ROWS: Hard the AC 1, attack 1, damage 4 - the muscles and bones for power; Soft the AC 3, attack 0 - the only zero of the grid, damage 2 - the inner power; Hard/Soft the 2/1/3 of the best practices from each. THE METHOD ROWS: Kick the 1/1/4 of the Foot; Lock the 1/1/2 of the Body; Movement the 2/1/2 of the Legs; Push the 2/1/1 of the Hand; Strike the 1/1/1 of the Hand; Throw the 1/1/2 of the whole Body; Vital Area the 2/1/1 of the Hand and Foot; Weapon the 1/1 of the Hand and Arm, the damage BY WEAPON - pinned 0, not a mod, the R662 convention. THE USE: the mods totaled per the R690 mechanics - the AC from the 10, the attacks style-specific, the damage rounded up to the die, the body part free; the derived examples prove it within the round - Hard plus Kick the AC 8, attacks 2, damage 8; Soft plus Movement the damage 4. The grid codifies per the R431 calculus  the gap census after this round: 144 closed, 91 open - the Table 69 box flips (census 613 -> 614); NEXT - R692: Table 70 the martial arts special maneuvers grid (capture p. 227), prefix djf (verify free at the landing), audit \"R692 OA special maneuvers audit\", include after rules/oa69combos.h",
    },
  "consts" = { {
      "name" = "djeOA69RowCount",
      "value" = 11,
      "comment" = "the Table 69 row count - the three form rows and the eight principal method rows, the loop bound of the emitted grid audit (print capture p. 226)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "djeOA69ACMod",
      "values" = { 1, 3, 2, 1, 1, 2, 2, 1, 1, 2, 1 },
      "default" = 0,
      "comment" = "the Table 69 armor class mods by row ordinal (print capture p. 226): rows 0-2 the forms - Hard 1, Soft 3, Hard/Soft 2; rows 3-10 the methods - Kick 1, Lock 1, Movement 2, Push 2, Strike 1, Throw 1, Vital Area 2, Weapon 1; the AC of a style 10 minus the totaled form and method mods",
    }, {
      "name" = "djeOA69AtMod",
      "values" = { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
      "default" = 0,
      "comment" = "the Table 69 attack mods by row ordinal (print capture p. 226): the forms - Hard 1, Soft 0 - the only zero of the grid, Hard/Soft 1; every method a 1; the number of attacks the totaled form and method mods",
    }, {
      "name" = "djeOA69DamageMod",
      "values" = { 4, 2, 3, 4, 2, 2, 1, 1, 2, 1, 0 },
      "default" = 0,
      "comment" = "the Table 69 damage mods by row ordinal (print capture p. 226): the forms - Hard 4, Soft 2, Hard/Soft 3; the methods - Kick 4, Lock 2, Movement 2, Push 1, Strike 1, Throw 2, Vital Area 1; the Weapon row a 0 - the printed damage BY WEAPON, not a mod, the R662 convention; the damage the totaled mods rounded up to the nearest die - 6 the 1d6, 4 the 1d4, 5 the 1d6",
    }, {
      "name" = "djeOA69BodyPart",
      "values" = { 0, 0, 0, 1, 2, 3, 4, 4, 2, 5, 6 },
      "default" = 0,
      "comment" = "the Table 69 body parts by row ordinal, coded (print capture p. 226): 0 none - the form rows printed a dash; 1 Foot (Kick), 2 Body (Lock and Throw), 3 Legs (Movement), 4 Hand (Push and Strike), 5 Hand and Foot (Vital Area), 6 Hand and Arm (Weapon); kicking the feet, throwing the whole body, the attacks effective so long as the part is unbound or free to move",
    } },
  "tables" = { {
      "name" = "djeOA69Grid",
      "tag" = "OA69Data",
      "count" = "djeOA69RowCount",
      "col_default" = 0,
      "cols" = { "djeOA69ACMod", "djeOA69AtMod", "djeOA69DamageMod", "djeOA69BodyPart" },
      "col_comments" = { "the Table 69 armor class mods by row ordinal (print capture p. 226): rows 0-2 the forms - Hard 1, Soft 3, Hard/Soft 2; rows 3-10 the methods - Kick 1, Lock 1, Movement 2, Push 2, Strike 1, Throw 1, Vital Area 2, Weapon 1; the AC of a style 10 minus the totaled form and method mods", "the Table 69 attack mods by row ordinal (print capture p. 226): the forms - Hard 1, Soft 0 - the only zero of the grid, Hard/Soft 1; every method a 1; the number of attacks the totaled form and method mods", "the Table 69 damage mods by row ordinal (print capture p. 226): the forms - Hard 4, Soft 2, Hard/Soft 3; the methods - Kick 4, Lock 2, Movement 2, Push 1, Strike 1, Throw 2, Vital Area 1; the Weapon row a 0 - the printed damage BY WEAPON, not a mod, the R662 convention; the damage the totaled mods rounded up to the nearest die - 6 the 1d6, 4 the 1d4, 5 the 1d6", "the Table 69 body parts by row ordinal, coded (print capture p. 226): 0 none - the form rows printed a dash; 1 Foot (Kick), 2 Body (Lock and Throw), 3 Legs (Movement), 4 Hand (Push and Strike), 5 Hand and Foot (Vital Area), 6 Hand and Arm (Weapon); kicking the feet, throwing the whole body, the attacks effective so long as the part is unbound or free to move" },
      "data" = { { 1, 1, 4, 0 }, { 3, 0, 2, 0 }, { 2, 1, 3, 0 }, { 1, 1, 4, 1 }, { 1, 1, 2, 2 }, { 2, 1, 2, 3 }, { 2, 1, 1, 4 }, { 1, 1, 1, 4 }, { 1, 1, 2, 2 }, { 2, 1, 1, 5 }, { 1, 1, 0, 6 } },
      "comment" = "Table 69: the martial style combinations - the three forms and the eight principal methods with their AC, attack and damage mods and body parts (print capture p. 226)",
      "audit_comment" = "the Table 69 grid - the eleven rows across four columns",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['djeOA69RowCount']() != 11",
      "note" = "",
    }, {
      "expr" = "m['djeOA69ACMod'](0) != 1  or m['djeOA69AtMod'](0) != 1  or m['djeOA69DamageMod'](0) != 4  or m['djeOA69ACMod'](1) != 3  or m['djeOA69AtMod'](1) != 0  or m['djeOA69DamageMod'](1) != 2  or m['djeOA69ACMod'](2) != 2  or m['djeOA69DamageMod'](2) != 3",
      "note" = "the form rows - Hard 1/1/4, Soft 3/0/2, Hard/Soft 2/1/3",
    }, {
      "expr" = "m['djeOA69ACMod'](3) != 1  or m['djeOA69ACMod'](4) != 1  or m['djeOA69ACMod'](5) != 2  or m['djeOA69ACMod'](6) != 2  or m['djeOA69ACMod'](9) != 2  or m['djeOA69ACMod'](10) != 1",
      "note" = "the method AC mods - Kick, Lock and Throw at 1, Movement, Push and Vital Area at 2",
    }, {
      "expr" = "m['djeOA69DamageMod'](3) != 4  or m['djeOA69DamageMod'](6) != 1  or m['djeOA69DamageMod'](7) != 1  or m['djeOA69DamageMod'](9) != 1  or m['djeOA69DamageMod'](10) != 0",
      "note" = "the damage mods - the Kick 4 the highest method, Push, Strike and Vital Area the 1s, Weapon the by-weapon 0",
    }, {
      "expr" = "m['djeOA69BodyPart'](3) != 1  or m['djeOA69BodyPart'](4) != 2  or m['djeOA69BodyPart'](5) != 3  or m['djeOA69BodyPart'](6) != 4  or m['djeOA69BodyPart'](8) != 2  or m['djeOA69BodyPart'](9) != 5  or m['djeOA69BodyPart'](10) != 6",
      "note" = "the body parts - Foot, Body, Legs, Hand, Hand, Body, Hand-and-Foot, Hand-and-Arm",
    }, {
      "expr" = "10 -m['djeOA69ACMod'](0) -m['djeOA69ACMod'](3) != 8  or m['djeOA69AtMod'](0) +m['djeOA69AtMod'](3) != 2",
      "note" = "the derived style - Hard plus Kick: the AC 10-1-1, the attacks 1+1",
    }, {
      "expr" = "m['djeOA69DamageMod'](0) +m['djeOA69DamageMod'](3) != 8  or m['djeOA69DamageMod'](1) +m['djeOA69DamageMod'](5) != 4",
      "note" = "the derived damage - Hard plus Kick the 8, Soft plus Movement the 4",
    } },
  "audit" = {
      "label" = "R691 OA style combinations audit",
      "comment" = "OA round seventy-eight (capture p. 226): Table 69 - the martial style combinations grid, the three forms and eight methods across four columns with the derived-style examples, single-pass pins per the Chapter 9 provenance shift",
    },
}
