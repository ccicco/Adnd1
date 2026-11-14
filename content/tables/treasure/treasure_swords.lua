-- treasure table def: treasure_swords
-- The DMG Table III.G swords (p.123), the R1041 de-wire: the printed
-- percentile bands with the printed xp/gp values. xp_hi/
-- gp_hi above the base mark a printed uniform range; qty
-- above zero marks a printed bundle. The roller semantics
-- (band scan on 1+d100, fallback the last row) live in
-- dm/treasure.cpp and are unchanged.
-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.

return {
  key = "treasure_swords",
  name = "Table III.G swords",
  rows = {
    { name = "Sword +1", set = "treasure_swords", band = { 1, 25 }, xp = 400, xp_hi = 0, gp = 2000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +1, +2 vs. magic-using & enchanted creatures", set = "treasure_swords", band = { 26, 30 }, xp = 600, xp_hi = 0, gp = 3000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +1, +3 vs. lycanthropes & shape changers", set = "treasure_swords", band = { 31, 35 }, xp = 700, xp_hi = 0, gp = 3500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +1, +3 vs. regenerating creatures", set = "treasure_swords", band = { 36, 40 }, xp = 800, xp_hi = 0, gp = 4000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +1, +4 vs. reptiles", set = "treasure_swords", band = { 41, 45 }, xp = 800, xp_hi = 0, gp = 4000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +1, Flame Tongue", set = "treasure_swords", band = { 46, 49 }, xp = 900, xp_hi = 0, gp = 4500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +1, Luck Blade", set = "treasure_swords", band = { 50, 50 }, xp = 1000, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +2", set = "treasure_swords", band = { 51, 58 }, xp = 800, xp_hi = 0, gp = 4000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +2, Giant Slayer", set = "treasure_swords", band = { 59, 62 }, xp = 900, xp_hi = 0, gp = 4500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +2, Dragon Slayer", set = "treasure_swords", band = { 63, 66 }, xp = 900, xp_hi = 0, gp = 4500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +2, Nine Lives Stealer", set = "treasure_swords", band = { 67, 67 }, xp = 1600, xp_hi = 0, gp = 8000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +3", set = "treasure_swords", band = { 68, 71 }, xp = 1400, xp_hi = 0, gp = 7000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +3, Frost Brand", set = "treasure_swords", band = { 72, 74 }, xp = 1600, xp_hi = 0, gp = 8000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +4", set = "treasure_swords", band = { 75, 76 }, xp = 2000, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +4, Defender", set = "treasure_swords", band = { 77, 77 }, xp = 3000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +5", set = "treasure_swords", band = { 78, 78 }, xp = 3000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +5, Defender", set = "treasure_swords", band = { 79, 79 }, xp = 3600, xp_hi = 0, gp = 18000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +5, Holy Avenger", set = "treasure_swords", band = { 80, 80 }, xp = 4000, xp_hi = 0, gp = 20000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword of Dancing", set = "treasure_swords", band = { 81, 81 }, xp = 4400, xp_hi = 0, gp = 22000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword of Wounding", set = "treasure_swords", band = { 82, 82 }, xp = 4400, xp_hi = 0, gp = 22000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword of Life Stealing", set = "treasure_swords", band = { 83, 83 }, xp = 5000, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword of Sharpness", set = "treasure_swords", band = { 84, 84 }, xp = 7000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword, Vorpal Weapon", set = "treasure_swords", band = { 85, 85 }, xp = 10000, xp_hi = 0, gp = 50000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword +1, Cursed", set = "treasure_swords", band = { 86, 90 }, xp = 400, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword -2, Cursed", set = "treasure_swords", band = { 91, 95 }, xp = 600, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword, Cursed Berserking", set = "treasure_swords", band = { 96, 100 }, xp = 900, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1041 },
  },
  pins = {
    { name = "treasure_swordsRowCount", value = 26, comment = "the printed row count" },
  },
  tables = {},
}
