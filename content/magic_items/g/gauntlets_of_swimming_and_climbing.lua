-- misc magic item def: gauntlets_of_swimming_and_climbing
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "gauntlets_of_swimming_and_climbing",
  name = "Gauntlets of Swimming and Climbing",
  rows = {
    { name = "Gauntlets of Swimming and Climbing",
      set = "kMisc3", band = { 23, 25 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "gauntSwimUnderwaterInches", value = 15,
      comment = "swims as a triton: 15 inches under water" },
    { name = "gauntSwimSurfaceInches", value = 18,
      comment = "swims as a merman: 18 inches on the surface" },
    { name = "gauntSwimClimbSuccessPct", value = 95,
      comment = "95 percent of not slipping while climbing" },
    { name = "gauntSwimThiefSuccessTenthPct", value = 995,
      comment = "a thief climbs at 99.5 percent (tenths)" },
  },
  tables = {
  },
}
