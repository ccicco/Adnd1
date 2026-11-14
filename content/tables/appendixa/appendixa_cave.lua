-- dressing table def: appendixa_cave
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VIII. caves (8 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- see the seam comment in dm/appendixa.h for this
-- shape's field map. The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_cave",
  name = "Appendix A Table VIII. caves (8 bands)",
  rows = {
    { name = "CAVE_1", set = "appendixa_cave", band = { 1, 5 }, xp = 0, xp_hi = 0, gp = 40, gp_hi = 60, qty = { 0, 0 } },
    { name = "CAVE_2", set = "appendixa_cave", band = { 6, 7 }, xp = 0, xp_hi = 0, gp = 50, gp_hi = 75, qty = { 0, 0 } },
    { name = "CAVE_3", set = "appendixa_cave", band = { 8, 9 }, xp = 60, xp_hi = 60, gp = 20, gp_hi = 30, qty = { 0, 0 } },
    { name = "CAVE_4", set = "appendixa_cave", band = { 10, 11 }, xp = 80, xp_hi = 90, gp = 35, gp_hi = 50, qty = { 1, 0 } },
    { name = "CAVE_5", set = "appendixa_cave", band = { 12, 14 }, xp = 0, xp_hi = 0, gp = 95, gp_hi = 125, qty = { 1, 0 } },
    { name = "CAVE_6", set = "appendixa_cave", band = { 15, 16 }, xp = 0, xp_hi = 0, gp = 120, gp_hi = 150, qty = { 0, 0 } },
    { name = "CAVE_7", set = "appendixa_cave", band = { 17, 18 }, xp = 0, xp_hi = 0, gp = 150, gp_hi = 200, qty = { 1, 0 } },
    { name = "CAVE_8", set = "appendixa_cave", band = { 19, 20 }, xp = 0, xp_hi = 0, gp = 275, gp_hi = 375, qty = { 0, 1 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_caveRowCount", value = 8 },
  },
  tables = {},
}
