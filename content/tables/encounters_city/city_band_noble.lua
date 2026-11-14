-- encounter table def: city_band_noble
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired kNobleKinds (R174) of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). the p.191-192 noble gender coin (fiction-only).
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

return {
  key = "city_band_noble",
  rows = {
    { band = {1,75}, kind = "nobleman" },
    { band = {76,100}, kind = "noblewoman" },
  },
}
