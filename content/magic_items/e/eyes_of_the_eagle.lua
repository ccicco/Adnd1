-- misc magic item def: eyes_of_the_eagle
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "eyes_of_the_eagle",
  name = "Eyes of the Eagle",
  rows = {
    { name = "Eyes of the Eagle",
      set = "kMisc2", band = { 96, 97 }, xp = 3500, xp_hi = 0,
      gp = 18000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "eyesEagleVisionFactor", value = 100,
      comment = "vision 100 times greater than normal" },
    { name = "eyesEagleMinDistanceFeet", value = 1,
      comment = "at distances of 1 feet or more" },
    { name = "eyesEagleSeeAtFeet", value = 2000,
      comment = "sees at 2000 feet" },
    { name = "eyesEagleNormalSeeFeet", value = 20,
      comment = "what normal sight does at 20 feet" },
    { name = "eyesEagleSingleStunRounds", value = 1,
      comment = "one cusp: dizzy, stunned, for 1 round" },
  },
  tables = {
  },
}
