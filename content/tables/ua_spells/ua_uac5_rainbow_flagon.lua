-- ua_uac5_rainbow_flagon
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA rainbow flagon draught colors.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_rainbow_flagon",
  name = "UA rainbow flagon draught colors",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_rainbow_flagonRowCount",
      value = 7,
      comment = "the table rows" },
  },
  rows = {
    { name = "red",
      set = "ua_uac5_rainbow_flagon",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "orange",
      set = "ua_uac5_rainbow_flagon",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "yellow",
      set = "ua_uac5_rainbow_flagon",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "green",
      set = "ua_uac5_rainbow_flagon",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "blue",
      set = "ua_uac5_rainbow_flagon",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "indigo",
      set = "ua_uac5_rainbow_flagon",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "violet",
      set = "ua_uac5_rainbow_flagon",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
