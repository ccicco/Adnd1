-- misc magic item def: amulet_of_inescapable_location
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "amulet_of_inescapable_location",
  name = "Amulet of Inescapable Location",
  rows = {
    { name = "Amulet of Inescapable Location",
      set = "kMisc1", band = { 3, 4 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "amuletLocationMultiplier", value = 2,
      comment = "DOUBLES the likelihood and range (a cursed lure "
      .. "disguised as a protection amulet)" },
  },
  tables = {
  },
}
