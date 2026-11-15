-- wspec
-- The R1058 weapons-family de-wire.
-- weapon specialization level bands.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in the family headers and keep their clamps.
-- DO NOT hand-edit: tools/r1058_splice.py is the only writer.

return {
  key = "wspec",
  name = "weapon specialization level bands",
  sources = {
    { part = 0, round = 1058 },
  },
  pins = {
    { name = "wspecRowCount",
      value = 3,
      comment = "the table rows" },
  },
  rows = {
    { name = "band_0",
      set = "wspec",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_1",
      set = "wspec",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "band_2",
      set = "wspec",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "band_high",
      values = {
        6, 12, 0, 
      },
      comment = "the weapon specialization level bands band_high column" },
    { name = "band_low",
      values = {
        1, 7, 13, 
      },
      comment = "the weapon specialization level bands band_low column" },
  },
}
