-- misc magic item def: eversmoking_bottle
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "eversmoking_bottle",
  name = "Eversmoking Bottle",
  rows = {
    { name = "Eversmoking Bottle",
      set = "kMisc2", band = { 94, 94 }, xp = 500, xp_hi = 0,
      gp = 2500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "eversmokeFirstRoundCubicFeet", value = 50000,
      comment = "obscures a 50000 cubic foot area" },
    { name = "eversmokePerRoundCubicFeet", value = 10000,
      comment = "10000 cubic feet more each round" },
    { name = "eversmokeMaxCubicFeet", value = 120000,
      comment = "until 120000 cubic feet are fogged" },
  },
  tables = {
  },
}
