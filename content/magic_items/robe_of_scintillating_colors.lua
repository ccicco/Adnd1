-- misc magic item def: robe_of_scintillating_colors
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part21.h (R277)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "robe_of_scintillating_colors",
  name = "Robe of Scintillating Colors",
  rows = {
    { name = "Robe of Scintillating Colors",
      set = "kMisc5", band = { 11, 11 }, xp = 2750, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 21, round = 277 },
  },
  pins = {
    { name = "scintIntMin", value = 15,
      comment = "needs intelligence of 15 or higher" },
    { name = "scintWisMin", value = 13,
      comment = "and a wisdom of 13 or more" },
    { name = "scintLightFeet", value = 40,
      comment = "sheds light in a 40 foot diameter sphere" },
    { name = "scintStartRounds", value = 1,
      comment = "a full round to cause the colors to flow" },
    { name = "scintTransfixMin", value = 2,
      comment = "stand transfixed for 2-5 rounds" },
    { name = "scintTransfixMax", value = 5,
      comment = "the transfix ceiling" },
    { name = "scintHitPctPerRound", value = 5,
      comment = "5 percent harder to hit per round of play" },
    { name = "scintHitPctMax", value = 25,
      comment = "to a maximum of 25 percent (minus 5)" },
    { name = "scintHitMaxRounds", value = 5,
      comment = "attained after 5 continuous rounds" },
    { name = "scintCastRangeInches", value = 1,
      comment = "activity within 1 inch of the start point" },
    { name = "scintHypnotizeMin", value = 2,
      comment = "non-combat hypnosis for 2-5 turns" },
    { name = "scintHypnotizeMax", value = 5,
      comment = "the non-combat hypnosis ceiling" },
  },
  tables = {
  },
}
