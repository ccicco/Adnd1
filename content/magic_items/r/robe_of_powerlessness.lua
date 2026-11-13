-- misc magic item def: robe_of_powerlessness
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part21.h (R277)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "robe_of_powerlessness",
  name = "Robe of Powerlessness",
  rows = {
    { name = "Robe of Powerlessness",
      set = "kMisc5", band = { 10, 10 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 21, round = 277 },
  },
  pins = {
    { name = "powerlessIntelligence", value = 3,
      comment = "the wearer drops to 3 intelligence" },
    { name = "powerlessStrength", value = 3,
      comment = "and becomes weak as well (3 strength)" },
  },
  tables = {
  },
}
