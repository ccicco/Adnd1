-- misc magic item def: stone_of_good_luck
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "stone_of_good_luck",
  name = "Stone of Good Luck (Luckstone)",
  rows = {
    { name = "Stone of Good Luck (Luckstone)",
      set = "kMisc5", band = { 51, 52 }, xp = 3000, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "luckSaveBonus", value = 1,
      comment = "+1 on adverse-happening dice rolls" },
    { name = "luckSavePctBonus", value = 5,
      comment = "+5 percent where applicable" },
    { name = "luckItemPctMin", value = 1,
      comment = "1 percent on magic item and treasure division rolls" },
    { name = "luckItemPctMax", value = 10,
      comment = "up to 10 percent at owner option" },
  },
  tables = {
  },
}
