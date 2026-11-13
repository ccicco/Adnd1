-- misc magic item def: bucknards_everfull_purse
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part4.h (R260)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bucknards_everfull_purse",
  name = "Bucknard's Everfull Purse",
  rows = {
    { name = "Bucknard's Everfull Purse",
      set = "kMisc1", band = { 99, 100 }, xp = 1500, xp_hi = 4000,
      gp = 15000, gp_hi = 40000, qty = { 0, 0 } },
  },
  sources = {
    { part = 4, round = 260 },
  },
  pins = {
    { name = "purseCoinsPerType", value = 26,
      comment = "26 of each applicable type, next morning" },
    { name = "purseTypeRowCount", value = 3,
      comment = "the type bands" },
    { name = "purseGemsBaseGp", value = 10,
      comment = "base gems" },
    { name = "purseGemsMaxGp", value = 100,
      comment = "gems may increase to 100 at most" },
    { name = "purseAbilitiesNeverChange", value = 1,
      comment = "once rolled, the type never changes" },
    { name = "purseSpiceNote", value = 1,
      comment = "the design note: a constant fund source" },
  },
  tables = {
    { name = "purseTypeBandLo",
      comment = "the type band lower edges; i clamps",
      clamp_hi = 2,
      values = {
        1, 51, 91,
      } },
    { name = "purseTypeBandHi",
      comment = "the type band upper edges; i clamps",
      clamp_hi = 2,
      values = {
        50, 90, 100,
      } },
  },
}
