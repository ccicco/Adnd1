-- misc magic item def: boots_of_elvenkind
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part3.h (R259)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "boots_of_elvenkind",
  name = "Boots of Elvenkind",
  rows = {
    { name = "Boots of Elvenkind",
      set = "kMisc1", band = { 37, 42 }, xp = 1000, xp_hi = 0,
      gp = 5000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 3, round = 259 },
  },
  pins = {
    { name = "elvenkindSilencePctWorst", value = 95,
      comment = "95% chance of silence in the worst conditions" },
    { name = "elvenkindSilencePctBest", value = 100,
      comment = "100% in the best" },
  },
  tables = {
  },
}
