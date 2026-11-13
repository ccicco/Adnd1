-- misc magic item def: vacuous_grimoire
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "vacuous_grimoire",
  name = "Vacuous Grimoire",
  rows = {
    { name = "Vacuous Grimoire",
      set = "kMisc5", band = { 86, 87 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "vacuousSaveCount", value = 2,
      comment = "the reader must make 2 saving throws versus magic" },
    { name = "vacuousIntLoss", value = 1,
      comment = "the first throw: 1 point of intelligence lost" },
    { name = "vacuousWisLoss", value = 2,
      comment = "the second throw: 2 points of wisdom lost" },
    { name = "vacuousBurnAfterRemoveCurse", value = 1,
      comment = "it must be burned to be rid of after remove curse" },
  },
  tables = {
  },
}
