-- encounter table def: magic_ladder
-- The R53/R55 party family (R1039 de-wire): the level-chance ladder
-- (DMG Appendix C Premium reprint p.176-177, OCR-verified).
-- level = the character level (13+ reads row 13); tNpct = the chance per Table N roll (percentile x level; -1 = automatic, the printed "3 items" rows); tNn = the number of Table N rolls.
-- DO NOT hand-edit: tools/r1039_splice.py is the only writer.

return {
  key = "magic_ladder",
  rows = {
    { level = 1, t1pct = 10, t1n = 1, t2pct = 0, t2n = 0, t3pct = 0, t3n = 0, t4pct = 0, t4n = 0 },
    { level = 2, t1pct = 20, t1n = 2, t2pct = 0, t2n = 0, t3pct = 0, t3n = 0, t4pct = 0, t4n = 0 },
    { level = 3, t1pct = 30, t1n = 2, t2pct = 10, t2n = 1, t3pct = 0, t3n = 0, t4pct = 0, t4n = 0 },
    { level = 4, t1pct = 40, t1n = 2, t2pct = 20, t2n = 1, t3pct = 0, t3n = 0, t4pct = 0, t4n = 0 },
    { level = 5, t1pct = 50, t1n = 2, t2pct = 30, t2n = 1, t3pct = 0, t3n = 0, t4pct = 0, t4n = 0 },
    { level = 6, t1pct = 60, t1n = 3, t2pct = 40, t2n = 2, t3pct = 0, t3n = 0, t4pct = 0, t4n = 0 },
    { level = 7, t1pct = 70, t1n = 3, t2pct = 50, t2n = 2, t3pct = 10, t3n = 1, t4pct = 0, t4n = 0 },
    { level = 8, t1pct = 80, t1n = 3, t2pct = 60, t2n = 2, t3pct = 20, t3n = 1, t4pct = 0, t4n = 0 },
    { level = 9, t1pct = 90, t1n = 3, t2pct = 70, t2n = 2, t3pct = 30, t3n = 1, t4pct = 0, t4n = 0 },
    { level = 10, t1pct = -1, t1n = 3, t2pct = 80, t2n = 2, t3pct = 40, t3n = 1, t4pct = 0, t4n = 0 },
    { level = 11, t1pct = -1, t1n = 3, t2pct = 90, t2n = 2, t3pct = 50, t3n = 1, t4pct = 10, t4n = 1 },
    { level = 12, t1pct = -1, t1n = 3, t2pct = -1, t2n = 2, t3pct = 60, t3n = 1, t4pct = 20, t4n = 1 },
    { level = 13, t1pct = -1, t1n = 3, t2pct = -1, t2n = 2, t3pct = -1, t3n = 1, t4pct = 60, t4n = 1 },
  },
}
