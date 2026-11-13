-- misc magic item def: boots_of_striding_and_springing
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part3.h (R259)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "boots_of_striding_and_springing",
  name = "Boots of Striding and Springing",
  rows = {
    { name = "Boots of Striding and Springing",
      set = "kMisc1", band = { 52, 55 }, xp = 2500, xp_hi = 0,
      gp = 20000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 3, round = 259 },
  },
  pins = {
    { name = "stridingBaseMovementInches", value = 12,
      comment = "base movement rate of 12 inches regardless" },
    { name = "stridingMaxHoursPerDay", value = 12,
      comment = "tirelessly for up to 12 hours per day" },
    { name = "stridingRechargeHours", value = 12,
      comment = "then no function for 12 hours (recharge)" },
    { name = "stridingNormalPaceFeet", value = 3,
      comment = "normal paces are 3 feet long" },
    { name = "stridingForwardJumpFeet", value = 30,
      comment = "forward jumps of up to 30 feet" },
    { name = "stridingBackwardLeapFeet", value = 9,
      comment = "backward leaps of 9 feet" },
    { name = "stridingVerticalSpringFeet", value = 15,
      comment = "vertical springs of 15 feet" },
    { name = "stridingStumbleBasePct", value = 20,
      comment = "base 20% stumble chance" },
    { name = "stridingStumbleDexAdjPct", value = 3,
      comment = "less 3% per point of dexterity above 12" },
    { name = "stridingStumbleDexThreshold", value = 12,
      comment = "the dexterity threshold" },
    { name = "stridingStumbleRowCount", value = 6,
      comment = "the dex ladder rows, 13 through 18" },
    { name = "stridingAcBonus", value = 1,
      comment = "increases armor class value by 1" },
  },
  tables = {
    { name = "stridingStumblePctByDex",
      comment = "row i = dexterity - 13; the stumble chance; i clamps",
      clamp_hi = 5,
      values = {
        17, 14, 11, 8, 5, 2,
      } },
  },
}
