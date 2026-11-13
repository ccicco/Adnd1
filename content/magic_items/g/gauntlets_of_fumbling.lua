-- misc magic item def: gauntlets_of_fumbling
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part11.h (R267)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "gauntlets_of_fumbling",
  name = "Gauntlets of Fumbling",
  rows = {
    { name = "Gauntlets of Fumbling",
      set = "kMisc3", band = { 19, 20 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 11, round = 267 },
  },
  pins = {
    { name = "gauntFumbDropPct", value = 50,
      comment = "50 percent each round of dropping held items" },
    { name = "gauntFumbDexPenalty", value = 2,
      comment = "lowers overall dexterity by 2 points" },
    { name = "gauntFumbRemoveCurseOnly", value = 1,
      comment = "only remove curse or a wish takes them off" },
  },
  tables = {
  },
}
