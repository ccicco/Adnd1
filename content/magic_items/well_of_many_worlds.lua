-- misc magic item def: well_of_many_worlds
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "well_of_many_worlds",
  name = "Well of Many Worlds",
  rows = {
    { name = "Well of Many Worlds",
      set = "kMisc5", band = { 88, 90 }, xp = 6000, xp_hi = 0,
      gp = 12000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "wellTwoWay", value = 1,
      comment = "things come through the opening both ways" },
  },
  tables = {
  },
}
