-- misc magic item def: cloak_of_manta_ray
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cloak_of_manta_ray",
  name = "Cloak of Manta Ray",
  rows = {
    { name = "Cloak of Manta Ray",
      set = "kMisc2", band = { 28, 30 }, xp = 2000, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "mantaRayLikenessPct", value = 90,
      comment = "identical to a manta ray in salt water" },
    { name = "mantaRayMoveInches", value = 18,
      comment = "moves as a manta ray" },
    { name = "mantaRayAc", value = 6,
      comment = "armor class of at least 6" },
    { name = "mantaRayTailDmgMin", value = 1,
      comment = "tail spine damage" },
    { name = "mantaRayTailDmgMax", value = 6,
      comment = "tail spine damage" },
    { name = "mantaRayTailStun", value = 0,
      comment = "no chance of stunning" },
    { name = "mantaRaySaltWaterTrigger", value = 1,
      comment = "the cloak adheres in salt water" },
  },
  tables = {
  },
}
