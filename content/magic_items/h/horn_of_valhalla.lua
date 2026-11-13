-- misc magic item def: horn_of_valhalla
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part13.h (R269)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "horn_of_valhalla",
  name = "Horn of Valhalla",
  rows = {
    { name = "Horn of Valhalla",
      set = "kMisc3", band = { 54, 60 }, xp = 1000, xp_hi = 0,
      gp = 15000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 13, round = 269 },
  },
  pins = {
    { name = "hornValhallaVarietyCount", value = 4,
      comment = "there are 4 varieties of this magical device" },
    { name = "hornValhallaBlowIntervalDays", value = 7,
      comment = "each variety can be blown but once every 7 days" },
    { name = "hornValhallaSummonedAc", value = 4,
      comment = "the fighters summoned are armor class 4" },
    { name = "hornValhallaSummonedHpPerDie", value = 6,
      comment = "they have 6 hit points per die" },
    { name = "hornValhallaSwordSpearPct", value = 50,
      comment = "armed with sword and spear 50 percent" },
    { name = "hornValhallaAxeSpearPct", value = 50,
      comment = "or battle axe and spear 50 percent" },
    { name = "hornValhallaServiceTurns", value = 6,
      comment = "they fight until slain or 6 turns have elapsed, "
      .. "whichever occurs first" },
    { name = "hornValhallaAlignedPct", value = 50,
      comment = "fully 50 percent of these horns are aligned and "
      .. "summon only same-alignment fighters" },
    { name = "hornValhallaBronzeXpMultiplier", value = 2,
      comment = "the base 1,000 xp is doubled for a bronze horn - the "
      .. "row 20 double asterisk" },
    { name = "hornValhallaIronXpMultiplier", value = 3,
      comment = "and tripled for an iron horn" },
  },
  tables = {
    { name = "hornValhallaDiceLo",
      comment = "the variety dice band lower edges; i clamps",
      clamp_hi = 3,
      values = {
        1, 9, 16, 19,
      } },
    { name = "hornValhallaDiceHi",
      comment = "silver 1-8, brass 9-15, bronze 16-18, iron 19-20; i "
      .. "clamps",
      clamp_hi = 3,
      values = {
        8, 15, 18, 20,
      } },
    { name = "hornValhallaCountMin",
      comment = "berserk fighters summoned lower edges; i clamps",
      clamp_hi = 3,
      values = {
        4, 3, 2, 2,
      } },
    { name = "hornValhallaCountMax",
      comment = "the 4-10, 3-9, 2-8, 2-5 upper edges; i clamps",
      clamp_hi = 3,
      values = {
        10, 9, 8, 5,
      } },
    { name = "hornValhallaLevel",
      comment = "the summoned fighter levels: 2nd, 3rd, 4th, 5th; i "
      .. "clamps",
      clamp_hi = 3,
      values = {
        2, 3, 4, 5,
      } },
    { name = "hornValhallaUsableAny",
      comment = "the silver horn is usable by any class; i clamps",
      clamp_hi = 3,
      values = {
        1, 0, 0, 0,
      } },
    { name = "hornValhallaUsableCleric",
      comment = "the (C) employ marks; i clamps",
      clamp_hi = 3,
      values = {
        0, 1, 1, 0,
      } },
    { name = "hornValhallaUsableFighter",
      comment = "the (F) employ marks; i clamps",
      clamp_hi = 3,
      values = {
        0, 1, 1, 1,
      } },
    { name = "hornValhallaUsableThief",
      comment = "the (T) employ marks; i clamps",
      clamp_hi = 3,
      values = {
        0, 1, 0, 0,
      } },
  },
}
