-- misc magic item def: mattock_of_the_titans
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "mattock_of_the_titans",
  name = "Mattock of the Titans",
  rows = {
    { name = "Mattock of the Titans",
      set = "kMisc4", band = { 11, 11 }, xp = 3500, xp_hi = 0,
      gp = 7000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "mattockLengthFeet", value = 10,
      comment = "the huge digging tool is 10 feet long" },
    { name = "mattockWeightLb", value = 100,
      comment = "and weighs over 100 pounds" },
    { name = "mattockMinStrength", value = 20,
      comment = "a giant-sized user of strength 20 or more" },
    { name = "mattockEarthCubicFeet", value = 100,
      comment = "loosens earth in a 100 cubic foot area" },
    { name = "mattockRockCubicFeet", value = 20,
      comment = "smashes rock in a 20 cubic feet area" },
    { name = "mattockAreaTurns", value = 1,
      comment = "either area in 1 turn of work" },
    { name = "mattockHitBonus", value = 3,
      comment = "+3 to hit as a weapon" },
    { name = "mattockDamageMin", value = 5,
      comment = "does 5-30 damage, strength bonuses aside" },
    { name = "mattockDamageMax", value = 30,
      comment = "the upper edge of the 5-30 damage" },
  },
  tables = {
  },
}
