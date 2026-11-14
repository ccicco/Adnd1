-- encounter table def: city_band_ruffian
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired kRuffianKinds (R174) of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). the p.191 ruffian 1-in-4 matrix footnote, banded as five equal fifths of the quarter (fiction-only).
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

return {
  key = "city_band_ruffian",
  rows = {
    { band = {1,75}, kind = "human" },
    { band = {76,80}, kind = "half-orc" },
    { band = {81,85}, kind = "goblin" },
    { band = {86,90}, kind = "hobgoblin" },
    { band = {91,95}, kind = "kobold" },
    { band = {96,100}, kind = "orc" },
  },
}
