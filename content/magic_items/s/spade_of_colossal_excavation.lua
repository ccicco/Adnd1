-- misc magic item def: spade_of_colossal_excavation
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "spade_of_colossal_excavation",
  name = "Spade of Colossal Excavation",
  rows = {
    { name = "Spade of Colossal Excavation",
      set = "kMisc5", band = { 47, 47 }, xp = 1000, xp_hi = 0,
      gp = 6500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "spadeLengthFeet", value = 8,
      comment = "the digging tool is 8 feet long" },
    { name = "spadeBladeWidthFeet", value = 2,
      comment = "with a blade 2 feet wide" },
    { name = "spadeBladeLengthFeet", value = 3,
      comment = "and 3 feet long" },
    { name = "spadeUserStrength", value = 18,
      comment = "any fighter with 18 strength can use it" },
    { name = "spadeDigYardsPerRound", value = 1,
      comment = "1 cubic yard excavated in 1 round" },
    { name = "spadeWorkRounds", value = 10,
      comment = "every 10 rounds of digging" },
    { name = "spadeRestRounds", value = 5,
      comment = "forces a rest of 5 rounds" },
    { name = "spadeHardPanFactor", value = 2,
      comment = "hard pan clay takes twice as long" },
    { name = "spadeGravelFactor", value = 2,
      comment = "as does gravel" },
    { name = "spadeLooseSoilDivisor", value = 2,
      comment = "loose soil takes half as long" },
  },
  tables = {
  },
}
