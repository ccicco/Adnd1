-- ua_s2_il2
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA illusionist 2nd-level spell names.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_s2_il2",
  name = "UA illusionist 2nd-level spell names",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_s2_il2RowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "Dispel Illusion",
      set = "ua_s2_il2",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Hallucinatory Terrain",
      set = "ua_s2_il2",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Magic Mouth",
      set = "ua_s2_il2",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Mirror Image",
      set = "ua_s2_il2",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
