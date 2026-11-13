-- misc magic item def: eyes_of_charming
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "eyes_of_charming",
  name = "Eyes of Charming",
  rows = {
    { name = "Eyes of Charming",
      set = "kMisc2", band = { 95, 95 }, xp = 4000, xp_hi = 0,
      gp = 24000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "eyesCharmTargetsPerRound", value = 1,
      comment = "one person per round can be looked at" },
    { name = "eyesCharmBothSaveMod", value = -2,
      comment = "both lenses: saves at -2" },
    { name = "eyesCharmOneSaveMod", value = 2,
      comment = "only 1 of a pair: saves at +2" },
  },
  tables = {
  },
}
