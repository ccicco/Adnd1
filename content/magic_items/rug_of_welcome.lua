-- misc magic item def: rug_of_welcome
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "rug_of_welcome",
  name = "Rug of Welcome",
  rows = {
    { name = "Rug of Welcome",
      set = "kMisc5", band = { 33, 33 }, xp = 6500, xp_hi = 0,
      gp = 45000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "welcomeFlyWidthFeet", value = 6,
      comment = "functions as a carpet of flying (6 x 9" },
    { name = "welcomeFlyLengthFeet", value = 9,
      comment = "size)" },
    { name = "welcomeBridgeFeet", value = 27,
      comment = "stiffens as steel up to 27 feet long" },
    { name = "welcomeBridgeWidthFeet", value = 2,
      comment = "at a 2 foot width" },
    { name = "welcomeAcClass", value = 0,
      comment = "the bridge form is AC 0" },
    { name = "welcomeDestroyHitPoints", value = 100,
      comment = "takes 100 hit points to destroy" },
    { name = "welcomeShrinkDivisor", value = 12,
      comment = "shrinks to 1/12 size on command" },
  },
  tables = {
  },
}
