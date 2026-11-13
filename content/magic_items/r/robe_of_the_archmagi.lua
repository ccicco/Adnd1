-- misc magic item def: robe_of_the_archmagi
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part21.h (R277)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "robe_of_the_archmagi",
  name = "Robe of the Archmagi",
  rows = {
    { name = "Robe of the Archmagi",
      set = "kMisc5", band = { 1, 1 }, xp = 6000, xp_hi = 0,
      gp = 65000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 21, round = 277 },
  },
  pins = {
    { name = "archmagiWhitePct", value = 45,
      comment = "white: 45 percent (good alignment)" },
    { name = "archmagiGrayPct", value = 30,
      comment = "gray: 30 percent (neutral alignment)" },
    { name = "archmagiBlackPct", value = 25,
      comment = "black: 25 percent (evil alignment)" },
    { name = "archmagiAcClass", value = 5,
      comment = "power 1: serves as armor equal to AC 5" },
    { name = "archmagiMagicResistPct", value = 5,
      comment = "power 2: confers a 5 percent magic resistance" },
    { name = "archmagiSaveBonus", value = 1,
      comment = "power 3: adds +1 to saving throw scores" },
    { name = "archmagiPenaltyPct", value = 20,
      comment = "power 4: worn spells cut foe magic resistance and "
      .. "saves by 20 percent" },
    { name = "archmagiPenaltyMinus", value = 4,
      comment = "the saving throw half of the 20 percent cut" },
    { name = "archmagiCharmFamilyCount", value = 7,
      comment = "the seven spells of the power 4 list" },
    { name = "archmagiClashDmgMin", value = 18,
      comment = "white on evil: take 18-51 hit points" },
    { name = "archmagiClashDmgMax", value = 51,
      comment = "the clash damage ceiling" },
    { name = "archmagiClashDiceCount", value = 11,
      comment = "the clash dice are 11d4" },
    { name = "archmagiClashDiceBonus", value = 7,
      comment = "the clash dice bonus is +7" },
    { name = "archmagiClashXpMin", value = 18000,
      comment = "and lose 18,000-51,000 experience points" },
    { name = "archmagiClashXpMax", value = 51000,
      comment = "the clash experience loss ceiling" },
    { name = "archmagiGrayDmgMin", value = 6,
      comment = "the gray or crossed clash: 6-24 hit points" },
    { name = "archmagiGrayDmgMax", value = 24,
      comment = "the gray clash damage ceiling" },
    { name = "archmagiGrayXpMin", value = 6000,
      comment = "6,000-24,000 experience points loss" },
    { name = "archmagiGrayXpMax", value = 24000,
      comment = "the gray experience loss ceiling" },
  },
  tables = {
  },
}
