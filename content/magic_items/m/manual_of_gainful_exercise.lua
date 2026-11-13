-- misc magic item def: manual_of_gainful_exercise
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part17.h (R273)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "manual_of_gainful_exercise",
  name = "Manual of Gainful Exercise",
  rows = {
    { name = "Manual of Gainful Exercise",
      set = "kMisc4", band = { 6, 6 }, xp = 5000, xp_hi = 0,
      gp = 50000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 17, round = 273 },
  },
  pins = {
    { name = "exerciseStrGain", value = 1,
      comment = "the course adds 1 point of strength" },
  },
  tables = {
  },
}
