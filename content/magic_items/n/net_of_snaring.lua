-- misc magic item def: net_of_snaring
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "net_of_snaring",
  name = "Net of Snaring",
  rows = {
    { name = "Net of Snaring",
      set = "kMisc4", band = { 39, 42 }, xp = 1000, xp_hi = 0,
      gp = 6000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "snareRangeInches", value = 3,
      comment = "shoots forth up to 3 inches underwater" },
  },
  tables = {
  },
}
