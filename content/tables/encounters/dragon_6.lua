-- encounter table def: dragon_6
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dragon_6",
  rows = {
    { band = { 1, 8 }, key = "black_dragon", age = { 6, 6 } },
    { band = { 9, 19 }, key = "blue_dragon", age = { 5, 5 } },
    { band = { 20, 29 }, key = "brass_dragon", age = { 6, 6 } },
    { band = { 30, 36 }, key = "bronze_dragon", age = { 5, 5 } },
    { band = { 37, 48 }, key = "copper_dragon", age = { 5, 5 } },
    { band = { 49, 52 }, key = "gold_dragon", age = { 5, 5 } },
    { band = { 53, 65 }, key = "green_dragon", age = { 5, 5 } },
    { band = { 66, 78 }, key = "red_dragon", age = { 5, 5 } },
    { band = { 79, 87 }, key = "silver_dragon", age = { 5, 5 } },
    { band = { 88, 100 }, key = "white_dragon", age = { 6, 6 } },
  },
}
