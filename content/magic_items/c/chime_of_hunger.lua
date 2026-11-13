-- misc magic item def: chime_of_hunger
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "chime_of_hunger",
  name = "Chime of Hunger",
  rows = {
    { name = "Chime of Hunger",
      set = "kMisc2", band = { 14, 14 }, xp = 0, xp_hi = 0,
      gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "chimeHungerRadiusInches", value = 6,
      comment = "ravenous hunger radius" },
    { name = "chimeHungerMinEatRounds", value = 1,
      comment = "must eat at least 1 round" },
  },
  tables = {
  },
}
