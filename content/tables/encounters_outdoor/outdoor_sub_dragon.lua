-- encounter table def: outdoor_sub_dragon
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
  key = "outdoor_sub_dragon",
  rows = {
    { key = "black_dragon", cols = { {1,2}, {1,2}, {1,16}, {1,30}, {1,2}, {1,6}, {1,4}, {1,50} } },
    { key = "blue_dragon", cols = { {3,4}, {3,4}, {17,18}, {31,32}, {3,20}, {7,10}, {5,15}, {51,52} } },
    { key = "brass_dragon", cols = { {5,6}, {5,6}, {19,20}, {33,40}, {21,65}, {11,20}, {16,17}, {53,54} } },
    { key = "bronze_dragon", cols = { {7,8}, {7,8}, {21,22}, {41,45}, {66,67}, {21,25}, {18,25}, {55,56} } },
    { key = "chimera", cols = { {9,10}, {9,10}, {23,30}, {46,50}, {68,70}, {26,35}, {26,30}, {57,58} } },
    { key = "copper_dragon", cols = { {11,12}, {11,14}, {31,35}, {51,55}, {71,80}, {36,45}, {31,40}, {59,60} } },
    { key = "gold_dragon", cols = { {13,28}, {15,16}, {36,40}, {56,57}, {81,82}, {46,50}, {41,45}, {61,62} } },
    { key = "green_dragon", cols = { {29,30}, {17,36}, {41,80}, {58,59}, {83,84}, {51,52}, {46,47}, {63,75} } },
    { key = "red_dragon", cols = { {31,32}, {37,38}, {81,82}, {60,64}, {85,88}, {53,60}, {48,60}, {76,77} } },
    { key = "white_dragon", cols = { {33,34}, {39,40}, {83,84}, {65,66}, {89,90}, {61,65}, {61,95}, {78,79} } },
    { key = "wyvern", cols = { {35,100}, {41,100}, {85,100}, {67,100}, {91,100}, {66,100}, {96,100}, {80,100} } },
  },
}
