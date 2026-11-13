-- misc magic item def: pipes_of_the_sewers
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part20.h (R276)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "pipes_of_the_sewers",
  name = "Pipes of the Sewers",
  rows = {
    { name = "Pipes of the Sewers",
      set = "kMisc4", band = { 77, 84 }, xp = 1750, xp_hi = 0,
      gp = 8500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 20, round = 276 },
  },
  pins = {
    { name = "pipeGiantRatMin", value = 10,
      comment = "attracts from 10-60 giant rats" },
    { name = "pipeGiantRatMax", value = 60,
      comment = "the giant rat ceiling" },
    { name = "pipeGiantRatPct", value = 80,
      comment = "giant rats at 80 percent" },
    { name = "pipeNormalRatMin", value = 30,
      comment = "or from 30-180 normal rats" },
    { name = "pipeNormalRatMax", value = 180,
      comment = "the normal rat ceiling" },
    { name = "pipeNormalRatPct", value = 20,
      comment = "normal rats at 20 percent" },
    { name = "pipeCallRangeInches", value = 40,
      comment = "if either or both are within 40 inches" },
    { name = "pipeDelayPerInches", value = 5,
      comment = "a 1 round delay per each 5 inches traveled" },
    { name = "pipeObeyPct", value = 95,
      comment = "95 percent likely to obey while the piper plays" },
    { name = "pipeReplayObeyPct", value = 70,
      comment = "called again: 70 percent come and obey" },
    { name = "pipeReplayTurnPct", value = 30,
      comment = "but 30 percent turn upon the piper" },
    { name = "pipeTakeoverPctPerRound", value = 30,
      comment = "30 percent per round to take over control from a "
      .. "controlling creature" },
    { name = "pipeKeepPct", value = 70,
      comment = "70 percent chance of maintaining control" },
  },
  tables = {
  },
}
