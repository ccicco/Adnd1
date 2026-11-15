-- ua_uac5_rainbow_bow_targets
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA rainbow bow color targets.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_rainbow_bow_targets",
  name = "UA rainbow bow color targets",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_rainbow_bow_targetsRowCount",
      value = 7,
      comment = "the table rows" },
  },
  rows = {
    { name = "fire dwellers/users",
      set = "ua_uac5_rainbow_bow_targets",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "earth elementals",
      set = "ua_uac5_rainbow_bow_targets",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "vegetable targets (incl. fungus creatures, shambling mounds, treants)",
      set = "ua_uac5_rainbow_bow_targets",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "aquatic creatures and water elementals",
      set = "ua_uac5_rainbow_bow_targets",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "aerial creatures, electricity-using creatures, and air elementals",
      set = "ua_uac5_rainbow_bow_targets",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "acid-using or poison-using creatures",
      set = "ua_uac5_rainbow_bow_targets",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "metallic or regenerating creatures",
      set = "ua_uac5_rainbow_bow_targets",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
