-- dressing table def: appendixa_gas
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VII.A gas (7 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_gas",
  name = "Appendix A Table VII.A gas (7 bands)",
  rows = {
    { name = "GAS_OBSCURE", set = "appendixa_gas", band = { 1, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "GAS_BLIND", set = "appendixa_gas", band = { 8, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "GAS_FEAR", set = "appendixa_gas", band = { 10, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "GAS_SLEEP", set = "appendixa_gas", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "GAS_STRENGTH", set = "appendixa_gas", band = { 14, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "GAS_SICKNESS", set = "appendixa_gas", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "GAS_POISON", set = "appendixa_gas", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_gasRowCount", value = 7 },
  },
  tables = {},
}
