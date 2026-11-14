-- treasure table def: treasure_weapons
-- The DMG Table III.H miscellaneous weapons (p.123), the R1041 de-wire: the printed
-- percentile bands with the printed xp/gp values. xp_hi/
-- gp_hi above the base mark a printed uniform range; qty
-- above zero marks a printed bundle. The roller semantics
-- (band scan on 1+d100, fallback the last row) live in
-- dm/treasure.cpp and are unchanged.
-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.

return {
  key = "treasure_weapons",
  name = "Table III.H miscellaneous weapons",
  rows = {
    { name = "Arrow +1", set = "treasure_weapons", band = { 1, 8 }, xp = 20, xp_hi = 0, gp = 120, gp_hi = 0, qty = { 2, 24 } },
    { name = "Arrow +2", set = "treasure_weapons", band = { 9, 12 }, xp = 50, xp_hi = 0, gp = 300, gp_hi = 0, qty = { 2, 16 } },
    { name = "Arrow +3", set = "treasure_weapons", band = { 13, 14 }, xp = 75, xp_hi = 0, gp = 450, gp_hi = 0, qty = { 2, 12 } },
    { name = "Arrow of Slaying", set = "treasure_weapons", band = { 15, 15 }, xp = 250, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Axe +1", set = "treasure_weapons", band = { 16, 20 }, xp = 300, xp_hi = 0, gp = 1750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Axe +2", set = "treasure_weapons", band = { 21, 22 }, xp = 600, xp_hi = 0, gp = 3750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Axe +2, Throwing", set = "treasure_weapons", band = { 23, 23 }, xp = 750, xp_hi = 0, gp = 4500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Axe +3", set = "treasure_weapons", band = { 24, 24 }, xp = 1000, xp_hi = 0, gp = 7000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Battle Axe +1", set = "treasure_weapons", band = { 25, 27 }, xp = 400, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Bolt +2", set = "treasure_weapons", band = { 28, 32 }, xp = 50, xp_hi = 0, gp = 300, gp_hi = 0, qty = { 2, 20 } },
    { name = "Bow +1", set = "treasure_weapons", band = { 33, 35 }, xp = 500, xp_hi = 0, gp = 3500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Crossbow of Accuracy, +3", set = "treasure_weapons", band = { 36, 36 }, xp = 2000, xp_hi = 0, gp = 12000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Crossbow of Distance", set = "treasure_weapons", band = { 37, 37 }, xp = 1500, xp_hi = 0, gp = 7500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Crossbow of Speed", set = "treasure_weapons", band = { 38, 38 }, xp = 1500, xp_hi = 0, gp = 7500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Dagger +1, +2 vs. creatures smaller than man-sized", set = "treasure_weapons", band = { 39, 46 }, xp = 100, xp_hi = 0, gp = 750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Dagger +2, +3 vs. creatures larger than man-sized", set = "treasure_weapons", band = { 47, 50 }, xp = 250, xp_hi = 0, gp = 2000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Dagger of Venom", set = "treasure_weapons", band = { 51, 51 }, xp = 350, xp_hi = 0, gp = 3000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Flail +1", set = "treasure_weapons", band = { 52, 56 }, xp = 450, xp_hi = 0, gp = 4000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Hammer +2", set = "treasure_weapons", band = { 57, 60 }, xp = 300, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Hammer +2", set = "treasure_weapons", band = { 61, 62 }, xp = 650, xp_hi = 0, gp = 6000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Hammer +3, Dwarven Thrower", set = "treasure_weapons", band = { 63, 63 }, xp = 1500, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Hammer of Thunderbolts", set = "treasure_weapons", band = { 64, 64 }, xp = 2500, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Javelin +2", set = "treasure_weapons", band = { 65, 67 }, xp = 750, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mace +1", set = "treasure_weapons", band = { 68, 72 }, xp = 350, xp_hi = 0, gp = 3000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mace +2", set = "treasure_weapons", band = { 73, 75 }, xp = 700, xp_hi = 0, gp = 4500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mace of Disruption", set = "treasure_weapons", band = { 76, 76 }, xp = 1750, xp_hi = 0, gp = 17500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mace +4", set = "treasure_weapons", band = { 77, 77 }, xp = 1500, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Military Pick +1", set = "treasure_weapons", band = { 78, 80 }, xp = 350, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Morning Star +1", set = "treasure_weapons", band = { 81, 83 }, xp = 400, xp_hi = 0, gp = 3000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Scimitar +2", set = "treasure_weapons", band = { 84, 88 }, xp = 750, xp_hi = 0, gp = 6000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sling of Seeking +2", set = "treasure_weapons", band = { 89, 89 }, xp = 700, xp_hi = 0, gp = 7000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Spear +1", set = "treasure_weapons", band = { 90, 94 }, xp = 500, xp_hi = 0, gp = 3000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Spear +2", set = "treasure_weapons", band = { 95, 96 }, xp = 1000, xp_hi = 0, gp = 6500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Spear +3", set = "treasure_weapons", band = { 97, 97 }, xp = 1750, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Spear, Cursed Backbiter", set = "treasure_weapons", band = { 98, 99 }, xp = 0, xp_hi = 0, gp = 1000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Trident (Military Fork) +3", set = "treasure_weapons", band = { 100, 100 }, xp = 1500, xp_hi = 0, gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1041 },
  },
  pins = {
    { name = "treasure_weaponsRowCount", value = 36, comment = "the printed row count" },
  },
  tables = {},
}
