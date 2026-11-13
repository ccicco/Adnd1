-- encounter table def: waterborne_fresh_small
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
  key = "waterborne_fresh_small",
  rows = {
    { band = { 1, 15 }, key = "giant_beaver", flags = 1 },
    { band = { 16, 30 }, key = "crocodile", flags = 2 },
    { band = { 31, 40 }, key = "hippopotamus", flags = 2 },
    { band = { 41, 60 }, key = "lizard_man", flags = 0 },
    { band = { 61, 65 }, key = "nixie", flags = 1 },
    { band = { 66, 70 }, key = "nymph", flags = 0 },
    { band = { 71, 85 }, key = "giant_otter", flags = 0 },
    { band = { 86, 98 }, key = "snapping_turtle", flags = 0 },
    { band = { 99, 100 }, key = "water_weird", flags = 0 },
  },
}
