-- wsg_cyclone_drift_bands
-- The R1048 straggler de-wire. The WSG cyclone drift dispatch (2d6, 3 bands)
-- The accessor and the clamp semantics live in
-- the source header and are unchanged.
-- DO NOT hand-edit: tools/r1048_splice.py is
-- the only writer.

return {
  key = "wsg_cyclone_drift_bands",
  name = "The WSG cyclone drift dispatch (2d6, 3 bands)",
  rows = {
    { name = "DRIFT_COOLER", set = "wsg_cyclone_drift_bands", band = { 1, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "DRIFT_HOLD", set = "wsg_cyclone_drift_bands", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 0, 0 } },
    { name = "DRIFT_WARMER", set = "wsg_cyclone_drift_bands", band = { 8, 12 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1048 },
  },
  pins = {
    { name = "wsg_cyclone_drift_bandsRowCount", value = 3, comment = "the printed band count" },
  },
  tables = {},
}
