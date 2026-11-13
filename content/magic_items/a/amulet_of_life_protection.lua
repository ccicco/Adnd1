-- misc magic item def: amulet_of_life_protection
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "amulet_of_life_protection",
  name = "Amulet of Life Protection",
  rows = {
    { name = "Amulet of Life Protection",
      set = "kMisc1", band = { 5, 5 }, xp = 5000, xp_hi = 0,
      gp = 20000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "amuletLifeProtectionDays", value = 7,
      comment = "the psyche is protected for 7 full days" },
  },
  tables = {
  },
}
