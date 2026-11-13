-- misc magic item def: crystal_hypnosis_ball
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part6.h (R262)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "crystal_hypnosis_ball",
  name = "Crystal Hypnosis Ball",
  rows = {
    { name = "Crystal Hypnosis Ball",
      set = "kMisc2", band = { 61, 61 }, xp = 0, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 6, round = 262 },
  },
  pins = {
    { name = "hypnosisBallCursed", value = 1,
      comment = "the cursed item type" },
    { name = "hypnosisBallRadiatesEvil", value = 0,
      comment = "radiates magic, but NOT evil" },
    { name = "hypnosisBallSuggestionImplanted", value = 1,
      comment = "hypnotized, telepathic suggestion implanted" },
    { name = "hypnosisBallIndistinguishable", value = 1,
      comment = "indistinguishable from a normal ball" },
    { name = "hypnosisBallInfluencerKindCount", value = 3,
      comment = "magic-user, lich, other-planar power" },
    { name = "hypnosisBallFateCount", value = 3,
      comment = "servant, tool, or possession object" },
    { name = "hypnosisBallRefereePace", value = 1,
      comment = "gradual or sudden, referee decides" },
  },
  tables = {
  },
}
