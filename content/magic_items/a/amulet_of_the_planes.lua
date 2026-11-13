-- misc magic item def: amulet_of_the_planes
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "amulet_of_the_planes",
  name = "Amulet of the Planes",
  rows = {
    { name = "Amulet of the Planes",
      set = "kMisc1", band = { 6, 7 }, xp = 6000, xp_hi = 0,
      gp = 30000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "amuletPlanesRowCount", value = 17,
      comment = "the plane table has 17 rows" },
    { name = "amuletPlanesLowDieFaces", value = 6,
      comment = "roll d6: 1-3 do not add 12" },
    { name = "amuletPlanesHighDieFaces", value = 12,
      comment = "add 12 to d12 for 1-24 random results" },
    { name = "amuletPlanesAddOnHigh", value = 12,
      comment = "the added 12 of the 4-6 results" },
    { name = "amuletPlanesResultMax", value = 24,
      comment = "1-24 random results" },
    { name = "amuletPlanesAltRowCount", value = 3,
      comment = "the alternate results: 3 rows" },
  },
  tables = {
    { name = "amuletPlanesRowLo",
      comment = "1-2 Seven Heavens through 21-24 Prime Material Plane",
      values = {
        1, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14, 15, 16, 18, 19, 20, 21,
      } },
    { name = "amuletPlanesRowHi",
      values = {
        2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14, 15, 17, 18, 19, 20, 24,
      } },
    { name = "amuletPlanesAltLo",
      comment = "alternates: 22 Ethereal, 23 Astral, 24 alternate Earth",
      values = {
        22, 23, 24,
      } },
  },
}
