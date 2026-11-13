-- misc magic item def: periapt_of_health
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "periapt_of_health",
  name = "Periapt of Health",
  rows = {
    { name = "Periapt of Health",
      set = "kMisc4", band = { 51, 53 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
  },
  tables = {
  },
}
