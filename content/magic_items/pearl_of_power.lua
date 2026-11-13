-- misc magic item def: pearl_of_power
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "pearl_of_power",
  name = "Pearl of Power",
  rows = {
    { name = "Pearl of Power",
      set = "kMisc4", band = { 45, 46 }, xp = 200, xp_hi = 0,
      gp = 2000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "powerRecallPerDay", value = 1,
      comment = "once a day the pearl recalls" },
    { name = "powerSpellsRecalled", value = 1,
      comment = "recalls any 1 spell as desired" },
    { name = "powerReverseOneIn", value = 20,
      comment = "1 in 20 of opposite effect" },
    { name = "powerDoubleMin", value = 2,
      comment = "the 00 row recalls 2 spells" },
    { name = "powerDoubleMaxLevel", value = 6,
      comment = "of 1st to 6th level" },
    { name = "powerDoubleDieSides", value = 6,
      comment = "the level picked by d6" },
  },
  tables = {
    { name = "powerRowLo",
      comment = "the printed die band lower edges; i clamps",
      clamp_hi = 9,
      values = {
        1, 26, 46, 61, 76, 86, 93, 97, 99, 100,
      } },
    { name = "powerRowHi",
      comment = "the printed die band upper edges; i clamps",
      clamp_hi = 9,
      values = {
        25, 45, 60, 75, 85, 92, 96, 98, 99, 100,
      } },
    { name = "powerSpellLevel",
      comment = "the spell level per die band, the 00 row marked 0 for "
      .. "the double-spell special; clamps",
      clamp_hi = 9,
      values = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
      } },
  },
}
