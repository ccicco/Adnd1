-- ua_uad1
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA druid ceremony varieties.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uad1",
  name = "UA druid ceremony varieties",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uad1RowCount",
      value = 9,
      comment = "the table rows" },
  },
  rows = {
    { name = "Coming of Age",
      set = "ua_uad1",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Rest Eternal",
      set = "ua_uad1",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Marriage",
      set = "ua_uad1",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Dedication",
      set = "ua_uad1",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Investiture",
      set = "ua_uad1",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Initiation",
      set = "ua_uad1",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Special Vows",
      set = "ua_uad1",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Hallowed Ground",
      set = "ua_uad1",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Cast Out",
      set = "ua_uad1",
      band = { 8, 8 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "variety_level",
      values = {
        1, 1, 1, 0, 0, 0, 0, 0, 12, 
      },
      comment = "the UA druid ceremony varieties variety_level column" },
  },
}
