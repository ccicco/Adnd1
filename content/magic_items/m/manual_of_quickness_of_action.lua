-- misc magic item def: manual_of_quickness_of_action
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part17.h (R273)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "manual_of_quickness_of_action",
  name = "Manual of Quickness of Action",
  rows = {
    { name = "Manual of Quickness of Action",
      set = "kMisc4", band = { 9, 9 }, xp = 5000, xp_hi = 0,
      gp = 50000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 17, round = 273 },
  },
  pins = {
    { name = "quicknessStudyDays", value = 3,
      comment = "3 days of uninterrupted study" },
    { name = "quicknessPracticeMonths", value = 1,
      comment = "the skills practiced 1 month" },
    { name = "quicknessDexGain", value = 1,
      comment = "the practice gains 1 point of dexterity" },
    { name = "quicknessRememberMonths", value = 3,
      comment = "the contents remembered 3 months" },
  },
  tables = {
  },
}
