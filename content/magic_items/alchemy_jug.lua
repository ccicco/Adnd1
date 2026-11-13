-- misc magic item def: alchemy_jug
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "alchemy_jug",
  name = "Alchemy Jug",
  rows = {
    { name = "Alchemy Jug",
      set = "kMisc1", band = { 1, 2 }, xp = 3000, xp_hi = 0,
      gp = 12000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "alchemyJugRowCount", value = 11,
      comment = "11 pourable liquids" },
    { name = "alchemyJugKindsPerDay", value = 1,
      comment = "only 1 kind of liquid on any given day" },
    { name = "alchemyJugPouringsPerDay", value = 7,
      comment = "7 pourings maximum" },
    { name = "alchemyJugGallonsPerRound", value = 2,
      comment = "pours forth 2 gallons per round" },
    { name = "alchemyJugRoundsPerLargePouring", value = 8,
      comment = "8 rounds for 1 pouring of salt water" },
  },
  tables = {
    { name = "alchemyJugRowQty",
      comment = "salt water 16 gallons, fresh 8, beer 4, vinegar 2, wine "
      .. "1, ammonia 1 quart, oil 1 pint, aqua regia 2 gills, "
      .. "alcohol 1 gill, chlorine 8 drams, cyanide 4 drams",
      values = {
        16, 8, 4, 2, 1, 1, 1, 2, 1, 8, 4,
      } },
    { name = "alchemyJugRowUnit",
      comment = "0 gallons, 1 quart, 2 pint, 3 gill, 4 drams",
      values = {
        0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4,
      } },
  },
}
