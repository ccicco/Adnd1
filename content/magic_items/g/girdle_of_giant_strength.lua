-- misc magic item def: girdle_of_giant_strength
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "girdle_of_giant_strength",
  name = "Girdle of Giant Strength",
  rows = {
    { name = "Girdle of Giant Strength",
      set = "kMisc3", band = { 29, 29 }, xp = 200, xp_hi = 0,
      gp = 2500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "girdleGiantTypeCount", value = 6,
      comment = "the six giant strength types" },
    { name = "girdleGiantRockDmgMin", value = 1,
      comment = "every type hurls rocks from 1 die" },
  },
  tables = {
    { name = "girdleGiantDiceLo",
      comment = "the type dice band lower edges; i clamps",
      clamp_hi = 5,
      values = {
        1, 31, 51, 71, 86, 96,
      } },
    { name = "girdleGiantDiceHi",
      comment = "the type dice band upper edges; i clamps",
      clamp_hi = 5,
      values = {
        30, 50, 70, 85, 95, 100,
      } },
    { name = "girdleGiantStrength",
      comment = "the strength and rating column; i clamps",
      clamp_hi = 5,
      values = {
        19, 20, 21, 22, 23, 24,
      } },
    { name = "girdleGiantHitBonus",
      comment = "the to hit column; i clamps",
      clamp_hi = 5,
      values = {
        3, 3, 4, 4, 5, 6,
      } },
    { name = "girdleGiantDmgBonus",
      comment = "the damage column; i clamps",
      clamp_hi = 5,
      values = {
        7, 8, 9, 10, 11, 12,
      } },
    { name = "girdleGiantOpenDoorsTop",
      comment = "open doors numerator (7 in 8); i clamps",
      clamp_hi = 5,
      values = {
        7, 7, 9, 11, 11, 19,
      } },
    { name = "girdleGiantOpenDoorsBottom",
      comment = "open doors denominator (in 8); i clamps",
      clamp_hi = 5,
      values = {
        8, 8, 10, 12, 12, 20,
      } },
    { name = "girdleGiantOpenChances",
      comment = "the parenthesized chances (3 of 6); i clamps",
      clamp_hi = 5,
      values = {
        3, 3, 4, 4, 5, 7,
      } },
    { name = "girdleGiantOpenOutOf",
      comment = "chances out of 6 (8 for storm); i clamps",
      clamp_hi = 5,
      values = {
        6, 6, 6, 6, 6, 8,
      } },
    { name = "girdleGiantWeightAllowance",
      comment = "the weight allowance column; i clamps",
      clamp_hi = 5,
      values = {
        4500, 5000, 6000, 7500, 9000, 12000,
      } },
    { name = "girdleGiantRangeInches",
      comment = "the rock range column; i clamps",
      clamp_hi = 5,
      values = {
        8, 16, 10, 12, 14, 16,
      } },
    { name = "girdleGiantRockDmgMax",
      comment = "the rock base damage top die; i clamps",
      clamp_hi = 5,
      values = {
        6, 12, 8, 8, 10, 12,
      } },
    { name = "girdleGiantRockWeight",
      comment = "the approximate average missile weight; i clamps",
      clamp_hi = 5,
      values = {
        140, 198, 156, 170, 184, 212,
      } },
    { name = "girdleGiantBendBarsPct",
      comment = "bend bars and lift gates percent; i clamps",
      clamp_hi = 5,
      values = {
        50, 60, 70, 80, 90, 100,
      } },
  },
}
