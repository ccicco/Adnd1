-- equipment table def: equipment_arms
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
  key = "equipment_arms",
  name = "Equipment arms list (52 rows)",
  rows = {
    { name = "arrow, normal, single", set = "equipment_arms", band = { 0, 0 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 0, qty = { 2, 0 } },
    { name = "arrow, normal, dozen", set = "equipment_arms", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 3, 0 } },
    { name = "arrow, silver, single", set = "equipment_arms", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 3, 0 } },
    { name = "axe, battle", set = "equipment_arms", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 3, 0 } },
    { name = "axe, hand or throwing", set = "equipment_arms", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 3, 0 } },
    { name = "bardiche", set = "equipment_arms", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 3, 0 } },
    { name = "bec de corbin", set = "equipment_arms", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 6, gp_hi = 0, qty = { 3, 0 } },
    { name = "bill-guisarme", set = "equipment_arms", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 6, gp_hi = 0, qty = { 3, 0 } },
    { name = "bow, composite, short", set = "equipment_arms", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 75, gp_hi = 0, qty = { 3, 0 } },
    { name = "bow, composite, long", set = "equipment_arms", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 100, gp_hi = 0, qty = { 3, 0 } },
    { name = "bow, long", set = "equipment_arms", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 60, gp_hi = 0, qty = { 3, 0 } },
    { name = "bow, short", set = "equipment_arms", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 15, gp_hi = 0, qty = { 3, 0 } },
    { name = "crossbow, heavy", set = "equipment_arms", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 20, gp_hi = 0, qty = { 3, 0 } },
    { name = "crossbow, light", set = "equipment_arms", band = { 13, 13 }, xp = 0, xp_hi = 0, gp = 12, gp_hi = 0, qty = { 3, 0 } },
    { name = "dagger and scabbard", set = "equipment_arms", band = { 14, 14 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 0, qty = { 3, 0 } },
    { name = "dart", set = "equipment_arms", band = { 15, 15 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 2, 0 } },
    { name = "fauchard", set = "equipment_arms", band = { 16, 16 }, xp = 0, xp_hi = 0, gp = 3, gp_hi = 0, qty = { 3, 0 } },
    { name = "fauchard-fork", set = "equipment_arms", band = { 17, 17 }, xp = 0, xp_hi = 0, gp = 8, gp_hi = 0, qty = { 3, 0 } },
    { name = "footman flail", set = "equipment_arms", band = { 18, 18 }, xp = 0, xp_hi = 0, gp = 3, gp_hi = 0, qty = { 3, 0 } },
    { name = "horseman flail", set = "equipment_arms", band = { 19, 19 }, xp = 0, xp_hi = 0, gp = 8, gp_hi = 0, qty = { 3, 0 } },
    { name = "military fork", set = "equipment_arms", band = { 20, 20 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 3, 0 } },
    { name = "glaive", set = "equipment_arms", band = { 21, 21 }, xp = 0, xp_hi = 0, gp = 6, gp_hi = 0, qty = { 3, 0 } },
    { name = "glaive-guisarme", set = "equipment_arms", band = { 22, 22 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 3, 0 } },
    { name = "guisarme", set = "equipment_arms", band = { 23, 23 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 3, 0 } },
    { name = "guisarme-voulge", set = "equipment_arms", band = { 24, 24 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 3, 0 } },
    { name = "halberd", set = "equipment_arms", band = { 25, 25 }, xp = 0, xp_hi = 0, gp = 9, gp_hi = 0, qty = { 3, 0 } },
    { name = "lucern hammer", set = "equipment_arms", band = { 26, 26 }, xp = 0, xp_hi = 0, gp = 7, gp_hi = 0, qty = { 3, 0 } },
    { name = "hammer", set = "equipment_arms", band = { 27, 27 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 3, 0 } },
    { name = "javelin", set = "equipment_arms", band = { 28, 28 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 2, 0 } },
    { name = "lance", set = "equipment_arms", band = { 29, 29 }, xp = 0, xp_hi = 0, gp = 6, gp_hi = 0, qty = { 3, 0 } },
    { name = "footman mace", set = "equipment_arms", band = { 30, 30 }, xp = 0, xp_hi = 0, gp = 8, gp_hi = 0, qty = { 3, 0 } },
    { name = "horseman mace", set = "equipment_arms", band = { 31, 31 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 3, 0 } },
    { name = "morning star", set = "equipment_arms", band = { 32, 32 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 3, 0 } },
    { name = "partisan", set = "equipment_arms", band = { 33, 33 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 3, 0 } },
    { name = "footman pick", set = "equipment_arms", band = { 34, 34 }, xp = 0, xp_hi = 0, gp = 8, gp_hi = 0, qty = { 3, 0 } },
    { name = "horseman pick", set = "equipment_arms", band = { 35, 35 }, xp = 0, xp_hi = 0, gp = 5, gp_hi = 0, qty = { 3, 0 } },
    { name = "awl pike", set = "equipment_arms", band = { 36, 36 }, xp = 0, xp_hi = 0, gp = 3, gp_hi = 0, qty = { 3, 0 } },
    { name = "quarrel, light, single", set = "equipment_arms", band = { 37, 37 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 2, 0 } },
    { name = "quarrel, heavy, score", set = "equipment_arms", band = { 38, 38 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 0, qty = { 3, 0 } },
    { name = "ranseur", set = "equipment_arms", band = { 39, 39 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 3, 0 } },
    { name = "scimitar", set = "equipment_arms", band = { 40, 40 }, xp = 0, xp_hi = 0, gp = 15, gp_hi = 0, qty = { 3, 0 } },
    { name = "sling and bullets, dozen", set = "equipment_arms", band = { 41, 41 }, xp = 0, xp_hi = 0, gp = 15, gp_hi = 0, qty = { 2, 0 } },
    { name = "sling bullets, score", set = "equipment_arms", band = { 42, 42 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 2, 0 } },
    { name = "spear", set = "equipment_arms", band = { 43, 43 }, xp = 0, xp_hi = 0, gp = 1, gp_hi = 0, qty = { 3, 0 } },
    { name = "spetum", set = "equipment_arms", band = { 44, 44 }, xp = 0, xp_hi = 0, gp = 3, gp_hi = 0, qty = { 3, 0 } },
    { name = "bastard sword and scabbard", set = "equipment_arms", band = { 45, 45 }, xp = 0, xp_hi = 0, gp = 25, gp_hi = 0, qty = { 3, 0 } },
    { name = "broad sword and scabbard", set = "equipment_arms", band = { 46, 46 }, xp = 0, xp_hi = 0, gp = 10, gp_hi = 0, qty = { 3, 0 } },
    { name = "long sword and scabbard", set = "equipment_arms", band = { 47, 47 }, xp = 0, xp_hi = 0, gp = 15, gp_hi = 0, qty = { 3, 0 } },
    { name = "short sword and scabbard", set = "equipment_arms", band = { 48, 48 }, xp = 0, xp_hi = 0, gp = 8, gp_hi = 0, qty = { 3, 0 } },
    { name = "two-handed sword", set = "equipment_arms", band = { 49, 49 }, xp = 0, xp_hi = 0, gp = 30, gp_hi = 0, qty = { 3, 0 } },
    { name = "trident", set = "equipment_arms", band = { 50, 50 }, xp = 0, xp_hi = 0, gp = 4, gp_hi = 0, qty = { 3, 0 } },
    { name = "voulge", set = "equipment_arms", band = { 51, 51 }, xp = 0, xp_hi = 0, gp = 2, gp_hi = 0, qty = { 3, 0 } },
  },
  sources = {
    { part = 0, round = 1042 },
  },
  pins = {
    { name = "equipment_armsRowCount", value = 52, comment = "the printed row count" },
  },
  tables = {},
}
