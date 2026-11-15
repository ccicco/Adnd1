-- ua_uac5_golem_sd
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA lesser golem special defense strings.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_golem_sd",
  name = "UA lesser golem special defense strings",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_golem_sdRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "immune to piercing, half from blunt",
      set = "ua_uac5_golem_sd",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "immune to blunt, half from piercing",
      set = "ua_uac5_golem_sd",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "+1 or better weapon, half from blunt",
      set = "ua_uac5_golem_sd",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "+1 or better weapon, immune to blunt and piercing",
      set = "ua_uac5_golem_sd",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
