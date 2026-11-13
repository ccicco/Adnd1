-- misc magic item def: helm_of_telepathy
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "helm_of_telepathy",
  name = "Helm of Telepathy",
  rows = {
    { name = "Helm of Telepathy",
      set = "kMisc3", band = { 38, 39 }, xp = 3000, xp_hi = 0,
      gp = 35000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "helmTelepathyRangeInches", value = 6,
      comment = "the thoughts of creatures within a 6 inch range" },
    { name = "helmTelepathyStoneBarrierFeet", value = 3,
      comment = "no more than 3 feet of solid stone between the wearer "
      .. "and the creatures" },
    { name = "helmTelepathyIronBarrierQuarterFeet", value = 1,
      comment = "a quarter foot of iron" },
    { name = "helmTelepathyLeadGoldSheetBlocks", value = 1,
      comment = "any solid sheeting of lead or gold blocks the pick-up "
      .. "entirely" },
    { name = "helmTelepathyDirectional", value = 1,
      comment = "the thought pick-up is directional" },
    { name = "helmTelepathyConsciousEffort", value = 1,
      comment = "conscious effort must be made to pick up thoughts" },
    { name = "helmTelepathySuggestPctPer2IntAbove", value = 5,
      comment = "for every 2 points of intelligence greater than the "
      .. "subject the wearer is 5 percent more likely to "
      .. "implant" },
    { name = "helmTelepathySuggestPctPer1IntBelow", value = 5,
      comment = "for every 1 point lower the probability decreases by "
      .. "5 percent" },
    { name = "helmTelepathySavePenaltyPer2IntBelow", value = 1,
      comment = "the subject saves versus magic with a minus 1 for "
      .. "every 2 points of intelligence lower than the "
      .. "telepathist" },
    { name = "helmTelepathySaveBonusPer1IntAbove", value = 1,
      comment = "the subject saves with a plus 1 for every 1 point of "
      .. "intelligence higher than the wearer of the helm" },
    { name = "helmTelepathyEqualIntSaveAdjustment", value = 0,
      comment = "if intelligence is equal no adjustment is made" },
    { name = "helmTelepathyPsionicAttackBonus", value = 4,
      comment = "a plus 4 with respect to psionic related attacks" },
    { name = "helmTelepathyPsionicStrengthBonus", value = 40,
      comment = "increases total psionic strength by 40 points" },
  },
  tables = {
  },
}
