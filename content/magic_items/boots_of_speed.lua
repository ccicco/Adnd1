-- misc magic item def: boots_of_speed
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part3.h (R259)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "boots_of_speed",
  name = "Boots of Speed",
  rows = {
    { name = "Boots of Speed",
      set = "kMisc1", band = { 48, 51 }, xp = 2500, xp_hi = 0,
      gp = 20000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 3, round = 259 },
  },
  pins = {
    { name = "speedBaseMovementInches", value = 24,
      comment = "the speed of a fast horse, 24 inches base" },
    { name = "speedSlowPoundsPerInch", value = 10,
      comment = "1 inch slower per 10 pounds over 200" },
    { name = "speedFreeWeightPounds", value = 200,
      comment = "the 200 pound free allowance" },
    { name = "speedExampleHumanPounds", value = 180,
      comment = "the example: a 180 pound human" },
    { name = "speedExampleGearPounds", value = 60,
      comment = "with 60 pounds of gear" },
    { name = "speedExampleRateInches", value = 20,
      comment = "moves at 20 inches base rate" },
    { name = "speedSackCoins", value = 500,
      comment = "the extra sack of 500 gold pieces" },
    { name = "speedSackSlowInches", value = 5,
      comment = "slows the rate yet another 5 inches" },
    { name = "speedRestHoursPerMoveHour", value = 1,
      comment = "1 rest hour per hour of fast movement" },
    { name = "speedMaxContinuousHours", value = 8,
      comment = "no more than 8 hours continuous" },
    { name = "speedAcBonus", value = 2,
      comment = "+2 to armor class value in combat" },
  },
  tables = {
  },
}
