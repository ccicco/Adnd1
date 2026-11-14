-- dressing table def: appendixa_room_shape
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V room shape (9 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- see the seam comment in dm/appendixa.h for this
-- shape's field map. The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_room_shape",
  name = "Appendix A Table V room shape (9 bands)",
  rows = {
    { name = "RMS_10x10", set = "appendixa_room_shape", band = { 1, 2 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 10, qty = { 0, 0 } },
    { name = "RMS_20x20", set = "appendixa_room_shape", band = { 3, 4 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 20, qty = { 0, 1 } },
    { name = "RMS_30x30", set = "appendixa_room_shape", band = { 5, 6 }, xp = 0, xp_hi = 0, gp = 30, gp_hi = 30, qty = { 0, 2 } },
    { name = "RMS_40x40", set = "appendixa_room_shape", band = { 7, 8 }, xp = 0, xp_hi = 0, gp = 40, gp_hi = 40, qty = { 0, 3 } },
    { name = "RMS_10x20", set = "appendixa_room_shape", band = { 9, 10 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 20, qty = { 0, 4 } },
    { name = "RMS_20x30", set = "appendixa_room_shape", band = { 11, 13 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 30, qty = { 0, 5 } },
    { name = "RMS_20x40", set = "appendixa_room_shape", band = { 14, 15 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 40, qty = { 0, 6 } },
    { name = "RMS_30x40", set = "appendixa_room_shape", band = { 16, 17 }, xp = 0, xp_hi = 0, gp = 30, gp_hi = 40, qty = { 0, 7 } },
    { name = "RMS_BLANK", set = "appendixa_room_shape", band = { 18, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 8 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_room_shapeRowCount", value = 9 },
  },
  tables = {},
}
