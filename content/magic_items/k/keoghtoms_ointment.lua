-- misc magic item def: keoghtoms_ointment
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part16.h (R272)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "keoghtoms_ointment",
  name = "Keoghtom's Ointment",
  rows = {
    { name = "Keoghtom's Ointment",
      set = "kMisc3", band = { 93, 100 }, xp = 500, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 16, round = 272 },
  },
  pins = {
    { name = "ointmentJarDiameterInches", value = 3,
      comment = "the jar is three inches in diameter" },
    { name = "ointmentJarDepthInches", value = 1,
      comment = "the jar is one inch deep" },
    { name = "ointmentApplications", value = 5,
      comment = "the jar contains 5 applications" },
    { name = "ointmentHealMin", value = 9,
      comment = "rubbed on it heals 9-12 points" },
    { name = "ointmentHealMax", value = 12,
      comment = "the upper edge of the 9-12 healing" },
    { name = "ointmentFoundMin", value = 1,
      comment = "1-3 jars will commonly be found" },
    { name = "ointmentFoundMax", value = 3,
      comment = "the upper edge of the 1-3 jars" },
  },
  tables = {
  },
}
