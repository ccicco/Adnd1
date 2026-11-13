-- misc magic item def: eyes
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "eyes",
  name = "Eye mix note",
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "eyesMixInsanityMinTurns", value = 2,
      comment = "mixing eye types: insanity 2-8 turns" },
    { name = "eyesMixInsanityMaxTurns", value = 8,
      comment = "mixing eye types: insanity 2-8 turns" },
    { name = "eyesMixInsanityDice", value = 2,
      comment = "the insanity lasts 2-8 (2d4) turns" },
  },
  tables = {
  },
}
