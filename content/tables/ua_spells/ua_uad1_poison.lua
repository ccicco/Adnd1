-- ua_uad1_poison
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA detect poison types.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uad1_poison",
  name = "UA detect poison types",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uad1_poisonRowCount",
      value = 3,
      comment = "the table rows" },
  },
  rows = {
    { name = "Contact (Insinuative)",
      set = "ua_uad1_poison",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Ingestive",
      set = "ua_uad1_poison",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Respirative (Gas)",
      set = "ua_uad1_poison",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
