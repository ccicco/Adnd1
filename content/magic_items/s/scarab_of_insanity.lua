-- misc magic item def: scarab_of_insanity
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "scarab_of_insanity",
  name = "Scarab of Insanity",
  rows = {
    { name = "Scarab of Insanity",
      set = "kMisc5", band = { 39, 40 }, xp = 1500, xp_hi = 0,
      gp = 11000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "insanityRadiusInches", value = 2,
      comment = "insanity within a 2 inch radius" },
    { name = "insanitySavePenalty", value = 2,
      comment = "the save versus magic at -2" },
    { name = "insanityMagicResistPenaltyPct", value = 10,
      comment = "and -10 percent from magic resistance" },
    { name = "insanityRoundsMin", value = 9,
      comment = "completely insane for 9-12 rounds" },
    { name = "insanityRoundsMax", value = 12,
      comment = "the insanity ceiling" },
    { name = "insanityChargesMin", value = 9,
      comment = "the scarab has 9-16 charges" },
    { name = "insanityChargesMax", value = 16,
      comment = "the charge ceiling" },
  },
  tables = {
  },
}
