-- encounter table def: appendixp_potion_types
-- The DMG Appendix P convention party (R1040 de-wire): the ten printed potion types (p.226)
-- (DMG pp.225-226, 1eonline.info compilation, OCR-verified).
-- die = the roller face (1-10; 10 = the book's printed "0.", Polymorph Self); key = the printed type name.
-- DO NOT hand-edit: tools/r1040_splice.py is the only writer.

return {
  key = "appendixp_potion_types",
  rows = {
    { die = 1, key = "Climbing" },
    { die = 2, key = "Diminution" },
    { die = 3, key = "Extra-Healing" },
    { die = 4, key = "Fire Resistance" },
    { die = 5, key = "Flying" },
    { die = 6, key = "Gaseous Form" },
    { die = 7, key = "Growth" },
    { die = 8, key = "Healing" },
    { die = 9, key = "Invisibility" },
    { die = 10, key = "Polymorph Self" },
  },
}
