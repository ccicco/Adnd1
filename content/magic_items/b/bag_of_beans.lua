-- misc magic item def: bag_of_beans
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part1.h (R257)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bag_of_beans",
  name = "Bag of Beans",
  rows = {
    { name = "Bag of Beans",
      set = "kMisc1", band = { 18, 20 }, xp = 1000, xp_hi = 0,
      gp = 5000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 1, round = 257 },
  },
  pins = {
    { name = "beanExplodeDamageLo", value = 5,
      comment = "dumped beans explode for 5-20 hit points" },
    { name = "beanExplodeDamageHi", value = 20 },
    { name = "beanExplodeRadiusFeet", value = 10,
      comment = "all creatures within 10 feet save" },
    { name = "beanOptimumLo", value = 3,
      comment = "3-12 beans are optimum" },
    { name = "beanOptimumHi", value = 12 },
    { name = "beanBeneficialMax", value = 2,
      comment = "only 1 or 2 will be beneficial" },
    { name = "beanEffectRowCount", value = 7,
      comment = "the example bean table has 7 rows" },
    { name = "beanBerryCountLo", value = 5,
      comment = "the raspberry bush: 5-20 berries" },
    { name = "beanBerryCountHi", value = 20 },
    { name = "beanBerryGemLo", value = 100,
      comment = "berries are gems of 100 or 500 g.p." },
    { name = "beanBerryGemHi", value = 500 },
    { name = "beanSmokeRadiusFeet", value = 50,
      comment = "smoke covers 50 feet radius" },
    { name = "beanSmokeTurns", value = 5,
      comment = "for 5 turns" },
    { name = "beanBlindRoundsLo", value = 1,
      comment = "blinded for 1-6 rounds even outside" },
    { name = "beanBlindRoundsHi", value = 6 },
    { name = "beanGasRadiusFeet", value = 20,
      comment = "poison gas cloud of 20 feet radius" },
    { name = "beanGasTurns", value = 1,
      comment = "persists for 1 turn" },
  },
  tables = {
  },
}
