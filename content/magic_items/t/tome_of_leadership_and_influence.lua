-- misc magic item def: tome_of_leadership_and_influence
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "tome_of_leadership_and_influence",
  name = "Tome of Leadership and Influence",
  rows = {
    { name = "Tome of Leadership and Influence",
      set = "kMisc5", band = { 68, 68 }, xp = 7500, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "leadershipChaGain", value = 1,
      comment = "leadership and influence raises charisma by 1" },
  },
  tables = {
  },
}
