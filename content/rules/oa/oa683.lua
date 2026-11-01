-- oa683: promoted from rules/oa67bowfire.h (the OA TABLE 67, printed capture p. 220 - the horseback bowfire modifiers round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 683,
  "prefix" = "oa683",
  "banner" = {
      "title" = "OA TABLE 67, printed capture p. 220 - the horseback bowfire modifiers round",
      "provenance" = "census 605 -> 606.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE GRID: the animal's current movement read as eighths of its normal movement - less than 1/2 the -1, 1/2 to less than 3/4 the -3, 3/4 to maximum speed the -5 - the modifiers cumulative with those for range, weapon versus armor type, etc. THE TURN LIMIT: during the round in which he fires, the character cannot perform maneuvers with his mount except for slight turning - the most 30 degrees to either side of its current direction, sharper turns and maneuvers preventing the bowfire. THE HORSE-LIKE CLAUSE: the firing also performed mounted on any horse-like creature to which the horsemanship proficiency applies. The grid codifies per the R431 calculus  the gap census after this round: 136 closed, 99 open - the Table 67 box flips (census 605 -> 606); NEXT - R684: the Unhorsing doctrine (capture p. 220), prefix dix (verify free at the landing - diu, div and diw TAKEN by the R681-R683 call families), audit \"R684 OA unhorsing audit\", include after rules/oa67bowfire.h",
    },
  "consts" = { {
      "name" = "diwOA67TurnDegrees",
      "value" = 30,
      "comment" = "the maneuver limit - during the round in which he fires, the character cannot perform maneuvers with his mount except for slight turning, the most the horse can be turned being 30 degrees to either side of its current direction (print capture p. 220)",
    }, {
      "name" = "diwOA67BandCount",
      "value" = 3,
      "comment" = "the Table 67 band count - the three speed bands of the horseback bowfire grid, the loop bound of the emitted grid audit (print capture p. 220)",
    } },
  "bools" = { {
      "name" = "diwOA67CumulativeModifiers",
      "value" = true,
      "comment" = "the cumulative clause - the horseback bowfire modifiers are cumulative with those for range, weapon versus armor type, etc. (print capture p. 220)",
    }, {
      "name" = "diwOA67SharperTurnsPreventFire",
      "value" = true,
      "comment" = "the sharper-turns rule - sharper turns and maneuvers prevent the character from firing his bow (print capture p. 220)",
    }, {
      "name" = "diwOA67HorseLikeCreaturesApply",
      "value" = true,
      "comment" = "the horse-like clause - firing from horseback can also be performed while mounted on any horse-like creature to which the horsemanship proficiency also applies (print capture p. 220)",
    } },
  "switches" = { {
      "name" = "diwOA67MinEighths",
      "values" = { 0, 4, 6 },
      "default" = 0,
      "comment" = "the Table 67 band floors in eighths of the animal's normal movement, by band ordinal (print capture p. 220): band 0 the less-than-half floor 0, band 1 the half floor 4, band 2 the three-quarters floor 6 - the printed bands read as eighths: less than 1/2, 1/2 to less than 3/4, 3/4 to maximum speed",
    }, {
      "name" = "diwOA67MaxEighths",
      "values" = { 3, 5, 8 },
      "default" = 0,
      "comment" = "the Table 67 band ceilings in eighths of the animal's normal movement, by band ordinal (print capture p. 220): band 0 the below-half ceiling 3, band 1 the below-three-quarters ceiling 5, band 2 the maximum-speed ceiling 8 - the full-speed band capping at the whole movement",
    }, {
      "name" = "diwOA67Modifier",
      "values" = { -1, -3, -5 },
      "default" = 0,
      "comment" = "the Table 67 horseback bowfire to-hit modifiers by band ordinal (print capture p. 220): -1 below half speed, -3 from half to less than three-quarters, -5 from three-quarters to maximum speed - the modifiers deepening with the speed of the animal, cumulative with the range and weapon versus armor modifiers",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['diwOA67TurnDegrees']() != 30  or m['diwOA67BandCount']() != 3  or  m['diwOA67CumulativeModifiers']() != 1  or  m['diwOA67SharperTurnsPreventFire']() != 1  or  m['diwOA67HorseLikeCreaturesApply']() != 1",
      "note" = "",
    }, {
      "expr" = "m['diwOA67Modifier'](0) != -1  or m['diwOA67Modifier'](1) != -3  or m['diwOA67Modifier'](2) != -5",
      "note" = "the modifier column - the -1, -3 and -5 of the three speed bands",
    }, {
      "expr" = "m['diwOA67MinEighths'](0) != 0  or m['diwOA67MinEighths'](1) != 4  or m['diwOA67MinEighths'](2) != 6",
      "note" = "the band floors - 0, 4 and 6 eighths of normal movement",
    }, {
      "expr" = "m['diwOA67MaxEighths'](0) != 3  or m['diwOA67MaxEighths'](1) != 5  or m['diwOA67MaxEighths'](2) != 8",
      "note" = "the band ceilings - 3, 5 and 8 eighths of normal movement",
    }, {
      "expr" = "m['diwOA67MaxEighths'](0) !=m['diwOA67MinEighths'](1) - 1  or m['diwOA67MaxEighths'](1) !=m['diwOA67MinEighths'](2) - 1",
      "note" = "the band contiguity - each ceiling abutting the next floor",
    }, {
      "expr" = "m['diwOA67TurnDegrees']() != 30",
      "note" = "the turn pin - the 30 degrees of slight turning",
    } },
  "audit" = {
      "label" = "R683 OA horseback bowfire modifiers audit",
      "comment" = "OA round seventy (capture p. 220): Table 67 - the horseback bowfire modifiers - the three speed bands of the animal with the -1, -3 and -5 to-hit penalties, the cumulative clause, the 30-degree slight-turning limit and the horse-like creatures clause, single-pass pins per the Chapter 9 provenance shift",
    },
}
