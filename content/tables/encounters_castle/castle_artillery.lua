-- encounter table def: castle_artillery
-- The R67 castle family (R1038 de-wire): the ARTILLERY table, per fortress type
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- No percentile column - the rows key onto the Table I type strings; both shell-keep rows key "shell keep" (documented). ballistae / lightCatapults / oilCauldrons = the printed counts.
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

return {
  key = "castle_artillery",
  rows = {
    { type = "moat house or friary", ballistae = 2, lightCatapults = 0, oilCauldrons = 1 },
    { type = "tower", ballistae = 1, lightCatapults = 0, oilCauldrons = 1 },
    { type = "shell keep", ballistae = 0, lightCatapults = 1, oilCauldrons = 2 },
    { type = "small walled castle with keep", ballistae = 1, lightCatapults = 1, oilCauldrons = 2 },
    { type = "medium walled castle with keep", ballistae = 2, lightCatapults = 2, oilCauldrons = 5 },
    { type = "concentric castle", ballistae = 4, lightCatapults = 2, oilCauldrons = 6 },
    { type = "large walled castle with keep", ballistae = 4, lightCatapults = 4, oilCauldrons = 8 },
    { type = "fortress complex", ballistae = 4, lightCatapults = 4, oilCauldrons = 8 },
  },
}
