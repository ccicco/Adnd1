-- dressing table def: appendixa_unusual_size
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.B unusual size (7 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- see the seam comment in dm/appendixa.h for this
-- shape's field map. The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_unusual_size",
  name = "Appendix A Table V.B unusual size (7 bands)",
  rows = {
    { name = "SIZE_500", set = "appendixa_unusual_size", band = { 1, 3 }, xp = 0, xp_hi = 0, gp = 500, gp_hi = 0, qty = { 0, 0 } },
    { name = "SIZE_900", set = "appendixa_unusual_size", band = { 4, 6 }, xp = 0, xp_hi = 0, gp = 900, gp_hi = 0, qty = { 1, 0 } },
    { name = "SIZE_1300", set = "appendixa_unusual_size", band = { 7, 8 }, xp = 0, xp_hi = 0, gp = 1300, gp_hi = 0, qty = { 2, 0 } },
    { name = "SIZE_2000", set = "appendixa_unusual_size", band = { 9, 10 }, xp = 0, xp_hi = 0, gp = 2000, gp_hi = 0, qty = { 3, 0 } },
    { name = "SIZE_2700", set = "appendixa_unusual_size", band = { 11, 12 }, xp = 0, xp_hi = 0, gp = 2700, gp_hi = 0, qty = { 4, 0 } },
    { name = "SIZE_3400", set = "appendixa_unusual_size", band = { 13, 14 }, xp = 0, xp_hi = 0, gp = 3400, gp_hi = 0, qty = { 5, 0 } },
    { name = "SIZE_-1", set = "appendixa_unusual_size", band = { 15, 20 }, xp = 0, xp_hi = 0, gp = -1, gp_hi = 0, qty = { 6, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_unusual_sizeRowCount", value = 7 },
  },
  tables = {},
}
