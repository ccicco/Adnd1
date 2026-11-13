-- misc magic item def: saw_of_mighty_cutting
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "saw_of_mighty_cutting",
  name = "Saw of Mighty Cutting",
  rows = {
    { name = "Saw of Mighty Cutting",
      set = "kMisc5", band = { 34, 34 }, xp = 1750, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "sawLengthFeet", value = 12,
      comment = "the notched adamantite blade is 12 feet" },
    { name = "sawWidthFeet", value = 1,
      comment = "long and over 1 foot wide" },
    { name = "sawSoloStrength", value = 18,
      comment = "requires 18/00 or greater strength alone" },
    { name = "sawTandemStrength", value = 17,
      comment = "or 2 persons of 17 or greater strength" },
    { name = "sawTandemPersons", value = 2,
      comment = "working in tandem" },
    { name = "sawHardwoodFeet", value = 2,
      comment = "a 2 foot thick hardwood tree" },
    { name = "sawHardwoodTurns", value = 1,
      comment = "sliced through in 1 turn" },
    { name = "sawTrunkFeet", value = 4,
      comment = "a 4 foot thick trunk" },
    { name = "sawTrunkTurns", value = 3,
      comment = "sliced through in 3 turns" },
    { name = "sawSmallDiameterFeet", value = 1,
      comment = "a 1 foot diameter tree" },
    { name = "sawSmallRounds", value = 3,
      comment = "sliced through in but 3 rounds" },
    { name = "sawWorkTurns", value = 6,
      comment = "after 6 turns of cutting" },
    { name = "sawRestTurns", value = 6,
      comment = "the users must rest for 6 turns" },
  },
  tables = {
  },
}
