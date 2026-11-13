-- encounter table def: lists
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "lists",
  princes = { "demogorgon", "juiblex", "orcus", "yeenoghu" },
  arch_devils = { "asmodeus", "baalzebul", "dispater", "geryon" },
  elementals = { "air_elemental", "earth_elemental", "fire_elemental", "water_elemental" },
  hill_stone = { "hill_giant", "stone_giant" },
  fire_frost = { "fire_giant", "frost_giant" },
  piercers = { "piercer_smallest", "piercer_small", "piercer_medium", "piercer_largest" },
}
