-- dressing table def: appendixa_lake
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VIII.B lakes (4 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_lake",
  name = "Appendix A Table VIII.B lakes (4 bands)",
  rows = {
    { name = "LAKE_NONE", set = "appendixa_lake", band = { 1, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "LAKE_NO_MONSTERS", set = "appendixa_lake", band = { 11, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "LAKE_MONSTERS", set = "appendixa_lake", band = { 16, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "LAKE_ENCHANTED", set = "appendixa_lake", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_lakeRowCount", value = 4 },
  },
  tables = {},
}
