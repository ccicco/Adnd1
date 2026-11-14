-- encounter table def: outdoor_dinosaur_age
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
  key = "outdoor_dinosaur_age",
  rows = {
    { key = "anatosaurus", cols = { {1,10}, {1,6}, {1,8}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {1,12} } },
    { key = "ankylosaurus", cols = { {11,12}, {7,10}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "antrodemus", cols = { {-1,-1}, {11,12}, {9,14}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "apatosaurus", cols = { {13,13}, {13,13}, {15,19}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {13,18} } },
    { key = "brachiosaurus", cols = { {14,14}, {14,14}, {20,20}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {19,23} } },
    { key = "camarasaurus", cols = { {15,15}, {15,17}, {21,23}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {24,28} } },
    { key = "ceratosaurus", cols = { {-1,-1}, {18,22}, {24,28}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "cetiosaurus", cols = { {16,16}, {23,23}, {29,29}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {29,34} } },
    { key = "giant_crocodile", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {35,40} } },
    { key = "diplodocus", cols = { {17,17}, {24,24}, {30,30}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {41,48} } },
    { key = "gorgosaurus", cols = { {18,20}, {25,28}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "IGUANODON_SET", cols = { {21,40}, {29,35}, {31,40}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {49,56} } },
    { key = "giant_lizard", cols = { {-1,-1}, {-1,-1}, {41,45}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {57,60} } },
    { key = "minotaur_lizard", cols = { {41,42}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {61,63} } },
    { key = "megalosaurus", cols = { {-1,-1}, {-1,-1}, {46,50}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "monoclonius", cols = { {43,46}, {36,41}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "MISC_REPTILE", cols = { {47,53}, {42,47}, {51,55}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {64,65} } },
    { key = "megalosaurus", cols = { {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {66,71} } },
    { key = "paleoscincus", cols = { {-1,-1}, {-1,-1}, {56,63}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {72,76} } },
    { key = "pentaceratops", cols = { {54,67}, {48,54}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "plateosaurus", cols = { {-1,-1}, {55,60}, {64,80}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "pteranodon", cols = { {68,69}, {61,62}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {77,82} } },
    { key = "pteranodon", cols = { {70,76}, {63,67}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {83,89} } },
    { key = "constrictor_snake", cols = { {-1,-1}, {68,69}, {81,85}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {90,100} } },
    { key = "stegosaurus", cols = { {-1,-1}, {70,82}, {86,95}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "styracosaurus", cols = { {77,79}, {83,87}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "teratosaurus", cols = { {80,82}, {88,89}, {96,100}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "triceratops", cols = { {83,92}, {90,95}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
    { key = "tyrannosaurus_rex", cols = { {93,100}, {96,100}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1} } },
  },
}
