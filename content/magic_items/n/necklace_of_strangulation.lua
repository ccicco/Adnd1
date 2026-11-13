-- misc magic item def: necklace_of_strangulation
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "necklace_of_strangulation",
  name = "Necklace of Strangulation",
  rows = {
    { name = "Necklace of Strangulation",
      set = "kMisc4", band = { 34, 35 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "strangleDamagePerRound", value = 6,
      comment = "6 hit points of strangulation damage per round" },
  },
  tables = {
  },
}
