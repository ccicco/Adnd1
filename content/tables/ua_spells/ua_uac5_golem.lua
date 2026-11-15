-- ua_uac5_golem
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA lesser golem materials and combat cells.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uac5_golem",
  name = "UA lesser golem materials and combat cells",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uac5_golemRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "straw",
      set = "ua_uac5_golem",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "rope",
      set = "ua_uac5_golem",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "leather",
      set = "ua_uac5_golem",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "wood",
      set = "ua_uac5_golem",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "ac",
      values = {
        10, 8, 6, 4, 
      },
      comment = "the UA lesser golem materials and combat cells ac column" },
    { name = "at",
      values = {
        2, 1, 2, 1, 
      },
      comment = "the UA lesser golem materials and combat cells at column" },
    { name = "build_hours",
      values = {
        1, 3, 9, 27, 
      },
      comment = "the UA lesser golem materials and combat cells build_hours column" },
    { name = "carry_pounds",
      values = {
        30, 40, 50, 60, 
      },
      comment = "the UA lesser golem materials and combat cells carry_pounds column" },
    { name = "dur_hours",
      values = {
        1, 3, 6, 12, 
      },
      comment = "the UA lesser golem materials and combat cells dur_hours column" },
    { name = "hd_base",
      values = {
        2, 3, 4, 5, 
      },
      comment = "the UA lesser golem materials and combat cells hd_base column" },
    { name = "hd_bonus",
      values = {
        4, 6, 8, 10, 
      },
      comment = "the UA lesser golem materials and combat cells hd_bonus column" },
    { name = "hp",
      values = {
        20, 30, 40, 50, 
      },
      comment = "the UA lesser golem materials and combat cells hp column" },
    { name = "min_level",
      values = {
        9, 11, 13, 15, 
      },
      comment = "the UA lesser golem materials and combat cells min_level column" },
    { name = "mv",
      values = {
        12, 9, 6, 3, 
      },
      comment = "the UA lesser golem materials and combat cells mv column" },
  },
}
