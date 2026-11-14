-- encounter table def: outdoor_sub_lycanthrope
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
  key = "outdoor_sub_lycanthrope",
  rows = {
    { key = "werebear", cols = { {1,2}, {-1,-1}, {1,10}, {1,2}, {-1,-1}, {1,2}, {1,75}, {-1,-1} } },
    { key = "wereboar", cols = { {3,25}, {-1,-1}, {11,70}, {3,15}, {-1,-1}, {3,15}, {-1,-1}, {-1,-1} } },
    { key = "wererat", cols = { {26,30}, {-1,-1}, {-1,-1}, {16,90}, {-1,-1}, {16,20}, {76,80}, {-1,-1} } },
    { key = "weretiger", cols = { {31,40}, {-1,-1}, {71,90}, {-1,-1}, {-1,-1}, {21,30}, {81,90}, {-1,-1} } },
    { key = "werewolf", cols = { {41,100}, {-1,-1}, {91,100}, {91,100}, {-1,-1}, {31,100}, {91,100}, {-1,-1} } },
  },
}
