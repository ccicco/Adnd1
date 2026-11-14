-- dressing table def: appendixa_unusual_shape
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.A unusual shape (8 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_unusual_shape",
  name = "Appendix A Table V.A unusual shape (8 bands)",
  rows = {
    { name = "US_CIRCULAR", set = "appendixa_unusual_shape", band = { 1, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "US_TRIANGULAR", set = "appendixa_unusual_shape", band = { 6, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "US_TRAPEZOIDAL", set = "appendixa_unusual_shape", band = { 9, 11 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "US_ODD", set = "appendixa_unusual_shape", band = { 12, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "US_OVAL", set = "appendixa_unusual_shape", band = { 14, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "US_HEXAGONAL", set = "appendixa_unusual_shape", band = { 16, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "US_OCTAGONAL", set = "appendixa_unusual_shape", band = { 18, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "US_CAVE", set = "appendixa_unusual_shape", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_unusual_shapeRowCount", value = 8 },
  },
  tables = {},
}
