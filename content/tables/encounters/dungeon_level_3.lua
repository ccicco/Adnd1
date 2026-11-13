-- encounter table def: dungeon_level_3
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_3",
  rows = {
    { kind = "monster", band = { 1, 10 }, key = "boring_beetle", count = { 1, 3 } },
    { kind = "monster", band = { 11, 20 }, key = "bugbear", count = { 2, 7 } },
    { kind = "character", band = { 21, 30 } },
    { kind = "dragon", band = { 31, 32 } },
    { kind = "monster", band = { 33, 34 }, key = "violet_fungus", count = { 1, 3 } },
    { kind = "monster", band = { 35, 40 }, key = "gelatinous_cube", count = { 1, 1 } },
    { kind = "monster", band = { 41, 45 }, key = "ghoul", count = { 1, 4 } },
    { kind = "monster", band = { 46, 50 }, key = "giant_lizard", count = { 1, 3 } },
    { kind = "monster", band = { 51, 54 }, key = "wererat", count = { 2, 5 } },
    { kind = "monster", band = { 55, 60 }, key = "ochre_jelly", count = { 1, 1 } },
    { kind = "monster", band = { 61, 72 }, key = "ogre", count = { 1, 3 } },
    { kind = "monster", band = { 73, 74 }, key = "PIERCER", count = { 2, 5 } },
    { kind = "monster", band = { 75, 75 }, key = "rot_grub", count = { 1, 4 } },
    { kind = "monster", band = { 76, 77 }, key = "shrieker", count = { 2, 5 } },
    { kind = "monster", band = { 78, 84 }, key = "huge_spider", count = { 1, 3 } },
    { kind = "monster", band = { 85, 93 }, key = "large_spider", count = { 2, 5 } },
    { kind = "monster", band = { 94, 95 }, key = "giant_tick", count = { 1, 3 } },
    { kind = "monster", band = { 96, 100 }, key = "giant_weasel", count = { 1, 4 } },
  },
}
