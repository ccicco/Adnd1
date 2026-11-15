-- ua_ast_cantrip_cat
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA magic-user cantrip categories.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_ast_cantrip_cat",
  name = "UA magic-user cantrip categories",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_ast_cantrip_catRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "Useful",
      set = "ua_ast_cantrip_cat",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Reversed",
      set = "ua_ast_cantrip_cat",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Legerdemain",
      set = "ua_ast_cantrip_cat",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Person-Affecting",
      set = "ua_ast_cantrip_cat",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Personal",
      set = "ua_ast_cantrip_cat",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Haunting",
      set = "ua_ast_cantrip_cat",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "cantrip_count",
      values = {
        20, 12, 6, 10, 10, 8, 
      },
      comment = "the UA magic-user cantrip categories cantrip_count column; banded reads index arg - 0" },
  },
}
