-- encounter table def: dungeon_level_8
-- The DMG Appendix C dungeon tables (R52 print-fidelity record,
-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py
-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in
-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.


return {
  key = "dungeon_level_8",
  rows = {
    { kind = "monster", band = { 1, 1 }, key = "aerial_servant", count = { 1, 1 } },
    { kind = "character", band = { 2, 6 } },
    { kind = "monster", band = { 7, 7 }, key = "type_iv_demon_nalfeshnee", count = { 1, 1 } },
    { kind = "monster", band = { 8, 8 }, key = "type_v_demon_marilith", count = { 1, 1 } },
    { kind = "monster", band = { 9, 9 }, key = "type_vi_demon_balor", count = { 1, 1 } },
    { kind = "monster", band = { 10, 10 }, key = "ice_devil", count = { 1, 1 } },
    { kind = "dragon", band = { 11, 12 } },
    { kind = "monster", band = { 13, 17 }, key = "ghost", count = { 1, 1 } },
    { kind = "monster", band = { 18, 21 }, key = "cloud_giant", count = { 1, 2 } },
    { kind = "monster", band = { 22, 23 }, key = "clay_golem", count = { 1, 1 } },
    { kind = "hydra", band = { 24, 26 }, key = "hydra", heads = { 13, 16 }, number = { 1, 1 } },
    { kind = "hydra", band = { 27, 27 }, key = "hydra", heads = { 12, 12 }, number = { 1, 1 } },
    { kind = "monster", band = { 28, 29 }, key = "intellect_devourer", count = { 1, 2 } },
    { kind = "monster", band = { 30, 35 }, key = "lurker_above", count = { 1, 1 } },
    { kind = "monster", band = { 36, 41 }, key = "brown_mold", count = { 1, 1 } },
    { kind = "monster", band = { 42, 43 }, key = "yellow_mold", count = { 1, 1 } },
    { kind = "monster", band = { 44, 47 }, key = "mind_flayer", count = { 1, 4 } },
    { kind = "monster", band = { 48, 50 }, key = "guardian_naga", count = { 1, 2 } },
    { kind = "monster", band = { 51, 56 }, key = "neo_otyugh", count = { 1, 1 } },
    { kind = "monster", band = { 57, 64 }, key = "purple_worm", count = { 1, 1 } },
    { kind = "monster", band = { 65, 69 }, key = "rust_monster", count = { 1, 1 } },
    { kind = "monster", band = { 70, 73 }, key = "giant_slug", count = { 1, 1 } },
    { kind = "monster", band = { 74, 78 }, key = "trapper", count = { 1, 1 } },
    { kind = "monster", band = { 79, 86 }, key = "vampire", count = { 1, 1 } },
    { kind = "monster", band = { 87, 92 }, key = "will_o_wisp", count = { 2, 5 } },
    { kind = "monster", band = { 93, 100 }, key = "xorn", count = { 2, 5 } },
  },
}
