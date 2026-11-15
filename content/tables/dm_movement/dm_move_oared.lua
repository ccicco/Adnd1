-- dm_move_oared
-- The R1050 outdoor movement
-- de-wire (DMG pp.58-59).
-- The DMG pp.58-59 afloat oared miles per day.
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
  key = "dm_move_oared",
  name = "The DMG pp.58-59 afloat oared miles per day",
  sources = {
    { part = 0, round = 1050 },
  },
  pins = {
    { name = "dm_move_oaredRowCount",
      value = 8,
      comment = "the grid rows" },
    { name = "dm_move_oaredColCount",
      value = 5,
      comment = "the grid cols" },
  },
  tables = {
    { name = "grid", values = {
      15, 5, 15, 0, 10, 
      30, 15, 35, 0, 25, 
      20, 5, 20, 0, 0, 
      40, 5, 40, 30, 0, 
      30, 0, 30, 30, 0, 
      10, 0, 15, 20, 0, 
      10, 0, 10, 15, 0, 
      10, 0, 10, 20, 0, 
    } },
  },
}
