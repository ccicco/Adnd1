-- dressing table def: appendixi_air_states
-- The DMG Appendix I dressing bands, the R1045 de-wire. Appendix I air (6 bands)
-- Row encoding: name = the enum tag at the row index
-- (dm/appendixi.h), band = { lo, hi } the printed
-- percentile band (the 00 band is 100). The accessor,
-- the 00-fold and the clamp semantics live in
-- dm/appendixi.h and are unchanged.
-- DO NOT hand-edit: tools/r1045_splice.py is the only writer.

return {
  key = "appendixi_air_states",
  name = "Appendix I air (6 bands)",
  rows = {
    { name = "AIR_CLEAR", set = "appendixi_air_states", band = { 1, 70 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AIR_FOGGY", set = "appendixi_air_states", band = { 71, 80 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AIR_FOGGY_NEAR_FLOOR", set = "appendixi_air_states", band = { 81, 88 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AIR_HAZY_DUST", set = "appendixi_air_states", band = { 89, 90 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AIR_HAZY_SMOKE", set = "appendixi_air_states", band = { 91, 98 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AIR_MISTED", set = "appendixi_air_states", band = { 99, 100 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1045 },
  },
  pins = {
    { name = "appendixi_air_statesRowCount", value = 6, comment = "the printed band count" },
  },
  tables = {},
}
