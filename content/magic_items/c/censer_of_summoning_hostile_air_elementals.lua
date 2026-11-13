-- misc magic item def: censer_of_summoning_hostile_air_elementals
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "censer_of_summoning_hostile_air_elementals",
  name = "Censer of Summoning Hostile Air Elementals",
  rows = {
    { name = "Censer of Summoning Hostile Air Elementals",
      set = "kMisc2", band = { 11, 11 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "censerHostileMin", value = 1,
      comment = "enraged elementals, minimum" },
    { name = "censerHostileMax", value = 4,
      comment = "enraged elementals, maximum" },
    { name = "censerHostilePerRound", value = 1,
      comment = "elementals appear 1 per round" },
  },
  tables = {
  },
}
