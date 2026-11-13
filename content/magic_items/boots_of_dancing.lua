-- misc magic item def: boots_of_dancing
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part3.h (R259)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "boots_of_dancing",
  name = "Boots of Dancing",
  rows = {
    { name = "Boots of Dancing",
      set = "kMisc1", band = { 36, 36 }, xp = 0, xp_hi = 0,
      gp = 5000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 3, round = 259 },
  },
  pins = {
    { name = "dancingDisguisedBootTypeCount", value = 4,
      comment = "masquerade as one of the other 4 useful types until "
      .. "melee combat" },
    { name = "dancingTriggerCaseCount", value = 2,
      comment = "in melee, or fleeing from the actuality" },
    { name = "dancingAcPenalty", value = 4,
      comment = "the armor class penalty" },
    { name = "dancingRemovalSpellCount", value = 1,
      comment = "only a remove curse spell frees the wearer" },
  },
  tables = {
  },
}
