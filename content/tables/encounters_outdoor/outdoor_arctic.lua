-- encounter table def: outdoor_arctic
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
  key = "outdoor_arctic",
  rows = {
    { key = "brown_bear", cols = { {1,10}, {-1,-1}, {-1,-1}, {1,9}, {-1,-1}, {-1,-1}, {1,7}, {-1,-1} } },
    { key = "white_dragon", cols = { {11,12}, {-1,-1}, {-1,-1}, {10,12}, {-1,-1}, {-1,-1}, {8,15}, {-1,-1} } },
    { key = "frost_giant", cols = { {13,15}, {-1,-1}, {-1,-1}, {13,15}, {-1,-1}, {-1,-1}, {16,20}, {-1,-1} } },
    { key = "herd_animal", cols = { {16,55}, {-1,-1}, {-1,-1}, {16,55}, {-1,-1}, {-1,-1}, {21,55}, {-1,-1} } },
    { key = "caveman", cols = { {56,65}, {-1,-1}, {-1,-1}, {56,60}, {-1,-1}, {-1,-1}, {56,60}, {-1,-1} } },
    { key = "giant_owl", cols = { {66,70}, {-1,-1}, {-1,-1}, {61,70}, {-1,-1}, {-1,-1}, {61,70}, {-1,-1} } },
    { key = "remorhaz", cols = { {71,72}, {-1,-1}, {-1,-1}, {71,75}, {-1,-1}, {-1,-1}, {71,72}, {-1,-1} } },
    { key = "constrictor_snake", cols = { {73,74}, {-1,-1}, {-1,-1}, {76,80}, {-1,-1}, {-1,-1}, {73,75}, {-1,-1} } },
    { key = "ice_toad", cols = { {75,80}, {-1,-1}, {-1,-1}, {81,83}, {-1,-1}, {-1,-1}, {76,80}, {-1,-1} } },
    { key = "wolf", cols = { {81,90}, {-1,-1}, {-1,-1}, {84,91}, {-1,-1}, {-1,-1}, {81,86}, {-1,-1} } },
    { key = "winter_wolf", cols = { {91,95}, {-1,-1}, {-1,-1}, {92,95}, {-1,-1}, {-1,-1}, {87,90}, {-1,-1} } },
    { key = "yeti", cols = { {96,100}, {-1,-1}, {-1,-1}, {96,100}, {-1,-1}, {-1,-1}, {91,100}, {-1,-1} } },
  },
}
