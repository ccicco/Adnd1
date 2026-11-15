-- ua_uch
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA haunting-sound cantrips.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uch",
  name = "UA haunting-sound cantrips",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uchRowCount",
      value = 8,
      comment = "the table rows" },
  },
  rows = {
    { name = "Creak",
      set = "ua_uch",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Footfall",
      set = "ua_uch",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Groan",
      set = "ua_uch",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Moan",
      set = "ua_uch",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Rattle",
      set = "ua_uch",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Tap",
      set = "ua_uch",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Thump",
      set = "ua_uch",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Whistle",
      set = "ua_uch",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "cast_den",
      values = {
        6, 6, 6, 10, 10, 6, 10, 6, 
      },
      comment = "the UA haunting-sound cantrips cast_den column" },
  },
}
