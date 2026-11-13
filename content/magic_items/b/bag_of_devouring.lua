-- misc magic item def: bag_of_devouring
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bag_of_devouring",
  name = "Bag of Devouring",
  rows = {
    { name = "Bag of Devouring",
      set = "kMisc1", band = { 21, 21 }, xp = 0, xp_hi = 0,
      gp = 1500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "devouringIgnorePct", value = 90,
      comment = "90% likely to ignore initial intrusions" },
    { name = "devouringClosePct", value = 60,
      comment = "60% likely to close on living human flesh" },
    { name = "devouringBaseDrawPct", value = 75,
      comment = "base 75% chance to draw the victim in" },
    { name = "devouringDrawModPerPlus", value = 5,
      comment = "each +1 damage bonus is -5% on the base" },
    { name = "devouringExampleStr18Pct", value = 65,
      comment = "18 strength (+2 damage): only 65%" },
    { name = "devouringExampleStr5Pct", value = 80,
      comment = "5 strength (-1 damage): 80%" },
    { name = "devouringCapacityCubicFeet", value = 30,
      comment = "holds up to 30 cubic feet of matter" },
    { name = "devouringSwallowPctPerTurn", value = 5,
      comment = "5% cumulative chance per turn - THE SEAM FACT, "
      .. "completed from part2 line 3" },
    { name = "devouringConsumeSegments", value = 7,
      comment = "creatures drawn within are consumed in 7 segments" },
  },
  tables = {
  },
}
