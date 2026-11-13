-- misc magic item def: trident_of_fish_command
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "trident_of_fish_command",
  name = "Trident of Fish Command",
  rows = {
    { name = "Trident of Fish Command",
      set = "kMisc5", band = { 70, 76 }, xp = 500, xp_hi = 0,
      gp = 4000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "fishCmdRadiusInches", value = 6,
      comment = "all fish within a 6 inch radius save versus magic" },
    { name = "fishCmdChargeCost", value = 1,
      comment = "the command uses one charge" },
    { name = "fishCmdProtectFeet", value = 10,
      comment = "commanded fish spare all within 10 feet" },
    { name = "fishCmdApproachFeet", value = 10,
      comment = "free fish keep 10 feet off the trident" },
    { name = "fishCmdSchoolsAsOne", value = 1,
      comment = "schooling fish check as a single entity" },
    { name = "fishCmdChargesMin", value = 17,
      comment = "it contains 17-20 charges" },
    { name = "fishCmdChargesMax", value = 20,
      comment = "the charge ceiling" },
    { name = "fishCmdMagicBonus", value = 1,
      comment = "otherwise a +1 magic weapon" },
  },
  tables = {
  },
}
