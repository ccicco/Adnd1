-- encounter table def: dinosaur_sub
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
  key = "dinosaur_sub",
  rows = {
    { band = { 1, 15 }, key = "archelon_ischyros", flags = 0 },
    { band = { 16, 35 }, key = "dinichthys", flags = 4 },
    { band = { 36, 55 }, key = "elasmosaurus", flags = 0 },
    { band = { 56, 75 }, key = "mosasaurus", flags = 0 },
    { band = { 76, 100 }, key = "plesiosaurus", flags = 0 },
  },
}
