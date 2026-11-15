-- ua_paladin
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA paladin cavalier abilities.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_paladin",
  name = "UA paladin cavalier abilities",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_paladinRowCount",
      value = 5,
      comment = "the table rows" },
  },
  rows = {
    { name = "weapons of choice",
      set = "ua_paladin",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "parrying ability",
      set = "ua_paladin",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "horsemanship",
      set = "ua_paladin",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "saving throw bonuses",
      set = "ua_paladin",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "immunity to fear",
      set = "ua_paladin",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
