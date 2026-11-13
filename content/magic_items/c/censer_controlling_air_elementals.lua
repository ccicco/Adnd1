-- misc magic item def: censer_controlling_air_elementals
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "censer_controlling_air_elementals",
  name = "Censer Controlling Air Elementals",
  rows = {
    { name = "Censer Controlling Air Elementals",
      set = "kMisc2", band = { 9, 10 }, xp = 4000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "censerAirHd", value = 12,
      comment = "the summoned air elemental" },
    { name = "censerAirMedBonusPerDie", value = 3,
      comment = "incense of meditation: +3 per die" },
    { name = "censerAirWidthInches", value = 6,
      comment = "the half-foot-wide vessel" },
    { name = "censerAirHeightInches", value = 12,
      comment = "the 1-foot-high vessel" },
    { name = "censerAirTurnsIfExtinguished", value = 1,
      comment = "extinguished: elemental remains, turns hostile" },
  },
  tables = {
  },
}
