-- encounter table def: appendixp_potions
-- The DMG Appendix P convention party (R1040 de-wire): the POTION chance and maximum (p.226)
-- (DMG pp.225-226, 1eonline.info compilation, OCR-verified).
-- class = the engine class (1 fighter / 2 magic-user / 3 cleric / 4 thief); pct = the per-level chance; max = the most carried.
-- DO NOT hand-edit: tools/r1040_splice.py is the only writer.

return {
  key = "appendixp_potions",
  rows = {
    { class = 1, pct = 8, max = 1 },
    { class = 2, pct = 10, max = 3 },
    { class = 3, pct = 6, max = 1 },
    { class = 4, pct = 9, max = 2 },
  },
}
