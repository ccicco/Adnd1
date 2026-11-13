-- misc magic item def: phylactery_of_long_years
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part20.h (R276)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "phylactery_of_long_years",
  name = "Phylactery of Long Years",
  rows = {
    { name = "Phylactery of Long Years",
      set = "kMisc4", band = { 71, 74 }, xp = 3000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 20, round = 276 },
  },
  pins = {
    { name = "longYearsSlowPct", value = 25,
      comment = "slows the aging process by one-quarter" },
    { name = "longYearsDonAge", value = 20,
      comment = "the example cleric dons the device at age 20" },
    { name = "longYearsMonthsPerYear", value = 9,
      comment = "he or she will age 9 months every 12" },
    { name = "longYearsPhysicalAge", value = 29,
      comment = "in 12 chronological years, physically 29" },
    { name = "longYearsChronAge", value = 32,
      comment = "rather than the naive 32" },
    { name = "longYearsReverseOneIn", value = 20,
      comment = "1 in 20 cursed to operate in reverse" },
  },
  tables = {
  },
}
