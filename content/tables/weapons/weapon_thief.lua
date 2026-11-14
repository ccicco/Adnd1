-- weapon table def: weapon_thief
-- The PHB weapon tables, the R1043 de-wire. Name-only rows.
-- Row encoding: band = { i, i } the printed row index.
-- The accessor and clamp semantics live in
-- rules/phb/weapontables.h and are unchanged.
-- DO NOT hand-edit: tools/r1043_splice.py is the only writer.

return {
  key = "weapon_thief",
  name = "Thief weapon allowlist (8 rows)",
  rows = {
    { name = "club", set = "weapon_thief", band = { 0, 0 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "dagger", set = "weapon_thief", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "dart", set = "weapon_thief", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "sling bullet", set = "weapon_thief", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "sling stone", set = "weapon_thief", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "short sword", set = "weapon_thief", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "broad sword", set = "weapon_thief", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "long sword", set = "weapon_thief", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1043 },
  },
  pins = {
    { name = "weapon_thiefRowCount", value = 8, comment = "the printed row count" },
  },
  tables = {},
}
