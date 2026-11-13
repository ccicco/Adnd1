-- misc magic item def: ioun_stone
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part14.h (R270)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "ioun_stone",
  name = "Ioun Stone",
  rows = {
    { name = "Ioun Stone",
      set = "kMisc3", band = { 72, 72 }, xp = 300, xp_hi = 0,
      gp = 5000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 14, round = 270 },
  },
  pins = {
    { name = "iounSortCount", value = 14,
      comment = "there are 14 sorts of useful ioun stones" },
    { name = "iounOwnerRadiusFeet", value = 3,
      comment = "the stones must be within 3 feet of their owner to be "
      .. "efficacious" },
    { name = "iounOrbitMinFeet", value = 1,
      comment = "the circling orbit starts at a 1 foot radius" },
    { name = "iounOrbitMaxFeet", value = 3,
      comment = "the circling orbit tops at a 3 foot radius" },
    { name = "iounFoundMin", value = 1,
      comment = "from 1-10 ioun stones will be found" },
    { name = "iounFoundMax", value = 10,
      comment = "the upper edge of the 1-10 found" },
    { name = "iounTableRowCount", value = 15,
      comment = "the property table has 15 rows" },
    { name = "iounDeadRowLo", value = 15,
      comment = "the dull gray dead band starts at roll 15" },
    { name = "iounDeadRowHi", value = 20,
      comment = "and ends at roll 20" },
    { name = "iounStatBonusPoints", value = 1,
      comment = "the six stat stones add 1 point to the score" },
    { name = "iounStatCap", value = 18,
      comment = "with an 18 maximum" },
    { name = "iounStatBonusRowCount", value = 6,
      comment = "six stones add to a stat score" },
    { name = "iounLevelGainLevels", value = 1,
      comment = "the pale green prism adds 1 level of experience" },
    { name = "iounRegenHpPerTurn", value = 1,
      comment = "the pearly white spindle regenerates 1 hit point of "
      .. "damage per turn" },
    { name = "iounPurpleStoreMin", value = 2,
      comment = "the vibrant purple prism stores 2-12 levels" },
    { name = "iounPurpleStoreMax", value = 12,
      comment = "the upper edge of the stored 2-12 levels" },
    { name = "iounRoseProtectionBonus", value = 1,
      comment = "the dusty rose prism gives +1 protection" },
    { name = "iounGrayPsionicBonus", value = 10,
      comment = "the dead gray stone adds 10 points to the psionic "
      .. "strength total" },
    { name = "iounGrayPsionicCap", value = 50,
      comment = "the psionic strength total caps at 50 points" },
    { name = "iounHpToDestroy", value = 10,
      comment = "the stones take 10 hit points of damage to destroy" },
    { name = "iounSaveBonus", value = 3,
      comment = "they save as if they were of hard metal, +3" },
    { name = "iounAttackAc", value = 4,
      comment = "exposed to attack they are treated as armor class -4 "
      .. "(the minus rides the comment)" },
  },
  tables = {
    { name = "iounRowRollLo",
      comment = "the printed roll lower edges, rolls 1-14 then the dead "
      .. "band; i clamps",
      clamp_hi = 14,
      values = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
      } },
    { name = "iounRowRollHi",
      comment = "the printed roll upper edges, the dead band topping at "
      .. "20; i clamps",
      clamp_hi = 14,
      values = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 20,
      } },
    { name = "iounRowAddsStat",
      comment = "the rolls 1-6 stones add to a stat score; i clamps",
      clamp_hi = 14,
      values = {
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      } },
    { name = "iounRowAbsorbMaxLevel",
      comment = "the roll 11 and 12 stones absorb spells up to the 4th "
      .. "and 8th level; i clamps",
      clamp_hi = 14,
      values = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 8, 0, 0, 0,
      } },
    { name = "iounRowBurnoutMin",
      comment = "the absorbed spell levels that burn a stone out, the "
      .. "lower edges; i clamps",
      clamp_hi = 14,
      values = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 20, 0, 0, 0,
      } },
    { name = "iounRowBurnoutMax",
      comment = "the absorbed spell levels that burn a stone out, the "
      .. "upper edges; i clamps",
      clamp_hi = 14,
      values = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 80, 0, 0, 0,
      } },
  },
}
