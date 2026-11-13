-- misc magic item def: scarab_of_enraging_enemies
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "scarab_of_enraging_enemies",
  name = "Scarab of Enraging Enemies",
  rows = {
    { name = "Scarab of Enraging Enemies",
      set = "kMisc5", band = { 36, 38 }, xp = 1000, xp_hi = 0,
      gp = 8000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "enrageRadiusInches", value = 4,
      comment = "enrages hostiles within a 4 inch radius" },
    { name = "enrageToHitBonus", value = 1,
      comment = "the enraged gain +1 to hit" },
    { name = "enrageDamageBonus", value = 2,
      comment = "and +2 on damage" },
    { name = "enrageAcPenalty", value = 3,
      comment = "and -3 on their own armor class" },
    { name = "enrageRageMin", value = 7,
      comment = "the rage lasts for 7-12 rounds" },
    { name = "enrageRageMax", value = 12,
      comment = "the rage ceiling" },
    { name = "enrageChargesMin", value = 19,
      comment = "contains from 19-24 charges" },
    { name = "enrageChargesMax", value = 24,
      comment = "the charge ceiling" },
  },
  tables = {
  },
}
