-- misc magic item def: arrow_of_direction
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "arrow_of_direction",
  name = "Arrow of Direction",
  rows = {
    { name = "Arrow of Direction",
      set = "kMisc1", band = { 14, 16 }, xp = 2500, xp_hi = 0,
      gp = 17500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "arrowDirectionUsesPerDay", value = 1,
      comment = "tossed into the air once per day" },
    { name = "arrowDirectionRepetitions", value = 7,
      comment = "the process can be repeated 7 times" },
    { name = "arrowDirectionTurns", value = 7,
      comment = "during the next 7 turns" },
    { name = "arrowDirectionRequestKinds", value = 5,
      comment = "stairway, sloping passage, dungeon exit or entrance, "
      .. "cave, cavern" },
  },
  tables = {
  },
}
