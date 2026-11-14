-- encounter table def: castle_humans
-- The R67 castle family (R1038 de-wire): CASTLE SUB-TABLE II.A, humans are
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- band = the percentile column; key = the bestiary key (brigand -> bandit, the R63 substitution; berserker; dervish) - numbers come from the registry's noAppearing (the R60 convention).
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

return {
  key = "castle_humans",
  rows = {
    { band = {1,25}, key = "bandit" },
    { band = {26,85}, key = "bandit" },
    { band = {86,97}, key = "berserker" },
    { band = {98,100}, key = "dervish" },
  },
}
