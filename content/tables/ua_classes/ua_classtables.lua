-- ua_classtables
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA acrobat extra weapons.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_classtables",
  name = "UA acrobat extra weapons",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_classtablesRowCount",
      value = 2,
      comment = "the table rows" },
  },
  rows = {
    { name = "lasso",
      set = "ua_classtables",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "staff",
      set = "ua_classtables",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
