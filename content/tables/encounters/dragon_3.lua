-- encounter table def: dragon_3
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dragon_3",
  rows = {
    { band = { 1, 28 }, key = "black_dragon", age = { 1, 1 } },
    { band = { 29, 62 }, key = "brass_dragon", age = { 1, 1 } },
    { band = { 63, 100 }, key = "white_dragon", age = { 1, 1 } },
  },
}
