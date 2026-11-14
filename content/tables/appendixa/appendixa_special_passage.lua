-- dressing table def: appendixa_special_passage
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table III.B special passage (9 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_special_passage",
  name = "Appendix A Table III.B special passage (9 bands)",
  rows = {
    { name = "SPEC_COLUMNS_CENTER", set = "appendixa_special_passage", band = { 1, 4 }, xp = 0, xp_hi = 0, gp = 40, gp_hi = 0, qty = { 0, 0 } },
    { name = "SPEC_COLUMNS_DOUBLE", set = "appendixa_special_passage", band = { 5, 7 }, xp = 0, xp_hi = 0, gp = 40, gp_hi = 0, qty = { 1, 0 } },
    { name = "SPEC_COLUMNS_DOUBLE", set = "appendixa_special_passage", band = { 8, 10 }, xp = 0, xp_hi = 0, gp = 50, gp_hi = 0, qty = { 1, 0 } },
    { name = "SPEC_COLUMNS_GALLERIES", set = "appendixa_special_passage", band = { 11, 12 }, xp = 0, xp_hi = 0, gp = 50, gp_hi = 0, qty = { 2, 0 } },
    { name = "SPEC_STREAM", set = "appendixa_special_passage", band = { 13, 15 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 3, 0 } },
    { name = "SPEC_RIVER", set = "appendixa_special_passage", band = { 16, 17 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 0, qty = { 4, 0 } },
    { name = "SPEC_RIVER", set = "appendixa_special_passage", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 40, gp_hi = 0, qty = { 4, 0 } },
    { name = "SPEC_RIVER", set = "appendixa_special_passage", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 60, gp_hi = 0, qty = { 4, 0 } },
    { name = "SPEC_CHASM", set = "appendixa_special_passage", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 0, qty = { 5, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_special_passageRowCount", value = 9 },
  },
  tables = {},
}
