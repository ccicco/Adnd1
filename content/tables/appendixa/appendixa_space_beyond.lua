-- dressing table def: appendixa_space_beyond
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table II. space beyond (6 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_space_beyond",
  name = "Appendix A Table II. space beyond (6 bands)",
  rows = {
    { name = "SB_PARALLEL", set = "appendixa_space_beyond", band = { 1, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "SB_STRAIGHT_AHEAD", set = "appendixa_space_beyond", band = { 5, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "SB_45_AHEAD", set = "appendixa_space_beyond", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "SB_45_BEHIND", set = "appendixa_space_beyond", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "SB_ROOM", set = "appendixa_space_beyond", band = { 11, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "SB_CHAMBER", set = "appendixa_space_beyond", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_space_beyondRowCount", value = 6 },
  },
  tables = {},
}
