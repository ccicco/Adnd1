-- dressing table def: appendixa_turn
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table IV. turns (6 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_turn",
  name = "Appendix A Table IV. turns (6 bands)",
  rows = {
    { name = "T_L90", set = "appendixa_turn", band = { 1, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "T_L45_AHEAD", set = "appendixa_turn", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "T_L45_BEHIND", set = "appendixa_turn", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "T_R90", set = "appendixa_turn", band = { 11, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "T_R45_AHEAD", set = "appendixa_turn", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "T_R45_BEHIND", set = "appendixa_turn", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_turnRowCount", value = 6 },
  },
  tables = {},
}
