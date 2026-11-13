-- misc magic item def: brazier_commanding_fire_elementals
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "brazier_commanding_fire_elementals",
  name = "Brazier Commanding Fire Elementals",
  rows = {
    { name = "Brazier Commanding Fire Elementals",
      set = "kMisc1", band = { 82, 84 }, xp = 4000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "brazierFireHd", value = 12,
      comment = "the summoned fire elemental" },
    { name = "brazierFireLightRounds", value = 1,
      comment = "lighting the fire usually takes 1 round" },
    { name = "brazierFireSulphurBonusPerDie", value = 1,
      comment = "sulphur: +1 on each hit die" },
    { name = "brazierFireSulphurHpMin", value = 2,
      comment = "sulphur: 2-9 hp per die" },
    { name = "brazierFireSulphurHpMax", value = 9,
      comment = "sulphur: 2-9 hp per die" },
  },
  tables = {
  },
}
