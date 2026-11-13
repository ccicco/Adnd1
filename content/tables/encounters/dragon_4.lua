-- encounter table def: dragon_4
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dragon_4",
  rows = {
    { band = { 1, 9 }, key = "black_dragon", age = { 2, 3 } },
    { band = { 10, 20 }, key = "blue_dragon", age = { 1, 2 } },
    { band = { 21, 30 }, key = "brass_dragon", age = { 2, 3 } },
    { band = { 31, 37 }, key = "bronze_dragon", age = { 1, 2 } },
    { band = { 38, 50 }, key = "copper_dragon", age = { 1, 2 } },
    { band = { 51, 54 }, key = "gold_dragon", age = { 1, 2 } },
    { band = { 55, 70 }, key = "green_dragon", age = { 1, 2 } },
    { band = { 71, 80 }, key = "red_dragon", age = { 1, 2 } },
    { band = { 81, 88 }, key = "silver_dragon", age = { 1, 2 } },
    { band = { 89, 100 }, key = "white_dragon", age = { 2, 3 } },
  },
}
