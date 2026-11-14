-- dressing table def: appendixa_chamber_shape
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V chamber shape (7 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- see the seam comment in dm/appendixa.h for this
-- shape's field map. The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_chamber_shape",
  name = "Appendix A Table V chamber shape (7 bands)",
  rows = {
    { name = "CHS_20x20", set = "appendixa_chamber_shape", band = { 1, 4 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 20, qty = { 0, 0 } },
    { name = "CHS_30x30", set = "appendixa_chamber_shape", band = { 5, 6 }, xp = 0, xp_hi = 0, gp = 30, gp_hi = 30, qty = { 0, 1 } },
    { name = "CHS_40x40", set = "appendixa_chamber_shape", band = { 7, 8 }, xp = 0, xp_hi = 0, gp = 40, gp_hi = 40, qty = { 0, 2 } },
    { name = "CHS_20x30", set = "appendixa_chamber_shape", band = { 9, 13 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 30, qty = { 0, 3 } },
    { name = "CHS_30x50", set = "appendixa_chamber_shape", band = { 14, 15 }, xp = 0, xp_hi = 0, gp = 30, gp_hi = 50, qty = { 0, 4 } },
    { name = "CHS_40x60", set = "appendixa_chamber_shape", band = { 16, 17 }, xp = 0, xp_hi = 0, gp = 40, gp_hi = 60, qty = { 0, 5 } },
    { name = "CHS_UNUSUAL", set = "appendixa_chamber_shape", band = { 18, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 6 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_chamber_shapeRowCount", value = 7 },
  },
  tables = {},
}
