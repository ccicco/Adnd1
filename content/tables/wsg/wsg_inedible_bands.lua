-- wsg_inedible_bands
-- The R1048 straggler de-wire. The WSG inedible-plant dispatch (1d8, 3 bands)
-- The accessor and the clamp semantics live in
-- the source header and are unchanged.
-- DO NOT hand-edit: tools/r1048_splice.py is
-- the only writer.

return {
  key = "wsg_inedible_bands",
  name = "The WSG inedible-plant dispatch (1d8, 3 bands)",
  rows = {
    { name = "INED_POISONOUS", set = "wsg_inedible_bands", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "INED_TAINTED", set = "wsg_inedible_bands", band = { 2, 4 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 0, 0 } },
    { name = "INED_NO_FOOD_VALUE", set = "wsg_inedible_bands", band = { 5, 8 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1048 },
  },
  pins = {
    { name = "wsg_inedible_bandsRowCount", value = 3, comment = "the printed band count" },
  },
  tables = {},
}
