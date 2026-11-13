-- misc magic item def: bracers_of_defenselessness
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bracers_of_defenselessness",
  name = "Bracers of Defenselessness",
  rows = {
    { name = "Bracers of Defenselessness",
      set = "kMisc1", band = { 80, 81 }, xp = 0, xp_hi = 0,
      gp = 2000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "defenselessAc", value = 10,
      comment = "lowers armor class to 10" },
    { name = "defenselessNegatesProtections", value = 1,
      comment = "all protections and dex bonuses" },
    { name = "defenselessRemoveCurseOnly", value = 1,
      comment = "only remove curse takes them off" },
  },
  tables = {
  },
}
