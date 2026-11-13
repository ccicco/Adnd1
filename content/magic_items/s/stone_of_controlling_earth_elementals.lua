-- misc magic item def: stone_of_controlling_earth_elementals
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "stone_of_controlling_earth_elementals",
  name = "Stone of Controlling Earth Elementals",
  rows = {
    { name = "Stone of Controlling Earth Elementals",
      set = "kMisc5", band = { 49, 50 }, xp = 1500, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "earthStoneEarthDice", value = 12,
      comment = "an earth elemental of 12 hit dice from earth" },
    { name = "earthStoneRoughDice", value = 8,
      comment = "8 hit dice from rough unhewn stone or sand" },
    { name = "earthStoneWorkedStoneDice", value = 0,
      comment = "none can be summoned from worked stone" },
    { name = "earthStoneAreaFeet", value = 4,
      comment = "the summoning area must be 4 feet square" },
    { name = "earthStoneVolumeYards", value = 4,
      comment = "and hold 4 cubic yards of medium" },
    { name = "earthStoneRoundsMin", value = 1,
      comment = "the elemental appears in 1-4 rounds" },
    { name = "earthStoneRoundsMax", value = 4,
      comment = "the appearance ceiling" },
    { name = "earthStonePerDay", value = 1,
      comment = "one elemental per day by means of the stone" },
  },
  tables = {
  },
}
