-- encounter table def: underwater_salt_deep
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
  key = "underwater_salt_deep",
  rows = {
    { band = { 1, 3 }, key = "giant_crayfish", flags = 0 },
    { band = { 4, 5 }, key = "giant_crocodile", flags = 0 },
    { band = { 6, 12 }, key = "DINOSAUR", flags = 0 },
    { band = { 13, 20 }, key = "dolphin", flags = 0 },
    { band = { 21, 21 }, key = "dragon_turtle", flags = 0 },
    { band = { 22, 23 }, key = "giant_eel", flags = 0 },
    { band = { 24, 24 }, key = "eye_of_the_deep", flags = 0 },
    { band = { 25, 25 }, key = "storm_giant", flags = 0 },
    { band = { 26, 30 }, key = "hippocampus", flags = 0 },
    { band = { 31, 33 }, key = "ixitxachitl", flags = 0 },
    { band = { 34, 35 }, key = "hobgoblin", flags = 0 },
    { band = { 36, 38 }, key = "gargoyle", flags = 0 },
    { band = { 39, 40 }, key = "ghoul", flags = 0 },
    { band = { 41, 42 }, key = "giant_lamprey", flags = 0 },
    { band = { 43, 44 }, key = "locathah", flags = 0 },
    { band = { 45, 45 }, key = "masher", flags = 0 },
    { band = { 46, 50 }, key = "merman", flags = 0 },
    { band = { 51, 52 }, key = "morkoth", flags = 0 },
    { band = { 53, 54 }, key = "octopus", flags = 0 },
    { band = { 55, 57 }, key = "manta_ray", flags = 0 },
    { band = { 58, 61 }, key = "sahuagin", flags = 0 },
    { band = { 62, 63 }, key = "sea_hag", flags = 0 },
    { band = { 64, 68 }, key = "sea_horse", flags = 0 },
    { band = { 69, 73 }, key = "sea_lion", flags = 0 },
    { band = { 74, 78 }, key = "giant_shark", flags = 0 },
    { band = { 79, 80 }, key = "sea_snake", flags = 0 },
    { band = { 81, 82 }, key = "giant_squid", flags = 0 },
    { band = { 83, 85 }, key = "triton", flags = 0 },
    { band = { 86, 86 }, key = "sea_turtle", flags = 0 },
    { band = { 87, 88 }, key = "sperm_whale", flags = 0 },
    { band = { 89, 90 }, key = "killer_whale", flags = 0 },
    { band = { 91, 92 }, key = "black_whale", flags = 0 },
    { band = { 93, 95 }, key = "whale", flags = 0 },
    { band = { 96, 98 }, key = "right_whale", flags = 0 },
    { band = { 99, 100 }, key = "white_whale_beluga", flags = 0 },
  },
}
