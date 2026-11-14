-- weapon table def: weapon_cleric
-- The PHB weapon tables, the R1043 de-wire. Name-only rows.
-- Row encoding: band = { i, i } the printed row index.
-- The accessor and clamp semantics live in
-- rules/phb/weapontables.h and are unchanged.
-- DO NOT hand-edit: tools/r1043_splice.py is the only writer.

return {
  key = "weapon_cleric",
  name = "Cleric weapon allowlist (7 rows)",
  rows = {
    { name = "club", set = "weapon_cleric", band = { 0, 0 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "footman flail", set = "weapon_cleric", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "horseman flail", set = "weapon_cleric", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "hammer", set = "weapon_cleric", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "footman mace", set = "weapon_cleric", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "horseman mace", set = "weapon_cleric", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "quarterstaff", set = "weapon_cleric", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1043 },
  },
  pins = {
    { name = "weapon_clericRowCount", value = 7, comment = "the printed row count" },
  },
  tables = {},
}
