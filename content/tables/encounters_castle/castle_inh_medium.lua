-- encounter table def: castle_inh_medium
-- The R67 castle family (R1038 de-wire): CASTLE TABLE II, the medium castle inhabitants
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- band = the percentile column; cat = the printed category token (totally_deserted / deserted_monster / humans / character_types).
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

return {
  key = "castle_inh_medium",
  rows = {
    { band = {1,30}, cat = "totally_deserted" },
    { band = {31,50}, cat = "deserted_monster" },
    { band = {51,65}, cat = "humans" },
    { band = {66,100}, cat = "character_types" },
  },
}
