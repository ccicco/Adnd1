-- encounter table def: dungeon_level_1
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_1",
  rows = {
    { kind = "monster", band = { 1, 2 }, key = "giant_ant", count = { 1, 4 } },
    { kind = "monster", band = { 3, 4 }, key = "hobgoblin", count = { 2, 8 } },
    { kind = "monster", band = { 5, 14 }, key = "fire_beetle", count = { 1, 4 } },
    { kind = "monster", band = { 15, 15 }, key = "manes", count = { 1, 4 } },
    { kind = "monster", band = { 16, 17 }, key = "dwarf", count = { 4, 14 } },
    { kind = "monster", band = { 18, 18 }, key = "ear_seeker", count = { 1, 1 } },
    { kind = "monster", band = { 19, 19 }, key = "elf", count = { 3, 11 } },
    { kind = "monster", band = { 20, 21 }, key = "gnome", count = { 5, 15 } },
    { kind = "monster", band = { 22, 26 }, key = "goblin", count = { 6, 15 } },
    { kind = "monster", band = { 27, 28 }, key = "giant_rat", count = { 5, 20 } },
    { kind = "monster", band = { 29, 33 }, key = "hobgoblin", count = { 2, 8 } },
    { kind = "human", band = { 34, 48 } },
    { kind = "monster", band = { 49, 54 }, key = "kobold", count = { 6, 18 } },
    { kind = "monster", band = { 55, 66 }, key = "orc", count = { 7, 12 } },
    { kind = "monster", band = { 67, 70 }, key = "PIERCER", count = { 1, 3 } },
    { kind = "monster", band = { 71, 83 }, key = "giant_rat", count = { 5, 20 } },
    { kind = "monster", band = { 84, 85 }, key = "rot_grub", count = { 1, 3 } },
    { kind = "monster", band = { 86, 96 }, key = "shrieker", count = { 1, 2 } },
    { kind = "monster", band = { 97, 98 }, key = "skeleton", count = { 1, 4 } },
    { kind = "monster", band = { 99, 100 }, key = "zombie", count = { 1, 3 } },
  },
}
