-- misc magic item def: javelin_of_lightning
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part16.h (R272)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "javelin_of_lightning",
  name = "Javelin of Lightning",
  rows = {
    { name = "Javelin of Lightning",
      set = "kMisc3", band = { 81, 85 }, xp = 250, xp_hi = 0,
      gp = 3000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 16, round = 272 },
  },
  pins = {
    { name = "javelinLightningPlus", value = 2,
      comment = "equal to a +2 magic weapon, no bonuses" },
    { name = "javelinLightningRangeInches", value = 9,
      comment = "the range is 9 inches" },
    { name = "javelinLightningStrokeWidthHalfInches", value = 1,
      comment = "the stroke is one half inch wide" },
    { name = "javelinLightningStrokeLengthInches", value = 3,
      comment = "the stroke is 3 inches long" },
    { name = "javelinLightningDamageMin", value = 1,
      comment = "the struck target takes 1-6 hit points" },
    { name = "javelinLightningDamageMax", value = 6,
      comment = "the upper edge of the 1-6 damage" },
    { name = "javelinLightningElectricalDamage", value = 20,
      comment = "plus 20 hit points of electrical damage" },
    { name = "javelinLightningBackstrokeMin", value = 10,
      comment = "the back stroke deals 10 or 20" },
    { name = "javelinLightningBackstrokeMax", value = 20,
      comment = "the upper edge of the back stroke" },
    { name = "javelinLightningBackstrokeInches", value = 3,
      comment = "drawn 3 inches back toward the hurler" },
    { name = "javelinLightningFoundMin", value = 2,
      comment = "from 2-5 will be found" },
    { name = "javelinLightningFoundMax", value = 5,
      comment = "the upper edge of the 2-5 find" },
  },
  tables = {
  },
}
