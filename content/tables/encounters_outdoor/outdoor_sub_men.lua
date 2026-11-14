-- encounter table def: outdoor_sub_men
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
  key = "outdoor_sub_men",
  rows = {
    { key = "bandit", cols = { {1,5}, {1,10}, {1,10}, {1,10}, {1,5}, {1,10}, {1,5}, {1,5} } },
    { key = "berserker", cols = { {6,7}, {11,12}, {-1,-1}, {11,12}, {-1,-1}, {11,12}, {6,10}, {-1,-1} } },
    { key = "bandit", cols = { {8,10}, {13,15}, {11,15}, {13,15}, {6,10}, {13,20}, {11,20}, {6,10} } },
    { key = "SUB_CHARACTER", cols = { {11,20}, {16,25}, {16,25}, {16,25}, {11,20}, {21,30}, {21,30}, {11,20} } },
    { key = "dervish", cols = { {21,22}, {26,27}, {-1,-1}, {26,27}, {21,50}, {31,40}, {31,35}, {-1,-1} } },
    { key = "merchant", cols = { {23,60}, {28,60}, {26,40}, {28,50}, {51,75}, {41,65}, {36,50}, {21,35} } },
    { key = "dervish", cols = { {61,90}, {61,80}, {-1,-1}, {51,60}, {76,95}, {66,80}, {-1,-1}, {-1,-1} } },
    { key = "pilgrim", cols = { {91,95}, {81,85}, {41,45}, {61,80}, {96,100}, {81,90}, {51,65}, {36,50} } },
    { key = "caveman", cols = { {96,100}, {86,100}, {46,100}, {81,100}, {-1,-1}, {91,100}, {66,100}, {51,100} } },
  },
}
