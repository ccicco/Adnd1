-- misc magic item def: bowl_commanding_water_elementals
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bowl_commanding_water_elementals",
  name = "Bowl Commanding Water Elementals",
  rows = {
    { name = "Bowl Commanding Water Elementals",
      set = "kMisc1", band = { 56, 58 }, xp = 4000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "bowlCmdHd", value = 12,
      comment = "the summoned water elemental" },
    { name = "bowlCmdWordsRounds", value = 1,
      comment = "the summoning words take 1 round" },
    { name = "bowlCmdSaltBonusPerDie", value = 2,
      comment = "salt water: +2 per hit die" },
    { name = "bowlCmdSaltMaxHpPerDie", value = 8,
      comment = "salt water: max 8 hp per die" },
    { name = "bowlCmdDiameterInches", value = 12,
      comment = "about 1 foot across" },
    { name = "bowlCmdDepthInches", value = 6,
      comment = "half the diameter" },
  },
  tables = {
  },
}
