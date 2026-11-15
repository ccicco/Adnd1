-- ua_s2_il7
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA illusionist 7th-level spell names.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_s2_il7",
  name = "UA illusionist 7th-level spell names",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_s2_il7RowCount",
      value = 1,
      comment = "the table rows" },
  },
  rows = {
    { name = "Shadow Walk",
      set = "ua_s2_il7",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
