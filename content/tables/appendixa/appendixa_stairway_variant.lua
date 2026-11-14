-- dressing table def: appendixa_stairway_variant
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.F stairway variant (5 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_stairway_variant",
  name = "Appendix A Table V.F stairway variant (5 bands)",
  rows = {
    { name = "SV_UP1", set = "appendixa_stairway_variant", band = { 1, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "SV_UP2", set = "appendixa_stairway_variant", band = { 7, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "SV_DOWN1", set = "appendixa_stairway_variant", band = { 9, 14 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "SV_DOWN2", set = "appendixa_stairway_variant", band = { 15, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "SV_DOWN3", set = "appendixa_stairway_variant", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_stairway_variantRowCount", value = 5 },
  },
  tables = {},
}
