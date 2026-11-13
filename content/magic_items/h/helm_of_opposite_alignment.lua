-- misc magic item def: helm_of_opposite_alignment
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "helm_of_opposite_alignment",
  name = "Helm of Opposite Alignment",
  rows = {
    { name = "Helm of Opposite Alignment",
      set = "kMisc3", band = { 36, 37 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "helmOppAlignIndeterminateDweomer", value = 1,
      comment = "by test it radiates an indeterminate dweomer" },
    { name = "helmOppAlignCurseOnDonning", value = 1,
      comment = "once placed upon the head the curse immediately takes "
      .. "place" },
    { name = "helmOppAlignAbsoluteKinds", value = 4,
      comment = "neutral goes to some absolute commitment: LE, LG, CE "
      .. "or CG" },
    { name = "helmOppAlignAlterationDesired", value = 1,
      comment = "the alteration, once effected, is desired by the "
      .. "individual the magic changed" },
    { name = "helmOppAlignRestoreSpellKinds", value = 2,
      comment = "only a wish, or alter reality, can restore the former "
      .. "alignment" },
    { name = "helmOppAlignSelfRestoreAttempts", value = 0,
      comment = "the affected individual will make no attempt to "
      .. "return to the former alignment" },
    { name = "helmOppAlignPaladinQuestAndAtone", value = 1,
      comment = "a paladin must undergo a special quest and atone for "
      .. "the curse to be obliterated" },
    { name = "helmOppAlignPowersAfterFunctioning", value = 0,
      comment = "once functioned the helm loses all of its magical "
      .. "properties" },
  },
  tables = {
  },
}
