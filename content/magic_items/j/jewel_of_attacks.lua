-- misc magic item def: jewel_of_attacks
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part16.h (R272)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "jewel_of_attacks",
  name = "Jewel of Attacks",
  rows = {
    { name = "Jewel of Attacks",
      set = "kMisc3", band = { 91, 91 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 16, round = 272 },
  },
  pins = {
    { name = "jewelAttacksWanderingPct", value = 100,
      comment = "100 percent more wandering monsters" },
    { name = "jewelAttacksPursuitPct", value = 100,
      comment = "100 percent greater pursuit likelihood" },
  },
  tables = {
  },
}
