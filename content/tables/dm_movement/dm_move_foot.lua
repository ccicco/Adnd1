-- dm_move_foot
-- The R1050 outdoor movement
-- de-wire (DMG pp.58-59).
-- The DMG pp.58-59 afoot miles per day.
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
  key = "dm_move_foot",
  name = "The DMG pp.58-59 afoot miles per day",
  sources = {
    { part = 0, round = 1050 },
  },
  pins = {
    { name = "dm_move_footRowCount",
      value = 3,
      comment = "the grid rows" },
    { name = "dm_move_footColCount",
      value = 3,
      comment = "the grid cols" },
  },
  tables = {
    { name = "grid", values = {
      30, 20, 10, 
      20, 10, 5, 
      10, 5, 2, 
    } },
  },
}
