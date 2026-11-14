-- class ladder def: monk
-- The PHB class xp-title ladder, the R1044 de-wire. The six subclass ladders of rules/phb/subclasses.h.
-- Row encoding: band = { level, level } the printed
-- level, gp the XP to attain it (0 at level 1),
-- name the printed title. The accessor and clamp
-- semantics live in rules/phb/subclasses.h and are unchanged.
-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.

return {
  key = "monk",
  name = "The monk xp and title ladder (17 rows)",
  rows = {
    { name = "Novice", set = "monk", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate", set = "monk", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 2250, gp_hi = 0, qty = { 0, 0 } },
    { name = "Brother", set = "monk", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 4750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Disciple", set = "monk", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Immaculate", set = "monk", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 22500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master", set = "monk", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 47500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Superior Master", set = "monk", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 98000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of Dragons", set = "monk", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 200000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of the North Wind", set = "monk", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 350000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of the West Wind", set = "monk", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 500000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of the South Wind", set = "monk", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 700000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of the East Wind", set = "monk", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 950000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of Winter", set = "monk", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 1250000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of Autumn", set = "monk", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 1750000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of Summer", set = "monk", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 2250000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master of Spring", set = "monk", band = { 16, 16 }, xp = 0, xp_hi = 0, gp = 2750000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Grand Master of Flowers", set = "monk", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 3250000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1044 },
  },
  pins = {
    { name = "monkRowCount", value = 17, comment = "the printed row count" },
  },
  tables = {},
}
