-- misc magic item def: girdle_of_femininity_masculinity
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "girdle_of_femininity_masculinity",
  name = "Girdle of Femininity/Masculinity",
  rows = {
    { name = "Girdle of Femininity/Masculinity",
      set = "kMisc3", band = { 28, 28 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "girdleSexWishRestorePct", value = 50,
      comment = "a wish restores the sex: 50 percent" },
    { name = "girdleSexSexlessPct", value = 10,
      comment = "10 percent of these remove all sex" },
  },
  tables = {
  },
}
