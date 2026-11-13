-- misc magic item def: periapt_of_foul_rotting
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "periapt_of_foul_rotting",
  name = "Periapt of Foul Rotting",
  rows = {
    { name = "Periapt of Foul Rotting",
      set = "kMisc4", band = { 49, 50 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "rotAbilityLossPerWeek", value = 1,
      comment = "1 point per ability per week" },
    { name = "rotStartWeek", value = 1,
      comment = "beginning 1 week after claiming" },
    { name = "rotAbilityCount", value = 3,
      comment = "dexterity, constitution and charisma" },
    { name = "rotDeathScore", value = 0,
      comment = "dead when any score reaches 0" },
  },
  tables = {
  },
}
