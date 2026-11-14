-- dressing table def: appendixa_stairs
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VI. stairs (12 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_stairs",
  name = "Appendix A Table VI. stairs (12 bands)",
  rows = {
    { name = "ST_DOWN1", set = "appendixa_stairs", band = { 1, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "ST_DOWN2", set = "appendixa_stairs", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "ST_DOWN3", set = "appendixa_stairs", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "ST_UP1", set = "appendixa_stairs", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "ST_UP_DEAD", set = "appendixa_stairs", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "ST_DOWN_DEAD", set = "appendixa_stairs", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "ST_CHIMNEY_UP1", set = "appendixa_stairs", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "ST_CHIMNEY_UP2", set = "appendixa_stairs", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
    { name = "ST_CHIMNEY_DOWN2", set = "appendixa_stairs", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 8, 0 } },
    { name = "ST_TRAPDOOR_DOWN1", set = "appendixa_stairs", band = { 14, 16 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 9, 0 } },
    { name = "ST_TRAPDOOR_DOWN2", set = "appendixa_stairs", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 10, 0 } },
    { name = "ST_UP1_DOWN2", set = "appendixa_stairs", band = { 18, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 11, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_stairsRowCount", value = 12 },
  },
  tables = {},
}
