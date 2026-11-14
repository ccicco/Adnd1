-- dressing table def: appendixa_periodic_check
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table I. periodic check (9 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_periodic_check",
  name = "Appendix A Table I. periodic check (9 bands)",
  rows = {
    { name = "PC_STRAIGHT", set = "appendixa_periodic_check", band = { 1, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "PC_DOOR", set = "appendixa_periodic_check", band = { 3, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "PC_SIDE", set = "appendixa_periodic_check", band = { 6, 10 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "PC_TURN", set = "appendixa_periodic_check", band = { 11, 13 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
    { name = "PC_CHAMBER", set = "appendixa_periodic_check", band = { 14, 16 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "PC_STAIRS", set = "appendixa_periodic_check", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "PC_DEAD_END", set = "appendixa_periodic_check", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 6, 0 } },
    { name = "PC_TRICK_TRAP", set = "appendixa_periodic_check", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 7, 0 } },
    { name = "PC_WANDERER", set = "appendixa_periodic_check", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 8, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_periodic_checkRowCount", value = 9 },
  },
  tables = {},
}
