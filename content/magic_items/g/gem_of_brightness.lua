-- misc magic item def: gem_of_brightness
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "gem_of_brightness",
  name = "Gem of Brightness",
  rows = {
    { name = "Gem of Brightness",
      set = "kMisc3", band = { 26, 26 }, xp = 2000, xp_hi = 0,
      gp = 17500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "gemBrightLightSorts", value = 3,
      comment = "the gem emits bright light of 3 sorts" },
    { name = "gemBrightConeLengthFeet", value = 10,
      comment = "the pale light cone is 10 feet long" },
    { name = "gemBrightConeRadiusHalfFeet", value = 5,
      comment = "cone radius 2.5 feet at the beam end" },
    { name = "gemBrightRayDiameterFeet", value = 1,
      comment = "the bright ray is 1 feet diameter" },
    { name = "gemBrightRayLengthFeet", value = 50,
      comment = "the bright ray is 50 feet long" },
    { name = "gemBrightDazzleMinRounds", value = 1,
      comment = "dazzled 1-4 rounds" },
    { name = "gemBrightDazzleMaxRounds", value = 4,
      comment = "dazzled 1-4 rounds" },
    { name = "gemBrightRayCharges", value = 1,
      comment = "the ray use expends 1 energy charge" },
    { name = "gemBrightFlashLengthFeet", value = 30,
      comment = "the blinding flash cone is 30 feet long" },
    { name = "gemBrightFlashRadiusFeet", value = 5,
      comment = "flash cone radius 5 feet at its terminus" },
    { name = "gemBrightBlindMinRounds", value = 1,
      comment = "blinded 1-4 rounds" },
    { name = "gemBrightBlindMaxRounds", value = 4,
      comment = "blinded 1-4 rounds" },
    { name = "gemBrightEyePenaltyMin", value = 1,
      comment = "permanent eye damage: -1 at least" },
    { name = "gemBrightEyePenaltyMax", value = 4,
      comment = "permanent eye damage: up to -4" },
    { name = "gemBrightFlashCharges", value = 5,
      comment = "the flash use expends 5 charges" },
    { name = "gemBrightTotalCharges", value = 50,
      comment = "50 charges, cannot be recharged" },
    { name = "gemBrightDarknessDrainCharges", value = 1,
      comment = "a darkness spell drains 1 charge" },
    { name = "gemBrightDarknessRoundUseless", value = 1,
      comment = "or makes the gem useless for 1 round" },
    { name = "gemBrightDarknessDayUseless", value = 1,
      comment = "continual darkness: useless for 1 day" },
    { name = "gemBrightDarknessExpelCharges", value = 5,
      comment = "or the owner expends 5 charges" },
  },
  tables = {
  },
}
