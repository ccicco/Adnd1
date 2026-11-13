-- misc magic item def: mirror_of_opposition
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "mirror_of_opposition",
  name = "Mirror of Opposition",
  rows = {
    { name = "Mirror of Opposition",
      set = "kMisc4", band = { 20, 20 }, xp = 0, xp_hi = 0,
      gp = 2000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
  },
  tables = {
  },
}
