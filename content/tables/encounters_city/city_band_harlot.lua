-- encounter table def: city_band_harlot
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired kHarlotKinds (R146) of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). the p.192 harlot type table (fiction-only descriptors).
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

return {
  key = "city_band_harlot",
  rows = {
    { band = {1,10}, kind = "slovenly trull" },
    { band = {11,25}, kind = "brazen strumpet" },
    { band = {26,35}, kind = "cheap trollop" },
    { band = {36,50}, kind = "typical streetwalker" },
    { band = {51,65}, kind = "saucy tart" },
    { band = {66,75}, kind = "wanton wench" },
    { band = {76,85}, kind = "expensive doxy" },
    { band = {86,90}, kind = "haughty courtesan" },
    { band = {91,92}, kind = "aged madam" },
    { band = {93,94}, kind = "wealthy procuress" },
    { band = {95,98}, kind = "sly pimp" },
    { band = {99,100}, kind = "rich panderer" },
  },
}
