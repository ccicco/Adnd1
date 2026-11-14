-- encounter table def: outdoor_sub_undead
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
  key = "outdoor_sub_undead",
  rows = {
    { key = "ghost", cols = { {-1,-1}, {-1,-1}, {1,10}, {1,15}, {-1,-1}, {1,10}, {1,10}, {1,15} } },
    { key = "ghast", cols = { {-1,-1}, {-1,-1}, {11,12}, {16,20}, {-1,-1}, {11,12}, {11,13}, {16,18} } },
    { key = "ghoul", cols = { {-1,-1}, {-1,-1}, {13,55}, {21,55}, {-1,-1}, {13,35}, {14,30}, {19,75} } },
    { key = "lich", cols = { {-1,-1}, {-1,-1}, {56,56}, {56,60}, {-1,-1}, {36,40}, {31,35}, {-1,-1} } },
    { key = "mummy", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {61,70}, {-1,-1}, {41,55}, {36,40}, {-1,-1} } },
    { key = "shadow", cols = { {-1,-1}, {-1,-1}, {57,70}, {71,84}, {-1,-1}, {56,61}, {41,50}, {76,81} } },
    { key = "spectre", cols = { {-1,-1}, {-1,-1}, {71,79}, {85,87}, {-1,-1}, {62,64}, {51,60}, {82,91} } },
    { key = "vampire", cols = { {-1,-1}, {-1,-1}, {80,89}, {88,89}, {-1,-1}, {65,74}, {61,75}, {92,93} } },
    { key = "wight", cols = { {-1,-1}, {-1,-1}, {90,96}, {90,98}, {-1,-1}, {75,97}, {76,94}, {-1,-1} } },
    { key = "wraith", cols = { {-1,-1}, {-1,-1}, {97,100}, {99,100}, {-1,-1}, {98,100}, {95,100}, {94,100} } },
  },
}
