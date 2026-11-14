-- dressing table def: appendixa_room_contents
-- The DMG Appendix A dungeon dressing bands, the R1046 de-wire.
-- Appendix A Table V.F room contents (6 bands).
-- Row encoding: the R1046 shape convention (name the
-- enum tag or the synthetic tag, band the printed
-- roll band, and the shape payload in gp/gpHi/xp/xpHi/qty;
-- qty[1] the enum ordinal, never the row index
-- (cascade order is not enum order). The accessor
-- and the fall-through semantics live in dm/appendixa.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1046_splice.py is the only writer.

return {
  key = "appendixa_room_contents",
  name = "Appendix A Table V.F room contents (6 bands)",
  rows = {
    { name = "ROOM_EMPTY", set = "appendixa_room_contents", band = { 1, 12 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "ROOM_MONSTER", set = "appendixa_room_contents", band = { 13, 14 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 1, 0 } },
    { name = "ROOM_MONSTER_TREASURE", set = "appendixa_room_contents", band = { 15, 17 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 2, 0 } },
    { name = "ROOM_SPECIAL", set = "appendixa_room_contents", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 4, 0 } },
    { name = "ROOM_TRAP", set = "appendixa_room_contents", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 5, 0 } },
    { name = "ROOM_TREASURE", set = "appendixa_room_contents", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 3, 0 } },
  },
  sources = {
    { part = 0, round = 1046 },
  },
  pins = { { name = "appendixa_room_contentsRowCount", value = 6 },
  },
  tables = {},
}
