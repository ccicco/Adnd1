-- misc magic item def: broom_of_flying
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "broom_of_flying",
  name = "Broom of Flying",
  rows = {
    { name = "Broom of Flying",
      set = "kMisc1", band = { 94, 98 }, xp = 2000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "broomFlySpeedInches", value = 30,
      comment = "movement speed" },
    { name = "broomFlyCapacityPounds", value = 182,
      comment = "carries 182 pounds at speed" },
    { name = "broomFlyPoundsPerInch", value = 14,
      comment = "every 14 pounds slows 1 inch" },
    { name = "broomFlyClimbDiveDegrees", value = 30,
      comment = "climb or dive angle" },
    { name = "broomFlyFetchSpeedInches", value = 30,
      comment = "comes to its owner at up to 30" },
  },
  tables = {
  },
}
