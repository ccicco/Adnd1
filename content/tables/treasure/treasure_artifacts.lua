-- treasure table def: treasure_artifacts
-- The DMG Table III.E Special artifacts (p.122), the R1041 de-wire: the printed
-- percentile bands with the printed xp/gp values. xp_hi/
-- gp_hi above the base mark a printed uniform range; qty
-- above zero marks a printed bundle. The roller semantics
-- (band scan on 1+d100, fallback the last row) live in
-- dm/treasure.cpp and are unchanged.
-- DO NOT hand-edit: tools/r1041_splice.py is the only writer.

return {
  key = "treasure_artifacts",
  name = "Table III.E Special artifacts",
  rows = {
    { name = "Axe of the Dwarvish Lords", set = "treasure_artifacts", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 55000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Baba Yaga's Hut", set = "treasure_artifacts", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 90000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Codex of the Infinite Planes", set = "treasure_artifacts", band = { 3, 4 }, xp = 0, xp_hi = 0, gp = 62500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Crown of Might", set = "treasure_artifacts", band = { 5, 20 }, xp = 0, xp_hi = 0, gp = 50000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Crystal of the Ebon Flame", set = "treasure_artifacts", band = { 21, 21 }, xp = 0, xp_hi = 0, gp = 75000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Cup and Talisman of Al'Akbar", set = "treasure_artifacts", band = { 22, 22 }, xp = 0, xp_hi = 0, gp = 85000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Eye of Vecna", set = "treasure_artifacts", band = { 23, 24 }, xp = 0, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Hand of Vecna", set = "treasure_artifacts", band = { 25, 25 }, xp = 0, xp_hi = 0, gp = 60000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Heward's Mystical Organ", set = "treasure_artifacts", band = { 26, 26 }, xp = 0, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Horn of Change", set = "treasure_artifacts", band = { 27, 27 }, xp = 0, xp_hi = 0, gp = 20000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Invulnerable Coat of Arnd", set = "treasure_artifacts", band = { 28, 29 }, xp = 0, xp_hi = 0, gp = 47500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Iron Flask of Tuerny the Merciless", set = "treasure_artifacts", band = { 30, 31 }, xp = 0, xp_hi = 0, gp = 50000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Jacinth of Inestimable Beauty", set = "treasure_artifacts", band = { 32, 32 }, xp = 0, xp_hi = 0, gp = 100000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Johydee's Mask", set = "treasure_artifacts", band = { 33, 33 }, xp = 0, xp_hi = 0, gp = 40000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Kuroth's Quill", set = "treasure_artifacts", band = { 34, 35 }, xp = 0, xp_hi = 0, gp = 27500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mace of Cuthbert", set = "treasure_artifacts", band = { 36, 37 }, xp = 0, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Machine of Lum the Mad", set = "treasure_artifacts", band = { 38, 38 }, xp = 0, xp_hi = 0, gp = 72500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Mighty Servant of Leuk-O", set = "treasure_artifacts", band = { 39, 40 }, xp = 0, xp_hi = 0, gp = 185000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Orb of the Dragonkind", set = "treasure_artifacts", band = { 41, 47 }, xp = 0, xp_hi = 0, gp = 10000, gp_hi = 80000, qty = { 0, 0 } },
    { name = "Orb of Might", set = "treasure_artifacts", band = { 48, 63 }, xp = 0, xp_hi = 0, gp = 100000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Queen Ehlissa's Marvelous Nightingale", set = "treasure_artifacts", band = { 64, 64 }, xp = 0, xp_hi = 0, gp = 112500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Recorder of Ye'Cind", set = "treasure_artifacts", band = { 65, 66 }, xp = 0, xp_hi = 0, gp = 80000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Ring of Gaxx", set = "treasure_artifacts", band = { 67, 68 }, xp = 0, xp_hi = 0, gp = 17500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Rod of Seven Parts", set = "treasure_artifacts", band = { 69, 74 }, xp = 0, xp_hi = 0, gp = 25000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sceptre of Might", set = "treasure_artifacts", band = { 75, 91 }, xp = 0, xp_hi = 0, gp = 150000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Sword of Kas", set = "treasure_artifacts", band = { 92, 92 }, xp = 0, xp_hi = 0, gp = 97000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Teeth of Dahlver-Nar", set = "treasure_artifacts", band = { 93, 98 }, xp = 0, xp_hi = 0, gp = 5000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Throne of the Gods", set = "treasure_artifacts", band = { 99, 99 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Wand of Orcus", set = "treasure_artifacts", band = { 100, 100 }, xp = 0, xp_hi = 0, gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1041 },
  },
  pins = {
    { name = "treasure_artifactsRowCount", value = 29, comment = "the printed row count" },
  },
  tables = {},
}
