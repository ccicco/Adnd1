-- misc magic item def: rope_of_entanglement
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part22.h (R278)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "rope_of_entanglement",
  name = "Rope of Entanglement",
  rows = {
    { name = "Rope of Entanglement",
      set = "kMisc5", band = { 28, 31 }, xp = 1250, xp_hi = 0,
      gp = 12000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 22, round = 278 },
  },
  pins = {
    { name = "entangleLashFeet", value = 20,
      comment = "lashes forward 20 feet upon command" },
    { name = "entangleUpwardFeet", value = 10,
      comment = "or upwards 10 feet" },
    { name = "entangleManSizedMax", value = 8,
      comment = "ties fast up to 8 man-sized creatures" },
    { name = "entangleStrikeSegments", value = 1,
      comment = "a single segment to strike" },
    { name = "entangleEntwineSegments", value = 1,
      comment = "another segment to entwine" },
    { name = "entangleCommandSegments", value = 1,
      comment = "the command requires 1 segment" },
    { name = "entangleWholeSegments", value = 3,
      comment = "the whole takes 3 segments to perform" },
    { name = "entangleAcClass", value = -2,
      comment = "the rope is AC -2" },
    { name = "entangleCutHitPoints", value = 22,
      comment = "takes 22 hit points to cut through" },
    { name = "entangleRepairTurns", value = 6,
      comment = "damage under 22 repairs itself in 6 turns" },
  },
  tables = {
    { name = "entangleManUnits",
      comment = "the man-sized equivalence chain; i clamps 1 storm giant "
      .. "or fire giant = 2 frost or stone or hill giants = 3 "
      .. "ogres = 4 bugbears = 6 gnolls = 8 men = 10 elves = 12 "
      .. "dwarves = 16 gnomes or kobolds",
      clamp_hi = 8,
      values = {
        1, 2, 3, 4, 6, 8, 10, 12, 16,
      } },
  },
}
