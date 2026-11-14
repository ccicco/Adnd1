-- encounter table def: city_magic
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired rollCityMagicItems chance arrays of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). one row per p.192 magic category; groups = the percent-per-level chance for group 0 (fighter-ish), 1 (cleric/druid), 2 (magic-user).
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

return {
  key = "city_magic",
  rows = {
    { category = "sword", groups = {10,0,0} },
    { category = "misc_weapon", groups = {5,10,5} },
    { category = "armor", groups = {10,10,0} },
    { category = "protection", groups = {2,2,10} },
  },
}
