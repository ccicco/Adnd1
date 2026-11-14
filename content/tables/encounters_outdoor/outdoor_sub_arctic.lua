-- encounter table def: outdoor_sub_arctic
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
  key = "outdoor_sub_arctic",
  rows = {
    { key = "brown_bear", cols = { {-1,-1}, {1,5}, {1,10}, {1,5}, {-1,-1}, {1,5}, {-1,-1}, {-1,-1} } },
    { key = "cave_bear", cols = { {-1,-1}, {-1,-1}, {11,15}, {6,10}, {-1,-1}, {6,10}, {1,15}, {-1,-1} } },
    { key = "white_dragon", cols = { {1,5}, {6,10}, {-1,-1}, {11,15}, {-1,-1}, {11,15}, {16,25}, {1,5} } },
    { key = "frost_giant", cols = { {6,10}, {11,15}, {16,20}, {16,20}, {-1,-1}, {16,20}, {26,30}, {-1,-1} } },
    { key = "gnoll", cols = { {11,15}, {16,20}, {21,25}, {21,25}, {-1,-1}, {21,25}, {31,35}, {6,20} } },
    { key = "hell_hound", cols = { {-1,-1}, {-1,-1}, {26,27}, {26,27}, {-1,-1}, {26,27}, {36,40}, {-1,-1} } },
    { key = "herd_animal", cols = { {16,40}, {21,40}, {28,38}, {28,40}, {-1,-1}, {28,50}, {41,60}, {21,50} } },
    { key = "giant_lynx", cols = { {-1,-1}, {-1,-1}, {39,45}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "mammoth", cols = { {41,45}, {41,50}, {46,50}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "mastodon", cols = { {46,55}, {51,55}, {51,55}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {51,55} } },
    { key = "caveman", cols = { {56,65}, {56,65}, {56,65}, {41,50}, {-1,-1}, {51,60}, {-1,-1}, {56,65} } },
    { key = "giant_owl", cols = { {66,70}, {66,70}, {66,70}, {51,55}, {-1,-1}, {61,65}, {61,65}, {66,75} } },
    { key = "giant_ram", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {56,60}, {-1,-1}, {66,70}, {66,70}, {-1,-1} } },
    { key = "giant_rat", cols = { {-1,-1}, {-1,-1}, {71,75}, {61,65}, {-1,-1}, {-1,-1}, {-1,-1}, {76,85} } },
    { key = "remorhaz", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {66,67}, {-1,-1}, {-1,-1}, {71,75}, {-1,-1} } },
    { key = "woolly_rhinoceros", cols = { {71,80}, {71,80}, {-1,-1}, {-1,-1}, {-1,-1}, {71,75}, {-1,-1}, {-1,-1} } },
    { key = "tiger", cols = { {81,90}, {81,90}, {76,80}, {68,75}, {-1,-1}, {76,80}, {-1,-1}, {-1,-1} } },
    { key = "ice_toad", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {86,90} } },
    { key = "troll", cols = { {-1,-1}, {-1,-1}, {81,85}, {76,80}, {-1,-1}, {81,85}, {76,85}, {91,100} } },
    { key = "wolf", cols = { {91,100}, {91,100}, {86,95}, {81,90}, {-1,-1}, {86,92}, {86,92}, {-1,-1} } },
    { key = "winter_wolf", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {93,94}, {93,95}, {-1,-1} } },
    { key = "wolverine", cols = { {-1,-1}, {-1,-1}, {96,98}, {91,96}, {-1,-1}, {95,96}, {-1,-1}, {-1,-1} } },
    { key = "giant_wolverine", cols = { {-1,-1}, {-1,-1}, {99,100}, {97,98}, {-1,-1}, {97,98}, {-1,-1}, {-1,-1} } },
    { key = "yeti", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {99,100}, {-1,-1}, {99,100}, {96,100}, {-1,-1} } },
  },
}
