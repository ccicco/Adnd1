-- encounter table def: castle_master
-- The R67 castle family (R1038 de-wire): CASTLE SUB-TABLE II.B, the master's class and level
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- band = the percentile column; prof = the printed profession token; level = the printed level range. The OCR overlap (printed Assassin 94-96 / Monk 94-99) is corrected to Assassin 94-96 / Monk 97-99 / Bard 00 (documented); monk and bard share the monk_bard token - the bard row's level (23) is its tell.
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

return {
  key = "castle_master",
  rows = {
    { band = {1,18}, prof = "cleric", level = {9,12} },
    { band = {19,20}, prof = "druid", level = {12,13} },
    { band = {21,65}, prof = "fighter", level = {9,12} },
    { band = {66,66}, prof = "paladin", level = {9,10} },
    { band = {67,68}, prof = "ranger", level = {10,13} },
    { band = {69,80}, prof = "magic_user", level = {11,14} },
    { band = {81,85}, prof = "illusionist", level = {10,13} },
    { band = {86,93}, prof = "thief", level = {10,14} },
    { band = {94,96}, prof = "assassin", level = {14,14} },
    { band = {97,99}, prof = "monk_bard", level = {9,12} },
    { band = {100,100}, prof = "monk_bard", level = {23,23} },
  },
}
