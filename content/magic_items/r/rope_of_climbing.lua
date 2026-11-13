-- misc magic item def: rope_of_climbing
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "rope_of_climbing",
  name = "Rope of Climbing",
  rows = {
    { name = "Rope of Climbing",
      set = "kMisc5", band = { 20, 25 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "climbLengthFeet", value = 60,
      comment = "a 60 foot long rope of climbing" },
    { name = "climbWeightPounds", value = 3,
      comment = "weighs no more than 3 pounds" },
    { name = "climbSupportPounds", value = 3000,
      comment = "strong enough to support 3,000 pounds" },
    { name = "climbSpeedFeetPerRound", value = 10,
      comment = "moves at 10 feet per round upon command" },
    { name = "climbKnotIntervalFeet", value = 1,
      comment = "large knots appear at 1 foot intervals" },
    { name = "climbKnottedLengthFeet", value = 50,
      comment = "knotting shortens the rope to 50 feet" },
  },
  tables = {
  },
}
