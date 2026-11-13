-- misc magic item def: medallion_of_esp
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "medallion_of_esp",
  name = "Medallion of ESP",
  rows = {
    { name = "Medallion of ESP",
      set = "kMisc4", band = { 13, 15 }, xp = 1000, xp_hi = 3000,
      gp = 10000, gp_hi = 30000, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "espPathWidthFeet", value = 1,
      comment = "the path is 1 foot wide at the medallion" },
    { name = "espBroadenFeet", value = 2,
      comment = "broadening 2 feet every 10 feet of reach" },
    { name = "espBroadenPerFeet", value = 10,
      comment = "every 10 feet from the device" },
    { name = "espMaxWidthFeet", value = 11,
      comment = "up to an 11 foot maximum width" },
    { name = "espMaxWidthAtFeet", value = 50,
      comment = "the maximum reached at 50 feet" },
    { name = "espUseRounds", value = 1,
      comment = "a full round to use the device" },
    { name = "espStoneBlockFeet", value = 3,
      comment = "stone of over 3 feet thickness blocks" },
    { name = "espMetalBlockSixthsFeet", value = 1,
      comment = "metal of over 1/6 foot thickness blocks" },
    { name = "espMalfunctionRoll", value = 6,
      comment = "malfunctions on a die roll of 6" },
    { name = "espMalfunctionDieSides", value = 6,
      comment = "the roll is on d6, checked each use" },
  },
  tables = {
    { name = "espRowLo",
      comment = "the printed die band lower edges; i clamps",
      clamp_hi = 3,
      values = {
        1, 16, 19, 20,
      } },
    { name = "espRowHi",
      comment = "the printed die band upper edges; i clamps",
      clamp_hi = 3,
      values = {
        15, 18, 19, 20,
      } },
    { name = "espRangeFeet",
      comment = "the medallion range per type; i clamps",
      clamp_hi = 3,
      values = {
        30, 30, 60, 90,
      } },
    { name = "espEmpathy",
      comment = "the with-empathy mark per type; i clamps",
      clamp_hi = 3,
      values = {
        0, 1, 0, 0,
      } },
  },
}
