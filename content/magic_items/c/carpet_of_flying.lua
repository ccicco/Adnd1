-- misc magic item def: carpet_of_flying
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "carpet_of_flying",
  name = "Carpet of Flying",
  rows = {
    { name = "Carpet of Flying",
      set = "kMisc2", band = { 7, 8 }, xp = 7500, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "carpetRowCount", value = 4,
      comment = "the random carpet table rows" },
  },
  tables = {
    { name = "carpetBandLo",
      comment = "the carpet band lower edges; i clamps",
      clamp_hi = 3,
      values = {
        1, 21, 56, 81,
      } },
    { name = "carpetBandHi",
      comment = "the carpet band upper edges; i clamps",
      clamp_hi = 3,
      values = {
        20, 55, 80, 100,
      } },
    { name = "carpetWidthFeet",
      comment = "the carpet width; i clamps",
      clamp_hi = 3,
      values = {
        3, 4, 5, 6,
      } },
    { name = "carpetLengthFeet",
      comment = "the carpet length; i clamps",
      clamp_hi = 3,
      values = {
        5, 6, 7, 9,
      } },
    { name = "carpetPersons",
      comment = "the carpet capacity; i clamps",
      clamp_hi = 3,
      values = {
        1, 2, 3, 4,
      } },
    { name = "carpetSpeedInches",
      comment = "the carpet speed; i clamps",
      clamp_hi = 3,
      values = {
        42, 36, 30, 24,
      } },
  },
}
