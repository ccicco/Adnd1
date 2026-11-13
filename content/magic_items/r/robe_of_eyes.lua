-- misc magic item def: robe_of_eyes
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part21.h (R277)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "robe_of_eyes",
  name = "Robe of Eyes",
  rows = {
    { name = "Robe of Eyes",
      set = "kMisc5", band = { 9, 9 }, xp = 4500, xp_hi = 0,
      gp = 50000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 21, round = 277 },
  },
  pins = {
    { name = "eyesInfravisionInches", value = 12,
      comment = "infravisual capability to 12 inch range" },
    { name = "eyesSeeInvisibleInches", value = 24,
      comment = "invisible things within a 24 inch normal vision range" },
    { name = "eyesSeeInfraredInches", value = 12,
      comment = "or 12 inches if infravision is used" },
    { name = "eyesTrackRangerLevel", value = 12,
      comment = "tracks as if a 12th level ranger" },
    { name = "eyesBlindLightMin", value = 1,
      comment = "a light spell blinds it for 1-3 rounds" },
    { name = "eyesBlindLightMax", value = 3,
      comment = "the light blindness ceiling" },
    { name = "eyesBlindContinualMin", value = 2,
      comment = "a continual light for 2-8 rounds" },
    { name = "eyesBlindContinualMax", value = 8,
      comment = "the continual light blindness ceiling" },
  },
  tables = {
  },
}
