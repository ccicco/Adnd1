-- dressing table def: appendixa_exits
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.C number of exits (7 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- see the seam comment in dm/appendixa.h for this
-- shape's field map. The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_exits",
  name = "Appendix A Table V.C number of exits (7 bands)",
  rows = {
    { name = "EXITS_1", set = "appendixa_exits", band = { 1, 3 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 2, qty = { 0, 0 } },
    { name = "EXITS_2", set = "appendixa_exits", band = { 4, 6 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 3, qty = { 1, 0 } },
    { name = "EXITS_3", set = "appendixa_exits", band = { 7, 9 }, xp = 0, xp_hi = 0, gp = 3, gp_hi = 4, qty = { 2, 0 } },
    { name = "EXITS_4", set = "appendixa_exits", band = { 10, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 1, qty = { 3, 0 } },
    { name = "EXITS_5", set = "appendixa_exits", band = { 13, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 1, qty = { 4, 0 } },
    { name = "EXITS_6", set = "appendixa_exits", band = { 16, 18 }, xp = 0, xp_hi = 0, gp = -1, gp_hi = -1, qty = { 5, 0 } },
    { name = "EXITS_7", set = "appendixa_exits", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 1, qty = { 6, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_exitsRowCount", value = 7 },
  },
  tables = {},
}
