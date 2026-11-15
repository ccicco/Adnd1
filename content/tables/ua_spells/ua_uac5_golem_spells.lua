-- ua_uac5_golem_spells
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA lesser golem mindless spell examples.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_golem_spells",
  name = "UA lesser golem mindless spell examples",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_golem_spellsRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "charm",
      set = "ua_uac5_golem_spells",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "fear",
      set = "ua_uac5_golem_spells",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "hold",
      set = "ua_uac5_golem_spells",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "sleep",
      set = "ua_uac5_golem_spells",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
