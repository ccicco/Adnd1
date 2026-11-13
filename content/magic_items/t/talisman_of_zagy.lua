-- misc magic item def: talisman_of_zagy
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "talisman_of_zagy",
  name = "Talisman of Zagy",
  rows = {
    { name = "Talisman of Zagy",
      set = "kMisc5", band = { 61, 66 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "zagyHostileDmgMin", value = 5,
      comment = "a hostile reaction acts as a stone of weight; "
      .. "discarding or destroying it costs 5-30 damage" },
    { name = "zagyHostileDmgMax", value = 30,
      comment = "the hostile discard ceiling" },
    { name = "zagyNeutralHoursMin", value = 5,
      comment = "a neutral reaction stays 5-30 hours" },
    { name = "zagyNeutralHoursMax", value = 30,
      comment = "the neutral stay ceiling" },
    { name = "zagyFriendlyMonthsPerChaPoint", value = 1,
      comment = "friendly, it stays one month per charisma point" },
    { name = "zagyWishChaDivisor", value = 6,
      comment = "it grants 1 wish per 6 charisma points" },
    { name = "zagyTrapRangeFeet", value = 20,
      comment = "it grows warm within 20 feet of a trap" },
    { name = "zagyDiamondGp", value = 10000,
      comment = "a base 10,000 gp diamond remains behind" },
  },
  tables = {
  },
}
