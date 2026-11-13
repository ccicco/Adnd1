-- misc magic item def: cube_of_frost_resistance
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part7.h (R263)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cube_of_frost_resistance",
  name = "Cube of Frost Resistance",
  rows = {
    { name = "Cube of Frost Resistance",
      set = "kMisc2", band = { 64, 65 }, xp = 2000, xp_hi = 0,
      gp = 14000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 7, round = 263 },
  },
  pins = {
    { name = "cubeFrostSideInches", value = 1,
      comment = "encloses 1 inch per side" },
    { name = "cubeFrostTempF", value = 65,
      comment = "always 65 degrees F inside" },
    { name = "cubeFrostColdAttackCount", value = 3,
      comment = "cone of cold, ice storm, dragon breath" },
    { name = "cubeFrostCollapseHp", value = 50,
      comment = "more than this per turn: collapse" },
    { name = "cubeFrostTurnRounds", value = 10,
      comment = "a turn is 10 rounds" },
    { name = "cubeFrostRenewHours", value = 1,
      comment = "after collapse: no renewal for" },
    { name = "cubeFrostDestroyHp", value = 100,
      comment = "over this in 1 turn: destroyed" },
    { name = "cubeFrostColdPer10BelowF", value = 2,
      comment = "2 hp of cold per minus 10 degrees" },
    { name = "cubeFrostAt40BelowHp", value = 42,
      comment = "at minus 40 F: withstands only" },
  },
  tables = {
  },
}
