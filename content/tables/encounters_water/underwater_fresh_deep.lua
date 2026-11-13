-- encounter table def: underwater_fresh_deep
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
  key = "underwater_fresh_deep",
  rows = {
    { band = { 1, 1 }, key = "giant_beaver", flags = 1 },
    { band = { 2, 6 }, key = "water_beetle", flags = 0 },
    { band = { 7, 9 }, key = "giant_crayfish", flags = 0 },
    { band = { 10, 14 }, key = "giant_crocodile", flags = 2 },
    { band = { 15, 20 }, key = "DINOSAUR", flags = 2 },
    { band = { 21, 21 }, key = "dragon_turtle", flags = 0 },
    { band = { 22, 25 }, key = "electric", flags = 2 },
    { band = { 26, 32 }, key = "giant_gar", flags = 0 },
    { band = { 33, 34 }, key = "storm_giant", flags = 0 },
    { band = { 35, 36 }, key = "hippocampus", flags = 0 },
    { band = { 37, 38 }, key = "hobgoblin", flags = 0 },
    { band = { 39, 43 }, key = "gargoyle", flags = 0 },
    { band = { 44, 47 }, key = "ghoul", flags = 0 },
    { band = { 48, 55 }, key = "giant_lamprey", flags = 1 },
    { band = { 56, 60 }, key = "lizard_man", flags = 0 },
    { band = { 61, 63 }, key = "purple_worm", flags = 0 },
    { band = { 64, 64 }, key = "water_naga", flags = 0 },
    { band = { 65, 70 }, key = "nixie", flags = 0 },
    { band = { 71, 76 }, key = "giant_otter", flags = 0 },
    { band = { 77, 86 }, key = "giant_pike", flags = 0 },
    { band = { 87, 95 }, key = "water_spider", flags = 0 },
    { band = { 96, 99 }, key = "snapping_turtle", flags = 0 },
    { band = { 100, 100 }, key = "water_weird", flags = 0 },
  },
}
