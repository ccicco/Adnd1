-- encounter table def: underwater_fresh_shallow
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
  key = "underwater_fresh_shallow",
  rows = {
    { band = { 1, 6 }, key = "giant_beaver", flags = 1 },
    { band = { 7, 10 }, key = "giant_crayfish", flags = 0 },
    { band = { 11, 18 }, key = "crocodile", flags = 2 },
    { band = { 19, 20 }, key = "giant_crocodile", flags = 2 },
    { band = { 21, 23 }, key = "DINOSAUR", flags = 2 },
    { band = { 24, 26 }, key = "electric", flags = 2 },
    { band = { 27, 32 }, key = "giant_frog", flags = 0 },
    { band = { 33, 34 }, key = "killer_frog", flags = 0 },
    { band = { 35, 35 }, key = "poisonous_frog", flags = 0 },
    { band = { 36, 40 }, key = "giant_gar", flags = 0 },
    { band = { 41, 42 }, key = "green_slime", flags = 1 },
    { band = { 43, 47 }, key = "hippocampus", flags = 0 },
    { band = { 48, 52 }, key = "hippopotamus", flags = 2 },
    { band = { 53, 56 }, key = "hobgoblin", flags = 0 },
    { band = { 57, 58 }, key = "gargoyle", flags = 0 },
    { band = { 59, 60 }, key = "ghoul", flags = 0 },
    { band = { 61, 65 }, key = "lamprey", flags = 1 },
    { band = { 66, 71 }, key = "giant_leech", flags = 0 },
    { band = { 72, 76 }, key = "lizard_man", flags = 0 },
    { band = { 77, 77 }, key = "water_naga", flags = 0 },
    { band = { 78, 81 }, key = "nixie", flags = 1 },
    { band = { 82, 82 }, key = "nymph", flags = 0 },
    { band = { 83, 87 }, key = "giant_otter", flags = 0 },
    { band = { 88, 90 }, key = "giant_pike", flags = 0 },
    { band = { 91, 94 }, key = "water_spider", flags = 0 },
    { band = { 95, 99 }, key = "snapping_turtle", flags = 0 },
    { band = { 100, 100 }, key = "water_weird", flags = 0 },
  },
}
