-- misc magic item def: incense_of_meditation
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part13.h (R269)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "incense_of_meditation",
  name = "Incense of Meditation",
  rows = {
    { name = "Incense of Meditation",
      set = "kMisc3", band = { 66, 70 }, xp = 500, xp_hi = 0,
      gp = 7500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 13, round = 269 },
  },
  pins = {
    { name = "incenseMedRecognizeClericLevel", value = 5,
      comment = "the smoke is recognizable by any cleric of 5th or "
      .. "higher level" },
    { name = "incenseMedPrayHours", value = 8,
      comment = "the cleric spends 8 hours praying and meditating "
      .. "nearby" },
    { name = "incenseMedCureAlwaysMax", value = 1,
      comment = "cure wounds spells are always maximum" },
    { name = "incenseMedBroadestArea", value = 1,
      comment = "spell effects are of the broadest area possible" },
    { name = "incenseMedSavePenalty", value = 1,
      comment = "saving throws against the effects are at minus 1" },
    { name = "incenseMedNotSurvivingDivisor", value = 2,
      comment = "the revived dead reduce their chance of not surviving "
      .. "by one-half (rounded down)" },
    { name = "incenseMedPieceCountMin", value = 2,
      comment = "discovered with from 2-8 pieces of incense" },
    { name = "incenseMedPieceCountMax", value = 8,
      comment = "the piece count upper edge" },
    { name = "incenseMedBurnHours", value = 8,
      comment = "one piece burns for 8 hours" },
    { name = "incenseMedEffectHours", value = 24,
      comment = "the effects remain for 24 hours" },
  },
  tables = {
  },
}
