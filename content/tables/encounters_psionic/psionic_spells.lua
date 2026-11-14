-- encounter table def: psionic_spells
-- The R66 psionic family (R1037 de-wire): the printed Spells Resembling Psionic Powers list
-- (DMG Appendix C Premium reprint p.182, OCR-verified).
-- exact = the 20 printed spell names (matched case-insensitively on the full name); family = the 6 printed '(any)' leading words (charm, cure, detect, invisibility, polymorph, tele-), matched by prefix. The engine's matching logic is spellResemblesPsionicPower's, unchanged.
-- DO NOT hand-edit: tools/r1037_splice.py is the only writer.

return {
  key = "psionic_spells",
  exact = { "astral spell", "augury", "blink", "clairadience", "clairvoyance", "dimension door", "enlarge", "esp", "feather fall", "feign death", "heat metal", "heal", "hypnotism", "know alignment", "levitation", "plane shift", "remove curse", "shape change", "stone tell", "temporal stasis" },
  family = { "charm", "cure", "detect", "invisibility", "polymorph", "tele" },
}
