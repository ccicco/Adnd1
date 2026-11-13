-- misc magic item def: necklace_of_adaptation
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "necklace_of_adaptation",
  name = "Necklace of Adaptation",
  rows = {
    { name = "Necklace of Adaptation",
      set = "kMisc4", band = { 21, 23 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "adaptationAirlessDays", value = 7,
      comment = "exists in airless space for up to 7 days" },
  },
  tables = {
  },
}
