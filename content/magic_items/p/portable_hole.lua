-- misc magic item def: portable_hole
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part20.h (R276)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "portable_hole",
  name = "Portable Hole",
  rows = {
    { name = "Portable Hole",
      set = "kMisc4", band = { 85, 85 }, xp = 5000, xp_hi = 0,
      gp = 50000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 20, round = 276 },
  },
  pins = {
    { name = "holeDiameterFeet", value = 6,
      comment = "opened fully, 6 feet in diameter" },
    { name = "holeDepthFeet", value = 10,
      comment = "an extra-dimensional hole 10 feet deep" },
    { name = "holeBreathTurns", value = 1,
      comment = "breath runs out after about a turn" },
    { name = "holeGateRadiusFeet", value = 10,
      comment = "creatures within a 10 foot radius are drawn to the "
      .. "plane, both items destroyed" },
  },
  tables = {
  },
}
