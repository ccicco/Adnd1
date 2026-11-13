-- misc magic item def: dust_of_sneezing_and_choking
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "dust_of_sneezing_and_choking",
  name = "Dust of Sneezing and Choking",
  rows = {
    { name = "Dust of Sneezing and Choking",
      set = "kMisc2", band = { 92, 92 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "dustChokeRadiusFeet", value = 20,
      comment = "the sneezing fits radius" },
    { name = "dustChokeDisabledMinRounds", value = 5,
      comment = "survivors disabled 5-20 rounds" },
    { name = "dustChokeDisabledMaxRounds", value = 20,
      comment = "survivors disabled 5-20 rounds" },
  },
  tables = {
  },
}
