-- misc magic item def: chime_of_opening
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "chime_of_opening",
  name = "Chime of Opening",
  rows = {
    { name = "Chime of Opening",
      set = "kMisc2", band = { 12, 13 }, xp = 3500, xp_hi = 0,
      gp = 20000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "chimeOpenLengthInches", value = 12,
      comment = "the hollow mithral tube" },
    { name = "chimeOpenWizardLockLevel", value = 15,
      comment = "defeats locks cast below 15th level" },
    { name = "chimeOpenRoundPerFunction", value = 1,
      comment = "one function completes per round" },
    { name = "chimeOpenSoundingsMin", value = 4,
      comment = "the fully chained and locked chest" },
    { name = "chimeOpenSoundingsMax", value = 5,
      comment = "the fully chained and locked chest" },
    { name = "chimeOpenChargesMin", value = 20,
      comment = "20-80 charges, 20 + d6 x 10" },
    { name = "chimeOpenChargesMax", value = 80,
      comment = "20-80 charges, 20 + d6 x 10" },
    { name = "chimeOpenChargesDieSides", value = 6,
      comment = "20 + d6 x 10" },
    { name = "chimeOpenChargesDieMult", value = 10,
      comment = "20 + d6 x 10" },
  },
  tables = {
  },
}
