-- misc magic item def: periapt_of_proof_against_poison
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part19.h (R275)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "periapt_of_proof_against_poison",
  name = "Periapt of Proof Against Poison",
  rows = {
    { name = "Periapt of Proof Against Poison",
      set = "kMisc4", band = { 54, 60 }, xp = 1500, xp_hi = 0,
      gp = 12500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 19, round = 275 },
  },
  pins = {
    { name = "poisonSavePctPerPlus", value = 10,
      comment = "a 10 percent saving throw per plus" },
  },
  tables = {
    { name = "poisonRowLo",
      comment = "the printed die band lower edges; i clamps",
      clamp_hi = 3,
      values = {
        1, 9, 15, 19,
      } },
    { name = "poisonRowHi",
      comment = "the printed die band upper edges; i clamps",
      clamp_hi = 3,
      values = {
        8, 14, 18, 20,
      } },
    { name = "poisonPlus",
      comment = "the plus of periapt per die band; i clamps",
      clamp_hi = 3,
      values = {
        1, 2, 3, 4,
      } },
  },
}
