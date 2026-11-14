-- dressing table def: appendixa_trick_trap
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table VII. trick/trap (15 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_trick_trap",
  name = "Appendix A Table VII. trick/trap (15 bands)",
  rows = {
    { name = "TT_SECRET_DOOR", set = "appendixa_trick_trap", band = { 1, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "TT_PIT", set = "appendixa_trick_trap", band = { 6, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "TT_PIT_SPIKED", set = "appendixa_trick_trap", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "TT_ELEVATOR_DOWN1", set = "appendixa_trick_trap", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "TT_ELEVATOR_DOWN2", set = "appendixa_trick_trap", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "TT_ELEVATOR_2TO5", set = "appendixa_trick_trap", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "TT_SLIDING_WALL", set = "appendixa_trick_trap", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "TT_OIL_CINDER", set = "appendixa_trick_trap", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
    { name = "TT_PIT_CRUSHING", set = "appendixa_trick_trap", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 8, 0 } },
    { name = "TT_ARROW_TRAP", set = "appendixa_trick_trap", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 9, 0 } },
    { name = "TT_SPEAR_TRAP", set = "appendixa_trick_trap", band = { 16, 16 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 10, 0 } },
    { name = "TT_GAS", set = "appendixa_trick_trap", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 11, 0 } },
    { name = "TT_FALLING_DOOR_STONE", set = "appendixa_trick_trap", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 12, 0 } },
    { name = "TT_ILLUSIONARY_WALL", set = "appendixa_trick_trap", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 13, 0 } },
    { name = "TT_CHUTE", set = "appendixa_trick_trap", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 14, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_trick_trapRowCount", value = 15 },
  },
  tables = {},
}
