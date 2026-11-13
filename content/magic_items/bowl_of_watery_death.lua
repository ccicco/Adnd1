-- misc magic item def: bowl_of_watery_death
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bowl_of_watery_death",
  name = "Bowl of Watery Death",
  rows = {
    { name = "Bowl of Watery Death",
      set = "kMisc1", band = { 59, 59 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "wateryDeathSaltSavePenalty", value = 2,
      comment = "salt water: the save is at minus 2" },
    { name = "wateryDeathDrownMinRounds", value = 3,
      comment = "the victim drowns in 3-8 rounds" },
    { name = "wateryDeathDrownMaxRounds", value = 8,
      comment = "the victim drowns in 3-8 rounds" },
    { name = "wateryDeathFreeSpellCount", value = 3,
      comment = "animal growth, enlarge, wish" },
    { name = "wateryDeathDeathPermanent", value = 1,
      comment = "no resurrection, even a wish fails" },
    { name = "wateryDeathSweetWaterAnotherSave", value = 1,
      comment = "a sweet water potion: another save" },
  },
  tables = {
  },
}
