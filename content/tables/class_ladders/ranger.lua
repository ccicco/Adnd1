-- class ladder def: ranger
-- The PHB class xp-title ladder, the R1044 de-wire. The six subclass ladders of rules/phb/subclasses.h.
-- Row encoding: band = { level, level } the printed
-- level, gp the XP to attain it (0 at level 1),
-- name the printed title. The accessor and clamp
-- semantics live in rules/phb/subclasses.h and are unchanged.
-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.

return {
  key = "ranger",
  name = "The ranger xp and title ladder (12 rows)",
  rows = {
    { name = "Runner", set = "ranger", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Strider", set = "ranger", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 2250, gp_hi = 0, qty = { 0, 0 } },
    { name = "Scout", set = "ranger", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 4500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Courser", set = "ranger", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Tracker", set = "ranger", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 20000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Guide", set = "ranger", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 40000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Pathfinder", set = "ranger", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 90000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ranger", set = "ranger", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 150000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ranger Knight", set = "ranger", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 225000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ranger Lord", set = "ranger", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 325000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ranger Lord (11th level)", set = "ranger", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 650000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ranger Lord (12th level)", set = "ranger", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 975000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1044 },
  },
  pins = {
    { name = "rangerRowCount", value = 12, comment = "the printed row count" },
  },
  tables = {},
}
