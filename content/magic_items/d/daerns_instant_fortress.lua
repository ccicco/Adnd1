-- misc magic item def: daerns_instant_fortress
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part7.h (R263)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "daerns_instant_fortress",
  name = "Daern's Instant Fortress",
  rows = {
    { name = "Daern's Instant Fortress",
      set = "kMisc2", band = { 68, 69 }, xp = 7000, xp_hi = 0,
      gp = 27500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 7, round = 263 },
  },
  pins = {
    { name = "daernSquareFeet", value = 20,
      comment = "the tower footprint, square" },
    { name = "daernHeightFeet", value = 30,
      comment = "the tower height" },
    { name = "daernGroundDepthFeet", value = 10,
      comment = "metal extends into the ground" },
    { name = "daernCollapseHp", value = 200,
      comment = "damage before the tower collapses" },
    { name = "daernWishRepairHp", value = 10,
      comment = "a wish restores this much damage" },
    { name = "daernSpringRounds", value = 1,
      comment = "springs up in but 1 round" },
    { name = "daernGrowthDamageMin", value = 10,
      comment = "caught by the growth: minimum" },
    { name = "daernGrowthDamageMax", value = 100,
      comment = "caught by the growth: maximum" },
    { name = "daernDoorOwnerOnly", value = 1,
      comment = "opens only to the owner command" },
    { name = "daernNormalWeaponsAffect", value = 0,
      comment = "normal weapons do NOT affect the walls" },
    { name = "daernDamageCumulative", value = 1,
      comment = "sustained damage is cumulative" },
  },
  tables = {
  },
}
