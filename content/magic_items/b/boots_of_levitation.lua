-- misc magic item def: boots_of_levitation
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part3.h (R259)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "boots_of_levitation",
  name = "Boots of Levitation",
  rows = {
    { name = "Boots of Levitation",
      set = "kMisc1", band = { 43, 47 }, xp = 2000, xp_hi = 0,
      gp = 15000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 3, round = 259 },
  },
  pins = {
    { name = "levitationSpeedInchesPerRound", value = 20,
      comment = "the ascent/descent speed per round (the 102 seam "
      .. "fact, completed across the page header)" },
    { name = "levitationWeightIncrementPounds", value = 14,
      comment = "d20 in 14 pound increments" },
    { name = "levitationWeightDieSides", value = 20,
      comment = "the d20 on the weight capacity" },
    { name = "levitationWeightBasePounds", value = 280,
      comment = "added to a base of 280 pounds" },
    { name = "levitationWeightMinPounds", value = 294,
      comment = "294 pounds at the minimum roll" },
    { name = "levitationWeightMaxPounds", value = 560,
      comment = "560 pounds at the maximum roll" },
  },
  tables = {
  },
}
