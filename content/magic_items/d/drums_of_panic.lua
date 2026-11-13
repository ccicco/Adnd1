-- misc magic item def: drums_of_panic
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "drums_of_panic",
  name = "Drums of Panic",
  rows = {
    { name = "Drums of Panic",
      set = "kMisc2", band = { 78, 79 }, xp = 6500, xp_hi = 0,
      gp = 35000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "drumPanicRangeInches", value = 12,
      comment = "both drums: the panic radius" },
    { name = "drumPanicSafeZoneInches", value = 2,
      comment = "the safe zone radius from the drums" },
    { name = "drumPanicFleeTurns", value = 1,
      comment = "move directly away for 1 full turn" },
    { name = "drumPanicRestRoundsPerTurn", value = 3,
      comment = "3 rounds of rest per 1 turn of flight" },
    { name = "drumPanicInt2SaveMod", value = -2,
      comment = "intelligence of 2 saves at -2" },
    { name = "drumPanicInt1SaveMod", value = -4,
      comment = "intelligence of 1 or less saves at -4" },
    { name = "drumPanicHemisphereHalfFeet", value = 3,
      comment = "each drum: 1.5 feet diameter hemisphere" },
  },
  tables = {
  },
}
