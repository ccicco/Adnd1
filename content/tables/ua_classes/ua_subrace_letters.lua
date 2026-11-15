-- ua_subrace_letters
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA racial preference letters.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_subrace_letters",
  name = "UA racial preference letters",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_subrace_lettersRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "P",
      set = "ua_subrace_letters",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "G",
      set = "ua_subrace_letters",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "T",
      set = "ua_subrace_letters",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "N",
      set = "ua_subrace_letters",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "A",
      set = "ua_subrace_letters",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "H",
      set = "ua_subrace_letters",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
