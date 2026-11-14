-- treasure table def: treasure_rings
-- The DMG Table III.C rings (p.122), the R1041 de-wire: the printed
-- percentile bands with the printed xp/gp values. xp_hi/
-- gp_hi above the base mark a printed uniform range; qty
-- above zero marks a printed bundle. The roller semantics
-- (band scan on 1+d100, fallback the last row) live in
-- dm/treasure.cpp and are unchanged.
-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.

return {
  key = "treasure_rings",
  name = "Table III.C rings",
  rows = {
    { name = "Ring of Contrariness", set = "treasure_rings", band = { 1, 6 }, xp = 0, xp_hi = 0, gp = 1000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Delusion", set = "treasure_rings", band = { 7, 12 }, xp = 0, xp_hi = 0, gp = 2000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Djinni Summoning", set = "treasure_rings", band = { 13, 14 }, xp = 3000, xp_hi = 0, gp = 20000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Elemental Command", set = "treasure_rings", band = { 15, 15 }, xp = 5000, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Feather Falling", set = "treasure_rings", band = { 16, 21 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Fire Resistance", set = "treasure_rings", band = { 22, 27 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Free Action", set = "treasure_rings", band = { 28, 30 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Human Influence", set = "treasure_rings", band = { 31, 33 }, xp = 2000, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Invisibility", set = "treasure_rings", band = { 34, 40 }, xp = 1500, xp_hi = 0, gp = 7500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Mammal Control", set = "treasure_rings", band = { 41, 43 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Multiple Wishes", set = "treasure_rings", band = { 44, 44 }, xp = 5000, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Protection", set = "treasure_rings", band = { 45, 60 }, xp = 2000, xp_hi = 4000, gp = 10000, gp_hi = 20000, qty = { 0, 0 } },
    { name = "Ring of Regeneration", set = "treasure_rings", band = { 61, 61 }, xp = 5000, xp_hi = 0, gp = 40000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Shooting Stars", set = "treasure_rings", band = { 62, 63 }, xp = 3000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Spell Storing", set = "treasure_rings", band = { 64, 65 }, xp = 2500, xp_hi = 0, gp = 22500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Spell Turning", set = "treasure_rings", band = { 66, 69 }, xp = 2000, xp_hi = 0, gp = 17500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Swimming", set = "treasure_rings", band = { 70, 75 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Telekinesis", set = "treasure_rings", band = { 76, 77 }, xp = 2000, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Three Wishes", set = "treasure_rings", band = { 78, 79 }, xp = 3000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Warmth", set = "treasure_rings", band = { 80, 85 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Water Walking", set = "treasure_rings", band = { 86, 90 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Weakness", set = "treasure_rings", band = { 91, 98 }, xp = 0, xp_hi = 0, gp = 1000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Wizardry", set = "treasure_rings", band = { 99, 99 }, xp = 4000, xp_hi = 0, gp = 50000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of X-Ray Vision", set = "treasure_rings", band = { 100, 100 }, xp = 4000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1041 },
  },
  pins = {
    { name = "treasure_ringsRowCount", value = 24, comment = "the printed row count" },
  },
  tables = {},
}
