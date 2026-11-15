-- ua_acrobat_retained
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA thief-acrobat retained skill names.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_acrobat_retained",
  name = "UA thief-acrobat retained skill names",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_acrobat_retainedRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "Move Silently",
      set = "ua_acrobat_retained",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Hide in Shadows",
      set = "ua_acrobat_retained",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Hear Noise",
      set = "ua_acrobat_retained",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Read Languages",
      set = "ua_acrobat_retained",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
