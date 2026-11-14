-- dressing table def: appendixa_pool
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VIII.A pools (5 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_pool",
  name = "Appendix A Table VIII.A pools (5 bands)",
  rows = {
    { name = "POOL_NONE", set = "appendixa_pool", band = { 1, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "POOL_NO_MONSTER", set = "appendixa_pool", band = { 9, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "POOL_MONSTER", set = "appendixa_pool", band = { 11, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "POOL_MONSTER_TREASURE", set = "appendixa_pool", band = { 13, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "POOL_MAGICAL", set = "appendixa_pool", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_poolRowCount", value = 5 },
  },
  tables = {},
}
