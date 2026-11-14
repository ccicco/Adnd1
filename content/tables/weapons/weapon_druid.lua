-- weapon table def: weapon_druid
-- The PHB weapon tables, the R1043 de-wire. Name-only rows.
-- Row encoding: band = { i, i } the printed row index.
-- The accessor and clamp semantics live in
-- rules/phb/weapontables.h and are unchanged.
-- DO NOT hand-edit: tools/r1043_splice.py is the only writer.

return {
  key = "weapon_druid",
  name = "Druid weapon allowlist (9 rows)",
  rows = {
    { name = "club", set = "weapon_druid", band = { 0, 0 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "dagger", set = "weapon_druid", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "dart", set = "weapon_druid", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "hammer", set = "weapon_druid", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "scimitar", set = "weapon_druid", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "sling bullet", set = "weapon_druid", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "sling stone", set = "weapon_druid", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "spear", set = "weapon_druid", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "quarterstaff", set = "weapon_druid", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1043 },
  },
  pins = {
    { name = "weapon_druidRowCount", value = 9, comment = "the printed row count" },
  },
  tables = {},
}
