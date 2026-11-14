-- encounter table def: outdoor_pleistocene
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
  key = "outdoor_pleistocene",
  rows = {
    { key = "axe_beak", cols = { {1,5}, {1,2}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "baluchitherium", cols = { {6,10}, {3,7}, {1,5}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "cave_bear", cols = { {-1,-1}, {-1,-1}, {6,7}, {1,5}, {-1,-1}, {1,5}, {1,20}, {-1,-1} } },
    { key = "giant_boar", cols = { {11,13}, {8,12}, {8,12}, {6,9}, {-1,-1}, {6,10}, {-1,-1}, {-1,-1} } },
    { key = "bull", cols = { {14,16}, {13,14}, {13,14}, {-1,-1}, {-1,-1}, {11,13}, {-1,-1}, {-1,-1} } },
    { key = "wild_camel", cols = { {-1,-1}, {15,17}, {15,17}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "wild_cattle", cols = { {17,21}, {18,20}, {18,19}, {10,11}, {-1,-1}, {14,16}, {-1,-1}, {-1,-1} } },
    { key = "giant_crocodile", cols = { {-1,-1}, {21,23}, {-1,-1}, {12,15}, {-1,-1}, {-1,-1}, {-1,-1}, {1,20} } },
    { key = "flightless_bird", cols = { {22,26}, {24,25}, {-1,-1}, {16,25}, {-1,-1}, {17,20}, {-1,-1}, {21,70} } },
    { key = "herd_animal", cols = { {27,50}, {26,50}, {20,50}, {26,65}, {-1,-1}, {21,50}, {21,50}, {71,90} } },
    { key = "giant_hyena", cols = { {51,55}, {51,55}, {-1,-1}, {66,75}, {-1,-1}, {51,55}, {-1,-1}, {-1,-1} } },
    { key = "irish_deer", cols = { {-1,-1}, {-1,-1}, {51,55}, {-1,-1}, {-1,-1}, {56,60}, {51,60}, {-1,-1} } },
    { key = "spotted_lion", cols = { {56,57}, {56,57}, {56,60}, {76,85}, {-1,-1}, {61,65}, {61,70}, {-1,-1} } },
    { key = "mammoth", cols = { {58,65}, {58,65}, {61,65}, {-1,-1}, {-1,-1}, {66,70}, {-1,-1}, {-1,-1} } },
    { key = "mastodon", cols = { {66,70}, {66,70}, {66,70}, {-1,-1}, {-1,-1}, {71,75}, {-1,-1}, {91,98} } },
    { key = "caveman", cols = { {-1,-1}, {-1,-1}, {71,75}, {86,90}, {-1,-1}, {76,80}, {71,90}, {-1,-1} } },
    { key = "woolly_rhinoceros", cols = { {71,75}, {71,75}, {-1,-1}, {-1,-1}, {-1,-1}, {81,85}, {-1,-1}, {-1,-1} } },
    { key = "giant_stag", cols = { {76,80}, {76,80}, {76,80}, {-1,-1}, {-1,-1}, {86,90}, {-1,-1}, {-1,-1} } },
    { key = "constrictor_snake", cols = { {-1,-1}, {-1,-1}, {81,82}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {99,100} } },
    { key = "sabre_tooth_tiger", cols = { {81,87}, {81,90}, {83,90}, {-1,-1}, {-1,-1}, {91,92}, {-1,-1}, {-1,-1} } },
    { key = "titanotherium", cols = { {88,95}, {91,95}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "giant_weasel", cols = { {96,98}, {96,98}, {91,95}, {-1,-1}, {-1,-1}, {93,95}, {-1,-1}, {-1,-1} } },
    { key = "dire_wolf", cols = { {99,100}, {99,100}, {96,100}, {91,100}, {-1,-1}, {96,100}, {91,100}, {-1,-1} } },
  },
}
