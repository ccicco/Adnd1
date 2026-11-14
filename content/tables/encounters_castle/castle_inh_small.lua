-- encounter table def: castle_inh_small
-- The R67 castle family (R1038 de-wire): CASTLE TABLE II, the small castle inhabitants
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- band = the percentile column; cat = the printed category token (totally_deserted / deserted_monster / humans / character_types).
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

return {
  key = "castle_inh_small",
  rows = {
    { band = {1,45}, cat = "totally_deserted" },
    { band = {46,60}, cat = "deserted_monster" },
    { band = {61,70}, cat = "humans" },
    { band = {71,100}, cat = "character_types" },
  },
}
