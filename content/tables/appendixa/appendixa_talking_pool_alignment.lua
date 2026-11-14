-- dressing table def: appendixa_talking_pool_alignment
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VIII.C pool alignment (5 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_talking_pool_alignment",
  name = "Appendix A Table VIII.C pool alignment (5 bands)",
  rows = {
    { name = "PA_LAWFUL_GOOD", set = "appendixa_talking_pool_alignment", band = { 1, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "PA_LAWFUL_EVIL", set = "appendixa_talking_pool_alignment", band = { 7, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "PA_CHAOTIC_GOOD", set = "appendixa_talking_pool_alignment", band = { 10, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "PA_CHAOTIC_EVIL", set = "appendixa_talking_pool_alignment", band = { 13, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "PA_NEUTRAL", set = "appendixa_talking_pool_alignment", band = { 18, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_talking_pool_alignmentRowCount", value = 5 },
  },
  tables = {},
}
