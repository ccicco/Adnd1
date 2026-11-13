-- encounter table def: dragon_5
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dragon_5",
  rows = {
    { band = { 1, 8 }, key = "black_dragon", age = { 4, 5 } },
    { band = { 9, 20 }, key = "blue_dragon", age = { 3, 4 } },
    { band = { 21, 30 }, key = "brass_dragon", age = { 4, 5 } },
    { band = { 31, 37 }, key = "bronze_dragon", age = { 3, 4 } },
    { band = { 38, 50 }, key = "copper_dragon", age = { 3, 4 } },
    { band = { 51, 54 }, key = "gold_dragon", age = { 3, 4 } },
    { band = { 55, 70 }, key = "green_dragon", age = { 3, 4 } },
    { band = { 71, 80 }, key = "red_dragon", age = { 3, 4 } },
    { band = { 81, 88 }, key = "silver_dragon", age = { 3, 4 } },
    { band = { 89, 100 }, key = "white_dragon", age = { 4, 5 } },
  },
}
