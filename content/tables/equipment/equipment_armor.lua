-- equipment table def: equipment_armor
-- The PHB BASIC EQUIPMENT AND SUPPLIES COSTS tables, the
-- R1042 de-wire: the printed price rows in print order.
-- band = { i, i } the printed row index; gp = the printed
-- price in its printed coin; qty = { coin, 0 } the coin
-- code (1 copper, 2 silver, 3 gold - exactly one coin
-- nonzero per row, the R300a identity). The clamp and
-- accessor semantics live in rules/phb/equipcosts.h and
-- are unchanged.
-- DO NOT hand-edit: tools/r1042_splice.py is the only writer.

return {
  key = "equipment_armor",
  name = "Equipment armor list (14 rows)",
  rows = {
    { name = "banded", set = "equipment_armor", band = { 0, 0 }, xp = 0, xp_hi = 0, gp = 90, gp_hi = 0, qty = { 3, 0 } },
    { name = "chain", set = "equipment_armor", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 75, gp_hi = 0, qty = { 3, 0 } },
    { name = "helmet, great", set = "equipment_armor", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 15, gp_hi = 0, qty = { 3, 0 } },
    { name = "helmet, small", set = "equipment_armor", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 3, 0 } },
    { name = "leather", set = "equipment_armor", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 3, 0 } },
    { name = "padded", set = "equipment_armor", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 3, 0 } },
    { name = "plate", set = "equipment_armor", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 400, gp_hi = 0, qty = { 3, 0 } },
    { name = "ring", set = "equipment_armor", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 30, gp_hi = 0, qty = { 3, 0 } },
    { name = "scale", set = "equipment_armor", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 45, gp_hi = 0, qty = { 3, 0 } },
    { name = "shield, large", set = "equipment_armor", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 15, gp_hi = 0, qty = { 3, 0 } },
    { name = "shield, small", set = "equipment_armor", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 3, 0 } },
    { name = "shield, small, wooden", set = "equipment_armor", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 3, 0 } },
    { name = "splinted", set = "equipment_armor", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 80, gp_hi = 0, qty = { 3, 0 } },
    { name = "studded", set = "equipment_armor", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 15, gp_hi = 0, qty = { 3, 0 } },
  },
  sources = {
    { part = 0, round = 1042 },
  },
  pins = {
    { name = "equipment_armorRowCount", value = 14, comment = "the printed row count" },
  },
  tables = {},
}
