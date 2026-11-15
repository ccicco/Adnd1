-- ua_uac5_animate
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA animate dead example types.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_animate",
  name = "UA animate dead example types",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_animateRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "apes (carnivorous and giant)",
      set = "ua_uac5_animate",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "bugbears",
      set = "ua_uac5_animate",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "ettins",
      set = "ua_uac5_animate",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "giants (all varieties)",
      set = "ua_uac5_animate",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "ogres",
      set = "ua_uac5_animate",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "trolls",
      set = "ua_uac5_animate",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
