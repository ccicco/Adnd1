-- treasure table def: treasure_rods
-- The DMG Table III.D rods, staves and wands (p.122), the R1041 de-wire: the printed
-- percentile bands with the printed xp/gp values. xp_hi/
-- gp_hi above the base mark a printed uniform range; qty
-- above zero marks a printed bundle. The roller semantics
-- (band scan on 1+d100, fallback the last row) live in
-- dm/treasure.cpp and are unchanged.
-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.

return {
  key = "treasure_rods",
  name = "Table III.D rods, staves and wands",
  rows = {
    { name = "Rod of Absorption", set = "treasure_rods", band = { 1, 3 }, xp = 7500, xp_hi = 0, gp = 40000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rod of Beguiling", set = "treasure_rods", band = { 4, 4 }, xp = 5000, xp_hi = 0, gp = 30000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rod of Cancellation", set = "treasure_rods", band = { 5, 14 }, xp = 10000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rod of Lordly Might", set = "treasure_rods", band = { 15, 16 }, xp = 6000, xp_hi = 0, gp = 20000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rod of Resurrection", set = "treasure_rods", band = { 17, 17 }, xp = 10000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rod of Rulership", set = "treasure_rods", band = { 18, 18 }, xp = 8000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rod of Smiting", set = "treasure_rods", band = { 19, 19 }, xp = 4000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Staff of Command", set = "treasure_rods", band = { 20, 20 }, xp = 5000, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Staff of Curing", set = "treasure_rods", band = { 21, 22 }, xp = 6000, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Staff of the Magi", set = "treasure_rods", band = { 23, 23 }, xp = 15000, xp_hi = 0, gp = 75000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Staff of Power", set = "treasure_rods", band = { 24, 24 }, xp = 12000, xp_hi = 0, gp = 60000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Staff of the Serpent", set = "treasure_rods", band = { 25, 27 }, xp = 7000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Staff of Striking", set = "treasure_rods", band = { 28, 31 }, xp = 6000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Staff of Withering", set = "treasure_rods", band = { 32, 33 }, xp = 8000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Conjuration", set = "treasure_rods", band = { 34, 34 }, xp = 7000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Enemy Detection", set = "treasure_rods", band = { 35, 38 }, xp = 2000, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Fear", set = "treasure_rods", band = { 39, 41 }, xp = 3000, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Fire", set = "treasure_rods", band = { 42, 44 }, xp = 4500, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Frost", set = "treasure_rods", band = { 45, 47 }, xp = 6000, xp_hi = 0, gp = 50000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Illumination", set = "treasure_rods", band = { 48, 52 }, xp = 2000, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Illusion", set = "treasure_rods", band = { 53, 56 }, xp = 3000, xp_hi = 0, gp = 20000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Lightning", set = "treasure_rods", band = { 57, 59 }, xp = 4000, xp_hi = 0, gp = 30000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Magic Detection", set = "treasure_rods", band = { 60, 68 }, xp = 2500, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Metal & Mineral Detection", set = "treasure_rods", band = { 69, 73 }, xp = 1500, xp_hi = 0, gp = 7500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Magic Missiles", set = "treasure_rods", band = { 74, 78 }, xp = 4000, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Negation", set = "treasure_rods", band = { 79, 86 }, xp = 3500, xp_hi = 0, gp = 15000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Paralyzation", set = "treasure_rods", band = { 87, 89 }, xp = 3500, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Polymorphing", set = "treasure_rods", band = { 90, 92 }, xp = 3500, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Secret Door & Trap Location", set = "treasure_rods", band = { 93, 94 }, xp = 5000, xp_hi = 0, gp = 40000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Wonder", set = "treasure_rods", band = { 95, 100 }, xp = 6000, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1041 },
  },
  pins = {
    { name = "treasure_rodsRowCount", value = 30, comment = "the printed row count" },
  },
  tables = {},
}
