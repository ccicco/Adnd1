-- misc magic item def: cubic_gate
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part7.h (R263)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cubic_gate",
  name = "Cubic Gate",
  rows = {
    { name = "Cubic Gate",
      set = "kMisc2", band = { 66, 67 }, xp = 5000, xp_hi = 0,
      gp = 17500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 7, round = 263 },
  },
  pins = {
    { name = "cubicGateSideCount", value = 6,
      comment = "the 6 sides, each keyed to a plane" },
    { name = "cubicGatePrimeSides", value = 1,
      comment = "one side is always Prime Material" },
    { name = "cubicGateChosenSides", value = 5,
      comment = "the other 5 are chosen" },
    { name = "cubicGateNexusChancePct", value = 10,
      comment = "per turn, something comes through" },
    { name = "cubicGateDrawRadiusFeet", value = 5,
      comment = "second press draws all within" },
    { name = "cubicGateMaxLinks", value = 1,
      comment = "no more than 1 nexial link at once" },
  },
  tables = {
  },
}
