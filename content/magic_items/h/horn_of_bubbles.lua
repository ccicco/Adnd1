-- misc magic item def: horn_of_bubbles
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "horn_of_bubbles",
  name = "Horn of Bubbles",
  rows = {
    { name = "Horn of Bubbles",
      set = "kMisc3", band = { 47, 48 }, xp = 0, xp_hi = 0,
      gp = 0, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "hornBubblesBlindRoundsMin", value = 2,
      comment = "the bubbles surround and blind the individual who "
      .. "blew the horn" },
    { name = "hornBubblesBlindRoundsMax", value = 20,
      comment = "blinded for 2-20 rounds" },
    { name = "hornBubblesOnlyWhenSlayerSeeks", value = 1,
      comment = "the bubbles only appear in the presence of a creature "
      .. "actively seeking to slay the character who winded the "
      .. "horn" },
    { name = "hornBubblesAppearanceMayDelay", value = 1,
      comment = "the appearance might be delayed for a very short or "
      .. "extremely lengthy period" },
  },
  tables = {
  },
}
