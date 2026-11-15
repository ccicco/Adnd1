-- ua_cavmoney_entry
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA cavalier money station entry labels.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_cavmoney_entry",
  name = "UA cavalier money station entry labels",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_cavmoney_entryRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "Horseman",
      set = "ua_cavmoney_entry",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Horseman",
      set = "ua_cavmoney_entry",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Horseman",
      set = "ua_cavmoney_entry",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Cavalier",
      set = "ua_cavmoney_entry",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Cavalier",
      set = "ua_cavmoney_entry",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Cavalier",
      set = "ua_cavmoney_entry",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
