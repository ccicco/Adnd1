-- misc magic item def: gauntlets_of_ogre_power
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "gauntlets_of_ogre_power",
  name = "Gauntlets of Ogre Power",
  rows = {
    { name = "Gauntlets of Ogre Power",
      set = "kMisc3", band = { 21, 22 }, xp = 1000, xp_hi = 0,
      gp = 15000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "gauntOgreStrength", value = 18,
      comment = "18/00 strength in hands, arms and shoulders" },
    { name = "gauntOgreStrengthPercentile", value = 0,
      comment = "the 18/00 exceptional percentile" },
    { name = "gauntOgreHitBonus", value = 3,
      comment = "+3 to hit probability" },
    { name = "gauntOgreDmgBonus", value = 6,
      comment = "+6 to damage inflicted" },
  },
  tables = {
  },
}
