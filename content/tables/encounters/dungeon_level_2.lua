-- encounter table def: dungeon_level_2
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_2",
  rows = {
    { kind = "monster", band = { 1, 1 }, key = "gnoll", count = { 4, 10 } },
    { kind = "monster", band = { 2, 16 }, key = "giant_centipede", count = { 3, 13 } },
    { kind = "character", band = { 17, 27 } },
    { kind = "monster", band = { 28, 29 }, key = "lemure", count = { 2, 5 } },
    { kind = "monster", band = { 30, 31 }, key = "gas_spore", count = { 1, 2 } },
    { kind = "monster", band = { 32, 38 }, key = "gnoll", count = { 4, 10 } },
    { kind = "monster", band = { 39, 46 }, key = "PIERCER", count = { 1, 4 } },
    { kind = "monster", band = { 47, 58 }, key = "giant_rat", count = { 6, 24 } },
    { kind = "monster", band = { 59, 60 }, key = "rot_grub", count = { 1, 4 } },
    { kind = "monster", band = { 61, 72 }, key = "shrieker", count = { 1, 3 } },
    { kind = "monster", band = { 73, 77 }, key = "stirge", count = { 5, 15 } },
    { kind = "monster", band = { 78, 87 }, key = "giant_toad", count = { 1, 4 } },
    { kind = "monster", band = { 88, 100 }, key = "troglodyte", count = { 2, 8 } },
  },
}
