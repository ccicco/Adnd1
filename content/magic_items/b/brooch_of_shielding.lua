-- misc magic item def: brooch_of_shielding
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "brooch_of_shielding",
  name = "Brooch of Shielding",
  rows = {
    { name = "Brooch of Shielding",
      set = "kMisc1", band = { 86, 92 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "broochPctWithoutGems", value = 90,
      comment = "usually without gems inset" },
    { name = "broochAbsorbHp", value = 101,
      comment = "absorbs magic missile damage, then melts" },
  },
  tables = {
  },
}
