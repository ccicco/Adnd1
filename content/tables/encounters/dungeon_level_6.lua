-- encounter table def: dungeon_level_6
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_6",
  rows = {
    { kind = "monster", band = { 1, 3 }, key = "basilisk", count = { 1, 1 } },
    { kind = "monster", band = { 4, 10 }, key = "carrion_crawler", count = { 1, 2 } },
    { kind = "character", band = { 11, 16 } },
    { kind = "monster", band = { 17, 17 }, key = "erinyes", count = { 1, 2 } },
    { kind = "monster", band = { 18, 19 }, key = "djinni", count = { 1, 1 } },
    { kind = "dragon", band = { 20, 21 } },
    { kind = "monster", band = { 22, 25 }, key = "green_slime", count = { 1, 1 } },
    { kind = "hydra", band = { 26, 28 }, key = "hydra", heads = { 8, 9 }, number = { 1, 1 } },
    { kind = "monster", band = { 29, 32 }, key = "jackalwere", count = { 1, 2 } },
    { kind = "monster", band = { 33, 36 }, key = "lammasu", count = { 1, 3 } },
    { kind = "monster", band = { 37, 38 }, key = "werebear", count = { 1, 1 } },
    { kind = "monster", band = { 39, 41 }, key = "weretiger", count = { 1, 2 } },
    { kind = "monster", band = { 42, 50 }, key = "manticore", count = { 1, 2 } },
    { kind = "monster", band = { 51, 55 }, key = "medusa", count = { 1, 1 } },
    { kind = "monster", band = { 56, 56 }, key = "brown_mold", count = { 1, 1 } },
    { kind = "monster", band = { 57, 58 }, key = "yellow_mold", count = { 1, 1 } },
    { kind = "monster", band = { 59, 60 }, key = "ogre_magi", count = { 1, 2 } },
    { kind = "monster", band = { 61, 68 }, key = "otyugh", count = { 1, 1 } },
    { kind = "monster", band = { 69, 70 }, key = "rakshasa", count = { 1, 1 } },
    { kind = "monster", band = { 71, 73 }, key = "salamander", count = { 1, 2 } },
    { kind = "monster", band = { 74, 77 }, key = "phase_spider", count = { 1, 3 } },
    { kind = "monster", band = { 78, 88 }, key = "troll", count = { 1, 3 } },
    { kind = "monster", band = { 89, 93 }, key = "wight", count = { 1, 4 } },
    { kind = "monster", band = { 94, 95 }, key = "wind_walker", count = { 1, 2 } },
    { kind = "monster", band = { 96, 98 }, key = "wraith", count = { 1, 2 } },
    { kind = "monster", band = { 99, 100 }, key = "wyvern", count = { 1, 1 } },
  },
}
