-- ua_ast_druid4
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA druid 4th-level spell names.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_ast_druid4",
  name = "UA druid 4th-level spell names",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_ast_druid4RowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "Cure Serious Wounds",
      set = "ua_ast_druid4",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Dispel Magic",
      set = "ua_ast_druid4",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Hallucinatory Forest",
      set = "ua_ast_druid4",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Protection From Lightning",
      set = "ua_ast_druid4",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Repel Insects",
      set = "ua_ast_druid4",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Speak With Plants",
      set = "ua_ast_druid4",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
