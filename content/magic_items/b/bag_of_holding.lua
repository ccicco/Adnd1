-- misc magic item def: bag_of_holding
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part2.h (R258)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bag_of_holding",
  name = "Bag of Holding",
  rows = {
    { name = "Bag of Holding",
      set = "kMisc1", band = { 22, 26 }, xp = 5000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 2, round = 258 },
  },
  pins = {
    { name = "holdingSackShortSideFeet", value = 2,
      comment = "a common cloth sack about 2 feet by 4" },
    { name = "holdingSackLongSideFeet", value = 4,
      comment = "the long side of the 2 by 4 sack" },
    { name = "holdingRowCount", value = 4,
      comment = "the 4 quality rows" },
    { name = "holdingRuptureCauseCount", value = 2,
      comment = "overloaded, or pierced by sharp objects" },
  },
  tables = {
    { name = "holdingRowLo",
      comment = "the d100 band lower edges; i clamps",
      clamp_hi = 3,
      values = {
        1, 31, 71, 91,
      } },
    { name = "holdingRowHi",
      comment = "the d100 band upper edges (00 = 100)",
      clamp_hi = 3,
      values = {
        30, 70, 90, 100,
      } },
    { name = "holdingRowWeightPounds",
      comment = "the fixed bag weight by quality; i clamps",
      clamp_hi = 3,
      values = {
        15, 15, 35, 60,
      } },
    { name = "holdingRowWeightLimitPounds",
      comment = "the contents weight limit by quality; i clamps",
      clamp_hi = 3,
      values = {
        250, 500, 1000, 1500,
      } },
    { name = "holdingRowVolumeLimitCubicFeet",
      comment = "the volume limit by quality; i clamps",
      clamp_hi = 3,
      values = {
        30, 70, 150, 250,
      } },
  },
}
