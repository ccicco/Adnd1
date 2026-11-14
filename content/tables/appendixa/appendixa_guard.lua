-- dressing table def: appendixa_guard
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.I guard (16 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_guard",
  name = "Appendix A Table V.I guard (16 bands)",
  rows = {
    { name = "G_CONTACT_POISON_CONTAINER", set = "appendixa_guard", band = { 1, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "G_CONTACT_POISON_TREASURE", set = "appendixa_guard", band = { 3, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "G_NEEDLES_LOCK", set = "appendixa_guard", band = { 5, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "G_NEEDLES_HANDLES", set = "appendixa_guard", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "G_DARTS_FRONT", set = "appendixa_guard", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "G_DARTS_TOP", set = "appendixa_guard", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "G_DARTS_BOTTOM", set = "appendixa_guard", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "G_BLADE_SCYTHE", set = "appendixa_guard", band = { 11, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
    { name = "G_CREATURES", set = "appendixa_guard", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 8, 0 } },
    { name = "G_GAS", set = "appendixa_guard", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 9, 0 } },
    { name = "G_TRAPDOOR_FRONT", set = "appendixa_guard", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 10, 0 } },
    { name = "G_TRAPDOOR_6FT", set = "appendixa_guard", band = { 16, 16 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 11, 0 } },
    { name = "G_STONE_BLOCK", set = "appendixa_guard", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 12, 0 } },
    { name = "G_SPEARS", set = "appendixa_guard", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 13, 0 } },
    { name = "G_EXPLOSIVE_RUNES", set = "appendixa_guard", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 14, 0 } },
    { name = "G_SYMBOL", set = "appendixa_guard", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 15, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_guardRowCount", value = 16 },
  },
  tables = {},
}
