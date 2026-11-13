-- misc magic item def: manual_of_golems
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part17.h (R273)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "manual_of_golems",
  name = "Manual of Golems",
  rows = {
    { name = "Manual of Golems",
      set = "kMisc4", band = { 7, 7 }, xp = 3000, xp_hi = 0,
      gp = 30000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 17, round = 273 },
  },
  pins = {
    { name = "golemKindCount", value = 4,
      comment = "4 sorts of golems" },
    { name = "golemMinUserLevel", value = 10,
      comment = "the maker assumed 10th or higher" },
    { name = "golemFailurePctPerLevel", value = 10,
      comment = "cumulative 10 percent per level under 10th" },
    { name = "golemFailureWindowTurns", value = 1,
      comment = "falls to pieces within 1 turn of completion" },
    { name = "golemClericXpLossMin", value = 10000,
      comment = "a cleric reading loses 10,000 xp" },
    { name = "golemClericXpLossMax", value = 60000,
      comment = "up to 60,000 xp lost" },
    { name = "golemMuLevelLoss", value = 1,
      comment = "a magic-user reading loses 1 level" },
    { name = "golemOtherDamageMin", value = 6,
      comment = "any other class suffers 6-36 damage" },
    { name = "golemOtherDamageMax", value = 36,
      comment = "the upper edge of the 6-36 damage" },
  },
  tables = {
    { name = "golemDieLo",
      comment = "the printed die band lower edges; i clamps",
      clamp_hi = 3,
      values = {
        1, 6, 18, 19,
      } },
    { name = "golemDieHi",
      comment = "the printed die band upper edges; i clamps",
      clamp_hi = 3,
      values = {
        5, 17, 18, 20,
      } },
    { name = "golemMonths",
      comment = "the construction months per golem sort; i clamps",
      clamp_hi = 3,
      values = {
        1, 2, 4, 3,
      } },
    { name = "golemCostGp",
      comment = "the construction cost per golem sort; i clamps",
      clamp_hi = 3,
      values = {
        65000, 50000, 100000, 80000,
      } },
  },
}
