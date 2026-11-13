-- misc magic item def: gem_of_seeing
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "gem_of_seeing",
  name = "Gem of Seeing",
  rows = {
    { name = "Gem of Seeing",
      set = "kMisc3", band = { 27, 27 }, xp = 2000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "gemSeeCursoryRangeInches", value = 30,
      comment = "cursory scan range 30 inches" },
    { name = "gemSeeCarefulRangeInches", value = 10,
      comment = "small things: 10 inches" },
    { name = "gemSeeCursoryAreaFeet", value = 200,
      comment = "1 round scans a 200 feet square" },
    { name = "gemSeeCursoryRounds", value = 1,
      comment = "the cursory scan takes 1 round" },
    { name = "gemSeeCarefulAreaFeet", value = 100,
      comment = "2 rounds view a 100 feet square" },
    { name = "gemSeeCarefulRounds", value = 2,
      comment = "the careful view takes 2 rounds" },
    { name = "gemSeeHallucinationPct", value = 5,
      comment = "5 percent chance of an hallucination" },
  },
  tables = {
  },
}
