-- ua_ast_druid6
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA druid 6th-level spell names.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_ast_druid6",
  name = "UA druid 6th-level spell names",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_ast_druid6RowCount",
      value = 5,
      comment = "the table rows" },
  },
  rows = {
    { name = "Cure Critical Wounds",
      set = "ua_ast_druid6",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Fire Seeds",
      set = "ua_ast_druid6",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Turn Wood",
      set = "ua_ast_druid6",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Wall Of Thorns",
      set = "ua_ast_druid6",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Weather Summoning",
      set = "ua_ast_druid6",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
