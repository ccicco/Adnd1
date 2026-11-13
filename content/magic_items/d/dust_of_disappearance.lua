-- misc magic item def: dust_of_disappearance
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "dust_of_disappearance",
  name = "Dust of Disappearance",
  rows = {
    { name = "Dust of Disappearance",
      set = "kMisc2", band = { 86, 91 }, xp = 2000, xp_hi = 0,
      gp = 8000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "dustGoneDurationMinTurns", value = 2,
      comment = "invisibility lasts 2 to 20 turns" },
    { name = "dustGoneDurationMaxTurns", value = 20,
      comment = "invisibility lasts 2 to 20 turns" },
    { name = "dustGoneSprinkleMinTurns", value = 11,
      comment = "carefully sprinkled: 11-20 turns" },
    { name = "dustGoneSprinkleMaxTurns", value = 20,
      comment = "carefully sprinkled: 11-20 turns" },
    { name = "dustGoneAcBonusPlaces", value = 4,
      comment = "armor class 4 places better" },
  },
  tables = {
  },
}
