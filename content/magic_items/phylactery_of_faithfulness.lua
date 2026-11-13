-- misc magic item def: phylactery_of_faithfulness
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part20.h (R276)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "phylactery_of_faithfulness",
  name = "Phylactery of Faithfulness",
  rows = {
    { name = "Phylactery of Faithfulness",
      set = "kMisc4", band = { 65, 70 }, xp = 1000, xp_hi = 0,
      gp = 7500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 20, round = 276 },
  },
  pins = {
  },
  tables = {
  },
}
