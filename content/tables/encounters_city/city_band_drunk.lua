-- encounter table def: city_band_drunk
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired kDrunkKinds (R146) of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). the p.191 drunk identity table (fiction-only descriptors; the app's cityFlavor strings dress the drunk rows with them).
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

return {
  key = "city_band_drunk",
  rows = {
    { band = {1,2}, kind = "assassin" },
    { band = {3,10}, kind = "bandit" },
    { band = {11,18}, kind = "brigand" },
    { band = {19,20}, kind = "city guard" },
    { band = {21,22}, kind = "city official" },
    { band = {23,25}, kind = "city watchman" },
    { band = {26,27}, kind = "cleric" },
    { band = {28,29}, kind = "druid" },
    { band = {30,38}, kind = "fighter" },
    { band = {39,45}, kind = "gentleman" },
    { band = {46,48}, kind = "illusionist" },
    { band = {49,63}, kind = "laborer" },
    { band = {64,65}, kind = "magic-user" },
    { band = {66,73}, kind = "mercenary" },
    { band = {74,80}, kind = "merchant" },
    { band = {81,82}, kind = "noble" },
    { band = {83,90}, kind = "rake" },
    { band = {91,95}, kind = "ruffian" },
    { band = {96,97}, kind = "thief" },
    { band = {98,100}, kind = "tradesman" },
  },
}
