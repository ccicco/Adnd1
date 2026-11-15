-- ua_uailc
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA illusionist cantrips.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uailc",
  name = "UA illusionist cantrips",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uailcRowCount",
      value = 8,
      comment = "the table rows" },
  },
  rows = {
    { name = "Colored Lights (Alteration)",
      set = "ua_uailc",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Dim (Alteration)",
      set = "ua_uailc",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Haze (Alteration)",
      set = "ua_uailc",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Mask (Illusion)",
      set = "ua_uailc",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Mirage",
      set = "ua_uailc",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Noise (Illusion)",
      set = "ua_uailc",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Rainbow (Alteration)",
      set = "ua_uailc",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Two-D'lusion",
      set = "ua_uailc",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "cast_den",
      values = {
        2, 2, 2, 8, 2, 8, 3, 8, 
      },
      comment = "the UA illusionist cantrips cast_den column" },
  },
}
