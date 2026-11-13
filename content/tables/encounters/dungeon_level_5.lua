-- encounter table def: dungeon_level_5
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_5",
  rows = {
    { kind = "character", band = { 1, 8 } },
    { kind = "monster", band = { 9, 15 }, key = "cockatrice", count = { 1, 2 } },
    { kind = "monster", band = { 16, 18 }, key = "displacer_beast", count = { 1, 2 } },
    { kind = "monster", band = { 19, 22 }, key = "doppelganger", count = { 1, 3 } },
    { kind = "dragon", band = { 23, 24 } },
    { kind = "hydra", band = { 25, 26 }, key = "hydra", heads = { 7, 7 }, number = { 1, 1 } },
    { kind = "hydra", band = { 27, 27 }, key = "hydra", heads = { 6, 6 }, number = { 1, 1 } },
    { kind = "monster", band = { 28, 28 }, key = "imp", count = { 1, 2 } },
    { kind = "monster", band = { 29, 31 }, key = "leucrotta", count = { 1, 2 } },
    { kind = "monster", band = { 32, 50 }, key = "fire_lizard", count = { 1, 3 } },
    { kind = "monster", band = { 51, 52 }, key = "wereboar", count = { 1, 3 } },
    { kind = "monster", band = { 53, 60 }, key = "minotaur", count = { 1, 3 } },
    { kind = "monster", band = { 61, 64 }, key = "yellow_mold", count = { 1, 1 } },
    { kind = "monster", band = { 65, 65 }, key = "quasit", count = { 1, 1 } },
    { kind = "monster", band = { 66, 67 }, key = "rust_monster", count = { 1, 1 } },
    { kind = "monster", band = { 68, 70 }, key = "shrieker", count = { 2, 5 } },
    { kind = "monster", band = { 71, 72 }, key = "slithering_tracker", count = { 1, 1 } },
    { kind = "monster", band = { 73, 74 }, key = "amphisbaena_snake", count = { 1, 1 } },
    { kind = "monster", band = { 75, 82 }, key = "poisonous_snake", count = { 1, 1 } },
    { kind = "monster", band = { 83, 86 }, key = "spitting_snake", count = { 1, 1 } },
    { kind = "monster", band = { 87, 100 }, key = "giant_spider", count = { 1, 2 } },
  },
}
