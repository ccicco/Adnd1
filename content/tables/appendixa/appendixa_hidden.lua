-- dressing table def: appendixa_hidden
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.J hidden (10 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_hidden",
  name = "Appendix A Table V.J hidden (10 bands)",
  rows = {
    { name = "H_INVISIBILITY", set = "appendixa_hidden", band = { 1, 3 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "H_ILLUSION", set = "appendixa_hidden", band = { 4, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "H_SECRET_SPACE_UNDER", set = "appendixa_hidden", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "H_SECRET_COMPARTMENT", set = "appendixa_hidden", band = { 7, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "H_ORDINARY_ITEM", set = "appendixa_hidden", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "H_DISGUISED", set = "appendixa_hidden", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "H_TRASH_DUNG", set = "appendixa_hidden", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "H_LOOSE_FLOOR_STONE", set = "appendixa_hidden", band = { 12, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
    { name = "H_LOOSE_WALL_STONE", set = "appendixa_hidden", band = { 14, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 8, 0 } },
    { name = "H_SECRET_ROOM", set = "appendixa_hidden", band = { 16, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 9, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_hiddenRowCount", value = 10 },
  },
  tables = {},
}
