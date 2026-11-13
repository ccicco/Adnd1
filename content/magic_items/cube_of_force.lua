-- misc magic item def: cube_of_force
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part7.h (R263)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cube_of_force",
  name = "Cube of Force",
  rows = {
    { name = "Cube of Force",
      set = "kMisc2", band = { 62, 63 }, xp = 3000, xp_hi = 0,
      gp = 20000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 7, round = 263 },
  },
  pins = {
    { name = "cubeForceWallInches", value = 1,
      comment = "wall of force, 1 inch per side" },
    { name = "cubeForceCharges", value = 36,
      comment = "the cube has 36 charges" },
    { name = "cubeForceRestoreDays", value = 1,
      comment = "energy restored each day" },
    { name = "cubeForceFaceCount", value = 6,
      comment = "six faces, one per screen strength" },
    { name = "cubeForceSurchargeFormCount", value = 14,
      comment = "the attack-form surcharge table entries" },
    { name = "cubeForceSpellsInOutBlocked", value = 1,
      comment = "no casting into or out of the cube" },
    { name = "cubeForceMaterialCount", value = 3,
      comment = "hard mineral, ivory, bone" },
  },
  tables = {
    { name = "cubeForceCostPerTurn",
      comment = "the face charge cost; i clamps",
      clamp_hi = 5,
      values = {
        1, 2, 3, 4, 6, 0,
      } },
    { name = "cubeForceMoveInches",
      comment = "the face movement rate; 0 is normal; i clamps",
      clamp_hi = 5,
      values = {
        1, 8, 6, 4, 3, 0,
      } },
    { name = "cubeForceSurchargeAt",
      comment = "the attack-form surcharges, row-major print order; i "
      .. "clamps",
      clamp_hi = 13,
      values = {
        1, 3, 2, 4, 6, 8, 3, 3, 6, 5, 3, 7, 3, 2,
      } },
  },
}
