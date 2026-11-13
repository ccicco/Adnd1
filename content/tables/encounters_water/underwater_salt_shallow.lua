-- encounter table def: underwater_salt_shallow
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
  key = "underwater_salt_shallow",
  rows = {
    { band = { 1, 2 }, key = "barracuda", flags = 0 },
    { band = { 3, 5 }, key = "giant_crab", flags = 0 },
    { band = { 6, 6 }, key = "giant_crayfish", flags = 0 },
    { band = { 7, 8 }, key = "DINOSAUR", flags = 0 },
    { band = { 9, 12 }, key = "dolphin", flags = 0 },
    { band = { 13, 13 }, key = "giant_eel", flags = 0 },
    { band = { 14, 17 }, key = "weed", flags = 0 },
    { band = { 18, 19 }, key = "elf", flags = 0 },
    { band = { 20, 21 }, key = "floating_eye", flags = 0 },
    { band = { 22, 22 }, key = "storm_giant", flags = 0 },
    { band = { 23, 26 }, key = "hippocampus", flags = 0 },
    { band = { 27, 28 }, key = "ixitxachitl", flags = 0 },
    { band = { 29, 34 }, key = "hobgoblin", flags = 0 },
    { band = { 35, 36 }, key = "gargoyle", flags = 0 },
    { band = { 37, 38 }, key = "ghoul", flags = 0 },
    { band = { 39, 41 }, key = "locathah", flags = 0 },
    { band = { 42, 43 }, key = "masher", flags = 0 },
    { band = { 44, 46 }, key = "merman", flags = 0 },
    { band = { 47, 47 }, key = "nymph", flags = 0 },
    { band = { 48, 49 }, key = "ochre_jelly", flags = 0 },
    { band = { 50, 51 }, key = "octopus", flags = 0 },
    { band = { 52, 54 }, key = "portuguese_man_o_war", flags = 0 },
    { band = { 55, 56 }, key = "manta_ray", flags = 0 },
    { band = { 57, 58 }, key = "pungi_ray", flags = 0 },
    { band = { 59, 60 }, key = "sting_ray", flags = 0 },
    { band = { 61, 65 }, key = "sahuagin", flags = 0 },
    { band = { 66, 66 }, key = "sea_hag", flags = 0 },
    { band = { 67, 72 }, key = "sea_horse", flags = 0 },
    { band = { 73, 78 }, key = "sea_lion", flags = 0 },
    { band = { 79, 81 }, key = "shark", flags = 0 },
    { band = { 82, 82 }, key = "giant_shark", flags = 0 },
    { band = { 83, 83 }, key = "sea_snake", flags = 0 },
    { band = { 84, 84 }, key = "giant_squid", flags = 0 },
    { band = { 85, 87 }, key = "strangle_weed", flags = 0 },
    { band = { 88, 90 }, key = "triton", flags = 0 },
    { band = { 91, 91 }, key = "sea_turtle", flags = 0 },
    { band = { 92, 92 }, key = "sperm_whale", flags = 0 },
    { band = { 93, 93 }, key = "killer_whale", flags = 0 },
    { band = { 94, 96 }, key = "black_whale", flags = 0 },
    { band = { 97, 97 }, key = "whale", flags = 0 },
    { band = { 98, 98 }, key = "right_whale", flags = 0 },
    { band = { 99, 100 }, key = "white_whale_beluga", flags = 0 },
  },
}
