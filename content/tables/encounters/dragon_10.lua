-- encounter table def: dragon_10
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dragon_10",
  rows = {
    { band = { 1, 20 }, key = "blue_dragon", age = { 7, 8 } },
    { band = { 21, 26 }, key = "bronze_dragon", age = { 7, 8 } },
    { band = { 27, 33 }, key = "copper_dragon", age = { 7, 8 } },
    { band = { 34, 35 }, key = "chromatic_dragon", age = { 8, 8 } },
    { band = { 36, 40 }, key = "gold_dragon", age = { 6, 8 } },
    { band = { 41, 60 }, key = "green_dragon", age = { 7, 8 } },
    { band = { 61, 63 }, key = "platinum_dragon", age = { 8, 8 } },
    { band = { 64, 94 }, key = "red_dragon", age = { 6, 8 } },
    { band = { 95, 100 }, key = "silver_dragon", age = { 6, 8 } },
  },
}
