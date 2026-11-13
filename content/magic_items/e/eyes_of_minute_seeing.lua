-- misc magic item def: eyes_of_minute_seeing
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "eyes_of_minute_seeing",
  name = "Eyes of Minute Seeing",
  rows = {
    { name = "Eyes of Minute Seeing",
      set = "kMisc2", band = { 98, 99 }, xp = 2000, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "eyesMinuteVisionFactor", value = 100,
      comment = "see 100 times better at 1 feet or less" },
    { name = "eyesMinuteMaxDistanceFeet", value = 1,
      comment = "only within 1 feet" },
  },
  tables = {
  },
}
