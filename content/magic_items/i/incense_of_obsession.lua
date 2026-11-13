-- misc magic item def: incense_of_obsession
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part14.h (R270)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "incense_of_obsession",
  name = "Incense of Obsession",
  rows = {
    { name = "Incense of Obsession",
      set = "kMisc3", band = { 71, 71 }, xp = 0, xp_hi = 0,
      gp = 500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 14, round = 270 },
  },
  pins = {
    { name = "obsessionDurationHours", value = 24,
      comment = "the cleric remains obsessed until all spells are cast "
      .. "or 24 hours have elapsed" },
    { name = "obsessionPiecesMin", value = 2,
      comment = "there are 2-8 pieces of this incense normally" },
    { name = "obsessionPiecesMax", value = 8,
      comment = "the upper edge of the normal 2-8 pieces" },
    { name = "obsessionBurnHours", value = 1,
      comment = "each piece burns for 1 hour" },
  },
  tables = {
  },
}
