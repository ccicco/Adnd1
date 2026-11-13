-- misc magic item def: amulet_of_proof_against_detection_and_location
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "amulet_of_proof_against_detection_and_location",
  name = "Amulet of Proof Against Detection and Location",
  rows = {
    { name = "Amulet of Proof Against Detection and Location",
      set = "kMisc1", band = { 8, 11 }, xp = 4000, xp_hi = 0,
      gp = 15000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "amuletProofNoAuraFlag", value = 1,
      comment = "no aura is discernible on the wearer" },
  },
  tables = {
  },
}
