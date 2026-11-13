-- misc magic item def: candle_of_invocation
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part5.h (R261)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "candle_of_invocation",
  name = "Candle of Invocation",
  rows = {
    { name = "Candle of Invocation",
      set = "kMisc2", band = { 1, 6 }, xp = 1000, xp_hi = 0,
      gp = 5000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 5, round = 261 },
  },
  pins = {
    { name = "candleAlignments", value = 9,
      comment = "one candle per alignment" },
    { name = "candleClericLevelBoost", value = 2,
      comment = "same-alignment cleric level, while aflame" },
    { name = "candleBurnHours", value = 4,
      comment = "each candle burns for 4 hours" },
    { name = "candleGateSpell", value = 1,
      comment = "any burning allows a gate; taper consumed" },
  },
  tables = {
  },
}
