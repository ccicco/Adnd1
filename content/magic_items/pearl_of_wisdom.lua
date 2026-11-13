-- misc magic item def: pearl_of_wisdom
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "pearl_of_wisdom",
  name = "Pearl of Wisdom",
  rows = {
    { name = "Pearl of Wisdom",
      set = "kMisc4", band = { 47, 48 }, xp = 500, xp_hi = 0,
      gp = 5000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "wisdomGain", value = 1,
      comment = "the cleric gains 1 point of wisdom" },
    { name = "wisdomMonths", value = 1,
      comment = "retained for a 1 month period" },
    { name = "wisdomDays", value = 30,
      comment = "the gain at the expiration of 30 days" },
    { name = "wisdomReverseOneIn", value = 20,
      comment = "1 in 20 cursed to work in reverse" },
  },
  tables = {
  },
}
