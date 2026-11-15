-- ua_socialclass
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA social class bands.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_socialclass",
  name = "UA social class bands",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_socialclassRowCount",
      value = 9,
      comment = "the table rows" },
  },
  rows = {
    { name = "Lower Lower Class",
      set = "ua_socialclass",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Middle Lower Class",
      set = "ua_socialclass",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Upper Lower Class",
      set = "ua_socialclass",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Lower Middle Class",
      set = "ua_socialclass",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Middle Middle Class",
      set = "ua_socialclass",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Upper Middle Class",
      set = "ua_socialclass",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Lower Upper Class",
      set = "ua_socialclass",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Middle Upper Class",
      set = "ua_socialclass",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Upper Upper Class",
      set = "ua_socialclass",
      band = { 8, 8 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "band_high",
      values = {
        4, 10, 20, 35, 55, 87, 96, 99, 100, 
      },
      comment = "the UA social class bands band_high column" },
    { name = "band_low",
      values = {
        1, 5, 11, 21, 36, 56, 88, 97, 100, 
      },
      comment = "the UA social class bands band_low column" },
    { name = "roster_count",
      values = {
        8, 10, 7, 8, 8, 9, 9, 6, 3, 
      },
      comment = "the UA social class bands roster_count column" },
    { name = "roster_offset",
      values = {
        0, 8, 18, 25, 33, 41, 50, 59, 65, 
      },
      comment = "the computed prefix-sum offsets" },
  },
}
