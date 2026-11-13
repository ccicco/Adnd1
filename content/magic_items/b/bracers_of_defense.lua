-- misc magic item def: bracers_of_defense
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bracers_of_defense",
  name = "Bracers of Defense",
  rows = {
    { name = "Bracers of Defense",
      set = "kMisc1", band = { 60, 79 }, xp = 500, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "bracersDefRowCount", value = 7,
      comment = "the random AC table rows" },
    { name = "bracersDefAcMin", value = 2,
      comment = "the 86-00 row" },
    { name = "bracersDefAcMax", value = 8,
      comment = "the 01-05 row" },
  },
  tables = {
    { name = "bracersDefBandLo",
      comment = "printed band lower edges; i clamps",
      clamp_hi = 6,
      values = {
        1, 6, 16, 36, 51, 71, 86,
      } },
    { name = "bracersDefBandHi",
      comment = "printed band upper edges; i clamps",
      clamp_hi = 6,
      values = {
        5, 15, 35, 50, 70, 85, 100,
      } },
    { name = "bracersDefAc",
      comment = "the armor class per band; i clamps",
      clamp_hi = 6,
      values = {
        8, 7, 6, 5, 4, 3, 2,
      } },
  },
}
