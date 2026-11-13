-- misc magic item def: iron_flask
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part16.h (R272)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "iron_flask",
  name = "Iron Flask",
  rows = {
    { name = "Iron Flask",
      set = "kMisc3", band = { 79, 80 }, xp = 0, xp_hi = 0,
      gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 16, round = 272 },
  },
  pins = {
    { name = "flaskRangeInches", value = 6,
      comment = "the command range is 6 inches" },
    { name = "flaskMaxCreatures", value = 1,
      comment = "only 1 creature at a time can be held" },
    { name = "flaskServiceTurns", value = 1,
      comment = "forced service lasts 1 turn" },
    { name = "flaskServiceHours", value = 1,
      comment = "a minor service up to 1 hour of time" },
    { name = "flaskRepeatSaveBonus", value = 2,
      comment = "a second forcing attempt saves at +2" },
    { name = "flaskContentsRowCount", value = 19,
      comment = "19 bands, empty through xorn" },
  },
  tables = {
    { name = "flaskContentsLo",
      comment = "the printed band lower edges; i clamps",
      clamp_hi = 18,
      values = {
        1, 51, 55, 57, 58, 60, 61, 66, 70, 73, 77, 82, 84, 86, 87, 90, 94,
          98, 100,
      } },
    { name = "flaskContentsHi",
      comment = "the printed band upper edges; i clamps",
      clamp_hi = 18,
      values = {
        50, 54, 56, 57, 59, 60, 65, 69, 72, 76, 81, 83, 85, 86, 89, 93, 97,
          99, 100,
      } },
  },
}
