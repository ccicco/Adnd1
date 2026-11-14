-- class ladder def: druid
-- The PHB class xp-title ladder, the R1044 de-wire. The six subclass ladders of rules/phb/subclasses.h.
-- Row encoding: band = { level, level } the printed
-- level, gp the XP to attain it (0 at level 1),
-- name the printed title. The accessor and clamp
-- semantics live in rules/phb/subclasses.h and are unchanged.
-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.

return {
  key = "druid",
  name = "The druid xp and title ladder (14 rows)",
  rows = {
    { name = "Aspirant", set = "druid", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ovate", set = "druid", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 2000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 1st Circle", set = "druid", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 4000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 2nd Circle", set = "druid", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 7500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 3rd Circle", set = "druid", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 12500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 4th Circle", set = "druid", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 20000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 5th Circle", set = "druid", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 6th Circle", set = "druid", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 60000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 7th Circle", set = "druid", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 90000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 8th Circle", set = "druid", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 125000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Initiate of the 9th Circle", set = "druid", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 200000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Druid", set = "druid", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 300000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Archdruid", set = "druid", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 750000, gp_hi = 0, qty = { 0, 0 } },
    { name = "The Great Druid", set = "druid", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 1500000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1044 },
  },
  pins = {
    { name = "druidRowCount", value = 14, comment = "the printed row count" },
  },
  tables = {},
}
