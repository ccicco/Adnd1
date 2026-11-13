-- misc magic item def: horn_of_blasting
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part12.h (R268)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "horn_of_blasting",
  name = "Horn of Blasting",
  rows = {
    { name = "Horn of Blasting",
      set = "kMisc3", band = { 46, 46 }, xp = 5000, xp_hi = 0,
      gp = 55000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 12, round = 268 },
  },
  pins = {
    { name = "hornBlastingConeLengthInches", value = 12,
      comment = "a cone of sound 12 inches long" },
    { name = "hornBlastingConeBaseWidthInches", value = 3,
      comment = "3 inches wide at the base" },
    { name = "hornBlastingSaveStunRounds", value = 1,
      comment = "those saving versus magic are stunned for 1 round" },
    { name = "hornBlastingSaveDeafRounds", value = 2,
      comment = "those saving are deafened for 2" },
    { name = "hornBlastingFailDmgMin", value = 1,
      comment = "those failing the save sustain damage" },
    { name = "hornBlastingFailDmgMax", value = 10,
      comment = "1-10 hit points of damage" },
    { name = "hornBlastingFailStunRounds", value = 2,
      comment = "those failing are stunned for 2 rounds" },
    { name = "hornBlastingFailDeafRounds", value = 4,
      comment = "those failing are deafened for 4" },
    { name = "hornBlastingPulseWidthFeet", value = 1,
      comment = "a wave of ultrasonic sound, a 1 foot wide pulse" },
    { name = "hornBlastingPulseLengthInches", value = 10,
      comment = "the pulse is 10 inches long" },
    { name = "hornBlastingCatapultMultiplier", value = 3,
      comment = "the weakening of metal, stone and wood equals 3 times "
      .. "a large catapult missile hit" },
    { name = "hornBlastingCatapultHitDamage", value = 6,
      comment = "the large catapult missile hit damage (derived: 18 "
      .. "structural at triple)" },
    { name = "hornBlastingStructuralPoints", value = 18,
      comment = "18 structural points, sufficient to smash a "
      .. "drawbridge or flatten a normal cottage" },
    { name = "hornBlastingExplodePctPerExtraUse", value = 10,
      comment = "winded magically more than once per day: a 10 percent "
      .. "cumulative chance to explode itself" },
    { name = "hornBlastingExplodeDmgMin", value = 5,
      comment = "the explosion inflicts 5-50 hit points of damage on "
      .. "the person sounding it" },
    { name = "hornBlastingExplodeDmgMax", value = 50,
      comment = "the 5-50 upper edge" },
    { name = "hornBlastingCharges", value = 0,
      comment = "there are no charges upon a horn" },
    { name = "hornBlastingShiverPctPerUse", value = 2,
      comment = "each magical use: a 2 percent cumulative chance of "
      .. "shivering itself" },
    { name = "hornBlastingShiverWielderDamage", value = 0,
      comment = "a shiver inflicts no damage on the character blowing "
      .. "it" },
  },
  tables = {
  },
}
