-- misc magic item def: horn_of_the_tritons
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part13.h (R269)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "horn_of_the_tritons",
  name = "Horn of the Tritons",
  rows = {
    { name = "Horn of the Tritons",
      set = "kMisc3", band = { 50, 53 }, xp = 2000, xp_hi = 0,
      gp = 17500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 13, round = 269 },
  },
  pins = {
    { name = "hornTritonPerDay", value = 1,
      comment = "a conch shell horn blown but once per day" },
    { name = "hornTritonTritonPerDay", value = 3,
      comment = "except by a triton who can sound it 3 times" },
    { name = "hornTritonFunctionCount", value = 3,
      comment = "any 1 of the following functions" },
    { name = "hornTritonCalmRadiusMiles", value = 1,
      comment = "calm rough waters in a 1 mile radius" },
    { name = "hornTritonCalmDispelKinds", value = 2,
      comment = "dispels a water elemental or water weird" },
    { name = "hornTritonSummonKindCount", value = 3,
      comment = "hippocampi, giant sea horses, sea lions" },
    { name = "hornTritonPanicAnimalOrLower", value = 1,
      comment = "panics marine creatures with animal, or lower, "
      .. "intelligence" },
    { name = "hornTritonPanicToHitPenalty", value = 5,
      comment = "those who save take a minus 5 on to hit dice" },
    { name = "hornTritonPanicTurnsMin", value = 3,
      comment = "the penalty lasts 3-18 turns" },
    { name = "hornTritonPanicTurnsMax", value = 18,
      comment = "the turns upper edge" },
    { name = "hornTritonPanicRoundsPerTurn", value = 10,
      comment = "3-18 turns is 30-180 rounds: 10 rounds per turn" },
    { name = "hornTritonPanicRoundsMin", value = 30,
      comment = "the 30 rounds lower edge" },
    { name = "hornTritonPanicRoundsMax", value = 180,
      comment = "the 180 rounds upper edge" },
    { name = "hornTritonHearRadiusLeagues", value = 1,
      comment = "any sounding is heard by all tritons within a 1 "
      .. "league radius" },
  },
  tables = {
    { name = "hornTritonSummonDieLo",
      comment = "the selection die band lower edges: 1-2 the hippocampi, "
      .. "3-5 the sea horses, 6 the lions; i clamps",
      clamp_hi = 2,
      values = {
        1, 3, 6,
      } },
    { name = "hornTritonSummonDieHi",
      comment = "the selection die band upper edges; i clamps",
      clamp_hi = 2,
      values = {
        2, 5, 6,
      } },
    { name = "hornTritonSummonCountMin",
      comment = "the creatures summoned lower edges: 5-20 hippocampi, "
      .. "5-30 sea horses, 1-10 sea lions; i clamps",
      clamp_hi = 2,
      values = {
        5, 5, 1,
      } },
    { name = "hornTritonSummonCountMax",
      comment = "the summon upper edges; i clamps",
      clamp_hi = 2,
      values = {
        20, 30, 10,
      } },
  },
}
