-- dressing table def: appendixa_transport_dest
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VIII.C transport dest (4 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_transport_dest",
  name = "Appendix A Table VIII.C transport dest (4 bands)",
  rows = {
    { name = "TD_SURFACE", set = "appendixa_transport_dest", band = { 1, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "TD_ELSEWHERE_LEVEL", set = "appendixa_transport_dest", band = { 8, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "TD_ONE_DOWN", set = "appendixa_transport_dest", band = { 13, 16 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "TD_100_MILES", set = "appendixa_transport_dest", band = { 17, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_transport_destRowCount", value = 4 },
  },
  tables = {},
}
