-- ua_uac7
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA succor object examples.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac7",
  name = "UA succor object examples",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac7RowCount",
      value = 3,
      comment = "the table rows" },
  },
  rows = {
    { name = "a string of prayer beads",
      set = "ua_uac7",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "a small clay tablet",
      set = "ua_uac7",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "an ivory baton",
      set = "ua_uac7",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
