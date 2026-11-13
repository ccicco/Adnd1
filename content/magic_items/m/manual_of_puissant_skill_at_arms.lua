-- misc magic item def: manual_of_puissant_skill_at_arms
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part17.h (R273)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "manual_of_puissant_skill_at_arms",
  name = "Manual of Puissant Skill at Arms",
  rows = {
    { name = "Manual of Puissant Skill at Arms",
      set = "kMisc4", band = { 8, 8 }, xp = 8000, xp_hi = 0,
      gp = 40000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 17, round = 273 },
  },
  pins = {
    { name = "puissantPracticeMonths", value = 1,
      comment = "the fighter practices 1 month" },
    { name = "puissantForgetMonths", value = 3,
      comment = "the knowledge fades within 3 months" },
    { name = "puissantStunTurnsMin", value = 1,
      comment = "a scanning magic-user is stunned 1-6 turns" },
    { name = "puissantStunTurnsMax", value = 6,
      comment = "the upper edge of the 1-6 turn stun" },
    { name = "puissantXpLossMin", value = 10000,
      comment = "the scanning magic-user loses 10,000 xp" },
    { name = "puissantXpLossMax", value = 60000,
      comment = "up to 60,000 xp lost" },
  },
  tables = {
  },
}
