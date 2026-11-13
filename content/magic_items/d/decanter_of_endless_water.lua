-- misc magic item def: decanter_of_endless_water
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part7.h (R263)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "decanter_of_endless_water",
  name = "Decanter of Endless Water",
  rows = {
    { name = "Decanter of Endless Water",
      set = "kMisc2", band = { 70, 72 }, xp = 1000, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 7, round = 263 },
  },
  pins = {
    { name = "decanterModeCount", value = 3,
      comment = "stream, fountain, geyser" },
    { name = "decanterStreamGallonsPerRound", value = 1,
      comment = "stream pours per round" },
    { name = "decanterFountainLengthFeet", value = 5,
      comment = "the fountain stream length" },
    { name = "decanterFountainGallonsPerRound", value = 5,
      comment = "fountain pours per round" },
    { name = "decanterGeyserLengthFeet", value = 20,
      comment = "the geyser stream length" },
    { name = "decanterGeyserGallonsPerRound", value = 30,
      comment = "geyser pours per round" },
    { name = "decanterWaterTypeCount", value = 2,
      comment = "fresh or salt, as ordered" },
    { name = "decanterGeyserKnockover", value = 1,
      comment = "geyser back pressure knocks over" },
    { name = "decanterStopsOnCommand", value = 1,
      comment = "the command word ceases the flow" },
  },
  tables = {
  },
}
