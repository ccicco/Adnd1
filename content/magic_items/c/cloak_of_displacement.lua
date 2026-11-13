-- misc magic item def: cloak_of_displacement
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cloak_of_displacement",
  name = "Cloak of Displacement",
  rows = {
    { name = "Cloak of Displacement",
      set = "kMisc2", band = { 15, 18 }, xp = 3000, xp_hi = 0,
      gp = 17500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "displacementMinFeet", value = 1,
      comment = "apparent offset, minimum" },
    { name = "displacementMaxFeet", value = 2,
      comment = "apparent offset, maximum" },
    { name = "displacementAcBonus", value = 2,
      comment = "2 classes better, after the first attack" },
    { name = "displacementSaveBonus", value = 2,
      comment = "saving throw dice bonus" },
    { name = "displacementHumanoidPct", value = 75,
      comment = "sized for humans or elves" },
    { name = "displacementSmallPct", value = 25,
      comment = "sized for 4-foot persons" },
  },
  tables = {
  },
}
