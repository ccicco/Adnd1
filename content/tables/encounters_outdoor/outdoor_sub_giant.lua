-- encounter table def: outdoor_sub_giant
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
  key = "outdoor_sub_giant",
  rows = {
    { key = "cloud_giant", cols = { {1,2}, {1,2}, {1,2}, {1,2}, {-1,-1}, {1,3}, {1,15}, {-1,-1} } },
    { key = "ettin", cols = { {3,4}, {3,5}, {3,10}, {3,10}, {-1,-1}, {4,10}, {16,20}, {-1,-1} } },
    { key = "fire_giant", cols = { {5,6}, {6,7}, {11,12}, {11,20}, {-1,-1}, {11,15}, {21,30}, {-1,-1} } },
    { key = "frost_giant", cols = { {7,8}, {8,9}, {13,14}, {21,25}, {-1,-1}, {16,20}, {31,45}, {-1,-1} } },
    { key = "hill_giant", cols = { {9,95}, {10,94}, {15,93}, {26,85}, {-1,-1}, {21,81}, {46,50}, {-1,-1} } },
    { key = "stone_giant", cols = { {96,98}, {95,98}, {94,98}, {86,98}, {-1,-1}, {82,98}, {51,90}, {-1,-1} } },
    { key = "storm_giant", cols = { {99,99}, {99,99}, {99,99}, {99,99}, {-1,-1}, {99,99}, {91,98}, {-1,-1} } },
    { key = "titan", cols = { {100,100}, {100,100}, {100,100}, {100,100}, {-1,-1}, {100,100}, {99,100}, {-1,-1} } },
  },
}
