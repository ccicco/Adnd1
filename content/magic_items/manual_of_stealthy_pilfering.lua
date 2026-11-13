-- misc magic item def: manual_of_stealthy_pilfering
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "manual_of_stealthy_pilfering",
  name = "Manual of Stealthy Pilfering",
  rows = {
    { name = "Manual of Stealthy Pilfering",
      set = "kMisc4", band = { 10, 10 }, xp = 8000, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "stealthyPracticeMonths", value = 1,
      comment = "the thief practices 1 month thereafter" },
    { name = "stealthyKnowledgeMonths", value = 3,
      comment = "the knowledge is retained for 3 months" },
    { name = "stealthyAssassinXp", value = 5000,
      comment = "an assassin gains but 5,000 additional xp" },
    { name = "stealthyAssassinWeeks", value = 1,
      comment = "the contents pondered for 1 week" },
    { name = "stealthyWrongDamageMin", value = 5,
      comment = "a wrong-class reader takes 5-20 damage" },
    { name = "stealthyWrongDamageMax", value = 20,
      comment = "the upper edge of the 5-20 damage" },
    { name = "stealthyStunRoundsMin", value = 5,
      comment = "stunned a like number of rounds" },
    { name = "stealthyStunRoundsMax", value = 20,
      comment = "the upper edge of the like-number rounds" },
    { name = "stealthyXpLossMin", value = 5000,
      comment = "a failed save loses 5,000-20,000 xp" },
    { name = "stealthyXpLossMax", value = 20000,
      comment = "the upper edge of the 5,000-20,000 xp loss" },
    { name = "stealthyAtoneDays", value = 1,
      comment = "must atone within 1 day" },
    { name = "stealthyWisdomLoss", value = 1,
      comment = "or lose 1 point of wisdom" },
  },
  tables = {
  },
}
