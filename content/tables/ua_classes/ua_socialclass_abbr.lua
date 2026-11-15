-- ua_socialclass_abbr
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA social class abbreviations.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_socialclass_abbr",
  name = "UA social class abbreviations",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_socialclass_abbrRowCount",
      value = 9,
      comment = "the table rows" },
  },
  rows = {
    { name = "LLC",
      set = "ua_socialclass_abbr",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "MLC",
      set = "ua_socialclass_abbr",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "ULC",
      set = "ua_socialclass_abbr",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "LMC",
      set = "ua_socialclass_abbr",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "MMC",
      set = "ua_socialclass_abbr",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "UMC",
      set = "ua_socialclass_abbr",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "LUC",
      set = "ua_socialclass_abbr",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "MUC",
      set = "ua_socialclass_abbr",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "UUC",
      set = "ua_socialclass_abbr",
      band = { 8, 8 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
