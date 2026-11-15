-- dm_move_sail_hi
-- The R1050 outdoor movement
-- de-wire (DMG pp.58-59).
-- The DMG pp.58-59 afloat sailed miles per day, band hi.
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
  key = "dm_move_sail_hi",
  name = "The DMG pp.58-59 afloat sailed miles per day, band hi",
  sources = {
    { part = 0, round = 1050 },
  },
  pins = {
    { name = "dm_move_sail_hiRowCount",
      value = 8,
      comment = "the grid rows" },
    { name = "dm_move_sail_hiColCount",
      value = 5,
      comment = "the grid cols" },
  },
  tables = {
    { name = "grid", values = {
      30, 10, 30, 0, 15, 
      80, 20, 60, 0, 40, 
      50, 10, 40, 0, 0, 
      80, 0, 60, 50, 0, 
      60, 0, 50, 50, 0, 
      60, 0, 50, 50, 0, 
      35, 0, 35, 35, 0, 
      50, 0, 40, 50, 0, 
    } },
  },
}
