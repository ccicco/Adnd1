-- misc magic item def: cloak_of_poisonousness
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "cloak_of_poisonousness",
  name = "Cloak of Poisonousness",
  rows = {
    { name = "Cloak of Poisonousness",
      set = "kMisc2", band = { 31, 32 }, xp = 0, xp_hi = 0,
      gp = 2500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "poisonCloakRevivalPctPenalty", value = 10,
      comment = "raise dead chance penalty" },
    { name = "poisonCloakRemoveCurseDestroys", value = 1,
      comment = "remove curse removes and destroys the magic" },
    { name = "poisonCloakNeutralizeNoEffect", value = 1,
      comment = "neutralize poison does not affect it" },
  },
  tables = {
  },
}
