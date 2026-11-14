-- encounter table def: outdoor_sub_snake
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
  key = "outdoor_sub_snake",
  rows = {
    { key = "amphisbaena_snake", cols = { {1,10}, {1,5}, {-1,-1}, {-1,-1}, {1,15}, {1,5}, {-1,-1}, {-1,-1} } },
    { key = "constrictor_snake", cols = { {-1,-1}, {6,10}, {1,65}, {1,5}, {-1,-1}, {6,10}, {-1,-1}, {1,70} } },
    { key = "poisonous_snake", cols = { {11,80}, {11,80}, {66,95}, {6,95}, {16,90}, {11,90}, {1,90}, {71,100} } },
    { key = "spitting_snake", cols = { {81,100}, {81,100}, {96,100}, {96,100}, {91,100}, {91,100}, {91,100}, {-1,-1} } },
  },
}
