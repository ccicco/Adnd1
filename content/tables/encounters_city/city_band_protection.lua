-- encounter table def: city_band_protection
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired rollProtectionDevice bands of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). the p.192 protection device subtable; the PROT_* enum mapping stays in the engine (the bracers/cloak mechanics are engine code).
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

return {
  key = "city_band_protection",
  rows = {
    { band = {1,25}, kind = "prot_ring1" },
    { band = {26,30}, kind = "prot_ring2" },
    { band = {31,31}, kind = "prot_ring3" },
    { band = {32,32}, kind = "prot_amulet" },
    { band = {33,55}, kind = "prot_bracers6" },
    { band = {56,70}, kind = "prot_bracers4" },
    { band = {71,75}, kind = "prot_bracers2" },
    { band = {76,82}, kind = "prot_displacement" },
    { band = {83,95}, kind = "prot_cloak1" },
    { band = {96,99}, kind = "prot_cloak2" },
    { band = {100,100}, kind = "prot_cloak3" },
  },
}
