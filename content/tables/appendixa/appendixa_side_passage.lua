-- dressing table def: appendixa_side_passage
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table III. side passages (12 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_side_passage",
  name = "Appendix A Table III. side passages (12 bands)",
  rows = {
    { name = "SP_L90", set = "appendixa_side_passage", band = { 1, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "SP_R90", set = "appendixa_side_passage", band = { 3, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "SP_L45_AHEAD", set = "appendixa_side_passage", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "SP_R45_AHEAD", set = "appendixa_side_passage", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "SP_L45_BEHIND", set = "appendixa_side_passage", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "SP_R45_BEHIND", set = "appendixa_side_passage", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "SP_L_CURVE", set = "appendixa_side_passage", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "SP_R_CURVE", set = "appendixa_side_passage", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
    { name = "SP_T", set = "appendixa_side_passage", band = { 11, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 8, 0 } },
    { name = "SP_Y", set = "appendixa_side_passage", band = { 14, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 9, 0 } },
    { name = "SP_FOURWAY", set = "appendixa_side_passage", band = { 16, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 10, 0 } },
    { name = "SP_X", set = "appendixa_side_passage", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 11, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_side_passageRowCount", value = 12 },
  },
  tables = {},
}
