-- misc magic item def: beaker_of_plentiful_potions
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part2.h (R258)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "beaker_of_plentiful_potions",
  name = "Beaker of Plentiful Potions",
  rows = {
    { name = "Beaker of Plentiful Potions",
      set = "kMisc1", band = { 30, 31 }, xp = 1500, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 2, round = 258 },
  },
  pins = {
    { name = "beakerDoseMin", value = 2,
      comment = "compounds from 2-5 doses" },
    { name = "beakerDoseMax", value = 5,
      comment = "the top of the 2-5 dose range" },
    { name = "beakerPotionCountMin", value = 2,
      comment = "of from 2-5 potions" },
    { name = "beakerPotionCountMax", value = 5,
      comment = "the top of the 2-5 potion range" },
    { name = "beakerCountDieSides", value = 4,
      comment = "roll d4 plus 1 for the potion count" },
    { name = "beakerCountDiePlus", value = 1,
      comment = "the +1 on the count die" },
    { name = "beakerPourRounds", value = 1,
      comment = "each pouring takes 1 round" },
    { name = "beakerPourDoses", value = 1,
      comment = "spills forth 1 dose of 1 potion type" },
    { name = "beakerBadTypeCount", value = 2,
      comment = "delusion and poison are possible" },
    { name = "beakerMonthlyTypeLoss", value = 1,
      comment = "one potion type lost per month, permanent" },
    { name = "beakerDispenseRowMin", value = 2,
      comment = "dispensing rows keyed by potions held" },
    { name = "beakerDispenseRowMax", value = 5,
      comment = "the top row key (5 potions)" },
  },
  tables = {
    { name = "beakerPerDayByCount",
      comment = "row i = potions held - 2; per-day rate, 0 for the 4-5 "
      .. "potion rows; i clamps",
      clamp_hi = 3,
      values = {
        1, 1, 0, 0,
      } },
    { name = "beakerPerWeekByCount",
      comment = "row i = potions held - 2; per-week rate; i clamps",
      clamp_hi = 3,
      values = {
        3, 2, 1, 1,
      } },
  },
}
