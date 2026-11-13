-- misc magic item def: net_of_entrapment
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "net_of_entrapment",
  name = "Net of Entrapment",
  rows = {
    { name = "Net of Entrapment",
      set = "kMisc4", band = { 36, 38 }, xp = 1000, xp_hi = 0,
      gp = 7500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "entrapMinStrength", value = 20,
      comment = "defies strength under 20" },
    { name = "entrapCutAc", value = -10,
      comment = "equal to AC -10 against cutting blows" },
    { name = "entrapSizeFeet", value = 10,
      comment = "each net is 10 feet square" },
    { name = "entrapMeshQuarterFeet", value = 1,
      comment = "with a quarter-foot mesh" },
    { name = "entrapThrowFeet", value = 20,
      comment = "it can be thrown 20 feet" },
    { name = "entrapCloseCubeFeet", value = 5,
      comment = "stretches to close over a 5 foot cube" },
  },
  tables = {
  },
}
