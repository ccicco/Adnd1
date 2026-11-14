-- dressing table def: appendixa_chasm_feature
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table III.B chasm feature (3 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_chasm_feature",
  name = "Appendix A Table III.B chasm feature (3 bands)",
  rows = {
    { name = "CF_BRIDGED", set = "appendixa_chasm_feature", band = { 1, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "CF_JUMPING", set = "appendixa_chasm_feature", band = { 11, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "CF_OBSTACLE", set = "appendixa_chasm_feature", band = { 16, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_chasm_featureRowCount", value = 3 },
  },
  tables = {},
}
