-- ua_ucl
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA legerdemain cantrips.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_ucl",
  name = "UA legerdemain cantrips",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uclRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "Change",
      set = "ua_ucl",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Distract",
      set = "ua_ucl",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Hide",
      set = "ua_ucl",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Mute",
      set = "ua_ucl",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Palm",
      set = "ua_ucl",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Present",
      set = "ua_ucl",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "cast_den",
      values = {
        10, 3, 10, 10, 10, 8, 
      },
      comment = "the UA legerdemain cantrips cast_den column" },
  },
}
