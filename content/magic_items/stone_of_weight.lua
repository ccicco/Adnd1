-- misc magic item def: stone_of_weight
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "stone_of_weight",
  name = "Stone of Weight (Loadstone)",
  rows = {
    { name = "Stone of Weight (Loadstone)",
      set = "kMisc5", band = { 53, 54 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "loadMoveReductionPct", value = 50,
      comment = "a 50 percent reduction in movement when haste is due" },
    { name = "loadAttackReductionPct", value = 50,
      comment = "attacks also reduced to 50 percent normal rate" },
    { name = "loadDispelClears", value = 1,
      comment = "a dispel evil makes the item disappear" },
  },
  tables = {
  },
}
