-- misc magic item def: talisman_of_pure_good
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "talisman_of_pure_good",
  name = "Talisman of Pure Good",
  rows = {
    { name = "Talisman of Pure Good",
      set = "kMisc5", band = { 55, 57 }, xp = 3500, xp_hi = 0,
      gp = 27500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "pureGoodCharges", value = 7,
      comment = "the talisman of pure good has 7 charges" },
    { name = "pureGoodRechargeable", value = 0,
      comment = "it cannot be recharged" },
    { name = "pureGoodNeutralDmgMin", value = 7,
      comment = "a neutral cleric touching it takes 7-28 damage" },
    { name = "pureGoodNeutralDmgMax", value = 28,
      comment = "the neutral touch ceiling" },
    { name = "pureGoodEvilDmgMin", value = 12,
      comment = "an evil cleric touching it takes 12-48 damage" },
    { name = "pureGoodEvilDmgMax", value = 48,
      comment = "the evil touch ceiling" },
    { name = "pureGoodNonClericDmg", value = 0,
      comment = "non-clerics are not affected by the device" },
  },
  tables = {
  },
}
