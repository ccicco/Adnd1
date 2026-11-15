-- ua_uac5_rainbow_flagon_effects
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA rainbow flagon draught effects.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_rainbow_flagon_effects",
  name = "UA rainbow flagon draught effects",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_rainbow_flagon_effectsRowCount",
      value = 7,
      comment = "the table rows" },
  },
  rows = {
    { name = "cure light wounds",
      set = "ua_uac5_rainbow_flagon_effects",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "resist fire",
      set = "ua_uac5_rainbow_flagon_effects",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "cure blindness",
      set = "ua_uac5_rainbow_flagon_effects",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "slow poison",
      set = "ua_uac5_rainbow_flagon_effects",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "cure disease",
      set = "ua_uac5_rainbow_flagon_effects",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "resist cold",
      set = "ua_uac5_rainbow_flagon_effects",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "remove paralysis",
      set = "ua_uac5_rainbow_flagon_effects",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
