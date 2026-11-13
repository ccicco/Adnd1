-- encounter table def: dungeon_level_10
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_10",
  rows = {
    { kind = "monster", band = { 1, 12 }, key = "beholder", count = { 1, 1 } },
    { kind = "character", band = { 13, 20 } },
    { kind = "prince", band = { 21, 28 } },
    { kind = "prince", band = { 29, 30 } },
    { kind = "dragon", band = { 31, 40 } },
    { kind = "monster", band = { 41, 50 }, key = "iron_golem", count = { 1, 1 } },
    { kind = "monster", band = { 51, 60 }, key = "lich", count = { 1, 1 } },
    { kind = "monster", band = { 61, 70 }, key = "elder_titan_ac_2", count = { 1, 1 } },
    { kind = "monster", band = { 71, 80 }, key = "vampire", count = { 1, 1 } },
    { kind = "none", band = { 81, 100 } },
  },
}
