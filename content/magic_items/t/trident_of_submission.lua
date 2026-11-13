-- misc magic item def: trident_of_submission
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "trident_of_submission",
  name = "Trident of Submission",
  rows = {
    { name = "Trident of Submission",
      set = "kMisc5", band = { 77, 78 }, xp = 1250, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "submitMoraleDelayRounds", value = 1,
      comment = "a failed save means a morale check the next round" },
    { name = "submitHopelessRoundsMin", value = 2,
      comment = "the hopelessness lasts 2-8 rounds" },
    { name = "submitHopelessRoundsMax", value = 8,
      comment = "the hopelessness ceiling" },
    { name = "submitChargesMin", value = 17,
      comment = "it has 17-20 charges" },
    { name = "submitChargesMax", value = 20,
      comment = "the charge ceiling" },
    { name = "submitMagicBonus", value = 1,
      comment = "a +1 magic weapon" },
  },
  tables = {
  },
}
