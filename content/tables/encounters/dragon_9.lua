-- encounter table def: dragon_9
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dragon_9",
  rows = {
    { band = { 1, 10 }, key = "black_dragon", age = { 6, 8 } },
    { band = { 11, 22 }, key = "blue_dragon", age = { 8, 8 } },
    { band = { 23, 31 }, key = "brass_dragon", age = { 6, 8 } },
    { band = { 32, 34 }, key = "bronze_dragon", age = { 8, 8 } },
    { band = { 35, 42 }, key = "copper_dragon", age = { 8, 8 } },
    { band = { 43, 46 }, key = "gold_dragon", age = { 8, 8 } },
    { band = { 47, 62 }, key = "green_dragon", age = { 8, 8 } },
    { band = { 63, 78 }, key = "red_dragon", age = { 8, 8 } },
    { band = { 79, 82 }, key = "silver_dragon", age = { 8, 8 } },
    { band = { 83, 100 }, key = "white_dragon", age = { 7, 8 } },
  },
}
