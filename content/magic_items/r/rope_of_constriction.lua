-- misc magic item def: rope_of_constriction
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "rope_of_constriction",
  name = "Rope of Constriction",
  rows = {
    { name = "Rope of Constriction",
      set = "kMisc5", band = { 26, 27 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "constrictExtraVictimsMin", value = 1,
      comment = "lashes at 1-4 others near the holder" },
    { name = "constrictExtraVictimsMax", value = 4,
      comment = "the extra victim ceiling" },
    { name = "constrictVictimRangeFeet", value = 10,
      comment = "the others within 10 feet of the victim" },
    { name = "constrictDmgMin", value = 2,
      comment = "each round delivers 2-12 hit points" },
    { name = "constrictDmgMax", value = 12,
      comment = "the constriction damage ceiling" },
    { name = "constrictAcClass", value = -2,
      comment = "the rope itself is AC -2" },
    { name = "constrictCutHitPoints", value = 22,
      comment = "takes 22 hit points to cut through" },
  },
  tables = {
  },
}
