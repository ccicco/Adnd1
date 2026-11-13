-- misc magic item def: bag_of_tricks
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part2.h (R258)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bag_of_tricks",
  name = "Bag of Tricks",
  rows = {
    { name = "Bag of Tricks",
      set = "kMisc1", band = { 28, 29 }, xp = 2500, xp_hi = 0,
      gp = 15000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 2, round = 258 },
  },
  pins = {
    { name = "tricksTossMinFeet", value = 1,
      comment = "withdrawn and tossed 1 to 20 feet away" },
    { name = "tricksTossMaxFeet", value = 20,
      comment = "the top of the 1-20 foot toss" },
    { name = "tricksTypeDieSides", value = 10,
      comment = "roll d10 to determine the bag type" },
    { name = "tricksTypeCount", value = 3,
      comment = "three type tables" },
    { name = "tricksAnimalsPerType", value = 8,
      comment = "8 animals per type table, die 1-8" },
    { name = "tricksAnimalDieMin", value = 1,
      comment = "the animal die low edge" },
    { name = "tricksAnimalDieMax", value = 8,
      comment = "the animal die high edge" },
    { name = "tricksDrawnAtOnceMax", value = 1,
      comment = "only 1 creature drawn forth at a time" },
    { name = "tricksDurationTurns", value = 1,
      comment = "exists until slain or 1 turn elapsed" },
    { name = "tricksEndConditionCount", value = 2,
      comment = "slain, or ordered back after the turn" },
    { name = "tricksTypeRollCount", value = 1,
      comment = "one roll only for the bag type" },
    { name = "tricksWeeklyDrawMax", value = 10,
      comment = "up to 10 creatures per week" },
  },
  tables = {
    { name = "tricksTypeLo",
      comment = "the d10 type band lower edges; i clamps",
      clamp_hi = 2,
      values = {
        1, 6, 9,
      } },
    { name = "tricksTypeHi",
      comment = "the d10 type band upper edges (0 = 10)",
      clamp_hi = 2,
      values = {
        5, 8, 100,
      } },
  },
}
