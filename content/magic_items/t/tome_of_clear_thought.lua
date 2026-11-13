-- misc magic item def: tome_of_clear_thought
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "tome_of_clear_thought",
  name = "Tome of Clear Thought",
  rows = {
    { name = "Tome of Clear Thought",
      set = "kMisc5", band = { 67, 67 }, xp = 8000, xp_hi = 0,
      gp = 48000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "clearThoughtIntGain", value = 1,
      comment = "the tome raises intelligence by 1 point" },
    { name = "clearThoughtReadHours", value = 48,
      comment = "reading takes 48 hours over 6 days" },
    { name = "clearThoughtReadDays", value = 6,
      comment = "the six reading days" },
    { name = "clearThoughtStartWeeks", value = 1,
      comment = "the exercises must begin within 1 week" },
    { name = "clearThoughtGainMonths", value = 1,
      comment = "intelligence goes up after 1 full month" },
    { name = "clearThoughtRereadGain", value = 0,
      comment = "any further perusal is of no benefit" },
  },
  tables = {
  },
}
