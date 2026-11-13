-- misc magic item def: dust_of_appearance
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part9.h (R265)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "dust_of_appearance",
  name = "Dust of Appearance",
  rows = {
    { name = "Dust of Appearance",
      set = "kMisc2", band = { 80, 85 }, xp = 1000, xp_hi = 0,
      gp = 4000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 9, round = 265 },
  },
  pins = {
    { name = "dustAppearDurationMinTurns", value = 2,
      comment = "appearance lasts for 2-20 turns" },
    { name = "dustAppearDurationMaxTurns", value = 20,
      comment = "appearance lasts for 2-20 turns" },
    { name = "dustAppearPacketRadiusFeet", value = 10,
      comment = "a packet covers a 10 feet radius" },
    { name = "dustAppearTubeStartFeet", value = 1,
      comment = "the cone: 1 feet wide at the start" },
    { name = "dustAppearTubeEndFeet", value = 15,
      comment = "the cone: 15 feet wide at the end" },
    { name = "dustAppearTubeLengthFeet", value = 20,
      comment = "the cone: 20 feet long" },
    { name = "dustAppearContainerMin", value = 5,
      comment = "from 5 to 50 containers in one place" },
    { name = "dustAppearContainerMax", value = 50,
      comment = "from 5 to 50 containers in one place" },
  },
  tables = {
  },
}
