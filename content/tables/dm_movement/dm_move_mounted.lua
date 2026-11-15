-- dm_move_mounted
-- The R1050 outdoor movement
-- de-wire (DMG pp.58-59).
-- The DMG pp.58-59 mounted miles per day.
-- Grid encoding: tables[1]
-- name "grid", values = the
-- printed rates flat (row-
-- major). RowCount/ColCount
-- pins. Rowless def (the
-- R1047 class_grids shape).
-- The accessors live in
-- dm/outdoormove.h and are
-- unchanged.
-- DO NOT hand-edit: tools/r1050_splice.py
-- is the only writer.

return {
  key = "dm_move_mounted",
  name = "The DMG pp.58-59 mounted miles per day",
  sources = {
    { part = 0, round = 1050 },
  },
  pins = {
    { name = "dm_move_mountedRowCount",
      value = 6,
      comment = "the grid rows" },
    { name = "dm_move_mountedColCount",
      value = 3,
      comment = "the grid cols" },
  },
  tables = {
    { name = "grid", values = {
      60, 25, 5, 
      40, 20, 5, 
      30, 15, 5, 
      30, 15, 5, 
      25, 15, 0, 
      25, 10, 0, 
    } },
  },
}
