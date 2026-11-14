-- dressing table def: appendixa_treasure
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.G treasure (8 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_treasure",
  name = "Appendix A Table V.G treasure (8 bands)",
  rows = {
    { name = "TR_CP", set = "appendixa_treasure", band = { 1, 25 }, xp = 0, xp_hi = 0, gp = 1000, gp_hi = 0, qty = { 0, 0 } },
    { name = "TR_SP", set = "appendixa_treasure", band = { 26, 50 }, xp = 0, xp_hi = 0, gp = 1000, gp_hi = 0, qty = { 1, 0 } },
    { name = "TR_EP", set = "appendixa_treasure", band = { 51, 65 }, xp = 0, xp_hi = 0, gp = 750, gp_hi = 0, qty = { 2, 0 } },
    { name = "TR_GP", set = "appendixa_treasure", band = { 66, 80 }, xp = 0, xp_hi = 0, gp = 250, gp_hi = 0, qty = { 3, 0 } },
    { name = "TR_PP", set = "appendixa_treasure", band = { 81, 90 }, xp = 0, xp_hi = 0, gp = 100, gp_hi = 0, qty = { 4, 0 } },
    { name = "TR_GEMS", set = "appendixa_treasure", band = { 91, 94 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 5, 0 } },
    { name = "TR_JEWELRY", set = "appendixa_treasure", band = { 95, 97 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 6, 0 } },
    { name = "TR_MAGIC", set = "appendixa_treasure", band = { 98, 100 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_treasureRowCount", value = 8 },
  },
  tables = {},
}
