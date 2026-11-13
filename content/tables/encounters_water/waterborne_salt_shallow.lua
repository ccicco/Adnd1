-- encounter table def: waterborne_salt_shallow
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
  key = "waterborne_salt_shallow",
  rows = {
    { band = { 1, 2 }, key = "giant_crocodile", flags = 2 },
    { band = { 3, 10 }, key = "DINOSAUR", flags = 0 },
    { band = { 11, 17 }, key = "dolphin", flags = 0 },
    { band = { 18, 18 }, key = "dragon_turtle", flags = 0 },
    { band = { 19, 20 }, key = "elf", flags = 0 },
    { band = { 21, 21 }, key = "ixitxachitl", flags = 0 },
    { band = { 22, 23 }, key = "hobgoblin", flags = 0 },
    { band = { 24, 24 }, key = "gargoyle", flags = 0 },
    { band = { 25, 25 }, key = "ghoul", flags = 0 },
    { band = { 26, 26 }, key = "locathah", flags = 0 },
    { band = { 27, 35 }, key = "buccaneer", flags = 0 },
    { band = { 36, 63 }, key = "merchant", flags = 0 },
    { band = { 64, 67 }, key = "buccaneer", flags = 0 },
    { band = { 68, 70 }, key = "caveman", flags = 0 },
    { band = { 71, 73 }, key = "merman", flags = 0 },
    { band = { 74, 74 }, key = "nymph", flags = 0 },
    { band = { 75, 75 }, key = "giant_octopus", flags = 0 },
    { band = { 76, 80 }, key = "sahuagin", flags = 0 },
    { band = { 81, 83 }, key = "giant_shark", flags = 0 },
    { band = { 84, 86 }, key = "sea_snake", flags = 0 },
    { band = { 87, 89 }, key = "triton", flags = 0 },
    { band = { 90, 90 }, key = "sea_turtle", flags = 0 },
    { band = { 91, 96 }, key = "black_whale", flags = 0 },
    { band = { 97, 100 }, key = "white_whale_beluga", flags = 0 },
  },
}
