-- misc magic item def: scarab_of_protection
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "scarab_of_protection",
  name = "Scarab of Protection",
  rows = {
    { name = "Scarab of Protection",
      set = "kMisc5", band = { 41, 46 }, xp = 2500, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "protectSaveBonus", value = 1,
      comment = "+1 on all saving throws versus magic" },
    { name = "protectNoSaveBase", value = 20,
      comment = "a save of 20 when none is possible" },
    { name = "protectAbsorbCount", value = 12,
      comment = "absorbs up to 12 level drains or death" },
    { name = "protectReversedOneIn", value = 20,
      comment = "1 in 20 are reversed cursed items" },
    { name = "protectReversedPenalty", value = 2,
      comment = "giving the possessor a -2 on the dice" },
    { name = "protectFixedOneIn", value = 5,
      comment = "1 in 5 of the cursed items are fixed" },
    { name = "protectFixedBonus", value = 2,
      comment = "actually +2 once the curse is removed" },
    { name = "protectRemoveClericLevel", value = 16,
      comment = "removed by a cleric of 16 or higher level" },
    { name = "protectRemovedAbsorbCount", value = 24,
      comment = "the fixed scarab absorbs 24 rather than 12" },
  },
  tables = {
  },
}
