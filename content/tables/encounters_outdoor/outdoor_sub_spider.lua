-- encounter table def: outdoor_sub_spider
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
  key = "outdoor_sub_spider",
  rows = {
    { key = "giant_spider", cols = { {-1,-1}, {-1,-1}, {1,55}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "huge_spider", cols = { {1,15}, {1,25}, {56,75}, {1,20}, {-1,-1}, {1,20}, {-1,-1}, {-1,-1} } },
    { key = "large_spider", cols = { {16,100}, {26,100}, {76,80}, {21,100}, {1,100}, {21,100}, {-1,-1}, {-1,-1} } },
    { key = "phase_spider", cols = { {-1,-1}, {-1,-1}, {81,100}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
  },
}
