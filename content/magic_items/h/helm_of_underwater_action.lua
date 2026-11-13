-- misc magic item def: helm_of_underwater_action
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "helm_of_underwater_action",
  name = "Helm of Underwater Action",
  rows = {
    { name = "Helm of Underwater Action",
      set = "kMisc3", band = { 41, 45 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "helmUnderwaterSeeAndBreathe", value = 1,
      comment = "the possessor is able to both see and breathe under "
      .. "water" },
    { name = "helmUnderwaterLensCompartments", value = 2,
      comment = "small lenses drawn across the device from "
      .. "compartments on either side" },
    { name = "helmUnderwaterVisionFactor", value = 5,
      comment = "see 5 times farther than normal water and light "
      .. "conditions allow for normal human vision" },
    { name = "helmUnderwaterObstructionsBlock", value = 1,
      comment = "weeds, obstructions and such block vision in the "
      .. "usual manner" },
    { name = "helmUnderwaterAirGlobeUntilRepeat", value = 1,
      comment = "the command word creates a globe of air around the "
      .. "head, maintained until the word is again spoken" },
  },
  tables = {
  },
}
