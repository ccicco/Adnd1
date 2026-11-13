-- misc magic item def: gauntlets_of_dexterity
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "gauntlets_of_dexterity",
  name = "Gauntlets of Dexterity",
  rows = {
    { name = "Gauntlets of Dexterity",
      set = "kMisc3", band = { 17, 18 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "gauntDexBoostLow", value = 4,
      comment = "+4 dexterity if at 6 or less" },
    { name = "gauntDexBoostMid", value = 2,
      comment = "+2 dexterity if at 7-13" },
    { name = "gauntDexBoostHigh", value = 1,
      comment = "+1 dexterity if at 14 or higher" },
    { name = "gauntDexThiefLevel", value = 4,
      comment = "non-thieves act as a 4th level thief" },
    { name = "gauntDexThiefBonusPct", value = 10,
      comment = "thieves gain +10 percent for their level" },
  },
  tables = {
  },
}
