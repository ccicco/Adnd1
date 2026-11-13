-- misc magic item def: mirror_of_life_trapping
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "mirror_of_life_trapping",
  name = "Mirror of Life Trapping",
  rows = {
    { name = "Mirror of Life Trapping",
      set = "kMisc4", band = { 18, 18 }, xp = 2500, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "trapAreaSquareFeet", value = 4,
      comment = "the crystal device about 4 square feet" },
    { name = "trapCellMin", value = 13,
      comment = "from 13 compartments at the fewest" },
    { name = "trapCellMax", value = 18,
      comment = "to 18 compartments at the most" },
    { name = "trapTriggerFeet", value = 30,
      comment = "a looker coming within 30 feet" },
    { name = "trapSeePctUnaware", value = 100,
      comment = "100 percent when unaware of the device" },
    { name = "trapSeePctAvoiding", value = 50,
      comment = "dropping to 50 when actively avoiding" },
    { name = "trapSeePctAware", value = 20,
      comment = "and 20 when aware it traps life" },
    { name = "trapOverflowFreed", value = 1,
      comment = "1 random victim freed on overflow" },
  },
  tables = {
  },
}
