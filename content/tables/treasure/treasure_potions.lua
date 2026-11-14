-- treasure table def: treasure_potions
-- The DMG Table III.A potions (p.121), the R1041 de-wire: the printed
-- percentile bands with the printed xp/gp values. xp_hi/
-- gp_hi above the base mark a printed uniform range; qty
-- above zero marks a printed bundle. The roller semantics
-- (band scan on 1+d100, fallback the last row) live in
-- dm/treasure.cpp and are unchanged.
-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.

return {
  key = "treasure_potions",
  name = "Table III.A potions",
  rows = {
    { name = "Potion of Animal Control", set = "treasure_potions", band = { 1, 3 }, xp = 250, xp_hi = 0, gp = 400, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Clairaudience", set = "treasure_potions", band = { 4, 6 }, xp = 250, xp_hi = 0, gp = 400, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Clairvoyance", set = "treasure_potions", band = { 7, 9 }, xp = 300, xp_hi = 0, gp = 500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Climbing", set = "treasure_potions", band = { 10, 12 }, xp = 300, xp_hi = 0, gp = 500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Delusion", set = "treasure_potions", band = { 13, 15 }, xp = 0, xp_hi = 0, gp = 150, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Diminution", set = "treasure_potions", band = { 16, 18 }, xp = 300, xp_hi = 0, gp = 500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Dragon Control", set = "treasure_potions", band = { 19, 20 }, xp = 500, xp_hi = 1000, gp = 5000, gp_hi = 9000, qty = { 0, 0 } },
    { name = "Potion of ESP", set = "treasure_potions", band = { 21, 23 }, xp = 500, xp_hi = 0, gp = 850, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Extra-Healing", set = "treasure_potions", band = { 24, 26 }, xp = 400, xp_hi = 0, gp = 800, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Fire Resistance", set = "treasure_potions", band = { 27, 29 }, xp = 250, xp_hi = 0, gp = 400, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Flying", set = "treasure_potions", band = { 30, 32 }, xp = 500, xp_hi = 0, gp = 750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Gaseous Form", set = "treasure_potions", band = { 33, 34 }, xp = 300, xp_hi = 0, gp = 400, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Giant Control", set = "treasure_potions", band = { 35, 36 }, xp = 400, xp_hi = 900, gp = 1000, gp_hi = 6000, qty = { 0, 0 } },
    { name = "Potion of Giant Strength", set = "treasure_potions", band = { 37, 39 }, xp = 500, xp_hi = 750, gp = 900, gp_hi = 1400, qty = { 0, 0 } },
    { name = "Potion of Growth", set = "treasure_potions", band = { 40, 41 }, xp = 250, xp_hi = 0, gp = 300, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Healing", set = "treasure_potions", band = { 42, 47 }, xp = 200, xp_hi = 0, gp = 400, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Heroism", set = "treasure_potions", band = { 48, 49 }, xp = 300, xp_hi = 0, gp = 500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Human Control", set = "treasure_potions", band = { 50, 51 }, xp = 500, xp_hi = 0, gp = 900, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Invisibility", set = "treasure_potions", band = { 52, 54 }, xp = 250, xp_hi = 0, gp = 500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Invulnerability", set = "treasure_potions", band = { 55, 57 }, xp = 350, xp_hi = 0, gp = 500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Levitation", set = "treasure_potions", band = { 58, 60 }, xp = 250, xp_hi = 0, gp = 400, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Longevity", set = "treasure_potions", band = { 61, 63 }, xp = 500, xp_hi = 0, gp = 1000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Oil of Etherealness", set = "treasure_potions", band = { 64, 66 }, xp = 600, xp_hi = 0, gp = 1500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Oil of Slipperiness", set = "treasure_potions", band = { 67, 69 }, xp = 400, xp_hi = 0, gp = 750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Philter of Love", set = "treasure_potions", band = { 70, 72 }, xp = 200, xp_hi = 0, gp = 300, gp_hi = 0, qty = { 0, 0 } },
    { name = "Philter of Persuasiveness", set = "treasure_potions", band = { 73, 75 }, xp = 400, xp_hi = 0, gp = 850, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Plant Control", set = "treasure_potions", band = { 76, 78 }, xp = 250, xp_hi = 0, gp = 300, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Polymorph (self)", set = "treasure_potions", band = { 79, 81 }, xp = 200, xp_hi = 0, gp = 350, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Poison", set = "treasure_potions", band = { 82, 84 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Speed", set = "treasure_potions", band = { 85, 87 }, xp = 200, xp_hi = 0, gp = 450, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Super-Heroism", set = "treasure_potions", band = { 88, 90 }, xp = 450, xp_hi = 0, gp = 750, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Sweet Water", set = "treasure_potions", band = { 91, 93 }, xp = 200, xp_hi = 0, gp = 250, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Treasure Finding", set = "treasure_potions", band = { 94, 96 }, xp = 600, xp_hi = 0, gp = 2000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Undead Control", set = "treasure_potions", band = { 97, 97 }, xp = 700, xp_hi = 0, gp = 2500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Potion of Water Breathing", set = "treasure_potions", band = { 98, 100 }, xp = 400, xp_hi = 0, gp = 900, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1041 },
  },
  pins = {
    { name = "treasure_potionsRowCount", value = 35, comment = "the printed row count" },
  },
  tables = {},
}
