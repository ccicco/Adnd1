-- misc magic item def: librams
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part17.h (R273)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "librams",
  name = "Librams (the three librams)",
  rows = {
    { name = "Libram of Gainful Conjuration",
      set = "kMisc4", band = { 1, 1 }, xp = 8000, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Libram of Ineffable Damnation",
      set = "kMisc4", band = { 2, 2 }, xp = 8000, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Libram of Silver Magic",
      set = "kMisc4", band = { 3, 3 }, xp = 8000, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 17, round = 273 },
  },
  pins = {
    { name = "libramStudyWeeks", value = 1,
      comment = "a full week of cloistered study" },
    { name = "libramMisuseDamageMin", value = 5,
      comment = "a non-neutral reader takes 5-20 damage" },
    { name = "libramMisuseDamageMax", value = 20,
      comment = "the upper edge of the 5-20 damage" },
    { name = "libramUnconsciousTurnsMin", value = 5,
      comment = "unconscious a like number of turns" },
    { name = "libramUnconsciousTurnsMax", value = 20,
      comment = "the upper edge of the like-number turns" },
    { name = "libramInsanityRestMonths", value = 1,
      comment = "the insane reader rests 1 month" },
    { name = "libramDamnationLevelLoss", value = 1,
      comment = "a non-evil look inside loses 1 level" },
  },
  tables = {
  },
}
