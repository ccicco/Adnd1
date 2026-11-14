-- encounter table def: outdoor_sub_sphinx
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
  key = "outdoor_sub_sphinx",
  rows = {
    { key = "androsphinx", cols = { {-1,-1}, {-1,-1}, {1,5}, {1,10}, {1,40}, {1,10}, {1,15}, {1,5} } },
    { key = "criosphinx", cols = { {-1,-1}, {-1,-1}, {6,75}, {11,30}, {41,50}, {11,70}, {16,35}, {6,55} } },
    { key = "gynosphinx", cols = { {-1,-1}, {-1,-1}, {76,80}, {31,50}, {51,90}, {71,80}, {36,55}, {56,65} } },
    { key = "hieracosphinx", cols = { {-1,-1}, {-1,-1}, {81,100}, {51,100}, {91,100}, {81,100}, {56,100}, {66,100} } },
  },
}
