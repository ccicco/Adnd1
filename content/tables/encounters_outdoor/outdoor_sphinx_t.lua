-- encounter table def: outdoor_sphinx_t
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
  key = "outdoor_sphinx_t",
  rows = {
    { key = "androsphinx", cols = { {1,10}, {1,10}, {1,10}, {1,10}, {1,10}, {1,10}, {1,10}, {1,10} } },
    { key = "criosphinx", cols = { {11,40}, {11,40}, {11,40}, {11,40}, {11,40}, {11,40}, {11,40}, {11,40} } },
    { key = "gynosphinx", cols = { {41,70}, {41,70}, {41,70}, {41,70}, {41,70}, {41,70}, {41,70}, {41,70} } },
    { key = "hieracosphinx", cols = { {71,100}, {71,100}, {71,100}, {71,100}, {71,100}, {71,100}, {71,100}, {71,100} } },
  },
}
