-- misc magic item def: apparatus_of_kwalish
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "apparatus_of_kwalish",
  name = "Apparatus of Kwalish",
  rows = {
    { name = "Apparatus of Kwalish",
      set = "kMisc1", band = { 12, 13 }, xp = 8000, xp_hi = 0,
      gp = 35000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "kwalishLeverCount", value = 10,
      comment = "10 levers inside" },
    { name = "kwalishForwardInches", value = 3,
      comment = "moves forward at 3 inches" },
    { name = "kwalishBackwardInches", value = 6,
      comment = "backwards at 6 inches" },
    { name = "kwalishPincerReachFeet", value = 4,
      comment = "pincers extend forward 4 feet" },
    { name = "kwalishPincerDamageLo", value = 2,
      comment = "snap for 2-12 hit points each" },
    { name = "kwalishPincerDamageHi", value = 12 },
    { name = "kwalishPincerHitPct", value = 25,
      comment = "25% chance, no armor reduction" },
    { name = "kwalishMaxDepthFeet", value = 900,
      comment = "operates in waters up to 900 feet" },
    { name = "kwalishOccupants", value = 2,
      comment = "holds 2 human-sized persons" },
    { name = "kwalishAirHoursLo", value = 2,
      comment = "air for 2-5 hours at maximum capacity" },
    { name = "kwalishAirHoursHi", value = 5 },
    { name = "kwalishArmorClass", value = 0,
      comment = "the apparatus is AC 0" },
    { name = "kwalishLeakHp", value = 100,
      comment = "100 hit points to cause a leak" },
    { name = "kwalishStaveHp", value = 200,
      comment = "200 to stave in a side" },
  },
  tables = {
  },
}
