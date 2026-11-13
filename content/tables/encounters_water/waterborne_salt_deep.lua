-- encounter table def: waterborne_salt_deep
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
  key = "waterborne_salt_deep",
  rows = {
    { band = { 1, 5 }, key = "DINOSAUR", flags = 0 },
    { band = { 6, 13 }, key = "dolphin", flags = 0 },
    { band = { 14, 14 }, key = "dragon_turtle", flags = 0 },
    { band = { 15, 16 }, key = "buccaneer", flags = 0 },
    { band = { 17, 25 }, key = "merchant", flags = 0 },
    { band = { 26, 27 }, key = "buccaneer", flags = 0 },
    { band = { 28, 35 }, key = "merman", flags = 0 },
    { band = { 36, 40 }, key = "giant_octopus", flags = 0 },
    { band = { 41, 45 }, key = "sahuagin", flags = 0 },
    { band = { 46, 50 }, key = "giant_shark", flags = 0 },
    { band = { 51, 53 }, key = "sea_snake", flags = 0 },
    { band = { 54, 55 }, key = "giant_squid", flags = 0 },
    { band = { 56, 65 }, key = "triton", flags = 0 },
    { band = { 66, 68 }, key = "sea_turtle", flags = 0 },
    { band = { 69, 72 }, key = "sperm_whale", flags = 0 },
    { band = { 73, 78 }, key = "killer_whale", flags = 0 },
    { band = { 79, 85 }, key = "black_whale", flags = 0 },
    { band = { 86, 90 }, key = "whale", flags = 0 },
    { band = { 91, 95 }, key = "right_whale", flags = 0 },
    { band = { 96, 100 }, key = "white_whale_beluga", flags = 0 },
  },
}
