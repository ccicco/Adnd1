-- treasure table def: treasure_armor
-- The DMG Table III.F armor and shield (p.123), the R1041 de-wire: the printed
-- percentile bands with the printed xp/gp values. xp_hi/
-- gp_hi above the base mark a printed uniform range; qty
-- above zero marks a printed bundle. The roller semantics
-- (band scan on 1+d100, fallback the last row) live in
-- dm/treasure.cpp and are unchanged.
-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.

return {
  key = "treasure_armor",
  name = "Table III.F armor and shield",
  rows = {
    { name = "Chain Mail +1", set = "treasure_armor", band = { 1, 5 }, xp = 600, xp_hi = 0, gp = 3500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Chain Mail +2", set = "treasure_armor", band = { 6, 9 }, xp = 1200, xp_hi = 0, gp = 7500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Chain Mail +3", set = "treasure_armor", band = { 10, 11 }, xp = 2000, xp_hi = 0, gp = 12500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Leather Armor +1", set = "treasure_armor", band = { 12, 19 }, xp = 300, xp_hi = 0, gp = 2000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Plate Mail +1", set = "treasure_armor", band = { 20, 26 }, xp = 800, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Plate Mail +2", set = "treasure_armor", band = { 27, 32 }, xp = 1750, xp_hi = 0, gp = 10500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Plate Mail +3", set = "treasure_armor", band = { 33, 35 }, xp = 2750, xp_hi = 0, gp = 15500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Plate Mail +4", set = "treasure_armor", band = { 36, 37 }, xp = 3500, xp_hi = 0, gp = 20500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Plate Mail +5", set = "treasure_armor", band = { 38, 38 }, xp = 4500, xp_hi = 0, gp = 27500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Plate Mail of Etherealness", set = "treasure_armor", band = { 39, 39 }, xp = 5000, xp_hi = 0, gp = 30000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Plate Mail of Vulnerability", set = "treasure_armor", band = { 40, 44 }, xp = 0, xp_hi = 0, gp = 1500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring Mail +1", set = "treasure_armor", band = { 45, 50 }, xp = 400, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Scale Mail +1", set = "treasure_armor", band = { 51, 55 }, xp = 500, xp_hi = 0, gp = 3000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Scale Mail +2", set = "treasure_armor", band = { 56, 59 }, xp = 1100, xp_hi = 0, gp = 6750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Splint Mail +1", set = "treasure_armor", band = { 60, 63 }, xp = 700, xp_hi = 0, gp = 4000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Splint Mail +2", set = "treasure_armor", band = { 64, 66 }, xp = 1500, xp_hi = 0, gp = 8500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Splint Mail +3", set = "treasure_armor", band = { 67, 68 }, xp = 2250, xp_hi = 0, gp = 14500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Splint Mail +4", set = "treasure_armor", band = { 69, 69 }, xp = 3000, xp_hi = 0, gp = 19000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Studded Leather +1", set = "treasure_armor", band = { 70, 75 }, xp = 400, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Shield +1", set = "treasure_armor", band = { 76, 84 }, xp = 250, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Shield +2", set = "treasure_armor", band = { 85, 89 }, xp = 500, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Shield +3", set = "treasure_armor", band = { 90, 93 }, xp = 800, xp_hi = 0, gp = 8000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Shield +4", set = "treasure_armor", band = { 94, 95 }, xp = 1200, xp_hi = 0, gp = 12000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Shield +5", set = "treasure_armor", band = { 96, 96 }, xp = 1750, xp_hi = 0, gp = 17500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Shield, large, +1, +4 vs. missiles", set = "treasure_armor", band = { 97, 97 }, xp = 400, xp_hi = 0, gp = 4000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Shield -1, missile attractor", set = "treasure_armor", band = { 98, 100 }, xp = 0, xp_hi = 0, gp = 750, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1041 },
  },
  pins = {
    { name = "treasure_armorRowCount", value = 26, comment = "the printed row count" },
  },
  tables = {},
}
