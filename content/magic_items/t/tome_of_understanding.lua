-- misc magic item def: tome_of_understanding
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "tome_of_understanding",
  name = "Tome of Understanding",
  rows = {
    { name = "Tome of Understanding",
      set = "kMisc5", band = { 69, 69 }, xp = 8000, xp_hi = 0,
      gp = 43500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "understandingWisGain", value = 1,
      comment = "the tome of understanding raises wisdom by 1" },
  },
  tables = {
  },
}
