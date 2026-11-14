-- dressing table def: appendixi_air_currents
-- The DMG Appendix I dressing bands, the R1045 de-wire. Appendix I air currents (14 bands)
-- Row encoding: name = the enum tag at the row index
-- (dm/appendixi.h), band = { lo, hi } the printed
-- percentile band (the 00 band is 100). The accessor,
-- the 00-fold and the clamp semantics live in
-- dm/appendixi.h and are unchanged.
-- DO NOT hand-edit: tools/r1045_splice.py is the only writer.

return {
  key = "appendixi_air_currents",
  name = "Appendix I air currents (14 bands)",
  rows = {
    { name = "AC_BREEZE_SLIGHT", set = "appendixi_air_currents", band = { 1, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_BREEZE_SLIGHT_DAMP", set = "appendixi_air_currents", band = { 6, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_BREEZE_GUSTING", set = "appendixi_air_currents", band = { 11, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_COLD_CURRENT", set = "appendixi_air_currents", band = { 13, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_DOWNDRAFT_SLIGHT", set = "appendixi_air_currents", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_DOWNDRAFT_STRONG", set = "appendixi_air_currents", band = { 21, 22 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_STILL", set = "appendixi_air_currents", band = { 23, 69 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_STILL_VERY_CHILL", set = "appendixi_air_currents", band = { 70, 75 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_STILL_WARM", set = "appendixi_air_currents", band = { 76, 85 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_UPDRAFT_SLIGHT", set = "appendixi_air_currents", band = { 86, 87 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_UPDRAFT_STRONG", set = "appendixi_air_currents", band = { 88, 89 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_WIND_STRONG", set = "appendixi_air_currents", band = { 90, 93 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_WIND_STRONG_GUSTING", set = "appendixi_air_currents", band = { 94, 95 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "AC_WIND_STRONG_MOANING", set = "appendixi_air_currents", band = { 96, 100 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1045 },
  },
  pins = {
    { name = "appendixi_air_currentsRowCount", value = 14, comment = "the printed band count" },
  },
  tables = {},
}
