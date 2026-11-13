-- encounter table def: waterborne_fresh_large
-- The DMG Appendix C water encounter tables (R1033
-- de-wire): extracted verbatim from the retired
-- WaterRow arrays of dm/encounters.cpp (R60 underwater
-- set, Premium reprint p.179-181; R127 waterborne set,
-- p.190; the shared p.190 Dinosaur Subtable). flags
-- carries the footnote gates: 1 = cool waters only,
-- 2 = warm waters only, 4 = deep water only. In-row
-- substitutions and as-printed discrepancies are
-- documented in dm/encounters.cpp. DO NOT hand-edit:
-- tools/r1033_splice.py is the only writer.


return {
  key = "waterborne_fresh_large",
  rows = {
    { band = { 1, 2 }, key = "giant_beaver", flags = 1 },
    { band = { 3, 4 }, key = "giant_crayfish", flags = 0 },
    { band = { 5, 6 }, key = "crocodile", flags = 2 },
    { band = { 7, 10 }, key = "giant_crocodile", flags = 2 },
    { band = { 11, 15 }, key = "DINOSAUR", flags = 2 },
    { band = { 16, 21 }, key = "giant_gar", flags = 0 },
    { band = { 22, 23 }, key = "hippopotamus", flags = 2 },
    { band = { 24, 26 }, key = "hobgoblin", flags = 0 },
    { band = { 27, 28 }, key = "gargoyle", flags = 0 },
    { band = { 29, 29 }, key = "ghoul", flags = 0 },
    { band = { 30, 33 }, key = "lizard_man", flags = 0 },
    { band = { 34, 48 }, key = "buccaneer", flags = 0 },
    { band = { 49, 78 }, key = "merchant", flags = 0 },
    { band = { 79, 84 }, key = "buccaneer", flags = 0 },
    { band = { 85, 85 }, key = "water_naga", flags = 0 },
    { band = { 86, 90 }, key = "nixie", flags = 2 },
    { band = { 91, 93 }, key = "giant_otter", flags = 0 },
    { band = { 94, 97 }, key = "giant_pike", flags = 0 },
    { band = { 98, 99 }, key = "snapping_turtle", flags = 0 },
    { band = { 100, 100 }, key = "water_weird", flags = 0 },
  },
}
