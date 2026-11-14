-- encounter table def: character_subtable
-- The R53/R55 party family (R1039 de-wire): the Character Subtable
-- (DMG Appendix C Premium reprint p.176-177, OCR-verified).
-- band = the percentile column; prof = the printed profession token; max = the per-profession maximum per party (the DMG "ignore such rolls" advice). The monk-or-bard row shares the monk_bard token (the R1038 convention).
-- DO NOT hand-edit: tools/r1039_splice.py is the only writer.

return {
  key = "character_subtable",
  rows = {
    { band = {1,17}, prof = "cleric", max = 3 },
    { band = {18,20}, prof = "druid", max = 2 },
    { band = {21,60}, prof = "fighter", max = 5 },
    { band = {61,62}, prof = "paladin", max = 2 },
    { band = {63,65}, prof = "ranger", max = 2 },
    { band = {66,86}, prof = "magic_user", max = 3 },
    { band = {87,88}, prof = "illusionist", max = 1 },
    { band = {89,98}, prof = "thief", max = 4 },
    { band = {99,99}, prof = "assassin", max = 2 },
    { band = {100,100}, prof = "monk_bard", max = 1 },
  },
}
