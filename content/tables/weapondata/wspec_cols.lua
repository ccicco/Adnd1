-- wspec_cols
-- The R1058 weapons-family de-wire.
-- weapon specialization table columns.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in the family headers and keep their clamps.
-- DO NOT hand-edit: tools/r1058_splice.py is the only writer.

return {
  key = "wspec_cols",
  name = "weapon specialization table columns",
  sources = {
    { part = 0, round = 1058 },
  },
  pins = {
    { name = "wspec_colsRowCount",
      value = 8,
      comment = "the table rows" },
  },
  rows = {
    { name = "Melee Weapon",
      set = "wspec_cols",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Bow",
      set = "wspec_cols",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Light Crossbow",
      set = "wspec_cols",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Heavy Crossbow",
      set = "wspec_cols",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Lasso and Staff Sling",
      set = "wspec_cols",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Thrown Dagger",
      set = "wspec_cols",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Thrown Dart",
      set = "wspec_cols",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Other Missiles and Hurled Weapons",
      set = "wspec_cols",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
  },
}
