-- dressing table def: appendixa_container
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.H container (10 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_container",
  name = "Appendix A Table V.H container (10 bands)",
  rows = {
    { name = "C_BAGS", set = "appendixa_container", band = { 1, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "C_SACKS", set = "appendixa_container", band = { 3, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "C_SMALL_COFFERS", set = "appendixa_container", band = { 5, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "C_CHESTS", set = "appendixa_container", band = { 7, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "C_HUGE_CHESTS", set = "appendixa_container", band = { 9, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "C_POTTERY_JARS", set = "appendixa_container", band = { 11, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "C_METAL_URNS", set = "appendixa_container", band = { 13, 14 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "C_STONE_CONTAINERS", set = "appendixa_container", band = { 15, 16 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
    { name = "C_IRON_TRUNKS", set = "appendixa_container", band = { 17, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 8, 0 } },
    { name = "C_LOOSE", set = "appendixa_container", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 9, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_containerRowCount", value = 10 },
  },
  tables = {},
}
