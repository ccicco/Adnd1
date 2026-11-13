-- encounter table def: dragon_8
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dragon_8",
  rows = {
    { band = { 1, 13 }, key = "black_dragon", age = { 8, 8 } },
    { band = { 14, 24 }, key = "blue_dragon", age = { 7, 7 } },
    { band = { 25, 31 }, key = "brass_dragon", age = { 8, 8 } },
    { band = { 32, 35 }, key = "bronze_dragon", age = { 7, 7 } },
    { band = { 36, 43 }, key = "copper_dragon", age = { 7, 7 } },
    { band = { 44, 47 }, key = "gold_dragon", age = { 7, 7 } },
    { band = { 48, 62 }, key = "green_dragon", age = { 7, 7 } },
    { band = { 63, 78 }, key = "red_dragon", age = { 7, 7 } },
    { band = { 79, 82 }, key = "silver_dragon", age = { 7, 7 } },
    { band = { 83, 100 }, key = "white_dragon", age = { 8, 8 } },
  },
}
