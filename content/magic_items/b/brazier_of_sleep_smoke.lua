-- misc magic item def: brazier_of_sleep_smoke
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "brazier_of_sleep_smoke",
  name = "Brazier of Sleep Smoke",
  rows = {
    { name = "Brazier of Sleep Smoke",
      set = "kMisc1", band = { 85, 85 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "sleepSmokeRadiusInches", value = 1,
      comment = "the smoke cloud radius" },
    { name = "sleepSmokeHd", value = 12,
      comment = "the fire elemental that appears" },
    { name = "sleepSmokeAwakenSpellCount", value = 2,
      comment = "dispel magic or remove curse" },
  },
  tables = {
  },
}
