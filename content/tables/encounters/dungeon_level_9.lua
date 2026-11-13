-- encounter table def: dungeon_level_9
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_9",
  rows = {
    { kind = "character", band = { 1, 9 } },
    { kind = "monster", band = { 10, 12 }, key = "pit_fiend", count = { 1, 1 } },
    { kind = "dragon", band = { 13, 15 } },
    { kind = "monster", band = { 16, 21 }, key = "storm_giant", count = { 1, 2 } },
    { kind = "monster", band = { 22, 23 }, key = "stone_golem", count = { 1, 1 } },
    { kind = "hydra", band = { 24, 30 }, key = "hydra", heads = { 17, 20 }, number = { 1, 1 } },
    { kind = "hydra", band = { 31, 33 }, key = "hydra", heads = { 12, 12 }, number = { 1, 1 } },
    { kind = "monster", band = { 34, 40 }, key = "brown_mold", count = { 1, 1 } },
    { kind = "monster", band = { 41, 50 }, key = "yellow_mold", count = { 1, 1 } },
    { kind = "monster", band = { 51, 52 }, key = "REROLL", count = { 0, 0 } },
    { kind = "monster", band = { 53, 64 }, key = "purple_worm", count = { 1, 1 } },
    { kind = "monster", band = { 65, 67 }, key = "rust_monster", count = { 1, 1 } },
    { kind = "monster", band = { 68, 69 }, key = "lesser_titan_ac_1", count = { 1, 1 } },
    { kind = "monster", band = { 70, 73 }, key = "lesser_titan_ac_2", count = { 1, 1 } },
    { kind = "monster", band = { 74, 80 }, key = "umber_hulk", count = { 1, 4 } },
    { kind = "monster", band = { 81, 83 }, key = "vampire", count = { 1, 1 } },
    { kind = "monster", band = { 84, 93 }, key = "will_o_wisp", count = { 2, 5 } },
    { kind = "monster", band = { 94, 100 }, key = "xorn", count = { 2, 9 } },
  },
}
