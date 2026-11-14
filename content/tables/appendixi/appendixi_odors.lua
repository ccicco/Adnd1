-- dressing table def: appendixi_odors
-- The DMG Appendix I dressing bands, the R1045 de-wire. Appendix I odors (14 bands)
-- Row encoding: name = the enum tag at the row index
-- (dm/appendixi.h), band = { lo, hi } the printed
-- percentile band (the 00 band is 100). The accessor,
-- the 00-fold and the clamp semantics live in
-- dm/appendixi.h and are unchanged.
-- DO NOT hand-edit: tools/r1045_splice.py is the only writer.

return {
  key = "appendixi_odors",
  name = "Appendix I odors (14 bands)",
  rows = {
    { name = "OD_ACRID", set = "appendixi_odors", band = { 1, 3 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_CHLORINE", set = "appendixi_odors", band = { 4, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_DANK_MOULDY", set = "appendixi_odors", band = { 6, 39 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_EARTHY", set = "appendixi_odors", band = { 40, 49 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_MANURE", set = "appendixi_odors", band = { 50, 57 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_METALLIC", set = "appendixi_odors", band = { 58, 61 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_OZONE", set = "appendixi_odors", band = { 62, 65 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_PUTRID", set = "appendixi_odors", band = { 66, 70 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_ROTTING_VEGETATION", set = "appendixi_odors", band = { 71, 75 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_SALTY_WET", set = "appendixi_odors", band = { 76, 77 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_SMOKY", set = "appendixi_odors", band = { 78, 82 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_STALE_FETID", set = "appendixi_odors", band = { 83, 89 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_SULPHUROUS", set = "appendixi_odors", band = { 90, 95 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "OD_URINE", set = "appendixi_odors", band = { 96, 100 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1045 },
  },
  pins = {
    { name = "appendixi_odorsRowCount", value = 14, comment = "the printed band count" },
  },
  tables = {},
}
