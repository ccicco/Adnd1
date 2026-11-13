-- misc magic item def: trident_of_warning
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part23.h (R279)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "trident_of_warning",
  name = "Trident of Warning",
  rows = {
    { name = "Trident of Warning",
      set = "kMisc5", band = { 79, 83 }, xp = 1000, xp_hi = 0,
      gp = 10000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 23, round = 279 },
  },
  pins = {
    { name = "warningRadiusInches", value = 24,
      comment = "it scans hostile hungry predators within 24 inches" },
    { name = "warningScanRounds", value = 1,
      comment = "one round scans the 24 inch hemisphere" },
    { name = "warningChargesMin", value = 19,
      comment = "it carries 19-24 charges" },
    { name = "warningChargesMax", value = 24,
      comment = "the charge ceiling" },
    { name = "warningChargeRounds", value = 2,
      comment = "each charge lasts for 2 rounds of scanning" },
    { name = "warningMagicBonus", value = 2,
      comment = "otherwise a +2 magic weapon" },
  },
  tables = {
  },
}
