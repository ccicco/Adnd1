-- misc magic item def: maul_of_the_titans
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "maul_of_the_titans",
  name = "Maul of the Titans",
  rows = {
    { name = "Maul of the Titans",
      set = "kMisc4", band = { 12, 12 }, xp = 4000, xp_hi = 0,
      gp = 12000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "maulLengthFeet", value = 8,
      comment = "the huge mallet is 8 feet long" },
    { name = "maulWeightLb", value = 150,
      comment = "and weighs over 150 pounds" },
    { name = "maulMinStrength", value = 21,
      comment = "a giant-sized user of strength 21 or greater" },
    { name = "maulPileDiameterFeet", value = 2,
      comment = "drives piles of up to 2 feet diameter" },
    { name = "maulPileDepthFeet", value = 4,
      comment = "into normal earth at 4 feet per blow" },
    { name = "maulBlowsPerRound", value = 2,
      comment = "2 blows per round" },
    { name = "maulDoorHeightFeet", value = 10,
      comment = "an oaken door of up to 10 feet height" },
    { name = "maulDoorWidthFeet", value = 4,
      comment = "by 4 feet width" },
    { name = "maulDoorThicknessInches", value = 2,
      comment = "by 2 inch thickness" },
    { name = "maulDoorBlows", value = 1,
      comment = "smashed to flinders in 1 blow" },
    { name = "maulDoorIronBlows", value = 2,
      comment = "2 blows if heavily bound with iron" },
    { name = "maulHitBonus", value = 2,
      comment = "+2 to hit as a weapon" },
    { name = "maulDamageMin", value = 10,
      comment = "inflicts 10-40 damage, strength bonuses aside" },
    { name = "maulDamageMax", value = 40,
      comment = "the upper edge of the 10-40 damage" },
  },
  tables = {
  },
}
