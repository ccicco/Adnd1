-- encounter table def: outdoor_sets
-- The six R63 outdoor pick-sets (R1034 de-wire): extracted
-- verbatim from the retired kOut*Set arrays of dm/encounters.cpp.
-- A set resolves on the second percentile modulo the set size
-- (DMG Appendix C, Premium reprint p.182-191). Porcupine/Skunk
-- maps to the giant varieties (the bestiary carries those only).
-- DO NOT hand-edit: tools/r1034_splice.py is the only writer.


return {
  key = "outdoor_sets",
  ki_rin = { "ki_rin", "lammasu", "shedu" },
  leprechaun = { "leprechaun", "brownie" },
  porcupine = { "giant_porcupine", "giant_skunk" },
  iguanodon = { "iguanodon", "lambeosaurus" },
  lammasu = { "lammasu", "shedu" },
  wolf_dog = { "wolf", "wild_dog" },
}
