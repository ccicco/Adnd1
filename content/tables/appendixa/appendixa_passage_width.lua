-- dressing table def: appendixa_passage_width
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table III.A passage width (5 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- see the seam comment in dm/appendixa.h for this
-- shape's field map. The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_passage_width",
  name = "Appendix A Table III.A passage width (5 bands)",
  rows = {
    { name = "PW_10", set = "appendixa_passage_width", band = { 1, 12 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 0, 0 } },
    { name = "PW_20", set = "appendixa_passage_width", band = { 13, 16 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 0, qty = { 1, 0 } },
    { name = "PW_30", set = "appendixa_passage_width", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 30, gp_hi = 0, qty = { 2, 0 } },
    { name = "PW_5", set = "appendixa_passage_width", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 3, 0 } },
    { name = "PW_-1", set = "appendixa_passage_width", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = -1, gp_hi = 0, qty = { 4, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_passage_widthRowCount", value = 5 },
  },
  tables = {},
}
