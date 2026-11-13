-- misc magic item def: horseshoes_of_speed
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part13.h (R269)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "horseshoes_of_speed",
  name = "Horseshoes of Speed",
  rows = {
    { name = "Horseshoes of Speed",
      set = "kMisc3", band = { 61, 63 }, xp = 2000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 13, round = 269 },
  },
  pins = {
    { name = "horseshoesSpeedShoeCount", value = 4,
      comment = "4 normal-appearing iron horse shoes" },
    { name = "horseshoesSpeedFullPct", value = 200,
      comment = "affixed, they double the animal speed (the 200 "
      .. "percent full rate)" },
    { name = "horseshoesSpeedDropPct", value = 1,
      comment = "a 1 percent chance per 7 leagues travelled that 1 "
      .. "shoe drops off" },
    { name = "horseshoesSpeedDropLeagues", value = 7,
      comment = "the drop interval in leagues" },
    { name = "horseshoesSpeedOneLostPct", value = 150,
      comment = "one lost and unnoticed: 150 percent of the normal "
      .. "rate" },
    { name = "horseshoesSpeedTwoLostPct", value = 100,
      comment = "2 lost: the speed is normal" },
  },
  tables = {
  },
}
