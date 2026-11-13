-- misc magic item def: book_of_exalted_deeds
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part2.h (R258)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "book_of_exalted_deeds",
  name = "Book of Exalted Deeds",
  rows = {
    { name = "Book of Exalted Deeds",
      set = "kMisc1", band = { 33, 33 }, xp = 8000, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 2, round = 258 },
  },
  pins = {
    { name = "exaltedReadingWeeks", value = 1,
      comment = "reading requires 1 week" },
    { name = "exaltedWisdomGain", value = 1,
      comment = "the good cleric gains 1 wisdom" },
    { name = "exaltedHalfwayPct", value = 50,
      comment = "XP to exactly half way into next level" },
    { name = "exaltedNeutralXpLossMin", value = 20000,
      comment = "neutral clerics lose 20,000-80,000 XP" },
    { name = "exaltedNeutralXpLossMax", value = 80000,
      comment = "the top of the neutral loss" },
    { name = "exaltedLevelFloor", value = 1,
      comment = "negative XP possible, never below 1st" },
    { name = "exaltedEvilLevelLoss", value = 1,
      comment = "evil clerics lose 1 full level" },
    { name = "exaltedAtonementPct", value = 50,
      comment = "or offer up 50% of everything gained" },
    { name = "exaltedAtonementAdventuresMin", value = 2,
      comment = "for 2-5 adventures" },
    { name = "exaltedAtonementAdventuresMax", value = 5,
      comment = "the top of the 2-5 adventures" },
    { name = "exaltedMuIntLoss", value = 1,
      comment = "magic-users lose 1 intelligence, unless they save "
      .. "versus magic" },
    { name = "exaltedMuSaveXpLossMin", value = 2000,
      comment = "on a save they lose 2,000-20,000 XP" },
    { name = "exaltedMuSaveXpLossMax", value = 20000,
      comment = "the top of the save loss" },
    { name = "exaltedThiefHpMin", value = 5,
      comment = "the thief takes 5-30 hit points" },
    { name = "exaltedThiefHpMax", value = 30,
      comment = "the top of the thief damage" },
    { name = "exaltedThiefDexLoss", value = 1,
      comment = "save or lose 1 dexterity" },
    { name = "exaltedThiefConvertPctMin", value = 10,
      comment = "10%-60% chance to become a good cleric" },
    { name = "exaltedThiefConvertPctMax", value = 60,
      comment = "the top of the conversion range" },
    { name = "exaltedThiefConvertWisReq", value = 15,
      comment = "if wisdom is 15 or higher" },
    { name = "exaltedAssassinHpMin", value = 5,
      comment = "the assassin takes 5-40 hit points" },
    { name = "exaltedAssassinHpMax", value = 40,
      comment = "the top of the assassin damage" },
    { name = "exaltedVanishesAfterPerusal", value = 1,
      comment = "once perused the book vanishes" },
    { name = "exaltedMaxBenefitTimes", value = 1,
      comment = "never a second benefit, same character" },
  },
  tables = {
  },
}
