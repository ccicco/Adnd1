-- misc magic item def: drums_of_deafening
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "drums_of_deafening",
  name = "Drums of Deafening",
  rows = {
    { name = "Drums of Deafening",
      set = "kMisc2", band = { 77, 77 }, xp = 0, xp_hi = 0,
      gp = 500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "drumDeafDeafRangeInches", value = 7,
      comment = "both drums: permanent deafness radius" },
    { name = "drumDeafStunRangeInches", value = 1,
      comment = "the stun zone radius" },
    { name = "drumDeafStunMinRounds", value = 2,
      comment = "stunned for from 2-8 rounds" },
    { name = "drumDeafStunMaxRounds", value = 8,
      comment = "stunned for from 2-8 rounds" },
    { name = "drumDeafHemisphereHalfFeet", value = 3,
      comment = "each drum: 1.5 feet diameter hemisphere" },
  },
  tables = {
  },
}
