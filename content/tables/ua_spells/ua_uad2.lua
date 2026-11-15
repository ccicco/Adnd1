-- ua_uad2
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA reflecting pool cast-through spells.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uad2",
  name = "UA reflecting pool cast-through spells",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uad2RowCount",
      value = 3,
      comment = "the table rows" },
  },
  rows = {
    { name = "Detect Magic",
      set = "ua_uad2",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Detect Snares and Pits",
      set = "ua_uad2",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Detect Poison",
      set = "ua_uad2",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
