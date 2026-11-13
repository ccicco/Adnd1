-- encounter table def: dungeon_level_4
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_4",
  rows = {
    { kind = "monster", band = { 1, 8 }, key = "carnivorous_ape", count = { 1, 3 } },
    { kind = "monster", band = { 9, 14 }, key = "blink_dog", count = { 2, 5 } },
    { kind = "character", band = { 15, 22 } },
    { kind = "dragon", band = { 23, 24 } },
    { kind = "monster", band = { 25, 30 }, key = "gargoyle", count = { 1, 2 } },
    { kind = "monster", band = { 31, 36 }, key = "ghost", count = { 1, 4 } },
    { kind = "monster", band = { 37, 40 }, key = "gray_ooze", count = { 1, 1 } },
    { kind = "monster", band = { 41, 44 }, key = "hell_hound", count = { 1, 2 } },
    { kind = "hydra", band = { 45, 47 }, key = "hydra", heads = { 5, 6 }, number = { 1, 1 } },
    { kind = "hydra", band = { 48, 48 }, key = "hydra", heads = { 5, 5 }, number = { 1, 1 } },
    { kind = "monster", band = { 49, 62 }, key = "werewolf", count = { 1, 2 } },
    { kind = "monster", band = { 63, 75 }, key = "yellow_mold", count = { 1, 1 } },
    { kind = "monster", band = { 76, 78 }, key = "owlbear", count = { 1, 2 } },
    { kind = "monster", band = { 79, 79 }, key = "rust_monster", count = { 1, 1 } },
    { kind = "monster", band = { 80, 82 }, key = "shadow", count = { 1, 3 } },
    { kind = "monster", band = { 83, 90 }, key = "constrictor_snake", count = { 1, 1 } },
    { kind = "monster", band = { 91, 94 }, key = "su_monster", count = { 1, 2 } },
    { kind = "monster", band = { 95, 96 }, key = "ice_toad", count = { 1, 1 } },
    { kind = "monster", band = { 97, 100 }, key = "poisonous_toad", count = { 1, 3 } },
  },
}
