-- misc magic item def: manual_of_bodily_health
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part17.h (R273)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "manual_of_bodily_health",
  name = "Manual of Bodily Health",
  rows = {
    { name = "Manual of Bodily Health",
      set = "kMisc4", band = { 5, 5 }, xp = 5000, xp_hi = 0,
      gp = 50000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 17, round = 273 },
  },
  pins = {
    { name = "healthReadHours", value = 24,
      comment = "the read takes 24 hours of time" },
    { name = "healthReadDaysMin", value = 3,
      comment = "over 3-5 days" },
    { name = "healthReadDaysMax", value = 5,
      comment = "the upper edge of the 3-5 days" },
    { name = "healthConGain", value = 1,
      comment = "the regimen raises constitution by 1 point" },
    { name = "healthRegimenMonths", value = 1,
      comment = "the diet and breathing run 1 month" },
    { name = "healthForgetMonths", value = 3,
      comment = "the secrets fade in 3 months" },
  },
  tables = {
  },
}
