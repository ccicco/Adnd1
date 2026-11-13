-- misc magic item def: necklace_of_missiles
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part18.h (R274)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "necklace_of_missiles",
  name = "Necklace of Missiles",
  rows = {
    { name = "Necklace of Missiles",
      set = "kMisc4", band = { 24, 27 }, xp = 50, xp_hi = 0,
      gp = 200, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 18, round = 274 },
  },
  pins = {
    { name = "missileRangeInches", value = 7,
      comment = "the globes hurled up to 7 inches distance" },
  },
  tables = {
    { name = "neckRowLo",
      comment = "the printed die band lower edges; i clamps",
      clamp_hi = 6,
      values = {
        1, 5, 9, 13, 17, 19, 20,
      } },
    { name = "neckRowHi",
      comment = "the printed die band upper edges; i clamps",
      clamp_hi = 6,
      values = {
        4, 8, 12, 16, 18, 19, 20,
      } },
    { name = "neckDieOf",
      comment = "the hit dice column ladder; i clamps",
      clamp_hi = 9,
      values = {
        11, 10, 9, 8, 7, 6, 5, 4, 3, 2,
      } },
    { name = "neckCell",
      comment = "the flattened count table, the row-major index i = row "
      .. "* 10 + column, the columns running the 11-dice through "
      .. "2-dice ladder; the 9-12 row reads the printed example: "
      .. "one 7-dice, two 5-dice, four 3-dice; clamps",
      clamp_hi = 69,
      values = {
        0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 2, 0, 0,
          0, 0, 1, 0, 2, 0, 4, 0, 0, 0, 0, 1, 0, 2, 0, 2, 0, 4, 0, 0, 1, 0,
          2, 0, 2, 0, 2, 0, 0, 1, 0, 2, 0, 2, 0, 4, 0, 0, 1, 0, 2, 0, 2, 0,
          2, 0, 2, 0,
      } },
  },
}
