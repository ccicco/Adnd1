-- encounter table def: castle_inh_large
-- The R67 castle family (R1038 de-wire): CASTLE TABLE II, the large castle inhabitants
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- band = the percentile column; cat = the printed category token (totally_deserted / deserted_monster / humans / character_types).
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

return {
  key = "castle_inh_large",
  rows = {
    { band = {1,15}, cat = "totally_deserted" },
    { band = {16,40}, cat = "deserted_monster" },
    { band = {41,60}, cat = "humans" },
    { band = {61,100}, cat = "character_types" },
  },
}
