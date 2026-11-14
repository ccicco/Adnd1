-- encounter table def: outdoor_sub_humanoid
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
  key = "outdoor_sub_humanoid",
  rows = {
    { key = "gnoll", cols = { {1,5}, {1,10}, {1,10}, {1,20}, {-1,-1}, {1,25}, {1,15}, {1,25} } },
    { key = "goblin", cols = { {6,10}, {11,15}, {11,20}, {21,30}, {1,40}, {26,50}, {16,50}, {26,35} } },
    { key = "hobgoblin", cols = { {11,15}, {16,50}, {21,30}, {31,50}, {41,90}, {51,75}, {51,65}, {36,75} } },
    { key = "kobold", cols = { {-1,-1}, {51,80}, {31,80}, {51,55}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "orc", cols = { {16,100}, {81,100}, {81,100}, {56,100}, {91,100}, {76,100}, {66,100}, {76,100} } },
  },
}
