-- misc magic item def: trident_of_yearning
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "trident_of_yearning",
  name = "Trident of Yearning",
  rows = {
    { name = "Trident of Yearning",
      set = "kMisc5", band = { 84, 85 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "yearningMagicPenalty", value = 2,
      comment = "a -2 cursed magical weapon" },
    { name = "yearningFreeingSpells", value = 3,
      comment = "freed by water breathing, wish or alter reality" },
    { name = "yearningGrantsWaterBreathing", value = 0,
      comment = "it does not confer the ability to breathe underwater" },
  },
  tables = {
  },
}
