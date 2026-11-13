-- misc magic item def: javelin_of_piercing
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part16.h (R272)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "javelin_of_piercing",
  name = "Javelin of Piercing",
  rows = {
    { name = "Javelin of Piercing",
      set = "kMisc3", band = { 86, 90 }, xp = 250, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 16, round = 272 },
  },
  pins = {
    { name = "javelinPiercingRangeInches", value = 6,
      comment = "range 6 inches, all distances short" },
    { name = "javelinPiercingToHitBonus", value = 6,
      comment = "+6 to hit" },
    { name = "javelinPiercingDamageMin", value = 7,
      comment = "the strike inflicts 7-12 hit points" },
    { name = "javelinPiercingDamageMax", value = 12,
      comment = "the upper edge of the 7-12 damage" },
    { name = "javelinPiercingFoundMin", value = 2,
      comment = "from 2-8 will be found" },
    { name = "javelinPiercingFoundMax", value = 8,
      comment = "the upper edge of the 2-8 find" },
    { name = "javelinPiercingThrows", value = 1,
      comment = "the magic is good for only 1 throw" },
  },
  tables = {
  },
}
