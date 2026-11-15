-- ua_s2_ilcantrip
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA illusionist cantrip names.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_s2_ilcantrip",
  name = "UA illusionist cantrip names",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_s2_ilcantripRowCount",
      value = 8,
      comment = "the table rows" },
  },
  rows = {
    { name = "Colored Lights",
      set = "ua_s2_ilcantrip",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Dim",
      set = "ua_s2_ilcantrip",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Haze",
      set = "ua_s2_ilcantrip",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Mask",
      set = "ua_s2_ilcantrip",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Mirage",
      set = "ua_s2_ilcantrip",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Noise",
      set = "ua_s2_ilcantrip",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Rainbow",
      set = "ua_s2_ilcantrip",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Two-D'lusion",
      set = "ua_s2_ilcantrip",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
