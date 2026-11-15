-- ua_s2_il1
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA illusionist 1st-level spell names.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_s2_il1",
  name = "UA illusionist 1st-level spell names",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_s2_il1RowCount",
      value = 5,
      comment = "the table rows" },
  },
  rows = {
    { name = "Color Spray",
      set = "ua_s2_il1",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Dancing Lights",
      set = "ua_s2_il1",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Darkness",
      set = "ua_s2_il1",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Hypnotism",
      set = "ua_s2_il1",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Phantasmal Force",
      set = "ua_s2_il1",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
