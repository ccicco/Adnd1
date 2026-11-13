-- misc magic item def: talisman_of_ultimate_evil
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "talisman_of_ultimate_evil",
  name = "Talisman of Ultimate Evil",
  rows = {
    { name = "Talisman of Ultimate Evil",
      set = "kMisc5", band = { 59, 60 }, xp = 3500, xp_hi = 0,
      gp = 32500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "ultimateEvilCharges", value = 6,
      comment = "the exact opposite of pure good; 6 charges" },
  },
  tables = {
  },
}
