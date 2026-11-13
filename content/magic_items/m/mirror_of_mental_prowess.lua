-- misc magic item def: mirror_of_mental_prowess
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "mirror_of_mental_prowess",
  name = "Mirror of Mental Prowess",
  rows = {
    { name = "Mirror of Mental Prowess",
      set = "kMisc4", band = { 19, 19 }, xp = 5000, xp_hi = 0,
      gp = 50000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "prowessQuestionsPerWeek", value = 1,
      comment = "answers one short question per week" },
    { name = "prowessWidthFeet", value = 5,
      comment = "the typical mirror 5 feet by" },
    { name = "prowessHeightFeet", value = 2,
      comment = "2 feet" },
  },
  tables = {
  },
}
