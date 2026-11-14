-- weapon table def: weapon_speed
-- The PHB weapon tables, the R1043 de-wire. gp = the printed speed factor; the rest zero.
-- Row encoding: band = { i, i } the printed row index.
-- The accessor and clamp semantics live in
-- rules/phb/weapontables.h and are unchanged.
-- DO NOT hand-edit: tools/r1043_splice.py is the only writer.

return {
  key = "weapon_speed",
  name = "Weapon speed verify list (18 rows)",
  rows = {
    { name = "fist", set = "weapon_speed", band = { 0, 0 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 0, 0 } },
    { name = "dagger", set = "weapon_speed", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 0, qty = { 0, 0 } },
    { name = "short sword", set = "weapon_speed", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 3, gp_hi = 0, qty = { 0, 0 } },
    { name = "hammer", set = "weapon_speed", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 0, 0 } },
    { name = "club", set = "weapon_speed", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 0, 0 } },
    { name = "hand axe", set = "weapon_speed", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 0, 0 } },
    { name = "quarterstaff", set = "weapon_speed", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 0, 0 } },
    { name = "scimitar", set = "weapon_speed", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 0, 0 } },
    { name = "long sword", set = "weapon_speed", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 0, 0 } },
    { name = "broad sword", set = "weapon_speed", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 0, 0 } },
    { name = "horseman mace", set = "weapon_speed", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 6, gp_hi = 0, qty = { 0, 0 } },
    { name = "spear", set = "weapon_speed", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 0, 0 } },
    { name = "footman mace", set = "weapon_speed", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 0, 0 } },
    { name = "footman flail", set = "weapon_speed", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 0, 0 } },
    { name = "morning star", set = "weapon_speed", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 0, 0 } },
    { name = "battle axe", set = "weapon_speed", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 0, 0 } },
    { name = "two-handed sword", set = "weapon_speed", band = { 16, 16 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 0, 0 } },
    { name = "pike", set = "weapon_speed", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 13, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1043 },
  },
  pins = {
    { name = "weapon_speedRowCount", value = 18, comment = "the printed row count" },
  },
  tables = {},
}
