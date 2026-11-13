-- misc magic item def: robe_of_blending
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part21.h (R277)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "robe_of_blending",
  name = "Robe of Blending",
  rows = {
    { name = "Robe of Blending",
      set = "kMisc5", band = { 2, 8 }, xp = 3500, xp_hi = 0,
      gp = 35000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 21, round = 277 },
  },
  pins = {
    { name = "blendDetectRangeInches", value = 3,
      comment = "within 3 inches something amiss is detectable" },
    { name = "blendDetectPerIntPct", value = 1,
      comment = "1 percent per intelligence point chance" },
    { name = "blendDetectIntMin", value = 15,
      comment = "exceptional (15+) or better intelligence" },
    { name = "blendLevelDetectIntMin", value = 5,
      comment = "low intelligence (5+) or better and" },
    { name = "blendLevelDetectLevelMin", value = 10,
      comment = "10 or more levels of experience or hit dice" },
    { name = "blendDetectPerLevelPct", value = 1,
      comment = "1 percent per level or hit die chance" },
    { name = "blendExamplePct", value = 30,
      comment = "the 18 int / 12th level example: 30 percent" },
  },
  tables = {
  },
}
