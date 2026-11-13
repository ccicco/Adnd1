-- misc magic item def: nolzurs_marvelous_pigments
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "nolzurs_marvelous_pigments",
  name = "Nolzur's Marvelous Pigments",
  rows = {
    { name = "Nolzur's Marvelous Pigments",
      set = "kMisc4", band = { 43, 44 }, xp = 500, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "pigPotCubicFeet", value = 1000,
      comment = "one pot creates a 1,000 cubic foot object" },
    { name = "pigDepictSquareFeet", value = 100,
      comment = "depicted over a 100 square foot surface" },
    { name = "pigContainersMin", value = 1,
      comment = "from 1-4 containers found" },
    { name = "pigContainersMax", value = 4,
      comment = "the upper edge of the 1-4 containers" },
    { name = "pigInstrumentFeet", value = 1,
      comment = "a single instrument about 1 foot long" },
    { name = "pigDepictTurns", value = 1,
      comment = "1 turn to depict an object" },
  },
  tables = {
  },
}
