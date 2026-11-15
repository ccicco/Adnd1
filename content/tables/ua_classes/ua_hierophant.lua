-- ua_hierophant
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA druid hierophant ladder and conjure bands.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_hierophant",
  name = "UA druid hierophant ladder and conjure bands",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_hierophantRowCount",
      value = 8,
      comment = "the table rows" },
  },
  rows = {
    { name = "band_16",
      set = "ua_hierophant",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_17",
      set = "ua_hierophant",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_18",
      set = "ua_hierophant",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_19",
      set = "ua_hierophant",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_20",
      set = "ua_hierophant",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_21",
      set = "ua_hierophant",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_22",
      set = "ua_hierophant",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_23",
      set = "ua_hierophant",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "conjure_high",
      values = {
        85, 94, 98, 100, 85, 94, 98, 100, 85, 94, 
        98, 100, 85, 94, 98, 100, 85, 95, 100, 0, 
      },
      comment = "the UA druid hierophant ladder and conjure bands conjure_high column; [a][b] FLATTENED a-major, width 4" },
    { name = "conjure_low",
      values = {
        1, 86, 95, 99, 1, 86, 95, 99, 1, 86, 
        95, 99, 1, 86, 95, 99, 1, 86, 96, 0, 
      },
      comment = "the UA druid hierophant ladder and conjure bands conjure_low column; [a][b] FLATTENED a-major, width 4" },
    { name = "xp_band_low",
      values = {
        1, 500001, 1000001, 1500001, 2000001, 2500001, 3000001, 3500001, 
      },
      comment = "the UA druid hierophant ladder and conjure bands xp_band_low column; banded reads index arg - 16" },
  },
}
