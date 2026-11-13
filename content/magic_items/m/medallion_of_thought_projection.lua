-- misc magic item def: medallion_of_thought_projection
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "medallion_of_thought_projection",
  name = "Medallion of Thought Projection",
  rows = {
    { name = "Medallion of Thought Projection",
      set = "kMisc4", band = { 16, 17 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "projectionWorksRoll", value = 6,
      comment = "correct without projecting on a roll of 6" },
  },
  tables = {
  },
}
