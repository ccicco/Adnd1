-- misc magic item def: broom_of_animated_attack
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "broom_of_animated_attack",
  name = "Broom of Animated Attack",
  rows = {
    { name = "Broom of Animated Attack",
      set = "kMisc1", band = { 93, 93 }, xp = 0, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "broomAttackDumpMinFeet", value = 6,
      comment = "dumps the rider from 6 feet" },
    { name = "broomAttackDumpMaxFeet", value = 9,
      comment = "dumps the rider up to 9 feet" },
    { name = "broomAttackAttacksPerRound", value = 2,
      comment = "each attack twice per round" },
    { name = "broomAttackAsHd", value = 4,
      comment = "attacks as a 4 hit die monster" },
    { name = "broomAttackStrawBlindRounds", value = 1,
      comment = "the straw end blinds for 1 round" },
    { name = "broomAttackHandleDmgMin", value = 1,
      comment = "the handle end: 1-3 hp" },
    { name = "broomAttackHandleDmgMax", value = 3,
      comment = "the handle end: 1-3 hp" },
    { name = "broomAttackAc", value = 7,
      comment = "the broom armor class" },
    { name = "broomAttackHpToDestroy", value = 18,
      comment = "hit points to destroy" },
  },
  tables = {
  },
}
