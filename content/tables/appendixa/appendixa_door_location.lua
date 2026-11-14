-- dressing table def: appendixa_door_location
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table II. door location (3 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_door_location",
  name = "Appendix A Table II. door location (3 bands)",
  rows = {
    { name = "DL_LEFT", set = "appendixa_door_location", band = { 1, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "DL_RIGHT", set = "appendixa_door_location", band = { 7, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "DL_AHEAD", set = "appendixa_door_location", band = { 13, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_door_locationRowCount", value = 3 },
  },
  tables = {},
}
