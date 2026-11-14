-- dressing table def: appendixa_magic_pool
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VIII.C magic pools (4 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_magic_pool",
  name = "Appendix A Table VIII.C magic pools (4 bands)",
  rows = {
    { name = "MP_GOLD_TO_PLATINUM_LEAD", set = "appendixa_magic_pool", band = { 1, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "MP_CHARACTERISTIC", set = "appendixa_magic_pool", band = { 9, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "MP_TALKING", set = "appendixa_magic_pool", band = { 16, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "MP_TRANSPORTER", set = "appendixa_magic_pool", band = { 18, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_magic_poolRowCount", value = 4 },
  },
  tables = {},
}
