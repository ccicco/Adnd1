-- ua_hierophant_special
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA hierophant para-elemental special roster.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_hierophant_special",
  name = "UA hierophant para-elemental special roster",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_hierophant_specialRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "5-8 lava children",
      set = "ua_hierophant_special",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "5-8 winter wolves",
      set = "ua_hierophant_special",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "21-24 mudmen",
      set = "ua_hierophant_special",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "21-24 vapor rats",
      set = "ua_hierophant_special",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
