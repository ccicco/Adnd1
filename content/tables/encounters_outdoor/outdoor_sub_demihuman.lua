-- encounter table def: outdoor_sub_demihuman
-- The DMG Appendix C outdoor (wilderness) encounter tables
-- (R1034 de-wire): extracted verbatim from the retired OutdoorRow
-- arrays of dm/encounters.cpp (R63 climate tables and SUB_*
-- subtables, Premium reprint p.182-191, OCR-verified; the tropical
-- Sphinx footnote p.189). cols carries one percentile band per
-- terrain column (Plain, Scrub, Forest, Rough, Desert, Hills,
-- Mountains, Marsh), -1 = the row prints no entry there. The
-- substitution and OCR-fold provenance lives in the R1034 seam
-- comment in dm/encounters.cpp. DO NOT hand-edit:
-- tools/r1034_splice.py is the only writer.



return {
  key = "outdoor_sub_demihuman",
  rows = {
    { key = "dwarf", cols = { {1,5}, {1,5}, {1,5}, {1,10}, {-1,-1}, {1,20}, {1,70}, {-1,-1} } },
    { key = "elf", cols = { {6,70}, {6,60}, {6,70}, {11,15}, {-1,-1}, {21,30}, {71,75}, {-1,-1} } },
    { key = "gnome", cols = { {71,80}, {61,80}, {71,95}, {16,85}, {-1,-1}, {31,70}, {76,95}, {-1,-1} } },
    { key = "halfling", cols = { {81,100}, {81,100}, {96,100}, {86,100}, {-1,-1}, {71,100}, {96,100}, {-1,-1} } },
  },
}
