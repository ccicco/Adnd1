-- ua_uac5_golem_damage
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA lesser golem damage strings.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_golem_damage",
  name = "UA lesser golem damage strings",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_golem_damageRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "1-2/1-2",
      set = "ua_uac5_golem_damage",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "1-6 plus strangulation",
      set = "ua_uac5_golem_damage",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "1-6/1-6",
      set = "ua_uac5_golem_damage",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "3-12",
      set = "ua_uac5_golem_damage",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
